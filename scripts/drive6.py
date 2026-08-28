#!/usr/bin/env python3
"""drive6.py — vision-classified dialog driver.

Rules (derived from previous native reads):
  title contains 'Giants Error'  -> native box; OK at (0.32, 0.88)  [continue]
  title == 'GFX_DX7' (custom)    -> OK at (0.26, 0.74)              [Continue?]
Every dialog is snapshotted (audit PNG) BEFORE clicking; clicks are confined
to the dialog rect. Main-window shots every 4th poll. Leaves game running.
"""
import os
import re
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
SNAP = "G:/VibeRE/GiantsRE/RuntimeLab/logs"
BUILD = "G:/VibeRE/GiantsRE/RuntimeLab/menu_build"


def ps(cmd):
    return subprocess.run(["powershell", "-NoProfile", "-Command", cmd],
                          capture_output=True, timeout=30).stdout.decode("cp1252", errors="replace").strip()


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
                res.append((parts[0].strip(), parts[1].strip(), *[int(x) for x in m.groups()]))
    return res


def click(x, y):
    ps(f"Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class W {{ [DllImport(\"user32.dll\")] public static extern bool SetCursorPos(int x,int y); [DllImport(\"user32.dll\")] public static extern void mouse_event(int f,int dx,int dy,int d,int i); }}';"
       f"[W]::SetCursorPos({x},{y})|Out-Null; Start-Sleep -Milliseconds 180;"
       "[W]::mouse_event(2,0,0,0,0); Start-Sleep -Milliseconds 70; [W]::mouse_event(4,0,0,0,0)")


def foreground(h):
    ps(f"Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class F {{ [DllImport(\"user32.dll\")] public static extern bool SetForegroundWindow(IntPtr h); }}';"
       f"[F]::SetForegroundWindow([IntPtr]{h})|Out-Null")


def snap(L, T, R, B, name):
    try:
        from PIL import ImageGrab as IG
        im = IG.grab(bbox=(L, T, R, B))
        p = os.path.join(SNAP, name)
        im.save(p)
        return p
    except Exception as e:
        print(f"  snap err {e}")
        return None


def main():
    subprocess.run(["taskkill", "/IM", "Giants.exe", "/F"], capture_output=True)
    time.sleep(1)
    subprocess.run(["cmd", "/c", "start", '', '/D', BUILD, "Giants.exe"], capture_output=True)
    print("[launched]", flush=True)

    t0 = time.time()
    handled = set()
    polls = 0
    menu_stable = 0
    empty_polls = 0
    while time.time() - t0 < 600:
        time.sleep(5)
        wins = windows_list()
        mains = [w for w in wins if w[1].lower() == "giants"]
        dialogs = [w for w in wins if w not in mains and 100 < (w[4] - w[2]) < 500 and (w[5] - w[3]) > 60]
        polls += 1

        for d in dialogs:
            hwnd, title, L, T, R, B = d
            if hwnd in handled:
                continue
            handled.add(hwnd)
            p = snap(L, T, R, B, f"d6_dlg_{hwnd}.png")
            print(f"[dialog] '{title}' {R-L}x{B-T} snap={os.path.basename(p or '')}", flush=True)
            tl = title.lower()
            if "error" in tl:
                fx, fy = 0.32, 0.88
            else:
                fx, fy = 0.26, 0.74
            foreground(hwnd)
            time.sleep(0.25)
            click(L + int((R - L) * fx), T + int((B - T) * fy))
            print(f"[click] {fx}/{fy} in dialog", flush=True)

        if mains and not dialogs:
            hwnd, title, L, T, R, B = mains[0]
            if polls % 4 == 0:
                p = snap(L, T, R, B, f"d6_main_{int(time.time()-t0):03d}.png")
                if p:
                    print(f"[main] {os.path.basename(p)}", flush=True)
                # non-black check
                try:
                    from PIL import Image
                    im = Image.open(p).convert("L")
                    px = list(im.getdata())[::997]
                    bright = sum(1 for v in px if v > 24) / max(1, len(px))
                    if bright > 0.10:
                        menu_stable += 1
                        print(f"[menu?] bright={bright:.2f} stable={menu_stable}", flush=True)
                        if menu_stable >= 3:
                            print("[SUCCESS] menu content visible — leaving running", flush=True)
                            return
                    else:
                        menu_stable = 0
                except Exception:
                    pass
        if not wins:
            empty_polls += 1
            if empty_polls > 6:
                print("[end] no windows — process exited", flush=True)
                return
        else:
            empty_polls = 0


if __name__ == "__main__":
    main()
