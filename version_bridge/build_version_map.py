#!/usr/bin/env python3
"""
Build the VERSION_MAP: match 1.520.59 functions -> vanilla 1.0 functions, and
quantify how identical they are. Hand-off artifact so the main agent carries its
1.5 reverse knowledge onto vanilla 1.0 as the canonical target.

Signals:
  1. Shared UNIQUE strings (primary, strongest): a 1.5 func and vanilla func
     referencing the same rare string = same function.
  2. PS2-name triangulation (cross-check): both sides matched to PS2 names.
  3. Size proximity (secondary).

Identity tiers per matched pair:
  IDENTICAL   - string sets ~equal, sizes within 15%  -> 1.5 knowledge transfers 1:1
  NEAR        - shares >=2 rare strings, sizes within 40%
  MODIFIED    - shares 1 rare string (same function, patched body)
  (unmatched 1.5 funcs are 1.5-only / patch-added, or stringless)

Inputs:
  vanilla_functions.json   (from Ghidra export_functions.py)
  ghidra_exports/00*.json  (1.5, read-only)
  ps2_symbols/SLUS_201.78.rodata_strings.txt  (rare-string filter)
  ps2_symbols/pc_ps2_matches_full.csv (1.5 -> PS2 names)
Output:
  version_bridge/VERSION_MAP.csv   1.5_addr,1.5_name,vanilla_addr,identity,shared,ps2_name
  version_bridge/VERSION_MAP.md    summary + hand-off notes
"""
import csv, os, re, json, glob, collections

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(HERE)
VAN = os.path.join(HERE, "vanilla_functions.jsonl")
PC_EXPORT = os.path.join(REPO, "ghidra_exports")
PS2_STR = os.path.join(REPO, "ps2_symbols", "SLUS_201.78.rodata_strings.txt")
PS2_MATCH = os.path.join(REPO, "ps2_symbols", "pc_ps2_matches_full.csv")

STR_RE = re.compile(r'"((?:\\.|[^"\\])*)"')

def load_vanilla():
    d = [json.loads(l) for l in open(VAN, encoding="utf-8") if l.strip()]
    for f in d:
        a = f["addr"]
        f["addr"] = a[2:] if a.startswith("0x") else a
    return d

def load_15():
    """{addr: {name, strings, size_proxy}}"""
    out = {}
    for f in glob.glob(os.path.join(PC_EXPORT, "00*.json")):
        try: d = json.load(open(f, encoding="utf-8"))
        except: continue
        a = d["address"]
        body = d.get("decompiled","") or ""
        strs = set(m.replace("\\n"," ").replace('\\"','"') for m in STR_RE.findall(body) if len(m)>=5)
        out[a] = {"name": d.get("name", "FUN_"+a), "strings": strs}
    # size proxy: sort by addr, gap to next
    addrs = sorted(out.keys())
    for i,a in enumerate(addrs):
        nxt = int(addrs[i+1],16) if i+1 < len(addrs) else int(a,16)+0x40
        out[a]["size_proxy"] = nxt - int(a,16)
    return out

def main():
    van = load_vanilla()
    pc = load_15()
    # rare-string set: strings appearing few times across BOTH binaries are discriminative
    freq = collections.Counter()
    for f in van: freq.update(f["strings"])
    for a in pc: freq.update(pc[a]["strings"])
    def rare(s): return freq.get(s,0) <= 4 and len(s) >= 5

    # string -> vanilla funcs index (rare strings only)
    s2van = collections.defaultdict(set)
    for f in van:
        for s in f["strings"]:
            if rare(s): s2van[s].add(f["addr"])

    # PS2 name per 1.5 func (triangulation cross-check)
    pc2ps2 = {}
    if os.path.exists(PS2_MATCH):
        for r in csv.DictReader(open(PS2_MATCH, encoding="utf-8")):
            pc2ps2[r["pc_addr"]] = r["ps2_name"].split("__")[0].split("(")[0]

    rows = []
    for a, info in pc.items():
        pstr = info["strings"]
        votes = collections.Counter()
        shared = {}
        for s in pstr:
            for va in s2van.get(s, ()):
                votes[va] += 1.0/max(1,freq[s])
                shared.setdefault(va, set()).add(s)
        if not votes:
            continue
        best, score = votes.most_common(1)[0]
        second = votes.most_common(2)[1][1] if len(votes)>1 else 0
        vfn = next(f for f in van if f["addr"]==best)
        # identity tier
        nshared = len(shared[best])
        sp = info["size_proxy"]; vs = vfn["size"]
        szratio = max(sp,vs)/max(1,min(sp,vs)) if sp and vs else 99
        ps2 = pc2ps2.get(a,"")
        if nshared >= 2 and szratio <= 1.15 and score > second*1.5:
            tier = "IDENTICAL"
        elif nshared >= 2 and szratio <= 1.4:
            tier = "NEAR"
        else:
            tier = "MODIFIED"
        rows.append({"1.5_addr":a, "1.5_name":info["name"], "vanilla_addr":best,
                     "identity":tier, "shared":nshared, "size_ratio":round(szratio,2),
                     "ps2_name":ps2, "sample":sorted(shared[best])[:2]})

    rows.sort(key=lambda r: (r["identity"], -r["shared"]))
    csvp = os.path.join(HERE, "VERSION_MAP.csv")
    with open(csvp,"w",newline="",encoding="utf-8") as f:
        w=csv.DictWriter(f, fieldnames=["1.5_addr","1.5_name","vanilla_addr","identity","shared","size_ratio","ps2_name","sample"])
        w.writeheader(); w.writerows(rows)

    n_id = sum(1 for r in rows if r["identity"]=="IDENTICAL")
    n_near = sum(1 for r in rows if r["identity"]=="NEAR")
    n_mod = sum(1 for r in rows if r["identity"]=="MODIFIED")
    total15 = len(pc)
    mdp = os.path.join(HERE, "VERSION_MAP.md")
    with open(mdp,"w",encoding="utf-8") as f:
        f.write("# VERSION MAP: 1.520.59 -> vanilla 1.0\n\n")
        f.write("Hand-off artifact: maps the main agent's reversed 1.5 functions to vanilla 1.0\n")
        f.write("addresses, quantifying identity so 1.5 knowledge carries onto vanilla.\n\n")
        f.write("## Summary\n\n")
        f.write(f"- 1.5 functions total: **{total15}**\n")
        f.write(f"- matched to a vanilla counterpart: **{len(rows)}**\n")
        f.write(f"  - IDENTICAL (carry over 1:1): **{n_id}**\n")
        f.write(f"  - NEAR (small patch delta): **{n_near}**\n")
        f.write(f"  - MODIFIED (same func, heavier patch): **{n_mod}**\n")
        f.write(f"- 1.5-only / patch-added (no vanilla match): **{total15-len(rows)}**\n\n")
        f.write("## How to use (main agent hand-off)\n\n")
        f.write("The reconstructed source is vanilla-canonical going forward. For each matched\n")
        f.write("function, cite the **vanilla_addr** as the canonical provenance. IDENTICAL pairs\n")
        f.write("= your 1.5 reverse transfers verbatim. NEAR/MODIFIED = re-verify against vanilla.\n")
        f.write("1.5-only functions are the post-1.4 patch layer (reimplement, don't inherit).\n\n")
        f.write("Full table in VERSION_MAP.csv.\n")
    print("[+] VERSION_MAP built:")
    print(f"    matched {len(rows)}/{total15}  (IDENTICAL {n_id}, NEAR {n_near}, MODIFIED {n_mod})")
    print(f"    1.5-only (patch layer): {total15-len(rows)}")
    print(f"[+] VERSION_MAP.csv + .md written")

if __name__ == "__main__":
    main()
