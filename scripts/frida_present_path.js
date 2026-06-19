// frida_present_path.js — OBSERVE the ORIGINAL's device render-target value (crash-safe).
// Hooks the device's GetRenderTarget passively (onLeave reads the out-param the original itself
// fills) + the renderer Present (obj+0xa8). No self-invoked NativeFunction calls (those crash).
// Goal: learn the original's device-RT and compare to obj+0x28c — does the original draw to the
// same surface it presents? (the recomp's mismatch is the white-render root cause).
var t0 = Date.now();
function ts(){ return (((Date.now()-t0)/1000).toFixed(3)); }
var mod = Process.findModuleByName("Giants_nocd.exe");
if(!mod){ send("[!] no module"); }
else {
  function va(a){ return mod.base.add(a - 0x400000); }
  var pRenderer = va(0x654940);
  var START_AT = 2.0;
  function ready(){ return ((Date.now()-t0)/1000) >= START_AT; }
  var hooked=false, nRT=0;
  function hookAll(){
    if(hooked) return;
    var obj = pRenderer.readPointer();
    if(obj.isNull()) return;
    var dev = obj.add(0x294).readPointer();
    if(dev.isNull()) return;
    var dvt = dev.readPointer();
    var pGetRT = dvt.add(0x24).readPointer();   // GetRenderTarget
    var pPresent = obj.add(0xa8).readPointer(); // renderer Present
    // passive GetRenderTarget hook: the original fills *(arg2) = the RT surface
    Interceptor.attach(pGetRT, {
      onEnter: function(a){ this.outp = a[2]; },
      onLeave: function(r){
        if(!ready() || nRT>=3) return;
        var devRT = this.outp.readPointer();
        send("["+ts()+"s] ORIG GetRenderTarget -> device-RT="+devRT+" obj+0x28c="+obj.add(0x28c).readPointer()+" obj+0x288="+obj.add(0x288).readPointer()+" match28c="+(devRT.equals(obj.add(0x28c).readPointer())?1:0));
        nRT++;
      }
    });
    var nP=0;
    Interceptor.attach(pPresent, { onEnter: function(a){ if(!ready())return; if(nP<3){ send("["+ts()+"s] ORIG renderer Present(obj+0xa8) called"); nP++; } }});
    send("[+] hooked GetRT + Present, obj="+obj+" dev="+dev);
    hooked=true;
  }
  var tries=0;
  var iv=setInterval(function(){ if(hookAll()||++tries>400) clearInterval(iv); }, 50);
  send("[+] frida_present_path started");
}
