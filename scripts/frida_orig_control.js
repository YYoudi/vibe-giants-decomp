// Frida control of the ORIGINAL Giants_nocd.exe — reliable intro skip + boot timing.
// SendInput-based skipping is fragile (window focus); this replaces the intro player
// FUN_00523b60 so the original deterministically skips intros -> menu/level.
//
// RPC exposed:
//   skipintros() — Interceptor.replace FUN_00523b60 with a stub returning 0.
//                  The whole 3-intro sequence is skipped; FUN_004913c0 still runs
//                  (boot step 14) -> menu/level loads normally.
//
// Also emits a READY message with the module base for address confirmation.

function exeBase() {
  var m = Process.findModuleByName('Giants_nocd.exe') || Process.findModuleByName('Giants.exe');
  return m ? m.base : null;
}

// Keep the NativeCallback alive (GC would undo the replace).
var _skipCb = null;
var skipDone = false;
rpc.exports = {
  // RVA of FUN_00523b60 = 0x523b60 - 0x400000 imagebase = 0x123b60
  skipintros: function () {
    if (skipDone) return true;
    var b = exeBase(); if (!b) { send({type:'ERR', e:'no module'}); return false; }
    var addr = b.add(0x123b60);
    try {
      _skipCb = new NativeCallback(function (arg) { return 0; }, 'int', ['pointer']);
      Interceptor.replace(addr, _skipCb);
      skipDone = true;
      send({type:'OK', msg:'skipIntros replaced @ ' + addr});
      return true;
    } catch (e) { send({type:'ERR', e:''+e}); return false; }
  }
};

send({type:'READY', base: exeBase() ? exeBase().toString() : null});
