// frida_projmatrix.js — OBSERVE the original's camera projection/view matrix at the menu.
// The engine pushes the matrix to the renderer via method +0x20 (SetCameraProjection(obj,&mat16)),
// called by FUN_0051bea0 (perspective) / FUN_0051bbd0 (2D-HUD). Hooking the renderer's +0x20 method
// and dumping arg[1] (the 16 floats) captures the EXACT matrix the renderer renders with.
var t0 = Date.now();
function ts() { return (((Date.now() - t0) / 1000).toFixed(3)); }
var mod = Process.findModuleByName("Giants_nocd.exe");
if (!mod) { send("[!] no module"); }
else {
  var b = mod.base;
  function va(a) { return b.add(a - 0x400000); }
  var pRenderer = va(0x654940);          // DAT_00654940 = g_vRenderer
  var logged = 0;
  function tryHook() {
    var obj = pRenderer.readPointer();
    if (obj.isNull()) return false;
    // method +0x20 is an inline pointer in the renderer's front table
    var m20 = obj.add(0x20).readPointer();
    send("[+] renderer=" + obj + " method+0x20=" + m20);
    Interceptor.attach(m20, {
      onEnter: function (args) {
        if (logged >= 4) return;
        // cdecl: args[0]=this(renderer), args[1]=&matrix (16 floats)
        var mp = args[1];
        try {
          var f = [];
          for (var i = 0; i < 16; i++) f.push(mp.add(i*4).readFloat().toFixed(4));
          send("[" + ts() + "s] +0x20 matrix: " + f.join(","));
          logged++;
        } catch (e) { send("[err] " + e); }
      }
    });
    return true;
  }
  // poll until the renderer object is created
  var tries = 0;
  var iv = setInterval(function () {
    if (tryHook() || ++tries > 200) clearInterval(iv);
  }, 100);
}
