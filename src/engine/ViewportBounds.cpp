// Giants Engine - Viewport Bounds Computation Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ViewportBounds.h"
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static int    g_renderActive = 0;        // DAT_007488e8
static float* g_cameraBounds = nullptr;  // DAT_007488f4
static float  g_cachedExtentX = 0.0f;    // DAT_00702c1c
static float  g_cachedExtentY = 0.0f;    // DAT_00702c20
static int    g_depthVal1 = 0;            // DAT_00727fbc
static int    g_depthVal2 = 0;            // DAT_00727fc0
static int    g_depthVal3 = 0;            // DAT_00727fc4

// ═══════════════════════════════════════════════════════════════════
// ComputeViewportBounds (FUN_005de3d0) — 24 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Extracts viewport extents from the active camera bounds.
// Updates cached extents (min/max), then writes viewport struct:
//   [0] = extentX (min/max of camera bounds[3] and [0])
//   [1] = extentY (min/max of camera bounds[4] and [1])
//   [2..4] = depth values from globals
//   [5] = extentX / width (scale X)
//   [6] = extentY / height (scale Y)

void ComputeViewportBounds(float* output, int width, int height)
{
    // Update cached extents from camera bounds
    if (g_renderActive != 0 && g_cameraBounds != nullptr) {
        float boundMax = g_cameraBounds[3];
        if (boundMax < g_cachedExtentX) {
            g_cachedExtentX = boundMax;
        } else {
            boundMax = g_cameraBounds[0];
            if (g_cachedExtentX < boundMax) {
                g_cachedExtentX = boundMax;
            }
        }

        float boundMaxY = g_cameraBounds[4];
        if (boundMaxY < g_cachedExtentY) {
            g_cachedExtentY = boundMaxY;
        } else {
            boundMaxY = g_cameraBounds[1];
            if (g_cachedExtentY < boundMaxY) {
                g_cachedExtentY = boundMaxY;
            }
        }
    }

    // Write viewport structure
    float extentX = g_cachedExtentX;
    output[0] = extentX;

    float extentY = g_cachedExtentY;
    output[1] = extentY;

    // Depth values (reinterpret int globals as float)
    float d1; memcpy(&d1, &g_depthVal1, 4);
    float d2; memcpy(&d2, &g_depthVal2, 4);
    float d3; memcpy(&d3, &g_depthVal3, 4);
    output[2] = d1;
    output[3] = d2;
    output[4] = d3;

    // Scale factors
    output[5] = extentX / static_cast<float>(width);
    output[6] = extentY / static_cast<float>(height);
}

} // namespace Giants
