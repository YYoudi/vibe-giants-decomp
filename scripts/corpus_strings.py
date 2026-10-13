#!/usr/bin/env python3
"""Dump string literals per function from an LLM corpus file (compact triage)."""
import re, sys

txt = open(sys.argv[1], encoding="utf-8").read()
blocks = re.split(r"/\* ===== (FUN_[0-9A-F]+) ===== \*/", txt)
for i in range(1, len(blocks), 2):
    nm, body = blocks[i], blocks[i + 1]
    seen = []
    for s in re.findall(r'"([^"\\]{4,70})"', body):
        if s not in seen:
            seen.append(s)
    print(f"{nm}: {seen[:8]}")
