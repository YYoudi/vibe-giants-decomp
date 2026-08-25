#!/usr/bin/env python3
"""Boot-flow tracer for Giants.exe via the x64dbg MCP plugin.

Sets breakpoints on key Win32 APIs, then for each hit logs:
  - API name + interesting string/int arguments
  - return address resolved to module+RVA (caller site)

Events are appended as JSON lines to RuntimeLab/logs/boot_trace_<ts>.jsonl.
The target is left RUNNING when no more breakpoints hit (game should sit at
its menu) — nothing is killed.

Usage:
  python scripts/trace_boot.py [--max 600] [--idle 45]
"""
import datetime
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xdbg_call import call  # noqa: E402

# api -> {argidx: kind} describing which stack args to capture
API_ARGS = {
    "CreateFileA": {1: "str", 2: "hex"},
    "LoadLibraryA": {1: "str"},
    "RegOpenKeyExA": {2: "str"},
    "RegQueryValueExA": {2: "str"},
    "GetVolumeInformationA": {1: "str"},
    "GetDriveTypeA": {1: "str"},
    "GetPrivateProfileStringA": {1: "str", 2: "str", 6: "str"},
    "MessageBoxA": {1: "str", 2: "str"},
}

HEXLINE = re.compile(r"^\s*([0-9A-Fa-f]{8,16}):((?:\s+[0-9A-Fa-f]{2})+)")


def evalx(expr: str):
    """Evaluate an x64dbg expression, return int or None."""
    try:
        out = call("EvalExpression", {"expression": expr}, timeout=15)
    except Exception:
        return None
    m = re.search(r"0x[0-9A-Fa-f]+", out)
    return int(m.group(0), 16) if m else None


def read_cstr(addr: int, maxlen: int = 520) -> str:
    """Read a NUL-terminated ANSI string via ReadMemory hex dump."""
    if not addr:
        return ""
    try:
        out = call("ReadMemory", {"address": hex(addr), "length": maxlen}, timeout=15)
    except Exception:
        return "<read-failed>"
    raw = bytearray()
    for line in out.splitlines():
        m = HEXLINE.match(line)
        if not m:
            continue
        for pair in m.group(2).split():
            raw.append(int(pair, 16))
            if raw[-1] == 0:
                try:
                    return raw[:-1].decode("cp1252", errors="replace")
                except Exception:
                    return repr(bytes(raw[:-1]))
    return raw.decode("cp1252", errors="replace")


def get_modules():
    """Return list of (name, base, size) parsed from ListModules."""
    try:
        out = call("ListModules", {}, timeout=20)
    except Exception:
        return []
    mods = []
    for line in out.splitlines():
        m = re.match(r"^\s*(\S+)\s+([0-9A-Fa-f]{8,16})\s+([0-9A-Fa-f]+)\s*(\S+)", line)
        if m:
            mods.append((m.group(1), int(m.group(2), 16), int(m.group(3), 16)))
    return mods


def locate(addr: int, mods) -> str:
    for name, base, size in mods:
        if base <= addr < base + size:
            return f"{name}+0x{addr - base:X}"
    return f"0x{addr:X}"


def stack_read(esp: int, offset: int):
    return evalx(f"[{esp + offset:#x}]")


def wait_paused(idle_sec: int) -> str:
    """Poll debug state until PAUSED / target gone / idle timeout.

    Returns 'paused', 'gone' or 'idle'."""
    deadline = datetime.datetime.now() + datetime.timedelta(seconds=idle_sec)
    while datetime.datetime.now() < deadline:
        try:
            state = call("GetDebugState", {}, timeout=8)
        except Exception:
            state = ""
        if "NO_TARGET" in state or "isDebugging: false" in state:
            return "gone"
        if "RUNNING" in state or "isRunning: true" in state:
            time.sleep(1.0)
            continue
        # PAUSED / LOCKED / anything else with isRunning: false = a stop we must examine
        return "paused"
    return "idle"


import time  # noqa: E402  (used by wait_paused)


def main():
    max_events = 600
    idle_sec = 45
    if "--max" in sys.argv:
        max_events = int(sys.argv[sys.argv.index("--max") + 1])
    if "--idle" in sys.argv:
        idle_sec = int(sys.argv[sys.argv.index("--idle") + 1])

    os.makedirs(os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                             "RuntimeLab", "logs"), exist_ok=True)
    ts = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
    logfile = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                           "RuntimeLab", "logs", f"boot_trace_{ts}.jsonl")

    # sanity: debugger must have a target loaded
    state = call("GetDebugState", {}, timeout=10)
    if "NO_TARGET" in state or "isDebugging: false" in state:
        print("No target loaded. Use LoadBinary first.")
        sys.exit(1)

    api_addr = {}
    for api in API_ARGS:
        call("ExecuteDebuggerCommand", {"command": f"bp {api}"}, timeout=15)
        a = evalx(api)
        if a:
            api_addr[a] = api
    print(f"[bps] set: {', '.join(sorted(set(api_addr.values())))}")

    mods = get_modules()
    if not mods:
        print("[warn] ListModules parse failed; caller resolution degrades to hex")

    n = 0
    stray = 0
    with open(logfile, "w", encoding="utf-8") as lf:
        call("ExecuteDebuggerCommand", {"command": "g"}, timeout=15)
        while n < max_events and stray < 250:
            why = wait_paused(idle_sec)
            if why == "gone":
                print(f"[end] target exited after {n} events")
                break
            if why == "idle":
                print(f"[end] no breakpoint hit for {idle_sec}s ({n} events) — leaving target RUNNING")
                break
            eip = evalx("eip")
            esp = evalx("esp")
            api = api_addr.get(eip)
            ev = {"seq": n + 1, "eip": hex(eip or 0)}
            if api and esp:
                stray = 0
                ret = stack_read(esp, 0)
                ev["api"] = api
                args = {}
                for idx, kind in API_ARGS[api].items():
                    val = stack_read(esp, 4 * idx)
                    if val is None:
                        continue
                    args[f"a{idx}"] = read_cstr(val) if kind == "str" else hex(val)
                ev["args"] = args
                ev["caller"] = locate(ret, mods) if ret else "?"
            else:
                stray += 1
                ev["pause"] = f"non-bp stop #{stray} (DLL entry / exception?)"
                try:
                    tail = call("GetEventLog", {}, timeout=10).splitlines()[-2:]
                    ev["logtail"] = tail
                except Exception:
                    pass
            lf.write(json.dumps(ev, ensure_ascii=False) + "\n")
            lf.flush()
            n += 1
            kind = ev.get("api", "PAUSE")
            args_s = " ".join(f"{k}={v[:70]}" for k, v in ev.get("args", {}).items())
            print(f"[{n:3d}] {kind:24s} {args_s}  <- {ev.get('caller','')}")
            call("ExecuteDebuggerCommand", {"command": "g"}, timeout=15)

    print(f"[done] {n} events -> {logfile}")


if __name__ == "__main__":
    main()
