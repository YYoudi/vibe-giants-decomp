#!/usr/bin/env python3
"""Pause-probe: run Giants.exe until an interesting API breakpoint hits.

Sets pausing breakpoints on CD-check / renderer APIs, auto-resumes startup
DLL-entry pauses, and on the first interesting hit dumps the call stack and
leaves the target PAUSED for interactive inspection.

Usage: python scripts/probe_cdcheck.py [apis...]   (default set below)
"""
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xdbg_call import call  # noqa: E402

EXE = "G:/VibeRE/GiantsRE/RuntimeLab/GiantsWork/Giants.exe"
DEFAULT_APIS = ["GetVolumeInformationA", "GetDriveTypeA", "MessageBoxA", "LoadLibraryA"]


def evalx(expr):
    try:
        out = call("EvalExpression", {"expression": expr}, timeout=20)
    except Exception:
        return None
    first = out.strip().splitlines()[0] if out.strip() else ""
    return int(first.split()[0], 16) if first.startswith("0x") else None


def main():
    apis = sys.argv[1:] or DEFAULT_APIS
    call("LoadBinary", {"filePath": EXE}, timeout=60)
    call("DeleteAllBreakpoints", {}, timeout=20)
    addr = {}
    for api in apis:
        r = call("SetBreakpoint", {"target": api}, timeout=20)
        a = evalx(api)
        if a:
            addr[a] = api
        print(f"[bp] {api}: {r.strip().splitlines()[0] if r.strip() else '?'}")

    call("run", {}, timeout=30)
    n = 0
    while n < 300:
        n += 1
        try:
            r = call("WaitForPause", {}, timeout=45)
        except Exception:
            r = "TIMEOUT"
        if "TIMEOUT" in str(r):
            print("[info] WaitForPause timeout — issuing run again")
            call("run", {}, timeout=30)
            continue
        try:
            state = call("GetDebugState", {}, timeout=15)
        except Exception:
            state = ""
        if "NO_TARGET" in state:
            print("[end] target gone")
            return
        eip = evalx("eip")
        if eip in addr:
            print(f"\n*** HIT {addr[eip]} @ {hex(eip)} — leaving target PAUSED ***\n")
            print("== call stack ==")
            print(call("GetCallStack", {}, timeout=30))
            return
        # startup/DLL/exception pause -> resume
        print(f"[resume] pause at {hex(eip or 0)} ({state.strip().splitlines()[0] if state.strip() else '?'})")
        call("run", {}, timeout=30)
        time.sleep(0.3)

    print("[end] resume budget exhausted")


if __name__ == "__main__":
    main()
