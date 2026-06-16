// Frida: the GDVSysCreate allocator [base+0x28780] returns NULL in the recomp (only
// early-exit path). Find what it points to, hook it, log args + return value. This
// allocator is a renderer-internal global (NOT an IAT import) — likely set by the
// renderer's DllMain or by UpCallsLoad from one of the 21 engine callbacks.
var allocOff = 0x28780;
function hookAll(base){
  // 1. Read the allocator fn pointer
  try {
    var allocFn = base.add(allocOff).readPointer();
    send({type:'ALLOC_PTR', at:'0x'+(base.add(allocOff)).toString(), fn:allocFn.toString()});
    // Is it inside gg_dx7r.dll? inside exe? an UpCalls callback?
    var mods=Process.enumerateModules();
    var where='unknown';
    for(var i=0;i<mods.length;i++){ var s=mods[i].base.toUInt32(), e=s+mods[i].size; var av=allocFn.toUInt32(); if(av>=s&&av<e) where=mods[i].name+' ('+mods[i].base+')'; }
    send({type:'ALLOC_RESOLVES_TO', where:where});
    Interceptor.attach(allocFn,{
      onEnter:function(a){ this.a0=a[0]; send({type:'ALLOC_call', a0:a[0].toString(), a1:a[1].toString(), a2:a[2].toString()}); },
      onLeave:function(r){ send({type:'ALLOC_ret', ret:r.toString(), NULL:r.isNull()}); }
    });
    send({type:'alloc_hooked'});
  } catch(e){ send({type:'alloc_hookerr', e:e.message}); }
  // 2. Hook GDVSysCreate to confirm NULL + the esi after alloc
  try{ Interceptor.attach(base.add(0x2dc0),{ onEnter:function(){}, onLeave:function(r){ send({type:'GDV_ret', ret:r.toString()}); } }); }catch(e){}
}
var k32=Process.findModuleByName('kernel32.dll')||Process.findModuleByName('kernelbase.dll');
var lla=k32.findExportByName('LoadLibraryA');
Interceptor.attach(lla,{ onEnter:function(a){try{this.n=a[0].readCString();}catch(e){this.n='?';}},
  onLeave:function(r){ if(this.n && this.n.toLowerCase().indexOf('gg_dx7')>=0){ hookAll(r); } }});
send({type:'start'});
