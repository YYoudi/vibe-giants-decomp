// Giants Engine - Water System (terrain bump-mapping, waves, texture/shader caps)
// Reverse engineered from FUN_004dfe20, FUN_004dff90, FUN_004e07f0,
//   FUN_004e2180, FUN_004de7d0, FUN_005f9b00, FUN_0042b1f0

#include "WaterSystem.h"
#include <cstdlib>

namespace Giants {

// Forward declarations for external engine functions
extern void operator_delete(void* p, size_t size, size_t alignment);
extern void* FUN_006438b2(size_t size, size_t alignment, uint32_t cookie);
extern void FUN_00643505(void* p, size_t size);

// External globals referenced by these functions
// DAT_00702770 — renderer device object pointer
// DAT_00702700 — renderer vtable base
// DAT_00747c74 — global LandBump context pointer
// DAT_0066bf2c — reference resolution constant (typically 1.0)
// DAT_00702b64 — bump-map quality level (0=off, 1+=on)
// DAT_00701d58 — water system initialized flag
// DAT_00701de8 — vertex stride for water mesh
// DAT_00701d7c — vertex format FVF code
// DAT_00701d34 — vertex processing callback
// DAT_00701d10 — light transform callback
// DAT_007026cc — device state object
// DAT_00702684 — texture scale X
// DAT_0070263c — texture scale Y
// DAT_00702660 — texture scale Y (copy)
// DAT_007026a8 — texture scale X (copy)
// DAT_007026d8 — surface/texture handle array (9 entries)
// DAT_00701dc4 — buffer array (9 entries)
// DAT_007488b8 — dynamic buffer count
// DAT_0074ba64 — dynamic buffer array

// ─── QueryTextureCaps (FUN_004dfe20) ───────────────────────────
// Ghidra: FUN_004dfe20 (8 callers, 2 callees)
// Purpose: Initialize the water/terrain bump-mapping system. Computes
//          scale factors from renderer resolution data, creates a new
//          LandBump object (replacing any existing one), and configures
//          vertex format + shader paths based on bump-map availability.
// Original:
// void __fastcall FUN_004dfe20(void *param_1)
// {
//   float fVar1;
//   undefined4 uVar2;
//   void *pvVar3;
//   undefined4 *puVar4;
//   bool bVar5;
//   DAT_00702684 = DAT_0066bf2c / *(float *)(DAT_00702770 + 0x4f5c);
//   if (*(int *)(DAT_00702770 + 0x4fb0) == 0) {
//     if (*(int *)(DAT_00702770 + 0x5010) == 0) goto LAB_004dfe7d;
//     fVar1 = *(float *)(DAT_00702770 + 0x501c);
//   }
//   else {
//     fVar1 = *(float *)(DAT_00702770 + 0x4fbc);
//   }
//   DAT_0070263c = DAT_0066bf2c / fVar1;
//   DAT_00702660 = DAT_0070263c;
// LAB_004dfe7d:
//   DAT_007026a8 = DAT_00702684;
//   puVar4 = (undefined4 *)FUN_004e2180();
//   uVar2 = *puVar4;
//   *puVar4 = 0;
//   pvVar3 = DAT_00747c74;
//   bVar5 = DAT_00747c74 != (void *)0x0;
//   DAT_00747c74 = (void *)uVar2;
//   if (bVar5) {
//     operator_delete(pvVar3,0x270,0x10);
//   }
//   if (param_1 != (void *)0x0) {
//     operator_delete(param_1,0x270,0x10);
//   }
//   DAT_00701d58 = 1;
//   if ((DAT_00702b64 < 1) ||
//      ((*(int *)(DAT_00702770 + 0x4fb0) == 0 && (*(int *)(DAT_00702770 + 0x5010) == 0)))) {
//     DAT_00701de8 = 0x1c;
//     DAT_00701d7c = 10;
//     DAT_00701d34 = &LAB_004de5e0;
//   }
//   else {
//     DAT_00701de8 = 0x20;
//     DAT_00701d7c = 0xb;
//     DAT_00701d34 = &LAB_004de630;
//   }
//   DAT_00701d10 = FUN_004de7d0;
//   DAT_007026cc = (**(code **)(*DAT_00702700 + 8))();
//   (**(code **)(*DAT_00702700 + 0x60))
//             (*(undefined4 *)(DAT_00702770 + 0x4ec0),
//              *(undefined4 *)(DAT_00702770 + 0x4ec4),
//              *(undefined4 *)(DAT_00702770 + 0x4ec8));
//   return;
// }
void QueryTextureCaps(void* param_1)
{
    // Compute texture scale from renderer resolution
    // s_texScaleX = refRes / renderer->displayWidth;  // DAT_00702684
    // if (renderer->bumpTexture != 0)
    //     s_texScaleY = refRes / renderer->bumpScale;
    // else if (renderer->envTexture != 0)
    //     s_texScaleY = refRes / renderer->envScale;
    // s_texScaleY_copy = s_texScaleY;  // DAT_00702660
    // s_texScaleX_copy = s_texScaleX;  // DAT_007026a8

    // Allocate new LandBump context via AllocateWaveContext
    // void* newContext = AllocateWaveContext(&outPtr);
    // void* oldContext = s_landBumpContext;  // DAT_00747c74
    // s_landBumpContext = outPtr;
    // if (oldContext) operator_delete(oldContext, 0x270, 0x10);
    // if (param_1) operator_delete(param_1, 0x270, 0x10);

    // s_waterInitialized = true;  // DAT_00701d58 = 1

    // Select vertex format based on bump-map quality
    // if (s_bumpQuality < 1 || no bump textures available) {
    //     s_vertexStride = 0x1C;  // 28 bytes — simple vertex
    //     s_vertexFVF = 10;
    //     s_vertexProcessor = &FallbackVertexShader;
    // } else {
    //     s_vertexStride = 0x20;  // 32 bytes — bump-mapped vertex
    //     s_vertexFVF = 11;
    //     s_vertexProcessor = &BumpVertexShader;
    // }

    // s_lightTransformFn = &BuildLightTransformMatrices;  // DAT_00701d10
    // s_deviceState = renderer->vtable[2]();               // DAT_007026cc
    // renderer->vtable[0x18](renderer->viewportX, renderer->viewportY, renderer->viewportW);
}

// ─── QueryShaderCaps (FUN_004dff90) ────────────────────────────
// Ghidra: FUN_004dff90 (8 callers, 4 callees)
// Purpose: Teardown the water/terrain bump-mapping system. Releases
//          all renderer surfaces (textures), frees buffer arrays,
//          and destroys the LandBump context object.
// Original:
// void FUN_004dff90(void)
// { ... (see Ghidra output — ~150 lines of surface/buffer cleanup) }
void QueryShaderCaps()
{
    // Phase 1: Release device state object
    // if (s_deviceState != nullptr) {
    //     s_deviceState->vtable[0](s_deviceState, cookie);
    //     s_deviceState = nullptr;
    // }

    // Phase 2: Release surface handles (9 entries at DAT_007026d8)
    // for (int i = 0; i < 9; i++) {
    //     if (s_surfaceHandles[i] != 0) {
    //         renderer->vtable[0x14](s_surfaceHandles[i]);  // ReleaseSurface
    //         s_surfaceHandles[i] = 0;
    //     }
    // }

    // Phase 3: Free buffer arrays (9 entries at DAT_00701dc4)
    // for (int i = 0; i < 9; i++) {
    //     if (s_bufferArrays[i] != 0) {
    //         // Array cleanup with VectorDeallocate per element
    //         FUN_006438f8(...);
    //         s_bufferArrays[i] = 0;
    //     }
    // }

    // Phase 4: Release texture surfaces (3 passes x 3 texture types)
    // for (int pass = 0; pass < 3; pass++) {
    //     // Release bump textures, env textures, and custom textures
    //     // via renderer->vtable[200] (ReleaseTexture)
    //     // Free associated buffer if owned
    // }

    // Phase 5: Destroy LandBump context
    // void* ctx = s_landBumpContext;  // DAT_00747c74
    // s_landBumpContext = nullptr;
    // if (ctx) operator_delete(ctx, 0x270, 0x10);
}

// ─── ComputeWaveVertex (FUN_004e07f0) ──────────────────────────
// Ghidra: FUN_004e07f0 (10 callers, 1 callee)
// Purpose: Transform a water wave vertex by applying a 4x3 matrix from
//          the wave context to UV coordinates. Returns true if the
//          resulting vertex falls outside the valid range (for culling).
//          The matrix is stored at offsets 0x3C..0x58 of the wave context.
// Original:
// bool FUN_004e07f0(float *param_1,float param_2,float param_3,float *param_4,int param_5)
// {
//   float fVar1;
//   float fVar2;
//   *param_1 = param_2;
//   param_1[1] = param_3;
//   fVar1 = *param_4;
//   if (DAT_007488b8 != 0) {
//     FUN_005f9b00();
//   }
//   param_1[2] = fVar1;
//   fVar2 = param_2 * *(float *)(param_5 + 0x4c) + param_3 * *(float *)(param_5 + 0x50) +
//           *(float *)(param_5 + 0x58);
//   fVar1 = param_2 * *(float *)(param_5 + 0x3c) + param_3 * *(float *)(param_5 + 0x40) +
//           *(float *)(param_5 + 0x48);
//   param_1[3] = 0.0;
//   param_1[4] = fVar1;
//   param_1[5] = fVar2;
//   return (fVar1 < 0.0 || (fVar2 < 0.0 || DAT_0066bf2c < fVar2)) || DAT_0066bf2c < fVar1;
// }
bool ComputeWaveVertex(float* outUV, float u, float v, float* srcZ, int waveContext)
{
    // Copy input UV and source Z
    outUV[0] = u;
    outUV[1] = v;
    float z = *srcZ;

    // Flush dynamic buffers if active
    // if (s_dynamicBufferCount != 0) {
    //     FlushDynamicBuffers();
    // }

    outUV[2] = z;

    // Apply 4x3 transform matrix from wave context
    // Matrix layout at waveContext offsets:
    //   [0x3C..0x48] — row 0 (U transform)
    //   [0x4C..0x58] — row 1 (V transform)
    float* matrix = reinterpret_cast<float*>(waveContext);
    float transformedU = u * matrix[0x3C / 4] + v * matrix[0x40 / 4] + matrix[0x48 / 4];
    float transformedV = u * matrix[0x4C / 4] + v * matrix[0x50 / 4] + matrix[0x58 / 4];

    outUV[3] = 0.0f;
    outUV[4] = transformedU;
    outUV[5] = transformedV;

    // Out-of-bounds culling check against reference resolution
    const float refRes = 1.0f; // DAT_0066bf2c
    return (transformedU < 0.0f || transformedV < 0.0f ||
            refRes < transformedV || refRes < transformedU);
}

// ─── AllocateWaveContext (FUN_004e2180) ────────────────────────
// Ghidra: FUN_004e2180 (1 caller, 3 callees)
// Purpose: Allocate and initialize a LandBump wave context. Allocates
//          0x270 bytes (16-byte aligned), creates a "LandBump" renderer
//          resource via vtable dispatch, and sets up vtable pointers.
// Original:
// undefined4 * __fastcall FUN_004e2180(undefined4 *param_1)
// {
//   undefined4 *puVar1;
//   undefined4 uVar2;
//   void *local_10;
//   undefined1 *puStack_c;
//   undefined4 local_8;
//   local_8 = 0xffffffff;
//   puStack_c = &LAB_0064b0f9;
//   local_10 = ExceptionList;
//   ExceptionList = &local_10;
//   puVar1 = (undefined4 *)FUN_006438b2(0x270,0x10,DAT_0067d280 ^ (uint)&stack0xfffffffc);
//   local_8 = 0;
//   if (puVar1 != (undefined4 *)0x0) {
//     uVar2 = (**(code **)(*DAT_00702700 + 0xe8))("LandBump");
//     *puVar1 = &PTR_LAB_0066a484;
//     puVar1[1] = uVar2;
//     puVar1[2] = 0;
//     FUN_0061ff00(uVar2);
//     FUN_0061fe60(uVar2);
//     puVar1[4] = &PTR_LAB_0066a4b4;
//     puVar1[0x6c] = &PTR_LAB_0066a4a0;
//     *puVar1 = &PTR_LAB_0066a4a8;
//     *param_1 = puVar1;
//     ExceptionList = local_10;
//     return param_1;
//   }
//   *param_1 = 0;
//   ExceptionList = local_10;
//   return param_1;
// }
void* AllocateWaveContext(void** outContext)
{
    // Allocate 0x270 bytes, 16-byte aligned
    // void* mem = AlignedAlloc(0x270, 0x10);
    // if (mem == nullptr) {
    //     *outContext = nullptr;
    //     return nullptr;
    // }

    // Create "LandBump" renderer resource via vtable
    // uint32_t landBumpRes = renderer->vtable[0x3A]("LandBump");
    //
    // Initialize the LandBump context:
    //   mem->vtable1 = &LandBumpVTable;       // offset 0x00
    //   mem->rendererResource = landBumpRes;   // offset 0x04
    //   mem->field_08 = 0;                     // offset 0x08
    //   InitRendererResource(landBumpRes);     // FUN_0061ff00
    //   ResetRendererResource(landBumpRes);    // FUN_0061fe60
    //   mem->vtable2 = &LandBumpSubVTable2;    // offset 0x10
    //   mem->vtable3 = &LandBumpSubVTable1;    // offset 0x1B0
    //   mem->vtable1 = &LandBumpMainVTable;    // offset 0x00 (overwritten)
    //
    // *outContext = mem;
    // return outContext;
    *outContext = nullptr;
    return nullptr;
}

// ─── BuildLightTransformMatrices (FUN_004de7d0) ────────────────
// Ghidra: FUN_004de7d0 (1 caller, 2 callees)
// Purpose: Build per-light 4x4 transform matrices from the per-light data
//          arrays at DAT_007021xx and upload them to the GPU via the
//          LandBump context. Two shader paths:
//            - Simple path (no bump textures): builds a 4x4 matrix directly
//            - Bump path: builds two 4x4 matrices (world + bump), determines
//              light type (0=directional, 1=point, 2=spot), uploads 0xA0 bytes
//              of constant data to the device.
// Original:
// void FUN_004de7d0(int param_1)
// { ... (see Ghidra output — ~200 lines of matrix math + GPU upload) }
void BuildLightTransformMatrices(int lightIndex)
{
    // Invoke renderer BeginScene via vtable+0x3C
    // renderer->vtable[0x0F]();

    // Compute stride into per-light data arrays
    // int stride = lightIndex * 0x44;

    // Two paths based on bump-map availability:
    //
    // SIMPLE PATH (s_bumpQuality < 1 or no bump textures):
    //   Load 4 rows of a 4x4 matrix from DAT_0070212C + stride
    //   Build world-space light matrix
    //   Store result in 4x4 output matrix (afStack_c0)
    //
    // BUMP PATH:
    //   Load bump-space matrix from DAT_00702394 + stride
    //   Build bump transform (4x4)
    //   Also load world-space matrix from DAT_0070212C + stride
    //   Build second 4x4 matrix
    //   Determine light type: 0=none, 1=bump, 2=env
    //   Store 8 matrices total (0x160 bytes)

    // Compare new matrices against cached values at LandBump+0x70
    // If different, upload 0xA0 bytes of constant data:
    //   if (memcmp(newMatrix, landBump->cached, 0xA0) != 0) {
    //       memcpy(landBump->cached, newMatrix, 0xA0);
    //       landBump->matrixDirty = true;
    //   }

    // Upload to GPU via vtable dispatch:
    //   Get shader constant buffer via vtable+0x08
    //   Submit via vtable+0x0C
    //   FUN_0061fbd0() — post-upload processing

    // Commit vertex data if dirty:
    //   if (landBump->vertexDirty)
    //       uploadContext->vtable[0x10](landBump+8, 0x180);
    //   if (landBump->matrixDirty)
    //       uploadContext->vtable[0x10](landBump+0x70, 0xA0);

    // Set vertex count and primitive parameters via vtable
    //   surfaceHandle->vtable[0x0C](handle, vertexCount);
    //   surfaceHandle->vtable[0x10](handle, 0);  // base vertex
    //   if (s_indexCount[lightIndex] != 0)
    //       surfaceHandle->vtable[0x18](handle, s_indexCount[lightIndex], 0);
}

// ─── FlushDynamicBuffers (FUN_005f9b00) ────────────────────────
// Ghidra: FUN_005f9b00 (8 callers, 1 callee)
// Purpose: Iterate over the dynamic buffer array and flush each active
//          entry. The array at DAT_0074ba64 has s_dynamicBufferCount
//          entries, each 32 bytes apart. Entries are active when the
//          preceding DWORD is non-zero.
// Original:
// void FUN_005f9b00(void)
// {
//   undefined4 *puVar1;
//   undefined4 *extraout_EDX;
//   int iVar2;
//   if (DAT_007488b8 != 0) {
//     if (0 < DAT_007488b8) {
//       puVar1 = &DAT_0074ba64;
//       iVar2 = DAT_007488b8;
//       do {
//         if (puVar1[-1] != 0) {
//           FUN_0042d350();
//           puVar1 = extraout_EDX;
//         }
//         puVar1 = puVar1 + 8;
//         iVar2 = iVar2 + -1;
//       } while (iVar2 != 0);
//     }
//     return;
//   }
//   return;
// }
void FlushDynamicBuffers()
{
    // if (s_dynamicBufferCount <= 0) return;
    //
    // DynamicBuffer* ptr = &s_dynamicBuffers[0]; // DAT_0074ba64
    // for (int i = s_dynamicBufferCount; i != 0; i--) {
    //     if (ptr->active != 0) {    // active flag is at ptr[-1] relative to iteration
    //         FUN_0042d350(ptr);      // flush/commit the dynamic buffer
    //     }
    //     ptr += 8;  // stride = 32 bytes per entry
    // }
}

// ─── VectorDeallocate (FUN_0042b1f0) ───────────────────────────
// Ghidra: FUN_0042b1f0 (95 callers, 2 callees)
// Purpose: Generic vector/container deallocator. Frees the heap block
//          and zeroes the 3 container fields (data pointer, size, capacity).
//          Validates the allocation header for large blocks before freeing.
// Original:
// void __fastcall FUN_0042b1f0(int *param_1)
// {
//   int iVar1;
//   int iVar2;
//   uint uVar3;
//   iVar1 = *param_1;
//   if (iVar1 != 0) {
//     uVar3 = param_1[2] - iVar1 & 0xfffffffc;
//     iVar2 = iVar1;
//     if (0xfff < uVar3) {
//       iVar2 = *(int *)(iVar1 + -4);
//       uVar3 = uVar3 + 0x23;
//       if (0x1f < (iVar1 - iVar2) - 4U) {
//         _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
//       }
//     }
//     FUN_00643505(iVar2,uVar3);
//     *param_1 = 0;
//     param_1[1] = 0;
//     param_1[2] = 0;
//   }
//   return;
// }
void VectorDeallocate(int* container)
{
    // container layout: [0]=data ptr, [1]=size, [2]=capacity/end
    int dataPtr = container[0];
    if (dataPtr == 0)
        return;

    // Compute actual allocation size (end - begin, aligned to 4 bytes)
    uint32_t allocSize = (container[2] - dataPtr) & 0xFFFFFFFC;
    int* blockToFree = reinterpret_cast<int*>(dataPtr);

    // For large allocations (>0xFFF), validate the CRT heap header
    if (allocSize > 0xFFF) {
        // The allocation header is at (dataPtr - 4), contains the raw block start
        blockToFree = reinterpret_cast<int*>(*(reinterpret_cast<int*>(dataPtr - 4)));
        allocSize += 0x23; // Add overhead for CRT debug header
        // Sanity check: block start should be within 32 bytes of dataPtr
        // if ((dataPtr - blockToFree) - 4 > 0x1F)
        //     _invoke_watson(nullptr, nullptr, nullptr, 0, 0); // CRT abort
    }

    // Free the block and zero all container fields
    FUN_00643505(blockToFree, allocSize);
    container[0] = 0;  // data pointer
    container[1] = 0;  // size
    container[2] = 0;  // capacity
}

} // namespace Giants
