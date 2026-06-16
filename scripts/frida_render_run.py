import frida, sys, time, os
os.chdir(r"G:\GiantsRE\GameFiles")
out = r"G:\GiantsRE\reports\frida_render_seq.txt"
# Run the ORIGINAL (oracle) with the proxy → real renderer, so the render cycle executes.
pid = frida.spawn(["GiantsMain_orig.exe", "-launcher", "-window", "-gamegauge"])
s = frida.attach(pid)
script = s.create_script(open(r"G:\GiantsRE\scripts\frida_render_seq.js").read())
lines = []
def on_msg(msg, data):
    if msg.get("type")=="send":
        lines.append(str(msg["payload"])); print(msg["payload"])
    elif msg.get("type")=="error":
        lines.append("ERR "+str(msg)); print("ERR", msg)
script.on("message", on_msg)
script.load(); frida.resume(pid)
time.sleep(9)
try: frida.kill(pid)
except: pass
os.makedirs(r"G:\GiantsRE\reports", exist_ok=True)
open(out,"w").write("\n".join(lines))
print("=== wrote", out, "===")
