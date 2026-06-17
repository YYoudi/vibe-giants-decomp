// Giants Vanilla-Native Recomp — Loading-screen picker + async-load launcher.
// Faithful port of vanilla FUN_0045a530 (VA 0x0045a530, size 269).
// See vanilla_decompiled/0045a530.json, behavior_specs/loading_screen.md.
//
// What FUN_0045a530 does (decompiled body):
//   FUN_0050e4d0();                          // flush/reset scene state
//   DAT_006316e4 = 1;                        // "loading screen active" flag
//   DAT_0059ca70 = 0; DAT_0059ca54 = 0;      // clear colour/UV accumulators
//   _DAT_0059ca6c = 1.0f; _DAT_0059ca68 = 1.0f;
//   FUN_0050f120(DAT_0059ca58..DAT_0059ca64); // tear down previous loading texture
//   DAT_0059ca58..DAT_0059ca64 = 0;
//   iVar1 = FUN_004b7640(DAT_0059ca4c);      // resolve pending-level object
//   switch ( toupper(name[0]) ) {            // via FUN_005460c2
//     case 'K': PTR_s_kabuto_loading_0055c1cc;
//     case 'R': PTR_s_reaper_loading_0055c1c8;
//     case 'I': PTR_s_giants_loading_0055c1d0;
//     default:  PTR_s_mecc_loading_0055c1c4;
//   }
//   FUN_0050eb50(picked, &DAT_0059ca58..);   // load+bind loading .tga
//   FUN_0042bfb0();                          // prime async level load
//   FUN_0042be00(&LAB_0045a640, &LAB_0045a7c0); // install async task callbacks
// All 4 loading .tga live in Bin/xx_giants_logo_3d.gzp.
#pragma once
#include <cstdint>

namespace VanillaLoadScreen {

// Pick the loading-screen texture name by the FIRST LETTER of the level name
// (vanilla FUN_0045a530 switch, case-insensitive via toupper):
//   'K' -> kabuto_loading, 'R' -> reaper_loading, 'I' -> giants_loading (intro_island),
//   default -> mecc_loading.
const char* PickLoadingScreen(const char* levelName);

// Port of FUN_0045a530: pick + load+parse the loading .tga (stands in for the
// renderer's FUN_0050eb50 texture-bind callback, not yet callable). The async
// machinery (FUN_0042bfb0 + FUN_0042be00) depends on unported callees -> FIXME.
void ShowLoadingScreen(const char* levelName);

// Self-test: PickLoadingScreen("intro_island") == "giants_loading" + the texture
// is readable/parseable from xx_giants_logo_3d.gzp. Logs to g_vTrace.
bool SelfTest();

} // namespace VanillaLoadScreen
