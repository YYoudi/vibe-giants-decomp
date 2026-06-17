#include <cstdarg>
// Giants Vanilla-Native Recomp — Terrain (GTI heightfield) render port.
// See VanillaTerrain.h for the design and RE_docs/TERRAIN_RENDER.md for the
// full reverse-engineering reference of the vanilla terrain path.
//
// This module ports the SIMPLIFIED terrain render: build a triangle grid
// from a parsed GTI and submit it via renderer slot +0x98. The vanilla path
// (FUN_00476d40 load → FUN_00436910 9-pass render → FUN_00436540 per-pass →
// FUN_00438530 per-quad → slot +0xa0) is documented but not fully ported —
// it requires the world struct (DAT_006316ec), 9 per-pass VB sub-objects,
// and the frustum cull, which are too deep for a standalone first draw.
#include <cstdarg>
#include "VanillaTerrain.h"
#include "VanillaGTI.h"
#include "VanillaVFS.h"
#include "VanillaEngine.h"          // g_vRenderer (DAT_00654940)

#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

extern FILE* g_vTrace;

// ── Minimal D3D7 matrix helpers (row-major, D3D row-vector convention v' = v*M) ──
struct Vec3 { float x, y, z; };
static Vec3 vsub(Vec3 a, Vec3 b) { return { a.x - b.x, a.y - b.y, a.z - b.z }; }
static float vdot(Vec3 a, Vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
static Vec3 vcross(Vec3 a, Vec3 b) { return { a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x }; }
static Vec3 vnorm(Vec3 a) { float l = sqrtf(vdot(a, a)); if (l < 1e-9f) l = 1; return { a.x/l, a.y/l, a.z/l }; }
using Mtx = float[16];   // row-major: m[r*4+c]
static void mtxIdentity(Mtx m) { for (int i=0;i<16;i++) m[i]=0; m[0]=m[5]=m[10]=m[15]=1; }
static void mtxLookAtLH(Mtx m, Vec3 eye, Vec3 at, Vec3 up) {
    // D3D LH look-at (row-major). zaxis = forward(at-eye), xaxis = cross(up,zaxis), yaxis=cross(zaxis,xaxis)
    Vec3 z = vnorm(vsub(at, eye));
    Vec3 x = vnorm(vcross(up, z));
    Vec3 y = vcross(z, x);
    m[0]=x.x; m[1]=y.x; m[2]=z.x; m[3]=0;
    m[4]=x.y; m[5]=y.y; m[6]=z.y; m[7]=0;
    m[8]=x.z; m[9]=y.z; m[10]=z.z; m[11]=0;
    m[12]=-vdot(x,eye); m[13]=-vdot(y,eye); m[14]=-vdot(z,eye); m[15]=1;
}
static void mtxPerspectiveFovLH(Mtx m, float fovy, float aspect, float zn, float zf) {
    float ys = 1.0f / tanf(fovy * 0.5f);
    float xs = ys / aspect;
    for (int i=0;i<16;i++) m[i]=0;
    m[0]=xs; m[5]=ys; m[10]=zf/(zf-zn); m[11]=1; m[14]=-zn*zf/(zf-zn);
}
// SetTransform (vt[11]=byte 0x2c) + SetRenderState (vt[20]=byte 0x50) on the wrapper.
typedef long (__stdcall *PFN_SetXform)(void*, uint32_t, const float*);
typedef long (__stdcall *PFN_SetRS)(void*, uint32_t, uint32_t);
static void SetupCamera(void* wrapper, void** wvt) {
    Mtx world, view, proj;
    mtxIdentity(world);
    // Island spans x[0..4600] y[0..5680] z[-40..760]; center ~(2300,2840,300).
    mtxLookAtLH(view, {2300.f, -4000.f, 2500.f}, {2300.f, 2840.f, 0.f}, {0.f, 0.f, 1.f});
    mtxPerspectiveFovLH(proj, 1.0472f /*60deg*/, 640.f/480.f, 10.f, 30000.f);
    auto sx = (PFN_SetXform)wvt[0x2c / 4];
    if (sx) { sx(wrapper, 1 /*WORLD*/, world); sx(wrapper, 2 /*VIEW*/, view); sx(wrapper, 3 /*PROJECTION*/, proj); }
    auto sr = (PFN_SetRS)wvt[0x50 / 4];
    if (sr) { sr(wrapper, 22 /*D3DRENDERSTATE_CULLMODE*/, 1 /*D3DCULL_NONE*/);
              sr(wrapper, 7  /*D3DRENDERSTATE_ZENABLE*/, 0 /*FALSE — show all*/);
              sr(wrapper, 27 /*D3DRENDERSTATE_ALPHABLENDENABLE*/, 0 /*FALSE — opaque*/); }
}

extern "C" int VanillaTerrain_DrawX(const char* a, const char* b) { return VanillaTerrain::VanillaTerrain_Draw(a, b); }

namespace VanillaTerrain {

// ─── Helpers ──────────────────────────────────────────────────────────────

static void trace(const char* fmt, ...) {
    if (!g_vTrace) return;
    va_list ap; va_start(ap, fmt);
    vfprintf(g_vTrace, fmt, ap);
    va_end(ap);
    fflush(g_vTrace);
}

// Build a triangle-list mesh from a parsed GTI terrain.
//
// For each interior cell (x, y) we emit 2 triangles covering the quad
// (x,y)-(x+1,y)-(x+1,y+1)-(x,y+1). The height at each grid corner is taken
// from the parsed cells. This is the "flat quad per cell" triangulation —
// visually equivalent to the vanilla adaptive (triFlag) version for a
// heightfield, at the cost of ~2x the triangle count (no LOD, no diagonal
// selection). World-space position matches FUN_00458ab0:
//   X = x * cellSize + originX
//   Y = y * cellSize + originY
//   Z = cells[y * xcells + x].height
//
// The 4 corners of cell (x,y) are read from cells[(y)*xcells + x],
// cells[(y)*xcells + x+1], cells[(y+1)*xcells + x], cells[(y+1)*xcells + x+1].
// We skip cells whose height is the sentinel -10000.0f (ocean / no-terrain).
//
// Vertex color: the parsed cell RGB if present, else a flat terrain green so
// the mesh is visible even without the texture bound. Color is packed as
// 0x00RRGGBB (the renderer's diffuse format per FUN_00438530 which writes
// 0xffffff for unlit and a packed value from the cell otherwise).
static uint32_t packRGB(uint8_t r, uint8_t g, uint8_t b) {
    return 0xFF000000u | (uint32_t(r) << 16) | (uint32_t(g) << 8) | uint32_t(b);  // alpha=0xFF opaque
}

// Returns the number of triangles appended. out is appended to.
static int BuildMesh(const VanillaGTI::Terrain& t,
                     std::vector<TerrainVertex>& out) {
    if (!t.ok || t.width < 2 || t.height < 2) return 0;

    // Cell corners: a cell at (x,y) covers corners (x,y)..(x+1,y+1).
    // Vanilla iterates x in [0, xcells-2], y in [0, ycells-2] (interior).
    // The edge caches (world+0x14/+0x18) clip this further; we skip cells
    // whose corner height is the sentinel.
    const float sentinel = -10000.0f;        // vanilla 0xc5800000
    const float cellSize = t.stretch > 0.0f ? t.stretch : 2.0f;
    const uint32_t defaultColor = packRGB(120, 140, 90);  // terrain green

    // Use the GTI origin if reasonable, else 0. Vanilla stores origin at
    // world+0x1cc/0x1d0 (X/Y); the .gti header has xOff/yOff at +8/+12.
    const float orgX = (std::isfinite(t.xOff) && std::fabs(t.xOff) < 1e5f) ? t.xOff : 0.0f;
    const float orgY = (std::isfinite(t.yOff) && std::fabs(t.yOff) < 1e5f) ? t.yOff : 0.0f;

    int triCount = 0;
    const uint32_t w = t.width;
    const uint32_t h = t.height;

    for (uint32_t y = 0; y + 1 < h; ++y) {
        for (uint32_t x = 0; x + 1 < w; ++x) {
            const auto& c00 = t.cells[y * w + x];
            const auto& c10 = t.cells[y * w + x + 1];
            const auto& c01 = t.cells[(y + 1) * w + x];
            const auto& c11 = t.cells[(y + 1) * w + x + 1];

            // Skip if any corner is the sentinel (ocean / no-terrain).
            if (c00.height <= sentinel || c10.height <= sentinel ||
                c01.height <= sentinel || c11.height <= sentinel) {
                continue;
            }

            // World-space corner positions (matches FUN_00458ab0).
            const float X0 = float(x)     * cellSize + orgX;
            const float X1 = float(x + 1) * cellSize + orgX;
            const float Y0 = float(y)     * cellSize + orgY;
            const float Y1 = float(y + 1) * cellSize + orgY;

            // Per-corner color: prefer the parsed cell RGB if the file had
            // colors, else the flat default. The vanilla render pre-bakes
            // lighting into the triFlag light code; we use the raw RGB.
            const uint32_t col00 = packRGB(c00.r, c00.g, c00.b) ?: defaultColor;
            const uint32_t col10 = packRGB(c10.r, c10.g, c10.b) ?: defaultColor;
            const uint32_t col01 = packRGB(c01.r, c01.g, c01.b) ?: defaultColor;
            const uint32_t col11 = packRGB(c11.r, c11.g, c11.b) ?: defaultColor;

            // UV: map the grid to [0,1]. Vanilla uses world+0x1c8 (1/cellSize)
            // and the texture matrix; a simple normalized UV is fine for the
            // untextured draw and is a reasonable default for later texturing.
            const float u0 = float(x)     / float(w);
            const float u1 = float(x + 1) / float(w);
            const float v0 = float(y)     / float(h);
            const float v1 = float(y + 1) / float(h);

            // Triangle 1: (x,y)-(x+1,y)-(x,y+1) — diagonal TL-BR (case 1 in
            // the vanilla triFlag switch). Winding matches vanilla (CCW).
            out.push_back({ X0, Y0, c00.height, col00, u0, v0 });
            out.push_back({ X1, Y0, c10.height, col10, u1, v0 });
            out.push_back({ X0, Y1, c01.height, col01, u0, v1 });

            // Triangle 2: (x+1,y)-(x+1,y+1)-(x,y+1)
            out.push_back({ X1, Y0, c10.height, col10, u1, v0 });
            out.push_back({ X1, Y1, c11.height, col11, u1, v1 });
            out.push_back({ X0, Y1, c01.height, col01, u0, v1 });

            triCount += 2;
        }
    }
    return triCount;
}

// ─── Renderer submission ─────────────────────────────────────────────────

// Call a renderer method-table slot. The vanilla calling convention is
// __cdecl with the renderer object as the first arg; the slot holds a code
// pointer at g_vRenderer + offset (single indirection). See
// RE_docs/DX7_METHOD_MAP.md §1: "first stack arg [esp+4] = this".
//
// We do NOT go through the per-pass VB sub-object machinery (FUN_00438f00
// + FUN_00438530) — that requires the full world struct and 9 pre-allocated
// VBs. Instead we call the front-table DrawPrimitive slot directly, which
// is what the VB sub-object's vt[0x24] ultimately reaches anyway (via
// wrapper@obj+0x294 -> vt[0x28]).
//
// Slot +0x98 (RVA 0x87e0) signature (from disasm):
//   void DrawTriList(renderer* this, int vertexCount)
// It pushes (0, 1.0f, vertexCount, 3=TRIANGLELIST, 0, this) and calls
// wrapper->vt[0x28]. The vertex data must be in the renderer's currently-
// locked vertex buffer — which for a raw call without a VB lock is the
// renderer's internal stream. This is the same limitation the vanilla
// intros.bin player (FUN_00523b60) works around by drawing through the
// scene pipeline. For a first-visible-geometry test we submit through the
// slot to validate the path; a faithful port would lock a real VB first.
static void CallRendererSlot(uint32_t slot, void* a0 = nullptr, void* a1 = nullptr,
                             void* a2 = nullptr, void* a3 = nullptr) {
    if (!g_vRenderer) return;
    void** vtable = *(void***)g_vRenderer;
    if (!vtable || slot > 0xe0) return;
    void* fn = vtable[slot / 4];
    if (!fn) return;
    // __cdecl: renderer this, then up to 4 args.
    typedef void(__cdecl *SlotFn)(void*, void*, void*, void*, void*);
    ((SlotFn)fn)(g_vRenderer, a0, a1, a2, a3);
}

// Submit a triangle list to the renderer.
// Returns the triangle count drawn, or 0 if the renderer is not live.
static int SubmitTris(const std::vector<TerrainVertex>& verts, int triCount) {
    if (!g_vRenderer || verts.empty()) {
        trace("[VTERRAIN] SubmitTris: no renderer or no verts (ren=%p verts=%zu)\n",
              g_vRenderer, verts.size());
        return 0;
    }
    // Call IDirect3DDevice7::DrawPrimitive DIRECTLY on the renderer's wrapper COM device
    // (wrapper@obj+0x294, vtable = *wrapper). DrawPrimitive = vt index 25 = byte 0x64
    // (confirmed from d3d.h IDirect3DDevice7 vtable order). DX7 DrawPrimitive is
    // UP-style: takes a direct user vertex pointer (no VB lock needed).
    //   HRESULT DrawPrimitive(this, D3DPT_TRIANGLELIST=3, DWORD fvf, void* verts,
    //                          DWORD vertexCount, DWORD flags=0)
    // TerrainVertex = xyz(12)+diffuse(4)+uv(8) = 24B → fvf = XYZ|DIFFUSE|TEX1 = 0x142.
    // BeginScene/EndScene are handled by the manual frame driver (VanillaDriveFrame).
    void** obj = (void**)g_vRenderer;
    void* wrapper = obj[0x294 / 4];
    if (!wrapper) { trace("[VTERRAIN] wrapper@obj+0x294 NULL\n"); return 0; }
    void** wvt = *(void***)wrapper;
    if (!wvt) { trace("[VTERRAIN] wrapper vtable NULL\n"); return 0; }
    void* drawPrim = wvt[0x64 / 4];   // vt[25] = DrawPrimitive
    if (!drawPrim) { trace("[VTERRAIN] DrawPrimitive (vt[0x64]) NULL\n"); return 0; }
    // Diagnostic: the device's render target is NOT obj+0x288 (the surface Present shows) —
    // obj+0x288 is the presented primary, not a valid D3D render target. The renderer copies
    // the device back-buffer to obj+0x288 in its frame (a step the manual driver lacks).
    {
        void* rt = nullptr;
        typedef long (__stdcall *PFN_GetRT)(void*, void**);
        auto grt = (PFN_GetRT)wvt[0x24 / 4];
        if (grt) grt(wrapper, &rt);
        trace("[VTERRAIN] device render-target=%p  presented(obj+0x288)=%p (renderer copies btwn them in its frame)\n", rt, obj[0x288 / 4]);
    }
    // ── DIAGNOSTIC: screen-space triangle (XYZRHW, bypasses transforms) to confirm
    // DrawPrimitive produces VISIBLE output end-to-end. White/red/green, centered @640x480.
    {   struct V { float x,y,z,rhw; uint32_t diff; };  // XYZRHW|DIFFUSE=0x044, 20 bytes
        V tri[3] = { {320.f,80.f,0.f,1.f,0xFFFFFFFF}, {80.f,400.f,0.f,1.f,0xFFFF2020},
                     {560.f,400.f,0.f,1.f,0xFF20FF20} };
        typedef long (__stdcall *PFN_DP)(void*,uint32_t,uint32_t,const void*,uint32_t,uint32_t);
        long hr2 = ((PFN_DP)drawPrim)(wrapper, 3, 0x044, tri, 3, 0);
        trace("[VTERRAIN] TEST TRIANGLE (XYZRHW) hr=0x%lx\n", (unsigned long)hr2);
    }
    // Set up camera (world/view/projection + cull/z) so the world-coord terrain maps to screen.
    SetupCamera(wrapper, wvt);
    typedef long (__stdcall *PFN_DrawPrim)(void*, uint32_t, uint32_t, const void*, uint32_t, uint32_t);
    int vCount = (int)verts.size();
    const uint32_t fvf = 0x002 /*D3DFVF_XYZ*/ | 0x040 /*D3DFVF_DIFFUSE*/ | 0x100 /*D3DFVF_TEX1*/;
    long hr = ((PFN_DrawPrim)drawPrim)(wrapper, 3 /*D3DPT_TRIANGLELIST*/, fvf,
                                       verts.data(), vCount, 0);
    trace("[VTERRAIN] SubmitTris: DrawPrimitive(wrapper=%p, TRIANGLELIST, fvf=0x%x, %d verts, %d tris) hr=0x%lx\n",
          wrapper, fvf, vCount, triCount, (unsigned long)hr);
    return triCount;
}

// ─── Public API ───────────────────────────────────────────────────────────

extern "C" int VanillaTerrain_DrawParsed(const void* terrain) {
    if (!terrain) return 0;
    const auto& t = *static_cast<const VanillaGTI::Terrain*>(terrain);

    std::vector<TerrainVertex> verts;
    int triCount = BuildMesh(t, verts);
    if (triCount == 0) {
        trace("[VTERRAIN] DrawParsed: BuildMesh produced 0 triangles (w=%u h=%u ok=%d)\n",
              t.width, t.height, (int)t.ok);
        return 0;
    }
    return SubmitTris(verts, triCount);
}

extern "C" int VanillaTerrain_Draw(const char* gtiPath, const char* gzpPath) {
    if (!gtiPath || !gzpPath) return 0;

    auto data = VanillaVFS::GzpReadFile(gzpPath, gtiPath);
    if (data.empty()) {
        trace("[VTERRAIN] Draw: %s:%s not found via VFS\n", gzpPath, gtiPath);
        return 0;
    }
    VanillaGTI::Terrain t = VanillaGTI::Parse(data.data(), data.size());
    if (!t.ok) {
        trace("[VTERRAIN] Draw: parse failed (sig=%08x)\n", t.sig);
        return 0;
    }
    trace("[VTERRAIN] Draw: parsed %s %ux%u stretch=%.2f cells=%zu\n",
          gtiPath, t.width, t.height, t.stretch, t.cells.size());
    return VanillaTerrain_DrawParsed(&t);
}

// ─── Self-test (no renderer required) ─────────────────────────────────────

int SelfTest() {
    trace("=== VanillaTerrain::SelfTest ===\n");

    auto data = VanillaVFS::GzpReadFile("Bin\\w_intro_island.gzp", "intro_island.gti");
    if (data.empty()) {
        trace("[VTERRAIN] SelfTest: intro_island.gti not found via VFS\n");
        return 0;
    }
    VanillaGTI::Terrain t = VanillaGTI::Parse(data.data(), data.size());
    if (!t.ok) {
        trace("[VTERRAIN] SelfTest: parse FAILED (sig=%08x)\n", t.sig);
        return 0;
    }

    // Compute height range over live (non-sentinel) cells for the report.
    const float sentinel = -10000.0f;
    float lo = 1e30f, hi = -1e30f;
    int liveCells = 0;
    for (const auto& c : t.cells) {
        if (c.height <= sentinel) continue;
        lo = std::min(lo, c.height);
        hi = std::max(hi, c.height);
        ++liveCells;
    }

    std::vector<TerrainVertex> verts;
    int triCount = BuildMesh(t, verts);

    trace("[VTERRAIN] SelfTest: intro_island.gti %ux%u stretch=%.2f\n",
          t.width, t.height, t.stretch);
    trace("[VTERRAIN]   live cells: %d / %zu  height range [%.2f .. %.2f]\n",
          liveCells, t.cells.size(), lo, hi);
    trace("[VTERRAIN]   mesh: %d triangles, %zu verts (%zu bytes)\n",
          triCount, verts.size(), verts.size() * sizeof(TerrainVertex));
    if (!verts.empty()) {
        // Sample the first vertex.
        const auto& v0 = verts[0];
        trace("[VTERRAIN]   v0: pos=(%.1f, %.1f, %.1f) color=0x%08x uv=(%.3f, %.3f)\n",
              v0.x, v0.y, v0.z, v0.color, v0.u, v0.v);
    }
    trace("[VTERRAIN]   renderer live: %s (g_vRenderer=%p)\n",
          g_vRenderer ? "YES" : "no", g_vRenderer);
    trace("=== VanillaTerrain::SelfTest done ===\n");
    return triCount;
}

} // namespace VanillaTerrain
