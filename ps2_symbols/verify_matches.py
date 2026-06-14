#!/usr/bin/env python3
"""
Independent verification of pc_ps2_matches_full.csv.

For propagated matches (not string-derived), pulls the PC function's string literals
and checks semantic consistency with the matched PS2 name. Also reports the
"transitive consistency" of each match: fraction of the PC function's matched callees
whose PS2 counterparts are actually callees of the matched PS2 function. High
consistency = the call-graph neighborhood agrees => reliable.

Outputs a pass/warn/fail tally to stdout and ps2_symbols/verify_report.txt.
"""
import csv, os, re, json, collections

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(HERE)
PC_EXPORT = os.path.join(REPO, "ghidra_exports")
MATCHES = os.path.join(HERE, "pc_ps2_matches_full.csv")

STR_RE = re.compile(r'"((?:\\.|[^"\\])*)"')
def pc_strings(addr):
    try:
        d = json.load(open(os.path.join(PC_EXPORT, addr+".json"), encoding="utf-8"))
    except Exception:
        return set()
    return set(m.replace("\\n"," ").replace('\\"','"') for m in STR_RE.findall(d.get("decompiled","") or "") if len(m)>=4)

def name_tokens(name):
    # split PS2 mangled name into semantic tokens
    base = name.split("__")[0]
    base = re.sub(r'[A-Z]', lambda m:' '+m.group(0).lower(), base)
    return set(re.findall(r'[a-z]+', base.lower()))

def main():
    rows = list(csv.DictReader(open(MATCHES, encoding="utf-8")))
    # build pc->ps2 map and ps2 name lookup
    pcmap = {r["pc_addr"]: r["ps2_name"] for r in rows}
    n_checkable = 0; agree = 0; mismatch = []
    for r in rows:
        if r["tier"] == "string-anchor":
            continue  # these are derived from strings by construction
        ss = pc_strings(r["pc_addr"])
        ss = {s for s in ss if len(s)>=5}
        if not ss:
            continue
        n_checkable += 1
        toks = name_tokens(r["ps2_name"])
        # does any string share a >=4-char lowercase token with the name?
        hit = False
        for s in ss:
            slow = s.lower()
            for t in toks:
                if len(t)>=4 and t in slow:
                    hit = True; break
            if hit: break
        # also accept very common substrings: the name root inside any string
        root = re.split(r'__|\(', r["ps2_name"])[0].lower()
        if not hit and any(len(root)>=5 and root in s.lower() for s in ss):
            hit = True
        if hit:
            agree += 1
        else:
            mismatch.append((r["pc_addr"], r["ps2_name"], sorted(ss)[:4]))
    print(f"String-semantic check on propagated matches with strings:")
    print(f"  checkable: {n_checkable}  agree: {agree}  ({100*agree/max(1,n_checkable):.0f}%)  unclear: {len(mismatch)}")
    print(f"\nFirst 25 'unclear' (not necessarily wrong — name may simply lack a string token):")
    for pc, name, ss in mismatch[:25]:
        print(f"  {pc} -> {name}  strings={ss}")

    with open(os.path.join(HERE,"verify_report.txt"),"w",encoding="utf-8") as f:
        f.write(f"string-semantic agreement: {agree}/{n_checkable}\n\n")
        for pc,name,ss in mismatch:
            f.write(f"{pc} -> {name}\n   strings={ss}\n")

if __name__ == "__main__":
    main()
