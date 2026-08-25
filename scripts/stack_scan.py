#!/usr/bin/env python3
"""Scan the current thread stack for return addresses into a module.

Usage: python scripts/stack_scan.py [module_range_lo module_range_hi] [depth]
Defaults: giants.exe 0x401000-0x590000, depth 0x500 bytes from ESP.
Target must be PAUSED.
"""
import json
import os
import re
import struct
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))


def callt(tool, args):
    out = subprocess.run(["python", os.path.join(HERE, "xdbg_call.py"), tool,
                          json.dumps(args)], capture_output=True, text=True, timeout=60).stdout
    return out


def main():
    lo = int(sys.argv[1], 16) if len(sys.argv) > 1 else 0x401000
    hi = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x590000
    depth = int(sys.argv[3], 16) if len(sys.argv) > 3 else 0x500
    esp = int(callt("EvalExpression", {"expression": "esp"}).splitlines()[0].split()[0], 16)
    dump = callt("ReadMemory", {"address": hex(esp), "length": depth})
    raw = bytearray()
    for line in dump.splitlines():
        m = re.match(r"\s*[0-9A-Fa-f]+:((?:\s+[0-9A-Fa-f]{2})+)", line)
        if m:
            for p in m.group(1).split():
                raw.append(int(p, 16))
    hits = []
    for i in range(0, len(raw) - 4, 4):
        v = struct.unpack("<I", raw[i:i + 4])[0]
        if lo <= v < hi:
            hits.append((esp + i, v))
    print(f"esp={hex(esp)}  range={hex(lo)}-{hex(hi)}  {len(hits)} hits:")
    for addr, v in hits:
        print(f"  [esp+{addr-esp:#05x}] = 0x{v:x} (giants+0x{v-0x400000:x})")


if __name__ == "__main__":
    main()
