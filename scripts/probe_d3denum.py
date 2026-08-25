#!/usr/bin/env python3
"""Probe the renderer's D3D device enumeration chain.

Sets bp on LoadLibraryA; when gg_dx7r loads, sets bps on:
  gg_dx7r+0x1050 (D3DEnum_EnumerateDevices wrapper)
  gg_dx7r+0x10A0 (internal per-device callback)
  gg_dx7r+0xD7E0 (enumerator driver)
Then runs and reports which links fire, leaving target paused at the last hit.
"""
import os
import re
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xdbg_call import call  # noqa: E402

EXE = "G:/VibeRE/GiantsRE/RuntimeLab/GiantsWork/Giants.exe"
CD_CHECK = 0x53AE80
GG = 0x10000000
SITES = {
    GG + 0x1050: "D3DEnum_EnumerateDevices",
    GG + 0x10A0: "enum_internal_callback",
    GG + 0xD7E0: "enumerator_driver",
}


def evalx(expr):
    try:
        out = call("EvalExpression", {"expression": expr}, timeout=20)
    except Exception:
        return None
    first = out.strip().splitlines()[0] if out.strip() else ""
    return int(first.split()[0], 16) if first.startswith("0x") else None


def main():
    call("LoadBinary", {"filePath": EXE}, timeout=60)
    call("DeleteAllBreakpoints", {}, timeout=20)
    call("WriteMemToAddress", {"address": hex(CD_CHECK), "byteString": "B8 01 00 00 00 C3"}, timeout=20)
    call("WriteMemToAddress", {"address": "0x631890", "byteString": "01 00 00 00"}, timeout=20)
    call("SetBreakpoint", {"target": "LoadLibraryA"}, timeout=20)
    call("run", {}, timeout=30)

    armed = False
    fired = []
    resumes = 0
    t0 = time.time()
    while time.time() - t0 < 300:
        try:
            r = call("WaitForPause", {}, timeout=40)
        except Exception:
            r = "TIMEOUT"
        if "TIMEOUT" in str(r):
            continue
        state = call("GetDebugState", {}, timeout=15)
        if "NO_TARGET" in state:
            print("[end] target gone")
            return
        eip = evalx("eip")
        if not armed:
            # at LoadLibraryA: check arg
            arg = evalx("[esp+4]")
            if arg:
                raw = call("ReadMemory", {"address": hex(arg), "length": 64}, timeout=15)
                name = ""
                for line in raw.splitlines():
                    m = re.match(r"^\s*[0-9A-Fa-f]+:((?:\s+[0-9A-Fa-f]{2})+)", line)
                    if not m:
                        continue
                    for pair in m.group(1).split():
                        b = int(pair, 16)
                        if b == 0:
                            break
                        if 32 <= b < 127:
                            name += chr(b)
                        else:
                            name = ""
                            break
                    if name:
                        break
                print(f"[LoadLibraryA] {name!r}")
                if "gg_dx7r" in name.lower():
                    call("DeleteBreakpoint", {"target": "LoadLibraryA"}, timeout=15)
                    for addr, nm in SITES.items():
                        rr = call("SetBreakpoint", {"target": hex(addr)}, timeout=15)
                        print(f"[bp] {nm} @ {hex(addr)}: {'ok' if 'error' not in rr.lower() else rr.strip()}")
                    armed = True
            call("run", {}, timeout=30)
            continue
        if eip in SITES:
            fired.append(SITES[eip])
            print(f"*** HIT {SITES[eip]} (fire #{len(fired)}) ***")
            if len(fired) >= 6:
                print("[done] leaving paused for inspection")
                return
            call("run", {}, timeout=30)
            continue
        resumes += 1
        if resumes < 40:
            print(f"[erun] pause at {hex(eip or 0)}")
        call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
    print(f"[end] budget: fired={fired}")


if __name__ == "__main__":
    main()
