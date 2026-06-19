// frida_init_recipe.js — OBSERVE the ORIGINAL's renderer front-table calls from INIT (t=0),
// especially +0x8c (PushViewport/SetRenderTarget) — capture its surf+flags args so the recomp
// can bind the device RT to the presented surface (white-render root cause).
// Frida spawn-gating: script loads before the process runs, so the obj is hooked the moment it
// exists (DAT_00654940 is created during GDVSysCreate) — catching the first +0x8c at init.
var t0 = Date.now();
function ts(){ return (((Date.now()-t0)/1000).toFixed(3)); }
var mod = Process.findModuleByName("Giants_nocd.exe");
if(!mod){ send("[!] no module"); }
else {
  function va(a){ return mod.base.add(a - 0x400000); }
  var pRenderer = va(0x654940);
  var hooked=false;
  var slots = ["0x8c","0x90","0x94","0x98","0x9c","0xa0","0xa4","0xa8","0xb4","0xb8","0xd8"];
  var names = {"0x8c":"SetRT/PushVP","0x90":"BeginScene","0x94":"EndScene","0x98":"Clear",
               "0x9c":"Blt2D","0xa0":"Blt2Dvar","0xa4":"?","0xa8":"Present","0xb4":"ReleaseTex",
               "0xb8":"PopVP/Blt","0xd8":"CreateTex"};
  function hookAll(){
    if(hooked) return;
    var obj = pRenderer.readPointer();
    if(obj.isNull()) return;
    var count = {};
    slots.forEach(function(offHex){
      var off = parseInt(offHex,16);
      var p = obj.add(off).readPointer();
      count[offHex]=0;
      if(p.isNull()) return;
      Interceptor.attach(p, { onEnter: function(a){
        count[offHex] = (count[offHex]||0)+1;
        if(count[offHex] <= 5){
          var args=[];
          for(var i=1;i<=5;i++){ try{ args.push("0x"+a[i].toString(16)); }catch(e){ args.push("?"); } }
          send("["+ts()+"s] +"+offHex+" "+names[offHex]+" #"+count[offHex]+" args="+args.join(","));
        }
      }});
    });
    send("[+] hooked renderer obj="+obj+" at t="+ts()+"s");
    hooked=true;
  }
  var tries=0;
  var iv=setInterval(function(){ if(hookAll()||++tries>600) clearInterval(iv); }, 20);
  send("[+] frida_init_recipe started");
}
