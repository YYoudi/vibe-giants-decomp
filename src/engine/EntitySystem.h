#pragma once

#include <cstdint>

// ============================================================================
// EntitySystem.h — Entity management, camera, FX, sound, game state functions
// Reverse-engineered from GiantsMain.exe v1.520.59 via Ghidra decompilation
// ============================================================================

namespace Giants {

// ---------------------------------------------------------------------------
// Entity Factory & Lifecycle
// ---------------------------------------------------------------------------

// FUN_005d6d00 — FAIL — Allocates entity by type ID (40+ types)
// Caller count: 6. Switch on entityType, operator_new + memset for each type.
void* EntityFactoryCreate(uint32_t entityType);

// FUN_0055cda0 — FAIL — Creates entity, sets up ref-counted wrapper
// Caller count: 6. Allocates 0x14-byte wrapper, links into observer list.
void EntityCreateAndRegister(int entityDef);

// FUN_0055cae0 — FAIL — Frees type-specific data via vtable
// Caller count: 8. Calls type destructor, frees sub-objects, releases refs.
void EntityDestructor(int entityPtr);

// FUN_00503330 — PASS — Copies weapon/action slots between type-2 entities
// Caller count: 2. Copies 10 DWORDs from src+0x14c offsets to dst+0x14c.
void CopyEntityWeaponSlots(int* dstEntity, int* srcEntity);

// FUN_0055a400 — PASS — Copies animation/matrix data (offsets 0x60-0xEC)
// Caller count: 3. Block copy of 36 DWORDs covering animation state.
void CopyEntityAnimationData(int* dstEntity, int* srcEntity);

// FUN_0055a680 — PASS — Copies world transform + velocity (0xF0-0x120)
// Caller count: 10. Copies position, orientation, velocity (10 fields).
void CopyEntityPositionVelocity(int* dstEntity, int* srcEntity);

// FUN_0055cd40 — PASS — Uses vtable to get size, memcpy sub-data
// Caller count: 2. Queries vtable for data size, then memcpy.
void CopyEntityTypeSpecificData(int* dstEntity, int* srcEntity);

// ---------------------------------------------------------------------------
// Entity Search & Linking
// ---------------------------------------------------------------------------

// FUN_004ffb40 — PASS — Walks linked list matching owner + slot
// Caller count: 49. Linear search on DAT_007027c0 linked list.
int* FindEntityByOwnerSlot(int ownerId, int slotId);

// FUN_004ffba0 — FAIL — Switches entity slot type, sends network packets
// Caller count: 22. Updates entity state flags, sends network message.
void EntityStateTransition(int entityId, uint32_t param2, int param3);

// FUN_004ea1b0 — FAIL — Removes entity from linked list (123 callers)
// Caller count: 123. Walks DAT_007027e0, calls FUN_004e9fc0 for match.
void UnlinkEntity(int* entityPtr);

// ---------------------------------------------------------------------------
// Game Object Factory
// ---------------------------------------------------------------------------

// FUN_004743f0 — FAIL — mallocs 0x3D50 entity, initializes vtables
// Caller count: 1. Allocates game object, sets up Window/Table vtable entries.
void* GameObjectFactoryCreate();

// ---------------------------------------------------------------------------
// Entity Tick & Update
// ---------------------------------------------------------------------------

// FUN_005908e0 — PASS — Copies position from global data, clears motion flag
// Caller count: 2. Reads DAT_007028f4+0x704/0x708, clears bit 8 of flags.
void EntityTickUpdate(int entityPtr);

// ---------------------------------------------------------------------------
// Camera System
// ---------------------------------------------------------------------------

// FUN_005eddc0 — FAIL — Clears camera target, sends network disconnect
// Caller count: 7. Clears camera entity link, resets camera state globals.
void CameraDetach(int entityPtr);

// FUN_00563520 — FAIL — Reads path data, applies position
// Caller count: 2. Reads interpolated path data, sets camera position+velocity.
void CameraUpdateNetworkSync();

// FUN_004fccc0 — FAIL — Interpolated camera positions
// Caller count: 6. Complex camera path update with multiple path types.
void CameraPathTick();

// ---------------------------------------------------------------------------
// Random Events & Animation
// ---------------------------------------------------------------------------

// FUN_005f7fc0 — FAIL — Applies fog/ambient/rotation from data
// Caller count: 4. Reads event data, interpolates fog/ambient/rotation.
void ApplyRandomEvent(void* param1, char param2);

// FUN_00634700 — FAIL — Binary search, lerp, wrap/clamp
// Caller count: 20. Keyframe interpolation with binary search.
void AnimateKeyframeInterpolation(int param1, int param2);

// ---------------------------------------------------------------------------
// Object Cleanup
// ---------------------------------------------------------------------------

// FUN_004e1e60 — FAIL — Frees 7 linked game objects
// Caller count: 1. Sequentially frees 7 global object pointers.
void MultiObjectDestructor();

// FUN_005c1ec0 — FAIL — Frees 3 buffer pairs from game object
// Caller count: 2. Releases renderer sub-objects via vtable + free.
void RendererSubObjectCleanup();

// FUN_005c1fe0 — FAIL — Walks function pointer array, compacts list
// Caller count: 3. Calls each callback, removes failed entries via memmove.
void CallbackListCleanup();

// ---------------------------------------------------------------------------
// FX / Effects
// ---------------------------------------------------------------------------

// FUN_004e9cd0 — FAIL — Creates visual effect node (169 callers)
// Caller count: 169. Allocates FX node, links to active list, sets params.
void* CreateFXEffect(char* name, uint32_t param2, int* param3);

// ---------------------------------------------------------------------------
// Sound System
// ---------------------------------------------------------------------------

// FUN_005583d0 — FAIL — Plays sound effect via callback
// Caller count: 17. Dispatches sound playback through multiple code paths.
void PlaySoundEffect(int soundHandle);

// FUN_005584d0 — FAIL — Returns node to free list
// Caller count: 15. Unlinks sound node, pushes to DAT_007496bc free list.
int ReleaseSoundNode(int* nodePtr);

// ---------------------------------------------------------------------------
// Entity Map & Lookup
// ---------------------------------------------------------------------------

// FUN_00627080 — FAIL — Walks hash table bucket
// Caller count: 3. Hash table lookup using bucket index from param3.
void EntityMapLookup(void* result, uint32_t param2, uint32_t param3);

// ---------------------------------------------------------------------------
// Scene & Game State
// ---------------------------------------------------------------------------

// FUN_004a4b40 — FAIL — Sends network packet, resets camera
// Caller count: 2. Network disconnect + camera/projection reset.
void SceneCameraReset(uint32_t param1);

// FUN_0052e310 — FAIL — Sends network disconnect, copies state
// Caller count: 2. Copies 0x22 DWORDs from save buffer to game state.
void GameStateSaveRestore(int param1);

// FUN_00541a50 — FAIL — Dialog push, registry reads
// Caller count: 5. Game init: dialog stack, registry, display mode.
void GameInitialization();

// FUN_00501ab0 — FAIL — Handles mode switch (load/clear/setup/save)
// Caller count: 3. Mode dispatcher for game state transitions.
int GameModeDispatch(int mode);

// FUN_004ae170 — FAIL — Smartie/Mecc weapon selection
// Caller count: 1. Complex weapon/action dispatch based on player type.
void WeaponActionDispatch(int param1, int param2);

// FUN_00557cc0 — FAIL — Reads binary SFX entries
// Caller count: 1. Loads SFX sound bank from file/buffer into global table.
void LoadSFXSoundBank(int* param1);

// FUN_00559dc0 — FAIL — Spawn object by type ID (142 callers)
// Core spawning: allocate slot, lookup type, init entity, set position
int SpawnObjectByType(uint32_t objectType, int positionParam);  // FUN_00559dc0

// ---------------------------------------------------------------------------
// Sound Dispatch
// ---------------------------------------------------------------------------

// FUN_00558240 — Walks entity list to tail, dispatches sound play variant
// Caller count: 65. Two dispatch paths: on-screen vs off-screen.
uint32_t SoundDispatch(uint32_t param_1, int param_2);  // FUN_00558240

// ---------------------------------------------------------------------------
// Entity Lifecycle
// ---------------------------------------------------------------------------

// FUN_004e9fc0 — Disconnects entity: FX effect, sound stop, observer notify
// Caller count: 8. Sets bit 0x8000 (detached flag) on entity.
void EntityCleanup(int param_1, int param_2, int param_3);  // FUN_004e9fc0

// FUN_004ea130 — Returns entity node to free-list allocator
// Caller count: 5. Maintains DAT_00747d30/DAT_00747d44 linked list pool.
int EntityPoolReturn(int* param_1);  // FUN_004ea130

// FUN_00586090 — Zero-initializes ~4KB game entity struct
// Caller count: 2. Only non-zero field: offset 0x3D9 = 1.0f (scale).
uint32_t* EntityZeroInit(uint32_t* param_1);  // FUN_00586090

// FUN_0056e760 — Initializes weapon/projectile with default tuning data
// Caller count: 2. All data constants (speed=50, range=1000, scale=1.0, etc.)
uint32_t* WeaponDefaultsInit(uint32_t* param_1);  // FUN_0056e760

// FUN_0055d050 — Hash table observer slot update with callback dispatch
// Caller count: 2. Iterates observers backward, calls vtable callbacks.
void ObserverSlotUpdate(uint32_t* param_1);  // FUN_0055d050

// FUN_0055ca70 — Releases entity mesh buffer via renderer vtable + free
// Caller count: 1. Checks 0x330 mesh object, releases vertex buffer, frees memory.
void EntityMeshBufferCleanup(int param_1);  // FUN_0055ca70

// FUN_0058e220 — Dispatches network event to type 0x3E entities
// Caller count: 3. Walks entity list, matches target ID at offset 0x2c4.
void NetworkEventDispatch(int param_1, uint32_t* param_2, uint32_t param_3, uint32_t param_4);  // FUN_0058e220

// FUN_0055c150 — Updates entity position with cache invalidation
// Caller count: 121. Sets position (0xf0-0xf8), frees mesh cache if changed,
// shifts position history (previous←current, old←previous).
void SetEntityPosition(int param_1, float x, float y, float z);  // FUN_0055c150

// FUN_005581d0 — Plays sound via observer callback (off-screen variant)
// Caller count: 147. Slot lookup in DAT_00702800 table, dispatch to callback.
uint32_t PlaySoundAImpl(int param_1, uint32_t param_2);  // FUN_005581d0

// FUN_00558360 — Plays sound via observer callback (on-screen variant)
// Caller count: 302. Same as PlaySoundA with extra parameter.
uint32_t PlaySoundBImpl(int param_1, uint32_t param_2);  // FUN_00558360

// FUN_0062a0b0 — Spatial sound/visibility listener check
// Caller count: 438. Iterates listener list, checks 2D distance + angle
// + entity ID matching + type filtering. Returns 1 if sound should play.
int SpatialSoundCheck(int param_1, int param_2);  // FUN_0062a0b0

// FUN_004a67b0 — Entity weapon/action slot range check
// Caller count: 99. Resolves entity slot, checks type-specific range.
int WeaponRangeCheck(int param_1, int param_2);  // FUN_004a67b0

// FUN_0042fb40 — Notify observer via vtable callback
// Caller count: 106. Calls observer vtable[4] if present, clears pointer.
void ObserverNotify(int* param_1);  // FUN_0042fb40

// FUN_005d8c90 — Entity command dispatch (console/dialog commands)
// Caller count: 83. Routes commands to entity handlers based on param_4 type.
// 87 lines, handles types 0x4d (camera reset), 0 (string resolve + callback).
int EntityCommandDispatch(int param_1, uint32_t* param_2, int param_3, int param_4);  // FUN_005d8c90

// FUN_00559530 — Allocates entity slot from free pool
// Caller count: 65. Pops from DAT_007027e8 free list, memsets 0x374 bytes,
// appends to DAT_007027a8 active list. Returns allocated slot or null.
int* AllocateEntitySlot();  // FUN_00559530

// FUN_0048fba0 — Applies entity transform matrix with XOR depth obfuscation
// Caller count: 59, 170 lines. Processes 4 transform rows, applies scale/rotation,
// XOR key DAT_0066c580 on depth column. Core render transform.
void ApplyEntityTransform(int* param_1);  // FUN_0048fba0

// FUN_005d8890 — Entity property lookup from command string
// Caller count: 59. Resolves entity by string name, computes distance,
// returns property value or 0xFFFFFF on error.
uint32_t EntityPropertyLookup(int param_1, int param_2, int param_3, int param_4);  // FUN_005d8890

// FUN_00497350 — PASS — Entity owner table lookup
// Checks if entity (typeId at +0x22c) is registered in owner's item table
// (26 entries, stride 28 bytes). Early returns for type 0x20 and states 9-12.
// Caller count: 53.
void EntityOwnerTableCheck(int* entity);  // FUN_00497350

// FUN_00580930 — PASS — Entity owner table check variant (type 0x52)
// Same pattern as EntityOwnerTableCheck but checks type 0x52 (skip),
// 16 entries (vs 26), stride 28 bytes. States 9-12 skip.
// Caller count: 51.
void EntityOwnerTableCheckVariant(int* entity);  // FUN_00580930

} // namespace Giants
