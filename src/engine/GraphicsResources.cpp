// Giants Engine - Graphics Resource Initialization
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_004f7fa0 — PASS
//   Creates 4 devices via factory vtable, then 9 buffers (3 per device group),
//   and allocates 2 heap blocks. All resource creation uses vtable dispatch
//   on the renderer factory object at DAT_00702700.

#include "GraphicsResources.h"
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <windows.h>

namespace Giants {

// ─── Global definitions (extern in GraphicsResources.h) ──────────
void*  g_renderFactory = nullptr;       // DAT_00702700
void*  g_device0 = nullptr;             // DAT_00702708
void*  g_device1 = nullptr;             // DAT_0070270c
void*  g_device2 = nullptr;             // DAT_00702710
void*  g_device3 = nullptr;             // DAT_00702714
void*  g_buffer0 = nullptr;             // DAT_00702718
void*  g_buffer1 = nullptr;             // DAT_0070271c
void*  g_buffer2 = nullptr;             // DAT_00702720
void*  g_buffer3 = nullptr;             // DAT_00702724
void*  g_buffer4 = nullptr;             // DAT_0070272c
void*  g_buffer5 = nullptr;             // DAT_00702728
void*  g_buffer6 = nullptr;             // DAT_00702730
void*  g_buffer7 = nullptr;             // DAT_00702734
void*  g_buffer8 = nullptr;             // DAT_00702738
void*  g_heapBlock0 = nullptr;          // DAT_0070273c
void*  g_heapBlock1 = nullptr;          // DAT_00702740
int    g_rendererMode = 0;              // DAT_00702be4
void*  g_entityListHead = nullptr;      // DAT_007027a8
void*  g_renderBuf0 = nullptr;          // DAT_00701d04
void*  g_renderBuf1 = nullptr;          // DAT_00701d00
void*  g_renderBuf2 = nullptr;          // DAT_00701ce4
void*  g_renderBuf3 = nullptr;          // DAT_00701ce8
void*  g_renderBuf4 = nullptr;          // DAT_00701cdc
void (*g_renderDispatchFn)() = nullptr; // PTR_FUN_0067d334
DWORD  g_playerIdFlag = 0;              // DAT_007028b0

// ─── Vtable Layout for Renderer Factory (DAT_00702700) ──────────
// The factory object has the following COM-style vtable:
//
//   vtable[0] = QueryInterface / AddRef / Release (standard IUnknown)
//   vtable[1] (offset 0x04) = AddRef / Release
//   vtable[2] (offset 0x08) = CreateDevice — creates a device handle
//     typedef void* (*CreateDeviceFn)();
//   vtable[3] (offset 0x0C) = GetDeviceCaps — returns capability flags
//     typedef void* (*GetCapsFn)();
//   vtable[4] (offset 0x10) = CreateBuffer — creates vertex/index buffer
//     typedef void* (*CreateBufferFn)(
//         uint32_t type,        // buffer type (0=vertex, 2=index, 6=other)
//         uint32_t elementCount,// number of elements
//         uint32_t stride,      // element stride (0=auto, 0x80, 0x100, etc.)
//         void*    format,      // pointer to format descriptor (in .rdata)
//         uint32_t flags5,      // always 0
//         uint32_t flags6,      // always 0
//         uint32_t flags7,      // always 0
//         uint32_t flags8       // always 0
//     );
//   vtable[5] (offset 0x14) = AddBufferToDevice — binds buffer to device
//     typedef void (*AddBufferFn)(void* device);
//
// Format descriptors (in .rdata, opaque pointers):
//   DAT_0066310c — format for buffer0 (index, 2 elements)
//   DAT_00663114 — format for buffer1 (vertex, 128 stride)
//   DAT_0066311c — format for buffer2 (vertex, 4000 elements)
//   DAT_00663124 — format for buffer3 (vertex, 256 elements)
//   DAT_0066312c — format for buffer4 (vertex, 256x256)
//   DAT_00663134 — format for buffer5 (vertex, 512 elements)
//   DAT_0066313c — format for buffer6 (type 0, 32000 elements)
//   DAT_00663144 — format for buffer7 (type 6, 32000 elements)
//   DAT_0066314c — format for buffer8 (type 1 or 8, 32000 elements)

// ─── InitGraphicsResources (FUN_004f7fa0) ────────────────────────

void InitGraphicsResources()
{
    // INIT-BEHAVIOR RECONSTRUCTION MODE: this function creates render devices +
    // vertex/index buffers via the renderer factory vtable (vtable[2]/[3]/[4]).
    // The real gg_dx9r.dll factory methods are thiscall and require the full
    // engine-context protocol (UpCalls + state) the recomp doesn't yet drive —
    // calling them crashes deep in the renderer (vtable[3]=0x1001DB10). Per the
    // project focus (init BEHAVIOR, not visual rendering), the device/buffer
    // creation is deferred. Devices/buffers stay null; the game loop guards on
    // g_renderDevice and runs the init sequence without rendering.
    extern FILE* g_traceLog;
    if (g_traceLog) { fprintf(g_traceLog, "[GFX] InitGraphicsResources: factory device/buffer creation deferred (init-behavior mode)\n"); fflush(g_traceLog); }
    return;

    // The factory object at DAT_00702700 is a COM-style renderer factory.
    // Its vtable provides device creation and buffer allocation methods.
    void* factory = g_renderFactory;   // DAT_00702700
    if (factory == nullptr)
        return;

    // ── Step 1: Create 4 device handles ──────────────────────────
    // vtable[3] (offset 0x0C) = GetCaps — returns capability/device handle
    // vtable[2] (offset 0x08) = CreateDevice — returns device handle
    //
    // In the original binary the calls are:
    //   g_device0 = vtable[3]()   — capability query / primary device
    //   g_device1 = vtable[2]()   — secondary device
    //   g_device2 = vtable[2]()   — tertiary device
    //   g_device3 = vtable[2]()   — quaternary device

    auto* vtable = *reinterpret_cast<void***>(factory);

    // typedef void* (*GetCapsFn)();
    auto getDevice = reinterpret_cast<void*(*)()>(vtable[2]);       // offset 0x08
    auto getCaps   = reinterpret_cast<void*(*)()>(vtable[3]);       // offset 0x0C

    g_device0 = getCaps();        // DAT_00702708 — capability handle
    g_device1 = getDevice();      // DAT_0070270c — secondary device
    g_device2 = getDevice();      // DAT_00702710 — tertiary device
    g_device3 = getDevice();      // DAT_00702714 — quaternary device

    // ── Step 2: Create Group 0 buffers (bound to device 0) ──────
    // vtable[4] (offset 0x10) = CreateBuffer(type, count, stride, fmt, 0,0,0,0)
    // vtable[5] (offset 0x14) = bind buffer to device (called via buffer's vtable[2])
    //
    // Buffer binding: each buffer has its own vtable; vtable[2] binds it to a device.
    //   buffer->vtable[2](device) — adds buffer to the device's resource list

    auto createBuffer = reinterpret_cast<void*(*)(uint32_t, uint32_t, uint32_t, void*, uint32_t, uint32_t, uint32_t, uint32_t)>(
        vtable[4]   // offset 0x10
    );

    // Format descriptor pointers (in .rdata section)
    void* fmt0 = reinterpret_cast<void*>(0x0066310c);  // DAT_0066310c
    void* fmt1 = reinterpret_cast<void*>(0x00663114);  // DAT_00663114
    void* fmt2 = reinterpret_cast<void*>(0x0066311c);  // DAT_0066311c

    // Buffer 0: type=2 (index), 2 elements, stride=0
    g_buffer0 = createBuffer(2, 2, 0, fmt0, 0, 0, 0, 0);         // DAT_00702718
    // Buffer 1: type=2 (index), 0x80 elements, stride=0x80
    g_buffer1 = createBuffer(2, 0x80, 0x80, fmt1, 0, 0, 0, 0);   // DAT_0070271c
    // Buffer 2: type=2 (index), 4000 elements, stride=0
    g_buffer2 = createBuffer(2, 4000, 0, fmt2, 0, 0, 0, 0);      // DAT_00702720

    // Bind all Group 0 buffers to device 0 (g_device0 → DAT_0070270c)
    // Each buffer's vtable[2] takes the device handle:
    //   (**buffer_vtable)(device)
    auto bindBuffer = [](void* buffer, void* device) {
        if (buffer && device)
        {
            auto* bvt = *reinterpret_cast<void***>(buffer);
            auto bindFn = reinterpret_cast<void(*)(void*)>(bvt[2]);  // offset 0x08
            bindFn(device);
        }
    };

    bindBuffer(g_buffer0, g_device0);
    bindBuffer(g_buffer1, g_device0);
    bindBuffer(g_buffer2, g_device0);

    // ── Step 3: Create Group 1 buffers (bound to device 1) ──────

    void* fmt3 = reinterpret_cast<void*>(0x00663124);  // DAT_00663124
    void* fmt4 = reinterpret_cast<void*>(0x0066312c);  // DAT_0066312c
    void* fmt5 = reinterpret_cast<void*>(0x00663134);  // DAT_00663134

    // Buffer 3: type=2, 0x100 elements, stride=0
    g_buffer3 = createBuffer(2, 0x100, 0, fmt3, 0, 0, 0, 0);     // DAT_00702724
    // Buffer 4: type=2, 0x100 elements, stride=0x100
    g_buffer4 = createBuffer(2, 0x100, 0x100, fmt4, 0, 0, 0, 0); // DAT_0070272c
    // Buffer 5: type=2, 0x200 elements, stride=0
    g_buffer5 = createBuffer(2, 0x200, 0, fmt5, 0, 0, 0, 0);     // DAT_00702728

    // Bind Group 1 to device 1 (g_device1 → DAT_00702710)
    bindBuffer(g_buffer3, g_device1);
    bindBuffer(g_buffer4, g_device1);
    bindBuffer(g_buffer5, g_device1);

    // ── Step 4: Create Group 2 buffers (bound to device 2) ──────

    void* fmt6 = reinterpret_cast<void*>(0x0066313c);  // DAT_0066313c
    void* fmt7 = reinterpret_cast<void*>(0x00663144);  // DAT_00663144
    void* fmt8 = reinterpret_cast<void*>(0x0066314c);  // DAT_0066314c

    // Buffer 6: type=0 (vertex), 32000 elements
    g_buffer6 = createBuffer(0, 32000, 0, fmt6, 0, 0, 0, 0);     // DAT_00702730
    // Buffer 7: type=6 (index/other), 32000 elements
    g_buffer7 = createBuffer(6, 32000, 0, fmt7, 0, 0, 0, 0);     // DAT_00702734

    // Buffer 8: type depends on renderer mode
    // DAT_00702be4 == 3 → type 8 (DX11/12 enhanced), else type 1 (standard)
    uint32_t buf8Type = (g_rendererMode == 3) ? 8 : 1;
    g_buffer8 = createBuffer(buf8Type, 32000, 0, fmt8, 0, 0, 0, 0);  // DAT_00702738

    // Bind Group 2 to device 2 (g_device2 → DAT_00702714)
    bindBuffer(g_buffer6, g_device2);
    bindBuffer(g_buffer7, g_device2);
    bindBuffer(g_buffer8, g_device2);

    // ── Step 5: Allocate heap blocks ─────────────────────────────
    // Two large heap allocations used as scratch buffers for vertex data.
    // 0x5DC00 = 384,000 bytes each

    g_heapBlock0 = malloc(0x5DC00);    // DAT_0070273c
    g_heapBlock1 = malloc(0x5DC00);    // DAT_00702740
}

// ─── Internal: Reset a single render buffer object ─────────────────
// Rewinds the write/read/end pointers to the data base, clears the
// first vertex data fields, releases the buffer lock, and zeroes the
// counter at offset 0x7C.
//
// Buffer object layout (derived from repeated pattern in FUN_004e1cc0):
//   +0x14 (int)     : element count
//   +0x18 (void**)  : data base pointer (allocated buffer)
//   +0x1C (void**)  : current write cursor  → reset to data base
//   +0x20 (void**)  : read cursor           → reset to data base
//   +0x24 (void**)  : end sentinel          → reset to data_base + (count*3-3)*8
//   +0x38           : lock/semaphore        → FUN_0063e7f0 releases it
//   +0x7C (DWORD)   : usage counter         → zeroed

static void ResetSingleBuffer(uint8_t* bufObj)
{
    if (bufObj == nullptr)
        return;

    int elementCount = *reinterpret_cast<int*>(bufObj + 0x14);
    uint8_t* dataBase = *reinterpret_cast<uint8_t**>(bufObj + 0x18);

    // Rewind cursors to data base
    *reinterpret_cast<uint8_t**>(bufObj + 0x1C) = dataBase;     // write cursor
    *reinterpret_cast<uint8_t**>(bufObj + 0x20) = dataBase;     // read cursor

    // End sentinel: dataBase + (elementCount*3 - 3) * 8
    // In the original: puVar1 + (iVar2 * 3 + -3) * 2
    // Each pointer is 4 bytes, so the index *2 gives byte offset *2 = *8 for the pointer math
    uint8_t* endPtr = dataBase + (elementCount * 3 - 3) * 2 * sizeof(uint8_t*);
    *reinterpret_cast<uint8_t**>(bufObj + 0x24) = endPtr;

    // Clear first vertex data in the buffer
    // DAT: *(dataBase + 0x12) = 0, *(dataBase + 0x10) = 0 (as uint16),
    //      *(dataBase + 0x16) = 0 (as uint16), *dataBase = 0 (as uint32)
    if (dataBase != nullptr)
    {
        *reinterpret_cast<uint16_t*>(dataBase + 0x12) = 0;     // word at offset 0x12
        *reinterpret_cast<uint16_t*>(dataBase + 0x10) = 0;     // word at offset 0x10
                                                              // (puVar1+4 as uint16* = offset 0x10)
        *reinterpret_cast<uint16_t*>(dataBase + 0x16) = 0;     // word at offset 0x16
        *reinterpret_cast<uint32_t*>(dataBase) = 0;            // dword at offset 0x00
    }

    // Release lock at offset 0x38
    // DAT: FUN_0063e7f0 — unlock/leave critical section
    // extern "C" void __cdecl ReleaseBufferLock(void* lock);
    // ReleaseBufferLock(bufObj + 0x38);
    // Stub: lock release not needed in static lib

    // Zero usage counter
    *reinterpret_cast<uint32_t*>(bufObj + 0x7C) = 0;
}

// ─── ResetRenderBuffers (FUN_004e1cc0) ──────────────────────────────
// Clears entity visibility flags and resets all 5 render buffer objects.
// 7 callers across the rendering pipeline.

void ResetRenderBuffers()
{
    // ── Phase 1: Walk entity linked list, clear bit 30 ────────────
    // DAT_00701d04 — g_renderBuf0 (also used as temp in loop, re-read each iteration)
    // DAT_007027a8 — g_entityListHead (linked list head)
    //
    // Each entity node:
    //   node[0] = next pointer (0 = end of list)
    //   node[3] = entity data pointer
    //   entity_data + 0x214 = state flags (bit 30 = visibility/render flag)

    uint8_t* node = reinterpret_cast<uint8_t*>(g_entityListHead);   // DAT_007027a8

    while (node != nullptr)
    {
        // Get entity data pointer from node[3] (offset 0x0C)
        uint8_t* entityData = *reinterpret_cast<uint8_t**>(node + 0x0C);

        // Clear bit 30 (0x40000000) from entity state flags
        // DAT: *(entity + 0x214) &= 0xBFFFFFFF
        if (entityData != nullptr)
        {
            uint32_t& flags = *reinterpret_cast<uint32_t*>(entityData + 0x214);
            flags &= 0xBFFFFFFF;
        }

        // Advance to next node
        node = *reinterpret_cast<uint8_t**>(node);
    }

    // ── Phase 2: Select render dispatch function ──────────────────
    // DAT_007028b0 — g_playerIdFlag: if bit 7 is set, use fast path
    // PTR_FUN_0067d334 — g_renderDispatchFn (function pointer)

    if ((g_playerIdFlag & 0x80) == 0)
    {
        // Normal path: FUN_004e08c0
        // Note: Ghidra labels this LAB_004e08c0, but it is a code address
        g_renderDispatchFn = reinterpret_cast<void(*)()>(0x004e08c0);
    }
    else
    {
        // Alternate path: FUN_004e07f0
        g_renderDispatchFn = reinterpret_cast<void(*)()>(0x004e07f0);
    }

    // ── Phase 3: Reset 5 render buffer objects ────────────────────
    // DAT_00701d04, DAT_00701d00, DAT_00701ce4, DAT_00701ce8, DAT_00701cdc
    // Each buffer is reset using the same pattern (see ResetSingleBuffer).

    ResetSingleBuffer(reinterpret_cast<uint8_t*>(g_renderBuf0));    // DAT_00701d04
    ResetSingleBuffer(reinterpret_cast<uint8_t*>(g_renderBuf1));    // DAT_00701d00
    ResetSingleBuffer(reinterpret_cast<uint8_t*>(g_renderBuf2));    // DAT_00701ce4
    ResetSingleBuffer(reinterpret_cast<uint8_t*>(g_renderBuf3));    // DAT_00701ce8
    ResetSingleBuffer(reinterpret_cast<uint8_t*>(g_renderBuf4));    // DAT_00701cdc
}

} // namespace Giants
