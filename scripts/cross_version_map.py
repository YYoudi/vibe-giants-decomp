#!/usr/bin/env python3
"""cross_version_map.py — match v1.0 functions to 1.449 by code signature.

For each function in the v1.0 dump (decompiled/full_index.json), extracts a
code hash from the first N bytes and searches the 1.449 exe for a match.
Outputs a JSON address map + stats.
"""
import json
import struct
import sys
import hashlib

# --- read both PE files ---
def load_pe(path):
    import pefile
    pe = pefile.PE(path)
    secs = []
    for s in pe.sections:
        va = pe.OPTIONAL_HEADER.ImageBase + s.VirtualAddress
        secs.append((va, s.Misc_VirtualSize, s.PointerToRawData, s.SizeOfRawData, s.Name.decode().strip('\x00')))
    data = open(path, 'rb').read()
    return data, secs

def va_to_off(va, secs):
    for v, sz, raw, rawsz, name in secs:
        if v <= va < v + rawsz:
            return raw + (va - v)
    return None

V10 = load_pe('GameFiles-VanillaV1/Giants.exe')
V149 = load_pe('G:/Games/Giants/Giants.exe')

# --- v1.0 index (function list) ---
idx = json.load(open('decompiled/full_index.json'))

# --- build v1.0 .text blob for searching ---
def text_blob(data, secs):
    for v, sz, raw, rawsz, name in secs:
        if name == '.text':
            return v, data[raw:raw+rawsz]
    return None, None

t10_va, t10_blob = text_blob(V10[0], V10[1])
t49_va, t49_blob = text_blob(V149[0], V149[1])

results = {}
matched = renamed = 0

for va_str, info in sorted(idx.items()):
    va = int(va_str, 16)
    name = info['name']
    # extract signature: 32 bytes from function start in v1.0
    off10 = va_to_off(va, V10[1])
    if off10 is None:
        continue
    sig = V10[0][off10:off10+32]
    if len(sig) < 32:
        continue
    # search in 1.449 .text
    pos = t49_blob.find(sig)
    if pos < 0:
        # try shorter signature (16 bytes)
        sig = sig[:16]
        pos = t49_blob.find(sig)
        if pos < 0:
            continue
    va49 = t49_va + pos
    results[va_str] = {'v10_name': name, 'v149_va': hex(va49)}
    matched += 1
    if not name.startswith('FUN_'):
        renamed += 1

print(f"matched: {matched}/{len(idx)} (renamed-fns: {renamed})")

# --- also scan the 1.449 dump for its own function starts ---
# For each v1.0 function that DIDN'T match by byte-sig, try a relaxed match:
# hash the first 16 non-NOP bytes
json.dump(results, open('decompiled/v10_to_v149_map.json', 'w'), indent=1)
print("saved -> decompiled/v10_to_v149_map.json")
