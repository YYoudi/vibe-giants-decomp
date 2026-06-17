// Frida (ORIGINAL vanilla Giants_nocd.exe): capture how the working game PRESENTS —
// hook DirectDraw Flip/Blt (ddraw.dll) to find the real present mechanism (the recomp's
// slot+0x60 is just SetRect; the real present must go through ddraw Flip/Blt).
function hookDD() {
  var dd = Process.findModuleByName('ddraw.dll');
  if (!dd) return false;
  ['Flip','Blt','BltFast','UpdateOverlay','GetDC','Lock'].forEach(function (n) {
    var p = dd.findExportByName(n);
    if (!p) return;
    var c = 0;
    Interceptor.attach(p, {
      onEnter: function (a) {
        c++;
        if (c <= 2) {
          // First arg = this (surface). Walk a couple stack-frame returns to see who calls.
          send({ type: 'DD', name: n, call: c, this: a[0].toString(),
                 ret: this.returnAddress ? this.returnAddress.toString() : '?' });
        }
      }
    });
    send({ type: 'hooked', name: n });
  });
  return true;
}
var tries = 0;
var iv = setInterval(function () { tries++; if (hookDD() || tries > 320) clearInterval(iv); }, 50);
send({ type: 'start' });
