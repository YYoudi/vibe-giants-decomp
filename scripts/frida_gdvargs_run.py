import frida, time, os
os.chdir(r"G:\GiantsRE\GameFiles-VanillaV1")
out = r"G:\GiantsRE\reports\frida_gdvargs.txt"
pid = frida.spawn(["Giants_nocd.exe", ""])
s = frida.attach(pid)
script = s.create_script(open(r"G:\GiantsRE\scripts\frida_gdvargs.js").read())
lines=[]
def on_msg(msg,data):
    if msg.get("type")=="send":
        lines.append(str(msg["payload"])); print(msg["payload"])
    elif msg.get("type")=="error":
        lines.append("ERR "+str(msg)); print("ERR",msg)
script.on("message",on_msg); script.load(); frida.resume(pid)
time.sleep(12)
try: frida.kill(pid)
except: pass
os.makedirs(r"G:\GiantsRE\reports",exist_ok=True)
open(out,"w").write("\n".join(lines))
print("=== wrote",out,"===")
