#!/usr/bin/env python3
"""run_to_menu.py — unified orchestrator toward the Giants main menu.

Composes every verified ingredient:
  * CD-check stub (Giants+0x53AE80)               [memory only]
  * gg_dx7r device-filter format-NOP (+0x10D3), re-applied on EVERY load of
    the dll through ANY LoadLibrary* API (dynamic return bp, live base)
  * auto-click on dialog OK-spot while RUNNING (« Continue? » rounds)
  * diagnostic breakpoints: enum wrapper/driver/adddev counts, upcall site
    0x432FC2 with args, renderer method NULL/OK exits
  * screen-region snapshots every ~15 s for native-vision review
"""
import os
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xdbg_call import call  # noqa: E402

EXE = "G:/VibeRE/GiantsRE/RuntimeLab/GiantsWork/Giants.exe"
CD_CHECK = 0x53AE80
PATCH_RVA = 0x10D3
NOP6 = "90 90 90 90 90 90"
LL_APIS = ["LoadLibraryA", "LoadLibraryW", "LoadLibraryExA", "LoadLibraryExW"]
SNAPDIR = "G:/VibeRE/GiantsRE/RuntimeLab/logs"
BUDGET_S = 480

# diagnostics
DIAG_WRAPPER = 0x10001050
DIAG_ADDDEV = 0x10001300
UPCALL_SITE = 0x432FC2


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


def snapshot(pid, name):
    try:
        from PIL import ImageGrab
        out = ps(f"$p=Get-Process -Id {pid};"
                 "Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class R { [StructLayout(LayoutKind.Sequential)] public struct RECT { public int L,T,Rt,B; } [DllImport(\"user32.dll\")] public static extern bool GetWindowRect(IntPtr h, out RECT r); }';"
                 "$r=New-Object R+RECT; [R]::GetWindowRect($p.MainWindowHandle,[ref]$r)|Out-Null; \"$($r.L),$($r.T),$($r.Rt),$($r.B)\"")
        L, T, R, B = [int(x) for x in out.split(",")]
        if R - L <= 0 or B - T <= 0:
            return None
        img = __import__("PIL.ImageGrab", fromlist=["ImageGrab"]).ImageGrab
        im = ImageGrab.grab(bbox=(L, T, R, B))
        path = os.path.join(SNAPDIR, name)
        im.save(path)
        return path
    except Exception as e:
        print(f"  snap err: {e}")
        return None


def read_str(addr, wide=False):
    import re
    raw = call("ReadMemory", {"address": hex(addr), "length": 96}, timeout=15)
    hexpart = ""
    for ln in raw.splitlines():
        m = re.match(r"^\s*[0-9A-Fa-f]+:((?:\s+[0-9A-Fa-f]{2})+)", ln)
        if m:
            hexpart += m.group(1).replace(" ", "")
    b = bytes.fromhex(hexpart[:384])
    s = b.decode("utf-16-le" if wide else "cp1252", errors="replace")
    return s.split("\x00")[0]


def gg_base():
    out = call("ListModules", {}, timeout=25)
    for ln in out.splitlines():
        if "gg_dx7r" in ln.lower():
            tok = ln.split("|")[0].strip()
            try:
                return int(tok, 16)
            except Exception:
                continue
    return None


def patch_round(tag):
    base = gg_base()
    if not base:
        print(f"[{tag}] no gg_dx7r module yet")
        return False
    addr = base + PATCH_RVA
    raw = call("ReadMemory", {"address": hex(addr), "length": 6}, timeout=15)
    cur = ""
    for ln in raw.splitlines():
        if ":" in ln and "  " in ln:
            cur = ln.split(":", 1)[1].split("  ")[0].strip().replace(" ", "").lower()
            break
    if not cur.startswith("909090"):
        call("WriteMemToAddress", {"address": hex(addr), "byteString": NOP6}, timeout=15)
    chk = call("ReadMemory", {"address": hex(addr), "length": 6}, timeout=15)
    okv = "909090" in chk.replace(" ", "").replace("\n", "").lower()
    print(f"[{tag}] patch@base={hex(base)} VERIFIED={okv}")
    return okv


def main():
    subprocess.run(["taskkill", "/IM", "Giants.exe", "/F"], capture_output=True)
    time.sleep(1)
    pid = None
    call("LoadBinary", {"filePath": EXE}, timeout=60)
    call("DeleteAllBreakpoints", {}, timeout=20)
    call("WriteMemToAddress", {"address": hex(CD_CHECK), "byteString": "B8 01 00 00 00 C3"}, timeout=20)
    call("WriteMemToAddress", {"address": "0x631890", "byteString": "01 00 00 00"}, timeout=20)

    ll_addr = {}
    for api in LL_APIS:
        call("SetBreakpoint", {"target": api}, timeout=15)
        a = evalx(api)
        if a:
            ll_addr[a] = api

    st = call("GetDebugState", {}, timeout=15)
    for ln in st.splitlines():
        if ln.startswith("pid:"):
            pid = int(ln.split()[1])
    print(f"[boot] pid={pid} ll-watch={list(ll_addr.values())}")
    call("SetBreakpoint", {"target": hex(DIAG_ADDDEV)}, timeout=15)   # accept counter
    call("SetBreakpoint", {"target": hex(UPCALL_SITE)}, timeout=15)   # upcall arg capture
    call("run", {}, timeout=30)

    armed_ret = None
    adds = 0
    ups = 0
    t0 = time.time()
    last_click = 0
    last_snap = 0
    snaps = []
    while time.time() - t0 < BUDGET_S:
        eip = None
        try:
            r = call("WaitForPause", {}, timeout=8)
            if "TIMEOUT" not in str(r):
                eip = evalx("eip")
        except Exception:
            pass
        stt = call("GetDebugState", {}, timeout=10)
        if "NO_TARGET" in stt:
            print("[end] target gone")
            break

        if eip is not None and eip in ll_addr:
            argp = evalx("[esp+4]")
            wide = ll_addr[eip].endswith("W")
            nm = read_str(argp, wide) if argp else ""
            if "gg_dx7r" in nm.lower():
                ret = evalx("[esp]")
                if ret:
                    call("SetBreakpoint", {"target": hex(ret)}, timeout=15)
                    armed_ret = ret
                    for a2 in ll_addr:
                        call("DisableBreakpoint", {"target": hex(a2)}, timeout=8)
                    call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
                    continue
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        if armed_ret and eip == armed_ret:
            call("DeleteBreakpoint", {"target": hex(armed_ret)}, timeout=10)
            armed_ret = None
            patch_round("reload")
            for a2 in ll_addr:
                call("EnableBreakpoint", {"target": hex(a2)}, timeout=8)
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        if eip == DIAG_ADDDEV:
            adds += 1
            cnt = evalx("[0x1002844C]")
            print(f"[adddev #{adds}] count-after={cnt}")
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        if eip == UPCALL_SITE:
            ups += 1
            obj = evalx("[esp]")
            vt = evalx(hex(obj)) if obj else None
            meth = evalx(f"{hex(vt)}+0x10") if vt else None
            print(f"[upcall #{ups}] obj={hex(obj or 0)} vtable={hex(vt or 0)} method={hex(meth or 0)}")
            if ups >= 3:
                print("[hold] pausing at upcall for inspection")
                break
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        if eip is not None:
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        now = time.time()
        if pid and now - last_snap > 15:
            p = snapshot(pid, f"rt_t{int(now-t0):03d}.png")
            if p:
                snaps.append(os.path.basename(p))
            last_snap = now
        if pid and now - last_click > 17:
            click_ok(pid)
            print("[click]")
            last_click = now

    p = snapshot(pid, "rt_final.png") if pid else None
    print(f"[done] adddev={adds} upcalls={ups} last_snaps={snaps[-3:]}")


if __name__ == "__main__":
    main()
