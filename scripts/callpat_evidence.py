#!/usr/bin/env python3
"""Evidence dump for call-pattern-attributed functions: named calls + strings
per function, for LLM promotion reading."""
import csv, json, glob, re, collections, os, sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXP = os.path.join(REPO, "ghidra_exports")
PS2 = os.path.join(REPO, "ps2_symbols")

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

src = sys.argv[1] if len(sys.argv) > 1 else "callpat_wave.csv"
targets = {}
for r in csv.DictReader(open(os.path.join(PS2, src), encoding="utf-8")):
    targets[norm(r["pc_addr"])] = r["ps2_name"]

named = {}
for f in ["unified_names_1449.csv", "crt_llm_names.csv", "crt_llm_names2.csv", "bsim_wave.csv",
          "module_names_wave.csv", "module_bands.csv", "system_wave2.csv",
          "llm_strings_wave.csv", "llm_strings_wave2.csv", "llm_wave4.csv", "callpat_wave.csv",
          "llm_bigbodies.csv"]:
    try:
        for r in csv.DictReader(open(os.path.join(PS2, f), encoding="utf-8")):
            if float(r["conf"]) >= 0.9:
                named[norm(r["pc_addr"])] = r["ps2_name"].split("__F")[0]
    except FileNotFoundError:
        pass

CALL = re.compile(r"\bFUN_([0-9a-fA-F]{8})\s*\(")
SR = re.compile(r'"([^"\\]{4,60})"')
for a in sorted(targets):
    d = json.load(open(os.path.join(EXP, f"{a}.json"), encoding="utf-8"))
    body = d["decompiled"]
    calls = set()
    for m in CALL.finditer(body):
        c = norm(m.group(1))
        if c in named:
            calls.add(named[c])
    strs = []
    for s in SR.findall(body):
        if s not in strs:
            strs.append(s)
    print(f"{a} {targets[a]} {len(body)}c")
    print(f"   calls: {sorted(calls)[:8]}")
    if strs:
        print(f"   strs: {strs[:5]}")
