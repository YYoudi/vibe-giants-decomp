// Giants Vanilla-Native Recomp — Entity child-initializer + spawn helpers.
//
// Faithful port of Giants.exe!FUN_0045fde0 (vanilla 1.0 retail, base 0x400000),
// confirmed by capstone disassembly of G:\GiantsRE\GameFiles-VanillaV1\Giants.exe.
// Instruction addresses cited inline as [0x......]. See VanillaObject.h for the
// architectural correction (this is NOT the vtable installer) and
// RE_docs/OBJECT_CREATE_CHILD.md for the full reference doc.
#include "VanillaObject.h"
#include "VanillaSceneTypes.h"
#include "VanillaEngine.h"

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cstdlib>

extern "C" FILE* g_vTrace;   // defined in WinMain_vanilla.cpp

namespace {

// ============================================================================
// Vanilla .data globals read by FUN_0045fde0 (zero-init in the recomp).
// ============================================================================
// DAT_0059ca80 — one-time level-stat init gate. [0x45fe0c] reads it; when 0
//   the function runs the init loop over the level-stat table (DAT_0055c604)
//   then sets it to 1 at [0x45fe84].
uint32_t g_StatInitGate_59ca80 = 0;   // BSS in vanilla (zero at start)

// DAT_0055c604 — per-level class-stat table. Stride 0x1c, terminated by a
//   record whose [+0x10] == 0xfe (sentinel). Each record {kind, group, ?, ?,
//   class_id@+0x10, statA@+0x14, statB@+0x18}. The init loop applies stats to
//   the entity via FUN_00403800. We carry the table address for fidelity but
//   the apply callee is not yet ported (logged).
//   In vanilla this is a baked .data table; in the recomp we reference it by
//   its VA so the doc/integration layer can find it, but keep a null stub.
constexpr uint32_t VANILLA_STAT_TABLE_VA = 0x55c604;   // [0x45fe16] push 0x460330; call FUN_004f31e0 (log)

// DAT_00631530 — current-level id selector. [0x46022c] reads it and writes
//   entity->uselist ([esi+0x120]) when it differs.
uint32_t g_CurrentLevel_631530 = 0;
// DAT_00631538 — pointer to the active level-config struct (floats at +0x5f8,
//   +0x604, +0x608, +0x6b4, +0x6b8 read at [0x46027a..0x4602d3]).
uint32_t g_LevelConfig_631538 = 0;
// DAT_00631578 — frame counter read at [0x460128] and passed to FUN_00526ad0.
uint32_t g_FrameCounter_631578 = 0;

// ============================================================================
// Stub vtable for SpawnTestEntity. Slot [0x30/4 = 8] is Render (OBJECT::Render),
// the target the renderer dispatches via (node-0x34)->vtable[0x30]. We size the
// table to cover the slots the scene walk reads (0x00..0x30) and fill every
// entry with a logging no-op so any stray dispatch is observable, not a crash.
// ============================================================================
constexpr uint32_t VTAB_SLOTS = 0x34 / 4 + 1;   // cover slots 0..0x30 (13 entries)

extern "C" void __cdecl EntityVtable_StubRender(EntityObject* self);

void __cdecl EntityVtable_StubRender(EntityObject* self) {
    // OBJECT::Render stub. The real per-class Render reads the model data
    // (GBS/SKN/ANM) the entity's typeId resolves to and issues D3D7 draw
    // calls via the renderer vtable. Until that pipeline is ported we log so
    // the dispatch walk is observable.
    if (g_vTrace) {
        fprintf(g_vTrace,
                "[OBJ/Render stub] entity=%p kind=%u variant=%u flags_e4=%u "
                "(typeId→class→model not yet resolved; real draw path TBD)\n",
                (void*)self, self->kind, self->variant, self->flags_e4);
        fflush(g_vTrace);
    }
}

// Build a fresh stub vtable (per entity, so future per-class tables can replace
// entries without aliasing). All slots → the logging Render stub.
void** MakeStubVtable() {
    void** vtbl = (void**)std::malloc(sizeof(void*) * VTAB_SLOTS);
    if (!vtbl) return nullptr;
    for (uint32_t i = 0; i < VTAB_SLOTS; ++i) {
        vtbl[i] = (void*)&EntityVtable_StubRender;
    }
    return vtbl;
}

// ============================================================================
// Child sub-object stubs. FUN_0045fde0 spawns (per entity):
//   * light-pair at fx_light (entity+0x100): two children via FUN_0049c190
//     named fx_buoy_red_light / fx_buoy_green_light ([0x45ff78]/[0x45ffdd]).
//   * 8 attachment slots at entity+0x22c, stride 0x1c (loop [0x460063..0x4600d3]).
//   * 1 special slot at entity+0x314 ([0x460122]).
// Each child in vanilla is a sub-EntityObject allocated via the engine
// allocator (FUN_0049c6b0/FUN_0049f3b0). We allocate matching storage so the
// entity layout the renderer expects is present, and zero-init it.
// ============================================================================
constexpr uint32_t LIGHT_CHILD_SIZE   = 0x2ed;   // [0x45ff0f] push 0x2ed (alloc size)
constexpr uint32_t ATTACH_CHILD_SIZE  = 0x362;   // [0x46006e] push 0x362 (alloc size)
constexpr uint32_t SPECIAL_CHILD_SIZE = 0x3d4;   // [0x4600d6] push 0x3d4 (alloc size)
constexpr uint32_t ATTACH_SLOT_COUNT  = 8;       // [0x46004d] mov [esp+0x10],8 ; loop count
constexpr uint32_t ATTACH_SLOT_STRIDE = 0x1c;    // [0x4600c3] add eax,0x1c (next slot)

} // namespace

// ============================================================================
// FUN_0045fde0 — entity one-shot child/attachment initializer (faithful port).
// ============================================================================
extern "C" uint32_t FUN_0045fde0(void* entityOpaque) {
    EntityObject* ebp = (EntityObject*)entityOpaque;
    if (!ebp) return 0;

    // [0x45fdea..0x45fdf8] read [ebp+0xe8] (kind); if != 0 → already init'd.
    //   [0x45fdfa] push 0xf; push ebp; call FUN_0049f3b0; return 0.
    // FUN_0049f3b0 is an event-dispatch helper (opcode 0xf). Not ported; we
    // honor the early-out semantic so the function is idempotent like vanilla.
    if (ebp->kind != 0) {
        if (g_vTrace) {
            fprintf(g_vTrace, "[OBJ/0x45fde0] entity %p kind=%u !=0 — already init'd, early-out\n",
                    (void*)ebp, ebp->kind);
            fflush(g_vTrace);
        }
        return 0;
    }

    void* esi = ebp->fx_light;   // [0x45fdf0] esi = [ebp+0x100]

    // [0x45fe0c..0x45fe84] one-time level-stat table init gate.
    // Vanilla reads DAT_0059ca80; if 0 it iterates the stat table at
    // DAT_0055c604 (stride 0x1c, term [rec+0x10]==0xfe) applying per-class
    // stats via FUN_00403800, then sets the gate. We mirror the gate so the
    // init runs exactly once; the apply callee is logged-only for now.
    if (g_StatInitGate_59ca80 == 0) {
        if (g_vTrace) {
            fprintf(g_vTrace,
                    "[OBJ/0x45fde0] stat-table init @ VA 0x%x (apply callee FUN_00403800 not ported; logged)\n",
                    VANILLA_STAT_TABLE_VA);
            fflush(g_vTrace);
        }
        // [0x45fe84] mov [0x59ca80],1
        g_StatInitGate_59ca80 = 1;
    }

    // [0x45fe8e..0x45fe95] gate on [esi] bit 0 (~[esi] & 1). If the fx_light
    //   child is already flagged initialized, skip the child spawn block.
    uint32_t esiFlags = esi ? *(uint32_t*)esi : 0;
    if ((~esiFlags & 1u) == 0) {
        // Already flagged → jump to 0x46022c (uselist section). We skip the
        // child-spawn block just like vanilla.
        if (g_vTrace) {
            fprintf(g_vTrace, "[OBJ/0x45fde0] entity %p fx_light already flagged — skip child spawn\n",
                    (void*)ebp);
            fflush(g_vTrace);
        }
    }
    else if (esi) {
        // --- Child spawn block [0x45fe9b..0x46022a] ---
        // [0x45fe9e..0x45fea4] FUN_0049d2d0([ebp+4]) → entity name hash → [esi+0x154].
        //   ebp+4 is the entity's name-string slot. We log; the hash callee
        //   is not ported.
        if (g_vTrace) { fprintf(g_vTrace, "[OBJ/0x45fde0] spawning children for entity %p\n", (void*)ebp); fflush(g_vTrace); }

        // [0x45feaa..0x45fed9] zero-init a batch of fx_light fields and set
        //   constants: [esi+0x7c]=[esi+0x78]=-1.0 (0xbf800000), [esi+0x90/0x98/
        //   0x9c]=-1, [esi+0x84]=0xfe, [esi+0xd8]=3, [esi+0xd4]=[esi+0xcc]=0,
        //   [esi+0xc8]=[esi+0xd4]=1.0 (0x3f800000), etc.
        *(float*)((uint8_t*)esi + 0x7c) = -1.0f;  // [0x45feaf]
        *(float*)((uint8_t*)esi + 0x78) = -1.0f;  // [0x45feb2]
        *(uint32_t*)((uint8_t*)esi + 0x90) = 0xffffffffu; // [0x45feb8] (-1)
        *(uint32_t*)((uint8_t*)esi + 0x98) = 0xffffffffu; // [0x45fec1]
        *(uint32_t*)((uint8_t*)esi + 0x9c) = 0xffffffffu; // [0x45fec7]
        *(uint32_t*)((uint8_t*)esi + 0x84) = 0xfeu;       // [0x45fecf]
        *(float*)((uint8_t*)esi + 0xd4) = 1.0f;           // [0x45ff36]
        *(float*)((uint8_t*)esi + 0xcc) = 1.0f;           // [0x45ff3c]
        *(uint32_t*)((uint8_t*)esi + 0xd8) = 3u;          // [0x45ff14]
        *(float*)((uint8_t*)esi + 0x128) = 1.0f;          // [0x45ff54]
        *(float*)((uint8_t*)esi + 0x134) = 1.0f;          // [0x45ff5a]

        // [0x45ff0d..0x45ff78] allocate the light-pair first child via
        //   FUN_0049c190(1, 0x2ed) → red light. Its fields are configured at
        //   [0x45ff83..0x460003] (flags @0xd8, 0xdc, 0x1c8; back-ptr @0x210;
        //   owner @0x18c=[ebp+0x18c]).
        void* redLight = std::calloc(1, LIGHT_CHILD_SIZE);
        if (redLight) {
            *(uint32_t*)((uint8_t*)redLight + 0x210) = (uint32_t)(uintptr_t)ebp; // [0x45ff89]
            *(uint32_t*)((uint8_t*)redLight + 0x218) = 0xa;                      // [0x45ff95]
            *(uint32_t*)((uint8_t*)redLight + 0x1c8) |= 0x24000000u;            // [0x45ffa5]
            *(uint32_t*)((uint8_t*)redLight + 0xd8)  |= 0x400000u;              // [0x45ffc2]
            *(uint32_t*)((uint8_t*)redLight + 0x1c8) |= 0x20000000u;            // [0x46003d]
            *(uint32_t*)((uint8_t*)redLight + 0xdc)  |= 0x2000000u;             // [0x46005b]
            // FUN_0049c190 returns its result in eax; vanilla stores eax into
            // [esp+0x14] then re-reads. We keep the child on the fx_light
            // sub-struct's first slot (esi+0x150 per [0x45ffe2]).
            *(void**)((uint8_t*)esi + 0x150) = redLight;                         // [0x45ffe2]
            if (g_vTrace) { fprintf(g_vTrace, "[OBJ/0x45fde0]   + fx_buoy_red_light child=%p\n", redLight); fflush(g_vTrace); }
        }

        // [0x460063..0x4600d3] 8 attachment slots at entity+0x22c, stride 0x1c.
        //   Each slot allocated via FUN_0049c6b0(0x362) then init'd via
        //   FUN_0049f3b0 + FUN_0053fc40 (config). The loop writes the slot
        //   pointer into a trailing array ([esp+0x2c] base, +0x1c per iter).
        // We allocate the slots and place them at entity+0x22c+i*0x1c so the
        // layout the renderer/destructor (FUN_00460440) walks is present.
        for (uint32_t i = 0; i < ATTACH_SLOT_COUNT; ++i) {
            void* slot = std::calloc(1, ATTACH_CHILD_SIZE);
            if (!slot) continue;
            // [0x4600a8/0x46010d] flags @0xd8 |= 0x40010000, @0x1c8 |= 0x0e<<8.
            *(uint32_t*)((uint8_t*)slot + 0xd8)  |= 0x40010000u;
            *(uint32_t*)((uint8_t*)slot + 0x1c8) |= (0x0eu << 8);
            *(void**)((uint8_t*)ebp + 0x22c + i * ATTACH_SLOT_STRIDE) = slot;
        }
        if (g_vTrace) { fprintf(g_vTrace, "[OBJ/0x45fde0]   + %u attachment slots @ entity+0x22c\n", ATTACH_SLOT_COUNT); fflush(g_vTrace); }

        // [0x4600d5..0x460122] special slot at entity+0x314 via FUN_0049c6b0(0x3d4).
        void* special = std::calloc(1, SPECIAL_CHILD_SIZE);
        if (special) {
            *(uint32_t*)((uint8_t*)special + 0xd8)  |= 0x40010000u;  // [0x4600fb]
            *(uint32_t*)((uint8_t*)special + 0x1c8) |= (0x0eu << 8); // [0x46010d]
            *(void**)((uint8_t*)ebp + 0x314) = special;              // [0x460122]
            if (g_vTrace) { fprintf(g_vTrace, "[OBJ/0x45fde0]   + special slot @ entity+0x314 =%p\n", special); fflush(g_vTrace); }
        }

        // [0x460128] frame-counter tick: eax=[0x631578]; call FUN_00526ad0.
        g_FrameCounter_631578++;

        // [0x46021d..0x46022a] gravity: [esi+0x220] = FUN_00469a30(entity,0x20,2,4.0).
        //   FUN_00469a30 is a physics-field setter; the 4.0 (0x40800000) is the
        //   gravity magnitude. Vanilla stores the result handle at [esi+0x220].
        *(float*)((uint8_t*)esi + 0x220) = 4.0f;   // [0x46020e] push 0x40800000

        // [0x460223..0x46022a] set the "children spawned" latch: [esi] |= 1.
        *(uint32_t*)esi |= 1u;
    }

    // --- Uselist / level-config block [0x46022c..0x460319] ---
    // [0x46022c] eax = [0x631530] (current level); if [esi+0x120] != eax,
    //   store it and apply the level-config floats from DAT_00631538.
    if (esi) {
        uint32_t curLevel = g_CurrentLevel_631530;            // [0x46022c]
        if (*(uint32_t*)((uint8_t*)esi + 0x120) != curLevel) {
            *(uint32_t*)((uint8_t*)esi + 0x120) = curLevel;   // [0x46023f]

            // [0x460245..0x46024d] first-time uselist allocation at entity+0x104
            //   (zero 0xf dwords, then call FUN_004a73b0). We allocate the
            //   uselist block lazily so the field is non-NULL.
            if (ebp->pair_ref == nullptr) {                   // (abusing pair_ref@0x274 as a scratch flag is NOT vanilla;
                //  the real check is [ebp+0x104]==0 at [0x46024b]. We mirror that.)
            }
            void** useListPtr = (void**)((uint8_t*)ebp + 0x104);
            if (*useListPtr == nullptr) {
                // [0x46024f] lea edi,[esi+0xe4]; rep stosd (0xf dwords = 0x3c bytes)
                void* ul = std::calloc(0x3c, 1);
                *useListPtr = ul;                             // [0x46025c] mov [ebp+0x104],edi
            }

            // [0x46026d..0x4602d3] apply level-config floats (g_LevelConfig_631538
            //   in vanilla points to the active level descriptor). In the recomp
            //   that struct is not yet populated → we skip the float copies but
            //   keep the field zero-init done above.
            if (g_LevelConfig_631538 != 0 && g_vTrace) {
                fprintf(g_vTrace, "[OBJ/0x45fde0] apply level-config @ 0x%x (floats +0x5f8/+0x604/+0x608/+0x6b4/+0x6b8)\n",
                        g_LevelConfig_631538);
                fflush(g_vTrace);
            }

            // [0x4602ee..0x4602f3] set the uselist "configured" flag bit: [useList]+0 dh|=4.
            // [0x460307..0x460313] compute [esi+0x14c] = (useList[+4]/useList[+8]) * -32.174.
            //   (-32.174 = gravity ft/s^2, const @ 0x55251c.) Requires valid
            //   uselist floats; skipped when config absent.

            // [0x460319] call FUN_0045eed0(ebp) — entity post-init hook.
            //   Not ported; logged.
            if (g_vTrace) { fprintf(g_vTrace, "[OBJ/0x45fde0] entity %p post-init (FUN_0045eed0 not ported)\n", (void*)ebp); fflush(g_vTrace); }
        }
    }

    // [0x460324] mov eax,1; ret. Success.
    return 1;
}

// ============================================================================
// SpawnTestEntity — recomp-only helper. Allocates an EntityObject, installs a
// stub vtable, head-inserts into g_PlacedObjectList, runs FUN_0045fde0.
// ============================================================================
extern "C" void* SpawnTestEntity(uint32_t typeId, float x, float y, float z) {
    // Allocate the EntityObject zero-init. (Size: we cover the largest field
    // offset the renderer/destructor touches, +0x314 special slot + its alloc.)
    constexpr uint32_t ENTITY_ALLOC_SIZE = 0x320;   // covers all confirmed fields
    EntityObject* entity = (EntityObject*)std::calloc(1, ENTITY_ALLOC_SIZE);
    if (!entity) return nullptr;

    // Install the stub vtable so the dispatch walk (renderer method 0x2d80,
    // (node-0x34)->vtable[0x30]) sees a non-NULL [entity+0x00] and a callable
    // Render at slot [0x30/4].
    void** vtbl = MakeStubVtable();
    if (!vtbl) { std::free(entity); return nullptr; }
    entity->vftable = vtbl;

    // Seed the fields the dispatch + child-init read.
    entity->kind      = typeId;   // [ebp+0xe8] — selectors the lookup (FUN_0040bfd0)
    entity->variant   = 0;        // [ebp+0x174]
    entity->flags_e4  = 3;        // [ebp+0xe4] — placed/active (matches buoy attach)
    // Position: the EntityObject placement fields are within the pad_link region
    // (the .BIN ObjectRef6 x/y/z land in the osl record, not directly here); we
    // stash x/y/z into a known offset the renderer reads for the matrix build.
    // Offset +0xa0 is the transform slot group (see FUN_0050afb0 [0x50b0b6]
    // lea eax,[esi+0xa0]; the placement handler copies ObjectRef6 there).
    *(float*)((uint8_t*)entity + 0xa0 + 0x00) = x;
    *(float*)((uint8_t*)entity + 0xa0 + 0x04) = y;
    *(float*)((uint8_t*)entity + 0xa0 + 0x08) = z;

    // Set kind=0 so FUN_0045fde0 runs the full child-spawn path (it early-outs
    // on kind!=0). We restore the real typeId AFTER, so lookups match.
    entity->kind = 0;

    // fx_light sub-struct (entity+0x100) must be non-NULL for the child spawn.
    // Allocate a zero-init block the child spawn writes into.
    entity->fx_light = std::calloc(1, 0x160);   // covers fields up to +0x154/+0x158
    if (!entity->fx_light) {
        std::free(vtbl); std::free(entity); return nullptr;
    }

    // Run the child initializer (faithful port).
    FUN_0045fde0(entity);

    // Restore the typeId so the dispatch can classify the entity.
    entity->kind = typeId;

    // ── Head-insert into g_PlacedObjectList (DAT_006313c8) ──
    // The walker (SceneWalk_PlacedObjects / FUN_0050e540) expects:
    //   outer node:  +0x00 next, +0x0c → inner-list header
    //   inner header: +0x08 = entity-ptr count, +0x400..+0x424 = entity ptrs (10 slots)
    // We build that two-level structure for the one test entity.
    struct InnerHolder { uint32_t pad[2]; uint32_t count; uint8_t  slots[0x430]; };
    struct OuterNode  { OuterNode* next; uint32_t pad[2]; InnerHolder* inner; };
    OuterNode* outer = (OuterNode*)std::calloc(1, sizeof(OuterNode));
    InnerHolder* inner = (InnerHolder*)std::calloc(1, sizeof(InnerHolder));
    if (!outer || !inner) {
        std::free(outer); std::free(inner);
        std::free(entity->fx_light); std::free(vtbl); std::free(entity);
        return nullptr;
    }
    inner->count = 1;                                       // [inner+0x08]
    *(void**)(inner->slots + (0x400 - 0x0c)) = entity;      // entity ptr @ +0x400
    outer->inner = inner;
    // Head-insert: outer->next = current head; g_PlacedObjectList = outer.
    outer->next = (OuterNode*)(uintptr_t)g_PlacedObjectList; // [0x4b5130..] head-insert
    g_PlacedObjectList = (uint32_t)(uintptr_t)outer;

    if (g_vTrace) {
        fprintf(g_vTrace,
                "[OBJ/Spawn] entity=%p typeId=%u pos=(%.1f,%.1f,%.1f) vtable=%p "
                "Render[slot8]=%p — inserted into g_PlacedObjectList (outer=%p inner=%p)\n",
                (void*)entity, typeId, x, y, z, (void*)vtbl, (void*)&EntityVtable_StubRender,
                (void*)outer, (void*)inner);
        fflush(g_vTrace);
    }
    return entity;
}
