#!/usr/bin/env python3
"""Boot Giants with a runtime-only patch to the renderer's device filter.

After gg_dx7r.dll is mapped (bp at the exe's LoadLibraryA return site 0x51EBEF):
  patch gg_dx7r+0x10D3: 0F 8C rel32 (jl reject) -> 90 x6   [format-check bypass]
Files on disk stay untouched (memory patch only).

Then runs the boot (erun exception passing) and leaves the target RUNNING.
"""
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xdbg_call import call  # noqa: E402

EXE = "G:/VibeRE/GiantsRE/RuntimeLab/GiantsWork/Giants.exe"
LOAD_RET = 0x51EBEF
PATCHES = [
    # (address, expected-prefix-before-patch, new-bytes, description)
    (0x100010D3, "0f8c", "90 90 90 90 90 90", "bypass format-check reject (jl->nops)"),
]


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
    call("WriteMemToAddress", {"address": "0x53AE80", "byteString": "B8 01 00 00 00 C3"}, timeout=20)
    call("WriteMemToAddress", {"address": "0x631890", "byteString": "01 00 00 00"}, timeout=20)
    call("SetBreakpoint", {"target": hex(LOAD_RET)}, timeout=20)
    call("run", {}, timeout=30)

    # grind startup pauses until the renderer load site
    armed = False
    for _ in range(80):
        eip = None
        for _ in range(10):
            try:
                r = call("WaitForPause", {}, timeout=25)
                if "TIMEOUT" not in str(r):
                    eip = evalx("eip")
                    break
            except Exception:
                pass
        if eip is None:
            continue
        if eip == LOAD_RET:
            armed = True
            break
        call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
    if not armed:
        print("[fatal] renderer load site never hit")
        return
    call("DeleteBreakpoint", {"target": hex(LOAD_RET)}, timeout=15)

    for addr, expect, newbytes, desc in PATCHES:
        raw = call("ReadMemory", {"address": hex(addr), "length": 8}, timeout=20)
        line = ""
        for ln in raw.splitlines():
            if ":" in ln and "  " in ln:
                line = ln.split(":", 1)[1].split("  ")[0].strip().replace(" ", "")
                break
        ok = line.lower().startswith(expect.lower())
        print(f"[patch] {desc} @ {hex(addr)}: current={line[:12]} expected-prefix={expect} -> {'APPLY' if ok else 'SKIP(bytes mismatch!)'}")
        if ok:
            r = call("WriteMemToAddress", {"address": hex(addr), "byteString": newbytes}, timeout=20)
            print(f"        {r.strip().splitlines()[0]}")

    call("run", {}, timeout=30)
    resumes = 0
    t0 = time.time()
    running_since = None
    while time.time() - t0 < 300:
        time.sleep(5)
        try:
            state = call("GetDebugState", {}, timeout=15)
        except Exception:
            continue
        if "NO_TARGET" in state:
            print(f"[end] target gone after {resumes} resumes")
            return
        if "RUNNING" in state:
            if running_since is None:
                running_since = time.time()
            if time.time() - running_since > 45:
                print(f"[ok] RUNNING stable ({resumes} resumes) — check the screen")
                break
        else:
            running_since = None
            resumes += 1
            if resumes < 50:
                eip = evalx("eip")
                print(f"[erun {resumes}] {hex(eip or 0)}")
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)


if __name__ == "__main__":
    main()
