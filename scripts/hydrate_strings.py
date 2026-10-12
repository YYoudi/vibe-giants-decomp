#!/usr/bin/env python3
"""Rewrite Ghidra-12 `s_label_00XXXXXX` string-symbol references in decompiled
bodies into real quoted literals, by reading the string bytes at that VA from the
source PE. This restores the inline string literals that match_pc_ps2.py expects.

Usage: python scripts/hydrate_strings.py <exports_dir> <pe_path>
Rewrites the "decompiled" field of every <addr>.json in place (idempotent-ish:
re-running re-reads from s_ tokens that survived, quoted literals are untouched).
"""
import json, os, re, struct, sys, glob

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(HERE)

S_TOKEN = re.compile(r"s_[A-Za-z0-9_]+_([0-9a-fA-F]{7,8})(?![0-9a-fA-F])")

class PE:
    def __init__(self, path):
        self.raw = open(path, "rb").read()
        e_lfanew = struct.unpack_from("<I", self.raw, 0x3C)[0]
        assert self.raw[e_lfanew:e_lfanew+4] == b"PE\0\0", "not a PE"
        coff = e_lfanew + 4
        nsec = struct.unpack_from("<H", self.raw, coff + 2)[0]
        opt_size = struct.unpack_from("<H", self.raw, coff + 16)[0]
        opt = coff + 20
        magic = struct.unpack_from("<H", self.raw, opt)[0]
        assert magic == 0x10B, "not PE32"
        self.image_base = struct.unpack_from("<I", self.raw, opt + 28)[0]
        sec0 = opt + opt_size
        self.sections = []
        for i in range(nsec):
            off = sec0 + 40 * i
            name = self.raw[off:off+8].rstrip(b"\0").decode("ascii", "replace")
            vsize, va, rsize, roff = struct.unpack_from("<IIII", self.raw, off + 8)
            self.sections.append((name, va, vsize, roff, rsize))

    def read_va(self, va, maxlen=512):
        rva = va - self.image_base
        for name, sva, vsize, roff, rsize in self.sections:
            if sva <= rva < sva + max(vsize, rsize):
                fo = roff + (rva - sva)
                if fo >= len(self.raw):
                    return None
                chunk = self.raw[fo:fo + maxlen]
                out = bytearray()
                for b in chunk:
                    if b == 0:
                        break
                    out.append(b)
                if len(out) < 4:
                    return None
                try:
                    s = out.decode("ascii")
                except UnicodeDecodeError:
                    return None
                if all(0x20 <= ord(c) <= 0x7E for c in s):
                    return s
                return None
        return None

def main():
    exports_dir = sys.argv[1] if len(sys.argv) > 1 else os.path.join(REPO, "ghidra_exports")
    pe_path = sys.argv[2] if len(sys.argv) > 2 else r"G:\Games\Giants\Giants.exe"
    pe = PE(pe_path)
    cache = {}
    ntok = nmiss = nfiles = 0
    for fp in glob.glob(os.path.join(exports_dir, "*.json")):
        d = json.load(open(fp, encoding="utf-8"))
        body = d.get("decompiled", "") or ""
        hits = list(S_TOKEN.finditer(body))
        if not hits:
            continue
        nfiles += 1
        out, last = [], 0
        for m in hits:
            va = int(m.group(1), 16)
            if va not in cache:
                cache[va] = pe.read_va(va)
            s = cache[va]
            if s is None or len(s) < 4:
                nmiss += 1
                continue
            esc = s.replace("\\", "\\\\").replace('"', '\\"').replace("\n", "\\n").replace("\t", "\\t")
            out.append(body[last:m.start()])
            out.append(f'"{esc}"')
            last = m.end()
            ntok += 1
        out.append(body[last:])
        d["decompiled"] = "".join(out)
        json.dump(d, open(fp, "w", encoding="utf-8"))
    print(f"hydrated {ntok} string tokens in {nfiles} files ({nmiss} unreadable, {len(cache)} unique VAs)")

if __name__ == "__main__":
    main()
