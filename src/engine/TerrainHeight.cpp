// Giants Engine - Terrain Height & Plane Calculation Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "TerrainHeight.h"
#include "CRTStubs.h"
#include <cfloat>
#include <cmath>

namespace Giants {

// ─── Terrain globals ──────────────────────────────────────────
// TODO: Move to GiantsTypes.h once terrain module is fully mapped
static TerrainData* g_terrain = nullptr;              // DAT_XXXXXXXX — global terrain DB
static const float g_half = 0.5f;                     // DAT_XXXXXXXX — 0.5 constant
static const float g_one = 1.0f;                      // DAT_XXXXXXXX — 1.0 constant
static const uint32_t g_sign_mask = 0x80000000u;      // DAT_XXXXXXXX — sign bit mask for depth XOR
static bool g_terrain_assert_enabled = false;         // DAT_XXXXXXXX — terrain debug asserts

// External: error formatting and fatal exit
extern void FormatStringInternal(int level, int code, const char* msg);  // FUN_0043f440
extern void FatalExit();                                                              // FUN_004439b0
extern void SseSqrtAssert();                                                          // FUN_005f9b00
extern void UnreachableTrap();                                                        // FUN_0042bee0

// ═══════════════════════════════════════════════════════════════════
// GroundGetPlaneEgg (FUN_004fecb0) — 109 callers
// ═══════════════════════════════════════════════════════════════════
// Core terrain function: given a world position, computes the ground
// plane equation and interpolated height. Used for collision, physics,
// camera grounding, entity placement, AI navigation.
//
// Algorithm:
//   1. Convert world coords to grid coords (using origin + inv_scale)
//   2. Clamp to grid bounds
//   3. Look up terrain cell at grid position
//   4. Determine triangle type from cell flags
//   5. Compute plane normal via cross product of triangle edges
//   6. Apply depth XOR (g_sign_mask) to D component
//   7. Interpolate height from plane equation

TerrainCell* GroundGetPlaneEgg(const float* pos, float* out_plane,
                                uint32_t* out_triangle, float* out_height,
                                int flags)
{
    // ─── Null terrain check ────────────────────────────────────
    if (g_terrain->rows == nullptr) {
        // Terrain not loaded — fatal error
        // TODO: Use FormatString when available
        FormatStringInternal(6, 4, "ground_get_planegg: World terrain was not loaded");
        FatalExit();
        return nullptr;
    }

    // ─── World-to-grid conversion ──────────────────────────────
    float origin_x = g_terrain->origin_x;
    float inv_scale = g_terrain->inv_scale;
    float fx = (pos[0] - origin_x) * inv_scale;
    float fy = (pos[1] - g_terrain->origin_y) * inv_scale;

    // ─── Clamp to grid bounds ──────────────────────────────────
    float max_x = static_cast<float>(g_terrain->width - 1);
    float cx = fx;
    if (max_x <= fx) {
        cx = static_cast<float>(g_terrain->width - 2);
    }

    bool clamped_y = static_cast<float>(g_terrain->height - 1) <= fy;
    float cy = fy;
    if (clamped_y) {
        cy = static_cast<float>(g_terrain->height - 2);
    }

    bool clamped_x = cx < 0.0f;
    if (clamped_x) {
        cx = 0.0f;
    }

    bool clamped_y_neg = cy < 0.0f;
    if (clamped_y_neg) {
        cy = 0.0f;
    }

    // ─── Cell lookup ───────────────────────────────────────────
    int ix = static_cast<int>(cx);
    int iy = static_cast<int>(cy);

    int row_offset = ix * 0x1C;  // sizeof(TerrainCell)
    int row_ptr = reinterpret_cast<int>(g_terrain->rows[iy]);
    TerrainCell* cell = reinterpret_cast<TerrainCell*>(row_offset + row_ptr);

    float frac_x = cx - static_cast<float>(ix);
    uint32_t cell_type = cell->flags & 7;

    // ─── Triangle classification ───────────────────────────────
    // Types 1,2,6 → lower-left diagonal; Types 3,4,5 → upper-right diagonal
    uint32_t triangle = 0;
    switch (cell_type) {
    case 1: case 2: case 6:
        triangle = static_cast<uint32_t>(g_half - (fy - static_cast<float>(iy)) < frac_x) + 1;
        break;
    case 3: case 4: case 5:
        triangle = static_cast<uint32_t>(frac_x <= fy - static_cast<float>(iy)) + 3;
        break;
    default:
        triangle = 0;
        break;
    }

    // Safety: clamp triangle to cell type if mismatched
    if ((triangle != cell_type) && (cell_type < 5)) {
        triangle = 0;
    }

    // ─── Vertex height fetch ───────────────────────────────────
    float scale = g_terrain->scale;
    float v0x = scale * static_cast<float>(ix) + origin_x;
    float v0y = scale * static_cast<float>(iy) + g_terrain->origin_y;
    float v1x = static_cast<float>(ix + 1) * scale + origin_x;

    int row_ptr_i = reinterpret_cast<int>(g_terrain->rows[iy]);
    float h00 = cell->height;
    float h10 = *reinterpret_cast<float*>(row_ptr_i + (ix + 1) * 0x1C);

    int next_row_ptr = reinterpret_cast<int>(g_terrain->rows[iy + 1]);
    float h11 = *reinterpret_cast<float*>(next_row_ptr + (ix + 1) * 0x1C);
    float h01 = *reinterpret_cast<float*>(next_row_ptr + ix * 0x1C);
    float v1y = static_cast<float>(iy + 1) * scale + g_terrain->origin_y;

    // ─── Debug asserts ─────────────────────────────────────────
    if (g_terrain_assert_enabled && flags != 0) {
        SseSqrtAssert();
        SseSqrtAssert();
        SseSqrtAssert();
        SseSqrtAssert();
        // NOTE: Assert block has known variable mapping issues
        // from re-agent FAIL. Original Ghidra shows local_58=fVar15,
        // local_5c=local_58, local_4c=local_5c, local_50=fVar15
    }

    // ─── Plane normal computation ──────────────────────────────
    // Cross product of triangle edges, normalized
    uint32_t sign_mask = g_sign_mask;
    float nx, ny, nz, d;
    float det = 0.0f;

    switch (triangle) {
    case 1: {
        // Triangle: (v0x,h00,v0y) — (v1x,h10,v0y) — (v0x,h01,v1y)
        float e0x = v0x - v1x;
        float a = (v1y - v0y) * (h01 - h10) /* - (v0y - v0y) * (...) */;
        float b = (/* v0x - v1x */ e0x) * (h01 - h10) - e0x * (v1y - v0y);
        float c = e0x * (v1y - v0y);
        // NOTE: case 1 b,c simplified — original has 0 terms
        UnreachableTrap();
        det = 0.0f;
        float len_sq = a * a + b * b + c * c;
        if (0.0f < len_sq) {
            float inv = g_one / len_sq;
            a *= inv; b *= inv; c *= inv;
        }
        nx = a; ny = c; nz = b;
        { uint32_t tmp; float val = v0y * c + v1x * a + b * h10; memcpy(&tmp, &val, 4); tmp ^= sign_mask; memcpy(&d, &tmp, 4); }
        break;
    }
    case 2: {
        float e0x = v1x - v0x;
        float a = (v0y - v1y) * (h11 - h01);
        float b = (v1x - v0x) * (h10 - h01) - e0x * (h11 - h01);
        float c = e0x * (v1y - v0y);
        UnreachableTrap();
        det = 0.0f;
        float len_sq = a * a + b * b + c * c;
        if (0.0f < len_sq) {
            float inv = g_one / len_sq;
            a *= inv; b *= inv; c *= inv;
        }
        nx = a; ny = b; nz = c;
        { uint32_t tmp; float val = v1y * b + v0x * a + c * h01; memcpy(&tmp, &val, 4); tmp ^= sign_mask; memcpy(&d, &tmp, 4); }
        break;
    }
    case 3: {
        float e0y = v0y - v1y;
        float a = (v0y - v1y) * (h10 - h11) - e0y * (h01 - h11);
        float b = /* (v1x-v1x)=0 */ -(v0x - v1x) * (h10 - h11);
        float c = (v0x - v1x) * e0y;
        UnreachableTrap();
        det = 0.0f;
        float len_sq = a * a + b * b + c * c;
        if (0.0f < len_sq) {
            float inv = g_one / len_sq;
            a *= inv; b *= inv; c *= inv;
        }
        nx = a; ny = b; nz = c;
        { uint32_t tmp; float val = v1y * b + v1x * a + c * h11; memcpy(&tmp, &val, 4); tmp ^= sign_mask; memcpy(&d, &tmp, 4); }
        break;
    }
    case 4: {
        float e0y = v1y - v0y;
        float a = (v1y - v0y) * (h01 - h00) - e0y * (h11 - h00);
        float c = /* (v0x-v0x)=0 */ -(v1x - v0x) * (h01 - h00);
        float b = (v1x - v0x) * e0y;
        UnreachableTrap();
        det = 0.0f;
        float len_sq = a * a + b * b + c * c;
        if (0.0f < len_sq) {
            float inv = g_one / len_sq;
            a *= inv; b *= inv; c *= inv;
        }
        nx = a; ny = c; nz = b;
        { uint32_t tmp; float val = v0y * c + v0x * a + b * h00; memcpy(&tmp, &val, 4); tmp ^= sign_mask; memcpy(&d, &tmp, 4); }
        break;
    }
    default:
        nx = 0.0f;
        ny = 0.0f;
        nz = 1.0f;
        d = 0.0f;
        break;
    }

    // ─── Output ────────────────────────────────────────────────
    out_plane[0] = nx;
    out_plane[1] = ny;
    out_plane[2] = nz;
    out_plane[3] = d;

    if (out_triangle != nullptr) {
        *out_triangle = triangle;
    }

    // Height interpolation from plane equation
    constexpr float INVALID_HEIGHT = -61.1f;
    if (out_height != nullptr) {
        float height = INVALID_HEIGHT;
        bool in_bounds = !clamped_y_neg && !clamped_x && !clamped_y && (fx < max_x);
        if (in_bounds && nz != det) {
            // height = (Nx*px + Ny*py + D) / Nz  (with depth XOR on numerator)
            uint32_t tmp;
            float numerator = pos[1] * ny + pos[0] * nx + d;
            memcpy(&tmp, &numerator, 4);
            tmp ^= sign_mask;
            float xorResult;
            memcpy(&xorResult, &tmp, 4);
            height = xorResult / nz;
        }
        *out_height = (height < INVALID_HEIGHT) ? INVALID_HEIGHT : height;
    }

    return cell;
}

} // namespace Giants
