// Giants Engine - Entity Clone/Spawn Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityCloneSpawn.h"
#include <cstdint>
#include <cstring>

namespace Giants {

// ─── Forward declarations ──────────────────────────────────────
extern int FUN_00559dc0();  // Allocate new entity from pool

// ═══════════════════════════════════════════════════════════════════
// CloneEntity (FUN_0055bce0) — 20 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Creates a clone of srcEntity in the entity pool.
// Copies: origin (3 floats at +0xf0), type (+0x1d8), flags (+0x114).
// Sets spawned flag (0x400000) on clone's +0x124.
// Links parent at +0x264, stores params at +0x268 and +0x26c.

int CloneEntity(int srcEntity, uint32_t param2, uint32_t param3)
{
    int newEntity = FUN_00559dc0();
    if (newEntity == 0) {
        return 0;
    }

    // Copy type
    *reinterpret_cast<uint32_t*>(newEntity + 0x1d8) =
        *reinterpret_cast<uint32_t*>(srcEntity + 0x1d8);

    // Copy origin (x, y as uint64, z as uint32)
    *reinterpret_cast<uint64_t*>(newEntity + 0xf0) =
        *reinterpret_cast<uint64_t*>(srcEntity + 0xf0);
    *reinterpret_cast<uint32_t*>(newEntity + 0xf8) =
        *reinterpret_cast<uint32_t*>(srcEntity + 0xf8);

    // Copy entity class/data pointer
    uint32_t classPtr = *reinterpret_cast<uint32_t*>(srcEntity + 0x114);
    *reinterpret_cast<uint32_t*>(newEntity + 0x114) = classPtr;

    // Mark as spawned
    *reinterpret_cast<uint32_t*>(newEntity + 0x124) |= 0x400000;

    // Link to parent and store params
    *reinterpret_cast<uint32_t*>(newEntity + 0x268) = param2;
    *reinterpret_cast<int*>(newEntity + 0x264) = srcEntity;  // parent ref
    *reinterpret_cast<uint32_t*>(newEntity + 0x26c) = param3;

    return newEntity;
}

} // namespace Giants
