#!/usr/bin/env python3
"""Constant-anchor matcher PC <-> PS2.

Game magic constants (enums, object ids, flags, colors, sizes) are identical
in the PS2 (GCC/MIPS) and PC (MSVC/x86) builds because they share C++ source.
A function pair sharing RARE constants anchors a match, same contract as the
string-anchor matcher.

PS2 side: capstone word-by-word decode per symtab function, collecting
immediate operands (lui/addiu/ori and general imm ops).
PC side: integer literals from the decompiled bodies.

Output: ps2_symbols/pc_ps2_const_anchors_1449.csv (append-ready format for
match_propagate seeds: pc_addr,pc_name,ps2_addr,ps2_name,shared,conf)
"""
import csv, json, os, re, glob, collections

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(HERE)
PS2_ELF = os.path.join(HERE, "SLUS_201.78")
EXP = os.path.join(REPO, "ghidra_exports")

MIN_CONST = 0x100          # ignore tiny values
EXCL_RE = re.compile(r"^0x00[456][0-9a-f]{5}$", re.I)   # image VAs

def load_ps2():
    from elftools.elf.elffile import ELFFile
    raw = open(PS2_ELF, "rb").read()
    e = ELFFile(open(PS2_ELF, "rb"))
    st = e.get_section_by_name(".symtab")
    funcs = {s["st_value"]: (s.name, s["st_size"]) for s in st.iter_symbols()
             if s["st_info"]["type"] == "STT_FUNC" and s["st_size"] > 0 and s.name}
    text = e.get_section_by_name(".text")
    t_addr, t_off, t_size = text["sh_addr"], text["sh_offset"], text["sh_size"]
    return raw, funcs, t_addr, t_off, t_size

def ps2_consts():
    """Per-function full constants via lui/addiu/ori register tracking
    (MIPS splits 32-bit constants across two instructions)."""
    import capstone
    raw, funcs, t_addr, t_off, t_size = load_ps2()
    md = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 + capstone.CS_MODE_LITTLE_ENDIAN)
    data = raw[t_off:t_off + t_size]
    out = collections.defaultdict(set)
    for faddr, (fname, fsize) in funcs.items():
        off = faddr - t_addr
        if off < 0 or off + fsize > t_size:
            continue
        regs = {}
        consts = set()
        p = off
        end = off + fsize
        while p + 4 <= end:
            ins = next(md.disasm(data[p:p + 4], t_addr + p), None)
            p += 4
            if ins is None:
                continue
            parts = ins.op_str.replace(" ", "").split(",")
            mn = ins.mnemonic
            def imm(tok):
                try:
                    return int(tok, 0)
                except ValueError:
                    return None
            if mn == "lui" and len(parts) == 2:
                v = imm(parts[1])
                if v is not None:
                    regs[parts[0]] = (v & 0xFFFF) << 16
            elif mn in ("addiu", "addi") and len(parts) == 3:
                rd, rs, tok = parts
                v = imm(tok)
                if v is None:
                    continue
                sv = v - 0x10000 if v >= 0x8000 else v
                ea = (regs.get(rs, 0) + sv) & 0xFFFFFFFF
                if ea >= MIN_CONST and not EXCL_RE.match(hex(ea)):
                    consts.add(ea)
                if rd.startswith("$"):
                    regs[rd] = ea
            elif mn == "ori" and len(parts) == 3:
                rd, rs, tok = parts
                v = imm(tok)
                if v is None:
                    continue
                ea = (regs.get(rs, 0) | (v & 0xFFFF)) & 0xFFFFFFFF
                if ea >= MIN_CONST and not EXCL_RE.match(hex(ea)):
                    consts.add(ea)
                if rd.startswith("$"):
                    regs[rd] = ea
            else:
                for tok in parts:
                    v = imm(tok)
                    if v is not None and v >= MIN_CONST and not EXCL_RE.match(hex(v)):
                        consts.add(v)
        if consts:
            out[faddr] = consts
    return out

STR_LIT = re.compile(r"\b0x[0-9a-fA-F]{5,8}\b|\b\d{4,10}\b")

def pc_consts():
    out = collections.defaultdict(set)
    for f in glob.glob(os.path.join(EXP, "*.json")):
        d = json.load(open(f, encoding="utf-8"))
        a = d["address"]
        for tok in STR_LIT.findall(d["decompiled"]):
            try:
                v = int(tok, 0)
            except ValueError:
                continue
            if v >= MIN_CONST and not EXCL_RE.match(hex(v)):
                out[a].add(v)
    return out

def main():
    print("[*] PS2 constants ...")
    psc = ps2_consts()
    print(f"    {len(psc)} PS2 funcs with constants")
    pcc = pc_consts()
    print(f"    {len(pcc)} PC funcs with constants")

    ps2_idx = collections.defaultdict(set)
    globfreq = collections.Counter()
    for fa, cs in psc.items():
        for c in cs:
            ps2_idx[c].add(fa)
            globfreq[c] += 1
    for cs in pcc.values():
        for c in cs:
            globfreq[c] += 1

    rows = []
    for a149, cs in pcc.items():
        vote = collections.Counter()
        shared = set()
        for c in cs:
            cands = ps2_idx.get(c)
            if not cands:
                continue
            w = 1.0 / max(1, globfreq[c])
            for pf in cands:
                vote[pf] += w
        if not vote:
            continue
        ranked = vote.most_common()
        best, bs = ranked[0]
        sec = ranked[1][1] if len(ranked) > 1 else 0
        dom = bs / (bs + sec) if bs + sec else 1.0
        # count distinct shared rare constants
        shared = [c for c in cs if best in ps2_idx.get(c, set()) and globfreq[c] <= 4]
        if not shared:
            continue
        conf = round(dom * min(1.0, len(shared) / 3.0), 3)
        rows.append({"pc_addr": a149, "pc_name": "FUN_" + a149.upper(),
                     "ps2_addr": f"0x{best:08x}", "ps2_name": "PENDING",
                     "shared": len(shared), "conf": conf,
                     "sample_shared": " | ".join(hex(c) for c in shared[:4])})
    rows.sort(key=lambda r: -r["conf"])
    outp = os.path.join(HERE, f"pc_ps2_const_anchors_1449.csv")
    with open(outp, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["pc_addr", "pc_name", "ps2_addr", "ps2_name", "shared", "conf", "sample_shared"])
        w.writeheader(); w.writerows(rows)
    hi = sum(1 for r in rows if r["conf"] >= 0.5)
    print(f"const anchors: {len(rows)} (conf>=0.5: {hi}) -> {outp}")

if __name__ == "__main__":
    main()
