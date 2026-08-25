#!/usr/bin/env python3
"""GText*.bin (Giants translations) parser — v1.0 format, FULLY decoded.

Format (validated against the exe loader at Giants.exe+0x10D660):
  u32 count          number of entries
  u32 keypool_len    byte length of the key string pool
  u32 textpool_len   byte length of the text string pool
  count × { u32 key_off, u32 text_off }   (table starts at 0x0C)
  keypool            NUL-terminated key strings ("$IDselect", "$KB_kbd_00",
                     "MO_kstory4_3", ...) — starts at 0x0C + count*8
  textpool           NUL-terminated translation strings

At runtime the game builds a 1901-bucket hash: key string -> text string.

Usage: python scripts/gtext_parse.py <GTextX.bin> [entry_index...]
       python scripts/gtext_parse.py <file> --dump out.txt
"""
import struct
import sys


def parse(path):
    d = open(path, "rb").read()
    count, klen, tlen = struct.unpack_from("<III", d, 0)
    kbase = 0x0C + count * 8
    tbase = kbase + klen
    entries = []
    for i in range(count):
        ko, to = struct.unpack_from("<II", d, 0x0C + i * 8)
        if ko == 0 and to == 0:
            entries.append((None, None))
            continue

        def cstr(base):
            e = d.index(b"\x00", base)
            return d[base:e].decode("cp1252", errors="replace")

        entries.append((cstr(kbase + ko) if ko < klen else None,
                        cstr(tbase + to) if to < tlen else None))
    return entries


def main():
    args = [a for a in sys.argv[1:]]
    dump = "--dump" in args
    if dump:
        args.remove("--dump")
        out = args[2] if len(args) > 2 else "gtext_dump.txt"
    entries = parse(args[0])
    print(f"{len(entries)} entries")
    if dump:
        with open(out, "w", encoding="utf-8") as f:
            for k, t in entries:
                if k:
                    f.write(f"{k}\t{t}\n")
        print(f"dumped -> {out}")
        return
    idxs = [int(x) for x in args[1:]] or [0, 1, 2, 3, 4, 5, 100, 600, 1200, len(entries) - 1]
    for i in idxs:
        if 0 <= i < len(entries):
            k, t = entries[i]
            print(f"[{i:4d}] {k!r:34s} -> {(t or '')[:90]!r}")


if __name__ == "__main__":
    main()
