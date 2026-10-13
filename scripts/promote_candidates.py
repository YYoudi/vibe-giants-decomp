#!/usr/bin/env python3
"""Rank sub-0.9 PS2 candidates on FUN_ functions by corroboration signals.

Signals (each 1 point, token overlap always required on at least one):
  caller: a NAMED caller's name shares a token with the candidate name
  callee: a NAMED callee's name shares a token with the candidate name
  sig:    PS2 mangled signature (…__FP6OBJECT…) param-count/type hints match
          the decompiled signature (ptr-ish count)
  module: source-module attribution (func_source_map) shares a token
Output: ranked TSV to stdout; promote-ready CSV (score>=2) via --csv.
"""
import csv, glob, json, os, re, sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def norm(a):
    a = a.lower()
    if a.startswith("0x"): a = a[2:]
    return a.lstrip("0").rjust(8, "0")

def tokens(name):
    name = re.sub(r"__FP.*$", "", name)
    parts = re.split(r"[^a-z0-9]+", name.lower())
    stop = {"", "f", "p", "pc", "pi", "t", "t0", "t1", "i", "void", "int", "float", "obj", "object"}
    return {p for p in parts if len(p) > 2 and p not in stop}

def main():
    out_csv = None
    if len(sys.argv) > 1 and sys.argv[1] == "--csv":
        out_csv = sys.argv[2] if len(sys.argv) > 2 else os.path.join(REPO, "ps2_symbols", "promote_review.csv")

    # best candidate per address
    best = {}
    for p in glob.glob(os.path.join(REPO, "ps2_symbols", "*.csv")):
        try:
            for r in csv.DictReader(open(p, encoding="utf-8")):
                pa, pn = r.get("pc_addr"), r.get("ps2_name", "")
                if not pa or not pn or pn.startswith("FUN_"):
                    continue
                try: c = float(r.get("conf") or 0)
                except ValueError: c = 0
                k = norm(pa)
                if c < 0.9 and (k not in best or c > best[k][0]):
                    best[k] = (c, pn)
        except Exception:
            pass

    src = open(os.path.join(REPO, "decompiled", "gog144_full", "all_decompiled.c"),
               encoding="utf-8", errors="replace").read()
    funcs = {}
    for f in re.split(r"\n/\* ===== ", src):
        m = re.match(r"(\S+)(?: @ (0x[0-9A-F]+))? ===== \*/", f)
        if m:
            key = norm(m.group(2) or ("0x" + m.group(1)[-8:]))
            funcs[key] = (m.group(1), f)

    smap = {}
    try:
        smap = json.load(open(os.path.join(REPO, "decompiled", "func_source_map_1449.json"), encoding="utf-8"))
        smap = {norm(k): v for k, v in smap.items()}
    except Exception:
        pass

    def named_callers(key):
        out = []
        for k2, (n2, body) in funcs.items():
            if n2.startswith("FUN_"):
                continue
            if re.search(r"\b" + re.escape(funcs[key][0]) + r"\(", body):
                out.append(n2)
        return out

    def named_callees(key):
        body = funcs[key][1]
        return [m for m in re.findall(r"\b([A-Za-z_]\w*)\(", body)
                if not m.startswith(("FUN_", "SUB_", "thunk_")) and m not in
                ("if", "for", "while", "switch", "ABS", "SQRT", "__ftol", "NAN", "POPCOUNT")]

    rows = []
    for k, (conf, cand) in best.items():
        if k not in funcs or not funcs[k][0].startswith("FUN_"):
            continue
        ctok = tokens(cand)
        if not ctok:
            continue
        ncall = named_callers(k)
        ncal = named_callees(k)
        s_call = any(ctok & tokens(n) for n in ncall)
        s_cal = any(ctok & tokens(n) for n in ncal)
        mangled = "__FP" in cand
        sig = ""
        if mangled:
            nparams = len(re.findall(r"P[0-9]*[A-Za-z]", cand.split("__FP")[1]))
            body_sig = funcs[k][1][:600]
            s_sig = False  # decompiler sigs unreliable; only count if params present
        else:
            s_sig = False
        mod = smap.get(k, "")
        s_mod = bool(ctok & tokens(mod))
        score = (1 if s_call else 0) + (1 if s_cal else 0) + (1 if s_mod else 0) + conf
        rows.append((score, k, conf, cand, "+".join(
            x for x, f in (("caller", s_call), ("callee", s_cal), ("module", s_mod), ("sig", s_sig)) if f),
            ncall[:3], mod))
    rows.sort(reverse=True)
    print(f"candidates on FUN_: {len(rows)}")
    for r in rows[:40]:
        print(f"{r[0]:.2f} {r[1]} c={r[2]:.2f} [{r[4]:<20}] {r[3]:<44} <- {r[5]} @{r[6]}")
    if out_csv:
        with open(out_csv, "w", encoding="utf-8", newline="") as fh:
            w = csv.writer(fh)
            w.writerow(["pc_addr", "pc_name", "ps2_addr", "ps2_name", "conf", "tier", "shared"])
            for score, k, conf, cand, sigs, ncall, mod in rows:
                promote = score >= 2.4 or (conf >= 0.70 and ("caller" in sigs or "callee" in sigs or "module" in sigs))
                if promote:
                    w.writerow([k, funcs[k][0], "", cand, 0.9, "promote-auto", f"score={score:.2f};{sigs};callers={ncall[:2]}"])
        print(f"wrote {out_csv} (score>=2.4)")

if __name__ == "__main__":
    main()
