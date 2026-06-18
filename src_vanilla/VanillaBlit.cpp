// Vanilla-Native Recomp — the canonical 2D TILED BLITTER (port of FUN_00433900).
// See behavior_specs/vanilla_2d_render_pipeline.md. The original renders ALL 2D imagery
// (intros, loading, menu sky/logo/GUI text) by tiling the image into ≤128px D3D7 textures
// and drawing each tile as a TRIFAN-4 quad (XYZRHW+DIFFUSE[alpha=fade]+UV) through the
// device. This is the source of the menu trace's 130 TRIFAN-4 quads. The recomp's GDI
// BitBlt bracket was a fundamental deviation; this drives the renderer like the original.
//
// Pipeline (from decompiled code):
//   FUN_0050eb50: load TGA, tile into 128px, create a D3D7 texture surface per tile.
//   FUN_00433900: per tile → SetTexture@0x8c + STSS@0x94 + DrawPrimitive@0x64 TRIFAN-4.
#include <windows.h>
#include <ddraw.h>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <vector>
#include "VanillaVFS.h"
#include "VanillaTGA.h"

extern "C" FILE* g_vTrace;

// D3D7 device vtable slots (see RE_docs/DX7_D3D7_VTABLE_AUTHORITATIVE.md):
//   0x8c SetTexture, 0x94 SetTextureStageState, 0x50 SetRenderState, 0x64 DrawPrimitive.
typedef long (__stdcall *PFN_GetRT)(void*, void**);
typedef long (__stdcall *PFN_GetDDI)(void*, void**);
typedef long (__stdcall *PFN_CreateSurf)(void*, DDSURFACEDESC2*, void**, void*);
typedef long (__stdcall *PFN_Lock)(void*, void*, DDSURFACEDESC2*, uint32_t, void*);
typedef long (__stdcall *PFN_Unlock)(void*, void*);
typedef long (__stdcall *PFN_SetTex)(void*, uint32_t, void*);
typedef long (__stdcall *PFN_STSS)(void*, uint32_t, uint32_t, uint32_t);
typedef long (__stdcall *PFN_SR)(void*, uint32_t, uint32_t);
typedef long (__stdcall *PFN_DP)(void*, uint32_t, uint32_t, const void*, uint32_t, uint32_t);

static inline void** vt(void* obj) { return *(void***)obj; }

// D3D7 render-state + texture-stage-state enums used.
enum { D3DRS_ALPHABLENDENABLE = 27, D3DRS_SRCBLEND = 19, D3DRS_DESTBLEND = 20 };
enum { D3DBLEND_SRCALPHA = 5, D3DBLEND_INVSRCALPHA = 6 };
enum { D3DTSS_COLOROP = 1, D3DTSS_COLORARG1 = 2, D3DTSS_COLORARG2 = 3,
       D3DTSS_ALPHAOP = 25, D3DTSS_ALPHAARG1 = 26, D3DTSS_ALPHAARG2 = 27 };
enum { D3DTOP_DISABLE = 1, D3DTOP_SELECTARG1 = 2, D3DTOP_SELECTARG2 = 3, D3DTOP_MODULATE = 4 };
enum { D3DTA_DIFFUSE = 0, D3DTA_TEXTURE = 2 };
enum { D3DPT_TRIANGLEFAN = 6 };

// ── texture surface creation (32-bit X8R8G8B8 managed) ───────────────────────
static void* CreateTexSurf(void* device, int w, int h, const uint8_t* srcBGR, int srcBpp) {
    void** dvt = vt(device);
    void* rt = nullptr;
    ((PFN_GetRT)dvt[0x24/4])(device, &rt);
    if (!rt) return nullptr;
    void* dd7 = nullptr;
    ((PFN_GetDDI)vt(rt)[0x90/4])(rt, &dd7);
    ((long(__stdcall*)(void*))vt(rt)[0x08/4])(rt);   // release rt
    if (!dd7) return nullptr;
    DDSURFACEDESC2 desc = {};
    desc.dwSize = sizeof(desc);
    desc.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT | DDSD_PIXELFORMAT | DDSD_TEXTURESTAGE;
    desc.dwWidth = w; desc.dwHeight = h;
    desc.ddsCaps.dwCaps = DDSCAPS_TEXTURE;
    desc.ddsCaps.dwCaps2 = DDSCAPS2_TEXTUREMANAGE;
    desc.ddpfPixelFormat.dwSize = sizeof(desc.ddpfPixelFormat);
    desc.ddpfPixelFormat.dwFlags = DDPF_RGB;
    desc.ddpfPixelFormat.dwRGBBitCount = 32;
    desc.ddpfPixelFormat.dwRBitMask = 0x00FF0000;
    desc.ddpfPixelFormat.dwGBitMask = 0x0000FF00;
    desc.ddpfPixelFormat.dwBBitMask = 0x000000FF;
    void* surf = nullptr;
    long hr = ((PFN_CreateSurf)vt(dd7)[0x18/4])(dd7, &desc, &surf, nullptr);
    ((long(__stdcall*)(void*))vt(dd7)[0x08/4])(dd7);
    if (hr != 0 || !surf) return nullptr;
    // Lock + copy srcBGR → 32bit BGRX.
    DDSURFACEDESC2 lk = {}; lk.dwSize = sizeof(lk);
    if (((PFN_Lock)vt(surf)[0x64/4])(surf, nullptr, &lk, 0, nullptr) == 0 && lk.lpSurface) {
        uint8_t* dst = (uint8_t*)lk.lpSurface;
        for (int y = 0; y < h; y++) {
            uint8_t* drow = dst + y * lk.lPitch;
            const uint8_t* srow = srcBGR + y * w * srcBpp;
            for (int x = 0; x < w; x++) {
                drow[x*4+0] = srow[x*srcBpp+0];
                drow[x*4+1] = srow[x*srcBpp+1];
                drow[x*4+2] = srow[x*srcBpp+2];
                drow[x*4+3] = 0xFF;
            }
        }
        ((PFN_Unlock)vt(surf)[0x80/4])(surf, nullptr);
    }
    return surf;
}

// ── TiledImage: a TGA split into ≤128px D3D7 texture tiles (cached) ───────────
namespace VanillaBlit {
struct Tile { void* surf; int sw, sh; };   // surf = 128px (or edge) D3D7 texture
struct TiledImage {
    int imgW = 0, imgH = 0;
    int tileW = 128, tileH = 128;
    int tilesX = 0, tilesY = 0;
    std::vector<Tile> tiles;
    bool ok = false;
};

TiledImage* Load(void* device, const char* gzp, const char* tgaName) {
    auto gz = VanillaVFS::GzpReadFile(gzp, tgaName);
    if (gz.empty()) return nullptr;
    VanillaTGA::Image img = VanillaTGA::Parse(gz.data(), gz.size());
    if (!img.ok || img.pixels.empty()) return nullptr;
    TiledImage* ti = new TiledImage{};
    ti->imgW = img.width; ti->imgH = img.height;
    ti->tileW = 128; ti->tileH = 128;
    ti->tilesX = (img.width  + ti->tileW - 1) / ti->tileW;
    ti->tilesY = (img.height + ti->tileH - 1) / ti->tileH;
    ti->tiles.resize(ti->tilesX * ti->tilesY);
    int bpp = img.bitsPerPixel / 8;
    for (int ty = 0; ty < ti->tilesY; ty++) {
        for (int tx = 0; tx < ti->tilesX; tx++) {
            int x0 = tx * ti->tileW, y0 = ty * ti->tileH;
            int tw = (x0 + ti->tileW > img.width)  ? img.width  - x0 : ti->tileW;
            int th = (y0 + ti->tileH > img.height) ? img.height - y0 : ti->tileH;
            // extract the tile's pixels (contiguous, for the Lock copy).
            std::vector<uint8_t> tilePx(tw * th * bpp);
            for (int y = 0; y < th; y++) {
                memcpy(&tilePx[y * tw * bpp], &img.pixels[((y0+y)*img.width + x0) * bpp], tw * bpp);
            }
            void* surf = CreateTexSurf(device, tw, th, tilePx.data(), bpp);
            ti->tiles[ty * ti->tilesX + tx] = { surf, tw, th };
        }
    }
    ti->ok = true;
    if (g_vTrace) { fprintf(g_vTrace, "[BLIT] loaded '%s' %dx%d -> %dx%d tiles (128px)\n",
        tgaName, ti->imgW, ti->imgH, ti->tilesX, ti->tilesY); fflush(g_vTrace); }
    return ti;
}

// Draw the tiled image at (dstX,dstY) with fade alpha [0..1] via D3D7 TRIFAN-4 quads.
// Mirrors FUN_00433900: per tile SetTexture + STSS + DrawPrimitive(TRIFAN, 4 verts).
void Draw(void* device, TiledImage* img, int dstX, int dstY, float fade) {
    if (!device || !img || !img->ok) return;
    void** dvt = vt(device);
    PFN_SetTex setTex = (PFN_SetTex)dvt[0x8c/4];
    PFN_STSS stss     = (PFN_STSS)dvt[0x94/4];
    PFN_SR   sr       = (PFN_SR)dvt[0x50/4];
    PFN_DP   dp       = (PFN_DP)dvt[0x64/4];
    if (!setTex || !stss || !dp) return;
    // alpha blend for the fade.
    if (sr) {
        sr(device, D3DRS_ALPHABLENDENABLE, 1);
        sr(device, D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA);
        sr(device, D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    }
    // stage 0: color = texture * diffuse; alpha = diffuse (the fade).
    stss(device, 0, D3DTSS_COLOROP,   D3DTOP_MODULATE);
    stss(device, 0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
    stss(device, 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
    stss(device, 0, D3DTSS_ALPHAOP,   D3DTOP_SELECTARG2);  // alpha from diffuse (arg2)
    stss(device, 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
    uint32_t a = (uint32_t)(fade * 255.0f); if (a > 255) a = 255;
    uint32_t diff = (a << 24) | 0x00FFFFFF;   // white RGB + fade alpha
    struct PtV { float x, y, z, rhw; uint32_t diff; float u, v; };  // FVF 0x144
    for (int ty = 0; ty < img->tilesY; ty++) {
        for (int tx = 0; tx < img->tilesX; tx++) {
            Tile& t = img->tiles[ty * img->tilesX + tx];
            if (!t.surf) continue;
            setTex(device, 0, t.surf);
            float x0 = (float)(dstX + tx * img->tileW);
            float y0 = (float)(dstY + ty * img->tileH);
            float x1 = x0 + t.sw, y1 = y0 + t.sh;
            PtV v[4] = {
                { x0, y0, 0.0f, 1.0f, diff, 0.0f, 0.0f },  // TL
                { x1, y0, 0.0f, 1.0f, diff, 1.0f, 0.0f },  // TR
                { x1, y1, 0.0f, 1.0f, diff, 1.0f, 1.0f },  // BR
                { x0, y1, 0.0f, 1.0f, diff, 0.0f, 1.0f },  // BL
            };
            dp(device, D3DPT_TRIANGLEFAN, 0x144, v, 4, 0);
        }
    }
    // restore: disable alpha blend (so subsequent non-blended draws are unaffected).
    if (sr) sr(device, D3DRS_ALPHABLENDENABLE, 0);
}

// Draw the tiled image SCALED to a (dstW x dstH) rectangle (the vanilla device-fit path —
// intros are 1600x1200 but the device is 640x480, so native Draw crops them). Each tile maps
// to its proportional sub-rectangle of the destination, UVs = the tile's sub-rect.
void DrawScaled(void* device, TiledImage* img, int dstX, int dstY, int dstW, int dstH, float fade) {
    if (!device || !img || !img->ok || dstW <= 0 || dstH <= 0) return;
    void** dvt = vt(device);
    PFN_SetTex setTex = (PFN_SetTex)dvt[0x8c/4];
    PFN_STSS stss     = (PFN_STSS)dvt[0x94/4];
    PFN_SR   sr       = (PFN_SR)dvt[0x50/4];
    PFN_DP   dp       = (PFN_DP)dvt[0x64/4];
    if (!setTex || !dp) return;
    if (sr) {
        sr(device, D3DRS_ALPHABLENDENABLE, 1);
        sr(device, D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA);
        sr(device, D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    }
    stss(device, 0, D3DTSS_COLOROP,   D3DTOP_MODULATE);
    stss(device, 0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
    stss(device, 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
    stss(device, 0, D3DTSS_ALPHAOP,   D3DTOP_SELECTARG2);
    stss(device, 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
    uint32_t a = (uint32_t)(fade * 255.0f); if (a > 255) a = 255;
    uint32_t diff = (a << 24) | 0x00FFFFFF;
    struct PtV { float x, y, z, rhw; uint32_t diff; float u, v; };
    float sx = (float)dstW / (float)(img->tilesX * img->tileW);  // dest px per src px
    float sy = (float)dstH / (float)(img->tilesY * img->tileH);
    for (int ty = 0; ty < img->tilesY; ty++) {
        for (int tx = 0; tx < img->tilesX; tx++) {
            Tile& t = img->tiles[ty * img->tilesX + tx];
            if (!t.surf) continue;
            setTex(device, 0, t.surf);
            float x0 = dstX + (tx * img->tileW) * sx;
            float y0 = dstY + (ty * img->tileH) * sy;
            float x1 = x0 + t.sw * sx, y1 = y0 + t.sh * sy;
            PtV v[4] = {
                { x0, y0, 0.0f, 1.0f, diff, 0.0f, 0.0f },
                { x1, y0, 0.0f, 1.0f, diff, 1.0f, 0.0f },
                { x1, y1, 0.0f, 1.0f, diff, 1.0f, 1.0f },
                { x0, y1, 0.0f, 1.0f, diff, 0.0f, 1.0f },
            };
            dp(device, D3DPT_TRIANGLEFAN, 0x144, v, 4, 0);
        }
    }
    if (sr) sr(device, D3DRS_ALPHABLENDENABLE, 0);
}
} // namespace VanillaBlit
