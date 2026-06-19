// frida_intro_recipe.js — OBSERVE the ORIGINAL's renderer front-table 2D recipe during INTROS
// (auto-play at boot, no clicks needed). The renderer drives 2D via front-table methods
// (+0x8c SetRT/PushVP, +0x98 Clear, +0x90 BeginScene, +0x9c/+0xa0 2D Blt quads, +0xa8 Present) —
// NOT device-direct DrawPrimitive. This is the faithful 2D path that reaches the presented surface.
var t0 = Date.now();
function ts(){ return (((Date.now()-t0)/1000).toFixed(3)); }
var mod = Process.findModuleByName("Giants_nocd.exe");
if(!mod){ send("[!] no module"); }
else {
  function va(a){ return mod.base.add(a - 0x400000); }
  var pRenderer = va(0x654940);          // DAT_00654940 = g_vRenderer
  var START_AT = 2.0;                     // intros auto-play at boot
  function ready(){ return ((Date.now()-t0)/1000) >= START_AT; }
  var hooked=false;
  function hookAll(){
    if(hooked) return;
    var obj = pRenderer.readPointer();
    if(obj.isNull()) return;
    // renderer front-table method pointers (read from obj+offset)
    var slots = {0x8c:"SetRT/PushVP", 0x90:"BeginScene", 0x98:"Clear", 0x9c:"Blt2D",
                 0xa0:"Blt2Dvar", 0xa8:"Present", 0x94:"EndScene", 0xb4:"ReleaseTex", 0xd8:"CreateTex"};
    var count = {0x8c:0,0x90:0,0x98:0,0x9c:0,0xa0:0,0xa8:0};
    Object.keys(slots).forEach(function(offHex){
      var off = parseInt(offHex,16);
      var p = obj.add(off).readPointer();
      if(p.isNull()) return;
      Interceptor.attach(p, { onEnter: function(a){
        if(!ready()) return;
        count[off] = (count[off]||0)+1;
        // log first few of each + arg dump (cdecl: a0=this(obj), a1.. args)
        if(count[off] <= 4){
          var args=[];
          for(var i=1;i<=6;i++){ try{ args.push("0x"+a[i].toString(16)); }catch(e){ args.push("?"); } }
          send("["+ts()+"s] renderer+"+offHex+" "+slots[offHex]+" #"+count[off]+" args="+args.join(","));
        }
      }});
    });
    send("[+] hooked renderer front-table slots, obj="+obj);
    hooked=true;
  }
  var tries=0;
  var iv=setInterval(function(){ if(hookAll()||++tries>400) clearInterval(iv); }, 50);
  send("[+] frida_intro_recipe started");
}
