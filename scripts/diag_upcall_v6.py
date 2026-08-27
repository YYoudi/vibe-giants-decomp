#!/usr/bin/env python3
"""Upcall micro-trace: why does Giants.exe+0x432FC2's renderer call return NULL?

Arms everything BEFORE the game gets far:
  1. at LoadLibraryA-ret: apply gg_dx7r format-NOP patch
  2. bp 0x432FC2  -> log pushed args: [esp]=obj(this), [esp+4]=arg
     resolve method=[[obj_vtable]+0x10], report live instance fields
  3. bp on that method's two exits:
       0x100025E9 = returns NULL (grow failed)
       0x100025EE = proceeds normally
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
CALLSITE = 0x432FC2
M_NULL = 0x100025E9
M_OK = 0x100025EE


def evalx(expr):
    try:
        out = call("EvalExpression", {"expression": expr}, timeout=15)
    except Exception:
        return None
    first = out.strip().splitlines()[0] if out.strip() else ""
    return int(first.split()[0], 16) if first.startswith("0x") else None


def main():
    subprocess.run(["taskkill", "/IM", "Giants.exe", "/F"], capture_output=True)
    time.sleep(1)
    call("LoadBinary", {"filePath": EXE}, timeout=60)
    call("DeleteAllBreakpoints", {}, timeout=20)
    call("WriteMemToAddress", {"address": hex(CD_CHECK), "byteString": "B8 01 00 00 00 C3"}, timeout=20)
    call("WriteMemToAddress", {"address": "0x631890", "byteString": "01 00 00 00"}, timeout=20)
    call("SetBreakpoint", {"target": hex(LOAD_RET_SITE)}, timeout=15)
    call("run", {}, timeout=30)

    armed = False
    cs_hits = 0
    null_hits = 0
    ok_hits = 0
    t0 = time.time()
    while time.time() - t0 < 300:
        try:
            r = call("WaitForPause", {}, timeout=12)
            eip = evalx("eip") if "TIMEOUT" not in str(r) else None
        except Exception:
            eip = None
        st = call("GetDebugState", {}, timeout=10)
        if "NO_TARGET" in st:
            print("[end] gone")
            break

        if not armed and eip == LOAD_RET_SITE:
            call("DeleteBreakpoint", {"target": hex(LOAD_RET_SITE)}, timeout=10)
            addr = 0x10000000 + PATCH_RVA
            call("WriteMemToAddress", {"address": hex(addr), "byteString": NOP6}, timeout=15)
            chk = call("ReadMemory", {"address": hex(addr), "length": 6}, timeout=15)
            okv = "909090" in chk.replace(" ", "").replace("\n", "").lower()
            print(f"[patch] verified={okv}")
            call("SetBreakpoint", {"target": hex(CALLSITE)}, timeout=15)
            call("SetBreakpoint", {"target": hex(M_NULL)}, timeout=15)
            call("SetBreakpoint", {"target": hex(M_OK)}, timeout=15)
            armed = True
            call("run", {}, timeout=30)
            continue

        if eip == CALLSITE:
            cs_hits += 1
            obj = evalx("[esp]")
            arg = evalx("[esp+4]")
            vt = evalx(f"[{hex(obj)}]") if obj else None
            meth = evalx(f"[{hex(vt)}+0x10]") if vt else None
            print(f"[callsite #{cs_hits}] obj={hex(obj or 0)} arg={arg} vtable={hex(vt or 0)} method={hex(meth or 0)}")
            if meth and meth != M_NULL and meth != M_OK and cs_hits == 1:
                # different target than assumed — show it, keep both known exits
                print("   note: method differs from static guess")
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        if eip == M_NULL:
            null_hits += 1
            esi = evalx("esi")
            edi = evalx("edi")
            f60 = evalx(f"[{hex(esi)}+0x60]")
            f68 = evalx(f"[{hex(esi)}+0x68]")
            f74 = evalx(f"[{hex(esi)}+0x74]")
            f84 = evalx(f"[{hex(esi)}+0x84]")
            print(f"[NULL-RETURN #{null_hits}] esi={hex(esi or 0)} edi(arg)={edi} "
                  f"cap[60]={f60} used[68]={f68} ptr[74]={hex(f74 or 0)} elsz[84]={f84}")
            if null_hits >= 3:
                print("[hold] leaving paused for inspection")
                break
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        if eip == M_OK:
            ok_hits += 1
            if ok_hits <= 4:
                print(f"[ok-path #{ok_hits}]")
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
            continue

        call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)

    print(f"[summary] callsite={cs_hits} null={null_hits} ok={ok_hits}")


if __name__ == "__main__":
    main()
