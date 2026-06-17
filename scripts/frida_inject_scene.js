// Frida (recomp): inject the terrain draw INTO the renderer's own scene-render (gg_dx7r.dll
// RVA 0x71a0) so it draws on the device's RT during the frame that the renderer presents.
// (The manual frame driver + callbacks don't reach the presented surface; drawing here
// during the renderer's in-frame scene render should, if the renderer presents.)
function go(ggdx, exeBase) {
  // VanillaTerrain_DrawX(const char*, const char*) __cdecl, at exe+0x9cbe.
  var drawX = new NativeFunction(exeBase.add(0x9cbe), 'int', ['pointer', 'pointer'], 'mscdecl');
  var gti = Memory.allocUtf8String('intro_island.gti');
  var gzp = Memory.allocUtf8String('Bin\\w_intro_island.gzp');
  var sceneRender = ggdx.add(0x71a0);
  var n = 0;
  Interceptor.attach(sceneRender, {
    onEnter: function () {
      if (n < 3) send({ type: 'INJECT', at: '0x71a0 scene-render', n: n });
      try { drawX(gti, gzp); } catch (e) { send({ type: 'ERR', e: e.message }); }
      n++;
    }
  });
  send({ type: 'hooked_scene_render', at: sceneRender.toString() });
}
var don = false;
var k32 = Process.findModuleByName('kernel32.dll') || Process.findModuleByName('kernelbase.dll');
var lla = k32.findExportByName('LoadLibraryA');
Interceptor.attach(lla, { onEnter: function (a) { try { this.n = a[0].readCString(); } catch (e) {} },
  onLeave: function () {
    if (this.n && this.n.toLowerCase().indexOf('gg_dx7') >= 0 && !don) {
      var ggdx = Process.findModuleByName('gg_dx7r.dll');
      var exe = null; var ms = Process.enumerateModules();
      for (var i = 0; i < ms.length; i++) if (ms[i].name.indexOf('GiantsMain_vanilla') >= 0) exe = ms[i];
      if (ggdx && exe) { don = true; go(ggdx.base, exe.base); }
    }
  } });
send({ type: 'start' });
