// Giants Vanilla-Native Recomp — texture-list feed to renderer (FUN_004b7c50 sub-path).
//
// Faithful sub-port of FUN_004b7c50 @ 0x4b7d26 (the SEEK header[1] +
// FUN_0050d8f0(name, handle) call) followed by FUN_0050e4d0 (texture-list walker
// → renderer slot +0xb4). This is the recipe from RE_docs/OBJECT_VTABLE_SYSTEM.md
// §7 ("To install a real Render on an entity, do X") Step 1+2:
//
//   Step 1: populate g_TextureEntityList from the level .BIN
//   Step 2: dispatch each entry via SceneWalk_Textures() to the renderer
//
// After this, the original gg_dx7r.dll's slot +0xb4 (RVA 0xc6a0 → 0xc630)
// should move the engine data into its renderer-internal list, and the
// renderer's per-frame slot +0x10 (RVA 0x2d80) should build scene-entities.
#include "VanillaFeed.h"
#include "VanillaFileIO.h"
#include "VanillaSceneTypes.h"
#include "VanillaEngine.h"

#include <cstdio>
#include <cstdint>
#include <cstring>

extern "C" FILE* g_vTrace;

// Defined in VanillaSceneLists.cpp / VanillaSceneDispatch.cpp.
extern "C" void  FUN_0050d8f0(const char* name, uint32_t stream);
extern "C" uint32_t SceneWalk_Textures(void);   // FUN_0050e4d0 port

namespace {

constexpr uint32_t kBinMagic = 0x1a0002e5u;     // [0x4b7cbe] cmp eax,0x1a0002e5

} // namespace

// ============================================================================
// VanillaFeedTextures — populate g_TextureEntityList + dispatch to renderer.
// ============================================================================
extern "C" uint32_t VanillaFeedTextures(void) {
    const char* kLevel = "w_intro_island.bin";

    if (g_vTrace) { std::fprintf(g_vTrace, "[FEED] begin: '%s'\n", kLevel); std::fflush(g_vTrace); }

    // 1. Open the level .BIN via the engine file API (FUN_00539e30).
    uint32_t handle = FUN_00539e30(kLevel);
    if (handle == 0) {
        if (g_vTrace) { std::fprintf(g_vTrace, "[FEED] FAILED to open '%s'\n", kLevel); std::fflush(g_vTrace); }
        return 0;
    }
    if (g_vTrace) { std::fprintf(g_vTrace, "[FEED] opened '%s' handle=%u\n", kLevel, handle); std::fflush(g_vTrace); }

    // 2. READ 4-byte magic.                                       [0x4b7cb2]
    uint32_t magic = 0;
    FUN_0051d750(handle, &magic, 4);
    if (magic != kBinMagic) {
        if (g_vTrace) { std::fprintf(g_vTrace, "[FEED] BAD magic 0x%08x (expected 0x%08x)\n", magic, kBinMagic); std::fflush(g_vTrace); }
        FUN_0051d850(handle);
        return 0;
    }

    // 3. READ 0x1c-byte header (7 u32 section offsets).           [0x4b7d04]
    uint32_t header[7] = {0};
    FUN_0051d750(handle, header, 0x1c);
    if (g_vTrace) {
        std::fprintf(g_vTrace, "[FEED] header (7 section offsets):\n");
        for (int i = 0; i < 7; i++)
            std::fprintf(g_vTrace, "[FEED]   header[%d]=%u (0x%x)\n", i, header[i], header[i]);
        std::fflush(g_vTrace);
    }

    // 4. SEEK header[1] (name_list) then call FUN_0050d8f0(name, handle).
    //    This mirrors FUN_004b7c50 [0x4b7d24..0x4b7d32] exactly:
    //      push ecx (=header[1]); push esi (=handle); call 0x51d7b0   ; SEEK
    //      push edx (=version); push esi (=handle); push ebp (=name); call 0x50d8f0
    //    FUN_0050d8f0 reads sub_count + entries from the name_list section.
    FUN_0051d7b0(handle, header[1]);
    if (g_vTrace) { std::fprintf(g_vTrace, "[FEED] SEEK name_list @%u; calling FUN_0050d8f0\n", header[1]); std::fflush(g_vTrace); }

    // Caller passes the level base-name (without .bin) as the node name.
    // The vanilla code at [0x4b7d31] pushes ebp which was loaded with arg1 of
    // FUN_004b7c50 (the full bin name string from the caller). We pass the
    // level base name for clarity (FUN_0050d8f0 copies it into node->name).
    FUN_0050d8f0(kLevel, handle);

    // Snapshot list state.
    uint32_t list_head = g_TextureEntityList;
    uint32_t sub_total = 0;
    for (TextureListNode* n = reinterpret_cast<TextureListNode*>(static_cast<uintptr_t>(list_head));
         n; n = n->next) {
        sub_total += n->sub_count;
    }
    if (g_vTrace) {
        std::fprintf(g_vTrace, "[FEED] g_TextureEntityList head=0x%08x total_sub_entries=%u\n",
                     list_head, sub_total);
        std::fflush(g_vTrace);
    }

    // 5. Close the file handle (FUN_0050d8f0 leaves the cursor mid-stream).
    FUN_0051d850(handle);

    // 6. Dispatch each texture entry to the renderer via SceneWalk_Textures()
    //    (= FUN_0050e4d0 port → renderer slot +0xb4 per entry).
    if (g_vRenderer) {
        if (g_vTrace) { std::fprintf(g_vTrace, "[FEED] dispatching to renderer %p via SceneWalk_Textures...\n", g_vRenderer); std::fflush(g_vTrace); }
        uint32_t dispatched = SceneWalk_Textures();
        if (g_vTrace) { std::fprintf(g_vTrace, "[FEED] SceneWalk_Textures dispatched %u entries via slot 0xb4\n", dispatched); std::fflush(g_vTrace); }
        return dispatched;
    } else {
        if (g_vTrace) { std::fprintf(g_vTrace, "[FEED] g_vRenderer=NULL — cannot dispatch to slot 0xb4\n"); std::fflush(g_vTrace); }
        return 0;
    }
}
