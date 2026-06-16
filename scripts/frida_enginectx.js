// Frida: observe which engine-context (TextLookupService) vtable methods the
// renderer calls on the original exe, + their args. Hooks the 5 methods by
// original image address (exe base 0x00400000) + UpCallsLoad.
var counts = [0,0,0,0,0];
var names = ['vt0_Release(0x0044DDB0)','vt1_Register(0x00635F80)','vt2_Query(0x00636180)','vt3_Unregister(0x006362D0)','vt4_Clear(0x00636210)'];
var addrs = [0x0044ddb0, 0x00635f80, 0x00636180, 0x006362d0, 0x00636210];

addrs.forEach(function(a, i) {
  try {
    Interceptor.attach(ptr(a), {
      onEnter: function(args) {
        counts[i]++;
        if (counts[i] <= 8) {
          var ecx = this.context.ecx;
          var sp = this.context.esp;
          // thiscall: ECX=this; stack args at esp+4 (param_2), esp+8 (param_3)...
          var guid = null;
          var info = {type:'call', idx:i, name:names[i], n:counts[i], ecx:ecx.toString()};
          try {
            if (i === 1) {
              // Register: param_2 (esp+4) = ptr to GUID struct (16 bytes at *esp+4)
              var gp = sp.add(4).readPointer();
              info.arg2 = gp.toString();
              guid = gp.readByteArray(16);
            } else if (i === 2) {
              // Query: param_3 (esp+8) = POINTER to GUID; FUN_00635d70 derefs it.
              var gp = sp.add(8).readPointer();
              info.arg3 = gp.toString();
              guid = gp.readByteArray(16);
            } else if (i === 3) {
              // Unregister: param_2 (esp+4) = GUID by value
              info.arg2 = sp.add(4).toString();
              guid = sp.add(4).readByteArray(16);
            }
          } catch(e) { info.readErr = e.message; }
          send(info, guid);
        }
      }
    });
    send({type:'hook_ok', idx:i, name:names[i]});
  } catch(e) { send({type:'hook_fail', idx:i, err:e.message}); }
});

// Also hook UpCallsLoad (export of gg_dx9r_orig.dll) — log the 22-addrs table.
try {
  var upc = Module.findExportByName('gg_dx9r_orig.dll', 'UpCallsLoad');
  if (upc) {
    Interceptor.attach(upc, {
      onEnter: function(args) {
        var ver = args[0].toInt32(), cnt = args[1].toInt32(), tbl = args[2];
        send({type:'UpCallsLoad', ver:'0x'+ver.toString(16), cnt:cnt, tbl:tbl.toString()});
      }
    });
    send({type:'hook_ok', name:'UpCallsLoad'});
  } else send({type:'hook_fail', name:'UpCallsLoad not found'});
} catch(e) { send({type:'hook_fail', name:'UpCallsLoad', err:e.message}); }

// On detach, dump counts.
send({type:'start', msg:'hooks installed'});
