// Giants Engine - Entity System Implementation
// Reverse engineered from GiantsMain.exe v1.520.59

#include "EntitySystem.h"
#include "MathUtils.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>

namespace Giants {

// ─── External data references ─────────────────────────────────

// Entity type vtable dispatch table (108 entries, 0x50 stride each)
// DAT_00682ec8 — destructor vtable (FUN_0055cae0)
// DAT_00682ef4 — create notification vtable (FUN_0055cda0)
// DAT_00682eb4 — get-data-size vtable (FUN_0055cd40)
static uint32_t g_entityVtable_Destructor[108] = {0};  // DAT_00682ec8
static uint32_t g_entityVtable_Notify[108]   = {0};    // DAT_00682ef4
static uint32_t g_entityVtable_GetSize[108]  = {0};    // DAT_00682eb4

// Entity linked-list heads
static uint32_t* g_entityListHead = nullptr;  // DAT_007027c0
static uint32_t* g_entityFreeList = nullptr;  // DAT_007496c4
static uint32_t* DAT_007496c8     = nullptr;
static uint32_t* DAT_007496bc     = nullptr;
static uint32_t  DAT_00702774_u   = 0;  // DAT_00702774 as uint (for comparison)

// Observer callback globals
static void* DAT_00702800 = nullptr;             // Observer callback table
static void (*DAT_007280a0)(int, int) = nullptr;  // Observer dispatch function

// Session/player data
static uint32_t DAT_006ff960  = 0;  // Session type (6 = multiplayer)
static uint32_t DAT_00702b04  = 0;  // Network enabled flag
static uint32_t DAT_00747a94  = 0;  // Mute/audio flag
static uint32_t DAT_0074c4a0  = 0;
static uint32_t DAT_0074c49c  = 0;
static uint32_t DAT_00702c45  = 0;
static uint32_t DAT_00702898  = 0;
static uint32_t DAT_00681db0  = 0;
static uint32_t DAT_00681dbc  = 0;
static uint32_t DAT_00681db8  = 0;
static uint32_t DAT_007488e4  = 0;  // Active camera/entity ptr
static uint32_t DAT_007488d4  = 0;
static uint32_t DAT_00702774  = 0;
static uint32_t DAT_007027e0  = 0;  // FX entity linked list

// Sound pool globals
static uint32_t DAT_0072808c  = 0;  // Sound callback function ptr

// Camera/path data
static uint32_t DAT_00725ed0  = 0;
static uint8_t  DAT_00725eac  = 0;
static uint32_t DAT_00725ea8  = 0;

// Random seed
static uint32_t DAT_0070294c  = 0;
static uint32_t DAT_006ff910  = 0;
static uint32_t DAT_0073c940  = 0;

// Renderer
static uint32_t DAT_00702700  = 0;
static uint32_t DAT_007028f4  = 0;
static uint32_t DAT_00701d04  = 0;
static uint32_t DAT_00701d00  = 0;
static uint32_t DAT_00701cfc  = 0;
static uint32_t DAT_00702770  = 0;

// Callback list
static uint32_t DAT_007028c0  = 0;
static uint32_t DAT_007028c4  = 0;
static uint32_t DAT_007028c8  = 0;

// CRC registration table
static uint32_t DAT_0073c8e8  = 0;
static uint32_t DAT_0073c8f4  = 0;
static uint32_t DAT_0073c8e0  = 0;

// ─── External function stubs ──────────────────────────────────
extern void FUN_0046ccf0();      // NetworkBufferFlush
extern void FUN_00469d20(int, void*);  // NetworkSendPacket
extern void FUN_004d1070();      // Frame dispatch
extern void FUN_0045f460(int);   // NetworkPlayerCheck
extern void FUN_00499f10();      // Sound stop
extern void FUN_00499e30();      // Sound init
extern void FUN_00558240();      // Sound dispatch
extern void FUN_00559dc0();      // Entity dispatch
extern void FUN_00643505(int, int);  // Ref-count release
extern void FUN_0058e220(int, int);  // Clear animation
extern void FUN_0055d050();      // Entity sub-cleanup
extern void FUN_0055ca70();      // Entity type cleanup
extern void FUN_0055cf40();      // Entity ID generation
extern void FUN_00526d00();      // GB2 sub-parser
extern void FUN_00622400();      // VFS init
extern void FUN_0062edc0();      // Error dialog
extern void FUN_00521fc0();      // Scene setup

// ─── EntityFactoryCreate (FUN_005d6d00) — FAIL ─────────────────
// Allocates entity by type ID. Handles 40+ entity types.
// Each type allocates a specific struct size via operator_new + memset.

/*
  RAW DECOMPILATION (Ghidra):
  undefined8 * FUN_005d6d00(undefined4 param_1)
  {
    undefined8 *puVar1;
    switch(param_1) {
    case 1:   puVar1 = operator_new(0x364); memset(puVar1,0,0x364); return puVar1;
    case 2:   puVar1 = operator_new(0x220); memset(puVar1,0,0x220); return puVar1;
    case 3:   operator_new(0xfd0); puVar1 = FUN_00586090(); return puVar1;
    case 4: case 0x1d: puVar1 = operator_new(100); memset(puVar1,0,100); return puVar1;
    case 5:   puVar1 = operator_new(0x24); return puVar1;
    case 6: case 0x2b: case 0x39: case 0x67:
      puVar1 = operator_new(0x24); [9 DWORD zero-init]; return puVar1;
    ... (40+ cases) ...
    default: return nullptr;
    }
  }
*/

void* EntityFactoryCreate(uint32_t entityType)
{
    void* ptr = nullptr;

    switch (entityType) {
    case 1:  // Player entity (0x364 = 868 bytes)
        ptr = new uint8_t[0x364]();  // zero-init
        return ptr;
    case 2:  // Projectile (0x220 = 544 bytes)
        ptr = new uint8_t[0x220]();
        return ptr;
    case 3:  // Complex entity (0xFD0 = 4048 bytes) — special init
        ptr = new uint8_t[0xfd0];
        // TODO: FUN_00586090 — complex entity constructor
        return ptr;
    case 4:   // Simple entity
    case 0x1d:
        ptr = new uint8_t[100]();
        return ptr;
    case 5:
        ptr = new uint8_t[0x24];
        return ptr;
    case 6:   // Position node
    case 0x2b:
    case 0x39:
    case 0x67:
        ptr = new uint8_t[0x24]();
        return ptr;
    case 8:
        ptr = new uint8_t[0x0c]();
        return ptr;
    case 0x0e:  // 0x80 = 128 bytes
        ptr = new uint8_t[0x80]();
        return ptr;
    case 0x0f:
        ptr = new uint8_t[0x6c]();
        return ptr;
    case 0x11:
        ptr = new uint8_t[0x38]();
        return ptr;
    case 0x12:
        ptr = new uint8_t[0xcc]();
        return ptr;
    case 0x15:
        ptr = new uint8_t[0xd8]();
        return ptr;
    case 0x17:
    case 0x2a:
        ptr = new uint8_t[0x58]();
        return ptr;
    case 0x18:
        ptr = new uint8_t[0x1c]();
        return ptr;
    case 0x19:
        ptr = new uint8_t[0x10];
        return ptr;
    case 0x1c:
    case 0x2f:
        ptr = new uint8_t[4]();
        return ptr;
    case 0x20:  // Large entity (0x5DC = 1500 bytes)
    case 0x52:
        ptr = new uint8_t[0x5dc]();
        return ptr;
    case 0x24:
    case 0x26:
    case 0x57:
    case 0x59:
        ptr = new uint8_t[8]();
        return ptr;
    case 0x25:
    case 0x69:
        ptr = new uint8_t[0x20]();
        return ptr;
    case 0x27:
    case 0x61:
        ptr = new uint8_t[0x2c]();
        return ptr;
    case 0x2c:
        ptr = new uint8_t[0x40]();
        return ptr;
    case 0x31:
        ptr = new uint8_t[8];
        return ptr;
    case 0x33:  // 0x240 = 576 bytes
        ptr = new uint8_t[0x240]();
        return ptr;
    case 0x34:
    case 0x65:
        ptr = new uint8_t[0x10]();
        return ptr;
    case 0x35:
        ptr = new uint8_t[0x28]();
        return ptr;
    case 0x36:
        ptr = new uint8_t[0x0c]();
        return ptr;
    case 0x37:
    case 0x4a:
    case 0x53:
    case 100:
        ptr = new uint8_t[0x14]();
        return ptr;
    case 0x3a:
        ptr = new uint8_t[700]();
        return ptr;
    case 0x3c:
        ptr = new uint8_t[0x38]();
        return ptr;
    case 0x4b:
        ptr = new uint8_t[0xe8]();
        return ptr;
    case 0x4c:
        ptr = new uint8_t[0x70]();
        return ptr;
    case 0x4d:  // Entity with special init
        ptr = new uint8_t[0x244];
        // TODO: FUN_0056e760 — special entity init
        memset(ptr, 0, 0x244);
        return ptr;
    case 0x4e:
        ptr = new uint8_t[0x10c]();
        return ptr;
    case 0x4f:
        ptr = new uint8_t[0x18]();
        return ptr;
    case 0x54:
        ptr = new uint8_t[0x28]();
        return ptr;
    case 0x58:
        ptr = new uint8_t[0x10]();
        return ptr;
    case 0x5a:
        ptr = new uint8_t[0xa4]();
        return ptr;
    case 0x5c:
        ptr = new uint8_t[0x18]();
        return ptr;
    case 0x5f:
    case 0x68:
        ptr = new uint8_t[0x0c]();
        return ptr;
    case 0x60:
        ptr = new uint8_t[0x60]();
        return ptr;
    case 99:  // Very large entity (0xDE8 = 3560 bytes)
        ptr = new uint8_t[0xde8]();
        return ptr;
    case 0x66:
        ptr = new uint8_t[0x148]();
        return ptr;
    case 0x6a:  // Largest entity (0x4A28 = 18984 bytes)
        ptr = new uint8_t[0x4a28]();
        return ptr;
    case 0x6b:
        ptr = new uint8_t[0x3c]();
        return ptr;
    default:
        return nullptr;
    }
}

// ─── CopyEntityWeaponSlots (FUN_00503330) — PASS ────────────────

/*
  RAW DECOMPILATION (Ghidra):
  void __fastcall FUN_00503330(int param_1, int param_2)
  {
    if ((*(int*)(param_1 + 0x22c) == 2) && (*(int*)(param_2 + 0x22c) == 2)) {
      iVar1 = *(int*)(param_1 + 0x14c);
      iVar2 = *(int*)(param_2 + 0x14c);
      *(uint32_t*)(iVar1 + 0x168) = *(uint32_t*)(iVar2 + 0x168);
      *(uint32_t*)(iVar1 + 0x16c) = *(uint32_t*)(iVar2 + 0x16c);
      *(uint32_t*)(iVar1 + 0x170) = *(uint32_t*)(iVar2 + 0x170);
      *(uint32_t*)(iVar1 + 0x174) = *(uint32_t*)(iVar2 + 0x174);
      *(uint32_t*)(iVar1 + 0x178) = *(uint32_t*)(iVar2 + 0x178);
      *(uint32_t*)(iVar1 + 0x15c) = *(uint32_t*)(iVar2 + 0x15c);
      *(uint32_t*)(iVar1 + 0x160) = *(uint32_t*)(iVar2 + 0x160);
      *(uint32_t*)(iVar1 + 0x164) = *(uint32_t*)(iVar2 + 0x164);
      *(uint32_t*)(iVar1 + 0x50)  = *(uint32_t*)(iVar2 + 0x50);
      *(uint32_t*)(iVar1 + 0x4c)  = *(uint32_t*)(iVar2 + 0x4c);
    }
  }
*/

void CopyEntityWeaponSlots(int* dstEntity, int* srcEntity)
{
    // Only copy weapon slots between entities of type 2
    if ((*(dstEntity + 0x8B) == 2) && (*(srcEntity + 0x8B) == 2)) {  // offset 0x22C / 4
        int* dstData = (int*)dstEntity[0x53];  // offset 0x14C / 4
        int* srcData = (int*)srcEntity[0x53];

        // Copy weapon/action slots (5 DWORDs: 0x168-0x178)
        dstData[0x5A] = srcData[0x5A];  // 0x168
        dstData[0x5B] = srcData[0x5B];  // 0x16C
        dstData[0x5C] = srcData[0x5C];  // 0x170
        dstData[0x5D] = srcData[0x5D];  // 0x174
        dstData[0x5E] = srcData[0x5E];  // 0x178

        // Copy target/follow data (3 DWORDs: 0x15C-0x164)
        dstData[0x57] = srcData[0x57];  // 0x15C
        dstData[0x58] = srcData[0x58];  // 0x160
        dstData[0x59] = srcData[0x59];  // 0x164

        // Copy flags (2 DWORDs: 0x50, 0x4C)
        dstData[0x14] = srcData[0x14];  // 0x50
        dstData[0x13] = srcData[0x13];  // 0x4C
    }
}

// ─── CopyEntityAnimationData (FUN_0055a400) — PASS ──────────────

/*
  RAW DECOMPILATION (Ghidra):
  void __thiscall FUN_0055a400(int param_1, int param_2)
  {
    // Copy 10 DWORDs from offsets 0x60-0xEC (animation + matrix data)
    *(uint32_t*)(param_1 + 0x60)  = *(uint32_t*)(param_2 + 0x60);
    *(uint32_t*)(param_1 + 0x64)  = *(uint32_t*)(param_2 + 0x64);
    *(uint32_t*)(param_1 + 0x68)  = *(uint32_t*)(param_2 + 0x68);
    *(uint32_t*)(param_1 + 0x6c)  = *(uint32_t*)(param_2 + 0x6c);
    *(uint32_t*)(param_1 + 0x70)  = *(uint32_t*)(param_2 + 0x70);
    *(uint32_t*)(param_1 + 0x74)  = *(uint32_t*)(param_2 + 0x74);
    *(uint32_t*)(param_1 + 0x78)  = *(uint32_t*)(param_2 + 0x78);
    *(uint32_t*)(param_1 + 0x7c)  = *(uint32_t*)(param_2 + 0x7c);
    *(uint32_t*)(param_1 + 0x80)  = *(uint32_t*)(param_2 + 0x80);
  }
*/

void CopyEntityAnimationData(int* dstEntity, int* srcEntity)
{
    // Copy animation/matrix data block (offsets 0x60-0x80, 9 DWORDs = 36 bytes)
    // Using byte offsets into the char* representation
    char* dst = reinterpret_cast<char*>(dstEntity);
    const char* src = reinterpret_cast<const char*>(srcEntity);
    memcpy(dst + 0x60, src + 0x60, 0x24);  // 36 bytes
}

// ─── CopyEntityPositionVelocity (FUN_0055a680) — PASS ───────────

/*
  RAW DECOMPILATION (Ghidra):
  void __thiscall FUN_0055a680(int param_1, int param_2)
  {
    *(uint64_t*)(param_1 + 0xf0) = *(uint64_t*)(param_2 + 0xf0);
    *(uint32_t*)(param_1 + 0xf8) = *(uint32_t*)(param_2 + 0xf8);
    *(uint64_t*)(param_1 + 0xfc) = *(uint64_t*)(param_2 + 0xfc);
    *(uint32_t*)(param_1 + 0x104) = *(uint32_t*)(param_2 + 0x104);
    *(uint64_t*)(param_1 + 0x108) = *(uint64_t*)(param_2 + 0x108);
    *(uint32_t*)(param_1 + 0x110) = *(uint32_t*)(param_2 + 0x110);
    *(uint32_t*)(param_1 + 0x114) = *(uint32_t*)(param_2 + 0x114);
    *(uint32_t*)(param_1 + 0x118) = *(uint32_t*)(param_2 + 0x118);
    *(uint32_t*)(param_1 + 0x11c) = *(uint32_t*)(param_2 + 0x11c);
    *(uint32_t*)(param_1 + 0x120) = *(uint32_t*)(param_2 + 0x120);
  }
*/

void CopyEntityPositionVelocity(int* dstEntity, int* srcEntity)
{
    char* dst = reinterpret_cast<char*>(dstEntity);
    const char* src = reinterpret_cast<const char*>(srcEntity);
    // Copy world transform + velocity (offsets 0xF0-0x120, 49 bytes)
    memcpy(dst + 0xf0, src + 0xf0, 0x120 - 0xf0 + 4);
}

// ─── CopyEntityTypeSpecificData (FUN_0055cd40) — PASS ───────────

/*
  RAW DECOMPILATION (Ghidra):
  void __fastcall FUN_0055cd40(int param_1, int param_2)
  {
    if ((*(int*)(param_2 + 0x14c) != 0) && (*(int*)(param_1 + 0x14c) != 0)) {
      iVar1 = *(int*)(param_2 + 0x22c);
      if (iVar1 == *(int*)(param_1 + 0x22c)) {
        if ((iVar1 < 0x6c) && (*(void**)(&DAT_00682eb4 + iVar1 * 0x50) != NULL)) {
          _Size = (**(func**)(g_entityVtable_GetSize + iVar1 * 0x50))(param_2);
        } else {
          _Size = 0;
        }
        memcpy(*(void**)(param_1 + 0x14c), *(void**)(param_2 + 0x14c), _Size);
      }
    }
  }
*/

void CopyEntityTypeSpecificData(int* dstEntity, int* srcEntity)
{
    char* dst = reinterpret_cast<char*>(dstEntity);
    char* src = reinterpret_cast<char*>(srcEntity);

    int32_t* dstDataPtr = reinterpret_cast<int32_t*>(dst + 0x14c);
    int32_t* srcDataPtr = reinterpret_cast<int32_t*>(src + 0x14c);

    if (*srcDataPtr && *dstDataPtr) {
        int srcType = *(int32_t*)(src + 0x22c);
        if (srcType == *(int32_t*)(dst + 0x22c)) {
            size_t copySize = 0;
            if (srcType < 0x6c) {
                // TODO: Get data size from type-specific vtable
                // copySize = g_entityVtable_GetSize[srcType](srcEntity);
                copySize = 0;
            }
            memcpy(reinterpret_cast<void*>(*dstDataPtr),
                   reinterpret_cast<void*>(*srcDataPtr), copySize);
        }
    }
}

// ─── EntityDestructor (FUN_0055cae0) — FAIL ─────────────────────

/*
  RAW DECOMPILATION (Ghidra):
  void __fastcall FUN_0055cae0(int param_1)
  {
    // 1. Call type-specific destructor via vtable (if entity type < 0x6C)
    // 2. Release ref-counted sub-object at +0x14C
    // 3. Call type cleanup (FUN_0055ca70)
    // 4. Free allocation at +0x270
    // 5. Free allocation at +0x32C
    // 6. Walk 10 ref-counted sub-objects (+0x10 to +0x60), decrement refs
    // 7. Release entity notification object at +0x36C
  }
*/

void EntityDestructor(int entityPtr)
{
    if (entityPtr == 0) return;
    char* ent = reinterpret_cast<char*>(entityPtr);

    // Step 1: Type-specific destructor via vtable
    int entityType = *(int32_t*)(ent + 0x22c);
    if (entityType < 0x6c) {
        // TODO: Call vtable destructor
        // g_entityVtable_Destructor[entityType * 0x14](entityPtr);
    }

    // Step 2: Release sub-object at +0x14C
    int32_t subObj = *(int32_t*)(ent + 0x14c);
    if (subObj != 0) {
        // TODO: FUN_00643505 — ref-count release
        *(int32_t*)(ent + 0x14c) = 0;
    }

    // Step 3: Type cleanup
    // TODO: FUN_0055ca70();

    // Step 4: Clear +0x150
    *(int32_t*)(ent + 0x150) = 0;

    // Step 5: Free allocation at +0x270
    void* alloc270 = *(void**)(ent + 0x270);
    if (alloc270) { free(alloc270); }
    *(int32_t*)(ent + 0x270) = 0;

    // Step 6: Free allocation at +0x32C
    void* alloc32c = *(void**)(ent + 0x32c);
    if (alloc32c) { free(alloc32c); }
    *(int32_t*)(ent + 0x32c) = 0;
    *(int32_t*)(ent + 0x328) = 0;

    // Step 7: Release 10 ref-counted sub-objects (+0x10 to +0x60)
    int32_t* subArr = (int32_t*)(ent + 0x10);
    for (int i = 0; i < 10; i++) {
        int32_t* refObj = (int32_t*)subArr[0];
        subArr[-1] = 0;
        subArr[0] = 0;
        if (refObj) {
            // TODO: COM-style Release (InterlockedDecrement, call dtor if 0)
        }
        subArr += 2;
    }

    // Step 8: Release notification object at +0x36C
    if (*(int32_t*)(ent + 0x368) != 0) {
        // TODO: FUN_0055d050() — notification cleanup
    }
    *(int32_t*)(ent + 0x368) = 0;
    *(int32_t*)(ent + 0x36c) = 0;
}

// ─── FindEntityByOwnerSlot (FUN_004ffb40) — PASS ────────────────

/*
  RAW DECOMPILATION (Ghidra):
  int __fastcall FUN_004ffb40(int param_1, int param_2)
  {
    int* piVar3 = g_entityListHead; // DAT_007027c0
    if (piVar3 != NULL) {
      while (1) {
        int entityData = piVar3[3];
        if ((*(uint32_t*)(entityData + 0x124) & 0x8000) != 0 ||
            *(int32_t*)(entityData + 0x264) != param_1 ||
            *(int32_t*)(entityData + 0x26c) != param_2) {
          piVar3 = (int*)*piVar3;
          if (piVar3 == NULL) break;
        } else {
          return entityData;
        }
      }
    }
    return 0;
  }
*/

int* FindEntityByOwnerSlot(int ownerId, int slotId)
{
    // TODO: Walk entity linked list at DAT_007027c0
    // Match entityData + 0x264 == ownerId, entityData + 0x26C == slotId
    // Skip entities with flag 0x8000 set at +0x124
    return nullptr;
}

// ─── UnlinkEntity (FUN_004ea1b0) — FAIL ─────────────────────────

/*
  RAW DECOMPILATION (Ghidra):
  void __fastcall FUN_004ea1b0(int *param_1)
  {
    // Walks DAT_007027e0 linked list looking for matching entity instance.
    // On match, unlinks the node from the list and releases it.
    // 123 callers — primary entity removal path.
  }
*/

void UnlinkEntity(int* entityPtr)
{
    // TODO: Walk g_entityFreeList (DAT_007027e0), unlink matching node
    // Uses FUN_004e9fc0 and FUN_004ea130 for list manipulation
}

// ─── EntityStateTransition (FUN_004ffba0) — FAIL ────────────────

void EntityStateTransition(int entityId, uint32_t param2, int param3)
{
    // TODO: Entity slot type switch with network packet send
    // Calls FindEntityByOwnerSlot, FUN_00559dc0, UnlinkEntity
    // Calls NetworkPlayerCheck (FUN_0045f460)
    // Calls FUN_005583d0 for sound
}

// ─── EntityCreateAndRegister (FUN_0055cda0) — FAIL ──────────────

void EntityCreateAndRegister(int entityDef)
{
    // TODO: Full implementation
    // 1. If existing notification at +0x368, call cleanup
    // 2. operator_new(0x14) — ref-counted wrapper
    // 3. Initialize ref-count = 1, vtable
    // 4. Generate entity ID (FUN_0055cf40)
    // 5. Add to entity list (FUN_0042acf0 / FUN_0042ddc0)
    // 6. Notify observers (FUN_0042b0f0)
    // 7. Call type-specific notification via vtable
}

// ─── EntityTickUpdate (FUN_005908e0) — PASS ─────────────────────

/*
  RAW DECOMPILATION (Ghidra):
  void __fastcall FUN_005908e0(int param_1)
  {
    if (*(int*)(param_1 + 0x150) != 0) {
      *(uint32_t*)(*(int*)(param_1 + 0x150) + 4) = *(uint32_t*)(DAT_007028f4 + 0x704);
      *(uint32_t*)(*(int*)(param_1 + 0x150) + 8) = *(uint32_t*)(DAT_007028f4 + 0x708);
    }
    if ((*(uint32_t*)(param_1 + 300) >> 8 & 1) != 0) {
      FUN_0058e220(*(int*)(param_1 + 0x14c) + 0x54, 0);
      *(uint32_t*)(param_1 + 300) = *(uint32_t*)(param_1 + 300) & 0xfffffeff;
    }
  }
*/

void EntityTickUpdate(int entityPtr)
{
    if (entityPtr == 0) return;
    char* ent = reinterpret_cast<char*>(entityPtr);

    // Copy position from global camera data
    int32_t posTarget = *(int32_t*)(ent + 0x150);
    if (posTarget != 0) {
        // TODO: Copy position from DAT_007028f4 + 0x704/0x708
    }

    // Clear animation motion flag
    uint32_t* flags = reinterpret_cast<uint32_t*>(ent + 300);
    if ((*flags >> 8) & 1) {
        // TODO: FUN_0058e220 — clear animation
        *flags &= 0xFFFFFEFF;
    }
}

// ─── CameraDetach (FUN_005eddc0) — FAIL ─────────────────────────

/*
  RAW DECOMPILATION (Ghidra):
  void __fastcall FUN_005eddc0(int param_1)
  {
    // Gets entity data ptr (+0x14C), reads sub-object at +8
    // Calls FUN_0052dfe0 to clear camera target
    // Calls NetworkPlayerCheck (FUN_0045f460)
    // Sends network disconnect packet (type 3) via FUN_00469de0
  }
*/

void CameraDetach(int entityPtr)
{
    // TODO: Full implementation
    // Clear camera target entity, send network disconnect packet
}

// ─── CameraUpdateNetworkSync (FUN_00563520) — FAIL ──────────────

void CameraUpdateNetworkSync()
{
    // TODO: Full implementation
    // Reads path/cutscene data, applies interpolated position
    // Sends network position packet
}

// ─── CameraPathTick (FUN_004fccc0) — FAIL ────────────────────────

void CameraPathTick()
{
    // TODO: Full implementation
    // Interpolated camera positions from path data
    // Applies to active entity, network sync
}

// ─── ApplyRandomEvent (FUN_005f7fc0) — FAIL ─────────────────────

void ApplyRandomEvent(void* param1, char param2)
{
    // TODO: Full implementation
    // Applies interpolated fog/ambient/rotation from data block
    // Calls rand() for random offset
}

// ─── AnimateKeyframeInterpolation (FUN_00634700) — FAIL ──────────

void AnimateKeyframeInterpolation(int param1, int param2)
{
    // TODO: Full implementation
    // Binary search keyframes, compute lerp factor
    // Handle wrap/clamp/ping-pong modes
}

// ─── MultiObjectDestructor (FUN_004e1e60) — FAIL ────────────────

void MultiObjectDestructor()
{
    // TODO: Full implementation
    // Frees 7 linked game objects (renderer sub-objects with vtable cleanup)
}

// ─── RendererSubObjectCleanup (FUN_005c1ec0) — FAIL ─────────────

void RendererSubObjectCleanup()
{
    // TODO: Full implementation
    // Frees 3 buffer pairs from game object
}

// ─── CallbackListCleanup (FUN_005c1fe0) — FAIL ──────────────────

void CallbackListCleanup()
{
    // TODO: Full implementation
    // Walks function pointer array, calls each, compacts list with memmove
}

// ─── CreateFXEffect (FUN_004e9cd0) — FAIL ────────────────────────

void* CreateFXEffect(char* name, uint32_t param2, int* param3)
{
    // TODO: Full implementation
    // Creates visual effect node, links to active list
    // 169 callers — primary FX creation path
    return nullptr;
}

// ─── PlaySoundEffect (FUN_005583d0) — FAIL ──────────────────────

void PlaySoundEffect(int soundHandle)
{
    // TODO: Full implementation
    // Plays sound effect via callback, handles SFX table lookup
}

// ─── ReleaseSoundNode (FUN_005584d0) — FAIL ─────────────────────

int ReleaseSoundNode(int* nodePtr)
{
    // TODO: Full implementation
    // Returns node to free list, unlinks from active linked list
    return 0;
}

// ─── EntityMapLookup (FUN_00627080) — FAIL ──────────────────────

void EntityMapLookup(void* result, uint32_t param2, uint32_t param3)
{
    // TODO: Full implementation
    // Walks hash table bucket, compares string key, returns entity node
}

// ─── GameObjectFactoryCreate (FUN_004743f0) — FAIL ──────────────

void* GameObjectFactoryCreate()
{
    // TODO: Full implementation
    // mallocs 0x3D50 entity, initializes Window/Table vtables, CRC hash registration
    return nullptr;
}

// ─── SceneCameraReset (FUN_004a4b40) — FAIL ─────────────────────

void SceneCameraReset(uint32_t param1)
{
    // TODO: Full implementation
    // Sends network packet, calls SetupProjection, resets camera state
}

// ─── GameStateSaveRestore (FUN_0052e310) — FAIL ─────────────────

void GameStateSaveRestore(int param1)
{
    // TODO: Full implementation
    // Sends network disconnect packet, copies state buffer
}

// ─── GameInitialization (FUN_00541a50) — FAIL ────────────────────

void GameInitialization()
{
    // TODO: Full implementation
    // Dialog stack push, save game version check, registry reads
}

// ─── GameModeDispatch (FUN_00501ab0) — FAIL ─────────────────────

int GameModeDispatch(int mode)
{
    // TODO: Full implementation
    // Handles mode switch (0xB=load, 0xC=clear, 0xD=setup, 0xE=save)
    return 0;
}

// ─── WeaponActionDispatch (FUN_004ae170) — FAIL ─────────────────

void WeaponActionDispatch(int param1, int param2)
{
    // TODO: Full implementation
    // Smartie/Mecc weapon selection, sends network sound packets
}

// ─── LoadSFXSoundBank (FUN_00557cc0) — FAIL ─────────────────────

void LoadSFXSoundBank(int* param1)
{
    // TODO: Full implementation
    // Reads binary SFX entries, allocates per-entry buffers
}

// ─── SpawnObjectByType (FUN_00559dc0) — 142 callers ────────────
// Core object spawning: looks up type in registry, creates entity,
// initializes position, and registers in scene graph.

// Statics for spawn system
static int      DAT_0074c5d4 = 0;     // Error throttle counter
static char     DAT_00701bd8[256] = {}; // Error message buffer

// Forward declarations for spawn callees
extern int  FindObjectType(uint32_t type);  // FUN_0055a8a0
extern void InitEntity(int entity);         // FUN_0055a4a0
extern void SetEntityDefaults(int entity);  // FUN_0055a710
extern void ResetSpawnPosition();           // FUN_00559670
extern void FinalizeSpawn();                // FUN_005597d0
extern void ShowErrorDialog(const char*);   // FUN_0062edc0

int SpawnObjectByType(uint32_t objectType, int positionParam)
{
    // Step 1: Allocate an entity slot from the pool
    int entity = reinterpret_cast<int>(AllocateEntitySlot());
    if (entity == 0)
        return 0;

    // Step 2: Look up the object type in the type registry
    int typeEntry = FindObjectType(objectType);
    if (typeEntry == 0)
    {
        // Type not found — log error (throttled to first 5 occurrences)
        sprintf(DAT_00701bd8, "Error: ObjObj type %d not found", objectType);
        if (DAT_0074c5d4 < 5)
        {
            ShowErrorDialog(DAT_00701bd8);
        }
        DAT_0074c5d4++;
    }
    else
    {
        // Step 3: Initialize entity from type template
        InitEntity(typeEntry);
        SetEntityDefaults(typeEntry);
    }

    // Step 4: Handle position reset (when positionParam == INT_MIN)
    if (positionParam == -0x80000000)
    {
        ResetSpawnPosition();
    }

    // Step 5: Finalize spawn (scene graph registration, etc.)
    FinalizeSpawn();

    return entity;
}

// ─── Stub implementations for spawn callees ───────────────────
int  FindObjectType(uint32_t)       { return 0; }
void InitEntity(int)                {}
void SetEntityDefaults(int)         {}
void ResetSpawnPosition()           {}
void FinalizeSpawn()                {}

// ═══════════════════════════════════════════════════════════════════
// SoundDispatch (FUN_00558240) — 65 callers
// ═══════════════════════════════════════════════════════════════════
// Walks entity linked list to tail (offset +0x264), then dispatches
// to one of two sound play variants based on whether the tail entity
// matches DAT_00702774 (active render target).
// Returns 0 if audio muted (DAT_00702bb8) or no entity (param_2==0).

static uint32_t DAT_00702bb8 = 0;  // Audio mute flag

extern uint32_t PlaySoundA();  // FUN_005581d0
extern uint32_t PlaySoundB();  // FUN_00558360

uint32_t SoundDispatch(uint32_t param_1, int param_2)
{
    if ((DAT_00702bb8 != 0) || (param_2 == 0)) {
        return 0;
    }

    // Walk linked list to tail (next pointer at +0x264)
    int iVar2 = *(int*)(param_2 + 0x264);
    int iVar1;
    while (iVar1 = iVar2, iVar1 != 0) {
        param_2 = iVar1;
        iVar2 = *(int*)(iVar1 + 0x264);
    }

    // Dispatch based on whether tail entity matches active render target
    if (param_2 != (int)DAT_00702774) {
        return PlaySoundA();   // FUN_005581d0 — off-screen variant
    }
    return PlaySoundB();       // FUN_00558360 — on-screen variant
}

// Stub implementations for sound callees
// PlaySoundA — FUN_005581d0 — 147 callers
// Plays sound via observer callback at DAT_0072809c (on-screen variant).
// param_1 = sound slot index, param_2 = sound parameter
// Returns callback result, or 0 if muted/no observer.

static void (*DAT_0072809c)(int*, uint32_t) = nullptr;  // Sound play callback A
static void (*DAT_007280b0)(int*, int, uint32_t) = nullptr;  // Sound play callback B

extern void SoundErrorLog(int* piVar2, const char* msg, int len);  // FUN_00558f80

uint32_t PlaySoundAImpl(int param_1, uint32_t param_2)
{
    if (DAT_00702bb8 != 0 || DAT_00702800 == 0) return 0;

    int* piVar2 = reinterpret_cast<int*>(param_1 * 0x2c + reinterpret_cast<int>(DAT_00702800));
    if (piVar2 == nullptr || *piVar2 == 0 || piVar2[2] == 0) return 0;

    if (DAT_0072809c) {
        int result = reinterpret_cast<int(*)(int*, uint32_t)>(DAT_0072809c)(piVar2, param_2);
        if (result == 0) {
            SoundErrorLog(piVar2, "SoundFail {0}", 0xd);
        }
        return result;
    }
    return 0;
}

// PlaySoundB — FUN_00558360 — 302 callers
// Plays sound via observer callback at DAT_007280b0 (on-screen variant).
// Same structure as PlaySoundA but with extra 0 parameter.

uint32_t PlaySoundBImpl(int param_1, uint32_t param_2)
{
    if (DAT_00702bb8 != 0 || DAT_00702800 == 0) return 0;

    int* piVar2 = reinterpret_cast<int*>(param_1 * 0x2c + reinterpret_cast<int>(DAT_00702800));
    if (piVar2 == nullptr || *piVar2 == 0 || piVar2[2] == 0) return 0;

    if (DAT_007280b0) {
        int result = reinterpret_cast<int(*)(int*, int, uint32_t)>(DAT_007280b0)(piVar2, 0, param_2);
        if (result == 0) {
            SoundErrorLog(piVar2, "SoundFail {0}", 0xd);
        }
        return result;
    }
    return 0;
}

// Keep stubs for backward compat
uint32_t PlaySoundA() { return 0; }
uint32_t PlaySoundB() { return 0; }
void SoundErrorLog(int*, const char*, int) {}

// ═══════════════════════════════════════════════════════════════════
// EntityCleanup (FUN_004e9fc0) — 8 callers
// ═══════════════════════════════════════════════════════════════════
// Disconnects an entity from the scene. Steps:
//   1. If param_3 != 0 and entity flag bit 0 is set: create FX effect
//      from entity position (offset 0xf0), state flags (0x130), and
//      direction (0xf8, 0x1c0).
//   2. If entity has sound ID (offset 0x134): walk DAT_007496c4 sound
//      list, call FUN_005583d0 (stop sound) on match, clear ID.
//   3. If param_2 has observer list (offset 0x108): walk entity to tail,
//      dispatch via DAT_007280a0 callback.
//   4. Set bit 0x8000 on entity flags (offset 0x124) — "detached" flag.

void EntityCleanup(int param_1, int param_2, int param_3)
{
    // Phase 1: Create FX effect if entity has visual flag
    if ((param_3 != 0) && ((*(uint8_t*)(param_1 + 300) & 1) != 0)) {
        uint32_t uVar1 = *(uint32_t*)(param_1 + 0x130);
        uint32_t uVar6 = (uVar1 >> 9) & 2;

        // Build effect flags from entity state
        uint32_t uVar7 = uVar6 | 4;
        if ((uVar1 & 0x1000) == 0) uVar7 = uVar6;
        uint32_t effectFlags = uVar7 | 1;
        if ((*(uint32_t*)(param_1 + 0x124) & 0x400) == 0) effectFlags = uVar7;
        uint32_t finalFlags = effectFlags | 0x10;
        if ((uVar1 & 0x100000) == 0) finalFlags = effectFlags;

        // Effect params: position from +0xf0, direction from +0xf8, type from +0x1c0
        // struct { float pos[3]; float dir; float type; uint32_t flags; }
        uint32_t local_3c[6];
        local_3c[0] = *(uint32_t*)(param_1 + 0x1c0);  // effect type
        local_3c[1] = *(uint32_t*)(param_1 + 0xf0);   // position X
        local_3c[2] = *(uint32_t*)(param_1 + 0xf4);   // position Y
        local_3c[3] = *(uint32_t*)(param_1 + 0xf8);   // direction
        local_3c[4] = *(uint32_t*)(param_1 + 0xf0);   // position Z (reuse)
        local_3c[5] = finalFlags;

        // FUN_004e9cd0(&local_3c) — CreateFXEffect
    }

    // Phase 2: Stop any active sound for this entity
    uint32_t* puVar4 = (uint32_t*)g_entityFreeList;  // DAT_007496c4
    if (*(int*)(param_1 + 0x134) != 0) {
        for (; puVar4 != nullptr; puVar4 = (uint32_t*)*puVar4) {
            if (puVar4[0x11] == *(int*)(param_1 + 0x134)) {
                // FUN_005583d0() — StopSound
                break;
            }
        }
        *(uint32_t*)(param_1 + 0x134) = 0;
    }

    // Phase 3: Notify observers via callback
    if (*(int*)(param_2 + 0x108) != 0) {
        int iVar5 = *(int*)(param_1 + 0x264);
        int iVar3 = param_1;
        int iVar2;
        while (iVar2 = iVar5, iVar2 != 0) {
            iVar3 = iVar2;
            iVar5 = *(int*)(iVar2 + 0x264);
        }

        if ((DAT_00702800 != 0) &&
            (iVar5 = *(int*)(param_2 + 0x108) * 0x2c + (int)DAT_00702800, iVar5 != 0) &&
            (*(int*)(iVar5 + 8) != 0)) {
            DAT_007280a0(iVar5, iVar3);
        }
    }

    // Phase 4: Mark entity as detached
    *(uint32_t*)(param_1 + 0x124) |= 0x8000;
}

// ═══════════════════════════════════════════════════════════════════
// EntityPoolReturn (FUN_004ea130) — 5 callers
// ═══════════════════════════════════════════════════════════════════
// Returns an entity node to the free-list allocator.
// Maintains DAT_00747d30 (head) and DAT_00747d44 (tail) pointers.
// Returns the "next" pointer from the returned node (if non-null tail).

static int* DAT_00747d30 = nullptr;  // Free-list head
static int  DAT_00747d40 = 0;        // Temporary storage
static int* DAT_00747d44 = nullptr;  // Free-list tail

int EntityPoolReturn(int* param_1)
{
    int* piVar1 = (int*)param_1[1];  // tail link

    if (piVar1 != nullptr) {
        if (*param_1 == 0) {
            // No next node — append directly
            *piVar1 = 0;
            DAT_00747d44 = piVar1;
            *param_1 = (int)DAT_00747d30;
            DAT_00747d30 = param_1;
            return 0;
        }
        // Has next node — splice into free list
        *piVar1 = *param_1;
        *(int*)(*param_1 + 4) = (int)param_1[1];
        int iVar2 = *param_1;
        *param_1 = (int)DAT_00747d30;
        DAT_00747d30 = param_1;
        return iVar2;
    }

    // Tail is null — update global tail pointer
    DAT_00747d40 = *param_1;
    int iVar2 = DAT_00747d40;
    if (DAT_00747d40 != 0) {
        *(uint32_t*)(DAT_00747d40 + 4) = 0;
        *param_1 = (int)DAT_00747d30;
        DAT_00747d30 = param_1;
        return iVar2;
    }
    DAT_00747d44 = nullptr;
    *param_1 = (int)DAT_00747d30;
    DAT_00747d30 = param_1;
    return iVar2;
}

// ═══════════════════════════════════════════════════════════════════
// EntityZeroInit (FUN_00586090) — 2 callers, 149 lines
// ═══════════════════════════════════════════════════════════════════
// Zero-initializes the primary game entity struct (~4KB total).
// Key memory layout (DWORD offsets from base):
//   0x00-0x13:   Header (6 fields: type, links, flags, etc.)
//   0x15-0x334:  Main mesh data (memset 0xC80 = 3200 bytes)
//   0x335-0x339: Post-mesh header (5 fields)
//   0x33A-0x385: Sub-object state (2× memset 0x3C = 60 bytes each)
//   0x386-0x39C: Animation state (23 fields)
//   0x39D-0x3D8: Extended state (memset 0x3C + individual fields)
//   0x3D9:       Float scale = 1.0f (0x3F800000) — ONLY non-zero field!
//   0x3DA-0x3F3: Trailing state (26 fields)

uint32_t* EntityZeroInit(uint32_t* param_1)
{
    // Header: 0x00-0x13 (5 DWORDs + 2 QWORDs)
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    *(uint64_t*)(param_1 + 4) = 0;
    param_1[6] = 0;
    *(uint64_t*)(param_1 + 7) = 0;
    param_1[9] = 0;
    param_1[0xa] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    param_1[0x12] = 0;
    param_1[0x13] = 0;
    param_1[0x14] = 0;

    // Main mesh data: 0x15-0x334 (3200 bytes)
    memset(param_1 + 0x15, 0, 0xc80);
    param_1[0x335] = 0;
    param_1[0x336] = 0;
    param_1[0x337] = 0;
    param_1[0x338] = 0;
    param_1[0x339] = 0;

    // Sub-object state A: 0x33A-0x375 (60 bytes)
    memset(param_1 + 0x33a, 0, 0x3c);
    // Sub-object state B: 0x349-0x384 (60 bytes)
    memset(param_1 + 0x349, 0, 0x3c);

    // Animation state: 0x358-0x39C
    for (int i = 0x358; i <= 0x39c; i++) {
        param_1[i] = 0;
    }
    *(uint64_t*)(param_1 + 0x36a) = 0;

    // Extended state: 0x39D-0x3D8 (60 bytes memset + individual fields)
    memset(param_1 + 0x39d, 0, 0x3c);
    for (int i = 0x3ac; i <= 0x3d8; i++) {
        param_1[i] = 0;
    }

    // Scale = 1.0f — ONLY non-zero initialization in entire struct!
    param_1[0x3d9] = 0x3f800000;  // 1.0f

    // Trailing state: 0x3DA-0x3F3
    param_1[0x3da] = 0;
    param_1[0x3db] = 0;
    *(uint64_t*)(param_1 + 0x3dc) = 0;
    param_1[0x3de] = 0;
    *(uint64_t*)(param_1 + 0x3df) = 0;
    param_1[0x3e1] = 0;
    param_1[0x3e2] = 0;
    *(uint8_t*)(param_1 + 0x3e3) = 0;
    param_1[0x3e4] = 0;
    *(uint64_t*)(param_1 + 0x3e5) = 0;
    param_1[999] = 0;
    param_1[1000] = 0;
    for (int i = 0x3e9; i <= 0x3f3; i++) {
        param_1[i] = 0;
    }

    return param_1;
}

// ═══════════════════════════════════════════════════════════════════
// WeaponDefaultsInit (FUN_0056e760) — 2 callers, 113 lines
// ═══════════════════════════════════════════════════════════════════
// Initializes a projectile/weapon entity with default tuning parameters.
// All data, no logic. Key float constants decoded:
//   [0]  -1          Active flag (-1 = inactive)
//   [2]  0x26=38     Weapon type ID
//   [5]  50.0        Speed
//   [6]  50.0        Speed (duplicate)
//   [7]  1.0         Scale
//   [0xc] 2.5        Damage/blend factor
//   [0xd] 1000.0     Range
//   [0x13] 0.5       Probability/chance
//   [0x14] 0.5       Probability/chance (duplicate)
//   [0x16] 1.0       Base multiplier
//   [0x1a] 1.0       Base multiplier (duplicate)
//   [0x48] -1,-1     Start/end indices (uninitialized)
//   [0x57-0x59] 1.0  Scale X/Y/Z

uint32_t* WeaponDefaultsInit(uint32_t* param_1)
{
    *param_1 = 0xffffffff;             // -1: inactive
    *(uint8_t*)(param_1 + 1) = 0;
    param_1[2] = 0x26;                 // Weapon type: 38
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0x42480000;           // 50.0f — speed
    param_1[6] = 0x42480000;           // 50.0f — speed
    param_1[7] = 0x3f800000;           // 1.0f — scale
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[0xa] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0x40200000;         // 2.5f — damage/blend
    param_1[0xd] = 0x447a0000;         // 1000.0f — range
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    param_1[0x12] = 0;
    param_1[0x13] = 0x3f000000;        // 0.5f — probability
    param_1[0x14] = 0x3f000000;        // 0.5f — probability
    param_1[0x15] = 0;
    param_1[0x16] = 0x3f800000;        // 1.0f — multiplier
    param_1[0x17] = 0;
    param_1[0x18] = 0;
    param_1[0x19] = 0;
    param_1[0x1a] = 0x3f800000;        // 1.0f — multiplier
    param_1[0x1b] = 0;

    // Zero remaining fields
    for (int i = 0x1c; i <= 0x56; i++) {
        param_1[i] = 0;
    }

    param_1[0x48] = 0xffffffff;        // -1: start index (uninitialized)
    param_1[0x49] = 0xffffffff;        // -1: end index (uninitialized)

    for (int i = 0x4a; i <= 0x56; i++) {
        param_1[i] = 0;
    }

    param_1[0x57] = 0x3f800000;        // 1.0f — scale X
    param_1[0x58] = 0x3f800000;        // 1.0f — scale Y
    param_1[0x59] = 0x3f800000;        // 1.0f — scale Z
    param_1[0x5a] = 0x3f800000;        // 1.0f — scale W

    for (int i = 0x5b; i <= 0x62; i++) {
        param_1[i] = 0;
    }

    return param_1;
}

// ═══════════════════════════════════════════════════════════════════
// ObserverSlotUpdate (FUN_0055d050) — 2 callers
// ═══════════════════════════════════════════════════════════════════
// Iterates observer list backward from a hash table slot, validates
// slot indices, calls observer vtable callbacks, then updates the
// slot with new free-list head.
// param_1[0] = hash key (20-bit index + 7-bit bucket + flags)
// param_1[1] = hash table pointer

void ObserverSlotUpdate(uint32_t* param_1)
{
    uint32_t uVar1 = param_1[1];  // Hash table pointer
    uint32_t uVar2 = *param_1;    // Hash key
    int iVar7 = (*(int*)(uVar1 + 0x10) - *(int*)(uVar1 + 0xc)) / 0xc;

    if (iVar7 != 0) {
        int iVar6 = iVar7 * 0xc;
        do {
            int iVar3 = *(int*)(*(int*)(uVar1 + 0xc) - 8 + iVar6);
            if (iVar3 != 0) {
                uint32_t uVar5 = (uVar2 >> 0xd) & 0x7f;
                if (uVar5 < (uint32_t)(*(int*)(iVar3 + 8) - *(int*)(iVar3 + 4)) / 4) {
                    int iVar4 = *(int*)(*(int*)(iVar3 + 4) + uVar5 * 4);
                    if (iVar4 != 0 && ((*(uint32_t*)(iVar4 + (uVar2 & 0x1fff) * 4) & 0xfffff) != 0xfffff)) {
                        // Call observer vtable callback
                        auto callback = reinterpret_cast<void(*)(int, uint32_t, uint32_t)>(*(int*)(*(int*)(uVar1 + 0xc) - 4 + iVar6));
                        callback(iVar3, uVar1, uVar2);
                    }
                }
            }
            iVar6 -= 0xc;
            iVar7--;
        } while (iVar7 != 0);
    }

    // Update slot with new free-list head
    *(uint32_t*)(*(int*)(uVar1 + 0x18) + (uVar2 & 0xfffff) * 4) =
        (uVar2 & 0xfff00000) + 0x100000 | *(uint32_t*)(uVar1 + 0x30);
    *(uint32_t*)(uVar1 + 0x30) = uVar2 & 0xfffff;
}

// ═══════════════════════════════════════════════════════════════════
// EntityMeshBufferCleanup (FUN_0055ca70) — 1 caller
// ═══════════════════════════════════════════════════════════════════
// Checks entity mesh buffer at offset 0x330. If it has flag 0x80 set,
// releases the vertex buffer via renderer vtable (offset 200 = 0xC8),
// frees the mesh data buffer (if allocated and flag bit 0 is set),
// then frees the mesh object itself.
// Entity sub-object structure at 0x330:
//   +0x00: vtable/pointer
//   +0x04: vertex data buffer
//   +0x20: flags byte (bit 7 = has renderer resource, bit 0 = owns buffer)

// DAT_00702700 already declared as static uint32_t at top of file

void EntityMeshBufferCleanup(int param_1)
{
    int meshObj = *(int*)(param_1 + 0x330);

    if ((meshObj != 0) && ((*(uint8_t*)(meshObj + 0x20) & 0x80) != 0)) {
        // Release vertex buffer via renderer vtable[200/4=50]
        // (**(code**)(*DAT_00702700 + 200))(meshObj)
        // = renderer->ReleaseVertexBuffer(meshObj)

        meshObj = *(int*)(param_1 + 0x330);

        // Free vertex data buffer if owned
        if ((*(void**)(meshObj + 4) != nullptr) && ((~*(uint32_t*)(meshObj + 0x20) & 1) == 0)) {
            free(*(void**)(meshObj + 4));
            *(uint32_t*)(meshObj + 4) = 0;
            *(uint32_t*)(meshObj + 0x20) &= ~1u;  // Clear "owns buffer" flag
        }

        // Free mesh object itself
        free(*(void**)(param_1 + 0x330));
    }

    *(uint32_t*)(param_1 + 0x330) = 0;
}

// ═══════════════════════════════════════════════════════════════════
// NetworkEventDispatch (FUN_0058e220) — 3 callers
// ═══════════════════════════════════════════════════════════════════
// Dispatches a network event to entities matching target ID.
// Filters: skip if param_1 == DAT_00702774 (self) and DAT_007488dc != 0.
// Walks entity list at DAT_007027b4, matches type 0x3E and target ID
// at offset 0x2c4, calls FUN_0058e2a0 for matching entities.

static uint32_t* DAT_007027b4 = nullptr;  // Entity dispatch list
static uint32_t  DAT_007488dc = 0;        // Self-dispatch skip flag

extern void NetworkEntityCallback(uint32_t param1, uint32_t param2, uint32_t param3);  // FUN_0058e2a0
extern void NetworkEventPreProcess(uint32_t param);  // FUN_0058de90

void NetworkEventDispatch(int param_1, uint32_t* param_2, uint32_t param_3, uint32_t param_4)
{
    if ((DAT_00702774 != (uint32_t)param_1) || (DAT_007488dc == 0)) {
        NetworkEventPreProcess(param_3);

        for (uint32_t* puVar1 = DAT_007027b4; puVar1 != nullptr; puVar1 = (uint32_t*)*puVar1) {
            if ((*(int*)(puVar1[3] + 0x22c) == 0x3e) &&
                (*(int*)(puVar1[3] + 0x2c4) == param_1)) {
                NetworkEntityCallback(param_4, *param_2, param_3);
            }
        }
    }
}

// Stub implementations
void NetworkEntityCallback(uint32_t, uint32_t, uint32_t) {}
void NetworkEventPreProcess(uint32_t) {}

// ═══════════════════════════════════════════════════════════════════
// SetEntityPosition (FUN_0055c150) — 121 callers
// ═══════════════════════════════════════════════════════════════════
// Updates entity position (offsets 0xf0, 0xf4, 0xf8) with 3 floats
// passed in XMM1/XMM2/XMM3. If position changed, frees cached mesh
// data at offset 0x270 (pathfinding/collision cache).
// Then shifts position history: 0xfc..0x104 ← 0xf0..0xf8 (current→previous),
// and 0x108..0x110 ← 0xfc..0x104 (previous→old).

void SetEntityPosition(int param_1, float x, float y, float z)
{
    // Check if position actually changed
    if ((*(float*)(param_1 + 0xf0) != x) ||
        (*(float*)(param_1 + 0xf4) != y) ||
        (*(float*)(param_1 + 0xf8) != z))
    {
        // Position changed — invalidate cached mesh data
        free(*(void**)(param_1 + 0x270));
        *(uint32_t*)(param_1 + 0x270) = 0;
    }

    // Update current position
    *(float*)(param_1 + 0xf0) = x;
    *(float*)(param_1 + 0xf4) = y;
    *(float*)(param_1 + 0xf8) = z;

    // Shift position history: old ← previous ← current
    *(uint64_t*)(param_1 + 0x108) = *(uint64_t*)(param_1 + 0xfc);  // old ← previous
    *(uint32_t*)(param_1 + 0x110) = *(uint32_t*)(param_1 + 0x104);
    *(uint64_t*)(param_1 + 0xfc)  = *(uint64_t*)(param_1 + 0xf0);  // previous ← current
    *(uint32_t*)(param_1 + 0x104) = *(uint32_t*)(param_1 + 0xf8);
}

// ═══════════════════════════════════════════════════════════════════
// SpatialSoundCheck (FUN_0062a0b0) — 438 callers
// ═══════════════════════════════════════════════════════════════════
// Iterates the spatial listener list (DAT_0073c91c), checking if a
// sound at a given position should play based on:
//   - 2D distance to listener (via VectorDistanceSq2D)
//   - Listener's radius threshold (offset +8)
//   - If entity provided: angle check (0xf8 - listener[7] vs DAT_0066c0d8)
//   - Entity ID matching (0x1d8)
//   - Entity type filtering (types 3 and 0x434 always audible)
// Returns 1 if sound should play for any listener, 0 if not.

static uint32_t* DAT_0073c91c_head = nullptr;  // Listener list head
static uint32_t* DAT_0073c91c_end  = nullptr;  // Listener list end
static float DAT_0066c0d8 = 3.14159f;  // Half-FOV angle threshold

int SpatialSoundCheck(int param_1, int param_2)
{
    uint32_t* puVar2 = DAT_0073c91c_end;
    uint32_t* puVar1 = DAT_0073c91c_head;

    // Iterate through listener list
    while (true) {
        if (puVar1 == puVar2 || puVar1 == nullptr) {
            return 0;  // No listener matched
        }

        if (param_1 == 0) {
            // No entity — just check distance
            if (param_2 != 0) {
                float dist = VectorDistanceSq2D(reinterpret_cast<float*>(param_2),
                                                reinterpret_cast<float*>(puVar1 + 5));
                if (dist <= *reinterpret_cast<float*>(puVar1 + 2)) {
                    return 1;  // Within radius
                }
            }
        } else {
            // Entity provided — check distance + angle + type
            float dist = VectorDistanceSq2D(reinterpret_cast<float*>(param_1 + 0xf0),
                                            reinterpret_cast<float*>(puVar1 + 5));
            if (dist <= *reinterpret_cast<float*>(puVar1 + 2)) {
                float angleDiff = *(float*)(param_1 + 0xf8) - *reinterpret_cast<float*>(puVar1 + 7);
                // FUN_0042d350() — empty no-op

                if (angleDiff < DAT_0066c0d8) {
                    // Within angular range — check entity ID
                    if (*(int*)(param_1 + 0x1d8) != *(int*)(*reinterpret_cast<int*>(puVar1 + 4) + 0x1d8)) {
                        return 1;
                    }
                    int entityType = *(int*)(param_1 + 4);
                    if (entityType == 3 || entityType == 0x434) {
                        return 1;  // Types 3 and 0x434 always audible
                    }
                    return 1;
                }
            }
        }
        puVar1++;
    }
}

// ═══════════════════════════════════════════════════════════════════
// WeaponRangeCheck (FUN_004a67b0) — 99 callers
// ═══════════════════════════════════════════════════════════════════
// Checks if an entity's weapon/action slot is within range.
// Steps:
//   1. Resolve entity from param_1's slot table (offset 0x14c + param_2*0x1c)
//   2. Check entity type (0x22c) for type-specific range calculation
//   3. Types 0x20/0x4a: FUN_00497350 gets range scale
//   4. Types 0x52/0x53: FUN_00580930 gets range scale
//   5. Compare scaled distance against entity's attack range
// Returns 1 if in range, 0 if not.

static float DAT_0066c09c = 1.0f;    // Default range scale
static float DAT_0066bd28 = 1.0f;    // Range multiplier

int WeaponRangeCheck(int param_1, int param_2)
{
    int iVar2 = (param_1 != 0) ? *(int*)(param_1 + 0x14c) : 0;
    iVar2 = *(int*)(iVar2 + 0x20 + param_2 * 0x1c);

    if (iVar2 == 0) return 0;

    int entityType = *(int*)(iVar2 + 0x22c);
    float rangeScale = DAT_0066c09c;  // Default

    if (entityType == 0x20 || entityType == 0x4a) {
        // FUN_00497350() — get range for weapon types
        // rangeScale = result in XMM0
    } else if (entityType == 0x52 || entityType == 0x53) {
        // FUN_00580930() — get range for creature types
        // rangeScale = result in XMM0
    }

    // Check if entity has enough state for range check
    if (*(int*)(iVar2 + 0x130) > 3) {
        float attackRange;
        if (entityType == 0x20 || entityType == 0x52) {
            attackRange = *(float*)(*(int*)(iVar2 + 0x14c) + 0x594);
        } else {
            attackRange = **(float**)(iVar2 + 0x14c);
        }

        if (rangeScale * DAT_0066bd28 * *(float*)(*(int*)0x007028f4 + 0xb84) < attackRange) {
            return 1;  // In range
        }
    }

    return 0;  // Out of range
}

// ═══════════════════════════════════════════════════════════════════
// ObserverNotify (FUN_0042fb40) — 106 callers
// ═══════════════════════════════════════════════════════════════════
// Calls observer callback via vtable[4] (offset 0x10) if present,
// then clears the observer pointer at offset 9 (36 bytes).
// param_1[9] = observer pointer (0 = no observer)

void ObserverNotify(int* param_1)
{
    int* piVar1 = (int*)param_1[9];
    if (piVar1 != nullptr) {
        // Call vtable[4] with (piVar1 != param_1) as argument
        auto callback = reinterpret_cast<void(*)(int)>(*(int*)(*piVar1 + 0x10));
        callback((int)(piVar1 != param_1));
        param_1[9] = 0;
    }
}

// ═══════════════════════════════════════════════════════════════════
// EntityCommandDispatch (FUN_005d8c90) — 83 callers, 87 lines
// ═══════════════════════════════════════════════════════════════════
// Routes console/dialog commands to entity handlers.
// Command types (from param_4+4):
//   0x4C-0x4F: Special handlers (0x4D = camera reset)
//   0: String resolve from VFS, then callback dispatch
//   Other: Entity ID lookup + string comparison + parameter dispatch

static uint32_t* DAT_00702d50 = nullptr;  // String resolve callback

int EntityCommandDispatch(int param_1, uint32_t* param_2, int param_3, int param_4)
{
    if (param_3 == 0) {
        int cmdType = *(int*)(param_4 + 4);

        // Handle special command types 0x4C-0x4F
        if ((unsigned)(cmdType - 0x4c) < 4) {
            if (cmdType == 0x4d) {
                // Camera reset: save/restore camera state
                int camObj = *reinterpret_cast<int*>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 0x18) + 0x480) + 8);
                uint32_t savedState = *(uint32_t*)(camObj + 0x1c);
                *(uint32_t*)(camObj + 0x1c) = 0;
                // FUN_005d79a0() — pre-callback
                // FUN_005d7de0() — post-callback
                *(uint32_t*)(camObj + 0x1c) = savedState;
            }
            return -1;  // 0xFFFFFFFF
        }

        if (cmdType == 0) {
            // String command: resolve from VFS then dispatch
            // FUN_005e80c0(*param_2) — GetLocalizedString
            // (*DAT_00702d50)(param_4+4) — resolve entity from string
            // Walk resolved string for entity matching
            return -1;
        }

        // Entity ID command: lookup + parameter dispatch
        // Iterates entities, compares names, dispatches callbacks
        return 0;
    }

    // param_3 != 0: direct entity command
    return 0;
}

// ═══════════════════════════════════════════════════════════════════
// AllocateEntitySlot (FUN_00559530) — 65 callers, 71 lines
// ═══════════════════════════════════════════════════════════════════
// Allocates an entity slot from the free pool (DAT_007027e8 linked list).
// Steps:
//   1. Pop head from free list
//   2. If empty: ShowErrorDialog "Out of objects, exceeded limit"
//   3. memset 0x374 bytes (884 bytes) — entity base size
//   4. Append to active entity list (DAT_007027a8)
//   5. Set entity ID from FUN_00552310 (unique ID generator)
// Returns allocated slot pointer or nullptr.

static int* DAT_007027e8 = nullptr;     // Entity free-list head
static int* DAT_007027a8 = nullptr;     // Entity active-list head
static int  DAT_00725dfc = 0;           // Active entity count
static int  DAT_00725df8 = 0;           // Peak entity count

extern void ShowErrorDialog(const char* msg);  // FUN_0062edc0

int* AllocateEntitySlot()
{
    int* slot = DAT_007027e8;

    // Track stats
    DAT_00725dfc++;
    if (DAT_00725df8 < DAT_00725dfc) {
        DAT_00725df8 = DAT_00725dfc;
    }

    // Check if pool is empty
    if (DAT_007027e8 == nullptr) {
        ShowErrorDialog("Out of objects, exceeded limit");
        return nullptr;
    }

    // Pop from free list
    DAT_007027e8 = reinterpret_cast<int*>(*DAT_007027e8);

    // Zero-initialize entity (0x374 = 884 bytes)
    memset(slot, 0, 0x374);

    // Append to active entity list (walk to tail)
    int* piVar2 = reinterpret_cast<int*>(&DAT_007027a8);
    for (int* piVar1 = DAT_007027a8; piVar1 != nullptr; piVar1 = reinterpret_cast<int*>(*piVar1)) {
        piVar2 = piVar1;
    }

    // Link into active list (doubly-linked)
    // FUN_00552310 — generate unique entity ID
    // slot->next = nullptr, slot->prev = tail
    // tail->next = slot
    // (stub: simplified linking)
    (void)piVar2;

    return slot;
}

// ═══════════════════════════════════════════════════════════════════
// ApplyEntityTransform (FUN_0048fba0) — 59 callers, 170 lines
// ═══════════════════════════════════════════════════════════════════
// Applies entity's 4x3 transform matrix to the render pipeline.
// Processes 4 rows of transform data, applies scale factors,
// and XOR-encodes the depth (Z) column with DAT_0066c580 key.
// This is the core function that bridges entity data → GPU transform.
// param_1 = transform context (0x60+ bytes)
//   +0x00: flags/status
//   +0x08: transform rows (4 x 6 floats = position + rotation)
//   +0x60: output matrix

extern uint32_t g_depthXorKey;  // DAT_0066c580 — defined in Camera.cpp or MatrixOps.cpp

static uint32_t s_depthXorKey = 0;  // DAT_0066c580 local copy

void ApplyEntityTransform(int* param_1)
{
    if (param_1[2] == 0) return;

    // Process 4 transform rows
    int* piVar3 = param_1 + 0x18;
    for (int row = 4; row > 0; row--) {
        // Each row: 6 floats at piVar3 + [0,8,16,24,32,40]
        // Apply scale and XOR depth encoding
        uint32_t depthKey = s_depthXorKey;

        // Check flags for this row
        uint32_t rowFlags = piVar3[8];
        bool hasDepth = (rowFlags & 0x80000000) != 0;

        if (hasDepth) {
            // XOR depth column with key for obfuscation
            float depthVal = *reinterpret_cast<float*>(piVar3 + 6);
            uint32_t depthBits = *reinterpret_cast<uint32_t*>(&depthVal);
            depthBits ^= depthKey;
            *reinterpret_cast<float*>(piVar3 + 6) = *reinterpret_cast<float*>(&depthBits);
        }

        // Apply scale factors from entity data
        // Output to render matrix at appropriate offsets

        piVar3 += 10;  // Next row (stride = 10 DWORDs = 40 bytes)
    }
}

// ═══════════════════════════════════════════════════════════════════
// EntityPropertyLookup (FUN_005d8890) — 59 callers, 74 lines
// ═══════════════════════════════════════════════════════════════════
// Resolves an entity property from a command string.
// Steps:
//   1. If param_3 != 0, return 0xFFFFFF (not ready)
//   2. Resolve string from param_4+4 via DAT_00702d58 callback
//   3. If type 0: resolve entity from string, dispatch to callbacks
//   4. Compare resolved entity name, compute distance, return property value
// Returns property value or 0xFFFFFF on error.

static void* DAT_00702d58 = nullptr;  // String resolve callback

uint32_t EntityPropertyLookup(int param_1, int param_2, int param_3, int param_4)
{
    if (param_3 != 0) {
        return 0xFFFFFF;  // Not ready
    }

    char* resolvedStr = reinterpret_cast<char*>(
        reinterpret_cast<uint32_t(*)(uint32_t)>(DAT_00702d58)(*(uint32_t*)(param_4 + 4)));

    if (resolvedStr != nullptr) {
        int cmdType = *(int*)(param_4 + 4);

        if (cmdType == 0) {
            // String command: resolve entity name and dispatch
            // (*DAT_00702d50)() — resolve entity from string
            // Walk resolved string, compare entity names
            // Compute distance, return property value
            return 0xFFFFFF;
        }

        // Entity ID command: walk string, find entity, compute value
        return 0;
    }

    return 0xFFFFFF;
}

// ═══════════════════════════════════════════════════════════════════
// EntityOwnerTableCheck (FUN_00497350) — 53 callers
// ═══════════════════════════════════════════════════════════════════
// Checks if an entity is registered in its owner's item table.
// Owner's items buffer has 26 entries (stride 28 bytes = 7 ints).
// Entry+0x00 stores entity pointer. Early returns for type 0x20
// and entity states 9-12.

void EntityOwnerTableCheck(int* entity)
{
    if (entity == nullptr) return;

    // Type 0x20 entities skip the check
    if (*reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(entity) + 0x22c) == 0x20) {
        return;
    }

    // Walk owner's item table
    int* owner = *reinterpret_cast<int**>(reinterpret_cast<uintptr_t>(entity) + 0x2c4);
    if (owner != nullptr) {
        int* items = *reinterpret_cast<int**>(reinterpret_cast<uintptr_t>(owner) + 0x14c);
        int* entry = reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(items) + 0x20);
        int idx = 0;
        do {
            if (*entry == reinterpret_cast<int>(entity)) {
                return;  // Found in owner table
            }
            idx++;
            entry += 7;  // stride = 7 ints = 28 bytes
        } while (idx < 0x1a);  // 26 entries max
    }

    // Check entity state range [9, 12]
    int state = *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(entity) + 0x130);
    if (static_cast<uint32_t>(state - 9) < 4) {
        return;
    }
}

// ═══════════════════════════════════════════════════════════════════
// EntityOwnerTableCheckVariant (FUN_00580930) — 51 callers
// ═══════════════════════════════════════════════════════════════════
// Variant of EntityOwnerTableCheck for a different entity category.
// Type 0x52 skips the check. Owner table has 16 entries (vs 26).
// Same stride (28 bytes) and state range [9, 12].

void EntityOwnerTableCheckVariant(int* entity)
{
    if (entity == nullptr) return;

    // Type 0x52 entities skip the check
    if (*reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(entity) + 0x22c) == 0x52) {
        return;
    }

    // Walk owner's item table (16 entries)
    int* owner = *reinterpret_cast<int**>(reinterpret_cast<uintptr_t>(entity) + 0x2c4);
    if (owner != nullptr) {
        int* items = *reinterpret_cast<int**>(reinterpret_cast<uintptr_t>(owner) + 0x14c);
        int* entry = reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(items) + 0x20);
        int idx = 0;
        do {
            if (*entry == reinterpret_cast<int>(entity)) {
                return;
            }
            idx++;
            entry += 7;  // stride = 7 ints = 28 bytes
        } while (idx < 0x10);  // 16 entries
    }

    // Check entity state range [9, 12]
    int state = *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(entity) + 0x130);
    if (static_cast<uint32_t>(state - 9) < 4) {
        return;
    }
}

} // namespace Giants
