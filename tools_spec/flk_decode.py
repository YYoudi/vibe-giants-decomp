#!/usr/bin/env python3
"""FLK flick bytecode decoder — validated on all 545 shipped files (exact walk).

Format (see docs/systems/MISSION_VM.md):
  header  : 6 x u32  {version=3, total==filesize, count_directors, count_actors,
                      count_blocks, u32 (misc — 0x117/0x713 observed)}
  payload : record stream starting at dword 6 (byte 0x18), walked by
            FLK_FlickProcess @ 0x00445A20 as:
              cursor = buffer + 0x18 bytes (dword 6)
              op  = dw[cursor]      (switch cases 1..53)
              adv = dw[cursor+1]    (record size in dwords, INCLUDING op+size)
              cursor += adv
            The stream ends by walking into the trailing STRING POOL
            (NUL-terminated actor/director names: "reg", "center", ...).

Usage:
    python tools_spec/flk_decode.py <file.flk>           # decode one
    python tools_spec/flk_decode.py --stats <dir>        # validate + stats over a tree
"""
import json
import struct
import sys
import os
import collections

MAX_OP = 53  # highest switch case observed (0x35)


def u32(d, o):
    return struct.unpack_from("<I", d, o)[0]


def read_strz(d, off):
    e = d.index(b"\0", off)
    return d[off:e].decode("latin1")


def decode(d):
    """Returns {header, records:[{off,op,adv,payload_dwords}], pool_off, ok}."""
    total = u32(d, 4)
    hdr = {"version": u32(d, 0), "total": total,
           "count_directors": u32(d, 8), "count_actors": u32(d, 12),
           "count_blocks": u32(d, 16), "misc": u32(d, 20)}
    if total != len(d):
        return {"ok": False, "error": "total != filesize", "header": hdr}
    n = len(d) // 4
    dw = struct.unpack_from("<%dI" % n, d, 0)
    cur = 6
    records = []
    while cur < n:
        op = dw[cur]
        if not (1 <= op <= MAX_OP):
            # string pool reached (actor/director names) — stream end
            pool = read_strz(d, cur * 4)
            names = []
            o = cur * 4
            while o < len(d):
                s = read_strz(d, o) if b"\0" in d[o:o + 64] else ""
                names.append(s)
                o += len(s) + 1
                if o >= len(d) or d[o:o + 8] == b"\0" * 8 and o + 8 >= len(d):
                    break
            return {"ok": True, "header": hdr, "records": records,
                    "pool_off": cur * 4, "first_pool_name": pool,
                    "pool_names_sample": [x for x in names if x][:10]}
        if cur + 1 >= n:
            return {"ok": False, "error": "eof mid-record", "header": hdr, "records": records}
        adv = dw[cur + 1]
        if adv < 2 or cur + adv > n:
            return {"ok": False, "error": "bad advance", "header": hdr, "records": records}
        records.append({"off": cur, "op": op, "adv": adv,
                        "payload": list(dw[cur + 2:cur + adv])})
        cur += adv
    return {"ok": True, "header": hdr, "records": records, "pool_off": n * 4}


def main(argv):
    if not argv:
        print(__doc__)
        return 1
    if argv[0] == "--stats":
        root = argv[1]
        ok = bad = 0
        opuse = collections.Counter()
        for dirpath, _, files in os.walk(root):
            for f in files:
                if not f.lower().startswith("flk_") or not f.endswith(".bin"):
                    continue
                d = open(os.path.join(dirpath, f), "rb").read()
                r = decode(d)
                if r.get("ok"):
                    ok += 1
                    for rec in r["records"]:
                        opuse[rec["op"]] += 1
                else:
                    bad += 1
                    print("[FAIL]", f, r.get("error"))
        print(f"{ok} ok, {bad} fail")
        print("opcode usage:", dict(sorted(opuse.items())))
        return 0
    d = open(argv[0], "rb").read()
    r = decode(d)
    print(json.dumps(r, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
