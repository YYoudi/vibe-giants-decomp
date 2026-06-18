// Vanilla recomp — boot/CLI configuration.
// Phase-jump + test flags so the agent can test a specific boot phase WITHOUT
// replaying the full ~15s intro sequence every iteration. Parsed once in WinMain
// from lpCmdLine, consumed by the boot state machine (VanillaDriveFrame) + init.
//
// Flags (all optional, dev/test-only — the canonical boot ignores them):
//   -skip-intros / -nointro   jump past INTRO phases straight to LOADING/MENU
//   -at menu                   start directly at the 3D MENU phase
//   -at level:<name>           (future) load <name> directly via the level chain
//   -frames <N>                exit cleanly after N rendered MENU frames (deterministic capture)
//   -no-audio                  skip audio subsystem init
//   -window                    windowed (already default)
#pragma once
#include <cstdint>

struct VanillaBootConfig {
    bool   skipIntros  = false;   // -skip-intros / -nointro
    bool   atMenu      = false;   // -at menu
    bool   noAudio     = false;   // -no-audio
    bool   scene3d     = false;   // -scene3d: MENU calls the renderer's REAL scene walk (0x7370) instead of the 2D bracket
    int    frameLimit  = 0;       // -frames N (0 = unlimited)
    char   level[64]   = {0};     // -at level:<name> (future)
};

// Global config, defined in WinMain_vanilla.cpp, set by VanillaParseArgs().
extern VanillaBootConfig g_bootCfg;

// Parse lpCmdLine into g_bootCfg. Call once at WinMain start.
void VanillaParseArgs(const char* cmdLine);
