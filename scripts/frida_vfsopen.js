// frida_vfsopen.js — RUNTIME observation: log every asset the ORIGINAL game opens BY NAME.
// Hooks FUN_00539e30 (vanilla VFS open-by-name) — the definitive asset-load observer.
// This is the ONLY way to prove "is asset X loaded at phase Y" (CreateFile can't, rule 5).
// FUN_00539e30(char* name): looks name up in GZP index (DAT_005e12b4), builds path, opens.
var t0 = Date.now();
function ts() { return (((Date.now() - t0) / 1000).toFixed(3)); }

var mod = Process.findModuleByName("Giants_nocd.exe");
if (!mod) { send("[!] Giants_nocd.exe module not found"); }
else {
  var openByName = mod.base.add(0x539e30 - 0x400000);  // decompile addr is absolute VA (ImageBase 0x400000 included)
  send("[+] module base=" + mod.base + "  VFS-open-by-name FUN_00539e30 @ " + openByName);
  Interceptor.attach(openByName, {
    onEnter: function (args) {
      var name = null;
      try { name = args[0].readAnsiString(); } catch (e) { name = "<unreadable>"; }
      this.name = name;
    },
    onLeave: function (retval) {
      send("[" + ts() + "s] VFSopen  " + (retval.toInt32() ? "OK   " : "MISS ")
           + (this.name || "<null>"));
    }
  });
  send("[vfsopen] ready");
}
