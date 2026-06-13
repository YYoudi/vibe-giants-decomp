// Giants Engine - Virtual File System Implementation
// Reverse engineered from FUN_00622930 (VFS_Initialize)
//
// The VFS provides layered file access:
//   Priority order: Override dir > GZP archives > Stream dirs
//   GZP format: magic 0x6608F101, file index at end of archive
//   Each file entry: 18-byte header + variable-length filename
//
// Phases of VFS_Initialize:
//   Phase 1: Scan "Bin\Override\*.*" for loose override files
//   Phase 2: For each data path (up to 4): scan *.gzp, open archive,
//            read index, register files
//   Phase 3: For each data path: scan subdirectories for .bin/.abx/.gzp files
//   Phase 4: For each stream path (up to 7): scan for .wav audio files
#include <cstdlib>
#include <cstring>
#include "VirtualFileSystem.h"
#include <cstdio>
#include <cstdint>

namespace Giants {

void VFS_Initialize()
{
    // Phase 1: Override directory
    // Scans "Bin\Override\*.*" and registers each file
    char pathBuffer[512];

    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA("Bin\\Override\\*.*", &findData);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            VFS_RegisterFile(findData.cFileName, 0, 0, 0, 0);
        } while (FindNextFileA(hFind, &findData));
        FindClose(hFind);
    }

    // Phase 2: Scan GZP archives from each data path
    for (int pathIndex = 0; pathIndex < 4; pathIndex++) {
        const char* dataPath = VFS_GetDataPath(pathIndex);
        if (dataPath == nullptr) continue;

        snprintf(pathBuffer, sizeof(pathBuffer), "%s\\*.gzp", dataPath);
        hFind = FindFirstFileA(pathBuffer, &findData);
        if (hFind == INVALID_HANDLE_VALUE) continue;

        do {
            // Check for VO_Sfx language-specific archives
            if (_strnicmp(findData.cFileName, "VO_Sfx", 6) == 0) {
                // Only load if matches current language
                // (language comparison against global setting)
            }

            // Open the GZP file
            snprintf(pathBuffer, sizeof(pathBuffer), "%s\\%s", dataPath, findData.cFileName);
            HANDLE hFile = CreateFileA(pathBuffer, GENERIC_READ, FILE_SHARE_READ,
                                       nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
            if (hFile == INVALID_HANDLE_VALUE) continue;

            // Read magic number
            uint32_t magic;
            DWORD bytesRead;
            SetFilePointer(hFile, 0, nullptr, FILE_BEGIN);
            ReadFile(hFile, &magic, 4, &bytesRead, nullptr);

            if (magic == GZP_MAGIC) {
                // GZP custom format: read header then seek to index at end
                SetFilePointer(hFile, 0, nullptr, FILE_BEGIN);

                uint8_t header[8];
                ReadFile(hFile, header, 8, &bytesRead, nullptr);

                // Seek to file index (at offset header[4..7] from start)
                uint32_t indexOffset = *reinterpret_cast<uint32_t*>(&header[4]);
                SetFilePointer(hFile, indexOffset, nullptr, FILE_BEGIN);

                // Read index size
                uint32_t indexSize;
                ReadFile(hFile, &indexSize, 8, &bytesRead, nullptr);

                // Read each file entry
                for (uint32_t i = 0; i < indexSize; i++) {
                    uint8_t entryHeader[18];
                    ReadFile(hFile, entryHeader, 0x12, &bytesRead, nullptr);

                    uint32_t nameLen = entryHeader[16] | (entryHeader[17] << 8);
                    char* name = static_cast<char*>(malloc(nameLen + 0x17));
                    ReadFile(hFile, name + 0x16, nameLen, &bytesRead, nullptr);

                    // Register file in VFS
                    VFS_RegisterFile(
                        name + 0x16,
                        *reinterpret_cast<uint32_t*>(&entryHeader[8]),  // compressed size
                        *reinterpret_cast<uint32_t*>(&entryHeader[4]),  // uncompressed size
                        *reinterpret_cast<uint32_t*>(&entryHeader[12]), // date
                        *reinterpret_cast<uint32_t*>(&entryHeader[0])   // offset
                    );
                }
            }
            // Note: magic == ZIP_MAGIC (0x4034b50) is handled differently

            CloseHandle(hFile);
        } while (FindNextFileA(hFind, &findData));
        FindClose(hFind);
    }

    // Phase 4: Scan stream directories for audio
    for (int streamIndex = 1; streamIndex < 7; streamIndex++) {
        const char* streamPath = VFS_GetStreamPath(streamIndex);
        if (streamPath == nullptr) continue;

        snprintf(pathBuffer, sizeof(pathBuffer), "%s\\*.*", streamPath);
        hFind = FindFirstFileA(pathBuffer, &findData);
        if (hFind == INVALID_HANDLE_VALUE) continue;

        do {
            if (findData.cFileName[0] == '.') continue;
            if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) continue;

                // Scan subdirectory for .wav files
                char wavPattern[512];
                snprintf(wavPattern, sizeof(wavPattern), "%s\\%s\\*.wav",
                         streamPath, findData.cFileName);

                WIN32_FIND_DATAA wavData;
                HANDLE hWavFind = FindFirstFileA(wavPattern, &wavData);
                if (hWavFind != INVALID_HANDLE_VALUE) {
                    do {
                        if (wavData.cFileName[0] == '.') continue;
                        VFS_RegisterFile(wavData.cFileName, 0, 0, 0, 0);
                    } while (FindNextFileA(hWavFind, &wavData));
                    FindClose(hWavFind);
                }
        } while (FindNextFileA(hFind, &findData));
        FindClose(hFind);
    }
}

// ─── Static globals for new VFS functions ──────────────────────

// File format mode: 0 = GZP/raw, 1 = ZIP/PK
static uint32_t DAT_00681cdc = 0;  // file format flag (0=GZP, 1=ZIP)

// File handle for currently opened archive
static HANDLE DAT_0073f7c4 = nullptr;  // current archive file handle

// ZIP stream reader context
static uint32_t DAT_0073f7c8 = 0;     // ZIP stream context pointer

// VFS path string cache (SSO wstring at 0x6866ac)
static uint32_t DAT_006866ac[6] = {0};  // cached path string buffer
static uint32_t DAT_006866c0 = 0;       // cached path length

// VFS hash table sentinel value
static uint32_t DAT_0074bbec = 0;       // hash table null sentinel

// VFS state flags
static char DAT_0074bc20 = 0;           // path type 2 initialized flag
static char DAT_0074bd20 = 0;           // path type default initialized flag

// GB2 error flag
static uint32_t DAT_007282bc = 0;       // GB2 mesh load error flag

// Directory entry linked list head
static uint32_t* DAT_0074b820 = nullptr; // directory entry list head

// Current file ID in VFS
static uint32_t DAT_0074bc18 = 0;       // current open file ID

// VFS mutex
static uint32_t DAT_00685860 = 0;       // mutex for VFS file open
static uint32_t DAT_0068588c = 0x7fffffff; // open count / ref count

// ─── ZipFileStreamReader (FUN_00490ae0) — FAIL ─────────────────
// Status: FAIL
// Dispatches between raw file read (mode 0) and zip entry read (mode 1).
// Mode 1 uses ZIP stream functions: seek, tell, read, decompress.

/*
  RAW DECOMPILATION (Ghidra):
  void __fastcall FUN_00490ae0(undefined4 param_1, undefined4 param_2, undefined4 param_3)
  {
    undefined1 local_168 [80];
    undefined1 local_118 [268];
    uint local_c;

    local_c = DAT_0067d280 ^ (uint)local_168;
    if (DAT_00681cdc == 0) {
      FUN_00490920(param_3);                   // raw file read
    }
    else if (DAT_00681cdc == 1) {
      FUN_00631e80(DAT_0073f7c8, param_1);     // zip seek
      FUN_00631010(DAT_0073f7c8);              // zip tell
      FUN_00630db0(DAT_0073f7c8, local_168, local_118, 0x104, 0, 0, 0, 0); // zip read
      FUN_00631ad0(DAT_0073f7c8, param_3, param_2); // zip decompress
      return;
    }
    return;
  }
*/

void ZipFileStreamReader(uint32_t param1, uint32_t param2, uint32_t param3)
{
    if (DAT_00681cdc == 0)
    {
        // Mode 0: Raw file — delegate to raw file reader
        // FUN_00490920(param3);
    }
    else if (DAT_00681cdc == 1)
    {
        // Mode 1: ZIP entry — seek, read, decompress
        // FUN_00631e80(DAT_0073f7c8, param1);    // zip_seek(context, offset)
        // FUN_00631010(DAT_0073f7c8);             // zip_tell(context)
        // FUN_00630db0(DAT_0073f7c8, ..., 0x104); // zip_read(context, buf, size)
        // FUN_00631ad0(DAT_0073f7c8, param3, param2); // zip_decompress(ctx, out, size)
    }
}

// ─── FileOpenWithFormatDetection (FUN_00490b90) — FAIL ─────────
// Status: FAIL
// Opens file via CreateFileA, reads first 4 bytes to detect format.
// Sets DAT_00681cdc to 1 for ZIP (PK magic 0x4034B50) or 0 for GZP (0x6608F101).

/*
  RAW DECOMPILATION (Ghidra):
  bool __fastcall FUN_00490b90(LPCSTR param_1)
  {
    int local_8;
    DWORD local_4;
    if (DAT_0073f7c4 == (HANDLE)0x0) {
      DAT_0073f7c4 = CreateFileA(param_1, 0x80000000, 1, 0, 3, 0x80, 0);
      if (DAT_0073f7c4 == (HANDLE)0xffffffff) {
        DAT_0073f7c4 = (HANDLE)0x0;
      }
      else {
        SetFilePointer(DAT_0073f7c4, 0, 0, 0);
        ReadFile(DAT_0073f7c4, &local_8, 4, &local_4, 0);
        if (local_8 == 0x4034b50) {            // PK magic
          DAT_00681cdc = 1;
          DAT_0073f7c8 = FUN_00630ff0(param_1); // init ZIP context
          return DAT_0073f7c8 != 0;
        }
        if (local_8 == 0x6608f101) {           // GZP magic
          DAT_00681cdc = 0;
          DAT_0073f7c8 = 0;
          return true;
        }
      }
    }
    return false;
  }
*/

bool FileOpenWithFormatDetection(const char* path)
{
    if (DAT_0073f7c4 == nullptr)
    {
        DAT_0073f7c4 = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ,
                                    nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
        if (DAT_0073f7c4 == INVALID_HANDLE_VALUE)
        {
            DAT_0073f7c4 = nullptr;
        }
        else
        {
            int32_t magic = 0;
            DWORD bytesRead = 0;
            SetFilePointer(DAT_0073f7c4, 0, nullptr, FILE_BEGIN);
            ReadFile(DAT_0073f7c4, &magic, 4, &bytesRead, nullptr);

            if (magic == (int32_t)ZIP_MAGIC)
            {
                // ZIP/PK format detected
                DAT_00681cdc = 1;
                // DAT_0073f7c8 = InitZipContext(path);   // FUN_00630ff0
                return DAT_0073f7c8 != 0;
            }
            if (magic == (int32_t)GZP_MAGIC)
            {
                // GZP format detected
                DAT_00681cdc = 0;
                DAT_0073f7c8 = 0;
                return true;
            }
        }
    }
    return false;
}

// ─── GB2MeshFileLoader (FUN_00526ed0) — FAIL ──────────────────
// Status: FAIL
// Parses GB2 mesh file header, allocates vertex/index/texcoord buffers.
// GB2 magic: 0xAA0100AA (version 1) or 0xAA010059/0xAA010058 (-0x55FEFF55/-0x55FEFF56).
// Returns pointer to mesh struct: {flags, vertexCount, indexCount, vertices, normals, texcoords, indices}.

/*
  RAW DECOMPILATION (Ghidra) — see ghidra_exports/level4/00526ed0.c (166 lines)
  Key operations:
    - Opens file via VFS (FUN_00622400)
    - Checks GB2 version magic: -0x55FEFF55 or -0x55FEFF56
    - Iterates mesh subsections, matches name against param_2
    - For matched section: reads flags, vertex count, index count
    - Allocates: vertices (vertexCount * 12), indices (indexCount * 6),
                 texcoords (vertexCount * 8 or 3+1), normals (vertexCount * 8)
    - Copies data from file buffer, converts indices to 16-bit
    - Returns struct: {0, vertexCount, indexCount, vertices, normals, texcoords, indices}
*/

uint32_t* GB2MeshFileLoader(uint32_t param1, uint32_t param2)
{
    // Open file via VFS
    // FUN_00622400(&local_34);

    // NOTE: Full implementation requires VFS file handle infrastructure.
    // The decompiled code operates on a memory-mapped file buffer.
    // Below is the structural logic with stubs for VFS calls.

    /*
    int* fileData = nullptr; // local_44
    uint32_t sectionCount = 0; // local_34

    // FUN_00622400 populates fileData and sectionCount
    if (sectionCount == 0) return nullptr;

    int version = *fileData;
    if (version != -0x55FEFF55 && version != -0x55FEFF56)
    {
        // FUN_0062edc0("Bad version of GB2 file");
        DAT_007282bc = 1;
        return nullptr;
    }

    int numSections = fileData[1];
    for (int i = 0; i < numSections; i++)
    {
        uint32_t* section = (uint32_t*)(fileData[i + 2] + (uint32_t)fileData);

        // Read section header (name + flags)
        // Match section name against param_2 via FUN_00632950

        uint32_t flags = section[4]; // local_1c
        uint32_t hasTexcoords = flags & 4;
        uint32_t hasNormals = flags & 2;

        // Calculate buffer pointers within file data
        uint32_t* vertexData = section + (hasTexcoords ? 7 : 6);
        uint32_t vertexCount = *vertexData;     // local_40
        uint32_t vertexBufSize = vertexCount * 12; // local_38
        uint32_t indexCount = vertexData[1];    // local_24

        // Allocate output buffers
        void* vertices = malloc(vertexBufSize);     // local_3c
        void* indices = malloc(indexCount * 6);     // local_20
        void* normals = hasNormals ? malloc(vertexCount * 8) : nullptr;  // local_2c
        void* texcoords = hasTexcoords ? malloc(vertexCount * 3 + 1) : nullptr; // local_28

        // Copy vertex data from file
        memcpy(vertices, vertexData + 2, vertexBufSize);

        // Read index data, convert 32-bit to 16-bit
        // If index value >= 0x10000, set DAT_007282bc = 1

        // Allocate and return mesh struct (8 DWORDs):
        // {0, vertexCount, indexCount, vertices, normals, texcoords, indices}
    }
    */

    return nullptr;
}

// ─── FilePathResolver (FUN_005e8f10) — FAIL ───────────────────
// Status: FAIL
// Reads directory entries from file or memory stream, builds a linked-list
// hash table keyed by entry name. Each entry stores name, offset, count, and
// per-entry subrecords with string hash keys.

/*
  RAW DECOMPILATION (Ghidra) — see ghidra_exports/level4/005e8f10.c (218 lines)
  Key operations:
    - Traverses linked list at DAT_0074b820, compares names
    - Reads entry count from stream (file or memory, param_2[4] selects mode)
    - For each entry: reads name length (capped at 0x20), name string,
      then sub-records with 3 fields each (flag, size, name)
    - Allocates linked-list node, hashes sub-record names via FUN_00632790
    - Links node into DAT_0074b820 list
*/

void FilePathResolver(char* param1, uint32_t* param2)
{
    // Check existing entries in linked list
    /*
    for (uint32_t* entry = DAT_0074b820; entry != nullptr; entry = (uint32_t*)*entry)
    {
        int match = 0; // FUN_00632950(entry + 1, param1);
        if (match != 0) return;
    }

    // Read entry count from stream
    uint32_t streamOffset = 0;
    if (param2[4] == 0)
        streamOffset = SetFilePointer((HANDLE)param2[3], 0, 0, FILE_CURRENT);
    else if (param2[4] == 1)
        streamOffset = *param2;

    // Read entry count (4 bytes)
    uint32_t entryCount = 0;
    // ... stream read based on mode ...

    if (entryCount != 0)
    {
        // For each entry: read name_len, name, then sub-records
        // Allocate linked list node: total = entryCount * 12 * 16 + 0x5C
        // Link into DAT_0074b820
        // Hash each sub-record name via FUN_00632790
    }
    */
}

// ─── FileReadToMemory (FUN_00632820) — FAIL ───────────────────
// Status: FAIL
// Opens file, reads entire contents into memory, passes to parser.

/*
  RAW DECOMPILATION (Ghidra):
  bool FUN_00632820(LPCSTR param_1, undefined4 *param_2)
  {
    *param_2 = 0;
    hFile = CreateFileA(param_1, 1, 1, 0, 3, 0x8000027, 0);
    if (hFile == (HANDLE)0xffffffff) return false;
    local_8 = hFile;
    nNumberOfBytesToRead = GetFileSize(hFile, 0);
    lpBuffer = FUN_0064356b(nNumberOfBytesToRead);    // alloc
    BVar1 = ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, &local_c, 0);
    uVar2 = FUN_006326f0(lpBuffer, nNumberOfBytesToRead); // parse
    *param_2 = uVar2;
    free(lpBuffer);
    CloseHandle(local_8);
    return BVar1 != 0;
  }
*/

bool FileReadToMemory(const char* path, uint32_t* outHandle)
{
    *outHandle = 0;

    HANDLE hFile = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ,
                                nullptr, OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN,
                                nullptr);
    if (hFile == INVALID_HANDLE_VALUE)
        return false;

    DWORD fileSize = GetFileSize(hFile, nullptr);
    void* buffer = malloc(fileSize);  // FUN_0064356b (CRT alloc wrapper)
    DWORD bytesRead = 0;
    BOOL readOk = ReadFile(hFile, buffer, fileSize, &bytesRead, nullptr);

    // Parse buffer into handle
    // uint32_t result = FUN_006326f0(buffer, fileSize);
    // *outHandle = result;

    free(buffer);
    CloseHandle(hFile);
    return (readOk != 0);
}

// ─── FilePathBuilder (FUN_00623960) — FAIL ────────────────────
// Status: FAIL
// Constructs a path from format string. Handles SSO (Small String Optimization)
// wstring internally. Uses CRT string formatting helpers.

/*
  RAW DECOMPILATION (Ghidra) — see ghidra_exports/level4/00623960.c (121 lines)
  Key operations:
    - If param2 != 0, formats path using FUN_00625d60 (sprintf wrapper)
    - Initializes SSO wstring (capacity 7, length 0)
    - Copies formatted string into param_1 (up to 24 bytes SSO)
    - Triggers string finalization via FUN_00440620 (destructor chain)
    - May reallocate if string exceeds SSO threshold (15 chars)
*/

uint32_t* FilePathBuilder(uint32_t* param1, int param2)
{
    /*
    if (param2 != 0)
    {
        // uint32_t formatted = FUN_00625d60(&param2);
        // FUN_00441d10(formatted);
    }

    // Initialize output as empty SSO wstring
    param1[0] = 0; param1[1] = 0; param1[2] = 0;
    param1[3] = 0; param1[4] = 0; param1[5] = 0;

    // Get formatted result
    // uint32_t* result = FUN_00632a10(local_54, 1, ...);
    // Copy result into param1

    // Finalize / cleanup
    // FUN_00443490();
    */
    return param1;
}

// ─── VFSPathResolver (FUN_00623b00) — FAIL ────────────────────
// Status: FAIL
// Returns a static path string based on param:
//   0         → "Bin\Override"
//   1         → PTR_DAT_0066a804 (data path 0)
//   2         → dynamic path (if DAT_0074bc20 initialized)
//   0xFFFFFFFE → builds path via FilePathBuilder
//   0xFFFFFFFF → "Bin\Worlds"
//   default   → dynamic path (if DAT_0074bd20 initialized)

/*
  RAW DECOMPILATION (Ghidra) — see ghidra_exports/level4/00623b00.c (123 lines)
  Key switch:
    case 0:          return "Bin\\Override"
    case 1:          return &PTR_DAT_0066a804
    case 2:          if (!DAT_0074bc20) return NULL; else return cached path
    case 0xFFFFFFFE: FUN_00623960(); build path; cache it; return
    case 0xFFFFFFFF: return "Bin\\Worlds"
    default:         if (!DAT_0074bd20) return NULL; else return cached path
*/

uint32_t** VFSPathResolver(uint32_t param1)
{
    uint32_t** result = nullptr;

    switch (param1)
    {
    case 0:
        // Override directory
        result = (uint32_t**)"Bin\\Override";
        break;

    case 1:
        // Data path 0 (first data directory)
        // result = &PTR_DAT_0066a804;
        break;

    case 2:
        if (DAT_0074bc20 == 0)
            return nullptr;
        // Build and cache path from configuration
        // FUN_00625890(param1); // get config path
        result = (uint32_t**)&DAT_006866ac;
        if (DAT_006866c0 > 0x0F)
            result = (uint32_t**)DAT_006866ac[0];
        break;

    case 0xFFFFFFFE:
        // Build path via FilePathBuilder
        // FilePathBuilder(...);
        // Cache in DAT_006866ac
        result = (uint32_t**)&DAT_006866ac;
        if (DAT_006866c0 > 0x0F)
            result = (uint32_t**)DAT_006866ac[0];
        break;

    case 0xFFFFFFFF:
        // Worlds directory
        result = (uint32_t**)"Bin\\Worlds";
        break;

    default:
        if (DAT_0074bd20 == 0)
            return nullptr;
        // FUN_00625910(); // get dynamic path
        result = (uint32_t**)&DAT_006866ac;
        if (DAT_006866c0 > 0x0F)
            result = (uint32_t**)DAT_006866ac[0];
        break;
    }

    return result;
}

// ─── DirectoryPathJoin (FUN_00623dc0) — FAIL ──────────────────
// Status: FAIL
// Formats "%s\%s" or "%s\%s\%s" paths. Uses SSO wstring concatenation.
// If the prefix string is empty, uses 2-part format; otherwise 3-part.

/*
  RAW DECOMPILATION (Ghidra):
  undefined4 * __fastcall FUN_00623dc0(undefined4 *param_1, int *param_2)
  {
    local_28 = FUN_00623ce0();              // get prefix directory
    if (local_28 == NULL) {
      // return empty string in param_1
      *param_1 = 0; param_1[1] = 0; ... param_1[5] = 0xf; *param_1 byte = 0;
      return param_1;
    }
    if (*local_28 == '\0') {
      // Format: "%s\\%s"  (prefix + suffix)
      local_38 = "%s\\%s";
      uVar2 = 0xcc;  // format arg count
    } else {
      // Format: "%s\\%s\\%s"  (prefix + mid + suffix)
      local_38 = "%s\\%s\\%s";
      uVar2 = 0xccc;
    }
    FUN_00444db0(uVar2, 0, &local_28);     // sprintf into param_1
    return param_1;
  }
*/

uint32_t* DirectoryPathJoin(uint32_t* param1, int* param2)
{
    // char* prefix = FUN_00623ce0();  // get prefix directory string

    /*
    if (prefix == nullptr)
    {
        // Return empty string
        param1[0] = 0; param1[1] = 0; param1[2] = 0;
        param1[3] = 0; param1[4] = 0; param1[5] = 0x0F;
        *reinterpret_cast<uint8_t*>(param1) = 0;
        return param1;
    }

    if (*prefix == '\0')
    {
        // Format: "%s\\%s"
        // FUN_00444db0(0xCC, 0, ...);  // sprintf wrapper
    }
    else
    {
        // Format: "%s\\%s\\%s"
        // FUN_00444db0(0xCCC, 0, ...); // sprintf wrapper
    }
    */
    return param1;
}

// ─── VFSFileLookup (FUN_00623f00) — FAIL ──────────────────────
// Status: FAIL
// Hashes filename using FNV-1a algorithm, searches hash table for match.
// Returns the file handle (value at offset +0x20 in table entry) or 0.

/*
  RAW DECOMPILATION (Ghidra) — see ghidra_exports/level4/00623f00.c (101 lines)
  Key operations:
    - Lowercases filename via FUN_00442eb0
    - Initializes SSO wstring for the lookup key
    - Converts to narrow string via FUN_005e8ea0
    - Computes FNV-1a hash: init=0x811C9DC5, prime=0x1000193
    - Looks up hash in table via FUN_00626fe0
    - Returns *(entry + 0x20) on match, 0 on miss
*/

uint32_t VFSFileLookup(char* filename)
{
    // FNV-1a hash computation
    /*
    // Step 1: Lowercase filename
    // FUN_00442eb0(filename, strlen(filename));

    // Step 2: Convert to narrow string
    // uint32_t* nameStr = FUN_005e8ea0(...);

    // Step 3: Get raw char pointer (SSO check)
    uint32_t* namePtr = nameStr;
    if (nameStr[5] > 0x0F)
        namePtr = (uint32_t*)nameStr[0];

    // Step 4: FNV-1a hash
    uint32_t hash = 0x811C9DC5;
    uint32_t idx = 0;
    if (nameStr[4] != 0)
    {
        do {
            uint8_t byte = *(uint8_t*)((uint32_t)namePtr + idx);
            idx++;
            hash = (byte ^ hash) * 0x1000193;
        } while (idx < nameStr[4]);
    }

    // Step 5: Look up in hash table
    // int result = FUN_00626fe0(..., nameStr, hash);
    // int entryPtr = *(int*)(result + 4);
    // if (entryPtr == 0) entryPtr = *(int*)(param1 + 4); // sentinel

    // Step 6: Return handle or 0
    // if (entryPtr == sentinel) return 0;
    // return *(uint32_t*)(entryPtr + 0x20);
    */

    return 0;
}

// ─── VFSFileOpen (FUN_00624cb0) — FAIL ────────────────────────
// Status: FAIL
// Mutex-locked file open. Checks VFS init, searches hash table, opens via
// FileOpenWithFormatDetection if needed, creates stream reader object.

/*
  RAW DECOMPILATION (Ghidra) — see ghidra_exports/level4/00624cb0.c (172 lines)
  Key operations:
    - Calls VFS_Initialize() to ensure VFS is ready
    - Locks mutex DAT_00685860
    - Searches file via FUN_00624910 (hash table lookup)
    - If found in hash table:
        - Checks if same file already open (DAT_0074bc18)
        - If different, closes old via FUN_00490c50, opens new via FileOpenWithFormatDetection
        - Creates stream reader object (ref-counted, vtable at PTR_FUN_0066a958)
        - Allocates read buffer, calls ZipFileStreamReader
    - If not in hash table:
        - Falls back to FUN_00624a10 / FUN_006242d0 (raw file path)
        - Creates different stream reader type
    - Unlocks mutex, calls FUN_00624f88 (post-open)
*/

void VFSFileOpen(int* param1)
{
    // Ensure VFS is initialized
    VFS_Initialize();

    // Lock mutex
    // _Mtx_lock(&DAT_00685860);

    /*
    // Search for file in hash table
    int* fileEntry = nullptr; // FUN_00624910();

    if (fileEntry != nullptr)
    {
        // File found in VFS
        // FUN_00624190(); // prepare path

        if (*fileEntry != (int)DAT_0074bc18)
        {
            if (DAT_0074bc18 != 0)
            {
                // FUN_00490c50(); // close previous file
            }
            DAT_0074bc18 = 0;

            bool opened = FileOpenWithFormatDetection(nullptr);
            if (!opened)
            {
                *param1 = 0;
                param1[1] = 0;
                goto cleanup;
            }
            DAT_0074bc18 = *fileEntry;
        }

        // Create stream reader object (0x20 bytes, ref-counted)
        // vtable at PTR_FUN_0066a958
        // Read buffer allocated via FUN_0064356b
        // ZipFileStreamReader called for initial read
    }
    else
    {
        // Fall back to raw file path
        // FUN_00624a10() / FUN_006242d0()
    }

cleanup:
    // FUN_004439b0(); // string cleanup
    // _Mtx_unlock(&DAT_00685860);
    // FUN_00624f88(); // post-open notification
    */
}

// ─── MultiLevelPathBuilder (FUN_00625490) — FAIL ──────────────
// Status: FAIL
// Formats a multi-level path: "%s\%c%c%c\%s" from components.
// Used for 3-character subdirectory structures (e.g., "Bin\Worlds\abc\file.ext").

/*
  RAW DECOMPILATION (Ghidra):
  undefined4 __thiscall FUN_00625490(undefined4 param_1, undefined4 *param_2,
      undefined1 *param_3, undefined1 *param_4, undefined1 *param_5, undefined4 *param_6)
  {
    local_54 = 0xc;
    local_38 = *param_2;
    local_60 = CONCAT31((int3)((uint)param_1 >> 8), *param_3);
    local_50 = CONCAT31(local_50._1_3_, *param_4);
    local_58 = "%s\\%c%c%c\\%s";
    local_48 = CONCAT31(local_48._1_3_, *param_5);
    local_18 = *param_6;
    local_34 = 0xc;
    local_30 = local_60;
    local_28 = local_50;
    local_20 = local_48;
    local_14 = 0xc;
    FUN_00444db0(0xc888c, 0, &local_38); // sprintf wrapper
    return param_1;
  }
*/

uint32_t MultiLevelPathBuilder(uint32_t param1, uint32_t* param2,
                               uint8_t* param3, uint8_t* param4,
                               uint8_t* param5, uint32_t* param6)
{
    /*
    // Format: "%s\\%c%c%c\\%s"
    // Components:
    //   param_2  — base path string
    //   param_3  — first char of subdirectory
    //   param_4  — second char of subdirectory
    //   param_5  — third char of subdirectory
    //   param_6  — filename string
    //   param_1  — high byte provides additional context
    //
    // Delegates to sprintf wrapper: FUN_00444db0(0x0C888C, 0, ...)
    */
    return param1;
}

// ─── SimplePathJoin (FUN_00625570) — FAIL ─────────────────────
// Status: FAIL
// Formats "%s\%s" from two string parameters.

/*
  RAW DECOMPILATION (Ghidra):
  undefined4 __thiscall FUN_00625570(undefined4 param_1, undefined4 *param_2, undefined4 *param_3)
  {
    local_2c = 5;
    local_20 = *param_2;
    local_30 = "%s\\%s";
    local_18 = *param_3;
    local_1c = 5;
    local_14 = 5;
    local_34 = param_1;
    FUN_00444db0(0xcc, 0, &local_20);  // sprintf wrapper
    return param_1;
  }
*/

uint32_t SimplePathJoin(uint32_t param1, uint32_t* param2, uint32_t* param3)
{
    /*
    // Format: "%s\\%s"
    //   param_2 — first path component
    //   param_3 — second path component
    //   param_1 — output / context
    //
    // Delegates to sprintf wrapper: FUN_00444db0(0xCC, 0, ...)
    */
    return param1;
}

// ─── VFSHashTableLookup (FUN_00625a30) — FAIL ─────────────────
// Status: FAIL
// FNV-1a hash on filename, searches file table. Returns handle at entry+0x20.

/*
  RAW DECOMPILATION (Ghidra):
  undefined4 __fastcall FUN_00625a30(int param_1, undefined4 param_2)
  {
    FUN_004431a0(param_2);                      // lowercase / normalize
    puVar2 = FUN_005e8ea0(local_20);            // convert to narrow string
    puVar6 = puVar2;
    if (0xf < (uint)puVar2[5]) puVar6 = *puVar2; // SSO check

    // FNV-1a hash
    uVar4 = 0; uVar5 = 0x811c9dc5;
    if (puVar2[4] != 0) {
      do {
        pbVar1 = (byte *)((int)puVar6 + uVar4);
        uVar4++;
        uVar5 = (*pbVar1 ^ uVar5) * 0x1000193;
      } while (uVar4 < (uint)puVar2[4]);
    }

    iVar3 = FUN_004c3300(local_28, puVar2, uVar5); // hash table lookup
    iVar3 = *(int *)(iVar3 + 4);
    if (iVar3 == 0) iVar3 = *(int *)(param_1 + 4); // sentinel
    FUN_004439b0();                              // cleanup

    if (iVar3 != *(int *)(param_1 + 4))
      return *(undefined4 *)(iVar3 + 0x20);     // found: return handle
    return 0;                                    // not found
  }
*/

uint32_t VFSHashTableLookup(int param1, uint32_t param2)
{
    /*
    // Step 1: Normalize filename
    // FUN_004431a0(param2);

    // Step 2: Convert to narrow string
    // uint32_t* nameStr = FUN_005e8ea0(...);

    // Step 3: SSO pointer resolution
    // uint32_t* namePtr = (nameStr[5] > 0x0F) ? (uint32_t*)nameStr[0] : nameStr;

    // Step 4: FNV-1a hash
    uint32_t hash = 0x811C9DC5;
    uint32_t idx = 0;
    // if (nameStr[4] != 0) {
    //     do { hash = (*(uint8_t*)(namePtr + idx) ^ hash) * 0x1000193; idx++; }
    //     while (idx < nameStr[4]);
    // }

    // Step 5: Hash table lookup
    // int result = FUN_004c3300(..., nameStr, hash);
    // int entryPtr = *(int*)(result + 4);
    // if (entryPtr == 0) entryPtr = *(int*)(param1 + 4); // sentinel

    // Step 6: Return handle or 0
    // if (entryPtr != *(int*)(param1 + 4))
    //     return *(uint32_t*)(entryPtr + 0x20);
    */
    return 0;
}

// ─── PathBuilderWorlds (FUN_0044e25b) — FAIL ──────────────────
// Status: FAIL
// Appends "Bin\Worlds" directory path to the output wstring.
// Uses CRT string copy (FUN_0043db50) and SSO wstring assignment.

/*
  RAW DECOMPILATION (Ghidra):
  void FUN_0044e25b(void)
  {
    *(undefined1 *)(unaff_EBP + -0x54) = 0;
    FUN_0043db50(*(undefined4 *)(unaff_EBP + -0x54), "Bin\\Worlds", 10); // strncpy
    if (unaff_EDI != (undefined4 *)(unaff_EBP + -0x34)) {
      FUN_00443490();   // string assign/copy
      // Copy 6 DWORDs (SSO wstring: buffer[4] + length + capacity)
      *unaff_EDI = uVar1; unaff_EDI[1] = uVar2; ... unaff_EDI[3] = uVar4;
      *(undefined8 *)(unaff_EDI + 4) = *(undefined8 *)(unaff_EBP + -0x24);
      *(uint*)(unaff_EBP + -0x24) = 0;
      *(uint*)(unaff_EBP + -0x20) = 7;  // SSO capacity
    }
    FUN_00443490();     // cleanup temp
    FUN_00450d90();     // destructor
    FUN_00443490();     // final cleanup
  }
*/

void PathBuilderWorlds()
{
    // Copies "Bin\Worlds" (10 chars) into output wstring.
    // The function operates via register-based calling convention (unaff_EBP/EDI),
    // suggesting it is inlined or uses a non-standard frame.
    //
    // Essentially equivalent to:
    //   output_wstring = L"Bin\\Worlds";
    //
    // Full implementation requires the CRT SSO wstring helpers:
    //   FUN_0043db50 — strncpy into temp buffer
    //   FUN_00443490 — SSO string assign/destruct
    //   FUN_00450d90 — temp string destructor
}

} // namespace Giants
