import frida, time, sys, os, ctypes
from ctypes import wintypes

# OBSERVE the original's 3D MENU state: spawn via Frida + vfsopen hook, skip intros with 4 clicks,
# screenshot the 3D menu. Produces: the menu asset-load log + a screenshot of what 3D renders.
# User-discovered skip: open, click 4x in window, wait → 3D menu.

user32 = ctypes.windll.user32
SECS_AFTER = int(sys.argv[1]) if len(sys.argv) > 1 else 10

# --- click helpers (SendInput) ---
MOUSEEVENTF_LEFTDOWN, MOUSEEVENTF_LEFTUP = 0x0002, 0x0004
class MOUSEINPUT(ctypes.Structure):
    _fields_ = [("dx",ctypes.c_long),("dy",ctypes.c_long),("mouseData",ctypes.c_ulong),
                ("dwFlags",ctypes.c_ulong),("time",ctypes.c_ulong),("dwExtraInfo",ctypes.POINTER(ctypes.c_ulong))]
class _INPUT_U(ctypes.Union):
    _fields_ = [("mi",MOUSEINPUT)]
class INPUT(ctypes.Structure):
    _anonymous_ = ("u",)
    _fields_ = [("type",ctypes.c_ulong),("u",_INPUT_U)]

def click():
    for flag in (MOUSEEVENTF_LEFTDOWN, MOUSEEVENTF_LEFTUP):
        inp = INPUT(type=0)
        inp.mi = MOUSEINPUT(0,0,0,flag,0,None)
        user32.SendInput(1, ctypes.byref(inp), ctypes.sizeof(inp))
    time.sleep(0.05)

def find_window():
    res = []
    def cb(hwnd, _):
        if user32.IsWindowVisible(hwnd):
            buf = ctypes.create_unicode_buffer(256)
            user32.GetWindowTextW(hwnd, buf, 256)
            if "giants" in buf.value.lower() or "island" in buf.value.lower():
                res.append(hwnd)
        return True
    user32.EnumWindows(ctypes.WINFUNCTYPE(ctypes.c_bool, wintypes.HWND, wintypes.LPARAM)(cb), 0)
    return res[0] if res else None

def force_foreground(hwnd):
    # AttachThreadInput trick — bypasses SetForegroundWindow restriction.
    fg = user32.GetForegroundWindow()
    t1 = user32.GetWindowThreadProcessId(fg, None)
    t2 = user32.GetWindowThreadProcessId(hwnd, None)
    if t1 != t2:
        user32.AttachThreadInput(t2, t1, True)
    user32.ShowWindow(hwnd, 9)
    user32.SetForegroundWindow(hwnd)
    user32.SetFocus(hwnd)
    if t1 != t2:
        user32.AttachThreadInput(t2, t1, False)

# --- spawn + hook ---
os.chdir(r"G:\GiantsRE\GameFiles-VanillaV1")
pid = frida.spawn(["Giants_nocd.exe", "-window"])
s = frida.attach(pid)
sc = s.create_script(open(r"G:\GiantsRE\scripts\frida_vfsopen.js").read())
lines = []
def on(m, d):
    if m.get("type") == "send":
        print(m["payload"]); lines.append(m["payload"])
    elif m.get("type") == "error":
        print("ERR", m)
sc.on("message", on); sc.load(); frida.resume(pid)

# --- wait for window, then 4 clicks to skip intros ---
time.sleep(6.0)  # let window + intros start
hwnd = find_window()
if not hwnd:
    print("[!] no window found, retrying..."); time.sleep(3.0); hwnd = find_window()
if hwnd:
    force_foreground(hwnd); time.sleep(0.5)
    r = wintypes.RECT(); user32.GetClientRect(hwnd, ctypes.byref(r))
    # client center → screen coords
    pt = wintypes.POINT((r.right-r.left)//2, (r.bottom-r.top)//2)
    user32.ClientToScreen(hwnd, ctypes.byref(pt))
    user32.SetCursorPos(pt.x, pt.y); time.sleep(0.3)
    print(f"[clicks] hwnd={hwnd} client-center=({pt.x},{pt.y}) — 4 clicks")
    for i in range(4):
        force_foreground(hwnd); click(); time.sleep(1.2)
else:
    print("[!] no window — skipping clicks")

# --- wait until the menu scene loads (W_intro_island.bin appears) or timeout ---
deadline = time.time() + 45
while time.time() < deadline:
    if any("W_intro_island.bin" in l for l in lines):
        print("[menu] W_intro_island.bin loaded — 3D menu scene up")
        break
    time.sleep(0.5)
else:
    print("[menu] timeout — W_intro_island.bin never loaded (clicks may have failed)")
time.sleep(4.0)  # let the 3D render settle

# --- screenshot: verify client rect in ctypes, then ImageGrab of the window's screen region ---
png = r"G:\GiantsRE\behavior_specs\orig_menu_3d.png"
from PIL import ImageGrab
def grab_window(h, path):
    force_foreground(h); time.sleep(0.4)
    wr = wintypes.RECT(); user32.GetWindowRect(h, ctypes.byref(wr))
    cr = wintypes.RECT(); user32.GetClientRect(h, ctypes.byref(cr))
    print(f"[shot] hwnd={h} winrect=({wr.left},{wr.top},{wr.right},{wr.bottom}) client={cr.right}x{cr.bottom}")
    bbox = (wr.left, wr.top, wr.right, wr.bottom)
    img = ImageGrab.grab(bbox=bbox, all_screens=True)
    img.convert("RGB").save(path)
    return img.size
try:
    sz = grab_window(hwnd, png)
    print("[shot] ImageGrab", sz, "->", png)
except Exception as e:
    print("[shot] ImageGrab failed:", e)

open(r"G:\GiantsRE\behavior_specs\orig_vfsopen_menu.txt","w",encoding="utf-8").write("\n".join(lines))
try: frida.kill(pid)
except: pass
print("[done] menu vfsopen log:", len(lines), "lines")
