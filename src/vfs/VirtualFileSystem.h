#pragma once
// Giants Engine - Virtual File System
// Reverse engineered from FUN_00622930 (VFS_Initialize)
//
// The VFS manages layered file access through:
//   1. "Bin\Override" directory (highest priority, loose files)
//   2. *.gzp archives (custom LZ77-compressed, magic 0x6608F101)
//   3. Stream directories (audio .wav files per language)
//
// Archive search order: up to 4 data paths scanned sequentially

#include <windows.h>
#include <cstdint>

namespace Giants {

// GZP archive magic number
constexpr uint32_t GZP_MAGIC = 0x6608F101;
constexpr uint32_t ZIP_MAGIC = 0x4034B50;   // PK\x03\x04

// File entry in the VFS index (0x12 = 18 byte header in archive)
struct VFSFileEntry {
    unsigned int compressedSize;
    unsigned int uncompressedSize;
    unsigned int fileDate;
    unsigned int compressionType;
    char fileName[1]; // Variable length, null-terminated
};

// Initialize the VFS - scans all data paths, loads GZP archives
// Called during engine startup from FUN_0062e1a0 (GFX/audio init path)
void VFS_Initialize();

// Register a file in the VFS index
void VFS_RegisterFile(const char* fileName, unsigned int compressedSize,
                      unsigned int uncompressedSize, unsigned int offset,
                      unsigned int compressionType);

// Get the data path for a given index (0-3)
// Returns nullptr if no path configured for that index
const char* VFS_GetDataPath(int index);

// Get the stream path for a given index (0-6)
// Points to "Stream", "StreamEnglish", "StreamFrench", etc.
const char* VFS_GetStreamPath(int index);

// ─── ZipFileStreamReader (FUN_00490ae0) — FAIL ─────────────────
// Dispatches between raw file and zip entry read.
// 2 callers (FUN_00622400, FUN_00624cb0), 6 callees.
void ZipFileStreamReader(uint32_t param1, uint32_t param2, uint32_t param3);  // FUN_00490ae0

// ─── FileOpenWithFormatDetection (FUN_00490b90) — FAIL ─────────
// CreateFileA, checks PK/GB2 magic (0x4034B50 / 0x6608F101).
// 2 callers (FUN_00622400, FUN_00624cb0), 4 callees.
bool FileOpenWithFormatDetection(const char* path);  // FUN_00490b90

// ─── GB2MeshFileLoader (FUN_00526ed0) — FAIL ──────────────────
// Parses GB2 header, allocates vertex/index/texcoord buffers.
// 3 callers (FUN_00575e10), 9 callees.
uint32_t* GB2MeshFileLoader(uint32_t param1, uint32_t param2);  // FUN_00526ed0

// ─── FilePathResolver (FUN_005e8f10) — FAIL ───────────────────
// Reads directory entries from file/memory stream, builds string hash table.
// 1 caller (FUN_005791c0), 8 callees.
void FilePathResolver(char* param1, uint32_t* param2);  // FUN_005e8f10

// ─── FileReadToMemory (FUN_00632820) — FAIL ───────────────────
// CreateFileA, GetFileSize, ReadFile, processes through parser.
// 3 callers, 7 callees.
bool FileReadToMemory(const char* path, uint32_t* outHandle);  // FUN_00632820

// ─── FilePathBuilder (FUN_00623960) — FAIL ────────────────────
// Constructs path from format string, handles SSO wstring.
// 8 callers, 10 callees.
uint32_t* FilePathBuilder(uint32_t* param1, int param2);  // FUN_00623960

// ─── VFSPathResolver (FUN_00623b00) — FAIL ────────────────────
// Returns "Bin\Override", "Bin\Worlds", or dynamic path based on param.
// 5 callers (FUN_00622930 x2, etc.), 10 callees.
uint32_t** VFSPathResolver(uint32_t param1);  // FUN_00623b00

// ─── DirectoryPathJoin (FUN_00623dc0) — FAIL ──────────────────
// Formats "%s\%s" or "%s\%s\%s" paths using string concatenation.
// 1 caller (FUN_00621e50), 3 callees.
uint32_t* DirectoryPathJoin(uint32_t* param1, int* param2);  // FUN_00623dc0

// ─── VFSFileLookup (FUN_00623f00) — FAIL ──────────────────────
// Hashes filename (FNV-1a), searches hash table, returns file handle.
// 2 callers (FUN_00622930, FUN_00621e50), 8 callees.
uint32_t VFSFileLookup(char* filename);  // FUN_00623f00

// Functional VFS table accessors (for diagnostics).
int VFS_GetFileCount();
const char* VFS_GetFileName(int i);

// Extract a file from the VFS by name into outBuf. Returns uncompressed size
// (0 on failure). Handles GZP LZ77 decompression (compr=1).
uint32_t VFSExtractFile(const char* name, unsigned char* outBuf, unsigned int outBufSize);

// ─── VFSFileOpen (FUN_00624cb0) — FAIL ────────────────────────
// Mutex-locked, checks zip vs raw file, creates stream reader.
// 1 caller (FUN_005791c0), 18 callees.
void VFSFileOpen(int* param1);  // FUN_00624cb0

// ─── MultiLevelPathBuilder (FUN_00625490) — FAIL ──────────────
// Formats "%s\%c%c%c\%s" path from components.
// 1 caller (FUN_00621fe0), 2 callees.
uint32_t MultiLevelPathBuilder(uint32_t param1, uint32_t* param2,
                               uint8_t* param3, uint8_t* param4,
                               uint8_t* param5, uint32_t* param6);  // FUN_00625490

// ─── SimplePathJoin (FUN_00625570) — FAIL ─────────────────────
// Formats "%s\%s" from two string params.
// 1 caller (FUN_00622400), 2 callees.
uint32_t SimplePathJoin(uint32_t param1, uint32_t* param2, uint32_t* param3);  // FUN_00625570

// ─── VFSHashTableLookup (FUN_00625a30) — FAIL ─────────────────
// FNV-1a hash, searches file table, returns handle.
// 2 callers (FUN_00624910 x2), 5 callees.
uint32_t VFSHashTableLookup(int param1, uint32_t param2);  // FUN_00625a30

// ─── PathBuilderWorlds (FUN_0044e25b) — FAIL ──────────────────
// Appends "Bin\Worlds" directory path.
// 1 caller (FUN_0044e140), 4 callees.
void PathBuilderWorlds();  // FUN_0044e25b

} // namespace Giants
