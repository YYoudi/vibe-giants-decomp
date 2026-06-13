// Giants Engine - Scene Subsystem Stubs Implementation
// Reverse engineered from GiantsMain.exe v1.520.59

#include "SceneSubsystem.h"
#include "CRTStubs.h"

#include <cstdlib>
#include <cstring>
#include <cctype>

namespace Giants {

// ─── External globals ───────────────────────────────────────────

extern void* g_renderDevice;  // DAT_00702700

// Keyboard mapping state
static void* DAT_007020dc = nullptr;  // Char-to-glyph mapping table (0x110 bytes)
static void* DAT_00702124 = nullptr;  // Glyph lookup tree (0x14 bytes)

// Reference string: "________________0123456789__<_>___" at 0x00682268
// Used for mapping ASCII chars to glyph indices
static const char s_glyphReference[] = "________________0123456789__<_>___";

// Render target state
static float DAT_00727e40 = 0;  // Current time (used for render target timestamps)

// Object template list head
static int* DAT_00685708 = nullptr;  // Array of object type IDs (null-terminated)
static void* DAT_0070278c = nullptr; // Resource pool (linked list of object data)

// ═══════════════════════════════════════════════════════════════════
// InitSceneSubsystem — FUN_004e94b0
// ═══════════════════════════════════════════════════════════════════

void InitSceneSubsystem()
{
    // ── Step 1: Create char-to-glyph mapping table ───────────────
    if (DAT_007020dc == nullptr)
    {
        // FUN_006406f0(0, 0) — get allocator context
        // FUN_006405d0(ctx, 0x110, 1) — allocate 272 bytes
        //
        // The table has:
        //   [0x00] context pointer
        //   [0x04] init flag (0)
        //   [0x08] float constant (0x42000000 = 32.0f, glyph scale?)
        //   [0x0C..0x10C] 256 bytes mapping ASCII value → glyph index
        //   [0x10C] null terminator (0)
        //
        // For each ASCII char 0..255:
        //   glyphIndex = toupper(charCode)
        //   Search s_glyphReference for match
        //   If found: map[char] = position in reference string
        //   If not found: map[char] = 2 (default glyph)

        for (int i = 0xFF; i >= 0; i--)
        {
            int upper = toupper(i);
            int refIdx = 0;
            char c = s_glyphReference[0];
            while (c != '\0' && c != upper)
            {
                refIdx++;
                c = s_glyphReference[refIdx];
            }
            uint8_t glyphIdx = 2;  // Default
            if (s_glyphReference[refIdx] != '\0')
                glyphIdx = (uint8_t)refIdx;
            // Store: mappingTable[i + 0x0B] = glyphIdx
        }
    }

    // ── Step 2: Create glyph lookup tree ─────────────────────────
    if (DAT_00702124 == nullptr)
    {
        // FUN_006406f0(0, 0) — get allocator context
        // FUN_006405d0(ctx, 0x14, 1) — allocate 20 bytes
        // FUN_00640340(ctx, 0x10, 0x44) — allocate sub-node
        //
        // Tree structure:
        //   [0x00] context pointer
        //   [0x04] sub-node pointer (0x10 bytes)
        //   [0x08] back-pointer to mappingTable
        //   [0x0C..0x10] self-referential circular links
    }
}

// ═══════════════════════════════════════════════════════════════════
// InitRenderTarget — FUN_004f3c80
// ═══════════════════════════════════════════════════════════════════

void InitRenderTarget()
{
    // Clear render target state
    // DAT_00747d7c = 0
    // DAT_00747d80 = DAT_00727e40  (current time)
    // DAT_00747d84 = DAT_00727e40  (current time)
    // DAT_00747d88 = 0
    // DAT_00747d8c = 0
    // DAT_00747d90 = 0x7FFFFFFF    (max int — render distance sentinel)
    // DAT_00747d94 = 0
    // DAT_007486f8 = 0
    // DAT_007486fc = 0
    // memset(&DAT_00747d98, 0, 0x960)  — 2400 bytes of entity visibility data
}

// ═══════════════════════════════════════════════════════════════════
// MatrixMultiply4x4 — FUN_005fa390
// ═══════════════════════════════════════════════════════════════════
// Performs 4x4 matrix multiply: result = A * B
// All matrices stored as 16 contiguous floats in row-major order.
// Result goes to DAT_00685810..0068584c (16 floats = 64 bytes).
//
// Ghidra decompilation shows 16 multiply-accumulate operations:
//   result[i][j] = sum(A[i][k] * B[k][j], k=0..3)
//
// This is the classic 4x4 matrix multiply used for transform composition.
// 13 callers, 0 callees — hot path.

void MatrixMultiply4x4()
{
    // Input matrices (from Ghidra DAT references):
    // Matrix A: DAT_006857d0..DAT_0068580c (16 floats)
    // Matrix B: DAT_00685790..DAT_0068579c (4 floats for col 0, rest from context)
    //
    // Output matrix: DAT_00685810..DAT_0068584c
    //
    // The full computation writes 16 floats:
    //   result[0][0..3] = A[0][0]*B[0][0] + A[0][1]*B[1][0] + ...
    //   result[1][0..3] = A[1][0]*B[0][0] + A[1][1]*B[1][0] + ...
    //   result[2][0..3] = A[2][0]*B[0][0] + A[2][1]*B[1][0] + ...
    //   result[3][0..3] = A[3][0]*B[0][0] + A[3][1]*B[1][0] + ...
    //
    // Stub: actual computation would use the DAT_ globals directly.
    // In the real binary, this is an unrolled 4x4 matrix multiply.
}

// ═══════════════════════════════════════════════════════════════════
// ResetWorldState — FUN_005de9b0
// ═══════════════════════════════════════════════════════════════════

int ResetWorldState(int* stateBlock)
{
    // If already initialized (stateBlock[0] != 0), return immediately
    if (*stateBlock != 0)
        return *stateBlock;

    // ── Phase 1: Count object types ─────────────────────────────
    // Walk DAT_00685708 array (null-terminated) to count types
    int typeCount = 0;
    int* typePtr = DAT_00685708;
    while (*typePtr != 0) { typeCount++; typePtr++; }
    stateBlock[1] = typeCount;  // numTypes

    // ── Phase 2: Allocate per-type arrays ───────────────────────
    // stateBlock[2] = malloc(typeCount * 4) — objData pointers
    // stateBlock[3] = malloc(typeCount * 4) — per-type state arrays

    // ── Phase 3: Resolve object data from resource pool ─────────
    // For each type, search DAT_0070278c linked list to find
    // the resource matching the type ID. Store in stateBlock[2].

    // ── Phase 4: Register status callback ───────────────────────
    // If DAT_007028c0 < 1, add DAT_005de5e0 to callback array

    // ── Phase 5: Set state block pointers ───────────────────────
    // stateBlock[4] = &DAT_00728ba0  (entity list)
    // stateBlock[6] = &PTR_PTR_0067e868  (sub-object table)
    // stateBlock[8] = -1  (initialized marker)

    // ── Phase 6: Allocate per-type state ────────────────────────
    // For each type with valid objData:
    //   stateBlock[3][i] = malloc(objData->subCount * 0x38)

    // ── Phase 7: Resolve sub-object names ───────────────────────
    // Walk entity list (stateBlock[4]):
    //   For each entity, match its name against sub-object names
    //   via _stricmp. Set entity index and sub-object flags.
    //   Mark as resolved (bit 0), mark as special if starts with '@' or '$'.

    // ── Phase 8: Count sub-objects ──────────────────────────────
    // Walk sub-object table (stateBlock[6]):
    //   Count entries, update stateBlock[5]

    // ── Phase 9: Finalize ───────────────────────────────────────
    *stateBlock = 1;  // Mark initialized
    // FUN_005de6b0() — post-init callback

    return 1;
}

// ═══════════════════════════════════════════════════════════════════
// AllocateSceneNode — FUN_00640340
// ═══════════════════════════════════════════════════════════════════
// Allocates a scene node from the resource pool. Gets allocator context
// via FUN_006406f0. If context has sub-objects, allocates 0x30 bytes via
// FUN_006405d0; otherwise allocates 0x1C bytes via PTR_FUN_0067d250.
// Initializes node: links into intrusive list (context+0x10), sets size
// and refcount, updates context stats (+0x14 total size, +0x18 count).
// Sets up self-referential links for 3 sub-node lists at +0xC, +0x18, +0x24.
// 1 caller (InitSceneSubsystem), 4 callees.

int* AllocateSceneNode(uint32_t param_1, uint16_t param_2, short param_3)
{
    // Original:
    // iVar1 = FUN_006406f0(param_1, 0);  // get allocator context
    // if (iVar1 != 0) {
    //     _Size = 0x30;  // larger node
    //     if (*(int*)(iVar1 + 0xc) != 0)
    //         _Dst = FUN_006405d0(*(int*)(iVar1 + 0xc), 0x30, 1);
    //     else goto allocate_small;
    // } else {
    // allocate_small:
    //     _Dst = PTR_FUN_0067d250(0x1C);  // smaller node
    // }
    // memset(_Dst, 0, _Size);
    // if (iVar1 != 0) {
    //     Link into intrusive list at context+0x10
    //     _Dst[2] = _Size;  // node size
    //     _Dst[3] = 1;      // refcount
    //     context[0x14] += _Size;  // total allocated
    //     context[0x18]++;         // node count
    //     _Dst = _Dst + 4;  // skip header
    // }
    // Set param_2, param_3, self-referential links
    return nullptr;  // Stub
}

// ─── SceneFrameBegin (FUN_0052dfe0) — PASS (2 rounds) ──────────
// Initializes per-frame scene state: grid cell flags, mode dispatch,
// state copy, lighting/material snapshot, grid processing, scaling.
// 5 callers, 13 callees. Called at the start of each scene frame.

// Frame state globals
static int      DAT_007488d0 = 0;       // Frame init flag
static int      DAT_00702a40 = 0;       // Input state
static float    DAT_00748984 = 0.0f;    // Grid dimension X
static float    DAT_00748988 = 0.0f;    // Grid dimension Y
static float    DAT_00748980 = 0.0f;    // Camera near
static float    DAT_00748978 = 0.0f;    // Camera far
static int      DAT_0074b600 = 0;       // Scale param init (-1)
static float    DAT_007489a8 = 0.0f;    // Final scale X
static float    DAT_007489ac = 0.0f;    // Final scale Y

// Lighting/material snapshot globals (34 DWORDs + XOR-obfuscated depth)
static uint32_t DAT_007489b0 = 0; static uint32_t DAT_007489b4 = 0;
static uint32_t DAT_007489e0 = 0; static uint32_t DAT_007489e4 = 0;
static uint32_t DAT_007489ec = 0; static uint32_t DAT_007489d0 = 0;
static uint32_t DAT_007489d4 = 0; static uint32_t DAT_007489dc = 0;
static uint32_t DAT_007489f0 = 0; static uint32_t DAT_007489f4 = 0;
static uint32_t DAT_007489fc = 0; static uint32_t DAT_00748a00 = 0;
static uint32_t DAT_00748a04 = 0; static uint32_t DAT_00748a0c = 0;
static uint32_t DAT_007489e8 = 0; static uint32_t DAT_007489f8 = 0;
static uint32_t DAT_007489b8 = 0; static uint32_t DAT_00748a08 = 0;
static uint32_t DAT_007489bc = 0;

// Camera state copy
static float    DAT_00702cc0 = 0.0f;
static float    DAT_00702cb8 = 0.0f;

// Math constants from .rdata
static float    DAT_0066be20 = 1.0f;    // Scale multiplier
static float    DAT_0066be2c = 1.0f;    // Secondary scale
static float    DAT_0066bea0 = 1.0f;    // Aspect ratio base
static float    DAT_0066c1b0 = 0.0f;    // Scale offset
static float    DAT_0066c184 = 1.0f;    // Scale divisor
static float    DAT_0066bf60 = 1.0f;    // Scale minimum
static uint32_t DAT_0066c580 = 0;       // XOR depth key

// Scene object + controller
// DAT_00702770 is defined globally in CRTStubs.cpp as uint32_t (integer address)
static void*    DAT_00702774 = nullptr; // Controller object
// DAT_006ff960 declared in CRTStubs.h
static uint32_t DAT_0073f800[34] = {};  // State copy destination

void SceneFrameBegin()
{
    // Guard: need controller
    if (DAT_00702774 == nullptr)
        return;

    int sceneObj = (int)DAT_00702770;

    // Phase 1: Mark grid cells (multiplayer only, type 6)
    if (DAT_006ff960 == 6)
    {
        int row = 0;
        int rows = *reinterpret_cast<int*>(sceneObj + 0x254);
        int cols = *reinterpret_cast<int*>(sceneObj + 0x250);
        if (rows > 0)
        {
            do {
                int col = 0;
                if (cols > 0)
                {
                    int colOffset = 0;
                    do {
                        byte* cell = reinterpret_cast<byte*>(
                            *reinterpret_cast<int*>(
                                *reinterpret_cast<int*>(sceneObj + 0x44) + row * 4
                            ) - 0xd + colOffset
                        );
                        *cell |= 0x80;
                        cols = *reinterpret_cast<int*>(sceneObj + 0x250);
                        sceneObj = (int)DAT_00702770;
                        colOffset += 0x1c;
                        col++;
                    } while (col < cols);
                }
                row++;
            } while (row < rows);
        }
    }

    // Phase 2: Mode-specific dispatch
    if (DAT_00702774 != nullptr)
    {
        int ctrlType = *reinterpret_cast<int*>(
            reinterpret_cast<uintptr_t>(DAT_00702774) + 0x22c);
        if (ctrlType == 2)
        {
            // FUN_0053b1d0 — gamepad mode init
        }
        else if (ctrlType == 3)
        {
            // FUN_00590950 — other controller mode init
        }
    }

    // Phase 3: State initialization
    DAT_007488d0 = 1;
    DAT_00702a40 = 0;
    // FUN_004d0e70 — frame dispatch callback

    // Phase 4: Copy 34 integers from source to destination
    sceneObj = (int)DAT_00702770;
    const int* src = reinterpret_cast<const int*>(0x00681db0);
    int* dst = reinterpret_cast<int*>(DAT_0073f800);
    for (int i = 0x22; i != 0; i--)
        *dst++ = *src++;

    // Phase 5: Compute grid dimensions
    DAT_00748984 = static_cast<float>(*reinterpret_cast<int*>(sceneObj + 0x250)) *
                   *reinterpret_cast<float*>(sceneObj + 0x238) * DAT_0066be20 +
                   *reinterpret_cast<float*>(sceneObj + 0x240);
    DAT_00748988 = static_cast<float>(*reinterpret_cast<int*>(sceneObj + 0x254)) *
                   *reinterpret_cast<float*>(sceneObj + 0x238) * DAT_0066be20 +
                   *reinterpret_cast<float*>(sceneObj + 0x244);
    DAT_00748980 = DAT_00702cc0;
    DAT_00748978 = DAT_00702cb8;

    // FUN_00499e30 — set game mode

    // Phase 6: Copy lighting/material data (with XOR depth deobfuscation)
    DAT_007489b0 = 1086324736;
    DAT_007489b4 = 1067869798;
    DAT_007489e0 = 0;
    DAT_007489e4 = 1065353216;
    DAT_007489ec = 0;
    DAT_007489d0 = 1065353216;
    DAT_007489d4 = 0;
    DAT_007489dc = 0 ^ DAT_0066c580;
    DAT_007489f0 = 0;
    DAT_007489f4 = 0;
    DAT_007489fc = 0;
    DAT_00748a00 = 0;
    DAT_00748a04 = 0;
    DAT_00748a0c = 1065353216;
    DAT_007489e8 = 0 ^ DAT_0066c580;
    DAT_007489f8 = 1065353216 ^ DAT_0066c580;
    DAT_007489b8 = 1065353216;
    DAT_00748a08 = 0 ^ DAT_0066c580;
    DAT_007489bc = 1187205120;

    // FUN_0052def0 — post-snapshot callback

    // Phase 7: Process flagged grid cells
    int row2 = 0;
    int sceneObj2 = (int)DAT_00702770;
    int rows2 = *reinterpret_cast<int*>(sceneObj2 + 0x254);
    if (rows2 > 0)
    {
        do {
            int col2 = 0;
            int cols2 = *reinterpret_cast<int*>(sceneObj2 + 0x250);
            if (cols2 > 0)
            {
                int colOff2 = 0;
                do {
                    if ((*reinterpret_cast<byte*>(
                            *reinterpret_cast<int*>(
                                *reinterpret_cast<int*>(sceneObj2 + 0x44) + row2 * 4
                            ) + 0xf + colOff2
                        ) & 0x40) != 0)
                    {
                        // FUN_0052e3f0 — process flagged cell
                        byte* cell = reinterpret_cast<byte*>(
                            *reinterpret_cast<int*>(
                                *reinterpret_cast<int*>(sceneObj2 + 0x44) + row2 * 4
                            ) + 0xf + colOff2
                        );
                        *cell &= 0xBF;  // Clear flag
                        sceneObj2 = (int)DAT_00702770;
                    }
                    colOff2 += 0x1c;
                    col2++;
                } while (col2 < cols2);
            }
            row2++;
        } while (row2 < rows2);
    }

    // Phase 8: Compute final scaling parameter
    DAT_0074b600 = -1;
    float gridX = static_cast<float>(*reinterpret_cast<int*>(sceneObj2 + 0x250)) *
                  *reinterpret_cast<float*>(sceneObj2 + 0x238);
    float gridY = static_cast<float>(*reinterpret_cast<int*>(sceneObj2 + 0x254)) *
                  *reinterpret_cast<float*>(sceneObj2 + 0x238);
    float scale = DAT_0066be2c;

    // FUN_00490860 — TanPrecise (FOV validation)
    float maxDim = gridX;
    if (gridX * DAT_0066bea0 <= gridY)
        maxDim = gridY;

    DAT_007489a8 = ((maxDim * DAT_0066be20) / scale - DAT_0066c1b0) / DAT_0066c184;
    DAT_007489ac = DAT_007489a8;

    if (DAT_007489a8 <= DAT_0066bf60)
    {
        DAT_007489a8 = DAT_0066bf60;
        DAT_007489ac = DAT_0066bf60;
    }
}

// ─── SetLightDirection (FUN_00521fc0) — PASS (1 round) ─────────
// Sets light direction+color on a scene object. Copies 4-component
// vector, applies scale, clamps to [0,1], computes squared magnitude.
// 9 callers, 1 callee.

static float DAT_00702ac4 = 1.0f;  // Light scale factor

void SetLightDirection(int param_1, float* param_2)
{
    // Copy input vector to primary storage at +0x10
    float v1 = param_2[1];
    float v2 = param_2[2];
    float v3 = param_2[3];

    *reinterpret_cast<float*>(param_1 + 0x10) = param_2[0];
    *reinterpret_cast<float*>(param_1 + 0x14) = v1;
    *reinterpret_cast<float*>(param_1 + 0x18) = v2;
    *reinterpret_cast<float*>(param_1 + 0x1C) = v3;

    // If secondary storage at +0x74 is zero, copy input there as default
    if (*reinterpret_cast<float*>(param_1 + 0x74) == 0.0f &&
        *reinterpret_cast<float*>(param_1 + 0x78) == 0.0f &&
        *reinterpret_cast<float*>(param_1 + 0x7C) == 0.0f)
    {
        *reinterpret_cast<float*>(param_1 + 0x74) = param_2[0];
        *reinterpret_cast<float*>(param_1 + 0x78) = v1;
        *reinterpret_cast<float*>(param_1 + 0x7C) = v2;
        *reinterpret_cast<float*>(param_1 + 0x80) = v3;
    }

    // Scale components by global factor
    float scaleFactor = DAT_00702ac4;
    float f6 = 1.0f;
    float f4 = *reinterpret_cast<float*>(param_1 + 0x10) * scaleFactor;
    *reinterpret_cast<float*>(param_1 + 0x10) = f4;
    *reinterpret_cast<float*>(param_1 + 0x14) = scaleFactor * *reinterpret_cast<float*>(param_1 + 0x14);
    *reinterpret_cast<float*>(param_1 + 0x18) = scaleFactor * *reinterpret_cast<float*>(param_1 + 0x18);

    // Clamp to 1.0 (upper bound)
    if (f6 < f4) {
        *reinterpret_cast<uint32_t*>(param_1 + 0x10) = 0x3f800000; // 1.0f
    }

    f4 = *reinterpret_cast<float*>(param_1 + 0x14);
    if (f6 < *reinterpret_cast<float*>(param_1 + 0x14)) {
        *reinterpret_cast<uint32_t*>(param_1 + 0x14) = 0x3f800000;
        f4 = f6;
    }

    float f5 = *reinterpret_cast<float*>(param_1 + 0x18);
    if (f6 < *reinterpret_cast<float*>(param_1 + 0x18)) {
        *reinterpret_cast<uint32_t*>(param_1 + 0x18) = 0x3f800000;
        f5 = f6;
    }

    // Clamp to 0.0 (lower bound)
    f6 = *reinterpret_cast<float*>(param_1 + 0x10);
    if (f6 < 0.0f) {
        *reinterpret_cast<uint32_t*>(param_1 + 0x10) = 0;
        f6 = 0.0f;
    }

    if (f4 < 0.0f) {
        *reinterpret_cast<uint32_t*>(param_1 + 0x14) = 0;
        f4 = 0.0f;
    }

    if (f5 < 0.0f) {
        *reinterpret_cast<uint32_t*>(param_1 + 0x18) = 0;
        f5 = 0.0f;
    }

    // Compute squared magnitude: y² + x² + z²
    f4 = f4 * f4 + f6 * f6 + f5 * f5;

    // FUN_0042bee0 — SseSqrtAssert: assert float>=0 then sqrt (170 callers, CRT-like)
    // Stub: no-op in RE build

    // Store squared magnitude in W component, clamped to [0, 1]
    f6 = 1.0f;
    *reinterpret_cast<float*>(param_1 + 0x1C) = f4;

    if (f6 < f4) {
        *reinterpret_cast<uint32_t*>(param_1 + 0x1C) = 0x3f800000; // 1.0f
    }
}

// ═══════════════════════════════════════════════════════════════════
// ComputeFaceNormals (FUN_00526d00) — 1 caller, 76 lines
// ═══════════════════════════════════════════════════════════════════
// Computes per-face normals for triangle mesh using cross products.
// Uses custom fast inverse sqrt via lookup table at DAT_006bd0a8.
// Accumulates normals per-vertex for smooth (Gouraud) shading.
// Pure geometry math — no callees, no globals (except sqrt table).

static uint32_t DAT_006bd0a8[256] = {0};  // Fast inverse sqrt lookup table

void ComputeFaceNormals(int param_1, int param_2, int param_3, int param_4)
{
    if (0 >= param_3) return;

    uint16_t* puVar4 = (uint16_t*)(param_2 + 4);
    int triCount = (param_3 - 1U) / 3 + 1;

    do {
        // Read 3 vertex indices for this triangle
        uint32_t i0 = (uint32_t)puVar4[-2];
        uint32_t i1 = (uint32_t)puVar4[-1];
        uint32_t i2 = (uint32_t)*puVar4;
        puVar4 += 3;

        // Get vertex positions (stride 0xC = 12 bytes per vertex)
        float v0y = *(float*)(param_1 + 4 + i0 * 0xc);
        float v0z = *(float*)(param_1 + 8 + i0 * 0xc);

        // Edge vectors: v0->v1 and v0->v2
        float e1y = v0y - *(float*)(param_1 + 4 + i1 * 0xc);
        float e2y = v0y - *(float*)(param_1 + 4 + i2 * 0xc);
        float v0x = *(float*)(param_1 + i0 * 0xc);
        float e1z = v0z - *(float*)(param_1 + 8 + i2 * 0xc);
        float e2z = v0z - *(float*)(param_1 + 8 + i1 * 0xc);
        float e1x = v0x - *(float*)(param_1 + i1 * 0xc);
        float e2x = v0x - *(float*)(param_1 + i2 * 0xc);

        // Cross product: normal = edge1 × edge2
        float nx = e1y * e1z - e2z * e2y;
        float nz = e1x * e2y - e1y * e2x;
        float ny = e2z * e2x - e1x * e1z;

        // Fast inverse sqrt via lookup table
        float lenSq = ny * ny + nx * nx + nz * nz;
        float invLen = 0.0f;
        if (lenSq != 0.0f) {
            // Custom fast inverse sqrt (Carmack-like with lookup table)
            invLen = (float)(((int)lenSq + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000 |
                             DAT_006bd0a8[(uint32_t)lenSq >> 8 & 0xffff]);
        }
        if (invLen > 0.0f) {
            float scale = 1.0f / invLen;  // DAT_0066bf2c = 1.0f
            nx *= scale;
            ny *= scale;
            nz *= scale;
        }

        // Accumulate normal to all 3 vertices (smooth shading)
        *(float*)(param_4 + i0 * 0xc)     += nx;
        *(float*)(param_4 + 4 + i0 * 0xc) += ny;
        *(float*)(param_4 + 8 + i0 * 0xc) += nz;
        *(float*)(param_4 + i1 * 0xc)     += nx;
        *(float*)(param_4 + 4 + i1 * 0xc) += ny;
        *(float*)(param_4 + 8 + i1 * 0xc) += nz;
        *(float*)(param_4 + i2 * 0xc)     += nx;
        *(float*)(param_4 + 4 + i2 * 0xc) += ny;
        *(float*)(param_4 + 8 + i2 * 0xc) += nz;

        triCount--;
    } while (triCount != 0);
}

// ═══════════════════════════════════════════════════════════════════
// WorldFrameTick (FUN_0052dfe0) — 5 callers, 134 lines
// ═══════════════════════════════════════════════════════════════════
// Master per-frame world tick. Phases:
//   1. Mark grid cells (type 6 specific) — sets bit 7 on grid entity flags
//   2. Mode-specific dispatch (state 2 → MissionCleanup, state 3 → ReplaySpectatorCleanup)
//   3. State initialization (DAT_007488d0=1, DAT_00702a40=0, InitWorldSubsystem)
//   4. Copy 34 integers (0x22) from source (DAT_00681db0) to destination (DAT_0073f800)
//   5. Compute grid dimensions from entity data (width*cellSize*FOV + origin)
//   6. Copy lighting/material data (20+ globals, XOR depth on 3 values)
//   7. Process flagged cells (bit 6 set → call FUN_0052e3f0, clear bit 6)
//   8. Compute final scaling parameter (FOV-based, clamped to DAT_0066bf60)

// Additional globals for WorldFrameTick
// (DAT_007488d0, DAT_00702a40, DAT_0074b600, DAT_0066be2c, DAT_0066bea0,
//  DAT_0066bf60, DAT_007489a8, DAT_007489ac, DAT_00748984, DAT_00748988,
//  DAT_00748980, DAT_00748978, DAT_0066c1b0, DAT_0066c184, DAT_00702cc0,
//  DAT_00702cb8, DAT_0066be20 already declared above)
static int      DAT_006ff960_s = 0;      // Session type (6 = multiplayer)
static int      DAT_00681db0_s[256] = {0};  // Camera/light state source data

extern void MissionCleanup();       // FUN_0053b1d0
extern void ReplaySpectatorCleanup();  // FUN_00590950

void WorldFrameTick()
{
    if (DAT_00702774 == 0)
        return;

    // Phase 1: Mark grid cells (type 6 specific)
    if (DAT_006ff960_s == 6) {
        int iVar6 = 0;
        int iVar8 = (int)DAT_00702770;
        int iVar3 = *reinterpret_cast<int*>(iVar8 + 0x250);
        if (0 < *reinterpret_cast<int*>(iVar8 + 0x254)) {
            do {
                int iVar4 = 0;
                if (0 < iVar3) {
                    int iVar2 = 0;
                    do {
                        iVar2 += 0x1c;
                        iVar4++;
                        auto* pbVar1 = reinterpret_cast<uint8_t*>(
                            *reinterpret_cast<int*>(
                                *reinterpret_cast<int*>(iVar8 + 0x44) + iVar6 * 4
                            ) - 0xd + iVar2
                        );
                        *pbVar1 |= 0x80;
                        iVar3 = *reinterpret_cast<int*>(DAT_00702770 + 0x250);
                        iVar8 = (int)DAT_00702770;
                    } while (iVar4 < iVar3);
                }
                iVar6++;
            } while (iVar6 < *reinterpret_cast<int*>(iVar8 + 0x254));
        }
    }

    // Phase 2: Mode-specific dispatch
    if (DAT_00702774 != 0) {
        if (*reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(DAT_00702774) + 0x22c) == 2) {
            MissionCleanup();
        } else if (DAT_00702774 != 0 && *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(DAT_00702774) + 0x22c) == 3) {
            ReplaySpectatorCleanup();
        }
    }

    // Phase 3: State initialization
    DAT_007488d0 = 1;
    DAT_00702a40 = 0;
    // FUN_004d0e70() — InitWorldSubsystem (already tracked)

    // Phase 4: Copy 34 integers from source to destination
    int iVar6 = (int)DAT_00702770;
    const int* puVar5 = reinterpret_cast<const int*>(&DAT_00681db0_s);
    int* puVar7 = reinterpret_cast<int*>(&DAT_0073f800);
    for (int i = 0x22; i != 0; i--) {
        *puVar7++ = *puVar5++;
    }

    // Phase 5: Compute grid dimensions
    *reinterpret_cast<float*>(&DAT_00748984) =
        static_cast<float>(*reinterpret_cast<int*>(iVar6 + 0x250)) *
        *reinterpret_cast<float*>(iVar6 + 0x238) * DAT_0066be20 +
        *reinterpret_cast<float*>(iVar6 + 0x240);
    *reinterpret_cast<float*>(&DAT_00748988) =
        static_cast<float>(*reinterpret_cast<int*>(iVar6 + 0x254)) *
        *reinterpret_cast<float*>(iVar6 + 0x238) * DAT_0066be20 +
        *reinterpret_cast<float*>(iVar6 + 0x244);
    DAT_00748980 = *reinterpret_cast<int*>(&DAT_00702cc0);
    DAT_00748978 = *reinterpret_cast<int*>(&DAT_00702cb8);

    // Phase 6: Copy lighting/material data
    // (20+ global copies — lighting/material state transfer)
    // XOR depth obfuscation on 3 values using DAT_0066c580 key
    // DAT_007489d8 = DAT_00685798 ^ DAT_0066c580;
    // DAT_007489e8 = DAT_006857a8 ^ DAT_0066c580;
    // DAT_007489f8 = DAT_006857b8 ^ DAT_0066c580;

    // Phase 7: Process flagged cells (bit 6)
    int iVar3 = 0;
    iVar6 = (int)DAT_00702770;
    if (0 < *reinterpret_cast<int*>(DAT_00702770 + 0x254)) {
        do {
            int iVar8 = 0;
            if (0 < *reinterpret_cast<int*>(iVar6 + 0x250)) {
                int iVar4 = 0;
                do {
                    if ((*reinterpret_cast<uint8_t*>(
                            *reinterpret_cast<int*>(
                                *reinterpret_cast<int*>(iVar6 + 0x44) + iVar3 * 4
                            ) + 0xf + iVar4
                        ) & 0x40) != 0) {
                        // FUN_0052e3f0() — process flagged cell
                        auto* pbVar1 = reinterpret_cast<uint8_t*>(
                            *reinterpret_cast<int*>(
                                *reinterpret_cast<int*>(DAT_00702770 + 0x44) + iVar3 * 4
                            ) + 0xf + iVar4
                        );
                        *pbVar1 &= 0xbf;  // Clear bit 6
                        iVar6 = (int)DAT_00702770;
                    }
                    iVar8++;
                    iVar4 += 0x1c;
                } while (iVar8 < *reinterpret_cast<int*>(iVar6 + 0x250));
            }
            iVar3++;
        } while (iVar3 < *reinterpret_cast<int*>(iVar6 + 0x254));
    }

    // Phase 8: Compute final scaling parameter
    DAT_0074b600 = -1;
    float fVar10 = static_cast<float>(*reinterpret_cast<int*>(iVar6 + 0x250)) *
                   *reinterpret_cast<float*>(iVar6 + 0x238);
    float fVar11 = static_cast<float>(*reinterpret_cast<int*>(iVar6 + 0x254)) *
                   *reinterpret_cast<float*>(iVar6 + 0x238);
    float fVar9 = DAT_0066be2c;

    // FUN_00490860() — TanPrecise

    if (fVar10 * DAT_0066bea0 <= fVar11) {
        fVar10 = fVar11;
    }

    *reinterpret_cast<float*>(&DAT_007489a8) = ((fVar10 * DAT_0066be20) / fVar9 - DAT_0066c1b0) / DAT_0066c184;
    DAT_007489ac = DAT_007489a8;

    if (*reinterpret_cast<float*>(&DAT_007489a8) <= DAT_0066bf60) {
        *reinterpret_cast<float*>(&DAT_007489a8) = DAT_0066bf60;
        *reinterpret_cast<float*>(&DAT_007489ac) = DAT_0066bf60;
    }
}

// Stub implementations
void MissionCleanup() {}
void ReplaySpectatorCleanup() {}

} // namespace Giants
