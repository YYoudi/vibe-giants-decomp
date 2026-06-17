// Giants Vanilla-Native Recomp — Loading-screen picker + async-load launcher.
// Faithful port of vanilla FUN_0045a530 (VA 0x0045a530, size 269). See .h.
#include "VanillaLoadScreen.h"
#include "VanillaVFS.h"
#include "VanillaTGA.h"

#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>

extern FILE* g_vTrace;

namespace VanillaLoadScreen {

// vanilla .rdata name pointers (VA): mecc 0x0055c1c4, reaper 0x0055c1c8,
// kabuto 0x0055c1cc, giants 0x0055c1d0. String bodies 0x0055c1d4..0x0055c208.
static const char* const kMeccLoadingName   = "mecc_loading";     // PTR_s_mecc_loading_0055c1c4
static const char* const kReaperLoadingName = "reaper_loading";   // PTR_s_reaper_loading_0055c1c8
static const char* const kKabutoLoadingName = "kabuto_loading";   // PTR_s_kabuto_loading_0055c1cc
static const char* const kGiantsLoadingName = "giants_loading";   // PTR_s_giants_loading_0055c1d0

// All four loading textures are packed in this single archive.
static const char* const kLoadingScreenArchive = "Bin\\xx_giants_logo_3d.gzp";

// FUN_0045a530's switch (the picker). Decompiled short-circuit chain:
// toupper(name[0]) compared as 0x4b('K') -> 0x52('R') -> 0x49('I') -> default(mecc).
const char* PickLoadingScreen(const char* levelName) {
    if (levelName == nullptr || levelName[0] == '\0') return kMeccLoadingName;
    int first = std::toupper(static_cast<unsigned char>(levelName[0]));
    if (first == 0x4b) return kKabutoLoadingName;   // 'K'
    if (first == 0x52) return kReaperLoadingName;   // 'R'
    if (first == 0x49) return kGiantsLoadingName;   // 'I' (intro_island)
    return kMeccLoadingName;                         // default
}

// FUN_0045a530. The original reads the pending-level object from DAT_0059ca4c via
// FUN_004b7640; only the name string (obj+4) is inspected. We take the name directly.
void ShowLoadingScreen(const char* levelName) {
    // FIXME(unverified): FUN_0050e4d0 scene-flush + DAT_006316e4/0059ca* state block
    // + FUN_0050f120 previous-texture release — renderer-internal, not ported.

    const char* texName = PickLoadingScreen(levelName);
    if (g_vTrace) {
        std::fprintf(g_vTrace,
            "[VLoadScreen] FUN_0045a530: level='%s' first=0x%02X -> pick '%s'\n",
            levelName ? levelName : "<null>",
            (levelName && levelName[0])
                ? (unsigned)(unsigned char)std::toupper((unsigned char)levelName[0]) : 0u,
            texName);
        std::fflush(g_vTrace);
    }

    // FUN_0050eb50 (renderer load+bind-texture callback) is not callable yet (no live
    // bind path). Verify the data path instead: load+parse the .tga from the GZP.
    char tgaName[64];
    std::snprintf(tgaName, sizeof(tgaName), "%s.tga", texName);
    std::vector<uint8_t> raw = VanillaVFS::GzpReadFile(kLoadingScreenArchive, tgaName);
    if (raw.empty()) {
        if (g_vTrace) { std::fprintf(g_vTrace, "[VLoadScreen] !! %s not found in %s\n", tgaName, kLoadingScreenArchive); std::fflush(g_vTrace); }
    } else {
        VanillaTGA::Image img = VanillaTGA::Parse(raw.data(), raw.size());
        if (g_vTrace) {
            std::fprintf(g_vTrace, "[VLoadScreen] bound %s: %ux%u %ubpp type=%u (%zu bytes) %s\n",
                tgaName, img.width, img.height, img.bitsPerPixel, img.imageType, raw.size(),
                img.ok ? "OK" : "PARSE-FAIL");
            std::fflush(g_vTrace);
        }
    }

    // FIXME(unverified): async-load install (FUN_0042bfb0 + FUN_0042be00 @ LAB_0045a640/
    // LAB_0045a7c0) — depends on the engine task scheduler + BIN scene loader. Tracing only.
    if (g_vTrace) { std::fprintf(g_vTrace, "[VLoadScreen] FIXME: async-load install skipped (FUN_0042bfb0+FUN_0042be00 unported)\n"); std::fflush(g_vTrace); }
}

bool SelfTest() {
    const char* picked = PickLoadingScreen("intro_island");
    const bool pickerOk = (picked && std::strcmp(picked, "giants_loading") == 0);
    if (g_vTrace) {
        std::fprintf(g_vTrace, "[VLoadScreen] SelfTest: PickLoadingScreen(\"intro_island\") -> \"%s\"%s\n",
            picked ? picked : "<null>", pickerOk ? "  [OK]" : "  [FAIL]");
        std::fflush(g_vTrace);
    }
    bool dataOk = false;
    if (pickerOk) {
        std::vector<uint8_t> raw = VanillaVFS::GzpReadFile(kLoadingScreenArchive, "giants_loading.tga");
        if (!raw.empty()) {
            VanillaTGA::Image img = VanillaTGA::Parse(raw.data(), raw.size());
            dataOk = img.ok;
            if (g_vTrace) { std::fprintf(g_vTrace, "[VLoadScreen] SelfTest: giants_loading.tga -> %s (%ux%u %ubpp)\n", img.ok?"PARSED":"PARSE-FAIL", img.width, img.height, img.bitsPerPixel); std::fflush(g_vTrace); }
        }
    }
    if (g_vTrace) { std::fprintf(g_vTrace, "[VLoadScreen] SelfTest: %s%s\n", pickerOk?"PICKER-OK":"PICKER-FAIL", dataOk?" + DATA-OK":" + DATA-MISSING"); std::fflush(g_vTrace); }
    return pickerOk && dataOk;
}

} // namespace VanillaLoadScreen
