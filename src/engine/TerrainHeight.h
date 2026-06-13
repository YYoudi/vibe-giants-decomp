// Giants Engine - Terrain Height & Plane Calculation
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── Terrain cell structure (0x1C bytes) ──────────────────────
// Each cell in the terrain grid stores height + flags.
// Cell size = 28 bytes (0x1C). Rows are arrays of cells.
struct TerrainCell {
    float height;           // +0x00 — terrain height at this vertex
    uint16_t flags;         // +0x04 — cell type/flags (bits 0-2: triangle type)
    uint16_t pad;           // +0x06
    float reserved[6];      // +0x08 — reserved data
};

// ─── Terrain data structure ───────────────────────────────────
// Global terrain database accessed via g_terrain pointer.
struct TerrainData {
    uint8_t pad_000[0x44];
    int** rows;             // +0x44 — row pointers (each row = array of TerrainCell)
    uint8_t pad_048[0x1F0];
    float scale;            // +0x238 — world-units per cell
    float inv_scale;        // +0x23C — 1.0 / scale
    float origin_x;         // +0x240 — world X origin
    float origin_y;         // +0x244 — world Y origin
    uint8_t pad_248[0x08];
    int width;              // +0x250 — grid width (cells)
    int height;             // +0x254 — grid height (cells)
};

// ─── GroundGetPlaneEgg (FUN_004fecb0) ─────────────────────────
// Computes terrain plane equation and height for a world position.
// Returns the terrain cell at the given position, fills plane equation
// (4 floats: Nx, Ny, Nz, D), triangle index, and interpolated height.
// 109 callers — core terrain collision/physics function.
//
// Triangle types (from cell->flags & 7):
//   0 = flat, 1,2,6 = lower-left split, 3,4,5 = upper-right split
//
// @param pos          World position (x, y, z) — only x,y used for lookup
// @param out_plane    Output: 4-float plane equation (Nx, Ny, Nz, D)
// @param out_triangle Output: triangle index within cell (1-4, or 0)
// @param out_height   Output: interpolated height at position
// @param flags        Assertion/edge flags
// @return             Pointer to the terrain cell at the position
TerrainCell* GroundGetPlaneEgg(const float* pos, float* out_plane,
                                uint32_t* out_triangle, float* out_height,
                                int flags);  // FUN_004fecb0

} // namespace Giants
