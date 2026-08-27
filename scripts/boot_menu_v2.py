#!/usr/bin/env python3
"""Boot Giants toward the real main menu — v2 with patch persistence across
renderer reinitializations (v1 lesson: gg_dx7r.dll reload wipes memory patches).

Strategy:
- bp at the exe's LoadLibraryA return site 0x51EBEF stays armed forever;
  EVERY hit = a fresh gg_dx7r mapping -> re-verify & re-write the 6 NOPs
  at gg_dx7r+0x10D3 before continuing.
- While RUNNING: periodically foreground the game window, click its dialog-OK
  spot (handles « Continue? » rounds), and save screen-region snapshots.
- Evidence = PNGs on disk; a human-level vision pass reads them afterwards.
"""
import os
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xdbg_call import call  # noqa: E402

EXE = "G:/VibeRE/GiantsRE/RuntimeLab/GiantsWork/Giants.exe"
LOAD_RET = 0x51EBEF
PATCH_ADDR = 0x100010D3
NOP6 = "90 90 90 90 90 90"
SNAPDIR = "G:/VibeRE/GiantsRE/RuntimeLab/logs"
BUDGET_S = 400


def evalx(expr):
    try:
        out = call("EvalExpression", {"expression": expr}, timeout=20)
    except Exception:
        return None
    first = out.strip().splitlines()[0] if out.strip() else ""
    return int(first.split()[0], 16) if first.startswith("0x") else None


def ps(cmd):
    return subprocess.run(["powershell", "-NoProfile", "-Command", cmd],
                          capture_output=True, text=True, timeout=30).stdout.strip()


def win_rect(pid):
    out = ps(f"$p=Get-Process -Id {pid} -ErrorAction Stop;"
             "$m=[System.Runtime.InteropServices.Marshal];"
             "Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class R { [StructLayout(LayoutKind.Sequential)] public struct RECT { public int L,T,Rt,B; } [DllImport(\"user32.dll\")] public static extern bool GetWindowRect(IntPtr h, out RECT r); }';"
             "$r=New-Object R+RECT; [R]::GetWindowRect($p.MainWindowHandle,[ref]$r)|Out-Null; \"$($r.L),$($r.T),$($r.Rt),$($r.B)\"")
    try:
        L, T, R, B = [int(x) for x in out.split(",")]
        return L, T, R, B
    except Exception:
        return None


def click(x, y):
    ps(f"Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class W {{ [DllImport(\"user32.dll\")] public static extern bool SetCursorPos(int x,int y); [DllImport(\"user32.dll\")] public static extern void mouse_event(int f,int dx,int dy,int d,int i); }}';"
       f"[W]::SetCursorPos({x},{y})|Out-Null; Start-Sleep -Milliseconds 250;"
       "[W]::mouse_event(2,0,0,0,0); Start-Sleep -Milliseconds 70; [W]::mouse_event(4,0,0,0,0)")


def foreground(pid):
    ps(f"Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class F {{ [DllImport(\"user32.dll\")] public static extern bool SetForegroundWindow(IntPtr h); }}';"
       f"[F]::SetForegroundWindow((Get-Process -Id {pid}).MainWindowHandle)|Out-Null")


def snapshot(pid, name):
    try:
        from PIL import ImageGrab
        rect = win_rect(pid)
        if not rect:
            return None
        foreground(pid)
        time.sleep(0.35)
        img = ImageGrab.grab(bbox=rect)
        path = os.path.join(SNAPDIR, name)
        img.save(path)
        return path
    except Exception as e:
        print(f"  snap err {e}")
        return None


def apply_patch_round(tag):
    raw = call("ReadMemory", {"address": hex(PATCH_ADDR), "length": 8}, timeout=20)
    cur = ""
    for ln in raw.splitlines():
        if ":" in ln and "  " in ln:
            cur = ln.split(":", 1)[1].split("  ")[0].strip().replace(" ", "").lower()
            break
    if cur.startswith("909090"):
        print(f"[{tag}] patch already present ({cur[:12]})")
        return True
    if cur.startswith("0f8c"):
        call("WriteMemToAddress", {"address": hex(PATCH_ADDR), "byteString": NOP6}, timeout=20)
        print(f"[{tag}] PATCH APPLIED ({cur[:12]} -> NOPx6)")
        return True
    print(f"[{tag}] unexpected bytes {cur[:16]} — writing anyway")
    call("WriteMemToAddress", {"address": hex(PATCH_ADDR), "byteString": NOP6}, timeout=20)
    return True


def main():
    subprocess.run(["taskkill", "/IM", "Giants.exe", "/F"], capture_output=True)
    time.sleep(1)
    pid = None
    call("LoadBinary", {"filePath": EXE}, timeout=60)
    call("DeleteAllBreakpoints", {}, timeout=20)
    call("WriteMemToAddress", {"address": "0x53AE80", "byteString": "B8 01 00 00 00 C3"}, timeout=20)
    call("WriteMemToAddress", {"address": "0x631890", "byteString": "01 00 00 00"}, timeout=20)
    call("SetBreakpoint", {"target": hex(LOAD_RET)}, timeout=20)
    state = call("GetDebugState", {}, timeout=15)
    for ln in state.splitlines():
        if ln.startswith("pid:"):
            pid = int(ln.split()[1])
    print(f"[boot] pid={pid}")

    t0 = time.time()
    patches_done = 0
    last_snap = 0
    last_click = 0
    running_since = None
    while time.time() - t0 < BUDGET_S:
        eip = None
        try:
            r = call("WaitForPause", {}, timeout=8)
            if "TIMEOUT" not in str(r):
                eip = evalx("eip")
        except Exception:
            pass
        state = call("GetDebugState", {}, timeout=10)
        if "NO_TARGET" in state:
            print("[end] target gone")
            break
        if eip == LOAD_RET:
            patches_done += 1
            print(f"[reload #{patches_done}] gg_dx7r mapped — re-patching")
            apply_patch_round(f"r{patches_done}")
            call("run", {}, timeout=30)
            continue
        if eip is not None:
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue
        # running phase: housekeeping
        if running_since is None:
            running_since = time.time()
        now = time.time()
        if now - last_snap > 14 and pid:
            p = snapshot(pid, f"v2_t{int(now-t0):03d}.png")
            if p:
                print(f"[snap] {os.path.basename(p)}")
            last_snap = now
        if now - running_since > 12 and now - last_click > 15 and pid:
            rect = win_rect(pid)
            if rect:
                L, T, R, B = rect
                if R - L > 50:
                    click(L + int((R - L) * 0.26), T + int((B - T) * 0.74))
                    print("[click] OK-spot")
                    last_click = now
    # final evidence shots
    if pid:
        for i in range(2):
            snapshot(pid, f"v2_final{i}.png")
            time.sleep(3)
    print(f"[done] patch rounds={patches_done} budget={int(time.time()-t0)}s")


if __name__ == "__main__":
    main()
