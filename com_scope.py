#!/usr/bin/env python3
"""
M6 — COM subsystem scope mapper.

Extracts the full transitive call subtree from a root function (default
PreInitCheck 0x005c45f0) through the Ghidra callee graph, so we know the EXACT
scope of the COM/object-creation porting effort (no more "discovering stubs one
at a time"). Also scans all decompiled bodies for the COM-object instantiation
pattern (operator_new + vtable assignment) to enumerate every COM class.

Reads ghidra_exports/*.json (offline, no Ghidra connection).

Usage:
    python com_scope.py                       # default: PreInitCheck root, depth 12
    python com_scope.py 0042fc00              # different root (InitCOMSubsystem)
    python com_scope.py 005c45f0 --depth 8    # shallower
"""
import json, glob, os, sys, re
from collections import deque, defaultdict

EXPORTS = "ghidra_exports"

def load_functions():
    """Load all function JSONs -> {addr: {name, decompiled, callees:[addr], callers}}"""
    fns = {}
    for f in glob.glob(os.path.join(EXPORTS, "00*.json")):
        try:
            d = json.load(open(f, encoding="utf-8"))
        except Exception:
            continue
        addr = d.get("address", "").lower().lstrip("0")
        if not addr:
            continue
        addr = ("0" * (8 - len(addr))) + addr if len(addr) <= 8 else addr
        callees = set()
        for c in d.get("callees", []):
            ca = c.get("addr", "").lower().lstrip("0")
            if ca:
                callees.add(ca.rjust(8, "0") if len(ca) <= 8 else ca)
        fns[addr] = {
            "name": d.get("name", addr),
            "decompiled": d.get("decompiled", ""),
            "callees": callees,
            "callers": set(),
        }
    # build reverse (callers) + resolve callee names
    for addr, d in fns.items():
        for c in d["callees"]:
            if c in fns:
                fns[c]["callers"].add(addr)
    return fns

def call_tree(fns, root, max_depth=12):
    """BFS from root, return {addr: depth} for all reachable within max_depth."""
    root = root.lower().lstrip("0").rjust(8, "0")
    seen = {root: 0}
    q = deque([(root, 0)])
    while q:
        addr, depth = q.popleft()
        if depth >= max_depth:
            continue
        d = fns.get(addr)
        if not d:
            continue
        for c in d["callees"]:
            if c not in seen:
                seen[c] = depth + 1
                q.append((c, depth + 1))
    return seen

def com_class_scan(fns):
    """Scan all bodies for COM-object instantiation pattern:
       operator_new(SIZE); obj[0] = &PTR_FUN_vtable; obj[1] = 1 (refcount)."""
    # Pattern: a vtable pointer assigned from PTR_FUN_xxxxxx (.rdata ~0x65-0x66xxxx)
    vt_pat = re.compile(r'PTR_FUN_([0-9a-f]{6,8})')
    classes = defaultdict(list)  # vtable_addr -> [func_addrs that instantiate it]
    for addr, d in fns.items():
        if "operator_new" not in d["decompiled"]:
            continue
        for m in vt_pat.finditer(d["decompiled"]):
            vt = m.group(1).rjust(8, "0")
            classes[vt].append(addr)
    return classes

def main():
    root = sys.argv[1] if len(sys.argv) > 1 and not sys.argv[1].startswith("--") else "005c45f0"
    max_depth = 12
    if "--depth" in sys.argv:
        max_depth = int(sys.argv[sys.argv.index("--depth") + 1])

    print(f"Loading ghidra_exports/...", end=" ", flush=True)
    fns = load_functions()
    print(f"{len(fns)} functions loaded")

    root = root.lower().lstrip("0").rjust(8, "0")
    print(f"\n=== Call subtree from {fns[root]['name'] if root in fns else root} (depth<={max_depth}) ===")
    tree = call_tree(fns, root, max_depth)
    print(f"Reachable: {len(tree)} functions")

    # Bucket by depth
    by_depth = defaultdict(list)
    for addr, depth in tree.items():
        by_depth[depth].append(addr)
    print("\nBy depth:")
    for depth in sorted(by_depth):
        print(f"  depth {depth}: {len(by_depth[depth])} functions")

    # Top functions by caller count (priority for porting — shared infra first)
    print("\n=== Top 25 by GLOBAL caller count (shared infra, port first) ===")
    ranked = sorted(tree.items(),
                    key=lambda kv: -len(fns.get(kv[0], {}).get("callers", set())))
    print(f"{'addr':<10} {'callers':>7} {'callees':>7} {'lines':>6}  name")
    for addr, depth in ranked[:25]:
        d = fns.get(addr, {})
        lines = d.get("decompiled", "").count("\n")
        n_callers = len(d.get("callers", set()))
        n_callees = len(d.get("callees", set()))
        print(f"{addr:<10} {n_callers:>7} {n_callees:>7} {lines:>6}  {d.get('name','')[:40]}")

    # COM class instantiation scan
    print("\n=== COM object classes (operator_new + PTR_FUN vtable) ===")
    classes = com_class_scan(fns)
    print(f"Found {len(classes)} distinct COM-class vtables instantiated:")
    for vt, instancers in sorted(classes.items(), key=lambda kv: -len(kv[1]))[:30]:
        print(f"  PTR_FUN_{vt}: instantiated in {len(instancers)} funcs "
              f"(e.g. {instancers[0]})")

    # Summary
    print(f"\n=== SCOPE SUMMARY ===")
    print(f"COM subtree reachable from {root}: {len(tree)} functions")
    print(f"Distinct COM-class vtables: {len(classes)}")

if __name__ == "__main__":
    main()
