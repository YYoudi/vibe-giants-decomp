#!/usr/bin/env python3
"""Read head of specific function addresses for identification."""
import json, re, sys

for a in sys.argv[1:]:
    d = json.load(open(f"ghidra_exports/{a}.json", encoding="utf-8"))
    b = d["decompiled"]
    strs = re.findall(r'"([^"\\]{5,60})"', b)[:6]
    print(f"===== {a} ({len(b)}c) strs={strs}")
    print("\n".join(l for l in b.split("\n")[2:34] if l.strip())[:800])
    print()
