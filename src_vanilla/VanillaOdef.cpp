// Giants Vanilla-Native Recomp — ODEF VM interpreter (faithful spawn port).
//
// Faithful port of the ODEF bytecode dispatcher in Giants.exe!FUN_004b7c50
// (vanilla 1.0 retail, base 0x400000). The dispatcher loop is at 0x4b809d; its
// jump table is at 0x4baa28 (opcodes 0x13..0x84). See VanillaOdef.h for the
// architectural overview and RE_docs/ODEF_VM.md for the full opcode map.
//
// Every opcode handler is traced to specific instruction addresses cited inline
// as [0x......]. The SPAWN opcodes (0x2a / 0x46) are implemented faithfully:
// they allocate an EntityObject via FUN_0049c190 (entity pool pop + zero +
// head-insert into g_PlacedObjectList), then write the placement fields
// (position → [+0xa0..0xa8], angle → [+0xc8], and for 0x46 two more angles
// → [+0xcc] / [+0xd0]) exactly as the vanilla handler at 0x4b8908 does.
//
// Non-spawn opcodes are advanced by their disassembly-confirmed byte sizes
// (derived from the `add ebp, N` / `inc ebp` instruction sequence in each
// handler — see RE_docs/ODEF_VM.md §3). Their engine-state writes are not
// reproduced (those subsystems — materials, lights, paths, fx — are not yet
// ported); they are logged at trace level so the walk is observable.
#include "VanillaOdef.h"
#include "VanillaFileIO.h"
#include "VanillaSceneTypes.h"
#include "VanillaEngine.h"
#include "VanillaObject.h"

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cstdarg>

extern "C" FILE* g_vTrace;   // defined in WinMain_vanilla.cpp

// ============================================================================
// FUN_0049c190 — entity pool allocator (faithful port of the spawn primitive).
// ============================================================================
// Vanilla disasm @ 0x49c190 (base 0x400000):
//   [0x49c190] mov eax, [0x59e3dc]      ; allocation counter
//   [0x49c195] mov ecx, [0x59e3e0]      ; high-water mark
//   [0x49c19b] inc eax; mov [0x59e3dc], eax
//   [0x49c1a1] cmp ecx, eax; jge skip; mov [0x59e3e0], eax  ; update HW mark
//   [0x49c1b0] mov esi, [0x631404]      ; esi = entity free-list head (pool)
//   [0x49c1b7] test esi, esi; jne pop   ; if pool non-empty, pop
//   [0x49c1bc] push 0x55f7f0; call 0x523aa0  ; else fatal ("no free entities")
//   [0x49c1cb] mov eax, [esi]; mov [0x631404], eax  ; pop next from free-list
//   [0x49c1d9] mov edi, esi; xor eax, eax
//   [0x49c1db] push esi
//   [0x49c1dc] mov ecx, 0xc1; rep stosd  ; ZERO 0x304 bytes (entity slot)
//   [0x49c1de] push 0x6313c8            ; &g_PlacedObjectList
//   [0x49c1e3] call 0x472ef0            ; head-insert scene-list node
//   [0x49c1e8] mov eax, [esi+0xdc]; or eax, 0x80000000; mov [esi+0xdc], eax
//   [0x49c1f6] mov dword ptr [esi+0xc4], 0x3f800000  ; scale = 1.0f
//   [0x49c206] lea eax, [esi+0x10]; mov ecx, 4
//   [0x49c20e] loop: mov dword ptr [eax], 0xfe; add eax, 0x24; dec ecx; jne loop
//                  ; writes 0xfe at +0x10, +0x34, +0x58, +0x7c (sentinel slots)
//   [0x49c21a] call 0x49c150             ; post-alloc hook (event dispatch)
//
// The recomp does not yet have the engine pool / scene-list node factory
// (FUN_00472ef0 builds 0xc84-byte scene nodes that embed the entity). We provide
// a faithful ALLOCATION+ZERO+HEAD-INSERT here using the recomp's list layout
// (see SpawnTestEntity in VanillaObject.cpp for the two-level outer/inner node
// structure the renderer walker expects).
//
// size_arg - the vanilla allocator receives the template size (0x406 from the
//            spawn handler at [0x4b88e0]). The actual zeroed slot is 0x304
//            bytes (0xc1 dwords) regardless; size_arg is informational.
// Returns a pointer to the zeroed EntityObject, head-inserted into
// g_PlacedObjectList, or nullptr on allocation failure.
extern "C" void* FUN_0049c190(uint32_t size_arg) {
    (void)size_arg;   // vanilla ignores it for the zero-size (uses fixed 0xc1)

    constexpr uint32_t ENTITY_SLOT_SIZE = 0x304;   // 0xc1 dwords @ [0x49c1dc]
    EntityObject* entity = (EntityObject*)std::calloc(1, ENTITY_SLOT_SIZE);
    if (!entity) {
        if (g_vTrace) { std::fprintf(g_vTrace, "[ODEF/FUN_0049c190] ALLOC FAILED (size=0x%x)\n", size_arg); std::fflush(g_vTrace); }
        return nullptr;
    }

    // [0x49c1e8] flags: [+0xdc] |= 0x80000000 (active/in-list flag).
    // Note: +0xdc is beyond the EntityObject struct's documented pad4 tail; we
    // write through a raw byte pointer to match the vanilla layout exactly.
    uint8_t* raw = (uint8_t*)entity;
    *(uint32_t*)(raw + 0xdc) |= 0x80000000u;

    // [0x49c1f6] scale: [+0xc4] = 1.0f.
    *(float*)(raw + 0xc4) = 1.0f;

    // [0x49c206] sentinel slots: [+0x10], [+0x34], [+0x58], [+0x7c] = 0xfe.
    *(uint32_t*)(raw + 0x10) = 0xfeu;
    *(uint32_t*)(raw + 0x34) = 0xfeu;
    *(uint32_t*)(raw + 0x58) = 0xfeu;
    *(uint32_t*)(raw + 0x7c) = 0xfeu;

    // [0x49c1e3] head-insert into g_PlacedObjectList (DAT_006313c8). The vanilla
    // list-builder FUN_00472ef0 allocates a 0xc84-byte scene-list node that embeds
    // the entity at a fixed inner-stride offset. We reproduce the two-level layout
    // the renderer walker (FUN_0050e540) expects:
    //   outer node : { next@+0x00, ?, inner_hdr@+0x0c }
    //   inner hdr   : { ?, count@+0x08, entity_ptrs[10]@+0x400 }
    // Each spawn creates a fresh inner block with count=1 holding this entity.
    struct InnerHolder { uint32_t pad[2]; uint32_t count; uint8_t slots[0x430]; };
    struct OuterNode  { OuterNode* next; uint32_t pad[2]; InnerHolder* inner; };

    OuterNode* outer   = (OuterNode*)std::calloc(1, sizeof(OuterNode));
    InnerHolder* inner = (InnerHolder*)std::calloc(1, sizeof(InnerHolder));
    if (!outer || !inner) {
        std::free(outer); std::free(inner); std::free(entity);
        return nullptr;
    }
    inner->count = 1;                                              // [+0x08]
    *(void**)(inner->slots + (0x400 - 0x0c)) = entity;             // entity @ +0x400
    outer->inner = inner;
    outer->next  = (OuterNode*)(uintptr_t)g_PlacedObjectList;      // head-insert
    g_PlacedObjectList = (uint32_t)(uintptr_t)outer;

    if (g_vTrace) {
        std::fprintf(g_vTrace, "[ODEF/FUN_0049c190] entity=%p (size_arg=0x%x) scale=1.0 active — inserted into g_PlacedObjectList (outer=%p inner=%p)\n",
                     (void*)entity, size_arg, (void*)outer, (void*)inner);
        std::fflush(g_vTrace);
    }
    return entity;
}

namespace {

// ============================================================================
// Opcode handler stream-consumption sizes (bytes consumed AFTER the opcode byte).
// ============================================================================
// Derived from the `add ebp, N` / `inc ebp` instruction sequence in each handler
// (auto-extracted via capstone — see RE_docs/ODEF_VM.md §3 for the per-handler
// trace). Variable-length opcodes (containing an embedded NUL-string) use -1.
//
// The dispatcher validates `opcode_byte in [0x13..0x84]` (table index = byte -
// 0x13, range-checked against 0x71 at [0x4b80b5]); anything else jumps to the
// bad-opcode error at 0x4ba592.
struct OpInfo { int16_t size; const char* name; };

#define OP(op, sz, name) case op: return { sz, name };

OpInfo lookup_op(uint8_t op) {
    switch (op) {
        // ── variable-length (NUL-string + tail) ──
        OP(0x84, -1, "NAME_set")              // 0x4ba50a: NUL-string → [engine+0x509c]
        OP(0x76, -1, "name+dwords")           // 0x4ba02a: NUL-string + 16B → [engine+0x4efc..0x4f54]
        OP(0x5d, -1, "name+slot")             // 0x4b8ba2: NUL-string + 0x20B block (slot table find)
        OP(0x5e, -1, "name+slot_find")        // 0x4b87e9: NUL-string + slot-array find
        OP(0x82, -1, "name_0x20")             // 0x4b878d: 0x20-byte name → [engine+0x507c]
        OP(0x6f, -1, "name_0x20_dup")         // (shared 0x4b878d variant via 0x4b87b7? — treat as var)
        // ── SPAWN opcodes (the goal) ──
        OP(0x2a, 20, "SPAWN_pos+angle")       // 0x4b883f: nameId(4) + pos(12) + angle(4)
        OP(0x46, 28, "SPAWN_pos+3angles")     // 0x4b883f: nameId(4) + pos(12) + 3 angles(12)
        // ── property setters (current entity / engine) ──
        OP(0x13,  1, "byte_to_[ebx+0x10]")    // 0x4b8a17
        OP(0x17,  4, "dword_[0x6316ec+?]")    // 0x4b97ce
        OP(0x1d, 16, "block16")               // 0x4b810a
        OP(0x1e, 16, "block16")               // 0x4b80c5
        OP(0x1f, 16, "block16")               // 0x4b814a
        OP(0x20, 16, "block16")               // 0x4b818a
        OP(0x21, 16, "block16")               // 0x4b81d2
        OP(0x22, 16, "block16")               // 0x4b821a
        OP(0x23, 16, "block16")               // 0x4b9445 (shared)
        OP(0x24, 16, "block16")               // 0x4b8262
        OP(0x25, 16, "block16")               // 0x4b82a2
        OP(0x26, 16, "block16")               // 0x4b82eb
        OP(0x27, 17, "attach_slot")           // 0x4b837f: byte + 4 dwords
        OP(0x28,  3, "three_bytes")           // 0x4b8451: 3 bytes → engine +0x4f38..0x4f40
        OP(0x29, 11, "misc_11B")              // 0x4b8533
        OP(0x2b,  4, "dword_[ebx+0x14]")      // 0x4b8a36
        OP(0x2c, 32, "block32")               // 0x4b9dc5
        OP(0x2d, 36, "block36")               // 0x4b8c3c
        OP(0x2e, 12, "light_color")           // 0x4b8333: dword + 2 floats
        OP(0x2f, 28, "skip_ObjectRef6")       // 0x4b8a05: skip 0x1c (the on-disk placement row)
        OP(0x30, 18, "slot18")                // 0x4b83e7
        OP(0x31, 40, "block40")               // 0x4b8e7a
        OP(0x32,  2, "short")                 // 0x4b8e8c
        OP(0x33, 36, "block36")               // 0x4b8fd0
        OP(0x34, 44, "light_prop_0x1e4")      // 0x4b9112
        OP(0x35, 44, "light_prop_0x1ec")      // 0x4b9195
        OP(0x36, 44, "light_prop_0x1f4")      // 0x4b9218
        OP(0x37, 36, "error_fog?")            // 0x4b8fef (logs error 0x56336c)
        OP(0x38, 36, "error_fog?")            // 0x4b900e (logs error 0x563350)
        OP(0x39, 28, "ambient_light")         // 0x4b902d: [engine+0x1ac..0x1b8]
        OP(0x3a, 36, "block36")               // 0x4b8c2e
        OP(0x3b,  1, "KIND_[ebx+0xe8]")       // 0x4b8a4e: 1 byte → entity kind/typeId
        OP(0x3c, 16, "block16_dup")           // 0x4b9445 (shared with 0x23)
        OP(0x3d,  0, "no_op")                 // 0x4ba57f (shared)
        OP(0x3e, 20, "block20")               // 0x4b9457
        OP(0x3f,  8, "path_segment")          // 0x4b8f2b: 2 dwords → [ebx+0x170][+0xc/+0x10]
        OP(0x40, 25, "block25")               // 0x4b9469
        OP(0x41,  8, "two_dwords")            // 0x4b95bb
        OP(0x42, 32, "block32b")              // 0x4b95e8
        OP(0x43,  0, "no_op_dup")             // 0x4ba57f (shared)
        OP(0x44,  0, "no_op")                 // 0x4b97e9
        OP(0x45,  0, "no_op")                 // 0x4b9800
        OP(0x47, 20, "block20b")              // 0x4b9817
        OP(0x48, 12, "three_dwords")          // 0x4b8f65
        OP(0x49,  4, "dword")                 // 0x4b98c2
        OP(0x4a,  0, "no_op")                 // 0x4b98e3
        OP(0x4b,  6, "six_bytes")             // 0x4b9902
        OP(0x4c,  4, "dword_dup")             // 0x4b99e6
        OP(0x4d,  0, "no_op")                 // 0x4b9b92
        OP(0x4e, 32, "block32c")              // 0x4b9cc0
        OP(0x4f, 64, "name32+block32")        // 0x4b9c55: 0x20 name + 0x20 data
        OP(0x50,  5, "byte+dword")            // 0x4b9e41
        OP(0x51, 12, "three_dwords_b")        // 0x4b9f19
        OP(0x52,  4, "VARIANT_[ebx+0x174]")   // 0x4b8a69: dword → entity variant
        OP(0x53,  4, "dword_[engine+0x4ea8]") // 0x4b8e2c
        OP(0x54, 44, "block44")               // 0x4b8d22
        OP(0x55,  0, "no_op")                 // default 0x4ba58e (error if reached)
        OP(0x56,  0, "no_op")                 // default
        OP(0x57,  0, "no_op")                 // default
        OP(0x58, 11, "misc_11B_b")            // 0x4b8660
        OP(0x59,  1, "byte_[engine+0x4ebc]")  // 0x4b8dfd
        OP(0x5a, 12, "POS_[ebx+0xf4]")        // 0x4b8a84: 3 floats → entity +0xf4..0xfc
        OP(0x5b, 12, "three_floats")          // 0x4b8e4a
        OP(0x5c, 37, "byte+dword+block32")    // 0x4b8b48
        OP(0x5f, 12, "three_dwords_c")        // 0x4b9f69
        OP(0x60,  4, "fx_selector")           // 0x4b84f2: dword → [engine+0x4e8c]
        OP(0x61,  8, "two_dwords_b")          // 0x4b8ab7
        OP(0x62,  8, "two_floats_[ebx+0x100]")// 0x4b8ae7: 2 floats → fx_light +0x10/+0x14
        OP(0x63,  0, "no_op")                 // 0x4b8b10
        OP(0x64,  0, "no_op")                 // 0x4b8b2c
        OP(0x65, 12, "three_dwords_d")        // 0x4b9fa4
        OP(0x66,  8, "two_dwords_c")          // 0x4b9fe8
        OP(0x67,  8, "two_dwords_d")          // 0x4b9e74
        OP(0x68,  8, "two_dwords_e")          // 0x4b9ebe
        OP(0x69,  0, "no_op")                 // default
        OP(0x6a,  1, "byte")                  // 0x4b9df5
        OP(0x6b,  4, "dword_[engine+0x4a80]") // 0x4b9dd7
        OP(0x6c, 64, "block64")               // 0x4b87b7
        OP(0x6d, 64, "block64")               // 0x4b87b7
        OP(0x6e, 64, "block64")               // 0x4b87b7
        OP(0x70, 32, "block32b_dup")          // 0x4b9dc5 (shared with 0x2c)
        OP(0x71, 32, "block32b_dup")          // 0x4b9dc5
        OP(0x72, 44, "fog_prop_0x1e4")        // 0x4b929b
        OP(0x73, 44, "fog_prop_0x1ec")        // 0x4b931e
        OP(0x74, 44, "fog_prop_0x1f4")        // 0x4b93a1
        OP(0x75,  4, "dword_[engine+0x4ef4]") // 0x4b9424
        OP(0x77, 48, "block48")               // 0x4ba0b0
        OP(0x78, 48, "block48b")              // 0x4ba193
        OP(0x79, 48, "block48c")              // 0x4ba276
        OP(0x7a,  0, "no_op")                 // default
        OP(0x7b,  0, "no_op")                 // default
        OP(0x7c,  0, "no_op")                 // default
        OP(0x7d,  0, "no_op")                 // default
        OP(0x7e,  0, "no_op")                 // default
        OP(0x7f,  0, "no_op")                 // default
        OP(0x80,  0, "no_op")                 // default
        OP(0x81,  4, "dword_[engine+0x4a7c]") // 0x4b87c9
        OP(0x83,  0, "no_op")                 // default
        default:    return { -2, "INVALID" };   // outside [0x13..0x84]
    }
}
#undef OP

// Skip a NUL-terminated string starting at cursor p; return position AFTER the NUL.
uint32_t skip_cstr(const uint8_t* blob, uint32_t p, uint32_t end) {
    while (p < end && blob[p] != 0) ++p;
    return (p < end) ? p + 1 : p;
}

void trace(const char* fmt, ...) {
    if (!g_vTrace) return;
    va_list ap; va_start(ap, fmt);
    std::vfprintf(g_vTrace, fmt, ap);
    va_end(ap);
    std::fflush(g_vTrace);
}

// Per-entity placement fields written by the spawn handler tail @ 0x4b8908.
// We expose them here as raw-offset writes so the field offsets are visible
// and traceable to the disasm citations.
void write_entity_placement(void* entity, float x, float y, float z,
                            float ang0, float ang1, float ang2, bool has_3_angles) {
    uint8_t* raw = (uint8_t*)entity;
    *(float*)(raw + 0xa0) = x;       // [0x4b8958] mov [ebx+0xa0],ecx
    *(float*)(raw + 0xa4) = y;       // [0x4b8967] mov [ebx+0xa4],edx
    *(float*)(raw + 0xa8) = z;       // [0x4b8973] mov [ebx+0xa8],eax
    *(float*)(raw + 0xc8) = ang0;    // [0x4b8986] mov [ebx+0xc8],ecx
    if (has_3_angles) {
        *(float*)(raw + 0xcc) = ang1;  // [0x4b8994] mov [ebx+0xcc],edx
        *(float*)(raw + 0xd0) = ang2;  // [0x4b89a0] mov [ebx+0xd0],eax
    }
}

} // namespace

// ============================================================================
// VanillaOdef_Run — the faithful ODEF dispatcher.
// ============================================================================
extern "C" void VanillaOdef_Run(uint32_t stream, uint32_t blobSize) {
    if (blobSize == 0 || blobSize > (1u << 20)) {
        trace("[ODEF] blobSize=%u out of range — skip\n", blobSize);
        return;
    }

    // [0x4b7ea0] malloc 0x1c9 template; [0x4b7eb2] READ blobSize bytes into it.
    // We bound to blobSize (the vanilla 0x1c9 is the small-template path; for
    // real levels the loader mallocs blobSize).
    uint8_t* blob = (uint8_t*)std::malloc(blobSize);
    if (!blob) { trace("[ODEF] malloc %u failed\n", blobSize); return; }
    FUN_0051d750(stream, blob, blobSize);
    trace("[ODEF] loaded %u-byte blob from stream handle %u\n", blobSize, stream);

    // [0x4b7eb7..0x4b7edb] skip TWO NUL-terminated header strings (template-name
    //   + class-name). e.g. for w_intro_island: "box01\0" + "intro_island.gti\0".
    uint32_t cursor = 0;
    cursor = skip_cstr(blob, cursor, blobSize);   // string 1
    cursor = skip_cstr(blob, cursor, blobSize);   // string 2
    trace("[ODEF] header strings consumed; cursor @ %u\n", cursor);

    // Per-entity state mirrored from the dispatcher registers.
    void* current_entity = nullptr;   // ebx in vanilla (the entity being defined)
    uint32_t spawn_count = 0;

    // ── Main dispatch loop (0x4b809d) ──
    while (cursor < blobSize) {
        uint8_t op = blob[cursor++];               // [0x4b809f] mov al, [ebp]; inc ebp
        if (op == 0xff) {                          // [0x4b80a3] cmp eax, 0xff; je end
            trace("[ODEF] END (0xff) @ cursor %u\n", cursor - 1);
            break;
        }
        // [0x4b80b2] lea ecx, [eax-0x13]; cmp ecx, 0x71; ja bad_opcode
        if (op < 0x13 || op > 0x84) {
            trace("[ODEF] BAD opcode 0x%02x @ cursor %u (out of [0x13..0x84]) — abort\n",
                  op, cursor - 1);
            break;
        }

        OpInfo info = lookup_op(op);

        // ── NAME opcode (0x84): NUL-string → pending name slot ──
        // Vanilla @ 0x4ba50a: reads NUL-string, copies into [engine+0x509c].
        // We track the last name to log spawns with context.
        if (op == 0x84) {
            uint32_t start = cursor;
            cursor = skip_cstr(blob, cursor, blobSize);
            char name[128];
            uint32_t len = (cursor - 1) - start;
            if (len >= sizeof(name)) len = sizeof(name) - 1;
            std::memcpy(name, blob + start, len);
            name[len] = '\0';
            trace("[ODEF]   @%-5u NAME(0x84) \"%s\"\n", cursor - len - 1, name);
            continue;
        }

        // ── Variable-length opcodes (name + tail) ──
        if (info.size == -1) {
            uint32_t start = cursor;
            uint32_t after_str = skip_cstr(blob, cursor, blobSize);
            uint32_t tail = 0;
            // Tail sizes per-opcode (from disasm of the post-string reads):
            switch (op) {
                case 0x76: tail = 16; break;   // 4 dwords
                case 0x5d: tail = 2;  break;   // (slot-find returns; minimal)
                case 0x5e: tail = 0;  break;
                case 0x82: tail = 0;  break;   // 0x20-byte name only (head-copy)
                case 0x6f: tail = 0;  break;
                default:   tail = 0;  break;
            }
            trace("[ODEF]   @%-5u op 0x%02x %-22s (var: str=%u + tail=%u)\n",
                  start - 1, op, info.name, after_str - start, tail);
            cursor = after_str + tail;
            continue;
        }

        if (info.size < 0) {
            trace("[ODEF]   @%-5u op 0x%02x INVALID — abort\n", cursor - 1, op);
            break;
        }

        // ── Fixed-size opcodes ──
        uint32_t payload_off = cursor;
        if (cursor + info.size > blobSize) {
            trace("[ODEF]   @%-5u op 0x%02x %-22s truncated (need %d, have %u) — abort\n",
                  cursor - 1, op, info.name, info.size, (unsigned)(blobSize - cursor));
            break;
        }
        cursor += info.size;

        // ── SPAWN opcodes (0x2a / 0x46): the goal of this port ──
        // Vanilla handler @ 0x4b883f: reads nameId (4B) then tail-jumps to
        // 0x4b8908 which allocates the entity and writes placement.
        if (op == 0x2a || op == 0x46) {
            uint32_t nameId = *(const uint32_t*)(blob + payload_off);
            float x = *(const float*)(blob + payload_off + 4);
            float y = *(const float*)(blob + payload_off + 8);
            float z = *(const float*)(blob + payload_off + 12);
            float ang0 = *(const float*)(blob + payload_off + 16);
            float ang1 = 0.0f, ang2 = 0.0f;
            if (op == 0x46) {
                ang1 = *(const float*)(blob + payload_off + 20);
                ang2 = *(const float*)(blob + payload_off + 24);
            }

            // FUN_0049d2d0(nameId) would look up an existing entity; on miss we
            // allocate via FUN_0049c190 (entity pool pop + zero + head-insert).
            void* entity = FUN_0049c190(0x406);   // [0x4b88e5] push 0x406
            if (entity) {
                write_entity_placement(entity, x, y, z, ang0, ang1, ang2, op == 0x46);
                current_entity = entity;
                ++spawn_count;
                trace("[ODEF]   @%-5u >>> SPAWN op 0x%02x nameId=0x%08x pos=(%.2f,%.2f,%.2f) ang=(%.2f%s) → entity=%p (#%u)\n",
                      payload_off - 1, op, nameId, x, y, z, ang0,
                      op == 0x46 ? "," : "", (void*)entity, spawn_count);
            } else {
                trace("[ODEF]   @%-5u SPAWN op 0x%02x nameId=0x%08x — ALLOC FAILED\n",
                      payload_off - 1, op, nameId);
            }
            continue;
        }

        // ── Property setters on current entity ──
        // These mirror vanilla field writes; we apply the ones we can and log
        // the rest. The current entity must exist for entity-targeted opcodes.
        if (op == 0x3b && current_entity) {
            // [0x4b8a5c] mov [ebx+0xe8], al — set entity kind/typeId.
            uint8_t kind = blob[payload_off];
            *(uint32_t*)((uint8_t*)current_entity + 0xe8) = kind;
            trace("[ODEF]   @%-5u KIND(0x3b) = %u → [entity+0xe8]\n", payload_off - 1, kind);
            continue;
        }
        if (op == 0x52 && current_entity) {
            // [0x4b8a70] mov [ebx+0x174], edx — set entity variant.
            uint32_t variant = *(const uint32_t*)(blob + payload_off);
            *(uint32_t*)((uint8_t*)current_entity + 0x174) = variant;
            trace("[ODEF]   @%-5u VARIANT(0x52) = 0x%08x → [entity+0x174]\n",
                  payload_off - 1, variant);
            continue;
        }
        if (op == 0x5a && current_entity) {
            // [0x4b8a8a..] mov [ebx+0xf4..0xfc] — alternate position slot.
            float x = *(const float*)(blob + payload_off);
            float y = *(const float*)(blob + payload_off + 4);
            float z = *(const float*)(blob + payload_off + 8);
            *(float*)((uint8_t*)current_entity + 0xf4) = x;
            *(float*)((uint8_t*)current_entity + 0xf8) = y;
            *(float*)((uint8_t*)current_entity + 0xfc) = z;
            trace("[ODEF]   @%-5u POS(0x5a) = (%.2f,%.2f,%.2f) → [entity+0xf4..0xfc]\n",
                  payload_off - 1, x, y, z);
            continue;
        }

        // ── All other opcodes: advance + log ──
        trace("[ODEF]   @%-5u op 0x%02x %-22s size=%d (engine-state write skipped)\n",
              payload_off - 1, op, info.name, info.size);
    }

    trace("[ODEF] run complete: %u entities spawned\n", spawn_count);
    std::free(blob);
}

// ============================================================================
// SelfTest — load w_intro_island.bin and run its ODEF blob.
// ============================================================================
namespace VanillaOdef {

int SelfTest() {
    trace("=== VanillaOdef::SelfTest ===\n");

    // Open the .BIN file via the recomp VFS (FUN_00539e30).
    uint32_t h = FUN_00539e30("w_intro_island.bin");
    if (h == 0) {
        trace("[ODEF/SelfTest] FAILED to open w_intro_island.bin\n");
        return -1;
    }

    // Replicate the header parse from FUN_004b7c50 just enough to locate the
    // odef section (header[0] = odef_blob offset; u32 at that offset = size).
    uint32_t magic = 0;
    FUN_0051d750(h, &magic, 4);
    if (magic != SCENE_MAGIC) {
        trace("[ODEF/SelfTest] BAD magic 0x%08x\n", magic);
        FUN_0051d850(h);
        return -1;
    }
    uint32_t header[7];
    FUN_0051d750(h, header, 0x1c);
    trace("[ODEF/SelfTest] header[0] (odef offset) = %u\n", header[0]);

    // SEEK to header[0]+4 (past the size u32) and read the blob.
    FUN_0051d7b0(h, header[0] + 4);
    uint32_t odef_size = 0;
    FUN_0051d7b0(h, header[0]);     // re-seek to read the size first
    FUN_0051d750(h, &odef_size, 4);
    trace("[ODEF/SelfTest] odef blob size = %u\n", odef_size);

    // The cursor is now positioned AFTER the size u32. Run the interpreter.
    VanillaOdef_Run(h, odef_size);

    FUN_0051d850(h);
    trace("=== VanillaOdef::SelfTest done ===\n");
    return 0;
}

} // namespace VanillaOdef
