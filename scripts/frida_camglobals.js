// frida_camglobals.js — OBSERVE the original's camera globals at the menu.
// callback[12] (FUN_0050d430... actually 0040d430) returns these to the renderer for its view matrix:
//   DAT_005561a4/a8/ac = camera position (x,y,z), DAT_005561b0/b4/b8 = angles.
// Reading them at the menu gives the EXACT faithful camera (no guessing).
var t0 = Date.now();
function ts() { return (((Date.now() - t0) / 1000).toFixed(3)); }
var mod = Process.findModuleByName("Giants_nocd.exe");
if (!mod) { send("[!] Giants_nocd.exe not found"); }
else {
  // .data globals: subtract ImageBase 0x400000 (decompile addrs are absolute VAs).
  function va(addr) { return mod.base.add(addr - 0x400000); }
  var pPos = va(0x5561a4);       // DAT_005561a4 (pos.x) ; a8=pos.y ; ac=pos.z
  var pAng = va(0x5561b0);       // DAT_005561b0 (angle1) ; b4=angle2 ; b8=angle3
  send("[+] base=" + mod.base + " pos@0x5561a4=" + pPos + " ang@0x5561b0=" + pAng);
  function rd(p) { return [p.readFloat(), p.add(4).readFloat(), p.add(8).readFloat()]; }
  // Poll every 2s; log when values look "live" (non-zero / changing).
  var prev = "";
  setInterval(function () {
    try {
      var pos = rd(pPos), ang = rd(pAng);
      var s = "pos=(" + pos[0].toFixed(1) + "," + pos[1].toFixed(1) + "," + pos[2].toFixed(1) +
              ") ang=(" + ang[0].toFixed(2) + "," + ang[1].toFixed(2) + "," + ang[2].toFixed(2) + ")";
      if (s !== prev) { send("[" + ts() + "s] " + s); prev = s; }
    } catch (e) { send("[err] " + e); }
  }, 2000);
}
