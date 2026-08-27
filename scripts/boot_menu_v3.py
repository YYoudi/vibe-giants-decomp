#!/usr/bin/env python3
"""Boot Giants toward the real main menu — v3, reload-proof patching.

Lessons baked in (v1/v2):
- gg_dx7r.dll is reloaded after the game's « Continue? » fallback, through an
  UNKNOWN call site — so we break on ALL LoadLibrary* exports, and when the
  argument is gg_dx7r, set a temporary bp on the caller's return address so we
  resume exactly after the mapping, then re-write the accept-NOPs.
- Never assume the preferred image base: resolve gg_dx7r's live base via
  ListModules on every patch round.
"""

import os
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xdbg_call import call  # noqa: E402

EXE = "G:/VibeRE/GiantsWork"
EXE = "G:/VibeRE/GiantsRE/RuntimeLab/GiantsWork/Giants.exe"
CD_CHECK = 0x53AE80
LOAD_RET_SITE = 0x51EBEF          # exe site after its own LoadLibraryA(gg_dx7r)
PATCH_RVA = 0x10D3                # jl reject inside gg_dx7r device filter
NOP6 = "90 90 90 90 90 90"
SNAPDIR = "G:/VibeRE/GiantsRE/RuntimeLab/logs"
LL_APIS = ["LoadLibraryA", "LoadLibraryW", "LoadLibraryExA", "LoadLibraryExW"]
BUDGET_S = 420


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
             "Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class R { [StructLayout(LayoutKind.Sequential)] public struct RECT { public int L,T,Rt,B; } [DllImport(\"user32.dll\")] public static extern bool GetWindowRect(IntPtr h, out RECT r); }';"
             "$r=New-Object R+RECT; [R]::GetWindowRect($p.MainWindowHandle,[ref]$r)|Out-Null; \"$($r.L),$($r.T),$($r.Rt),$($r.B)\"")
    try:
        L, T, R, B = [int(x) for x in out.split(",")]
        return L, T, R, B
    except Exception:
        return None


def click(x, y):
    ps(f"Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class W {{ [DllImport(\"user32.dll\")] public static extern bool SetCursorPos(int x,int y); [DllImport(\"user32.dll\")] public static extern void mouse_event(int f,int dx,int dy,int d,int i); }}';"
       f"[W]::SetCursorPos({x},{y})|Out-Null; Start-Sleep -Milliseconds 220;"
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
        time.sleep(0.3)
        img = ImageGrab.grab(bbox=rect)
        path = os.path.join(SNAPDIR, name)
        img.save(path)
        return path
    except Exception as e:
        print(f"  snap err {e}")
        return None


def read_arg_string(addr, wide=False):
    raw = call("ReadMemory", {"address": hex(addr), "length": 128}, timeout=15)
    chars = []
    hexpart = ""
    for ln in raw.splitlines():
        import re
        m = re.match(r"^\s*[0-9A-Fa-f]+:((?:\s+[0-9A-Fa-f]{2})+)", ln)
        if m:
            hexpart += m.group(1).replace(" ", "")
    b = bytes.fromhex(hexpart[:512])
    if wide:
        s = b.decode("utf-16-le", errors="replace")
    else:
        s = b.decode("cp1252", errors="replace")
    return s.split("\x00")[0]


def gg_base():
    out = call("ListModules", {}, timeout=25)
    for ln in out.splitlines():
        parts = [p for p in ln.split("|")]
        if len(parts) >= 3 and "gg_dx7r" in parts[-1].lower():
            try:
                return int(parts[0].strip(), 16)
            except Exception:
                pass
    # fallback parse: '0x10000000 | 0x2C000 | gg_dx7r.dll'
    for ln in out.splitlines():
        if "gg_dx7r" in ln.lower():
            tok = ln.split("|")[0].strip()
            try:
                return int(tok, 16)
            except Exception:
                pass
    return None


def patch_filter(tag):
    base = gg_base()
    if not base:
        print(f"[{tag}] gg_dx7r not in module list yet!")
        return False
    addr = base + PATCH_RVA
    raw = call("ReadMemory", {"address": hex(addr), "length": 6}, timeout=20)
    cur = ""
    for ln in raw.splitlines():
        if ":" in ln and "  " in ln:
            cur = ln.split(":", 1)[1].split("  ")[0].strip().replace(" ", "").lower()
            break
    if cur.startswith("909090"):
        print(f"[{tag}] already patched @gg+{hex(PATCH_RVA)} (base {hex(base)})")
        return True
    call("WriteMemToAddress", {"address": hex(addr), "byteString": NOP6}, timeout=20)
    chk_raw = call("ReadMemory", {"address": hex(addr), "length": 6}, timeout=20)
    ok = "909090" in chk_raw.replace(" ", "").lower()
    print(f"[{tag}] PATCH base={hex(base)} +0x{PATCH_RVA:x}: {'VERIFIED' if ok else 'FAILED'} ({cur[:12]} -> nops)")
    return ok


def main():
    subprocess.run(["taskkill", "/IM", "Giants.exe", "/F"], capture_output=True)
    time.sleep(1)
    pid = None
    call("LoadBinary", {"filePath": EXE}, timeout=60)
    call("DeleteAllBreakpoints", {}, timeout=20)
    call("WriteMemToAddress", {"address": hex(CD_CHECK), "byteString": "B8 01 00 00 00 C3"}, timeout=20)
    call("WriteMemToAddress", {"address": "0x631890", "byteString": "01 00 00 00"}, timeout=20)

    # persistent watchpoints on every loader API
    ll_addr = {}
    for api in LL_APIS:
        call("SetBreakpoint", {"target": api}, timeout=15)
        a = evalx(api)
        if a:
            ll_addr[a] = api

    state = call("GetDebugState", {}, timeout=15)
    for ln in state.splitlines():
        if ln.startswith("pid:"):
            pid = int(ln.split()[1])
    print(f"[boot] pid={pid} watching {list(ll_addr.values())}")

    call("run", {}, timeout=30)

    patches_done = 0
    armed_ret = None            # dynamic return-address bp while waiting a lib load return
    armed_target_is_gg = False
    last_click = 0
    t0 = time.time()
    last_snap = 0
    last_click = 0
    snaps = []
    while time.time() - t0 < BUDGET_S:
        eip = None
        try:
            r = call("WaitForPause", {}, timeout=6)
            if "TIMEOUT" not in str(r):
                eip = evalx("eip")
        except Exception:
            pass
        st = call("GetDebugState", {}, timeout=10)
        if "NO_TARGET" in st:
            print("[end] target gone")
            break

        if eip is not None and eip in ll_addr:
            argp = evalx("[esp+4]" if "Ex" not in ll_addr[eip] or ll_addr[eip].endswith("A") else "[esp+4]")
            if argp:
                wide = ll_addr[eip].endswith("W")
                nm = read_arg_string(argp, wide=wide)
                if "gg_dx7r" in nm.lower():
                    ret = evalx("[esp]")
                    if ret:
                        call("SetBreakpoint", {"target": hex(ret)}, timeout=15)
                        armed_ret = ret
                        armed_target_is_gg = True
                        print(f"[ll] {ll_addr[eip]}(\"{nm}\") ret={hex(ret)} — armed return bp")
                        # disable all LL bps while stepping over this load
                        for a2 in ll_addr:
                            call("DisableBreakpoint", {"target": hex(a2)}, timeout=10)
                        call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
                        continue
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        if eip is not None and armed_target_is_gg and eip == armed_ret:
            call("DeleteBreakpoint", {"target": hex(armed_ret)}, timeout=10)
            patches_done += 1
            patch_filter(f"load#{patches_done}")
            armed_ret = None
            armed_target_is_gg = False
            for a2 in ll_addr:
                call("EnableBreakpoint", {"target": hex(a2)}, timeout=10)
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        if eip is not None:
            # startup pauses / exceptions -> deliver them
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            # housekeeping while passing through
            continue

        # running phase
        now = time.time()
        if now - last_snap > 14 and pid:
            p = snapshot(pid, f"v3_t{int(now-t0):03d}.png")
            if p:
                snaps.append(os.path.basename(p))
                print(f"[snap] {os.path.basename(p)}")
            last_snap = now
        if now - last_click > 15 and pid:
            rect = win_rect(pid)
            if rect:
                L, T, R, B = rect
                if R - L > 50:
                    click(L + int((R - L) * 0.26), T + int((B - T) * 0.74))
                    print("[click] OK-spot")
                    last_click = now

    if pid:
        for i in range(2):
            snapshot(pid, f"v3_final{i}.png")
            time.sleep(3)
    print(f"[done] patch rounds={patches_done} snaps={snaps[-4:]}")


def api_dummy():
    return None


if __name__ == "__main__":
    main()
