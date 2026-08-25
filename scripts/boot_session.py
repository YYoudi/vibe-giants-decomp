#!/usr/bin/env python3
"""Canonical Giants boot session under x64dbg.

LoadBinary -> apply runtime CD-check stub (Giants.exe+0x13AE80) -> run,
auto-resuming startup/exception pauses. Leaves the target RUNNING (menu).

The stub `mov eax,1; ret` makes cd_check() always pass. Patch is memory-only;
the exe file on disk stays byte-identical to vanilla.
"""
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xdbg_call import call  # noqa: E402

EXE = "G:/VibeRE/GiantsRE/RuntimeLab/GiantsWork/Giants.exe"
CD_CHECK = 0x53AE80  # Giants.exe RVA 0x13AE80
STUB = "B8 01 00 00 00 C3"  # mov eax,1 ; ret


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
    call("WriteMemToAddress", {"address": hex(CD_CHECK), "byteString": STUB}, timeout=20)
    # also pre-set the "already validated" cache flag used by other paths
    call("WriteMemToAddress", {"address": "0x631890", "byteString": "01 00 00 00"}, timeout=20)
    # deliver ALL exceptions to the debuggee (never swallow C++ EH with plain 'run')
    call("ExecuteDebuggerCommand", {"command": "IgnoreRange 00000000-FFFFFFFF"}, timeout=20)
    chk = call("ReadMemory", {"address": hex(CD_CHECK), "length": 8}, timeout=20)
    print("[patch] cd_check stub:", chk.strip().splitlines()[1] if len(chk.strip().splitlines()) > 1 else chk)
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
        if "NO_TARGET" in state or "isDebugging: false" in state:
            print(f"[end] target gone after +{int(time.time()-t0)}s ({resumes} resumes)")
            return
        if "RUNNING" in state:
            if running_since is None:
                running_since = time.time()
            if time.time() - running_since > 60:
                print(f"[ok] target RUNNING stably for 60s (+{int(time.time()-t0)}s total, {resumes} resumes) — menu presumed")
                break
        else:
            running_since = None
            eip = evalx("eip")
            resumes += 1
            if resumes <= 40:
                print(f"[erun {resumes}] pause at {hex(eip or 0)}")
            # erun: resume AND deliver the exception to the debuggee
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)

    mods = call("ListModules", {}, timeout=30)
    interesting = [l for l in mods.splitlines()
                   if any(k in l.lower() for k in ("gg_", "ddraw", "d3d", "dsound", "dinput", "giants"))]
    print("[modules]\n" + "\n".join(interesting))


if __name__ == "__main__":
    main()
