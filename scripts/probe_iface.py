#!/usr/bin/env python3
"""Probe the renderer interface: after gg_dx7r is fully loaded (bp at the exe's
LoadLibraryA return site 0x51EBEF), set bps on every gg_dx7r export + the
D3DEnum chain, then log the interface call sequence.

Leaves target paused after N hits (or budget) for inspection.
"""
import os
import re
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xdbg_call import call  # noqa: E402

EXE = "G:/VibeRE/GiantsRE/RuntimeLab/GiantsWork/Giants.exe"
CD_CHECK = 0x53AE80
LOAD_RET_SITE = 0x51EBEF  # exe addr right after LoadLibraryA("gg_dx7r")
GG = 0x10000000
ENUM_SITES = {
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
    call("SetBreakpoint", {"target": hex(LOAD_RET_SITE)}, timeout=20)
    call("run", {}, timeout=30)

    armed = False
    sites = {}
    fired = []
    resumes = 0
    t0 = time.time()
    while time.time() - t0 < 420:
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
            if eip == LOAD_RET_SITE:
                call("DeleteBreakpoint", {"target": hex(LOAD_RET_SITE)}, timeout=15)
                exp = call("GetExports", {"module": "gg_dx7r"}, timeout=30)
                print("[exports]\n" + exp.strip())
                for line in exp.splitlines():
                    m = re.match(r"\s*(0x[0-9A-Fa-f]+)\s*(\d+)\s+(\S+)", line)
                    if m:
                        sites[int(m.group(1), 16)] = f"EXPORT:{m.group(3)}"
                sites.update(ENUM_SITES)
                for addr, nm in sites.items():
                    rr = call("SetBreakpoint", {"target": hex(addr)}, timeout=15)
                    okk = "error" not in rr.lower()
                    print(f"[bp] {nm} @ {hex(addr)}: {'ok' if okk else rr.strip()}")
                armed = True
            call("run", {}, timeout=30)
            continue
        if eip in sites:
            fired.append(sites[eip])
            print(f"*** HIT #{len(fired)}: {sites[eip]} @ {hex(eip)} ***")
            if len(fired) >= 25:
                print("[done] leaving paused")
                return
            call("run", {}, timeout=30)
            continue
        resumes += 1
        if resumes < 60:
            print(f"[erun] pause at {hex(eip or 0)}")
        call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
    print(f"[end] budget: {len(fired)} hits: {fired}")


if __name__ == "__main__":
    main()
