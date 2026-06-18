// Vanilla-Native Recomp — bitmap font renderer (port of FUN_0044a9c0/FUN_004a4e0 + the
// text flush). See behavior_specs/menu_system_code.md. The Giants font "GiantFont_Eng"
// (tx_lev1.gzp) is a glyph tile-sheet; chars map to glyph cells via a charmap built from
// the printable-ASCII charset. Text = per-char glyph-cell UV-subrect quads via the 2D
// blitter (same mechanism as the cursor/intros — vanilla_2d_render_pipeline.md).
#include <windows.h>
#include <ddraw.h>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <vector>
#include "VanillaVFS.h"
#include "VanillaTGA.h"

extern "C" FILE* g_vTrace;

// D3D7 device vtable slots.
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
enum { D3DRS_ALPHABLENDENABLE = 27, D3DRS_SRCBLEND = 19, D3DRS_DESTBLEND = 20 };
enum { D3DBLEND_SRCALPHA = 5, D3DBLEND_INVSRCALPHA = 6 };
enum { D3DTSS_COLOROP = 1, D3DTSS_COLORARG1 = 2, D3DTSS_COLORARG2 = 3,
       D3DTSS_ALPHAOP = 25, D3DTSS_ALPHAARG2 = 27 };
enum { D3DTOP_MODULATE = 4, D3DTOP_SELECTARG2 = 3 };
enum { D3DTA_DIFFUSE = 0, D3DTA_TEXTURE = 2 };
enum { D3DPT_TRIANGLEFAN = 6 };

namespace VanillaFont {
struct Font {
    void* texSurf = nullptr;   // the whole font sheet as one D3D7 texture
    int   imgW = 0, imgH = 0;  // sheet pixel dims
    int   cellW = 16, cellH = 16; // glyph cell size
    int   cols = 0;            // glyphs per row = imgW / cellW
    bool  ok = false;
    // charmap: char (0..255) -> glyph cell index (or -1 if unmapped).
    int   map[256];
};

// Exact vanilla charset (s_...0055a948, extracted from Giants_nocd.exe): starts at '!',
// NO space, uppercase only. The font sheet's glyph cells are in THIS order.
static const char* CHARSET =
    "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_";

static void buildCharmap(Font& f) {
    for (int i = 0; i < 256; i++) f.map[i] = -1;
    for (int i = 0; CHARSET[i]; i++) f.map[(unsigned char)CHARSET[i]] = i;
}

Font* Load(void* device) {
    auto gz = VanillaVFS::GzpReadFile("Bin\\tx_lev1.gzp", "GiantFont_Eng.tga");
    if (gz.empty()) return nullptr;
    VanillaTGA::Image img = VanillaTGA::Parse(gz.data(), gz.size());
    if (!img.ok || img.pixels.empty()) return nullptr;
    Font* f = new Font{};
    f->imgW = img.width; f->imgH = img.height;
    // Cell size: Giants font cells. Determine cols from a square-ish layout; the charmap
    // cell height is 32 per FUN_004a4e0 but the sheet is laid out in narrower cells.
    // Trace the dims; assume 16px cells (will refine from the measured sheet).
    f->cellW = 16; f->cellH = 16;
    f->cols = f->imgW / f->cellW;
    buildCharmap(*f);
    // Create ONE D3D7 texture for the whole sheet (32-bit BGRX, alpha from intensity).
    void** dvt = vt(device);
    void* rt = nullptr; ((PFN_GetRT)dvt[0x24/4])(device, &rt);
    void* dd7 = nullptr; ((PFN_GetDDI)vt(rt)[0x90/4])(rt, &dd7);
    ((long(__stdcall*)(void*))vt(rt)[0x08/4])(rt);
    DDSURFACEDESC2 desc = {}; desc.dwSize = sizeof(desc);
    desc.dwFlags = DDSD_CAPS|DDSD_WIDTH|DDSD_HEIGHT|DDSD_PIXELFORMAT|DDSD_TEXTURESTAGE;
    desc.dwWidth = img.width; desc.dwHeight = img.height;
    desc.ddsCaps.dwCaps = DDSCAPS_TEXTURE; desc.ddsCaps.dwCaps2 = DDSCAPS2_TEXTUREMANAGE;
    desc.ddpfPixelFormat.dwSize = sizeof(desc.ddpfPixelFormat);
    desc.ddpfPixelFormat.dwFlags = DDPF_RGB;
    desc.ddpfPixelFormat.dwRGBBitCount = 32;
    desc.ddpfPixelFormat.dwRBitMask = 0x00FF0000; desc.ddpfPixelFormat.dwGBitMask = 0x0000FF00;
    desc.ddpfPixelFormat.dwBBitMask = 0x000000FF;
    long hr = ((PFN_CreateSurf)vt(dd7)[0x18/4])(dd7, &desc, &f->texSurf, nullptr);
    ((long(__stdcall*)(void*))vt(dd7)[0x08/4])(dd7);
    if (hr == 0 && f->texSurf) {
        DDSURFACEDESC2 lk = {}; lk.dwSize = sizeof(lk);
        if (((PFN_Lock)vt(f->texSurf)[0x64/4])(f->texSurf, nullptr, &lk, 0, nullptr) == 0 && lk.lpSurface) {
            uint8_t* dst = (uint8_t*)lk.lpSurface; int bpp = img.bitsPerPixel/8;
            for (int y = 0; y < img.height; y++) {
                uint8_t* dr = dst + y*lk.lPitch; const uint8_t* sr = img.pixels.data() + y*img.width*bpp;
                for (int x = 0; x < img.width; x++) {
                    // GiantFont_Eng is 32bpp: white RGB + glyph coverage in the ALPHA channel.
                    // (Not greyscale-in-RGB — using RGB intensity gave alpha=255 everywhere → blocks.)
                    dr[x*4+0] = dr[x*4+1] = dr[x*4+2] = 255;       // white glyph
                    dr[x*4+3] = (bpp >= 4) ? sr[x*bpp+3]            // TGA alpha = glyph coverage
                                           : (uint8_t)((sr[x*bpp]+sr[x*bpp+1]+sr[x*bpp+2])/3);
                }
            }
            ((PFN_Unlock)vt(f->texSurf)[0x80/4])(f->texSurf, nullptr);
        }
    }
    f->ok = (f->texSurf != nullptr);
    if (g_vTrace) { fprintf(g_vTrace, "[FONT] GiantFont_Eng %dx%d cellW=%d cols=%d glyphs=%zu ok=%d\n",
        f->imgW, f->imgH, f->cellW, f->cols, strlen(CHARSET), (int)f->ok); fflush(g_vTrace); }
    // Dump the raw font sheet to a BMP (one-time) to inspect the real glyph layout/format.
    {
        FILE* bf = fopen("giants_font_sheet.bmp", "wb");
        if (bf) {
            int W=img.width, H=img.height, bpp=img.bitsPerPixel/8;
            uint32_t pad=(4-((W*3)%4))%4, imgsz=(W*3+pad)*H;
            struct { char id[2]; uint32_t sz,res1,off; } fh={{'B','M'},54+imgsz,0,54};
            struct { uint32_t hsz,w,hh; uint16_t pl,bp; uint32_t cp,is,xp,yp,cu,ci; } ih={40,W,H,1,24,0,imgsz,2835,2835,0,0};
            fwrite(&fh,1,sizeof(fh),bf); fwrite(&ih,1,sizeof(ih),bf);
            for (int y=H-1;y>=0;y--) {
                for (int x=0;x<W;x++) {
                    uint8_t* p=&img.pixels[(y*W+x)*bpp];
                    uint8_t px[3]={p[0],p[1],p[2]}; fwrite(px,1,3,bf);
                }
                for (uint32_t p=0;p<pad;p++) fputc(0,bf);
            }
            fclose(bf);
        }
    }
    return f;
}

// Draw a string at (x,y) screen px, height px tall. White text, alpha-blended.
void Draw(void* device, Font* f, const char* s, int x, int y, int height, uint32_t color) {
    if (!device || !f || !f->ok || !s) return;
    void** dvt = vt(device);
    PFN_SetTex setTex = (PFN_SetTex)dvt[0x8c/4];
    PFN_STSS stss = (PFN_STSS)dvt[0x94/4];
    PFN_SR sr = (PFN_SR)dvt[0x50/4];
    PFN_DP dp = (PFN_DP)dvt[0x64/4];
    if (!setTex || !dp) return;
    setTex(device, 0, f->texSurf);
    if (sr) { sr(device, D3DRS_ALPHABLENDENABLE, 1); sr(device, D3DRS_SRCBLEND, D3DBLEND_SRCALPHA); sr(device, D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA); }
    if (stss) { stss(device, 0, D3DTSS_COLOROP, D3DTOP_MODULATE); stss(device, 0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
                stss(device, 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE); stss(device, 0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG2);
                stss(device, 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE); }
    struct PtV { float x,y,z,rhw; uint32_t diff; float u,v; };  // FVF 0x144
    int cw = height;  // square glyph cells scaled to the requested height
    float scaleU = (float)f->cellW / f->imgW;
    float scaleV = (float)f->cellH / f->imgH;
    for (int i = 0; s[i]; i++) {
        int gi = f->map[(unsigned char)s[i]];
        if (gi < 0) { x += cw; continue; }   // unmapped → space advance
        int col = gi % f->cols, row = gi / f->cols;
        float u0 = col * scaleU, v0 = row * scaleV;
        float u1 = u0 + scaleU, v1 = v0 + scaleV;
        PtV v[4] = {
            { (float)x,(float)y,0,1, color, u0,v0 },
            { (float)(x+cw),(float)y,0,1, color, u1,v0 },
            { (float)(x+cw),(float)(y+height),0,1, color, u1,v1 },
            { (float)x,(float)(y+height),0,1, color, u0,v1 },
        };
        dp(device, D3DPT_TRIANGLEFAN, 0x144, v, 4, 0);
        x += cw;
    }
    if (sr) sr(device, D3DRS_ALPHABLENDENABLE, 0);
}
} // namespace VanillaFont
