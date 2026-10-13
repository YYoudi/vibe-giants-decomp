#!/usr/bin/env python3
"""Automated audit of PS2 candidate names (the plate-comment tier).

Evidence model (same as the manual spot-checks that verified mission_init and
teammecc_clear_mode):
  A. string evidence  — distinctive tokens of the proposed name appear in the
     function's own string literals (case-insensitive)
  B. neighbor evidence — a trusted-named caller/callee shares the proposal's
     leading token (family prefix), e.g. teammecc_clear_mode next to
     teammecc_set_mode

Promotion rule (conservative):
  A on a token >=5 chars                      -> promote
  A on a token >=4 chars AND B prefix match   -> promote
Everything else stays a comment. Output appends to verified_names.txt and
writes ps2_symbols/candidate_audit.csv for review.

Usage: python scripts/audit_candidates.py
"""
import csv, json, os, re, glob, collections

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXP = os.path.join(REPO, "ghidra_exports")
PS2 = os.path.join(REPO, "ps2_symbols")

CALL = re.compile(r"\bFUN_([0-9a-fA-F]{8})\s*\(")
STR = re.compile(r'"((?:\\.|[^"\\])*)"')
GENERIC = {"process", "logic", "init", "create", "get", "set", "update", "check",
           "draw", "load", "free", "new", "delete", "move", "shot", "item",
           "award", "setup", "the", "and", "for"}

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

def name_tokens(name):
    base = name.split("__F")[0]
    toks = [t for t in re.split(r"[^A-Za-z0-9]+", base) if t]
    return [t for t in toks if t.lower() not in GENERIC and len(t) >= 4]

def main():
    funcs = {}
    for f in glob.glob(os.path.join(EXP, "*.json")):
        d = json.load(open(f, encoding="utf-8"))
        funcs[d["address"]] = d

    callers = collections.defaultdict(set)
    callees = collections.defaultdict(set)
    for a, d in funcs.items():
        for m in CALL.finditer(d["decompiled"]):
            c = m.group(1).lower()
            if c != a:
                callers[c].add(a)
                callees[a].add(c)

    # trusted names: verified file + high-conf unified + module wave
    trusted = {}
    vfile = os.path.join(PS2, "verified_names.txt")
    if os.path.exists(vfile):
        for line in open(vfile, encoding="utf-8"):
            p = line.split()
            if len(p) >= 2:
                trusted[norm(p[0])] = p[1]
    for r in csv.DictReader(open(os.path.join(PS2, "unified_names_1449.csv"), encoding="utf-8")):
        a = norm(r["pc_addr"])
        if float(r["conf"]) >= 0.9 and a not in trusted:
            trusted[a] = r["ps2_name"]
    for r in csv.DictReader(open(os.path.join(PS2, "module_names_wave.csv"), encoding="utf-8")):
        a = norm(r["pc_addr"])
        trusted.setdefault(a, r["ps2_name"])

    promoted, report = [], []
    cand_rows = []
    for r in csv.DictReader(open(os.path.join(PS2, "unified_names_1449.csv"), encoding="utf-8")):
        if float(r["conf"]) >= 0.9:
            continue                      # already renamed
        cand_rows.append({"pc_addr": r["pc_addr"], "ps2_name": r["ps2_name"]})
    # also audit BSim comment-tier candidates (real PS2 names, sim 0.5-0.9)
    try:
        seen_c = {r["pc_addr"] for r in cand_rows}
        for r in csv.DictReader(open(os.path.join(PS2, "bsim_wave.csv"), encoding="utf-8")):
            if float(r["conf"]) >= 0.9:
                continue
            a = norm(r["pc_addr"])
            if a in seen_c:
                continue
            seen_c.add(a)
            cand_rows.append({"pc_addr": r["pc_addr"], "ps2_name": r["ps2_name"]})
    except FileNotFoundError:
        pass
    for r in cand_rows:
        a = norm(r["pc_addr"])
        if a not in funcs:
            continue
        name = r["ps2_name"]
        toks = name_tokens(name)
        if not toks:
            continue
        d = funcs[a]
        body = d["decompiled"]
        strings = " ".join(STR.findall(body)).lower()

        # A: string evidence
        hits = [t for t in toks if t.lower() in strings]
        str_hit = max((len(t) for t in hits), default=0)

        # B: neighbor family prefix
        lead = toks[0].lower()
        nb_names = [trusted[n] for n in (callers.get(a, set()) | callees.get(a, set())) if n in trusted]
        nb_match = any(nm.lower().startswith(lead) or lead in nm.lower() for nm in nb_names)

        promote = str_hit >= 5 or (str_hit >= 4 and nb_match)
        report.append({"pc_addr": a, "name": name, "tokens": " ".join(toks),
                       "str_hit": str_hit, "nb_prefix_match": nb_match,
                       "promoted": promote,
                       "evidence": "; ".join(hits[:4])})
        if promote:
            promoted.append((a, name))

    # append to verified list
    have = set()
    if os.path.exists(vfile):
        for line in open(vfile, encoding="utf-8"):
            p = line.split()
            if p:
                have.add(norm(p[0]))
    new = [(a, n) for a, n in promoted if a not in have]
    if new:
        with open(vfile, "a", encoding="utf-8") as f:
            for a, n in new:
                f.write(f"{a} {n}\n")
    with open(os.path.join(PS2, "candidate_audit.csv"), "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["pc_addr", "name", "tokens", "str_hit", "nb_prefix_match", "promoted", "evidence"])
        w.writeheader(); w.writerows(report)
    print(f"candidates audited: {len(report)}  promoted: {len(new)} (appended to verified_names.txt)")
    for a, n in new[:20]:
        print(f"  + {a} {n}")

if __name__ == "__main__":
    main()
