// Giants Engine - System Initialization & GPU Capabilities Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include <cstdlib>
#include <cstring>
#include "SystemInit.h"
#include "SceneSubsystem.h"
#include <cstring>

namespace Giants {

// ─── External data references ─────────────────────────────────

// FLICK/scene system state
static uint32_t DAT_00747d2c = 0;              // FLICK system active flag
static int      DAT_00682264 = 0;              // Initialization state (0 = pending)

// Object linked list (for callback dispatch)
static uint32_t DAT_007027a8 = 0;              // Head of linked object list

// Callback dispatch table: 108 entries of 0x50 bytes each
// Indexed by object type (offset 0x22c in each object)
// DAT_00682ee4 is the base of the function pointer table
static uint32_t DAT_00682ee4[108] = {0};       // Callback table (108 * 0x50 = 0x21C0 bytes)

// Post-init callback function pointers
static uint32_t DAT_00728024 = 0;              // Post-init callback 1
static uint32_t DAT_00728028 = 0;              // Post-init callback 2
static uint32_t DAT_0072802c = 0;              // Post-init callback 3

// World state reset values
static uint32_t DAT_00747d18 = 0;              // World timer A
static uint32_t DAT_00747d08 = 0;              // World timer B (_DAT prefix)
static uint32_t DAT_00747d10 = 0;              // World timer C (_DAT prefix)
static float    DAT_00747d1c = 0.039999999f;   // Near plane default (0x3d23d70a)
static float    DAT_00747d20 = 5.0f;           // Far plane default (0x40a00000)
static uint32_t DAT_00747d24 = 0;              // World state flags

// World data buffer (cleared on init)
// DAT_0074b830, 0x230 bytes
static uint8_t  g_worldData[0x230] = {0};      // DAT_0074b830
static uint32_t DAT_0074b82c = 1;              // World data valid flag

// Scene loading functions (from SceneSubsystem.h)
// ResetWorldState = FUN_005de9b0
// InitSceneSubsystem = FUN_004e94b0
// InitRenderTarget = FUN_004f3c80

extern int  ValidateScenePath();                // FUN_004e5030
extern void CopyScenePath(char* dst, const char* src);  // Inline string copy
extern void LoadScene(const char* path);        // FUN_004e4d40
extern int  PerformSceneInit(const char* path); // FUN_004e5150

// Renderer device vtable
static uint32_t DAT_00702700 = 0;              // D3D device

// ─── Render capability flags ──────────────────────────────────
static uint32_t DAT_007028b0 = 0;              // GPU capability bits
static uint32_t DAT_00702bd0 = 0;              // Force software flag
static uint32_t DAT_00702be4 = 0;              // Max supported feature level
static uint32_t DAT_00702b5c = 0;              // Stencil buffer support
static uint32_t DAT_00702b64 = 0;              // Depth bias mode
static uint8_t  DAT_00702b5e = 0;              // Clip plane support
static uint32_t DAT_00702b6c = 0;              // Shadow filter quality
static uint32_t DAT_00702afc = 0;              // Render path index
static uint32_t DAT_00702b18 = 0;              // MSAA mode
static uint32_t DAT_00702b24 = 0;              // Anisotropic filter level
static uint32_t DAT_00702b70 = 0;              // HDR flag
static float    DAT_00702b74 = 0;              // Bloom intensity

// Render context
static uint32_t DAT_00702770 = 0;              // Render context / scene object

// External capability query helpers
extern void QueryShaderCaps();                  // FUN_004dff90
extern void QueryTextureCaps();                 // FUN_004dfe20

// ─── WaitForInit (FUN_004e8c30) — PASS ─────────────────────────

void WaitForInit()
{
    // Only block if the FLICK system is active
    if (DAT_00747d2c == 0) {
        return;
    }

    // Spin until PerformInitialization returns non-zero
    // FUN_004e8dd0 performs the actual initialization work
    while (DAT_00682264 == 0) {
        DAT_00682264 = 1;
        DAT_00682264 = PerformSceneInit(nullptr);  // FUN_004e8dd0
    }
}

// ─── SystemInit (FUN_004e8c70) — PASS ──────────────────────────

int SystemInit(const char* scenePath)
{
    // Step 1: Wait for async initialization to complete
    WaitForInit();

    int result = DAT_00682264;

    // Step 2: Dispatch callbacks to all registered objects
    // Only when FLICK system has been initialized (DAT_00747d2c == 0)
    if (DAT_00747d2c == 0 && DAT_007027a8 != 0) {
        uint32_t* node = (uint32_t*)DAT_007027a8;

        // Walk linked list: node[0] = next, node[3] = object pointer
        while (node != nullptr) {
            uint32_t obj = node[3];              // Object at offset 0xC in list node
            int objType = *(int*)(obj + 0x22c);  // Object type at offset 0x22c

            // Dispatch if type index is valid (< 108 = 0x6c)
            // and the callback table has a handler for this type
            if (objType < 0x6c) {
                uint32_t handlerAddr = DAT_00682ee4[objType];
                if (handlerAddr != 0) {
                    // Call the type-specific initialization handler
                    typedef void(__cdecl* InitHandler)(uint32_t);
                    ((InitHandler)handlerAddr)(obj);
                }
            }
            node = (uint32_t*)node[0];          // Next node
        }

        // Step 3: Invoke post-initialization callbacks
        if (DAT_00728024 != 0) {
            ((void(*)())DAT_00728024)();
        }
        if (DAT_0072802c != 0) {
            ((void(*)())DAT_0072802c)();
        }
        if (DAT_00728028 != 0) {
            ((void(*)())DAT_00728028)();
        }

        // Step 4: Reset world state
        DAT_00747d18 = 0;
        DAT_00747d08 = 0;
        DAT_00747d10 = 0;
        DAT_00747d1c = 0.039999999f;           // Near plane: 0x3d23d70a
        DAT_00747d20 = 5.0f;                    // Far plane: 0x40a00000
        DAT_00747d24 = 0;

        // Reset world state and clear world data buffer
        ResetWorldState((int*)nullptr);  // TODO: pass real state block                       // FUN_005de9b0
        memset(g_worldData, 0, sizeof(g_worldData));  // DAT_0074b830, 0x230 bytes
        DAT_0074b82c = 1;                       // Mark world data as valid

        // Initialize scene subsystem
        InitSceneSubsystem();                    // FUN_004e94b0

        // Step 5: Load the scene file
        result = ValidateScenePath();            // FUN_004e5030
        if (result != 0) {
            // Copy scene path to internal buffer
            // Ghidra shows an inline string copy to offset 0x747c87 relative to param_1
            // This copies scenePath to a global buffer at DAT_00747c87
            const char* src = scenePath;
            char* dst = (char*)(0x747c87);       // Ghidra: pcVar4[0x747c87 - (int)param_1] = cVar1

            // Simple strcpy equivalent
            char c;
            do {
                c = *src;
                src++;
                *dst = c;
                dst++;
            } while (c != '\0');

            // Load scene data
            LoadScene(scenePath);                // FUN_004e4d40

            // Perform full scene initialization
            DAT_00747d2c = PerformSceneInit(scenePath);  // FUN_004e5150
            if (DAT_00747d2c != 0) {
                DAT_00682264 = 0;               // Mark as initialized
            }
        }

        result = DAT_00682264;

        // Step 6: Initialize render target if fixed timestep mode
        // DAT_00702be8 = g_isFixedTimestep
        // (referenced in GiantsTypes.h)
        extern uint8_t g_isFixedTimestep;
        if (g_isFixedTimestep != 0) {
            InitRenderTarget();                  // FUN_004f3c80
        }
    }

    return result;
}

// ─── QueryRenderCapabilities (FUN_004f8550) — PASS ─────────────

void QueryRenderCapabilities()
{
    // Query GPU capabilities via renderer vtable[0xd4] (GetDeviceCaps)
    // Parameter 7 = D3DDEVTYPE_HAL (hardware rasterization)
    if (DAT_00702700 != 0) {
        uint32_t** device = (uint32_t**)DAT_00702700;
        typedef uint32_t(__thiscall* GetCapsFn)(uint32_t, uint32_t);
        GetCapsFn fn = (GetCapsFn)(*device)[0xd4 / 4];
        DAT_007028b0 = fn((uint32_t)device, 7);
    }

    // ── Configure stencil buffer support ──
    // If not forcing software AND caps indicate stencil (bit 2)
    // AND feature level > 3, enable stencil
    if (DAT_00702bd0 == 0 && (DAT_007028b0 & 2) != 0) {
        if (1 < (int)(DAT_00702be4 - 3U)) {
            DAT_00702b5c = 1;                   // Enable stencil
        } else {
            DAT_00702b5c = 0;                   // Disable stencil
        }
    } else {
        DAT_00702b5c = 1;                       // Default: stencil enabled
    }

    // ── Configure depth bias mode ──
    // If caps have both bit 2 and bit 0x8000, set depth bias = 2
    if (DAT_00702bd0 == 0 && (DAT_007028b0 & 2) != 0) {
        if ((DAT_007028b0 & 0x8000) != 0) {
            DAT_00702b64 = 2;                   // Slope-scale depth bias
        } else {
            DAT_00702b64 = 0;                   // No depth bias
        }
    }

    // ── Initialize render context capabilities ──
    if (DAT_00702770 != 0) {
        QueryShaderCaps();                       // FUN_004dff90
        QueryTextureCaps();                      // FUN_004dfe20
        *(uint8_t*)(DAT_00702770 + 0x503a) = 1; // Mark caps as queried
    }

    // ── Configure clip plane support ──
    if (DAT_00702b5e != '\0') {
        // Check for clip plane caps (bit 4 + bit 0x4000)
        if (DAT_00702bd0 == 0 &&
            (DAT_007028b0 & 4) != 0 &&
            (DAT_007028b0 & 0x4000) != 0)
        {
            DAT_00702b5e = 1;                   // Enable clip planes
            goto check_software;
        }

        DAT_00702b5e = 0;                       // Disable clip planes

        // Clear clip plane flag in render context
        if (DAT_00702770 != 0) {
            uint32_t flags = *(uint32_t*)(DAT_00702770 + 0x4efc);
            *(uint32_t*)(DAT_00702770 + 0x4efc) = flags & 0xffffbfff;
        }

    check_software:

        // ── Software rendering fallback ──
        if (DAT_00702bd0 == 0) {
            // Hardware path: check for high-quality shadow caps
            if ((DAT_007028b0 & 0x40) != 0 && (DAT_007028b0 & 0x4000) != 0) {
                DAT_00702b6c = 2;               // High-quality shadow filter
                goto configure_defaults;
            }
        }

        DAT_00702b6c = 0;                       // No shadow filter

        // Software fallback: set fixed render path parameters
        if (DAT_00702bd0 != 0) {
            DAT_00702afc = 2;                   // Render path: deferred
            DAT_00702b18 = 1;                   // MSAA: off
            DAT_00702b24 = 3;                   // Aniso: 8x
            DAT_00702b6c = 0;                   // No shadow filter
            DAT_00702b70 = 0;                   // No HDR
            DAT_00702b74 = 1.0f;                // Bloom: default
            return;
        }

    configure_defaults:
        // ── Final capability configuration ──
        // Check for advanced shadow + HDR caps
        if ((DAT_007028b0 & 0x4000) != 0 && (DAT_007028b0 & 0x40000) != 0) {
            DAT_00702afc = 2;                   // Render path: deferred
            DAT_00702b18 = 2;                   // MSAA: 2x
            DAT_00702b24 = 3;                   // Aniso: 8x
            DAT_00702b70 = 0;                   // No HDR
            DAT_00702b74 = 1.0f;                // Bloom: default
            return;
        }

        // Default hardware path
        DAT_00702b18 = 1;                       // MSAA: off
        DAT_00702b70 = 0;                       // No HDR
        DAT_00702afc = 2;                       // Render path: deferred
        DAT_00702b24 = 3;                       // Aniso: 8x
        DAT_00702b74 = 1.0f;                    // Bloom: default
        return;
    }

    // Fallback when clip plane flag is already 0
    if (DAT_00702bd0 == 0) {
        // Same hardware checks as above
        if ((DAT_007028b0 & 0x40) != 0 && (DAT_007028b0 & 0x4000) != 0) {
            DAT_00702b6c = 2;
            goto configure_defaults;
        }
    }

    DAT_00702b6c = 0;

    if (DAT_00702bd0 != 0) {
        DAT_00702afc = 2;
        DAT_00702b18 = 1;
        DAT_00702b24 = 3;
        DAT_00702b6c = 0;
        DAT_00702b70 = 0;
        DAT_00702b74 = 1.0f;
        return;
    }

    if ((DAT_007028b0 & 0x4000) != 0 && (DAT_007028b0 & 0x40000) != 0) {
        DAT_00702afc = 2;
        DAT_00702b18 = 2;
        DAT_00702b24 = 3;
        DAT_00702b70 = 0;
        DAT_00702b74 = 1.0f;
        return;
    }

    DAT_00702b18 = 1;
    DAT_00702b70 = 0;
    DAT_00702afc = 2;
    DAT_00702b24 = 3;
    DAT_00702b74 = 1.0f;
}

} // namespace Giants
