// Giants Engine - Flick Animation & Player Init Stubs Implementation
// Reverse engineered from GiantsMain.exe v1.520.59

#include "FlickAnim.h"
#include "CRTStubs.h"
#include "ReplayFileStubs.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>

namespace Giants {

// ─── External globals ───────────────────────────────────────────

extern void* g_renderDevice;  // DAT_00702700

// ═══════════════════════════════════════════════════════════════════
// CreateDirectorObject — FUN_00633480
// ═══════════════════════════════════════════════════════════════════

int CreateDirectorObject(uint32_t allocatorCtx, const char* filename, int* outHeader)
{
    uint32_t fileLoaded = 0;

    if (filename != nullptr)
    {
        FILE* fp = fopen(filename, "rb");
        if (fp == nullptr)
        {
            DebugPrintf("Error loading ANM_Anim \"%s\"\n", filename);
        }
        else
        {
            // Read 8-byte header: size + magic/version
            int header[2];
            fread(header, 8, 1, fp);

            // Allocate buffer for full file content
            int fileSize = header[0];  // First 4 bytes = data size
            int* data = (int*)malloc(fileSize);  // FUN_006405d0 in original
            data[0] = fileSize;
            data[1] = header[1];

            // Read remaining data
            fread(data + 2, fileSize - 8, 1, fp);
            fclose(fp);

            fileLoaded = 1;
            outHeader = data;
        }
    }

    if (outHeader == nullptr)
        return 0;

    // Create resource object via allocator system
    // FUN_006406f0(allocatorCtx, outHeader) → resource ID
    // FUN_006408c0(resourceId) → resource handle
    // FUN_006331f0(handle, &local_14) — register in lookup table
    // *(uint*)(handle + 8) = fileLoaded | (uint)outHeader

    return 0;  // Stub: resource handle
}

// ═══════════════════════════════════════════════════════════════════
// ResolveFlickEntity — FUN_00634e20
// ═══════════════════════════════════════════════════════════════════

uint32_t ResolveFlickEntity(int param_1, int param_2, uint32_t param_3)
{
    uint32_t subTablePtr;

    if (param_2 == 0)
    {
        // Primary key is 0: use default table at (param_1 + 0x24)
        subTablePtr = *(uint32_t*)(param_1 + 0x24);
    }
    else
    {
        // Look up primary key in table at (param_1 + 0x20)
        // FUN_00640c20(table, key) → entry
        int entry = 0;  // FUN_00640c20(*(uint32_t*)(param_1 + 0x20), param_2)
        if (entry == 0)
            return 0;

        // Get sub-table pointer from entry
        // FUN_00640c60(entry) → sub-table data
        uint32_t* subTableData = nullptr;  // FUN_00640c60(entry)
        subTablePtr = *subTableData;
    }

    // Look up secondary key in sub-table
    int subEntry = 0;  // FUN_00640c20(subTablePtr, param_3)
    if (subEntry == 0)
        return 0;

    // Get final value
    uint32_t* result = nullptr;  // FUN_00640c60(subEntry)
    return *result;
}

// ═══════════════════════════════════════════════════════════════════
// InitLevel — FUN_00501f50
// ═══════════════════════════════════════════════════════════════════

int InitLevel()
{
    // ── Phase 1: Reset game state ───────────────────────────────
    // FUN_005e9ab0(cookie) — security check
    // DAT_00702aec = 1  (level active)
    // DAT_00748940 = 0  (entity count)
    // DAT_00748950 = 0  (render target count)
    // DAT_00748948 = 1.0f  (scale X)
    // DAT_00748944 = 1.0f  (scale Y)
    // FUN_005e9ff0(ecx, DAT_00748960) — finalize previous level
    // DAT_00748954..960 = 0  (clear state)

    // ── Phase 2: Get player manager ─────────────────────────────
    // FUN_00461a60(&local_2c) — get player manager
    // local_24 = vtable[0x10](DAT_0074893c) — get current player

    // ── Phase 3: Check player type ──────────────────────────────
    // Read player name from local_24 + 0x04 (SSO string)
    // toupper first char: if 'K' → Kabuto, else if 'R' → Reaper, else Delphi
    // (This determines which character the player controls)

    // ── Phase 4: Load skybox texture ────────────────────────────
    // FUN_005e9b20(&DAT_00748958, &DAT_0074895c, &DAT_00748960)
    // — loads skybox TGA into tiled texture array

    // ── Phase 5: Initialize world ───────────────────────────────
    // DAT_00682204 = -1  (world state sentinel)
    // FUN_004d0e70() — initialize world subsystem

    // ── Phase 6: Release player manager ─────────────────────────
    // Ref-counted release of local_28 (COM object)

    return 0;  // Stub: result from FUN_004d0e70
}

// ─── InitWorldSubsystem (FUN_004d0e70) ──────────────────────────
// Ghidra: FUN_004d0e70 (7 callers, 1 callee)
// Purpose: Push a new entry onto the world/dialog level stack.
//   Validates depth (max 9), then stores two params and clears
//   four state fields in the stack frame.
// Original:
// void __fastcall FUN_004d0e70(undefined4 param_1,undefined4 param_2)
// {
//   int iVar1;
//   if (9 < DAT_00682204) {
//     FUN_00461e70("Overflow of dialog level stack",0x1e);
//     DAT_00682204 = DAT_00682204 + -1;
//   }
//   iVar1 = DAT_00682204 + 1;
//   DAT_00682204 = iVar1;
//   (&DAT_00747b60)[iVar1 * 6] = param_1;
//   (&DAT_00747b64)[iVar1 * 6] = param_2;
//   (&DAT_00747b68)[iVar1 * 6] = 0;
//   (&DAT_00747b6c)[iVar1 * 6] = 0;
//   (&DAT_00747b70)[iVar1 * 6] = 0;
//   (&DAT_00747b74)[iVar1 * 6] = 0;
//   return;
// }
void InitWorldSubsystem(uint32_t param_1, uint32_t param_2)
{
    // DAT_00682204 declared in CRTStubs.h

    if (9 < DAT_00682204) {
        // FUN_00461e70("Overflow of dialog level stack", 0x1e);
        DAT_00682204--;
    }

    int depth = DAT_00682204 + 1;
    DAT_00682204 = depth;

    // Stack frame: 6 uint32_t entries per level (stride = 24 bytes)
    extern uint32_t DAT_00747b60[];  // World stack base
    int idx = depth * 6;
    DAT_00747b60[idx + 0] = param_1;  // Context param 1
    DAT_00747b60[idx + 1] = param_2;  // Context param 2
    DAT_00747b60[idx + 2] = 0;       // State field 1
    DAT_00747b60[idx + 3] = 0;       // State field 2
    DAT_00747b60[idx + 4] = 0;       // State field 3
    DAT_00747b60[idx + 5] = 0;       // State field 4
}

// ─── AllocateResourceBlock (FUN_006405d0) ───────────────────────
// Ghidra: FUN_006405d0 (14 callers, 3 callees)
// Purpose: Allocate a block from the resource pool. If param_1 (allocator
//   context) is non-null, tries the sub-allocator at ctx+0xc first. Rounds
//   size up to 16-byte alignment. If param_3 is set, zeroes the block.
//   Returns a tracking header: [prev_link, self_link, size, refcount, user_data...].
//   User data starts at offset 0x10 from the raw allocation.
// Original:
// void * FUN_006405d0(int param_1,size_t param_2,int param_3)
// {
//   void *_Dst; undefined4 *puVar1;
//   if (param_2 == 0) return (void *)0x0;
//   if (param_1 != 0) {
//     param_2 = param_2 + 0x1f & 0xfffffff0;
//     if (*(int *)(param_1 + 0xc) != 0) {
//       _Dst = (void *)FUN_006405d0(*(int *)(param_1 + 0xc),param_2,param_3);
//       if (_Dst != (void *)0x0) goto LAB_00640616;
//     }
//   }
//   _Dst = (void *)(*(code *)PTR_FUN_0067d250)(param_2);
// LAB_00640616:
//   if (param_3 != 0) { memset(_Dst,0,param_2); }
//   if (param_1 != 0) {
//     puVar1 = (undefined4 *)((int)_Dst + 4);
//     *puVar1 = puVar1;
//     *puVar1 = *(undefined4 *)(param_1 + 0x10);
//     *(undefined4 **)(param_1 + 0x10) = puVar1;
//     *(size_t *)((int)_Dst + 8) = param_2;
//     *(undefined4 *)((int)_Dst + 0xc) = 1;
//     *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + param_2;
//     *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
//     return (void *)((int)_Dst + 0x10);
//   }
//   return _Dst;
// }
void* AllocateResourceBlock(int allocatorCtx, size_t size, int zeroFill)
{
    if (size == 0) {
        return nullptr;
    }

    void* block = nullptr;

    if (allocatorCtx != 0) {
        // Round up to 16-byte alignment
        size = (size + 0x1f) & ~(size_t)0xF;

        // Try sub-allocator at ctx+0xc first
        int subAllocator = *(int*)(allocatorCtx + 0xc);
        if (subAllocator != 0) {
            block = AllocateResourceBlock(subAllocator, size, zeroFill);
        }
    }

    if (block == nullptr) {
        // Allocate via general allocator (PTR_FUN_0067d250 = malloc-like)
        block = malloc(size);
    }

    if (zeroFill != 0 && block != nullptr) {
        memset(block, 0, size);
    }

    if (allocatorCtx != 0 && block != nullptr) {
        // Insert into intrusive linked list at allocatorCtx+0x10
        // Block header layout: [0x00]=prev, [0x04]=next, [0x08]=size, [0x0C]=refcount
        uint32_t* node = (uint32_t*)((uint8_t*)block + 4);
        node[0] = (uint32_t)(uintptr_t)node;  // Self-reference (circular list insert)
        node[0] = *(uint32_t*)(allocatorCtx + 0x10);  // Link to existing head
        *(uint32_t**)(allocatorCtx + 0x10) = node;

        node[1] = (uint32_t)size;    // Store allocated size
        node[2] = 1;                 // Initial refcount

        // Update allocator stats
        *(int*)(allocatorCtx + 0x14) += (int)size;  // Total bytes allocated
        *(int*)(allocatorCtx + 0x18) += 1;           // Allocation count

        return (void*)((uint8_t*)block + 0x10);  // Return user-data pointer past header
    }

    return block;
}

// ─── GetAllocatorContext (FUN_006406f0) ─────────────────────────
// Ghidra: FUN_006406f0 (7 callers, 4 callees)
// Purpose: Creates or reuses an allocator context. If param_2 is non-null,
//   walks an existing context's linked list and patches offsets via FUN_006408d0.
//   If param_2 is null, creates a fresh allocator context (0x24 or 0x40 bytes),
//   registers it with the parent allocator (param_1), and initializes the
//   internal red-black tree root and linked list sentinel.
//   Returns a pointer to the internal linked-list root of the new context.
// Original:
// int FUN_006406f0(int param_1,int param_2) { ... 70 lines ... }
int GetAllocatorContext(int parentAllocator, int existingContext)
{
    if (existingContext != 0) {
        // Patch existing context: walk linked list and fix up offsets
        int base = *(int*)(existingContext + 4) + existingContext;
        int patchCtx[2] = { existingContext, 1 };

        int* node = (int*)(base + 0x10);
        do {
            // FUN_006408d0(node, patchCtx) — relocate/patch node
            node = (int*)*node;
        } while (node != (int*)(base + 0x10));

        // FUN_006408d0(base + 0x1c, patchCtx) — patch tree root
        // FUN_006408d0(base + 0xc, patchCtx)  — patch list head
        *(int*)(base + 0xc) = parentAllocator;
        return base;
    }

    // Create new allocator context
    size_t allocSize = 0x24;
    if (parentAllocator != 0) {
        allocSize = 0x40;
    }

    void* mem = nullptr;
    if (parentAllocator != 0) {
        // Try sub-allocator
        int subAlloc = *(int*)(parentAllocator + 0xc);
        if (subAlloc != 0) {
            mem = AllocateResourceBlock(subAlloc, 0x40, 1);
        }
    }

    if (mem == nullptr) {
        mem = malloc(allocSize);
    }

    memset(mem, 0, allocSize);

    // Register with parent allocator (same linked-list insert as AllocateResourceBlock)
    if (parentAllocator != 0) {
        uint32_t* node = (uint32_t*)((uint8_t*)mem + 4);
        node[0] = (uint32_t)(uintptr_t)node;
        node[0] = *(uint32_t*)(parentAllocator + 0x10);
        *(uint32_t**)(parentAllocator + 0x10) = node;
        node[1] = (uint32_t)allocSize;
        node[2] = 1;
        *(int*)(parentAllocator + 0x14) += (int)allocSize;
        *(int*)(parentAllocator + 0x18) += 1;
        mem = (void*)((uint8_t*)mem + 0x10);
    }

    // Initialize context structure
    int* ctx = (int*)mem;
    ctx[4] = parentAllocator;          // [0x10] = parent allocator

    // Initialize circular linked list at ctx+0x14
    int* listHead = &ctx[5];           // ctx + 0x14
    *listHead = (int)listHead;         // Self-referential sentinel
    ctx[6] = 0;                        // ctx + 0x18 = tree root (null)
    ctx[7] = 0;                        // ctx + 0x1c = tree count (0)

    // Insert listHead into the circular list (insert after sentinel)
    int* tail = &ctx[5];
    *listHead = *tail;                 // Point to current tail
    *tail = (int)listHead;             // Tail now points to new head

    // Store allocation metadata
    ctx[2] = 0x24;                     // ctx + 0x08 = block size
    ctx[3] = 1;                        // ctx + 0x0c = refcount
    ctx[6] += 0x24;                    // ctx + 0x18 = total allocated (self)
    ctx[7] += 1;                       // ctx + 0x1c = allocation count

    // Store list root pointer at ctx + 0x20
    ctx[8] = (int)listHead;

    return (int)listHead;
}

// ─── GetResourceHandle (FUN_006408c0) ───────────────────────────
// Ghidra: FUN_006408c0 (2 callers, 0 callees)
// Purpose: Trivial accessor — returns the handle/count field at offset 0x1c
//   from the given allocator/resource context. Used after GetAllocatorContext
//   to retrieve the resource tracking handle.
// Original:
// undefined4 FUN_006408c0(int param_1)
// {
//   return *(undefined4 *)(param_1 + 0x1c);
// }
uint32_t GetResourceHandle(int contextPtr)
{
    return *(uint32_t*)(contextPtr + 0x1c);
}

// ─── LookupTableEntry (FUN_00640c20) ────────────────────────────
// Ghidra: FUN_00640c20 (7 callers, 1 callee)
// Purpose: Look up an entry in a hash/tree table. Delegates to FUN_00640530
//   passing the table root (at param_1+4), the key (param_2), and bucket 0.
//   The underlying function walks a red-black tree to find the entry.
// Original:
// void FUN_00640c20(int param_1,undefined4 param_2)
// {
//   FUN_00640530(*(undefined4 *)(param_1 + 4),param_2,0);
//   return;
// }
int LookupTableEntry(int tablePtr, uint32_t key)
{
    // Delegate to the tree lookup: FUN_00640530(tableRoot, key, bucketIndex)
    // FUN_00640530(*(uint32_t*)(tablePtr + 4), key, 0)
    // Stub: return 0 (not found)
    return 0;
}

// ─── GetSubTableData (FUN_00640c60) ─────────────────────────────
// Ghidra: FUN_00640c60 (14 callers, 0 callees)
// Purpose: Compute a pointer into sub-table data from a table entry.
//   Reads the 16-bit offset at entry+2 and adds it to the entry base address.
//   This resolves the "value" pointer from a key-value entry in the
//   engine's hash/tree tables.
// Original:
// int FUN_00640c60(int param_1)
// {
//   return (uint)*(ushort *)(param_1 + 2) + param_1;
// }
int GetSubTableData(int entryPtr)
{
    return (uint16_t)*(uint16_t*)(entryPtr + 2) + entryPtr;
}

// ─── ProcessRenderCookies (FUN_005e9ab0) ────────────────────────
// Ghidra: FUN_005e9ab0 (3 callers, 0 callees)
// Purpose: Iterates over two linked lists of render "cookie" structures and
//   calls the render device vtable method at offset 200 (0xC8) for each cookie.
//   First list (DAT_0074b820): each node has an array of entries at +0x2C,
//   with count at +0x28. Second list (DAT_0074b824): single entries at +4.
//   Used during InitLevel to process deferred render state.
// Original:
// void FUN_005e9ab0(void)
// {
//   undefined4 *puVar1; undefined4 *puVar2; uint uVar3;
//   for (puVar1 = DAT_0074b820; puVar2 = DAT_0074b824, puVar1 != (undefined4 *)0x0;
//       puVar1 = (undefined4 *)*puVar1) {
//     uVar3 = 0;
//     if (puVar1[10] != 0) {
//       puVar2 = puVar1 + 0xb;
//       do {
//         (**(code **)(*DAT_00702700 + 200))(puVar2);
//         uVar3 = uVar3 + 1; puVar2 = puVar2 + 0xc;
//       } while (uVar3 < (uint)puVar1[10]);
//     }
//   }
//   for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
//     (**(code **)(*DAT_00702700 + 200))(puVar2 + 1);
//   }
//   return;
// }
void ProcessRenderCookies()
{
    extern void* g_renderDevice;  // DAT_00702700
    extern uint32_t* DAT_0074b820;  // Primary cookie list head
    extern uint32_t* DAT_0074b824;  // Secondary cookie list head

    // Phase 1: Walk primary cookie list (array entries per node)
    for (uint32_t* node = DAT_0074b820; node != nullptr; node = (uint32_t*)*node) {
        uint32_t count = node[10];  // Array count at +0x28
        if (count != 0) {
            uint32_t* entries = node + 0xb;  // Array start at +0x2C
            for (uint32_t i = 0; i < count; i++) {
                // Call renderDevice->vtable[50] (offset 200 = 0xC8)
                // This processes a deferred render operation
                // (*(g_renderDevice->vtable + 0xC8))(entries);
                (void)entries;
                entries += 0xc;  // 12 uint32_t stride per entry
            }
        }
    }

    // Phase 2: Walk secondary cookie list (single entries)
    for (uint32_t* node2 = DAT_0074b824; node2 != nullptr; node2 = (uint32_t*)*node2) {
        // Call renderDevice->vtable[50] (node2 + 4)
        // (*(g_renderDevice->vtable + 0xC8))(node2 + 1);
        (void)node2;
    }
}

// ═══════════════════════════════════════════════════════════════════
// RegisterAnimHandle — FUN_006331f0
// ═══════════════════════════════════════════════════════════════════
// Registers animation data into a handle's lookup tables. Walks the
// handle's resource tree (FUN_00640c40/FUN_00640c60), initializes sub-tables
// via FUN_006408d0, then for each entity entry:
//   - Resolves animator slots (up to 3 per entity, type-dependent)
//   - Applies XOR depth key (DAT_0066c580) to transform data
//   - Links animator entries to global animation table (DAT_0067d008)
// Supports entity types 1 (single animator), 2 (rotation+scale), 3 (recursive).
// 1 caller (CreateDirectorObject), 5 callees.

void RegisterAnimHandle(int param_1, int param_2)
{
    // Original:
    // FUN_006408d0(param_1 + 0xc, param_2);  // init sub-table
    // puVar1 = param_1 + 0x20;
    // FUN_006408d0(puVar1, param_2);
    // FUN_006408d0(param_1 + 0x24, param_2);
    // FUN_00640b60(*puVar1, &LAB_00640b50, param_2);
    //
    // Outer loop: walk top-level entries via FUN_00640c40
    //   For each top-level entry, walk children:
    //     Init sub-tables (puVar6+3,4,5) via FUN_006408d0
    //     For entity type 1: init animator at +0x27
    //     For entity type 2 or 3: init animators at +0x26,27,28
    //     If sub-entity flag (*(short*)(puVar6+1) == 1): init +0x3e,3f,40
    //     Apply XOR key DAT_0066c580 to transform fields (+0x1e,1f,20)
    //     Link animator pointers to DAT_0067d008 table:
    //       if (animator != null) animator[1] = DAT_0067d008[animator[0] * 0xC]
    //     This resolves animation function pointers from global table
}

} // namespace Giants
