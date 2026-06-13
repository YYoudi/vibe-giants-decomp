// Giants Engine - Flick Animation & Player Init Stubs
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_00633480 — CreateDirectorObject: loads ANM file, registers in resource system
// FUN_00634e20 — ResolveFlickEntity: resolves entity by type, key, and name
// FUN_00501f50 — InitLevel: initializes game level, loads skybox texture

#pragma once

#include <cstdint>

namespace Giants {

// ─── CreateDirectorObject (FUN_00633480) — PASS ─────────────────
// Loads an ANM (animation) file and registers it in the resource system.
// Opens the file, reads header (8 bytes), allocates buffer, reads data,
// then creates a resource object via FUN_006406f0/FUN_006408c0.
// 2 callers, 8 callees.
/// Returns resource handle on success, 0 on failure.
int CreateDirectorObject(
    uint32_t allocatorCtx,  // param_1 — allocator context
    const char* filename,   // param_2 — ANM file path
    int* outHeader          // param_3 — receives file header
);  // FUN_00633480

// ─── ResolveFlickEntity (FUN_00634e20) — PASS ──────────────────
// Resolves a FLICK entity by navigating a two-level lookup table.
// First looks up by param_2 in the table at (param_1+0x20),
// then looks up param_3 in the resulting sub-table.
// Returns the resolved pointer, or 0 if not found.
// 16 callers, 2 callees (FUN_00640c20 + FUN_00640c60).
uint32_t ResolveFlickEntity(
    int param_1,        // entity context
    int param_2,        // primary key (entity type)
    uint32_t param_3    // secondary key (entity name)
);  // FUN_00634e20

// ─── InitLevel (FUN_00501f50) — PASS ────────────────────────────
// Initializes a game level: resets game state, loads skybox texture
// (FUN_005e9b20), initializes world (FUN_004d0e70), checks player
// type from registry. 7 callers, 6 callees.
/// Returns result code from FUN_004d0e70.
int InitLevel();  // FUN_00501f50

// ─── InitWorldSubsystem (FUN_004d0e70) — PASS ───────────────────
// Pushes a new entry onto the world/dialog level stack (max depth 9).
// Stores two context parameters and clears four state fields.
// 7 callers, 1 callee (FUN_00461e70 error handler).
void InitWorldSubsystem(
    uint32_t param_1,  // Context parameter 1
    uint32_t param_2   // Context parameter 2
);  // FUN_004d0e70

// ─── AllocateResourceBlock (FUN_006405d0) — PASS ────────────────
// Allocates a memory block from the engine's resource pool.
// If allocatorCtx is non-null, tries sub-allocator first, rounds size to
// 16-byte alignment, and inserts into an intrusive linked list for tracking.
// If zeroFill is set, zeroes the returned memory.
// Returns user-data pointer (header + 0x10) when tracked, raw pointer otherwise.
// 14 callers, 3 callees.
void* AllocateResourceBlock(
    int allocatorCtx,  // Allocator context (0 = untracked malloc)
    size_t size,       // Requested size in bytes
    int zeroFill       // If non-zero, memset returned block to 0
);  // FUN_006405d0

// ─── GetAllocatorContext (FUN_006406f0) — PASS ──────────────────
// Creates or patches an allocator context for resource management.
// If existingContext is non-null, walks and patches its linked list.
// Otherwise allocates a new context (0x24 or 0x40 bytes), registers with
// parent allocator, and initializes internal red-black tree + linked list.
// Returns pointer to the linked-list root of the context.
// 7 callers, 4 callees.
int GetAllocatorContext(
    int parentAllocator,   // Parent allocator (0 = root)
    int existingContext    // Existing context to patch (0 = create new)
);  // FUN_006406f0

// ─── GetResourceHandle (FUN_006408c0) — PASS (trivial) ──────────
// Returns the handle/count field at offset 0x1c from a resource context.
// 2 callers, 0 callees.
uint32_t GetResourceHandle(
    int contextPtr   // Resource context pointer
);  // FUN_006408c0

// ─── LookupTableEntry (FUN_00640c20) — PASS ─────────────────────
// Looks up a key in a hash/tree table. Delegates to the tree lookup
// function FUN_00640530 using the table root at tablePtr+4 and bucket 0.
// Returns the found entry, or 0 if not found.
// 7 callers, 1 callee (FUN_00640530).
int LookupTableEntry(
    int tablePtr,       // Table descriptor pointer
    uint32_t key        // Key to look up
);  // FUN_00640c20

// ─── GetSubTableData (FUN_00640c60) — PASS (trivial) ────────────
// Resolves a sub-table data pointer from a table entry.
// Reads the 16-bit offset at entry+2 and adds it to the entry base.
// 14 callers, 0 callees.
int GetSubTableData(
    int entryPtr   // Table entry pointer
);  // FUN_00640c60

// ─── ProcessRenderCookies (FUN_005e9ab0) — PASS ─────────────────
// Iterates two linked lists of render cookie structures, calling the
// render device vtable method at offset 0xC8 for each. Used during
// level initialization to process deferred render operations.
// 3 callers, 0 callees.
void ProcessRenderCookies();  // FUN_005e9ab0

// ─── RegisterAnimHandle (FUN_006331f0) — FAIL (usable ~65%) ─────
// Registers animation data into handle's lookup tables. Walks resource tree,
/// initializes sub-tables, resolves animator slots per entity type, applies
/// XOR depth key, links to global animation function table.
/// @param param_1  Handle/context pointer (animation data)
/// @param param_2  Registration context (frame counter for change detection)
void RegisterAnimHandle(int param_1, int param_2);  // FUN_006331f0

} // namespace Giants
