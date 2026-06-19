// frida_find_creator.js — find which renderer front-table method CREATES the source handle
// passed to +0xa8 Present (e.g. 0xf8e7510). Hook a broad range of front-table methods (0x00-0x180),
// log onLeave return values, grep for the handle prefix (0xf8e7). Also log +0xa8's arg4 (source).
var t0 = Date.now();
function ts(){ return (((Date.now()-t0)/1000).toFixed(3)); }
var mod = Process.findModuleByName("Giants_nocd.exe");
if(!mod){ send("[!] no module"); }
else {
  function va(a){ return mod.base.add(a - 0x400000); }
  var pRenderer = va(0x654940);
  var hooked=false;
  var targetPrefix = null;   // learned from first +0xa8 arg4
  function hookAll(){
    if(hooked) return;
    var obj = pRenderer.readPointer();
    if(obj.isNull()) return;
    // hook +0xa8 to learn the source handle prefix
    var pA8 = obj.add(0xa8).readPointer();
    Interceptor.attach(pA8, { onEnter: function(a){
      if(!targetPrefix && !a[4].isNull()){
        targetPrefix = a[4].and(ptr("0xFFFF0000"));
        send("["+ts()+"s] +0xa8 source handle="+a[4]+" prefix="+targetPrefix);
      }
    }});
    // hook a broad front-table range, log returns matching the prefix
    var found={};
    for (var off = 0; off <= 0x180; off += 4) {
      (function(off){
        var p;
        try { p = obj.add(off).readPointer(); } catch(e){ return; }
        if (p.isNull()) return;
        try {
          Interceptor.attach(p, { onLeave: function(r){
            if (!targetPrefix) return;
            if (r.isNull()) return;
            try {
              if (r.and(ptr("0xFFFF0000")).equals(targetPrefix) && !found[off]) {
                found[off] = 1;
                send("["+ts()+"s] CREATOR? +0x"+off.toString(16)+" returns "+r+" (matches +0xa8 source prefix)");
              }
            } catch(e){}
          }});
        } catch(e){}
      })(off);
    }
    send("[+] hooked broad front-table 0x00-0x180 + +0xa8, obj="+obj);
    hooked=true;
  }
  var tries=0; var iv=setInterval(function(){ if(hookAll()||++tries>600) clearInterval(iv); },20);
  send("[+] frida_find_creator started");
}
