#!/usr/bin/env python3
"""capdiff.py — capture-diff harness for the Giants vanilla recomp vs the original.

The auto-verification core (skill giants-advance "auto-verif"). Three pieces:

  recomp <phase>   Capture the RECOMP at a boot phase (uses the C1 phase-jump flags:
                   -skip-intros / -frames N). Fast (no 15s boot replay).
  original <phase> Capture the ORIGINAL at the same phase (SendInput to skip intros,
                   appsnap the window).
  diff <a> <b>     PIL pixel diff -> mean-abs-delta + PASS/FAIL verdict + diff image.
  compare <phase>  capture both + diff (the one-command auto-verif).

Phases: intro1 | intro2 | intro3 | loading | menu.

Usage:
  python tools/capdiff.py recomp menu -o shots/r_menu.png
  python tools/capdiff.py original menu -o shots/o_menu.png
  python tools/capdiff.py diff shots/r_menu.png shots/o_menu.png
  python tools/capdiff.py compare menu

This is objective verification: the agent should never claim "the menu renders
correctly" without a compare that PASSES (or a documented reason it can't).
"""
import argparse, os, sys, subprocess, time, ctypes
from ctypes import wintypes
from PIL import Image, ImageChops
try:
    import frida
    HAVE_FRIDA = True
except Exception:
    HAVE_FRIDA = False
FRIDA_CTRL = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "scripts", "frida_orig_control.js")

ROOT      = r"G:\GiantsRE"
RECOMP    = os.path.join(ROOT, "GameFiles-VanillaV1", "GiantsMain_vanilla.exe")
ORIG      = os.path.join(ROOT, "GameFiles-VanillaV1", "Giants_nocd.exe")   # no-CD patched retail
GAMEDIR   = os.path.join(ROOT, "GameFiles-VanillaV1")
SHOTS     = os.path.join(ROOT, "RESSOURCES_FOR_AI", "temp_screenshots")
APPSNAP   = ["uvx", "appsnap"]
WIN_TITLE = "Giants"
PASS_THRESH = 0.04   # mean-abs-delta below this = PASS (4% per-channel)

# ── Windows SendInput (drive the original's intro-skip via mouse click/key) ──
INPUT_MOUSE, INPUT_KEYBOARD = 0, 1
MOUSEEVENTF_LEFTDOWN, MOUSEEVENTF_LEFTUP = 0x0002, 0x0004
VK_SPACE = 0x20
KEYEVENTF_KEYUP = 0x0002

class MOUSEINPUT(ctypes.Structure):
    _fields_=[("dx",wintypes.LONG),("dy",wintypes.LONG),("mouseData",wintypes.DWORD),
              ("dwFlags",wintypes.DWORD),("time",wintypes.DWORD),("dwExtraInfo",ctypes.POINTER(wintypes.ULONG))]
class KEYBDINPUT(ctypes.Structure):
    _fields_=[("wVk",wintypes.WORD),("wScan",wintypes.WORD),("dwFlags",wintypes.DWORD),
              ("time",wintypes.DWORD),("dwExtraInfo",ctypes.POINTER(wintypes.ULONG))]
class INPUT_UNION(ctypes.Union):
    _fields_=[("mi",MOUSEINPUT),("ki",KEYBDINPUT)]
class INPUT(ctypes.Structure):
    _anonymous_=("u",)
    _fields_=[("type",wintypes.DWORD),("u",INPUT_UNION)]

def send_click():
    extra = ctypes.pointer(wintypes.ULONG(0))
    for flag in (MOUSEEVENTF_LEFTDOWN, MOUSEEVENTF_LEFTUP):
        inp = INPUT(type=INPUT_MOUSE)
        inp.mi = MOUSEINPUT(0,0,0,flag,0,extra)
        ctypes.windll.user32.SendInput(1, ctypes.byref(inp), ctypes.sizeof(INPUT))
    time.sleep(0.05)

def send_space():
    extra = ctypes.pointer(wintypes.ULONG(0))
    for flag in (0, KEYEVENTF_KEYUP):
        inp = INPUT(type=INPUT_KEYBOARD)
        inp.ki = KEYBDINPUT(VK_SPACE, 0, flag, 0, extra)
        ctypes.windll.user32.SendInput(1, ctypes.byref(inp), ctypes.sizeof(INPUT))
    time.sleep(0.05)

def find_window(title=WIN_TITLE):
    return ctypes.windll.user32.FindWindowW(None, title)

def kill(name):
    subprocess.run(["taskkill","/F","/IM",name], capture_output=True)
    time.sleep(3)   # DX7 device (gg_dx7r.dll) needs time to fully release or the next
                    # process that creates a device on the same adapter hangs/crashes.

def launch(exe, args=None):
    """Robust detached launch. The DX7 original segfaults under a plain bash/Python
    subprocess (inherited console/handles); PowerShell Start-Process gives it a clean
    process and is reliable for both the original and the recomp."""
    args = args or []
    argstr = " ".join(['"' + a + '"' if " " in a else a for a in args])
    ps = (
        f"Start-Process -FilePath '{exe}' "
        f"-WorkingDirectory '{os.path.dirname(exe)}' "
        f"-ArgumentList '{argstr}'"
    )
    subprocess.run(["powershell", "-NoProfile", "-Command", ps],
                   capture_output=True)

def appsnap(out):
    os.makedirs(os.path.dirname(out), exist_ok=True)
    # -t 100 = strict match: avoid fuzzy-matching the "GiantsRE" editor window (which
    # contains "Giants" as a substring) when the game window is absent.
    r = subprocess.run(APPSNAP + ["-t", "100", "-o", out, WIN_TITLE], capture_output=True, text=True)
    return os.path.exists(out)

def foreground(title=WIN_TITLE, timeout=8.0):
    """Bring the game window to the foreground (SendInput targets the fg window)."""
    t0 = time.time()
    while time.time() - t0 < timeout:
        hwnd = find_window(title)
        if hwnd:
            ctypes.windll.user32.ShowWindow(hwnd, 9)   # SW_RESTORE
            ctypes.windll.user32.SetForegroundWindow(hwnd)
            return hwnd
        time.sleep(0.3)
    return 0

# ── phase -> timing/flags ──
# Recomp + original now share the SAME intro timing (fade 0.2s / hold 12s, measured —
# behavior_specs/intro_timings.md), so a single offset table works for both. Offset =
# mid-hold of each phase (well past fade-in, before fade-out). menu uses -skip-intros.
PHASE_WAIT = {"intro1":6000, "intro2":18000, "intro3":30000, "loading":1000, "menu":2500}

def capture_recomp(phase, out, extra_flags=None):
    """Run recomp to <phase>, appsnap while the window is live, then kill.
    Uses a generous -frames so the window stays open during capture (we kill it after)."""
    kill("GiantsMain_vanilla.exe")
    args = ["-launcher", "-window"]
    if phase == "menu":
        args += ["-skip-intros"]           # boot straight to menu
    # large -frames keeps the process alive while we appsnap
    args += ["-frames", "5000"]
    if extra_flags:
        args += extra_flags
    launch(RECOMP, args)
    wait = PHASE_WAIT[phase]
    time.sleep(wait / 1000.0 + 1.5)        # +1.5s for process startup + appsnap settle
    ok = appsnap(out)
    kill("GiantsMain_vanilla.exe")
    return ok

def frida_skip_intros(proc_name="Giants_nocd.exe", timeout=15):
    """Attach Frida to the original, call rpc.skipintros to deterministically skip the
    3-intro sequence (SendInput is fragile). Returns True on success.
    DISABLED by default — frida-agent injection crashes the no-CD original (anti-debug /
    DX7 conflict). Enable with GIANTS_USE_FRIDA=1 once injection is stabilized."""
    if not HAVE_FRIDA or os.environ.get("GIANTS_USE_FRIDA") != "1":
        return False
    try:
        session = frida.attach(proc_name)
        src = open(FRIDA_CTRL, "r", encoding="utf-8").read()
        script = session.create_script(src)
        done = {"ok": False}
        def on_msg(message, data):
            if message.get("type") == "send" and message.get("payload", {}).get("type") == "OK":
                done["ok"] = True
        script.on("message", on_msg)
        script.load()
        t0 = time.time()
        # wait for READY, then call rpc
        time.sleep(0.5)
        try:
            r = script.exports_sync.skipintros()
        except Exception:
            r = False
        # wait for the OK message
        while not done["ok"] and time.time() - t0 < timeout:
            time.sleep(0.3)
        session.detach()
        return done["ok"] or bool(r)
    except Exception as e:
        print(f"[frida] skip failed: {e}", file=sys.stderr)
        return False

def capture_original(phase, out):
    """Run original (Giants_nocd), skip intros, appsnap at phase.
    Intros: capture during natural play (no skip). Menu/loading: Frida skip (reliable)."""
    if not os.path.exists(ORIG):
        print(f"[orig] {ORIG} not found", file=sys.stderr); return False
    kill("Giants.exe"); kill("Giants_nocd.exe")
    launch(ORIG, ["-window"])
    time.sleep(3.0)                                   # let the window + intro1 appear
    if phase.startswith("intro"):
        # intros visible right after boot; capture intro1 immediately, others at offset
        wait = PHASE_WAIT[phase]
        extra = max(0, wait - 3000) / 1000.0
        time.sleep(extra)
        ok = appsnap(out); kill("Giants_nocd.exe"); return ok
    # loading / menu: the most RELIABLE path to the original's menu is to let the 3
    # intros play out NATURALLY (3 × ~12.4s ≈ 38s) — SendInput skip destabilizes the
    # DX7 window and Frida injection crashes the no-CD exe. No input = no crash.
    # Slow (~40s) but deterministic. (Skip methods kept above for when stabilized.)
    if phase == "loading":
        # loading screen (giants_loading.tga) flashes during the async load right after
        # the intros end — capture just before/at the 38s boundary.
        time.sleep(36.0)
    else:                                             # menu
        time.sleep(42.0)                              # past all 3 intros + menu settle
    ok = appsnap(out); kill("Giants_nocd.exe")
    return ok

def diff_images(a, b, out_diff=None, thresh=PASS_THRESH):
    """Mean-abs-delta in [0,1]. Returns (delta, verdict)."""
    ia, ib = Image.open(a).convert("RGB"), Image.open(b).convert("RGB")
    # resize to common size for comparison
    w = min(ia.width, ib.width); h = min(ia.height, ib.height)
    ia, ib = ia.resize((w,h)), ib.resize((w,h))
    ch = ImageChops.difference(ia, ib)
    n = w * h
    pixels_a = ia.load(); pixels_b = ib.load()
    s = 0
    for y in range(h):
        for x in range(w):
            ra, ga, ba = pixels_a[x, y]; rb, gb, bb = pixels_b[x, y]
            s += abs(ra - rb) + abs(ga - gb) + abs(ba - bb)
    delta = s / (n * 3 * 255.0)
    if out_diff:
        ch.save(out_diff)
    return delta, ("PASS" if delta < thresh else "FAIL")

def main():
    ap = argparse.ArgumentParser(description="capdiff — recomp vs original capture-diff")
    sub = ap.add_subparsers(dest="cmd", required=True)
    pr = sub.add_parser("recomp");  pr.add_argument("phase"); pr.add_argument("-o","--out", required=True); pr.add_argument("--flags", nargs="*")
    po = sub.add_parser("original"); po.add_argument("phase"); po.add_argument("-o","--out", required=True)
    pd = sub.add_parser("diff"); pd.add_argument("a"); pd.add_argument("b"); pd.add_argument("-o","--out")
    pc = sub.add_parser("compare"); pc.add_argument("phase"); pc.add_argument("--thresh", type=float, default=PASS_THRESH)
    args = ap.parse_args()

    if args.cmd == "recomp":
        ok = capture_recomp(args.phase, args.out, args.flags)
        print(f"[recomp {args.phase}] {'OK' if ok else 'FAIL'} -> {args.out}")
        sys.exit(0 if ok else 1)
    if args.cmd == "original":
        ok = capture_original(args.phase, args.out)
        print(f"[original {args.phase}] {'OK' if ok else 'FAIL'} -> {args.out}")
        sys.exit(0 if ok else 1)
    if args.cmd == "diff":
        d, v = diff_images(args.a, args.b, args.out, PASS_THRESH)
        print(f"[diff] mean_abs_delta={d:.4f} -> {v}")
        sys.exit(0 if v == "PASS" else 1)
    if args.cmd == "compare":
        r = os.path.join(SHOTS, f"cmp_recomp_{args.phase}.png")
        o = os.path.join(SHOTS, f"cmp_orig_{args.phase}.png")
        df = os.path.join(SHOTS, f"cmp_diff_{args.phase}.png")
        ok1 = capture_recomp(args.phase, r)
        # Both the recomp and the original use gg_dx7r.dll → the DX7 device must be
        # fully released before the other process creates its own, or the second one
        # hangs/crashes. Give the driver time to tear down.
        time.sleep(4.0)
        ok2 = capture_original(args.phase, o)
        if not (ok1 and ok2):
            print(f"[compare {args.phase}] capture failed (recomp={ok1} original={ok2})"); sys.exit(2)
        d, v = diff_images(r, o, df, args.thresh)
        print(f"[compare {args.phase}] recomp={r} original={o} diff={df}")
        print(f"            mean_abs_delta={d:.4f} thresh={args.thresh:.3f} -> {v}")
        sys.exit(0 if v == "PASS" else 1)

if __name__ == "__main__":
    main()
