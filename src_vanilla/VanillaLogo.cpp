// Giants Vanilla-Native Recomp — menu 3D logo render via D3D7 3D pipeline. See VanillaLogo.h.
#include "VanillaLogo.h"
#include "VanillaEngine.h"          // g_vRenderer
#include "VanillaGBS.h"
#include "VanillaVFS.h"
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

extern "C" FILE* g_vTrace;
extern "C" void VanillaD3D7_BindTga(void* device, const char* gzpPath, const char* tgaName,
                                    void** pCacheSurf, int* pTried);

static void trace(const char* fmt, ...) {
    if (!g_vTrace) return;
    va_list ap; va_start(ap, fmt); vfprintf(g_vTrace, fmt, ap); va_end(ap);
    fputc('\n', g_vTrace); fflush(g_vTrace);
}

typedef float Mtx[16];
struct Vec3 { float x, y, z; };
static void mtxLookAtLH(Mtx m, Vec3 eye, Vec3 at, Vec3 up) {
    Vec3 z = { at.x-eye.x, at.y-eye.y, at.z-eye.z };
    float zl = z.x*z.x+z.y*z.y+z.z*z.z; float zis = (zl>0?1.0f/std::sqrt(zl):0);
    z.x*=zis; z.y*=zis; z.z*=zis;
    Vec3 c = { up.y*z.z-up.z*z.y, up.z*z.x-up.x*z.z, up.x*z.y-up.y*z.x };
    Vec3 a = { c.y*z.z-c.z*z.y, c.z*z.x-c.x*z.z, c.x*z.y-c.y*z.x };
    float cl=a.x*a.x+a.y*a.y+a.z*a.z; float cis=(cl>0?1.0f/std::sqrt(cl):0);
    a.x*=cis; a.y*=cis; a.z*=cis; c.x=a.y*z.z-a.z*z.y; c.y=a.z*z.x-a.x*z.z; c.z=a.x*z.y-a.y*z.x;
    m[0]=a.x; m[1]=c.x; m[2]=z.x; m[3]=0;
    m[4]=a.y; m[5]=c.y; m[6]=z.y; m[7]=0;
    m[8]=a.z; m[9]=c.z; m[10]=z.z; m[11]=0;
    m[12]=-(a.x*eye.x+a.y*eye.y+a.z*eye.z);
    m[13]=-(c.x*eye.x+c.y*eye.y+c.z*eye.z);
    m[14]=-(z.x*eye.x+z.y*eye.y+z.z*eye.z);
    m[15]=1;
}
static void mtxPerspectiveFovLH(Mtx m, float fovy, float aspect, float zn, float zf) {
    float yScale = 1.0f / std::tan(fovy * 0.5f);
    float xScale = yScale / aspect;
    std::memset(m, 0, sizeof(Mtx));
    m[0]=xScale; m[5]=yScale; m[10]=zf/(zf-zn); m[11]=1.0f; m[14]=-(zn*zf)/(zf-zn);
}

// Cached parsed model + texture cache slot.
static VanillaGBS::Model g_logo;
static bool g_parsed = false;
static void* g_logoTex = nullptr;
static int   g_logoTexTried = 0;

extern "C" int VanillaLogo_Draw() {
    if (!g_vRenderer) { trace("[VLOGO] no renderer"); return 0; }
    void** obj = (void**)g_vRenderer;
    void* wrapper = obj[0x294 / 4];
    if (!wrapper) { trace("[VLOGO] wrapper@obj+0x294 NULL"); return 0; }
    void** wvt = *(void***)wrapper;
    if (!wvt) { trace("[VLOGO] wrapper vtable NULL"); return 0; }

    // Parse the logo model once.
    if (!g_parsed) {
        g_parsed = true;
        auto data = VanillaVFS::GzpReadFile("Bin\\xx_giants_logo_3d.gzp", "Giants_logo_3D.gbs");
        if (data.empty()) { trace("[VLOGO] Giants_logo_3D.gbs not found"); return 0; }
        g_logo = VanillaGBS::Parse(data.data(), data.size());
        if (!g_logo.ok) { trace("[VLOGO] gbs parse failed magic=%08x", g_logo.magic); return 0; }
        trace("[VLOGO] parsed: verts=%u nverts=%u subobjs=%u bbox x[%.1f..%.1f] y[%.1f..%.1f] z[%.1f..%.1f]",
              g_logo.numVertices, g_logo.nverts, g_logo.numSubObjects,
              g_logo.bboxMin[0], g_logo.bboxMax[0], g_logo.bboxMin[1], g_logo.bboxMax[1],
              g_logo.bboxMin[2], g_logo.bboxMax[2]);
    }
    if (!g_logo.ok) return 0;

    size_t vcount = 0;
    std::vector<float> verts = g_logo.buildTexturedTris(&vcount);
    if (vcount == 0) { trace("[VLOGO] buildTexturedTris empty"); return 0; }

    // Camera framed on the bbox. Logo is thin in Y → face is in XZ plane → camera looks along -Y.
    float cx = (g_logo.bboxMin[0]+g_logo.bboxMax[0])*0.5f;
    float cy = (g_logo.bboxMin[1]+g_logo.bboxMax[1])*0.5f;
    float cz = (g_logo.bboxMin[2]+g_logo.bboxMax[2])*0.5f;
    float w = g_logo.bboxMax[0]-g_logo.bboxMin[0];
    float fov = 0.55f;  // ~31deg
    float dist = (w*0.5f) / std::tan(fov*0.5f) * 1.15f;
    Mtx view, proj; float ident[16]={1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1};
    mtxLookAtLH(view, {cx, cy-dist, cz}, {cx, cy, cz}, {0.f, 0.f, 1.f});
    mtxPerspectiveFovLH(proj, fov, 640.f/480.f, 1.f, 4000.f);

    typedef long (__stdcall *PFN_SX)(void*, uint32_t, const float*);
    typedef long (__stdcall *PFN_SR)(void*, uint32_t, uint32_t);
    typedef long (__stdcall *PFN_SL)(void*, uint32_t, const void*);
    typedef long (__stdcall *PFN_LE)(void*, uint32_t, uint32_t);
    typedef long (__stdcall *PFN_STSS)(void*, uint32_t, uint32_t, uint32_t);
    typedef long (__stdcall *PFN_DP)(void*, uint32_t, uint32_t, const void*, uint32_t, uint32_t);
    PFN_SX sx = (PFN_SX)(uintptr_t)wvt[0x2c/4];
    PFN_SR sr = (PFN_SR)(uintptr_t)wvt[0x50/4];
    PFN_SL sl = (PFN_SL)(uintptr_t)wvt[0x48/4];
    PFN_LE le = (PFN_LE)(uintptr_t)wvt[0xb0/4];
    PFN_STSS stss = (PFN_STSS)(uintptr_t)wvt[0x94/4];
    PFN_DP dp = (PFN_DP)(uintptr_t)wvt[0x64/4];

    if (sx) { sx(wrapper, 256, ident); sx(wrapper, 2, view); sx(wrapper, 3, proj); }
    // lighting + ambient (DX7 XYZ verts always go through lighting)
    static bool lit = false;
    if (!lit) { lit = true;
        if (sr) { sr(wrapper, 22, 1); sr(wrapper, 7, 1); sr(wrapper, 14, 1); sr(wrapper, 139, 0xFFFFFFFF); }
        struct D3DL7 { uint32_t t; float d[3]; float da; float s[3]; float sa; float a[3]; float aa;
            float p[3]; float dir[3]; float range; float fall; float a0,a1,a2; float th,ph; };
        D3DL7 lt = {1, {1,1,1},1, {0,0,0},0, {0.8f,0.8f,0.8f},1, {0,0,0}, {0,-0.7f,-0.5f}, 100000,0, 1,0,0, 0,0};
        if (sl) sl(wrapper, 0, &lt);
        if (le) le(wrapper, 0, 1);
    }
    // texture stage: MODULATE (texture × vertex diffuse) — the original's recipe (COLOROP=MODULATE).
    VanillaD3D7_BindTga(wrapper, "Bin\\xx_giants_logo_3d.gzp", "Giants_logo_512.tga",
                        &g_logoTex, &g_logoTexTried);
    if (stss) { stss(wrapper, 0, 1 /*D3DTSS_COLOROP*/, 2 /*D3DTOP_MODULATE*/);
                 stss(wrapper, 0, 4 /*COLORARG1*/, 2 /*TEXTURE*/);
                 stss(wrapper, 0, 5 /*COLORARG2*/, 0 /*CURRENT=diffuse*/); }

    long hr = dp ? dp(wrapper, 3 /*TRIANGLELIST*/, 0x142 /*XYZ|DIFFUSE|TEX1*/,
                      verts.data(), (uint32_t)vcount, 0) : -1;
    trace("[VLOGO] DrawPrimitive: %zu verts (%zu tris) hr=0x%lx", vcount, vcount/3, (unsigned long)hr);
    return (int)(vcount / 3);
}
