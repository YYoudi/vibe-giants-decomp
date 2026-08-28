#!/usr/bin/env python3
"""wedge_sample.py — launch the static patched build, auto-dismiss the
'Giants Error' native dialog by exact dialog-rect click, then minidump the
wedged process for thread forensics."""
import os
import re
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
SNAP = "G:/VibeRE/GiantsRE/RuntimeLab/logs"


def ps(cmd):
    return subprocess.run(["powershell", "-NoProfile", "-Command", cmd],
                          capture_output=True, text=True, timeout=30).stdout.strip()


def windows_list():
    out = subprocess.run(["powershell", "-NoProfile", "-ExecutionPolicy", "Bypass",
                          "-File", HERE + "/list_windows_all.ps1"],
                         capture_output=True, timeout=60).stdout.decode("cp1252", errors="replace").strip()
    res = []
    for ln in out.splitlines():
        parts = ln.split("|")
        if len(parts) >= 3:
            m = re.match(r"(-?\d+),(-?\d+),(-?\d+),(-?\d+)", parts[2])
            if m:
                res.append((parts[0].strip(), parts[1].strip(),
                            *[int(x) for x in m.groups()]))
    return res


def click(x, y):
    ps(f"Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class W {{ [DllImport(\"user32.dll\")] public static extern bool SetCursorPos(int x,int y); [DllImport(\"user32.dll\")] public static extern void mouse_event(int f,int dx,int dy,int d,int i); }}';"
       f"[W]::SetCursorPos({x},{y})|Out-Null; Start-Sleep -Milliseconds 200;"
       "[W]::mouse_event(2,0,0,0,0); Start-Sleep -Milliseconds 70; [W]::mouse_event(4,0,0,0,0)")


def main():
    subprocess.run(["taskkill", "/IM", "Giants.exe", "/F"], capture_output=True)
    time.sleep(1)
    subprocess.run(["cmd", "/c", "start", '', '/D', "G:/VibeRE/GiantsRE/RuntimeLab/menu_build",
                    "Giants.exe"], capture_output=True)
    print("[launched]")
    t0 = time.time()
    snd_dismissed = False
    while time.time() - t0 < 300:
        time.sleep(5)
        wins = windows_list()
        main_w = [w for w in wins if w[1].lower() == "giants"]
        dialogs = [w for w in wins if w not in main_w and (w[4] - w[2]) < 500]
        for d in dialogs:
            hwnd, title, L, T, R, B = d
            w_, h_ = R - L, B - T
            print(f"[dlg] '{title}' {w_}x{h_} @({L},{T})")
            if h_ <= 160:
                # small box = ErrFailedSND (OK = continue without sound)
                click(L + int(w_ * 0.32), T + int(h_ * 0.88))
                snd_dismissed = True
                print("[snd] OK clicked")
                time.sleep(3)
            else:
                # large box = fatal (OK exits). Do NOT click. Report + let it sit.
                print("[FATAL-DIALOG] left untouched for inspection")
                time.sleep(5)
        if snd_dismissed and not dialogs:
            # give the wedge a minute to establish
            time.sleep(60)
            break
        if not main_w and not dialogs and time.time() - t0 > 30:
            print("[end] no giants windows (exited early?)")
            return
    # minidump
    r = subprocess.run(["G:/Tools/procdump.exe", "-accepteula", "-mm", "Giants.exe",
                        "G:/VibeRE/GiantsRE/RuntimeLab/logs/wedge3.dmp"],
                       capture_output=True, text=True, timeout=180)
    print("[dump]", "ok" if os.path.exists("G:/VibeRE/GiantsRE/RuntimeLab/logs/wedge3.dmp") else r.stderr[:200])


if __name__ == "__main__":
    main()
