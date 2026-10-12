#!/usr/bin/env python3
"""CRT pass: identify MSVC runtime library functions in the 1.449 decompilation
by distinctive constants and strings, plus CRT-region relationship rules.

Fingerprints (VC6-era msvcrt/libc):
  rand/srand      : imul 0x343FD, add 0x269EC3 (also 0x343fd >> shifts)
  _finite/_isnan  : fbits & 0x7FF00000 / 0x7FF80000 comparisons
  _ftol           : fnstcw/fistp + 0xFFFFF prologue fix (search 'fistp' won't
                    appear in decomp — use __ftol bytehash anchor instead)
  _initterm       : walks pointer table, calls each non-null
  _NMSG_WRITE box : refs "Microsoft Visual C++ Runtime Library" + MessageBoxA
  runtime errors  : refs "runtime error" / R6xxx message strings
  _strlwr/_strupr : -0x41/'a'-'A' 0x20 loops (weak — skip)
  memcpy/memset   : found via callers of __NMSG or known patterns (skip inline)

Emission: only HIGH-PRECISION names here; relationships (callers named) gate
the weaker ones. Output: ps2_symbols/crt_names_1449.csv (apply-CSV format).
"""
import json, os, re, glob, collections, csv

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXP = os.path.join(REPO, "ghidra_exports")

def main():
    funcs = {}
    for f in glob.glob(os.path.join(EXP, "*.json")):
        d = json.load(open(f, encoding="utf-8"))
        funcs[d["address"]] = d

    named = {a: d["name"] for a, d in funcs.items() if not d["name"].startswith("FUN_")}
    sizes = {r["addr"].lower(): int(r["size"]) for r in
             csv.DictReader(open(os.path.join(REPO, "decompiled", "v149_func_bytes.csv"), encoding="utf-8"))}
    out = []
    used_names = set(named.values())

    def add(addr, name, rule, conf=1.0):
        if addr in named:            # already has a name — skip
            return
        base = name
        i = 2
        while name in used_names:    # Ghidra rejects duplicates
            name = f"{base}_{i}"; i += 1
        used_names.add(name)
        out.append({"pc_addr": addr, "pc_name": funcs[addr]["name"],
                    "ps2_addr": "", "ps2_name": name, "conf": conf,
                    "tier": f"crt-{rule}", "shared": ""})

    # 1) rand: constant pair 0x343fd / 0x269ec3
    for a, d in funcs.items():
        body = d["decompiled"]
        if ("0x343fd" in body.lower() and "0x269ec3" in body.lower()):
            add(a, "rand", "rand-const")
        elif "0x343fd" in body.lower():
            add(a, "srand_or_rand_seed", "rand-const-half", 0.6)  # reviewed only

    # 2) _finite / _isnan masks — only tiny standalone helpers count
    for a, d in funcs.items():
        if sizes.get(a, 1 << 30) > 120:
            continue
        body = d["decompiled"]
        if re.search(r"0x7ff00000", body, re.I) and re.search(r"0x7ff80000|0xfff80000", body, re.I):
            add(a, "_isnan", "fp-masks", 0.95)
        elif re.search(r"0x7ff00000", body, re.I):
            add(a, "_finite", "fp-masks", 0.9)

    # 3) runtime error box: references the VC6 caption + MessageBoxA import usage
    for a, d in funcs.items():
        body = d["decompiled"]
        if "Microsoft Visual C++ Runtime Library" in body:
            add(a, "__rt_error_box", "rtc-string", 0.95)
        if re.search(r"runtime error", body, re.I):
            add(a, "_NMSG_WRITE", "rtc-string", 0.9)

    # 4) _initterm: pattern '(*DAT_xxx)()' loops over table of pointers
    for a, d in funcs.items():
        body = d["decompiled"]
        if re.search(r"\(\*(?:code\s*\*)?\s*\*", body) and "0x0" in body and "while" in body:
            # too weak alone — only if inside CRT region and small
            addr = int(a, 16)
            if 0x53A000 <= addr < 0x55001C and len(body) < 1200:
                add(a, "_initterm_cand", "crt-shape", 0.5)

    # 5) relationship: unknown function called ONLY by already-CRT-named funcs
    crt_named = {a for a, n in named.items()}  # e.g. _strncpy etc from earlier waves
    callers = collections.defaultdict(set)
    CALL = re.compile(r"\bFUN_([0-9a-fA-F]{8})\s*\(")
    for a, d in funcs.items():
        for m in CALL.finditer(d["decompiled"]):
            callers[m.group(1).lower()].add(a)
    for a, cs in callers.items():
        if a in funcs and funcs[a]["name"].startswith("FUN_"):
            if cs and all(c in crt_named for c in cs):
                # only callees are CRT-named and all callers CRT-named: strong hint
                addr = int(a, 16)
                if 0x53A000 <= addr < 0x55001C:
                    add(a, f"crt_helper_of_{len(cs)}", "crt-region-rel", 0.55)

    seen = {}
    for r in out:
        k = r["pc_addr"]
        if k not in seen or r["conf"] > seen[k]["conf"]:
            seen[k] = r
    rows = sorted(seen.values(), key=lambda r: -r["conf"])
    outp = os.path.join(REPO, "ps2_symbols", "crt_names_1449.csv")
    with open(outp, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["pc_addr", "pc_name", "ps2_addr", "ps2_name", "conf", "tier", "shared"])
        w.writeheader(); w.writerows(rows)
    print(f"CRT candidates: {len(rows)} (conf>=0.9: {sum(1 for r in rows if r['conf']>=0.9)}) -> {outp}")
    for r in rows[:15]:
        print(f"  {r['pc_addr']} {r['ps2_name']:<24} {r['conf']} {r['tier']}")

if __name__ == "__main__":
    main()
