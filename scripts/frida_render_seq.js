// Frida: observe the original's per-frame RENDER call sequence on the renderer
// device vtable, to ground the recomp's FrameEnd reconstruction.
// Render-cycle vtable method RVAs (from the device vtable dump, base 0x10000000):
//   [41]=0x4D9C0 [42]=0x4DAA0 [43]=0x4DAE0 [44]=0x4DB20 [45]=0x4DBB0 [46]=0x4DC20 [47]=0x4DCC0
var methods = {
  'vt41': 0x4D9C0, 'vt42': 0x4DAA0, 'vt43': 0x4DAE0, 'vt44': 0x4DB20,
  'vt45': 0x4DBB0, 'vt46': 0x4DC20, 'vt47': 0x4DCC0
};
var counts = {}; var seq = []; var hooked = false;
Object.keys(methods).forEach(function(n){ counts[n]=0; });

function findRenderer() {
  var mods = Process.enumerateModules();
  for (var i=0;i<mods.length;i++) if (mods[i].name.toLowerCase().indexOf('gg_dx9r')>=0) return mods[i];
  return null;
}
function hookAll(mod) {
  if (hooked) return;
  Object.keys(methods).forEach(function(name){
    try {
      Interceptor.attach(mod.base.add(methods[name]), {
        onEnter: function(){ counts[name]++; if (seq.length<50) seq.push(name); }
      });
    } catch(e){ send({type:'fail',name:name,err:e.message}); }
  });
  hooked = true;
  send({type:'hooked', mod:mod.name, base:mod.base.toString()});
}
var poll = setInterval(function(){
  var m = findRenderer();
  if (m) { hookAll(m); clearInterval(poll); }
}, 100);
setTimeout(function(){ send({type:'counts', counts:counts}); send({type:'sequence', seq:seq}); }, 7000);
send({type:'start'});
