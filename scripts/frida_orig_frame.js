// Frida (ORIGINAL Giants_nocd.exe): hook the renderer front-table slots + see which fire
// during the WORKING game's frame (the recomp fires only 0x80/0xb4/0xc0 — the original
// should fire the PRESENT slot too). Renderer obj @ DAT_00654940 (original exe 0x654940).
var counts = {};
var done = false;
function hookSlots(renderer) {
  if (done) return; done = true;
  var slots = [0x04,0x08,0x10,0x14,0x18,0x1c,0x20,0x24,0x28,0x2c,0x30,0x34,0x38,0x3c,0x40,0x44,0x48,0x4c,0x50,0x54,0x58,0x5c,0x60,0x64,0x68,0x6c,0x70,0x74,0x78,0x7c,0x80,0x84,0x88,0x8c,0x90,0x94,0x98,0x9c,0xa0,0xa4,0xa8,0xac,0xb0,0xb4,0xb8,0xbc,0xc0,0xc4,0xc8,0xcc,0xd0,0xd4,0xd8,0xdc,0xe0];
  slots.forEach(function (off) {
    try {
      var fn = renderer.add(off).readPointer();
      if (fn.isNull()) return;
      counts[off] = 0;
      Interceptor.attach(fn, { onEnter: function () { counts[off]++; } });
    } catch (e) {}
  });
  send({ type: 'hooked', renderer: renderer.toString() });
}
// Poll for the renderer object @ exe+0x254940 (DAT_00654940 - exe_base 0x400000 = 0x254940).
var iv = setInterval(function () {
  try {
    var exe = Process.findModuleByName('Giants_nocd.exe') || Process.findModuleByName('Giants.exe');
    if (!exe) return;
    var renderer = exe.base.add(0x254940).readPointer();
    if (!renderer.isNull()) { clearInterval(iv); hookSlots(renderer); }
  } catch (e) {}
}, 100);
setTimeout(function () { send({ type: 'COUNTS', counts: counts }); }, 10000);
send({ type: 'start' });
