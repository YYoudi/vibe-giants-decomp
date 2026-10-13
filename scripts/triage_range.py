#!/usr/bin/env python3
"""Triage unnamed functions in an address range: strings + named-call patterns."""
import csv, json, glob, re, collections, os, sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PS2 = os.path.join(REPO, "ps2_symbols")
EXP = os.path.join(REPO, "ghidra_exports")

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

named = {}
for f in ["unified_names_1449.csv", "crt_llm_names.csv", "crt_llm_names2.csv", "bsim_wave.csv",
          "module_names_wave.csv", "module_bands.csv", "system_wave2.csv",
          "llm_strings_wave.csv", "llm_strings_wave2.csv", "llm_wave4.csv", "callpat_wave.csv"]:
    try:
        for r in csv.DictReader(open(os.path.join(PS2, f), encoding="utf-8")):
            if float(r["conf"]) >= 0.9:
                named[norm(r["pc_addr"])] = r["ps2_name"]
    except FileNotFoundError:
        pass

funcs = {}
claimed = set()
for cf in glob.glob(os.path.join(PS2, "*.csv")):
    try:
        for r in csv.DictReader(open(cf, encoding="utf-8")):
            if "pc_addr" in r and r.get("pc_addr"):
                claimed.add(norm(r["pc_addr"]))
    except (FileNotFoundError, KeyError, ValueError):
        pass
for f in glob.glob(os.path.join(EXP, "*.json")):
    d = json.load(open(f, encoding="utf-8"))
    if d["address"] not in claimed:
        funcs[d["address"]] = d

    d = json.load(open(f, encoding="utf-8"))
    if d["address"] not in claimed:
        funcs[d["address"]] = d

CALL = re.compile(r"\bFUN_([0-9a-fA-F]{8})\s*\(")
SR = re.compile(r'"([^"\\]{4,50})"')
lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
n = 0
for a, d in sorted(funcs.items(), key=lambda kv: int(kv[0], 16)):
    ai = int(a, 16)
    if not (lo <= ai < hi):
        continue
    pass
    body = d["decompiled"]
    calls = set()
    for m in CALL.finditer(body):
        c = norm(m.group(1))
        if c in named:
            calls.add(named[c].split("__F")[0])
    strs = []
    for s in SR.findall(body):
        if s not in strs:
            strs.append(s)
    n += 1
    print(f"{a} {len(body)}c calls={sorted(calls)[:5]} str={strs[:4]}")
print(f"TOTAL unnamed in [{lo:X},{hi:X}): {n}")
