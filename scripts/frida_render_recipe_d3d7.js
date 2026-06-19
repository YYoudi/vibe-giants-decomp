// frida_render_recipe_d3d7.js — OBSERVE the ORIGINAL's per-frame D3D7 device recipe at the menu.
// The engine drives a STOCK IDirect3DDevice7 at renderer_obj+0x294 (vtable in D3DIM700.DLL).
// Hooking its SetTransform/SetTexture/DrawPrimitive/SetRenderState captures the FULL render recipe:
//   SetTransform(state, &mat16): state=2 VIEW, 3 PROJECTION, 256+ WORLD  -> reveals the camera VIEW
//   SetTexture(stage, surf), DrawPrimitive(primType, FVF, verts, count), SetRenderState(state, val)
// This is the OBSERVE step required before porting the 3D pipeline. Ground truth, no guessing.
var t0 = Date.now();
function ts(){ return (((Date.now()-t0)/1000).toFixed(3)); }
var mod = Process.findModuleByName("Giants_nocd.exe");
if(!mod){ send("[!] no module"); }
else {
  function va(a){ return mod.base.add(a - 0x400000); }
  var pRenderer = va(0x654940);          // DAT_00654940 = g_vRenderer
  var stateName = {2:"VIEW",3:"PROJ"};   // 256+n = WORLD_n
  var primName = {1:"PT_POINTLIST",2:"PT_LINELIST",3:"PT_LINESTRIP",4:"PT_TRIANGLELIST",5:"PT_TRIANGLESTRIP",6:"PT_TRIANGLEFAN"};
  var hooked=false;
  function hookDevice(){
    if(hooked) return;
    var obj = pRenderer.readPointer();
    if(obj.isNull()) return;
    var dev = obj.add(0x294).readPointer();        // IDirect3DDevice7*
    if(dev.isNull()) return;
    var vt = dev.readPointer();                    // vtable*
    var pSetTransform = vt.add(0x2c).readPointer();
    var pSetTexture   = vt.add(0x8c).readPointer();
    var pDrawPrim     = vt.add(0x64).readPointer();
    var pDrawIdx      = vt.add(0x68).readPointer();   // DrawIndexedPrimitive
    var pDrawVB       = vt.add(0x6c).readPointer();   // DrawPrimitiveVB
    var pDrawIdxVB    = vt.add(0x70).readPointer();   // DrawIndexedPrimitiveVB
    var pSetRS        = vt.add(0x50).readPointer();
    var pBeginScene   = vt.add(0x14).readPointer();
    var pEndScene     = vt.add(0x18).readPointer();
    var pDrawStride   = vt.add(0x78).readPointer();   // DrawPrimitiveStrided
    var pDrawIdxStride= vt.add(0x7c).readPointer();   // DrawIndexedPrimitiveStrided
    send("[+] device="+dev+" vt="+vt+" SetTransform="+pSetTransform+" SetTexture="+pSetTexture+" DrawPrim="+pDrawPrim+" DrawIdx="+pDrawIdx+" DrawVB="+pDrawVB+" DrawIdxVB="+pDrawIdxVB+" DrawStride="+pDrawStride+" SetRS="+pSetRS);

    var nTr=0, nTx=0, nDp=0, nRs=0, nBeg=0;
    var MAX=40;
    var START_AT=33.0;     // skip the 3 intros (~12s each) -> capture the MENU 3D recipe
    function ready(){ return ((Date.now()-t0)/1000) >= START_AT; }

    Interceptor.attach(pBeginScene, { onEnter: function(a){
      if(!ready()) return; nBeg++;
      if(nBeg<=4) send("["+ts()+"s] BeginScene (#"+nBeg+")");
    }});
    Interceptor.attach(pEndScene, { onEnter: function(a){
      if(ready() && nBeg<=4) send("["+ts()+"s] EndScene (#"+nBeg+")");
    }});

    // SetTransform(this __stdcall, State, pMatrix)
    Interceptor.attach(pSetTransform, { onEnter: function(a){
      if(nTr>=200 || !ready()) return;
      var st = a[1].toInt32();
      var mp = a[2];
      var f=[]; try{ for(var i=0;i<16;i++) f.push(mp.add(i*4).readFloat().toFixed(4)); }catch(e){ f.push("?"); }
      var name = stateName[st] || (st>=256?"WORLD"+(st-256):("ST"+st));
      send("["+ts()+"s] SetTransform "+name+" ["+f.join(",")+"]");
      nTr++;
    }});

    // SetTexture(this, stage, IDirectDrawSurface7*)
    Interceptor.attach(pSetTexture, { onEnter: function(a){
      if(nTx>=MAX || !ready()) return;
      send("["+ts()+"s] SetTexture stage="+a[1].toInt32()+" surf="+a[2]);
      nTx++;
    }});

    // DrawPrimitive(this, primType, FVF, verts, count, flags)
    Interceptor.attach(pDrawPrim, { onEnter: function(a){
      if(nDp>=120 || !ready()) return;
      var pt=a[1].toInt32(), fvf=a[2].toString(16), vcount=a[4].toInt32();
      send("["+ts()+"s] DrawPrimitive "+(primName[pt]||pt)+" FVF=0x"+fvf+" verts="+a[3]+" count="+vcount);
      nDp++;
    }});

    // DrawIndexedPrimitive(this, primType, FVF, verts, vertCount, indices, idxCount, flags)
    Interceptor.attach(pDrawIdx, { onEnter: function(a){
      if(nDp>=120 || !ready()) return;
      var pt=a[1].toInt32(), fvf=a[2].toString(16), vc=a[4].toInt32(), ic=a[6].toInt32();
      send("["+ts()+"s] DrawIndexedPrimitive "+(primName[pt]||pt)+" FVF=0x"+fvf+" vCount="+vc+" idxCount="+ic);
      nDp++;
    }});
    // DrawPrimitiveVB(this, primType, vb, startVert, vertCount, flags)
    Interceptor.attach(pDrawVB, { onEnter: function(a){
      if(nDp>=120 || !ready()) return;
      var pt=a[1].toInt32(), vb=a[2], sv=a[3].toInt32(), vc=a[4].toInt32();
      send("["+ts()+"s] DrawPrimitiveVB "+(primName[pt]||pt)+" vb="+vb+" start="+sv+" vCount="+vc);
      nDp++;
    }});
    // DrawIndexedPrimitiveVB(this, primType, vb, startVert, vertCount, indices, idxCount, flags)
    Interceptor.attach(pDrawIdxVB, { onEnter: function(a){
      if(nDp>=120 || !ready()) return;
      var pt=a[1].toInt32(), vb=a[2], sv=a[3].toInt32(), vc=a[4].toInt32(), ic=a[6].toInt32();
      send("["+ts()+"s] DrawIndexedPrimitiveVB "+(primName[pt]||pt)+" vb="+vb+" start="+sv+" vCount="+vc+" idxCount="+ic);
      nDp++;
    }});
    // DrawPrimitiveStrided(this, primType, vertCount, stridedData, FVF, flags)
    Interceptor.attach(pDrawStride, { onEnter: function(a){
      if(nDp>=120 || !ready()) return;
      var pt=a[1].toInt32(), vc=a[2].toInt32(), fvf=a[4].toString(16);
      send("["+ts()+"s] DrawPrimitiveStrided "+(primName[pt]||pt)+" vCount="+vc+" FVF=0x"+fvf);
      nDp++;
    }});
    Interceptor.attach(pDrawIdxStride, { onEnter: function(a){
      if(!ready()) return;
      var pt=a[1].toInt32();
      var vCount=a[4].toInt32();   // dwVertexCount
      // Log big meshes (3D island/logo) fully; only tally the 2D quads.
      if(vCount>50){
        if(nDp<120) send("["+ts()+"s] DrawIdxPrimStrided BIG prim="+(primName[pt]||pt)+" vCount="+vCount+" fvf/raw a2="+a[2]+" a3="+a[3]+" idx="+a[5]+" ic="+a[6]+" fl="+a[7]);
      }
      nDp++;
    }});

    // SetRenderState(this, state, value)
    Interceptor.attach(pSetRS, { onEnter: function(a){
      if(nRs>=MAX) return;
      send("["+ts()+"s] SetRenderState st="+a[1].toInt32()+" val=0x"+a[2].toString(16));
      nRs++;
    }});

    hooked=true;
  }
  var tries=0;
  var iv=setInterval(function(){ if(hookDevice() || ++tries>400) clearInterval(iv); }, 50);
  send("[+] frida_render_recipe_d3d7 started, polling g_vRenderer");
}
