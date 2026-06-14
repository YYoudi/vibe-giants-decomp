#!/usr/bin/env python3
"""
#3 — Build a TYPE CATALOG from the 4769 demangled PS2 signatures.

Reveals the engine's type architecture so the PC agent can name/type its Ghidra
structs: which types exist, how central each is (param frequency), and which
functions operate on each. The most-used pointer types are the structs worth
recovering first (OBJECT* is the universal game object).

Output: ps2_symbols/TYPE_CATALOG.md
"""
import csv, os, re, collections

HERE = os.path.dirname(os.path.abspath(__file__))

def parse_params(demangled):
    if "(" not in demangled:
        return []
    params = demangled.split("(", 1)[1].rstrip(")")
    if not params or params == "void":
        return []
    # split top-level commas (no nested parens in these signatures)
    out = []
    depth = 0
    cur = ""
    for ch in params:
        if ch == "(": depth += 1
        elif ch == ")": depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip()); cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out

def base_type(param):
    p = param.replace("/*same*/", "").strip()
    # strip pointer/ref markers for the "struct" view, but keep a pointer flag
    is_ptr = "*" in p
    p = p.replace("*","").replace("&","").strip()
    # drop qualifiers
    for q in ("const ","volatile ","unsigned ","signed "):
        p = p.replace(q,"")
    p = p.strip()
    # normalize primitives
    prims = {"int":"int","long":"long","short":"short","char":"char",
             "float":"float","double":"double","bool":"bool","void":"void"}
    return p, is_ptr

rows = []
with open(os.path.join(HERE, "SLUS_201.78.symbols.csv"), encoding="utf-8") as f:
    for r in csv.DictReader(f):
        if r["kind"] == "FUNC":
            rows.append((int(r["addr"],16), r["demangled"]))

type_freq = collections.Counter()                 # type -> #params using it
ptr_freq = collections.Counter()                  # type -> #params using it as pointer
type_funcs = collections.defaultdict(set)         # type -> set(func base name)
func_paramcount = collections.Counter()           # arity distribution

named_types = collections.defaultdict(int)        # capitalized (struct-like) types

for addr, dem in rows:
    base = re.split(r"\(", dem)[0].strip()
    ps = parse_params(dem)
    func_paramcount[len(ps)] += 1
    for p in ps:
        t, is_ptr = base_type(p)
        if not t: continue
        type_freq[t] += 1
        if is_ptr: ptr_freq[t] += 1
        type_funcs[t].add(base)
        if t and t[0].isupper():
            named_types[t] += 1

# struct-like types ranked by pointer-param usage (the structs to recover first)
struct_ranked = sorted(((t,c) for t,c in ptr_freq.items() if t and t[0].isupper()),
                       key=lambda x:-x[1])

out = []
out.append("# Giants engine — TYPE CATALOG (from PS2 signatures)\n")
out.append("Derived from 4769 demangled PS2 function signatures. Shows the engine's type")
out.append("architecture to guide naming/typing the PC Ghidra structs.\n")
out.append("## Most central pointer types (structs to recover FIRST)\n")
out.append("Ranked by how often each appears as a pointer parameter. `OBJECT*` is the")
out.append("universal game-object struct — recover its layout first.\n")
out.append("| type | as ptr param | total params | #funcs using it | example functions |")
out.append("|------|-------------:|-------------:|----------------:|-------------------|")
for t,c in struct_ranked[:35]:
    funcs = sorted(type_funcs[t])[:4]
    out.append(f"| `{t}*` | {c} | {type_freq[t]} | {len(type_funcs[t])} | {', '.join(funcs)} |")

out.append("\n## Primitive parameter usage\n")
out.append("| type | count |\n|------|------:|")
for t,c in type_freq.most_common(20):
    if not t[0].isupper():
        out.append(f"| `{t}` | {c} |")

out.append("\n## Function arity distribution\n")
out.append("| #params | #functions |\n|--------:|----------:|")
for k in sorted(func_paramcount):
    out.append(f"| {k} | {func_paramcount[k]} |")

out.append("\n## All named (struct-like) types seen\n")
out.append("Alphabetical — each is a candidate Ghidra struct to define on the PC side.\n")
for t in sorted(named_types):
    out.append(f"- `{t}` ({named_types[t]} param uses, {len(type_funcs[t])} funcs)")

open(os.path.join(HERE, "TYPE_CATALOG.md"), "w", encoding="utf-8").write("\n".join(out))
print(f"[+] TYPE_CATALOG.md written")
print(f"    distinct param types: {len(type_freq)}")
print(f"    named struct types: {len(named_types)}")
print(f"    top: " + ", ".join(f"{t}*({c})" for t,c in struct_ranked[:8]))
