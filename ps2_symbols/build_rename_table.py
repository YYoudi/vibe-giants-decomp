#!/usr/bin/env python3
"""
#1 — Build a ready-to-consume RENAME + TYPE table from the validated PC<->PS2 matches.

Consumes (read-only):
  pc_ps2_matches_full.csv   (PC addr -> PS2 addr, conf, tier)
  SLUS_201.78.symbols.csv   (PS2 addr -> full demangled signature)
Produces (in ps2_symbols/):
  pc_rename_apply.csv       pc_addr, apply_name, ps2_demangled, params, conf, tier, notes
  apply_renames_ghidra.py   Ghidra script (Jython) that renames+comments each safe match

apply_name = a clean C identifier (the demangled base, sanitized, de-duplicated).
  - conf >= 0.9  -> notes="SAFE_APPLY"   (the rock-solid tier the PC agent applies now)
  - 0.6..0.8    -> notes="REVIEW"        (1-hop propagation, light review)
  - < 0.6       -> notes="DRAFT"         (multi-hop, review on touch)
Name collisions (>=2 PC funcs wanting the same base) are resolved by keeping the
highest-confidence one and flagging the losers "COLLISION_REVIEW".
"""
import csv, os, re, collections

HERE = os.path.dirname(os.path.abspath(__file__))

# load PS2 demangled signatures by address
ps2_sig = {}
with open(os.path.join(HERE, "SLUS_201.78.symbols.csv"), encoding="utf-8") as f:
    for r in csv.DictReader(f):
        if r["kind"] == "FUNC":
            ps2_sig[int(r["addr"], 16)] = r["demangled"]

def base_and_params(demangled):
    if "(" in demangled:
        base, rest = demangled.split("(", 1)
        params = rest.rstrip(")")
    else:
        base, params = demangled, ""
    return base.strip(), params.strip()

def sanitize(name):
    name = re.sub(r"[^A-Za-z0-9_]", "_", name)
    if name and name[0].isdigit():
        name = "_" + name
    return name or "unnamed"

# load matches
matches = []
with open(os.path.join(HERE, "pc_ps2_matches_full.csv"), encoding="utf-8") as f:
    for r in csv.DictReader(f):
        ps2a = int(r["ps2_addr"], 16)
        dem = ps2_sig.get(ps2a, r["ps2_name"])
        base, params = base_and_params(dem)
        matches.append({
            "pc_addr": r["pc_addr"],
            "ps2_addr": r["ps2_addr"],
            "demangled": dem,
            "base": base,
            "apply_name": sanitize(base),
            "params": params,
            "conf": float(r["conf"]),
            "tier": r["tier"],
        })
matches.sort(key=lambda m: -m["conf"])

# resolve collisions on apply_name: highest conf wins, losers flagged
best_for_name = {}
flagged = []
for m in matches:
    nm = m["apply_name"]
    if nm not in best_for_name:
        best_for_name[nm] = m
    else:
        flagged.append(m)

def tier_note(conf):
    if conf >= 0.9: return "SAFE_APPLY"
    if conf >= 0.6: return "REVIEW"
    return "DRAFT"

# emit CSV
out_csv = os.path.join(HERE, "pc_rename_apply.csv")
with open(out_csv, "w", newline="", encoding="utf-8") as f:
    w = csv.writer(f)
    w.writerow(["pc_addr", "apply_name", "ps2_demangled", "params", "conf", "tier", "notes"])
    for m in matches:
        note = tier_note(m["conf"])
        if m in flagged:
            note = "COLLISION_REVIEW"
        w.writerow([m["pc_addr"], m["apply_name"], m["demangled"], m["params"],
                    f"{m['conf']:.2f}", m["tier"], note])

# emit Ghidra apply script (safe tier only by default)
safe = [m for m in matches if m["conf"] >= 0.9 and m not in flagged]
ghp = os.path.join(HERE, "apply_renames_ghidra.py")
with open(ghp, "w", encoding="utf-8") as f:
    f.write("# Ghidra (Jython) script: apply PS2-derived names to matched PC functions.\n")
    f.write("# Generated from pc_ps2_matches_full.csv, conf>=0.9 only. Safe tier.\n")
    f.write("# @category GiantsRE\n")
    f.write("from ghidra.program.model.symbol import SourceType\n\n")
    f.write("RENAMES = [\n")
    for m in safe:
        f.write(f"    (0x{m['pc_addr']}, {m['apply_name']!r}, {m['demangled']!r}),\n")
    f.write("]\n\n")
    f.write("fm = currentProgram.getFunctionManager()\n")
    f.write("ok = miss = 0\n")
    f.write("for addr, name, sig in RENAMES:\n")
    f.write("    fn = fm.getFunctionContaining(toAddr(addr))\n")
    f.write("    if fn is None:\n")
    f.write("        print('  miss 0x%08x' % addr); miss += 1; continue\n")
    f.write("    fn.setName(name, SourceType.USER_DEFINED)\n")
    f.write("    fn.setComment('PS2 match: ' + sig)\n")
    f.write("    ok += 1\n")
    f.write("print('applied %d, missed %d' % (ok, miss))\n")

n_safe = sum(1 for m in matches if m["conf"] >= 0.9 and m not in flagged)
n_review = sum(1 for m in matches if 0.6 <= m["conf"] < 0.9 and m not in flagged)
n_draft = sum(1 for m in matches if m["conf"] < 0.6 and m not in flagged)
n_coll = len(flagged)
print(f"[+] pc_rename_apply.csv: {len(matches)} rows")
print(f"    SAFE_APPLY (conf>=0.9): {n_safe}")
print(f"    REVIEW (0.6-0.8)     : {n_review}")
print(f"    DRAFT (<0.6)         : {n_draft}")
print(f"    COLLISION_REVIEW     : {n_coll}")
print(f"[+] apply_renames_ghidra.py: {len(safe)} safe renames (conf>=0.9)")
