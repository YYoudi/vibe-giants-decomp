// Giants Vanilla-Native Recomp — Terrain (GTI heightfield) render port.
//
// Ports the TERRAIN RENDER path (the island mesh) from vanilla Giants.exe.
// See RE_docs/TERRAIN_RENDER.md for the full reverse-engineering reference.
//
// The vanilla terrain render is a 9-pass, multi-VB, frustum-culled pipeline
// (FUN_00438090 → FUN_00438420 → FUN_00436690 → FUN_00436910 → FUN_00436540
// → FUN_00438530), which requires the full world struct (DAT_006316ec), the
// 9 per-pass VB sub-objects (FUN_00438f00), and the frustum cull. That is
// too deep to port standalone for a first-visible-geometry milestone.
//
// This module implements the SIMPLIFIED path: build a flat triangle grid
// directly from a parsed GTI heightfield (via VanillaGTI::Parse) and submit
// it to the renderer's DrawPrimitive slot +0x98 (RVA 0x87e0 in gg_dx7r.dll),
// which draws a non-indexed D3DPT_TRIANGLELIST. The vertex format matches
// the vanilla TerrainVertex (0x18 bytes: x, y, z, color, u, v).
//
// What this does NOT do (vs the faithful vanilla path):
//   - Adaptive triangulation per triFlag (draws both diagonals = flat quad
//     per cell; visually equivalent for a heightfield, ~2x the triangles).
//   - Per-vertex lighting / shadow codes (uses cell RGB or flat color).
//   - Frustum culling (draws the whole grid every frame).
//   - Texturing (submits untextured colored vertices; binding o_grnd
//     requires the texture-list path through renderer slot +0xb4).
//   - The 9-pass light accumulation (single pass only).
//
// What this DOES: demonstrates the full data path (GTI → cells → world-space
// vertices → renderer DrawPrimitive → wrapper-vt[0x28] → D3D device) and
// produces the first real 3D geometry on screen.
#pragma once
#include <cstdint>

namespace VanillaTerrain {

// Vanilla renderer method-table offsets (see RE_docs/DX7_METHOD_MAP.md).
// All are __cdecl, first arg = renderer object (g_vRenderer = DAT_00654940).
constexpr uint32_t kSlot_DrawPrimitiveTriList = 0x98;  // RVA 0x87e0 — non-indexed TRIANGLELIST
constexpr uint32_t kSlot_DrawPrimitiveIndexed = 0xa0;  // RVA 0x8890 — indexed (terrain uses this)
constexpr uint32_t kSlot_SetTransform         = 0xac;  // RVA 0x84d0 — SetTransform + state batch
constexpr uint32_t kSlot_BeginScene           = 0x90;  // RVA 0x86a0 — scene open + Clear
constexpr uint32_t kSlot_EndScene             = 0x94;  // RVA 0x87a0 — scene close

// Vanilla TerrainVertex format (0x18 bytes / 24 bytes — 6 dwords).
// Matches the per-vertex layout written by FUN_00438530 in the vanilla
// render path. This is the Giants internal TLVERTEX (pre-lit transformed
// vertex: position + diffuse color + UV).
#pragma pack(push, 4)
struct TerrainVertex {            // offset  size
    float  x, y, z;               // +0x00   12  (world-space position; Z = height)
    uint32_t color;               // +0x0c   4   (packed RGB diffuse, 0x00RRGGBB)
    float  u, v;                  // +0x10   8   (texture coords — unused when untextured)
};                                // total   0x18 (24 bytes)
#pragma pack(pop)
static_assert(sizeof(TerrainVertex) == 0x18, "TerrainVertex must be 0x18 bytes");

// Build a triangle-list mesh from a parsed GTI heightfield and submit it to
// the renderer. One frame's worth of geometry.
//
// gtiPath:   the .gti file to load (via VanillaVFS, e.g. "intro_island.gti")
// gzpPath:   the archive containing the gti (e.g. "Bin\\w_intro_island.gzp")
//
// Returns the number of triangles drawn, or 0 on failure (GTI not found,
// parse failed, or renderer not initialized). Logs to g_vTrace.
extern "C" int VanillaTerrain_Draw(const char* gtiPath, const char* gzpPath);

// Same as VanillaTerrain_Draw but operates on an already-parsed Terrain.
// Useful for repeated draws (avoids re-parsing the GTI every frame).
extern "C" int VanillaTerrain_DrawParsed(const void* terrain);

// Self-test: parse intro_island.gti, build the mesh, log vertex/triangle
// counts + height range. Does NOT call the renderer (renderer may not be
// live when the self-test runs at startup). Returns triangle count, 0 on err.
int SelfTest();

} // namespace VanillaTerrain
