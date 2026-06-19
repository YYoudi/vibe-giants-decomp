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
    ["0xd8","0xb4","0xa8"].forEach(function(offHex){
      var off=parseInt(offHex,16);
      var p=obj.add(off).readPointer();
      if(p.isNull()) return;
      var cnt={n:0};
      Interceptor.attach(p,{ onEnter:function(a){
        cnt.n++;
        if(cnt.n>6) return;
        var args=[];
        for(var i=1;i<=7;i++){ try{ args.push("0x"+a[i].toString(16)); }catch(e){ args.push("?"); } }
        // for +0xd8, try to read the source dims if arg looks like a ptr to data
        send("["+ts()+"s] +"+offHex+" #"+cnt.n+" args(1..7)="+args.join(","));
      }, onLeave:function(r){
        if(cnt.n<=6) send("["+ts()+"s] +"+offHex+" #"+cnt.n+" RET=0x"+r.toString(16));
      }});
    });
    send("[+] hooked +0xd8/+0xb4/+0xa8 obj="+obj);
    hooked=true;
  }
  var tries=0; var iv=setInterval(function(){ if(hookAll()||++tries>600) clearInterval(iv); },20);
  send("[+] frida_createtex started");
}
