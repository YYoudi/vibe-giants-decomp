#!/usr/bin/env python3
"""
Automated PC (GiantsMain.exe, x86)  <->  PS2 (SLUS_201.78, MIPS) function matcher.

Most-reliable signal: SHARED UNIQUE STRING REFERENCES. A PC function references a
string literal in its decompiled body; if the exact same string exists in the PS2
.rodata and is referenced by exactly one PS2 function, that anchors a 1:1 match.
Confidence scales with how rare the string is across both binaries.

Pipeline:
  1. PS2: disassemble .text (capstone MIPS-LE), track lui/addiu/ori address formation,
     resolve effective addresses landing in .rodata to strings -> {ps2_func: {strings}}
  2. PC : extract string literals from each Ghidra decompiled body -> {pc_func: {strings}}
  3. Build the global string frequency across both binaries; "anchors" = strings seen in
     BOTH binaries whose combined frequency is low (rare = discriminative).
  4. For each PC function, score every PS2 function by overlap of anchor strings.
     Emit ranked correspondences (only top candidate when it dominates).

Outputs:
  ps2_symbols/pc_ps2_matches.csv      pc_addr, pc_name, ps2_addr, ps2_name, shared, conf
  ps2_symbols/pc_ps2_matches.md       human-readable ranked report
"""
import csv, os, re, sys, json, glob, collections

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(HERE)
PS2_ELF   = os.path.join(HERE, "SLUS_201.78")
PC_EXPORT = os.path.join(REPO, "ghidra_exports")

# ---------------------------------------------------------------- PS2 side ----
def load_ps2():
    from elftools.elf.elffile import ELFFile
    f = open(PS2_ELF, "rb"); e = ELFFile(f)
    funcs = {}  # addr -> (name, size, end)
    st = e.get_section_by_name(".symtab")
    for s in st.iter_symbols():
        if s["st_info"]["type"] == "STT_FUNC" and s["st_size"] > 0 and s.name:
            funcs[s["st_value"]] = (s.name, s["st_size"])
    text  = e.get_section_by_name(".text")
    rodat = e.get_section_by_name(".rodata")
    datad = e.get_section_by_name(".data")
    t_addr, t_off, t_size = text["sh_addr"],  text["sh_offset"], text["sh_size"]
    f.seek(0)
    raw = open(PS2_ELF,"rb").read()
    text_bytes = raw[t_off:t_off+t_size]
    # build (addr->string) lookup for every printable run in .rodata AND .data
    def runs(sec):
        base=sec["sh_addr"]; data=raw[sec["sh_offset"]:sec["sh_offset"]+sec["sh_size"]]
        out={}
        i=0
        while i < len(data):
            j=i
            while j<len(data) and 0x20<=data[j]<=0x7e: j+=1
            if j-i>=4 and data[j]==0:  # null-terminated
                out[base+i]=data[i:j].decode("ascii","replace")
            i=max(j+1,i+1)
        return out
    strmap={}; strmap.update(runs(rodat)); strmap.update(runs(datad))
    # address ranges
    ranges=[(rodat["sh_addr"], rodat["sh_addr"]+rodat["sh_size"]),
            (datad["sh_addr"], datad["sh_addr"]+datad["sh_size"])]
    return e, funcs, text_bytes, t_addr, strmap, ranges

def ps2_string_refs(text_bytes, t_addr, funcs, strmap, ranges):
    """Return {func_addr: set(string)} via lui/addiu/ori address tracking."""
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_MIPS,
                     capstone.CS_MODE_MIPS32 + capstone.CS_MODE_LITTLE_ENDIAN)
    md.detail = False
    # disassemble whole .text once, then attribute instructions to functions by addr range
    insns = list(md.disasm(text_bytes, t_addr))
    # index instruction addresses
    func_starts = sorted(funcs.keys())
    def owner(addr):
        # find function whose [start,start+size) contains addr
        import bisect
        i = bisect.bisect_right(func_starts, addr) - 1
        if i < 0: return None
        st = func_starts[i]; nm, sz = funcs[st]
        if st <= addr < st+sz: return st
        return None
    def in_str_range(a):
        return any(lo<=a<hi for lo,hi in ranges)
    # walk instructions tracking regs within sliding window per function
    cur=None; regs={}; out=collections.defaultdict(set)
    for ins in insns:
        own = owner(ins.address)
        if own != cur:
            cur=own; regs={}
        if cur is None: continue
        mn = ins.mnemonic; op = ins.op_str.replace(" ","")
        parts = op.split(",")
        def regset(idx,val):
            if idx < len(parts):
                r=parts[idx]
                if r.startswith("$"): regs[r]=val & 0xFFFFFFFF
        if mn=="lui" and len(parts)==2:
            r=parts[0]
            try: imm=int(parts[1],0)
            except: imm=None
            if imm is not None and r.startswith("$"): regs[r]=(imm&0xffff)<<16
        elif mn in ("addiu","daddiu") and len(parts)==3:
            rd,rs,imm=parts
            try: v=int(imm,0)
            except: v=None
            base=regs.get(rs,0)
            if v is not None:
                ea=(base + (v & 0xffff if v<0x8000 else v-0x10000)) & 0xFFFFFFFF
                if in_str_range(ea) and ea in strmap:
                    out[cur].add(strmap[ea])
                if rd.startswith("$"): regs[rd]=ea
        elif mn=="ori" and len(parts)==3:
            rd,rs,imm=parts
            try: v=int(imm,0)
            except: v=None
            base=regs.get(rs,0)
            if v is not None:
                ea=(base | (v & 0xffff)) & 0xFFFFFFFF
                if in_str_range(ea) and ea in strmap:
                    out[cur].add(strmap[ea])
                if rd.startswith("$"): regs[rd]=ea
        elif mn=="addu" and len(parts)==3:
            rd,rs,rt=parts
            ea=(regs.get(rs,0)+regs.get(rt,0))&0xFFFFFFFF
            if in_str_range(ea) and ea in strmap:
                out[cur].add(strmap[ea])
            if rd.startswith("$"): regs[rd]=ea
    return out

# ----------------------------------------------------------------- PC side ----
STR_RE = re.compile(r'"((?:\\.|[^"\\])*)"')
def pc_string_refs():
    """{pc_addr: set(string)} from decompiled text literals."""
    out=collections.defaultdict(set)
    names={}
    for f in glob.glob(os.path.join(PC_EXPORT, "00*.json")):
        try: d=json.load(open(f,encoding="utf-8"))
        except: continue
        addr=d.get("address"); body=d.get("decompiled","") or ""
        names[addr]=d.get("name", addr)
        for m in STR_RE.findall(body):
            m=m.replace("\\n","\n").replace("\\t","\t").replace('\\"','"')
            if len(m)>=6: out[addr].add(m)
    return out, names

# --------------------------------------------------------------- matching -----
def main():
    print("[*] loading PS2 ELF ...")
    e, funcs, text_bytes, t_addr, strmap, ranges = load_ps2()
    print(f"    PS2 functions: {len(funcs)}  printable string runs: {len(strmap)}")
    print("[*] disassembling PS2 .text for string refs ...")
    ps2refs = ps2_string_refs(text_bytes, t_addr, funcs, strmap, ranges)
    print(f"    PS2 functions with string refs: {len(ps2refs)}")
    print("[*] loading PC Ghidra exports ...")
    pcrefs, pcnames = pc_string_refs()
    print(f"    PC functions with string literals: {len(pcrefs)}")

    # global string frequency across both sides
    globfreq=collections.Counter()
    for s in ps2refs.values():
        globfreq.update(s)
    for s in pcrefs.values():
        globfreq.update(s)

    # anchors: present in BOTH a PS2 func and a PC func, and rare enough
    ps2_str_index = collections.defaultdict(set)  # string -> set(ps2_func addr)
    for fa,ss in ps2refs.items():
        for s in ss: ps2_str_index[s].add(fa)
    pc_str_index = collections.defaultdict(set)
    for fa,ss in pcrefs.items():
        for s in ss: pc_str_index[s].add(fa)

    # candidate matches: for each PC func, gather PS2 funcs sharing any anchor string
    rows=[]
    for pcfa, pcstrings in pcrefs.items():
        # anchors = strings also referenced by some PS2 func
        ps2vote=collections.Counter()
        shared_detail=[]
        for s in pcstrings:
            cands = ps2_str_index.get(s)
            if not cands: continue
            # weight inversely by global rarity (rare string = strong vote)
            w = 1.0 / max(1, globfreq[s])
            for pf in cands:
                ps2vote[pf]+=w
            shared_detail.append((s, globfreq[s]))
        if not ps2vote: continue
        # rank candidates
        ranked=ps2vote.most_common()
        best_pf, best_score = ranked[0]
        second = ranked[1][1] if len(ranked)>1 else 0
        # shared literal strings with best
        shared = sorted(set(s for s,_ in shared_detail if best_pf in ps2_str_index.get(s,set())))
        # confidence: dominance over 2nd + number of distinct shared strings
        distinct=len(shared)
        dom = best_score/(best_score+second) if (best_score+second)>0 else 1.0
        conf = dom * min(1.0, distinct/3.0)
        rows.append({
            "pc_addr":pcfa,"pc_name":pcnames.get(pcfa,pcfa),
            "ps2_addr":f"0x{best_pf:08x}","ps2_name":funcs[best_pf][0],
            "shared":distinct,"conf":round(conf,3),
            "sample_shared":" | ".join(shared[:3]),
        })
    rows.sort(key=lambda r:(-r["conf"], -r["shared"]))

    csvp=os.path.join(HERE,"pc_ps2_matches.csv")
    with open(csvp,"w",newline="",encoding="utf-8") as f:
        w=csv.DictWriter(f,fieldnames=["pc_addr","pc_name","ps2_addr","ps2_name","shared","conf","sample_shared"])
        w.writeheader(); w.writerows(rows)
    # markdown report: high-confidence matches
    high=[r for r in rows if r["conf"]>=0.5 and r["shared"]>=1]
    mdp=os.path.join(HERE,"pc_ps2_matches.md")
    with open(mdp,"w",encoding="utf-8") as f:
        f.write(f"# PC <-> PS2 automated matches (string-anchor)\n\n")
        f.write(f"Total candidate matches: **{len(rows)}**  |  high-confidence (conf>=0.5): **{len(high)}**\n\n")
        f.write("| conf | shared | PC addr | PC name | PS2 addr | PS2 name | sample shared string |\n")
        f.write("|------|--------|---------|---------|----------|----------|----------------------|\n")
        for r in high[:200]:
            f.write(f"| {r['conf']} | {r['shared']} | {r['pc_addr']} | `{r['pc_name']}` | {r['ps2_addr']} | `{r['ps2_name']}` | {r['sample_shared'][:60]} |\n")
    print(f"[+] matches: {len(rows)} total, {len(high)} high-confidence")
    print(f"[+] wrote {csvp}")
    print(f"[+] wrote {mdp}")

if __name__=="__main__":
    main()
