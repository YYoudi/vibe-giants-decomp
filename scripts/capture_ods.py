#!/usr/bin/env python3
"""Capture the game's own OutputDebugString narration via breakpoint.

Boots the canonical session (CD stub), sets bp on OutputDebugStringA/W,
logs each message (up to N), resumes past other pauses. Writes to
RuntimeLab/logs/ods_capture.txt as well.
"""
import os
import re
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xdbg_call import call  # noqa: E402

EXE = "G:/VibeRE/GiantsRE/RuntimeLab/GiantsWork/Giants.exe"
OUT = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                   "RuntimeLab", "logs", "ods_capture.txt")


def evalx(expr):
    try:
        out = call("EvalExpression", {"expression": expr}, timeout=20)
    except Exception:
        return None
    first = out.strip().splitlines()[0] if out.strip() else ""
    return int(first.split()[0], 16) if first.startswith("0x") else None


def read_str(addr, maxlen=400):
    try:
        raw = call("ReadMemory", {"address": hex(addr), "length": maxlen}, timeout=15)
    except Exception:
        return ""
    s = ""
    for line in raw.splitlines():
        m = re.match(r"^\s*[0-9A-Fa-f]+:((?:\s+[0-9A-Fa-f]{2})+)", line)
        if not m:
            continue
        for pair in m.group(1).split():
            b = int(pair, 16)
            if b == 0:
                return s
            if 32 <= b < 127:
                s += chr(b)
            elif b == 0x0A:
                s += "\\n"
            else:
                s += f"\\x{b:02x}"
    return s


def main():
    call("LoadBinary", {"filePath": EXE}, timeout=60)
    call("DeleteAllBreakpoints", {}, timeout=20)
    call("WriteMemToAddress", {"address": "0x53AE80", "byteString": "B8 01 00 00 00 C3"}, timeout=20)
    call("WriteMemToAddress", {"address": "0x631890", "byteString": "01 00 00 00"}, timeout=20)
    call("SetBreakpoint", {"target": "OutputDebugStringA"}, timeout=20)
    call("SetBreakpoint", {"target": "OutputDebugStringW"}, timeout=20)
    a_addr = evalx("OutputDebugStringA")
    w_addr = evalx("OutputDebugStringW")
    call("run", {}, timeout=30)

    msgs = []
    resumes = 0
    t0 = time.time()
    with open(OUT, "w", encoding="utf-8") as f:
        while time.time() - t0 < 420 and len(msgs) < 40:
            try:
                r = call("WaitForPause", {}, timeout=35)
            except Exception:
                r = "TIMEOUT"
            if "TIMEOUT" in str(r):
                continue
            state = call("GetDebugState", {}, timeout=15)
            if "NO_TARGET" in state:
                print("[end] target gone")
                break
            eip = evalx("eip")
            if eip in (a_addr, w_addr):
                arg = evalx("[esp+4]")
                wide = eip == w_addr
                txt = read_str(arg, 400 if not wide else 800)
                if wide and txt.startswith("\\x"):
                    # try utf-16 decode
                    try:
                        raw = call("ReadMemory", {"address": hex(arg), "length": 400}, timeout=15)
                        hexpart = ""
                        for line in raw.splitlines():
                            m = re.match(r"^\s*[0-9A-Fa-f]+:((?:\s+[0-9A-Fa-f]{2})+)", line)
                            if m:
                                hexpart += m.group(1).replace(" ", "")
                        b = bytes.fromhex(hexpart)
                        txt = b.decode("utf-16-le", errors="replace").split("\x00")[0]
                    except Exception:
                        pass
                msgs.append(txt)
                f.write(txt + "\n")
                f.flush()
                print(f"[ODS #{len(msgs)}] {txt[:160]}")
                call("run", {}, timeout=30)
                continue
            resumes += 1
            if resumes < 60:
                print(f"[erun] {hex(eip or 0)}")
            call("ExecuteDebuggerCommand", {"command": "erun"}, timeout=30)
    print(f"[done] {len(msgs)} messages -> {OUT}")


if __name__ == "__main__":
    main()
