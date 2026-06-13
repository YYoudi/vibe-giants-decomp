// Giants Engine - Game Context & Initialization Dispatch Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_00461a60 — GetGameContext: COM-style ref-counted context accessor
// FUN_0045af70 — GameInitDispatch: game init/shutdown coordinator
// FUN_00454bd0 — MPCleanup: multiplayer session teardown
// FUN_00454cf0 — SPCleanup: single-player session teardown
// FUN_005c2040 — FullRenderCleanup: complete render pipeline teardown
// FUN_00501340 — PrimaryRenderReset: registry settings refresh
// FUN_00501a20 — PartialRenderCleanup: conditional render cleanup
// FUN_0053b1d0 — MissionCleanup: mission object cleanup
// FUN_00590950 — ReplaySpectatorCleanup: replay/spectator cleanup
// FUN_005dd760 — SecondaryRenderReset: subsystem reset
// FUN_004d1070 — PopDialogLevel: UI dialog stack pop
// FUN_004d39d0 — FreeCommandList: command linked-list deallocator
// FUN_005e9ff0 — CleanupCurrentScene: scene tile grid deallocator

#include "GameContext.h"
#include "ConsoleDebug.h"

#include <cstring>
#include <cstdlib>

namespace Giants {

// ─── External data references ─────────────────────────────────
// Scene context (active scene pointer or handle)
static uint32_t DAT_0073c954 = 0;

// Network session active flag (0 = single-player, non-zero = multiplayer)
static uint32_t DAT_00702964 = 0;

// Single-player init flag
static uint32_t DAT_00702bdd = 0;

// Game state flags
static uint32_t DAT_00702b34 = 0;
static uint32_t DAT_00702b30 = 0;
static uint32_t DAT_00702b50 = 0;
static uint32_t DAT_00702b54 = 0;
static uint32_t DAT_00702be8 = 0;

// Scene object pointer (active game scene)
static uint32_t DAT_00702774 = 0;

// Game state active flag
static uint32_t DAT_006fef88 = 0;

// Render state sentinel (dialog/UI stack depth)
static int32_t DAT_00682204 = 0;

// Scene/Renderer object pointer
static uint32_t DAT_00702770 = 0;

// Renderer vtable pointer
static uint32_t DAT_00702700 = 0;

// Network interface: WinSock (MP) and DirectPlay (SP) COM objects
static int* DAT_006ff9e4 = nullptr;  // WinSock interface
static int* DAT_006ff9e0 = nullptr;  // DirectPlay interface
static int* DAT_006ff9dc = nullptr;  // MP player address object
static int* DAT_006ff9d8 = nullptr;  // SP player address object
static int* DAT_006ff9d4 = nullptr;  // SP provider object
static uint32_t DAT_006ff960 = 0;    // Network active flag
static uint32_t DAT_00702b50_flag = 0;
static int* DAT_0073c92c = nullptr;  // Additional MP COM object

// Network player slots and statistics
static uint32_t DAT_006ff910[20] = {};  // Player slot array (0x50 bytes)
static uint32_t DAT_006fef90[20] = {};  // Player stats array (0x50 bytes)
static uint32_t DAT_006ff558 = 0;
static uint32_t DAT_006ff548 = 0;
static uint32_t DAT_006ff54c = 0;
static uint32_t DAT_006ff550 = 0;
static uint32_t DAT_006ff554 = 0;
static uint32_t DAT_00702bcc = 0;

// Extra COM object pointer
static uint32_t* DAT_0073e77c = nullptr;

// Registry key for game settings
static void* DAT_0074be5c = nullptr;

// Game settings globals (read from registry)
static uint32_t DAT_00702930 = 0;   // PlayerTeam
static uint32_t DAT_00702b40 = 0;
static uint32_t DAT_0070292c = 0;   // GameTeam
static uint8_t  DAT_00702968[32] = {}; // SessionName
static uint32_t DAT_00702b48 = 0;
static uint32_t DAT_00702934 = 0;   // GameType
static uint32_t DAT_00702928 = 0;   // GameBaseLevel
static uint32_t DAT_00702938 = 0;   // AllowJoiners
static uint8_t  DAT_00702939 = 0;   // DamageTeammates
static uint8_t  DAT_0070295c = 0;   // NoVimps
static uint32_t DAT_00702950 = 0;   // LockTeams
static uint32_t DAT_0070293c = 0;   // PointsPerKill
static uint32_t DAT_00702940 = 0;   // PointsPerCapture
static uint32_t DAT_00702944 = 0;   // CapturePreventTime
static uint32_t DAT_00702948 = 0;   // CapturePreventTime (float adjusted)
static uint32_t DAT_00702b44 = 0;
static uint32_t DAT_0070294c = 0;   // MaxPlayers
static uint32_t DAT_00702954 = 0;   // SmartieDifficulty
static uint32_t DAT_00702958 = 0;   // VimpMeatDifficulty
static uint32_t DAT_007029ec = 0;   // TimeLimit
static uint32_t DAT_007029e0 = 0;   // HasTimeLimit
static uint32_t DAT_00702a30 = 0;   // TimeLimit (float adjusted)
static uint32_t DAT_007029fc = 0;   // PlayerScoreLimit
static uint32_t DAT_007029f0 = 0;   // HasPlayerScoreLimit
static uint32_t DAT_00702a0c = 0;   // TeamScoreLimit
static uint32_t DAT_00702a00 = 0;   // HasTeamScoreLimit
static uint32_t DAT_00702a10 = 0;   // BaseComplete
static uint32_t DAT_00702af0 = 0;   // Unavail1
static uint32_t DAT_00702af4 = 0;   // Unavail2

// Float constants
static float DAT_0066c0ac = 0.0f;

// SecondaryRenderReset subsystem flags
static uint32_t DAT_007488e0 = 0;
static uint32_t DAT_007488d8 = 0;
static uint32_t DAT_007488dc = 0;
static uint32_t DAT_007488d4 = 0;
static uint32_t DAT_007488d0 = 0;

// Scene object linked list head
static uint32_t* DAT_007027ac = nullptr;

// Dialog stack data
static uint32_t DAT_00747b60[256] = {};  // Dialog stack array

// Display configuration pointers
static uint32_t DAT_006818b8 = 0;
static uint32_t DAT_006818c8 = 0;
static uint32_t* PTR_DAT_00685890 = nullptr;
static uint32_t DAT_0074be50 = 0;

// Global config constants
static uint32_t DAT_0066c4b0 = 0;
static uint32_t DAT_0066c4b4 = 0;
static uint32_t DAT_0066c4b8 = 0;
static uint32_t DAT_0066c4bc = 0;

// FullRenderCleanup globals
static uint32_t DAT_00702a58 = 0;
static uint32_t DAT_00702a3c = 0;
static uint32_t DAT_00702a40 = 0;
static uint32_t DAT_0073f8b8 = 0;
static int* DAT_00725e98 = nullptr;
static int DAT_00725eae = 0;
static int DAT_00725ea8 = 0;
static int DAT_00725eac = 0;

// Object list globals
static uint32_t* DAT_007496c4 = nullptr;
static uint32_t* DAT_007496c0 = nullptr;
static uint32_t DAT_007496bc = 0;
static uint32_t DAT_007496c8 = 0;
static uint32_t* DAT_007027a8 = nullptr;
static uint32_t DAT_00702800 = 0;
static uint32_t* DAT_007280a0 = nullptr;

// Scene tile grid globals
static uint32_t DAT_00725e14 = 0;

// ═══════════════════════════════════════════════════════════════════
// GetGameContext (FUN_00461a60)
// ═══════════════════════════════════════════════════════════════════
// Returns a ref-counted game context object via COM-style vtable dispatch.
//
// Ghidra: FUN_00461a60 (34 callers, 0 callees)
// Type info reference: DAT_0065f184

int* GetGameContext(uint32_t param_1)
{
    // Compute vtable selector from param_1
    uint32_t vtableSelector = -(uint32_t)(param_1 != 0xFFFFFFFC) & param_1;

    // Stub: In the binary, this performs complex COM-style construction:
    //   1. vtable = *(int*)vtableSelector
    //   2. constructor = *(vtable + 8)
    //   3. constructor(local_8, &DAT_0065f184)
    //   4. Return [object_ptr, refcount_block_ptr]
    //
    // Thread-safe ref-counting uses LOCK/UNLOCK primitives.
    (void)vtableSelector;
    return nullptr;
}

// ═══════════════════════════════════════════════════════════════════
// GameInitDispatch (FUN_0045af70)
// ═══════════════════════════════════════════════════════════════════
// High-level game initialization/shutdown dispatcher.
// Coordinates scene cleanup, network teardown, and buffer resets.
//
// Ghidra: FUN_0045af70 (7 callers, 13 callees)
//
// Original:
//   void __fastcall FUN_0045af70(undefined4 param_1)
//   {
//       FUN_005e9ff0(param_1, DAT_0073c954);     // scene cleanup
//       DAT_0073c954 = 0;
//       if (DAT_00702964 == 0) {                   // single-player path
//           DAT_00702bdd = 0;
//           FUN_00454cf0();                         // SP cleanup
//       } else {                                   // multiplayer path
//           FUN_00454bd0();                         // MP cleanup
//       }
//       DAT_00702b34 = 0;
//       DAT_00702b30 = 0;
//       DAT_00702b50 = 0;
//       if (DAT_00702774 != 0) {                   // scene object exists
//           if (*(int*)(DAT_00702774 + 0x22c) == 2)
//               FUN_0053b1d0();                     // mission cleanup
//           else if (*(int*)(DAT_00702774 + 0x22c) == 3)
//               FUN_00590950();                     // replay/spectator cleanup
//       }
//       if (DAT_006fef88 != 0) {                   // game state active
//           FUN_004d39d0();                         // game state cleanup
//           DAT_006fef88 = 0;
//           FUN_004d1070();                         // post-cleanup
//       }
//       FUN_00501340();                             // render reset
//       FUN_005dd760();                             // secondary render reset
//       DAT_00682204 = 0xffffffff;
//       if (DAT_00702770 != 0) {
//           if ((*(uint*)(DAT_00702770 + 0x3c) & 0x100) == 0)
//               FUN_005c2040();                     // full render cleanup
//           if ((*(uint*)(DAT_00702770 + 0x3c) & 0x100) != 0) {
//               FUN_00501a20();                     // partial render cleanup
//               FUN_00463020();                     // reset console buffers
//               return;
//           }
//       }
//       FUN_00552990();                             // fallback render cleanup
//       FUN_00463020();                             // reset console buffers
//   }

void GameInitDispatch(uint32_t param_1)
{
    // Step 1: Scene cleanup with context parameter
    CleanupCurrentScene(param_1, DAT_0073c954);

    // Reset scene context
    DAT_0073c954 = 0;

    // Step 2: Branch single-player vs multiplayer cleanup
    if (DAT_00702964 == 0)
    {
        // Single-player path
        DAT_00702bdd = 0;
        SPCleanup();
    }
    else
    {
        // Multiplayer path
        MPCleanup();
    }

    // Step 3: Reset game state flags
    DAT_00702b34 = 0;
    DAT_00702b30 = 0;
    DAT_00702b50 = 0;

    // Step 4: Type-specific scene object cleanup
    if (DAT_00702774 != 0)
    {
        int sceneType = *(int*)(DAT_00702774 + 0x22c);
        if (sceneType == 2)
        {
            MissionCleanup(DAT_00702774);
        }
        else if (sceneType == 3)
        {
            ReplaySpectatorCleanup(DAT_00702774);
        }
    }

    // Step 5: Game state cleanup
    if (DAT_006fef88 != 0)
    {
        FreeCommandList(reinterpret_cast<uint32_t*>(DAT_006fef88));
        DAT_006fef88 = 0;
        PopDialogLevel(0);
    }

    // Step 6: Render state reset
    PrimaryRenderReset();
    SecondaryRenderReset();

    // Set render state sentinel
    DAT_00682204 = -1;

    // Step 7: Final render cleanup based on scene flags
    if (DAT_00702770 != 0)
    {
        uint32_t sceneFlags = *(uint32_t*)(DAT_00702770 + 0x3c);

        if ((sceneFlags & 0x100) == 0)
        {
            // Full cleanup (flag 0x100 not set)
            FullRenderCleanup();
        }

        if ((sceneFlags & 0x100) != 0)
        {
            // Partial cleanup (flag 0x100 set)
            PartialRenderCleanup();
            ResetConsoleBuffers();
            return;
        }
    }
    else
    {
        // No scene object — fallback cleanup
        // FUN_00552990() — fallback render cleanup
    }

    // Step 8: Reset all console/network buffers
    ResetConsoleBuffers();
}

// ─── MPCleanup (FUN_00454bd0) ────────────────────────────────
// Ghidra: FUN_00454bd0 (3 callers, 2 callees)
// Purpose: Multiplayer session teardown via WinSock COM interface
// Original:
//   void FUN_00454bd0(void)
//   {
//       if ((DAT_006ff960 != 0) && (DAT_006ff9e4 != NULL)) {
//           if (DAT_00702964 != 0 && DAT_00702b50 == 0 &&
//               DAT_00702b54 == 0 && DAT_0073c92c != NULL)
//               (**(code**)(*DAT_0073c92c + 8))();       // vtable[2]: disconnect
//           (**(code**)(*DAT_006ff9e4 + 0x14))(DAT_006ff9e4, 0, 4);  // vtable[5]: close session
//           if (DAT_006ff9dc != NULL) {
//               (**(code**)(*DAT_006ff9dc + 8))(DAT_006ff9dc);  // vtable[2]: release addr
//               DAT_006ff9dc = NULL;
//           }
//           (**(code**)(*DAT_006ff9e4 + 0x5c))(DAT_006ff9e4, 0);  // vtable[23]: close player
//           (**(code**)(*DAT_006ff9e4 + 8))(DAT_006ff9e4);        // vtable[2]: release
//           DAT_006ff9e4 = NULL;
//           CoUninitialize();
//           memset(&DAT_006ff910, 0, 0x50);
//           // clear ~12 more global counters...
//           memset(&DAT_006fef90, 0, 0x50);
//           DAT_006ff558 = 0; DAT_006ff960 = 0; DAT_00702bcc = 0;
//           // clear 4 more counters at 0x6ff548-554
//           if (DAT_0073e77c != NULL) {
//               uint32_t* p = DAT_0073e77c;
//               DAT_0073e77c = NULL;
//               (**(code**)*p)(1);  // callback with param=1
//           }
//       }
//   }

void MPCleanup()
{
    if ((DAT_006ff960 != 0) && (DAT_006ff9e4 != nullptr))
    {
        // Disconnect from multiplayer session if conditions met
        if ((DAT_00702964 != 0) &&
            (DAT_00702b50_flag == 0) &&
            (DAT_00702b54 == 0) &&
            (DAT_0073c92c != nullptr))
        {
            // vtable[2] on DAT_0073c92c: disconnect callback
        }

        // vtable[5] on WinSock interface: close session with params (0, 4)
        // (**(code**)(*DAT_006ff9e4 + 0x14))(DAT_006ff9e4, 0, 4);

        // Release player address object
        if (DAT_006ff9dc != nullptr)
        {
            // vtable[2]: Release (DAT_006ff9dc)
            DAT_006ff9dc = nullptr;
        }

        // vtable[23]: close player (DAT_006ff9e4, 0)
        // vtable[2]: Release (DAT_006ff9e4)
        DAT_006ff9e4 = nullptr;

        // COM cleanup
        // CoUninitialize();

        // Clear network player slots (0x50 bytes each)
        std::memset(DAT_006ff910, 0, sizeof(DAT_006ff910));
        std::memset(DAT_006fef90, 0, sizeof(DAT_006fef90));

        // Clear network statistics
        DAT_006ff558 = 0;
        DAT_006ff960 = 0;
        DAT_00702bcc = 0;
        DAT_006ff548 = 0;
        DAT_006ff54c = 0;
        DAT_006ff550 = 0;
        DAT_006ff554 = 0;

        // Fire cleanup callback
        if (DAT_0073e77c != nullptr)
        {
            uint32_t* callback = DAT_0073e77c;
            DAT_0073e77c = nullptr;
            // Call through function pointer: callback(1)
            (void)callback;
        }
    }
}

// ─── SPCleanup (FUN_00454cf0) ────────────────────────────────
// Ghidra: FUN_00454cf0 (6 callers, 2 callees)
// Purpose: Single-player session teardown via DirectPlay COM interface
// Original:
//   void FUN_00454cf0(void)
//   {
//       uint32_t* p = DAT_0073e77c;
//       DAT_0073e77c = NULL;
//       if (p != NULL) (**(code**)*p)(1);
//       if ((DAT_006ff960 != 0) && (DAT_006ff9e0 != NULL)) {
//           (**(code**)(*DAT_006ff9e0 + 0x18))(DAT_006ff9e0, 0, 4);  // close session
//           if (DAT_006ff9d8 != NULL) { Release(DAT_006ff9d8); DAT_006ff9d8 = NULL; }
//           if (DAT_006ff9d4 != NULL) { Release(DAT_006ff9d4); DAT_006ff9d4 = NULL; }
//           (**(code**)(*DAT_006ff9e0 + 0x38))(DAT_006ff9e0, 0);  // close player
//           (**(code**)(*DAT_006ff9e0 + 8))(DAT_006ff9e0);        // release interface
//           DAT_006ff9e0 = NULL;
//           CoUninitialize();
//           memset(&DAT_006ff910, 0, 0x50);
//           // clear counters...
//           memset(&DAT_006fef90, 0, 0x50);
//           DAT_006ff558 = 0; DAT_00702bcc = 0; DAT_006ff960 = 0;
//       }
//   }

void SPCleanup()
{
    // Fire cleanup callback first (before COM teardown)
    if (DAT_0073e77c != nullptr)
    {
        uint32_t* callback = DAT_0073e77c;
        DAT_0073e77c = nullptr;
        // Call through function pointer: callback(1)
        (void)callback;
    }

    if ((DAT_006ff960 != 0) && (DAT_006ff9e0 != nullptr))
    {
        // vtable[6] on DirectPlay interface: close session with params (0, 4)
        // (**(code**)(*DAT_006ff9e0 + 0x18))(DAT_006ff9e0, 0, 4);

        // Release player address object
        if (DAT_006ff9d8 != nullptr)
        {
            // vtable[2]: Release
            DAT_006ff9d8 = nullptr;
        }

        // Release SP provider object
        if (DAT_006ff9d4 != nullptr)
        {
            // vtable[2]: Release
            DAT_006ff9d4 = nullptr;
        }

        // vtable[14]: close player (DAT_006ff9e0, 0)
        // vtable[2]: Release (DAT_006ff9e0)
        DAT_006ff9e0 = nullptr;

        // COM cleanup
        // CoUninitialize();

        // Clear network player slots
        std::memset(DAT_006ff910, 0, sizeof(DAT_006ff910));
        std::memset(DAT_006fef90, 0, sizeof(DAT_006fef90));

        // Clear network statistics
        DAT_006ff558 = 0;
        DAT_00702bcc = 0;
        DAT_006ff548 = 0;
        DAT_006ff54c = 0;
        DAT_006ff550 = 0;
        DAT_006ff554 = 0;
        DAT_006ff960 = 0;
    }
}

// ─── FullRenderCleanup (FUN_005c2040) ────────────────────────
// Ghidra: FUN_005c2040 (4 callers, 27 callees)
// Purpose: Complete render pipeline and scene object teardown.
// This is the largest cleanup function — iterates through the scene
// object linked list (DAT_00702790), freeing type-specific data for
// 17 different object types, then frees all GPU resources, textures,
// particle systems, and resets global state.
//
// Original: [large function — see ghidra_exports/ for full output]
// Key structure:
//   1. Reset render flags (DAT_00702a58, a3c, a40)
//   2. Clear texture array entries (0x725e14 to 0x725e8c)
//   3. Free DAT_0073f8b8 (texture buffer) and DAT_00725e98 (linked list node)
//   4. Call FUN_005c1ec0() (pre-cleanup)
//   5. Release renderer resources at DAT_00702770+0x4edc
//   6. Free type-specific data in scene object linked list for types:
//      3, 2, 0x85, 0x248, 0x270, 0x349, 0x34a, 0x34b, 0x3b, 0x3b5,
//      0x42e, 0x42f, 0x4aa, 0x4ab, 0x4ac, 0x4ad, 1
//   7. Call FUN_005c1fe0() (scene cleanup)
//   8. Free linked-list at DAT_0073c91c
//   9. Iterate DAT_007027a8 to free scene node buffers
//  10. Free object list DAT_007496c0/c4/c8 and DAT_0070280c-884
//  11. Free renderer allocations (textures, vertex buffers, etc.)
//  12. Free scene tile arrays and vertex data
//  13. Reset DAT_00702770 and DAT_00702774 to null

void FullRenderCleanup()
{
    // Reset render flags
    DAT_00702a58 = 0;
    DAT_00702a3c = 0;
    DAT_00702a40 = 0;

    // Clear texture array entries (loop from DAT_00725e14 to 0x725e8c, step 3 dwords)
    // Each iteration: clear two dwords, call FUN_004ea1b0()
    // Stub: texture array reset
    // ...

    // Free allocated texture buffer
    if (DAT_0073f8b8 != 0)
    {
        std::free(reinterpret_cast<void*>(DAT_0073f8b8));
        DAT_0073f8b8 = 0;
    }

    // Free linked list node at DAT_00725e98 (unlink from list then free)
    if (DAT_00725e98 != nullptr)
    {
        // Unlink: prev->next = self->next, next->prev = self->prev
        // Then reinit as self-referencing and free
        std::free(DAT_00725e98);
        DAT_00725e98 = nullptr;
    }

    // FUN_005c1ec0() — pre-cleanup helper

    // Release renderer resources if scene exists
    if (DAT_00702770 != 0)
    {
        // vtable[50](DAT_00702770 + 0x4edc): release render resources

        // Free allocated buffer at offset 0x4ee0 if owned
        uint32_t sceneBase = DAT_00702770;
        void* buffer = *reinterpret_cast<void**>(sceneBase + 0x4ee0);
        uint32_t flags = *reinterpret_cast<uint32_t*>(sceneBase + 0x4efc);
        if ((buffer != nullptr) && ((~flags & 1) == 0))
        {
            std::free(buffer);
            *reinterpret_cast<uint32_t*>(sceneBase + 0x4ee0) = 0;
            *reinterpret_cast<uint32_t*>(sceneBase + 0x4efc) &= 0xFFFFFFFE;
        }
    }

    // FUN_005f7fc0(1) — release render target

    // Free scene data at DAT_00725ed0
    // ...

    // Reset scene counters
    DAT_00725eae = 0;
    DAT_00725ea8 = 0;
    DAT_00725eac = 0;

    // FUN_004e1e60() — clear render state
    // FUN_004e8c30() — clear effect state

    // Clear render resource slots (loop DAT_0074992c to 0x74b4cc, step 0x374)
    // Each: if non-zero call FUN_0055cae0(), then set to 0

    // Free display config objects
    // ...

    // ── Free type-specific data in scene object linked list ──
    // Iterate DAT_00702790 linked list. For each node, scan its
    // sub-object array for specific type IDs and free their data
    // buffers at offset 0x118 (0x464 bytes per sub-object, stride 0x119).
    // Types processed (in order): 3, 2, 0x85, 0x248, 0x270, 0x349,
    //   0x34a, 0x34b, 0x3b, 0x3b5, 0x42e, 0x42f, 0x4aa, 0x4ab,
    //   0x4ac, 0x4ad, 1
    // Stub: the type-specific iteration loop is collapsed here
    // as it follows an identical pattern for all 17 types.

    // FUN_005c1fe0() — post-type-cleanup

    // Free linked-list at DAT_0073c91c
    // ...

    // Iterate DAT_007027a8, free scene node buffers for types 2 and 3
    // ...

    // Free object list at DAT_007496c0
    // ...

    // Free DAT_0070280c through 0x702884 array entries
    // ...

    // Free renderer allocations: textures, vertex buffers, etc.
    if (DAT_00702770 != 0)
    {
        // Free render targets at offsets 0x40, 0x44, 0x48, 0x4c
        // Free particle system arrays (offset 0x268, stride 0xc)
        // Free vertex data (offset 0xdc, 0xd4, 0xe4)
        // ...
    }

    // Free resource table entries
    // ...

    // Reset scene pointers
    DAT_00702770 = 0;
    DAT_00702774 = 0;

    // Free additional resource lists
    // ...

    // Reset subsystem flags
    // ...

    // Final cleanup calls
    // FUN_006259b0() and FUN_006259f0()
}

// ─── PrimaryRenderReset (FUN_00501340) ───────────────────────
// Ghidra: FUN_00501340 (2 callers, 1 callee)
// Purpose: Read game configuration from registry and update globals
// Original:
//   void FUN_00501340(void)
//   {
//       DWORD local_4;
//       if (DAT_0074be5c != NULL) {
//           local_4 = 4;
//           RegQueryValueExA(DAT_0074be5c, "PlayerTeam", 0, 0, &DAT_00702930, &local_4);
//       }
//       if ((DAT_00702b40 == 0) && (DAT_0074be5c != NULL)) {
//           local_4 = 4;
//           RegQueryValueExA(DAT_0074be5c, "GameTeam", 0, 0, &DAT_0070292c, &local_4);
//       }
//       if ((DAT_00702b30 == 0) && (DAT_0074be5c != NULL)) {
//           local_4 = 0x20;
//           RegQueryValueExA(DAT_0074be5c, "SessionName", 0, 0, &DAT_00702968, &local_4);
//       }
//       // ... continues with ~15 more RegQueryValueExA calls for
//       // GameType, GameBaseLevel, AllowJoiners, DamageTeammates,
//       // NoVimps, LockTeams, PointsPerKill, PointsPerCapture,
//       // CapturePreventTime, MaxPlayers, SmartieDifficulty,
//       // VimpMeatDifficulty, TimeLimit, PlayerScoreLimit,
//       // TeamScoreLimit, BaseComplete, Unavail1, Unavail2
//       //
//       // Then computes derived values:
//       // DAT_00702948 = (float)DAT_00702944 * DAT_0066c0ac;
//       // DAT_007029e0 = (0 < DAT_007029ec);
//       // DAT_00702a30 = (float)DAT_007029ec * DAT_0066c0ac;
//       // DAT_007029f0 = (0 < DAT_007029fc);
//       // DAT_00702a00 = (0 < DAT_00702a0c);
//   }

void PrimaryRenderReset()
{
    // Stub: Reads ~20 game configuration values from registry key DAT_0074be5c.
    // Each read follows the pattern:
    //   if (condition && DAT_0074be5c != NULL) {
    //       DWORD size = 4;
    //       RegQueryValueExA(DAT_0074be5c, "ValueName", 0, 0, &global, &size);
    //   }
    //
    // Values read (in order):
    //   "PlayerTeam"        -> DAT_00702930 (always)
    //   "GameTeam"          -> DAT_0070292c (if DAT_00702b40 == 0)
    //   "SessionName"       -> DAT_00702968 (if DAT_00702b30 == 0, 0x20 bytes)
    //   "GameType"          -> DAT_00702934 (if DAT_00702b48 == 0, then unconditionally)
    //   "GameBaseLevel"     -> DAT_00702928
    //   "AllowJoiners"      -> DAT_00702938
    //   "DamageTeammates"   -> DAT_00702939
    //   "NoVimps"           -> DAT_0070295c
    //   "LockTeams"         -> DAT_00702950
    //   "PointsPerKill"     -> DAT_0070293c
    //   "PointsPerCapture"  -> DAT_00702940
    //   "CapturePreventTime"-> DAT_00702944
    //   "MaxPlayers"        -> DAT_0070294c (if DAT_00702b44 == 0)
    //   "SmartieDifficulty" -> DAT_00702954
    //   "VimpMeatDifficulty"-> DAT_00702958
    //   "TimeLimit"         -> DAT_007029ec
    //   "PlayerScoreLimit"  -> DAT_007029fc
    //   "TeamScoreLimit"    -> DAT_00702a0c
    //   "BaseComplete"      -> DAT_00702a10
    //   "Unavail1"          -> DAT_00702af0
    //   "Unavail2"          -> DAT_00702af4
    //
    // Derived values computed:
    //   DAT_00702948 = (float)CapturePreventTime * DAT_0066c0ac
    //   DAT_007029e0 = (TimeLimit > 0) ? 1 : 0
    //   DAT_00702a30 = (float)TimeLimit * DAT_0066c0ac
    //   DAT_007029f0 = (PlayerScoreLimit > 0) ? 1 : 0
    //   DAT_00702a00 = (TeamScoreLimit > 0) ? 1 : 0
}

// ─── PartialRenderCleanup (FUN_00501a20) ─────────────────────
// Ghidra: FUN_00501a20 (11 callers, 3 callees)
// Purpose: Conditional render cleanup based on game state flags
// Original:
//   void FUN_00501a20(void)
//   {
//       if (DAT_00702b30 == 0 && DAT_00702b34 == 0 &&
//           DAT_00702b50 == 0 && DAT_00702be8 == 0) {
//           FUN_00541a50();  // lightweight cleanup
//           return;
//       }
//       FUN_004b4130();      // begin cleanup sequence
//       if (DAT_00702b30 != 0) { FUN_00501ab0(); return; }
//       if (DAT_00702b34 != 0) { FUN_00501ab0(); return; }
//       FUN_00501ab0();      // always call increment cleanup
//   }

void PartialRenderCleanup()
{
    // If all game state flags are clear, do lightweight cleanup
    if ((DAT_00702b30 == 0) && (DAT_00702b34 == 0) &&
        (DAT_00702b50 == 0) && (DAT_00702be8 == 0))
    {
        // FUN_00541a50() — lightweight render cleanup
        return;
    }

    // FUN_004b4130() — begin incremental cleanup sequence

    // Dispatch based on which flags are set (all paths call FUN_00501ab0)
    if (DAT_00702b30 != 0)
    {
        // FUN_00501ab0() — incremental render cleanup
        return;
    }
    if (DAT_00702b34 != 0)
    {
        // FUN_00501ab0() — incremental render cleanup
        return;
    }

    // Default: always call incremental cleanup
    // FUN_00501ab0()
}

// ─── MissionCleanup (FUN_0053b1d0) ───────────────────────────
// Ghidra: FUN_0053b1d0 (10 callers, 4 callees)
// Purpose: Clean up mission-specific game objects (scene type == 2)
// Original:
//   void __fastcall FUN_0053b1d0(int param_1)
//   {
//       int iVar5 = (param_1 != 0) ? *(int*)(param_1 + 0x14c) : 0;
//       // Release sound source at +0x188
//       if (*(int*)(iVar5 + 0x188) != 0) {
//           if (DAT_006ff960 == 6 && FUN_0045f460() != 0)
//               FUN_00469de0(0, 0, 0x18, 0, 0);  // network sound stop
//           FUN_004ea1b0();  // release sound
//       }
//       FUN_004ea1b0(); FUN_004ea1b0(); FUN_004ea1b0();  // release 3 more sounds
//       // Release entity at +0x1f8 from linked list DAT_007496c4
//       if (*(int*)(iVar5 + 0x1f8) != 0) { ... FUN_005584d0(); ... }
//       // Release entity at +0x1dc
//       // Release scene node at +0x1d8 (walk linked list to tail, call DAT_007280a0)
//       // Release scene node at +0x1d4 (same pattern)
//       // Release entity at +0x1e4
//       // Release entity at +0x1e0
//   }

void MissionCleanup(int param_1)
{
    // Get mission data pointer from scene object
    int missionData = (param_1 != 0) ? *(int*)(param_1 + 0x14c) : 0;

    // Release sound source at offset 0x188
    if (*(int*)(missionData + 0x188) != 0)
    {
        // If in debug mode (state 6) and network active: send stop sound command
        if (DAT_006ff960 == 6)
        {
            // FUN_00469de0(0, 0, 0x18, 0, 0) — network sound stop
        }
        // FUN_004ea1b0() — release sound source
    }

    // Release 3 more sound sources (always called)
    // FUN_004ea1b0() x 3

    // Release entity at offset 0x1f8 from object linked list (DAT_007496c4)
    if (*(int*)(missionData + 0x1f8) != 0)
    {
        if (DAT_006ff960 == 6)
        {
            // FUN_00469de0(0, 0, 0x1c, 0, 0) — network sound stop
        }
        // Walk DAT_007496c4 linked list, find matching entity at [0x11]
        // FUN_005584d0() — release entity
        *(uint32_t*)(missionData + 0x1f8) = 0;
    }

    // Release entity at offset 0x1dc (search DAT_007496c4 for match)
    if (*(int*)(missionData + 0x1dc) != 0)
    {
        // Walk linked list, find match at [0x11], call FUN_005584d0()
        *(uint32_t*)(missionData + 0x1dc) = 0;
    }

    // Release scene node at offset 0x1d8
    // Walk param_1+0x264 linked list to tail, then call through
    // DAT_007280a0 function pointer with (DAT_00702800+0xeff0, tailNode)
    if (*(int*)(missionData + 0x1d8) != 0)
    {
        if (param_1 != 0)
        {
            // Walk linked list at param_1+0x264 to find tail node
            // Then: (*DAT_007280a0)(DAT_00702800 + 0xeff0, tailNode)
        }
        *(uint32_t*)(missionData + 0x1d8) = 0;
    }

    // Release scene node at offset 0x1d4 (same pattern, different base: +0xf85c)
    if (*(int*)(missionData + 0x1d4) != 0)
    {
        if (param_1 != 0)
        {
            // Walk linked list to tail, call (*DAT_007280a0)(DAT_00702800 + 0xf85c, tailNode)
        }
        *(uint32_t*)(missionData + 0x1d4) = 0;
    }

    // Release entity at offset 0x1e4 (search DAT_007496c4)
    if (*(int*)(missionData + 0x1e4) != 0)
    {
        // Walk linked list, find match, call FUN_005584d0()
        *(uint32_t*)(missionData + 0x1e4) = 0;
    }

    // Release entity at offset 0x1e0 (search DAT_007496c4)
    if (*(int*)(missionData + 0x1e0) != 0)
    {
        // Walk linked list, find match, call FUN_005584d0()
        *(uint32_t*)(missionData + 0x1e0) = 0;
    }
}

// ─── ReplaySpectatorCleanup (FUN_00590950) ───────────────────
// Ghidra: FUN_00590950 (8 callers, 2 callees)
// Purpose: Clean up replay/spectator mode objects (scene type == 3)
// Original:
//   void __fastcall FUN_00590950(int param_1)
//   {
//       int iVar4 = (param_1 != 0) ? *(int*)(param_1 + 0x14c) : 0;
//       FUN_005908e0();  // replay-specific cleanup
//       // Release entity at +0xfa8 from DAT_007496c4
//       if (*(int*)(iVar4 + 0xfa8) != 0) {
//           for (p = DAT_007496c4; p; p = *p)
//               if (p[0x11] == *(int*)(iVar4 + 0xfa8)) { FUN_005583d0(); break; }
//           *(undefined4*)(iVar4 + 0xfa8) = 0;
//       }
//       // Release entity at +0xfac (same pattern)
//       // Release scene node at +0xfb0 (walk to tail, call DAT_007280a0)
//   }

void ReplaySpectatorCleanup(int param_1)
{
    // Get replay data pointer from scene object
    int replayData = (param_1 != 0) ? *(int*)(param_1 + 0x14c) : 0;

    // FUN_005908e0() — replay-specific cleanup

    // Release entity at offset 0xfa8 from object linked list (DAT_007496c4)
    if (*(int*)(replayData + 0xfa8) != 0)
    {
        // Walk DAT_007496c4 linked list, find matching entity at [0x11]
        // FUN_005583d0() — release replay entity
        *(uint32_t*)(replayData + 0xfa8) = 0;
    }

    // Release entity at offset 0xfac (same pattern)
    if (*(int*)(replayData + 0xfac) != 0)
    {
        // Walk linked list, find match, call FUN_005583d0()
        *(uint32_t*)(replayData + 0xfac) = 0;
    }

    // Release scene node at offset 0xfb0
    if (*(int*)(replayData + 0xfb0) != 0)
    {
        if (param_1 != 0)
        {
            // Walk param_1+0x264 linked list to tail
            // Then: (*DAT_007280a0)(DAT_00702800 + 0x9690, tailNode)
        }
        *(uint32_t*)(replayData + 0xfb0) = 0;
    }
}

// ─── SecondaryRenderReset (FUN_005dd760) ─────────────────────
// Ghidra: FUN_005dd760 (2 callers, 5 callees)
// Purpose: Secondary render subsystem reset — check active subsystem
// flags and invoke cleanup on each, plus iterate scene objects for
// type-0x2c cleanup
// Original:
//   void FUN_005dd760(void)
//   {
//       if (DAT_007488e0 != 0) FUN_00563520();     // audio cleanup
//       if (DAT_007488d8 != 0) FUN_004a4b40();     // effects cleanup
//       if (DAT_007488dc != 0) FUN_004fccc0();     // particle cleanup
//       if (DAT_007488d4 != 0) {
//           // iterate DAT_007027ac linked list
//           for (p = DAT_007027ac; p; p = *p)
//               if (*(int*)(p[3]+0x22c) == 0x2c &&
//                   *(int*)(*(int*)(p[3]+0x14c)+8) == DAT_00702774)
//                   FUN_005eddc0();  // collision cleanup
//       }
//       if (DAT_007488d0 != 0) FUN_0052e310();     // misc cleanup
//   }

void SecondaryRenderReset()
{
    // Subsystem cleanup based on active flags
    if (DAT_007488e0 != 0)
    {
        // FUN_00563520() — audio subsystem cleanup
    }
    if (DAT_007488d8 != 0)
    {
        // FUN_004a4b40() — effects subsystem cleanup
    }
    if (DAT_007488dc != 0)
    {
        // FUN_004fccc0() — particle subsystem cleanup
    }

    // Collision object cleanup: iterate scene object linked list
    if (DAT_007488d4 != 0)
    {
        uint32_t* node = DAT_007027ac;
        if (DAT_00702774 != 0)
        {
            while (node != nullptr)
            {
                int objType = *(int*)(node[3] + 0x22c);
                int objOwner = *(int*)(*(int*)(node[3] + 0x14c) + 8);
                if ((objType == 0x2c) && (objOwner == (int)DAT_00702774))
                {
                    // FUN_005eddc0() — collision object cleanup
                }
                node = reinterpret_cast<uint32_t*>(*node);
            }
        }
    }

    if (DAT_007488d0 != 0)
    {
        // FUN_0052e310() — misc subsystem cleanup
    }
}

// ─── PopDialogLevel (FUN_004d1070) ───────────────────────────
// Ghidra: FUN_004d1070 (69 callers, 2 callees)
// Purpose: Pop a level from the dialog/UI stack, validate underflow
// Original:
//   void __fastcall FUN_004d1070(int param_1)
//   {
//       if (DAT_00682204 < 0) {
//           FUN_00461e70("Underflow of dialog level stack", 0x1f);
//           DAT_00682204 = 0;
//       } else if (DAT_00747b60[DAT_00682204 * 6] != param_1) {
//           FUN_00461e70("Pop mismatch", 0xc);
//           return;
//       }
//       DAT_00682204--;
//       if (DAT_00682204 < 0) FUN_00629e90();  // stack empty handler
//       // Copy display config from DAT_0066c4b0 to DAT_006818b8
//       // Copy display config from DAT_0066c4b0 to DAT_006818c8
//       PTR_DAT_00685890 = &DAT_006818b8;
//       DAT_0074be50 = 0;  // clear registry key ref
//   }

void PopDialogLevel(int param_1)
{
    // Validate stack state
    if (DAT_00682204 < 0)
    {
        // FUN_00461e70("Underflow of dialog level stack", 31)
        DAT_00682204 = 0;
    }
    else if (DAT_00747b60[DAT_00682204 * 6] != (uint32_t)param_1)
    {
        // FUN_00461e70("Pop mismatch", 12)
        return;
    }

    // Decrement dialog stack depth
    DAT_00682204--;

    // Handle empty stack
    if (DAT_00682204 < 0)
    {
        // FUN_00629e90() — empty stack handler
    }

    // Restore display configuration from constants
    DAT_006818b8 = DAT_0066c4b0;
    DAT_006818c8 = DAT_0066c4b0;
    // (plus 3 more DWORDs per config block)
    PTR_DAT_00685890 = &DAT_006818b8;

    // Clear registry key reference
    DAT_0074be50 = 0;
}

// ─── FreeCommandList (FUN_004d39d0) ──────────────────────────
// Ghidra: FUN_004d39d0 (16 callers, 1 callee)
// Purpose: Free a linked list of command/message nodes with type-specific payloads
// Original:
//   void __fastcall FUN_004d39d0(uint32_t* param_1)
//   {
//       uint32_t* node = *param_1;
//       do {
//           if (node == NULL) { free(param_1); return; }
//           int type = node[1];
//           uint32_t* next = *node;
//           if (type == 3) {            // sub-list: free entire chain
//               uint32_t* sub = node[10];
//               while (sub) { uint32_t* n = *sub; free(sub); sub = n; }
//           } else if (type == 0) {     // string: free if owned
//               if (node[3] & 1) free(node[10]);
//           } else if (type == 2) {     // extra data: free if owned
//               if (node[3] & 1) free(node[11]);
//           }
//           free(node);
//           node = next;
//       } while (true);
//   }

void FreeCommandList(uint32_t* param_1)
{
    uint32_t* node = reinterpret_cast<uint32_t*>(*param_1);

    do
    {
        if (node == nullptr)
        {
            std::free(param_1);
            return;
        }

        int type = node[1];
        uint32_t* next = reinterpret_cast<uint32_t*>(*node);

        if (type == 3)
        {
            // Sub-list type: free entire sub-chain
            uint32_t* sub = reinterpret_cast<uint32_t*>(node[10]);
            while (sub != nullptr)
            {
                uint32_t* nextSub = reinterpret_cast<uint32_t*>(*sub);
                std::free(sub);
                sub = nextSub;
            }
        }
        else if (type == 0)
        {
            // String type: free string data if ownership flag set
            if ((node[3] & 1) != 0)
            {
                std::free(reinterpret_cast<void*>(node[10]));
            }
        }
        else if (type == 2)
        {
            // Extra data type: free data if ownership flag set
            if ((node[3] & 1) != 0)
            {
                std::free(reinterpret_cast<void*>(node[11]));
            }
        }

        std::free(node);
        node = next;
    } while (true);
}

// ─── CleanupCurrentScene (FUN_005e9ff0) ──────────────────────
// Ghidra: FUN_005e9ff0 (6 callers, 1 callee)
// Purpose: Deallocate a 2D grid of scene tile objects
// Original:
//   void __fastcall FUN_005e9ff0(int param_1, int param_2)
//   {
//       int tileW = (**(code**)(*DAT_00702700 + 0xd4))(3);  // renderer query: tile width
//       int tileH = (**(code**)(*DAT_00702700 + 0xd4))(4);  // renderer query: tile height
//       if (tileW > 0x80) tileW = 0x80;
//       if (tileH > 0x80) tileH = 0x80;
//       if (gridPtr != NULL) {
//           int cols = (param_1 - 1 + tileW) / tileW;
//           int rows = (param_2 - 1 + tileH) / tileH;
//           if (rows > 0) {
//               uint32_t* rowPtr = gridPtr + 1;
//               do {
//                   uint32_t* p = rowPtr;
//                   int c = cols;
//                   if (cols > 0) {
//                       do {
//                           (**(code**)(*DAT_00702700 + 200))(p - 1);  // vtable[50]: destructor
//                           free(*p);                                     // free tile data
//                           *p = 0;
//                           c--; p += 0xb;                                // stride = 11 dwords
//                       } while (c != 0);
//                   }
//                   rowPtr += cols * 0xb;
//                   rows--;
//               } while (rows != 0);
//           }
//           free(gridPtr);
//       }
//   }

void CleanupCurrentScene(int param_1, int param_2)
{
    // Query renderer for tile dimensions via vtable[53]
    // int tileW = renderer->Query(3);
    // int tileH = renderer->Query(4);
    int tileW = 0x80;  // stub: max tile width
    int tileH = 0x80;  // stub: max tile height

    // Clamp tile dimensions
    if (tileW > 0x80) tileW = 0x80;
    if (tileH > 0x80) tileH = 0x80;

    // Get the grid allocation (from unaff_retaddr in Ghidra —
    // this is actually passed implicitly or from a global)
    void* gridPtr = nullptr;  // stub: grid pointer from caller context

    if (gridPtr != nullptr)
    {
        // Compute grid dimensions
        int cols = (param_1 - 1 + tileW) / tileW;
        int rows = (param_2 - 1 + tileH) / tileH;

        if (rows > 0)
        {
            uint32_t* rowPtr = static_cast<uint32_t*>(gridPtr) + 1;
            do
            {
                uint32_t* p = rowPtr;
                int c = cols;
                if (c > 0)
                {
                    do
                    {
                        // vtable[50](p - 1): renderer destructor for tile
                        // (**(code**)(*DAT_00702700 + 200))(p - 1);

                        // Free tile data
                        std::free(reinterpret_cast<void*>(*p));
                        *p = 0;

                        c--;
                        p += 0xb;  // stride: 11 dwords (44 bytes) per tile entry
                    } while (c != 0);
                }

                rowPtr += cols * 0xb;
                rows--;
            } while (rows != 0);
        }

        std::free(gridPtr);
    }
}

} // namespace Giants
