#!/usr/bin/env python3
"""
#2 — On-demand PS2 REFERENCE for a matched PC function.

When the PC agent reaches a gameplay/object/AI function to port, it queries its PS2
counterpart (same algorithm, named, typed) for ground truth:

    python ps2_reference.py 00504a20            # one function
    python ps2_reference.py 00504a20 004a09f0    # several
    python ps2_reference.py --index              # list all 378 matched PC->PS2 names
    python ps2_reference.py --dump 00504a20      # write reference/PC_00504a20.md

Emits: PS2 name, demangled signature, size, referenced strings, callees (named),
and the MIPS disassembly. This is the "give the PS2 to be inspired" reference lib.
"""
import csv, os, re, sys, collections, bisect
from elftools.elf.elffile import ELFFile

HERE = os.path.dirname(os.path.abspath(__file__))
ELF = os.path.join(HERE, "SLUS_201.78")

def load_all():
    raw = open(ELF,"rb").read()
    e = ELFFile(open(ELF,"rb"))
    st = e.get_section_by_name(".symtab")
    fns = {s["st_value"]:(s.name, s["st_size"]) for s in st.iter_symbols()
           if s["st_info"]["type"]=="STT_FUNC" and s["st_size"]>0 and s.name}
    # demangled lookup
    dem = {}
    with open(os.path.join(HERE,"SLUS_201.78.symbols.csv"),encoding="utf-8") as f:
        for r in csv.DictReader(f):
            if r["kind"]=="FUNC": dem[int(r["addr"],16)] = r["demangled"]
    text = e.get_section_by_name(".text")
    t_addr, t_off, t_size = text["sh_addr"], text["sh_offset"], text["sh_size"]
    tb = raw[t_off:t_off+t_size]
    # string map (.rodata + .data)
    def runs(sec):
        base=sec["sh_addr"]; data=raw[sec["sh_offset"]:sec["sh_offset"]+sec["sh_size"]]; out={}
        i=0
        while i<len(data):
            j=i
            while j<len(data) and 0x20<=data[j]<=0x7e: j+=1
            if j-i>=4 and data[j]==0: out[base+i]=data[i:j].decode("ascii","replace")
            i=max(j+1,i+1)
        return out
    strmap={}; strmap.update(runs(e.get_section_by_name(".rodata"))); strmap.update(runs(e.get_section_by_name(".data")))
    ranges=[(e.get_section_by_name(".rodata")["sh_addr"], e.get_section_by_name(".rodata")["sh_addr"]+e.get_section_by_name(".rodata")["sh_size"]),
            (e.get_section_by_name(".data")["sh_addr"], e.get_section_by_name(".data")["sh_addr"]+e.get_section_by_name(".data")["sh_size"])]
    return fns, dem, tb, t_addr, strmap, ranges

def disasm_func(tb, t_addr, faddr, fsize, fns, dem, strmap, ranges):
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32+capstone.CS_MODE_LITTLE_ENDIAN)
    lines=[]; regs={}; callees=[]; strings=set()
    off=faddr-t_addr; p=off; end=off+fsize
    def inr(a): return any(lo<=a<hi for lo,hi in ranges)
    while p+4<=len(tb) and p<end:
        ins=next(md.disasm(tb[p:p+4], t_addr+p), None); p+=4
        if ins is None: continue
        annot=""
        mn=ins.mnemonic; parts=ins.op_str.replace(" ","").split(",")
        if mn in ("jal","bal"):
            try: tgt=int(ins.op_str,0)
            except ValueError: tgt=None
            if tgt is not None:
                callees.append(tgt)
                if tgt in dem: annot="  ; -> "+dem[tgt].split("(")[0]
        elif mn=="lui" and len(parts)==2 and parts[0].startswith("$"):
            try: regs[parts[0]]=(int(parts[1],0)&0xffff)<<16
            except ValueError: pass
        elif mn in ("addiu","addi") and len(parts)==3:
            rd,rs,imm=parts
            try: v=int(imm,0)
            except ValueError: continue
            sv=v-0x10000 if v>=0x8000 else v
            ea=(regs.get(rs,0)+sv)&0xFFFFFFFF
            if inr(ea) and ea in strmap: strings.add(strmap[ea]); annot="  ; \""+strmap[ea]+"\""
            if rd.startswith("$"): regs[rd]=ea
        elif mn=="ori" and len(parts)==3:
            rd,rs,imm=parts
            try: v=int(imm,0)
            except ValueError: continue
            ea=(regs.get(rs,0)|(v&0xffff))&0xFFFFFFFF
            if inr(ea) and ea in strmap: strings.add(strmap[ea]); annot="  ; \""+strmap[ea]+"\""
            if rd.startswith("$"): regs[rd]=ea
        lines.append(f"  {ins.address:08x}: {ins.mnemonic:8s} {ins.op_str}{annot}")
    return lines, callees, strings

def card(pc_addr, matches, fns, dem, tb, t_addr, strmap, ranges):
    m = matches.get(pc_addr)
    if not m:
        return f"!! no PS2 match for PC {pc_addr}"
    ps2 = m["ps2_addr"]
    name, size = fns.get(ps2, ("?",0))
    lines, callees, strings = disasm_func(tb, t_addr, ps2, size, fns, dem, strmap, ranges)
    out = []
    out.append(f"# PC {pc_addr}  <-  PS2 reference  (conf {m['conf']}, {m['tier']})")
    out.append(f"PS2 addr : 0x{ps2:08x}   size {size} bytes")
    out.append(f"Name     : {name}")
    out.append(f"Signature: {dem.get(ps2,name)}")
    if strings:
        out.append("Strings  : " + ", ".join(f'"{s}"' for s in sorted(strings)[:12]))
    if callees:
        cn = [dem.get(c, fns.get(c,("0x%08x"%c))[0] if c in fns else "0x%08x"%c) for c in callees]
        cn = [ (c.split("(")[0]) for c in cn]
        out.append("Callees  : " + ", ".join(sorted(set(cn))))
    out.append("")
    out.append("## MIPS disassembly")
    out.extend(lines[:200])
    if len(lines)>200: out.append(f"  ... ({len(lines)-200} more instructions)")
    return "\n".join(out)

def main():
    fns, dem, tb, t_addr, strmap, ranges = load_all()
    matches = {}
    with open(os.path.join(HERE,"pc_ps2_matches_full.csv"),encoding="utf-8") as f:
        for r in csv.DictReader(f):
            matches[r["pc_addr"]] = {"ps2_addr":int(r["ps2_addr"],16),
                                     "conf":r["conf"],"tier":r["tier"]}
    args = sys.argv[1:]
    if not args:
        print(__doc__); return
    if args[0]=="--index":
        print(f"# {len(matches)} matched PC -> PS2 (reference menu)")
        for pc in sorted(matches):
            ps2=matches[pc]["ps2_addr"]
            print(f"  {pc}  conf {matches[pc]['conf']:>4}  {dem.get(ps2,'?').split('(')[0]}")
        return
    dump = False
    if args[0]=="--dump": dump=True; args=args[1:]
    for pc in args:
        pc=pc.lower().lstrip("0") or "0"; pc=(8-len(pc))*"0"+pc
        txt = card(pc, matches, fns, dem, tb, t_addr, strmap, ranges)
        if dump:
            os.makedirs(os.path.join(HERE,"reference"),exist_ok=True)
            open(os.path.join(HERE,"reference",f"PC_{pc}.md"),"w",encoding="utf-8").write(txt)
            print(f"[+] reference/PC_{pc}.md")
        else:
            print(txt); print()

if __name__=="__main__":
    main()
