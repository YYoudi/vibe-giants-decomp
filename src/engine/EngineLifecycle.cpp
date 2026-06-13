// Giants Engine - Engine Lifecycle Stubs Implementation
// Reverse engineered from GiantsMain.exe v1.520.59

#include "EngineLifecycle.h"
#include "EngineInit.h"
#include "CRTStubs.h"

#include <cstdlib>
#include <cstring>
#include <objbase.h>
#include <mmsystem.h>

namespace Giants {

// ─── External globals ───────────────────────────────────────────

extern void* g_renderDevice;        // DAT_00702700 — primary renderer COM object
extern int   g_sceneReady;          // DAT_00702770
extern char  g_rendererAvailable;   // DAT_00702b5a

// Version components (from Ghidra: "Starting Giants v{}.{}.{}.{}")
static uint32_t s_versionA = 0;     // local_34 = version major
static uint32_t s_versionB = 0;     // local_2c = version minor
static uint32_t s_versionC = 0;     // local_24 = version patch
static uint32_t s_versionD = 0;     // local_1c = version build

// File validation globals
static uint8_t DAT_00702b58 = 0;    // Game files check passed
static void*   DAT_0074b820 = nullptr;  // Entity list head
static uint32_t DAT_0074b824 = 0;    // Entity list tail

// ═══════════════════════════════════════════════════════════════════
// PreInitCheck — FUN_005c45f0
// ═══════════════════════════════════════════════════════════════════
// Full game initialization. 36 callees, ~250 lines decompiled.
// This is THE main init function called from InitializeEngine.

int PreInitCheck()
{
    // ── Phase 1: Log version ────────────────────────────────────
    // fmt::v9::vformat("Starting Giants v{}.{}.{}.{}")
    // FUN_0043f440(6, 2, formattedString) — log output
    // FUN_004439b0() — ClearStdString

    // ── Phase 2: COM init ───────────────────────────────────────
    CoInitialize(nullptr);

    // ── Phase 3: Seed random ────────────────────────────────────
    DWORD seed = timeGetTime() & 0x7FFF;
    srand(seed);

    // ── Phase 4: Init subsystems ────────────────────────────────
    // FUN_00638e40() — math init
    // FUN_0042fc00() — CRT init
    // FUN_0046fd40() — COM class registration

    // ── Phase 5: Create COM objects ─────────────────────────────
    // Creates 3 COM objects with ref counting:
    //   1. Object with vtable PTR_FUN_0066a574 (size 0x28)
    //      Registered with DAT_0073c924 → pcVar2(&DAT_0066a584, ...)
    //   2. Object with vtable PTR_FUN_00660250 (size 0x24)
    //      Registered with FUN_00471ba0() + DAT_00660240
    //   3. Object with vtable PTR_FUN_0065dc80 (size 0x4C)
    //      Registered with FUN_0044e140() + DAT_0065dc70

    // ── Phase 6: Init engine state ──────────────────────────────
    g_sceneReady = 0;      // DAT_00702770 = 0
    // Various magic constants set at 0x00702754..0x0070276d
    // These appear to be XOR-encoded resource identifiers

    // ── Phase 7: Validate game files ────────────────────────────
    if (DAT_00702b58 == '\0')
    {
        // No launcher detected — show error
        // pcVar8 = "ErrNoLauncher"
        // FUN_005e80c0("ErrNoLauncher") → GetLocalizedString
        // FUN_0062edc0(errorMsg) → ShowErrorDialog
        return 0;
    }

    // Open game data file via VFS
    // FUN_00624b60() → OpenReplayFile (returns HANDLE)
    // ReadFile to validate header: first 4 bytes == 2, then == 0x7A330000

    // ── Phase 8: Load intro scene ───────────────────────────────
    // If file validation passes:
    //   FUN_00575e10() — scene init
    //   FUN_00576050() — scene load
    //   FUN_00461a60() — get player manager
    //   vtable[0x30]() — load "intro_island"
    //   FUN_0057ce00() — scene finalize
    //   FUN_005791c0() — audio init

    // ── Phase 9: Register 4th COM object ────────────────────────
    // Object with vtable PTR_guard_check_icall_0065dba0 (size 0x10)
    // Registered with DAT_0065db90

    // ── Phase 10: Final init ────────────────────────────────────
    // FUN_00443e20() — string cleanup
    // FUN_004630d0() — post-init
    // FUN_0056f920() — scene ready

    return 1;  // uVar10 = 1 (success)
}

// ═══════════════════════════════════════════════════════════════════
// ShutdownAudio — FUN_005c4d20
// ═══════════════════════════════════════════════════════════════════
// Full engine shutdown sequence. 19 callees, ~170 lines decompiled.

int ShutdownAudio()
{
    // ── Phase 1: Pre-shutdown hooks ─────────────────────────────
    // DAT_00728024(cookie) — security check
    // DAT_0072802c() — pre-shutdown callback
    // DAT_00728020() — pre-shutdown callback 2

    // ── Phase 2: Network cleanup ────────────────────────────────
    // if (DAT_006ff960 == 6) {  // game running
    //     if (DAT_00702964 == 0) FUN_00464710();
    //     else FUN_0045fe10(local_14);
    //     Sleep(500);
    // }

    // ── Phase 3: Game state cleanup ─────────────────────────────
    // DAT_006ffa0c = 1
    // if (DAT_00702964 == 0) FUN_00454cf0();
    // else FUN_00454bd0();
    // DeleteCriticalSection(&DAT_006ffa14)
    // DeleteCriticalSection(&DAT_006ff9ec)

    // ── Phase 4: Free allocated buffers ─────────────────────────
    // FUN_005c2040() — subsystem shutdown
    // free(DAT_0073f7f8) — primary buffer
    // free(DAT_0073f7f0) — secondary buffer
    // free(DAT_007496cc) — tertiary buffer

    // ── Phase 5: Zero globals ───────────────────────────────────
    // DAT_007027f4..f8 = 0, DAT_007027ec..e8 = 0
    // DAT_007027a8..e4 = 0 (19 globals zeroed)

    // ── Phase 6: Free COM objects ───────────────────────────────
    // DAT_00702788, DAT_00702784, DAT_00702780, DAT_0070277c
    // Each: free(obj+0x18), free(obj+0x14), free(obj+0x1c),
    //       free(obj+0xc), free(obj+0x10), free(obj)

    // ── Phase 7: String table cleanup ───────────────────────────
    // FUN_0062be00() — display cleanup
    // Walk DAT_0074b804 linked list, CRTFree each node[8]
    // FUN_005e8720() — string table shutdown
    // free(DAT_00685768), free(DAT_0068576c), free(DAT_00685770)

    // ── Phase 8: Entity list cleanup ────────────────────────────
    // Walk DAT_0074b820 linked list:
    //   For each entity with texture data (10 entries per entity),
    //   free texture data, clear flags
    // Free entity nodes via free_exref

    // ── Phase 9: Final cleanup ──────────────────────────────────
    // DAT_007280c4() — renderer shutdown callback
    // DAT_007280c8() — audio shutdown callback
    // FUN_00490c50() — if DAT_0074bc18 != 0
    // FUN_006259f0() — list cleanup 1
    // FUN_006259b0() — list cleanup 2
    // Walk DAT_0074bbcc list, free each node[8]
    // Walk DAT_0074bbec list, free each node[8]
    // Walk DAT_0074bc08..bc0c array, free each entry
    // Walk DAT_00747b44..b48 array, free each 0x140-byte entry

    // ── Phase 10: COM uninit ────────────────────────────────────
    CoUninitialize();

    // FUN_00461f00("Exiting game", 0xc) — debug log
    return 0;
}

// ═══════════════════════════════════════════════════════════════════
// InitGlobals — FUN_0062d590
// ═══════════════════════════════════════════════════════════════════
// Command-line argument parser + global defaults.
// 28 callees, ~250 lines decompiled.
// Tokenizes the command line and sets engine flags based on switches.

void InitGlobals(char* commandLine)
{
    // ── Phase 1: Set default globals ────────────────────────────
    // DAT_0074c468 = 6  (default game mode bits)
    // FUN_00561a70() — pre-init defaults
    // DAT_007283a9 = 0  (dedicated server flag)

    // ── Phase 2: Token parsing loop ─────────────────────────────
    // Tokenizes by whitespace, with support for quoted strings.
    // Each token is matched against a giant if-else chain:
    //
    // iVar8 = token index (incremented per token):
    //   1: Set player name → DAT_007281f0 (32 bytes)
    //   2: Set server address → DAT_00728210 (80 bytes)
    //   3: Set password → DAT_00728260 (8 bytes)
    //   4: Set session name → DAT_00728268 (80 bytes)
    //   5: Set max players (0..5) → DAT_00702934
    //   6: Set player count (2..20, default 10) → DAT_0070294c
    //   7: Set game type → DAT_00702a60 (32 bytes)
    //   8: Set server info → DAT_00702968 (32 bytes)
    //   9: Set level name → DAT_00702988, DAT_00702b34 = 1
    //   0xb: Set timeout → DAT_007029c8, DAT_00702b38 = 1
    //   0xc: Set port → DAT_0070292c
    //   0xd: Set team mode (0..2) → DAT_00702bf4
    //   0xe: Set server URL → DAT_0074be70 (64 bytes)
    //   0xf: Set FOV/scale → DAT_00682170 (mouse speed)
    //   0x10: Load dedicated server settings from file
    //         FUN_00624b60() → OpenReplayFile
    //         ReadFile of 0x130 bytes → parse server config
    //   0x13: Set value → DAT_00702b78
    //   0x14: Set value → DAT_00702b7c
    //
    // Non-indexed switches (matched by string comparison):
    //   "-dedicated"      → DAT_00702b5a = 1, server name
    //   "-window"         → windowed mode
    //   "-exit"           → immediate exit
    //   "-nointro"        → skip intro
    //   "+connect"        → DAT_00702b28 = 1
    //   "+host"           → DAT_00702b30 = 1
    //   "+log"            → DAT_00702b40 = 1
    //   "+nointro"        → skip intro
    //   "+useres"         → DAT_00702b50 = 1
    //   various resolution → DAT_00702b80/b84
    //   "-WxH"            → set resolution (e.g., -1024x768)

    // Parse loop (stub — actual token matching omitted for brevity)
    char* ptr = commandLine;
    int tokenIndex = 0;

    while (true)
    {
        // Skip whitespace
        while (*ptr != '\0' && isspace((int)*ptr))
            ptr++;

        if (*ptr == '\0')
            break;

        // Extract token (quoted or whitespace-delimited)
        char* tokenStart = ptr;
        char* tokenEnd = ptr;

        if (*ptr == '"')
        {
            ptr++;
            tokenStart = ptr;
            while (*ptr != '\0' && *ptr != '"')
                ptr++;
            tokenEnd = ptr;
            if (*ptr == '"')
                ptr++;
        }
        else
        {
            while (*ptr != '\0' && !isspace((int)*ptr))
                ptr++;
            tokenEnd = ptr;
        }

        // Token is [tokenStart, tokenEnd)
        int tokenLen = (int)(tokenEnd - tokenStart);

        // Match token against switch table
        // (Full matching logic in Ghidra decompilation — 250+ lines)
        tokenIndex++;
    }
}

// ═══════════════════════════════════════════════════════════════════
// InitCOMSubsystem — FUN_0042fc00
// ═══════════════════════════════════════════════════════════════════
// COM object factory: allocates 0x58-byte object with vtable PTR_FUN_0065ce08,
// initializes refcount (ref[1]=1, weak[2]=1), registers with DAT_0073c924
// via virtual call at vtable[1]. Calls FUN_004358b0, FUN_0042e110, FUN_0042fd68.
// 1 caller (PreInitCheck Phase 4), 7 callees.

void InitCOMSubsystem()
{
    // Original:
    // piVar5 = operator_new(0x58);
    // piVar5[0] = &PTR_FUN_0065ce08;  // vtable
    // piVar5[1] = 1;                   // refcount
    // piVar5[2] = 1;                   // weak refcount
    // memset(piVar5 + 4, 0, 0x48);     // zero fields
    // FUN_004358b0();
    // Register with DAT_0073c924->vtable[1](&DAT_0065cdf8, piVar5+4, piVar5)
    // FUN_0042e110();
    // FUN_0042fd68();
}

// ═══════════════════════════════════════════════════════════════════
// InitStringSubsystem — FUN_00443e20
// ═══════════════════════════════════════════════════════════════════
// String subsystem init: allocates 0x14-byte COM object with vtable PTR_FUN_0065d134,
// calls FUN_00443f80 for local context, FUN_00443ce0 for init, then registers
// with DAT_0073c924->vtable[1](&DAT_0065d124, obj+3, obj, cookie).
// 1 caller (PreInitCheck Phase 10), 5 callees.

int InitStringSubsystem()
{
    // Original:
    // FUN_00443f80(&local_1c);  — local string context init
    // piVar5 = operator_new(0x14);
    // piVar5[0] = &PTR_FUN_0065d134;  // vtable
    // piVar5[1] = 1;                   // refcount
    // piVar5[2] = 1;                   // weak refcount
    // Register with DAT_0073c924->vtable[1](&DAT_0065d124, piVar5+3, piVar5, cookie)
    // Release local_18 if non-null (COM release pattern)
    return 0;
}

// ═══════════════════════════════════════════════════════════════════
// InitRenderObject — FUN_0044e140
// ═══════════════════════════════════════════════════════════════════
// Initializes a 0x34-field render object with vtable PTR_FUN_0065dce4.
// Sets fields 1-10 to zero, fields 6/12 to 7, calls FUN_00623960 (VFS),
// FUN_00441d10 (string init), FUN_00450d90, FUN_0044e25b (self-call setup).
// 1 caller (PreInitCheck Phase 5), 4 callees.

void InitRenderObject(uint32_t* param_1)
{
    // Original:
    // *param_1 = &PTR_FUN_0065dce4;   // vtable
    // param_1[1..5] = 0;              // zero init
    // param_1[6] = 7;                 // sentinel value
    // param_1[7..10] = 0;
    // param_1[11] = 0;
    // param_1[12] = 7;                // sentinel value
    // param_1[13..15] = 0;
    // FUN_00623960();                  // VFS init
    // FUN_00441d10(local_5c);          // string init
    // FUN_00450d90();                  // sub-init
    // FUN_0044e25b();                  // self-setup
}

// ═══════════════════════════════════════════════════════════════════
// InitCriticalSectionSubsystem — FUN_004630d0
// ═══════════════════════════════════════════════════════════════════
// Initializes thread synchronization: zeroes DAT_006ffa08 (0x202c bytes),
// creates two critical sections (DAT_006ffa14, DAT_006ff9ec), calls
// FUN_006036a0, allocates 0x3C-byte COM object with vtable PTR_FUN_00669480,
// registers with DAT_0073c924 via 4 iterations over &DAT_00669460 array.
// 1 caller (PreInitCheck Phase 10), 8 callees.

int* InitCriticalSectionSubsystem()
{
    // Original:
    // memset(&DAT_006ffa08, 0, 0x202c);
    // FUN_00463020(cookie);
    // InitializeCriticalSection(&DAT_006ffa14);
    // InitializeCriticalSection(&DAT_006ff9ec);
    // FUN_006036a0();
    // piVar4 = operator_new(0x3c);
    // piVar4[0] = &PTR_FUN_00669480;
    // piVar4[1] = 1;  // refcount
    // piVar4[2] = 1;  // weak ref
    // Register with DAT_0073c924->vtable[1] 4 times (ppuVar7 loop)
    return nullptr;
}

// ═══════════════════════════════════════════════════════════════════
// CreateCOMInstance — FUN_0046fd40
// ═══════════════════════════════════════════════════════════════════
// COM class factory helper: creates an instance from a class ID.
// Calls vtable[2] on the class object (param_1 masked) to create instance.
// If unaff_EBX != 0, sets up a 2-field pair [ebx, classObj] with ref counting.
// 3 callers (PreInitCheck Phase 5 x3), 0 callees (pure COM dispatch).

int* CreateCOMInstance(uint32_t param_1)
{
    // Original:
    // vtable[2](&DAT_00660194) — create instance from class factory
    // If unaff_EBX == 0: release classObj and return null piStack_4
    // If unaff_EBX != 0:
    //   AddRef classObj
    //   piStack_4 = [unaff_EBX, classObj]
    //   Release classObj
    //   return piStack_4
    return nullptr;
}

// ═══════════════════════════════════════════════════════════════════
// InitAudioObject — FUN_00471ba0
// ═══════════════════════════════════════════════════════════════════
// Initializes an audio COM object (vtable PTR_FUN_00660260, 6 fields).
// Calls FUN_004743f0 for audio driver init, sets DAT_00701a3c flags |= 5,
// calls FUN_00483180 for audio config, clears DAT_00701a3c+0x1e78.
// 1 caller (PreInitCheck Phase 5), 2 callees.

uint32_t* InitAudioObject(uint32_t* param_1)
{
    // Original:
    // *param_1 = &PTR_FUN_00660260;   // vtable
    // param_1[1..3] = 0;
    // param_1[4] = 0;
    // *(uint8_t*)(param_1 + 5) = 0;
    // param_1[4] = FUN_004743f0(cookie);  // audio driver init
    // *(uint32_t*)(DAT_00701a3c + 8) |= 5;  // set flags
    // FUN_00483180();                        // audio config
    // *(uint32_t*)(DAT_00701a3c + 0x1e78) = 0;
    return param_1;
}

// ═══════════════════════════════════════════════════════════════════
// LoadDisplaySettings — FUN_00561a70
// ═══════════════════════════════════════════════════════════════════
// Loads video display settings from Windows registry.
// Opens registry via LockGraphics (FUN_0062ad90), reads values:
//   VideoWidth, VideoHeight, Antialiasing, Windowed, VerticalSync,
//   TripleBuffering, DisableAspectRatioCorrection, VideoDevGuid, VideoDrvGuid.
// Closes registry via UnlockGraphics (FUN_0062ae40).
// 1 caller (InitGlobals Phase 1), 5 callees.

void LoadDisplaySettings()
{
    // Original:
    // memset(&DAT_00702af8, 0, 0x104);  // clear video settings struct
    // DAT_00702b14 = 1;  // defaults
    // DAT_00702b24 = 3;
    // DAT_00702bf9 = 1;
    // FUN_0062ad90();  // LockGraphics — open registry key
    // FUN_00540230();  // pre-load defaults
    // RegQueryValueExA(DAT_0074be54, "VideoWidth", ..., &DAT_00702b80, ...);
    // RegQueryValueExA(DAT_0074be54, "VideoHeight", ..., &DAT_00702b84, ...);
    // RegQueryValueExA(DAT_0074be54, "Antialiasing", ..., &DAT_00702b88, ...);
    // RegQueryValueExA(DAT_0074be54, "Windowed", ..., &local_4, ...);
    // DAT_00702b8e = (local_4 != 0);  // fullscreen flag
    // RegQueryValueExA(DAT_0074be54, "VerticalSync", ..., &local_8, ...);
    // DAT_00702b8c = (local_8 != 0);  // vsync flag
    // RegQueryValueExA(DAT_0074be54, "TripleBuffering", ..., &local_8, ...);
    // DAT_00702b8d = (local_8 != 0);
    // RegQueryValueExA(DAT_0074be54, "DisableAspectRatioCorrection", ..., &local_8, ...);
    // if (local_8) DAT_00702bf9 = 0;
    // RegQueryValueExA(DAT_0074be54, "VideoDevGuid", ..., &DAT_00702ba0, 0x10);
    // RegQueryValueExA(DAT_0074be54, "VideoDrvGuid", ..., &DAT_00702b90, 0x10);
    // FUN_0062ae40();  // UnlockGraphics — close registry
}

// ═══════════════════════════════════════════════════════════════════
// LoadProjectileDefs — FUN_0056f920
// ═══════════════════════════════════════════════════════════════════
// Loads "wdefs.bin" (weapon/projectile definitions) from VFS.
// Opens file via FUN_00624b60, reads 8-byte header (magic=3, size),
// allocates buffer and reads full data. Creates 0x78-byte COM object
// (vtable PTR_FUN_00664978), validates checksum via FUN_00632820.
// On failure: logs error, sets DAT_007281e4 = 1.
// 1 caller (PreInitCheck Phase 8), 19 callees.

int* LoadProjectileDefs()
{
    // Original:
    // strncpy(local_30, "wdefs.bin", 10);
    // hFile = FUN_00624b60();  // OpenReplayFile
    // if (hFile) ReadFile(hFile, &local_5c, 8, ...);  // header: magic + size
    // if (local_5c != 3) { error; return; }
    // piVar9 = malloc(local_58);  // allocate buffer
    // ReadFile(hFile, piVar9 + 2, local_58 - 8, ...);
    // CloseHandle(hFile);
    // Allocate 0x78-byte COM object (vtable PTR_FUN_00664978)
    // Register with container, compute checksum
    // if (checksum != -0x410e18bb) DAT_007281e4 = 1;
    // free(piVar9);
    return nullptr;
}

// ═══════════════════════════════════════════════════════════════════
// LoadGameObjDefs — FUN_00575e10
// ═══════════════════════════════════════════════════════════════════
// Parses "GameObj.bin" — a binary file containing game object definitions.
// Opens via FUN_00624b60, validates magic 0x1a0002dd, reads entire blob.
// Parses byte records: type byte (1-9) followed by two null-terminated strings.
// Types 1,3,8 call FUN_00526ed0 to register string hashes into globals
// (DAT_0070277c, DAT_00702788, DAT_00702784).
// 1 caller (PreInitCheck Phase 8), 7 callees.

void LoadGameObjDefs()
{
    // Original:
    // hFile = FUN_00624b60();  // opens GameObj.bin
    // if (!hFile) { FUN_0062edc0("Failed to open GameObj.bin"); return; }
    // ReadFile(hFile, &local_8, 4, ...);  // magic
    // if (local_8 != 0x1a0002dd) { error; CloseHandle; return; }
    // ReadFile(hFile, &local_c, 4, ...);  // size
    // lpBuffer = malloc(local_c);
    // ReadFile(hFile, lpBuffer, local_c, ...);
    // Parse loop: byte record types 1-9 with 2 strings each
    // Type 1: DAT_0070277c = FUN_00526ed0(str1)
    // Type 3: DAT_00702788 = FUN_00526ed0(str1)
    // Type 8: DAT_00702784 = FUN_00526ed0(str1)
    // Types 2,4,5,6,7,9: skip (advance past two strings)
    // Type -1 (0xff): free + CloseHandle + return
}

// ═══════════════════════════════════════════════════════════════════
// LoadGDataFile — FUN_00576050
// ═══════════════════════════════════════════════════════════════════
// Loads "GData.gbn" — game data binary. Opens via FUN_00624b60,
// validates magic 0x7a330000, reads two integer arrays (int counts).
// Allocates/reuses buffers at DAT_007028f4 and DAT_007028fc.
// Validates checksum via FUN_00632820, increments DAT_007028ec load counter.
// On checksum mismatch: sets DAT_007281e4 = 1.
// 1 caller (PreInitCheck Phase 8), 10 callees.

void LoadGDataFile()
{
    // Original:
    // strncpy(local_30, "GData.gbn", 10);
    // hFile = FUN_00624b60();
    // if (!hFile) return;
    // ReadFile(hFile, &local_5c, 4, ...);  // magic
    // if (local_5c != 0x7a330000) { CloseHandle; return; }
    // ReadFile(hFile, &local_4c, 4, ...);  // count1
    // ReadFile(hFile, &local_50, 4, ...);  // count2
    // Allocate/reuse DAT_007028f4 = malloc(count1 * 4)
    // Allocate/reuse DAT_007028fc = malloc(count2 * 4)
    // ReadFile both arrays
    // Validate checksum via FUN_00632820
    // if (checksum != -0x1f8fcb08) DAT_007281e4 = 1;
    // CloseHandle(hFile);
    // DAT_007028ec++;
}

// ═══════════════════════════════════════════════════════════════════
// LoadWorldData — FUN_005791c0
// ═══════════════════════════════════════════════════════════════════
// Massive world data loader (~2000 lines Ghidra). Opens a worlds binary file
// via VFS (FUN_00624cb0), validates version 0x1a0002e5, reads scene header
// (0x1c bytes: file offsets and counts), then loads in sequence:
//   1. Skybox data (FUN_00557cc0)
//   2. Texture array (FUN_005e8f10)
//   3. Light data (FUN_005794d5 onward)
//   4. Entity/world objects
//   5. Game state (FUN_0056d960)
// Uses ReadFile for disk mode, memory pointer for packed mode.
// 2 callers (PreInitCheck, scene transition), 38 callees.
// FAIL (usable ~60%) — extremely complex, partially recovered.

float* LoadWorldData(float* param_1)
{
    // Phase 1: Open and validate
    // FUN_00624cb0() — open worlds binary
    // if (failed) { error + DAT_007283a5 = 1; return; }
    // Read version, validate == 0x1a0002e5

    // Phase 2: Read scene header (0x1c bytes)
    // SetFilePointer to offsets, load skybox, textures, lights, entities

    // Phase 3: Process entities
    // Loop over entity data, create objects, register in world

    // Phase 4: Post-load
    // FUN_0056d960() — game state init
    // Close file handle

    return nullptr;
}

// ═══════════════════════════════════════════════════════════════════
// DispatchSceneCommand — FUN_0057ce00
// ═══════════════════════════════════════════════════════════════════
// Dispatches a scene command with string parameter.
// Computes string length, packs (param_1, param_2 string, *param_3)
// into a local struct, and calls FUN_00444db0(opcode=0xC, flags=0, &struct).
// 3 callers (PreInitCheck, scene transitions), 2 callees.

uint32_t DispatchSceneCommand(uint32_t param_1, char* param_2, uint32_t* param_3)
{
    // Original:
    // pcVar2 = param_2; do { cVar1 = *pcVar2++; } while (cVar1 != '\0');
    // local_24 = strlen(param_2);
    // local_18 = *param_3;
    // local_2c = param_1;
    // local_28 = param_2;
    // local_14 = local_24;
    // FUN_00444db0(0xC, 0, &local_18);  // dispatch command
    return param_1;
}

// ═══════════════════════════════════════════════════════════════════
// ClearLinkedList — FUN_005e8720
// ═══════════════════════════════════════════════════════════════════
// Clears an intrusive doubly-linked list (sentinel at param_1+4).
// If count (param_1+8) is small relative to capacity (param_1+0x1c >> 3),
// walks the list: clears each node's backlink, calls ClearStdString (FUN_004439b0),
// frees each 0x24-byte node via FUN_00643505, then resets sentinel to self-link.
// Calls FUN_00438270 to reset count.
// 5 callers (ShutdownAudio, scene cleanup), 4 callees.

void ClearLinkedList(int param_1)
{
    // Original:
    // if (*(uint*)(param_1 + 8) == 0) return;
    // if (*(uint*)(param_1 + 8) < *(uint*)(param_1 + 0x1c) >> 3) {
    //     FUN_005e8a10(**(int**)(param_1+4), *(int**)(param_1+4));
    //     return;
    // }
    // Walk list from sentinel->next:
    //   puVar1 = *puVar1;  // next
    //   FUN_004439b0();    // ClearStdString
    //   FUN_00643505(puVar1, 0x24);  // free node
    // Reset sentinel to self-link, clear count
    // FUN_00438270(&local_4);
}

// ═══════════════════════════════════════════════════════════════════
// CleanupEntityListA — FUN_006259b0
// ═══════════════════════════════════════════════════════════════════
// Walks an intrusive linked list (sentinel at param_1+4), freeing each
// node's extension data (node[8], 0x24 bytes) via ClearStdString + free.
// Then calls ClearLinkedList (FUN_005e8720) to reset the list.
// 3 callers (ShutdownAudio), 3 callees.

void CleanupEntityListA(int param_1)
{
    // Original:
    // piVar2 = **(int***)(param_1 + 4);  // first node
    // while (piVar2 != *(int**)(param_1 + 4)) {  // sentinel
    //     iVar1 = piVar2[8];
    //     if (iVar1) { FUN_004439b0(); FUN_00643505(iVar1, 0x24); }
    //     piVar2 = *(int**)piVar2;
    // }
    // FUN_005e8720();  // ClearLinkedList
}

// ═══════════════════════════════════════════════════════════════════
// CleanupEntityListB — FUN_006259f0
// ═══════════════════════════════════════════════════════════════════
// Same as CleanupEntityListA but frees node extension data with 0x1C bytes
// instead of 0x24. Walks list, frees node[8], then calls ClearLinkedList.
// 3 callers (ShutdownAudio), 3 callees.

void CleanupEntityListB(int param_1)
{
    // Original:
    // piVar2 = **(int***)(param_1 + 4);
    // while (piVar2 != *(int**)(param_1 + 4)) {
    //     iVar1 = piVar2[8];
    //     if (iVar1) { FUN_004439b0(); FUN_00643505(iVar1, 0x1c); }
    //     piVar2 = *(int**)piVar2;
    // }
    // FUN_005e8720();  // ClearLinkedList
}

// ═══════════════════════════════════════════════════════════════════
// InitMathTables — FUN_00638e40
// ═══════════════════════════════════════════════════════════════════
// Initializes three math lookup tables:
//   DAT_00698800: sin table (0x5000 entries, indexed by i * _DAT_006543b8)
//   DAT_00688800: 1/sin table (0x4000 entries)
//   DAT_006ac808: acos table (0x4000 entries)
// Uses SSE2 sin/acos intrinsics for computation.
// DAT_006ac800 set to &DAT_0069c800 (cos table base).
// 1 caller (PreInitCheck Phase 4), 2 callees (sin, acos).

void InitMathTables()
{
    // Original:
    // iVar1 = 0;
    // do {  // 0x5000 entries
    //     dVar2 = (double)((float)iVar1 * _DAT_006543b8);
    //     (&DAT_00698800)[iVar1] = sin(dVar2);
    // } while (++iVar1 < 0x5000);
    //
    // DAT_006ac800 = &DAT_0069c800;  // cos table base
    //
    // iVar1 = 0;
    // do {  // 0x4000 entries
    //     dVar2 = (double)((float)iVar1 * _DAT_006543b8);
    //     (&DAT_00688800)[iVar1] = fVar3 / sin(dVar2);  // 1/sin
    // } while (++iVar1 < 0x4000);
    //
    // iVar1 = 0;
    // do {  // 0x4000 entries
    //     dVar2 = (double)((float)iVar1 * _DAT_006543b4 - fVar3);
    //     (&DAT_006ac808)[iVar1] = acos(dVar2);
    // } while (++iVar1 < 0x4000);
}

// ═══════════════════════════════════════════════════════════════════
// DisplayCleanup — FUN_0062be00
// ═══════════════════════════════════════════════════════════════════
// Releases display resources: flushes GDI, deletes font (DAT_0074be6c)
// and bitmap (DAT_0074be64) objects, deletes DC (DAT_0074be60),
// releases renderer surface via vtable[200] if DAT_0074bee8 != 0,
// frees DAT_0074bedc buffer, clears DAT_0074beb0 flag.
// 8 callers (OnResize, ShutdownAudio, mode changes), 4 callees.

void DisplayCleanup()
{
    // Original:
    // if (DAT_0074beb0 == 0) return;
    // GdiFlush();
    // DeleteObject(DAT_0074be6c);  // font
    // DeleteObject(DAT_0074be64);  // bitmap
    // DeleteDC(DAT_0074be60);      // DC
    // if (DAT_0074bee8 != 0) {
    //     (**(code**)(*DAT_00702700 + 200))(&DAT_0074bee0);  // release surface
    // }
    // free(DAT_0074bedc);
    // DAT_0074beb0 = 0;
}

} // namespace Giants
