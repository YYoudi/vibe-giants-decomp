// Giants Engine - Shader Initialization Functions
// Reverse engineered from GiantsMain.exe v1.520.59

#pragma once

#include <cstdint>

namespace Giants {

// --- ShaderConstantInit (FUN_00483180) - FAIL ---
// Sets 150+ float constants (ambient, diffuse, specular, fog, attenuation, light)
// on entity shader data structure.
void ShaderConstantInit(int entityPtr);  // FUN_00483180

// --- ShaderConstantBufferBinding (FUN_0061fbd0) - FAIL ---
// Allocates buffers for world/view/projection matrices, binds to renderer.
void ShaderConstantBufferBinding(int param1);  // FUN_0061fbd0

// --- ObjectConstantsInit (FUN_0061fe60) - FAIL ---
// Sets identity transform (scale 1.0, zero rotation/translation),
// gets "ObjectConstants" handle from renderer.
uint32_t* ObjectConstantsInit(uint32_t* param1, int* param2);  // FUN_0061fe60

// --- FrameConstantsInit (FUN_0061ff00) - FAIL ---
// Gets "FrameConstants" handle from renderer.
uint32_t* FrameConstantsInit(uint32_t* param1, int* param2);  // FUN_0061ff00

// --- ScreenSpaceShaderSetup (FUN_00621ba0) - FAIL ---
// Gets "ScreenSpace" sampler, sets up ObjectConstants render pass.
uint32_t* ScreenSpaceShaderSetup(uint32_t* param1);  // FUN_00621ba0

// --- VertexBufferClone (FUN_00501240) - FAIL ---
// Allocates and copies vertex/index/color buffers (stride 0xC).
uint32_t* VertexBufferClone(uint32_t* dst, uint32_t* src);  // FUN_00501240

// --- ShaderResourceLookup (FUN_00640530) - PASS ---
// Accesses resource array by index, sets parameter, calls init.
uint32_t ShaderResourceLookup(int param1, uint32_t param2, uint32_t param3);  // FUN_00640530

// --- ShaderConstantResolve (FUN_006408d0) - FAIL ---
// Looks up constant buffer entry, resolves symbol offset.
uint32_t ShaderConstantResolve(int* param1, int* param2);  // FUN_006408d0

// --- ShaderIteration (FUN_00640b60) - PASS ---
// Resolves two constant buffers, iterates shader resources.
void ShaderIteration(int param1, void* param2, uint32_t param3);  // FUN_00640b60

// --- ShaderResourceCount (FUN_00640bf0) - PASS ---
// Returns number of resources in shader table.
uint32_t ShaderResourceCount(int param1);  // FUN_00640bf0

// --- ShaderResourceSetter (FUN_00640c00) - PASS ---
// Binds resource at index 1.
void ShaderResourceSetter(int param1);  // FUN_00640c00

// --- ShaderResourceGetter (FUN_00640c40) - PASS ---
// Iterates resources matching param_2.
void ShaderResourceGetter(int param1, uint32_t param2);  // FUN_00640c40

// --- ShaderDataOffset (FUN_00640c70) - PASS ---
// Returns ushort at +2 + 4 + base (resource data pointer).
int ShaderDataOffset(int param1);  // FUN_00640c70

} // namespace Giants
