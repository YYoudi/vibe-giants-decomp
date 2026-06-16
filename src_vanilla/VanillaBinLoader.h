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
//   0x0004   4    header[0]            odef_blob section offset (=0x20). SEEK target @ 0x4b7e5d
//   0x0008   4    header[1]            name_list/stream offset. SEEK target @ 0x4b7d26
//   0x000c   4    header[2]            texmem offset.             SEEK target @ 0x4b7d12
//   0x0010   4    header[3]            world/terrain offset.      SEEK target @ 0x4b7e3f
//   0x0014   4    header[4]            fx offset.                  SEEK target @ 0x4b7d40
//   0x0018   4    header[5]            reserved5 offset
//   0x001c   4    header[6]            sub_bins offset.            SEEK target @ 0x4b7d99
//
// ALL seven header u32 are absolute file offsets to sections (proven: the odef
// blob = [0x24 .. 0x24+odefSize] terminates exactly at header[1], the name-list).
// header[0] itself (0x20) is a seek target: at that offset a u32 stores the odef
// blob size; the blob (object-definition VM script, opcodes 0x13..0x84, jump
// table @ 0x4baa28) immediately follows.
//
// READING MODEL (critical): vanilla FUN_0051d7b0(handle, off) is SetFilePointer
// (SEEK, FILE_BEGIN) — NOT a string read (IAT 0x5520ec = SetFilePointer). The
// loader seeks to each section offset, then reads. See VanillaBinLoader.cpp for
// the full sequence and the reason this module does its own SetFilePointer.
//
// NOTE: terrain (world), SFX, fx side-effects and the full odef VM are NOT ported
// here (their engine callees FUN_0049a580/0050d8f0/004b50b0 and the ~80 odef
// opcodes belong to separate modules). Their sections are seeked/skipped; the
// odef blob is captured and its object/spawn placements are logged.
#pragma once
#include <cstdint>


extern "C" {
    // Faithful port of Giants.exe!FUN_004b7c50 (readwrls.c .BIN loader).
    //   binName - level file name, e.g. "w_intro_island.bin"
    //   a2      - float arg passed to recursive sub-bin loads (vanilla param_2)
    //   a3      - int arg (vanilla param_3)
    // Opens binName, validates magic 0x1a0002e5, reads the 0x1c header, seeks to
    // each section offset (SetFilePointer model), and logs object placements from
    // the odef blob. Does not mutate engine lists.
    void FUN_004b7c50(const char* binName, float a2, int a3);
}

namespace VanillaBinLoader {
// Self-test: opens "w_intro_island.bin", logs the parsed header, the sub-bin
// list and the recovered object placements + total count. Returns 0 on success.
// Verifiable via g_binTraceLevel >= 1.
int SelfTest();
} // namespace VanillaBinLoader
