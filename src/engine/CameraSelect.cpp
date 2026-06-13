// Giants Engine - Camera Selection Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "CameraSelect.h"
#include "ViewportBounds.h"
#include <cstdint>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
// Camera array base pointer
static int g_cameraArray = 2313688100;  // faithful @0x00702780
// Camera count (max valid index + 1)
static int g_cameraCount = 4294966111;  // faithful @0x00702784
// Active camera index
static int g_activeCameraIndex = 1150094453;  // faithful @0x00702788
// Camera state flags
static uint32_t g_cameraFlags = 3897564196u;  // faithful @0x0070278C

// ═══════════════════════════════════════════════════════════════════
// SelectCamera (FUN_00541690) — 26 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Selects the active camera by index.
// Clamps to valid range, updates global camera state, then triggers
// viewport bounds recomputation via ComputeViewportBounds.

void SelectCamera(int cameraIndex)
{
    // Clamp index to valid camera range
    int maxIndex = g_cameraCount;
    if (maxIndex <= 0) {
        g_activeCameraIndex = 0;
        return;
    }

    if (cameraIndex < 0) {
        cameraIndex = 0;
    } else if (cameraIndex >= maxIndex) {
        cameraIndex = maxIndex - 1;
    }

    // Update active camera index
    g_activeCameraIndex = cameraIndex;

    // Mark camera state as changed
    g_cameraFlags |= 0x01;

    // Recompute viewport bounds for the new camera
    // Each camera entry is 0x30 bytes, viewport data starts at camera + 0x14
    int cameraEntry = g_cameraArray + cameraIndex * 0x30;
    ComputeViewportBounds(
        reinterpret_cast<float*>(cameraEntry + 0x14),
        *reinterpret_cast<int*>(cameraEntry + 0x1c),
        *reinterpret_cast<int*>(cameraEntry + 0x20)
    );
}

} // namespace Giants
