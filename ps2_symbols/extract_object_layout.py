#!/usr/bin/env python3
"""
#2-priority — Recover the OBJECT struct layout by mining field-access patterns
across the ~781 PS2 functions that take an OBJECT* parameter.

For each such function:
  - find which argument index is OBJECT* (from the demangled signature),
    map to the MIPS register (arg0=$a0, arg1=$a1, arg2=$a2, arg3=$a3),
  - propagate that "object register" through move/or/addu copies within the body,
  - record every memory access  lw/lb/lh/lbu/lhu/lwc1/ldc1 / sw/sb/sh/swc1/sdc1
    whose base register holds the object pointer -> (offset, width, load/store).

Aggregate offset -> {width, #loads, #stores, accessor function names}.
The accessor NAMES give the field's semantics (e.g. offset touched by
object_get_health / mecc_get_ammo / ai_get_location => health / ammo / location).

Output:
  ps2_symbols/OBJECT_LAYOUT.md   offset -> width -> accessors -> inferred meaning
  ps2_symbols/OBJECT_LAYOUT.csv  machine-readable

CAVEAT: PS2 is GCC/MIPS, the PC build is MSVC/x86 — struct alignment can differ
(doubles, padding). Treat offsets as a strong semantic guide and reconcile against
the PC binary's actual accesses.
"""
import csv, os, re, collections, bisect
from elftools.elf.elffile import ELFFile

HERE = os.path.dirname(os.path.abspath(__file__))
ELF = os.path.join(HERE, "SLUS_201.78")

WIDTHS = {
    "lw":4,"sw":4,"lwc1":4,"swc1":4,"ll":4,"sc":4,
    "lh":2,"lhu":2,"sh":2,
    "lb":1,"lbu":1,"sb":1,
    "ldc1":8,"sdc1":8,"ld":8,"sd":8,"lq":16,"sq":16,
}
LOADS = {"lw","lh","lhu","lb","lbu","lwc1","ldc1","ld","ll","lq"}
REGS_BY_ARG = ["$a0","$a1","$a2","$a3"]

def parse_param_types(dem):
    if "(" not in dem: return []
    p = dem.split("(",1)[1].rstrip(")")
    if not p or p=="void": return []
    out, depth, cur = [], 0, ""
    for ch in p:
        if ch=="(": depth+=1
        elif ch==")": depth-=1
        if ch=="," and depth==0:
            out.append(cur.strip()); cur=""
        else: cur+=ch
    if cur.strip(): out.append(cur.strip())
    return out

def object_arg_index(dem):
    """index of the first param whose base type is OBJECT (pointer). -1 if none."""
    for i,t in enumerate(parse_param_types(dem)):
        b = t.replace("const ","").replace("/*same*/","").replace("*","").strip()
        if b == "OBJECT":
            return i
    return -1

def main():
    raw=open(ELF,"rb").read()
    e=ELFFile(open(ELF,"rb"))
    st=e.get_section_by_name(".symtab")
    text=e.get_section_by_name(".text")
    t_addr,t_off,t_size=text["sh_addr"],text["sh_offset"],text["sh_size"]
    tb=raw[t_off:t_off+t_size]
    fns={s["st_value"]:(s.name,s["st_size"]) for s in st.iter_symbols()
         if s["st_info"]["type"]=="STT_FUNC" and s["st_size"]>0 and s.name}
    dem={}
    with open(os.path.join(HERE,"SLUS_201.78.symbols.csv"),encoding="utf-8") as f:
        for r in csv.DictReader(f):
            if r["kind"]=="FUNC": dem[int(r["addr"],16)]=r["demangled"]

    import capstone
    md=capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32+capstone.CS_MODE_LITTLE_ENDIAN)

    # offset -> data
    fields = collections.defaultdict(lambda: {"loads":0,"stores":0,"widths":collections.Counter(),
                                              "funcs":collections.Counter()})
    considered=0
    for faddr,(name,fsize) in fns.items():
        d=dem.get(faddr,"")
        idx=object_arg_index(d)
        if idx<0 or idx>=len(REGS_BY_ARG):
            continue
        obj_reg0=REGS_BY_ARG[idx]
        considered+=1
        off=faddr-t_addr; p=off; end=off+fsize
        obj_regs={obj_reg0}
        # demangled base for accessor labeling
        acc=re.split(r"__|\(",name)[0]
        while p+4<=len(tb) and p<end:
            ins=next(md.disasm(tb[p:p+4], t_addr+p), None); p+=4
            if ins is None: continue
            mn=ins.mnemonic; parts=ins.op_str.replace(" ","").split(",")
            # propagate object pointer through copies: move rd,rs ; or rd,rs,zero ; addu rd,rs,zero
            if mn=="move" and len(parts)==2:
                rd,rs=parts
                if rs in obj_regs and rd.startswith("$"): obj_regs.add(rd)
            elif mn in ("or","addu") and len(parts)==3:
                rd,rs,rt=parts
                if (rs in obj_regs and rt in ("$zero","$0")) or (rt in obj_regs and rs in ("$zero","$0")):
                    if rd.startswith("$"): obj_regs.add(rd)
            # memory access:  op rt, offset(base)
            if mn in WIDTHS and len(parts)==2:
                rt,mem=parts
                mm=re.match(r"(-?0?x?[0-9a-fA-F]+)\((\$[a-z0-9]+)\)", mem)
                if mm:
                    offv=int(mm.group(1),0); base=mm.group(2)
                    if base in obj_regs:
                        w=WIDTHS[mn]
                        rec=fields[offv]
                        if mn in LOADS: rec["loads"]+=1
                        else: rec["stores"]+=1
                        rec["widths"][w]+=1
                        rec["funcs"][acc]+=1

    # build report
    rows=[]
    for offv,rec in sorted(fields.items()):
        width=rec["widths"].most_common(1)[0][0]
        topfuncs=[f for f,_ in rec["funcs"].most_common(6)]
        rows.append({"offset":f"0x{offv:x}","dec":offv,"width":width,
                     "loads":rec["loads"],"stores":rec["stores"],
                     "nfuncs":len(rec["funcs"]),
                     "accessors":", ".join(topfuncs)})

    with open(os.path.join(HERE,"OBJECT_LAYOUT.csv"),"w",newline="",encoding="utf-8") as f:
        w=csv.DictWriter(f,fieldnames=["offset","dec","width","loads","stores","nfuncs","accessors"])
        w.writeheader(); w.writerows(rows)

    md_lines=["# OBJECT struct layout — recovered from PS2 field-access patterns\n",
              f"Mined {considered} PS2 functions taking an `OBJECT*` parameter. Each offset is a",
              "struct field; the accessor function names reveal its semantics.\n",
              "**CAVEAT**: PS2 = GCC/MIPS, PC = MSVC/x86 — struct alignment may differ (doubles,",
              "padding). Treat offsets as a semantic guide; reconcile against the PC binary.\n",
              "| offset | width | #loads | #stores | #funcs | accessor functions (top) |",
              "|--------|------:|-------:|--------:|-------:|---------------------------|"]
    for r in rows:
        md_lines.append(f"| `{r['offset']}` | {r['width']} | {r['loads']} | {r['stores']} | {r['nfuncs']} | {r['accessors']} |")
    open(os.path.join(HERE,"OBJECT_LAYOUT.md"),"w",encoding="utf-8").write("\n".join(md_lines))

    print(f"[+] considered {considered} OBJECT* functions")
    print(f"[+] recovered {len(fields)} distinct field offsets")
    print(f"[+] OBJECT_LAYOUT.md / .csv written")
    # print a compact preview of the most-accessed fields
    print("\nMost-accessed fields (by #funcs):")
    for r in sorted(rows,key=lambda x:-x["nfuncs"])[:25]:
        print(f"  {r['offset']:8s} w{r['width']:<2d}  L{r['loads']:<4d} S{r['stores']:<4d}  {r['accessors']}")

if __name__=="__main__":
    main()
