#!/usr/bin/env python3
"""List next unclaimed FUN_ functions by size desc, with named callers and body head.
Usage: python scripts/scan_unclaimed.py [N] [--skip addr,addr...] [--body-len 520]
"""
import csv, glob, json, os, re, sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def norm(a):
    a = a.lower()
    if a.startswith("0x"):
        a = a[2:]
    return a.lstrip("0").rjust(8, "0")

def main():
    n = int(sys.argv[1]) if len(sys.argv) > 1 and sys.argv[1].isdigit() else 8
    body_len = 520
    args = sys.argv[1:]
    skip = set()
    skipfile = os.path.join(REPO, "ps2_symbols", "unclaimed_skip.txt")
    if os.path.exists(skipfile):
        skip = {norm(x.strip()) for x in open(skipfile, encoding="utf-8")
                if x.strip() and not x.startswith("#")}
    if "--skip" in args:
        skip |= {norm(x) for x in args[args.index("--skip") + 1].split(",")}
    if "--body-len" in args:
        body_len = int(args[args.index("--body-len") + 1])

    claimed = set()
    for p in glob.glob(os.path.join(REPO, "ps2_symbols", "*.csv")):
        try:
            for r in csv.DictReader(open(p, encoding="utf-8")):
                if r.get("pc_addr"):
                    claimed.add(norm(r["pc_addr"]))
        except Exception:
            pass
    idx = json.load(open(os.path.join(REPO, "decompiled", "gog144_full", "index.json"), encoding="utf-8"))
    sizes = {}
    for r in csv.DictReader(open(os.path.join(REPO, "decompiled", "v149_func_bytes.csv"), encoding="utf-8")):
        sizes[norm(r["addr"])] = int(r["size"])
    unn = sorted(((sizes.get(norm(a), 0), norm(a)) for a, v in idx.items()
                  if v["name"].startswith("FUN_") and norm(a) not in claimed), reverse=True)
    sel = [(s, k) for s, k in unn if k not in skip][:n]
    print("unclaimed unnamed total:", len(unn))

    src = open(os.path.join(REPO, "decompiled", "gog144_full", "all_decompiled.c"),
               encoding="utf-8", errors="replace").read()
    headers = {}
    for f in re.split(r"\n/\* ===== ", src):
        m = re.match(r"(\S+)(?: @ 0x\S+)? ===== \*/", f)
        if m:
            headers[m.group(1)] = f
    for s, k in sel:
        a = k
        t = "FUN_" + a
        callers = [h for h, f in headers.items()
                   if re.search(r"\b" + re.escape(t) + r"\(", f) and h != t]
        try:
            d = json.load(open(os.path.join(REPO, "ghidra_exports", a + ".json"),
                               encoding="utf-8"))["decompiled"]
        except FileNotFoundError:
            print("=====", a, "NO-EXPORT", "<--", [c for c in callers][:4])
            continue
        print("=====", a, f"({s}B) <--", [c for c in callers][:5])
        print(d[:body_len])
        print()

if __name__ == "__main__":
    main()
