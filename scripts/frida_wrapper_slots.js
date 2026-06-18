// Frida: hook the wrapper@obj+0x294 vtable to find which slots fire during rendering.
// The wrapper is the renderer's custom D3D7-like device. SetTexture is an unmapped slot.
// Hook all vtable slots 0x00..0xC0 + log call counts → the slot that fires with 2 args
// (stage, texture) before DrawPrimitive = SetTexture.
var counts = {};
var renderer = null;

// Find the renderer object (DAT_00654940 = exe+0x254940).
var iv = setInterval(function () {
  try {
    var exe = Process.findModuleByName('Giants_nocd.exe') || Process.findModuleByName('Giants.exe');
    if (!exe) return;
    renderer = exe.base.add(0x254940).readPointer();
    if (!renderer.isNull()) { clearInterval(iv); go(); }
  } catch (e) {}
}, 100);

function go() {
  send({type:'READY', renderer: renderer.toString()});
  var wrapper = renderer.add(0x294).readPointer();   // wrapper@obj+0x294
  var vtable = wrapper.readPointer();                 // *wrapper = vtable
  send({type:'WRAPPER', wrapper: wrapper.toString(), vtable: vtable.toString()});

  // Hook all vtable slots 0x00..0xC0 (48 slots, 4 bytes each).
  for (var off = 0; off <= 0xC0; off += 4) {
    try {
      var fn = vtable.add(off).readPointer();
      if (fn.isNull()) continue;
      counts[off] = 0;
      Interceptor.attach(fn, { onEnter: function (args) {
        // 'off' is captured — but Interceptor closures share 'this', not loop vars.
        // Use a tagged wrapper.
      }});
    } catch (e) {}
  }

  // Better: attach individually with the offset baked in.
  for (var off2 = 0; off2 <= 0xC0; off2 += 4) {
    try {
      var fn2 = vtable.add(off2).readPointer();
      if (fn2.isNull()) continue;
      (function (o, f) {
        Interceptor.attach(f, { onEnter: function () { counts[o] = (counts[o]||0) + 1; } });
      })(off2, fn2);
    } catch (e) {}
  }

  // Report counts after 10s.
  setTimeout(function () { send({type:'COUNTS', counts: counts}); }, 10000);
}
send({type:'start'});
