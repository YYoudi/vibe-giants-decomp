import frida, time, os, subprocess
os.chdir(r"G:\GiantsRE\GameFiles-VanillaV1")
subprocess.run(["taskkill","/F","/IM","Giants_nocd.exe"], capture_output=True); time.sleep(2)
pid = frida.spawn(["Giants_nocd.exe","-window"]); s = frida.attach(pid)
sc=s.create_script(open(r"G:\GiantsRE\scripts\frida_createtex.js").read())
lines=[]
def on(m,d):
    p=m.get("payload") if m.get("type")=="send" else ("ERR "+str(m))
    lines.append(str(p))
sc.on("message",on); sc.load(); frida.resume(pid); time.sleep(10)
try: frida.kill(pid)
except: pass
os.makedirs(r"G:\GiantsRE\reports",exist_ok=True)
open(r"G:\GiantsRE\reports\frida_createtex.txt","w").write("\n".join(lines))
print("=== %d lines ==="%len(lines))
