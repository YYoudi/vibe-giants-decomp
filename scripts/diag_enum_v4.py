#!/usr/bin/env python3
"""Diagnostic v4: trace every D3DEnum_EnumerateDevices call (gg_dx7r+0x1050)
with the live device-counter value, plus the enum driver +0xD2B0 and the
device-add +0x1300 — to find where/when the count becomes 0.

Also answers: is there a SECOND enum pass (same dll instance, no reload)?
"""
import os
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xdbg_call import call  # noqa: E402

EXE = "G:/VibeRE/GiantsRE/RuntimeLab/GiantsWork/Giants.exe"
CD_CHECK = 0x53AE80
LOAD_RET_SITE = 0x51EBEF
PATCH_RVA = 0x10D3
NOP6 = "90 90 90 90 90 90"
WRAPPER = 0x10001050   # D3DEnum_EnumerateDevices
DRIVER = 0x10000D2B0 - 0x10000000 + 0x10000000  # placeholder, fixed below
DRIVER = 0x1000D2B0    # enum driver (Mecc build)
ADDDEV = 0x10001300    # device-add


def evalx(expr):
    try:
        out = call("EvalExpression", {"expression": expr}, timeout=15)
    except Exception:
        return None
    first = out.strip().splitlines()[0] if out.strip() else ""
    return int(first.split()[0], 16) if first.startswith("0x") else None


def ps(cmd):
    return subprocess.run(["powershell", "-NoProfile", "-Command", cmd],
                          capture_output=True, text=True, timeout=30).stdout.strip()


def click_ok(pid):
    ps(f"Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class W {{ [DllImport(\"user32.dll\")] public static extern bool SetCursorPos(int x,int y); [DllImport(\"user32.dll\")] public static extern void mouse_event(int f,int dx,int dy,int d,int i); }}';"
       "$p=Get-Process -Id " + str(pid) + ";"
       "Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class R { [StructLayout(LayoutKind.Sequential)] public struct RECT { public int L,T,Rt,B; } [DllImport(\"user32.dll\")] public static extern bool GetWindowRect(IntPtr h, out RECT r); }';"
       "$r=New-Object R+RECT; [R]::GetWindowRect($p.MainWindowHandle,[ref]$r)|Out-Null;"
       f"[W]::SetCursorPos($r.L+[int](($r.Rt-$r.L)*0.26),$r.T+[int](($r.B-$r.T)*0.74))|Out-Null;"
       "[W]::mouse_event(2,0,0,0,0); Start-Sleep -Milliseconds 70; [W]::mouse_event(4,0,0,0,0)")


def main():
    subprocess.run(["taskkill", "/IM", "Giants.exe", "/F"], capture_output=True)
    time.sleep(1)
    pid = None
    call("LoadBinary", {"filePath": EXE}, timeout=60)
    call("DeleteAllBreakpoints", {}, timeout=20)
    call("WriteMemToAddress", {"address": hex(CD_CHECK), "byteString": "B8 01 00 00 00 C3"}, timeout=20)
    call("WriteMemToAddress", {"address": "0x631890", "byteString": "01 00 00 00"}, timeout=20)

    state = call("GetDebugState", {}, timeout=15)
    for ln in state.splitlines():
        if ln.startswith("pid:"):
            pid = int(ln.split()[1])

    call("SetBreakpoint", {"target": hex(LOAD_RET_SITE)}, timeout=15)
    call("run", {}, timeout=30)

    armed_patch = False
    sites_on = False
    wrap_hits = []
    drv_hits = []
    add_hits = []
    t0 = time.time()
    last_click = 0
    while time.time() - t0 < 420:
        try:
            r = call("WaitForPause", {}, timeout=10)
            eip = evalx("eip") if "TIMEOUT" not in str(r) else None
        except Exception:
            eip = None
        st = call("GetDebugState", {}, timeout=10)
        if "NO_TARGET" in st:
            print("[end] target gone")
            break
        if eip is None:
            # fully running: occasional OK click to advance fallbacks
            now = time.time()
            if now - last_click > 18:
                click_ok(pid)
                print("[click] OK attempted")
                last_click = now
                call("run", {}, timeout=30)
            continue

        if not armed_patch and eip == LOAD_RET_SITE:
            call("DeleteBreakpoint", {"target": hex(LOAD_RET_SITE)}, timeout=10)
            base_raw = call("EvalExpression", {"expression": "gg_dx7r"}, timeout=15)
            base = evalx("gg_dx7r") or 0x10000000
            addr = base + PATCH_RVA
            raw = call("ReadMemory", {"address": hex(addr), "length": 6}, timeout=15)
            cur = ""
            for ln in raw.splitlines():
                if ":" in ln and "  " in ln:
                    cur = ln.split(":", 1)[1].split("  ")[0].strip().replace(" ", "").lower()
                    break
            call("WriteMemToAddress", {"address": hex(addr), "byteString": NOP6}, timeout=15)
            raw2 = call("ReadMemory", {"address": hex(addr), "length": 6}, timeout=15)
            ver = "909090" in raw2.replace(" ", "").replace("\n", "").lower()
            print(f"[patch] base={hex(base)} VERIFIED={ver}")
            armed_patch = True
            for name, a in (("wrapper", WRAPPER), ("driver", DRIVER), ("adddev", ADDDEV)):
                call("SetBreakpoint", {"target": hex(a)}, timeout=15)
            sites_on = True
            call("run", {}, timeout=30)
            continue

        if armed_patch and sites_on and eip == WRAPPER:
            cnt = evalx("[0x1002844C]")
            wrap_hits.append(cnt)
            print(f"[wrapper] call#{len(wrap_hits)} count-at-entry={cnt}")
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue
        if armed_patch and sites_on and eip == DRIVER:
            drv_hits.append(1)
            if len(drv_hits) <= 12:
                print(f"[driver] enter #{len(drv_hits)}")
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue
        if armed_patch and sites_on and eip == ADDDEV:
            cnt_after = evalx("[0x1002844C]")
            add_hits.append(cnt_after)
            if len(add_hits) <= 12:
                print(f"[adddev] accepted! count-after={cnt_after}")
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)

    print(f"[summary] wrapper_calls={wrap_hits} driver_enters={len(drv_hits)} accepts={len(add_hits)}")


if __name__ == "__main__":
    main()
