// Frida (original vanilla): capture the EXACT init+render recipe the engine drives on
// the DX7 renderer object. Hooks GDVSysCreate (via GetProcAddress) to grab the object,
// then hooks every method-table slot (RVAs from GDVSysCreate disasm). Logs call order:
// method-offset + this + first 3 args. Reveals which methods are init (one-shot) vs
// per-frame, and their arg patterns — the recipe the recomp must reproduce.
var METH = {
  '0x04':'m04','0x08':'m08','0x0c':'m0c','0x10':'m10','0x14':'m14','0x18':'m18','0x1c':'m1c',
  '0x20':'m20','0x24':'m24','0x28':'m28','0x2c':'m2c','0x30':'m30','0x34':'m34','0x38':'m38',
  '0x3c':'m3c','0x40':'m40','0x44':'m44','0x48':'m48','0x4c':'m4c','0x50':'m50','0x54':'m54',
  '0x58':'m58','0x5c':'m5c','0x60':'m60','0x64':'m64','0x68':'m68','0x6c':'m6c','0x70':'m70',
  '0x74':'m74','0x78':'m78','0x7c':'m7c','0x80':'m80','0x84':'m84','0x88':'m88','0x8c':'m8c',
  '0x90':'m90','0x94':'m94','0x98':'m98','0x9c':'m9c','0xa0':'mA0','0xa4':'mA4','0xa8':'mA8',
  '0xac':'mAC','0xb0':'mB0','0xb4':'mB4','0xb8':'mB8','0xbc':'mBC','0xc0':'mC0','0xc4':'mC4',
  '0xc8':'mC8','0xcc':'mCC','0xd0':'mD0','0xd4':'mD4','0xd8':'mD8','0xdc':'mDC','0xe0':'mE0'
};
var seq=[]; var counts={}; var hooked=false; var base=null;
function hookMethods(mod){
  if(hooked) return; hooked=true; base=mod.base;
  Object.keys(METH).forEach(function(offHex){
    var off=parseInt(offHex,16);
    try{
      // read the method pointer at obj+off — but we don't have obj yet. Instead hook by
      // RVA: the method table stores fixed RVAs (0x10003090 etc). Hook each unique RVA.
    }catch(e){}
  });
  // The method RVAs (from disasm) — hook each. They're called as thiscall (ECX=obj).
  var rvas=[0x3090,0x42c0,0x3490,0x2d80,0x42d0,0x3e60,0x3ea0,0x3ee0,0x3f90,0x3fe0,0x4000,
    0x4020,0x4040,0x4130,0x4070,0x4120,0x4200,0x4240,0x4180,0x2d40,0x4270,0x4290,0x42f0,
    0xc880,0xc9d0,0xc900,0xc970,0x79c0,0x7bc0,0x7aa0,0x7370,0x73e0,0x7910,0xaba0,0x86a0,
    0x87a0,0x87e0,0x8810,0x8890,0x8910,0x8990,0x84d0,0xc030,0xc6a0,0xacf0,0xae60,0xae80,
    0x7870,0x7950,0x76e0,0x77d0,0x7f20,0x7bf0,0x7c00,0x7be0];
  // map RVA -> offset (for labeling) by reading which slot stored it
  var rva2off={};
  Object.keys(METH).forEach(function(offHex){
    // we don't have slot->rva mapping handy; label by RVA hex instead
  });
  var seen={};
  rvas.forEach(function(rva){
    if(seen[rva])return; seen[rva]=1;
    var addr=base.add(rva);
    try{
      Interceptor.attach(addr,{ onEnter:function(a){
        counts[rva]=(counts[rva]||0)+1;
        if(seq.length<120){
          seq.push('rva='+('0x'+rva.toString(16))+' this='+a[0].toString()+' a1='+a[1].toString()+' a2='+a[2].toString()+' a3='+a[3].toString());
        }
      }});
    }catch(e){}
  });
  send({type:'methods_hooked', base:base.toString(), n:rvas.length});
}
var gpa=null;
var mods=Process.enumerateModules();
for(var i=0;i<mods.length;i++){var mn=mods[i].name.toLowerCase(); if(mn==='kernel32.dll'||mn==='kernelbase.dll'){try{gpa=mods[i].findExportByName('GetProcAddress');}catch(e){}if(gpa)break;}}
Interceptor.attach(gpa,{ onEnter:function(a){var p=a[1];this.n=null;try{if(p.toUInt32()>0x10000)this.n=p.readCString();}catch(e){}},
  onLeave:function(r){ if(this.n==='GDVSysCreate' && !r.isNull()){ var mod=Process.findModuleByName('gg_dx7r.dll'); if(mod) hookMethods(mod); } }});
setTimeout(function(){ send({type:'SEQ',seq:seq}); send({type:'COUNTS',counts:counts}); }, 9000);
send({type:'start'});
