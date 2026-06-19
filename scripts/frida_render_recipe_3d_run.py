import frida, time, sys, os, ctypes
from ctypes import wintypes
# OBSERVE the original's 3D MESH draw recipe (the strided geometry for island+logo), which is
# click-gated. Combines frida_menu_observe.py's click-into-3D (AttachThreadInput + 4 SendInput
# clicks) with frida_render_recipe_d3d7.js (D3D7 device hooks). After the clicks we capture
# DrawIndexedPrimitiveStrided BIG-mesh draws (vCount>50) = the actual 3D scene geometry.

user32 = ctypes.windll.user32
SECS = int(sys.argv[1]) if len(sys.argv) > 1 else 48
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
        inp = INPUT(type=0); inp.mi = MOUSEINPUT(0,0,0,flag,0,None)
        user32.SendInput(1, ctypes.byref(inp), ctypes.sizeof(inp))
    time.sleep(0.05)
def postmsg_click(hwnd):
    # PostMessage WM_LBUTTONDOWN/UP — delivered via window queue/WndProc (bypasses DI8).
    WM_LBUTTONDOWN, WM_LBUTTONUP = 0x201, 0x202
    user32.PostMessageW(hwnd, WM_LBUTTONDOWN, 1, 0)
    time.sleep(0.05)
    user32.PostMessageW(hwnd, WM_LBUTTONUP, 0, 0)
    time.sleep(0.05)
def find_window():
    res=[]
    def cb(hwnd,_):
        if user32.IsWindowVisible(hwnd):
            buf=ctypes.create_unicode_buffer(256); user32.GetWindowTextW(hwnd,buf,256)
            if "giants" in buf.value.lower() or "island" in buf.value.lower(): res.append(hwnd)
        return True
    user32.EnumWindows(ctypes.WINFUNCTYPE(ctypes.c_bool,wintypes.HWND,wintypes.LPARAM)(cb),0)
    return res[0] if res else None
def force_fg(hwnd):
    fg=user32.GetForegroundWindow(); t1=user32.GetWindowThreadProcessId(fg,None); t2=user32.GetWindowThreadProcessId(hwnd,None)
    if t1!=t2: user32.AttachThreadInput(t2,t1,True)
    user32.ShowWindow(hwnd,9); user32.SetForegroundWindow(hwnd); user32.SetFocus(hwnd)
    if t1!=t2: user32.AttachThreadInput(t2,t1,False)

os.chdir(r"G:\GiantsRE\GameFiles-VanillaV1")
out = r"G:\GiantsRE\reports\frida_render_recipe_3d.txt"
pid = frida.spawn(["Giants_nocd.exe","-window"])
s = frida.attach(pid)
sc = s.create_script(open(r"G:\GiantsRE\scripts\frida_render_recipe_d3d7.js").read())
lines=[]
def on(m,d):
    if m.get("type")=="send":
        lines.append(str(m["payload"])); print(m["payload"])
    elif m.get("type")=="error": lines.append("ERR "+str(m)); print("ERR",m)
sc.on("message",on); sc.load(); frida.resume(pid)

time.sleep(6.0)
hwnd=find_window()
if not hwnd: time.sleep(3.0); hwnd=find_window()
if hwnd:
    force_fg(hwnd); time.sleep(0.5)
    r=wintypes.RECT(); user32.GetClientRect(hwnd,ctypes.byref(r))
    pt=wintypes.POINT((r.right-r.left)//2,(r.bottom-r.top)//2); user32.ClientToScreen(hwnd,ctypes.byref(pt))
    user32.SetCursorPos(pt.x,pt.y); time.sleep(0.3)
    print(f"[clicks] hwnd={hwnd} center=({pt.x},{pt.y}) — 8 clicks (SendInput+PostMessage)")
    for i in range(8):
        force_fg(hwnd); click(); postmsg_click(hwnd); time.sleep(0.8)
else:
    print("[!] no window — no clicks")
time.sleep(SECS-12)
try: frida.kill(pid)
except: pass
os.makedirs(r"G:\GiantsRE\reports",exist_ok=True)
open(out,"w").write("\n".join(lines))
print("=== wrote",out,"(",len(lines),"lines ) ===")
