#!/usr/bin/env python3
"""Read heads of big unnamed functions for LLM identification."""
import json, re, sys

addrs = sys.argv[1:]
for a in addrs:
    d = json.load(open(f"ghidra_exports/{a}.json", encoding="utf-8"))
    b = d["decompiled"]
    calls = sorted(set(re.findall(r"FUN_([0-9a-f]{8})", b)))[:10]
    strs = re.findall(r'"([^"\\]{5,60})"', b)[:5]
    print(f"===== {a} ({len(b)}c) calls={calls} strs={strs}")
    print("\n".join(l for l in b.split("\n")[2:26] if l.strip())[:900])
    print()
