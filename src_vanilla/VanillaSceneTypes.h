// Giants Vanilla-Native Recomp — Scene/Entity list data structures.
//
// Field offsets are CONFIRMED by capstone disassembly of vanilla Giants.exe
// (G:\GiantsRE\GameFiles-VanillaV1\Giants.exe, base 0x400000). Evidence
// addresses are cited inline as [0x......] pointing at the instruction that
// proves the offset. See RE_docs/SCENE_SYSTEM.md for the cross-reference map.
//
// These structs back three engine globals (declared in VanillaEngine.h):
//   g_TextureEntityList  (DAT_005a78b4) — texture/entity list head
//   g_PlacedObjectList   (DAT_006313c8) — placed-object/entity list head
//   g_LevelTable         (DAT_00631388) — level descriptor table
#pragma once
#include <cstdint>

extern "C" {

// ============================================================================
// 1. Texture/entity list node  (head: DAT_005a78b4, insert = FUN_0050d8f0)
// ============================================================================
// Allocation size is variable: 0x2c header + sub_count * 0x24 entries.
// Confirmed by FUN_0050d8f0 disasm:
//   [0x50d99b] lea eax,[eax+eax*8]      ; eax = sub_count*9
//   [0x50d9ad] lea edi,[ebp+eax*4+0x2c] ; alloc size = sub_count*9*4 + 0x2c = sub_count*0x24 + 0x2c
//   [0x50d9da] mov [ebp+0],<old head>   ; next @ +0x00 (head insertion)
//   [0x50d9e1] mov [0x5a78b4],ebp       ; g_TextureEntityList = new node
//   [0x50d9f7] mov [ebp+0x24],ecx       ; data_size @ +0x24
//   [0x50d9fe] mov [ebp+0x28],edx       ; sub_count @ +0x28
//   [0x50da0d] lea ebx,[ebp+eax*4+0x2c] ; entries base @ +0x2c
struct TextureListNode {
    TextureListNode* next;          // +0x00  — [0x50d9da] head-insert link
    char             name[0x20];    // +0x04  — [0x50d9e7] strcpy(name@+4, param)
    uint32_t         data_size;     // +0x24  — [0x50d9f7] = FUN_0051d7f0(stream) (stream size)
    uint32_t         sub_count;     // +0x28  — [0x50d9fe] = count read from stream
    // entries[sub_count] follow at +0x2c, stride 0x24 (9 dwords each).
};

// Per-sub-entry stride = 0x24 (9 dwords). Confirmed by the entry-fill loop:
//   [0x50da0d] lea ebx,[ebp+eax*4+0x2c]  ; ebx = entries[0] base
//   [0x50daa0] add ebp,0x24              ; advance to next entry each iteration
struct TextureEntry {
    uint8_t  byte0;                 // +0x00 — [0x50da49] mov [ebp+0x20],al  (read byte 1)
    uint8_t  byte1;                 // +0x01 — [0x50da5d] mov [ebp+0x23],dl  (read byte 2)
    uint8_t  pad[0x18];             // +0x02..0x19
    uint8_t  state;                 // +0x1a — (~state & 1) ⇒ unloaded (FUN_0050daf0)
    uint8_t  pad2[1];               // +0x1b
    uint32_t fixed_18;              // +0x1c — vanilla writes 8 here ([0x50dab0])
    char     name[4];               // +0x20..0x23 — trailing 4-byte name tail set in loop
};                                  // total = 0x24
static_assert(sizeof(TextureEntry) == 0x24, "TextureEntry stride must be 0x24");

// ============================================================================
// 2. Placed-object / entity list  (head: DAT_006313c8, insert = FUN_004b50b0)
// ============================================================================
//
// FUN_004b50b0 reads the .BIN object-placement section. It builds THREE
// parallel sub-lists at DAT_006313ac / DAT_006313b0 / DAT_006313b4 (each a
// head pointer to a singly-linked list of alloc nodes). g_PlacedObjectList
// (DAT_006313c8) is the outer list head.
//
// Allocator tags confirm source: 'odef' [0x562d10], 'readobjs.c' [0x56311c],
// 'odl' [0x563118], 'osl' [0x563104], 'objl' [0x562fb0], 'atl' [0x5630ac].
//
// 2a. Object-placement record on disk (the "ObjectRef6" / .BIN placement row).
// Stride = 7 dwords = 0x1c. The placement loop reads 7 fields per record.
struct ObjectRef6 {
    uint32_t typeId;                // +0x00 — object class id (hashed name)
    float    x, y, z;               // +0x04 — world position
    float    angle, angle2, angle3; // +0x10 — orientation (Euler)
};                                  // total = 0x1c (7*4)
static_assert(sizeof(ObjectRef6) == 0x1c, "ObjectRef6 on-disk stride must be 0x1c");

// 2b. In-memory placement node (osl/objl list). Stride = 0xa4.
// Confirmed by allocation math in the osl/objl builder:
//   [0x4b51f3] lea eax,[esi*8]      ; eax = count*8
//   [0x4b51ff] sub eax,esi          ; eax = count*7
//   [0x4b520b] lea ecx,[eax+eax*4]  ; ecx = count*7*5 = count*35
//   [0x4b520e] lea edx,[esi+ecx*8]  ; edx = count + count*35*8 = count*281
//   [0x4b5211] lea edi,[edx*4+8]    ; alloc = count*281*4 + 8 = count*0x464 + 8
// Per-element after the 8-byte {next,count} header = 0x464 bytes.
//
// NOTE: 0x464 is the objl/osl record stride (FUN_004b50b0 builds these from
// the on-disk ObjectRef6 rows). SCENE_SYSTEM.md §1.2 documents the entity
// vtable fields (+0xe4/+0xe8/+0x100/+0x174/+0x274) read by the renderer
// dispatch (FUN_0040bfd0 / object_* cluster); those live in the EntityObject.
struct PlacementHeader {            // 8-byte list header shared by ac/b0/b4 lists
    PlacementHeader* next;          // +0x00 — head-insert link
    uint32_t         count;         // +0x04 — record count that follows
};
struct PlacementNode {              // stride 0x464 in the objl/osl list (DAT_006313b0)
    uint8_t data[0x464];
};
static_assert(sizeof(PlacementNode) == 0x464, "PlacementNode stride must be 0x464");

// 2c. EntityObject — the renderer-facing entity (PS2 symbols = OBJECT API).
// vtable[0x30/4 = slot 0xC] is Render(); renderer method 0x2d80 dispatches
// via (node-0x34)->vtable[0x30]. Field offsets confirmed by FUN_0040bfd0
// reads documented in RE_docs/SCENE_SYSTEM.md §1.2.
struct EntityObject {
    void*    vftable;               // +0x00 — method 0x30 = Render (0x2d80 target)
    uint8_t  pad_link[0x34];        // +0x04..0x33
    void*    link_node;             // +0x34 — node used by renderer 0x2d80 ((node-0x34)->vtable[0x30])
    uint8_t  pad1[0xa4];            // +0x38..0xdb
    uint32_t flags_e4;              // +0xe4 — set to 3 in buoy-light attach
    uint32_t kind;                  // +0xe8 — entity typeId/kind selector
    uint8_t  pad2[0x14];            // +0xec..0xff
    void*    fx_light;              // +0x100 — fx_buoy_red/green_light
    uint8_t  pad3[0x70];            // +0x104..0x173
    uint32_t variant;               // +0x174 — entity variant/skin selector
    uint8_t  pad4[0xfc];            // +0x178..0x273
    void*    pair_ref;              // +0x274 — paired-entity pointer (e.g. light pair)
};

// ============================================================================
// 3. Level table  (head: DAT_00631388, count: DAT_00631384)
// ============================================================================
//
// Stride = 0x50A0 per level entry. CONFIRMED by two independent paths:
//   (a) FUN_004b7640 [0x4b765f] add ecx,0x50a0   ; per-entry increment in the lookup loop
//   (b) FUN_004b77f0 allocation math [0x4b78f7..0x4b7914]:
//         eax = count*129; edx = eax*5 = count*645; edx <<= 5  → count*645*32 = count*0x50A0
// (SCENE_SYSTEM.md §1.3 listed 0x1428 — that was INCORRECT; the disasm is unambiguous.)
//
// Per-level descriptor layout (offsets confirmed by FUN_004b77f0 fill loop at
// [0x4b798a..0x4b79c1] which writes +0x00/+0x04/+0x08):
struct LevelEntry {                 // stride 0x50A0 — one per world from WorldList*.bin
    uint32_t something;             // +0x00 — written from string-table dword ( FUN_004b77f0 [0x4b79c1])
    const char* name_ptr;           // +0x04 — [0x4b7998] points into the string blob (level name)
    const char* name_ptr2;          // +0x08 — [0x4b79b5] points to next level name (link)
    uint8_t  pad[0x50A0 - 0x0c];    // +0x0c..0x509F — remainder (game/scene descriptors)
};
static_assert(sizeof(LevelEntry) == 0x50A0, "LevelEntry stride must be 0x50A0 (per FUN_004b7640)");

// ============================================================================
// 4. WorldList.bin on-disk header  (read by FUN_004b77f0)
// ============================================================================
// Confirmed by parsing G:\GiantsRE\GameFiles-VanillaV1\Bin\WorldList.bin
// (688 bytes): magic=0x1a0003d0, blob_size=0x2a8 (680 = 688-8 string bytes).
//   [0x4b7879] cmp eax,0x1a0003d0  ; magic check
//   [0x4b788c] call FUN_0051d750    ; read 4 bytes (count = blob size)
//   [0x4b78ba] call FUN_0051d750    ; read count bytes (the string blob)
struct WorldListHeader {
    uint32_t magic;                 // +0x00 — must be 0x1a0003d0
    uint32_t blob_size;             // +0x04 — byte length of the string blob that follows
    // char strings[blob_size] follow — sequence of NUL-terminated level names:
    //   "Story1","Story2",...,"intro_island","M_Mecc_L1",...,"M_3WAY_Lw1"
};
static_assert(sizeof(WorldListHeader) == 8, "WorldListHeader must be 8 bytes");

// Magic constants (format versions) — referenced by the readers.
#define WORLDLIST_MAGIC  0x1a0003d0u   // [0x4b7879] FUN_004b77f0 magic check
#define SCENE_MAGIC      0x1a0002e5u   // FUN_004b7c50 scene-.BIN magic (per SCENE_SYSTEM.md §3.1)

// Level-table array bounds. FUN_004b77f0 loops edi = 0..4 (5 worldlist files).
#define WORLDLIST_FILE_COUNT 5

} // extern "C"
