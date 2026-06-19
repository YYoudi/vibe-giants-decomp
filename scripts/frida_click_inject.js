// frida_click_inject.js — force the original to see mouse CLICKS at the logical level
// (bypassing the DI8 hardware barrier that ignores SendInput/PostMessage). The menu/UI often
// polls GetAsyncKeyState(VK_LBUTTON=1) or GetKeyState; hook those to report the button pressed
// on a schedule (press 8 frames, release 8 frames, repeat) — simulating distinct clicks.
var user32 = Process.findModuleByName("user32.dll");
var t0 = Date.now();
function ts(){ return (((Date.now()-t0)/1000).toFixed(3)); }
var VK_LBUTTON = 1;
// schedule: starting at START clicks every ~1.1s for CLICKS clicks
var START_AT = 9.0;
var PRESS_DUR = 0.06;   // 60ms press
var INTERVAL = 1.1;
function clickIdx(){ // -1 = not clicking, else 0..N
  var t = (Date.now()-t0)/1000;
  if (t < START_AT) return -1;
  var into = t - START_AT;
  var n = Math.floor(into / INTERVAL);          // which click
  var frac = into - n*INTERVAL;
  return frac < PRESS_DUR ? n : -1;
}
function hookExp(name, fn){
  var p = user32.findExportByName(name);
  if(!p){ send("[!] no export "+name); return; }
  Interceptor.attach(p, { onLeave: function(r){
    if(this.checked) return;
    var c = clickIdx();
    if(c >= 0){
      // GetAsyncKeyState returns SHORT with high bit set if currently down
      r.replace(ptr(r.toInt32() | 0x8000 | 0x0001));
      this.checked = true;
    }
  }});
  send("[+] hooked "+name+" @ "+p);
}
// GetAsyncKeyState(int vKey) -> force LBUTTON down during a click window
var pGAKS = user32.findExportByName("GetAsyncKeyState");
if(pGAKS){
  Interceptor.attach(pGAKS, { onEnter: function(a){ this.vk=a[0].toInt32(); },
    onLeave: function(r){
      if(this.vk===VK_LBUTTON && clickIdx()>=0){ r.replace(ptr(0x8001)); }
    }});
  send("[+] hooked GetAsyncKeyState");
}
// GetKeyState(int) similarly
var pGKS = user32.findExportByName("GetKeyState");
if(pGKS){
  Interceptor.attach(pGKS, { onEnter: function(a){ this.vk=a[0].toInt32(); },
    onLeave: function(r){
      if(this.vk===VK_LBUTTON && clickIdx()>=0){ r.replace(ptr(0x8001)); }
    }});
  send("[+] hooked GetKeyState");
}
// Also force the cursor into the client center so the click hits the menu area.
// (Done from Python via SetCursorPos; here we just drive the key state.)
send("[+] click_inject started: clicks from t="+START_AT+"s every "+INTERVAL+"s");
