// frida_filetrace.js — RUNTIME observation: log every file the ORIGINAL game opens.
// Ground truth for "what does the original load at phase X". Zero guessing.
// Hooks CreateFileA/W (kernel32) — every OS-level file open, path + relative time + result.
var t0 = Date.now();
function ts() { return (((Date.now() - t0) / 1000).toFixed(3)); }

function hook(mod, fn, wide) {
  var p = null;
  var m = Process.findModuleByName(mod);
  if (m) { p = m.findExportByName(fn); }
  if (!p && typeof Module.findGlobalExportByName === "function") { p = Module.findGlobalExportByName(fn); }
  if (!p) { send("[?] " + mod + "!" + fn + " NOT FOUND"); return; }
  Interceptor.attach(p, {
    onEnter: function (args) {
      this.path = wide ? (args[0].readUtf16String() || "<null>")
                        : (args[0].readAnsiString() || "<null>");
    },
    onLeave: function (retval) {
      // Only log the game's own file opens (skip system noise). Giants files are
      // relative or under G:\GiantsRE. We log everything but mark handles.
      var ok = retval.toInt32() !== -1;
      send("[" + ts() + "s] " + (ok ? "OPEN " : "FAIL ") + fn + "  " + this.path);
    }
  });
  send("[+] hooked " + mod + "!" + fn + " @ " + p);
}

hook("kernel32.dll", "CreateFileA", false);
hook("kernel32.dll", "CreateFileW", true);
send("[filetrace] ready, t0 set");
