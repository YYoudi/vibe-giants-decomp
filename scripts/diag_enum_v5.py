#!/usr/bin/env python3
"""Diagnostic v5: pinpoint where the gg_dx7r device-callback stops short of
add-dev (+0x1300 never hit in v4).

Instrumented milestones (Mecc renderer layout):
  A 0x100010BF  entering DirectDrawEnumerate (driver loop start)
  B 0x100010D9  a driver SURVIVED the display-format check (our NOP region)
  C 0x100010EE  QI(IID_IDirect3D7) FAILED branch -> EAX holds the HRESULT!
  D 0x10001109  QI succeeded
  E 0x10001212  about to call IDirect3D7::EnumDevices(adddev_cb)
Each milestone prints once until its budget, then auto-disables.
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
LOAD_RET_SITE = 0x51EBEF
PATCH_RVA = 0x10D3
NOP6 = "90 90 90 90 90 90"
MILESTONES = {
    0x100010BF: "A_ddenum_enter",
    0x100010D9: "B_format_ok",
    0x100010EE: "C_qi_FAILED(eax=hr)",
    0x10001109: "D_qi_ok",
    0x10001212: "E_call_enumdevices",
    0x10001300: "F_adddev",
}


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
    st = call("GetDebugState", {}, timeout=15)
    for ln in st.splitlines():
        if ln.startswith("pid:"):
            pid = int(ln.split()[1])
    print(f"[boot] pid={pid}")

    call("SetBreakpoint", {"target": hex(LOAD_RET_SITE)}, timeout=15)
    call("run", {}, timeout=30)

    armed = False
    counts = {}
    t0 = time.time()
    last_click = 0
    while time.time() - t0 < 380:
        try:
            r = call("WaitForPause", {}, timeout=10)
            eip = evalx("eip") if ("TIMEOUT" not in str(r)) else None
        except Exception:
            eip = None
        stt = call("GetDebugState", {}, timeout=10)
        if "NO_TARGET" in stt:
            print("[end] target gone")
            break

        if not armed and eip == LOAD_RET_SITE:
            call("DeleteBreakpoint", {"target": hex(LOAD_RET_SITE)}, timeout=10)
            addr = 0x10000000 + PATCH_RVA
            call("ReadMemory", {"address": hex(addr), "length": 6}, timeout=15)
            call("WriteMemToAddress", {"address": hex(addr), "byteString": NOP6}, timeout=15)
            chk = call("ReadMemory", {"address": hex(addr), "length": 6}, timeout=15)
            okv = "909090" in chk.replace(" ", "").replace("\n", "").lower()
            print(f"[patch] verified={okv}")
            armed = True
            for a in MILESTONES:
                call("SetBreakpoint", {"target": hex(a)}, timeout=15)
            alloc = call("AllocateMemory", {"size": 64, "protection": "rw"}, timeout=20)
            m_ = re.search(r"0x[0-9A-Fa-f]+", alloc)
            globals()['SCRATCH'] = int(m_.group(0), 16) if m_ else None
            print(f"[scratch] {hex(globals()['SCRATCH']) if globals()['SCRATCH'] else 'FAIL'}")
            call("run", {}, timeout=30)
            continue

        if armed and eip in MILESTONES:
            name = MILESTONES[eip]
            counts[eip] = counts.get(eip, 0) + 1
            extra = ""
            if eip == 0x100010EE:
                hr = evalx("eax")
                extra = f" eax(hr)={hex(hr) if hr is not None else '?'}"
            if counts[eip] <= 4:
                print(f"[{name}] #{counts[eip]}{extra}")
            if eip == 0x10001300:
                # full accept path live — let it cook a bit more
                pass
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            # housekeeping clicks while paused-busy?
            now = time.time()
            if now - last_click > 18:
                click_ok(pid)
                last_click = now
            continue

        if eip is not None:
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            sc_ = globals().get('SCRATCH')
            if sc_ and time.time() - globals().get('last_red', 0) > 2.0:
                globals()['last_red'] = time.time()
                obj = evalx("[0x654958]")
                if obj and obj > 0x10000:
                    vt = evalx(hex(obj))
                    if vt and 0x10000000 <= vt < 0x10050000:
                        slot = vt + 0x10
                        cur = evalx(hex(slot))
                        if cur and 0x10000000 <= cur < 0x10050000 and cur != sc_:
                            stub = "B8 " + " ".join(f"{(sc_ >> (8*i)) & 0xFF:02X}" for i in range(4)) + " C3"
                            call("WriteMemToAddress", {"address": hex(sc_), "byteString": stub}, timeout=12)
                            call("WriteMemToAddress", {"address": hex(slot), "byteString": " ".join(f"{(sc_ >> (8*i)) & 0xFF:02X}" for i in range(4))}, timeout=12)
                            new = evalx(hex(slot))
                            print(f"[vtable] redirect slot={hex(slot)} {hex(cur)}->{hex(new)} ok={new == sc_}")
            continue

        now = time.time()
        if now - last_click > 18:
            click_ok(pid)
            last_click = now

    print("[summary]", {MILESTONES[k]: v for k, v in sorted(counts.items())})


if __name__ == "__main__":
    main()
