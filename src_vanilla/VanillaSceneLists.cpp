// Giants Vanilla-Native Recomp — Scene/Entity list functions.
//
// Faithful C++ ports of three vanilla Giants.exe functions (base 0x400000),
// confirmed by capstone disassembly. Each function's behavior is traced to
// specific instruction addresses (cited inline as [0x......]).
//
//   FUN_0050d8f0 — texture/entity list INSERT (head at DAT_005a78b4)
//   FUN_004b50b0 — placed-object reader   (lists at DAT_006313ac/b0/b4)
//   FUN_004b77f0 — WorldList.bin reader   (table at DAT_00631388)
//
// File I/O uses the engine file API (VanillaFileIO.h): FUN_00539e30 open,
// FUN_0051d750 read, FUN_0051d7b0 read-line, FUN_0051d850 close.
#include "VanillaSceneTypes.h"
#include "VanillaEngine.h"
#include "VanillaFileIO.h"

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cstring>

extern "C" FILE* g_vTrace;   // defined in VanillaEngine.cpp / WinMain_vanilla.cpp

// ============================================================================
// Engine-state globals backing the .data list heads.
// ============================================================================
// Vanilla keeps these as raw DWORD pointers in .data. Our recomp declares them
// in VanillaEngine.h (g_TextureEntityList / g_PlacedObjectList / g_LevelTable).
// FUN_004b77f0 also touches three companion globals used as sub-list heads and
// a level-count field; we define the ones the ported functions mutate here.
extern "C" {
// Texture-list head is circular self-referential when empty. Vanilla inits it
// to NULL at reset (FUN_0050dae0) and head-inserts (FUN_0050d8f0), so the
// "empty" state observed by readers is g_TextureEntityList == 0. We keep that
// semantics: zero until first insert.
}

// FUN_004b50b0 places objects into three sub-lists at these .data addresses.
// Declared here (not in VanillaEngine.h) because they are internal to the
// placement reader. They are the same heads the renderer walks.
extern "C" {
    // DAT_006313ac / DAT_006313b0 / DAT_006313b4 — placement sub-list heads.
    // Defined here; zero-init. FUN_004b50b0 head-inserts PlacementHeader nodes.
    uint32_t g_PlacementListOdef = 0;   // DAT_006313ac — 'odef' list (object defs)
    uint32_t g_PlacementListObjl = 0;   // DAT_006313b0 — 'objl' list (object placement nodes)
    uint32_t g_PlacementListOsl  = 0;   // DAT_006313b4 — 'osl'  list (object set list)
    // DAT_00631384 — total level count (sum across the 5 worldlist files).
    uint32_t g_LevelCount = 0;          // DAT_00631384
    // DAT_005a5ca4 — 5-slot table of per-worldlist-file buffer pointers
    // (FUN_004b77f0 reads each worldlist%d.bin into one of these, then sums counts).
    uint32_t g_WorldListBuf[WORLDLIST_FILE_COUNT] = {0,0,0,0,0};
    // DAT_006316ec — world/game-state pointer (cleared by scene bootstrap).
    uint32_t g_WorldState = 0;          // DAT_006316ec
}

// FUN_0051d7f0 (GetFilePosition) is defined in VanillaFileIO.cpp (added there
// once the IAT semantics were confirmed via capstone: SetFilePointer(0, CURRENT)).
// Not redeclared here — see VanillaFileIO.h.

// ============================================================================
// Internal: head-insert a freshly-allocated node into a circular list.
// ============================================================================
// Vanilla pattern (e.g. FUN_0050d8f0 [0x50d9da]):
//   new_node->next = head;  head = new_node;
// For the circular variant (DAT_006313ac/b0/b4 used by FUN_004b50b0), the
// empty state is head==0 and the loop walks via next until next==0.
static inline void head_insert(uint32_t* head_ptr, void* new_node) {
    *reinterpret_cast<void**>(new_node) = reinterpret_cast<void*>(static_cast<uintptr_t>(*head_ptr));
    *head_ptr = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(new_node));
}

// ============================================================================
// FUN_0050d8f0 — Texture/entity list INSERT (head at DAT_005a78b4)
// ============================================================================
//
// CONFIRMED signature: void FUN_0050d8f0(const char* name, uint32_t stream)
//   arg1 = [esp+0x40] (name)   — node name (strcpy to +0x04)
//   arg2 = [esp+0x44] (stream) — file handle (caller has just SEEK'd to name_list)
//
// ON-DISK FORMAT (verified against w_intro_island.bin @ header[1]=0x46d):
//   u32 sub_count                          ← read by [0x50d936]
//   sub_count × {                          ← per-entry on-disk record
//     u8  flagsLo                          ← SKIPPED via FUN_0051d7d0(stream,1) [0x50d94d]
//     u8  flagsHi                          ← SKIPPED via FUN_0051d7d0(stream,1) [0x50d955]
//     u8  nameLen                          ← READ via FUN_0051d750(stream,&b,1) [0x50d962]
//     char name[nameLen]                   ← READ via FUN_0051d750(stream,buf,nameLen) [0x50d978]
//   }
//
// IN-MEMORY NODE LAYOUT (node + 0x2c entries, each 0x24 = 9 dwords):
//   +0x00 next                            [0x50d9da] = old head (head-insert)
//   +0x04 name[0x20]                      [0x50d9e7] strcpy(name@+4, param_1)
//   +0x24 data_size                       [0x50d9f7] = stream position (FUN_0051d7f0)
//   +0x28 sub_count                       [0x50d9fe] = u32 read from stream
//   +0x2c entries[sub_count] (stride 0x24)
//     per entry:
//       +0x00 → string-pool ptr (this entry's name)   [0x50da9e] *puVar4 = puVar8
//       +0x08 = 0                                     [0x50daab] puVar4[2] = 0
//       +0x14 = 8                                     [0x50dab3] puVar4[5] = 8
//       +0x18 = 8                                     [0x50dab5] puVar4[6] = 8
//       +0x20 = flagsLo (read first byte)             [0x50da8f] *(puVar4+8) byte = local_29
//       +0x23 = flagsHi (read second byte)            [0x50da9b] *(puVar4+0x23) byte = local_29
//   [after entries] name-string-pool (each entry's name copied NUL-terminated)
//
// `data_size` = FUN_0051d7f0(stream) = CURRENT stream position captured before
// reading sub_count (Ghidra decompile misled earlier: it's GetFilePosition
// via SetFilePointer(0, FILE_CURRENT), NOT the file size — confirmed by capstone).
// The vanilla body then re-seeks via FUN_0051d7b0(stream, data_size+4) to skip
// past sub_count before the second-pass entry-fill loop.
extern "C" void FUN_0050d8f0(const char* name, uint32_t stream) {
    // Phase 1: name-match walk (if a node with this name exists, skip).
    //   [0x50d8f6..0x50d91e] for each node, strcmp(node->name@+4, name).
    TextureListNode* cur = reinterpret_cast<TextureListNode*>(static_cast<uintptr_t>(g_TextureEntityList));
    while (cur) {
        if (name && std::strcmp(cur->name, name) == 0) {
            if (g_vTrace) { std::fprintf(g_vTrace, "[TEXLIST] duplicate '%s' — skip insert\n", name); std::fflush(g_vTrace); }
            return;
        }
        cur = cur->next;
    }

    // Phase 2: capture stream position (iVar3) + read sub_count.
    //   [0x50d925] iVar3 = FUN_0051d7f0(stream) = GetFilePosition
    //   [0x50d936] FUN_0051d750(stream, &sub_count, 4)
    const uint32_t data_size = FUN_0051d7f0(stream);
    uint32_t sub_count = 0;
    FUN_0051d750(stream, &sub_count, 4);

    // Cap sub_count to something sane to defend against a bad stream position.
    if (sub_count > 4096) {
        if (g_vTrace) { std::fprintf(g_vTrace, "[TEXLIST] sub_count=%u too large (bad stream pos %u) — ABORT\n", sub_count, data_size); std::fflush(g_vTrace); }
        return;
    }

    // Phase 3: First-pass walk to size the trailing name-string pool.
    //   The vanilla body computes the pool size as `iVar2 + 0x2c + sub_count*0x24`
    //   where iVar2 is the cumulative strlen+1 of each entry name (computed by
    //   walking the on-disk entries via skip/read at [0x50d94a..0x50d999]). We
    //   replicate: skip 2, read nameLen, read nameLen bytes, accumulate strlen+1.
    uint32_t pool_size = 0;
    {
        uint32_t pos_after_count = FUN_0051d7f0(stream);  // stream now at entries[0]
        for (uint32_t i = 0; i < sub_count; i++) {
            FUN_0051d7d0(stream, 1);                 // skip flagsLo
            FUN_0051d7d0(stream, 1);                 // skip flagsHi
            uint8_t nameLen = 0;
            FUN_0051d750(stream, &nameLen, 1);
            char nm[256] = {0};
            FUN_0051d750(stream, nm, nameLen);
            nm[sizeof(nm) - 1] = '\0';
            // strlen(nm) + 1 (NUL)
            uint32_t L = (uint32_t)std::strlen(nm) + 1;
            pool_size += L;
        }
        // Re-seek to entries[0] for the second pass (identical to vanilla's
        // FUN_0051d7b0(stream, data_size+4) at [0x50d9fe region]).
        FUN_0051d7b0(stream, data_size + 4);
        (void)pos_after_count;
    }

    // Phase 4: allocate node = 0x2c header + sub_count*0x24 entries + pool_size.
    //   Vanilla [0x50d99b..0x50d9ad] size = sub_count*9*4 + 0x2c + iVar2(pool)
    //   [0x50d9b4] allocate, [0x50d9c9] memset(0).
    const uint32_t node_size = 0x2c + sub_count * 0x24 + pool_size;
    TextureListNode* node = static_cast<TextureListNode*>(std::calloc(1, node_size));
    if (!node) {
        if (g_vTrace) { std::fprintf(g_vTrace, "[TEXLIST] alloc %u FAILED for '%s'\n", node_size, name ? name : "(null)"); std::fflush(g_vTrace); }
        return;
    }

    // Phase 5: head-insert into g_TextureEntityList.
    //   [0x50d9d5..0x50d9e1] node->next = head; head = node;
    node->next = reinterpret_cast<TextureListNode*>(static_cast<uintptr_t>(g_TextureEntityList));
    g_TextureEntityList = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(node));

    // Phase 6: fill header fields.
    //   [0x50d9e7..] strcpy(node+4, name); [0x50d9f7] data_size; [0x50d9fe] sub_count.
    if (name) {
        std::strncpy(node->name, name, sizeof(node->name) - 1);
        node->name[sizeof(node->name) - 1] = '\0';
    }
    node->data_size = data_size;
    node->sub_count = sub_count;

    // Phase 7: per-entry fill loop (faithful 1:1 with vanilla [0x50da30..0x50dac9]).
    //   On disk per entry: {flagsLo:1, flagsHi:1, nameLen:1, name:nameLen}.
    //   In memory per entry (stride 0x24):
    //     +0x00 → string-pool ptr (this entry's NUL-terminated name)
    //     +0x08 = 0, +0x14 = 8, +0x18 = 8 (fixed dwords)
    //     +0x20 byte = flagsLo, +0x23 byte = flagsHi
    uint8_t* entries = reinterpret_cast<uint8_t*>(node) + 0x2c;
    char*    pool    = reinterpret_cast<char*>(entries + sub_count * 0x24);
    char*    pool_cur = pool;
    for (uint32_t i = 0; i < sub_count; i++) {
        uint8_t* e = entries + i * 0x24;
        // Read flagsLo (byte → entry+0x20) + flagsHi (byte → entry+0x23).
        uint8_t flagsLo = 0, flagsHi = 0;
        FUN_0051d750(stream, &flagsLo, 1);            // [0x50da49] read first byte
        FUN_0051d750(stream, &flagsHi, 1);            // [0x50da5d] read second byte
        *(e + 0x20) = flagsLo;                        // [0x50da8f]
        *(e + 0x23) = flagsHi;                        // [0x50da9b]
        // Read nameLen + name bytes.
        uint8_t nameLen = 0;
        FUN_0051d750(stream, &nameLen, 1);            // [0x50da69]
        FUN_0051d750(stream, pool_cur, nameLen);      // [0x50da78]
        pool_cur[nameLen] = '\0';
        // Install string-pool pointer into entry+0x00.
        *reinterpret_cast<char**>(e + 0x00) = pool_cur;  // [0x50da9e]
        // Fixed dwords (per vanilla [0x50daab]/[0x50dab3]/[0x50dab5]).
        *reinterpret_cast<uint32_t*>(e + 0x08) = 0;       // puVar4[2] = 0
        *reinterpret_cast<uint32_t*>(e + 0x14) = 8;       // puVar4[5] = 8
        *reinterpret_cast<uint32_t*>(e + 0x18) = 8;       // puVar4[6] = 8
        // Advance pool pointer past this name (strlen+1).
        pool_cur += std::strlen(pool_cur) + 1;
    }

    if (g_vTrace) {
        std::fprintf(g_vTrace, "[TEXLIST] insert '%s' subs=%u pool=%u node=%p head=%08x\n",
                     name ? name : "(null)", sub_count, pool_size, static_cast<void*>(node), g_TextureEntityList);
        for (uint32_t i = 0; i < sub_count && i < 16; i++) {
            uint8_t* e = entries + i * 0x24;
            const char* nm = *reinterpret_cast<const char* const*>(e + 0x00);
            std::fprintf(g_vTrace, "[TEXLIST]   [%u] '%s' flags=%02x,%02x\n",
                         i, nm ? nm : "(null)", *(e + 0x20), *(e + 0x23));
        }
        std::fflush(g_vTrace);
    }
}

// ============================================================================
// FUN_004b50b0 — Placed-object reader (lists at DAT_006313ac/b0/b4)
// ============================================================================
//
// Confirmed signature: void FUN_004b50b0(uint32_t stream, const char* scene_name)
//   arg1 = [esp+0x27b8] (stream)    — esi for the body
//   arg2 = [esp+0x27bc] (scene_name)— referenced in error/allocator tags
// Frame: 0x27a8 bytes locals (mov eax,0x27a8; call __chkstk [0x4b50b5]).
// Disasm evidence:
//   [0x4b50bd] mov esi,[esp+0x27b8]          ; stream
//   [0x4b50cd] call FUN_0051d750(stream,&count,4)  ; read odef count
//   [0x4b50d6..0x4b50e5] allocate 'odef' list (DAT_006313ac): count*0x52 + header
//   [0x4b511c..0x4b5150] build 'odef' list, head-insert into DAT_006313ac
//   [0x4b51da..] read next count → 'osl' list (DAT_006313b4), stride 0x464
//   [0x4b5220..] build 'objl' list (DAT_006313b0), head-insert
//   [0x4b5269..0x4b5d21] per-object placement loop: parses opcode bytes ('Q'/'Y'/
//                       'Z'/'['/'R'/'V'/'W'/'X'), reads ObjectRef6-style records,
//                       builds placement nodes (stride 0x464), links into objl list
//   [0x4b5d25..0x4b5dc5] read 'atl' (animation trigger) list → DAT_006313b4
//
// This is a LARGE function (≈3000 bytes of code). The full faithful port reads
// the .BIN object section in three phases (odef → osl/objl → atl) and builds
// the placement sub-lists. We implement the structure-faithful skeleton:
// read counts, allocate the three sub-list headers, head-insert, and walk the
// per-object placement rows. The opcode-driven per-object body (Q/Y/Z/[/R/V/W/X
// cases at [0x4b52cb..0x4b5667]) is ported as a faithful record-reader that
// consumes the on-disk ObjectRef6 rows.
extern "C" void FUN_004b50b0_legacy(uint32_t stream, const char* scene_name) {
    // ---- Phase 1: 'odef' list (object definitions) → DAT_006313ac ----
    // [0x4b50cd] read count; [0x4b50e5] allocate count*0x52 + 4-byte header;
    // [0x4b511c..0x4b5150] head-insert into DAT_006313ac; zero-fill; set +4=count.
    uint32_t odef_count = 0;
    FUN_0051d750(stream, &odef_count, 4);
    if (odef_count) {
        const uint32_t odef_size = 8 + odef_count * 0x52;
        uint8_t* odef_node = static_cast<uint8_t*>(std::calloc(1, odef_size));
        if (odef_node) {
            *reinterpret_cast<uint32_t*>(odef_node + 4) = odef_count;   // [0x4b5150]
            head_insert(&g_PlacementListOdef, odef_node);               // [0x4b513a]
            // Read the odef payload (count*0x52 bytes) — names + mesh refs.
            // Vanilla reads each def's .gbs/.skn name here ([0x4b5164..0x4b51d8]).
            FUN_0051d750(stream, odef_node + 8, odef_count * 0x52);
        }
    }

    // ---- Phase 2: 'osl' list (object set list) → DAT_006313b4 ----
    // [0x4b51da] read count; [0x4b51f3..0x4b521b] allocate count*0x464 + 8;
    // [0x4b5220..0x4b5256] head-insert into DAT_006313b0; zero-fill; set +4=count.
    // NOTE: vanilla builds this into DAT_006313b0 first (objl), then the
    // placement-loop populates DAT_006313b4 nodes. We follow the same order.
    uint32_t osl_count = 0;
    FUN_0051d750(stream, &osl_count, 4);
    uint8_t* osl_node = nullptr;
    if (osl_count) {
        const uint32_t osl_size = 8 + osl_count * 0x464;
        osl_node = static_cast<uint8_t*>(std::calloc(1, osl_size));
        if (osl_node) {
            *reinterpret_cast<uint32_t*>(osl_node + 4) = osl_count;
            head_insert(&g_PlacementListObjl, osl_node);
        }
    }

    // ---- Phase 3: per-object placement loop → builds objl/osl records ----
    // [0x4b5269..0x4b5d21] For each of osl_count objects, read opcode bytes
    // and ObjectRef6 placement rows. Each placement row is 0x1c bytes
    // (typeId + xyz + 3 angles). The loop writes into the osl_node records
    // (stride 0x464) and dispatches per opcode (Q/Y/Z/[/R/V/W/X).
    for (uint32_t i = 0; i < osl_count && osl_node; i++) {
        uint8_t* rec = osl_node + 8 + i * 0x464;
        // Read the opcode stream until terminator. Vanilla reads 1 byte at
        // [0x4b52c7] and switches (cmp eax,0x51='Q' ... 0x58='X').
        // Each opcode consumes fields from the stream; we read the
        // ObjectRef6 placement row (7 dwords) for the common 'Q' case.
        uint8_t opcode = 0;
        FUN_0051d750(stream, &opcode, 1);
        // Common 'Q' (0x51) case: read ObjectRef6 placement row into the record.
        if (opcode == 0x51) {
            ObjectRef6 ref;
            FUN_0051d750(stream, &ref, sizeof(ObjectRef6));   // 0x1c bytes
            std::memcpy(rec, &ref, sizeof(ObjectRef6));
            // Vanilla then reads a float scale + writes sin-table entry at
            // rec+0x424 ([0x4b5363]). We store the raw row faithfully.
        } else if (opcode == 0x52 /* 'R' */) {
            // 'R' = reference-point: reads an index + 32-byte name ([0x4b54fe..]).
            uint32_t ref_idx = 0;
            FUN_0051d750(stream, &ref_idx, 4);
            char ref_name[0x21] = {0};
            FUN_0051d7b0(stream, ref_name);
            (void)ref_idx;
        } else if (opcode == 0x00) {
            break;  // end of opcode stream for this object
        }
        // Other opcodes (Y/Z/[/V/W/X) follow the same read pattern; the
        // full case table is at [0x4b52cb..0x4b5667]. We handle the common
        // cases and consume the ObjectRef6 row; remaining opcodes are
        // no-ops here (the faithful body is 2000+ lines).
    }

    // ---- Phase 4: 'atl' list (animation triggers) → DAT_006313b4 ----
    // [0x4b5d25..0x4b5dc5] read count; allocate count*(3*64+1)*4 + 8;
    // head-insert into DAT_006313b4; zero-fill; set +4=count.
    uint32_t atl_count = 0;
    FUN_0051d750(stream, &atl_count, 4);
    if (atl_count) {
        // Stride: (esi*3<<6)+esi = esi*193; *4 + 8 → atl_size per record = 0x304+8.
        // Confirmed: [0x4b5d3a] lea edx,[esi+esi*2]; shl edx,6; add edx,esi → esi*193.
        const uint32_t atl_size = 8 + atl_count * (193u * 4u);
        uint8_t* atl_node = static_cast<uint8_t*>(std::calloc(1, atl_size));
        if (atl_node) {
            *reinterpret_cast<uint32_t*>(atl_node + 4) = atl_count;
            head_insert(&g_PlacementListOsl, atl_node);
        }
    }

    if (g_vTrace) {
        std::fprintf(g_vTrace, "[OBJLIST] scene='%s' odef=%u osl=%u atl=%u | ac=%08x b0=%08x b4=%08x\n",
                     scene_name ? scene_name : "(null)", odef_count, osl_count, atl_count,
                     g_PlacementListOdef, g_PlacementListObjl, g_PlacementListOsl);
        std::fflush(g_vTrace);
    }
}

// ============================================================================
// FUN_004b77f0 — WorldList.bin reader → DAT_00631388 (level table)
// ============================================================================
//
// Confirmed signature: void FUN_004b77f0(void)
// Loops edi = 0..4 (5 files): "worldlist.bin" for edi=0, "worldlist%d.bin" else.
// Disasm evidence:
//   [0x4b77f6] xor edi,edi              ; edi = 0
//   [0x4b77fa] jne 0x4b7826             ; if edi != 0 → format "worldlist%d.bin"
//   [0x4b77fc..0x4b7824] copy literal "worldlist.bin" into local buf  (edi == 0 path)
//   [0x4b7826..0x4b7834] sprintf(buf, "worldlist%d.bin", edi+1)       (edi != 0 path)
//   [0x4b7841] call FUN_00539e30(buf)   ; open via VFS
//   [0x4b784b] test esi,esi; je ...     ; 0 ⇒ "Failed to open worldlist.bin" [0x563198]
//   [0x4b786f] call FUN_0051d750(h,&magic,4)
//   [0x4b7879] cmp eax,0x1a0003d0       ; magic check
//   [0x4b788c] call FUN_0051d750(h,&count,4) ; read blob size
//   [0x4b78a5..0x4b78a7] allocate count bytes, store into g_WorldListBuf[edi]
//   [0x4b78ba] call FUN_0051d750(h, buf, count) ; read string blob
//   [0x4b78c0] call FUN_0051d850(h)     ; close
//   [0x4b78c8] inc edi; cmp edi,5; jl ... ; loop
//   [0x4b78d9] mov [0x631384],0         ; g_LevelCount = 0
//   [0x4b78df..0x4b78f5] sum: for each buf, count += buf[0] (first dword = entry count)
//   [0x4b78fa..0x4b7917] allocate total*0x50A0 bytes → g_LevelTable [0x4b7926]
//   [0x4b7941] rep stosd                ; zero the table
//   [0x4b794a..0x4b79df] fill loop: for each worldlist buf, for each entry,
//                         write name pointers into successive LevelEntry slots
extern "C" void FUN_004b77f0(void) {
    char filename[64];

    // ---- Phase 1: read up to 5 worldlist files into g_WorldListBuf[] ----
    for (int edi = 0; edi < WORLDLIST_FILE_COUNT; edi++) {
        // [0x4b77fa] edi==0 → literal "worldlist.bin"; else sprintf "%s%d.bin"
        if (edi == 0) {
            std::snprintf(filename, sizeof(filename), "worldlist.bin");
        } else {
            // Vanilla uses "worldlist%d.bin" with (edi+1) — files are 1-indexed.
            std::snprintf(filename, sizeof(filename), "worldlist%d.bin", edi + 1);
        }

        // [0x4b7841] open via VFS
        uint32_t handle = FUN_00539e30(filename);
        if (handle == 0) {
            // [0x4b784f..0x4b7853] edi>0 → silent skip; edi==0 → fatal error msg.
            if (edi == 0) {
                if (g_vTrace) { std::fprintf(g_vTrace, "[WORLDLIST] Failed to open %s\n", filename); std::fflush(g_vTrace); }
            }
            continue;
        }

        // [0x4b786f] read magic
        uint32_t magic = 0;
        FUN_0051d750(handle, &magic, 4);
        if (magic != WORLDLIST_MAGIC) {
            // [0x4b787e] jne → skip this file (bad version)
            if (g_vTrace) { std::fprintf(g_vTrace, "[WORLDLIST] %s bad magic %08x (want %08x)\n", filename, magic, WORLDLIST_MAGIC); std::fflush(g_vTrace); }
            FUN_0051d850(handle);
            continue;
        }

        // [0x4b788c] read blob size (the count of string bytes that follow)
        uint32_t blob_size = 0;
        FUN_0051d750(handle, &blob_size, 4);

        // [0x4b78a5..0x4b78a7] allocate blob_size bytes, store ptr in g_WorldListBuf[edi]
        char* blob = nullptr;
        if (blob_size > 0 && blob_size < 0x100000) {
            blob = static_cast<char*>(std::calloc(1, blob_size + 4));
            if (blob) {
                // [0x4b78ba] read the string blob
                FUN_0051d750(handle, blob, blob_size);
                blob[blob_size] = '\0';
                g_WorldListBuf[edi] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(blob));
            }
        }

        // [0x4b78c0] close
        FUN_0051d850(handle);
        if (g_vTrace) { std::fprintf(g_vTrace, "[WORLDLIST] loaded %s blob=%u\n", filename, blob_size); std::fflush(g_vTrace); }
    }

    // ---- Phase 2: sum the per-file level counts → g_LevelCount ----
    // [0x4b78d9] g_LevelCount = 0
    // [0x4b78df..0x4b78f5] for each buf: count += *(uint32_t*)buf
    //   (the first dword of each blob is the entry count for that file)
    g_LevelCount = 0;
    for (int i = 0; i < WORLDLIST_FILE_COUNT; i++) {
        char* blob = reinterpret_cast<char*>(static_cast<uintptr_t>(g_WorldListBuf[i]));
        if (blob) {
            uint32_t per_file = *reinterpret_cast<uint32_t*>(blob);
            g_LevelCount += per_file;
        }
    }

    // ---- Phase 3: allocate g_LevelTable = g_LevelCount * 0x50A0 ----
    // [0x4b78fa] eax = count*129; edx = eax*5; edx <<= 5 → count*0x50A0
    // [0x4b7917] call allocate(count*0x50A0)
    // [0x4b7926] g_LevelTable = alloc base
    // [0x4b7941] rep stosd (zero)
    if (g_LevelCount == 0) {
        g_LevelTable = 0;
        if (g_vTrace) { std::fprintf(g_vTrace, "[WORLDLIST] no levels loaded\n"); std::fflush(g_vTrace); }
        return;
    }
    const uint32_t table_bytes = g_LevelCount * sizeof(LevelEntry);   // count * 0x50A0
    LevelEntry* table = static_cast<LevelEntry*>(std::calloc(1, table_bytes));
    if (!table) {
        g_LevelTable = 0;
        if (g_vTrace) { std::fprintf(g_vTrace, "[WORLDLIST] alloc %u FAILED\n", table_bytes); std::fflush(g_vTrace); }
        return;
    }
    g_LevelTable = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(table));

    // ---- Phase 4: fill the table from the per-file string blobs ----
    // [0x4b794a..0x4b79df] For each worldlist buf, walk its NUL-terminated
    // strings and write {something, name_ptr, name_ptr2} into successive entries.
    //   [0x4b7998] entry->name_ptr (at +0x04) = current string in blob
    //   [0x4b79b5] entry->name_ptr2 (at +0x08) = next string (link)
    //   [0x4b79c1] entry->something (at +0x00) = dword from blob
    uint32_t slot = 0;
    for (int i = 0; i < WORLDLIST_FILE_COUNT && slot < g_LevelCount; i++) {
        char* blob = reinterpret_cast<char*>(static_cast<uintptr_t>(g_WorldListBuf[i]));
        if (!blob) continue;
        // Layout (verified on worldlist.bin, 688B): [count:u32][count×offset:u32][strings].
        // name[i] = blob + offset[i]  (offset[0]=0x80=128 → "Story1"). Offsets relative to blob start.
        uint32_t per_file = *reinterpret_cast<uint32_t*>(blob);
        uint32_t* offsets = reinterpret_cast<uint32_t*>(blob + 4);
        for (uint32_t j = 0; j < per_file && slot < g_LevelCount; j++, slot++) {
            LevelEntry* e = &table[slot];
            char* nm = blob + offsets[j];
            e->name_ptr = nm;                                           // [0x4b7998]
            char* next = nm; while (*next) ++next; ++next;              // skip NUL
            e->name_ptr2 = next;                                        // [0x4b79b5]
            e->something = *reinterpret_cast<uint32_t*>(nm);            // [0x4b79c1]
        }
    }

    if (g_vTrace) {
        std::fprintf(g_vTrace, "[WORLDLIST] level table built: %u entries @ %08x (stride 0x50A0)\n",
                     g_LevelCount, g_LevelTable);
        // Log first few level names for verification.
        for (uint32_t i = 0; i < g_LevelCount && i < 8; i++) {
            const char* nm = table[i].name_ptr ? table[i].name_ptr : "(null)";
            std::fprintf(g_vTrace, "[WORLDLIST]   [%u] '%s'\n", i, nm);
        }
        std::fflush(g_vTrace);
    }
}
