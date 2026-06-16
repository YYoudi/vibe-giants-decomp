// Frida: dump ALL args of gg_dx7r.dll::GDVSysCreate (vanilla) to settle the
// signature (6 vs 9 params) and capture the EXACT dispCfg/winCfg/modeCfg values
// the original passes. Hooks via GetProcAddress (engine resolves at load).
function hexdump16(p, n) {
  try {
    var b = p.readByteArray(n);
    var view = new Uint8Array(b);
    var s = '';
    for (var i=0;i<view.length;i++){ s += ('0'+view[i].toString(16)).slice(-2) + ' '; if ((i&3)===3) s+=' '; }
    return s.trim();
  } catch(e){ return '<' + e.message + '>'; }
}
var hooked = false;
function hookGDV(addr) {
  if (hooked) return; hooked = true;
  Interceptor.attach(addr, {
    onEnter: function(args) {
      // Dump 12 candidate args as raw u32 + classified
      var raw=[]; var cls=[];
      for (var i=0;i<12;i++){
        var v = args[i].toInt32 ? args[i].toInt32() : 0;
        var uv = v>>>0;
        raw.push('0x'+uv.toString(16));
        // classify
        if (uv===0) cls.push('NULL');
        else if (uv < 0x10000) cls.push('int('+v+')');
        else {
          var isStr=false;
          try { var cs=args[i].readCString(8); if (cs && /^[\x20-\x7e]+$/.test(cs)) {cls.push('str"'+cs+'"'); isStr=true;} }catch(e){}
          if(!isStr) cls.push('ptr');
        }
      }
      send({type:'GDV_enter', raw:raw, cls:cls});
      // hexdump the pointer args (candidates 2..8) — these are dispCfg/winCfg/modeCfg structs
      for (var j=1;j<9;j++){
        var vv = args[j].toInt32()>>>0;
        if (vv > 0x10000 && vv < 0x7fffffff) {
          send({type:'GDV_argdump', idx:j, val:'0x'+vv.toString(16), hex:hexdump16(args[j],48)});
        }
      }
      this.hwnd = args[1].toString();
    },
    onLeave: function(r) {
      send({type:'GDV_ret', device:r.toString(), hWnd:this.hwnd});
      // Dump first 0x40 bytes of the returned renderer object to confirm method-table layout
      if (!r.isNull()) {
        send({type:'GDV_obj', hex:hexdump16(r,0x60)});
      }
    }
  });
  send({type:'hooked_GDV', addr:addr.toString()});
}

var gpa=null;
var mods=Process.enumerateModules();
for (var i=0;i<mods.length;i++){
  var mn=mods[i].name.toLowerCase();
  if (mn==='kernel32.dll'||mn==='kernelbase.dll'){ try{gpa=mods[i].findExportByName('GetProcAddress');}catch(e){} if(gpa)break; }
}
Interceptor.attach(gpa, {
  onEnter:function(a){ var p=a[1]; this.n=null; try{ if(p.toUInt32()>0x10000) this.n=p.readCString(); }catch(e){} },
  onLeave:function(rv){ if(this.n==='GDVSysCreate' && !rv.isNull()) hookGDV(rv); }
});
send({type:'start'});
