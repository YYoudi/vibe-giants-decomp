// Frida: capture the VANILLA DX7 renderer contract by hooking GetProcAddress —
// the moment the engine resolves GDVSysCreate/UpCallsLoad we attach to them,
// BEFORE the engine calls them. Dumps UpCallsLoad(version,count,table) + the
// callbacks, and GDVSysCreate args + the engine-context (NO COM registry in DX7).
var done = {GDVSysCreate:false, UpCallsLoad:false};
function hookExport(addr, name) {
  if (done[name]) return; done[name]=true;
  send({type:'hooking', name:name, addr:addr.toString()});
  if (name === 'UpCallsLoad') {
    Interceptor.attach(addr, {
      onEnter: function(args) {
        var ver=args[0].toInt32(), cnt=args[1].toInt32(), tbl=args[2];
        var ptrs=[];
        for (var i=0;i<Math.min(cnt,32);i++) ptrs.push(tbl.add(i*4).readPointer().toString());
        send({type:'UpCallsLoad', ver:'0x'+(ver>>>0).toString(16), count:cnt, table:tbl.toString(), callbacks:ptrs});
      }
    });
  } else { // GDVSysCreate(cmdLine, hWnd, dispCfg, winCfg, modeCfg, engineCtx)
    Interceptor.attach(addr, {
      onEnter: function(args) {
        var ec=args[5];
        var info={type:'GDVSysCreate', cmdLine:args[0].readCString(), hWnd:args[1].toString(), engineCtx:ec.toString()};
        try {
          var vt=ec.readPointer(); info.vtable=vt.toString();
          var f=[]; for (var i=1;i<=8;i++) f.push(ec.add(i*4).readU32().toString(16)); info.fields=f;
          if (vt.toUInt32()>0x10000) {
            var sl=[]; for (var j=0;j<24;j++){ try{ sl.push(vt.add(j*4).readPointer().toString()); }catch(e){ sl.push('?'); } }
            info.vtableSlots=sl;
          }
        } catch(e){ info.dumpErr=e.message; }
        send(info);
      },
      onLeave: function(r){ send({type:'GDVSysCreate_ret', device:r.toString()}); }
    });
  }
}
// Hook GetProcAddress to catch resolution of the renderer exports.
var gpa = null;
var mods = Process.enumerateModules();
for (var i=0;i<mods.length;i++) {
  var mn = mods[i].name.toLowerCase();
  if (mn === 'kernel32.dll' || mn === 'kernelbase.dll') {
    try { gpa = mods[i].findExportByName('GetProcAddress'); } catch(e){}
    if (gpa) break;
  }
}
Interceptor.attach(gpa, {
  onEnter: function(args) {
    // GetProcAddress(hModule, lpProcName) — args[1] is a string ptr OR an ordinal.
    var p = args[1];
    this.lpName = null;
    try {
      if (p.toUInt32() > 0x10000) this.lpName = p.readCString();
    } catch(e) { this.lpName = null; }
  },
  onLeave: function(retval) {
    if (this.lpName && (this.lpName==='GDVSysCreate' || this.lpName==='UpCallsLoad') && !retval.isNull()) {
      hookExport(retval, this.lpName);
    }
  }
});
// Also check if the module is already loaded (resume case) and the engine resolves
// by ordinal — guard by also hooking LoadLibraryA result.
send({type:'start', gpa:gpa?gpa.toString():'?'});
