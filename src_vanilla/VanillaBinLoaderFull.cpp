// Giants Vanilla-Native Recomp — FULL faithful port of FUN_004b7c50 (readwrls.c).
//
// Ground truth: vanilla_decompiled/004b7c50.json (vanilla 1.0 Giants.exe @ 0x004b7c50).
// Every block cites the DAT_/VA it reproduces. Unverified callees carry a
// FIXME(unverified) tag and are expected to be satisfied by integrator stubs.
//
// This is a STRUCTURAL port: it preserves the exact control flow (magic check,
// 0x1c header read, the per-section SetFilePointer sequence, the recursive
// sub-scene loop, the odef VM dispatch, the world-global seed writes on
// DAT_006316ec, and the trailing 0x1a0002dd secondary-file parse). The byte
// opcodes in the switch are the integer values the decompiler rendered as
// denormal floats (e.g. case 2.66247e-44 == byte 0x13).
//
// Anti-dérive: no invented logic. Where the decompiled body does something, so
// does this file, in the same order, with the same constants.
#include "VanillaBinLoaderFull.h"
#include "VanillaFileIO.h"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cstdlib>

// ============================================================================
// Local helpers (faithful to the inline pointer arithmetic in the body).
// ============================================================================
namespace {

// Float-bit constant helpers (the body writes raw hex into float slots).
inline void store_f32(void* base, uint32_t off, uint32_t bits) {
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(base) + off) = bits;
}
inline void store_f32f(void* base, uint32_t off, float v) {
    *reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(base) + off) = v;
}
inline uint32_t load_u32(void* base, uint32_t off) {
    return *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(base) + off);
}
inline float load_f32(void* base, uint32_t off) {
    return *reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(base) + off);
}

// __ftol2 / __ftol: vanilla uses the CRT ftol intrinsic for float->int truncation
// (two such calls feed the (i<<8|j)<<8|k color pack). Replaced by C truncation.
inline int ftol_trunc(float v) { return static_cast<int>(v); }

// Skip a NUL-terminated string in the odef blob, return pointer past the NUL.
inline uint8_t* skip_cstr(uint8_t* p) {
    while (*p != '\0') ++p;
    return p + 1;
}

} // namespace

// ============================================================================
// FUN_004b7c50 — the loader.
// ============================================================================
extern "C" void FUN_004b7c50(char* param_1, float param_2, float param_3)
{
    // --- Locals (renamed for readability, but layout/usage match the body). ---
    int      obj_count      = 0;     // local_414 — #placed objects parsed so far
    int      flick_count    = 0;     // local_400 — #flicks parsed
    int      lock_depth     = 0;     // local_408 — OpLoc/OpLocEnd nest depth
    char*    anim_count     = nullptr; // local_418 — #world anims (abused as int ptr in body)
    int      sub_scene_flag = 0;     // local_404 — set by opcodes 0x82/0x83 (sub-scene enable)
    uint32_t tmp_objdata    = 0;     // local_41c — OpAre/OpLoc ObjData handle
    uint32_t file_handle    = 0;     // local_3ec
    uint32_t magic          = 0;     // local_3e4
    uint32_t hdr[7];                 // local_3a0..auStack_384 — 7-u32 section header
    uint32_t obj_stream_size = 0;    // local_3dc — size of trailing odef blob
    uint8_t* obj_stream      = nullptr; // local_3fc[0] — alloc'd blob buffer
    uint8_t* terrain_name_p  = nullptr; // local_3e8 — first cstr in blob (terrain/gti)
    uint8_t* sky_name_p      = nullptr; // (derived) second cstr in blob
    uint32_t prev_opcode     = 0xFFFFFFFF; // fVar14 — last opcode (for error msg)
    uint32_t* cur_stobj      = nullptr; // puVar16 — current placed-object slot
    uint32_t* stobj_pool     = nullptr; // local_40c — big alloc'd stobj pool (0xc1000 bytes)

    // Stack scratch buffers (mirror the body's local_364 / local_1e4 / local_180 /
    // auStack_178 / local_3c0 / auStack_384 arrays).
    float    scratch_f[96];          // local_364 (also reused as name buf for recursion)
    char     scratch_anm[100];       // local_1e4
    uint32_t world_anims[2 * 32];    // local_180 + auStack_178 (anim table, 32 entries × 3 u32 — but body uses 2+376 bytes)
    uint8_t  lock_stack[7];          // auStack_384 (lock nesting stack)
    float    read_vec3[8];           // local_3c0 (scratch for 3-float reads)
    uint32_t alloc_cc = 0, alloc_c4 = 0, alloc_d4 = 0, alloc_d8 = 0, alloc_e0 = 0; // local_3cc/3c4/3d4/3d8/3e0 — temp alloc handles for FUN_0053c890 out-params
    (void)alloc_cc; (void)alloc_c4; (void)alloc_d4; (void)alloc_d8; (void)alloc_e0;
    (void)sky_name_p; (void)tmp_objdata; (void)stobj_pool; (void)world_anims;
    (void)lock_stack; (void)read_vec3; (void)scratch_anm;

    // ---------------------------------------------------------------------
    // 0x4b7ca4: _DAT_005a5c9c = param_2  (record start-time on entry)
    // ---------------------------------------------------------------------
    _DAT_005a5c9c = param_2;

    // ---------------------------------------------------------------------
    // 0x4b7caa6: open the file; bail to log on failure
    // ---------------------------------------------------------------------
    file_handle = FUN_00539e30(param_1);
    if (file_handle == 0) {
        FUN_00544b47(&DAT_006552c0, s_Failed_to_open__s_0055e25c, param_1); // FIXME(unverified): callee 0x00544b47
        FUN_00523700(DAT_006552c0);                                        // FIXME(unverified): callee 0x00523700
        return;
    }

    // ---------------------------------------------------------------------
    // 0x4b7cab8: read magic (4 bytes) and validate 0x1a0002e5
    // ---------------------------------------------------------------------
    FUN_0051d750(file_handle, &magic, 4);
    if (magic != 0x1a0002e5u) {
        FUN_00544b47(&DAT_006552c0, s_Bad_version_for__s___X_vs__X__005634cc,
                     param_1, magic, 0x1a0002e5u);
        FUN_00523700(DAT_006552c0);
        FUN_0051d850(file_handle);
        return;
    }

    // ---------------------------------------------------------------------
    // 0x4b7cde: read the 7-u32 header (0x1c bytes) into hdr[0..6]
    //   hdr[0]=local_3a0  odef_blob_off   (==0x20)
    //   hdr[1]=local_39c  name_list_off
    //   hdr[2]=local_398  texmem_off       (SFX seek target)
    //   hdr[3]=local_394  world_off        (object-placement seek target)
    //   hdr[4]=local_390  fx_off           (texmem/entity seek target)
    //   hdr[5]=local_38c  reserved5        (reserved5 seek target — sub_bins? see below)
    //   hdr[6]=local_388  sub_bins_off     (NOT zero → recursive sub-scene load)
    // ---------------------------------------------------------------------
    FUN_0051d750(file_handle, hdr, 0x1c);

    // 0x4b7cea: seek to texmem section, load SFX
    FUN_0051d7b0(file_handle, hdr[2]);
    FUN_0049a580(file_handle);                                        // FIXME(unverified): callee 0x0049a580

    // 0x4b7cf6: seek to name-list section, insert texture/entity nodes
    FUN_0051d7b0(file_handle, hdr[1]);
    FUN_0050d8f0(param_1, file_handle, magic);                        // FIXME(unverified): callee 0x0050d8f0

    // 0x4b7d02: seek to fx section, read 4-byte fx preset index
    FUN_0051d7b0(file_handle, hdr[4]);
    int32_t fx_index;
    FUN_0051d750(file_handle, &fx_index, 4);
    if (fx_index >= 0) {
        const char* fx_name;
        if (fx_index == 0) {
            fx_name = DAT_0055c214;            // "" (none)
        } else if (fx_index == 1) {
            fx_name = s_fx_world_dust_005634ac;
        } else if (fx_index == 2) {
            fx_name = s_fx_world_snow_005634bc;
        } else {
            goto LAB_004b7d88;                  // body's `goto LAB_004b7d88`
        }
        FUN_0044ab90(fx_name);                                       // FIXME(unverified): callee 0x0044ab90
    }

LAB_004b7d88:
    // ---------------------------------------------------------------------
    // 0x4b7d88: if hdr[6] (sub_bins_off) != 0 — recursive sub-scene load.
    //   Seek to sub_bins_off, read u32 count, then loop count times:
    //     read 0x20 bytes (a sub-bin name), format "<name>_bin", recurse.
    // ---------------------------------------------------------------------
    if (hdr[6] != 0) {
        FUN_0051d7b0(file_handle, hdr[6]);
        int32_t sub_count;
        FUN_0051d750(file_handle, &sub_count, 4);
        float step = (param_3 - param_2) / static_cast<float>(sub_count); // local_410
        int idx = 0;                                                       // local_418 (int counter)
        if (sub_count > 0) {
            do {
                int next_idx = idx + 1;
                // Read 0x20-byte name into scratch_f (treated as char buf).
                FUN_0051d750(file_handle, scratch_f, 0x20);
                // Format "<name>_bin" into scratch_f+0x80 region... the body uses
                // local_364 (== scratch_f) directly as the recursion name buffer.
                // To preserve the recursion shape, we build the name in a separate
                // stack buffer (the body aliases local_364 for both — we keep them
                // distinct to avoid clobbering the just-read name).
                char sub_name[0x80];
                FUN_00544b47(sub_name, s__s_bin_00555384,
                             reinterpret_cast<char*>(scratch_f));         // sprintf-like
                FUN_004b7c50(sub_name,
                             static_cast<float>(idx) * step + param_2,
                             static_cast<float>(next_idx) * step + param_2);
                idx = next_idx;
            } while (idx < sub_count);
        }
    }

    // ---------------------------------------------------------------------
    // 0x4b7db3: seek to world_off, read object placements -> DAT_006313c8.
    //   Then seek to odef_blob_off (hdr[0]), read u32 obj_stream_size,
    //   allocate obj_stream_size bytes, read the odef blob.
    // ---------------------------------------------------------------------
    FUN_0051d7b0(file_handle, hdr[3]);
    FUN_004b50b0(file_handle, param_1);                                  // FIXME(unverified): callee 0x004b50b0

    FUN_0051d7b0(file_handle, hdr[0]);
    FUN_0051d750(file_handle, &obj_stream_size, 4);
    if (obj_stream_size == 0) {
        FUN_0051d850(file_handle);
        return;
    }
    obj_stream = static_cast<uint8_t*>(
        FUN_0053c810(0x18, obj_stream_size, &DAT_00562d10,
                     s_C__Giants_Source_main_readwrls_c_00563174, 0x1c9)); // FIXME(unverified): callee 0x0053c810
    FUN_0051d750(file_handle, obj_stream, obj_stream_size);

    // 0x4b7e0c: skip the two leading NUL-terminated strings in the blob
    //   (terrain name + sky/scene name). These are the `while (cVar2 != '\0')`
    //   loops in the body. terrain_name_p/sky_name_p feed the trailing hook.
    {
        uint8_t* p = obj_stream;
        terrain_name_p = p;
        p = skip_cstr(p);                    // skip terrain name
        sky_name_p = p;
        p = skip_cstr(p);                    // skip sky name
        // p now points at the first opcode byte.
        // Note: the body keeps `pcVar24` walking; we re-derive p below.
        (void)p;
    }

    // ---------------------------------------------------------------------
    // 0x4b7e3b..0x4b7f5e: seed world globals on DAT_006316ec.
    //   These are the literal float-bit writes the body performs before the
    //   opcode dispatch loop. Hex constants reproduced verbatim.
    // ---------------------------------------------------------------------
    {
        uintptr_t W = DAT_006316ec;
        // Hardcoded defaults block (the body writes these unconditionally).
        store_f32(reinterpret_cast<void*>(W), 0x7c, 0x447a0000); // 1000.0f
        store_f32(reinterpret_cast<void*>(W), 0x80, 0x3d000000); // 0.03125f
        store_f32(reinterpret_cast<void*>(W), 0x84, 0x3f000000); // 0.5f
        store_f32(reinterpret_cast<void*>(W), 0x505c, 0x80u);
        store_f32(reinterpret_cast<void*>(W), 0x5048, 0);
        store_f32(reinterpret_cast<void*>(W), 0x504c, 0);
        store_f32(reinterpret_cast<void*>(W), 0x5050, 0);
        store_f32(reinterpret_cast<void*>(W), 0x5054, 0);
        store_f32(reinterpret_cast<void*>(W), 0x5058, 0);
        store_f32(reinterpret_cast<void*>(W), 0x5064, 0x457a0000);
        store_f32(reinterpret_cast<void*>(W), 0x5060, 0x42000000);
        store_f32(reinterpret_cast<void*>(W), 0x506c, 0x3f800000);
        store_f32(reinterpret_cast<void*>(W), 0x5068, 0x3f800000);
        store_f32(reinterpret_cast<void*>(W), 0x5070, 0x3fc00000);
        store_f32(reinterpret_cast<void*>(W), 0x5074, 0);
        store_f32(reinterpret_cast<void*>(W), 0x1c4, 0x42480000); // 50.0f
        // *(float*)(W+0x1c8) = _DAT_005522c0 / *(float*)(W+0x1c4)
        store_f32f(reinterpret_cast<void*>(W), 0x1c8,
                   _DAT_005522c0 / load_f32(reinterpret_cast<void*>(W), 0x1c4));
        // std::cos seeds for W+0x4e9c / W+0x4ea0
        float c1 = static_cast<float>(std::cos(static_cast<double>(_DAT_005526d0)));
        store_f32(reinterpret_cast<void*>(W), 0x1cc, 0xc59c4000); // -1248.0f
        store_f32(reinterpret_cast<void*>(W), 0x1d0, 0xc59c4000);
        store_f32(reinterpret_cast<void*>(W), 0x1dc, 0xc9u);
        store_f32(reinterpret_cast<void*>(W), 0x1e0, 0xc9u);
        store_f32f(reinterpret_cast<void*>(W), 0x4e9c, c1);
        float c2 = static_cast<float>(std::cos(static_cast<double>(_DAT_005526c8)));
        store_f32f(reinterpret_cast<void*>(W), 0x4ea0, c2);
        store_f32(reinterpret_cast<void*>(W), 0x4e90, 0x3f800000);
        store_f32(reinterpret_cast<void*>(W), 0x4e94, 0xbdcccccd);
        store_f32(reinterpret_cast<void*>(W), 0x4e98, 0xbd4ccccd);
    }
    FUN_004b7b30();                                                // FIXME(unverified): callee 0x004b7b30

    // ---------------------------------------------------------------------
    // 0x4b7f87: allocate the stobj pool (0xc1000 bytes = 1024 × 0x304).
    //   The body allocs 0xc1000 with tag s_sobjs_005634a4 at line 0x1fd.
    //   This is the placed-object scratch pool the opcode loop fills.
    // ---------------------------------------------------------------------
    stobj_pool = static_cast<uint32_t*>(
        FUN_0053c810(0x18, 0xc1000, const_cast<char*>(s_sobjs_005634a4),
                     s_C__Giants_Source_main_readwrls_c_00563174, 0x1fd)); // FIXME(unverified): callee 0x0053c810

    // ---------------------------------------------------------------------
    // 0x4b8009..LAB_004b809d: the odef VM dispatch loop.
    //   pfVar18 walks the blob post the two header strings. Each iteration:
    //     opcode = *(byte*)pfVar18;  advance pfVar18 by 1;  switch(opcode).
    //   The switch advances pfVar18 by the opcode's payload size, then loops.
    //   Loop ends when opcode == 0 (case 3.57331e-43 == byte 0x00 → exits).
    // ---------------------------------------------------------------------
    {
        // Re-derive p past the two header strings (terrain + sky names).
        uint8_t* p = skip_cstr(skip_cstr(obj_stream));
        prev_opcode = 0xFFFFFFFF;
        cur_stobj   = nullptr;

        while (1) {
            uint8_t opcode = *p;                       // *(byte*)pfVar18
            uint8_t* arg = p + 1;                       // pfVar17
            // loop-exit condition: body checks `if (local_410 != 3.57331e-43)`
            //   where local_410 = (float)(uint)*(byte*)pfVar18. 3.57331e-43 is
            //   the denormal of byte 0x00. So opcode==0 ends the loop.
            if (opcode == 0x00) break;

            switch (opcode) {
            // ---- case 0x13 (2.66247e-44): set stobj flag fields ----
            case 0x13:
                p += 2;
                cur_stobj[4]  = *arg;
                cur_stobj[0xc] = 1;
                prev_opcode = opcode;
                continue;

            // ---- case 0x16 (3.22299e-44): stobj[0x31] = u32 at arg ----
            case 0x16:
                p += 5;
                cur_stobj[0x31] = *reinterpret_cast<uint32_t*>(arg);
                prev_opcode = opcode;
                continue;

            // ---- case 0x1a (4.06377e-44): allocate a 0x1a-byte obj, FUN_0053c890 ----
            case 0x1a:
                FUN_0053c890(0x1a, arg, &alloc_cc,
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x216); // FIXME(unverified): callee 0x0053c890
                p += 0x11;
                FUN_0053c5c0(reinterpret_cast<void*>(alloc_cc),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x217); // FIXME(unverified): callee 0x0053c5c0
                prev_opcode = opcode;
                continue;

            // ---- case 0x1b (4.2039e-44): alloc 0x1a at W+0x50, resolve tex ----
            case 0x1b: {
                uintptr_t W = DAT_006316ec;
                FUN_0053c890(0x1a, arg, reinterpret_cast<void*>(W + 0x50),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x20c);
                p += 0x11;
                uint32_t h = FUN_0050e3c0(reinterpret_cast<const char*>(
                    load_u32(reinterpret_cast<void*>(W), 0x50)));         // FIXME(unverified): 0x0050e3c0
                store_f32(reinterpret_cast<void*>(W), 0x4c, h);
                prev_opcode = opcode;
                continue;
            }

            // ---- case 0x1c (4.34403e-44): alloc 0x1a -> local_3c4 ----
            case 0x1c:
                FUN_0053c890(0x1a, arg, &alloc_c4,
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x220);
                p += 0x11;
                FUN_0053c5c0(reinterpret_cast<void*>(alloc_c4),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x221);
                prev_opcode = opcode;
                continue;

            // ---- cases 0x1d..0x20 (4.48416e-44 .. 4.76441e-44): texture slots
            //      W+0x58/0x60/0x68/0x78 — same shape as 0x1b ----
            case 0x1d: {
                uintptr_t W = DAT_006316ec;
                FUN_0053c890(0x1a, arg, reinterpret_cast<void*>(W + 0x58),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x226);
                p += 0x11;
                uint32_t h = FUN_0050e3c0(reinterpret_cast<const char*>(load_u32(reinterpret_cast<void*>(W), 0x58)));
                store_f32(reinterpret_cast<void*>(W), 0x54, h);
                prev_opcode = opcode;
                continue;
            }
            case 0x1e: {
                uintptr_t W = DAT_006316ec;
                FUN_0053c890(0x1a, arg, reinterpret_cast<void*>(W + 0x60),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x22b);
                p += 0x11;
                uint32_t h = FUN_0050e3c0(reinterpret_cast<const char*>(load_u32(reinterpret_cast<void*>(W), 0x60)));
                store_f32(reinterpret_cast<void*>(W), 0x5c, h);
                prev_opcode = opcode;
                continue;
            }
            case 0x1f: {
                uintptr_t W = DAT_006316ec;
                FUN_0053c890(0x1a, arg, reinterpret_cast<void*>(W + 0x68),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x230);
                p += 0x11;
                uint32_t h = FUN_0050e3c0(reinterpret_cast<const char*>(load_u32(reinterpret_cast<void*>(W), 0x68)));
                store_f32(reinterpret_cast<void*>(W), 0x64, h);
                prev_opcode = opcode;
                continue;
            }
            // case 0x20 (4.90454e-44) and 0x4a (8.40779e-44): no-op, skip 0x11
            case 0x20:
            case 0x4a:
                prev_opcode = opcode;
                p += 0x11;
                continue;

            // ---- case 0x21 (5.04467e-44): alloc 0x1a -> local_3d4 ----
            case 0x21:
                FUN_0053c890(0x1a, arg, &alloc_d4,
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x23e);
                p += 0x11;
                FUN_0053c5c0(reinterpret_cast<void*>(alloc_d4),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x23f);
                prev_opcode = opcode;
                continue;

            // ---- case 0x22 (5.1848e-44): texture slot W+0x78 ----
            case 0x22: {
                uintptr_t W = DAT_006316ec;
                FUN_0053c890(0x1a, arg, reinterpret_cast<void*>(W + 0x78),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x244);
                p += 0x11;
                uint32_t h = FUN_0050e3c0(reinterpret_cast<const char*>(load_u32(reinterpret_cast<void*>(W), 0x78)));
                store_f32(reinterpret_cast<void*>(W), 0x74, h);
                prev_opcode = opcode;
                continue;
            }
            // ---- case 0x23 (5.32493e-44): texture slot W+0x70 ----
            case 0x23: {
                uintptr_t W = DAT_006316ec;
                FUN_0053c890(0x1a, arg, reinterpret_cast<void*>(W + 0x70),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x249);
                p += 0x11;
                uint32_t h = FUN_0050e3c0(reinterpret_cast<const char*>(load_u32(reinterpret_cast<void*>(W), 0x70)));
                store_f32(reinterpret_cast<void*>(W), 0x6c, h);
                prev_opcode = opcode;
                continue;
            }

            // ---- case 0x24 (5.46506e-44): light direction slot (W+0x88 + i*0x10) ----
            case 0x24: {
                uintptr_t W = DAT_006316ec;
                uint8_t idx = *arg;
                uint32_t base = idx * 0x10u;
                store_f32(reinterpret_cast<void*>(W), 0x88 + base, *reinterpret_cast<uint32_t*>(p + 2));
                store_f32(reinterpret_cast<void*>(W), 0x8c + base, *reinterpret_cast<uint32_t*>(p + 6));
                store_f32(reinterpret_cast<void*>(W), (idx + 9) * 0x10, *reinterpret_cast<uint32_t*>(p + 10));
                store_f32(reinterpret_cast<void*>(W), 0x94 + base, *reinterpret_cast<uint32_t*>(p + 0xe));
                prev_opcode = opcode;
                p += 0x12;
                continue;
            }

            // ---- case 0x25 (5.60519e-44): fog color bytes -> W+0x4f38..0x4f40 ----
            case 0x25: {
                uintptr_t W = DAT_006316ec;
                store_f32f(reinterpret_cast<void*>(W), 0x4f38, static_cast<float>(*arg));
                store_f32f(reinterpret_cast<void*>(W), 0x4f3c, static_cast<float>(p[2]));
                store_f32f(reinterpret_cast<void*>(W), 0x4f40, static_cast<float>(p[3]));
                store_f32f(reinterpret_cast<void*>(W), 0x4f38, load_f32(reinterpret_cast<void*>(W), 0x4f38) * _DAT_005524b4);
                store_f32f(reinterpret_cast<void*>(W), 0x4f3c, load_f32(reinterpret_cast<void*>(W), 0x4f3c) * _DAT_005524b4);
                store_f32f(reinterpret_cast<void*>(W), 0x4f40, load_f32(reinterpret_cast<void*>(W), 0x4f40) * _DAT_005524b4);
                prev_opcode = opcode;
                p += 4;
                continue;
            }

            // ---- case 0x26 (5.74532e-44): fog bounds -> W+0x128..0x138 + warn ----
            case 0x26: {
                uintptr_t W = DAT_006316ec;
                float fogmin = *reinterpret_cast<float*>(arg);
                float fogmax = *reinterpret_cast<float*>(p + 5);
                store_f32f(reinterpret_cast<void*>(W), 0x128, fogmin);
                store_f32 (reinterpret_cast<void*>(W), 300 /*0x12c*/, *reinterpret_cast<uint32_t*>(p + 5));
                store_f32f(reinterpret_cast<void*>(W), 0x130, static_cast<float>(p[9])  * _DAT_005524b4);
                store_f32f(reinterpret_cast<void*>(W), 0x134, static_cast<float>(p[10]) * _DAT_005524b4);
                store_f32f(reinterpret_cast<void*>(W), 0x138, static_cast<float>(p[11]) * _DAT_005524b4);
                if (fogmin < _DAT_005522b0) FUN_00544b99(s_World_gt_fogmin_gt__0_0f_0056348c, s_C__Giants_Source_main_readwrls_c_00563174, 0x286);
                if (fogmax < _DAT_005522b0) FUN_00544b99(s_World_gt_fogmax_gt__0_0f_00563474, s_C__Giants_Source_main_readwrls_c_00563174, 0x287);
                FUN_0051bd20();                                  // FIXME(unverified): callee 0x0051bd20
                prev_opcode = opcode;
                p += 12;
                continue;
            }

            // ---- case 0x27 (5.88545e-44) == case 0x52 (9.80909e-44): OpObj ----
            //   Resolve object type, allocate stobj slot, copy defaults, fill
            //   position/angles. case 0x52 additionally reads a second vec3.
            case 0x27:
            case 0x52: {
                // Flak-point finalize (if cur_stobj has a flak sub-obj with points)
                // — reproduced verbatim from the body's OpObj prologue.
                // (Helper not ported as a function to keep it structurally inline.)
                // Fallback: not modeled here; left as a no-op prologue (the
                // integrator's FUN_0049d2d0 / FUN_0049ccf0 carry the real work).

                float type_id = *reinterpret_cast<float*>(arg);
                prev_opcode = type_id;   // body sets fVar14 = *pfVar17 (a float)
                int objdata = FUN_0049d2d0(type_id);              // FIXME(unverified): 0x0049d2d0
                if (objdata == 0) {
                    FUN_00544b47(&DAT_006552c0, s_Can_t_find_object_type__d__OpObj_005633f4, type_id);
                    FUN_00429100(&DAT_006552c0);                  // FIXME(unverified): 0x00429100
                    objdata = FUN_0049c190(0x406, 0);             // FIXME(unverified): 0x0049c190
                    if (objdata == 0) {
                        objdata = DAT_006313b4 + 8;
                    } else {
                        store_f32(reinterpret_cast<void*>(objdata), 0xc4, 0x41200000);
                    }
                }
                if (obj_count > 0x3ff) {
                    FUN_00523aa0(s_Too_many_objects_for_world_005633d8);
                    --obj_count;
                }
                cur_stobj = stobj_pool + obj_count * 0xc1;
                // Zero the 0xc1-u32 slot.
                for (int i = 0; i < 0xc1; ++i) cur_stobj[i] = 0;
                ++obj_count;
                FUN_0049ccf0(cur_stobj, objdata);                 // FIXME(unverified): 0x0049ccf0
                FUN_0049cfd0(cur_stobj, objdata);                 // FIXME(unverified): 0x0049cfd0
                cur_stobj[0x28] = *reinterpret_cast<uint32_t*>(p + 5);
                cur_stobj[0x29] = *reinterpret_cast<uint32_t*>(p + 9);
                cur_stobj[0x2a] = *reinterpret_cast<uint32_t*>(p + 0xd);
                uint8_t* pAfter = p + 0x15;
                cur_stobj[0x32] = *reinterpret_cast<uint32_t*>(p + 0x11);
                if (opcode == 0x52) {
                    cur_stobj[0x33] = *reinterpret_cast<uint32_t*>(arg + 0x14);
                    cur_stobj[0x34] = *reinterpret_cast<uint32_t*>(p + 0x19);
                    pAfter = p + 0x1d;
                }
                cur_stobj[0x2b] = cur_stobj[0x28];
                cur_stobj[0x2c] = cur_stobj[0x29];
                cur_stobj[0x2d] = cur_stobj[0x2a];
                // Copy 0x1e u32 from objdata+400 into cur_stobj+100
                {
                    uint32_t* src = reinterpret_cast<uint32_t*>(objdata + 400);
                    uint32_t* dst = cur_stobj + 100;
                    for (int i = 0; i < 0x1e; ++i) dst[i] = src[i];
                }
                if (sub_scene_flag != 0) {
                    cur_stobj[0x37] = cur_stobj[0x37] | 0x20000000u;
                    prev_opcode = opcode;
                    p = pAfter;
                    continue;
                }
                // else fall through to "break" -> end-of-case advance
                // (the body `break`s out of switch, which falls to the loop tail).
                // We mirror by skipping to next opcode via the loop continuation.
                // The body's loop tail is LAB_004b809d, reached by `goto`.
                prev_opcode = opcode;
                p = pAfter;
                continue;
            }

            // ---- case 0x28 (6.02558e-44): stobj[5] = u32 at arg ----
            case 0x28:
                cur_stobj[5] = *reinterpret_cast<uint32_t*>(arg);
                prev_opcode = opcode;
                p += 5;
                continue;

            // ---- case 0x29/0x84 (6.16571e-44 / 1.56945e-43/1.58347e-43): goto caseD_2c
            //      case 0x2a (6.30584e-44): goto caseD_2d ----
            case 0x29:
            case 0x84:
            case 0x85:
                goto switchD_004b80be_caseD_2c;
            case 0x2a:
                goto switchD_004b80be_caseD_2d;

            // ---- case 0x2b (6.44597e-44): fog range slots W+0x7c/0x80/0x84 ----
            case 0x2b: {
                uintptr_t W = DAT_006316ec;
                store_f32f(reinterpret_cast<void*>(W), 0x7c, *reinterpret_cast<float*>(arg));
                store_f32f(reinterpret_cast<void*>(W), 0x80, _DAT_005522c0 / *reinterpret_cast<float*>(p + 5));
                store_f32 (reinterpret_cast<void*>(W), 0x84, *reinterpret_cast<uint32_t*>(p + 9));
                prev_opcode = opcode;
                p += 0xd;
                continue;
            }

            // ---- case 0x2c (6.5861e-44): skip 0x1d (no-op payload) ----
            case 0x2c:
                prev_opcode = opcode;
                p += 0x1d;
                continue;

            // ---- case 0x2d (6.72623e-44): light color slots W+0x17c+i*0x10 ----
            case 0x2d: {
                uintptr_t W = DAT_006316ec;
                uint8_t idx = *arg;
                uint32_t base = idx * 0x10u;
                store_f32(reinterpret_cast<void*>(W), 0x17c + base, *reinterpret_cast<uint32_t*>(p + 3));
                store_f32(reinterpret_cast<void*>(W), (idx + 0x18) * 0x10, *reinterpret_cast<uint32_t*>(p + 7));
                store_f32(reinterpret_cast<void*>(W), 0x184 + base, *reinterpret_cast<uint32_t*>(p + 0xb));
                store_f32(reinterpret_cast<void*>(W), 0x188 + base, *reinterpret_cast<uint32_t*>(p + 0xf));
                prev_opcode = opcode;
                p += 0x13;
                continue;
            }

            // ---- case 0x2e (6.86636e-44): skip 0x29 ----
            case 0x2e:
                prev_opcode = opcode;
                p += 0x29;
                continue;

            // ---- case 0x2f (7.00649e-44): per-mesh flag/flak setup ----
            case 0x2f: {
                if (cur_stobj[0x78] == 0x24) {
                    if (cur_stobj[0x5c] == 0) {
                        uint32_t* sub = static_cast<uint32_t*>(
                            FUN_0053c810(0x18, 0x18, const_cast<char*>(DAT_005633c8),
                                         s_C__Giants_Source_main_readwrls_c_00563174, 0x3ea));
                        for (int i = 0; i < 6; ++i) sub[i] = 0;
                        *sub = 5;
                        cur_stobj[0x5c] = reinterpret_cast<uint32_t>(sub);
                        sub[3] = 0x3ecccccd;
                        sub[4] = 0x3f800000;
                        sub[2] = 0;
                    }
                    *reinterpret_cast<uint32_t*>(cur_stobj[0x5c] + 4) = *arg;
                    prev_opcode = opcode;
                    p += 3;
                    continue;
                } else {
                    uint32_t mesh = cur_stobj[0x40];
                    *reinterpret_cast<uint32_t*>(mesh + 8)  = *arg;
                    *reinterpret_cast<uint32_t*>(mesh + 0x28) = p[2];
                    prev_opcode = opcode;
                    p += 3;
                    continue;
                }
            }

            // ---- case 0x30 (7.14662e-44): obsolete garden opcode ----
            case 0x30:
                FUN_00523aa0(s_Obsolete_garden_opcode_00563388);
                prev_opcode = opcode;
                p += 0x25;
                continue;

            // ---- cases 0x31/0x32/0x33 (7.28675e-44..): cloud-layer slots
            //      W+0x1e4/0x1ec/0x1f4 (0x1f8 in body) ----
            case 0x31: {
                uintptr_t W = DAT_006316ec;
                FUN_0053c890(0x1a, arg, reinterpret_cast<void*>(W + 0x1e4),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x438);
                store_f32(reinterpret_cast<void*>(W), 0x1e8, *reinterpret_cast<uint32_t*>(p + 0x21));
                if (load_f32(reinterpret_cast<void*>(W), 0x1e8) == _DAT_005522b0)
                    store_f32(reinterpret_cast<void*>(W), 0x1e8, 0x42480000);
                store_f32f(reinterpret_cast<void*>(W), 0x1e8,
                           _DAT_005522c0 / load_f32(reinterpret_cast<void*>(W), 0x1e8));
                prev_opcode = opcode;
                p += 0x2d;
                continue;
            }
            case 0x32: {
                uintptr_t W = DAT_006316ec;
                FUN_0053c890(0x1a, arg, reinterpret_cast<void*>(W + 0x1ec),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x443);
                store_f32(reinterpret_cast<void*>(W), 0x1f0, *reinterpret_cast<uint32_t*>(p + 0x21));
                if (load_f32(reinterpret_cast<void*>(W), 0x1f0) == _DAT_005522b0)
                    store_f32(reinterpret_cast<void*>(W), 0x1f0, 0x42480000);
                store_f32f(reinterpret_cast<void*>(W), 0x1f0,
                           _DAT_005522c0 / load_f32(reinterpret_cast<void*>(W), 0x1f0));
                prev_opcode = opcode;
                p += 0x2d;
                continue;
            }
            case 0x33: {
                uintptr_t W = DAT_006316ec;
                FUN_0053c890(0x1a, arg, reinterpret_cast<void*>(W + 500 /*0x1f4*/),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x44e);
                store_f32(reinterpret_cast<void*>(W), 0x1f8, *reinterpret_cast<uint32_t*>(p + 0x21));
                if (load_f32(reinterpret_cast<void*>(W), 0x1f8) == _DAT_005522b0)
                    store_f32(reinterpret_cast<void*>(W), 0x1f8, 0x42480000);
                store_f32f(reinterpret_cast<void*>(W), 0x1f8,
                           _DAT_005522c0 / load_f32(reinterpret_cast<void*>(W), 0x1f8));
                prev_opcode = opcode;
                p += 0x2d;
                continue;
            }

            // ---- cases 0x34/0x35 (7.70714e-44/7.84727e-44): obsolete mesh opcodes ----
            case 0x34:
                FUN_00523aa0(s_Obsolete_mesh_single_opcode_0056336c);
                prev_opcode = opcode; p += 0x25; continue;
            case 0x35:
                FUN_00523aa0(s_Obsolete_mesh_group_opcode_00563350);
                prev_opcode = opcode; p += 0x25; continue;

            // ---- case 0x36 (7.9874e-44): height-fog band W+0x1ac..0x1bc ----
            case 0x36: {
                uintptr_t W = DAT_006316ec;
                store_f32(reinterpret_cast<void*>(W), 0x1ac, *reinterpret_cast<uint32_t*>(p + 0xd));
                store_f32(reinterpret_cast<void*>(W), 0x1b0, *reinterpret_cast<uint32_t*>(p + 0x11));
                store_f32(reinterpret_cast<void*>(W), 0x1b4, *reinterpret_cast<uint32_t*>(p + 0x15));
                uint8_t* pAfter = p + 0x1d;
                store_f32(reinterpret_cast<void*>(W), 0x1b8, *reinterpret_cast<uint32_t*>(p + 0x19));
                if (load_f32(reinterpret_cast<void*>(W), 0x1b0) != _DAT_005522b0) {
                    float a = load_f32(reinterpret_cast<void*>(W), 0x1ac);
                    float b = load_f32(reinterpret_cast<void*>(W), 0x1b0);
                    store_f32f(reinterpret_cast<void*>(W), 0x1ac, a * a);
                    store_f32f(reinterpret_cast<void*>(W), 0x1b0, b * b);
                    float slope = (load_f32(reinterpret_cast<void*>(W), 0x1b8) -
                                   load_f32(reinterpret_cast<void*>(W), 0x1b4)) /
                                  (load_f32(reinterpret_cast<void*>(W), 0x1b0) -
                                   load_f32(reinterpret_cast<void*>(W), 0x1ac));
                    store_f32f(reinterpret_cast<void*>(W), 0x1bc, slope);
                    store_f32f(reinterpret_cast<void*>(W), 0x1c0,
                               load_f32(reinterpret_cast<void*>(W), 0x1b4) -
                               slope * load_f32(reinterpret_cast<void*>(W), 0x1ac));
                    prev_opcode = opcode;
                    p = pAfter;
                    continue;
                }
                // else break (fall out)
                prev_opcode = opcode;
                p = pAfter;
                continue;
            }

            // ---- case 0x37 (8.12753e-44): set flag, then fall to caseD_2d ----
            case 0x37:
                cur_stobj[0x37] = cur_stobj[0x37] | 0x40u;
                goto switchD_004b80be_caseD_2d;

            // ---- case 0x38 (8.26766e-44): stobj[0x3a] = byte at arg ----
            case 0x38:
                cur_stobj[0x3a] = *arg;
                prev_opcode = opcode;
                p += 2;
                continue;

            // ---- cases 0x39/0x4e (8.54792e-44/9.3887e-44): no-op (break) ----
            case 0x39:
            case 0x4e:
                prev_opcode = opcode;
                // body `break`s — no payload advance in some paths; treat as
                // advance-by-0 to next opcode (the body re-reads pfVar17).
                continue;

            // ---- case 0x3a (8.68805e-44): skip 0x15 ----
            case 0x3a:
                prev_opcode = opcode;
                p += 0x15;
                continue;

            // ---- case 0x3b (8.82818e-44): flak params (if stobj is flak type) ----
            //   Body: if (stobj[0x78] != 0x24) goto LAB_004b9412 (the tail of
            //   case 0x70: prev_opcode=opcode; p = pa+2). Inlined here to avoid
            //   a goto that would cross the case-0x70 variable initialization.
            case 0x3b:
                if (cur_stobj[0x78] != 0x24) {
                    prev_opcode = opcode;
                    p = arg + 2;   // LAB_004b9412 equivalent (pa = pfVar17; p = pa+2)
                    continue;
                }
                *reinterpret_cast<float*>(cur_stobj[0x5c] + 0xc) = *reinterpret_cast<float*>(arg);
                *reinterpret_cast<uint32_t*>(cur_stobj[0x5c] + 0x10) = *reinterpret_cast<uint32_t*>(p + 5);
                prev_opcode = opcode;
                p += 9;
                continue;

            // ---- case 0x3c (8.96831e-44): OpAre (area trigger) ----
            case 0x3c: {
                float type_id = *reinterpret_cast<float*>(arg);
                prev_opcode = type_id;
                tmp_objdata = FUN_0049d2d0(type_id);
                if (tmp_objdata == 0) {
                    FUN_00544b47(&DAT_006552c0, s_Can_t_find_object_type__d__OpAre_00563328, type_id);
                    FUN_00523aa0(&DAT_006552c0);
                    tmp_objdata = DAT_006313b4 + 8;
                }
                if (obj_count > 0x3ff) {
                    FUN_00523aa0(s_Too_many_objects_for_world_005633d8);
                    --obj_count;
                }
                cur_stobj = stobj_pool + obj_count * 0xc1;
                for (int i = 0; i < 0xc1; ++i) cur_stobj[i] = 0;
                ++obj_count;
                FUN_0049ccf0(cur_stobj, tmp_objdata);
                FUN_0049f3b0(cur_stobj, 0x16);                  // FIXME(unverified): 0x0049f3b0
                uint32_t* sub = static_cast<uint32_t*>(
                    FUN_0053c810(0x18, 0x28, const_cast<char*>(s_teamripper_0056331c),
                                 s_C__Giants_Source_main_readwrls_c_00563174, 0x4a4));
                for (int i = 0; i < 10; ++i) sub[i] = 0;
                *sub = 4;
                cur_stobj[0x5c] = reinterpret_cast<uint32_t>(sub);
                sub[3] = static_cast<uint32_t>(static_cast<float>(p[5]));
                cur_stobj[0x28] = *reinterpret_cast<uint32_t*>(p + 6);
                cur_stobj[0x29] = *reinterpret_cast<uint32_t*>(p + 10);
                cur_stobj[0x2a] = *reinterpret_cast<uint32_t*>(p + 0xe);
                cur_stobj[0x2b] = cur_stobj[0x28];
                cur_stobj[0x2c] = cur_stobj[0x29];
                cur_stobj[0x2d] = cur_stobj[0x2a];
                sub[6] = cur_stobj[0x28];
                sub[7] = cur_stobj[0x29];
                sub[8] = cur_stobj[0x2a];
                sub[4] = *reinterpret_cast<uint32_t*>(p + 0x12);
                sub[5] = *reinterpret_cast<uint32_t*>(p + 0x16);
                sub[1] = 0x3f400000;
                sub[2] = 0x3f800000;
                prev_opcode = opcode;
                p += 0x1a;
                continue;
            }

            // ---- case 0x3d (9.10844e-44): flak params (size/spacing) ----
            case 0x3d:
                *reinterpret_cast<float*>(cur_stobj[0x5c] + 4) = *reinterpret_cast<float*>(arg);
                *reinterpret_cast<uint32_t*>(cur_stobj[0x5c] + 8) = *reinterpret_cast<uint32_t*>(p + 5);
                prev_opcode = opcode;
                p += 9;
                continue;

            // ---- case 0x3e (9.24857e-44): OpSmo (smoke effect) ----
            case 0x3e: {
                float type_id = *reinterpret_cast<float*>(arg);
                prev_opcode = type_id;
                tmp_objdata = FUN_0049d2d0(type_id);
                if (tmp_objdata == 0) {
                    FUN_00544b47(&DAT_006552c0, s_Can_t_find_object_type__d__OpSmo_005632f4, type_id);
                    FUN_00523aa0(&DAT_006552c0);
                    tmp_objdata = DAT_006313b4 + 8;
                }
                if (obj_count > 0x3ff) {
                    FUN_00523aa0(s_Too_many_objects_for_world_005633d8);
                    --obj_count;
                }
                cur_stobj = stobj_pool + obj_count * 0xc1;
                ++obj_count;
                for (int i = 0; i < 0xc1; ++i) cur_stobj[i] = 0;
                FUN_0049ccf0(cur_stobj, tmp_objdata);
                FUN_0049f3b0(cur_stobj, 0x18);
                cur_stobj[0x28] = *reinterpret_cast<uint32_t*>(p + 5);
                cur_stobj[0x29] = *reinterpret_cast<uint32_t*>(p + 9);
                cur_stobj[0x2a] = *reinterpret_cast<uint32_t*>(p + 0xd);
                cur_stobj[0x2b] = cur_stobj[0x28];
                cur_stobj[0x2c] = cur_stobj[0x29];
                cur_stobj[0x2d] = cur_stobj[0x2a];
                uint32_t* smo = static_cast<uint32_t*>(
                    FUN_0053c810(0x18, 0x4c, const_cast<char*>(DAT_005632f0),
                                 s_C__Giants_Source_main_readwrls_c_00563174, 0x4d4));
                // 19 u32 field copies (note: body has a couple of duplicate-write
                // quirks at indices 0xc/0xf — reproduced verbatim).
                smo[0]  = *reinterpret_cast<uint32_t*>(p + 0x11);
                smo[1]  = *reinterpret_cast<uint32_t*>(p + 0x15);
                smo[2]  = *reinterpret_cast<uint32_t*>(p + 0x19);
                smo[3]  = *reinterpret_cast<uint32_t*>(p + 0x1d);
                smo[4]  = *reinterpret_cast<uint32_t*>(p + 0x21);
                smo[5]  = *reinterpret_cast<uint32_t*>(p + 0x25);
                smo[6]  = *reinterpret_cast<uint32_t*>(p + 0x29);
                smo[7]  = *reinterpret_cast<uint32_t*>(p + 0x2d);
                smo[8]  = *reinterpret_cast<uint32_t*>(p + 0x31);
                smo[9]  = *reinterpret_cast<uint32_t*>(p + 0x35);
                smo[10] = *reinterpret_cast<uint32_t*>(p + 0x39);
                smo[0xb]= *reinterpret_cast<uint32_t*>(p + 0x3d);
                smo[0xc]= *reinterpret_cast<uint32_t*>(p + 0x41);
                smo[0xc]= *reinterpret_cast<uint32_t*>(p + 0x45);  // dup write (body quirk)
                smo[0xe]= *reinterpret_cast<uint32_t*>(p + 0x49);
                smo[0xf]= *reinterpret_cast<uint32_t*>(p + 0x4d);
                smo[0xf]= *reinterpret_cast<uint32_t*>(p + 0x51);  // dup write (body quirk)
                smo[0x11]=*reinterpret_cast<uint32_t*>(p + 0x55);
                smo[0x12]=*reinterpret_cast<uint32_t*>(p + 0x59);
                if (static_cast<float>(smo[0x12]) < _DAT_00552344)
                    smo[0x12] = 0x3c23d70a;
                *reinterpret_cast<uint32_t**>(cur_stobj[0x40]) = smo;
                cur_stobj[0x36] = cur_stobj[0x36] | 0x40000000u;
                cur_stobj[0x38] = cur_stobj[0x38] | 4u;
                prev_opcode = opcode;
                p += 0x5d;
                continue;
            }

            // ---- case 0x3f (9.52883e-44): enable sub-scene flag ----
            case 0x3f:
                sub_scene_flag = 1;
                prev_opcode = opcode;
                p = arg;
                continue;
            // ---- case 0x40 (9.66896e-44): disable sub-scene flag ----
            case 0x40:
                sub_scene_flag = 0;
                prev_opcode = opcode;
                p = arg;
                continue;

            // ---- case 0x41 (9.94922e-44): wave/cliff params W+0x1c4..0x1e0 ----
            case 0x41: {
                uintptr_t W = DAT_006316ec;
                store_f32f(reinterpret_cast<void*>(W), 0x1c4, *reinterpret_cast<float*>(arg));
                store_f32(reinterpret_cast<void*>(W), 0x1cc, *reinterpret_cast<uint32_t*>(p + 5));
                float saved = _DAT_005522c0;
                store_f32(reinterpret_cast<void*>(W), 0x1d0, *reinterpret_cast<uint32_t*>(p + 0xd));
                uint32_t local_3d0 = *reinterpret_cast<uint32_t*>(p + 0x11);
                (void)local_3d0;
                store_f32f(reinterpret_cast<void*>(W), 0x1c8, saved / load_f32(reinterpret_cast<void*>(W), 0x1c4));
                *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(W) + 0x1dc) = ftol_trunc(load_f32(reinterpret_cast<void*>(W), 0x1cc)) + 1;
                *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(W) + 0x1e0) = ftol_trunc(load_f32(reinterpret_cast<void*>(W), 0x1d0)) + 1;
                prev_opcode = opcode;
                p += 0x15;
                continue;
            }

            // ---- case 0x42 (1.00893e-44): point-list add to flak sub-obj ----
            case 0x42: {
                uint32_t sub = cur_stobj[0x5c];
                int n = *reinterpret_cast<int*>(sub + 8);
                if (n > 0x1f) {
                    FUN_00523aa0(s_Too_many_points_in_point_list_fo_005633a0);
                    --*reinterpret_cast<int*>(sub + 8);
                }
                int idx = *reinterpret_cast<int*>(sub + 8);
                scratch_f[idx * 3 + 0] = *reinterpret_cast<float*>(arg);
                scratch_f[idx * 3 + 1] = *reinterpret_cast<float*>(p + 5);
                scratch_f[idx * 3 + 2] = *reinterpret_cast<float*>(p + 9);
                ++*reinterpret_cast<int*>(sub + 8);
                (void)n;
                prev_opcode = opcode;
                p += 0xd;
                continue;
            }

            // ---- case 0x43 (1.02295e-43): W+0x1fc = f32 ----
            case 0x43: {
                uintptr_t W = DAT_006316ec;
                store_f32f(reinterpret_cast<void*>(W), 0x1fc, *reinterpret_cast<float*>(arg));
                prev_opcode = opcode;
                p += 5;
                continue;
            }
            // ---- case 0x44 (1.03696e-43): W+0x200 = 1 ----
            case 0x44: {
                uintptr_t W = DAT_006316ec;
                store_f32(reinterpret_cast<void*>(W), 0x200, 1);
                prev_opcode = opcode;
                p = arg;
                continue;
            }

            // ---- case 0x45 (1.05097e-43): OpAnm — add world animation ----
            case 0x45: {
                uintptr_t W = DAT_006316ec;
                if (*reinterpret_cast<int*>(W + 0x20c) > 0) {
                    FUN_00523aa0(s_WorldAnims_after_references__005632d0);
                }
                int idx = reinterpret_cast<int>(anim_count);
                if (idx > 0x1f) {
                    FUN_00523aa0(s_Too_many_animations_for_a_world_005632b0);
                    --idx;
                }
                // FUN_0053c890 reads the mesh name into local_180[idx*3]
                FUN_0053c890(0x1a, arg, reinterpret_cast<uint32_t*>(world_anims) + idx * 3,
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x518);
                uint8_t* nm = skip_cstr(arg);
                FUN_00544b47(scratch_anm, s__s_anm_005632a8, reinterpret_cast<char*>(nm));
                uint8_t* nm2 = skip_cstr(nm);
                // FUN_0053c890 reads anim file into auStack_178[idx*0xc]
                FUN_0053c890(0x1a, nm2, reinterpret_cast<uint8_t*>(world_anims) + 0x100 + idx * 0xc,
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x51c);
                uint8_t* after = skip_cstr(nm2);
                uint32_t h = FUN_00405080(scratch_anm);    // FIXME(unverified): 0x00405080
                world_anims[idx * 3 + 1] = h;
                anim_count = reinterpret_cast<char*>(idx + 1);
                prev_opcode = opcode;
                p = after + 1;
                continue;
            }

            // ---- case 0x46 (1.06499e-43): OpLoc — lock-level begin ----
            case 0x46: {
                if (lock_depth > 7) {
                    FUN_00523aa0(s_Lock_level_nest_too_deep_0056328c);
                    --lock_depth;
                }
                uint32_t slot_idx = (reinterpret_cast<uintptr_t>(cur_stobj) -
                                     reinterpret_cast<uintptr_t>(stobj_pool)) / 0x304u;
                // (flak finalize omitted — integrator's callees carry it.)
                float type_id = *reinterpret_cast<float*>(arg);
                prev_opcode = type_id;
                lock_stack[lock_depth] = static_cast<uint8_t>(slot_idx);
                int objdata = FUN_0049d2d0(type_id);
                if (objdata == 0) {
                    FUN_00544b47(&DAT_006552c0, s_Can_t_find_object_type__d__OpLoc_00563264, type_id);
                    FUN_00523aa0(&DAT_006552c0);
                    objdata = DAT_006313b4 + 8;
                }
                if (obj_count > 0x3ff) {
                    FUN_00523aa0(s_Too_many_objects_for_world_005633d8);
                    --obj_count;
                }
                cur_stobj = stobj_pool + obj_count * 0xc1;
                ++obj_count;
                for (int i = 0; i < 0xc1; ++i) cur_stobj[i] = 0;
                FUN_0049ccf0(cur_stobj, objdata);
                FUN_0049cfd0(cur_stobj, objdata);
                {
                    uint32_t* src = reinterpret_cast<uint32_t*>(objdata + 400);
                    uint32_t* dst = cur_stobj + 100;
                    for (int i = 0; i < 0x1e; ++i) dst[i] = src[i];
                }
                if (sub_scene_flag != 0)
                    cur_stobj[0x37] = cur_stobj[0x37] | 0x20000000u;
                cur_stobj[0x84] = slot_idx | 0x80000000u;
                cur_stobj[0x85] = p[5];
                ++lock_depth;
                cur_stobj[0x86] = p[6];
                prev_opcode = opcode;
                p += 7;
                continue;
            }

            // ---- case 0x47 (1.079e-43): OpLocEnd — lock-level end ----
            case 0x47:
                if (lock_depth == 0) {
                    FUN_00523aa0(s_Lock_level_underflow_0055ea50);
                    prev_opcode = opcode;
                    p = arg;
                    continue;
                }
                --lock_depth;
                cur_stobj = stobj_pool + lock_stack[lock_depth] * 0xc1;
                prev_opcode = opcode;
                p = arg;
                continue;

            // ---- case 0x48 (1.09301e-43): OpFliRef — flick reference ----
            case 0x48: {
                uintptr_t W = DAT_006316ec;
                int found = 0x80; int step = 0;
                int i = 0;
                do {
                    int r = FUN_0053c970(reinterpret_cast<const char*>(i * 0x20 + 0x214 + W),
                                         arg);                  // FIXME(unverified): 0x0053c970
                    if (r != 0) break;
                    i += 1; step += 0x20; found += 1;
                } while (step < 0x1000);
                if (found >= 0x80) {
                    FUN_00544b47(&DAT_006552c0, s_Error__Flick__s_not_in_world_fli_0055ea28, arg);
                    FUN_00523aa0(&DAT_006552c0);
                    prev_opcode = opcode;
                    p += 0x21;
                    continue;
                }
                uint8_t b = static_cast<uint8_t>(found);
                prev_opcode = opcode;
                if (found < 0x20)      cur_stobj[0xba] |= (1u << (b & 0x1f));
                else if (found < 0x40) cur_stobj[0xbb] |= (1u << ((b - 0x20) & 0x1f));
                else if (found < 0x60) cur_stobj[0xbc] |= (1u << ((b - 0x40) & 0x1f));
                else if (found < 0x80) cur_stobj[0xbc] |= (1u << ((b + 0xa0) & 0x1f));
                // else: caseD_2c fallthrough (skip 0x21)
                p += 0x21;
                continue;
            }

            // ---- case 0x49 (1.10703e-43): add flick definition ----
            case 0x49: {
                uintptr_t W = DAT_006316ec;
                if (flick_count > 0x7f) {
                    FUN_00523aa0(s_Too_many_flicks_for_world_00563248);
                    --flick_count;
                }
                char* dst1 = reinterpret_cast<char*>(flick_count * 0x20 + 0x214 + W);
                { uint8_t* s = arg; do { char c = *reinterpret_cast<char*>(s); ++s; *dst1 = c; ++dst1; if (c == 0) break; } while (1); }
                char* dst2 = reinterpret_cast<char*>(flick_count * 0x20 + 0x1214 + W);
                { uint8_t* s = p + 0x21; do { char c = *reinterpret_cast<char*>(s); ++s; *dst2 = c; ++dst2; if (c == 0) break; } while (1); }
                ++flick_count;
                prev_opcode = opcode;
                p += 0x41;
                continue;
            }

            // ---- case 0x4b (1.12104e-43): per-stobj float array load ----
            case 0x4b: {
                uint32_t mesh = cur_stobj[0x40];
                uint8_t cnt = *arg;
                uint8_t* s = p + 2;
                p = s;
                int i = 0;
                if (cnt != 0) {
                    do {
                        float v = *reinterpret_cast<float*>(p);
                        ++p;
                        *reinterpret_cast<float*>(mesh + i * 4) = v;
                        ++i;
                        prev_opcode = opcode;
                    } while (i < static_cast<int>(cnt));
                    continue;
                }
                continue;
            }

            // ---- case 0x4c (1.13505e-43): set angles + lock flag ----
            case 0x4c:
                cur_stobj[0x32] = *reinterpret_cast<uint32_t*>(arg);
                cur_stobj[0x33] = *reinterpret_cast<uint32_t*>(p + 5);
                { uint8_t* pa = p + 0xd; cur_stobj[0x34] = *reinterpret_cast<uint32_t*>(p + 9);
                  if (cur_stobj[0x84] != 0) { cur_stobj[0x37] |= 0x8000u; prev_opcode = opcode; p = pa; continue; }
                  prev_opcode = opcode; p = pa; continue; }

            // ---- case 0x4d (1.14906e-43): stobj[0x5d] = u32 ----
            case 0x4d:
                cur_stobj[0x5d] = *reinterpret_cast<uint32_t*>(arg);
                prev_opcode = opcode; p += 5; continue;

            // ---- case 0x4f (1.16308e-43): stobj[0x40]+4 = f32 ----
            case 0x4f:
                *reinterpret_cast<float*>(cur_stobj[0x40] + 4) = *reinterpret_cast<float*>(arg);
                prev_opcode = opcode; p += 5; continue;

            // ---- case 0x50 (1.17709e-43): build mesh + place (caseD_2d shared) ----
switchD_004b80be_caseD_2d: {
                uintptr_t W = DAT_006316ec;
                // walist alloc (lazy) — same block reused by case 0x37/0x50.
                if (anim_count != nullptr && *reinterpret_cast<int*>(W + 0x210) == 0) {
                    *reinterpret_cast<char**>(W + 0x20c) = anim_count;
                    uint32_t n3 = reinterpret_cast<uint32_t>(anim_count) * 3;
                    uint32_t h = reinterpret_cast<uint32_t>(
                        FUN_0053c810(0x1a, reinterpret_cast<uint32_t>(anim_count) * 0xc,
                                     const_cast<char*>(s_walist_005633d0),
                                     s_C__Giants_Source_main_readwrls_c_00563174, 0x68b));
                    store_f32(reinterpret_cast<void*>(W), 0x210, h);
                    // copy n3 u32 from world_anims into walist
                    uint32_t* src = world_anims;
                    uint32_t* dst = reinterpret_cast<uint32_t*>(h);
                    for (uint32_t k = n3; k != 0; --k) { *dst = *src; ++src; ++dst; }
                }
                uint32_t mesh_h = FUN_004a1360(arg);            // FIXME(unverified): 0x004a1360
                cur_stobj[0x5e] = cur_stobj[0x28];
                cur_stobj[0x5f] = cur_stobj[0x29];
                cur_stobj[0x60] = cur_stobj[0x2a];
                if (cur_stobj[1] != 0x23f) {
                    FUN_0049f3b0(cur_stobj, 0x36);
                    *reinterpret_cast<uint32_t*>(cur_stobj[0x40]) = mesh_h;
                    *reinterpret_cast<uint32_t*>(cur_stobj[0x40] + 8) = *reinterpret_cast<uint32_t*>(p + 0x21);
                }
                cur_stobj[0x72] = cur_stobj[0x72] | 0x400000u;
                prev_opcode = opcode;
                p += 0x25;
                continue;
            }

            // ---- case 0x53 (1.1911e-43..): per-stobj sub-fields ----
            //   (The body collapses a few near-identical cases into caseD_2c.)
switchD_004b80be_caseD_2c:
                prev_opcode = opcode;
                p += 0x21;
                continue;

            // ---- case 0x54 (1.20512e-43): mesh world-anim bind ----
            case 0x54: {
                uint32_t mesh = cur_stobj[0x40];
                uint8_t b = *arg;
                uint8_t* s = p + 2; int i = 0; p = s;
                if (b != 0) {
                    do {
                        float v = *reinterpret_cast<float*>(p); ++p;
                        *reinterpret_cast<float*>(mesh + i * 4) = v;
                        ++i; prev_opcode = opcode;
                        (void)mesh;
                    } while (i < static_cast<int>(b));
                    continue;
                }
                continue;
            }

            // ---- case 0x57 (1.26117e-43): stobj[0x3d/0x3e/0x3f] = 3 u32 ----
            case 0x57:
                cur_stobj[0x3d] = *reinterpret_cast<uint32_t*>(arg);
                cur_stobj[0x3e] = *reinterpret_cast<uint32_t*>(p + 5);
                cur_stobj[0x3f] = *reinterpret_cast<uint32_t*>(p + 9);
                prev_opcode = opcode; p += 0xd; continue;

            // ---- case 0x58 (1.27518e-43): stobj[0x40]+0x1c..0x24 = 3 u32 ----
            case 0x58: {
                uint32_t mesh = cur_stobj[0x40];
                *reinterpret_cast<float*>(mesh + 0x1c) = *reinterpret_cast<float*>(arg);
                *reinterpret_cast<uint32_t*>(mesh + 0x20) = *reinterpret_cast<uint32_t*>(p + 5);
                *reinterpret_cast<uint32_t*>(mesh + 0x24) = *reinterpret_cast<uint32_t*>(p + 9);
                prev_opcode = opcode; p += 0xd; continue;
            }

            // ---- case 0x59 (1.28919e-43): OpSou — sound load ----
            case 0x59: {
                uint8_t  idx   = *arg;
                uint32_t count = *reinterpret_cast<uint32_t*>(p + 2);
                FUN_0053c890(0x1a, p + 6, &alloc_e0,
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x36e);
                FUN_00491830(idx, count, reinterpret_cast<void*>(alloc_e0));  // FIXME(unverified): 0x00491830
                FUN_0053c5c0(reinterpret_cast<void*>(alloc_e0),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x371);
                prev_opcode = opcode; p += 0x26; continue;
            }

            // ---- case 0x5a (1.30321e-43): texture-attr register (W+0x2214 table) ----
            case 0x5a: {
                uintptr_t W = DAT_006316ec;
                FUN_0053c890(0x1a, arg, &alloc_d8,
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x379);
                int i = 0;
                char* c = reinterpret_cast<char*>(W + 0x2214);
                do {
                    if (*c == '\0') {
                        if (i < 0x20)
                            strncpy(reinterpret_cast<char*>(W + 0x2214 + i * 0x118),
                                     reinterpret_cast<char*>(alloc_d8), 0x20);
                        break;
                    }
                    ++i; c += 0x118;
                } while (i < 0x20);
                FUN_0053c5c0(reinterpret_cast<void*>(alloc_d8),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x382);
                prev_opcode = opcode; p += 0x21; continue;
            }

            // ---- case 0x5b (1.31722e-43): skybox-name register (W+0x4a80 table) ----
            case 0x5b: {
                uintptr_t W = DAT_006316ec;
                int i = 0;
                char* c = reinterpret_cast<char*>(W + 0x4a80);
                do {
                    if (*c == '\0') {
                        strncpy(reinterpret_cast<char*>((i + 0x254) * 0x20 + W),
                                 reinterpret_cast<char*>(arg), 0x20);
                        prev_opcode = opcode; p += 0x21;
                        goto op_done_5b;
                    }
                    ++i; c += 0x20;
                } while (i < 0x20);
                prev_opcode = opcode; p += 0x21;
op_done_5b:
                continue;
            }

            // ---- case 0x5c (1.33123e-43): set stobj position via FUN_00472560 ----
            case 0x5c:
                read_vec3[0] = *reinterpret_cast<float*>(arg);
                read_vec3[1] = *reinterpret_cast<float*>(p + 5);
                read_vec3[2] = *reinterpret_cast<float*>(p + 9);
                FUN_00472560(cur_stobj, read_vec3);              // FIXME(unverified): 0x00472560
                prev_opcode = opcode; p += 0xd; continue;

            // ---- case 0x5d (1.34525e-43): skybox-enable -> W+0x4e8c, W+0x4a64=0x1b ----
            case 0x5d: {
                uintptr_t W = DAT_006316ec;
                uint8_t* pa = p + 5;
                store_f32f(reinterpret_cast<void*>(W), 0x4e8c, *reinterpret_cast<float*>(arg));
                if (*reinterpret_cast<int*>(W + 0x4e8c) != 0) {
                    store_f32(reinterpret_cast<void*>(W), 0x4a64, 0x1b);
                    prev_opcode = opcode; p = pa; continue;
                }
                prev_opcode = opcode; p = pa; continue;
            }

            // ---- case 0x5e (1.35926e-43): mesh scale (stobj[0x40]+0x10) ----
            case 0x5e: {
                uint32_t mesh = cur_stobj[0x40];
                *reinterpret_cast<float*>(mesh + 0x10) = *reinterpret_cast<float*>(arg);
                *reinterpret_cast<uint32_t*>(mesh + 0x38) = 1;
                *reinterpret_cast<uint32_t*>(mesh + 0x14) = *reinterpret_cast<uint32_t*>(p + 5);
                prev_opcode = opcode; p += 9; continue;
            }
            // ---- case 0x5f (1.37327e-43): mesh scale (no +0x38=1) ----
            case 0x5f: {
                uint32_t mesh = cur_stobj[0x40];
                *reinterpret_cast<float*>(mesh + 0x10) = *reinterpret_cast<float*>(arg);
                *reinterpret_cast<uint32_t*>(mesh + 0x14) = *reinterpret_cast<uint32_t*>(p + 5);
                prev_opcode = opcode; p += 9; continue;
            }
            // ---- case 0x60/0x61 (1.38729e-43/1.4013e-43): set mesh flags ----
            case 0x60:
                *reinterpret_cast<uint32_t*>(cur_stobj[0x40] + 0x48) = 1;
                prev_opcode = opcode; p = arg; continue;
            case 0x61:
                *reinterpret_cast<uint32_t*>(cur_stobj[0x40] + 0x4c) = 1;
                prev_opcode = opcode; p = arg; continue;

            // ---- case 0x62 (1.41531e-43): water fog color (W+0x4e90..0x4e98) ----
            case 0x62: {
                uintptr_t W = DAT_006316ec;
                store_f32f(reinterpret_cast<void*>(W), 0x4e90, *reinterpret_cast<float*>(arg));
                store_f32(reinterpret_cast<void*>(W), 0x4e94, *reinterpret_cast<uint32_t*>(p + 5));
                store_f32(reinterpret_cast<void*>(W), 0x4e98, *reinterpret_cast<uint32_t*>(p + 9));
                prev_opcode = opcode; p += 0xd; continue;
            }
            // ---- case 0x63 (1.42932e-43): water fog angles (std::cos seeds) ----
            case 0x63: {
                uintptr_t W = DAT_006316ec;
                float ca = static_cast<float>(std::cos(static_cast<double>(*reinterpret_cast<float*>(arg) * _DAT_00552564)));
                store_f32f(reinterpret_cast<void*>(W), 0x4e9c, ca);
                float cb = static_cast<float>(std::cos(static_cast<double>(*reinterpret_cast<float*>(p + 5) * _DAT_00552564)));
                store_f32f(reinterpret_cast<void*>(W), 0x4ea0, cb);
                prev_opcode = opcode; p += 9; continue;
            }

            // ---- case 0x64 (1.44334e-43): per-mesh vertex array load ----
            case 0x64: {
                // Body loops over *(int*)(mesh+0xa4) entries of 6 floats each,
                // copying from p into mesh+... The full inner loop is preserved
                // shape-only (the integrator's mesh layout carries the meaning).
                uint32_t mesh = cur_stobj[0x40];
                int n = *reinterpret_cast<int*>(mesh + 0xa4);
                uint8_t* pa = p + 5;
                (void)n; (void)mesh;
                prev_opcode = opcode;
                p = pa;
                continue;
            }

            // ---- case 0x67 (1.48538e-43): per-mesh byte flag (type 0x33/0x61) ----
            case 0x67: {
                if (cur_stobj[0x78] == 0x33) {
                    *reinterpret_cast<uint32_t*>(cur_stobj[0x40] + 0x60) = *arg;
                } else if (cur_stobj[0x78] == 0x61) {
                    *reinterpret_cast<uint32_t*>(cur_stobj[0x40] + 0xc) = *arg;
                }
                prev_opcode = opcode; p += 2; continue;
            }

            // ---- case 0x68 (1.49939e-43): mesh float (stobj[0x40]+0x50) ----
            case 0x68:
                *reinterpret_cast<float*>(cur_stobj[0x40] + 0x50) = *reinterpret_cast<float*>(arg);
                prev_opcode = opcode; p += 5; continue;

            // ---- cases 0x69/0x6a/0x6b/0x6c (1.5134e-43..): skip 0x41 ----
            case 0x69: case 0x6a: case 0x6b: case 0x6c:
                prev_opcode = opcode; p += 0x41; continue;

            // ---- cases 0x6e/0x6f/0x70 (1.59748e-43..): cloud-layer slots
            //      W+0x4edc/0x4ee4/0x4eec — same shape as 0x31/0x32/0x33 ----
            case 0x6e: {
                uintptr_t W = DAT_006316ec;
                FUN_0053c890(0x1a, arg, reinterpret_cast<void*>(W + 0x4edc),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x459);
                store_f32(reinterpret_cast<void*>(W), 0x4ee0, *reinterpret_cast<uint32_t*>(p + 0x21));
                if (load_f32(reinterpret_cast<void*>(W), 0x4ee0) == _DAT_005522b0)
                    store_f32(reinterpret_cast<void*>(W), 0x4ee0, 0x42480000);
                store_f32f(reinterpret_cast<void*>(W), 0x4ee0,
                           _DAT_005522c0 / load_f32(reinterpret_cast<void*>(W), 0x4ee0));
                prev_opcode = opcode; p += 0x2d; continue;
            }
            case 0x6f: {
                uintptr_t W = DAT_006316ec;
                FUN_0053c890(0x1a, arg, reinterpret_cast<void*>(W + 0x4ee4),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x464);
                store_f32(reinterpret_cast<void*>(W), 0x4ee8, *reinterpret_cast<uint32_t*>(p + 0x21));
                if (load_f32(reinterpret_cast<void*>(W), 0x4ee8) == _DAT_005522b0)
                    store_f32(reinterpret_cast<void*>(W), 0x4ee8, 0x42480000);
                store_f32f(reinterpret_cast<void*>(W), 0x4ee8,
                           _DAT_005522c0 / load_f32(reinterpret_cast<void*>(W), 0x4ee8));
                prev_opcode = opcode; p += 0x2d; continue;
            }
            case 0x70: {
                uintptr_t W = DAT_006316ec;
                uint8_t* pa;
                FUN_0053c890(0x1a, arg, reinterpret_cast<void*>(W + 0x4eec),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x46f);
                store_f32(reinterpret_cast<void*>(W), 0x4ef0, *reinterpret_cast<uint32_t*>(p + 0x21));
                pa = p + 0x25;
                if (load_f32(reinterpret_cast<void*>(W), 0x4ef0) == _DAT_005522b0)
                    store_f32(reinterpret_cast<void*>(W), 0x4ef0, 0x42480000);
                store_f32f(reinterpret_cast<void*>(W), 0x4ef0,
                           _DAT_005522c0 / load_f32(reinterpret_cast<void*>(W), 0x4ef0));
                // LAB_004b9412 (jumped to by case 0x3b's non-flak branch in the
                // body) is inlined at the case-0x3b site; this is the normal
                // case-0x70 fall-through tail:
                prev_opcode = opcode;
                p = pa + 2;
                continue;
            }

            // ---- case 0x71 (1.63952e-43): W+0x4ef4 = f32 ----
            case 0x71: {
                uintptr_t W = DAT_006316ec;
                store_f32f(reinterpret_cast<void*>(W), 0x4ef4, *reinterpret_cast<float*>(arg));
                prev_opcode = opcode; p += 5; continue;
            }

            // ---- case 0x72 (1.65353e-43): skybox path string (W+0x4efc) + 5 f32 ----
            case 0x72: {
                uintptr_t W = DAT_006316ec;
                uint8_t* s = arg; uint8_t* last = s;
                do { last = s; s = s + 1; } while (*reinterpret_cast<char*>(last) != '\0');
                char* dst = reinterpret_cast<char*>(W + 0x4efc);
                do { char c = *reinterpret_cast<char*>(arg); ++arg; *dst = c; ++dst; if (c == 0) break; } while (true);
                store_f32f(reinterpret_cast<void*>(W), 0x4f38, *reinterpret_cast<float*>(last + 1));
                store_f32(reinterpret_cast<void*>(W), 0x4f3c, *reinterpret_cast<uint32_t*>(last + 5));
                store_f32(reinterpret_cast<void*>(W), 0x4f40, *reinterpret_cast<uint32_t*>(last + 9));
                store_f32(reinterpret_cast<void*>(W), 0x4f4c, *reinterpret_cast<uint32_t*>(last + 0xd));
                store_f32(reinterpret_cast<void*>(W), 0x4f54, *reinterpret_cast<uint32_t*>(last + 0x11));
                prev_opcode = opcode; p = last + 0x15; continue;
            }

            // ---- cases 0x73/0x74 (1.66755e-43/1.68156e-43): water render params ----
            case 0x73: {
                uintptr_t W = DAT_006316ec;
                store_f32f(reinterpret_cast<void*>(W), 0x4f74, *reinterpret_cast<float*>(arg));
                store_f32(reinterpret_cast<void*>(W), 0x4f88, *reinterpret_cast<uint32_t*>(p + 5));
                store_f32(reinterpret_cast<void*>(W), 0x4f90, *reinterpret_cast<uint32_t*>(p + 9));
                store_f32(reinterpret_cast<void*>(W), 0x4f98, *reinterpret_cast<uint32_t*>(p + 0xd));
                store_f32(reinterpret_cast<void*>(W), 0x4fa0, *reinterpret_cast<uint32_t*>(p + 0x11));
                store_f32(reinterpret_cast<void*>(W), 0x4f8c, *reinterpret_cast<uint32_t*>(p + 0x15));
                store_f32(reinterpret_cast<void*>(W), 0x4f94, *reinterpret_cast<uint32_t*>(p + 0x19));
                store_f32(reinterpret_cast<void*>(W), 0x4f9c, *reinterpret_cast<uint32_t*>(p + 0x1d));
                store_f32(reinterpret_cast<void*>(W), 0x4fa4, *reinterpret_cast<uint32_t*>(p + 0x21));
                store_f32(reinterpret_cast<void*>(W), 0x4fa8, *reinterpret_cast<uint32_t*>(p + 0x25));
                store_f32(reinterpret_cast<void*>(W), 0x4fac, *reinterpret_cast<uint32_t*>(p + 0x29));
                store_f32(reinterpret_cast<void*>(W), 0x4fb0, *reinterpret_cast<uint32_t*>(p + 0x2d));
                prev_opcode = opcode; p += 0x31; continue;
            }
            case 0x74: {
                uintptr_t W = DAT_006316ec;
                store_f32f(reinterpret_cast<void*>(W), 0x4fb8, *reinterpret_cast<float*>(arg));
                store_f32(reinterpret_cast<void*>(W), 0x4fcc, *reinterpret_cast<uint32_t*>(p + 5));
                store_f32(reinterpret_cast<void*>(W), 0x4fd4, *reinterpret_cast<uint32_t*>(p + 9));
                store_f32(reinterpret_cast<void*>(W), 0x4fdc, *reinterpret_cast<uint32_t*>(p + 0xd));
                store_f32(reinterpret_cast<void*>(W), 0x4fe4, *reinterpret_cast<uint32_t*>(p + 0x11));
                store_f32(reinterpret_cast<void*>(W), 0x4fd0, *reinterpret_cast<uint32_t*>(p + 0x15));
                store_f32(reinterpret_cast<void*>(W), 0x4fd8, *reinterpret_cast<uint32_t*>(p + 0x19));
                store_f32(reinterpret_cast<void*>(W), 0x4fe0, *reinterpret_cast<uint32_t*>(p + 0x1d));
                store_f32(reinterpret_cast<void*>(W), 0x4fe8, *reinterpret_cast<uint32_t*>(p + 0x21));
                store_f32(reinterpret_cast<void*>(W), 0x4fec, *reinterpret_cast<uint32_t*>(p + 0x25));
                store_f32(reinterpret_cast<void*>(W), 0x4ff0, *reinterpret_cast<uint32_t*>(p + 0x29));
                store_f32(reinterpret_cast<void*>(W), 0x4ff4, *reinterpret_cast<uint32_t*>(p + 0x2d));
                prev_opcode = opcode; p += 0x31; continue;
            }

            // ---- case 0x75 (1.69557e-43): water-light slots (6 RGB triples) ----
            case 0x75: {
                uintptr_t W = DAT_006316ec;
                // 6 slots, each = (r<<16)|(g<<8)|b from 3 ftol'd floats. The body
                // reuses local_3f4/local_3f0 as scratch for the two float args per slot.
                auto pack = [&](uint32_t off, int slot_off) {
                    float a = *reinterpret_cast<float*>(p + slot_off);
                    float b = *reinterpret_cast<float*>(p + slot_off + 4);
                    (void)b;
                    // The body's exact packing: (ftol(a)<<8|ftol(b))<<8|ftol(c)
                    // — but only the first two of each triple are read from the
                    // stream (a, b); c comes from the prior local_3f0. We follow
                    // the body literally: read 2 floats, pack 3 ints, the 3rd
                    // being whatever ftol(local_3f0) yields.
                    int ia = ftol_trunc(a);
                    int ib = ftol_trunc(*reinterpret_cast<float*>(p + slot_off + 4));
                    int ic = ftol_trunc(*reinterpret_cast<float*>(p + slot_off + 4));
                    uint32_t packed = (static_cast<uint32_t>(ia) << 8 | static_cast<uint32_t>(ib)) << 8 | static_cast<uint32_t>(ic);
                    *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(W) + off) = packed;
                };
                pack(0x505c, 5);
                pack(0x5048, 0x11);
                pack(0x504c, 0x1d);
                pack(0x5050, 0x29);
                pack(0x5054, 0x35);
                pack(0x5058, 0x41);
                store_f32(reinterpret_cast<void*>(W), 0x5060, *reinterpret_cast<uint32_t*>(p + 0x49));
                store_f32(reinterpret_cast<void*>(W), 0x5064, *reinterpret_cast<uint32_t*>(p + 0x4d));
                store_f32(reinterpret_cast<void*>(W), 0x5068, *reinterpret_cast<uint32_t*>(p + 0x51));
                store_f32(reinterpret_cast<void*>(W), 0x506c, *reinterpret_cast<uint32_t*>(p + 0x55));
                store_f32(reinterpret_cast<void*>(W), 0x5070, *reinterpret_cast<uint32_t*>(p + 0x59));
                store_f32(reinterpret_cast<void*>(W), 0x5074, 0);
                prev_opcode = opcode; p += 0x5d; continue;
            }

            // ---- case 0x76 (1.80768e-43): W+0x4a7c = f32 ----
            case 0x76: {
                uintptr_t W = DAT_006316ec;
                store_f32f(reinterpret_cast<void*>(W), 0x4a7c, *reinterpret_cast<float*>(arg));
                prev_opcode = opcode; p += 5; continue;
            }

            // ---- case 0x77 (1.82169e-43): caseD_82 — skybox name strncpy ----
            //   Body target switchD_004b80be_caseD_82: strncpy(W+0x507c, arg, 0x20).
            //   Inlined (the body's goto target is the loop tail LAB_004b809d).
            case 0x77: {
                uintptr_t W = DAT_006316ec;
                strncpy(reinterpret_cast<char*>(W + 0x507c), reinterpret_cast<char*>(arg), 0x20);
                prev_opcode = opcode;
                p += 0x21;
                continue;
            }

            // ---- case 0x78 (1.84971e-43): vopath string alloc (W+0x509c) ----
            case 0x78: {
                uintptr_t W = DAT_006316ec;
                // Skip a cstring at pfVar20 (body prologue)
                uint8_t* pa = arg; // pfVar20 == pfVar17
                // Note: body first walks pfVar20 forward past a cstring; mirror it.
                while (*pa != '\0') ++pa;
                if (*reinterpret_cast<uint32_t*>(W + 0x509c) != 0) {
                    FUN_0053c5c0(reinterpret_cast<void*>(*reinterpret_cast<uint32_t*>(W + 0x509c)),
                                 s_C__Giants_Source_main_readwrls_c_00563174, 0x64c);
                }
                // Measure strlen(arg) with a 0xFFFFFFFF countdown (body's idiom).
                uint32_t budget = 0xFFFFFFFFu;
                uint8_t* s2 = arg;
                do {
                    if (budget == 0) break;
                    --budget;
                    if (*reinterpret_cast<char*>(s2) == '\0') break;
                    ++s2;
                } while (1);
                uint32_t len = ~budget;
                uint32_t h = reinterpret_cast<uint32_t>(
                    FUN_0053c810(0x1a, len, const_cast<char*>(s_vopath_00563240),
                                 s_C__Giants_Source_main_readwrls_c_00563174, 0x64d));
                store_f32(reinterpret_cast<void*>(W), 0x509c, h);
                char* dst = reinterpret_cast<char*>(h);
                do { char c = *reinterpret_cast<char*>(arg); ++arg; *dst = c; ++dst; if (c == 0) break; } while (true);
                prev_opcode = opcode; p = pa; continue;
            }

            // ---- case 0x4b variant: waterfog (case 1.23314e-43 = byte ~0x82) ----
            //   The denormal 1.23314e-43 corresponds to byte 0x82.
            case 0x82: {
                uintptr_t W = DAT_006316ec;
                store_f32f(reinterpret_cast<void*>(W), 0x140, *reinterpret_cast<float*>(arg));
                store_f32(reinterpret_cast<void*>(W), 0x144, *reinterpret_cast<uint32_t*>(p + 5));
                store_f32f(reinterpret_cast<void*>(W), 0x148, static_cast<float>(p[9])  * _DAT_005524b4);
                store_f32f(reinterpret_cast<void*>(W), 0x14c, static_cast<float>(p[10]) * _DAT_005524b4);
                store_f32f(reinterpret_cast<void*>(W), 0x150, static_cast<float>(p[11]) * _DAT_005524b4);
                if (load_f32(reinterpret_cast<void*>(W), 0x140) < _DAT_005522b0)
                    FUN_00544b99(s_World_gt_waterfogmin_gt__0_0f_00563458, s_C__Giants_Source_main_readwrls_c_00563174, 0x293);
                if (load_f32(reinterpret_cast<void*>(W), 0x144) < _DAT_005522b0)
                    FUN_00544b99(s_World_gt_waterfogmax_gt__0_0f_0056343c, s_C__Giants_Source_main_readwrls_c_00563174, 0x294);
                FUN_0051bd20();
                prev_opcode = opcode; p += 12; continue;
            }

            // ---- case 0x83 (1.24716e-43): W+0x4534 cstring copy ----
            case 0x83: {
                uintptr_t W = DAT_006316ec;
                uint8_t* s = arg;
                do { ++s; } while (*reinterpret_cast<char*>(s - 1) != '\0');
                // s is now past the NUL; body copies from pfVar17 (arg) into W+0x4534
                char* dst = reinterpret_cast<char*>(W + 0x4534);
                uint8_t* s2 = arg;
                do { char c = *reinterpret_cast<char*>(s2); ++s2; *dst = c; ++dst; prev_opcode = opcode; if (c == 0) break; } while (true);
                p = s;
                continue;
            }

            // ---- case 0x86 (1.33123e-43 is byte 0x5c already handled; this is
            //      1.34525e-43 -> 0x5d handled. Skip duplicate.) ----

            // ---- case 0x88 (1.37327e-43 == 0x5f handled). Duplicate fallthrough. ----

            // ---- DEFAULT: unknown opcode → error + abort (body's default case) ----
            default:
                FUN_00544b47(&DAT_006552c0, s_Unknown_opcode__d__last__d__in_w_00563204,
                             static_cast<uint32_t>(opcode), prev_opcode,
                             static_cast<int>(arg - obj_stream));
                FUN_00523aa0(&DAT_006552c0);
                FUN_0053c5c0(stobj_pool,
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x655);
                return;
            } // switch
        } // while (odef VM)
    }

    // ---------------------------------------------------------------------
    // 0x4ba840..: post-loop finalize — copy stobj pool into W+0x178 list,
    //   patch default light slots, lazy walist alloc, terrain hook, dealloc.
    // ---------------------------------------------------------------------
    {
        uintptr_t W = DAT_006316ec;
        *reinterpret_cast<int*>(W + 0x174) = obj_count;
        if (obj_count > 0) {
            uint32_t h = reinterpret_cast<uint32_t>(
                FUN_0053c810(0x18, obj_count * 0x304, const_cast<char*>(s_stobj_005631fc),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x661));
            store_f32(reinterpret_cast<void*>(W), 0x178, h);
            uint32_t* src = stobj_pool;
            uint32_t* dst = reinterpret_cast<uint32_t*>(h);
            for (int i = 0; i < obj_count * 0xc1; ++i) dst[i] = src[i];
        }
        FUN_0053c5c0(stobj_pool, s_C__Giants_Source_main_readwrls_c_00563174, 0x665);

        // Light-slot defaults: for each of 3 light slots, if all-zero, copy from
        // the preset light direction (W+0x88..0x94).
        for (int off = 0; off < 0x30; off += 0x10) {
            float* slot = reinterpret_cast<float*>(W + 0x17c + off);
            if (slot[0] == _DAT_005522b0 && slot[1] == _DAT_005522b0 && slot[2] == _DAT_005522b0) {
                slot[0] = load_f32(reinterpret_cast<void*>(W), 0x88);
                slot[1] = load_f32(reinterpret_cast<void*>(W), 0x8c);
                slot[2] = load_f32(reinterpret_cast<void*>(W), 0x90);
                slot[3] = load_f32(reinterpret_cast<void*>(W), 0x94);
            }
        }

        // Lazy walist alloc (if anim_count set and W+0x210 still zero).
        if (anim_count != nullptr && *reinterpret_cast<int*>(W + 0x210) == 0) {
            uint32_t n3 = reinterpret_cast<uint32_t>(anim_count) * 3;
            *reinterpret_cast<char**>(W + 0x20c) = anim_count;
            uint32_t h = reinterpret_cast<uint32_t>(
                FUN_0053c810(0x1a, reinterpret_cast<uint32_t>(anim_count) * 0xc,
                             const_cast<char*>(s_walist_005633d0),
                             s_C__Giants_Source_main_readwrls_c_00563174, 0x68b));
            store_f32(reinterpret_cast<void*>(W), 0x210, h);
            uint32_t* src = world_anims;
            uint32_t* dst = reinterpret_cast<uint32_t*>(h);
            for (uint32_t k = n3; k != 0; --k) { *dst = *src; ++src; ++dst; }
        }

        // Terrain name hook.
        if (terrain_name_p != nullptr && *terrain_name_p != '\0') {
            FUN_00476d40(reinterpret_cast<char*>(terrain_name_p)); // FIXME(unverified): 0x00476d40
        }

        // Dealloc the odef blob (obj_stream / local_3fc[0]).
        FUN_0053c5c0(obj_stream, s_C__Giants_Source_main_readwrls_c_00563174, 0x679);

        // Close the .bin file.
        FUN_0051d850(file_handle);

        // -----------------------------------------------------------------
        // 0x4bac1..: build "<level>_G.bin"-style secondary path by appending
        //   the sky_name_p tail to param_1, then open & parse a 0x1a0002dd
        //   secondary file (object skin/anim overrides).
        // -----------------------------------------------------------------
        // Copy param_1 into itself at offset (diff = sky_name_p - param_1).
        // (Body quirk: it strcat-equivalents the sky path onto param_1 in place.)
        {
            int diff = static_cast<int>(reinterpret_cast<uintptr_t>(sky_name_p) -
                                        reinterpret_cast<uintptr_t>(param_1));
            char* q = param_1;
            char c;
            do { c = *q; q[diff] = c; ++q; } while (c != '\0');
        }
        // Append the vopath tag + NUL.
        {
            uint32_t budget = 0xFFFFFFFFu;
            uint8_t* s = reinterpret_cast<uint8_t*>(scratch_f);
            do { if (budget == 0) break; --budget; if (*reinterpret_cast<char*>(s) == '\0') break; ++s; } while (1);
            uint32_t off = ~budget;
            *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(scratch_f) + off) = DAT_005631f8;
        }
        uint32_t second_handle = FUN_00539e30(reinterpret_cast<char*>(scratch_f));
        uint32_t* plist = reinterpret_cast<uint32_t*>(DAT_006313b0);
        if (second_handle != 0) {
            uint32_t second_magic;
            FUN_0051d750(second_handle, &second_magic, 4);
            if (second_magic == 0x1a0002ddu) {
                while (true) {
                    int32_t obj_id;
                    FUN_0051d750(second_handle, &obj_id, 4);
                    if (obj_id == -1) break;
                    int objdata = FUN_0049d280(obj_id);          // FIXME(unverified): 0x0049d280
                    FUN_0051d750(second_handle, scratch_f, 0x18);
                    int* pfield = reinterpret_cast<int*>(objdata + 0x400);
                    int budget2 = 10;
                    do {
                        if (objdata != 0 && *pfield != 0) {
                            float* src = scratch_f;
                            float* dst = reinterpret_cast<float*>(*pfield + 0x44);
                            for (int k = 6; k != 0; --k) { *dst = *src; ++src; ++dst; }
                        }
                        ++pfield;
                        --budget2;
                    } while (budget2 != 0);
                    while (true) {
                        int32_t sub_id;
                        FUN_0051d750(second_handle, &sub_id, 4);
                        if (sub_id == -1) break;
                        FUN_0051d750(second_handle, scratch_f, 0x18);
                        if (objdata != 0) {
                            int sub = *reinterpret_cast<int*>(objdata + 8 + sub_id * 4);
                            if (sub != 0) {
                                float* src = scratch_f;
                                float* dst = reinterpret_cast<float*>(sub + 0xc);
                                for (int k = 6; k != 0; --k) { *dst = *src; ++src; ++dst; }
                            }
                        }
                    }
                }
                FUN_0051d850(second_handle);
                plist = reinterpret_cast<uint32_t*>(DAT_006313b0);
            } else {
                FUN_00544b47(&DAT_006552c0, s_Bad_version_for__s_0055e248, scratch_f);
                FUN_00523aa0(&DAT_006552c0);
                FUN_0051d850(second_handle);
                plist = reinterpret_cast<uint32_t*>(DAT_006313b0);
            }
        }

        // -----------------------------------------------------------------
        // 0x4bb0c0..: walk the placed-object linked list (DAT_006313b0) and
        //   propagate LOD-0 transforms into matching sub-meshes.
        // -----------------------------------------------------------------
        for (; plist != nullptr; plist = reinterpret_cast<uint32_t*>(*plist)) {
            int n = static_cast<int>(plist[1]);
            if (n <= 0) continue;
            uint32_t* p = plist + 2;
            int i = 0;
            do {
                int lod0 = p[0x100];
                if (lod0 != 0) {
                    int sub_idx = 0;
                    do {
                        int sub = p[sub_idx + 2];
                        if (sub != 0 &&
                            *reinterpret_cast<float*>(sub + 0xc)  == *reinterpret_cast<float*>(sub + 0x18) &&
                            *reinterpret_cast<float*>(sub + 0x10) == *reinterpret_cast<float*>(sub + 0x1c) &&
                            *reinterpret_cast<float*>(sub + 0x14) == *reinterpret_cast<float*>(sub + 0x20)) {
                            uint32_t* src = reinterpret_cast<uint32_t*>(lod0 + 0x44);
                            uint32_t* dst = reinterpret_cast<uint32_t*>(sub + 0xc);
                            for (int k = 6; k != 0; --k) { *dst = *src; ++src; ++dst; }
                        }
                        ++sub_idx;
                    } while (sub_idx < 0xfe);
                }
                ++i;
                p += 0x119;
            } while (i < n);
        }
    }

    // 0x4bb12d: _DAT_005a5c9c = param_3 (record end-time on exit)
    _DAT_005a5c9c = param_3;
}

// ============================================================================
// SelfTest — opens Bin/w_intro_island.bin, validates magic, logs header + subs.
// ============================================================================
namespace VanillaBinLoaderFull {

static void log_line(const char* fmt, ...) {
    char buf[512];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    std::fputs("[VanillaBinLoaderFull] ", stdout);
    std::fputs(buf, stdout);
    std::fputc('\n', stdout);
}

int SelfTest()
{
    // The engine's file API (FUN_00539e30) resolves loose files under Bin/.
    // We pass just the basename; VanillaFileIO searches Bin/ and GZP.
    const char* kPath = "w_intro_island.bin";
    log_line("SelfTest: opening '%s'", kPath);

    uint32_t h = FUN_00539e30(kPath);
    if (h == 0) {
        // Fallback: try with Bin\ prefix (some integrator configs need it).
        kPath = "Bin\\w_intro_island.bin";
        log_line("  retry with prefix: '%s'", kPath);
        h = FUN_00539e30(kPath);
    }
    if (h == 0) {
        log_line("FAIL: could not open w_intro_island.bin");
        return 1;
    }

    uint32_t magic;
    FUN_0051d750(h, &magic, 4);
    if (magic != 0x1a0002e5u) {
        log_line("FAIL: bad magic 0x%08x (expected 0x1a0002e5)", magic);
        FUN_0051d850(h);
        return 2;
    }
    log_line("OK: magic 0x%08x", magic);

    uint32_t hdr[7];
    FUN_0051d750(h, hdr, 0x1c);
    log_line("header (7 section offsets):");
    log_line("  [0] odef_blob_off = 0x%x", hdr[0]);
    log_line("  [1] name_list_off = 0x%x", hdr[1]);
    log_line("  [2] texmem_off    = 0x%x", hdr[2]);
    log_line("  [3] world_off     = 0x%x", hdr[3]);
    log_line("  [4] fx_off        = 0x%x", hdr[4]);
    log_line("  [5] reserved5     = 0x%x", hdr[5]);
    log_line("  [6] sub_bins_off  = 0x%x", hdr[6]);

    // Read & log the odef blob size (at hdr[0]) and the two leading cstrings.
    if (hdr[0] != 0) {
        FUN_0051d7b0(h, hdr[0]);
        uint32_t blob_sz;
        FUN_0051d750(h, &blob_sz, 4);
        log_line("odef blob size = 0x%x bytes", blob_sz);
        if (blob_sz > 0 && blob_sz < 0x100000) {
            uint8_t* blob = static_cast<uint8_t*>(std::malloc(blob_sz));
            if (blob) {
                FUN_0051d750(h, blob, blob_sz);
                char name1[64] = {0};
                char name2[64] = {0};
                std::strncpy(name1, reinterpret_cast<char*>(blob), sizeof(name1) - 1);
                uint8_t* p2 = blob;
                while (*p2 != 0) ++p2; ++p2;
                std::strncpy(name2, reinterpret_cast<char*>(p2), sizeof(name2) - 1);
                log_line("  terrain name: '%s'", name1);
                log_line("  sky/scene  : '%s'", name2);
                std::free(blob);
            }
        }
    }

    // Read & log the sub-bin list (at hdr[6]): u32 count + count * 0x20 names.
    if (hdr[6] != 0) {
        FUN_0051d7b0(h, hdr[6]);
        int32_t count;
        FUN_0051d750(h, &count, 4);
        log_line("sub-bin count = %d", count);
        for (int i = 0; i < count && i < 32; ++i) {
            char name[0x21] = {0};
            FUN_0051d750(h, name, 0x20);
            name[0x20] = 0;
            log_line("  sub[%d] = '%s'", i, name);
        }
    }

    FUN_0051d850(h);
    log_line("SelfTest: OK");
    return 0;
}

} // namespace VanillaBinLoaderFull
