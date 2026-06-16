#!/usr/bin/env python3
"""
Extend vanilla(1.0) -> PS2 via anchored call-graph propagation.

vanilla_ps2_matches.csv (string-anchor, ~15 confident) is sparse because vanilla
has few string refs. Multiply it the same way match_propagate.py multiplied
1.5->PS2 (46 seeds -> 378): seeds = confident string anchors; growth = a vanilla
func F and PS2 func G match when they share >=2 already-matched callees/callers,
G is the UNIQUE best PS2 func for F and vice versa; confidence decays 0.85/hop,
stops below 0.4.

Reuses ps2_graph() (PS2 ELF disassembly) from ps2_symbols/match_propagate.py.
The vanilla call graph comes straight from vanilla_functions.jsonl (callees field).

Output: version_bridge/vanilla_ps2_matches_full.csv  (feeds triangulate.py)
"""
import csv, os, sys, json, collections
HERE = os.path.dirname(os.path.abspath(__file__))
PS2_DIR = os.path.join(os.path.dirname(HERE), "ps2_symbols")
sys.path.insert(0, PS2_DIR)
SEED = os.path.join(HERE, "vanilla_ps2_matches.csv")
VANILLA = os.path.join(HERE, "vanilla_functions.jsonl")

def na(a):
    a = a.lower(); a = a[2:] if a.startswith("0x") else a; return a.rjust(8, "0")

def vanilla_graph():
    callees = collections.defaultdict(set); names = {}
    for l in open(VANILLA, encoding="utf-8"):
        l = l.strip()
        if not l: continue
        r = json.loads(l); a = na(r["addr"]); names[a] = r.get("name", a)
        for c in r.get("callees", []):
            import re
            if re.fullmatch(r'0x[0-9a-fA-F]{6,8}|[0-9a-fA-F]{6,8}', str(c)):
                callees[a].add(na(c))
    callers = collections.defaultdict(set)
    for a, cs in callees.items():
        for c in cs: callers[c].add(a)
    return callees, callers, names

def main():
    from match_propagate import ps2_graph
    print("[*] building vanilla call graph ...")
    v_c, v_r, v_n = vanilla_graph()
    print(f"    vanilla funcs with callees: {len(v_c)}")
    print("[*] building PS2 call graph (disassemble ELF) ...")
    p_c, p_r, p_n = ps2_graph()
    print(f"    PS2 funcs with callees: {len(p_c)}")

    # seeds: ALL string-anchor matches (conf carries through; triangulate.py filters
    # on its own TRI_CONF). Seeding from the full set (not just conf>=0.5) keeps the
    # intersection with 1.5->PS2 populated and gives propagation more to work with.
    seeds = {}
    seedconf = {}
    ps2name = {}
    for r in csv.DictReader(open(SEED, encoding="utf-8")):
        va = na(r["vanilla_addr"])
        seeds[va] = r["ps2_addr"]
        seedconf[va] = float(r["conf"])
        ps2name[va] = r["ps2_name"]
    print(f"[*] seeds (all string anchors): {len(seeds)}")

    M = dict(seeds)  # vanilla -> ps2_addr (STRING only, so graph lookups work)
    Mrev = {pa: va for va, pa in M.items()}
    DECAY = 0.85; MIN_CONF = 0.4
    conf = {va: seedconf.get(va, 1.0) for va in M}
    rnd = 0
    while True:
        rnd += 1
        cand = collections.defaultdict(lambda: collections.defaultdict(list))
        for va, pa in list(M.items()):
            for nv in v_c.get(va, set()) | v_r.get(va, set()):
                if nv in M: continue
                for np in p_c.get(pa, set()) | p_r.get(pa, set()):
                    if np in Mrev: continue
                    cand[nv][np].append(conf[va])
        new = []
        for nv, prs in cand.items():
            scored = []
            for np, cs in prs.items():
                if len(cs) >= 2:
                    scored.append((len(cs), sum(cs)/len(cs), np))
            if not scored: continue
            scored.sort(reverse=True)
            if len(scored) >= 2 and scored[0][:2] == scored[1][:2]: continue  # tie -> skip
            ag, avg, bp = scored[0]
            # mutual uniqueness
            scored2 = []
            for nv2, prs2 in cand.items():
                if bp in prs2 and len(prs2[bp]) >= 2:
                    scored2.append((len(prs2[bp]), sum(prs2[bp])/len(prs2[bp]), nv2))
            scored2.sort(reverse=True)
            if not scored2 or scored2[0][2] != nv: continue
            c = DECAY * avg
            if c < MIN_CONF: continue
            new.append((c, nv, bp, ag))
        if not new: break
        applied = 0
        for c, nv, bp, ag in sorted(new, reverse=True):
            if nv in M or bp in Mrev: continue
            M[nv] = bp; Mrev[bp] = nv; conf[nv] = round(c, 3)
            ps2name[nv] = p_n.get(bp, ""); applied += 1
        print(f"[*] round {rnd}: +{applied} (total {len(M)})")
        if applied == 0: break

    # emit
    rows = []
    for va, pa in M.items():
        rows.append({"vanilla_addr": va, "vanilla_name": v_n.get(va, ""),
                     "ps2_addr": pa, "ps2_name": ps2name.get(va, p_n.get(pa, "")),
                     "conf": conf.get(va, 1.0),
                     "origin": "seed" if va in seeds else "propagated"})
    rows.sort(key=lambda r: -r["conf"])
    out = os.path.join(HERE, "vanilla_ps2_matches_full.csv")
    with open(out, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["vanilla_addr", "vanilla_name", "ps2_addr",
                                          "ps2_name", "conf", "origin"])
        w.writeheader(); w.writerows(rows)
    nseed = sum(1 for r in rows if r["origin"] == "seed")
    print(f"[+] vanilla_ps2_matches_full.csv: {len(rows)} (seed {nseed}, propagated {len(rows)-nseed})")

if __name__ == "__main__":
    main()
