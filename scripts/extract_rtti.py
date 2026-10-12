#!/usr/bin/env python3
"""Extract MSVC x86 RTTI metadata from a PE32: type descriptors (.?AV/.?AU/.?AW
mangled names), Complete Object Locators, and vftables.

Outputs a CSV: vftable_va,class_name,num_methods,demangled_kind
and a second CSV of all class/struct/enum names: kind,name,td_va

vftable method counting walks forward while dwords point into .text.
Usage: python scripts/extract_rtti.py <pe_path> <out_prefix>
"""
import csv, re, struct, sys

def load_pe(path):
    raw = open(path, "rb").read()
    e = struct.unpack_from("<I", raw, 0x3C)[0]
    coff = e + 4
    nsec = struct.unpack_from("<H", raw, coff + 2)[0]
    opt_size = struct.unpack_from("<H", raw, coff + 16)[0]
    opt = coff + 20
    image_base = struct.unpack_from("<I", raw, opt + 28)[0]
    sec0 = opt + opt_size
    secs = []
    for i in range(nsec):
        off = sec0 + 40 * i
        name = raw[off:off+8].rstrip(b"\0").decode("ascii", "replace")
        vsize, va, rsize, roff = struct.unpack_from("<IIII", raw, off + 8)
        secs.append((name, va, vsize, roff, rsize))
    return raw, image_base, secs

def va2off(raw, base, secs, va):
    rva = va - base
    for name, sva, vsize, roff, rsize in secs:
        if sva <= rva < sva + max(vsize, rsize):
            fo = roff + (rva - sva)
            if fo + 4 <= len(raw):
                return fo
    return None

def read_dwords(raw, off, n):
    return list(struct.unpack_from("<" + "I" * n, raw, off))

def demangle(name):
    # .?AVObjectName@@ -> kind=class, name=ObjectName (nested uses @ @)
    m = re.match(r"\.(\?A[VWU])(.+?)@@", name)
    if not m:
        return None, name
    kind = {"V": "class", "U": "struct", "W": "enum"}[m.group(1)]
    raw = m.group(2)
    parts = [p for p in raw.split("@") if p]
    return kind, "::".join(reversed(parts)) if parts else raw

def main():
    pe_path, out_prefix = sys.argv[1], sys.argv[2]
    raw, base, secs = load_pe(pe_path)
    text = next(s for s in secs if s[0] == ".text")
    text_lo, text_hi = base + text[1], base + text[1] + text[2]
    secs_data = [(n, base + va, base + va + max(vsize, rsize), roff)
                 for n, va, vsize, roff, rsize in secs]

    def sec_of(va):
        for n, lo, hi, roff in secs_data:
            if lo <= va < hi:
                return (n, roff + (va - lo))
        return None

    # 1) scan all sections for type descriptors: ".?A" prefix
    tds = {}  # td_va -> (kind, pretty name)
    for n, lo, hi, roff in secs_data:
        data = raw[roff:roff + (hi - lo)]
        for m in re.finditer(rb"\.(\?A[VWU][\x20-\x7e]{2,200}?@@\x00)", data):
            va = lo + m.start() - 8   # name field is +8 into type_info
            td_va = va
            try:
                sname = m.group(1).rstrip(b"\0").decode("ascii")
            except UnicodeDecodeError:
                continue
            kind, pretty = demangle(sname)
            if kind:
                tds[td_va] = (kind, pretty)

    print(f"type descriptors: {len(tds)}")

    # 2) find COLs: dword at +12 (pTypeDescriptor, VA in x86) hits a td
    cols = {}  # col_va -> td_va
    for n, lo, hi, roff in secs_data:
        data = raw[roff:roff + (hi - lo)]
        for i in range(0, len(data) - 24, 4):
            td = struct.unpack_from("<I", data, i + 12)[0]
            if td in tds:
                sig, off, cdoff = struct.unpack_from("<III", data, i)
                if sig == 0 and off == 0:
                    col_va = lo + i
                    cols[col_va] = td

    print(f"complete object locators: {len(cols)}")

    # 3) vftables: a dword immediately followed by >=1 text pointers whose
    #    PRECEDING dword equals a COL va
    vfts = []  # (vft_va, td, count)
    for n, lo, hi, roff in secs_data:
        data = raw[roff:roff + (hi - lo)]
        for i in range(4, len(data) - 4, 4):
            col = struct.unpack_from("<I", data, i - 4)[0]
            if col not in cols:
                continue
            p0 = struct.unpack_from("<I", data, i)[0]
            if not (text_lo <= p0 < text_hi):
                continue
            cnt = 0
            j = i
            while j + 4 <= len(data):
                pv = struct.unpack_from("<I", data, j)[0]
                if text_lo <= pv < text_hi:
                    cnt += 1
                    j += 4
                else:
                    break
            vft_va = lo + i
            vfts.append((vft_va, cols[col], cnt))

    print(f"vftables: {len(vfts)}")

    with open(out_prefix + "_vftables.csv", "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["vftable_va", "class", "kind", "num_methods"])
        for vft_va, td, cnt in sorted(vfts):
            w.writerow([f"{vft_va:X}", tds[td][1], tds[td][0], cnt])
    with open(out_prefix + "_classes.csv", "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["kind", "name", "td_va"])
        for td, (kind, nm) in sorted(tds.items(), key=lambda kv: (kv[1][0], kv[1][1])):
            w.writerow([kind, nm, f"{td:X}"])
    print(f"wrote {out_prefix}_vftables.csv / _classes.csv")

if __name__ == "__main__":
    main()
