#!/usr/bin/env python3
"""Full-boot trace collector for Giants.exe via x64dbg MCP.

Restarts a clean debug session on the working copy, sets non-pausing
conditional log breakpoints on key Win32 APIs (x64dbg logs formatted text
without stopping the target), runs the game at native speed and aggregates
the debugger log via periodic LogSave into a single master file.

Output: RuntimeLab/logs/boot_full_<ts>.log
"""
import datetime
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xdbg_call import call  # noqa: E402

EXE = "G:/VibeRE/GiantsRE/RuntimeLab/GiantsWork/Giants.exe"
LOGDIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "RuntimeLab", "logs")
RAW = os.path.join(LOGDIR, "xdbg_boot_raw.log")

# api -> log format (condition always "0": log & continue, never pause)
APIS = {
    "CreateFileA":           "CF|{s@[esp+4]}|access={x@[esp+8]}|ret={x@[esp]}",
    "LoadLibraryA":          "LL|{s@[esp+4]}|ret={x@[esp]}",
    "RegOpenKeyExA":         "RO|{s@[esp+8]}|ret={x@[esp]}",
    "RegQueryValueExA":      "RQ|{s@[esp+8]}|ret={x@[esp]}",
    "RegCreateKeyExA":       "RC|{s@[esp+8]}|ret={x@[esp]}",
    "RegSetValueExA":        "RS|{s@[esp+8]}|ret={x@[esp]}",
    "GetVolumeInformationA": "VI|{s@[esp+4]}|ret={x@[esp]}",
    "GetDriveTypeA":         "DT|{s@[esp+4]}|ret={x@[esp]}",
    "MessageBoxA":           "MB|cap={s@[esp+4]}|txt={s@[esp+8]}|ret={x@[esp]}",
    "FindFirstFileA":        "FF|{s@[esp+4]}|ret={x@[esp]}",
}


def evalx(expr):
    out = call("EvalExpression", {"expression": expr}, timeout=20)
    first = out.strip().splitlines()[0] if out.strip() else ""
    if first.startswith("0x"):
        return int(first.split()[0], 16)
    return None


def main():
    os.makedirs(LOGDIR, exist_ok=True)
    ts = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
    master = os.path.join(LOGDIR, f"boot_full_{ts}.log")

    print("[1] restarting debug session...")
    call("LoadBinary", {"filePath": EXE}, timeout=60)
    state = call("GetDebugState", {}, timeout=20)
    if "NO_TARGET" in state:
        print("load failed:", state)
        sys.exit(1)

    print("[2] setting conditional log breakpoints...")
    call("DeleteAllBreakpoints", {}, timeout=20)
    set_ok = []
    for api, fmt in APIS.items():
        addr = evalx(api)
        if not addr:
            print(f"    {api}: unresolved, skipped")
            continue
        r = call("SetConditionalBreakpoint",
                 {"address": hex(addr), "condition": "0", "log": fmt}, timeout=20)
        ok = "error" not in r.lower()
        set_ok.append(api)
        print(f"    {api} @ {hex(addr)}: {'ok' if ok else r.strip()}")

    print("[3] clearing logs and running target...")
    call("ClearEventLog", {}, timeout=15)
    call("ExecuteDebuggerCommand", {"command": f"LogSave {RAW}"}, timeout=15)
    call("run", {}, timeout=30)

    # [4] collect: resume unexpected pauses, snapshot log periodically
    seen = 0
    last_growth = time.time()
    resumes = 0
    t0 = time.time()
    with open(master, "w", encoding="utf-8", errors="replace") as mf:
        while time.time() - t0 < 420:
            time.sleep(10)
            try:
                state = call("GetDebugState", {}, timeout=15)
            except Exception as e:
                state = f"ERR {e}"
            if "NO_TARGET" in state or "isDebugging: false" in state:
                mf.write(f"=== TARGET GONE at +{int(time.time()-t0)}s ===\n")
                print("[end] target exited")
                break
            if ("RUNNING" not in state) and resumes < 80:
                # entry bp / exception / TLS callback — resume
                resumes += 1
                eip = evalx("eip")
                mf.write(f"=== manual resume #{resumes} at {hex(eip or 0)} ===\n")
                call("ExecuteDebuggerCommand", {"command": "g"}, timeout=20)
            # snapshot log
            call("ExecuteDebuggerCommand", {"command": f"LogSave {RAW}"}, timeout=20)
            try:
                with open(RAW, "r", encoding="utf-8", errors="replace") as rf:
                    lines = rf.readlines()
            except OSError:
                lines = []
            if len(lines) > seen:
                mf.writelines(lines[seen:])
                mf.flush()
                seen = len(lines)
                last_growth = time.time()
            elif time.time() - last_growth > 90:
                mf.write(f"=== idle 90s at +{int(time.time()-t0)}s, target {'RUNNING' if 'RUNNING' in state else state.strip()} ===\n")
                print("[end] log idle 90s — game presumably at menu, leaving it running")
                break
            print(f"    +{int(time.time()-t0):3d}s lines={seen} resumes={resumes} state={'RUN' if 'RUNNING' in state else 'PAUSE'}")

    print(f"[done] master log: {master} ({seen} lines)")


if __name__ == "__main__":
    main()
