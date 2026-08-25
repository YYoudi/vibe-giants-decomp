#!/usr/bin/env python3
"""Single-step one invocation of the renderer's D3D device-enum callback.

Boot -> wait gg_dx7r loaded (bp 0x51EBEF) -> bp gg_dx7r+0x10A0 -> on hit,
StepOver through the whole callback, logging eip. Reveals the exact reject path.
"""
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xdbg_call import call  # noqa: E402

EXE = "G:/VibeRE/GiantsRE/RuntimeLab/GiantsWork/Giants.exe"
LOAD_RET = 0x51EBEF
CB = 0x100010A0


def evalx(expr):
    try:
        out = call("EvalExpression", {"expression": expr}, timeout=20)
    except Exception:
        return None
    first = out.strip().splitlines()[0] if out.strip() else ""
    return int(first.split()[0], 16) if first.startswith("0x") else None


def wait_pause():
    for _ in range(12):
        try:
            r = call("WaitForPause", {}, timeout=25)
            if "TIMEOUT" not in str(r):
                return evalx("eip")
        except Exception:
            pass
    return None


def main():
    call("LoadBinary", {"filePath": EXE}, timeout=60)
    call("DeleteAllBreakpoints", {}, timeout=20)
    call("WriteMemToAddress", {"address": "0x53AE80", "byteString": "B8 01 00 00 00 C3"}, timeout=20)
    call("WriteMemToAddress", {"address": "0x631890", "byteString": "01 00 00 00"}, timeout=20)
    call("SetBreakpoint", {"target": hex(LOAD_RET)}, timeout=20)
    call("run", {}, timeout=30)
    # grind startup pauses until renderer load site
    for _ in range(80):
        eip = wait_pause()
        if eip is None:
            continue
        if eip == LOAD_RET:
            break
        call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
    else:
        print("[fatal] never reached renderer load site")
        return
    print("[+] gg_dx7r loaded")
    call("DeleteBreakpoint", {"target": hex(LOAD_RET)}, timeout=15)
    call("SetBreakpoint", {"target": hex(CB)}, timeout=20)
    call("run", {}, timeout=30)
    for _ in range(80):
        eip = wait_pause()
        if eip is None:
            continue
        if eip == CB:
            break
        call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
    else:
        print("[fatal] callback never hit")
        return
    print("[+] at enum callback entry — stepping")
    # grab device desc basics from stack: cb(GUID* guid, STR* desc, DWORD flags, ctx)
    # stdcall w/ ret 0x14 => args at esp+4.. after ret
    for name, off in (("guid", 4), ("desc", 8), ("flags", 0xC)):
        v = evalx(f"[esp+{off:#x}]")
        print(f"    arg {name} = {hex(v) if v else None}")
    trace = []
    for i in range(60):
        eip = evalx("eip")
        if eip is None:
            break
        trace.append(eip)
        print(f"  step {i:2d}: {hex(eip)} (gg_dx7r+0x{eip-0x10000000:x})" if 0x10000000 <= eip < 0x10050000 else f"  step {i:2d}: {hex(eip)}")
        if eip == 0x10001248 or eip == 0x10001254:  # reject/ret path
            print("  [reject path reached]")
            break
        r = call("StepOver", {}, timeout=25)
        if "error" in r.lower():
            print("  step err:", r.strip().splitlines()[0])
            break
    print("[done]")


if __name__ == "__main__":
    main()
