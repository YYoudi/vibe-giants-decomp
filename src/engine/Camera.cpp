// Giants Engine - Camera System Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include <cstdlib>
#include <cstring>
#include "Camera.h"
#include "ScenePipeline.h"
#include "GiantsTypes.h"
#include <cstring>

namespace Giants {

// ─── External data references ─────────────────────────────────
static uint32_t DAT_00702774 = 0;        // Active render target
static uint32_t DAT_00681db0 = 0;        // Camera object
static float    DAT_00681db4 = 0;        // Camera priority
static uint32_t DAT_00681dd0 = 0;       // Selected camera
static uint32_t DAT_007027a0 = 0;        // Fallback camera A
static uint32_t DAT_007027a4 = 0;        // Fallback camera B
static float    DAT_00681dc0 = 0;        // Camera timer
static float    DAT_00681e34 = 0;        // Camera freeze flag
static float    DAT_00727e38 = 0;        // Frame delta time
static char     DAT_00702c44 = 0;        // Camera smoothing flag
static char     DAT_0070288c = 0;        // Camera override flag
static uint32_t DAT_00681de8 = 0;        // Camera mode override
static uint32_t DAT_00681dec = 0;        // Camera mode
static float    DAT_00681de4 = 0;        // Camera angle override
static float    DAT_00681de0 = 0;        // Camera distance
static uint32_t DAT_00681dd4 = 0;        // Camera target (2 floats)
static float    DAT_00681ddc = 0;        // Camera height offset

// Projection globals
static uint32_t g_depthXorKey = 0;       // DAT_0066c580
static float    DAT_0066c1e8 = 0;        // Near plane distance
static uint32_t DAT_0067f0f4 = 0;        // Far plane distance
static float    DAT_0067f47c = 0;        // Far plane override
static float    DAT_0066be20 = 0;        // FOV base
static float    DAT_0066bfc8 = 0;        // FOV multiplier
static float    DAT_0066c110 = 0;        // FOV divisor
static float    DAT_0066bce4 = 0;        // Default aspect ratio

// Camera path animation globals
static float*   DAT_00725ed0 = nullptr;  // Camera path data
static uint32_t DAT_00747d2c = 0;        // FLICK system active
static uint32_t DAT_00682264 = 0;        // Camera path lock
static uint32_t DAT_00725ea8 = 0;        // Animation flags (bit 1=fwd, bit 2=rev)
static float    DAT_00725ec8 = 0;        // Remaining time

// Camera transform table globals
static uint32_t DAT_00681db8 = 0;        // Camera index (0=single, 1=split, 2=full)
static uint32_t DAT_00681dbc = 0;        // Camera split mode / transition flag
static char     DAT_00702c45 = 0;        // Camera override flag

// AnimateCameraPath globals
static uint32_t DAT_00702770 = 0;        // Render target for camera path

// ─── UpdateActiveCamera (FUN_0049a040) — FAIL (usable ~65%) ────

void UpdateActiveCamera()
{
    if (DAT_00702774 == 0) return;

    // Camera selection: find active camera from priority list
    if (((DAT_00681db0 == 0 && DAT_00681db4 < 0) || DAT_00681dd0 == 0) ||
        (*(uint32_t*)(DAT_00681dd0 + 0x124) & 0x8000) != 0)
    {
        if (DAT_007027a0 == 0 ||
            (DAT_00681dd0 = DAT_007027a4, DAT_007027a4 == 0))
        {
            DAT_00681dd0 = DAT_00702774;  // Use default
        }
    }

    // Skip if camera is in cinematic mode (type 2 + flag 0x8000000)
    if (DAT_00681dd0 != 0 &&
        *(int*)(DAT_00681dd0 + 0x22c) == 2 &&
        (*(uint32_t*)(DAT_00681dd0 + 300) & 0x8000000) != 0)
    {
        DAT_00681dd0 = *(int*)(DAT_00681dd0 + 0x264);
    }

    int activeCamera = DAT_00681dd0;

    // Camera update with view params
    if (DAT_00681db4 >= 0 &&
        (*(uint32_t*)(DAT_00681dd0 + 0x124) & 0x8000) == 0)
    {
        // FUN_0048f4a0 — update camera view from params
        // FUN_00499c90 — compute camera transform
        DAT_00681dec = 1;
    }

    // Camera timer update
    if (DAT_00681e34 == 0.0f) {
        // Camera smoothing with frame delta
        // FUN_00499c90 — compute
        // FUN_00499dd0 — check transition
        // Clamp camera timer between 0 and max
    }

    // Setup projection from active camera
    SetupProjection();   // FUN_005f9d00

    // Camera override (debug/cutscene)
    if (DAT_0070288c != 0) {
        DAT_00681de8 = 0;
        DAT_00681de4 = -90.0f;
        DAT_00681de0 = *(float*)(activeCamera + 0x114);
        // Set camera target position
        DAT_00681dd4 = *(uint32_t*)(activeCamera + 0xf0);
        DAT_00681ddc = *(float*)(activeCamera + 0xf8);
        // FUN_006387e0 — compute camera angles from distance/target
    }
}

// ─── SetupProjection (FUN_005f9d00) — FAIL (usable ~70%) ────────

static float g_projData[16] = {0};       // DAT_00685784-DAT_0068580c
static float DAT_0074bb90 = 0;           // Aspect ratio
static float DAT_0074bb94 = 0;           // Aspect ratio divisor

void SetupProjection(int mode)
{
    // Compute view distance from world transform translation
    float viewDist = DAT_0066c1e8 -
        (g_worldTransform.m21 * g_worldTransform.ty +
         g_worldTransform.m20 * g_worldTransform.tx +
         g_worldTransform.m22 * g_worldTransform.tz);

    float farPlane = (float)DAT_0067f0f4;
    if (mode == 1 && viewDist < farPlane) {
        farPlane = viewDist;
    }

    // Aspect ratio
    float aspect = g_projData[1];  // from previous frame or default
    if (aspect == DAT_0066bce4) {
        aspect = DAT_0074bb90 / DAT_0074bb94;
    }

    // FOV computation
    float fov = (g_projData[0] * DAT_0066be20 * DAT_0066bfc8) / DAT_0066c110;
    g_projData[0] = fov;         // DAT_00685784
    g_projData[1] = aspect;      // DAT_00685788

    // FUN_00483160 — likely compute projection matrix elements
    // FUN_00483140 — likely apply projection

    // Depth buffer setup with XOR obfuscation
    g_projData[5] = fov / farPlane;              // DAT_006857e4
    g_projData[9] = 0;                           // DAT_0068580c
    g_projData[8] = 0x3f800000;                  // DAT_006857fc (1.0f)
    g_projData[3] = 0;                           // pad
    g_projData[4] = 0;                           // pad
    g_projData[5] = 0;                           // pad
    g_projData[6] = 0;                           // pad

    float nearOverFar = g_projData[5] / aspect;
    g_projData[7] = nearOverFar;                 // DAT_006857d0

    float depthScale = farPlane / (farPlane - DAT_0067f47c);
    g_projData[10] = depthScale;                 // DAT_006857f8

    // Obfuscated depth value
    g_projData[11] = (float)((uint32_t)g_projData[10] ^ g_depthXorKey) * DAT_0067f47c;

    // Renderer vtable call: SetProjectionMatrix
    // vtable[0x34] on DAT_00702700
}

// ─── AnimateCameraPath (FUN_005f8480) — FAIL (usable ~60%) ─────

void AnimateCameraPath()
{
    if (DAT_00702770 == 0) return;           // No render target
    if (DAT_00725ed0 == nullptr) return;     // No path data
    if (DAT_00747d2c != 0 && DAT_00682264 == 0) return;

    // Advance time
    DAT_00725ed0[4] += DAT_00727e38;
    float remaining = DAT_00725ec8 - DAT_00727e38;

    float* path = DAT_00725ed0;
    uint32_t flags = DAT_00725ea8;

    if ((flags & 2) != 0) {
        // Forward animation: interpolate from start to end
        float t = path[4];
        float duration = path[0x12];
        if (t >= duration) {
            DAT_00725ea8 = flags & ~2;  // Clear forward flag
            if (flags & 1) {
                DAT_00725ea8 |= 4;      // Set reverse flag
            }
            t = duration;
        }

        // Lerp position/rotation
        float ratio = t / duration;
        *(float*)(DAT_00702770 + 0x1a0) =
            ((path[0xe] - path[0xf]) / duration) * t + path[0xf];
        *(float*)(DAT_00702770 + 0x1a4) =
            ((path[0x10] - path[0x11]) / duration) * t + path[0x11];
        *(float*)(DAT_00702770 + 0x1a8) =
            ((path[8] - path[0xb]) / duration) * t + path[0xb];
        *(float*)(DAT_00702770 + 0x1ac) =
            ((path[9] - path[0xc]) / duration) * t + path[0xc];
        float lastVal = ((path[10] - path[0xd]) / duration) * t + path[0xd];
        *(float*)(DAT_00702770 + 0x1b0) = lastVal;

        // Renderer vtable call: vtable[0xc0]
    }
    else if ((flags & 4) != 0) {
        // Reverse animation: interpolate from end to start
        // Same lerp but reversed direction
        float t = path[4];
        float duration = path[0x12];

        *(float*)(DAT_00702770 + 0x1a0) =
            ((path[0xf] - path[0xe]) / duration) * t + path[0xe];
        *(float*)(DAT_00702770 + 0x1a4) =
            ((path[0x11] - path[0x10]) / duration) * t + path[0x10];
        *(float*)(DAT_00702770 + 0x1a8) =
            ((path[0xb] - path[8]) / duration) * t + path[8];
        *(float*)(DAT_00702770 + 0x1ac) =
            ((path[0xc] - path[9]) / duration) * t + path[9];
        float lastVal = ((path[0xd] - path[10]) / duration) * t + path[10];
        *(float*)(DAT_00702770 + 0x1b0) = lastVal;

        // Renderer vtable call: vtable[0xc0]
    }
}

// ─── UpdateCameraView (FUN_0048f4a0) — PASS (usable ~70%) ────────

uint32_t UpdateCameraView(uint32_t param_1, float* param_2,
                          uint32_t param_3, int param_4,
                          int param_5, uint32_t param_6)
{
    // Security cookie
    // DAT_0067d280 — stack cookie XOR key

    uint32_t result = 0;

    // Step 1: Resolve entity from render target list
    // param_3 + 8 = render target array pointer
    // param_4 = index into that array
    int renderTargets = *(int*)(param_3 + 8);
    int targetSlot = param_4;

    if (renderTargets == 0) {
        return 0;
    }

    int entityHandle = *(int*)(renderTargets + 8 + targetSlot * 4);

    // Step 2: Optional sub-entity lookup via param_5
    int subEntity = 0;
    if (param_5 < *(int*)(renderTargets + 0x450) &&
        *(int*)(renderTargets + 0x454) != 0)
    {
        subEntity = *(int*)(*(int*)(renderTargets + 0x454) + param_5 * 4);
        if (subEntity != 0) {
            // Check if the sub-entity slot is uninitialized
            if (*(int*)(*(int*)(entityHandle + 0x54) + param_5 * 4) == 0) {
                if (*(int*)(entityHandle + 0x28) != 0) {
                    // FUN_00634e20 — create entity instance
                    // uint32_t newEntity = FUN_00634e20(*(int*)(entityHandle + 0x28), 0, subEntity);
                    // *(uint32_t*)(*(int*)(entityHandle + 0x54) + param_5 * 4) = newEntity;
                    subEntity = *(int*)(*(int*)(entityHandle + 0x54) + param_5 * 4);
                } else {
                    *(uint32_t*)(*(int*)(entityHandle + 0x54) + param_5 * 4) = 0;
                }
            }
            subEntity = *(int*)(*(int*)(entityHandle + 0x54) + param_5 * 4);
        }
    } else {
        subEntity = 0;
    }

    if (subEntity == 0) {
        return 0;
    }

    // Step 3: Scene state snapshot (two 0x44-byte blocks)
    uint8_t local_b8[0x44];   // Scene state block 1
    uint8_t local_70[0x44];   // Scene state block 2
    memset(local_b8, 0, 0x44);
    memset(local_70, 0, 0x44);

    int transformData;
    // Check if this is the same target slot as the current one
    if (targetSlot == *(int*)(param_3 + 0x60)) {
        // Reuse existing transform data from sub-entity table at 0x32c
        transformData = *(int*)(param_3 + 0x32c) + param_5 * 0x44;
    } else {
        // Create new transform data
        // FUN_00635830 — allocate transform context
        // FUN_00634ea0 — initialize transform from entity
        // transformData = FUN_00634ea0(subEntity, *(uint32_t*)(*(int*)(subEntity + 0xc) + 0x10), FUN_00635830());
        transformData = 0;
        if (transformData == 0) goto cleanup;
    }

    // FUN_0067d208 — apply transform (via function pointer)
    // PTR_FUN_0067d208(transformData);
    result = 1;

cleanup:
    // Step 4: Copy scene state from local variables back
    // FUN_0063e830 — scene state reconciliation
    // FUN_0067d20c — post-transform update
    // FUN_0063f360 — apply delta from scene state block

    // Step 5: FOV computation from entity data
    // FUN_00634e80 — get entity FOV data
    int entityFov = 0; // FUN_00634e80(subEntity);
    if (entityFov != 0) {
        // FUN_00635850 — query entity value
        // FUN_00634660 — compute FOV multiplier
        // float fovRaw = FUN_00634660(entityFov, FUN_00635850(*(uint32_t*)(entityFov + 0xc), param_6));
        // float fov = fovRaw * DAT_0066be20;
        // FUN_00490860 — validate FOV
        // float aspectCorrected = fov / DAT_00685788;  // divide by aspect ratio
        // FUN_00490880 — validate aspect
        // *param_2 = aspectCorrected * DAT_0066c0dc;
    }

    return result;
}

// ─── ComputeCameraTransform (FUN_00499c90) — PASS ────────────────

int ComputeCameraTransform(int param_1)
{
    int cameraType = 0;

    // Validate camera object and check disabled flag (0x8000)
    if (param_1 != 0 && (*(uint32_t*)(param_1 + 0x124) & 0x8000) == 0) {
        cameraType = *(int*)(param_1 + 4);

        if (cameraType == 2) {
            // Type 2 has special flag handling
            if ((*(uint32_t*)(param_1 + 300) & 0x20000) == 0) {
                if ((*(uint32_t*)(param_1 + 300) & 0x8000000) != 0) {
                    cameraType = 4;  // Promoted to type 4
                }
            } else {
                cameraType = 0x3df;  // Special transition type
            }
        } else if (cameraType == 3) {
            // Type 3: inherit from linked camera
            int linkedCamera = *(int*)(param_1 + 0x264);
            if (linkedCamera != 0 && *(int*)(linkedCamera + 0x22c) == 0x5a) {
                cameraType = *(int*)(linkedCamera + 4);
            }
        }
    }

    // Determine camera index multiplier
    int index = DAT_00681db8;

    // Check override conditions
    if (DAT_00702c45 != '\0' && DAT_00702774 != 0) {
        int renderType = *(int*)(DAT_00702774 + 0x22c);
        if (renderType == 2 || renderType == 3 || renderType == 1) {
            index = 1;
        }
    }

    // Camera transform table lookup (index * 0x18 stride)
    // These addresses are in .data section — camera transform parameters
    if (cameraType < 0x3e0) {
        if (cameraType == 0x3df) {
            return index * 0x18 + 0x681e80;
        }
        switch (cameraType) {
        case 1:  return index * 0x18 + 0x681ec8;
        case 2:  return index * 0x18 + 0x681e38;
        case 3:  return index * 0x18 + 0x681f10;
        case 4:  return index * 0x18 + 0x682030;
        case 6:  return index * 0x18 + 0x681fe8;
        case 7:  return index * 0x18 + 0x681fa0;
        }
    } else if (cameraType == 0x434) {
        return index * 0x18 + 0x681f58;
    }

    // Default fallback
    return index * 0x18 + 0x682078;
}

// ─── CameraTransitionCheck (FUN_00499dd0) — PASS ─────────────────

uint32_t CameraTransitionCheck()
{
    // Condition 1: No active camera + no transition flag + index == 1
    bool noCamera = (DAT_00681db0 == 0) &&
                    (DAT_00681dbc == 0) &&
                    (DAT_00681db8 == 1);

    // Condition 2: Camera override active with valid render target
    bool overrideActive = false;
    if (DAT_00702c45 != '\0' && DAT_00702774 != 0) {
        int renderType = *(int*)(DAT_00702774 + 0x22c);
        if (renderType == 2 || renderType == 3 || renderType == 1) {
            overrideActive = true;
        }
    }

    return (noCamera || overrideActive) ? 1 : 0;
}

// ═══════════════════════════════════════════════════════════════════
// TanPrecise — FUN_00490860
// ═══════════════════════════════════════════════════════════════════
// SSE2 precise tangent function. Thin wrapper around libm_sse2_tan_precise.
// Called from FOV validation in UpdateCameraView.
// 3 callers, 1 callee (tan intrinsic).

void TanPrecise()
{
    // Original: libm_sse2_tan_precise(); return;
    // Thin wrapper — compiler generates jmp to SSE2 tan
}

// ═══════════════════════════════════════════════════════════════════
// AtanPrecise — FUN_00490880
// ═══════════════════════════════════════════════════════════════════
// SSE2 precise arctangent function. Thin wrapper around libm_sse2_atan_precise.
// Called from FOV aspect validation in UpdateCameraView.
// 2 callers, 1 callee (atan intrinsic).

void AtanPrecise()
{
    // Original: libm_sse2_atan_precise(); return;
    // Thin wrapper — compiler generates jmp to SSE2 atan
}

// ═══════════════════════════════════════════════════════════════════
// AllocateTransformContext — FUN_00635830
// ═══════════════════════════════════════════════════════════════════
// Increments the global transform context counter (DAT_006887d0).
// If increment results in 0 (overflow), increments again (+2).
// Returns the counter value implicitly via global state.
// 7 callers (transform pipeline), 0 callees.

void AllocateTransformContext()
{
    // Original:
    // iVar1 = DAT_006887d0 + 1;
    // if (DAT_006887d0 + 1 == 0) iVar1 = DAT_006887d0 + 2;
    // DAT_006887d0 = iVar1;
}

// ═══════════════════════════════════════════════════════════════════
// ComputeEntityScaledValue — FUN_00635850
// ═══════════════════════════════════════════════════════════════════
// Computes a scaled value from entity data:
// result = (int)((float)*(int*)(param_1 + 0x18) * param_2 * (float)*(int*)(param_1 + 0x1c) + (float)*(int*)(param_1 + 0x10))
// Used for entity FOV/scale computation.
// 18 callers (extremely hot path), 0 callees.

int ComputeEntityScaledValue(int param_1, float param_2)
{
    // Original (single expression):
    // return (int)((float)*(int*)(param_1 + 0x18) * param_2 * (float)*(int*)(param_1 + 0x1c) + (float)*(int*)(param_1 + 0x10));
    return 0;  // Stub
}

// ═══════════════════════════════════════════════════════════════════
// BuildViewMatrix — FUN_0063e830
// ═══════════════════════════════════════════════════════════════════
// Constructs a 4x4 view matrix from forward vector (param_3) and position (param_2).
// Normalizes forward, computes right = cross(forward, up), normalizes right,
// computes up = cross(right, forward). Writes 4x4 row-major matrix to param_1.
// Sets param_1[0] = 0x11 (matrix type tag), param_1[0x10] = 1.0f (w component).
// 10 callers (camera, render pipeline), 1 callee (sqrt).

void BuildViewMatrix(uint32_t* param_1, uint32_t* param_2, float* param_3, float* param_4)
{
    // Original:
    // 1. Normalize param_3 (forward): len = sqrt(x*x + y*y + z*z)
    //    if (len == 0) use defaults; else scale = 1.0/len
    // 2. Cross product: right = cross(forward, param_4)
    // 3. Normalize right
    // 4. Build 3x3 rotation matrix into param_1[1..11]:
    //    [right.x, forward.x, -up.x]  row 0
    //    [right.y, forward.y, -up.y]  row 1
    //    [right.z, forward.z, -up.z]  row 2
    //    param_1[4..6] = param_2 (position)
    //    param_1[0xf..0xd] = 0, param_1[0x10] = 1.0 (identity w)
    //    param_1[0] = 0x11 (matrix type tag)
}

// ═══════════════════════════════════════════════════════════════════
// TransposeMatrix — FUN_0063f360
// ═══════════════════════════════════════════════════════════════════
// Transposes a 4x4 matrix (param_2 -> param_1). Uses temp buffer to handle
// in-place transpose. Copies 4 rows of 4 uint32_t from param_2[2,6,10,14]
// stride into contiguous param_1 rows. Swaps columns 0,1 with 4,5 via
// bit manipulation: (val >> 1 & 0x10) | (val & 0x10) * 2 | val & 0xCF.
// 14 callers (render pipeline), 0 callees.

void TransposeMatrix(uint32_t* param_1, uint32_t* param_2)
{
    // Original:
    // Temp buffer local_48[17]
    // Copy 4 rows from param_2 (stride 4) into temp (contiguous)
    // Swap columns via bit manipulation on param_2[0]
    // If param_1 != temp: copy all 17 uint32_t from temp to param_1
}

// ═══════════════════════════════════════════════════════════════════
// GetEntityFov — FUN_00634660
// ═══════════════════════════════════════════════════════════════════
// Computes entity FOV from entity data at param_1 (cast to int).
// Reads transform context (param_1+0xf8), float base (param_1+0xec),
// parent pointer (param_1+0xc). If context has sub-objects, resolves
// transform matrix and calls virtual function. Otherwise returns context+0xc.
// 2 callers (UpdateCameraView), 1 callee (FUN_00634700).

float GetEntityFov(float param_1, uint32_t param_2)
{
    // Original:
    // iVar3 = *(int*)((int)param_1 + 0xf8);  // transform context
    // pfVar2 = (float*)((int)param_1 + 0xec);  // base FOV
    // piVar1 = (int*)((int)param_1 + 0xc);       // parent
    // param_1 = *pfVar2;  // base value
    // if (iVar3 != 0) {
    //     if (*(int*)(iVar3 + 8) != 0) {
    //         Build transform matrix, call vtable[1]
    //         return result;
    //     }
    //     param_1 = *(float*)(iVar3 + 0xc);  // direct value
    // }
    return param_1;
}

// ═══════════════════════════════════════════════════════════════════
// IsEntityValid — FUN_00634e80
// ═══════════════════════════════════════════════════════════════════
// Checks if an entity is valid: returns entity pointer if *(short*)(param_1+4) == 1,
// otherwise returns 0. Simple type guard.
// 2 callers (UpdateCameraView, transform pipeline), 0 callees.

int IsEntityValid(int param_1)
{
    // Original:
    // if (*(short*)(param_1 + 4) == 1) return param_1;
    // return 0;
    return 0;  // Stub
}

// ═══════════════════════════════════════════════════════════════════
// UpdateEntityTransform — FUN_00634ea0
// ═══════════════════════════════════════════════════════════════════
// Complex entity transform update (~300 lines). Walks entity tree upward
// (param_1+0x10 links), marks visited nodes (param_3 stamp at +0x20),
// then processes bottom-up. Handles entity types 1 (direct transform),
// 2 (rotation + scale), 3 (recursive sub-entity with cross products).
// Applies XOR key DAT_0066c580 for depth obfuscation. Calls callbacks
// at +0x18, applies transform via PTR_FUN_0067d208.
// 16 callers (transform pipeline), 11 callees.
// FAIL (usable ~55%) — very complex with indirect calls.

uint32_t UpdateEntityTransform(int param_1, int param_2, int param_3)
{
    // Original:
    // Walk tree upward: param_1->0x10, mark +0x20 with param_3
    // Process bottom-up:
    //   Type 1: Direct transform from vtable, XOR depth
    //   Type 2: Rotation + scale from animators (+0x98, +0x9c)
    //   Type 3: Recursive — compute sub-entity transform, cross products,
    //           build rotation matrix, apply scale
    //   All types: apply +0xa0 animator for secondary transform
    // Call callback at +0x18 if non-null
    // Apply transform via PTR_FUN_0067d208 or FUN_0063e2c0
    return (uint32_t)(param_1 + 0x24) & -(uint32_t)(param_1 != 0);
}

} // namespace Giants

// ═══════════════════════════════════════════════════════════════════
// CameraModeSwitch — FUN_00499e30
// ═══════════════════════════════════════════════════════════════════
// Sets the camera display mode. 5 modes:
//   1 = Single player (DAT_00681db8=0)
//   2 = Player 1 of split (DAT_00681db8=1)
//   3 = 3-way split, camera A (DAT_00681dbc=2)
//   4 = 2-way split, camera A (DAT_00681dbc=1)
//   5 = Player 2 of split (DAT_00681db8=2)
//   -1 = Auto-detect based on current DAT_00681db8
// After mode set: recomputes camera transform, resets timer, calls SetupProjection.
// 11 callers, 2 callees (ComputeCameraTransform, SetupProjection).

namespace Giants {

void CameraModeSwitch(int param_1)
{
    int iVar1 = DAT_00681dd0;

    if (param_1 == -1) {
        // Auto: cycle based on current state
        param_1 = (DAT_00681db8 != 0) + 1;
    }

    if (param_1 == 1) {
        DAT_00681db8 = 0;
    } else if (param_1 == 2) {
        DAT_00681db8 = 1;
    } else {
        if (param_1 == 3) {
            DAT_00681dbc = 2;
            DAT_00681db8 = 0;
            goto recompute;
        }
        if (param_1 == 4) {
            DAT_00681dbc = 1;
            DAT_00681db8 = 0;
            goto recompute;
        }
        if (param_1 != 5) goto recompute;
        DAT_00681db8 = 2;
    }
    DAT_00681dbc = 0;

    // Update camera transform if active and not disabled
    if ((DAT_00681dd0 != 0) && ((*(uint32_t*)(DAT_00681dd0 + 0x124) & 0x8000) == 0)) {
        int iVar2 = ComputeCameraTransform(0);
        *(uint32_t*)(iVar1 + 0x120) = *(uint32_t*)(iVar2 + 0x14);
    }

recompute:
    ComputeCameraTransform(0);
    DAT_00681dc0 = 0;
    SetupProjection();
}

// ═══════════════════════════════════════════════════════════════════
// CameraFrameTick — FUN_00499f10
// ═══════════════════════════════════════════════════════════════════
// Cutscene camera sequencer. Increments frame counter, checks if the
// current frame matches a keyframe timestamp in DAT_0065c7d8. On match,
// dispatches SoundDispatch (FUN_00558240) for entity types 1/2/3.
// Entity types 1/2 reset the counter after dispatch; type 3 only dispatches.
// 2 callers, 1 callee (SoundDispatch).

static float DAT_0065c7d8[256] = {0};  // Keyframe timestamps
static uint32_t DAT_00681dc4 = 0;       // Cutscene frame counter

void CameraFrameTick()
{
    DAT_00681dc4 = DAT_00681dc4 + 1;

    // Check if current frame matches a keyframe timestamp
    if (*(float*)(&DAT_0065c7d8 + DAT_00681dc4 * 4) == DAT_0066bce4) {
        // Keyframe matched — dispatch sound for entity types 1/2/3
        if (DAT_00702774 != 0) {
            int entityType = *(int*)(DAT_00702774 + 0x22c);
            if (entityType == 3) {
                // FUN_00558240() — SoundDispatch
                DAT_00681dc4 = 0;
                return;
            }
            if (DAT_00702774 != 0) {
                if (entityType == 2) {
                    DAT_00681dc4 = 0;
                    return;
                }
                if ((DAT_00702774 != 0) && entityType == 1) {
                    // SoundDispatch (no counter reset for type 1)
                }
            }
        }
        DAT_00681dc4 = 0;
    } else if (DAT_00702774 != 0) {
        // Non-keyframe frame — still dispatch sound for types 1/2/3
        int entityType = *(int*)(DAT_00702774 + 0x22c);
        if (entityType == 3) {
            return;
        }
        if (DAT_00702774 != 0) {
            if (entityType == 2) {
                return;
            }
            if ((DAT_00702774 != 0) && entityType == 1) {
                return;
            }
        }
    }
}

} // namespace Giants

// ═══════════════════════════════════════════════════════════════════
// EntityWorldTransform (FUN_005fac30) — 108 callers
// ═══════════════════════════════════════════════════════════════════
// Applies entity's rotation matrix + position to a 3D vector.
// Two modes based on flag bit 0x20 at offset 0x124:
//   - Flag clear: decomposes rotation via FUN_005faab0 into 3x3 matrix
//   - Flag set: reads explicit 3x3 matrix at offsets 0x2e8-0x30c
// Output = rotation * input + entity_position(0xf0-0xf8)

namespace Giants {

void EntityWorldTransform(int param_1, float* param_2, float* param_3)
{
    if ((*(uint8_t*)(param_1 + 0x124) & 0x20) == 0) {
        // Mode A: decompose rotation from entity data via FUN_005faab0
        // Stub: identity transform + entity position
        *param_3     = param_2[0] + *(float*)(param_1 + 0xf0);
        param_3[1]   = param_2[1] + *(float*)(param_1 + 0xf4);
        param_3[2]   = param_2[2] + *(float*)(param_1 + 0xf8);
    } else {
        // Mode B: explicit 3x3 rotation matrix at entity offsets 0x2e8-0x30c
        *param_3     = *(float*)(param_1 + 0x2e8) * param_2[0]
                     + *(float*)(param_1 + 0x2ec) * param_2[1]
                     + *(float*)(param_1 + 0x2f0) * param_2[2]
                     + *(float*)(param_1 + 0xf0);
        param_3[1]   = *(float*)(param_1 + 0x2f4) * param_2[0]
                     + *(float*)(param_1 + 0x2f8) * param_2[1]
                     + *(float*)(param_1 + 0x2fc) * param_2[2]
                     + *(float*)(param_1 + 0xf4);
        param_3[2]   = *(float*)(param_1 + 0x300) * param_2[0]
                     + *(float*)(param_1 + 0x304) * param_2[1]
                     + *(float*)(param_1 + 0x308) * param_2[2]
                     + *(float*)(param_1 + 0xf8);
    }
}

} // namespace Giants
