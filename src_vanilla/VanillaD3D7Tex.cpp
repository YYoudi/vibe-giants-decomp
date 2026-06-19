// Vanilla-Native Recomp — D3D7 texture creation + device SetTexture.
// Applies the MEASURED render oracle (behavior_specs/menu_render_d3d7_trace.md):
// the original binds textures via IDirect3DDevice7::SetTexture (vtable slot 0x8c).
// The recomp's manual bracket never called it (used the renderer's internal +0xb4
// BindTexture, which only takes effect in the renderer's OWN scene walk). This
// helper creates a real IDirectDrawSurface7 texture from intro_grnd.tga pixels and
// calls device->SetTexture(stage 0, surface) — the exact mechanism the original uses.
//
// All COM access via raw vtable indices (DX7 device/surface/dd7 are __stdcall COM).
// Indices from d3d.h / ddraw.h (see RE_docs/DX7_D3D7_VTABLE_AUTHORITATIVE.md):
//   device GetRenderTarget=0x24, SetTexture=0x8c
//   surface GetDDInterface=0x90, Lock=0x64, Unlock=0x80, Release=0x08
//   dd7     CreateSurface=0x18
#include <windows.h>
#include <ddraw.h>
#include <cstdio>
#include <cstdint>
#include <vector>
#include "VanillaVFS.h"
#include "VanillaTGA.h"

extern "C" FILE* g_vTrace;

// Raw COM vtable typedefs (__stdcall; this is the implicit 1st arg).
typedef long (__stdcall *PFN_GetRT)(void*, void**);
typedef long (__stdcall *PFN_GetDDI)(void*, void**);
typedef long (__stdcall *PFN_CreateSurf)(void*, DDSURFACEDESC2*, void**, void*);
typedef long (__stdcall *PFN_Lock)(void*, void*, DDSURFACEDESC2*, uint32_t, void*);
typedef long (__stdcall *PFN_Unlock)(void*, void*);
typedef long (__stdcall *PFN_SetTex)(void*, uint32_t, void*);

static inline void** vt(void* obj) { return *(void***)obj; }

// Cached texture surface (created once, reused every frame).
static void* g_introGrndSurf = nullptr;
static int   g_introGrndTried = 0;

// Generic: create (once, cached in *pCache) + bind a TGA texture from a GZP to stage 0.
// Mirrors the original's IDirect3DDevice7::SetTexture@0x8c mechanism. Reused by terrain
// (intro_grnd) and the logo (Giants_logo_512). pCache/pTried are the caller's per-texture slots.
extern "C" void VanillaD3D7_BindTga(void* device, const char* gzpPath, const char* tgaName,
                                    void** pCacheSurf, int* pTried) {
    if (!device || !gzpPath || !tgaName || !pCacheSurf || !pTried) return;
    void** dvt = vt(device);
    if (!dvt) return;

    if (!*pCacheSurf && !*pTried) {
        *pTried = 1;
        auto gz = VanillaVFS::GzpReadFile(gzpPath, tgaName);
        VanillaTGA::Image img = gz.empty() ? VanillaTGA::Image{} : VanillaTGA::Parse(gz.data(), gz.size());
        if (!img.ok || img.pixels.empty()) {
            if (g_vTrace) { fprintf(g_vTrace, "[D3D7TEX] %s load FAILED ok=%d\n", tgaName, (int)img.ok); fflush(g_vTrace); }
            return;
        }
        if (g_vTrace) { fprintf(g_vTrace, "[D3D7TEX] %s %ux%u bpp=%u\n", tgaName, img.width, img.height, img.bitsPerPixel); fflush(g_vTrace); }

        void* rt = nullptr;
        ((PFN_GetRT)dvt[0x24/4])(device, &rt);
        if (!rt) { if (g_vTrace) { fprintf(g_vTrace, "[D3D7TEX] GetRenderTarget NULL\n"); fflush(g_vTrace); } return; }
        void* dd7 = nullptr;
        ((PFN_GetDDI)vt(rt)[0x90/4])(rt, &dd7);
        ((long(__stdcall*)(void*))vt(rt)[0x08/4])(rt);
        if (!dd7) { if (g_vTrace) { fprintf(g_vTrace, "[D3D7TEX] GetDDInterface NULL\n"); fflush(g_vTrace); } return; }

        DDSURFACEDESC2 desc = {};
        desc.dwSize = sizeof(desc);
        desc.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT | DDSD_PIXELFORMAT | DDSD_TEXTURESTAGE;
        desc.dwWidth = img.width; desc.dwHeight = img.height;
        desc.ddsCaps.dwCaps = DDSCAPS_TEXTURE;
        desc.ddsCaps.dwCaps2 = DDSCAPS2_TEXTUREMANAGE;
        desc.ddpfPixelFormat.dwSize = sizeof(desc.ddpfPixelFormat);
        desc.ddpfPixelFormat.dwFlags = DDPF_RGB;
        desc.ddpfPixelFormat.dwRGBBitCount = 32;
        desc.ddpfPixelFormat.dwRBitMask = 0x00FF0000;
        desc.ddpfPixelFormat.dwGBitMask = 0x0000FF00;
        desc.ddpfPixelFormat.dwBBitMask = 0x000000FF;
        void* texSurf = nullptr;
        long hr = ((PFN_CreateSurf)vt(dd7)[0x18/4])(dd7, &desc, &texSurf, nullptr);
        ((long(__stdcall*)(void*))vt(dd7)[0x08/4])(dd7);
        if (hr != 0 || !texSurf) {
            if (g_vTrace) { fprintf(g_vTrace, "[D3D7TEX] CreateSurface FAILED hr=0x%lx\n", (unsigned long)hr); fflush(g_vTrace); }
            return;
        }
        if (g_vTrace) { fprintf(g_vTrace, "[D3D7TEX] texture surface created %p\n", texSurf); fflush(g_vTrace); }

        DDSURFACEDESC2 lk = {}; lk.dwSize = sizeof(lk);
        hr = ((PFN_Lock)vt(texSurf)[0x64/4])(texSurf, nullptr, &lk, 0, nullptr);
        if (g_vTrace) { fprintf(g_vTrace, "[D3D7TEX] %s Lock hr=0x%lx lpSurface=%p pitch=%d\n", tgaName, (unsigned long)hr, lk.lpSurface, (int)lk.lPitch); fflush(g_vTrace); }
        if (hr == 0 && lk.lpSurface) {
            uint8_t* dst = (uint8_t*)lk.lpSurface;
            const uint8_t* src = img.pixels.data();
            int srcBpp = img.bitsPerPixel / 8;
            for (uint32_t y = 0; y < img.height; y++) {
                uint8_t* drow = dst + y * lk.lPitch;
                const uint8_t* srow = src + y * img.width * srcBpp;
                for (uint32_t x = 0; x < img.width; x++) {
                    drow[x*4+0] = srow[x*srcBpp+0]; drow[x*4+1] = srow[x*srcBpp+1];
                    drow[x*4+2] = srow[x*srcBpp+2]; drow[x*4+3] = 0xFF;
                }
            }
            if (g_vTrace) {  // dump center pixels (where the logo is) src + dst BEFORE unlock
                uint32_t cx = img.width/2, cy = img.height/2;
                const uint8_t* s = src + (cy*img.width + cx)*srcBpp;
                uint8_t* d = dst + cy*lk.lPitch + cx*4;
                fprintf(g_vTrace, "[D3D7TEX] %s copy center(%u,%u): src=", tgaName, cx, cy);
                for (int i = 0; i < 6; i++) fprintf(g_vTrace, " %02x%02x%02x", s[i*srcBpp+2], s[i*srcBpp+1], s[i*srcBpp]);
                fprintf(g_vTrace, " dst=");
                for (int i = 0; i < 6; i++) fprintf(g_vTrace, " %02x%02x%02x", d[i*4+2], d[i*4+1], d[i*4]);
                fprintf(g_vTrace, "\n"); fflush(g_vTrace);
            }
            ((PFN_Unlock)vt(texSurf)[0x80/4])(texSurf, nullptr);
        }
        *pCacheSurf = texSurf;
    }
    if (*pCacheSurf) {
        long hr = ((PFN_SetTex)dvt[0x8c/4])(device, 0, *pCacheSurf);
        if (g_vTrace) { fprintf(g_vTrace, "[D3D7TEX] SetTexture(stage0, %p) hr=0x%lx\n", *pCacheSurf, (unsigned long)hr); fflush(g_vTrace); }
    }
    // ONE-SHOT readback: re-Lock the texture + dump first 8 pixels to PROVE the surface has data.
    static int rbOnce = 0;
    if (*pCacheSurf && rbOnce < 1 && g_vTrace) {
        rbOnce++;
        DDSURFACEDESC2 rb = {}; rb.dwSize = sizeof(rb);
        long lh = ((PFN_Lock)vt(*pCacheSurf)[0x64/4])(*pCacheSurf, nullptr, &rb, 0, nullptr);
        if (lh == 0 && rb.lpSurface) {
            uint8_t* s = (uint8_t*)rb.lpSurface;
            fprintf(g_vTrace, "[D3D7TEX] READBACK %s pitch=%d first px:", tgaName, (int)rb.lPitch);
            for (int i = 0; i < 8; i++) fprintf(g_vTrace, " %02x%02x%02x", s[i*4+2], s[i*4+1], s[i*4+0]);
            fprintf(g_vTrace, "\n"); fflush(g_vTrace);
        }
        ((PFN_Unlock)vt(*pCacheSurf)[0x80/4])(*pCacheSurf, nullptr);
    }
}

extern "C" void VanillaD3D7_BindIntroGrnd(void* device) {
    VanillaD3D7_BindTga(device, "Bin\\w_intro_island.gzp", "intro_grnd.tga",
                        &g_introGrndSurf, &g_introGrndTried);
}
