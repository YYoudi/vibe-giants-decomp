#!/usr/bin/env python3
"""Validation parsers for the .bin/.abx/.gb2/.worldlist formats.

Derived from the GOG 1.449 named corpus (see docs/formats/*.md for evidence).
Structural metadata only: never emits asset bytes.

Usage:
    python tools_spec/bin_formats.py <file>...          # parse specific files
    python tools_spec/bin_formats.py --dir <Bin dir>    # parse a whole tree
"""
import os
import struct
import sys

MAGIC_BIN = 0x1A0002E5
MAGIC_ABX = 0x1A0002DD
MAGIC_WORLDLIST = 0x1A0003D0
MAGIC_GB2 = 0xAA0100AB


def u32(d, o):
    return struct.unpack_from("<I", d, o)[0]


def parse_worldlist(d):
    assert u32(d, 0) == MAGIC_WORLDLIST, "bad magic"
    names_end, count = u32(d, 4), u32(d, 8)
    offs = [u32(d, 0xC + 4 * i) for i in range(count)]
    names = []
    for o in offs:
        o_abs = o + 8  # stored offsets are relative to payload start 0x8 (Q4 fix)
        e = d.index(b"\0", o_abs)
        names.append(d[o_abs:e].decode("latin1"))
    return {"count": count, "names": names, "tail": (u32(d, names_end), u32(d, names_end + 4))}


def parse_abx_registry(d):
    assert u32(d, 0) == MAGIC_ABX, "bad magic"
    size = u32(d, 4)
    o, comps = 8, []
    while o < 8 + size:
        kind = d[o]
        if kind == 0xFF:
            break
        o += 1
        e = d.index(b"\0", o)
        f = d[o:e].decode("latin1")
        o = e + 1
        e = d.index(b"\0", o)
        n = d[o:e].decode("latin1")
        o = e + 1
        comps.append((kind, f, n))
    return {"components": comps, "terminator_ok": d[o] == 0xFF if o < len(d) else False}


def parse_abx_placements(d):
    assert u32(d, 0) == MAGIC_ABX, "bad magic"
    o, sets = 8, []
    while o + 4 <= len(d):
        sid = u32(d, o)
        o += 4
        if sid == 0xFFFFFFFF or o + 24 > len(d):
            break
        sets.append({"set_id": hex(sid), "members": 0})
        o += 24  # default f6
        while o + 4 <= len(d):
            idx = u32(d, o)
            o += 4
            if idx == 0xFFFFFFFF or o + 24 > len(d):
                break
            sets[-1]["members"] += 1
            o += 24
    return sets


def parse_bin_container(d, path=""):
    assert u32(d, 0) == MAGIC_BIN, "bad magic"
    hdr = [u32(d, 4 + 4 * i) for i in range(7)]
    out = {"path": path, "sections": hdr, "size": len(d)}
    env = u32(d, hdr[4]) if hdr[4] + 4 <= len(d) else None
    out["env"] = env
    logic = u32(d, hdr[0]) if hdr[0] + 4 <= len(d) else None
    out["logic_size"] = logic
    # opcode walk (sizes from the loader handlers; see docs/formats/bin_objects.md)
    sizes = {19: 2, 23: 5, 29: 17, 30: 17, 31: 17, 32: 17, 33: 17, 34: 17, 36: 17,
             37: 17, 38: 17, 39: 18, 40: 4, 41: 13, 43: 5, 45: 38, 46: 13, 47: 29,
             48: 19, 49: 41, 50: 6, 52: 45, 53: 45, 54: 45, 57: 29, 58: 37, 59: 2,
             60: 17, 62: 21, 63: 9, 64: 26, 65: 9, 66: 93, 68: 1, 69: 1, 70: 29,
             71: 21, 72: 13, 73: 5, 74: 1, 76: 7, 77: 1, 78: 34, 79: 65, 81: 13,
             82: 5, 83: 5, 84: 45, 88: 13, 90: 13, 91: 13, 92: 38, 93: 33, 94: 33,
             95: 13, 96: 5, 97: 9, 98: 9, 99: 1, 100: 1, 101: 13, 102: 9, 106: 4,
             107: 5, 111: 65, 113: 34, 114: 45, 115: 45, 116: 45, 117: 5, 118: "strz+20",
             119: 49, 120: 49, 121: 93, 129: 5, 130: 33, 133: 45, 134: 45, 135: 45,
             136: 45, 137: 46, 138: 46}
    # clean stream terminators (loader switch break-cases + 0xFF)
    terminators = {35, 42, 44, 61, 67, 108, 109, 110, 112, 255}
    rejected = {20, 21, 22, 24, 25, 26, 27, 28, 51, 55, 56, 85, 86, 87, 105, 122,
                123, 124, 125, 126, 127, 128, 131}
    unknown = []
    counts = {}
    if logic:
        o, end = hdr[0] + 4, hdr[0] + 4 + logic
        # skip two leading strz (loader does the same on the logic buffer)
        try:
            for _ in range(2):
                o = d.index(b"\0", o) + 1
        except ValueError:
            out["unknown"] = [("nostrz", 0)]
            return out
        counts = {}
        unknown = []
        while o < end:
            op = d[o]
            if op in terminators:
                counts[op] = counts.get(op, 0) + 1
                out["stream_end_exact"] = True
                out["ended_by"] = op
                break
            if op == 80:
                n = 2 + 4 * d[o + 1]
            elif op in (103, 104):
                n = 5 + 4 * u32(d, o + 1)
            elif op in (89, 118, 132):
                n = d.index(b"\0", o + 1) - o + 1
                if op == 118:
                    n += 20
            elif op in rejected:
                unknown.append((hex(o), op))
                break
            elif op not in sizes:
                unknown.append((hex(o), op))
                break
            else:
                n = sizes[op]
            counts[op] = counts.get(op, 0) + 1
            o += n
        else:
            out["stream_end_exact"] = o == end
        out["opcode_counts"] = counts
        out["unknown"] = unknown
        return out
    out["opcode_counts"] = {}
    out["unknown"] = []
    out["unknown"] = unknown
    return out


def parse_gb2(d):
    assert u32(d, 0) == MAGIC_GB2, "bad magic"
    count = u32(d, 4)
    offs = [u32(d, 8 + 4 * i) for i in range(count)]
    comps = []
    for off in offs:
        name = d[off:off + 16].split(b"\0")[0].decode("latin1")
        comps.append({"offset": off, "name": name})
    return {"count": count, "components": comps}


def parse_file(path):
    d = open(path, "rb").read()
    m = u32(d, 0)
    base = os.path.basename(path).lower()
    try:
        if m == MAGIC_WORLDLIST:
            r = parse_worldlist(d)
        elif m == MAGIC_ABX and base == "gameobj.bin":
            r = parse_abx_registry(d)
        elif m == MAGIC_ABX:
            r = parse_abx_placements(d)
        elif m == MAGIC_BIN:
            r = parse_bin_container(d, path)
        elif m == MAGIC_GB2:
            r = parse_gb2(d)
        else:
            return path, "FAIL", {"error": "unknown magic 0x%X" % m}
        return path, "PASS", r
    except Exception as exc:
        return path, "FAIL", {"error": str(exc)}


def main(argv):
    paths = []
    if argv and argv[0] == "--dir":
        root = argv[1]
        for dirpath, _, files in os.walk(root):
            for f in files:
                if f.lower().endswith((".bin", ".abx", ".gb2")):
                    paths.append(os.path.join(dirpath, f))
    else:
        paths = argv
    ok = bad = 0
    for p in paths:
        path, status, info = parse_file(p)
        if status == "PASS":
            ok += 1
        else:
            bad += 1
        print(f"[{status}] {path} :: {info}")
    print(f"\n{ok} pass, {bad} fail")
    return 0 if bad == 0 else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
