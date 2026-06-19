import frida, time, sys, os
# OBSERVE the original's D3D7 device recipe at the menu (SetTransform/SetTexture/DrawPrimitive).
# Captures the camera VIEW matrix (missing from recomp) + per-frame draw recipe.
# Usage: python frida_render_recipe_d3d7_run.py [seconds]
secs = int(sys.argv[1]) if len(sys.argv) > 1 else 45
os.chdir(r"G:\GiantsRE\GameFiles-VanillaV1")
out = r"G:\GiantsRE\reports\frida_render_recipe_d3d7.txt"
pid = frida.spawn(["Giants_nocd.exe", "-window"])
s = frida.attach(pid)
script = s.create_script(open(r"G:\GiantsRE\scripts\frida_render_recipe_d3d7.js").read())
lines=[]
def on_msg(msg,data):
    if msg.get("type")=="send":
        lines.append(str(msg["payload"])); print(msg["payload"])
    elif msg.get("type")=="error":
        lines.append("ERR "+str(msg)); print("ERR",msg)
script.on("message",on_msg); script.load(); frida.resume(pid)
time.sleep(secs)
try: frida.kill(pid)
except: pass
os.makedirs(r"G:\GiantsRE\reports",exist_ok=True)
open(out,"w").write("\n".join(lines))
print("=== wrote",out,"(",len(lines),"lines ) ===")
