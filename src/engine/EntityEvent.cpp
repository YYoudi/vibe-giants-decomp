// Giants Engine - Entity Event Processing Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityEvent.h"
#include "CRTStubs.h"
#include <cstring>

namespace Giants {

// ─── Globals ──────────────────────────────────────────────────
static bool     g_StopProcessing1 = false;     // DAT_00748928 — event processing lock 1
static bool     g_StopProcessing2 = false;     // DAT_00748929 — event processing lock 2
static int      g_GameMode = 0;                // DAT_006ff960 — current game mode (6 = replay)
static float    g_GlobalScaleFactor = 1.0f;    // _DAT_0066bce4 — global world scale
static float    g_PlayerScaleMultiplier = 1.0f; // DAT_007028f4+0x16a8 — player scale
static uint8_t* g_EventBufferPtr = nullptr;    // DAT_0073d348 — replay event buffer write cursor

// Event handler table: 0x50 bytes per entity type, function pointer at offset 0
static uint8_t g_EventHandlers[0x50 * 0x6c] = {};  // DAT_00682ee8

// External callees
extern int   GetGlobalState();                    // FUN_0056e960
extern int   CheckCondition();                    // FUN_0045f460
extern void  FlushEventBuffer();                  // FUN_0046ccf0
extern void  ProcessEventSecondary(int, uint64_t*, uint32_t, uint32_t);  // FUN_00501010
extern void  HandleAudioEvent();                  // FUN_00557290

// ═══════════════════════════════════════════════════════════════════
// ProcessEntityEvent (FUN_00500d30) — 59 callers
// ═══════════════════════════════════════════════════════════════════
// Main entity event dispatcher. Handles event routing, scaling,
// replay recording, and audio triggers.
//
// NOTE: This function has known issues from re-agent FAIL verdict.
// Key areas needing manual verification:
//   - Control flow around g_GameMode == 6 check
//   - Event handler table indexing (g_EventHandlers + type * 0x50)
//   - param_4 byte offsets (8 vs 4)

void ProcessEntityEvent(int param_1, int param_2, int param_3,
                        uint64_t* param_4, uint32_t param_5,
                        float scaleIn, uint32_t extraIn)
{
    // ─── Early-out checks ─────────────────────────────────────
    if (g_StopProcessing1) return;
    if (g_StopProcessing2) return;

    // Entity visibility check (bit 26 of flags at +0x218)
    if (((*reinterpret_cast<uint32_t*>(param_2 + 0x218) & 0x4000000) != 0) &&
        (param_1 != 4) && (param_1 != 6))
    {
        return;
    }

    // ─── Owner resolution ─────────────────────────────────────
    // If entity has an owner (+0x264) and certain conditions, resolve up the chain
    if (((param_1 < 0x33) || (0x46 < param_1)) &&
        (*reinterpret_cast<int*>(param_2 + 0x264) != 0) &&
        ((*reinterpret_cast<uint32_t*>(param_2 + 0x214) & 0x4000000) != 0))
    {
        // Certain event types bypass owner resolution
        if (param_1 == 0xf) return;
        if (param_1 == 0x12) return;
        if (param_1 == 8) return;
        if (param_1 == 4) return;

        if (param_1 == 0x19) {
            // Event 0x19: resolve to owner
            param_2 = *reinterpret_cast<int*>(param_2 + 0x264);
        } else {
            // Loop resolution: walk owner chain
            do {
                if (param_1 == 0x32) {
                    param_2 = *reinterpret_cast<int*>(param_2 + 0x264);
                    goto after_owner_resolution;
                }
                param_2 = *reinterpret_cast<int*>(param_2 + 0x264);
                param_1 = 0xc;
            } while (*reinterpret_cast<int*>(param_2 + 0x264) != 0);
        }
    }

after_owner_resolution:
    // ─── Scale computation ────────────────────────────────────
    float local_scale = scaleIn;
    float local_scale2 = scaleIn;
    uint8_t local_flags = 0;
    uint32_t local_c = 0;
    uint32_t local_extra = extraIn;

    // Skip scaling for entities with bit 26 set
    if ((*reinterpret_cast<uint32_t*>(param_2 + 0x214) & 0x4000000) != 0) {
        goto check_audio_event;
    }

    // Apply entity-type-specific scale
    if ((param_3 != 0) && (*reinterpret_cast<int*>(param_3 + 0x22c) == 0x4d)) {
        int statePtr = GetGlobalState();
        uint8_t entityType = *reinterpret_cast<uint8_t*>(param_2 + 0x242);
        float entityScale = *reinterpret_cast<float*>(statePtr + 0x15c + static_cast<uint32_t>(entityType) * 4);

        if ((entityScale != g_GlobalScaleFactor) && (param_1 != 0xc)) {
            local_scale = entityScale * scaleIn;
            local_scale2 = local_scale;
        }
    }

    // Player-specific scale multiplier (event 0x19, types 1 or 2)
    if ((param_1 == 0x19) &&
        (*reinterpret_cast<uint8_t*>(param_2 + 0x242) == 1 ||
         *reinterpret_cast<uint8_t*>(param_2 + 0x242) == 2))
    {
        local_scale = scaleIn * g_PlayerScaleMultiplier;
        local_scale2 = local_scale;
    }

    // ─── Event dispatch ───────────────────────────────────────
    if (param_3 == 0) {
        goto check_game_mode;
    }

    // Non-replay mode: dispatch to registered handler
    if ((g_GameMode != 6) || (CheckCondition() != 0)) {
        int entityType = *reinterpret_cast<int*>(param_2 + 0x22c);
        if (entityType < 0x6c) {
            uintptr_t handlerSlot = reinterpret_cast<uintptr_t>(g_EventHandlers) + entityType * 0x50;
            // NOTE: Known issue — null check needs void** dereference
            auto handler = *reinterpret_cast<void**>(handlerSlot);
            if (handler != nullptr) {
                auto fn = reinterpret_cast<void(*)(int, float*, int, int, uint64_t*, uint32_t, uint32_t*)>(handler);
                fn(param_1, &local_scale, param_2, param_3, param_4, param_5, &local_c);
                local_scale2 = local_scale;
                local_flags = static_cast<uint8_t>(local_c);
            }
        }
        goto check_game_mode;
    }

    // ─── Replay recording (game mode 6) ───────────────────────
    {
        // Check buffer space
        if (static_cast<int>(reinterpret_cast<uintptr_t>(g_EventBufferPtr) - 0x1cf4cb) > 0x3ff) {
            FlushEventBuffer();
        }

        uint8_t* buf = g_EventBufferPtr;

        // Write event header
        *reinterpret_cast<uint32_t*>(buf) = 0;
        buf[0] = 9;  // Event type marker

        // Entity IDs
        *reinterpret_cast<uint32_t*>(buf + 6) = *reinterpret_cast<uint32_t*>(param_2 + 0x1d4);

        uint32_t targetId = 0;
        if (param_3 != 0) {
            targetId = *reinterpret_cast<uint32_t*>(param_3 + 0x1d4);
        }
        *reinterpret_cast<uint32_t*>(buf + 2) = targetId;

        // Event data (from param_4 or entity position)
        if (param_4 == nullptr) {
            *reinterpret_cast<uint64_t*>(buf + 10) = *reinterpret_cast<uint64_t*>(param_2 + 0xf0);
            // NOTE: Known issue — offset should be +4 not +8 from param_4
        } else {
            *reinterpret_cast<uint64_t*>(buf + 10) = *param_4;
        }

        // Event metadata
        *reinterpret_cast<char*>(buf + 1) = static_cast<char>(param_1);
        *reinterpret_cast<float*>(buf + 0x16) = local_scale2;
        *reinterpret_cast<uint32_t*>(buf + 0x1a) = local_extra;
        *reinterpret_cast<uint8_t*>(buf + 0x1e) = local_flags;

        // Advance buffer pointer (0x1F = 31 bytes per event)
        g_EventBufferPtr = buf + 0x1f;
        goto finalize;
    }

check_game_mode:
    // In replay mode, skip secondary processing
    if (g_GameMode == 6) {
        goto finalize;
    }
    ProcessEventSecondary(param_3, param_4, param_5, local_c);

finalize:
    if (g_StopProcessing1) return;

check_audio_event:
    // Audio event trigger: check entity distance and type
    if (((*reinterpret_cast<float*>(param_2 + 0x20c) <= *reinterpret_cast<float*>(param_2 + 0x2c8)) ||
         ((*reinterpret_cast<uint32_t*>(param_2 + 0x124) & 0x8000) != 0)) &&
        ((*reinterpret_cast<uint32_t*>(param_2 + 0x128) & 0xf) == 2))
    {
        HandleAudioEvent();
    }
}

} // namespace Giants
