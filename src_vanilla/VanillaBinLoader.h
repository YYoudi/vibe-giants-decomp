// Giants Vanilla-Native Recomp — .BIN level-file loader.
//
// Faithful port of Giants.exe!FUN_004b7c50 (readwrls.c) for the vanilla 1.0
// retail binary (G:\GiantsRE\GameFiles-VanillaV1\Giants.exe, base 0x400000).
//
// CONFIRMED .BIN HEADER LAYOUT (disasm evidence in VanillaBinLoader.cpp):
//
//   offset  size  field                evidence (Giants.exe VA)
//   ------  ----  -------------------  ----------------------------------------
//   0x0000   4    magic                0x1a0002e5  (cmp eax,0x1a0002e5 @ 0x4b7cbe)
//   0x0004   4    version/flags =0x20  read as header[0] in the 0x1c read @ 0x4b7d04
//   0x0008   4    sectionOffset[0]     header[1] — render/name-list section
//   0x000c   4    sectionOffset[1]     header[2] — world/terrain section
//   0x0010   4    sectionOffset[2]     header[3] — texturesmemory section
//   0x0014   4    sectionOffset[3]     header[4] — fx section
//   0x0018   4    sectionOffset[4]     header[5] — unk2/huds section
//   0x001c   4    sectionOffset[5]     header[6] — objects/odef section
//   0x0020   ...  metadata C-strings   read via FUN_0051d7b0 @ 0x4b7d12/0x4b7d26/0x4b7d40
//                     (level name, .gti path, stream path)
//   ...           name-list section    header[1]: u32 count, then count ×
//                                        { u8 flagsLo, u8 flagsHi, u8 nameLen, char name[nameLen] }
//                                        (verified: w_intro_island 7 textures → ends exactly
//                                         at header[4]; w_intro 204 sprites → ends at header[4])
//   ...           odef blob            object-definition VM script (opcodes 0x13..0x84,
//                                        jump table @ 0x4baa28); each object instance record
//                                        carries mesh/spawn names — these are the placements.
//
// The header is 0x1c bytes (7 × u32) read in one FUN_0051d750 call at 0x4b7d04.
// header[0]=0x20 is a format constant; header[1..6] are absolute file offsets to the
// six sections (proven self-consistent against w_intro_island.bin [1514 B] and
// w_intro.bin [3301 B]: every offset lies within the file and the name-list parse
// terminates exactly at the next recorded section offset).
//
// NOTE on section handlers: terrain (world), SFX, fx and the full odef VM are NOT
// ported here. FUN_004b7c50 drives them through ~80 odef opcodes (jump table
// 0x4baa28) and several subsystem calls (FUN_004b50b0, FUN_0049a580, FUN_0050d8f0).
// This module skips those sections by their recorded offsets and, for the objects
// section, logs the parsed placements without inserting them into engine lists
// (engine insertion is a separate module's responsibility).
#pragma once
#include <cstdint>

extern uint32_t g_binTraceLevel;   // global trace level (0 = silent, >=1 = log)

extern "C" {
    // Faithful port of Giants.exe!FUN_004b7c50 (readwrls.c .BIN loader).
    //   binName - level file name, e.g. "w_intro_island.bin" (resolved via FUN_00539e30)
    //   a2      - float arg passed to recursive sub-bin loads (vanilla a2)
    //   a3      - int arg (vanilla a3)
    // Opens binName, validates magic 0x1a0002e5, reads the 0x1c header, walks the
    // sections. Unported sections are skipped by their recorded offsets; object
    // placements (odef instances) are logged. Does not mutate engine lists.
    void FUN_004b7c50(const char* binName, float a2, int a3);
}

namespace VanillaBinLoader {
// Self-test: opens "w_intro_island.bin", logs the parsed header, the name-list
// section and the first object placements + total object count. Returns 0 on
// success, nonzero on failure. Verifiable via g_binTraceLevel >= 1.
int SelfTest();
} // namespace VanillaBinLoader
