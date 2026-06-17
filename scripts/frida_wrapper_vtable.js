// Frida (recomp): dump the renderer's private wrapper object vtable so we can find the
// vertex-buffer lock + DrawPrimitive methods. The wrapper lives at renderer_obj+0x294;
// its vtable = [wrapper]. The terrain draw crashes because slot+0x98 (DrawPrimitive via
// wrapper vt[0x28]) reads from a locked VB — we need the VB-lock method (a wrapper vt slot).
function hexdump(p, n) {
  try { var b = p.readByteArray(n); var v = new Uint8Array(b); var s = '';
    for (var i = 0; i < v.length; i++) { s += ('0' + v[i].toString(16)).slice(-2) + ' '; if ((i & 3) === 3) s += ' '; }
    return s.trim();
  } catch (e) { return '<' + e.message + '>'; }
}
var done = false;
function go(renderer) {
  if (done) return; done = true;
  var obj = renderer;
  send({ type: 'renderer', addr: obj.toString() });
  // dump the renderer object fields around the wrapper + draw slots
  try {
    var wrapper = obj.add(0x294).readPointer();
    send({ type: 'wrapper', at: obj.add(0x294).toString(), ptr: wrapper.toString() });
    var vt = wrapper.readPointer();
    send({ type: 'wrapper_vtable', ptr: vt.toString() });
    // dump 48 vtable slots (4 bytes each)
    var slots = [];
    for (var i = 0; i < 48; i++) slots.push(vt.add(i * 4).readPointer().toString());
    send({ type: 'vt_slots', slots: slots });
    // also the renderer front-table slots we use: +0x90(begin/clear), +0x94(end), +0x98(draw), +0x60(present), +0xb0(linknode)
    var ft = {};
    [0x60, 0x90, 0x94, 0x98, 0x9c, 0xa0, 0xa4, 0xb0, 0xb4, 0xc0].forEach(function(off) {
      ft['+' + off.toString(16)] = obj.add(off).readPointer().toString();
    });
    send({ type: 'front_table', slots: ft });
  } catch (e) { send({ type: 'err', e: e.message }); }
}
// Hook GDVSysCreate return to get the renderer object.
var k32 = Process.findModuleByName('kernel32.dll') || Process.findModuleByName('kernelbase.dll');
var lla = k32.findExportByName('LoadLibraryA');
Interceptor.attach(lla, { onEnter: function (a) { try { this.n = a[0].readCString(); } catch (e) { this.n = '?'; } },
  onLeave: function (r) { if (this.n && this.n.toLowerCase().indexOf('gg_dx7') >= 0) {
    // poll g_vRenderer — it's set after GDVSysCreate. Give it a moment via a timed check.
    var iv = setInterval(function () {
      // g_vRenderer is a global in the recomp; find it via the export if present, else scan.
      var mods = Process.enumerateModules();
      var exe = null; for (var i = 0; i < mods.length; i++) if (mods[i].name.indexOf('GiantsMain_vanilla') >= 0) exe = mods[i];
      if (!exe) return;
      // g_vRenderer symbol
      var sym = Module.findExportByName(exe.name, 'g_vRenderer');
      if (!sym) { clearInterval(iv); send({ type: 'no_g_vRenderer_export' }); return; }
      var renderer = sym.readPointer();
      if (renderer.isNull()) return;
      clearInterval(iv);
      go(renderer);
    }, 50);
  } } });
send({ type: 'start' });
