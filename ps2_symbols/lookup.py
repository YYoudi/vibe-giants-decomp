#!/usr/bin/env python3
"""
Lookup helper: search the PS2 (SLUS_201.78) symbol database by keyword/regex.
Used by the RE workflow to find candidate names for a PC `sub_*` function.

Examples:
    python lookup.py game_loop
    python lookup.py "reaper.*save"
    python lookup.py --obj mecc_cameras        # search named globals too
    python lookup.py --top reaper              # list the reaper* module
"""
import argparse, os, re, sys
HERE = os.path.dirname(os.path.abspath(__file__))
FUNC = os.path.join(HERE, "SLUS_201.78.functions.txt")
CSV  = os.path.join(HERE, "SLUS_201.78.symbols.csv")

def load_funcs():
    rows=[]
    for l in open(FUNC, encoding="utf-8"):
        if not l.strip(): continue
        addr,sz,dm = l.rstrip("\n").split("\t")
        rows.append((addr,int(sz),dm))
    return rows

def main():
    ap=argparse.ArgumentParser()
    ap.add_argument("pattern", nargs="?", help="regex matched against demangled name (case-insensitive)")
    ap.add_argument("--obj", help="search named globals/objects instead of functions")
    ap.add_argument("--top", help="list all functions whose name starts with this prefix")
    ap.add_argument("-l","--limit", type=int, default=60)
    a=ap.parse_args()

    if a.top is not None:
        rows=load_funcs()
        hit=[r for r in rows if re.split(r'\(',r[2])[0].lower().startswith(a.top.lower())]
        for addr,sz,dm in hit[:a.limit]:
            print(f"{addr}  {sz:6d}  {dm}")
        print(f"-- {len(hit)} match(es)"); return

    if a.obj:
        import csv
        pat=re.compile(a.obj, re.I)
        n=0
        with open(CSV, encoding="utf-8") as f:
            for r in csv.DictReader(f):
                if r["kind"]=="OBJ" and pat.search(r["demangled"]):
                    print(f"{r['addr']}  {r['demangled']}"); n+=1
                    if n>=a.limit: break
        print(f"-- {n} match(es)"); return

    if not a.pattern:
        ap.error("need a pattern (or --top / --obj)")
    rows=load_funcs()
    pat=re.compile(a.pattern, re.I)
    hit=[r for r in rows if pat.search(r[2])]
    for addr,sz,dm in hit[:a.limit]:
        print(f"{addr}  {sz:6d}  {dm}")
    print(f"-- {len(hit)} match(es)")

if __name__=="__main__":
    main()
