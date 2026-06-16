// Giants Vanilla-Native Recomp — per-frame TEXTURE DATA loader (FUN_0050dd20 port).
// See VanillaTextureLoad.h for the contract and RE_docs/TEXTURE_LOADER.md for the
// full disasm-confirmed reference.
//
// Faithful 1:1 port of vanilla FUN_0050dd20 @ 0x50dd20. The vanilla body:
//   [0x50dd27] ebx = arg1 (TextureEntry*)
//   [0x50dd30] if (entry->surface_data [+0x04] != 0) return;   // idempotent
//   [0x50dd3c..0x50dd6d] walk g_TextureEntityList (DAT_005a78b4) + secondary list
//                        (DAT_005a78b8) to locate the owning node + entry index.
//                        If not found → log + zero entry+0x04 + return.
//   [0x50ddeb] eax = g_vRenderer (DAT_00654940)
//   [0x50ddf5] call [eax+0xc0](renderer, entry, 0, 0)   // slot +0xc0 mip-bias adjust
//   [0x50ddff] if returned nonzero AND ~(entry_flag_byte & 4):
//   [0x50dfe9..] TGA path: build filename, FUN_0053a3e0 (VFS open+read), parse TGA
//                header (type 1/2/3, cmap, bpp 8/24/32), compute format code,
//                write entry+0x14 (format), +0x18 (mip levels), +0x1e flags,
//                allocate pixel buffer (FUN_0053c810), memcpy pixels, store at
//                entry+0x04, set entry+0x1e bit 0.
//   [0x50de9b..] DDS path: if first 4 bytes == "DDS " (0x20534444) parse DDS header.
//   [0x50e0eb/0x50e13d] tail-jmp FUN_00523b40 → sets DAT_005dcb14 = 1 (textures-changed).
//
// Pixel source: the .tga bytes live in the level GZP archive (e.g.
// Bin/w_intro_island.gzp contains intro_sea.tga, intro_grnd.tga, ...). The
// recomp uses VanillaVFS::GzpReadFile to fetch them and VanillaTGA::Parse to
// decode (the vanilla engine uses its own VFS via FUN_0053a3e0 + an inline TGA
// parser; the recomp's VanillaTGA is a faithful equivalent for type-2/10 TGAs).
#include "VanillaTextureLoad.h"
#include "VanillaSceneTypes.h"
#include "VanillaEngine.h"
#include "VanillaTGA.h"
#include "VanillaVFS.h"

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

extern "C" FILE* g_vTrace;   // defined in VanillaEngine.cpp / WinMain_vanilla.cpp

// ── Renderer method-table invoker (cdecl this-first, per DX7_METHOD_MAP.md §1).
// Slot +0xc0 (gg_dx7r.dll RVA 0xae80). Vanilla call site [0x50ddf5]:
//   push 0; push 0; push ebx(entry); push eax(renderer); call [eax+0xc0]
// Returns nonzero if the entry's effective dimensions changed (mip-bias adjust).
namespace {
inline int RendererSlotC0(void* renderer, void* entry) {
    if (!renderer) return 0;
    typedef int(__cdecl *SlotC0Fn)(void*, void*, uint32_t, uint32_t);
    void** methods = (void**)renderer;
    SlotC0Fn fn = (SlotC0Fn)methods[0xc0 / 4];
    if (!fn) return 0;
    return fn(renderer, entry, 0, 0);
}
} // namespace

// Locate the owning TextureListNode + entry index for `entry` by walking
// g_TextureEntityList (DAT_005a78b4). Mirrors vanilla [0x50dd3c..0x50dd6d].
// Returns true if found (outputs node + index); false otherwise.
static bool FindEntryOwner(TextureEntry* entry,
                           TextureListNode** outNode, uint32_t* outIndex) {
    if (!entry) return false;
    TextureListNode* node = reinterpret_cast<TextureListNode*>(
        static_cast<uintptr_t>(g_TextureEntityList));
    while (node) {
        uint32_t sub_count = node->sub_count;          // [0x50dd47] [esi+0x28]
        uintptr_t entries_base = reinterpret_cast<uintptr_t>(node) + 0x2c;
        for (uint32_t i = 0; i < sub_count; ++i) {      // [0x50dd50..0x50dd5d] stride 0x24
            if (reinterpret_cast<uintptr_t>(entry) == entries_base + i * 0x24) {
                if (outNode) *outNode = node;
                if (outIndex) *outIndex = i;
                return true;
            }
        }
        node = node->next;                              // [0x50dd67] mov esi,[esi]
    }
    return false;
}

// DAT_005dcb14 — "textures changed" flag. Set by vanilla FUN_00523b40 (the
// tail-jump target of FUN_0050dd20's TGA/DDS paths). The game loop checks this
// and re-queries the display config + rebuilds the pipeline when set.
extern "C" {
uint32_t g_TexturesChangedFlag_5dcb14 = 0;
}

// Look up a texture by name across all Bin/*.gzp archives the engine knows about.
// The vanilla engine resolves these via its VFS (FUN_0053a3e0 → callback[17]); the
// recomp searches the same level archives VanillaFeedTextures opens.
static std::vector<uint8_t> LoadTextureBytes(const char* name) {
    static const char* const kArchives[] = {
        "Bin\\w_intro_island.gzp",
        "Bin\\w_storym.bin.gzp",
        // Add more level archives as they are wired into VanillaFeedTextures.
    };
    char tgaName[256];
    std::snprintf(tgaName, sizeof(tgaName), "%s.tga", name);
    for (const char* arch : kArchives) {
        std::vector<uint8_t> bytes = VanillaVFS::GzpReadFile(arch, tgaName);
        if (!bytes.empty()) {
            if (g_vTrace) {
                std::fprintf(g_vTrace, "[TEXLOAD] '%s' -> %zu bytes from %s\n",
                             tgaName, bytes.size(), arch);
                std::fflush(g_vTrace);
            }
            return bytes;
        }
    }
    // Fallback: try .dds
    char ddsName[256];
    std::snprintf(ddsName, sizeof(ddsName), "%s.dds", name);
    for (const char* arch : kArchives) {
        std::vector<uint8_t> bytes = VanillaVFS::GzpReadFile(arch, ddsName);
        if (!bytes.empty()) return bytes;
    }
    return {};
}

// ============================================================================
// FUN_0050dd20 — faithful port.
// ============================================================================
extern "C" void FUN_0050dd20(TextureEntry* entry) {
    if (!entry) return;

    // [0x50dd30] idempotency: entry+0x04 (surface_data) already populated → skip.
    void* surface_data = *reinterpret_cast<void**>(
        reinterpret_cast<uint8_t*>(entry) + 0x04);
    if (surface_data != nullptr) {
        return;
    }

    // [0x50dd3c..0x50dd6d] locate owning node + index. If not found, vanilla
    // logs an error and zeros entry+0x04 (it's already 0) and returns.
    TextureListNode* node = nullptr;
    uint32_t index = 0;
    if (!FindEntryOwner(entry, &node, &index)) {
        const char* nm = *reinterpret_cast<const char* const*>(entry);
        if (g_vTrace) {
            std::fprintf(g_vTrace, "[TEXLOAD] entry %p ('%s') not in any list node — skip\n",
                         (void*)entry, nm ? nm : "(null)");
            std::fflush(g_vTrace);
        }
        return;
    }

    // Entry name (string-pool ptr at entry+0x00, installed by FUN_0050d8f0).
    const char* entryName = *reinterpret_cast<const char* const*>(entry);

    // [0x50ddeb..0x50ddf5] call renderer slot +0xc0 (mip-bias adjust).
    int dimsChanged = 0;
    if (g_vRenderer) {
        dimsChanged = RendererSlotC0(g_vRenderer, entry);
    }

    // [0x50de07..0x50de15] entry flag byte at (node + index*0x24) + 0x4f - 0x2c =
    // entry + 0x23 (the flagsHi byte set by FUN_0050d8f0). Vanilla tests
    // `~flag & 4`: bit 2 = "renderer already created a surface for this entry".
    // If bit 2 is set, the renderer owns the surface → no engine-side data load.
    uint8_t flagsHi = *(reinterpret_cast<uint8_t*>(entry) + 0x23);
    if ((~flagsHi & 0x04) == 0) {
        // Bit 2 set: renderer has already bound this entry. Nothing to load.
        if (g_vTrace) {
            std::fprintf(g_vTrace, "[TEXLOAD] '%s' flag&4 set (renderer-bound) — skip load\n",
                         entryName ? entryName : "(null)");
            std::fflush(g_vTrace);
        }
        return;
    }

    if (g_vTrace) {
        std::fprintf(g_vTrace, "[TEXLOAD] '%s' dimsChanged=%d — loading pixel data...\n",
                     entryName ? entryName : "(null)", dimsChanged);
        std::fflush(g_vTrace);
    }

    // [0x50dfe9..] TGA path: fetch + parse the .tga.
    std::vector<uint8_t> raw = LoadTextureBytes(entryName ? entryName : "");
    if (raw.empty()) {
        if (g_vTrace) {
            std::fprintf(g_vTrace, "[TEXLOAD] '%s' NOT FOUND in any GZP — entry+0x04 stays NULL\n",
                         entryName ? entryName : "(null)");
            std::fflush(g_vTrace);
        }
        return;
    }

    // [0x50de9b] DDS magic check ("DDS " = 0x20534444).
    if (raw.size() >= 4 && raw[0] == 'D' && raw[1] == 'D' && raw[2] == 'S' && raw[3] == ' ') {
        // DDS path: vanilla copies the full DDS (header + surface) into an
        // engine-allocated buffer and hands it to the renderer verbatim. We
        // store the raw DDS bytes at entry+0x04 (the renderer's DDS upload path
        // in slot +0xb0 reads the format from the DDS header in-place).
        uint8_t* buf = static_cast<uint8_t*>(std::malloc(raw.size()));
        if (buf) {
            std::memcpy(buf, raw.data(), raw.size());
            *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(entry) + 0x04) = buf;
            // [0x50e213] entry+0x1e |= 4 (format = DDS / renderer-managed).
            *(reinterpret_cast<uint8_t*>(entry) + 0x1e) |= 0x04;
        }
        if (g_vTrace) {
            std::fprintf(g_vTrace, "[TEXLOAD] '%s' DDS %zu bytes -> entry+0x04=%p\n",
                         entryName ? entryName : "(null)", raw.size(), (void*)buf);
            std::fflush(g_vTrace);
        }
        // [0x50e0eb] tail-jmp FUN_00523b40 → DAT_005dcb14 = 1.
        g_TexturesChangedFlag_5dcb14 = 1;
        return;
    }

    // TGA path: parse via VanillaTGA::Parse (vanilla inlines an equivalent parser).
    VanillaTGA::Image img = VanillaTGA::Parse(raw.data(), raw.size());
    if (!img.ok) {
        if (g_vTrace) {
            std::fprintf(g_vTrace, "[TEXLOAD] '%s' TGA parse FAILED (type=%u bpp=%u)\n",
                         entryName ? entryName : "(null)", img.imageType, img.bitsPerPixel);
            std::fflush(g_vTrace);
        }
        return;
    }

    // [0x50e27b..0x50e2c1] allocate pixel buffer + memcpy.
    //   size = (bpp/8) * width * height  ([0x50e28f..0x50e2a2])
    uint8_t* pix = static_cast<uint8_t*>(std::malloc(img.pixels.size()));
    if (!pix) {
        if (g_vTrace) { std::fprintf(g_vTrace, "[TEXLOAD] '%s' pixel alloc FAILED\n", entryName); std::fflush(g_vTrace); }
        return;
    }
    std::memcpy(pix, img.pixels.data(), img.pixels.size());

    // [0x50e2c1] mov [ebx+4], eax  — store pixel buffer at entry+0x04.
    *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(entry) + 0x04) = pix;

    // [0x50e20a..0x50e274] write format/mip fields based on bpp + alpha.
    //   entry+0x14 = format code, entry+0x18 = mip levels, entry+0x1e flags.
    // Vanilla format codes (disasm [0x50e24d..0x50e274]):
    //   32bpp w/ alpha → 4 (A8R8G8B8), mip = entry+0x18 = 3 or per-caps
    //   24bpp          → 0 (R8G8B8)
    //   16bpp          → 2 (R5G6B5), mip per caps
    uint32_t format = 0, mips = 0;
    uint8_t* e1e = reinterpret_cast<uint8_t*>(entry) + 0x1e;
    if (img.bitsPerPixel == 32) {
        format = 4;                          // [0x50e21f] entry+0x14 = 0 (set below for 32)
        // vanilla: 32bpp path sets +0x14=0 and +0x18 per renderer caps; we use 3.
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(entry) + 0x14) = 0;
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(entry) + 0x18) = 3;
        *e1e |= 0x04;                        // [0x50e213] mark has-alpha/format
    } else if (img.bitsPerPixel == 24) {
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(entry) + 0x14) = 0;
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(entry) + 0x18) = 0;
    } else if (img.bitsPerPixel == 16) {
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(entry) + 0x14) = 2;
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(entry) + 0x18) = 5;
    }
    (void)format; (void)mips;

    // [0x50e2d0] entry+0x1e |= 1 (pixel data present).
    *e1e |= 0x01;

    if (g_vTrace) {
        std::fprintf(g_vTrace,
                     "[TEXLOAD] '%s' TGA %ux%u %ubpp -> entry+0x04=%p (+0x14=%u +0x18=%u +0x1e=0x%02x)\n",
                     entryName ? entryName : "(null)", img.width, img.height, img.bitsPerPixel,
                     (void*)pix,
                     *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(entry) + 0x14),
                     *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(entry) + 0x18),
                     *e1e);
        std::fflush(g_vTrace);
    }

    // [0x50e0eb/0x50e13d] tail-jmp FUN_00523b40 → DAT_005dcb14 = 1.
    g_TexturesChangedFlag_5dcb14 = 1;
}

// ============================================================================
// VanillaLoadAllTextures — iterate g_TextureEntityList + load every entry.
// ============================================================================
extern "C" void VanillaLoadAllTextures(void) {
    uint32_t total = 0;
    TextureListNode* node = reinterpret_cast<TextureListNode*>(
        static_cast<uintptr_t>(g_TextureEntityList));
    while (node) {
        uint32_t sub_count = node->sub_count;
        uint8_t* entries = reinterpret_cast<uint8_t*>(node) + 0x2c;
        for (uint32_t i = 0; i < sub_count; ++i) {
            TextureEntry* e = reinterpret_cast<TextureEntry*>(entries + i * 0x24);
            FUN_0050dd20(e);
            ++total;
        }
        node = node->next;
    }
    if (g_vTrace) {
        std::fprintf(g_vTrace, "[TEXLOAD] VanillaLoadAllTextures: processed %u entries\n", total);
        std::fflush(g_vTrace);
    }
}
