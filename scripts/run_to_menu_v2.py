#!/usr/bin/env python3
"""run_to_menu_v2.py — lean LL-watcher + vtable redirect + auto-clicks.

Sequence per gg_dx7r load (any call site):
  patch format-NOP at gg+0x10D3
When video-init objects appear ([[0x654958]] non-null):
  allocate scratch in target, write stub `mov eax,scratch; ret`,
  redirect vtable slot [[0x654958]vt+0x10] -> stub (bypasses NULL return of
  the grow-alloc upcall that AVs at Giants+0x432FDE and wedges init).
Clicks handle « Continue? » dialogs; snapshots for native-vision review.
"""
import os
import re
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
BUDGET_S = 540


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
        if R - L <= 0:
            return None
        from PIL import ImageGrab as IG
        im = IG.grab(bbox=(L, T, R, B))
        path = os.path.join(SNAPDIR, name)
        im.save(path)
        return path
    except Exception as e:
        print(f"  snap err {e}")
        return None


def read_str(addr, wide=False):
    raw = call("ReadMemory", {"address": hex(addr), "length": 96}, timeout=15)
    hexpart = ""
    for ln in raw.splitlines():
        m = re.match(r"^\s*[0-9A-Fa-f]+:((?:\s+[0-9A-Fa-f]{2})+)", ln)
        if m:
            hexpart += m.group(1).replace(" ", "")
    b = bytes.fromhex(hexpart[:384])
    return b.decode("utf-16-le" if wide else "cp1252", errors="replace").split("\x00")[0]


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


def apply_patches(tag, scratch):
    base = gg_base()
    if not base:
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
    print(f"[{tag}] format-NOP @gg+0x{PATCH_RVA:x} (base {hex(base)})")
    return True


def try_vtable_redirect(scratch):
    obj = evalx("[0x654958]")
    if not obj or obj < 0x10000:
        return False
    vt = evalx(hex(obj))
    if not vt:
        return False
    slot = vt + 0x10
    cur = evalx(hex(slot))
    if cur is None:
        return False
    if 0x10000000 <= cur < 0x10050000 and cur != scratch:
        # write stub into scratch: mov eax, scratch ; ret
        stub = "B8 " + " ".join(f"{(scratch >> (8 * i)) & 0xFF:02X}" for i in range(4)) + " C3"
        call("WriteMemToAddress", {"address": hex(scratch), "byteString": stub}, timeout=15)
        call("WriteMemToAddress", {"address": hex(slot), "byteString":
             " ".join(f"{(scratch >> (8 * i)) & 0xFF:02X}" for i in range(4))}, timeout=15)
        new = evalx(hex(slot))
        print(f"[vtable] slot {hex(slot)}: {hex(cur)} -> {hex(new)} (stub@{hex(scratch)})")
        return new == scratch
    return cur == scratch


def main():
    subprocess.run(["taskkill", "/IM", "Giants.exe", "/F"], capture_output=True)
    time.sleep(1)
    pid = None
    call("LoadBinary", {"filePath": EXE}, timeout=60)
    call("DeleteAllBreakpoints", {}, timeout=20)
    call("WriteMemToAddress", {"address": hex(CD_CHECK), "byteString": "B8 01 00 00 00 C3"}, timeout=20)
    call("WriteMemToAddress", {"address": "0x631890", "byteString": "01 00 00 00"}, timeout=20)
    # never pause on exceptions (DDraw/D3D legal first-chance storms)
    call("ExecuteDebuggerCommand", {"command": "IgnoreRange 00000000-FFFFFFFF"}, timeout=20)

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
    print(f"[boot] pid={pid}")

    scratch = None
    alloc = call("AllocateMemory", {"size": 64, "protection": "rw"}, timeout=20)
    for ln in alloc.splitlines():
        m = re.search(r"0x[0-9A-Fa-f]+", ln)
        if m:
            scratch = int(m.group(0), 16)
            break
    print(f"[scratch] {hex(scratch) if scratch else 'ALLOC FAILED'}")

    call("run", {}, timeout=30)

    armed_ret = None
    redirect_done = False
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

        if armed_ret and eip == armed_ret:
            call("DeleteBreakpoint", {"target": hex(armed_ret)}, timeout=10)
            armed_ret = None
            apply_patches("first-load", scratch)
            # empirically gg_dx7r is NEVER reloaded: free the loop from LL churn
            for a2 in ll_addr:
                call("DisableBreakpoint", {"target": hex(a2)}, timeout=8)
            print("[ll] watchers disabled for the rest of the run")
            redirect_done = False
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        if eip is not None:
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        now = time.time()
        if not redirect_done and scratch:
            if try_vtable_redirect(scratch):
                redirect_done = True
        if pid and now - last_snap > 15:
            p = snapshot(pid, f"v9_t{int(now-t0):03d}.png")
            if p:
                snaps.append(os.path.basename(p))
            last_snap = now
        if pid and now - last_click > 17:
            click_ok(pid)
            last_click = now

    if pid:
        snapshot(pid, "v9_final.png")
    print(f"[done] snaps={snaps[-4:]}")


if __name__ == "__main__":
    main()
