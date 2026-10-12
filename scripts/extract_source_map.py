#!/usr/bin/env python3
"""Map each 1.449 function to its ORIGINAL source file via assert/log strings
("C:\\Giants\\source\\<dir>\\<file>.c" found in decompiled bodies).
Output: decompiled/func_source_map_1449.json  {func_addr: "dir/file"}
"""
import json, glob, re, collections, os

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PAT = re.compile(r'C:[/\\]+Giants[/\\]+source[/\\]+([A-Za-z0-9_]+)[/\\]+([A-Za-z0-9_]+?)\.(?:c|cpp|h)', re.I)

def main():
    mods = collections.Counter()
    per_file = {}
    n = 0
    for f in glob.glob(os.path.join(REPO, "ghidra_exports", "*.json")):
        d = json.load(open(f, encoding="utf-8"))
        ms = PAT.findall(d["decompiled"])
        if ms:
            n += 1
            c = collections.Counter(f"{m[0]}/{m[1]}" for m in ms)
            per_file[d["address"]] = c.most_common(1)[0][0]
            mods[c.most_common(1)[0][0]] += 1
    print("functions with source-path strings:", n)
    print("unique source files:", len(mods))
    for m, c in mods.most_common(25):
        print(f"  {c:4d}  {m}")
    out = os.path.join(REPO, "decompiled", "func_source_map_1449.json")
    json.dump(per_file, open(out, "w", encoding="utf-8"), indent=1)
    print("wrote", out)

if __name__ == "__main__":
    main()
