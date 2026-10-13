#!/usr/bin/env python3
"""Read decompiled bodies for addresses from the exported corpus.
Usage: python scripts/read_bodies.py 0x004A2D60 [frac] 0x005375E0 [frac] ...
frac (0-1) = position in body. Prints trimmed body slices.
"""
import json,re,sys
idx=json.load(open('decompiled/gog144_full/index.json'))
a2n={k:v['name'] for k,v in idx.items()}
cur=None; buf=[]; bodies={}
hdr=re.compile(r'/\* ===== (\S+) @ (0x[0-9A-F]+) ===== \*/')
for line in open('decompiled/gog144_full/all_decompiled.c',encoding='utf-8',errors='replace'):
    m=hdr.match(line)
    if m:
        if cur: bodies[cur]=''.join(buf)
        cur=m.group(1); buf=[]
    elif cur: buf.append(line)
if cur: bodies[cur]=''.join(buf)
bl={k.lower():v for k,v in bodies.items()}
args=sys.argv[1:]
i=0
while i<len(args):
    a=args[i]; fr=float(args[i+1]) if i+1<len(args) and args[i+1].replace('.','').isdigit() else 0.0
    if fr>1: fr=0.0
    else: i+=1+ (1 if i+1<len(args) and args[i+1].replace('.','').isdigit() else 0)
    key='0x%08X'%int(a,16)
    n=a2n.get(key)
    if not n: print(f'## {a}: not in index'); continue
    b=bl.get(n.lower())
    if b is None: print(f'## {a} ({n}): NO BODY'); continue
    b=re.sub(r'\n{2,}','\n',b).strip()
    L=len(b); p=int(L*fr)
    print(f"##### {n} ({a}) len={L}")
    print(b[p:p+700]); print()
