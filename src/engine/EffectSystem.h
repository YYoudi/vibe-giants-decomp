// Giants Engine - Visual Effect System
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_004e9cd0 — fx_create: creates visual effects (particle systems, etc.)
// 169 callers — one of the most called game systems.

#pragma once

#include <cstdint>

namespace Giants {

// ─── Effect System Globals ──────────────────────────────────────
extern uint32_t  g_nextEffectId;         // DAT_00747d3c — auto-incrementing effect ID
extern uint32_t* g_effectListHead;       // DAT_00747d40 — linked list head
extern uint32_t* g_effectListTail;       // DAT_00747d44 — linked list tail

// ─── CreateEffect (FUN_004e9cd0) — PASS ─────────────────────────
// Creates a visual effect (particle system, muzzle flash, explosion, etc.)
// Allocates from a pool, links into doubly-linked list, copies parameters.
//
// Effect struct layout (0xE8 bytes = 58 DWORDs):
//   [+0x00] = prev link (uint32_t*)
//   [+0x04] = next link (uint32_t*)
//   [+0x08] = effect ID + lifetime (uint32_t)
//   [+0x14] = duration/timing (uint32_t)
//   [+0x18] = position X (float)
//   [+0x1C] = position Y (float)
//   [+0x20] = position Z (float)
//   [+0x24] = flags (uint32_t) — bitmask:
//             0x1000 = has origin entity
//             0x0004 = has target entity
//             0x4000 = flag bit 1 from param_3[4]
//             0x8000 = flag bit 2 from param_3[4]
//             0x10000 = flag bit 3 from param_3[4]
//             0x200000 = flag bit 4 from param_3[4]
//             0x20000 = flag bit 5 from param_3[4]
//   [+0x28..+0x4C] = name (char[32])
//   [+0x8C] = origin entity (uint32_t)
//   [+0x90] = target entity (uint32_t)
//   [+0x5C..+0x88] = bounding box / AABB (6 pairs of uint32_t, sentinel 0xFFFFFFFF)
//   [+0xD0] = custom data (uint32_t)
//
// param_2 flag bits:
//   0x01 = has position data (sets flag 0x1000, calls FUN_0063e480)
//   0x02 = has target data (offsets 0x34, 0x35)
//   0x04 = has entity reference (checks offset 0x124 & 0x400)
//   0x08 = has extended position (copies 3 uint32 from param_3)
//   0x10 = name from param_3 pointer (instead of FUN_004e9ab0 lookup)
//   0x20 = has render flags (translates param_3[4] bits to effect flags)
//   0x40 = has duration parameter (offset 0xC)
//   0x82 = skip creation entirely
//
// @param param_1  Effect name (null = use FUN_004e98e0 default)
// @param param_2  Flag bitmask controlling which params are used
// @param param_3  Parameter array (interpretation depends on param_2 flags)
// @return Pointer to allocated effect object, or nullptr on failure
uint32_t* CreateEffect(char* param_1, uint32_t param_2, int* param_3);   // FUN_004e9cd0

// ─── AllocateEffectNode (FUN_004e9c70) — PASS (trivial) ────────
// Allocates an effect node from the global pool.
// Returns nullptr if pool is exhausted.
// 1 caller (CreateEffect), 0 callees.
uint32_t* AllocateEffectNode();   // FUN_004e9c70

// ─── ResolveEffectOffset (FUN_004e9ab0) ──────────────────────────
// Resolves an effect parameter offset to a pointer/value.
// Used by CreateEffect to resolve name and position data.
// 1 caller, 0 callees.
char* ResolveEffectOffset(uint32_t cookie);   // FUN_004e9ab0

// ─── GetDefaultEffectName (FUN_004e98e0) ────────────────────────
// Returns the default effect name (used when param_1 is null).
// 1 caller, 0 callees.
const char* GetDefaultEffectName();   // FUN_004e98e0

// ─── InitEffectRenderState (FUN_0063e480) ───────────────────────
// Initializes the render state portion of an effect (bounding box, etc.).
// Called when flag 0x01 is set in CreateEffect.
// 1 caller, 0 callees.
void InitEffectRenderState(uint32_t* effect, int a, int b, int c);  // FUN_0063e480

// ─── PostEffectCreate (FUN_004eadd0) ────────────────────────────
// Post-creation callback for effects. Called after all fields are set.
// 1 caller, 0 callees.
void PostEffectCreate(int arg);   // FUN_004eadd0

} // namespace Giants
