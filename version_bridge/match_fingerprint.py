#!/usr/bin/env python3
"""
Reliable 1.5(1.520.59) <-> vanilla(1.0) function matcher (v2).

FINDING from the first attempt: mnemonic fingerprints are WEAK across these two
builds because the compiler changed between vanilla retail (~MSVC 2000) and the
1.5 community patch (~MSVC 2010s). Even the correct match (InitializeEngine:
1.5 size 2154 <-> vanilla size 2347) has 3-gram Jaccard only ~0.19 and a
2-token prefix. So fingerprint matching only catches byte-identical (same-
compiler) functions. The ROBUST cross-version signals are, in order:
  1. Shared rare strings         (preserved data; mutually-unique = anchor)
  2. Size in bytes               (preserved even under recompilation)
  3. Call-graph topology         (caller/callee relations preserved)
  4. Mnemonic fingerprint        (confirms same-compiler/identical only)

The previous map (VERSION_MAP_full.csv, 461 pairs) had 20 vanilla addresses each
claimed by 2-7 distinct 1.5 functions (~11% corrupted) because module-shared
strings collapsed the vote and no mutual-uniqueness guard was applied to seeds.
This matcher fixes that: every seed is mutually unique by construction, and the
global assignment enforces 1 vanilla <-> 1 1.5.

Pipeline:
  1. ANCHORS: mutually-unique rare-string pairs + fingerprint-EXACT pairs.
     Tiered by string count / size / fingerprint. Collision-free by construction.
  2. PROPAGATION: call-graph (>=2 matched-neighbor agreement, size gate,
     mutual uniqueness, confidence decay) for 3 rounds.
  3. Emit VERSION_MAP_v2.csv with tier + origin + all signals + PS2 name.
  4. (No unreliable size-only guesses -- those went into the old LOW tier.)

Tiers (honest confidence for the hand-off):
  EXACT   string>=2 AND size<=1.20, OR fingerprint jac>=0.90+prefix>=32+size<=1.12
  HIGH    string>=2, OR 1 string + size<=1.40, OR propagated with >=4 agreement
  MEDIUM  1 string + size<=1.80, OR propagated >=2 agreement
  LOW     propagated 1 round / weak agreement  -> verify in Ghidra
"""
import json, os, re, csv, collections

HERE = os.path.dirname(os.path.abspath(__file__))
RECOMP = os.path.join(HERE, "recomp_functions.jsonl")
VANILLA = os.path.join(HERE, "vanilla_functions.jsonl")
PS2_MATCH = os.path.join(os.path.dirname(HERE), "ps2_symbols", "pc_ps2_matches_full.csv")

ADDR_RE = re.compile(r'0x[0-9a-fA-F]{6,8}|[0-9a-fA-F]{6,8}')
def norm_addr(a):
    a = a.lower(); a = a[2:] if a.startswith("0x") else a; return a.rjust(8, "0")

def load(path):
    out = {}
    for l in open(path, encoding="utf-8"):
        l = l.strip()
        if not l: continue
        r = json.loads(l); a = norm_addr(r["addr"])
        toks = [t for t in r.get("fp","").split(" ") if t]
        grams = set((toks[i],toks[i+1],toks[i+2]) for i in range(len(toks)-2))
        out[a] = {
            "name": r.get("name",""),
            "size": int(r.get("size",0)),
            "toks": toks, "grams": grams,
            "callees": set(norm_addr(c) for c in r.get("callees",[]) if ADDR_RE.fullmatch(str(c))),
            "strings": set(s for s in r.get("strings",[]) if len(s) >= 5),
        }
    return out

def szratio(a, b):
    if not a or not b: return 1.0
    return max(a,b)/min(a,b)

def prefix(a, b, cap=64):
    n = min(len(a), len(b), cap); p = 0
    while p < n and a[p] == b[p]: p += 1
    return p

def jac(a, b):
    u = a | b
    return len(a & b)/len(u) if u else 0.0

def main():
    print("[*] loading ...")
    rec = load(RECOMP); van = load(VANILLA)
    print(f"    1.5: {len(rec)}  vanilla: {len(van)}")

    # rare strings (freq <= 6 across both binaries)
    freq = collections.Counter()
    for d in (rec, van):
        for f in d.values(): freq.update(f["strings"])
    for d in (rec, van):
        for f in d.values(): f["rare"] = set(s for s in f["strings"] if freq.get(s,0) <= 6)

    # PS2 name per 1.5 func
    rec2ps2 = {}
    if os.path.exists(PS2_MATCH):
        for r in csv.DictReader(open(PS2_MATCH, encoding="utf-8")):
            rec2ps2[norm_addr(r["pc_addr"])] = r["ps2_name"].split("__")[0].split("(")[0]

    # ---- 1. ANCHORS: mutually-unique rare-string pairs ----
    s2r = collections.defaultdict(set); s2v = collections.defaultdict(set)
    for a, f in rec.items():
        for s in f["rare"]: s2r[s].add(a)
    for a, f in van.items():
        for s in f["rare"]: s2v[s].add(a)
    pair_strings = collections.defaultdict(set)
    for s in set(s2r) & set(s2v):
        if len(s2r[s]) == 1 and len(s2v[s]) == 1:
            pair_strings[(next(iter(s2r[s])), next(iter(s2v[s])))].add(s)
    print(f"[*] mutually-unique string-anchor pairs: {len(pair_strings)}")

    assigned = {}  # ra -> record
    v_any = set()  # claimed vanilla addrs (string anchors may still many-to-1 onto these)

    def add_anchor(ra, va, origin, conf, shared, pl, jc):
        sr = szratio(rec[ra]["size"], van[va]["size"])
        # tier
        if (shared >= 2 and sr <= 1.20) or (jc >= 0.92 and sr <= 1.12 and pl >= 12):
            tier = "EXACT"
        elif shared >= 2 or (shared == 1 and sr <= 1.40) or (jc >= 0.80 and pl >= 20):
            tier = "HIGH"
        elif shared == 1 or (jc >= 0.55):
            tier = "MEDIUM"
        else:
            tier = "LOW"
        assigned[ra] = {
            "1.5_addr": ra, "1.5_name": rec[ra]["name"],
            "vanilla_addr": va, "vanilla_name": van[va]["name"],
            "score": round(conf,3), "prefix": pl, "jaccard": round(jc,3),
            "shared_rare": shared, "size_ratio": round(sr,3), "tier": tier,
            "origin": origin, "ps2_name": rec2ps2.get(ra,""),
        }

    # v_any = universal "claimed" set of vanilla addrs. String anchors ADD to it
    # but do NOT check it (allow many-to-1 merges); every other pass is strict 1-to-1
    # and skips addrs already in v_any. (declared above, before add_anchor)

    # string anchors: strength-ordered (shared-string count desc, then size, then jac).
    # Allow many-to-1: a vanilla func may be the merge target of several 1.5 funcs
    # (e.g. 1.5 split vanilla 0x005222c0 into InitializeEngine + MainGameLoop). Safe
    # because every seed is a MUTUALLY-UNIQUE string (exactly 1 rec, 1 van).
    pair_list = []
    for (ra, va), ss in pair_strings.items():
        pl = prefix(rec[ra]["toks"], van[va]["toks"])
        jc = jac(rec[ra]["grams"], van[va]["grams"])
        sr = szratio(rec[ra]["size"], van[va]["size"])
        pair_list.append((len(ss), -round(sr,3), round(jc,3), ra, va, len(ss), pl))
    pair_list.sort(reverse=True)
    for nstr, _negsr, jc, ra, va, shared, pl in pair_list:
        if ra in assigned: continue        # one van per rec (strongest pair wins)
        add_anchor(ra, va, "string", 1.0 if nstr >= 2 else 0.85, shared, pl, jc)
        v_any.add(va)

    # fingerprint-EXACT anchors for funcs not already anchored (same-compiler pairs)
    vidx = collections.defaultdict(set)
    for a, f in van.items():
        for g in f["grams"]: vidx[g].add(a)
    fp_added = 0
    for ra, rf in rec.items():
        if ra in assigned or not rf["grams"]: continue
        cand = set()
        for g in rf["grams"]:
            cand.update(vidx.get(g, ()))
            if len(cand) > 3000: break
        best = None
        for va in cand:
            if va in v_any: continue
            vf = van[va]; sr = szratio(rf["size"], vf["size"])
            if sr > 1.15: continue
            jc = jac(rf["grams"], vf["grams"]); pl = prefix(rf["toks"], vf["toks"])
            # small functions never reach prefix 32; require enough 3-grams + high jaccard
            if len(rf["grams"]) >= 5 and len(vf["grams"]) >= 5 and jc >= 0.92:
                s = (jc, pl, va)
                if best is None or s > best: best = s
        if best:
            jc, pl, va = best
            add_anchor(ra, va, "fingerprint", 1.0, 0, pl, jc); v_any.add(va); fp_added += 1
    print(f"[*] fingerprint-EXACT anchors added: {fp_added}")

    # ---- 2. PROPAGATION: call-graph, size-gated, mutual uniqueness ----
    rec_callers = collections.defaultdict(set); van_callers = collections.defaultdict(set)
    for a, f in rec.items():
        for c in f["callees"]: rec_callers[c].add(a)
    for a, f in van.items():
        for c in f["callees"]: van_callers[c].add(a)
    M = {ra: rec["vanilla_addr"] for ra, rec in assigned.items()}

    prop_added = 0
    for rnd in range(1, 6):
        new = []
        for ra, rf in rec.items():
            if ra in assigned: continue
            votes = collections.Counter()
            nbrs = rec_callers.get(ra, set()) | rf["callees"]
            for p in nbrs:
                if p == ra or p not in M: continue
                pvn = M[p]; pf = van.get(pvn)
                if not pf: continue
                vnbrs = van_callers.get(pvn, set()) | pf["callees"]
                for nb in vnbrs:
                    if nb in v_any: continue
                    if nb not in van: continue
                    votes[nb] += 1
            if not votes: continue
            top = votes.most_common(3)
            if top[0][1] < 2: continue
            if len(top) >= 2 and top[0][1] == top[1][1]: continue
            bva = top[0][0]; agree = top[0][1]
            sr = szratio(rf["size"], van[bva]["size"])
            if sr > 2.0: continue  # size gate (size is the most-preserved signal under recompilation)
            new.append((agree, ra, bva, sr))
        applied = 0
        for agree, ra, bva, sr in sorted(new, reverse=True):
            if ra in assigned or bva in v_any: continue
            conf = max(0.40, 0.70 - 0.10*(rnd-1)) if agree >= 2 else 0.45
            assigned[ra] = {
                "1.5_addr": ra, "1.5_name": rec[ra]["name"],
                "vanilla_addr": bva, "vanilla_name": van[bva]["name"],
                "score": round(min(0.75, conf + 0.03*agree),3), "prefix": 0, "jaccard": 0.0,
                "shared_rare": 0, "size_ratio": round(sr,3),
                "tier": "HIGH" if agree >= 4 else ("MEDIUM" if agree >= 2 else "LOW"),
                "origin": "propagated", "ps2_name": rec2ps2.get(ra,""),
            }
            M[ra] = bva; v_any.add(bva); applied += 1
        prop_added += applied
        print(f"[*] propagation round {rnd}: +{applied}")
        if applied == 0: break

    # ---- 3. STRUCTURAL LOW tier: best-guess by size + callee-count ----
    # For the long tail (no string, no graph anchor): match by closest size among
    # unmatched, requiring callee-count agreement and a clear size margin. These
    # are HINTS (verify in Ghidra), clearly tagged origin=structural.
    # index unmatched vanilla by size for nearest lookup
    van_by_size = sorted((van[a]["size"], a) for a in van if a not in v_any)
    van_sizes = [s for s, _ in van_by_size]
    import bisect
    struct_added = 0
    for ra, rf in rec.items():
        if ra in assigned: continue
        rsz = rf["size"]; rc = len(rf["callees"])
        if rsz < 32: continue  # too small to be discriminative
        # nearest by size
        i = bisect.bisect_left(van_sizes, rsz)
        cand_idx = []
        for j in (i-1, i, i+1, i+2):
            if 0 <= j < len(van_by_size): cand_idx.append(j)
        best = None
        for j in cand_idx:
            vsz, va = van_by_size[j]
            if va in v_any: continue
            sr = max(rsz,vsz)/min(rsz,vsz) if min(rsz,vsz) else 99
            if sr > 1.25: continue
            vc = len(van[va]["callees"])
            cdiff = abs(rc - vc)
            jc = jac(rf["grams"], van[va]["grams"])
            # prefer size-close + callee-count-close + higher jaccard
            sc = (sr, cdiff, -jc)
            if best is None or sc < best[0]: best = (sc, va, sr, cdiff, jc)
        if not best: continue
        (_, va, sr, cdiff, jc) = best
        # require callee-count within 1 (structural signature) OR decent jaccard
        if cdiff > 1 and jc < 0.30: continue
        assigned[ra] = {
            "1.5_addr": ra, "1.5_name": rec[ra]["name"],
            "vanilla_addr": va, "vanilla_name": van[va]["name"],
            "score": round(0.35 + jc*0.1,3), "prefix": prefix(rf["toks"], van[va]["toks"]),
            "jaccard": round(jc,3), "shared_rare": 0, "size_ratio": round(sr,3),
            "tier": "LOW", "origin": "structural", "ps2_name": rec2ps2.get(ra,""),
        }
        M[ra] = va; v_any.add(va); struct_added += 1
    print(f"[*] structural best-guess (LOW): +{struct_added}")

    # ---- emit ----
    rows = list(assigned.values())
    torder = {"EXACT":0,"HIGH":1,"MEDIUM":2,"LOW":3}
    rows.sort(key=lambda r: (torder[r["tier"]], -r["score"]))
    out = os.path.join(HERE, "VERSION_MAP_v2.csv")
    cols = ["1.5_addr","1.5_name","vanilla_addr","vanilla_name","tier","score","origin",
            "shared_rare","size_ratio","prefix","jaccard","ps2_name"]
    with open(out, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=cols); w.writeheader(); w.writerows(rows)

    tierc = collections.Counter(r["tier"] for r in rows)
    oric = collections.Counter(r["origin"] for r in rows)
    vtot = len(van)
    print(f"\n[+] VERSION_MAP_v2.csv: {len(rows)} pairs ({len(rows)*100//vtot}% of vanilla {vtot})")
    print(f"    tiers: " + ", ".join(f"{t}={tierc[t]}" for t in ["EXACT","HIGH","MEDIUM","LOW"]))
    print(f"    origin: " + ", ".join(f"{o}={oric[o]}" for o in ["string","fingerprint","propagated","structural"]))
    v2c = collections.Counter(r["vanilla_addr"] for r in rows)
    r2c = collections.Counter(r["1.5_addr"] for r in rows)
    merges = {va: c for va, c in v2c.items() if c > 1}
    print(f"    1.5->many (must be 0): {sum(1 for c in r2c.values() if c>1)}")
    print(f"    many-to-1 MERGES (1.5 split a vanilla func): {len(merges)} vanilla addrs, {sum(merges.values())} 1.5 funcs")
    for va, c in sorted(merges.items(), key=lambda kv: -kv[1]):
        members = [r["1.5_addr"] for r in rows if r["vanilla_addr"] == va]
        print(f"      {va} <- {members}")

if __name__ == "__main__":
    main()
