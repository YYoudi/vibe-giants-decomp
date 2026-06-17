// Frida (recomp): capture which renderer front-table slots fire during the renderer's real
// frame (VanillaRunFrame→0x7370→0x7340) to find the TRUE Present/flip (slot+0x60 is just
// SetRect — not the real present). Hooks every front-table method (obj+0x60..+0xe0) by
// reading g_vRenderer at runtime (ASLR) + counts calls + logs first-call order.
var done = false;
var counts = {};
var order = [];
function hookFrontTable(renderer) {
  if (done) return; done = true;
  // front-table slots live at obj+offset (single indirection). Hook a useful range.
  var slots = [0x04,0x08,0x0c,0x10,0x14,0x18,0x1c,0x20,0x24,0x28,0x2c,0x30,0x34,0x38,0x3c,0x40,0x44,0x48,0x4c,0x50,0x54,0x58,0x5c,0x60,0x64,0x68,0x6c,0x70,0x74,0x78,0x7c,0x80,0x84,0x88,0x8c,0x90,0x94,0x98,0x9c,0xa0,0xa4,0xa8,0xac,0xb0,0xb4,0xb8,0xbc,0xc0,0xc4,0xc8,0xcc,0xd0,0xd4,0xd8,0xdc,0xe0];
  slots.forEach(function (off) {
    try {
      var fn = renderer.add(off).readPointer();
      if (fn.isNull()) return;
      counts[off] = 0;
      Interceptor.attach(fn, {
        onEnter: function () {
          counts[off]++;
          if (counts[off] <= 3 && order.length < 80) order.push('+0x' + off.toString(16));
        }
      });
    } catch (e) {}
  });
  send({ type: 'hooked', n: slots.length });
  setTimeout(function () { send({ type: 'COUNTS', counts: counts }); send({ type: 'ORDER', order: order }); }, 4000);
}
var k32 = Process.findModuleByName('kernel32.dll') || Process.findModuleByName('kernelbase.dll');
var lla = k32.findExportByName('LoadLibraryA');
Interceptor.attach(lla, { onEnter: function (a) { try { this.n = a[0].readCString(); } catch (e) { this.n = '?'; } },
  onLeave: function (r) { if (this.n && this.n.toLowerCase().indexOf('gg_dx7') >= 0) {
    var iv = setInterval(function () {
      var mods = Process.enumerateModules();
      var exe = null; for (var i = 0; i < mods.length; i++) if (mods[i].name.indexOf('GiantsMain_vanilla') >= 0) exe = mods[i];
      if (!exe) return;
      var renderer = exe.base.add(0x5b810).readPointer();
      if (renderer.isNull()) return;
      clearInterval(iv); hookFrontTable(renderer);
    }, 50);
  } } });
send({ type: 'start' });
