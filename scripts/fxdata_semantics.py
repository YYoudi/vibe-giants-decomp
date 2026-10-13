#!/usr/bin/env python3
"""Map FxData offsets to the named fx functions that touch them (semantic
field-name evidence for the FxData struct)."""
import csv, json, glob, re, collections, os

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PS2 = os.path.join(REPO, "ps2_symbols")
EXP = os.path.join(REPO, "ghidra_exports")

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

fx_named = {}
for f in ["crt_llm_names.csv", "bsim_wave.csv", "unified_names_1449.csv", "llm_strings_wave.csv"]:
    try:
        for r in csv.DictReader(open(os.path.join(PS2, f), encoding="utf-8")):
            if float(r["conf"]) >= 0.9 and r["ps2_name"].startswith(("fx_", "fxb_", "fxn_")):
                fx_named[norm(r["pc_addr"])] = r["ps2_name"].split("__F")[0]
    except FileNotFoundError:
        pass

USE = re.compile(r"(?:fx|param_1)\s*\+\s*(0x[0-9a-fA-F]+)")
hits = collections.defaultdict(set)
for f in glob.glob(os.path.join(EXP, "*.json")):
    d = json.load(open(f, encoding="utf-8"))
    a = norm(d["address"])
    if a not in fx_named:
        continue
    for o in USE.findall(d["decompiled"]):
        hits[int(o, 16)].add(fx_named[a])

print("FxData offset -> touching named fx functions:")
for o in sorted(hits):
    if o < 0x80:
        print(f"  {hex(o)}: {sorted(hits[o])[:4]}")
