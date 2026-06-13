// Giants Engine - Shader Initialization Functions Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// Decompiled from Ghidra level4 exports

#include "ShaderInit.h"
#include <cstdlib>
#include <cstring>
#include <cstdint>

namespace Giants {

// ============================================================================
// Static globals (DAT_ references from .data/.bss sections)
// ============================================================================

// DAT_00701a3c — global entity data base pointer
static uint32_t DAT_00701a3c = 0;

// DAT_0066bec4 — light interpolation factor 1 (float, runtime)
static float DAT_0066bec4 = 0.0f;

// DAT_0066be4c — light interpolation factor 2 (float, runtime)
static float DAT_0066be4c = 0.0f;

// DAT_0066bdf4 — light interpolation factor 3 (float, runtime)
static float DAT_0066bdf4 = 0.0f;

// DAT_00702770 — renderer state pointer
static uint32_t DAT_00702770 = 0;

// DAT_00702700 — renderer interface pointer
static uint32_t DAT_00702700 = 0;

// DAT_0067d280 — security cookie
static uint32_t DAT_0067d280 = 0;

// DAT_0067d260 — shader iteration context
static uint32_t DAT_0067d260 = 0;

// PTR_FUN_0067d264 — shader iteration callback pointer
static void (*PTR_FUN_0067d264)() = nullptr;

// Vtable pointers (resolved at runtime)
static void* PTR_LAB_0066a490 = nullptr;  // FrameConstants vtable
static void* PTR_LAB_0066a484 = nullptr;  // ScreenSpace vtable (initial)
static void* PTR_LAB_0066a498 = nullptr;  // ObjectConstants vtable
static void* PTR_LAB_0066a5a8 = nullptr;  // ScreenSpace sub-object vtable
static void* PTR_LAB_0066a5b0 = nullptr;  // ScreenSpace vtable (final)
static void* PTR_LAB_0066a5bc = nullptr;  // ScreenSpace sub-object vtable (final)

// ============================================================================
// External function stubs (referenced by decompiled code, defined elsewhere)
// ============================================================================
extern "C" {
    void* operator_new(size_t size);
    void  _invoke_watson(void*, void*, void*, int, int);
}

// Internal helper stubs
extern void  FUN_00643505(void* ptr, uint32_t size);    // Safe buffer deallocation
extern void* FUN_0064356b(uint32_t size);                // Safe allocation (malloc wrapper)
extern void  FUN_00640170(int* context);                 // Shader resource initializer
extern void  FUN_00640400(uint32_t table, uint32_t* ctx, uint32_t param3); // Shader table setup
extern uint32_t FUN_00640590(uint32_t table, int index, int unused); // Resource accessor
extern void  FUN_00640b10();  // Default iteration callback
extern void  FUN_00640c90();  // Alternate iteration callback
extern void  FUN_004df880();  // Frame constants sub-init

// ============================================================================
// Helper: IEEE 754 float constants
// ============================================================================
static constexpr uint32_t F32_1_0 = 0x3F800000;  // 1.0f
static constexpr uint32_t F32_0_5 = 0x3F000000;  // 0.5f

// ============================================================================
// ShaderConstantInit (FUN_00483180) - FAIL
// Sets 150+ float constants (ambient, diffuse, specular, fog, attenuation,
// light parameters) on entity shader data structure.
//
// Raw decompilation:
//   void __fastcall FUN_00483180(int param_1)
//   Callers: FUN_00471ba0, FUN_00472070
//   Callees: 0
// ============================================================================
void ShaderConstantInit(int entityPtr)
{
    // 0x00483180
    if (entityPtr == 0) {
        entityPtr = DAT_00701a3c + 0x1518;
    }
    uint32_t* data = reinterpret_cast<uint32_t*>(entityPtr);
    float* fdata = reinterpret_cast<float*>(data);

    // --- Ambient color (RGBA) ---
    data[0x31] = F32_1_0;   // +0xC4  ambient R
    data[0x32] = F32_1_0;   // +0xC8  ambient G  (offset 200)
    data[0x33] = F32_1_0;   // +0xCC  ambient B
    data[0x34] = F32_1_0;   // +0xD0  ambient A

    // --- Diffuse color ---
    data[0x35] = F32_0_5;     // +0xD4  diffuse R
    data[0x36] = F32_0_5;     // +0xD8  diffuse G
    data[0x37] = F32_0_5;     // +0xDC  diffuse B

    // --- Specular ---
    data[0x38] = F32_1_0;     // +0xE0  specular

    // --- Emissive / shininess ---
    data[0x39] = 0x3D75C28F;  // +0xE4  ~0.058f
    data[0x3A] = 0x3D75C28F;  // +0xE8
    data[0x3B] = 0x3D75C28F;  // +0xEC
    data[0x3C] = 0x3F70A3D7;  // +0xF0  ~0.96f

    // --- Light direction / padding ---
    data[0x3D] = 0;           // +0xF4
    data[0x3E] = 0;           // +0xF8
    data[0x3F] = 0;           // +0xFC
    data[0x40] = 0;           // +0x100

    // --- Attenuation constants ---
    data[0x41] = 0x3DA3D70A;  // +0x104  ~0.08f
    data[0x42] = 0x3DA3D70A;  // +0x108
    data[0x43] = 0x3DA3D70A;  // +0x10C
    data[0x44] = 0x3F70A3D7;  // +0x110  ~0.96f

    // --- Light falloff ---
    data[0x45] = 0x3EDC28F6;  // +0x114  ~0.43f
    data[0x46] = 0x3EDC28F6;  // +0x118
    data[0x47] = F32_0_5;     // +0x11C
    data[0x48] = F32_0_5;     // +0x120

    // --- Padding ---
    data[0x49] = 0;           // +0x124
    data[0x4A] = 0;           // +0x128
    data[0x4B] = 0;           // +0x12C  (300)
    data[0x4C] = 0;           // +0x130

    // --- Fog parameters ---
    data[0x4D] = 0x3E23D70A;  // +0x134  ~0.16f
    data[0x4E] = 0x3E947AE1;  // +0x138  ~0.29f
    data[0x4F] = 0x3EF5C28F;  // +0x13C  ~0.48f
    data[0x50] = 0x3F0A3D71;  // +0x140  ~0.54f

    // --- Light #1 color ramp (R, G, B, A) ---
    data[0x51] = 0x3E851EB8;  // +0x144  ~0.26f
    data[0x52] = 0x3F170A3D;  // +0x148  ~0.59f
    data[0x53] = 0x3F7AE148;  // +0x14C  ~0.98f

    // --- Light #1 attenuation ---
    data[0x54] = 0x3ECCCCCD;  // +0x150  ~0.4f
    data[0x55] = 0x3E851EB8;  // +0x154
    data[0x56] = 0x3F170A3D;  // +0x158
    data[0x57] = 0x3F7AE148;  // +0x15C

    // --- Light #1 specular power ---
    data[0x58] = 0x3F2B851F;  // +0x160  ~0.67f
    data[0x59] = 0x3D23D70A;  // +0x164  ~0.04f
    data[0x5A] = 0x3D23D70A;  // +0x168
    data[0x5B] = 0x3D23D70A;  // +0x16C
    data[0x5C] = F32_1_0;     // +0x170

    // --- Light #2 (mirror of light #1) ---
    data[0x5D] = 0x3E23D70A;  // +0x174
    data[0x5E] = 0x3E947AE1;  // +0x178
    data[0x5F] = 0x3EF5C28F;  // +0x17C
    data[0x60] = F32_1_0;     // +0x180

    // --- Light #2 direction (zeros) ---
    data[0x61] = 0;           // +0x184
    data[0x62] = 0;           // +0x188
    data[0x63] = 0;           // +0x18C

    // --- Light #3 intensity ---
    data[0x64] = 0x3F028F5C;  // +0x190  (400) ~0.51f
    data[0x65] = 0x3E0F5C29;  // +0x194  ~0.14f
    data[0x66] = 0x3E0F5C29;  // +0x198
    data[0x67] = 0x3E0F5C29;  // +0x19C
    data[0x68] = F32_1_0;     // +0x1A0

    // --- Light #4 ---
    data[0x69] = 0x3CA3D70A;  // +0x1A4  ~0.02f
    data[0x6A] = 0x3CA3D70A;  // +0x1A8
    data[0x6B] = 0x3CA3D70A;  // +0x1AC
    data[0x6C] = 0x3F07AE14;  // +0x1B0  ~0.53f

    // --- Lights 5-8 ramp params ---
    data[0x6D] = 0x3E9EB852;  // +0x1B4  ~0.31f
    data[0x6E] = 0x3E9EB852;  // +0x1B8
    data[0x6F] = 0x3E9EB852;  // +0x1BC
    data[0x70] = F32_1_0;     // +0x1C0

    data[0x71] = 0x3ED1EB85;  // +0x1C4  ~0.41f
    data[0x72] = 0x3ED1EB85;  // +0x1C8
    data[0x73] = 0x3ED1EB85;  // +0x1CC
    data[0x74] = F32_1_0;     // +0x1D0

    data[0x75] = 0x3F028F5C;  // +0x1D4  ~0.51f
    data[0x76] = 0x3F028F5C;  // +0x1D8
    data[0x77] = 0x3F028F5C;  // +0x1DC
    data[0x78] = F32_1_0;     // +0x1E0

    // --- 8-light color ramps (4 components each) ---
    data[0x79] = 0x3E851EB8;  // +0x1E4
    data[0x7A] = 0x3F170A3D;  // +0x1E8
    data[0x7B] = 0x3F7AE148;  // +0x1EC
    data[0x7C] = F32_1_0;     // +0x1F0

    data[0x7D] = 0x3E75C28F;  // +0x1F4  (500)
    data[0x7E] = 0x3F051EB8;  // +0x1F8
    data[0x7F] = 0x3F6147AE;  // +0x1FC
    data[0x80] = F32_1_0;     // +0x200

    data[0x81] = 0x3E851EB8;  // +0x204
    data[0x82] = 0x3F170A3D;  // +0x208
    data[0x83] = 0x3F7AE148;  // +0x20C
    data[0x84] = F32_1_0;     // +0x210

    data[0x85] = 0x3E851EB8;  // +0x214
    data[0x86] = 0x3F170A3D;  // +0x218
    data[0x87] = 0x3F7AE148;  // +0x21C

    data[0x88] = 0x3ECCCCCD;  // +0x220  ~0.4f
    data[0x89] = 0x3E851EB8;  // +0x224
    data[0x8A] = 0x3F170A3D;  // +0x228
    data[0x8B] = 0x3F7AE148;  // +0x22C

    data[0x8C] = F32_1_0;     // +0x230
    data[0x8D] = 0x3D75C28F;  // +0x234
    data[0x8E] = 0x3F07AE14;  // +0x238
    data[0x8F] = 0x3F7AE148;  // +0x23C

    data[0x90] = F32_1_0;     // +0x240
    data[0x91] = 0x3E851EB8;  // +0x244
    data[0x92] = 0x3F170A3D;  // +0x248
    data[0x93] = 0x3F7AE148;  // +0x24C

    data[0x94] = 0x3E9EB852;  // +0x250
    data[0x95] = 0x3E851EB8;  // +0x254
    data[0x96] = 0x3F170A3D;  // +0x258  (600)
    data[0x97] = 0x3F7AE148;  // +0x25C

    // --- Interpolated light sets (runtime factor from DAT_0066bec4) ---
    float interpFactor = DAT_0066bec4;

    data[0x98] = 0x3F4CCCCD;  // +0x260  ~0.8f
    data[0x99] = 0x3E851EB8;  // +0x264
    data[0x9A] = 0x3F170A3D;  // +0x268
    data[0x9B] = 0x3F7AE148;  // +0x26C
    data[0x9C] = F32_1_0;     // +0x270

    // Copy from fog density region
    data[0x9D] = data[0x45];  // +0x274 = +0x114
    data[0x9E] = data[0x46];  // +0x278 = +0x118
    data[0x9F] = data[0x47];  // +0x27C = +0x11C
    data[0xA0] = data[0x48];  // +0x280 = +0x120

    // --- Fog density ramps ---
    data[0xA1] = 0x3DCCCCCD;  // +0x284  ~0.1f
    data[0xA2] = 0x3ECCCCCD;  // +0x288  ~0.4f
    data[0xA3] = 0x3F400000;  // +0x28C  ~0.75f
    data[0xA4] = 0x3F47AE14;  // +0x290  ~0.78f
    data[0xA5] = 0x3DCCCCCD;  // +0x294
    data[0xA6] = 0x3ECCCCCD;  // +0x298
    data[0xA7] = 0x3F400000;  // +0x29C
    data[0xA8] = F32_1_0;     // +0x2A0

    // --- More light ramps ---
    data[0xA9] = 0x3E851EB8;  // +0x2A4
    data[0xAA] = 0x3F170A3D;  // +0x2A8
    data[0xAB] = 0x3F7AE148;  // +0x2AC

    data[0xAC] = 0x3E4CCCCD;  // +0x2B0
    data[0xAD] = 0x3E851EB8;  // +0x2B4
    data[0xAE] = 0x3F170A3D;  // +0x2B8
    data[0xAF] = 0x3F7AE148;  // +0x2BC  (700)

    data[0xB0] = 0x3F2B851F;  // +0x2C0  ~0.67f
    data[0xB1] = 0x3E851EB8;  // +0x2C4
    data[0xB2] = 0x3F170A3D;  // +0x2C8
    data[0xB3] = 0x3F7AE148;  // +0x2CC
    data[0xB4] = 0x3F733333;  // +0x2D0  ~0.95f

    // --- Interpolated fog/light positions (DAT_0066bec4) ---
    fdata[0xB5] = (fdata[0x5D] - fdata[0x91]) * interpFactor + fdata[0x91];  // +0x2D4
    fdata[0xB6] = (fdata[0x5E] - fdata[0x92]) * interpFactor + fdata[0x92];  // +0x2D8
    fdata[0xB7] = (fdata[0x5F] - fdata[0x93]) * interpFactor + fdata[0x93];  // +0x2DC
    fdata[0xB8] = (fdata[0x60] - fdata[0x94]) * interpFactor + fdata[0x94];  // +0x2E0

    data[0xB9] = data[0x95];  // +0x2E4 = +0x254
    data[0xBA] = data[0x96];  // +0x2E8 = +0x258
    data[0xBB] = data[0x97];  // +0x2EC = +0x25C
    data[0xBC] = data[0x98];  // +0x2F0 = +0x260

    // --- Second interpolation pass (DAT_0066be4c) ---
    float interpFactor2 = DAT_0066be4c;
    fdata[0xBD] = (fdata[0x5D] - fdata[0x99]) * interpFactor2 + fdata[0x99];  // +0x2F4
    fdata[0xBE] = (fdata[0x5E] - fdata[0x9A]) * interpFactor2 + fdata[0x9A];  // +0x2F8
    fdata[0xBF] = (fdata[0x5F] - fdata[0x9B]) * interpFactor2 + fdata[0x9B];  // +0x2FC
    fdata[0xC0] = (fdata[0x60] - fdata[0x9C]) * interpFactor2 + fdata[0x9C];  // +0x300

    // --- Third interpolation pass (DAT_0066bec4 again) ---
    fdata[0xC1] = (fdata[0x59] - fdata[0xB5]) * interpFactor + fdata[0xB5];  // +0x304
    fdata[0xC2] = (fdata[0x5A] - fdata[0xB6]) * interpFactor + fdata[0xB6];  // +0x308
    fdata[0xC3] = (fdata[0x5B] - fdata[0xB7]) * interpFactor + fdata[0xB7];  // +0x30C
    fdata[0xC4] = (fdata[0x5C] - fdata[0xB8]) * interpFactor + fdata[0xB8];  // +0x310

    // --- Fourth interpolation pass (DAT_0066bdf4) ---
    float interpFactor3 = DAT_0066bdf4;
    fdata[0xC5] = (fdata[0x59] - fdata[0xBD]) * interpFactor3 + fdata[0xBD];  // +0x314
    fdata[0xC6] = (fdata[0x5A] - fdata[0xBE]) * interpFactor3 + fdata[0xBE];  // +0x318
    fdata[0xC7] = (fdata[0x5B] - fdata[0xBF]) * interpFactor3 + fdata[0xBF];  // +0x31C
    fdata[0xC8] = (fdata[0x5C] - fdata[0xC0]) * interpFactor3 + fdata[0xC0];  // +0x320  (800)

    // --- Global illumination / ambient occlusion ---
    data[0xC9] = 0x3F1C28F6;  // +0x324  ~0.61f
    data[0xCA] = 0x3F1C28F6;  // +0x328
    data[0xCB] = 0x3F1C28F6;  // +0x32C
    data[0xCC] = F32_1_0;     // +0x330
    data[0xCD] = F32_1_0;     // +0x334

    // --- Reflection / Fresnel ---
    data[0xCE] = 0x3EDC28F6;  // +0x338  ~0.43f
    data[0xCF] = 0x3EB33333;  // +0x33C  ~0.35f
    data[0xD0] = F32_1_0;     // +0x340
    data[0xD1] = 0x3F666666;  // +0x344  ~0.9f
    data[0xD2] = 0x3F333333;  // +0x348  ~0.7f
    data[0xD3] = 0;           // +0x34C
    data[0xD4] = F32_1_0;     // +0x350
    data[0xD5] = F32_1_0;     // +0x354
    data[0xD6] = 0x3F19999A;  // +0x358  ~0.6f
    data[0xD7] = 0;           // +0x35C
    data[0xD8] = F32_1_0;     // +0x360

    // --- Per-material shader constants ---
    data[0xD9] = 0x3E428F5C;  // +0x364  ~0.19f
    data[0xDA] = 0x3E428F5C;  // +0x368
    data[0xDB] = 0x3E4CCCCD;  // +0x36C  ~0.2f
    data[0xDC] = F32_1_0;     // +0x370
    data[0xDD] = 0x3E9EB852;  // +0x374  ~0.31f
    data[0xDE] = 0x3E9EB852;  // +0x378
    data[0xDF] = 0x3EB33333;  // +0x37C  ~0.35f
    data[0xE0] = F32_1_0;     // +0x380

    data[0xE1] = 0x3E6B851F;  // +0x384  (900) ~0.23f
    data[0xE2] = 0x3E6B851F;  // +0x388
    data[0xE3] = 0x3E800000;  // +0x38C  ~0.25f
    data[0xE4] = F32_1_0;     // +0x390

    // --- Padding / unused uniforms ---
    data[0xE5] = 0;           // +0x394
    data[0xE6] = 0;           // +0x398
    data[0xE7] = 0;           // +0x39C
    data[0xE8] = 0;           // +0x3A0

    // --- Wrap mode / UV params ---
    data[0xE9] = F32_1_0;     // +0x3A4
    data[0xEA] = F32_1_0;     // +0x3A8
    data[0xEB] = F32_1_0;     // +0x3AC
    data[0xEC] = 0x3D75C28F;  // +0x3B0  ~0.058f

    // --- Final color ramp ---
    data[0xED] = 0x3E851EB8;  // +0x3B4
    data[0xEE] = 0x3F170A3D;  // +0x3B8
    data[0xEF] = 0x3F7AE148;  // +0x3BC
    data[0xF0] = 0x3EB33333;  // +0x3C0
    data[0xF1] = F32_1_0;     // +0x3C4
    data[0xF2] = F32_1_0;     // +0x3C8
    data[0xF3] = 0;           // +0x3CC
    data[0xF4] = 0x3F666666;  // +0x3D0  ~0.9f

    data[0xF5] = 0x3E851EB8;  // +0x3D4
    data[0xF6] = 0x3F170A3D;  // +0x3D8
    data[0xF7] = 0x3F7AE148;  // +0x3DC
    data[0xF8] = F32_1_0;     // +0x3E0
    data[0xF9] = F32_1_0;     // +0x3E4
    data[0xFA] = F32_1_0;     // +0x3E8  (1000)
    data[0xFB] = F32_1_0;     // +0x3EC

    // --- Texture transform / UV scale ---
    data[0xFC] = 0x3F333333;  // +0x3F0  ~0.7f
    data[0xFD] = 0x3F4CCCCD;  // +0x3F4  ~0.8f
    data[0xFE] = 0x3F4CCCCD;  // +0x3F8
    data[0xFF] = 0x3F4CCCCD;  // +0x3FC

    data[0x100] = 0x3E4CCCCD; // +0x400
    data[0x101] = 0x3F4CCCCD; // +0x404
    data[0x102] = 0x3F4CCCCD; // +0x408
    data[0x103] = 0x3F4CCCCD; // +0x40C
    data[0x104] = 0x3EB33333; // +0x410
}

// ============================================================================
// ShaderConstantBufferBinding (FUN_0061fbd0) - FAIL
// Allocates buffers for world/view/projection matrices, binds to renderer.
//
// Raw decompilation:
//   void __fastcall FUN_0061fbd0(int param_1)
//   Callers: FUN_004de7d0
//   Callees: operator_new, _invoke_watson, FUN_00643505
//
// Binds three constant buffers to renderer slots 0, 2, 4 based on render mode
// (0=main, 1=shadow, 2=reflection). Uses renderer state at DAT_00702770
// offsets 0x4F50-0x5018 for buffer data pointers.
// ============================================================================
void ShaderConstantBufferBinding(int param1)
{
    // 0x0061fbd0
    // Read render target mode from +0x250
    int renderMode = *reinterpret_cast<int*>(param1 + 0x250);

    // Get renderer vtable function pointer for binding (vtable+0x14)
    auto renderBindFunc = reinterpret_cast<void(__cdecl*)(int, void**, uint32_t)>(
        *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(param1 + 4) + 0x14));

    // --- Buffer 0: Vertex shader constants (World/View/Projection) ---
    uint32_t* buffer0 = static_cast<uint32_t*>(operator_new(8));
    buffer0[0] = *reinterpret_cast<uint32_t*>(DAT_00702770 + 0x4F50);
    int secondaryPtr = *reinterpret_cast<int*>(DAT_00702770 + 0x4F54);
    if (secondaryPtr == 0) {
        secondaryPtr = *reinterpret_cast<int*>(DAT_00702770 + 0x4F50);
    }
    buffer0[1] = static_cast<uint32_t>(secondaryPtr);

    renderBindFunc(0, reinterpret_cast<void**>(&buffer0), DAT_0067d280);

    // Safe delete buffer0
    if (buffer0 != nullptr) {
        uint32_t bufSize = reinterpret_cast<uint8_t*>(buffer0 + 2) - reinterpret_cast<uint8_t*>(buffer0);
        void* deallocPtr = buffer0;
        if (bufSize > 0xFFF) {
            deallocPtr = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(buffer0) - 4);
            bufSize += 0x23;
            if ((reinterpret_cast<uintptr_t>(buffer0) - 4 - reinterpret_cast<uintptr_t>(deallocPtr)) > 0x1F) {
                std::abort();
            }
        }
        FUN_00643505(deallocPtr, bufSize);
    }

    // --- Buffer 2: Pixel shader constants (View matrix) ---
    buffer0 = static_cast<uint32_t*>(operator_new(8));
    uint32_t viewData = 0;

    if (renderMode == 0) {
        viewData = *reinterpret_cast<uint32_t*>(DAT_00702770 + 0x4FB0);
    } else if (renderMode == 1) {
        viewData = *reinterpret_cast<uint32_t*>(DAT_00702770 + 0x4FB4);
    } else if (renderMode == 2) {
        viewData = *reinterpret_cast<uint32_t*>(DAT_00702770 + 0x4FB8);
    }

    buffer0[0] = viewData;
    renderBindFunc(2, reinterpret_cast<void**>(&buffer0), 0);

    // Safe delete buffer0
    if (buffer0 != nullptr) {
        uint32_t bufSize = reinterpret_cast<uint8_t*>(buffer0 + 2) - reinterpret_cast<uint8_t*>(buffer0);
        void* deallocPtr = buffer0;
        if (bufSize > 0xFFF) {
            deallocPtr = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(buffer0) - 4);
            bufSize += 0x23;
            if ((reinterpret_cast<uintptr_t>(buffer0) - 4 - reinterpret_cast<uintptr_t>(deallocPtr)) > 0x1F) {
                std::abort();
            }
        }
        FUN_00643505(deallocPtr, bufSize);
    }

    // --- Buffer 4: Texture constants (Projection matrix) ---
    buffer0 = static_cast<uint32_t*>(operator_new(8));
    uint32_t projData = 0;

    if (renderMode == 0) {
        projData = *reinterpret_cast<uint32_t*>(DAT_00702770 + 0x5010);
    } else if (renderMode == 1) {
        projData = *reinterpret_cast<uint32_t*>(DAT_00702770 + 0x5014);
    } else if (renderMode == 2) {
        projData = *reinterpret_cast<uint32_t*>(DAT_00702770 + 0x5018);
    }

    buffer0[0] = projData;
    renderBindFunc(4, reinterpret_cast<void**>(&buffer0), 0);

    // Safe delete buffer0
    if (buffer0 != nullptr) {
        uint32_t bufSize = (reinterpret_cast<uint8_t*>(buffer0 + 2) - reinterpret_cast<uint8_t*>(buffer0)) & 0xFFFFFFFC;
        void* deallocPtr = buffer0;
        if (bufSize > 0xFFF) {
            deallocPtr = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(buffer0) - 4);
            bufSize += 0x23;
            if ((reinterpret_cast<uintptr_t>(buffer0) - 4 - reinterpret_cast<uintptr_t>(deallocPtr)) > 0x1F) {
                std::abort();
            }
        }
        FUN_00643505(deallocPtr, bufSize);
    }
}

// ============================================================================
// ObjectConstantsInit (FUN_0061fe60) - FAIL
// Sets identity transform (scale 1.0, zero rotation/translation),
// gets "ObjectConstants" handle from renderer.
//
// Raw decompilation:
//   undefined4 * __thiscall FUN_0061fe60(undefined4 *param_1, int *param_2)
//   Callers: FUN_004e2180
//   Callees: 0
// ============================================================================
uint32_t* ObjectConstantsInit(uint32_t* param1, int* param2)
{
    // 0x0061fe60
    // Set identity scale: [1.0, 0, 1.0, 1.0]
    param1[0x24] = F32_1_0;  // +0x90  scale X = 1.0
    param1[0x25] = 0;         // +0x94  rotation/translation = 0.0
    param1[0x26] = F32_1_0;  // +0x98  scale Y = 1.0
    param1[0x27] = F32_1_0;  // +0x9C  scale Z = 1.0
    param1[0x28] = 0;         // +0xA0  translation = 0.0

    // Set vtable pointer (ObjectConstants vtable)
    *param1 = reinterpret_cast<uint32_t>(PTR_LAB_0066a498);

    // Zero out transform region
    *reinterpret_cast<uint64_t*>(param1 + 0x29) = 0;  // +0xA4..+0xAB
    param1[0x2B] = 0;                                   // +0xAC

    // Mark as active
    *reinterpret_cast<uint8_t*>(param1 + 0x2C) = 1;    // +0xB0

    // Get "ObjectConstants" constant buffer handle from renderer
    param1[0x2D] = 0;
    auto getConstantHandle = reinterpret_cast<uint32_t(__cdecl*)(const char*, int)>(
        *reinterpret_cast<uint32_t*>(*param2 + 4));
    param1[0x2D] = getConstantHandle("ObjectConstants", 0x0F);

    return param1;
}

// ============================================================================
// FrameConstantsInit (FUN_0061ff00) - FAIL
// Gets "FrameConstants" handle from renderer.
//
// Raw decompilation:
//   undefined4 * __thiscall FUN_0061ff00(undefined4 *param_1, int *param_2)
//   Callers: FUN_004e2180
//   Callees: FUN_004df880
// ============================================================================
uint32_t* FrameConstantsInit(uint32_t* param1, int* param2)
{
    // 0x0061ff00
    // Set vtable pointer (FrameConstants vtable)
    *param1 = reinterpret_cast<uint32_t>(PTR_LAB_0066a490);

    // Call sub-initializer (base class init or render state flush)
    FUN_004df880();

    // Mark as active
    *reinterpret_cast<uint8_t*>(param1 + 100) = 1;  // +0x190

    // Get "FrameConstants" constant buffer handle from renderer
    param1[0x65] = 0;
    auto getConstantHandle = reinterpret_cast<uint32_t(__cdecl*)(const char*, int)>(
        *reinterpret_cast<uint32_t*>(*param2 + 4));
    param1[0x65] = getConstantHandle("FrameConstants", 0x0E);

    return param1;
}

// ============================================================================
// ScreenSpaceShaderSetup (FUN_00621ba0) - FAIL
// Gets "ScreenSpace" sampler, sets up ObjectConstants render pass.
//
// Raw decompilation:
//   undefined4 * __fastcall FUN_00621ba0(undefined4 *param_1)
//   Callers: FUN_0061f8f0, FUN_005d7de0
//   Callees: 0
// ============================================================================
uint32_t* ScreenSpaceShaderSetup(uint32_t* param1)
{
    // 0x00621ba0
    // Get "ScreenSpace" sampler from renderer interface via vtable+0xE8
    // TODO: Full vtable call — requires renderer interface type definition
    int* screenSpaceSampler = nullptr;

    // Set initial vtable and sampler reference
    *param1 = reinterpret_cast<uint32_t>(PTR_LAB_0066a484);
    param1[1] = reinterpret_cast<uint32_t>(screenSpaceSampler);

    // Zero out render state fields
    param1[2]  = 0;
    param1[0xC] = 0;
    param1[0xD] = 0;
    param1[8]  = 0;
    param1[9]  = 0;
    param1[10] = 0;
    param1[0xB] = 0;

    // Set sub-object vtable
    param1[4] = reinterpret_cast<uint32_t>(PTR_LAB_0066a5a8);

    // Mark as active
    *reinterpret_cast<uint8_t*>(param1 + 0x10) = 1;

    // Get "ObjectConstants" handle from the sampler interface
    param1[0x11] = 0;
    auto getConstantHandle = reinterpret_cast<uint32_t(__cdecl*)(const char*, int)>(
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t>(screenSpaceSampler) + 4));
    param1[0x11] = getConstantHandle("ObjectConstants", 0x0F);

    param1[0x14] = 0;

    // Override with final vtables (runtime polymorphism / subclass swap)
    *param1 = reinterpret_cast<uint32_t>(PTR_LAB_0066a5b0);
    param1[4] = reinterpret_cast<uint32_t>(PTR_LAB_0066a5bc);

    return param1;
}

// ============================================================================
// VertexBufferClone (FUN_00501240) - FAIL
// Allocates and copies vertex/index/color buffers (stride 0xC = 12 bytes).
//
// Raw decompilation:
//   uint * __thiscall FUN_00501240(uint *param_1, uint *param_2)
//   Callers: FUN_00559e60
//   Callees: FUN_0064356b (malloc wrapper), memcpy
// ============================================================================
uint32_t* VertexBufferClone(uint32_t* dst, uint32_t* src)
{
    // 0x00501240
    // Zero-initialize destination
    *dst = 0;
    dst[5] = 0;
    dst[1] = 0;
    dst[3] = 0;
    dst[4] = 0;
    dst[7] = 0;
    dst[8] = 0;

    // Copy vertex count and metadata
    uint32_t vertexCount = *src;
    *dst = vertexCount;
    dst[2] = src[2];  // Index count / capacity
    dst[5] = src[5];  // Additional data pointer

    // Calculate buffer size: vertexCount * 12 (stride 0xC)
    uint32_t bufferSize = vertexCount * 0xC;

    // Allocate and copy vertex buffer (field[1])
    void* newVertices = FUN_0064356b(bufferSize);
    dst[1] = reinterpret_cast<uint32_t>(newVertices);
    memcpy(newVertices, reinterpret_cast<void*>(src[1]), *dst * 0xC);

    // Clone index buffer if present (field[3])
    if (src[3] != 0) {
        uint32_t indexBufferSize = dst[2] * 0xC;
        void* newIndices = FUN_0064356b(indexBufferSize);
        dst[3] = reinterpret_cast<uint32_t>(newIndices);
        memcpy(newIndices, reinterpret_cast<void*>(src[3]), dst[2] * 0xC);
    }

    // Clone color/extra buffer if present (field[4])
    if (src[4] != 0) {
        uint32_t colorCount;
        if (static_cast<char>(src[6]) == '\0') {
            // Use count from metadata field at src[5]+0x14
            uint32_t metaCount = *reinterpret_cast<uint32_t*>(src[5] + 0x14);
            bufferSize = metaCount * 0xC;
            void* newColors = FUN_0064356b(bufferSize);
            dst[4] = reinterpret_cast<uint32_t>(newColors);
            colorCount = metaCount;
        } else {
            // Use same count as vertex buffer
            bufferSize = *dst * 0xC;
            void* newColors = FUN_0064356b(bufferSize);
            colorCount = *dst;
            dst[4] = reinterpret_cast<uint32_t>(newColors);
        }
        memcpy(reinterpret_cast<void*>(dst[4]), reinterpret_cast<void*>(src[4]), colorCount * 0xC);
    }

    return dst;
}

// ============================================================================
// ShaderResourceLookup (FUN_00640530) - PASS
// Accesses resource array by index, sets parameter, calls init.
//
// Raw decompilation:
//   undefined4 FUN_00640530(int param_1, undefined4 param_2, uint param_3)
//   Callers: FUN_00640c20, FUN_00640c00, FUN_005f0ed0
//   Callees: FUN_00640170
// ============================================================================
uint32_t ShaderResourceLookup(int param1, uint32_t param2, uint32_t param3)
{
    // 0x00640530
    int* tableBase = reinterpret_cast<int*>(param1);

    if (tableBase[0x1C / 4] != 0 && param3 < static_cast<uint32_t>(tableBase[0x20 / 4])) {
        int* entries = reinterpret_cast<int*>(tableBase[0x24 / 4]);
        int* entry = &entries[param3 * (0x1C / 4)];

        // Set resource base and parameter
        entry[0] = tableBase[0x1C / 4];
        entry[0x18 / 4] = static_cast<int>(param2);

        // Initialize resource entry
        FUN_00640170(entry);

        // If ref-count is zero, return resolved data pointer
        if (entry[0x0C / 4] == 0) {
            return *reinterpret_cast<uint32_t*>(entry[0x10 / 4] + entry[0x08 / 4] * 4);
        }
    }
    return 0;
}

// ============================================================================
// ShaderConstantResolve (FUN_006408d0) - FAIL
// Looks up constant buffer entry, resolves symbol offset.
//
// Raw decompilation:
//   undefined4 FUN_006408d0(int *param_1, int *param_2)
//   Callers: 29 (FUN_006406f0 x3, FUN_006331f0 x7, FUN_00634930, ...)
//   Callees: __security_check_cookie, FUN_00640170
// ============================================================================
uint32_t ShaderConstantResolve(int* param1, int* param2)
{
    // 0x006408d0
    // TODO: Security cookie validation with DAT_0067d280 omitted

    // Fast path: if param2[1] is non-zero, simple pointer addition
    if (param2[1] != 0) {
        if (*param1 != 0) {
            *param1 = *param2 + *param1;
        }
        return 1;
    }

    // Complex lookup path: resolve symbol via hash table
    int iVar2 = *reinterpret_cast<int*>(*param2 + 4);
    int* resolvedPtr = nullptr;

    if (*reinterpret_cast<int*>(iVar2 + 0x1C) != 0 && *reinterpret_cast<int*>(iVar2 + 0x20) != 0) {
        int* lookupTable = *reinterpret_cast<int**>(iVar2 + 0x24);
        lookupTable[0] = *reinterpret_cast<int*>(iVar2 + 0x1C);
        lookupTable[6] = reinterpret_cast<int>(param1);
        FUN_00640170(lookupTable);

        if (lookupTable[3] == 0) {
            resolvedPtr = reinterpret_cast<int*>(
                *reinterpret_cast<int*>(lookupTable[4] + lookupTable[2] * 4));
            goto LAB_RESOLVED;
        }
    }
    resolvedPtr = nullptr;

LAB_RESOLVED:
    if (resolvedPtr != nullptr) {
        // Compute symbol entry from resolved pointer
        int* symbolEntry = reinterpret_cast<int*>(
            static_cast<uint16_t>(*reinterpret_cast<uint16_t*>(
                reinterpret_cast<uint32_t>(resolvedPtr) + 2)) +
            reinterpret_cast<uint32_t>(resolvedPtr));

        // Compute base pointer from param1 offset
        int* basePtr = reinterpret_cast<int*>(
            param2[1] - param2[0] + reinterpret_cast<int>(param1));

        // Second lookup pass
        iVar2 = *reinterpret_cast<int*>(*param2 + 4);
        if (*reinterpret_cast<int*>(iVar2 + 0x1C) != 0 &&
            *reinterpret_cast<int*>(iVar2 + 0x20) != 0) {
            int* lookupTable2 = *reinterpret_cast<int**>(iVar2 + 0x24);
            lookupTable2[0] = *reinterpret_cast<int*>(iVar2 + 0x1C);
            lookupTable2[6] = reinterpret_cast<int>(param1);
            FUN_00640170(lookupTable2);

            if (lookupTable2[3] == 0) {
                int* result2 = reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(lookupTable2[4] + lookupTable2[2] * 4));
                if (result2 != nullptr) {
                    int* symbolEntry2 = reinterpret_cast<int*>(
                        static_cast<uint16_t>(*reinterpret_cast<uint16_t*>(
                            reinterpret_cast<uint32_t>(result2) + 2)) +
                        reinterpret_cast<uint32_t>(result2));
                    *basePtr = symbolEntry2[1] - *param2 - *symbolEntry2 + *param1;
                    return 1;
                }
            }
        }
        *basePtr = 0;
    }
    return 0;
}

// ============================================================================
// ShaderIteration (FUN_00640b60) - PASS
// Resolves two constant buffers, iterates shader resources.
//
// Raw decompilation:
//   void FUN_00640b60(int param_1, code *param_2, undefined4 param_3)
//   Callers: FUN_006331f0 (x2), FUN_00635620 (x3)
//   Callees: FUN_006408d0, FUN_00640400, FUN_00640590
// ============================================================================
void ShaderIteration(int param1, void* param2, uint32_t param3)
{
    // 0x00640b60
    // Resolve constant buffers for both halves of shader data
    ShaderConstantResolve(reinterpret_cast<int*>(param1), reinterpret_cast<int*>(param3));
    uint32_t* tablePtr = reinterpret_cast<uint32_t*>(param1 + 4);
    ShaderConstantResolve(reinterpret_cast<int*>(tablePtr), reinterpret_cast<int*>(param3));

    // Select iteration callback based on flags
    void (*callback)(void) = reinterpret_cast<void(*)(void)>(FUN_00640b10);
    if ((*reinterpret_cast<uint8_t*>(param1 + 8) & 2) != 0) {
        callback = reinterpret_cast<void(*)(void)>(FUN_00640c90);
    }
    PTR_FUN_0067d264 = callback;

    // Initialize iteration context
    FUN_00640400(*tablePtr, &DAT_0067d260, param3);

    // Iterate over all resources
    int index = 0;
    uint32_t resource = FUN_00640590(*tablePtr, 0, 0);

    while (resource != 0) {
        if (param2 != nullptr) {
            // Call user callback with resource data pointer
            auto userCallback = reinterpret_cast<void(*)(uint32_t, uint32_t)>(param2);
            uint32_t dataPtr = static_cast<uint16_t>(
                *reinterpret_cast<uint16_t*>(resource + 2)) + resource;
            userCallback(dataPtr, param3);
        }
        index++;
        resource = FUN_00640590(*tablePtr, index, 0);
    }
}

// ============================================================================
// ShaderResourceCount (FUN_00640bf0) - PASS
// Returns number of resources in shader table.
//
// Raw decompilation:
//   undefined4 FUN_00640bf0(int param_1)
//   Callers: FUN_00633560
//   Callees: 0
// ============================================================================
uint32_t ShaderResourceCount(int param1)
{
    // 0x00640bf0
    // Resource count stored at offset 0x1C in the table referenced by param1+4
    return *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(param1 + 4) + 0x1C);
}

// ============================================================================
// ShaderResourceSetter (FUN_00640c00) - PASS
// Binds resource at index 1.
//
// Raw decompilation:
//   void FUN_00640c00(int param_1)
//   Callers: FUN_00633560
//   Callees: FUN_00640530
//
// Note: &stack0x00000008 in original decompilation refers to the second
// parameter passed on the stack, which maps to param2 in ShaderResourceLookup.
// ============================================================================
void ShaderResourceSetter(int param1)
{
    // 0x00640c00
    // Access table from param1+4, then look up resource at index 1
    // The second parameter is the stack argument at offset +8 from the caller
    ShaderResourceLookup(
        *reinterpret_cast<int*>(param1 + 4),
        *reinterpret_cast<uint32_t*>(&param1 + 2),  // stack param from caller
        1);
}

// ============================================================================
// ShaderResourceGetter (FUN_00640c40) - PASS
// Iterates resources matching param_2.
//
// Raw decompilation:
//   void FUN_00640c40(int param_1, undefined4 param_2)
//   Callers: 12 (FUN_006331f0 x4, FUN_00633560 x2, FUN_006337c0 x2,
//            FUN_00635500, FUN_00635620 x2)
//   Callees: FUN_00640590
// ============================================================================
void ShaderResourceGetter(int param1, uint32_t param2)
{
    // 0x00640c40
    // Delegate to FUN_00640590 with table from param1+4, search key, index 0
    FUN_00640590(*reinterpret_cast<uint32_t*>(param1 + 4), param2, 0);
}

// ============================================================================
// ShaderDataOffset (FUN_00640c70) - PASS
// Returns ushort at +2 + 4 + base (resource data pointer).
//
// Raw decompilation:
//   int FUN_00640c70(int param_1)
//   Callers: FUN_00633560 (x2), FUN_006337c0
//   Callees: 0
// ============================================================================
int ShaderDataOffset(int param1)
{
    // 0x00640c70
    // Read 16-bit offset from param1+2, add 4 (skip header) and base pointer
    return *reinterpret_cast<uint16_t*>(param1 + 2) + 4 + param1;
}

} // namespace Giants
