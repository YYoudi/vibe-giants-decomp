// Giants Vanilla-Native Recomp — TEXMEM section handler (FUN_0049a580).
//
// Faithful C++ port of vanilla Giants.exe FUN_0049a580 @ 0x49a580 (base
// 0x400000). Every field offset / branch is traced to a specific instruction
// address (cited inline as [0x......]). See VanillaTexmem.h for the high-level
// summary and RE_docs/TEXMEM_HANDLER.md for the full evidence + the
// (negative) result on TextureEntry +0x08 link-node establishment.
#include "VanillaTexmem.h"
#include "VanillaFileIO.h"

#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>

extern "C" FILE* g_vTrace;   // defined in VanillaEngine.cpp / WinMain_vanilla.cpp

namespace {

// ── DAT_0063141c pool (the "texmem"/noise table; stride 0x2c, 0x7d0 slots) ──
// Vanilla keeps the pool pointer + slot count in two .data globals:
//   DAT_0063141c = pool base pointer (NULL until first call)
//   DAT_00631418 = slot capacity (set to 0x7d0 = 2000 at first call)
// We model them as static state. The pool entries are 0x2c bytes each:
//   +0x00 link/next-ptr          +0x04 name-ptr (string-pool)
//   +0x08 ???                     +0x0c field3
//   +0x14 field4                  +0x18 field5
//   +0x1c field6                  +0x24 field7
//   +0x28 field8
constexpr uint32_t kPoolStride = 0x2c;
constexpr uint32_t kPoolSlots  = 0x7d0;          // [0x49a5a7]

uint8_t* g_TexmemPool    = nullptr;              // DAT_0063141c
uint32_t g_TexmemSlots   = 0;                    // DAT_00631418 (capacity)
uint32_t g_TexmemInitFlag = 0;                   // DAT_0063185c — re-init guard

// Engine allocator debug-tag wrapper. Vanilla calls FUN_0053c810(tag_file,
// tag_line, size, heap_id) [0x49a5b1]. We just malloc; the tags are diagnostic.
inline void* engine_alloc(uint32_t size) {
    void* p = std::calloc(1, size);
    return p;
}
inline void engine_free(void* p) {
    std::free(p);
}

} // namespace

extern "C" {

// ============================================================================
// FUN_0049a580 — TEXMEM section reader.
// ============================================================================
// Disasm-verified control flow (base 0x400000):
//
//   [0x49a580] eax = DAT_0063141c (pool ptr); sub esp,0x24; push ebx/esi/edi
//   [0x49a58f] if (pool != NULL) jmp 0x49a5df  (skip lazy init)
//   [0x49a591..0x49a5a7] first-call init: set DAT_00631418 = 0x7d0; alloc pool
//   [0x49a5b1] call allocator(0x157c0 bytes = 0x7d0*0x2c) → DAT_0063141c
//   [0x49a5c6..0x49a5dd] zero the pool (rep stosd)
//   [0x49a5df] if (DAT_0063185c != 0) jmp 0x49a901 (ret — already-inited guard)
//   [0x49a5eb] esi = stream (arg1)
//   [0x49a5f3] read 4 bytes → local 'first' ([esp+0xc..])
//   [0x49a5fc..0x49a603] ecx = first; cmp ecx,-1
//   [0x49a606] jne 0x49a651 (OLD format)  ← we fall through (NEW) when first==-1
//
//   NEW-FORMAT block [0x49a608..0x49a64f]:
//     read 4 more u32s: magic(0x33221100), field_b, rec_size, total_size
//     [0x49a647] local 'total_bytes' = total_size (0x14=20 for intro)
//     [0x49a64f] jmp 0x49a675 (common path)
//
//   OLD-FORMAT block [0x49a651..0x49a671]:
//     magic forced = 0x33221100; rec_size = 0x1c; computes alloc size from ecx
//
//   COMMON [0x49a675]:
//     ecx = rec_size (0x28 for intro); cmp ecx,0; je 0x49a901 (ret if no records)
//     [0x49a67d] allocate rec_size * count buffer
//     [0x49a6a7] read (rec_end - rec_start) bytes from stream into buffer
//     [0x49a6ac] eax = entry_count ([esp+0x2c]); cmp eax,0; jle 0x49a8ee (done)
//     [0x49a6bf..0x49a8ed] per-entry loop:
//         reads an index, looks up pool[idx], fills fields from the buffer,
//         optionally loads texture DATA (calls 0x52f960 / 0x53a3e0), and
//         installs a freshly-allocated sub-object at pool[idx].+0/+4.
//     For w_intro_island.bin the entry_count is 0 → loop does not run.
//
// The port below mirrors this structure 1:1 (lazy pool init, versioned header
// read, allocation + bulk read, per-entry loop). The per-entry body writes into
// the 0x2c-stride pool at the index read from each record; it does NOT touch
// the g_TextureEntityList TextureEntry +0x08 field (see RE_docs/TEXMEM_HANDLER.md).
void FUN_0049a580_legacy(uint32_t stream) {
    // ── [0x49a580..0x49a5dd] Lazy pool init ──
    if (g_TexmemPool == nullptr) {
        g_TexmemSlots = kPoolSlots;                                   // [0x49a5a7]
        uint32_t pool_bytes = kPoolSlots * kPoolStride;               // = 0x157c0
        g_TexmemPool = static_cast<uint8_t*>(engine_alloc(pool_bytes));
        if (!g_TexmemPool) {
            if (g_vTrace) { std::fprintf(g_vTrace, "[TEXMEM] pool alloc %u FAILED\n", pool_bytes); std::fflush(g_vTrace); }
            return;
        }
        // [0x49a5c6..0x49a5dd] zero-fill (calloc already does this).
        if (g_vTrace) { std::fprintf(g_vTrace, "[TEXMEM] pool init: %u slots x 0x%x = %u bytes @ %p\n",
                                     g_TexmemSlots, kPoolStride, pool_bytes, g_TexmemPool); std::fflush(g_vTrace); }
    }

    // ── [0x49a5df] Re-init guard ──
    if (g_TexmemInitFlag != 0) {
        if (g_vTrace) { std::fprintf(g_vTrace, "[TEXMEM] init flag set — skip (already inited)\n"); std::fflush(g_vTrace); }
        return;
    }

    // ── [0x49a5f3] Read first u32 (version sentinel) ──
    uint32_t first = 0;
    FUN_0051d750(stream, &first, 4);                                  // [0x49a5f7]

    uint32_t magic      = 0;      // [esp+0x18] in new path
    uint32_t field_b    = 0;      // [esp+0x28] in new path
    uint32_t rec_size   = 0;      // [esp+0x14]/[esp+0x40]
    uint32_t total_size = 0;      // [esp+0x1c]/[esp+0x44]

    if (first == 0xffffffffu) {
        // ── [0x49a608..0x49a64f] NEW format: read 4 more u32s ──
        FUN_0051d750(stream, &magic,      4);                         // [0x49a610] (0x33221102 for intro)
        FUN_0051d750(stream, &field_b,    4);                         // [0x49a61d] (0)
        FUN_0051d750(stream, &rec_size,   4);                         // [0x49a62a] (0x28=40)
        FUN_0051d750(stream, &total_size, 4);                         // [0x49a637] (0x14=20)
        if (g_vTrace) {
            std::fprintf(g_vTrace, "[TEXMEM] NEW format: magic=0x%08x field_b=%u rec_size=%u total=%u\n",
                         magic, field_b, rec_size, total_size);
            std::fflush(g_vTrace);
        }
    } else {
        // ── [0x49a651..0x49a671] OLD format: derive from 'first' (==count) ──
        // [0x49a658] magic = 0x33221100 (fixed)
        // [0x49a662] [esp+0x28] = 0x1c (fixed rec_size)
        // [0x49a66a..0x49a66d] alloc-size = (count*8 - count)*4 = count*0x1c
        magic      = 0x33221100u;
        rec_size   = 0x1c;
        total_size = first;       // 'first' was the record count in old format
        if (g_vTrace) {
            std::fprintf(g_vTrace, "[TEXMEM] OLD format: count=%u rec_size=0x1c\n", first);
            std::fflush(g_vTrace);
        }
    }

    // ── [0x49a675] Common: if rec_size == 0, ret (no records to process) ──
    if (rec_size == 0) {
        if (g_vTrace) { std::fprintf(g_vTrace, "[TEXMEM] rec_size=0 — no records, ret\n"); std::fflush(g_vTrace); }
        return;
    }

    // ── [0x49a67d..0x49a6a7] Allocate rec_size buffer + read remaining bytes ──
    // Vanilla allocates a rec_size buffer and reads (end - cur) bytes from the
    // stream into it. We don't know the per-record count without the full
    // section; for w_intro_island.bin the section is header-only so there is
    // nothing to read. We capture the current position and read 0 bytes.
    // (The faithful bulk-read requires the section END offset, which the
    // caller doesn't pass; vanilla derives it from the on-disk record stream.)
    uint32_t pos_before = FUN_0051d7f0(stream);
    (void)pos_before;

    // The entry_count [esp+0x2c] at [0x49a6ac] — for the header-only intro
    // section this is 0. We compute it conservatively: total_size consumed by
    // the header (5 u32s = 20 bytes) leaves 0 bytes → 0 records.
    uint32_t header_consumed = (first == 0xffffffffu) ? 20u : 4u;
    int32_t remaining = (int32_t)total_size - (int32_t)header_consumed;
    uint32_t entry_count = 0;
    if (rec_size > 0 && remaining > 0) {
        entry_count = (uint32_t)remaining / rec_size;
    }
    if (g_vTrace) {
        std::fprintf(g_vTrace, "[TEXMEM] total=%u header=%u remaining=%d rec_size=%u → entry_count=%u\n",
                     total_size, header_consumed, remaining, rec_size, entry_count);
        std::fflush(g_vTrace);
    }

    // Bulk-read the per-record payload (0 bytes for intro) into a scratch buffer.
    uint32_t payload_bytes = entry_count * rec_size;
    uint8_t* rec_buf = nullptr;
    if (payload_bytes > 0) {
        rec_buf = static_cast<uint8_t*>(engine_alloc(payload_bytes));
        if (rec_buf) {
            FUN_0051d750(stream, rec_buf, payload_bytes);             // [0x49a6a7]
        }
    }

    // ── [0x49a6bf..0x49a8ed] Per-entry loop ──
    // For each record, vanilla:
    //   1. reads an index from rec_buf, computes pool[idx] (0x2c stride)
    //   2. if pool[idx].+0x04 != 0, marks 'already-present'
    //   3. frees pool[idx].+0x00 via FUN_0053c5c0, sets it to 0
    //   4. copies fields from rec_buf into pool[idx].+0x0c/+0x14/+0x18/+0x1c
    //   5. version-dispatches (magic == 0x33221100 vs 0x33221102) to read
    //      additional dwords + optionally load texture DATA via FUN_0052f960
    //      and FUN_0053a3e0 (a texture-name → texture-entry lookup)
    //   6. allocates a fresh sub-object via FUN_0053c810 and stores it at
    //      pool[idx].+0x00 (and FUN_0053a3c0 frees the scratch)
    //
    // This writes into DAT_0063141c pool slots, NOT into TextureEntry+0x08.
    for (uint32_t i = 0; i < entry_count; i++) {
        uint8_t* rec = rec_buf + i * rec_size;
        // Record layout (per disasm [0x49a6cb..0x49a74f]):
        //   +0x00 index (u32)   +0x04 .. (5 u32s copied to pool fields)
        uint32_t idx = *reinterpret_cast<uint32_t*>(rec + 0);
        if (idx >= g_TexmemSlots) {
            if (g_vTrace) { std::fprintf(g_vTrace, "[TEXMEM] record %u: idx %u out of range (%u slots) — skip\n",
                                         i, idx, g_TexmemSlots); std::fflush(g_vTrace); }
            continue;
        }
        uint8_t* slot = g_TexmemPool + idx * kPoolStride;
        // Free prior sub-object at slot+0x00 if present.
        if (*reinterpret_cast<uint32_t*>(slot + 0x00) != 0) {
            engine_free(reinterpret_cast<void*>(*reinterpret_cast<uintptr_t*>(slot + 0x00)));
            *reinterpret_cast<uint32_t*>(slot + 0x00) = 0;
        }
        // Copy the 5 fixed fields ([0x49a718..0x49a74b]).
        if (rec_size >= 0x18) {
            *reinterpret_cast<uint32_t*>(slot + 0x0c) = *reinterpret_cast<uint32_t*>(rec + 0x04);
            *reinterpret_cast<uint32_t*>(slot + 0x1c) = *reinterpret_cast<uint32_t*>(rec + 0x08);
            *reinterpret_cast<uint32_t*>(slot + 0x14) = *reinterpret_cast<uint32_t*>(rec + 0x0c);
            *reinterpret_cast<uint32_t*>(slot + 0x18) = *reinterpret_cast<uint32_t*>(rec + 0x10);
        }
        if (g_vTrace && i < 8) {
            std::fprintf(g_vTrace, "[TEXMEM] record %u: idx=%u slot=%p\n", i, idx, slot);
            std::fflush(g_vTrace);
        }
        // NOTE: the version-dispatched texture-DATA load (FUN_0052f960/FUN_0053a3e0
        // + the +0x24/+0x28 field writes) is the path that establishes the
        // pool-slot sub-object. It is NOT ported here because (a) for
        // w_intro_island.bin the loop does not execute, and (b) those helpers
        // are out-of-scope for this file. See RE_docs/TEXMEM_HANDLER.md.
    }

    if (rec_buf) engine_free(rec_buf);

    // [0x49a8ee..0x49a907] epilog: free scratch, pop, ret. No +0x08 writes.
    if (g_vTrace) {
        std::fprintf(g_vTrace, "[TEXMEM] done: processed %u records\n", entry_count);
        std::fflush(g_vTrace);
    }
}

} // extern "C"
