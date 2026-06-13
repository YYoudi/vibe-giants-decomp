// Giants Engine - Render Command Batch Processor Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "RenderCommandBatch.h"
#include <cstdint>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern void* DAT_00702700;      // g_renderDevice — EngineInit.h

// ─── External callees ──────────────────────────────────────────
extern void FUN_004e06c0();     // Render command dispatch
extern uint32_t FUN_00643f70(); // FloatToInt64 (__ftol2)

// ═══════════════════════════════════════════════════════════════════
// ProcessRenderCommands (FUN_004e0b70) — 20 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Processes render commands from a circular buffer of 0x18-byte entries.
//
// Buffer layout (param_1):
//   [+0x00] flags (bit 0: has callback, bit 1: color-fill mode)
//   [+0x04] field_4 (used for cmd count in color mode)
//   [+0x08..+0x0C] vtable callback (used if bit 0 set)
//   [+0x18] current entry pointer (iter)
//   [+0x1C] end entry pointer
//   [+0x24] wrap pointer
//   [+0x30..+0x34] output tracking
//
// Command entry layout (0x18 bytes):
//   [+0x04] int field_a
//   [+0x08] int field_b
//   [+0x0C] int color/ID
//   [+0x10] short field_d
//   [+0x14] short field_e
//
// Phase 1: vtable[0x2c] setup + vtable[0x50](hash, -1.0f) state init
// Phase 2: If bit 0 clear, call callback(0, 5)
// Phase 3: Process entries (dedup or color-fill depending on bit 1)
// Phase 4: If bit 0 set, finalize; else update buffer state

void ProcessRenderCommands(uint32_t* cmdBuffer)
{
    // Phase 1: Setup render state
    reinterpret_cast<void(*)()>(
        *reinterpret_cast<void**>(*reinterpret_cast<void**>(DAT_00702700) + 0x2c))();
    reinterpret_cast<void(*)(uint32_t, uint32_t)>(
        *reinterpret_cast<void**>(*reinterpret_cast<void**>(DAT_00702700) + 0x50))(
            0xB58637BD, 0xBF800000);

    uint32_t flags = cmdBuffer[0];

    // Phase 2: Optional callback init
    if ((~flags & 1) != 0) {
        reinterpret_cast<void(*)(int, int)>(
            *reinterpret_cast<void**>(cmdBuffer[0xC] + 4))(0, 5);
    }

    // Phase 3: Process command entries
    uint32_t* iter = reinterpret_cast<uint32_t*>(cmdBuffer[8]);

    if ((flags & 2) == 0) {
        // ── Mode 0: Strip duplicates ──
        int field_a = *reinterpret_cast<int*>(iter + 1);   // +0x04
        int field_b = *reinterpret_cast<int*>(iter + 2);   // +0x08
        int field_c = *reinterpret_cast<int*>(iter + 3);   // +0x0C
        uint32_t field_d = iter[4];                         // +0x10
        uint32_t field_e = iter[5];                         // +0x14

        if (iter != reinterpret_cast<uint32_t*>(cmdBuffer[7])) {
            do {
                iter += 6;  // next 0x18-byte entry
                if (reinterpret_cast<uint32_t*>(cmdBuffer[9]) < iter) {
                    iter = reinterpret_cast<uint32_t*>(cmdBuffer[6]);  // wrap
                }

                bool match = (field_a == *reinterpret_cast<int*>(iter + 1)) &&
                             (field_b == *reinterpret_cast<int*>(iter + 2)) &&
                             (field_c == *reinterpret_cast<int*>(iter + 3)) &&
                             (static_cast<uint16_t>(field_e >> 16) == *reinterpret_cast<uint16_t*>(iter + 5)) &&
                             (static_cast<uint16_t>(field_d >> 16) == *reinterpret_cast<uint16_t*>(iter + 4));

                if (match) {
                    // Merge: update high word of field_e from current entry
                    field_e = (static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(iter + 5)) << 16) |
                              static_cast<uint16_t>(field_e);
                    field_d = *reinterpret_cast<uint16_t*>(iter + 4) << 16;
                } else {
                    FUN_004e06c0();  // Dispatch command
                    field_a = *reinterpret_cast<int*>(iter + 1);
                    field_b = *reinterpret_cast<int*>(iter + 2);
                    field_c = *reinterpret_cast<int*>(iter + 3);
                    field_d = iter[4];
                    field_e = iter[5];
                }
            } while (iter != reinterpret_cast<uint32_t*>(cmdBuffer[7]));
        }

        // Check if merged fields differ → dispatch final
        if (static_cast<int16_t>(field_e) != static_cast<int16_t>(field_e >> 16)) {
            FUN_004e06c0();
        }
    } else {
        // ── Mode 1: Color-fill with sequential IDs ──
        if (iter != reinterpret_cast<uint32_t*>(cmdBuffer[7])) {
            do {
                uint32_t id = FUN_00643f70();  // Get sequential ID
                iter[3] = ((id << 8 | id) << 8 | id) << 8 | id;  // Replicate to all 4 bytes
                FUN_004e06c0();
                iter += 6;  // next 0x18-byte entry
                if (reinterpret_cast<uint32_t*>(cmdBuffer[9]) < iter) {
                    iter = reinterpret_cast<uint32_t*>(cmdBuffer[6]);  // wrap
                }
            } while (iter != reinterpret_cast<uint32_t*>(cmdBuffer[7]));
        }
        // Mark last entry
        iter[3] = 0xFFFFFFFF;
        FUN_004e06c0();
    }

    // Phase 4: Finalize
    if ((~flags & 1) == 0) {
        // No callback: update buffer state
        cmdBuffer[8] = reinterpret_cast<uint32_t>(iter);
        iter[4] = 0;
        iter[5] = 0;
        cmdBuffer[0x10] = cmdBuffer[3];
        cmdBuffer[0x11] = cmdBuffer[1];
        cmdBuffer[0x1F] = 0;
    } else {
        // With callback: release
        reinterpret_cast<void(*)(uint32_t)>(*reinterpret_cast<void**>(cmdBuffer[0xC] + 4))(
            cmdBuffer[0xC]);
    }

    // Restore render state
    reinterpret_cast<void(*)(uint32_t, uint32_t)>(
        *reinterpret_cast<void**>(*reinterpret_cast<void**>(DAT_00702700) + 0x50))(0, 0);
}

} // namespace Giants
