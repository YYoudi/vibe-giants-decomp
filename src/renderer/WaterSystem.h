#pragma once
// Giants Engine - Water System (terrain bump-mapping, waves, texture/shader caps)
// Reverse engineered from FUN_004dfe20, FUN_004dff90, FUN_004e07f0,
//   FUN_004e2180, FUN_004de7d0, FUN_005f9b00, FUN_0042b1f0

#include <cstdint>
#include <windows.h>

namespace Giants {

// ─── QueryTextureCaps (FUN_004dfe20) ─────────────────────────
// Ghidra: FUN_004dfe20 (8 callers, 2 callees)
// Purpose: Initialize the water/terrain bump-mapping system. Computes
//          scale factors from renderer data, creates a "LandBump" object,
//          configures display parameters, and sets up shader paths based
//          on renderer capabilities.
void QueryTextureCaps(void* param_1);

// ─── QueryShaderCaps (FUN_004dff90) ──────────────────────────
// Ghidra: FUN_004dff90 (8 callers, 4 callees)
// Purpose: Teardown the water/terrain bump-mapping system. Releases
//          renderer surfaces (textures, vertex buffers), frees LandBump
//          resources, destroys the LandBump object.
void QueryShaderCaps();

// ─── ComputeWaveVertex (FUN_004e07f0) ────────────────────────
// Ghidra: FUN_004e07f0 (10 callers, 1 callee)
// Purpose: Transform a wave vertex by applying a 4x3 matrix from the
//          wave context to UV coordinates. Returns true if the resulting
//          vertex is out of bounds (for culling).
bool ComputeWaveVertex(float* outUV, float u, float v, float* srcZ, int waveContext);

// ─── AllocateWaveContext (FUN_004e2180) ───────────────────────
// Ghidra: FUN_004e2180 (1 caller, 3 callees)
// Purpose: Allocate and initialize a LandBump wave context. Allocates
//          0x270 bytes (16-byte aligned), creates a "LandBump" renderer
//          resource via vtable, and sets up vtable pointers.
void* AllocateWaveContext(void** outContext);

// ─── BuildLightTransformMatrices (FUN_004de7d0) ──────────────
// Ghidra: FUN_004de7d0 (1 caller, 2 callees)
// Purpose: Build per-light 4x4 transform matrices from per-light data
//          arrays and upload them to the GPU via the LandBump context.
//          Selects shader path based on whether bump-mapping textures
//          are available (bump map vs. fallback path).
void BuildLightTransformMatrices(int lightIndex);

// ─── FlushDynamicBuffers (FUN_005f9b00) ──────────────────────
// Ghidra: FUN_005f9b00 (8 callers, 1 callee)
// Purpose: Iterate over the dynamic buffer array at DAT_0074ba64 and
//          call FUN_0042d350 for each active entry to flush/commit it.
void FlushDynamicBuffers();

// ─── VectorDeallocate (FUN_0042b1f0) ─────────────────────────
// Ghidra: FUN_0042b1f0 (95 callers, 2 callees)
// Purpose: Generic vector/container deallocator. Frees the heap block,
//          then zeroes all 3 fields (pointer, size, capacity). This is
//          the standard "clear + deallocate" for the engine's vector type.
void VectorDeallocate(int* container);

} // namespace Giants
