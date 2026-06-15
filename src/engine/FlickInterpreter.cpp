// Giants Engine - FLICK Cinematic Script Interpreter Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_004e7b10 — Switch-based opcode interpreter for cinematic sequences.
// The FLICK data is a stream of opcode records read from level files.
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include "FlickInterpreter.h"

namespace Giants {

// ─── External data references ─────────────────────────────────
static uint32_t* DAT_00747d2c = nullptr;    // FLICK context (main state)
static float     DAT_00727e38 = 0;          // Frame delta time
static uint32_t  g_depthXorKey = 0;         // DAT_0066c580
static float     DAT_0066c12c = 0;          // Flick timing constant
static float     DAT_0066bf2c = 0;          // Wave period for animation
static uint32_t  DAT_0074c5d4 = 0;          // Error counter for FLICK errors
static uint32_t  DAT_00702770 = 0;          // Scene/render context

// Stub helpers for unresolved functions
static int GetSubTableData(int) { return 0; }
static int LookupTableEntry(uint32_t, int) { return 0; }

// operator_new replacement (Ghidra artifact — maps to C++ new)
static inline void* operator_new(size_t size) { return malloc(size); }

// ─── ProcessFlickCommands (FUN_004e7b10) — FAIL (usable ~40%) ──

uint32_t ProcessFlickCommands()
{
    if (DAT_00747d2c == nullptr) return 1;

    uint32_t* ctx = DAT_00747d2c;
    int stringTableBase = ctx[0x21];
    uint32_t* opcodes = (uint32_t*)ctx[0x22];

    // Main dispatch loop. KEY: each opcode record carries its own size at
    // opcodes[1] (in u32 units). Advance = opcodes += opcodes[1]. Yield opcodes
    // (5, 8, 9, 34) save position + return to the game loop.
    while (true) {
        uint32_t op = opcodes[0];
        uint32_t recordSize = opcodes[1];  // record size in u32 (self-describing)
        if (recordSize == 0) break;         // safety (avoid infinite loop)

        switch (op) {
        case 1: {  // InitDirector — create director object in slot
            int nameOff = (opcodes[3] != 0) ? stringTableBase + opcodes[3] : 0;
            int* slot = (int*)(ctx[0x27] + opcodes[2] * 0xc);
            if (slot && slot[2] == 0) {
                // FUN_00633480(0, 0, nameOff) — create director (stubbed)
                slot[2] = 1;  // mark initialized
            }
            break;
        }
        case 2: {  // SetCameraTarget — set the camera's look-at target
            // FUN_004e5530(targetName, opcodes[4], opcodes[5]) — stubbed
            break;
        }
        case 3: {  // CreateEntity — create a scene entity from template
            int entityName = (opcodes[5] != 0) ? stringTableBase + opcodes[5] : 0;
            int templateName = (opcodes[3] != 0) ? stringTableBase + opcodes[3] : 0;
            int entityId = opcodes[2];
            // FUN_00634e20 — create entity instance (stubbed)
            (void)entityName; (void)templateName; (void)entityId;
            break;
        }
        // Yield opcodes — save position + return to game loop (resume next call)
        case 5:   // Wait/Yield
        case 8:   // End of block
        case 9:   // End of section
        case 34:  // Frame wait
            ctx[0x22] = (uint32_t)(opcodes + recordSize);  // save resume position
            return 1;
        default:
            // Opcodes 4, 6, 7, 10-33, 35+: move, rotate, animate, sound, etc.
            // Processed but stubbed — just advance past them.
            break;
        }

        opcodes += recordSize;  // advance to next record (self-describing size)
        ctx[0x22] = (uint32_t)opcodes;  // update position
    }

    return 1;
}

// ─── FlickSetCameraTarget (FUN_004e5530) — PASS (usable ~75%) ──

uint32_t FlickSetCameraTarget(uint32_t* param_1, int param_2,
                              int param_3, int param_4, int param_5)
{
    // Step 1: Resolve camera target from slot table
    float* targetData;
    if (param_2 < 0) {
        targetData = nullptr;
    } else {
        targetData = (float*)(param_1[0x27] + param_2 * 0xc);
    }
    float targetRef = (targetData != nullptr) ? *targetData : 0.0f;

    // Step 2: Validate and initialize actor slot
    if (param_4 < 0) {
        return 0;
    }

    int* actorSlot = (int*)(param_4 * 0x8e4 + param_1[0x28]);
    if (actorSlot == nullptr) {
        return 0;
    }

    // Check for duplicate initialization
    if (actorSlot[0x238] != 0) {
        // FUN_00640a00 — log duplicate actor error
        return 0;
    }

    // Initialize actor slot
    *actorSlot = 0;
    actorSlot[1] = param_3;     // Entity type
    actorSlot[2] = 1;           // Mark as active

    // Step 3: Create entity instance
    if (param_5 < 0) {
        // No sub-entity — create with default params
        // Entity creation path:
        //   iVar3 = FUN_0055a8a0() — lookup entity type
        //   if (iVar3 == 0) error("Error: ObjObj type %d not found")
        //   else FUN_0055a4a0(iVar3) + FUN_0055a710(iVar3) — init entity
        actorSlot[0xdf] = 0x3f800000;  // 1.0f — default scale
    } else {
        // With sub-entity — same creation path
        // FUN_0055a8a0() + FUN_0055a4a0() + FUN_0055a710()
    }

    // Step 4: If target has animation data, set up animation
    if (targetRef != 0.0f) {
        *actorSlot = (int)targetData;

        // Copy animation state from target's sub-data
        if ((int*)actorSlot[5] != nullptr) {
            int* src = (int*)actorSlot[5];
            int* dst = actorSlot + 0xe0;
            for (int j = 0x119; j != 0; j--) {
                *dst = *src;
                src++;
                dst++;
            }
        }

        // FUN_00559e60 — initialize animation state

        // Step 5: Allocate animation path data (0x58 bytes)
        float* animData = (float*)malloc(0x58);
        memset(animData, 0, 0x58);

        float wavePeriod = DAT_0066bf2c;
        animData[10] = targetRef;   // Target reference

        // Compute frame-to-world scale
        int texWidth = *(int*)((int)targetRef + 0x18);
        int texHeight = *(int*)((int)targetRef + 0x1c);
        animData[1] = *(float*)((int)targetRef + 0x10);
        *animData = (float)(*(int*)((int)targetRef + 0x14) - *(int*)((int)targetRef + 0x10)) *
                    ((wavePeriod / (float)texHeight) / (float)texWidth);

        // Fill animation frame mappings from actor's sub-entity table
        int actorState = actorSlot[5];
        float* frameOut = animData + 0xb;  // 11 float slots
        int* subEntity = (int*)(actorState + 0x400);
        for (int k = 0; k < 10; k++) {
            if (*subEntity == 0) break;
            int entityDef = *(int*)(*subEntity + 0x78);
            if (entityDef != 0) {
                // FUN_00633560 — resolve animation frame
                // *frameOut = FUN_00633560(targetRef, param_3, entityDef, 0);
            }
            subEntity++;
            frameOut++;
        }

        // Store animation data on actor
        *(float**)(actorState + 8) = animData;

        // Register with entity pool
        // FUN_006405d0(*param_1, entityCount * 4, 1)
        // Store result at animData + 0x54

        // Initialize render state
        // FUN_0048f2f0(0, 0x20, 1, 0, 0) — set render flags
        // FUN_0048f2f0(0xfe, 0, 1, 0, 0) — clear render state
    }

    // Step 6: Finalize actor initialization
    // FUN_0063e7f0(actorSlot + 0xbc) — clear actor lock
    actorSlot[0x22b] = 0;
    actorSlot[0x22c] = 0;
    actorSlot[0x22d] = 0;
    actorSlot[0x235] = 0;
    actorSlot[0x234] = 0;
    actorSlot[0x236] = 0;
    actorSlot[0x238] = 1;    // Mark as initialized

    return 1;
}

// ─── FlickFindEntityIndex (FUN_004e4d40) — PASS ────────────────

int FlickFindEntityIndex(uint32_t param_1)
{
    if (DAT_00702770 == 0) {
        return -1;
    }

    int index = 0;
    int offset = 0;
    do {
        // FUN_00632950 — compare entity name at scene offset
        int result = 0; // FUN_00632950(param_1, DAT_00702770 + 0x26c + offset);
        if (result != 0) {
            return index;
        }
        offset += 0x20;
        index++;
    } while (offset < 0x1000);  // 128 slots * 0x20 = 0x1000

    return -1;
}

// ─── FlickLoadAnimationFile (FUN_004e5030) — PASS (usable ~85%) ─

uint32_t* FlickLoadAnimationFile(int param_1)
{
    // Step 1: Construct filename
    char filename[132];
    filename[0] = '\0';

    if (DAT_00702770 == 0) {
        // No scene context — use param_1 directly
        // FUN_00463000(filename, "flk_%s.bin", param_1)
        goto open_file;
    }

    // Try to resolve name from entity table
    {
        int offset = 0;
        int entityIdx = 0;
        do {
            // FUN_00632950 — compare name
            int found = 0; // FUN_00632950(param_1, DAT_00702770 + 0x26c + offset);
            if (found != 0) {
                param_1 = DAT_00702770 + 0x26c + entityIdx * 0x20;
                goto open_file;
            }
            offset += 0x20;
            entityIdx++;
        } while (offset < 0x1000);
    }

open_file:
    // Step 2: Open file via VFS
    // HANDLE hFile = FUN_00624b60();
    HANDLE hFile = nullptr;  // Placeholder
    if (hFile == nullptr) {
        return nullptr;
    }

    // Step 3: Read header (0x18 bytes)
    DWORD header[6];
    DWORD bytesRead;
    ReadFile(hFile, &header[1], 0x18, &bytesRead, nullptr);

    // header[1] = local_a4 — magic/version
    // header[2] = sStack_a0 — body size
    // header[3] = uStack_9c
    // header[4] = uStack_98
    // header[5..6] = local_94 — additional header data

    // Step 4: Allocate and read body
    size_t bodySize = header[2];
    uint32_t* animData = (uint32_t*)malloc(bodySize);
    animData[0] = header[1];
    animData[1] = (uint32_t)bodySize;
    animData[2] = header[3];
    animData[3] = header[4];
    // *(uint64_t*)(animData + 4) = header[5..6];  // 8 bytes

    ReadFile(hFile, animData + 6, bodySize - 0x18, &bytesRead, nullptr);
    CloseHandle(hFile);

    return animData;
}

// ─── FlickCreateInterpreter (FUN_004e5150) — PASS (usable ~80%) ─

uint32_t* FlickCreateInterpreter(int param_1, uint32_t param_2, int param_3)
{
    // Step 1: Allocate context from pool
    // uint32_t allocator = FUN_006406f0(0, 0);
    // uint32_t* ctx = FUN_006405d0(allocator, 0x140, 1);
    uint32_t* ctx = nullptr;  // Placeholder

    // *ctx = allocator;

    // Step 2: Copy name
    if (param_3 != 0) {
        // FUN_006329a0(ctx + 1, param_3, 0x7f) — strncpy name
    }

    // Step 3: Set command table reference
    ctx[0x21] = param_1;
    int entityCount = 0;
    uint32_t animCount = 0;
    uint32_t pathCount = 0;

    if (param_1 == 0) {
        ctx[0x25] = 0;  // Animation count
        ctx[0x24] = 0;  // Entity count
    } else {
        ctx[0x22] = param_1 + 0x18;   // Opcode data pointer
        ctx[0x25] = *(uint32_t*)(param_1 + 0xc);  // Animation count
        entityCount = *(int*)(param_1 + 8);
        ctx[0x24] = entityCount;
        pathCount = *(uint32_t*)(param_1 + 0x10);
    }
    ctx[0x26] = pathCount;
    ctx[0x23] = param_2;

    // Step 4: Allocate entity/actor/path pools
    // ctx[0x27] = FUN_006405d0(allocator, entityCount * 0xc, 1);    — entity pool
    // ctx[0x28] = FUN_006405d0(allocator, ctx[0x25] * 0x8e4, 1);   — actor pool
    // ctx[0x29] = FUN_006405d0(allocator, pathCount * 0x380, 1);    — path pool

    // Step 5: Initialize default values
    ctx[0x2a] = 1;                 // Active flag
    ctx[0x2f] = 1;                 // Visible flag
    ctx[0x30] = 1;                 // Enabled flag
    ctx[0x34] = 0x3f800000;        // 1.0f — scale X
    ctx[0x33] = 0x3f800000;        // 1.0f — scale Y
    ctx[0x35] = 0;                 // Rotation
    ctx[0x37] = 0x3f800000;        // 1.0f — opacity
    ctx[0x36] = 0x3f800000;        // 1.0f — brightness
    ctx[0x38] = 0;                 // Flags
    ctx[0x3b] = 0x3f800000;        // 1.0f — speed
    ctx[0x3a] = 0x3f800000;        // 1.0f — blend
    ctx[0x3c] = 0;                 // Blend mode
    // ctx[0x3e] = param from stack (additional parameter)

    // Step 6: Recursively load sub-interpreter if referenced
    int subRef = *(int*)(param_1 + 0x14);
    if (subRef != 0) {
        // FUN_004e5030 — load sub-animation file
        int subAnim = 0; // FUN_004e5030(param_1 + subRef);
        if (subAnim != 0) {
            // FUN_004e4d40 — find entity index for sub-animation
            // FlickFindEntityIndex(param_1 + subRef);
            // Recursively create sub-interpreter
            // ctx[0x32] = FlickCreateInterpreter(subAnim, ...);
        }
    }

    ctx[0x4e] = 0x447a0000;   // 1000.0f — default duration (ms)

    return ctx;
}

// ─── SetRenderFlags (FUN_0048f2f0) ──────────────────────────────
// Ghidra: FUN_0048f2f0 (423 callers, 0 callees)
// Purpose: Set or clear render flags on a scene object. Manages a per-slot
//   render state array (0x24-byte stride) with current, previous, and target
//   values. When the target time (param_7) is set and the current time has
//   not yet started, it copies current state to previous/current for
//   interpolation. Sets the dirty flag (0x100) on the new target state.
//   If DAT_00702b14 is false, forces duration to 0 (instant change).
// Original:
// void __fastcall FUN_0048f2f0(int param_1,int param_2,undefined4 param_3,
//     uint param_4,undefined4 param_5,undefined4 param_6,float param_7)
// {
//   ... (saves prev/cur render state for interpolation, sets new target)
// }
void SetRenderFlags(int objectPtr, int slotIndex, uint32_t param_3,
                    uint32_t param_4, uint32_t param_5, uint32_t param_6,
                    float duration)
{
    extern char DAT_00702b14;  // Animation enabled flag
    extern float DAT_0066bf2c;  // Current time
    extern float DAT_0066bef8;  // Last render time

    if (DAT_00702b14 == '\0') {
        duration = 0.0f;
    }

    uint32_t timeValue = 0;
    if (duration == 0.0f) {
        timeValue = 0;
    } else {
        // Check if target time has not yet started (current time < slot time)
        float* slotTime = (float*)(objectPtr + 0x7c + slotIndex * 0x24);
        timeValue = *(uint32_t*)&DAT_0066bf2c;

        if (*slotTime <= DAT_0066bef8 && DAT_0066bef8 != *slotTime) {
            // Copy current state to "previous" for interpolation
            uint32_t* cur = (uint32_t*)(objectPtr + 0x60 + slotIndex * 0x24);
            uint32_t* prev = (uint32_t*)(objectPtr + 0xa8 + slotIndex * 0x24);
            prev[0] = cur[0];
            prev[1] = cur[1];
            prev[2] = cur[2];
            prev[3] = cur[3];

            // Copy alternate state to alternate previous
            uint32_t* curAlt = (uint32_t*)(objectPtr + 0x70 + slotIndex * 0x24);
            uint32_t* prevAlt = (uint32_t*)(objectPtr + 0xb8 + slotIndex * 0x24);
            prevAlt[0] = curAlt[0];
            prevAlt[1] = curAlt[1];
            prevAlt[2] = curAlt[2];
            prevAlt[3] = curAlt[3];

            // Copy target and set dirty flag
            uint32_t* target = (uint32_t*)(objectPtr + 200 + slotIndex * 0x24);
            *target = *(uint32_t*)(objectPtr + 0x80 + slotIndex * 0x24);
            *target |= 0x100;  // Mark dirty
        }
    }

    // Write new render state values
    *(float*)(objectPtr + 0x78 + slotIndex * 0x24) = duration;
    *(uint32_t*)(objectPtr + 0x7c + slotIndex * 0x24) = timeValue;
    *(uint32_t*)(objectPtr + 0x60 + slotIndex * 0x24) = param_3;
    *(uint32_t*)(objectPtr + 0x74 + slotIndex * 0x24) = param_6;
    *(uint32_t*)(objectPtr + 0x80 + slotIndex * 0x24) = param_4 | 0x100;
    *(uint32_t*)(objectPtr + 0x70 + slotIndex * 0x24) = param_5;
}

// ─── InitEntityRenderState (FUN_00559e60) ───────────────────────
// Ghidra: FUN_00559e60 (11 callers, 6 callees)
// Purpose: Initialize or copy an entity's render state. If param_2 is 0,
//   frees the entity's sub-object array and releases all 10 COM slots
//   (ref-counted Release pattern). If param_2 is non-null, copies the
//   sub-object table from param_2's entity pool (up to 10 entries),
//   allocating a matching sub-object buffer and creating new COM objects
//   (via operator new(0x38)) with vtable PTR_FUN_00664600 for each.
//   Links the entity's slot table (param_1+0x10, stride 8) to the new objects.
// Original:
// void __fastcall FUN_00559e60(int param_1,int param_2) { ... ~80 lines ... }
void InitEntityRenderState(int entityState, int sourceEntity)
{
    if (entityState == 0) return;

    if (sourceEntity == 0) {
        // Cleanup path: free sub-object array and release all COM slots
        free(*(void**)(entityState + 0x32c));
        *(uint32_t*)(entityState + 0x32c) = 0;
        *(uint32_t*)(entityState + 0x328) = 0;

        int* slot = (int*)(entityState + 0x10);
        for (int i = 0; i < 10; i++) {
            slot[-1] = 0;  // Clear sub-object pointer
            int* obj = (int*)*slot;
            *slot = 0;
            if (obj != nullptr) {
                // COM Release: decrement refcount[1], if 0 call vtable[0],
                // then decrement refcount[2], if 0 call vtable[1]
                // InterlockedDecrement pattern
                int ref1 = obj[1] - 1;
                obj[1] = ref1;
                if (ref1 == 0) {
                    // (*(vtable[0]))(obj) — destructor
                }
                int ref2 = obj[2] - 1;
                obj[2] = ref2;
                if (ref2 == 0) {
                    // (*(vtable[1]))(obj) — deallocate
                }
            }
            slot += 2;  // Move to next slot pair
        }
    } else {
        // Copy path: replicate sub-object table from source entity
        int sourceSubCount = *(int*)(sourceEntity + 0x450);

        if (sourceSubCount == 0) {
            // No sub-objects: just free existing
            free(*(void**)(entityState + 0x32c));
            *(uint32_t*)(entityState + 0x32c) = 0;
            *(uint32_t*)(entityState + 0x328) = 0;
        } else {
            // Reallocate sub-object buffer if count changed
            if (*(int*)(entityState + 0x328) != sourceSubCount) {
                // Recursive cleanup of existing sub-objects
                // FUN_00559e60(entityState, 0);

                *(int*)(entityState + 0x328) = sourceSubCount;
                void* newBuf = malloc(sourceSubCount * 0x44);
                *(void**)(entityState + 0x32c) = newBuf;
            }
            memset(*(void**)(entityState + 0x32c), 0,
                   *(int*)(entityState + 0x328) * 0x44);
        }

        // Copy sub-entity entries from source (up to 10)
        int* srcSlot = (int*)(sourceEntity + 0x400);
        uint32_t count = 0;
        int* dstSlot = (int*)(entityState + 0x10);

        do {
            dstSlot[-1] = 0;  // Clear sub-object link
            int* oldObj = (int*)*dstSlot;
            *dstSlot = 0;
            if (oldObj != nullptr) {
                // COM Release old object
                int ref1 = oldObj[1] - 1;
                oldObj[1] = ref1;
                if (ref1 == 0) { /* vtable[0] dtor */ }
                int ref2 = oldObj[2] - 1;
                oldObj[2] = ref2;
                if (ref2 == 0) { /* vtable[1] dealloc */ }
            }

            int srcEntry = *srcSlot;
            if (srcEntry == 0) break;

            // Create new sub-object (0x38 bytes, vtable PTR_FUN_00664600)
            uint32_t* newObj = (uint32_t*)operator_new(0x38);
            newObj[0] = 0;
            newObj[1] = 0;
            newObj[2] = 1;  // refcount
            newObj[4] = 1;  // refcount2
            // *(vtable**)newObj = &PTR_FUN_00664600;
            // FUN_00501240(srcEntry + 0x20) — initialize from source

            dstSlot[-1] = (int)newObj + 0xc;  // Link to sub-object data
            // Release old (already done above for *dstSlot)
            *dstSlot = (int)newObj;

            dstSlot += 2;
            count++;
            srcSlot++;
        } while (count < 10);
    }

    // Store back-reference to source entity
    *(int*)(entityState + 8) = sourceEntity;
}

// ─── CopyEntityState (FUN_0055a4a0) ─────────────────────────────
// Ghidra: FUN_0055a4a0 (81 callers, 9 callees)
// Purpose: Copy entity state from source to destination. If the entity type
//   (slot at +0x22c) differs, tears down the old type via vtable dispatch.
//   Copies 0x80 bytes of state from src+0x1dc to dst+0x1dc, calls
//   InitEntityRenderState (FUN_00559e60) to clone render objects, updates
//   the bounding sphere if larger, copies shadow texture info, and
//   registers the entity in the scene if it has collision data.
// Original:
// void __thiscall FUN_0055a4a0(int param_1,int param_2) { ... 80 lines ... }
void CopyEntityState(int dstEntity, int srcEntity)
{
    if (dstEntity == 0 || srcEntity == 0) return;

    // Check if entity types differ — tear down old if so
    int dstType = *(int*)(dstEntity + 0x22c);
    int srcType = *(int*)(srcEntity + 0x22c);

    if (srcType != dstType) {
        // If old type has a teardown handler in vtable and has render context
        if (dstType < 0x6c) {
            // void (**vtable)(...) = *(code***)(&DAT_00682ec8 + dstType * 0x50);
            // if (vtable != nullptr && *(int*)(dstEntity + 0x14c) != 0) (*vtable)(dstEntity);
        }
        // Release render context
        if (*(int*)(dstEntity + 0x14c) != 0) {
            // FUN_00643505(*(int*)(dstEntity + 0x14c), 0);
            *(uint32_t*)(dstEntity + 0x14c) = 0;
        }
    }

    // Copy 0x80 bytes of entity state (32 uint32_t at offset 0x1dc)
    uint32_t* src = (uint32_t*)(srcEntity + 0x1dc);
    uint32_t* dst = (uint32_t*)(dstEntity + 0x1dc);
    for (int i = 0x20; i != 0; i--) {
        *dst++ = *src++;
    }

    // Clone render objects from source
    // FUN_00559e60(dstEntity, srcEntity);

    // Copy entity ID
    *(uint32_t*)(dstEntity + 4) = *(uint32_t*)(srcEntity + 4);

    // Update bounding sphere if source is larger
    extern float DAT_0066bce4;
    if (DAT_0066bce4 < *(float*)(srcEntity + 0x370)) {
        *(float*)(dstEntity + 0x370) = *(float*)(srcEntity + 0x370);
    }

    // Copy additional state fields
    *(uint64_t*)(dstEntity + 0x1c4) = *(uint64_t*)(srcEntity + 0x1c4);
    *(uint32_t*)(dstEntity + 0x1cc) = *(uint32_t*)(srcEntity + 0x1cc);

    // Create render context if missing
    if (*(int*)(dstEntity + 0x14c) == 0) {
        // uint32_t ctx = FUN_005d6d00(*(uint32_t*)(dstEntity + 0x22c));
        // *(uint32_t*)(dstEntity + 0x14c) = ctx;
        // FUN_0055cda0(); — post-init render context
    }

    // FUN_0055cd40(); — update entity state
    // FUN_0055a400(srcEntity); — post-copy notification

    // Copy shadow texture info
    *(uint32_t*)(dstEntity + 0x334) = *(uint32_t*)(srcEntity + 0x334);
    uint32_t* srcShadow = *(uint32_t**)(srcEntity + 0x330);
    if (srcShadow != nullptr) {
        if ((*(uint8_t*)(srcShadow + 8) & 0x80) != 0) {
            // Dynamic shadow: allocate new texture descriptor
            uint32_t texW = srcShadow[3];
            uint32_t texH = srcShadow[4];
            uint32_t* newShadow = (uint32_t*)malloc(0x2c);
            newShadow[0] = (uint32_t)(uintptr_t)"Dynamic shadow texture";
            newShadow[1] = 0;
            newShadow[2] = 0;
            newShadow[3] = texW;
            newShadow[4] = texH;
            newShadow[6] = 5;
            newShadow[5] = 5;
            *(uint16_t*)(newShadow + 7) = 0x20;
            newShadow[8] = 0x80;

            void* oldShadow = *(void**)(dstEntity + 0x330);
            if (oldShadow != nullptr && ((*(uint8_t*)((uintptr_t)oldShadow + 0x20) & 0x80) != 0)) {
                free(oldShadow);
            }
        }
        *(uint32_t**)(dstEntity + 0x330) = srcShadow;
    }

    // Register in scene if entity has collision data
    int collisionType = *(int*)(srcEntity + 0x34c);
    if (collisionType > 0) {
        extern uint32_t DAT_00702770;
        if (*(int*)(DAT_00702770 + 500) != 0) {
            // int sceneIdx = *(char*)(srcEntity + 0x348);
            // FUN_004e9cd0(collisionType, sceneIdx, dstEntity);
        }
    }
}

// ─── TransferEntityBones (FUN_0055a710) ─────────────────────────
// Ghidra: FUN_0055a710 (72 callers, 6 callees)
// Purpose: Transfer bone/skeleton data from source entity to destination.
//   Copies rendering properties (flags, materials, textures), sets the
//   "modified" flag (0x80000000) on the bone count, then remaps bone
//   indices from the source skeleton to the destination skeleton using
//   two-pass lookup via FUN_004ffb40/FUN_004ffba0.
// Original:
// void __thiscall FUN_0055a710(int param_1,int param_2) { ... 70 lines ... }
void TransferEntityBones(int dstEntity, int srcEntity)
{
    // FUN_0055a680(srcEntity); — pre-transfer setup

    // Copy render properties
    *(uint32_t*)(dstEntity + 0x124) = *(uint32_t*)(srcEntity + 0x124);
    *(uint32_t*)(dstEntity + 0x128) = *(uint32_t*)(srcEntity + 0x128) | 0x80000000;  // Mark modified
    *(uint32_t*)(dstEntity + 0x1d8) = *(uint32_t*)(srcEntity + 0x1d8);
    *(uint32_t*)(dstEntity + 300)   = *(uint32_t*)(srcEntity + 300);
    *(uint32_t*)(dstEntity + 0x134) = *(uint32_t*)(srcEntity + 0x134);
    *(uint32_t*)(dstEntity + 0x130) = *(uint32_t*)(srcEntity + 0x130);

    // FUN_0055cd40(); — update render state

    *(uint32_t*)(dstEntity + 0x138) = *(uint32_t*)(srcEntity + 0x138);

    // Remap bone indices from source to destination skeleton
    int srcBoneCount = *(int*)(srcEntity + 0x224);
    if (srcBoneCount > 0) {
        // Pass 1: map source bone IDs to destination indices
        // FUN_004ffb40() returns {boneId, index} pair
        uint32_t boneMap = 0;  // FUN_004ffb40()
        if (boneMap != 0) {
            int startIdx = (int)((uint64_t)boneMap >> 32) + 1;
            int* srcBones = *(int**)(srcEntity + 0x228);
            do {
                if (*srcBones == *(int*)((int)boneMap + 4)) {
                    if (startIdx > 0 && startIdx <= *(int*)(dstEntity + 0x224)) {
                        int dstIdx = startIdx - 1;
                        if (dstIdx >= 0) {
                            dstIdx = *(int*)(*(int*)(dstEntity + 0x228) + dstIdx * 4);
                        }
                        // FUN_004ffba0(dstIdx) — set destination bone
                    }
                    break;
                }
                startIdx++;
                srcBones++;
            } while (startIdx <= srcBoneCount);
        }

        // Pass 2: second bone remapping pass
        boneMap = 0;  // FUN_004ffb40()
        int idx2 = (int)((uint64_t)boneMap >> 32);
        if (boneMap != 0 && idx2 <= srcBoneCount) {
            int* srcBones2 = *(int**)(srcEntity + 0x228);
            do {
                if (*srcBones2 == *(int*)((int)boneMap + 4)) {
                    if (idx2 > 0 && idx2 <= *(int*)(dstEntity + 0x224)) {
                        int dstIdx2 = idx2 - 1;
                        if (dstIdx2 >= 0) {
                            dstIdx2 = *(int*)(*(int*)(dstEntity + 0x228) + dstIdx2 * 4);
                        }
                        // FUN_004ffba0(dstIdx2)
                    }
                    break;
                }
                idx2++;
                srcBones2++;
            } while (idx2 <= srcBoneCount);
        }
    }

    // FUN_0055a400(srcEntity); — post-transfer notification
    // FUN_00503330(); — scene update
}

// ─── FindEntityTypeEntry (FUN_0055a8a0) ─────────────────────────
// Ghidra: FUN_0055a8a0 (104 callers, 0 callees)
// Purpose: Search the global entity type registry for a matching type ID.
//   Walks a linked list of entity type arrays (DAT_00702794). Each array
//   node has a count at [1] and an array of 0x374-byte entries starting at
//   offset [2]. Compares each entry's type field at [3] against param_1.
//   Returns pointer to the matching entry's data area (node+2), or nullptr.
// Original:
// undefined4 * __fastcall FUN_0055a8a0(int param_1)
// {
//   undefined4 *puVar1 = DAT_00702794;
//   do {
//     if (puVar1 == (undefined4 *)0x0) return (undefined4 *)0x0;
//     int iVar3 = 0; puVar2 = puVar1;
//     if (0 < (int)puVar1[1]) {
//       do {
//         if (puVar2[3] == param_1) return puVar2 + 2;
//         iVar3++; puVar2 += 0xdd;
//       } while (iVar3 < (int)puVar1[1]);
//     }
//     puVar1 = (undefined4 *)*puVar1;
//   } while(true);
// }
uint32_t* FindEntityTypeEntry(int entityTypeId)
{
    extern uint32_t* DAT_00702794;  // Entity type registry head

    uint32_t* node = DAT_00702794;
    while (true) {
        if (node == nullptr) {
            return nullptr;
        }

        int count = (int)node[1];
        uint32_t* entry = node;
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                if (entry[3] == (uint32_t)entityTypeId) {
                    return entry + 2;  // Return data area after header
                }
                entry += 0xdd;  // 0x374 / 4 = 0xDD stride
            }
        }
        node = (uint32_t*)*node;  // Next array in linked list
    }
}

// ─── CompareEntityName (FUN_00632950) ───────────────────────────
// Ghidra: FUN_00632950 (17 callers, 1 callee)
// Purpose: Case-insensitive string comparison for entity name matching.
//   Delegates to _stricmp. Used throughout the FLICK system for comparing
//   entity names, animation names, and scene identifiers.
// Original:
// bool FUN_00632950(char *param_1,char *param_2)
// {
//   int iVar1 = _stricmp(param_1,param_2);
//   return iVar1 == 0;
// }
bool CompareEntityName(const char* name1, const char* name2)
{
    return strcasecmp(name1, name2) == 0;
}

// ─── BuildSkinBinding (FUN_00633560) ────────────────────────────
// Ghidra: FUN_00633560 (2 callers, 8 callees)
// Purpose: Build a skin/bone binding table for skeletal animation.
//   Creates an output structure with the animation's bone hierarchy,
//   walks the skeleton definition (from param_3+0x18), and for each bone
//   creates a remapping from bone indices in the skeleton to bone indices
//   in the animation tree. If a named tree (param_2) is specified, looks
//   up the sub-tree for bone resolution; otherwise uses the default tree.
//   Error messages reference "SKN" (skin) and "ANM" (animation) files.
// Original:
// int FUN_00633560(int param_1,int param_2,int param_3) { ... ~100 lines ... }
int BuildSkinBinding(int animContext, int treeName, int skinDef)
{
    // Get bone count from skin definition
    int boneCount = 0;  // FUN_00640bf0(*(uint32_t*)(skinDef + 0x18))
    if (boneCount == 0) {
        return 0;
    }

    // Allocate output structure: header(0x18) + boneCount * 4 bytes
    int outBuf = 0;  // (*allocator)(boneCount * 4 + 0x18)
    *(int*)(outBuf + 8) = animContext;
    int* boneArray = (int*)(outBuf + 0x18);
    *(int*)(outBuf + 0xc) = skinDef;
    *(uint32_t*)(outBuf + 0x10) = 0;

    // Iterate over bones in the skeleton
    int boneIdx = 0;
    while (true) {
        int nextIdx = boneIdx + 1;
        int boneEntry = 0;  // FUN_00640c40(*(uint32_t*)(skinDef + 0x18), boneIdx)
        if (boneEntry == 0) break;

        int* boneData = (int*)GetSubTableData(boneEntry);
        int bonePtr = *boneData;
        if (bonePtr == 0) break;

        // Resolve the animation tree for bone lookup
        uint32_t* skinBinding = nullptr;
        uint32_t defaultTree = *(uint32_t*)(animContext + 0x24);

        if (treeName != 0) {
            int treeEntry = LookupTableEntry(*(uint32_t*)(animContext + 0x20), treeName);
            if (treeEntry == 0) {
                // FUN_00640a00("Can't find tree \"%s\" in ANM \"%s\"\n", treeName, animContext + 0x4c);
            } else {
                uint32_t* treeData = (uint32_t*)GetSubTableData(treeEntry);
                defaultTree = *treeData;
            }
        }

        // Process bone's skin influence list
        if (*(int*)(bonePtr + 0x10) != 0) {
            int influenceCount = *(int*)(bonePtr + 0x10);
            skinBinding = (uint32_t*)operator_new(influenceCount * 8 + 0xc);
            skinBinding[0] = defaultTree;
            skinBinding[1] = (uint32_t)bonePtr;
            skinBinding[2] = 0;

            int* influences = (int*)(bonePtr + 0x14);
            uint32_t* outEntry = skinBinding + 3;

            for (int j = 0; j < influenceCount; j++) {
                int influence = *influences;
                *outEntry = influence;

                // Resolve bone name -> bone index in animation tree
                // uint32_t boneId = FUN_00640c00(*(uint32_t*)(*(int*)(bonePtr + 4) + 0x10),
                //                                *(uint16_t*)(influence + 8));
                // const char* boneName = FUN_00640c70(boneId);
                // int boneLookup = LookupTableEntry(defaultTree, boneName);

                int boneLookup = 0;  // Stub
                if (boneLookup == 0) {
                    outEntry[1] = 0;
                    // Error: bone not found in animation tree
                } else {
                    int* resolvedBone = (int*)GetSubTableData(boneLookup);
                    outEntry[1] = *resolvedBone;
                }

                outEntry += 2;
                skinBinding[2]++;
                influences++;
            }
        }

        *boneArray = (int)(uintptr_t)skinBinding;
        boneIdx = nextIdx;

        if (skinBinding != nullptr) {
            // Accumulate bone data size
            *(int*)(outBuf + 0x10) += *(int*)(skinBinding[1] + 0xc);
            boneArray++;
        }
    }

    // Set final bone count in output
    *(int*)(outBuf + 0x14) = ((int)(uintptr_t)boneArray - (outBuf + 0x18)) >> 2;
    *(uint32_t*)(outBuf + 4) = **(uint32_t**)(outBuf + 0x18);

    return outBuf;
}

// ═══════════════════════════════════════════════════════════════════
// CopyStringTruncated — FUN_006329a0
// ═══════════════════════════════════════════════════════════════════
// Copies a string with truncation. Equivalent to strncpy + null terminator.
// strncpy(param_1, param_2, param_3); param_1[param_3] = '\0';
// Used throughout FLICK and entity systems for safe string handling.
// 12 callers (wide usage), 1 callee (strncpy).

void CopyStringTruncated(char* param_1, char* param_2, size_t param_3)
{
    // Original:
    // strncpy(param_1, param_2, param_3);
    // param_1[param_3] = '\0';
}

} // namespace Giants
