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

extern "C" void VanillaD3D7_BindIntroGrnd(void* device) {
    if (!device) return;
    void** dvt = vt(device);
    if (!dvt) return;

    // Create the texture surface once (cache).
    if (!g_introGrndSurf && !g_introGrndTried) {
        g_introGrndTried = 1;
        // Load intro_grnd.tga from the level GZP.
        auto gz = VanillaVFS::GzpReadFile("Bin\\w_intro_island.gzp", "intro_grnd.tga");
        if (gz.empty()) gz = VanillaVFS::GzpReadFile("Bin\\w_intro_island.gzp", "intro_sea.tga");
        VanillaTGA::Image img = gz.empty() ? VanillaTGA::Image{} : VanillaTGA::Parse(gz.data(), gz.size());
        if (!img.ok || img.pixels.empty()) {
            if (g_vTrace) { fprintf(g_vTrace, "[D3D7TEX] intro_grnd.tga load FAILED ok=%d\n", (int)img.ok); fflush(g_vTrace); }
            return;
        }
        if (g_vTrace) { fprintf(g_vTrace, "[D3D7TEX] intro_grnd %ux%u bpp=%u\n", img.width, img.height, img.bitsPerPixel); fflush(g_vTrace); }

        // Get IDirectDraw7 via the device render target -> surface GetDDInterface.
        void* rt = nullptr;
        ((PFN_GetRT)dvt[0x24/4])(device, &rt);
        if (!rt) { if (g_vTrace) { fprintf(g_vTrace, "[D3D7TEX] GetRenderTarget NULL\n"); fflush(g_vTrace); } return; }
        void* dd7 = nullptr;
        ((PFN_GetDDI)vt(rt)[0x90/4])(rt, &dd7);
        // Release the render target (we only borrowed it for GetDDInterface).
        ((long(__stdcall*)(void*))vt(rt)[0x08/4])(rt);
        if (!dd7) { if (g_vTrace) { fprintf(g_vTrace, "[D3D7TEX] GetDDInterface NULL\n"); fflush(g_vTrace); } return; }

        // Create a 32-bit X8R8G8B8 managed texture surface.
        DDSURFACEDESC2 desc = {};
        desc.dwSize = sizeof(desc);
        desc.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT | DDSD_PIXELFORMAT | DDSD_TEXTURESTAGE;
        desc.dwWidth = img.width;
        desc.dwHeight = img.height;
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
        ((long(__stdcall*)(void*))vt(dd7)[0x08/4])(dd7);  // release dd7
        if (hr != 0 || !texSurf) {
            if (g_vTrace) { fprintf(g_vTrace, "[D3D7TEX] CreateSurface FAILED hr=0x%lx\n", (unsigned long)hr); fflush(g_vTrace); }
            return;
        }
        if (g_vTrace) { fprintf(g_vTrace, "[D3D7TEX] texture surface created %p\n", texSurf); fflush(g_vTrace); }

        // Lock + copy TGA pixels (24bpp BGR → 32bit BGRX). TGA is bottom-up; D3D7
        // default surface pitch reported in the locked desc — copy row by row.
        DDSURFACEDESC2 lk = {};
        lk.dwSize = sizeof(lk);
        hr = ((PFN_Lock)vt(texSurf)[0x64/4])(texSurf, nullptr, &lk, 0 /*DDLOCK_WAIT*/, nullptr);
        if (hr == 0 && lk.lpSurface) {
            uint8_t* dst = (uint8_t*)lk.lpSurface;
            const uint8_t* src = img.pixels.data();
            int srcBpp = img.bitsPerPixel / 8;
            for (uint32_t y = 0; y < img.height; y++) {
                uint8_t* drow = dst + y * lk.lPitch;
                const uint8_t* srow = src + y * img.width * srcBpp;
                for (uint32_t x = 0; x < img.width; x++) {
                    drow[x*4+0] = srow[x*srcBpp+0];  // B
                    drow[x*4+1] = srow[x*srcBpp+1];  // G
                    drow[x*4+2] = srow[x*srcBpp+2];  // R
                    drow[x*4+3] = 0xFF;               // X/alpha
                }
            }
            ((PFN_Unlock)vt(texSurf)[0x80/4])(texSurf, nullptr);
        } else {
            if (g_vTrace) { fprintf(g_vTrace, "[D3D7TEX] Lock FAILED hr=0x%lx\n", (unsigned long)hr); fflush(g_vTrace); }
        }
        g_introGrndSurf = texSurf;
    }

    // Bind to stage 0 every frame (matches original: bind before draw).
    if (g_introGrndSurf) {
        ((PFN_SetTex)dvt[0x8c/4])(device, 0, g_introGrndSurf);
    }
}
