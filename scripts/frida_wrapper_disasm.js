// Frida (recomp): runtime-disasm the renderer wrapper vtable slots so we can find the
// vertex-buffer lock + DrawPrimitive protocol. g_vRenderer is at exe+0x5b810 (BSS).
// The wrapper@obj+0x294 vtable is ASLR-relocated → can't disasm statically; do it live.
function disasmAt(addr, n) {
  var out = [];
  try {
    var p = addr;
    for (var i = 0; i < n; i++) {
      var ins = Instruction.parse(p);
      out.push(ptr(ins.address).toString() + ': ' + ins.mnemonic + ' ' + ins.opStr);
      p = ptr(ins.address).add(ins.size);
      if (ins.mnemonic === 'ret') break;
    }
  } catch (e) { out.push('<disasm err: ' + e.message + '>'); }
  return out.join('\n');
}
var done = false;
function go(renderer) {
  if (done) return; done = true;
  try {
    var wrapper = renderer.add(0x294).readPointer();
    var vt = wrapper.readPointer();
    send({ type: 'wrapper', wrapper: wrapper.toString(), vt: vt.toString() });
    // disasm key slots: vt[0x0a]=DrawPrim(byte 0x28), vt[0x14]=BeginScene(0x50)?,
    // vt[0x05](0x14), vt[0x06](0x18=EndScene), vt[0x14](0x50=Clear). Dump several.
    var slots = [0x00, 0x04, 0x08, 0x0c, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x50];
    slots.forEach(function (off) {
      var fn = vt.add(off).readPointer();
      send({ type: 'slot', off: '0x' + off.toString(16), fn: fn.toString(), disasm: disasmAt(fn, 14) });
    });
  } catch (e) { send({ type: 'err', e: e.message }); }
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
      clearInterval(iv);
      go(renderer);
    }, 50);
  } } });
send({ type: 'start' });
