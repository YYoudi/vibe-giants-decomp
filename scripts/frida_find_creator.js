// frida_find_creator.js — find which renderer front-table method CREATES the source handle
// passed to +0xa8 Present. Log each method's FIRST return value (0x00-0x180) + every +0xa8
// source handle. Correlate offline (same-run ASLR): the creator's return == a +0xa8 source.
var t0 = Date.now();
function ts(){ return (((Date.now()-t0)/1000).toFixed(3)); }
var mod = Process.findModuleByName("Giants_nocd.exe");
if(!mod){ send("[!] no module"); }
else {
  function va(a){ return mod.base.add(a - 0x400000); }
  var pRenderer = va(0x654940);
  var hooked=false;
  function hookAll(){
    if(hooked) return;
    var obj = pRenderer.readPointer();
    if(obj.isNull()) return;
    // +0xa8: log every source handle (arg4)
    var pA8 = obj.add(0xa8).readPointer();
    var seenSrc={};
    Interceptor.attach(pA8, { onEnter: function(a){
      var s = a[4];
      if(!s.isNull() && !seenSrc[s]){
        seenSrc[s]=1;
        send("["+ts()+"s] A8SRC handle="+s);
      }
    }});
    // broad range: log FIRST return value per offset
    for (var off = 0; off <= 0x180; off += 4) {
      (function(off){
        var p;
        try { p = obj.add(off).readPointer(); } catch(e){ return; }
        if (p.isNull()) return;
        var logged={};
        try {
          Interceptor.attach(p, {
            onEnter: function(){ this.off=off; },
            onLeave: function(r){
              if(logged[off]) return;
              logged[off]=1;
              if(!r.isNull()) send("["+ts()+"s] RET +0x"+off.toString(16)+" = "+r);
            }
          });
        } catch(e){}
      })(off);
    }
    send("[+] hooked broad front-table (first-return log) + +0xa8, obj="+obj);
    hooked=true;
  }
  var tries=0; var iv=setInterval(function(){ if(hookAll()||++tries>600) clearInterval(iv); },20);
  send("[+] frida_find_creator started");
}
