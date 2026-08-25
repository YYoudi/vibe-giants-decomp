#!/usr/bin/env python3
"""GText*.bin (Giants translations) parser — v1.0 format, empirically derived.

Layout (GTextEnglish.bin reference):
  u32 count            entry count (1852 for English v1.0)
  u32 pool2_offset     mission-message id pool ("MO_..." strings)
  u32 pool3_offset     dialogue/text pool (game text lines)
  4 bytes              (zero / flags)
  count × { u32 offA, u32 offB }   offsets into pool1 / pool2-or-3
  pool1 (right after table): UI ids ("IDselect", "$KB_kbd_00", "$MC_...")
  pool2: mission ids / names
  pool3: text lines

offB < (pool3_offset - pool2_offset) indexes pool2, else pool3 (96% clean;
remaining semantics refined once the exe loader is located — see
docs/FORMAT_INVENTORY.md gaps).

Usage: python scripts/gtext_parse.py <GTextX.bin> [entry_index...]
"""
import struct
import sys


def parse(path):
    d = open(path, "rb").read()
    count, off2, off3 = struct.unpack_from("<III", d, 0)
    computed = 0x18 + count * 8
    # calibrate pool1 base: maximize valid-ASCII hits over +/-16 bytes
    best, best_score = computed, -1
    pairs_probe = [struct.unpack_from("<II", d, 0x18 + i * 8) for i in range(min(count, 200))]
    for cand in range(computed - 20, computed + 20):
        s = sum(1 for a, _ in pairs_probe if cstr_safe(d, cand + a) is not None)
        if s > best_score:
            best, best_score = cand, s
    pool1 = best
    pairs = [struct.unpack_from("<II", d, 0x18 + i * 8) for i in range(count)]

    def cstr(base):
        e = d.index(b"\x00", base)
        return d[base:e].decode("cp1252", errors="replace")

    entries = []
    for a, b in pairs:
        sid = cstr_safe(d, pool1 + a)
        txt2 = cstr_safe(d, off2 + b)
        txt3 = cstr_safe(d, off3 + b)
        if txt2 is not None and (txt3 is None or len(txt2) >= 1):
            entries.append((sid, txt2, 2))
        elif txt3 is not None:
            entries.append((sid, txt3, 3))
        else:
            entries.append((sid, f"<unresolved b={b:#x}>", 0))
    return entries


def cstr_safe(d, base):
    if not (0 < base < len(d)):
        return None
    try:
        e = d.index(b"\x00", base)
    except ValueError:
        return None
    s = d[base:e]
    if len(s) == 0 or len(s) > 512:
        return None
    try:
        return s.decode("cp1252")
    except Exception:
        return None


def main():
    entries = parse(sys.argv[1])
    print(f"{len(entries)} entries")
    if len(sys.argv) > 2:
        idxs = [int(x) for x in sys.argv[2:]]
    else:
        idxs = [0, 1, 2, 3, 4, 5, 100, 600, 1200, len(entries) - 1]
    for i in idxs:
        if 0 <= i < len(entries):
            sid, txt, src = entries[i]
            print(f"[{i:4d}] (p{src}) {sid!r:30s} -> {txt[:90]!r}")


if __name__ == "__main__":
    main()
