import frida, sys, time, subprocess, os

os.chdir(r"G:\GiantsRE\GameFiles")
script_path = r"G:\GiantsRE\scripts\frida_enginectx.js"
out_path = r"G:\GiantsRE\reports\frida_enginectx.txt"

# Spawn the original exe (which loads the proxy → real renderer).
pid = frida.spawn(["GiantsMain_orig.exe", "-launcher", "-window", "-gamegauge"])
session = frida.attach(pid)
with open(script_path, "r") as f:
    src = f.read()
script = session.create_script(src)

lines = []
def on_message(msg, data):
    if msg.get("type") == "send":
        p = msg["payload"]
        if data:
            # GUID 16 bytes as hex
            guid_hex = data.hex()
            p = dict(p) if isinstance(p, dict) else {"payload": p}
            p["guid_hex"] = guid_hex
        lines.append(str(p))
        print(p)
    elif msg.get("type") == "error":
        lines.append("ERROR: " + str(msg.get("stack", msg)))
        print("ERROR:", msg)
script.on("message", on_message)
script.load()
frida.resume(pid)

time.sleep(12)
try:
    frida.kill(pid)
except Exception:
    pass

os.makedirs(r"G:\GiantsRE\reports", exist_ok=True)
with open(out_path, "w") as f:
    f.write("\n".join(lines))
print("=== wrote", out_path, "===", len(lines), "msgs")
