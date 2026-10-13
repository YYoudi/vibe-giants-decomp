#!/usr/bin/env python3
"""Build the LLM naming corpus: unnamed functions ranked by string richness.
Output: decompiled/gog144_full/_game_llm_work.c (top N by total string bytes)
"""
import csv, json, glob, re, os, sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXP = os.path.join(REPO, "ghidra_exports")
PS2 = os.path.join(REPO, "ps2_symbols")
OUTF = os.path.join(REPO, "decompiled", "gog144_full", "_game_llm_work.c")
TOP = int(sys.argv[1]) if len(sys.argv) > 1 else 120

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

claimed = set()
for f in ["unified_names_1449.csv", "module_names_wave.csv", "module_bands.csv",
          "bsim_wave.csv", "system_wave2.csv", "crt_llm_names.csv", "crt_llm_names2.csv"]:
    try:
        for r in csv.DictReader(open(os.path.join(PS2, f), encoding="utf-8")):
            claimed.add(norm(r["pc_addr"]))
    except FileNotFoundError:
        pass

STR = re.compile(r'"((?:\\.|[^"\\])*)"')
rank = []
for f in glob.glob(os.path.join(EXP, "*.json")):
    d = json.load(open(f, encoding="utf-8"))
    a = int(d["address"], 16)
    if d["name"].startswith("FUN_") and d["address"] not in claimed and a < 0x546000:
        strs = STR.findall(d["decompiled"])
        score = sum(len(s) for s in strs)
        if score >= 6:
            rank.append((score, d["address"], len(strs)))
rank.sort(reverse=True)
print(f"unnamed funcs with rich strings: {len(rank)}")
sel = rank[:TOP]
out = []
for s, a, n in sel:
    d = json.load(open(os.path.join(EXP, f"{a}.json"), encoding="utf-8"))
    out.append((int(a, 16), d["decompiled"]))
out.sort()
with open(OUTF, "w", encoding="utf-8") as f:
    for a, body in out:
        f.write(f"/* ===== FUN_{a:08X} ===== */\n{body}\n\n")
print(f"work file: {os.path.getsize(OUTF)} bytes, {len(out)} funcs -> {OUTF}")
