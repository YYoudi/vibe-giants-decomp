// Giants Engine - FLICK Cinematic Script Interpreter
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_004e7b10 — Interprets FLICK opcode sequences for in-game cinematics.
// The FLICK system drives cutscenes via a switch/case on opcode bytes.

#pragma once

#include <cstdint>

namespace Giants {

// ─── ProcessFlickCommands (FUN_004e7b10) — FAIL (usable ~40%) ──
// Main FLICK interpreter loop. Reads opcode stream and dispatches.
// 23 callees, 1 caller. Partially reversed due to size (400+ lines).
//
// Known opcodes:
//   1 = InitDirector — create/lookup director object
//   2 = SetCameraTarget — set camera position/look-at
//   3 = CreateEntity — spawn cinematic entity with properties
//   4+ = ... (remaining opcodes not yet fully analyzed)
//
// @return 1 normally, or error code
uint32_t ProcessFlickCommands();   // FUN_004e7b10

// ─── FlickSetCameraTarget (FUN_004e5530) — PASS (usable ~75%) ──
// Initializes a FLICK actor/camera entity with target, animation path,
// and sub-entity slots. Called from opcode 2 (SetCameraTarget) in the
// FLICK interpreter.
//
// Performs:
//   1. Resolve camera target from context[0x27] + param_2 * 0xc
//   2. Create actor slot at context[0x28] + param_4 * 0x8e4
//   3. Initialize actor with entity type param_3
//   4. If target has animation path data, allocate and fill 0x58-byte
//      animation struct with frame mappings
//   5. Register actor with FLICK entity pool via FUN_006405d0
//   6. Initialize render state (FUN_0048f2f0 calls)
//
// @param param_1  FLICK context pointer
// @param param_2  Camera target index (slot in context[0x27])
// @param param_3  Entity type ID for the actor
// @param param_4  Actor slot index
// @param param_5  Sub-entity index (-1 = none)
// @return 1 on success, 0 on failure
uint32_t FlickSetCameraTarget(uint32_t* param_1, int param_2,
                              int param_3, int param_4, int param_5);  // FUN_004e5530

// ─── FlickFindEntityIndex (FUN_004e4d40) — PASS ────────────────
// Searches for an entity name in the scene entity table.
// Iterates over up to 128 entity slots (0x1000 / 0x20 stride),
// comparing each slot's name using FUN_00632950.
//
// @param param_1  Entity name/identifier to search for
// @return Entity index (0..127) if found, or -1 if not found
int FlickFindEntityIndex(uint32_t param_1);   // FUN_004e4d40

// ─── FlickLoadAnimationFile (FUN_004e5030) — PASS (usable ~85%) ─
// Loads a FLICK animation binary file from the VFS.
// Constructs the filename as "flk_<name>.bin" where name is either
// the param_1 directly or resolved from the scene entity table.
// Reads a header (0x18 bytes) then the body, returning a malloc'd
// buffer with header + body data.
//
// @param param_1  Animation name or entity identifier
// @return Pointer to loaded animation data, or nullptr if not found
uint32_t* FlickLoadAnimationFile(int param_1);   // FUN_004e5030

// ─── FlickCreateInterpreter (FUN_004e5150) — PASS (usable ~80%) ─
// Creates and initializes a new FLICK interpreter context.
// Allocates the context structure with entity pools, command tables,
// and animation data. Recursively loads referenced animation files.
//
// Context layout (0x140 bytes + variable pools):
//   [0x00]     = allocator handle
//   [0x01..0x20] = name buffer (0x7f bytes, from param_3)
//   [0x21]     = param_1 (command table base)
//   [0x22]     = param_1 + 0x18 (opcode pointer)
//   [0x24]     = entity count (from param_1 + 8)
//   [0x25]     = animation count (from param_1 + 0xc)
//   [0x26]     = path count (from param_1 + 0x10)
//   [0x27]     = entity pool (entityCount * 0xc bytes)
//   [0x28]     = actor pool (animCount * 0x8e4 bytes)
//   [0x29]     = path pool (pathCount * 0x380 bytes)
//   [0x32]     = sub-interpreter (recursive load)
//   [0x4e]     = 1000.0f (0x447a0000) — default duration
//
// @param param_1  Command data pointer (FLICK bytecode table)
// @param param_2  Parent interpreter handle
// @param param_3  Name string for this interpreter
// @return Pointer to initialized FLICK interpreter context
uint32_t* FlickCreateInterpreter(int param_1, uint32_t param_2, int param_3);  // FUN_004e5150

// ─── SetRenderFlags (FUN_0048f2f0) — PASS ──────────────────────
// Sets or clears render flags on a scene object with interpolation support.
// Manages per-slot render state (0x24-byte stride): saves current state for
// interpolation when transitioning, sets dirty flag 0x100.
// 423 callers, 0 callees (leaf function — extremely hot path).
void SetRenderFlags(
    int objectPtr,       // Scene object base pointer
    int slotIndex,       // Render state slot index
    uint32_t param_3,    // New render value 1
    uint32_t param_4,    // New render flags
    uint32_t param_5,    // New render value 2
    uint32_t param_6,    // New render value 3
    float duration       // Transition duration (0 = instant)
);  // FUN_0048f2f0

// ─── InitEntityRenderState (FUN_00559e60) — PASS ───────────────
// Initialize or copy an entity's render state. If sourceEntity is 0,
// frees sub-object array and releases 10 COM slots. If sourceEntity
// is non-null, copies sub-object table creating new COM objects.
// 11 callers, 6 callees.
void InitEntityRenderState(
    int entityState,      // Destination entity state
    int sourceEntity      // Source entity (0 = cleanup)
);  // FUN_00559e60

// ─── CopyEntityState (FUN_0055a4a0) — PASS ─────────────────────
// Copy full entity state from source to destination. Handles type change
// teardown, state block copy (0x80 bytes), render context creation,
// shadow texture cloning, and scene registration.
// 81 callers, 9 callees.
void CopyEntityState(
    int dstEntity,        // Destination entity
    int srcEntity         // Source entity
);  // FUN_0055a4a0

// ─── TransferEntityBones (FUN_0055a710) — PASS ─────────────────
// Transfer bone/skeleton data from source to destination entity.
// Copies render properties, sets modified flag, and remaps bone
// indices between source and destination skeletons (two-pass lookup).
// 72 callers, 6 callees.
void TransferEntityBones(
    int dstEntity,        // Destination entity
    int srcEntity         // Source entity
);  // FUN_0055a710

// ─── FindEntityTypeEntry (FUN_0055a8a0) — PASS ─────────────────
// Search the global entity type registry for a matching type ID.
// Walks linked list of entity arrays (stride 0x374), returns pointer
// to the matching entry's data area, or nullptr.
// 104 callers, 0 callees.
uint32_t* FindEntityTypeEntry(
    int entityTypeId      // Entity type ID to search for
);  // FUN_0055a8a0

// ─── CompareEntityName (FUN_00632950) — PASS (trivial) ─────────
// Case-insensitive string comparison for entity name matching.
// Used throughout FLICK system for entity/animation/scene names.
// 17 callers, 1 callee (_stricmp).
bool CompareEntityName(
    const char* name1,    // First name
    const char* name2     // Second name
);  // FUN_00632950

// ─── BuildSkinBinding (FUN_00633560) — PASS ────────────────────
// Build a skin/bone binding table for skeletal animation. Creates output
// structure with bone hierarchy, walks skeleton definition, and remaps
// bone indices from skeleton to animation tree. Error messages reference
// SKN (skin) and ANM (animation) files.
// 2 callers, 8 callees.
int BuildSkinBinding(
    int animContext,      // Animation context
    int treeName,         // Named tree for bone lookup (0 = default)
    int skinDef           // Skin definition entry
);  // FUN_00633560

// ─── CopyStringTruncated (FUN_006329a0) — PASS (trivial) ────────
// Safe string copy with guaranteed null termination: strncpy + null write.
// Used throughout FLICK and entity systems for bounded string operations.
// 12 callers, 1 callee (strncpy).
/// @param param_1  Destination buffer
/// @param param_2  Source string
/// @param param_3  Maximum bytes to copy (null written at param_1[param_3])
void CopyStringTruncated(char* param_1, char* param_2, size_t param_3);  // FUN_006329a0

} // namespace Giants
void LoadFlickScript(const char* flickName);
