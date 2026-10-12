#!/usr/bin/env python3
"""Organize the full decompilation into per-module C files using the original
source-tree mapping recovered from assert strings (func_source_map_1449.json).

Output: decompiled/gog144_modules/
  <dir>_<file>.c        functions of one original source file
  _unmapped_<n>.c       functions with no source-file evidence (by address bands)
  _INDEX.md             module table with function counts and named-function stats
"""
import json, os, re, collections

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(REPO, "decompiled", "gog144_full", "all_decompiled.c")
MAP = os.path.join(REPO, "decompiled", "func_source_map_1449.json")
OUT = os.path.join(REPO, "decompiled", "gog144_modules")

DELIM = re.compile(r"^/\* ===== (.+?) @ 0x([0-9A-Fa-f]{8}) ===== \*/", re.M)

def main():
    os.makedirs(OUT, exist_ok=True)
    srcmap = json.load(open(MAP, encoding="utf-8"))
    text = open(SRC, encoding="utf-8").read()
    hits = list(DELIM.finditer(text))

    buckets = collections.defaultdict(list)   # module -> [(addr, name, body)]
    for i, m in enumerate(hits):
        name, hx = m.group(1), m.group(2)
        addr = int(hx, 16)
        body = text[m.end(): hits[i + 1].start() if i + 1 < len(hits) else len(text)].strip("\n")
        module = srcmap.get(f"{addr:08x}")
        if module is None:
            module = f"_unmapped_{(addr >> 16):04x}"   # 64KB address band
        buckets[module].append((addr, name, body))

    index = []
    for module in sorted(buckets):
        fns = buckets[module]
        named = sum(1 for _, n, _ in fns if not n.startswith("FUN_"))
        safe = module.replace("/", "_").replace("\\", "_")
        path = os.path.join(OUT, safe + ".c")
        with open(path, "w", encoding="utf-8") as f:
            f.write(f"/* Giants 1.449 — module {module}\n"
                    f" * {len(fns)} functions ({named} named) — decompiled, names from PS2 symbols\n"
                    f" * Original source: C:\\Giants\\source\\{module}.c(pp) (assert-string evidence)\n"
                    f" */\n\n")
            for addr, n, body in sorted(fns):
                f.write(f"/* ===== {n} @ 0x{addr:08X} ===== */\n{body}\n\n")
        index.append((module, len(fns), named, safe + ".c"))

    with open(os.path.join(OUT, "_INDEX.md"), "w", encoding="utf-8") as f:
        f.write("# Giants 1.449 — decompiled modules\n\n")
        f.write("| module | functions | named | file |\n|---|---|---|---|\n")
        for module, n, named, fname in sorted(index, key=lambda x: -x[1]):
            f.write(f"| {module} | {n} | {named} | {fname} |\n")
    total = sum(n for _, n, _, _ in index)
    print(f"wrote {len(index)} module files, {total} functions -> {OUT}")

if __name__ == "__main__":
    main()
