// Giants Vanilla-Native Recomp — Engine file I/O layer.
// Ports the engine's file API used by the scene loader (FUN_004b7c50 .BIN loader):
//   FUN_00539e30(filename) -> handle (0 = fail)   [open: loose file OR GZP archive]
//   FUN_0051d750(handle, buf, count)              [read count bytes]
//   FUN_0051d7b0(handle, buf)                     [read a C-string line]
//   FUN_0051d850(handle)                          [close]
// Backed by VanillaVFS (GZP reader) + loose-file search in Bin/. The handle is an
// index into a static file-table of {buffer,size,pos}. This is THE prerequisite for
// the scene loader to read level/texture/mesh data.
#pragma once
#include <cstdint>

extern "C" {
    // Engine file API (cdecl). Names match vanilla function addresses.
    uint32_t FUN_00539e30(const char* filename);                       // open → handle (0=fail)
    void     FUN_0051d750(uint32_t handle, void* buf, uint32_t count); // read
    void     FUN_0051d7b0(uint32_t handle, char* buf);                 // read line (C-string)
    void     FUN_0051d850(uint32_t handle);                            // close
}

namespace VanillaFileIO {
// Self-test: open WorldList.bin (loose) + a GZP file, log. Returns #handles leaked.
int SelfTest();
} // namespace VanillaFileIO
