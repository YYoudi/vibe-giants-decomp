// Giants Engine - Entity Height Update Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityHeightUpdate.h"
#include <cstdint>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern float    DAT_0066bf2c;     // 1.0f — FlickInterpreter.cpp
extern float    DAT_0066bd58;     // Height scale — MathUtils.cpp
extern float    DAT_0066c0cc;     // Angle/height offset — MathUtils.cpp
extern int*     g_SomeGlobal;     // DAT_00702774 — Camera.cpp
extern char     DAT_00702c45;     // Camera state flag — Camera.cpp

// ─── Module-local constants ────────────────────────────────────
static float DAT_0066c0c4 = 80.0f;  // faithful @0x0066C0C4  // Max height (80.0f)
static float DAT_0066c2b8 = -90.0f;  // faithful @0x0066C2B8  // Min height (-90.0f)
// Height scale table — runtime-dumped from the original (file extraction gave
// garbage: this region is runtime-populated, not clean .rdata). Values verified
// via proxy probe: {0.5, 0.2, 0.1, 0.05}. Indexed by DAT_00681dc4 (0..3).
static const float DAT_0065c7d8[4] = {0.5f, 0.2f, 0.1f, 0.05f};  // runtime-verified @0x0065c7d8
static int DAT_00681dc4 = 0;  // Table index (BSS state, engine sets 0..3)

// ─── External callees ──────────────────────────────────────────
extern void FUN_0062a0b0();  // SSE2 sqrt/damping

// ═══════════════════════════════════════════════════════════════════
// UpdateEntityHeight (FUN_0056c1a0) — 17 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Updates entity vertical position based on input byte at +0x25d.
// The byte represents a joystick/input value that gets scaled to
// vertical velocity, then applied with time factor and clamping.

void UpdateEntityHeight(int entity)
{
    char inputByte = *reinterpret_cast<char*>(entity + 0x25d);
    if (inputByte == 0) {
        return;
    }

    // Scale input to velocity
    float inputScale = static_cast<float>(static_cast<int>(inputByte)) * DAT_0066bd58;

    // Get time factor: default 1.0f, or from table if camera state active
    float timeFactor = DAT_0066bf2c;
    if (DAT_00702c45 != '\0') {
        timeFactor = DAT_0065c7d8[DAT_00681dc4];
    }
    float adjustedTime = timeFactor;

    FUN_0062a0b0();

    // Apply to vertical position
    float newHeight = adjustedTime * inputScale * DAT_0066c0cc * timeFactor +
                      *reinterpret_cast<float*>(entity + 0x120);
    *reinterpret_cast<float*>(entity + 0x120) = newHeight;

    // Clamp for camera entity
    float maxVal = DAT_0066c0c4;
    if (entity == reinterpret_cast<int>(g_SomeGlobal) && DAT_0066c0c4 < newHeight) {
        *reinterpret_cast<uint32_t*>(entity + 0x120) = 0x42A00000;  // 80.0f
        newHeight = maxVal;
    }

    // Clamp minimum
    if (newHeight < DAT_0066c2b8) {
        *reinterpret_cast<uint32_t*>(entity + 0x120) = 0xC2B40000;  // -90.0f
    }
}

} // namespace Giants
