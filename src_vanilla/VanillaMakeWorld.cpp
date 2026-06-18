// Giants Vanilla-Native Recomp — FUN_00476d40 (makewrld.c) world/terrain builder.
//
// Faithful 1:1 port of vanilla Giants.exe's FUN_00476d40 (3216 bytes).
// Sourced ENTIRELY from vanilla_decompiled/00476d40.json (Ghidra body).
// No custom logic, no invented code — every field write, the version switch,
// the bbox loop, the float math, the cell decode, and the stencil scan are
// translated verbatim. See VanillaMakeWorld.h for the structural overview.
//
// Anti-derivation: each non-obvious line cites the source JSON line / address.
#include "VanillaMakeWorld.h"

#include <cstdint>
#include <cstring>

// ============================================================================
// Globals (world_state + scratch + 1.0f). These are defined elsewhere; we only
// extern-reference them. VanillaStubs.cpp / VanillaSceneLists.cpp hold the
// authoritative definitions; we add scratch/string globals to be safe below.
// ============================================================================
// DAT_006316ec — world/game-state pointer (g_WorldState). Same global that
// VanillaSceneLists.cpp / VanillaStubs.cpp define; we extern it here.
extern "C" uint32_t DAT_006316ec;   // = g_WorldState

// DAT_0059cc40 — 0x200-byte scratch buffer allocated at entry. VanillaStubs
// does NOT currently define this one; we declare it extern and rely on a
// single definition elsewhere (see note at the bottom of this file for the
// fallback definition if no other TU provides it).
extern "C" uint32_t* DAT_0059cc40;

// _DAT_005522c0 — 1.0f constant (float). Defined in VanillaBinStubs.cpp as
// uint32_t _DAT_005522c0 = 0; (we read it as float). Extern here.
extern "C" uint32_t _DAT_005522c0;

// ============================================================================
// String / file-tag literals referenced by the body. We declare them as
// extern "C" const char[] so they link to a single definition; if no other TU
// defines them yet, see the definitions at the bottom of this file.
// ============================================================================
extern "C" const char s_C__Giants_Source_main_makewrld_c_0055d974[]; // "C:\\Giants\\Source\\main\\makewrld.c"
extern "C" const char s_wbboxes_0055d9f4[];                          // "wbboxes"
extern "C" const char s_Bad_version_for_world_data_0055d9fc[];       // "Bad version for world data"
extern "C" const char s_World_0055d9ec[];                            // "World"
extern "C" const char s_YROWS_0055d9e4[];                            // "YROWS"
extern "C" const char s_ground_bump_texture_0055d960[];              // "ground bump texture"
// Bare-DAT string tags: DAT_0055d9e0 / DAT_0055d9dc are passed by ADDRESS
// (not by name) to FUN_0053c810 — vanilla just leaks whatever bytes live at
// those addresses into the allocator's tag slot. We expose them as 4-byte
// extern blobs so we can take their address verbatim.
extern "C" const uint8_t DAT_0055d9e0[4];
extern "C" const uint8_t DAT_0055d9dc[4];

// DAT_0055da18 — heap-tag blob (allocator cookie) passed by ADDRESS to
// FUN_0053c810 when allocating the 0x200-byte scratch buffer.
extern "C" uint8_t DAT_0055da18[];

// ============================================================================
// Callees not yet ported — declared extern "C" + called verbatim. Each is
// tagged // FIXME(unverified): callee <addr>.
// ============================================================================
// FIXME(unverified): callee 0x0053c810 — allocator (heapId, size, tag, file, line) -> ptr
extern "C" void* FUN_0053c810(uint32_t heapId, uint32_t size, const void* tag,
                              const char* file, int line);
// FIXME(unverified): callee 0x0053a3e0 — load world_data (levelName, &outStream, &outOk)
extern "C" void FUN_0053a3e0(const char* levelName, int** outStream, int* outOk);
// FIXME(unverified): callee 0x0053a3c0 — free world_data stream
extern "C" void FUN_0053a3c0(int* stream);
// FIXME(unverified): callee 0x00523aa0 — assertion/error print (msg)
extern "C" void FUN_00523aa0(const char* msg);
// FIXME(unverified): callee 0x005236f0 — fatal/abort (no args)
extern "C" void FUN_005236f0(void);
// FIXME(unverified): callee 0x0050e3c0 — texture lookup by name -> handle (0 = miss)
extern "C" uint32_t FUN_0050e3c0(const void* texName);
// FIXME(unverified): callee 0x0050e3a0 — texture release (tex)
extern "C" void FUN_0050e3a0(uint32_t tex);
// FIXME(unverified): callee 0x00458ab0 — compute terrain vertex world position (x, y, outVec3)
extern "C" void FUN_00458ab0(int x, int y, void* outVec3);
// FIXME(unverified): callee 0x00454620 — cross-product (a, b, c, outNormal)
extern "C" void FUN_00454620(const void* a, const void* b, const void* c, void* outNormal);
// FIXME(unverified): callee 0x004778f0 — normalize packed normal -> short
extern "C" short FUN_004778f0(void* normal);
// FIXME(unverified): callee 0x004768e0 — terrain visibility test (uses local struct, no args)
//   Reads the local_34/local_30/iStack_2c/iStack_28/iStack_24/local_20 packed
//   block built in the caller. We replicate the struct verbatim below.
extern "C" int FUN_004768e0(void);
// FIXME(unverified): callee 0x00436960 — post-build world init (no args)
extern "C" void FUN_00436960(void);

// ============================================================================
// Helpers: typed load/store on a raw world_state pointer (kept as uint8_t* so
// the offsets in the JSON match exactly — no struct layout drift).
// ============================================================================
static inline int32_t  ld_i32 (const void* base, uint32_t off) {
    int32_t v; std::memcpy(&v, (const uint8_t*)base + off, 4); return v;
}
static inline uint32_t ld_u32 (const void* base, uint32_t off) {
    uint32_t v; std::memcpy(&v, (const uint8_t*)base + off, 4); return v;
}
static inline float    ld_f32 (const void* base, uint32_t off) {
    float v; std::memcpy(&v, (const uint8_t*)base + off, 4); return v;
}
static inline void st_i32(void* base, uint32_t off, int32_t v) {
    std::memcpy((uint8_t*)base + off, &v, 4);
}
static inline void st_u32(void* base, uint32_t off, uint32_t v) {
    std::memcpy((uint8_t*)base + off, &v, 4);
}
static inline void st_f32(void* base, uint32_t off, float v) {
    std::memcpy((uint8_t*)base + off, &v, 4);
}

// Magic constants for the world_data version switch (Ghidra: -0x6b69afff and
// friends). Kept as the raw int32 literals the body compares against.
#define WORLD_VER_4ec4  (-0x6b69afff)   // == 0x94965001; oldest, no bbox count
#define WORLD_VER_4ec8  (-0x6b69affe)   // == 0x94965002; bbox count present
#define WORLD_VER_4ecc  (-0x6b69affd)   // == 0x94965003; bbox count present

// ============================================================================
// FUN_00476d40 — the world/terrain builder.
// ============================================================================
extern "C" void FUN_00476d40(const char* param_1) {
    // -- locals: mapped 1:1 from the Ghidra body. --
    float    fVar1;
    int      iVar12, iVar13, iVar17, iVar19, iVar21;
    int      iVar4;
    int*     piVar5;
    int*     piVar15;
    int*     piVar16;
    uint32_t uVar6;
    uint32_t* puVar7;
    uint32_t* puVar8;
    uint32_t* puVar20;
    char     cVar11;
    uint8_t* puVar9;   // used as both char* and void* in the body
    uint8_t* puVar14 = nullptr;   // packed-color dest (vanilla local; FIXME if type differs)
    uint8_t* puVar10;
    uint16_t* puVar18;
    int      local_84;
    // 4-byte packed locals that the body aliases heavily (CONCAT31/CONCAT12
    // etc.). We use a 16-byte buffer so this same storage can ALSO be used
    // as the 12-byte vec3 write target in Phase 14 (FUN_00458ab0(...,&local_7c)
    // writes 12 bytes starting at &local_7c in vanilla — that spills into
    // uStack_7b/cStack_7a/uStack_79/local_70, which is exactly the aliasing
    // we preserve by reserving 16 bytes here).
    struct { uint32_t u32; uint8_t pad[12]; } local_7c_u;
    #define local_7c   (reinterpret_cast<uint8_t&>(local_7c_u.u32))
    #define uStack_7b  (*reinterpret_cast<uint8_t*>((uintptr_t)&local_7c_u.u32 + 1))
    #define cStack_7a  (*reinterpret_cast<char*>((uintptr_t)&local_7c_u.u32 + 2))
    #define uStack_79  (*reinterpret_cast<uint8_t*>((uintptr_t)&local_7c_u.u32 + 3))
    uint8_t  local_70[16];                              // vec3 normal scratch (local_70)
    int*     local_60;                                  // world_data stream head (out of FUN_0053a3e0)
    uint8_t  local_5c[12];                              // vec3 vertex (x,   y)
    uint8_t  local_50[12];                              // vec3 vertex (x+1, y+1)
    uint8_t  local_44[12];                              // vec3 vertex (x+1, y)
    union { uint32_t u32; uint8_t b[4]; } local_38_u;   // local_38/uStack_37 (CONCAT31)
    #define _local_38  local_38_u.u32
    #define uStack_37  local_38_u.b[1]
    int      local_34;
    int      local_30;
    int      iStack_2c;
    int      iStack_28;
    int      iStack_24;
    int      local_20[5];
    uint8_t* local_c;
    int      local_8;
    int      local_4;

    // ------------------------------------------------------------------
    // Phase 1: allocate + zero the 0x200-byte scratch buffer at DAT_0059cc40.
    //   DAT_0059cc40 = FUN_0053c810(0x12, 0x200, &DAT_0055da18,
    //                               s_C__Giants_Source_main_makewrld_c_0055d974, 0x20e);
    //   for (iVar12 = 0x80; iVar12 != 0; iVar12--)
    //       *puVar8++ = 0;     // 0x80 dwords = 0x200 bytes
    // Note: DAT_0055da18 is a heap-tag blob (allocator cookie). We pass its
    // address verbatim via reinterpret_cast so the call is identical.
    // ------------------------------------------------------------------
    DAT_0059cc40 = (uint32_t*)FUN_0053c810(
        0x12, 0x200, (const void*)DAT_0055da18,
        s_C__Giants_Source_main_makewrld_c_0055d974, 0x20e);
    puVar8 = DAT_0059cc40;
    for (iVar12 = 0x80; iVar12 != 0; iVar12--) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
    }

    // ------------------------------------------------------------------
    // Phase 2: load world_data stream via FUN_0053a3e0(levelName, &stream, &ok).
    //   FUN_0053a3e0(param_1, &local_60, &local_34);
    //   if (local_34 == 0) return;            // load failed
    // ------------------------------------------------------------------
    FUN_0053a3e0(param_1, &local_60, &local_34);
    if (local_34 == 0) {
        return;
    }

    uint8_t* W = (uint8_t*)(uintptr_t)DAT_006316ec;   // world_state base

    // ------------------------------------------------------------------
    // Phase 3: version switch. First int of the stream is the magic.
    //   iVar12 = *local_60;  piVar15 = local_60 + 1;
    //   switch (iVar12) {
    //     case -0x6b69afff:  W+0x204 = 0;                              break;
    //     case -0x6b69affe:
    //     case -0x6b69affd:  W+0x204 = *piVar15;  piVar15 = local_60+2; break;
    //     default:           FUN_00523aa0("Bad version for world data");
    //                        FUN_005236f0();  return;
    //   }
    // ------------------------------------------------------------------
    iVar12 = *local_60;
    piVar15 = local_60 + 1;
    if (iVar12 == WORLD_VER_4ec4) {
        st_u32(W, 0x204, 0);
    } else {
        if (iVar12 != WORLD_VER_4ec8 && iVar12 != WORLD_VER_4ecc) {
            FUN_00523aa0(s_Bad_version_for_world_data_0055d9fc);
            FUN_005236f0();
            return;
        }
        iVar12 = *piVar15;
        piVar15 = local_60 + 2;
        st_i32(W, 0x204, iVar12);
    }

    // ------------------------------------------------------------------
    // Phase 4: bounding-box array. count = W+0x204, array = W+0x208,
    //   stride 0x38. Each bbox on disk = 8 ints (4 dwords copied inline in
    //   the 8-iteration loop) + 6 ints (piVar5[8..0xd]) copied into the
    //   tail of the 0x38 stride. The Ghidra body writes the tail fields
    //   using negative offsets from the NEXT slot's iVar21:
    //     *(W+0x208 + iVar21 - 0x18) = piVar5[8]
    //     *(W+0x208 + iVar21 - 0x14) = piVar5[9]
    //     ... piVar5[0xa], [0xb], [0xc], [0xd] at -0x10/-0xc/-8/-4.
    //   iVar21 then advances by 0x38 (= one stride), so the tail writes
    //   land at offsets +0x20..+0x34 of the CURRENT slot.
    // ------------------------------------------------------------------
    if (ld_i32(W, 0x204) == 0) {
        st_u32(W, 0x208, 0);
    } else {
        uVar6 = (uint32_t)(uintptr_t)FUN_0053c810(
            0x12, (uint32_t)(ld_i32(W, 0x204) * 0x38),
            (const void*)s_wbboxes_0055d9f4,
            s_C__Giants_Source_main_makewrld_c_0055d974, 0x234);
        st_u32(W, 0x208, uVar6);

        iVar12 = 0;
        if (0 < ld_i32(W, 0x204)) {
            iVar21 = 0;
            piVar5 = piVar15;
            do {
                piVar15 = piVar5;
                piVar16 = (int*)(uintptr_t)(ld_u32(W, 0x208) + iVar21);
                // 8 inline dwords (slot+0x00..0x1c)
                for (iVar17 = 8; iVar17 != 0; iVar17--) {
                    *piVar16 = *piVar15;
                    piVar15  = piVar15 + 1;
                    piVar16  = piVar16 + 1;
                }
                iVar21 = iVar21 + 0x38;
                // tail 6 dwords (slot+0x20..0x34), written via the negative
                // offsets from the NEXT slot's base (= current slot's tail).
                *(int*)(uintptr_t)(ld_u32(W, 0x208) + (iVar21 - 0x18)) = piVar5[8];
                *(int*)(uintptr_t)(ld_u32(W, 0x208) + (iVar21 - 0x14)) = piVar5[9];
                piVar15 = piVar5 + 0xe;
                iVar12  = iVar12 + 1;
                *(int*)(uintptr_t)(ld_u32(W, 0x208) + (iVar21 - 0x10)) = piVar5[10];
                *(int*)(uintptr_t)(ld_u32(W, 0x208) + (iVar21 - 0x0c)) = piVar5[0xb];
                *(int*)(uintptr_t)(ld_u32(W, 0x208) + (iVar21 - 0x08)) = piVar5[0xc];
                *(int*)(uintptr_t)(ld_u32(W, 0x208) + (iVar21 - 0x04)) = piVar5[0xd];
                piVar5 = piVar15;
            } while (iVar12 < ld_i32(W, 0x204));
        }
    }

    // ------------------------------------------------------------------
    // Phase 5: terrain dims + origin copy. piVar15 points at the next block
    //   of 0xe ints in the stream. Copy the first 7 into W+0x1cc..W+0x1e0
    //   (terrain dims/origin), the 7th into W+0x1c4 (cell-size denom for the
    //   stretch), then re-read fields 5/6/7 as floats and apply:
    //     W+0x1c8 = _DAT_005522c0 / W+0x1c4;          // 1.0f / cellSize
    //     W+0x1cc = W+0x1cc - W+0x1c4;                // origin.x -= cellSize
    //     W+0x1d0 = W+0x1d0 - W+0x1c4;                // origin.y -= cellSize
    //     W+0x1dc = W+0x1dc + 2;                       // (terrain width+2)
    //     W+0x1e0 = W+0x1e0 + 2;                       // (terrain height+2)
    //   NOTE: fields 5/6 (W+0x1e0, W+0x1c4) are written first as RAW int
    //   copies from the stream, THEN re-typed as float for the math.
    // ------------------------------------------------------------------
    st_i32(W, 0x1cc, *piVar15);
    st_i32(W, 0x1d0, piVar15[1]);
    st_i32(W, 0x1d4, piVar15[2]);
    st_i32(W, 0x1d8, piVar15[3]);
    st_i32(W, 0x1dc, piVar15[4]);
    fVar1 = *(float*)(uintptr_t)&_DAT_005522c0;   // = 1.0f
    st_i32(W, 0x1e0, piVar15[5]);
    st_i32(W, 0x1c4, piVar15[6]);
    st_f32(W, 0x1c8, fVar1 / ld_f32(W, 0x1c4));
    st_f32(W, 0x1cc, ld_f32(W, 0x1cc) - ld_f32(W, 0x1c4));
    st_f32(W, 0x1d0, ld_f32(W, 0x1d0) - ld_f32(W, 0x1c4));
    st_i32(W, 0x1dc, ld_i32(W, 0x1dc) + 2);
    st_i32(W, 0x1e0, ld_i32(W, 0x1e0) + 2);

    // ------------------------------------------------------------------
    // Phase 6: color bits + two more dwords.
    //   local_7c      = (byte)piVar15[0xb];                  // blue bits
    //   _local_38     = CONCAT31(uStack_37, *(byte*)((int)piVar15 + 0x2d));
    //   W+0x48        = (*(byte*)((int)piVar15 + 0x2e) << 4) |
    //                   (*(byte*)((int)piVar15 + 0x2d));      // packed color bits
    //   W+0x1c        = CONCAT12(cStack_7a, CONCAT11(uStack_7b, local_7c)) & 0xff;
    //   W+0x40        = piVar15[0xc];
    //   W+0x44        = piVar15[0xd];
    //
    // The CONCAT idioms are byte-shuffles. Modelled directly via byte arrays.
    // ------------------------------------------------------------------
    local_7c = (uint8_t)piVar15[0xb];   // alias for byte 0 of local_7c_u
    // _local_38 = CONCAT31(uStack_37, byte@piVar15+0x2d) → low 3 bytes =
    //   (byte@0x2d), high byte = uStack_37 (uninitialized in Ghidra; we leave 0).
    {
        uint8_t b = *(uint8_t*)(uintptr_t)((uintptr_t)piVar15 + 0x2d);
        _local_38 = 0;            // uStack_37 is uninitialized; preserve zero
        uStack_37 = 0;            // (no observable effect; matches Ghidra's UB-safe read)
        local_38_u.b[0] = b;      // low byte = byte@0x2d
    }
    {
        uint8_t lo = *(uint8_t*)(uintptr_t)((uintptr_t)piVar15 + 0x2d);
        uint8_t hi = *(uint8_t*)(uintptr_t)((uintptr_t)piVar15 + 0x2e);
        st_u32(W, 0x48, ((uint32_t)hi << 4) | (uint32_t)lo);
    }
    {
        // CONCAT12(cStack_7a, CONCAT11(uStack_7b, local_7c)) & 0xff
        //   CONCAT11(uStack_7b, local_7c) = (uStack_7b << 8) | local_7c
        //   CONCAT12(cStack_7a, ...)      = (cStack_7a  << 16) | (...)
        //   & 0xff ⇒ low byte of local_7c.
        uint32_t packed =
            ((uint32_t)(uint8_t)cStack_7a << 16) |
            ((uint32_t)uStack_7b          << 8)  |
            (uint32_t)local_7c;
        st_u32(W, 0x1c, packed & 0xff);
    }
    st_i32(W, 0x40, piVar15[0xc]);
    st_i32(W, 0x44, piVar15[0xd]);

    // ------------------------------------------------------------------
    // Phase 7: copy 8 ints into local_20 (texture-name buffer, 32 bytes),
    //   advance piVar15 past the 0x16-int block. Clear W+0x3c.
    // ------------------------------------------------------------------
    piVar5 = piVar15 + 0xe;
    piVar16 = (int*)local_20;
    for (iVar12 = 8; iVar12 != 0; iVar12--) {
        *piVar16 = *piVar5;
        piVar5   = piVar5 + 1;
        piVar16  = piVar16 + 1;
    }
    piVar15 = piVar15 + 0x16;
    st_u32(W, 0x3c, 0);

    // ------------------------------------------------------------------
    // Phase 8: texture resolution. If W+0x1e4 (primary texture name ptr) is
    //   NULL, fall back to local_20. Resolve via FUN_0050e3c0 and store into
    //   W+0x4ec4. Mirror into W+0x3c. Then resolve W+0x1ec → W+0x4ec8 and
    //   W+0x1f4 (DAT_006316ec+500) → W+0x4ecc.
    //   Each resolved texture gets its +0x1e ushort OR'd with 0x300.
    // ------------------------------------------------------------------
    piVar5 = (int*)(uintptr_t)ld_u32(W, 0x1e4);
    if (piVar5 == (int*)0) {
        piVar5 = (int*)local_20;
    }
    uVar6 = FUN_0050e3c0(piVar5);
    st_u32(W, 0x4ec4, uVar6);
    st_u32(W, 0x3c,   ld_u32(W, 0x4ec4));

    if (ld_i32(W, 0x1ec) != 0) {
        uVar6 = FUN_0050e3c0((void*)(uintptr_t)ld_u32(W, 0x1ec));
        st_u32(W, 0x4ec8, uVar6);
    }
    if (ld_i32(W, 500) != 0) {     // 0x1f4 == 500
        uVar6 = FUN_0050e3c0((void*)(uintptr_t)ld_u32(W, 500));
        st_u32(W, 0x4ecc, uVar6);
    }

    if (ld_i32(W, 0x4ec4) != 0) {
        puVar18 = (uint16_t*)(uintptr_t)(ld_u32(W, 0x4ec4) + 0x1e);
        *puVar18 = (uint16_t)(*puVar18 | 0x300);
    }
    if (ld_i32(W, 0x4ec8) != 0) {
        puVar18 = (uint16_t*)(uintptr_t)(ld_u32(W, 0x4ec8) + 0x1e);
        *puVar18 = (uint16_t)(*puVar18 | 0x300);
    }
    if (ld_i32(W, 0x4ecc) != 0) {
        puVar18 = (uint16_t*)(uintptr_t)(ld_u32(W, 0x4ecc) + 0x1e);
        *puVar18 = (uint16_t)(*puVar18 | 0x300);
    }

    // ------------------------------------------------------------------
    // Phase 9: bump-texture clone. For each of the three bump slots
    //   (W+0x4ed0/4ed4/4ed8): if NULL OR equal to the corresponding primary
    //   (W+0x4ec4/4ec8/4ecc), and that primary is non-NULL, allocate a 0x20-
    //   byte clone tagged "ground bump texture", copy 8 dwords from the
    //   primary, link it back to the primary at +4, set +0x18=2, OR its +0x1e
    //   ushort with 0x410 and AND with 0xfdfe. Else (already distinct), just
    //   OR its +0x1e with 0x110 and set +0x18=2.
    // ------------------------------------------------------------------
    // First, resolve W+0x4edc/4ee4/4eec → W+0x4ed0/4ed4/4ed8 if non-NULL.
    if (ld_i32(W, 0x4edc) != 0) {
        uVar6 = FUN_0050e3c0((void*)(uintptr_t)ld_u32(W, 0x4edc));
        st_u32(W, 0x4ed0, uVar6);
    }
    if (ld_i32(W, 0x4ee4) != 0) {
        uVar6 = FUN_0050e3c0((void*)(uintptr_t)ld_u32(W, 0x4ee4));
        st_u32(W, 0x4ed4, uVar6);
    }
    if (ld_i32(W, 0x4eec) != 0) {
        uVar6 = FUN_0050e3c0((void*)(uintptr_t)ld_u32(W, 0x4eec));
        st_u32(W, 0x4ed8, uVar6);
    }

    // Helper lambda: the clone-or-flag routine (3 identical instances below).
    auto bump_slot = [&](uint32_t slot_off, uint32_t primary_off) {
        puVar8 = (uint32_t*)(uintptr_t)ld_u32(W, slot_off);
        piVar5 = (int*)((uint8_t*)W + slot_off);
        if (puVar8 == (uint32_t*)0 ||
            puVar8 == (uint32_t*)(uintptr_t)ld_u32(W, primary_off)) {
            puVar7 = (uint32_t*)(uintptr_t)ld_u32(W, primary_off);
            // stash puVar7 into the 4-byte packed local for the CONCAT13 path.
            local_7c_u.u32 = (uint32_t)(uintptr_t)puVar7;
            if (puVar8 == puVar7 && puVar7 != (uint32_t*)0) {
                iVar12 = (int)(intptr_t)FUN_0053c810(
                    0x12, 0x20, (const void*)s_ground_bump_texture_0055d960,
                    s_C__Giants_Source_main_makewrld_c_0055d974, 0x2c);
                *piVar5 = iVar12;                         // store clone ptr
                FUN_0050e3a0((uint32_t)(uintptr_t)puVar7); // release primary ref
                puVar8  = (uint32_t*)(uintptr_t)*piVar5;   // = clone ptr
                puVar20 = (uint32_t*)(uintptr_t)*piVar5;
                // copy 8 dwords (32 bytes) from primary → clone
                for (iVar12 = 8; iVar12 != 0; iVar12--) {
                    *puVar20 = *puVar8;
                    puVar8   = puVar8 + 1;
                    puVar20  = puVar20 + 1;
                }
                // *(clone+4) = primary  (CONCAT13 reconstructs the pointer)
                *(uint32_t**)((uintptr_t)*piVar5 + 4) = puVar7;
                *(uint32_t*)((uintptr_t)*piVar5 + 0x18) = 2;
                *(uint16_t*)((uintptr_t)*piVar5 + 0x1e) =
                    (uint16_t)(*(uint16_t*)((uintptr_t)*piVar5 + 0x1e) | 0x410);
                *(uint16_t*)((uintptr_t)*piVar5 + 0x1e) =
                    (uint16_t)(*(uint16_t*)((uintptr_t)*piVar5 + 0x1e) & 0xfdfe);
            }
        } else {
            *(uint16_t*)((uintptr_t)puVar8 + 0x1e) =
                (uint16_t)(*(uint16_t*)((uintptr_t)puVar8 + 0x1e) | 0x110);
            *(uint32_t*)((uintptr_t)ld_u32(W, slot_off) + 0x18) = 2;
        }
    };
    bump_slot(0x4ed0, 0x4ec4);
    bump_slot(0x4ed4, 0x4ec8);
    bump_slot(0x4ed8, 0x4ecc);

    // ------------------------------------------------------------------
    // Phase 10: allocate + zero the heightfield World array (cells).
    //   alloc = FUN_0053c810(0x1a, W+0x1e0 * W+0x1dc * 0x10,
    //                        "World", makewrld.c, 0x2af);
    //   zero count = (W+0x1e0 * W+0x1dc & 0xfffffff) << 2  dwords
    //                (plus a trailing byte loop the decompiler emits as
    //                 `for (iVar12=0; iVar12!=0; ...)`, i.e. never runs).
    //   Then pre-fill each cell dword with 0xc5800000 (a sentinel marker,
    //   = -0x3a800000 as int, the "empty cell" sentinel tested in Phase 13).
    // ------------------------------------------------------------------
    puVar7 = (uint32_t*)FUN_0053c810(
        0x1a,
        (uint32_t)(ld_i32(W, 0x1e0) * ld_i32(W, 0x1dc) * 0x10),
        (const void*)s_World_0055d9ec,
        s_C__Giants_Source_main_makewrld_c_0055d974, 0x2af);
    puVar8 = puVar7;
    for (iVar12 = (int)(((uint32_t)(ld_i32(W, 0x1e0) * ld_i32(W, 0x1dc) & 0xfffffffU) << 2));
         iVar12 != 0; iVar12--) {
        *puVar8 = 0;
        puVar8  = puVar8 + 1;
    }
    // Trailing byte loop — Ghidra emits `for(iVar12=0; iVar12!=0; ...)` which
    // never executes (initializer is 0). Preserved verbatim for fidelity.
    for (iVar12 = 0; iVar12 != 0; iVar12--) {
        *(uint8_t*)puVar8 = 0;
        puVar8 = (uint32_t*)((uintptr_t)puVar8 + 1);
    }

    // Pre-fill sentinel: for each row, for each col, *cell = 0xc5800000.
    iVar21 = 0;
    iVar12 = (int)(uintptr_t)W;
    if (0 < ld_i32(W, 0x1e0)) {
        iVar17 = ld_i32(W, 0x1dc);
        puVar8 = puVar7;
        do {
            iVar13 = 0;
            if (0 < iVar17) {
                do {
                    *puVar8 = 0xc5800000;
                    puVar8  = puVar8 + 4;   // note: stride 4 bytes here (per-cell dword)
                    iVar13  = iVar13 + 1;
                    iVar17  = ld_i32(W, 0x1dc);
                    iVar12  = (int)(uintptr_t)W;
                } while (iVar13 < iVar17);
            }
            iVar21 = iVar21 + 1;
        } while (iVar21 < ld_i32((void*)(uintptr_t)iVar12, 0x1e0));
    }

    // ------------------------------------------------------------------
    // Phase 11: row-pointer table (YROWS) at W+0x10. Each row pointer =
    //   puVar7 + (W+0x1dc * row) * 4. Also allocate two parallel per-row
    //   arrays at W+0x14 (DAT_0055d9e0 tag) and W+0x18 (DAT_0055d9dc tag).
    // ------------------------------------------------------------------
    uVar6 = (uint32_t)(uintptr_t)FUN_0053c810(
        0x1a, (uint32_t)(ld_i32((void*)(uintptr_t)iVar12, 0x1e0) << 2),
        (const void*)s_YROWS_0055d9e4,
        s_C__Giants_Source_main_makewrld_c_0055d974, 700);
    st_u32(W, 0x10, uVar6);

    iVar12 = 0;
    if (0 < ld_i32(W, 0x1e0)) {
        do {
            *(uint32_t**)(uintptr_t)(ld_u32(W, 0x10) + iVar12 * 4) =
                puVar7 + (uint32_t)(ld_i32(W, 0x1dc) * iVar12) * 4;
            iVar12 = iVar12 + 1;
        } while (iVar12 < ld_i32(W, 0x1e0));
    }

    uVar6 = (uint32_t)(uintptr_t)FUN_0053c810(
        0x1a, (uint32_t)(ld_i32(W, 0x1e0) << 2),
        (const void*)DAT_0055d9e0,
        s_C__Giants_Source_main_makewrld_c_0055d974, 0x2c1);
    st_u32(W, 0x14, uVar6);

    uVar6 = (uint32_t)(uintptr_t)FUN_0053c810(
        0x1a, (uint32_t)(ld_i32(W, 0x1e0) << 2),
        (const void*)DAT_0055d9dc,
        s_C__Giants_Source_main_makewrld_c_0055d974, 0x2c2);
    iVar17 = 1;
    st_u32(W, 0x18, uVar6);

    // ------------------------------------------------------------------
    // Phase 12: terrain-cell decode (RLE run/byte cases). The decompiler
    //   collapses this into a single outer do/while over iVar17 (row) with
    //   iVar21 (col). Two cases:
    //     (a) byte < 0  → skip (256 - byte) cells, wrapping rows as needed;
    //     (b) byte >= 0 → read (byte+1) cells. Each cell on disk starts at
    //         piVar5 with: dword[0] = height (written to cell), byte[4] = a
    //         triFlag (written as ushort to cell+3). If W+0x1c & 2, an extra
    //         color record follows (4 or 6 bytes depending on W+0x1c & 4),
    //         written as a packed RGB dword to cell+4.
    //   The loop ends when iVar17 >= (W+0x1e0 - 1).
    // ------------------------------------------------------------------
    iVar21 = 1;
    iVar12 = (int)(uintptr_t)W;
    if (1 < ld_i32((void*)(uintptr_t)iVar12, 0x1e0) + -1) {
        do {
            cVar11 = (char)*piVar15;
            piVar15 = (int*)((uintptr_t)piVar15 + 1);
            if (cVar11 < '\0') {
                iVar21 = iVar21 - cVar11;
                iVar13 = ld_i32((void*)(uintptr_t)iVar12, 0x1dc);
                if (iVar13 + -1 <= iVar21) {
                    do {
                        iVar21 = iVar21 + (2 - iVar13);
                        iVar17 = iVar17 + 1;
                    } while (iVar13 + -1 <= iVar21);
                }
            } else {
                local_84 = cVar11 + 1;
                piVar5 = piVar15;
                if (0 < local_84) {
                    do {
                        piVar16 = (int*)((uintptr_t)piVar5 + 5);
                        // cell at (row=iVar17, col=iVar21) = *(int*)piVar5 (height dword)
                        puVar7[(uint32_t)(ld_i32((void*)(uintptr_t)iVar12, 0x1dc) * iVar17 + iVar21) * 4] =
                            (uint32_t)*piVar5;
                        // cell+3 (ushort) = byte@(piVar5+1) = triFlag.
                        // Ghidra: *(ushort *)(puVar7 + idx*4 + 3) — puVar7 is
                        // undefined4*, so puVar7 + idx*4 advances by idx*16
                        // bytes, and the +3 is added as a dword-unit offset
                        // (= +12 bytes). Net byte address: base + idx*16 + 12.
                        *(uint16_t*)((uintptr_t)puVar7 +
                                     ((uint32_t)(ld_i32(W, 0x1dc) * iVar17 + iVar21) * 4 + 3) * 4) =
                            (uint16_t)(*(uint8_t*)((uintptr_t)piVar5 + 1));
                        piVar15 = piVar16;
                        if ((ld_u32(W, 0x1c) & 2) != 0) {
                            if ((ld_u32(W, 0x1c) & 4) == 0) {
                                piVar15 = piVar5 + 2;   // +8 bytes
                                local_7c = (uint8_t)(*(uint16_t*)piVar16 & 0xff);
                                uStack_7b = (uint8_t)((*(uint16_t*)piVar16 >> 8) & 0xff);
                                cStack_7a = *(char*)((uintptr_t)piVar5 + 7);
                                cVar11 = (char)-1;
                            } else {
                                piVar15 = (int*)((uintptr_t)piVar5 + 9);
                                local_7c = (uint8_t)(*(uint16_t*)piVar16 & 0xff);
                                uStack_7b = (uint8_t)((*(uint16_t*)piVar16 >> 8) & 0xff);
                                cVar11 = (char)piVar5[2];
                                cStack_7a = *(char*)((uintptr_t)piVar5 + 7);
                            }
                            // packed color dword → cell+4
                            //   = ( (CONCAT11(cVar11, local_7c) << 8 |
                            //        CONCAT12(uStack_79, CONCAT11(cStack_7a, uStack_7b)) & 0xff) << 8 |
                            //        CONCAT11(uStack_79, cStack_7a) & 0xff )
                            {
                                uint32_t cat_a = ((uint32_t)(uint8_t)cVar11 << 8 |
                                                  (((uint32_t)uStack_79 << 8) |
                                                   ((uint32_t)(uint8_t)cStack_7a << 0) |
                                                   ((uint32_t)uStack_7b)) & 0xff);
                                uint32_t cat_b = (((uint32_t)uStack_79 << 8) |
                                                   (uint8_t)cStack_7a) & 0xff;
                                uint32_t packed = (cat_a << 8) | cat_b;
                                puVar7[(uint32_t)(ld_i32(W, 0x1dc) * iVar17 + iVar21) * 4 + 1] =
                                    packed;
                            }
                        }
                        iVar21 = iVar21 + 1;
                        if (ld_i32(W, 0x1dc) + -1 <= iVar21) {
                            iVar21 = 1;
                            iVar17 = iVar17 + 1;
                        }
                        local_84 = local_84 + -1;
                        piVar5 = piVar15;
                        iVar12 = (int)(uintptr_t)W;
                    } while (local_84 != 0);
                }
            }
        } while (iVar17 < ld_i32((void*)(uintptr_t)iVar12, 0x1e0) + -1);
    }

    // W+0x0c = puVar7 (heightfield base)
    *(uint32_t**)((uintptr_t)iVar12 + 0x0c) = puVar7;

    // ------------------------------------------------------------------
    // Phase 13: per-row first/last non-empty column scan.
    //   For each row y in [0, W+0x1e0):
    //     W+0x18[y] = -1 (default "no non-empty col")
    //     walk the row's cell dwords; find the first index whose dword is
    //     not 0xc5800000 (= -0x3a800000) → write to W+0x14[y]; then keep
    //     walking and overwrite W+0x18[y] with the LAST such index.
    // ------------------------------------------------------------------
    iVar21 = 0;
    iVar12 = (int)(uintptr_t)W;
    if (0 < ld_i32(W, 0x1e0)) {
        do {
            st_u32((void*)(uintptr_t)iVar12, 0x18 + iVar21 * 4, 0xffffffff);
            // row ptr = *(uint32_t*)(W+0x10 + iVar21*4)
            piVar15 = (int*)(uintptr_t)ld_u32(W, 0x10 + (uint32_t)iVar21 * 4);
            iVar17 = 0;
            if (0 < ld_i32(W, 0x1dc)) {
                do {
                    if (*piVar15 != -0x3a800000) break;
                    iVar17 = iVar17 + 1;
                    piVar15 = piVar15 + 4;
                } while (iVar17 < ld_i32(W, 0x1dc));
            }
            *(int*)(uintptr_t)(ld_u32(W, 0x14) + iVar21 * 4) = iVar17;
            iVar12 = (int)(uintptr_t)W;
            if (iVar17 < ld_i32(W, 0x1dc)) {
                do {
                    if (*piVar15 != -0x3a800000) {
                        *(int*)(uintptr_t)(ld_u32((void*)(uintptr_t)iVar12, 0x18) + iVar21 * 4) =
                            iVar17;
                        iVar12 = (int)(uintptr_t)W;
                    }
                    iVar17 = iVar17 + 1;
                    piVar15 = piVar15 + 4;
                } while (iVar17 < ld_i32((void*)(uintptr_t)iVar12, 0x1dc));
            }
            iVar21 = iVar21 + 1;
        } while (iVar21 < ld_i32((void*)(uintptr_t)iVar12, 0x1e0));
    }

    // Free the world_data stream.
    FUN_0053a3c0(local_60);

    // ------------------------------------------------------------------
    // Phase 14: per-cell render-flag switch. For each cell, read the ushort
    //   at cell+0xc (the triFlag), switch on its low 3 bits, compute two
    //   normals (FUN_00454620 cross + FUN_004778f0 pack) and OR the packed
    //   result into the flag.
    // ------------------------------------------------------------------
    local_84 = 0;
    iVar12 = (int)(uintptr_t)W;
    if (0 < ld_i32(W, 0x1e0)) {
        do {
            iVar21 = 0;
            if (0 < ld_i32((void*)(uintptr_t)iVar12, 0x1dc)) {
                puVar18 = (uint16_t*)(uintptr_t)
                    (*(uint32_t*)(uintptr_t)(ld_u32((void*)(uintptr_t)iVar12, 0x10) +
                                             local_84 * 4) + 0xc);
                do {
                    short sVar2, sVar3;
                    if (*puVar18 == 0) goto switchD_00477728_default;

                    // Compute the 4 corner vertices of the cell quad.
                    FUN_00458ab0(iVar21,     local_84,     local_5c);   // (x,   y)
                    FUN_00458ab0(iVar21 + 1, local_84,     local_44);   // (x+1, y)
                    FUN_00458ab0(iVar21,     local_84 + 1, &local_7c);  // (x,   y+1)  (reuses local_7c bytes!)
                    FUN_00458ab0(iVar21 + 1, local_84 + 1, local_50);   // (x+1, y+1)

                    // Note: &local_7c above aliases the SAME storage as our
                    // packed-color union — vanilla does this too (local_7c is
                    // a byte that opens into a 12-byte slot at &local_7c).
                    switch (*puVar18 & 7) {
                    case 1:
                        puVar10 = local_5c;  puVar9 = (uint8_t*)&local_7c;  puVar14 = local_44;
                        break;
                    case 2:
                        puVar10 = local_50;  puVar14 = local_44;            puVar9 = (uint8_t*)&local_7c;
                        break;
                    case 3:
                        puVar10 = local_44;  puVar14 = local_5c;            puVar9 = local_50;
                        break;
                    case 5:
                        FUN_00454620(local_5c, local_50, (uint8_t*)&local_7c, local_70);
                        puVar10 = local_44;  puVar14 = local_5c;            puVar9 = local_50;
                        goto LAB_00477785;
                    case 6:
                        FUN_00454620(local_44, (uint8_t*)&local_7c, local_5c, local_70);
                        puVar10 = local_50;  puVar14 = local_44;            puVar9 = (uint8_t*)&local_7c;
                    LAB_00477785:
                        FUN_00454620(puVar9, puVar14, puVar10, &local_30);
                        sVar2 = FUN_004778f0(local_70);
                        sVar3 = FUN_004778f0(&local_30);
                        goto LAB_0047781d;
                    case 7:
                        *puVar18 = (uint16_t)(*puVar18 & 0xfffc | 4);
                        // fallthrough
                    case 4:
                        puVar10 = (uint8_t*)&local_7c;  puVar14 = local_50;  puVar9 = local_5c;
                        break;
                    default:
                        goto switchD_00477728_default;
                    }
                    // cases 1/2/3/4 land here
                    FUN_00454620(puVar9, puVar14, puVar10, local_70);
                    sVar2 = FUN_004778f0(local_70);
                    sVar3 = FUN_004778f0((void*)0);
                LAB_0047781d:
                    *puVar18 = (uint16_t)(*puVar18 | (uint16_t)((sVar2 + sVar3 * 9) * 8));

                switchD_00477728_default:
                    iVar21 = iVar21 + 1;
                    puVar18 = (uint16_t*)((uintptr_t)puVar18 + 8);
                    iVar12  = (int)(uintptr_t)W;
                } while (iVar21 < ld_i32(W, 0x1dc));
            }
            local_84 = local_84 + 1;
        } while (local_84 < ld_i32((void*)(uintptr_t)iVar12, 0x1e0));
    }

    // ------------------------------------------------------------------
    // Phase 15: world-bounds writes. The decompiler emits these as constant
    //   dwords:
    //     W+0x20 = 0
    //     W+0x24 = W+0x1dc - 2          (max col)
    //     W+0x28 = 0
    //     W+0x2c = W+0x1e0 - 2          (max row)
    //     W+0x30 = 0xc2746666           (float constant, = 61.1f)
    //     W+0x34 = W+0x1d8              (copy of origin)
    //     W+0x4ef8 = 1
    //   Then FUN_00436960() (post-build init, no args).
    // ------------------------------------------------------------------
    st_u32((void*)(uintptr_t)iVar12, 0x20, 0);
    st_i32(W, 0x24, ld_i32(W, 0x1dc) + -2);
    st_u32(W, 0x28, 0);
    st_i32(W, 0x2c, ld_i32(W, 0x1e0) + -2);
    st_u32(W, 0x30, 0xc2746666u);
    st_u32(W, 0x34, ld_u32(W, 0x1d8));
    st_u32(W, 0x4ef8, 1);

    FUN_00436960();

    // ------------------------------------------------------------------
    // Phase 16: "alpha bit" stencil scan. For each cell, build a small
    //   descriptor struct on the stack (local_20[0], local_34, local_30,
    //   iStack_2c, iStack_28, iStack_24) and call FUN_004768e0(). If it
    //   returns 0, mark the cell's +0xe byte (= local_c) with 1. Then scan
    //   a 3x3 neighbourhood (iVar4 = local_4 in [-1,0,1], iVar13 ditto) with
    //   a second descriptor call; if any neighbour returns 0, mark +0xe.
    //   The local_c pointer advances by 0x10 per cell (stride matches the
    //   0x10-byte heightfield record).
    // ------------------------------------------------------------------
    local_8 = 0;
    iVar12 = (int)(uintptr_t)W;
    if (0 < ld_i32(W, 0x1e0)) {
        do {
            iVar17 = 0;
            iVar21 = local_8;
            if (0 < ld_i32((void*)(uintptr_t)iVar12, 0x1dc)) {
                local_c = (uint8_t*)(uintptr_t)
                    (*(uint32_t*)(uintptr_t)(ld_u32((void*)(uintptr_t)iVar12, 0x10) +
                                             local_8 * 4) + 0xe);
                do {
                    local_20[0] = 0;
                    local_34   = 0x476c79;     // 'G', 'l', 'y'  (tag bytes)
                    local_30   = iVar17;
                    iStack_2c  = iVar21;
                    iStack_28  = iVar17;
                    iStack_24  = iVar21;
                    iVar12 = FUN_004768e0();
                    if (iVar12 == 0) {
                        *local_c = 1;
                        iVar12 = (int)(uintptr_t)W;
                    } else {
                        local_4 = -1;
                        iVar12  = (int)(uintptr_t)W;
                        do {
                            iVar13 = -1;
                            iVar19 = local_4 + iVar17;
                            iVar21 = iVar21 + -1;
                            do {
                                if ((((-1 < iVar19) && (-1 < iVar21)) &&
                                     (iVar19 < ld_i32((void*)(uintptr_t)iVar12, 0x1dc))) &&
                                     (iVar21 < ld_i32((void*)(uintptr_t)iVar12, 0x1e0))) {
                                    local_20[0] = 1;
                                    iStack_24   = local_8;
                                    local_34    = 0x476cc9;   // 'G', 'l', 0xc9
                                    local_30    = iVar19;
                                    iStack_2c   = iVar21;
                                    iStack_28   = iVar17;
                                    iVar4 = FUN_004768e0();
                                    iVar12 = (int)(uintptr_t)W;
                                    if (iVar4 == 0) {
                                        *local_c = 1;
                                        iVar12 = (int)(uintptr_t)W;
                                        break;
                                    }
                                }
                                iVar13 = iVar13 + 1;
                                iVar21 = iVar21 + 1;
                            } while (iVar13 < 2);
                            local_4 = local_4 + 1;
                            iVar21  = local_8;
                        } while (local_4 < 2);
                    }
                    iVar17 = iVar17 + 1;
                    local_c = local_c + 0x10;
                } while (iVar17 < ld_i32((void*)(uintptr_t)iVar12, 0x1dc));
            }
            local_8 = iVar21 + 1;
        } while (local_8 < ld_i32((void*)(uintptr_t)iVar12, 0x1e0));
    }

    return;
}

// ============================================================================
// Fallback definitions for globals/strings that no other TU provides yet.
// These are WEAK candidates — if another TU (e.g. VanillaStubs.cpp) already
// defines them, the linker should prefer that definition; if not, these
// satisfy the references. Marked extern "C" to match the declarations above.
//
// NOTE: VanillaStubs.cpp currently defines `uint32_t DAT_006316ec = 0;` and
// `uint32_t _DAT_005522c0 = 0;`. VanillaSceneLists.cpp also defines
// g_WorldState (= DAT_006316ec). To avoid a multiple-definition error under
// MinGW32, we do NOT redefine those two here. We DO provide the makewrld.c
// string literals + DAT_0059cc40 + the two DAT string-tag blobs, since no
// other TU currently references them.
// ============================================================================
extern "C" {

// DAT_0059cc40 — scratch buffer pointer (allocated at runtime).
uint32_t* DAT_0059cc40 = nullptr;

// DAT_0055da18 — heap-tag blob (allocator cookie), 16 bytes zero-init.
uint8_t DAT_0055da18[16] = { 0 };

// makewrld.c source-path tag (used by every FUN_0053c810 call in this body).
const char s_C__Giants_Source_main_makewrld_c_0055d974[] =
    "C:\\Giants\\Source\\main\\makewrld.c";

// Allocator tag strings.
const char s_wbboxes_0055d9f4[]                   = "wbboxes";
const char s_Bad_version_for_world_data_0055d9fc[] = "Bad version for world data";
const char s_World_0055d9ec[]                     = "World";
const char s_YROWS_0055d9e4[]                     = "YROWS";
const char s_ground_bump_texture_0055d960[]       = "ground bump texture";

// Bare-address tag blobs (vanilla leaks whatever 4 bytes live at these
// addresses into the allocator's tag slot; we expose them as 4-byte arrays
// so we can take their address and pass it verbatim).
const uint8_t DAT_0055d9e0[4] = { 0,0,0,0 };
const uint8_t DAT_0055d9dc[4] = { 0,0,0,0 };

} // extern "C"
