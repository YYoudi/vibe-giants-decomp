// Giants Engine - Graphics Resource Initialization
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_004f7fa0 — PASS
//   Allocates 4 devices, 9 vertex/index buffers, and 2 heap blocks
//   via the renderer COM vtable. Called during engine initialization.

#pragma once

#include <cstdint>
#include <windows.h>

namespace Giants {

// ─── Graphics Resource Globals ───────────────────────────────────

// Primary renderer factory object (COM interface with vtable)
extern void* g_renderFactory;              // DAT_00702700 — IDirect3DDevice-like factory

// Device handles created from factory vtable[2] (CreateDevice)
extern void* g_device0;                    // DAT_00702708 — device handle 0
extern void* g_device1;                    // DAT_0070270c — device handle 1
extern void* g_device2;                    // DAT_00702710 — device handle 2
extern void* g_device3;                    // DAT_00702714 — device handle 3

// Buffer objects — created via factory vtable[4] (CreateBuffer)
// Group 0: bound to device 0 (g_device0 via DAT_0070270c)
extern void* g_buffer0;                    // DAT_00702718 — vertex buf, 2 elements, pool 2
extern void* g_buffer1;                    // DAT_0070271c — vertex buf, 128 elements, 128 stride
extern void* g_buffer2;                    // DAT_00702720 — vertex buf, 4000 elements

// Group 1: bound to device 1 (g_device1 via DAT_00702710)
extern void* g_buffer3;                    // DAT_00702724 — vertex buf, 256 elements
extern void* g_buffer4;                    // DAT_0070272c — vertex buf, 256 elements, 256 stride
extern void* g_buffer5;                    // DAT_00702728 — vertex buf, 512 elements

// Group 2: bound to device 2 (g_device2 via DAT_00702714)
extern void* g_buffer6;                    // DAT_00702730 — buf type 0, 32000 elements
extern void* g_buffer7;                    // DAT_00702734 — buf type 6, 32000 elements
extern void* g_buffer8;                    // DAT_00702738 — buf type 1 or 8, 32000 elements

// Heap allocation blocks
extern void* g_heapBlock0;                 // DAT_0070273c — malloc(0x5DC00) = 384,000 bytes
extern void* g_heapBlock1;                 // DAT_00702740 — malloc(0x5DC00) = 384,000 bytes

// ─── Renderer Mode ────────────────────────────────────────────────

extern int    g_rendererMode;              // DAT_00702be4 — renderer type (3 = DX11/12?)

// ─── Functions ────────────────────────────────────────────────────

/// Initialize all graphics resources via the renderer factory vtable.
/// Creates 4 devices, 9 buffers (vertex/index), and 2 heap blocks.
/// Called once during engine initialization by InitializeEngine.
void InitGraphicsResources();              // FUN_004f7fa0

// ─── Entity List Head ──────────────────────────────────────────────
// Linked list of renderable entities. Each node links to the next
// via its first DWORD. Entities have their state flags at offset +0x214.

extern void* g_entityListHead;             // DAT_007027a8 — first entity node

// ─── Render Buffer Objects (5 buffers) ─────────────────────────────
// These globals point to render buffer/state objects that are reset
// by ResetRenderBuffers (FUN_004e1cc0). Each buffer object has:
//   +0x14 : element count
//   +0x18 : data pointer
//   +0x1C : current write pointer (reset to data base)
//   +0x20 : read pointer (reset to data base)
//   +0x24 : end pointer (reset to data_base + (count*3-3)*8)
//   +0x38 : lock/semaphore (reset via FUN_0063e7f0)
//   +0x7C : counter (zeroed)

extern void*  g_renderBuf0;                // DAT_00701d04 — primary render buffer
extern void*  g_renderBuf1;                // DAT_00701d00 — secondary render buffer
extern void*  g_renderBuf2;                // DAT_00701ce4 — tertiary render buffer
extern void*  g_renderBuf3;                // DAT_00701ce8 — quaternary render buffer
extern void*  g_renderBuf4;                // DAT_00701cdc — quinary render buffer

// ─── Render Dispatch Function Pointer ──────────────────────────────
// Points to either FUN_004e07f0 (normal) or LAB_004e08c0 (fast path).
// Selection depends on DAT_007028b0 bit 7 (playerId & 0x80).

extern void (*g_renderDispatchFn)();       // PTR_FUN_0067d334

// ─── Player ID flag (used for render path selection) ───────────────
extern DWORD g_playerIdFlag;               // DAT_007028b0 — bit 7 selects render path

/// Reset all render buffers and clear entity visibility.
/// Walks the entity linked list, clearing bit 30 (0x40000000) from
/// each entity's state flags at offset +0x214. Then resets the 5
/// render buffer objects: rewinds write/read pointers, clears data,
/// releases locks, and zeroes counters. Selects the render dispatch
/// function based on player ID flags.
///
/// Ghidra: FUN_004e1cc0 (7 callers)
void ResetRenderBuffers();

} // namespace Giants
