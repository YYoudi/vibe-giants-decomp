import frida, time, os
os.chdir(r"G:\GiantsRE\GameFiles-VanillaV1")
pid=frida.spawn(["Giants_nocd.exe","-window"])
s=frida.attach(pid); sc=s.create_script(open(r"G:\GiantsRE\scripts\frida_dx7_renderseq.js").read())
def on(m,d):
    if m.get("type")=="send": print(m["payload"])
    elif m.get("type")=="error": print("ERR",m)
sc.on("message",on); sc.load(); frida.resume(pid)
time.sleep(11)
try: frida.kill(pid)
except: pass
