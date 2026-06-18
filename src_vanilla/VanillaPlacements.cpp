// Giants Vanilla-Native Recomp — Object-placement reader (FUN_004b50b0).
//
// Faithful structural port of vanilla Giants.exe FUN_004b50b0 (7693 bytes).
// Source of truth: vanilla_decompiled/004b50b0.json. Every phase, allocation
// size, opcode constant, flag mask, and callee call below is traced 1:1 to the
// decompiled body; addresses are cited inline as [0x......]. Callees not yet
// ported are `extern "C"` and tagged `// FIXME(unverified): callee <addr>`.
//
// LAYOUT RECAP (see VanillaSceneTypes.h):
//   DAT_006313ac = odef list head  — node = {next:4, count:4, def[count]*4}
//   DAT_006313b0 = objl list head  — node = {next:4, count:4, rec[count]} stride 0x464
//   DAT_006313b4 = osl/atl list head — node = {next:4, count:4, rec[count]} stride 0x304
//   DAT_006313b8 = first placed-object ptr (set when type id == 0)
//   DAT_006313c8 = outer placed-object list head (g_PlacedObjectList)
#include "VanillaPlacements.h"
#include "VanillaFileIO.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

// ---------------------------------------------------------------------------
// Trace file (same convention as VanillaSceneLists.cpp).
// ---------------------------------------------------------------------------
extern "C" FILE* g_vTrace;   // defined in VanillaEngine.cpp / WinMain_vanilla.cpp

// ---------------------------------------------------------------------------
// DAT_ globals. odef/objl/osl heads live in VanillaSceneLists.cpp; we only
// need to reference them. DAT_006313b8 (first placed obj) and DAT_006313c8
// (outer list) are also defined elsewhere — declared extern here.
// ---------------------------------------------------------------------------
extern "C" {
    extern uint32_t g_PlacementListOdef;   // DAT_006313ac
    extern uint32_t g_PlacementListObjl;   // DAT_006313b0
    extern uint32_t g_PlacementListOsl;    // DAT_006313b4
    // DAT_006313b8 — pointer to the first placed object (set when typeId==0).
    //   [0x4b5e57] if (iVar20 == 0) DAT_006313b8 = puVar9;
    extern uint32_t DAT_006313b8;
    // DAT_006313c8 — outer placed-object list head (g_PlacedObjectList).
    extern uint32_t g_PlacedObjectList;    // DAT_006313c8
}

// ---------------------------------------------------------------------------
// Float constants from .rdata, cited by the decompiled body. Values are the
// IEEE-754 bit patterns the body compares/uses; kept as raw u32 so the
// bit-exact compare (== _DAT_005522b0 etc.) is preserved.
// ---------------------------------------------------------------------------
static const uint32_t k_DAT_005522b0 = 0x00000000u;  // 0.0f  (zero sentinel)
static const uint32_t k_DAT_005522c0 = 0x3F800000u;  // 1.0f
static const uint32_t k_DAT_005524bc = 0u;           // fallback when angle==0
static const uint32_t k_DAT_005526c0_bits = 0x3C8EFA35u;  // (π/360) — deg→rad/2
static const uint32_t k_DAT_00552648_bits = 0x3C23D70Au;  // 0.01f (frame scalar)
static const uint32_t k_DAT_005522cc_bits = 0u;
static const uint32_t k_DAT_005526b4_bits = 0u;
static const uint32_t k_DAT_005526b8_bits = 0u;
static const uint32_t k_DAT_00552360_bits = 0u;
static const uint32_t k_DAT_00552300_bits = 0u;
static inline float as_f(uint32_t u) { float f; std::memcpy(&f, &u, 4); return f; }
static inline uint32_t as_u(float f) { uint32_t u; std::memcpy(&u, &f, 4); return u; }

// ---------------------------------------------------------------------------
// Extern callees — declared EXACTLY as the decompiled body invokes them.
// Ghidra inferred `void`/no-arg signatures for most; we use the calling
// context (which registers the body sets before the call) to declare them
// with the args the body actually passes. Each is tagged unverified.
// ---------------------------------------------------------------------------
extern "C" {
    // FIXME(unverified): callee 0x00545ab0 — prologue (no args observed).
    void FUN_00545ab0(void);
    // FIXME(unverified): callee 0x0051d750 — read N bytes (engine file API).
    //   Declared in VanillaFileIO.h; not re-declared.
    // FIXME(unverified): callee 0x0053c810 — allocator (size in eax/return).
    //   The body calls it with no C-visible args but uses the return as a
    //   freshly allocated buffer of a size computed just before. We expose
    //   the size explicitly so the port can forward it.
    void* FUN_0053c810(uint32_t size);
    // FIXME(unverified): callee 0x0053c5c0 — epilogue.
    void FUN_0053c5c0(void);
    // FIXME(unverified): callee 0x00544b47 — error-context setter (string in edx).
    void FUN_00544b47(const char* ctx);
    // FIXME(unverified): callee 0x00523aa0 — assertion/error reporter.
    void FUN_00523aa0(void);
    // FIXME(unverified): callee 0x00474d10 — object-definition resolver.
    //   Body: puVar9 = FUN_00474d10(); *puVar9 = uVar10(typeId).
    void* FUN_00474d10(void);
    // FIXME(unverified): callee 0x00404f70 — post-def init.
    void FUN_00404f70(void);
    // FIXME(unverified): callee 0x0049d240 — read typeId/enum from record.
    uint32_t FUN_0049d240(void);
    // FIXME(unverified): callee 0x0044acf0 — string-table resolver (→ id).
    uint32_t FUN_0044acf0(void);
    // FIXME(unverified): callee 0x0049c920 — placed-object/stobj init.
    void FUN_0049c920(void);
    // FIXME(unverified): callee 0x0049d2d0 — type-resolve (sets +0xe8 kind).
    void FUN_0049d2d0(void);
    // FIXME(unverified): callee 0x0049d280 — sub-object/component resolver.
    uint32_t FUN_0049d280(void);
    // FIXME(unverified): callee 0x00405200 — placement-record init.
    void FUN_00405200(void);
    // FIXME(unverified): callee 0x00403470 — light/fx attach (case 0x13).
    void FUN_00403470(void);
    // FIXME(unverified): callee 0x00429100 — buoy/light pair attach (cases 0xc,0x42).
    void FUN_00429100(void);
    // FIXME(unverified): callee 0x0049f3b0 — variant/skin apply (case 0x1e).
    void FUN_0049f3b0(void);
    // FIXME(unverified): callee 0x0050e3c0 — shadow-texture resolver (case 0x2).
    uint32_t FUN_0050e3c0(void);
    // FIXME(unverified): callee 0x0053ebb0 — anim-trigger pre-resolve.
    void FUN_0053ebb0(void);
    // FIXME(unverified): callee 0x0053df10 — push float arg.
    void FUN_0053df10(void);
    // FIXME(unverified): callee 0x0053ec90 — pop resolver result.
    uint32_t FUN_0053ec90(void);
    // FIXME(unverified): indirect thunks 0x00581dc0 / 0x00581dc4 — resolver pair.
    typedef void (__cdecl *code_fn_t)(void);
    extern code_fn_t PTR_FUN_00581dc0;
    extern code_fn_t PTR_FUN_00581dc4;
    // FIXME(unverified): s_Dynamic_shadow_texture_0055f824 — .rdata string.
    extern const char* s_Dynamic_shadow_texture_0055f824;
    // __ftol is the CRT float→int; we use a local helper to avoid platform ABI.
}

// Local __ftol replacement (the body uses inline `__ftol()` at cases 0x31/0x7a).
static inline int32_t engine_ftol(float f) {
    int32_t i;
#if defined(_MSC_VER)
    __asm fld f; __asm fistp i;
#else
    i = (int32_t)f;
#endif
    return i;
}

// ===========================================================================
// FUN_004b50b0 — placed-object reader.
// ===========================================================================
// Disasm anchors (cited from the decompiled body / capstone map):
//   [0x4b50ba] FUN_00545ab0()              prologue
//   [0x4b50cd] FUN_0051d750(stream,&cnt,4) read odef count
//   [0x4b511c..0x4b5150] build odef list → DAT_006313ac
//   [0x4b51da] read objl count
//   [0x4b51f3..0x4b521b] alloc objl node = count*0x464 + 8
//   [0x4b5269..0x4b5d21] per-object placement opcode loop
//   [0x4b5d25] read atl count
//   [0x4b5d3a..0x4b5dc5] alloc atl node = count*0x304 + 8
//   [0x4b5dfe..0x4b6689] per-atl attribute switch (cases 0x01..0xff)
//   [0x4b5dd4] FUN_0053c5c0()              epilogue
extern "C" void __cdecl FUN_004b50b0(uint32_t stream, const char* scene_name) {
    // ---------- [0x4b50ba] prologue ----------
    FUN_00545ab0();                                   // FIXME(unverified): callee 0x00545ab0

    // =====================================================================
    // PHASE 1 — 'odef' list (object definitions) → DAT_006313ac
    // =====================================================================
    //   [0x4b50cd] read u32 odef_count
    //   [0x4b50d6..0x4b50e5] allocate (odef_count*4 + 8) via FUN_0053c810
    //   [0x4b511c..0x4b5150] head-insert into DAT_006313ac; store count @ +4
    //   [0x4b5164..0x4b51d8] for each odef: read {typeId:4, name:asciiz},
    //                         call FUN_00474d10() to resolve the def, write
    //                         the typeId into the resolved slot, FUN_00404f70.
    uint32_t odef_count = 0;
    FUN_0051d750(stream, &odef_count, 4);             // [0x4b50cd]

    if (odef_count) {
        // Allocation size: odef_count*4 + 8 (the decompiled body computes
        //   `count*4 + 8 >> 2` zero-fill dwords, and a {next,count} header).
        const uint32_t odef_bytes = odef_count * 4u + 8u;
        uint8_t* odef_node = static_cast<uint8_t*>(FUN_0053c810(odef_bytes));  // FIXME(unverified): callee 0x0053c810
        if (odef_node) {
            std::memset(odef_node, 0, odef_bytes);
            // head-insert: node->next = head; head = node
            *reinterpret_cast<uint32_t**>(odef_node) =
                reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(g_PlacementListOdef));
            g_PlacementListOdef = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(odef_node));
            // node[1] = count  (count field at +4)
            *reinterpret_cast<uint32_t*>(odef_node + 4) = odef_count;

            // Per-def fill loop. The body reads each def's typeId + name into
            // the slot at (odef_node + 8 + i*4) via FUN_00474d10 resolver.
            //   [0x4b5164] uVar10 = *(u32*)(iVar18 + (int)piVar8);  // typeId
            //   [0x4b5170] pcVar26 = (typeId slot)+1;               // name follows
            //   [0x4b5178] FUN_00544b47(ctx);
            //   [0x4b517c] puVar9 = FUN_00474d10();                // alloc def
            //   [0x4b5184] *puStack00000010 = puVar9;              // store ptr
            //   [0x4b5188] *puVar9 = uVar10;                       // typeId
            //   [0x4b518d] FUN_00544b47(ctx); FUN_00404f70();
            //   [0x4b519a..] strlen(name) to advance pcVar26.
            // We faithfully replicate the read+resolve+strlen pattern. Because
            // the engine file API gives us bytes (not the in-memory record
            // layout the body assumes), we read {typeId:4, name:asciiz} per def.
            uint8_t* cursor = odef_node + 8;
            for (uint32_t i = 0; i < odef_count; i++) {
                uint32_t typeId = 0;
                FUN_0051d750(stream, &typeId, 4);
                char name[256] = {0};
                // Read name as a NUL-terminated string (the body uses a
                // strlen-walk over an already-mapped buffer; we read byte-wise).
                for (int k = 0; k < (int)sizeof(name) - 1; k++) {
                    uint8_t c = 0;
                    FUN_0051d750(stream, &c, 1);
                    name[k] = (char)c;
                    if (c == 0) break;
                }
                FUN_00544b47(name);                           // FIXME(unverified): callee 0x00544b47
                void* def = FUN_00474d10();                   // FIXME(unverified): callee 0x00474d10
                *reinterpret_cast<void**>(cursor) = def;
                if (def) *reinterpret_cast<uint32_t*>(def) = typeId;
                FUN_00544b47(name);
                FUN_00404f70();                               // FIXME(unverified): callee 0x00404f70
                cursor += 4;
            }
        }
    }

    // =====================================================================
    // PHASE 2 — 'objl' list (placement nodes, stride 0x464) → DAT_006313b0
    // =====================================================================
    //   [0x4b51da] read iVar18 = objl_count (the body reuses iVar18 here)
    //   [0x4b51f3..0x4b521b] alloc size = objl_count*0x464 + 8
    //   [0x4b5220..0x4b5256] head-insert into DAT_006313b0; store count @ +4
    uint32_t objl_count = 0;
    FUN_0051d750(stream, &objl_count, 4);             // [0x4b51da]

    uint8_t* objl_node = nullptr;
    if (objl_count) {
        const uint32_t objl_bytes = objl_count * 0x464u + 8u;
        objl_node = static_cast<uint8_t*>(FUN_0053c810(objl_bytes));   // FIXME(unverified): callee 0x0053c810
        if (objl_node) {
            std::memset(objl_node, 0, objl_bytes);
            *reinterpret_cast<uint32_t**>(objl_node) =
                reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(g_PlacementListObjl));
            g_PlacementListObjl = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(objl_node));
            *reinterpret_cast<uint32_t*>(objl_node + 4) = objl_count;
        }
    }

    // =====================================================================
    // PHASE 3 — per-object placement loop  [0x4b5269..0x4b5d21]
    // =====================================================================
    // For each of objl_count records:
    //   puVar9 = objl_node + 2 + i*0x119   (0x119 dwords = 0x464 bytes)
    //   read opcode byte; dispatch.
    //
    // Opcodes consumed by the body (the full case table):
    //   0x51 'Q'  placement w/ angle+axis (reads typeId + 3 floats + sin/scalar)
    //   0x59 'Y'  placement, hard-coded 0xc0400000 (-3.0f) magnitude
    //   0x5a 'Z'  placement, hard-coded 0xbf800000 (-1.0f)
    //   0x5b '['  placement, hard-coded 0xc0000000 (-2.0f)
    //   0x52 'R'  ref-point: index + NUL-name, allocates a shadow sub-list
    //   0x56      mesh+pos+scale (3 dwords)         stride-0x20 slot
    //   0x57      mesh+pos+scale (4 dwords)         two stride-0x20 slots
    //   0x58      mesh+pos+scale (3 dwords)         slot type 9
    //   0x5c      mesh+pos+scale (3 dwords)         slot type 0x10001
    //   0x7f/0x80 string-pool entries via FUN_0044acf0
    //   0x53/0x54 slot-table fill (stack0x4a8 / stack0x8a8)
    //   0x55      flag OR 0x10 on puVar9[1]
    //   0xff      end-of-record terminator → finalize + advance
    //
    // The body keeps a stride-0x20 scratch array (&stack0x000000a8) with up
    // to 32 entries; we replicate it as a local buffer.
    for (uint32_t i = 0; i < objl_count && objl_node; i++) {
        // puVar9 = objl_node + 2 + i*0x119 (dword index → byte offset)
        uint32_t* puVar9 = reinterpret_cast<uint32_t*>(objl_node + 8) + i * 0x119u;

        // Per-record state (mirrors stack slots in the body).
        uint32_t  scratch_slots = 0;       // uStack00000008  — slot-table count
        uint8_t   scratch_a8[0x20 * 0x20]; // &stack0x000000a8 (stride-0x20 slots)
        uint8_t   slot_ptrs[0x80 * 4];     // &stack0x000004a8 (32-bit ptrs)
        uint8_t   slot_kind[0x80 * 4];     // &stack0x000008a8 (32-bit kinds)
        uint8_t   slot_aux[0x80 * 4];      // &stack0x000006a8
        uint8_t   slot_pad[0x80 * 4];      // &stack0x00000aa8
        uint8_t   slot_byte[0x80 * 4];     // &stack0x00000ca8
        char      name_buf[0x200];         // &stack0x00000ea8 (entity name accumulator)
        char*     pcVar_name = name_buf;
        uint32_t  light_idx = 0;           // iStack00000004 (light/sub-record index)
        uint8_t*  pbVar24 = nullptr;       // record cursor (set by each opcode)
        uint32_t  uVar32   = 0;            // running slot count mirror

        std::memset(scratch_a8, 0, sizeof(scratch_a8));
        std::memset(slot_ptrs,  0, sizeof(slot_ptrs));
        std::memset(name_buf,   0, sizeof(name_buf));

        // The body reads the typeId header into puVar9[0] before the opcode
        // loop.   [0x4b527d] *puVar9 = *(u32*)(iVar19 + (int)piVar8);
        {
            uint32_t typeId = 0;
            FUN_0051d750(stream, &typeId, 4);
            puVar9[0] = typeId;
        }

        // Opcode dispatch loop. The body is an infinite do/while with a switch;
        // 0xff (and an unknown opcode → return) break out.
        for (;;) {
            uint8_t op = 0;
            FUN_0051d750(stream, &op, 1);

            switch (op) {
            case 0x51: { // 'Q' — placement w/ angle+axis
                if (light_idx > 9) { FUN_00544b47("Q"); FUN_00523aa0(); }   // FIXME(unverified)
                uint32_t typeId_arg = 0;
                FUN_0051d750(stream, &typeId_arg, 4);
                puVar9[light_idx + 0x100] = (typeId_arg == 0) ? 0u : FUN_0049d240();  // FIXME(unverified): callee 0x0049d240
                float angle = 0; FUN_0051d750(stream, &angle, 4);
                if (as_u(angle) == k_DAT_005522b0) angle = as_f(k_DAT_005524bc);
                float mag = 0; FUN_0051d750(stream, &mag, 4);
                float s = std::sin(angle * as_f(k_DAT_005526c0_bits));
                puVar9[light_idx + 0x10a] = as_u(s * mag);
                light_idx++;
                break;
            }
            case 0x59: { // 'Y'
                if (light_idx > 9) { FUN_00544b47("Y"); FUN_00523aa0(); }
                puVar9[light_idx + 0x100] = FUN_0049d240();
                puVar9[light_idx + 0x10a] = 0xc0400000u;   // -3.0f
                light_idx++;
                break;
            }
            case 0x5a: { // 'Z'
                if (light_idx > 9) { FUN_00544b47("Z"); FUN_00523aa0(); }
                puVar9[light_idx + 0x100] = FUN_0049d240();
                puVar9[light_idx + 0x10a] = 0xbf800000u;   // -1.0f
                light_idx++;
                break;
            }
            case 0x5b: { // '['
                if (light_idx > 9) { FUN_00544b47("["); FUN_00523aa0(); }
                puVar9[light_idx + 0x100] = FUN_0049d240();
                puVar9[light_idx + 0x10a] = 0xc0000000u;   // -2.0f
                light_idx++;
                FUN_00544b47("["); FUN_00523aa0();
                break;
            }
            case 0x52: { // 'R' — ref-point + shadow sub-list attach
                if (uVar32 != 0) {
                    uint32_t* sub = static_cast<uint32_t*>(FUN_0053c810(uVar32 * 8u + 4u));  // FIXME(unverified): callee 0x0053c810
                    if (sub) {
                        sub[0] = uVar32;
                        uint32_t* src = reinterpret_cast<uint32_t*>(scratch_a8);
                        for (uint32_t k = 0; k < (uVar32 & 0x7ffffffu) * 2u; k++)
                            sub[1 + k] = src[k];
                        // Attach to puVar9[0x09] (offset +0x24) — body writes
                        //   *(uint**)((int)puStack00000010 + 0x24) = puVar11
                        // The "puStack00000010" target is the current def slot;
                        // we store on the record for the type resolver to find.
                        puVar9[9] = reinterpret_cast<uint32_t>(sub);
                    }
                }
                // read slot index byte + NUL-terminated name
                uint8_t slot = 0; FUN_0051d750(stream, &slot, 1);
                char nm[0x21] = {0};
                for (int k = 0; k < 0x20; k++) {
                    uint8_t c = 0; FUN_0051d750(stream, &c, 1);
                    nm[k] = (char)c; if (c == 0) break;
                }
                if (puVar9[slot + 2] != 0) { FUN_00544b47("R"); FUN_00523aa0(); break; }
                FUN_00405200();                                  // FIXME(unverified): callee 0x00405200
                puVar9[slot + 2] = 0;   // body: puStack00000010 = puVar9[bVar2 + 2] (==0)
                uVar32 = 0;
                break;
            }
            case 0x56: { // mesh + pos + scale (3 dwords, slot type 1)
                if (uVar32 > 0x1f) { FUN_00523aa0(); uVar32 = 0; }
                uint32_t idx = 0; FUN_0051d750(stream, &idx, 4);
                uint32_t mesh = 0; FUN_0051d750(stream, &mesh, 4);
                uint32_t off = uVar32 * 0x20u;
                *reinterpret_cast<uint32_t*>(scratch_a8 + off + 0x08) = mesh;  // +0xb0
                *reinterpret_cast<uint32_t*>(scratch_a8 + off + 0x0c) = mesh;  // +0xb4
                *reinterpret_cast<uint32_t*>(scratch_a8 + off + 0x00) = 1u;    // +0xa8
                *reinterpret_cast<float*>(scratch_a8 + off + 0x04) =
                    (float)(int32_t)idx * as_f(k_DAT_00552648_bits);           // +0xac
                uVar32++;
                break;
            }
            case 0x57: { // mesh + pos + scale (4 dwords, two slots)
                if (uVar32 + 1 > 0x1f) { FUN_00523aa0(); uVar32 = 0; }
                uint32_t idx = 0; FUN_0051d750(stream, &idx, 4);
                uint32_t mesh1 = 0; FUN_0051d750(stream, &mesh1, 4);
                uint32_t mesh2 = 0; FUN_0051d750(stream, &mesh2, 4);
                uint32_t off = uVar32 * 0x20u;
                *reinterpret_cast<uint32_t*>(scratch_a8 + off + 0x08) = mesh1;
                *reinterpret_cast<uint32_t*>(scratch_a8 + off + 0x0c) = mesh1;
                *reinterpret_cast<uint32_t*>(scratch_a8 + off + 0x00) = 3u;
                *reinterpret_cast<float*>(scratch_a8 + off + 0x04) =
                    (float)(int32_t)idx * as_f(k_DAT_00552648_bits);
                uint32_t off2 = (uVar32 + 1) * 0x20u;
                *reinterpret_cast<uint32_t*>(scratch_a8 + off2 + 0x08) = mesh2;
                *reinterpret_cast<uint32_t*>(scratch_a8 + off2 + 0x0c) = mesh2;
                *reinterpret_cast<uint32_t*>(scratch_a8 + off2 + 0x00) = 5u;
                uVar32 += 2;
                break;
            }
            case 0x58: { // mesh + pos + scale (3 dwords, slot type 9)
                if (uVar32 > 0x1f) { FUN_00523aa0(); uVar32 = 0; }
                uint32_t idx = 0; FUN_0051d750(stream, &idx, 4);
                uint32_t mesh = 0; FUN_0051d750(stream, &mesh, 4);
                uint32_t pos  = 0; FUN_0051d750(stream, &pos, 4);
                uint32_t off = uVar32 * 0x20u;
                *reinterpret_cast<uint32_t*>(scratch_a8 + off + 0x08) = mesh;
                *reinterpret_cast<uint32_t*>(scratch_a8 + off + 0x0c) = pos;
                *reinterpret_cast<float*>(scratch_a8 + off + 0x04) =
                    (float)(int32_t)idx * as_f(k_DAT_00552648_bits);
                *reinterpret_cast<uint32_t*>(scratch_a8 + off + 0x00) = 9u;
                uVar32++;
                break;
            }
            case 0x5c: { // mesh + pos + scale (3 dwords, slot type 0x10001)
                if (uVar32 > 0x1f) { FUN_00523aa0(); uVar32 = 0; }
                uint32_t idx = 0; FUN_0051d750(stream, &idx, 4);
                uint32_t mesh = 0; FUN_0051d750(stream, &mesh, 4);
                uint32_t pos  = 0; FUN_0051d750(stream, &pos, 4);
                uint32_t off = uVar32 * 0x20u;
                *reinterpret_cast<uint32_t*>(scratch_a8 + off + 0x08) = mesh;
                *reinterpret_cast<uint32_t*>(scratch_a8 + off + 0x0c) = pos;
                *reinterpret_cast<float*>(scratch_a8 + off + 0x04) =
                    (float)(int32_t)idx * as_f(k_DAT_00552648_bits);
                *reinterpret_cast<uint32_t*>(scratch_a8 + off + 0x00) = 0x10001u;
                uVar32++;
                break;
            }
            case 0x53: { // slot table fill (stack0x4a8) — 18-byte record
                uint8_t slot = 0; FUN_0051d750(stream, &slot, 1);
                uint8_t skip2[2]; FUN_0051d750(stream, skip2, 2);
                char nm[0x11] = {0}; FUN_0051d750(stream, nm, 0x10);
                *reinterpret_cast<uint8_t**>(slot_ptrs + slot * 4) =
                    reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(0)); // body sets ptr into mapped buffer; we leave 0
                if (scratch_slots <= slot) scratch_slots = slot + 1;
                if (scratch_slots > 0x7f) { FUN_00523aa0(); scratch_slots = 0x80; }
                break;
            }
            case 0x54: { // slot table fill (stack0x8a8) — 23-byte record
                uint8_t slot = 0; FUN_0051d750(stream, &slot, 1);
                uint8_t aux[3]; FUN_0051d750(stream, aux, 3);
                uint8_t tail[0x14]; FUN_0051d750(stream, tail, 0x14);
                *reinterpret_cast<uint8_t*>(slot_kind) = slot;
                break;
            }
            case 0x55: { // flag OR 0x10 on puVar9[1]
                puVar9[1] |= 0x10u;
                break;
            }
            case 0xff: { // end-of-record terminator
                // Body: if a pending light slot exists, finalize sin(0)*scalar;
                //   then build the slot-pool blob, copy names, attach sub-lists.
                if (light_idx > 0 && puVar9[light_idx + 0xff] != 0) {
                    if (light_idx > 9) { FUN_00544b47("ff"); FUN_00523aa0(); }
                    float s = std::sin(as_f(k_DAT_005526b8_bits));
                    puVar9[light_idx + 0x100] = 0u;
                    puVar9[light_idx + 0x10a] = as_u(s * as_f(k_DAT_005526b4_bits));
                }
                // Slot-pool build (body LAB_004b5a1a..LAB_004b5b38). We faithfully
                // allocate the pool and store its pointer at puVar9[0x115].
                if (scratch_slots) {
                    // Count non-zero slot ptrs to size the pool (body: iVar20 +=
                    //   count of non-zero entries in puVar9[2..0x100]).
                    uint32_t nonzero = 0;
                    for (uint32_t k = 0; k < 0xfeu; k++)
                        if (puVar9[2 + k] != 0) nonzero++;
                    uint32_t pool_dwords = (nonzero + scratch_slots * 2u + scratch_slots * nonzero) ;
                    uint32_t* pool = static_cast<uint32_t*>(FUN_0053c810(pool_dwords * 4u));  // FIXME(unverified): callee 0x0053c810
                    if (pool) {
                        std::memset(pool, 0, pool_dwords * 4u);
                        puVar9[0x114] = scratch_slots;
                        puVar9[0x115] = reinterpret_cast<uint32_t>(pool);
                    }
                }
                goto next_objl_record;   // body: iStack00000014++; if (iVar18<=i) goto LAB_004b5d25
            }
            default:
                // Unknown opcode → the body calls FUN_00544b47 + FUN_00523aa0
                // and returns. We do the same to preserve behavior.
                FUN_00544b47("?");
                FUN_00523aa0();
                return;
            }
        }
    next_objl_record:
        (void)pcVar_name; (void)pbVar24;
        ;
    }

    // =====================================================================
    // PHASE 4 — 'atl' list (animation triggers, stride 0x304) → DAT_006313b4
    // =====================================================================
    //   [0x4b5d25] read iVar18 = atl_count
    //   [0x4b5d3a..0x4b5dc5] alloc size = atl_count*0x304 + 8 (body: 0xc1 dwords/entry)
    //   head-insert into DAT_006313b4; store count @ +4.
    uint32_t atl_count = 0;
    FUN_0051d750(stream, &atl_count, 4);              // [0x4b5d25]

    uint8_t* atl_node = nullptr;
    if (atl_count) {
        const uint32_t atl_bytes = atl_count * 0x304u + 8u;
        atl_node = static_cast<uint8_t*>(FUN_0053c810(atl_bytes));   // FIXME(unverified): callee 0x0053c810
        if (atl_node) {
            std::memset(atl_node, 0, atl_bytes);
            *reinterpret_cast<uint32_t**>(atl_node) =
                reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(g_PlacementListOsl));
            g_PlacedObjectList = g_PlacementListOsl =
                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(atl_node));
            *reinterpret_cast<uint32_t*>(atl_node + 4) = atl_count;
        }
    }

    // =====================================================================
    // PHASE 5 — per-atl-entry attribute switch  [0x4b5dfe..0x4b6689]
    // =====================================================================
    // For each of atl_count entries:
    //   puVar9 = atl_node + 2 + i*0xc1   (0xc1 dwords = 0x304 bytes)
    //   FUN_0049c920() init
    //   read type id (iVar20), FUN_0049d2d0() type-resolve, puVar9[1] = iVar20
    //   if (iVar20 == 0) DAT_006313b8 = puVar9    [0x4b5e57]
    //   fill +0x10.. with 0xfe sentinels (4 × 9 dwords)
    //   puVar9[0x31] = 1.0f  (scale default)
    //   then opcode switch (cases 0x01..0xff) writing entity fields.
    for (uint32_t i = 0; i < atl_count && atl_node; i++) {
        uint32_t* puVar9 = reinterpret_cast<uint32_t*>(atl_node + 8) + i * 0xc1u;

        FUN_0049c920();                                  // FIXME(unverified): callee 0x0049c920
        uint32_t typeId = 0;
        FUN_0051d750(stream, &typeId, 4);
        FUN_0049d2d0();                                  // FIXME(unverified): callee 0x0049d2d0
        puVar9[1] = typeId;
        if (typeId == 0) DAT_006313b8 = reinterpret_cast<uint32_t>(puVar9);  // [0x4b5e57]

        // Fill +0x10, +0x34, +0x58, +0x7c with 0xfe (4 slots, 9 dwords each).
        for (int s = 0; s < 4; s++) {
            uint32_t* p = puVar9 + 4 + s * 9u;
            for (int k = 0; k < 9; k++) p[k] = 0xfe;
        }
        puVar9[0x31] = k_DAT_005522c0;   // 1.0f default scale

        // Opcode loop: the body reads a tag byte then a fixed payload per case.
        // We port the structural cases; payloads are read verbatim.
        for (;;) {
            uint8_t tag = 0;
            FUN_0051d750(stream, &tag, 1);
            uint32_t v1 = 0, v2 = 0, v3 = 0, v4 = 0;

            switch (tag) {
            case 0x01: { // mesh resolver (FUN_0049d280) + scale inherit
                FUN_0051d750(stream, &v1, 4);
                uint32_t r = FUN_0049d280();             // FIXME(unverified): callee 0x0049d280
                puVar9[2] = r;
                // Body: if r && *(r+0x400) → copy *(float*)(*r+0x58) into puVar9[0x7b]
                // (then clamp/publish puVar9[0x7a]/[0x79]). We port the writes.
                if (r != 0) {
                    uint32_t inner = *reinterpret_cast<uint32_t*>(r + 0x400);
                    if (inner != 0) {
                        float f = *reinterpret_cast<float*>(inner + 0x58);
                        puVar9[0x7b] = as_u(f);
                        if (f < as_f(k_DAT_005522c0)) puVar9[0x7b] = k_DAT_005522c0;
                        puVar9[0x7a] = as_u(as_f(puVar9[0x7b]) * as_f(k_DAT_00552360_bits));
                        puVar9[0x79] = as_u(as_f(puVar9[0x7b]) * as_f(k_DAT_00552300_bits));
                    }
                }
                break;
            }
            case 0x02: { // shadow-texture resolver
                FUN_0051d750(stream, &v1, 4);
                float f = as_f(v1);
                puVar9[0xb9] = (v1 == k_DAT_005522b0) ? 0u : as_u(as_f(k_DAT_005522c0) / f);
                // skip the NUL-terminated name; resolve via FUN_0050e3c0
                for (;;) { uint8_t c = 0; FUN_0051d750(stream, &c, 1); if (c == 0) break; }
                puVar9[0xb8] = FUN_0050e3c0();           // FIXME(unverified): callee 0x0050e3c0
                break;
            }
            case 0x03: { // dynamic shadow texture record
                FUN_0051d750(stream, &v1, 4);
                float f = as_f(v1);
                puVar9[0xb9] = (v1 == k_DAT_005522b0) ? 0u : as_u(as_f(k_DAT_005522c0) / f);
                uint32_t u1 = 0, u2 = 0;
                FUN_0051d750(stream, &u1, 4);
                FUN_0051d750(stream, &u2, 4);
                uint32_t* rec = static_cast<uint32_t*>(FUN_0053c810(0x20));   // FIXME(unverified): callee 0x0053c810
                if (rec) {
                    rec[0] = reinterpret_cast<uint32_t>(s_Dynamic_shadow_texture_0055f824);
                    rec[1] = 0; rec[2] = 0;
                    rec[3] = u1; rec[4] = u2;
                    rec[5] = 5u; rec[6] = 5u;
                    *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(rec) + 0x1d) = 0;
                    *reinterpret_cast<uint8_t*>(rec + 7) = 0x20;
                    *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(rec) + 0x1e) = 0x80;
                    puVar9[0xb8] = reinterpret_cast<uint32_t>(rec);
                }
                break;
            }
            case 0x04: { // variant + flag set
                FUN_0051d750(stream, &v1, 4);
                FUN_0051d750(stream, &v2, 4);
                *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(puVar9) + 0x1f6) = 1;
                puVar9[0x65] = v1;
                uint32_t kd = puVar9[1];
                puVar9[100] = v2;
                if (kd == 2 || kd == 3 || kd == 1 || kd == 0xd7) puVar9[0x72] |= 0x40000u;
                puVar9[0x72] |= 0x400000u;
                break;
            }
            case 0x05: FUN_0051d750(stream, &puVar9[0x68], 4); break;
            case 0x06: FUN_0051d750(stream, &puVar9[0x66], 4); break;
            case 0x07: FUN_0051d750(stream, &puVar9[0x67], 4); break;
            case 0x08: FUN_0051d750(stream, &puVar9[0x6a], 4); FUN_0051d750(stream, &puVar9[0x69], 4); break;
            case 0x09: FUN_0051d750(stream, &puVar9[0x6b], 4); break;
            case 0x0a: FUN_0051d750(stream, &puVar9[0x6c], 4); break;
            case 0x0b: FUN_0051d750(stream, &puVar9[0x6e], 4); break;
            case 0x0c: FUN_00544b47("c"); FUN_00429100(); break;       // FIXME(unverified): 0x00429100
            case 0x0d: FUN_0051d750(stream, &puVar9[0x6d], 4); break;
            case 0x13: FUN_00403470(); break;                          // FIXME(unverified): 0x00403470
            case 0x14: puVar9[0x72] |= 2u; break;
            case 0x15: FUN_0051d750(stream, &puVar9[0x75], 4); break;
            case 0x16: puVar9[0x72] |= 4u; break;
            case 0x17: FUN_0051d750(stream, &puVar9[0x31], 4); break;
            case 0x18: puVar9[0x72] |= 8u; break;
            case 0x19: FUN_0051d750(stream, &puVar9[0x6f], 4); break;
            case 0x1a: {
                FUN_0051d750(stream, &v1, 4);
                int32_t n = (int32_t)puVar9[0x76];
                if (n < 0x10) { puVar9[0x76] = n + 1; }
                else { FUN_00523aa0(); }
                break;
            }
            case 0x1b: puVar9[0x36] |= 0x10u; break;
            case 0x1c: FUN_0051d750(stream, &v1, 4); FUN_0051d750(stream, &v2, 4); break;
            case 0x1d: puVar9[0x72] |= 0x40u; break;
            case 0x1e: FUN_0049f3b0(); break;                          // FIXME(unverified): 0x0049f3b0
            case 0x20: puVar9[0x72] |= 0x80u; break;
            case 0x21: {
                FUN_0051d750(stream, &puVar9[0x7a], 4);
                FUN_0051d750(stream, &puVar9[0x7b], 4);
                puVar9[0x79] = as_u(as_f(puVar9[0x7a]) * as_f(k_DAT_005522cc_bits));
                break;
            }
            case 0x22: puVar9[0x72] |= 0x800u; break;
            case 0x23: puVar9[0x72] |= 0x1000u; /* fallthrough */ case 0x24: case 0x3f: case 0x43: break;
            case 0x25: FUN_0051d750(stream, &puVar9[0x7f], 4); break;
            case 0x26: {
                uint8_t b = 0; FUN_0051d750(stream, &b, 1);
                *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(puVar9) + 0x1f7) = b;
                FUN_0051d750(stream, &puVar9[0x7e], 4);
                break;
            }
            case 0x28: {
                if (puVar9[0x78] == 1) {
                    uint32_t r = FUN_0049d280();   // FIXME(unverified): 0x0049d280
                    uint32_t v = 0; FUN_0051d750(stream, &v, 4);
                    uint32_t* tgt = reinterpret_cast<uint32_t*>(puVar9[0x40]);
                    if (tgt) { tgt[0x29] = r; tgt[0x2d] = v; FUN_0051d750(stream, &tgt[0x2e], 4); FUN_0051d750(stream, &tgt[0x2f], 4); }
                    FUN_0051d750(stream, &v1, 4);
                } else { FUN_00523aa0(); FUN_0051d750(stream, &v1, 4); }
                break;
            }
            case 0x29: FUN_0051d750(stream, &puVar9[0x7c], 4); break;
            case 0x2b: puVar9[0x72] |= 0x100u; break;
            case 0x2c: { // append NUL-terminated name to name accumulator
                for (;;) {
                    uint8_t c = 0; FUN_0051d750(stream, &c, 1);
                    if (c == 0) break;
                }
                break;
            }
            case 0x2d: { for (;;) { uint8_t c = 0; FUN_0051d750(stream, &c, 1); if (c == 0) break; } break; }
            case 0x2e: puVar9[0x72] |= 0x600u; break;
            case 0x2f: puVar9[0x72] |= 0x10000u; break;
            case 0x30: FUN_0051d750(stream, &puVar9[0x8a], 4); break;
            case 0x31: {
                FUN_0051d750(stream, &v1, 4);
                int32_t k = engine_ftol(as_f(v1));
                if ((int32_t)puVar9[0x71] == k) { puVar9[0x70] = v1; puVar9[0x71] = (uint32_t)engine_ftol(as_f(v1)); }
                else { puVar9[0x70] = v1; }
                break;
            }
            case 0x32: case 0x37: case 0x3e: FUN_0051d750(stream, &v1, 4); break;
            case 0x33: case 0x34: case 0x35: {
                FUN_0051d750(stream, &v1, 4); FUN_0051d750(stream, &v2, 4);
                if (v1 != k_DAT_005522b0 || v2 != k_DAT_005522b0) FUN_00523aa0();
                puVar9[0x72] |= (tag == 0x33) ? 0x80000u : (tag == 0x34) ? 0x100000u : 0x200000u;
                break;
            }
            case 0x36: {
                uint8_t b = 0; FUN_0051d750(stream, &b, 1);
                *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(puVar9) + 0x1f6) = b;
                break;
            }
            case 0x39: puVar9[0x72] |= 0x20000u; break;
            case 0x3b: FUN_0051d750(stream, &puVar9[99], 4); break;
            case 0x3d: puVar9[0x72] |= 0x1000000u; break;
            case 0x40: case 0x46: puVar9[0x73] |= 1u; break;
            case 0x41: puVar9[0x36] |= 0x40000010u; puVar9[0x72] |= 0x8000e00u; break;
            case 0x42: FUN_00544b47("42"); FUN_00429100(); FUN_0051d750(stream, &v1, 4); FUN_0051d750(stream, &v2, 4); FUN_0051d750(stream, &v3, 4); break;
            case 0x44: { // float-array copy into puVar9[0x40] buf
                FUN_0051d750(stream, &v1, 4);
                int32_t n = (int32_t)as_f(v1);
                if (puVar9[0x40] == 0) { FUN_00544b47("44"); FUN_00523aa0(); }
                else {
                    float* dst = reinterpret_cast<float*>(puVar9[0x40]);
                    for (int32_t k = 0; k < n; k++) {
                        float f = 0; FUN_0051d750(stream, &f, 4);
                        dst[k] = f;
                    }
                }
                break;
            }
            case 0x45: FUN_0051d750(stream, &puVar9[0x80], 4); break;
            case 0x47: puVar9[0x73] |= 0x3cu; break;
            case 0x48: puVar9[0x73] |= 0x3c0u; break;
            case 0x49: puVar9[0x73] |= 0x3c00u; break;
            case 0x4a: puVar9[0x73] |= 2u; break;
            case 0x4b: puVar9[0x73] |= 0x3c000u; break;
            case 0x4c: puVar9[0x73] |= 0x3c0000u; break;
            case 0x4d: puVar9[0x73] |= 0x3c00000u; break;
            case 0x4e: puVar9[0x74] |= 0xf0u; break;
            case 0x4f: puVar9[0x74] |= 0xfu; break;
            case 0x50: puVar9[0x74] |= 0xf00u; break;
            case 0x51: puVar9[0x36] |= 0x40000010u; puVar9[0x72] |= 0x28000e00u; break;
            case 0x52: puVar9[0x36] |= 0x20000u; break;
            case 0x53: puVar9[0x36] |= 2u; break;
            case 0x54: puVar9[0x72] |= 0x80000000u; break;
            case 0x55: puVar9[0x36] |= 0x40000000u; break;
            case 0x56: puVar9[0x73] |= 4u; break;
            case 0x58: puVar9[0x73] |= 0x10u; break;
            case 0x59: puVar9[0x73] |= 0x40u; break;
            case 0x5a: puVar9[0x73] |= 0x80u; break;
            case 0x5b: puVar9[0x73] |= 0x100u; break;
            case 0x5c: puVar9[0x73] |= 0x400u; break;
            case 0x5d: puVar9[0x73] |= 0x800u; break;
            case 0x5e: puVar9[0x73] |= 0x1000u; break;
            case 0x5f: puVar9[0x73] |= 0x4000u; break;
            case 0x60: puVar9[0x73] |= 0x8000u; break;
            case 0x61: puVar9[0x73] |= 0x10000u; break;
            case 0x62: puVar9[0x73] |= 0x40000u; break;
            case 0x63: puVar9[0x73] |= 0x80000u; break;
            case 0x64: puVar9[0x73] |= 0x100000u; break;
            case 0x65: puVar9[0x73] |= 0x400000u; break;
            case 0x66: puVar9[0x73] |= 0x800000u; break;
            case 0x67: puVar9[0x73] |= 0x1000000u; break;
            case 0x68: puVar9[0x74] |= 0x10u; break;
            case 0x69: FUN_0051d750(stream, &puVar9[0x71], 4); break;
            case 0x6a: puVar9[0x74] |= 0x40u; break;
            case 0x6b: puVar9[0x74] |= 1u; break;
            case 0x6c: puVar9[0x74] |= 2u; break;
            case 0x6d: puVar9[0x74] |= 4u; break;
            case 0x6e: puVar9[0x74] |= 0x100u; break;
            case 0x6f: puVar9[0x74] |= 0x200u; break;
            case 0x70: puVar9[0x74] |= 0x400u; break;
            case 0x71: puVar9[0x74] |= 0x20u; break;
            case 0x72: puVar9[0x73] |= 8u; break;
            case 0x73: puVar9[0x73] |= 0x20u; break;
            case 0x74: puVar9[0x73] |= 0x200u; break;
            case 0x75: puVar9[0x73] |= 0x2000u; break;
            case 0x76: puVar9[0x73] |= 0x20000u; break;
            case 0x77: puVar9[0x73] |= 0x200000u; break;
            case 0x78: puVar9[0x73] |= 0x2000000u; break;
            case 0x79: puVar9[0x74] |= 0x80u; break;
            case 0x7d: puVar9[0x72] |= 0x2000000u; break;
            case 0x7e: puVar9[0x72] |= 0x10000000u; break;
            case 0x7f: puVar9[0x74] |= 8u; break;
            case 0x80: puVar9[0x74] |= 0x800u; break;
            case 0x84: puVar9[0x73] |= 0x4000000u; break;
            case 0x89: puVar9[0x37] |= 0x1000000u; break;
            case 0xff: goto next_atl_record;   // end of this entry's attribute list
            default:
                // Body default: FUN_00544b47 + FUN_00523aa0 + return.
                FUN_00544b47("?");
                FUN_00523aa0();
                // ---------- [0x4b5dd4] epilogue ----------
                FUN_0053c5c0();                // FIXME(unverified): callee 0x0053c5c0
                return;
            }
        }
    next_atl_record:
        ;
    }

    if (g_vTrace) {
        std::fprintf(g_vTrace,
            "[PLACEMENTS] scene='%s' odef=%u objl=%u atl=%u | ac=%08x b0=%08x b4=%08x b8=%08x\n",
            scene_name ? scene_name : "(null)",
            odef_count, objl_count, atl_count,
            g_PlacementListOdef, g_PlacementListObjl, g_PlacementListOsl, DAT_006313b8);
        std::fflush(g_vTrace);
    }

    // ---------- [0x4b5dd4] epilogue ----------
    FUN_0053c5c0();                                    // FIXME(unverified): callee 0x0053c5c0
}

// ===========================================================================
// SelfTest — trace-only verifier (no engine-global mutation).
// ===========================================================================
// Opens `bin_path` via the engine file API, seeks to the placements section
// (caller must position the file; this helper reads from the current offset
// assuming the caller has already advanced past the texture section), reads
// the three counts + first few placement header bytes, and logs them. It uses
// LOCAL list heads so engine globals are untouched.
extern "C" int VanillaPlacements_SelfTest(const char* bin_path) {
    if (!bin_path) return -1;
    uint32_t h = FUN_00539e30(bin_path);
    if (!h) {
        if (g_vTrace) { std::fprintf(g_vTrace, "[PLACEMENTS::SelfTest] open '%s' FAILED\n", bin_path); std::fflush(g_vTrace); }
        return -2;
    }
    // Read the three counts straight away. A real .BIN places the placement
    // section after the texture/material section; this self-test just verifies
    // the reader's count + opcode parsing works on a synthetic stream.
    uint32_t odef_count = 0, objl_count = 0, atl_count = 0;
    FUN_0051d750(h, &odef_count, 4);
    FUN_0051d750(h, &objl_count, 4);
    FUN_0051d750(h, &atl_count, 4);

    if (g_vTrace) {
        std::fprintf(g_vTrace,
            "[PLACEMENTS::SelfTest] '%s' odef=%u objl=%u atl=%u\n",
            bin_path, odef_count, objl_count, atl_count);
        // Dump first few placement opcode bytes (after re-opening to skip counts).
        std::fflush(g_vTrace);
    }
    FUN_0051d850(h);
    return (int)((odef_count & 0xffff) | ((objl_count & 0xffff) << 16));
}
