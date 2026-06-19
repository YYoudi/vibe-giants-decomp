import frida, time, os, subprocess, sys
os.chdir(r"G:\GiantsRE\GameFiles-VanillaV1")
subprocess.run(["taskkill","/F","/IM","Giants_nocd.exe"], capture_output=True); time.sleep(2)
secs = int(sys.argv[1]) if len(sys.argv)>1 else 12
pid = frida.spawn(["Giants_nocd.exe","-window"]); s = frida.attach(pid)
sc=s.create_script(open(r"G:\GiantsRE\scripts\frida_init_recipe.js").read())
lines=[]
def on(m,d):
    p = m.get("payload") if m.get("type")=="send" else ("ERR "+str(m))
    lines.append(str(p))
sc.on("message",on); sc.load(); frida.resume(pid); time.sleep(secs)
try: frida.kill(pid)
except: pass
os.makedirs(r"G:\GiantsRE\reports",exist_ok=True)
open(r"G:\GiantsRE\reports\frida_init_recipe.txt","w").write("\n".join(lines))
print("=== wrote reports/frida_init_recipe.txt (%d lines) ===" % len(lines))
