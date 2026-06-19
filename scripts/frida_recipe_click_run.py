import frida, time, sys, os, ctypes
from ctypes import wintypes
# Combined: click_inject (GetAsyncKeyState/GetKeyState hooks) + render_recipe_d3d7 (device hooks).
# Tests whether logical-level click injection enters the 3D scene (-> big-mesh draws captured).
user32 = ctypes.windll.user32
SECS = int(sys.argv[1]) if len(sys.argv) > 1 else 40
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
out = r"G:\GiantsRE\reports\frida_recipe_click.txt"
pid = frida.spawn(["Giants_nocd.exe","-window"])
s = frida.attach(pid)
# load BOTH scripts on the same session
for js in ["frida_click_inject.js","frida_render_recipe_d3d7.js"]:
    sc = s.create_script(open(rf"G:\GiantsRE\scripts\{js}").read())
    sc.on("message", lambda m,d: print(m.get("payload") if m.get("type")=="send" else ("ERR "+str(m))))
    sc.load()
frida.resume(pid)
# park cursor in client center so any spatial click hits the menu
time.sleep(7.0)
hwnd=find_window() or 0
if hwnd:
    force_fg(hwnd); r=wintypes.RECT(); user32.GetClientRect(hwnd,ctypes.byref(r))
    pt=wintypes.POINT((r.right-r.left)//2,(r.bottom-r.top)//2); user32.ClientToScreen(hwnd,ctypes.byref(pt))
    user32.SetCursorPos(pt.x,pt.y); print(f"[cursor] center=({pt.x},{pt.y})")
time.sleep(SECS-7)
try: frida.kill(pid)
except: pass
