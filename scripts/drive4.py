#!/usr/bin/env python3
"""drive4.py — eternal daemon: grind pauses (erun), land the vtable redirect,
click dialogs, snapshot milestones. Status -> RuntimeLab/logs/d4_status.txt"""
import os
import re
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xdbg_call import call  # noqa: E402

SNAPDIR = "G:/VibeRE/GiantsRE/RuntimeLab/logs"
SCRATCH = None  # parsed from engine log
BUDGET_S = 1200

_LOG = open(os.path.join(SNAPDIR, "d4_status.txt"), "a", encoding="utf-8")


def log(msg):
    line = f"[{int(time.time())}] {msg}"
    print(line, flush=True)
    _LOG.write(line + "\n")
    _LOG.flush()


def evalx(expr):
    try:
        out = call("EvalExpression", {"expression": expr}, timeout=12)
    except Exception:
        return None
    first = out.strip().splitlines()[0] if out.strip() else ""
    return int(first.split()[0], 16) if first.startswith("0x") else None


def ps(cmd):
    return subprocess.run(["powershell", "-NoProfile", "-Command", cmd],
                          capture_output=True, text=True, timeout=30).stdout.strip()


def get_pid():
    out = subprocess.run(["tasklist", "/FI", "IMAGENAME eq Giants.exe", "/FO", "CSV", "/NH"],
                         capture_output=True).stdout.decode("cp1252", errors="replace")
    m = re.search(r'"Giants\.exe","(\d+)"', out)
    return int(m.group(1)) if m else None


def click_center(pid):
    ps(f"Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class W {{ [DllImport(\"user32.dll\")] public static extern bool SetCursorPos(int x,int y); [DllImport(\"user32.dll\")] public static extern void mouse_event(int f,int dx,int dy,int d,int i); }}';"
       "$p=Get-Process -Id " + str(pid) + ";"
       "Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class R { [StructLayout(LayoutKind.Sequential)] public struct RECT { public int L,T,Rt,B; } [DllImport(\"user32.dll\")] public static extern bool GetWindowRect(IntPtr h, out RECT r); }';"
       "$r=New-Object R+RECT; [R]::GetWindowRect($p.MainWindowHandle,[ref]$r)|Out-Null;"
       f"[W]::SetCursorPos($r.L+[int](($r.Rt-$r.L)*0.5),$r.T+[int](($r.B-$r.T)*0.5))|Out-Null; Start-Sleep -Milliseconds 150;"
       "[W]::mouse_event(2,0,0,0,0); Start-Sleep -Milliseconds 70; [W]::mouse_event(4,0,0,0,0)")


def key_enter():
    ps("Add-Type -MemberDefinition '[DllImport(\"user32.dll\")] public static extern void keybd_event(int k,int s,int f,int e);' -Name K -Namespace W;"
       "[W.K]::keybd_event(0x0D,0,0,0); Start-Sleep -Milliseconds 50; [W.K]::keybd_event(0x0D,0,2,0)")


def snapshot(pid, name):
    try:
        from PIL import ImageGrab as IG
        out = ps(f"$p=Get-Process -Id {pid};"
                 "Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class R { [StructLayout(LayoutKind.Sequential)] public struct RECT { public int L,T,Rt,B; } [DllImport(\"user32.dll\")] public static extern bool GetWindowRect(IntPtr h, out RECT r); }';"
                 "$r=New-Object R+RECT; [R]::GetWindowRect($p.MainWindowHandle,[ref]$r)|Out-Null; \"$($r.L),$($r.T),$($r.Rt),$($r.B)\"")
        L, T, R, B = [int(x) for x in out.split(",")]
        if R - L <= 0:
            return None
        im = IG.grab(bbox=(L, T, R, B))
        path = os.path.join(SNAPDIR, name)
        im.save(path)
        return path
    except Exception as e:
        log(f"snap err {e}")
        return None


def try_redirect(scratch):
    obj = evalx("[0x654958]")
    if not obj or obj <= 0x10000:
        return False
    vt = evalx(hex(obj))
    if not vt or not (0x10000000 <= vt < 0x10050000):
        return False
    slot = vt + 0x10
    cur = evalx(hex(slot))
    if not cur or not (0x10000000 <= cur < 0x10050000) or cur == scratch:
        return cur == scratch
    stub = "B8 " + " ".join(f"{(scratch >> (8 * i)) & 0xFF:02X}" for i in range(4)) + " C3"
    call("WriteMemToAddress", {"address": hex(scratch), "byteString": stub}, timeout=12)
    call("WriteMemToAddress", {"address": hex(slot), "byteString":
         " ".join(f"{(scratch >> (8 * i)) & 0xFF:02X}" for i in range(4))}, timeout=12)
    new = evalx(hex(slot))
    ok = new == scratch
    log(f"vtable slot={hex(slot)} {hex(cur)} -> {hex(new)} ok={ok}")
    return ok


def main():
    global SCRATCH
    log("daemon start (waiting engine scratch)")
    t0 = time.time()
    redirected = False
    storms = 0
    pauses = 0
    snaps = []
    last_click = 0
    last_snap = 0
    last_red = 0
    while time.time() - t0 < BUDGET_S:
        eip = None
        try:
            r = call("WaitForPause", {}, timeout=7)
            if "TIMEOUT" not in str(r):
                eip = evalx("eip")
        except Exception:
            pass
        st = call("GetDebugState", {}, timeout=8)
        if "NO_TARGET" in st:
            log("END target gone")
            break
        # passive while the engine drives the session
        if not os.path.exists(os.path.join(SNAPDIR, "engine_done.txt")):
            now2 = time.time()
            pid2 = get_pid()
            if SCRATCH is None:
                try:
                    for _ln in open(os.path.join(SNAPDIR, "v5r_engine.log"), encoding="utf-8", errors="replace"):
                        m2 = re.search(r"\[scratch\] 0x([0-9a-fA-F]+)", _ln)
                        if m2:
                            SCRATCH = int(m2.group(1), 16)
                            log(f"scratch from engine: {hex(SCRATCH)}")
                            break
                except OSError:
                    pass
            if not redirected and SCRATCH and now2 - last_red > 2.5:
                last_red = now2
                redirected = try_redirect(SCRATCH)
            if pid2 and now2 - last_snap > 20:
                p = snapshot(pid2, f"d4p_t{int(now2 - t0):03d}.png")
                if p:
                    snaps.append(os.path.basename(p))
                    log(f"psnap {os.path.basename(p)}")
            if pid2 and now2 - last_click > 30:
                click_center(pid2)
                key_enter()
                last_click = now2
                log("pinput click+enter")
            time.sleep(2)
            continue
        if eip is not None:
            pauses += 1
            if eip == 0x432FDE:
                storms += 1
                if storms % 20 == 1:
                    log(f"storm AV+{storms} redirected={redirected}")
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            if not redirected and time.time() - last_red > 2.5:
                last_red = time.time()
                redirected = try_redirect(SCRATCH)
            continue
        now = time.time()
        pid = get_pid()
        if SCRATCH is None:
            try:
                for _ln in open(os.path.join(SNAPDIR, "v5r_engine.log"), encoding="utf-8", errors="replace"):
                    m = re.search(r"\[scratch\] 0x([0-9a-fA-F]+)", _ln)
                    if m:
                        SCRATCH = int(m.group(1), 16)
                        log(f"scratch from engine: {hex(SCRATCH)}")
                        break
            except OSError:
                pass
        if not redirected and SCRATCH and now - last_red > 2.5:
            last_red = now
            redirected = try_redirect(SCRATCH)
        if pid and now - last_snap > 20:
            p = snapshot(pid, f"d4_t{int(now - t0):03d}.png")
            if p:
                snaps.append(os.path.basename(p))
                log(f"snap {os.path.basename(p)}")
            last_snap = now
        if pid and now - last_click > 25:
            click_center(pid)
            key_enter()
            last_click = now
            log("input click+enter")
    if pid:
        snapshot(pid, "d4_final.png")
    log(f"[done] redirected={redirected} storms={storms} pauses={pauses}")


if __name__ == "__main__":
    main()
