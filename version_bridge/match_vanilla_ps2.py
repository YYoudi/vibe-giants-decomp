#!/usr/bin/env python3
"""
vanilla(1.0) <-> PS2 (SLUS_201.78) function matcher via shared unique strings.

Reuses the PS2-side disassembly from ps2_symbols/match_pc_ps2.py (the PS2
{func: strings} map is a property of the ELF, independent of which PC binary we
match against). The PC side here is vanilla (vanilla_functions.jsonl) instead of
the 1.5 ghidra_exports.

Output: version_bridge/vanilla_ps2_matches.csv
  vanilla_addr, vanilla_name, ps2_addr, ps2_name, shared, conf, sample_shared

This feeds triangulation: if a vanilla func and a 1.5 func both match the SAME PS2
function name, they are the same function (two independent string-anchored paths
converging on an authoritative PS2 symbol).
"""
import csv, os, sys, collections
HERE = os.path.dirname(os.path.abspath(__file__))
PS2_DIR = os.path.join(os.path.dirname(HERE), "ps2_symbols")
sys.path.insert(0, PS2_DIR)
VANILLA = os.path.join(HERE, "vanilla_functions.jsonl")

def main():
    # reuse PS2 disassembly
    from match_pc_ps2 import load_ps2, ps2_string_refs
    print("[*] loading PS2 ELF + disassembling .text for string refs ...")
    e, funcs, text_bytes, t_addr, strmap, ranges = load_ps2()
    ps2refs = ps2_string_refs(text_bytes, t_addr, funcs, strmap, ranges)
    print(f"    PS2 functions with string refs: {len(ps2refs)}")

    # vanilla side: load strings from jsonl
    import json
    vanrefs = collections.defaultdict(set); vannames = {}
    for l in open(VANILLA, encoding="utf-8"):
        l = l.strip()
        if not l: continue
        r = json.loads(l)
        a = r["addr"]; a = a[2:] if a.startswith("0x") else a
        a = a.rjust(8, "0")
        vannames[a] = r.get("name", a)
        for s in r.get("strings", []):
            if len(s) >= 6: vanrefs[a].add(s)
    print(f"    vanilla functions with strings: {len(vanrefs)}")

    # global string frequency across both sides
    globfreq = collections.Counter()
    for s in ps2refs.values(): globfreq.update(s)
    for s in vanrefs.values(): globfreq.update(s)

    ps2_str_index = collections.defaultdict(set)
    for fa, ss in ps2refs.items():
        for s in ss: ps2_str_index[s].add(fa)

    rows = []
    for vfa, vstrings in vanrefs.items():
        ps2vote = collections.Counter()
        detail = []
        for s in vstrings:
            cands = ps2_str_index.get(s)
            if not cands: continue
            w = 1.0 / max(1, globfreq[s])
            for pf in cands: ps2vote[pf] += w
            detail.append((s, globfreq[s]))
        if not ps2vote: continue
        ranked = ps2vote.most_common()
        best_pf, best_score = ranked[0]
        second = ranked[1][1] if len(ranked) > 1 else 0
        shared = sorted(set(s for s, _ in detail if best_pf in ps2_str_index.get(s, set())))
        distinct = len(shared)
        dom = best_score / (best_score + second) if (best_score + second) > 0 else 1.0
        conf = dom * min(1.0, distinct / 3.0)
        rows.append({
            "vanilla_addr": vfa, "vanilla_name": vannames.get(vfa, vfa),
            "ps2_addr": f"0x{best_pf:08x}", "ps2_name": funcs[best_pf][0],
            "shared": distinct, "conf": round(conf, 3),
            "sample_shared": " | ".join(shared[:3]),
        })
    rows.sort(key=lambda r: (-r["conf"], -r["shared"]))

    out = os.path.join(HERE, "vanilla_ps2_matches.csv")
    with open(out, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["vanilla_addr", "vanilla_name", "ps2_addr",
                                          "ps2_name", "shared", "conf", "sample_shared"])
        w.writeheader(); w.writerows(rows)
    high = [r for r in rows if r["conf"] >= 0.5 and r["shared"] >= 1]
    print(f"[+] vanilla_ps2_matches.csv: {len(rows)} candidates, {len(high)} high-confidence (conf>=0.5)")

if __name__ == "__main__":
    main()
