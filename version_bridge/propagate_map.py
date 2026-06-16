#!/usr/bin/env python3
"""
Extend the 1.5<->vanilla string-anchor map via call-graph propagation.
Seeds = the string-confirmed pairs (IDENTICAL/NEAR/MODIFIED from VERSION_MAP.csv).
Grows: F(1.5) <-> G(vanilla) when >=2 matched parent-pairs both call (F,G),
mutual uniqueness both ways, confidence decays 0.8/hop.

Outputs an extended map + coverage stats for the hand-off.
"""
import csv, os, re, json, glob, collections

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(HERE)
SEED_CSV = os.path.join(HERE, "VERSION_MAP.csv")
VAN = os.path.join(HERE, "vanilla_functions.jsonl")
PC_EXPORT = os.path.join(REPO, "ghidra_exports")
CALPC = re.compile(r'\b(FUN_[0-9a-fA-F]{8})\s*\(')

def pc_graph():
    callees=collections.defaultdict(set); names={}
    for f in glob.glob(os.path.join(PC_EXPORT,"00*.json")):
        try: d=json.load(open(f,encoding="utf-8"))
        except: continue
        a=d["address"]; names[a]=d.get("name","FUN_"+a)
        for m in CALPC.finditer(d.get("decompiled","") or ""):
            c=m.group(1)[4:]
            if c!=a: callees[a].add(c)
    callers=collections.defaultdict(set)
    for a,cs in callees.items():
        for c in cs: callers[c].add(a)
    return callees, callers, names

def van_graph():
    callees=collections.defaultdict(set); names={}
    for l in open(VAN,encoding="utf-8"):
        r=json.loads(l)
        a=r["addr"].lstrip("0") or "0"; a=(8-len(a))*"0"+a
        names[a]=r["name"]; callees[a]=set(c.lstrip("0").rjust(8,"0") for c in r["callees"])
    callers=collections.defaultdict(set)
    for a,cs in callees.items():
        for c in cs: callers[c].add(a)
    return callees, callers, names

def main():
    # seeds
    seeds=[]
    for r in csv.DictReader(open(SEED_CSV,encoding="utf-8")):
        if r["identity"] in ("IDENTICAL","NEAR","MODIFIED"):
            seeds.append((r["1.5_addr"], r["vanilla_addr"].lstrip("0x").lstrip("0").rjust(8,"0") or "00000000"))
    print(f"[*] seeds: {len(seeds)}")
    print("[*] building 1.5 call graph ...")
    pc_c,pc_r,pc_n=pc_graph()
    print(f"    1.5: {len(pc_c)} w/ callees")
    print("[*] building vanilla call graph ...")
    vn_c,vn_r,vn_n=van_graph()
    print(f"    vanilla: {len(vn_c)} w/ callees")

    M={}; Mrev={}
    seedset=set()
    for pc,vn in seeds:
        M[pc]=(vn,1.0); Mrev[vn]=pc; seedset.add(pc)

    MIN_AGREE=2; DECAY=0.8; MIN_CONF=0.4
    it=0
    while True:
        it+=1
        cand=collections.defaultdict(lambda: collections.defaultdict(list))
        for ppc,(pvn,conf) in list(M.items()):
            for cpc in pc_c.get(ppc,()):
                if cpc in M: continue
                for cvn in vn_c.get(pvn,()):
                    if cvn in Mrev: continue
                    cand[cpc][cvn].append(conf)
            for cpc in pc_r.get(ppc,()):
                if cpc in M: continue
                for cvn in vn_r.get(pvn,()):
                    if cvn in Mrev: continue
                    cand[cpc][cvn].append(conf)
        new=[]
        for cpc,pairs in cand.items():
            scored=[]
            for cvn,confs in pairs.items():
                if len(confs)>=MIN_AGREE:
                    scored.append((len(confs),sum(confs)/len(confs),cvn))
            if not scored: continue
            scored.sort(reverse=True)
            if len(scored)>=2 and scored[0][0]==scored[1][0] and scored[0][1]==scored[1][1]: continue
            ag,avg,bvn=scored[0]
            scored2=[]
            for k,prs in cand.items():
                if bvn in prs and len(prs[bvn])>=MIN_AGREE:
                    scored2.append((len(prs[bvn]),sum(prs[bvn])/len(prs[bvn]),k))
            scored2.sort(reverse=True)
            if not scored2 or scored2[0][2]!=cpc: continue
            conf=DECAY*avg
            if conf<MIN_CONF: continue
            new.append((cpc,bvn,round(conf,3)))
        if not new: print(f"[iter {it}] stop"); break
        seen_p=set(M); seen_v=set(Mrev); applied=0
        for cpc,bvn,conf in sorted(new,key=lambda x:-x[2]):
            if cpc in seen_p or bvn in seen_v: continue
            M[cpc]=(bvn,conf); Mrev[bvn]=cpc; seen_p.add(cpc); seen_v.add(bvn); applied+=1
        print(f"[iter {it}] +{applied} (total {len(M)})")
        if applied==0: break

    # write extended map
    rows=[]
    for ppc,(bvn,conf) in M.items():
        rows.append({"1.5_addr":ppc,"1.5_name":pc_n.get(ppc,"FUN_"+ppc),
                     "vanilla_addr":"0x"+bvn,"vanilla_name":vn_n.get(bvn,"?"),
                     "conf":round(conf,3),"origin":"seed" if ppc in seedset else "propagated"})
    rows.sort(key=lambda r:-r["conf"])
    p=os.path.join(HERE,"VERSION_MAP_full.csv")
    with open(p,"w",newline="",encoding="utf-8") as f:
        w=csv.DictWriter(f,fieldnames=["1.5_addr","1.5_name","vanilla_addr","vanilla_name","conf","origin"])
        w.writeheader(); w.writerows(rows)
    nseed=sum(1 for r in rows if r["origin"]=="seed")
    nprop=len(rows)-nseed
    print(f"[+] VERSION_MAP_full.csv: {len(rows)} pairs (seed {nseed}, propagated {nprop})")
    # coverage vs vanilla function count
    van_total=sum(1 for _ in open(VAN,encoding="utf-8"))
    print(f"    coverage of vanilla {van_total}: {len(rows)} ({len(rows)*100//van_total}%)")

if __name__=="__main__":
    main()
