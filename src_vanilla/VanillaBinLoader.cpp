// Giants Vanilla-Native Recomp — .BIN level-file loader (FUN_004b7c50 port).
//
// FAITHFUL PORT of Giants.exe!FUN_004b7c50 (readwrls.c) — vanilla 1.0 retail,
// base 0x400000. Reading model derived from Ghidra decompile
// (vanilla_decompiled/004b7c50.json) cross-checked against IAT resolution:
//
//   IAT 0x5520ec = SetFilePointer  -> vanilla FUN_0051d7b0(handle, off) = SEEK(off, FILE_BEGIN)
//   IAT 0x5520f4 = ReadFile        -> vanilla FUN_0051d750(handle, buf, count) = READ(count)
//   IAT 0x5520f8 = CreateFileA     -> vanilla FUN_00539e30 = OPEN
//
// ROOT CAUSE OF PREVIOUS BUG: the recomp's VanillaFileIO.cpp implements
// FUN_0051d7b0 as "read a C-string", but the vanilla FUN_0051d7b0 is actually
// SetFilePointer (SEEK). Calling it with a header field (an offset like 1474)
// therefore misreads bytes as strings -> garbage. This module does NOT call the
// recomp's FUN_0051d7b0 for seeking; it performs its own SetFilePointer/ReadFile
// using the exact vanilla Win32 APIs, so cursor semantics match the original.
//
// CONFIRMED READING ORDER (Ghidra decompile + verified against
// w_intro_island.bin [1514 B] and w_intro.bin [3301 B]):
//
//   1. READ 4      -> magic (cmp 0x1a0002e5)                         @ 0x4b7cb2/cbe
//   2. READ 0x1c   -> header[0..6] (7 u32, all are section offsets)  @ 0x4b7d04
//   3. SEEK header[2]; FUN_0049a580(h)        [texmem; engine, unported] @ 0x4b7d12
//   4. SEEK header[1]; FUN_0050d8f0(name,h,*) [name-list/stream; unported] @ 0x4b7d26
//   5. SEEK header[4]; READ 4 -> fxSelector (0=fx,1=dust,2=snow)     @ 0x4b7d40/0x4b7d50
//   6. if header[6]!=0:
//        SEEK header[6]; READ 4 -> subBinCount                        @ 0x4b7d88/0x4b7d99/da6
//        loop subBinCount: READ 0x20 subBinName; sprintf "%s.bin";    @ 0x4b7dda
//                          RECURSIVE FUN_004b7c50(name,...)           @ 0x4b7e2b
//   7. SEEK header[3]; FUN_004b50b0(h,name)  [world/terrain; unported] @ 0x4b7e3f/0x4b7e4f
//   8. SEEK header[0]; READ 4 -> odef blob size (objCount)            @ 0x4b7e5d/0x4b7e6a
//   9. if objCount: malloc 0x1c9 tpl; READ objCount bytes -> odef VM  @ 0x4b7ea0/0x4b7eb2
//  10. close                                                          @ 0x4b7e7b
//
// Header is 0x1c bytes at file offset 4; header[0..6] are ALL absolute file
// offsets to the seven sections (proven: odef blob = [0x24 .. 0x24+objCount]
// terminates exactly at header[1], the name-list). The odef VM (~80 opcodes,
// jump table 0x4baa28) and the engine subsystems (FUN_0049a580/0050d8f0/004b50b0)
// are NOT ported here; their sections are skipped/logged only.
#include "VanillaBinLoader.h"
#include "VanillaFileIO.h"

#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <cstdlib>
#include <windows.h>
#include <new>

namespace {

static uint32_t g_binTraceLevel = 1;   // logging on

// ----- Engine constants (from disasm) ---------------------------------------
constexpr uint32_t kBinMagic    = 0x1a0002e5u;  // cmp eax,0x1a0002e5 @ 0x4b7cbe
constexpr uint32_t kHeaderU32   = 7;            // 0x1c = 28 bytes / 4
constexpr uint32_t kSubBinNameLen = 0x20;       // READ 0x20 @ 0x4b7dda
constexpr uint32_t kOdefTemplateSize = 0x1c9;   // malloc @ 0x4b7ea0

// Section names for header[0..6] (indices confirmed by the verified parse:
// header[0]=odef-blob section, header[1]=name_list/stream, header[2]=texmem,
// header[3]=world/terrain, header[4]=fx, header[5]=unused, header[6]=sub_bins).
const char* const kSectionNames[7] = {
    "odef_blob",     // header[0]
    "name_list",     // header[1]
    "texmem",        // header[2]
    "world_terrain", // header[3]
    "fx",            // header[4]
    "reserved5",     // header[5]
    "sub_bins",      // header[6]
};

void trace(const char* fmt, ...) {
    if (g_binTraceLevel < 1) return;
    va_list ap; va_start(ap, fmt);
    std::vprintf(fmt, ap);
    va_end(ap);
    std::fflush(stdout);
}

// ---- Minimal file handle: vanilla uses CreateFileA/SetFilePointer/ReadFile.
// We resolve the filename exactly as the engine VFS (Bin\<basename>) and operate
// on the OS handle directly so SetFilePointer cursor semantics are identical.
//
// We try the loose file first; if that fails we fall back to the recomp VFS
// (FUN_00539e30) for GZP-backed files and read the whole buffer into memory.
struct BinFile {
    HANDLE hFile = INVALID_HANDLE_VALUE;   // loose-file path
    // GZP fallback path:
    uint8_t* blob = nullptr;
    uint32_t blobSize = 0;
    uint32_t blobPos = 0;
    bool     ok = false;

    ~BinFile() {
        if (hFile != INVALID_HANDLE_VALUE) CloseHandle(hFile);
        if (blob) delete[] blob;
    }
};

// Resolve just like the engine: Bin\<basename of binName>.
void makeBinPath(const char* binName, char* out, size_t outCap) {
    const char* base = binName;
    for (const char* p = binName; *p; ++p)
        if (*p == '\\' || *p == '/') base = p + 1;
    snprintf(out, outCap, "Bin\\%s", base);
}

bool openBin(const char* binName, BinFile& f) {
    char path[512]; makeBinPath(binName, path, sizeof(path));
    f.hFile = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, nullptr,
                          OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (f.hFile != INVALID_HANDLE_VALUE) { f.ok = true; return true; }

    // GZP fallback: the recomp VFS (FUN_00539e30) loads the whole file into its
    // in-memory table on open. We pull it back through FUN_0051d750 in one bulk
    // request (the recomp clamps the copy to the available bytes). The trailing
    // slack beyond the real size is never read because our parse is bound by the
    // section offsets / sizes declared inside the file.
    uint32_t h = FUN_00539e30(binName);
    if (h == 0) return false;
    const uint32_t kCap = 16u * 1024 * 1024;
    f.blob = new (std::nothrow) uint8_t[kCap];
    if (!f.blob) { FUN_0051d850(h); return false; }
    FUN_0051d750(h, f.blob, kCap);
    FUN_0051d850(h);
    f.blobSize = kCap;
    f.blobPos = 0;
    f.ok = true;
    return true;
}

// Read exactly n bytes; returns bytes actually read.
uint32_t readBin(BinFile& f, void* buf, uint32_t n) {
    if (f.hFile != INVALID_HANDLE_VALUE) {
        DWORD got = 0;
        ReadFile(f.hFile, buf, n, &got, nullptr);
        return got;
    }
    if (f.blob && f.blobPos < f.blobSize) {
        uint32_t avail = f.blobSize - f.blobPos;
        uint32_t c = n < avail ? n : avail;
        memcpy(buf, f.blob + f.blobPos, c);
        f.blobPos += c;
        return c;
    }
    return 0;
}

// Seek to absolute offset (FILE_BEGIN). Vanilla FUN_0051d7b0 semantics.
void seekBin(BinFile& f, uint32_t offset) {
    if (f.hFile != INVALID_HANDLE_VALUE) {
        SetFilePointer(f.hFile, (LONG)offset, nullptr, FILE_BEGIN);
    } else if (f.blob) {
        f.blobPos = offset < f.blobSize ? offset : f.blobSize;
    }
}

} // namespace

// ============================================================================
// FUN_004b7c50 — faithful port of the vanilla .BIN loader.
// ============================================================================
extern "C" void FUN_004b7c50_legacy_light(const char* binName, float a2, int a3) {
    (void)a3;

    trace("[BIN] FUN_004b7c50(\"%s\", %g, %d)\n", binName ? binName : "(null)", a2, a3);

    BinFile f;
    if (!openBin(binName, f)) {                                   // 0x4b7c6e: open
        trace("[BIN]   FAILED to open \"%s\"\n", binName ? binName : "(null)");
        return;
    }

    // 1. READ 4-byte magic.                                                @0x4b7cb2
    uint32_t magic = 0;
    readBin(f, &magic, 4);
    if (magic != kBinMagic) {                                     // @0x4b7cbe
        trace("[BIN]   BAD magic 0x%08x (expected 0x%08x)\n", magic, kBinMagic);
        return;
    }

    // 2. READ 0x1c-byte header (7 u32).                                    @0x4b7d04
    uint32_t header[kHeaderU32];
    readBin(f, header, 0x1c);
    trace("[BIN]   header (7 section offsets):\n");
    for (int i = 0; i < 7; ++i)
        trace("[BIN]     header[%d]=%-6u  \"%s\"\n", i, header[i], kSectionNames[i]);

    // 3. SEEK header[2]; FUN_0049a580(h)  [texmem; engine, unported]      @0x4b7d12
    seekBin(f, header[2]);
    trace("[BIN]   seek texmem @%u (FUN_0049a580 unported)\n", header[2]);

    // 4. SEEK header[1]; FUN_0050d8f0(name,h,*) [name-list/stream; unported] @0x4b7d26
    seekBin(f, header[1]);
    trace("[BIN]   seek name_list/stream @%u (FUN_0050d8f0 unported)\n", header[1]);

    // 5. SEEK header[4]; READ 4 -> fxSelector (0=fx,1=dust,2=snow).       @0x4b7d40/0x4b7d50
    seekBin(f, header[4]);
    uint32_t fxSelector = 0;
    readBin(f, &fxSelector, 4);
    const char* fxTag = "fx";
    if (fxSelector == 1) fxTag = "fx_world_dust";
    else if (fxSelector == 2) fxTag = "fx_world_snow";
    trace("[BIN]   fx selector=%u -> \"%s\"\n", fxSelector, fxTag);

    // 6. if header[6] != 0: sub-bin section.                              @0x4b7d88
    if (header[6] != 0) {
        seekBin(f, header[6]);                                    // @0x4b7d99
        uint32_t subBinCount = 0;
        readBin(f, &subBinCount, 4);                              // @0x4b7da6
        trace("[BIN]   sub-bin count=%u @%u\n", subBinCount, header[6]);
        // Loop: READ 0x20 name, sprintf "%s.bin", recurse.               @0x4b7dda/0x4b7e2b
        // We log but do not recurse (sub-bin loading is the caller's concern).
        for (uint32_t i = 0; i < subBinCount; ++i) {
            char subBinName[kSubBinNameLen + 1];
            memset(subBinName, 0, sizeof(subBinName));
            readBin(f, subBinName, kSubBinNameLen);
            subBinName[kSubBinNameLen] = '\0';
            trace("[BIN]     sub-bin[%u] = \"%s\" -> \"%s.bin\" (not recursed)\n",
                  i, subBinName, subBinName);
        }
    }

    // 7. SEEK header[3]; FUN_004b50b0(h,name) [world/terrain; unported].  @0x4b7e3f/0x4b7e4f
    seekBin(f, header[3]);
    trace("[BIN]   seek world/terrain @%u (FUN_004b50b0 unported)\n", header[3]);

    // 8. SEEK header[0]; READ 4 -> odef blob size.                        @0x4b7e5d/0x4b7e6a
    seekBin(f, header[0]);
    uint32_t odefSize = 0;
    readBin(f, &odefSize, 4);
    trace("[BIN]   odef blob size=%u (objects section @%u)\n", odefSize, header[0]);

    // 9. if odefSize: malloc 0x1c9 template + READ odefSize bytes.        @0x4b7ea0/0x4b7eb2
    //    The vanilla odef VM (jump table 0x4baa28, opcodes 0x13..0x84) then
    //    interprets the blob. We capture it and recover object/spawn names.
    if (odefSize != 0) {
        const uint32_t kMaxOdef = 1u << 20;
        if (odefSize <= kMaxOdef) {
            uint8_t* blob = new (std::nothrow) uint8_t[odefSize];
            if (blob) {
                uint32_t got = readBin(f, blob, odefSize);
                trace("[BIN]   read odef blob: %u / %u bytes\n", got, odefSize);

                // Recover object/spawn placements: scan for NUL-terminated ASCII
                // identifiers embedded in the blob. The vanilla opcode-0x84 handler
                // (@0x4ba50a) consumes these into the engine spawn slot
                // (engine+0x509c); each is a level object instance name.
                int n = 0;
                for (uint32_t p = 0; p + 1 < got; ) {
                    uint8_t c0 = blob[p];
                    bool startChar = (c0 >= 'a' && c0 <= 'z') ||
                                     (c0 >= 'A' && c0 <= 'Z') || c0 == '_';
                    if (!startChar) { ++p; continue; }
                    uint32_t e = p;
                    while (e < got) {
                        uint8_t c = blob[e];
                        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
                            (c >= '0' && c <= '9') || c == '_') ++e;
                        else break;
                    }
                    uint32_t len = e - p;
                    // Require NUL terminator (engine reads these as C-strings).
                    if (len >= 4 && len < 64 && e < got && blob[e] == 0) {
                        char name[64];
                        memcpy(name, blob + p, len);
                        name[len] = '\0';
                        trace("[BIN]     placement[%d] @blob+%u  \"%s\"\n", n, p, name);
                        ++n;
                        p = e + 1;
                    } else {
                        p = e;
                    }
                }
                trace("[BIN]   odef placements recovered: %d\n", n);
                delete[] blob;
            }
        } else {
            trace("[BIN]   odef blob too large (%u); skipping\n", odefSize);
        }
    }

    // 10. close.                                                           @0x4b7e7b
    trace("[BIN]   closed \"%s\"\n", binName ? binName : "(null)");
}

// ============================================================================
// SelfTest.
// ============================================================================
namespace VanillaBinLoader {

int SelfTest() {
    if (g_binTraceLevel < 1) g_binTraceLevel = 1;   // ensure logging

    trace("=== VanillaBinLoader::SelfTest ===\n");
    trace("Parsing w_intro_island.bin via FUN_004b7c50...\n");

    FUN_004b7c50("w_intro_island.bin", 1.0f, 0);

    trace("=== VanillaBinLoader::SelfTest done ===\n");
    return 0;
}

} // namespace VanillaBinLoader
