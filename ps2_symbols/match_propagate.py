#!/usr/bin/env python3
"""
Anchored call-graph propagation: multiply the string-anchor matches into a large,
still-reliable correspondence table.

Seeds   = string-anchor matches (pc_ps2_matches.csv) with conf==1.0 and shared>=2
          (the rock-solid ones). These are never changed.
Growth  = iterate: a PC function F and PS2 function G are matched when they share
          >=2 already-matched callees (or callers), G is the UNIQUE best such PS2
          function for F, and F is the UNIQUE best PC function for G. Each accepted
          match decays confidence by 0.85 per hop; propagation stops below 0.4.

Reliability levers:
  - conservative seeds only
  - >=2 matched neighbors required (not 1)
  - mutual uniqueness (both directions must agree)
  - confidence decay across hops bounds error cascade

Outputs:
  ps2_symbols/pc_ps2_matches_full.csv   full layered correspondence (string + propagated)
  ps2_symbols/pc_ps2_matches_full.md    human-readable
"""
import csv, os, re, json, glob, collections, bisect

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(HERE)
PC_EXPORT = os.path.join(REPO, "ghidra_exports")
PS2_ELF   = os.path.join(HERE, "SLUS_201.78")
SEED_CSV  = os.path.join(HERE, "pc_ps2_matches.csv")

# --------------------------------------------------------------- call graphs --
def pc_graph():
    """pc_addr -> set(pc_callee_addr). Also returns name map."""
    pat = re.compile(r'\b(FUN_[0-9a-fA-F]{8})\s*\(')
    callees = collections.defaultdict(set)
    names = {}
    for f in glob.glob(os.path.join(PC_EXPORT, "00*.json")):
        d = json.load(open(f, encoding="utf-8"))
        a = d["address"]; body = d.get("decompiled","") or ""
        names[a] = d.get("name", "FUN_"+a)
        for m in pat.finditer(body):
            c = m.group(1)[4:]  # strip FUN_
            if c != a: callees[a].add(c)
    callers = collections.defaultdict(set)
    for a, cs in callees.items():
        for c in cs: callers[c].add(a)
    return callees, callers, names

def ps2_graph():
    """ps2_addr -> set(ps2_callee_addr)."""
    import capstone
    from elftools.elf.elffile import ELFFile
    raw = open(PS2_ELF,"rb").read()
    e = ELFFile(open(PS2_ELF,"rb"))
    st = e.get_section_by_name(".symtab")
    text = e.get_section_by_name(".text")
    t_addr, t_off, t_size = text["sh_addr"], text["sh_offset"], text["sh_size"]
    fns = {s["st_value"]:(s.name, s["st_size"]) for s in st.iter_symbols()
           if s["st_info"]["type"]=="STT_FUNC" and s["st_size"]>0 and s.name}
    starts = sorted(fns)
    def owner(a):
        i = bisect.bisect_right(starts, a) - 1
        if i < 0: return None
        s = starts[i]
        return s if s <= a < s+fns[s][1] else None
    tb = raw[t_off:t_off+t_size]
    md = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32+capstone.CS_MODE_LITTLE_ENDIAN)
    callees = collections.defaultdict(set)
    p = 0
    while p+4 <= len(tb):
        ins = next(md.disasm(tb[p:p+4], t_addr+p), None); p += 4
        if ins and ins.mnemonic in ("jal","bal"):
            try: tgt = int(ins.op_str, 0)
            except ValueError: continue
            o = owner(ins.address)
            if o is not None: callees[o].add(tgt)
    callers = collections.defaultdict(set)
    for a, cs in callees.items():
        for c in cs: callers[c].add(a)
    return callees, callers, fns

# ------------------------------------------------------------- propagation ----
def main():
    print("[*] building PC call graph ...")
    pc_callees, pc_callers, pc_names = pc_graph()
    print(f"    PC: {len(pc_callees)} funcs w/ callees, {len(pc_callers)} w/ callers")
    print("[*] building PS2 call graph ...")
    ps2_callees, ps2_callers, ps2_fns = ps2_graph()
    print(f"    PS2: {len(ps2_callees)} funcs w/ callees, {len(ps2_callers)} w/ callers")

    # seeds: string matches whose PS2 function is claimed by exactly ONE PC function
    # (unique in the PS2 direction). This removes ambiguous duplicate clusters
    # (e.g. _vfprintf_r x4, smartie_move x3) while keeping rock-solid single-string
    # anchors like firewall_create_fire(SpellHintFire), inv_award_item(InvChPickupItem).
    rows_csv = list(csv.DictReader(open(SEED_CSV, encoding="utf-8")))
    ps2_to_pcs = collections.defaultdict(list)
    for r in rows_csv:
        ps2_to_pcs[r["ps2_addr"]].append(r["pc_addr"])
    seeds = []
    for r in rows_csv:
        if len(ps2_to_pcs[r["ps2_addr"]]) != 1:
            continue  # ambiguous cluster -> skip as seed
        # confidence: strong if multi-string corroborated, otherwise a globally-rare
        # single string is still a reliable anchor
        conf = 1.0 if int(r["shared"]) >= 2 else 0.9
        seeds.append((r["pc_addr"], int(r["ps2_addr"],16), conf))
    print(f"[*] rock-solid seeds (conf=1, shared>=2): {len(seeds)}")

    # mapping tables
    M = {}      # pc(str) -> (ps2(int), conf)
    Mrev = {}   # ps2(int) -> pc(str)
    seed_pcs = set()
    for pc, ps2, c in seeds:
        M[pc] = (ps2, c); Mrev[ps2] = pc; seed_pcs.add(pc)

    # build candidate universe: every (pc, ps2) that share >=1 matched neighbor
    MIN_NEIGHBORS = 1
    DECAY = 0.75
    MIN_CONF = 0.3

    def neighbor_overlap(pc, ps2):
        # matched callees of pc (as ps2 addrs)
        pc_callee_ps2 = {M[c][0] for c in pc_callees.get(pc, ()) if c in M}
        pc_caller_ps2 = {M[cr][0] for cr in pc_callers.get(pc, ()) if cr in M}
        G_callees = set(ps2_callees.get(ps2, ()))
        G_callers = set(ps2_callers.get(ps2, ()))
        oc = len(pc_callee_ps2 & G_callees)
        ocr = len(pc_caller_ps2 & G_callers)
        return oc + ocr, oc, ocr

    MIN_AGREE = 2   # need >=2 independent matched parent-pairs to corroborate a match
    iteration = 0
    while True:
        iteration += 1
        # agreement signal: cand[pc][ps2] = list of confidences of matched (parent_pc,parent_ps2)
        # pairs where BOTH parents call (or are called by) (pc, ps2) respectively.
        cand = collections.defaultdict(lambda: collections.defaultdict(list))
        for parent_pc, (parent_ps2, pconf) in list(M.items()):
            for cpc in pc_callees.get(parent_pc, ()):
                if cpc in M: continue
                for gps2 in ps2_callees.get(parent_ps2, ()):
                    if gps2 in Mrev: continue
                    cand[cpc][gps2].append(pconf)
            for cpc in pc_callers.get(parent_pc, ()):
                if cpc in M: continue
                for gps2 in ps2_callers.get(parent_ps2, ()):
                    if gps2 in Mrev: continue
                    cand[cpc][gps2].append(pconf)
        new = []
        for pc, pairs in cand.items():
            scored = []
            for gps2, confs in pairs.items():
                agree = len(confs)
                if agree < MIN_AGREE: continue
                avg = sum(confs)/len(confs)
                scored.append((agree, avg, gps2, confs))
            if not scored: continue
            scored.sort(key=lambda t:(t[0], t[1]), reverse=True)
            # uniqueness on (agree, avg)
            if len(scored) >= 2 and scored[0][0] == scored[1][0] and scored[0][1] == scored[1][1]:
                continue
            agree, avg, best_ps2, confs = scored[0]
            # mutual uniqueness: pc must be the unique best for best_ps2 too
            scored2 = []
            for cpc, prs in cand.items():
                if best_ps2 not in prs: continue
                c = prs[best_ps2]
                if len(c) >= MIN_AGREE:
                    scored2.append((len(c), sum(c)/len(c), cpc))
            if not scored2: continue
            scored2.sort(key=lambda t:(t[0], t[1]), reverse=True)
            if len(scored2) >= 2 and scored2[0][0] == scored2[1][0] and scored2[0][1] == scored2[1][1]:
                continue
            if scored2[0][2] != pc: continue
            conf = DECAY * avg
            if conf < MIN_CONF: continue
            new.append((pc, best_ps2, round(conf,3), agree))
        if not new:
            print(f"[iter {iteration}] no new matches, stopping")
            break
        applied = 0
        seen_pc, seen_ps2 = set(M), set(Mrev)
        for pc, ps2, conf, agree in sorted(new, key=lambda x:-x[2]):
            if pc in seen_pc or ps2 in seen_ps2: continue
            M[pc] = (ps2, conf); Mrev[ps2] = pc; seen_pc.add(pc); seen_ps2.add(ps2); applied += 1
        print(f"[iter {iteration}] +{applied} matches (total {len(M)})")
        if applied == 0: break

    # also fold in the lower-confidence string matches (conf<1) as a separate tier
    string_matches = []
    with open(SEED_CSV, encoding="utf-8") as f:
        for r in csv.DictReader(f):
            if r["pc_addr"] in M: continue
            string_matches.append((r["pc_addr"], int(r["ps2_addr"],16), float(r["conf"]),
                                   "string", int(r["shared"])))

    rows = []
    for pc,(ps2,conf) in M.items():
        tier = "string-anchor" if pc in seed_pcs else "propagated"
        rows.append({"pc_addr":pc,"pc_name":pc_names.get(pc,"FUN_"+pc),
                     "ps2_addr":f"0x{ps2:08x}","ps2_name":ps2_fns.get(ps2,("?",0))[0],
                     "conf":conf,"tier":tier,"shared":""})
    for pc,ps2,conf,_,shared in string_matches:
        rows.append({"pc_addr":pc,"pc_name":pc_names.get(pc,"FUN_"+pc),
                     "ps2_addr":f"0x{ps2:08x}","ps2_name":ps2_fns.get(ps2,("?",0))[0],
                     "conf":conf,"tier":"string-anchor(weak)","shared":shared})
    rows.sort(key=lambda r:(-r["conf"], r["tier"]))

    csvp = os.path.join(HERE,"pc_ps2_matches_full.csv")
    with open(csvp,"w",newline="",encoding="utf-8") as f:
        w=csv.DictWriter(f,fieldnames=["pc_addr","pc_name","ps2_addr","ps2_name","conf","tier","shared"])
        w.writeheader(); w.writerows(rows)
    n_str = sum(1 for r in rows if r["tier"]=="string-anchor")
    n_prop = sum(1 for r in rows if r["tier"]=="propagated")
    mdp = os.path.join(HERE,"pc_ps2_matches_full.md")
    with open(mdp,"w",encoding="utf-8") as f:
        f.write(f"# PC <-> PS2 full correspondence (string anchors + call-graph propagation)\n\n")
        f.write(f"- string-anchor (conf=1.0): **{n_str}**\n")
        f.write(f"- propagated: **{n_prop}**\n")
        f.write(f"- weak string anchors: **{len(string_matches)}**\n")
        f.write(f"- **total: {len(rows)}**\n\n")
        f.write("| conf | tier | PC | PS2 name |\n|------|------|----|----------|\n")
        for r in rows:
            f.write(f"| {r['conf']} | {r['tier']} | `{r['pc_name']}` ({r['pc_addr']}) | `{r['ps2_name']}` ({r['ps2_addr']}) |\n")
    print(f"[+] total matches: {len(rows)} (string-anchor {n_str}, propagated {n_prop})")
    print(f"[+] wrote {csvp}")
    print(f"[+] wrote {mdp}")

if __name__=="__main__":
    main()
