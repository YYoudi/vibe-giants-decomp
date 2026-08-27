#!/usr/bin/env python3
"""drive3.py — dialog-aware supervised boot.

- Runs v5-style boot externally (expected already attached session)
- Polls the game process window list every few seconds:
    main 'Giants' 640x480  -> normal
    extra small window (~329x182, title GFX_DX7/etc) = RENDERER DIALOG
      -> foreground it, screenshot its rect, print the file for native vision,
         report geometry. Native-vision agent decides the click point;
         as a default action click bottom-left third (OK is consistently there).
- Also snapshots the main window periodically for milestone review.
"""
import os
import re
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
SNAPDIR = "G:/VibeRE/GiantsRE/RuntimeLab/logs"


def ps_file(script):
    return subprocess.run(["powershell", "-NoProfile", "-ExecutionPolicy", "Bypass",
                           "-File", os.path.join(HERE, script)],
                          capture_output=True, text=True, timeout=60).stdout.strip()


def win_rect_of(pid_handle_pair):  # unused placeholder
    return None


def get_pid():
    out = subprocess.run(["tasklist", "/FI", "IMAGENAME eq Giants.exe", "/FO", "CSV", "/NH"],
                         capture_output=True).stdout.decode("cp1252", errors="replace")
    m = re.search(r'"Giants\.exe","(\d+)"', out)
    return int(m.group(1)) if m else None


class WinEnum:
    SCRIPT = os.path.join(HERE, "list_windows_all.ps1")


def ensure_enum_script():
    src = r'''Add-Type -TypeDefinition @'
using System;
using System.Text;
using System.Runtime.InteropServices;
public class E2 {
  public delegate bool CB(IntPtr h, IntPtr l);
  [DllImport("user32.dll")] public static extern bool EnumWindows(CB c, IntPtr l);
  [DllImport("user32.dll")] public static extern uint GetWindowThreadProcessId(IntPtr h, out uint pid);
  [DllImport("user32.dll")] public static extern int GetWindowText(IntPtr h, StringBuilder s, int n);
  [DllImport("user32.dll")] public static extern bool IsWindowVisible(IntPtr h);
  [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RECT r);
  [StructLayout(LayoutKind.Sequential)] public struct RECT { public int L,T,R,B; }
  public static void List(uint target) {
    EnumWindows(delegate(IntPtr h, IntPtr l) {
      uint pid; GetWindowThreadProcessId(h, out pid);
      if (pid == target && IsWindowVisible(h)) {
        StringBuilder sb = new StringBuilder(128); GetWindowText(h, sb, 128);
        RECT r; GetWindowRect(h, out r);
        Console.WriteLine(h.ToInt64() + "|" + sb.ToString() + "|" + r.L + "," + r.T + "," + r.R + "," + r.B);
      }
      return true;
    }, IntPtr.Zero);
  }
}
'@
[E2]::List((Get-Process Giants -ErrorAction Stop).Id)
'''
    path = os.path.join(HERE, "list_windows_all.ps1")
    if not os.path.exists(path):
        open(path, "w", encoding="utf-8").write(src)
    return path


def click(x, y):
    ps = f'''Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class W {{ [DllImport("user32.dll")] public static extern bool SetCursorPos(int x,int y); [DllImport("user32.dll")] public static extern void mouse_event(int f,int dx,int dy,int d,int i); }}'
[W]::SetCursorPos({x},{y}) | Out-Null
Start-Sleep -Milliseconds 250
[W]::mouse_event(2,0,0,0,0); Start-Sleep -Milliseconds 70; [W]::mouse_event(4,0,0,0,0)'''
    subprocess.run(["powershell", "-NoProfile", "-Command",
                    ps.replace('"', '\\"')], capture_output=True, text=True, timeout=30)


def foreground(h):
    subprocess.run(["powershell", "-NoProfile", "-Command",
                    f"Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class F {{ [DllImport(\"user32.dll\")] public static extern bool SetForegroundWindow(IntPtr h); }}';"
                    f"[F]::SetForegroundWindow([IntPtr]{h}) | Out-Null"],
                   capture_output=True, text=True, timeout=30)


def snap_region(L, T, R, B, name):
    try:
        from PIL import ImageGrab as IG
        im = IG.grab(bbox=(L, T, R, B))
        path = os.path.join(SNAPDIR, name)
        im.save(path)
        return path
    except Exception as e:
        print(f"  snap err {e}")
        return None


def main():
    ensure_enum_script()
    t0 = time.time()
    dlg_seen = set()
    snaps = []
    while time.time() - t0 < 600:
        pid = get_pid()
        if not pid:
            print("[end] no giants process")
            break
        out = subprocess.run(["powershell", "-NoProfile", "-ExecutionPolicy", "Bypass",
                              "-File", HERE + "/list_windows_all.ps1"],
                             capture_output=True, text=True, timeout=60).stdout.strip()
        lines = [l for l in out.splitlines() if "|" in l]
        nows = len(lines)
        small = None
        for ln in lines:
            parts = ln.split("|")
            if len(parts) < 3:
                continue
            hwnd, title, rect = parts[0], parts[1], parts[2]
            m = re.match(r"(-?\d+),(-?\d+),(-?\d+),(-?\d+)", rect)
            if not m:
                continue
            L, T, R, B = map(int, m.groups())
            w, h = R - L, B - T
            if (w, h) == (640, 480):
                continue
            if 150 <= w <= 800 and 100 <= h <= 400:
                small = (hwnd.strip(), title.strip(), L, T, R, B)
        if small:
            key = small[0]
            hwnd, title, L, T, R, B = small
            fg = os.path.basename(snap_region(L, T, R, B, f"d3_dlg_{hwnd}_{int(time.time()-t0)}.png"))
            snaps.append(fg)
            print(f"[DIALOG] hwnd={hwnd} title='{title}' rect=({L},{T},{R},{B}) snap={fg}")
            # default action: click lower-left-third button zone of the dialog
            x = L + int((R - L) * 0.30)
            y = T + int((B - T) * 0.78)
            click(x, y)
            print(f"[click] OK-zone ({x},{y})")
            time.sleep(4)
            continue
        # periodic main-window snapshot
        if int(time.time() - t0) % 40 < 5:
            name = f"d3_main_{int(time.time()-t0):03d}.png"
            # find main window rect from the same listing
            for ln in lines:
                parts = ln.split("|")
                if len(parts) >= 3 and parts[1].strip().lower() == "giants":
                    m = re.match(r"(-?\d+),(-?\d+),(-?\d+),(-?\d+)", parts[2])
                    if m:
                        L, T, R, B = map(int, m.groups())
                        p = snap_region(L, T, R, B, name)
                        if p:
                            snaps.append(os.path.basename(p))
                            print(f"[main] {os.path.basename(p)}")
                    break
        time.sleep(4)
    print("[done] recent:", snaps[-6:])


if __name__ == "__main__":
    main()
