#!/usr/bin/env python3
"""probe_bank25c0.py — catch the vertex-bank grow-needed calls that precede
the NULL return wedging video init.

Boot (CD stub + IgnoreRange + format-NOP via LL watcher simplified), then a
CONDITIONAL bp on gg+0x25C0:
    condition: [[esp+4]+0x60] < [[esp+4]+0x68] + [esp+8]
   (cap < used + count  ->  this call will flush; if flush can't satisfy, NULL)
On hit: dump p1, p2, cap, used, cursor, elemsize, base(+0x6c), ptr(+0x74),
lockfail(+0x6c after flush not visible here) + caller ret, then erun.
Collect up to 12 hits, leave running afterwards (clicks in RUNNING windows).
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
LL_APIS = ["LoadLibraryA", "LoadLibraryW"]
M25C0 = 0x100025C0
BUDGET_S = 420


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


def read_str(addr, wide=False):
    raw = call("ReadMemory", {"address": hex(addr), "length": 64}, timeout=12)
    hexpart = ""
    for ln in raw.splitlines():
        m = re.match(r"^\s*[0-9A-Fa-f]+:((?:\s+[0-9A-Fa-f]{2})+)", ln)
        if m:
            hexpart += m.group(1).replace(" ", "")
    b = bytes.fromhex(hexpart[:256])
    return b.decode("utf-16-le" if wide else "cp1252", errors="replace").split("\x00")[0]


def click_ok(pid):
    ps(f"Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class W {{ [DllImport(\"user32.dll\")] public static extern bool SetCursorPos(int x,int y); [DllImport(\"user32.dll\")] public static extern void mouse_event(int f,int dx,int dy,int d,int i); }}';"
       "$p=Get-Process -Id " + str(pid) + ";"
       "Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class R { [StructLayout(LayoutKind.Sequential)] public struct RECT { public int L,T,Rt,B; } [DllImport(\"user32.dll\")] public static extern bool GetWindowRect(IntPtr h, out RECT r); }';"
       "$r=New-Object R+RECT; [R]::GetWindowRect($p.MainWindowHandle,[ref]$r)|Out-Null;"
       f"[W]::SetCursorPos($r.L+[int](($r.Rt-$r.L)*0.5),$r.T+[int](($r.B-$r.T)*0.5))|Out-Null; Start-Sleep -Milliseconds 150;"
       "[W]::mouse_event(2,0,0,0,0); Start-Sleep -Milliseconds 70; [W]::mouse_event(4,0,0,0,0)")


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
    cond_hits = 0
    last_click = 0
    t0 = time.time()
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
            nm = read_str(argp) if argp else ""
            if "gg_dx7r" in nm.lower():
                ret = evalx("[esp]")
                if ret:
                    call("SetBreakpoint", {"target": hex(ret)}, timeout=15)
                    armed_ret = ret
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        if armed_ret and eip == armed_ret:
            call("DeleteBreakpoint", {"address": hex(armed_ret)}, timeout=10)
            armed_ret = None
            base = 0x10000000
            call("WriteMemToAddress", {"address": hex(base + PATCH_RVA), "byteString": NOP6}, timeout=15)
            print("[patch] format-NOP applied")
            patched = True
            for a2 in ll_addr:
                call("DisableBreakpoint", {"address": hex(a2)}, timeout=10)
            # conditional grow-needed bp
            cond = "[[esp+4]+0x60] < [[esp+4]+0x68] + [esp+8]"
            rr = call("SetConditionalBreakpoint",
                      {"address": hex(M25C0), "condition": cond}, timeout=20)
            print(f"[bp] grow-needed conditional: {rr.strip().splitlines()[0] if rr else '?'}")
            call("run", {}, timeout=30)
            continue

        if patched and eip == M25C0:
            cond_hits += 1
            p1 = evalx("[esp+4]")
            p2 = evalx("[esp+8]")
            ret = evalx("[esp]")
            cap = evalx(f"[{hex(p1)}+0x60]") if p1 else None
            used = evalx(f"[{hex(p1)}+0x68]") if p1 else None
            cur = evalx(f"[{hex(p1)}+0x74]") if p1 else None
            base_p = evalx(f"[{hex(p1)}+0x6c]") if p1 else None
            elsz = evalx(f"[{hex(p1)}+0x84]") if p1 else None
            fmtag = ""
            if ret:
                rr = evalx(hex(ret))
                if rr and 0x400000 <= rr < 0x660000:
                    fmtag = f"caller=giants+0x{rr-0x400000:x}"
                elif rr and 0x10000000 <= rr < 0x10050000:
                    fmtag = f"caller=gg+0x{rr-0x10000000:x}"
            print(f"[grow#{cond_hits}] p1={hex(p1 or 0)} count={p2} cap={cap} used={used} "
                  f"cursor={hex(cur or 0)} base={hex(base_p or 0)} elemsz={elsz} {fmtag}")
            if cond_hits >= 12:
                print("[hold] 12 hits collected, leaving paused")
                break
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        if eip is not None:
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        now = time.time()
        if pid and now - last_click > 20:
            click_ok(pid)
            last_click = now

    print(f"[done] grow-hits={cond_hits}")


if __name__ == "__main__":
    main()
