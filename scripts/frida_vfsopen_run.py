import frida, time, sys, os
# Runtime observation: every asset the ORIGINAL opens by name, with timestamps.
# Run through intros into the menu. Usage: python frida_vfsopen_run.py [seconds]
secs = int(sys.argv[1]) if len(sys.argv) > 1 else 22
os.chdir(r"G:\GiantsRE\GameFiles-VanillaV1")
pid = frida.spawn(["Giants_nocd.exe", "-window"])
s = frida.attach(pid)
sc = s.create_script(open(r"G:\GiantsRE\scripts\frida_vfsopen.js").read())
lines = []
def on(m, d):
    if m.get("type") == "send":
        p = m["payload"]; print(p); lines.append(p)
    elif m.get("type") == "error":
        print("ERR", m)
sc.on("message", on); sc.load(); frida.resume(pid)
time.sleep(secs)
try: frida.kill(pid)
except: pass
out = r"G:\GiantsRE\behavior_specs\orig_vfsopen.txt"
open(out, "w", encoding="utf-8").write("\n".join(lines))
print("[vfsopen] wrote", out, "(", len(lines), "lines )")
