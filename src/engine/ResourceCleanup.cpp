// Giants Engine - Game Resource Cleanup Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ResourceCleanup.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

// ─── External functions (callees) ──────────────────────────────
extern void ReleaseRenderBuffer();      // FUN_004ea1b0
extern void* CleanupMeshResource();     // FUN_004ea130
extern void CleanupParticleSystem();    // FUN_004e9870

// ─── Globals ───────────────────────────────────────────────────
static int       g_renderCount = 0;          // DAT_0074892c
static int*      g_entityList = nullptr;     // DAT_00748b48 — linked list head
static int       g_renderBuffers[300] = {};  // DAT_00748b54 — 100 × 3-int structs
static uint32_t* g_objectList = nullptr;     // DAT_007027a8 — singly linked list
static uint32_t* g_meshList = nullptr;       // DAT_00747d40 — singly linked list
static int       g_hasParticles = 0;         // DAT_00748b44

// Game state block at 0x00702c00..0x00702c74
// Preserved fields during reset: 0x1c, 0x20 (mem pointers)
static uint32_t  g_gameState[29] = {};       // DAT_00702c00 (0x74 / 4 = 29)

// ═══════════════════════════════════════════════════════════════════
// ResetGameResources (FUN_00541080) — 34 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Five-phase cleanup:
//   Phase 1: Fixed array of render buffers (100 entries, 3 ints each)
//   Phase 2: Entity linked list — free per-entity render buffers
//   Phase 3: Object linked list — apply entity flag modifications
//   Phase 4: Mesh linked list — cleanup flagged mesh resources
//   Phase 5: Conditional particle system cleanup
//   Phase 6: Partial game state reset (preserve mem/size fields)

void ResetGameResources()
{
    g_renderCount = 0;

    // Phase 1: Free render buffer array (100 entries × 3 ints)
    // Layout: {ptr, count, _unused} from DAT_00748b54 to 0x749004
    int* entry = g_renderBuffers;
    do {
        if (entry[0] != 0) {
            // Release each sub-buffer
            for (int i = 0; i < entry[1]; i++) {
                ReleaseRenderBuffer();
            }
            free(reinterpret_cast<void*>(entry[0]));
            entry[0] = 0;
        }
        entry += 3;
    } while (reinterpret_cast<int>(entry) < 0x749004);

    // Phase 2: Entity linked list cleanup
    int iVar6 = reinterpret_cast<int>(g_entityList);
    uint32_t* puVar1;
    for (; puVar1 = g_objectList, iVar6 != 0;
         iVar6 = *reinterpret_cast<int*>(iVar6 + 0x50)) {
        if (*reinterpret_cast<int*>(iVar6 + 0x48) != 0) {
            for (int iVar7 = 0; iVar7 < *reinterpret_cast<int*>(iVar6 + 0x4c); iVar7++) {
                ReleaseRenderBuffer();
            }
            free(*reinterpret_cast<void**>(iVar6 + 0x48));
            *reinterpret_cast<uint32_t*>(iVar6 + 0x48) = 0;
        }
    }

    // Phase 3: Object list — flag modification for specific entity types
    // Check type == 0x4E ('N') and flag bit 0x400 set → set bit 0x8000
    for (; puVar1 != nullptr; puVar1 = reinterpret_cast<uint32_t*>(*puVar1)) {
        int entityData = puVar1[3];
        if ((*reinterpret_cast<int*>(entityData + 0x22c) == 0x4e) &&
            (*reinterpret_cast<uint32_t*>(entityData + 0x130) & 0x400) != 0) {
            *reinterpret_cast<uint32_t*>(entityData + 0x124) |= 0x8000;
        }
    }

    // Phase 4: Mesh list — cleanup flagged meshes (bit 0x4000)
    uint32_t* puVar4 = g_meshList;
    while (puVar4 != nullptr) {
        if ((puVar4[6] & 0x4000) == 0) {
            puVar4 = reinterpret_cast<uint32_t*>(*puVar4);
        } else {
            puVar4 = reinterpret_cast<uint32_t*>(CleanupMeshResource());
        }
    }

    // Phase 5: Conditional particle cleanup
    if (g_hasParticles != 0) {
        CleanupParticleSystem();
    }

    // Phase 6: Partial game state reset
    // Save mem/size fields, memset block, restore
    uint32_t savedMem2 = g_gameState[0x20 / 4];   // DAT_00702c20
    uint32_t savedMem1 = g_gameState[0x1c / 4];   // DAT_00702c1c

    memset(g_gameState, 0, 0x74);

    // Restore preserved fields
    g_gameState[0x1c / 4] = savedMem1;  // DAT_00702c1c
    g_gameState[0x24 / 4] = savedMem1;  // DAT_00702c24 = savedMem1
    g_gameState[0x20 / 4] = savedMem2;  // DAT_00702c20 = savedMem2
    g_gameState[0x28 / 4] = savedMem2;  // DAT_00702c28 = savedMem2
}

} // namespace Giants
