// Frida: capture vanilla DX7 per-frame render sequence — hook the GDVSysCreate-set
// renderer object method functions (count which the engine calls + first-frame order).
var base = null;
var methods = {
  '0x3090':0x3090,'0x42c0':0x42c0,'0x3490':0x3490,'0x2d80':0x2d80,'0x42d0':0x42d0,
  '0x3e60':0x3e60,'0x3ea0':0x3ea0,'0x3ee0':0x3ee0,'0x3f90':0x3f90,'0x3fe0':0x3fe0,
  '0x4000':0x4000,'0x4020':0x4020,'0x4040':0x4040,'0x4130':0x4130,'0x4070':0x4070,
  '0x4120':0x4120,'0x4200':0x4200,'0x4240':0x4240,'0x4180':0x4180,'0x2d40':0x2d40,
  '0x4270':0x4270,'0x4290':0x4290,'0x42f0':0x42f0,'0xc880':0xc880,'0xc9d0':0xc9d0,
  '0xc900':0xc900,'0xc970':0xc970,'0x79c0':0x79c0,'0x7bc0':0x7bc0,'0x7aa0':0x7aa0,
  '0x7370':0x7370,'0x73e0':0x73e0,'0x7910':0x7910,'0xaba0':0xaba0,'0x86a0':0x86a0,
  '0x87a0':0x87a0,'0x87e0':0x87e0
};
var counts={}; var seq=[]; var hooked=false;
Object.keys(methods).forEach(function(k){counts[k]=0;});
function findMod(){var m=Process.enumerateModules();for(var i=0;i<m.length;i++)if(m[i].name.toLowerCase().indexOf('gg_dx7')>=0)return m[i];return null;}
function go(mod){
  if(hooked)return; hooked=true;
  Object.keys(methods).forEach(function(k){
    try{ Interceptor.attach(mod.base.add(methods[k]),{onEnter:function(){counts[k]++; if(seq.length<60)seq.push(k);}}); }catch(e){}
  });
  send({type:'hooked', base:mod.base.toString()});
}
var p=setInterval(function(){var m=findMod(); if(m){go(m); clearInterval(p);}},50);
setTimeout(function(){send({type:'counts',counts:counts}); send({type:'seq',seq:seq});},8000);
send({type:'start'});
