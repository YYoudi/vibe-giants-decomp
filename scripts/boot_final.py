#!/usr/bin/env python3
"""boot_final.py — race-winning boot toward the menu.

Every fix consolidated:
  CD stub + IgnoreRange + format-NOP on gg load (LL watcher, then DISABLED via
  correct 'address' param) + auto-clicks + snapshots + staged vtable redirect:
  as soon as [[0x654958]] yields a sane vtable, redirect its +0x10 slot to a
  scratch stub BEFORE the upcall AV storm can wedge init.
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
        out = call("EvalExpression", {"expression": expr}, timeout=12)
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
        print(f"  snap err {e}")
        return None


def read_str(addr, wide=False):
    raw = call("ReadMemory", {"address": hex(addr), "length": 96}, timeout=12)
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


def main():
    subprocess.run(["taskkill", "/IM", "Giants.exe", "/F"], capture_output=True)
    time.sleep(1)
    pid = None
    call("LoadBinary", {"filePath": EXE}, timeout=60)
    call("DeleteAllBreakpoints", {}, timeout=20)
    call("WriteMemToAddress", {"address": hex(CD_CHECK), "byteString": "B8 01 00 00 00 C3"}, timeout=20)
    call("WriteMemToAddress", {"address": "0x631890", "byteString": "01 00 00 00"}, timeout=20)
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
    call("run", {}, timeout=30)

    armed_ret = None
    patched = False
    redirected = False
    scratch = None
    t0 = time.time()
    last_click = 0
    last_snap = 0
    snaps = []
    storm = 0
    while time.time() - t0 < BUDGET_S:
        eip = None
        try:
            r = call("WaitForPause", {}, timeout=7)
            if "TIMEOUT" not in str(r):
                eip = evalx("eip")
        except Exception:
            pass
        stt = call("GetDebugState", {}, timeout=10)
        if "NO_TARGET" in stt:
            print("[end] target gone")
            break

        if eip is not None and not patched and eip in ll_addr:
            argp = evalx("[esp+4]")
            wide = ll_addr[eip].endswith("W")
            nm = read_str(argp, wide) if argp else ""
            if "gg_dx7r" in nm.lower():
                ret = evalx("[esp]")
                if ret:
                    call("SetBreakpoint", {"target": hex(ret)}, timeout=15)
                    armed_ret = ret
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        if armed_ret and eip == armed_ret:
            call("DeleteBreakpoint", {"address": hex(armed_ret), "type": "software"}, timeout=10)
            armed_ret = None
            base = gg_base()
            if base:
                call("WriteMemToAddress", {"address": hex(base + PATCH_RVA), "byteString": NOP6}, timeout=15)
                chk = call("ReadMemory", {"address": hex(base + PATCH_RVA), "length": 6}, timeout=15)
                okv = "909090" in chk.replace(" ", "").replace("\n", "").lower()
                print(f"[patch] format-NOP verified={okv}")
            patched = True
            for a2 in ll_addr:
                rr = call("DisableBreakpoint", {"address": hex(a2)}, timeout=10)
            print("[ll] disabled (address-param)")
            alloc = call("AllocateMemory", {"size": 64, "protection": "rw"}, timeout=20)
            m = re.search(r"0x[0-9A-Fa-f]+", alloc)
            scratch = int(m.group(0), 16) if m else None
            print(f"[scratch] {hex(scratch) if scratch else 'FAIL'}")
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        if eip is not None:
            if eip == 0x432FDE:
                storm += 1
                if storm % 5 == 1:
                    print(f"[storm] upcall AV #{storm} — redirect active? {redirected}")
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            # even inside storm windows, try landing the redirect
            if not redirected and scratch:
                obj = evalx("[0x654958]")
                if obj and obj > 0x10000:
                    vt = evalx(hex(obj))
                    if vt and 0x10000000 <= vt < 0x10050000:
                        slot = vt + 0x10
                        cur = evalx(hex(slot))
                        if cur and 0x10000000 <= cur < 0x10050000:
                            stub = "B8 " + " ".join(f"{(scratch >> (8 * i)) & 0xFF:02X}" for i in range(4)) + " C3"
                            call("WriteMemToAddress", {"address": hex(scratch), "byteString": stub}, timeout=12)
                            call("WriteMemToAddress", {"address": hex(slot), "byteString":
                                 " ".join(f"{(scratch >> (8 * i)) & 0xFF:02X}" for i in range(4))}, timeout=12)
                            new = evalx(hex(slot))
                            redirected = (new == scratch)
                            print(f"[vtable] redirect slot={hex(slot)} {hex(cur)}->{hex(new)} ok={redirected}")
            continue

        # RUNNING window
        now = time.time()
        if not redirected and scratch:
            obj = evalx("[0x654958]")
            if obj and obj > 0x10000:
                vt = evalx(hex(obj))
                if vt and 0x10000000 <= vt < 0x10050000:
                    slot = vt + 0x10
                    cur = evalx(hex(slot))
                    if cur and 0x10000000 <= cur < 0x10050000:
                        stub = "B8 " + " ".join(f"{(scratch >> (8 * i)) & 0xFF:02X}" for i in range(4)) + " C3"
                        call("WriteMemToAddress", {"address": hex(scratch), "byteString": stub}, timeout=12)
                        call("WriteMemToAddress", {"address": hex(slot), "byteString":
                             " ".join(f"{(scratch >> (8 * i)) & 0xFF:02X}" for i in range(4))}, timeout=12)
                        new = evalx(hex(slot))
                        redirected = (new == scratch)
                        print(f"[vtable] redirect slot={hex(slot)} {hex(cur)}->{hex(new)} ok={redirected}")
        if pid and now - last_snap > 15:
            p = snapshot(pid, f"fin_t{int(now-t0):03d}.png")
            if p:
                snaps.append(os.path.basename(p))
            last_snap = now
        if pid and now - last_click > 16:
            click_ok(pid)
            last_click = now

    if pid:
        snapshot(pid, "fin_final.png")
    print(f"[done] redirected={redirected} storm={storm} snaps={snaps[-4:]}")


if __name__ == "__main__":
    main()
