import frida, time, sys, os
# Runtime observation: log every file the ORIGINAL game opens, in order, with relative timestamps.
# Ground truth for "what loads at phase X". Usage: python frida_filetrace_run.py [seconds]
secs = int(sys.argv[1]) if len(sys.argv) > 1 else 14
os.chdir(r"G:\GiantsRE\GameFiles-VanillaV1")
pid = frida.spawn(["Giants_nocd.exe", "-window"])
s = frida.attach(pid)
sc = s.create_script(open(r"G:\GiantsRE\scripts\frida_filetrace.js").read())
lines = []
def on(m, d):
    if m.get("type") == "send":
        p = m["payload"]
        print(p); lines.append(p)
    elif m.get("type") == "error":
        print("ERR", m)
sc.on("message", on); sc.load(); frida.resume(pid)
time.sleep(secs)
try: frida.kill(pid)
except: pass
out = r"G:\GiantsRE\behavior_specs\orig_filetrace.txt"
open(out, "w", encoding="utf-8").write("\n".join(lines))
print("[filetrace] wrote", out, "(", len(lines), "lines )")
