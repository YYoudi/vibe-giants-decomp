// frida_diclick_inject.js — DEFINITIVE click injection: hook IDirectInput(8) mouse device's
// GetDeviceState and force rgbButtons[0] |= 0x80 on a schedule. This is the actual DI8 data
// path (bypasses the hardware barrier). Captures the mouse device via DirectInputCreate/CreateEx,
// then hooks its CreateDevice method (vtable idx 3 in DI7/DI8 IDirectInput), then the created
// device's GetDeviceState (vtable idx 9 = offset 0x24).
var t0 = Date.now();
var PRESS_DUR = 0.07, INTERVAL = 1.1, START_AT = 9.0;
function clicking(){
  var t=(Date.now()-t0)/1000; if(t<START_AT) return false;
  var into=t-START_AT; var frac=into - Math.floor(into/INTERVAL)*INTERVAL;
  return frac < PRESS_DUR;
}
function hookDI(dll){
  var mod = Process.findModuleByName(dll);
  if(!mod){ send("[!] no "+dll); return; }
  // DirectInputCreate (DI7) and DirectInputCreateEx / DirectInput8Create (DI8) return IDirectInput*.
  ["DirectInputCreateA","DirectInputCreateW","DirectInputCreateEx","DirectInput8Create"].forEach(function(exp){
    var p = mod.findExportByName(exp);
    if(!p) return;
    Interceptor.attach(p, { onEnter: function(a){ this.outArg = a[ (exp==="DirectInput8Create"?4:3) ]; },
      onLeave: function(r){
        try{
          var ppI = this.outArg; var pI = ppI.readPointer();
          if(pI.isNull()) return;
          var vt = pI.readPointer();
          // CreateDevice = vtable index 3
          var createDevice = vt.add(3*4).readPointer();
          send("[+] "+exp+" IDirectInput="+pI+" CreateDevice="+createDevice);
          Interceptor.attach(createDevice, { onEnter: function(a){ this.devOut=a[2]; },
            onLeave: function(r){
              try{
                var dev = this.devOut.readPointer();
                if(dev.isNull()) return;
                var dvt = dev.readPointer();
                var getState = dvt.add(9*4).readPointer();   // GetDeviceState idx 9
                send("[+] DI device created dev="+dev+" GetDeviceState="+getState);
                Interceptor.attach(getState, { onEnter: function(a){ this.cb=a[1].toInt32(); this.buf=a[2]; },
                  onLeave: function(r){
                    if(r.toInt32()>=0 && this.cb>=20 && clicking()){
                      try{ // rgbButtons[0] is at offset 16 (DI7) in DIMOUSESTATE
                        var b=this.buf.add(16).readU8(); this.buf.add(16).writeU8(b|0x80);
                      }catch(e){}
                    }
                  }});
              }catch(e){ send("[err] cd-leave "+e); }
            }});
        }catch(e){ send("[err] di-leave "+e); }
      }});
    send("[+] hooked "+exp+" @ "+p);
  });
}
hookDI("dinput.dll");
hookDI("dinput8.dll");
// dinput8.dll loads lazily after spawn — poll for it.
var iv=setInterval(function(){ if(Process.findModuleByName("dinput8.dll")){ hookDI("dinput8.dll"); clearInterval(iv); } }, 50);
send("[+] diclick_inject started; clicks from t="+START_AT+"s");
