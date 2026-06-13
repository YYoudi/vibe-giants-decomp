// Giants Engine - Matrix Operations Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include <cstdlib>
#include <cstring>
#include "MatrixOps.h"
#include <cstring>

namespace Giants {

// ─── External data references ─────────────────────────────────

// Global projection matrix buffer (16 floats, 64 bytes)
// Ghidra labels: DAT_006857d0 through DAT_00685810
static float    g_viewportMatrix[16] = {0};      // DAT_006857d0 (+0x30)

// Obfuscation key for depth/Z-column values
static uint32_t g_depthXorKey = 0;                // DAT_0066c580

// Viewport scale constants (loaded from .data section)
static float    DAT_0066bfac = 0;                 // Viewport scale factor (2.0f)
static float    DAT_0066be20 = 0;                 // FOV multiplier

// Renderer device vtable pointer (D3D device)
static uint32_t DAT_00702700 = 0;                 // Renderer device object

// ─── Global render state buffer for matrix copy ───────────────
// Destination for CopyAndObfuscateMatrix (16 uint32, 64 bytes)
// Layout matches a row-major 4x4 matrix with Z-column obfuscation.
static uint32_t g_renderStateMatrix[16] = {0};    // DAT_00685790 (+0x40)

// External: renderer notification after matrix update
extern void NotifyMatrixUpdated();                 // FUN_005fa1a0

// ─── SetupViewportMatrix (FUN_005f9c10) — PASS ──────────────────

void SetupViewportMatrix(const float* param_1, const float* param_2)
{
    // Clear the entire viewport matrix buffer (64 bytes = 16 floats)
    // Ghidra: memset(&DAT_006857d0, 0, 0x40)
    memset(g_viewportMatrix, 0, sizeof(g_viewportMatrix));

    // Compute X-axis projection scale:  scale / (maxX - minX)
    // DAT_0066bfac is likely 2.0 (maps [-1,1] to clip space)
    g_viewportMatrix[0]  = DAT_0066bfac / (param_2[0] - param_1[0]);  // DAT_006857d0

    // Compute Y-axis projection scale:  scale / (maxY - minY)
    g_viewportMatrix[5]  = DAT_0066bfac / (param_2[1] - param_1[1]);  // DAT_006857e4

    // Aspect ratio: X scale / Y scale
    g_viewportMatrix[2]  = g_viewportMatrix[0] / g_viewportMatrix[5]; // DAT_00685788

    // Z clear / depth defaults
    g_viewportMatrix[10] = 0;                    // DAT_0068580c
    g_viewportMatrix[9]  = 0;                    // DAT_006857f8

    // Identity element (1.0f as IEEE 754: 0x3f800000)
    g_viewportMatrix[11] = 1.0f;  // DAT_0068580c — identity element

    // Obfuscated viewport center X:
    // ((minX + maxX) ^ XOR_key) * xScale * fovBase
    // The XOR on the sum prevents simple reconstruction of viewport bounds
    uint32_t sumX = *(uint32_t*)&param_1[0] + *(uint32_t*)&param_2[0];
    g_viewportMatrix[8]  = (float)(sumX ^ g_depthXorKey)
                           * g_viewportMatrix[0] * DAT_0066be20;    // DAT_00685800

    g_viewportMatrix[4]  = 0;                    // DAT_00685808 — unused / pad

    // Obfuscated viewport center Y:
    // ((minY + maxY) ^ XOR_key) * yScale * fovBase
    uint32_t sumY = *(uint32_t*)&param_1[1] + *(uint32_t*)&param_2[1];
    g_viewportMatrix[6]  = (float)(sumY ^ g_depthXorKey)
                           * g_viewportMatrix[5] * DAT_0066be20;    // DAT_00685804

    // Dispatch to renderer: vtable[0x34] on DAT_00702700
    // Ghidra: (**(code**)(*DAT_00702700 + 0x34))()
    // This is likely IDirect3DDevice::SetTransform or equivalent
    if (DAT_00702700 != 0) {
        uint32_t** device = (uint32_t**)DAT_00702700;
        if (*device != nullptr) {
            // vtable call at offset 0x34 (index 13)
            typedef void(__thiscall* VtableFn)(uint32_t);
            VtableFn fn = (VtableFn)(*device)[13];  // offset 0x34 / 4
            fn((uint32_t)device);
        }
    }
}

// ─── CopyAndObfuscateMatrix (FUN_005fa310) — PASS ───────────────

void CopyAndObfuscateMatrix(const uint32_t* matrix)
{
    // Copy all 16 elements of a 4x4 matrix to the global render state buffer.
    // Elements at indices [2], [6], [10], [14] (Z-column, row-major) are XOR'd
    // with g_depthXorKey (DAT_0066c580) before storage.
    //
    // Matrix layout (row-major):
    //   [ 0] [ 1] [ 2^] [ 3]     ^ = XOR'd with key
    //   [ 4] [ 5] [ 6^] [ 7]
    //   [ 8] [ 9] [10^] [11]
    //   [12] [13] [14^] [15]
    //
    // Destination mapping (global buffer at DAT_00685790):
    //   [0] → DAT_00685790   [1] → DAT_00685794   [2^] → DAT_00685798   [3] → DAT_0068579c
    //   [4] → DAT_006857a0   [5] → DAT_006857a4   [6^] → DAT_006857a8   [7] → DAT_006857ac
    //   [8] → DAT_006857b0   [9] → DAT_006857b4   [10^] → DAT_006857b8  [11] → DAT_006857bc
    //   [12] → DAT_006857c0  [13] → DAT_006857c4  [14^] → DAT_006857c8  [15] → DAT_006857cc

    g_renderStateMatrix[0]  = matrix[0];          // DAT_00685790
    g_renderStateMatrix[1]  = matrix[1];          // DAT_00685794
    g_renderStateMatrix[2]  = matrix[2] ^ g_depthXorKey;  // DAT_00685798 — XOR
    g_renderStateMatrix[3]  = matrix[3];          // DAT_0068579c

    g_renderStateMatrix[4]  = matrix[4];          // DAT_006857a0
    g_renderStateMatrix[5]  = matrix[5];          // DAT_006857a4
    g_renderStateMatrix[6]  = matrix[6] ^ g_depthXorKey;  // DAT_006857a8 — XOR
    g_renderStateMatrix[7]  = matrix[7];          // DAT_006857ac

    g_renderStateMatrix[8]  = matrix[8];          // DAT_006857b0
    g_renderStateMatrix[9]  = matrix[9];          // DAT_006857b4
    g_renderStateMatrix[10] = matrix[10] ^ g_depthXorKey; // DAT_006857b8 — XOR
    g_renderStateMatrix[11] = matrix[11];         // DAT_006857bc

    g_renderStateMatrix[12] = matrix[12];         // DAT_006857c0
    g_renderStateMatrix[13] = matrix[13];         // DAT_006857c4
    g_renderStateMatrix[14] = matrix[14] ^ g_depthXorKey; // DAT_006857c8 — XOR
    g_renderStateMatrix[15] = matrix[15];         // DAT_006857cc

    // Notify renderer that the matrix has been updated
    // FUN_005fa1a0 — likely triggers re-upload to GPU
    NotifyMatrixUpdated();
}

// ─── Matrix identity constants (16 uint32 = 4x4 identity matrix) ──
// Stored at DAT_0067d198..DAT_0067d1D8 (64 bytes)
// IEEE 754: 1.0f = 0x3F800000, 0.0f = 0x00000000
static const uint32_t g_identityMatrix[17] = {
    0x3F800000, 0x00000000, 0x00000000, 0x00000000,  // Row 0: [1, 0, 0, 0]
    0x00000000, 0x3F800000, 0x00000000, 0x00000000,  // Row 1: [0, 1, 0, 0]
    0x00000000, 0x00000000, 0x3F800000, 0x00000000,  // Row 2: [0, 0, 1, 0]
    0x00000000, 0x00000000, 0x00000000, 0x3F800000,  // Row 3: [0, 0, 0, 1]
    0x00000000                                         // DAT_0067d1d8 (padding/flags)
};

// ─── MatrixIdentityOrMultiply (FUN_0063e2c0) — FAIL ───────────
// Status: FAIL
// Loads a 4x4 identity matrix into param_1, then optionally applies scale
// and axis rotation from param_2 based on flags in param_2[10].
//
// Flags (param_2[10]):
//   bit 0 (0x01): If set, load identity via FUN_0063eaa0 (axis rotation matrix).
//                 If clear, load identity from g_identityMatrix directly.
//   bit 1 (0x02): Apply scale from param_2[7..9] (Y, Z, X scale factors).
//   bit 3 (0x08): Scale factors are XOR-obfuscated with DAT_0066c580.
//   bit 4 (0x10): Override row 3 (translation) from param_2[0..2].
//
// Scale is applied to columns 1,2,3 of the matrix (not column 0).
// When bit 3 is set, scale factors are deobfuscated: (param_2[i] ^ XOR_key) as float.
// Matrix layout (row-major, uint32 indices):
//   [  0] [  1] [  2] [  3]     Column 1: indices 1,5,9
//   [  4] [  5] [  6] [  7]     Column 2: indices 2,6,10
//   [  8] [  9] [ 10] [ 11]     Column 3: indices 3,7,11
//   [ 12] [ 13] [ 14] [ 15]

/*
  RAW DECOMPILATION (Ghidra):
  void FUN_0063e2c0(uint *param_1, uint *param_2)
  {
    uint uVar1, uVar2, uVar3;
    // Load identity matrix from globals
    uVar2 = _DAT_0067d1a4;  uVar1 = uRam0067d1a0;  uVar3 = uRam0067d19c;
    if ((param_2[10] & 1) == 0) {
      // Direct copy: 16 uint32 from DAT_0067d198..DAT_0067d1d8
      *param_1 = _DAT_0067d198;
      param_1[1] = uVar3;  param_1[2] = uVar1;  param_1[3] = uVar2;
      // ... all 16 elements ...
      param_1[0x10] = DAT_0067d1d8;
    } else {
      FUN_0063eaa0(param_1, param_2 + 3);  // axis rotation matrix
    }
    if ((param_2[10] & 0x10) != 0) {
      // Override translation row (row 3)
      param_1[4]  = *param_2;       // X translation
      param_1[8]  = param_2[1];     // Y translation
      param_1[0xc] = param_2[2];    // Z translation
    }
    uVar1 = DAT_0066c580;           // XOR obfuscation key
    uVar3 = param_2[10];
    if ((uVar3 & 10) != 0) {
      if ((uVar3 & 8) != 0) {
        // XOR-deobfuscated scale
        param_1[1]  = (uint)((float)(param_2[7] ^ DAT_0066c580) * (float)param_1[1]);
        param_1[5]  = (uint)((float)(param_2[7] ^ uVar1) * (float)param_1[5]);
        param_1[9]  = (uint)((float)(param_2[7] ^ uVar1) * (float)param_1[9]);
        param_1[2]  = (uint)((float)(param_2[8] ^ uVar1) * (float)param_1[2]);
        param_1[6]  = (uint)((float)(param_2[8] ^ uVar1) * (float)param_1[6]);
        param_1[10] = (uint)((float)(param_2[8] ^ uVar1) * (float)param_1[10]);
        param_1[3]  = (uint)((float)(param_2[9] ^ uVar1) * (float)param_1[3]);
        param_1[7]  = (uint)((float)(param_2[9] ^ uVar1) * (float)param_1[7]);
        param_1[0xb] = (uint)((float)(param_2[9] ^ uVar1) * (float)param_1[0xb]);
        *param_1 = param_2[10];
        return;
      }
      // Plain scale (no XOR)
      param_1[1]  = (uint)((float)param_1[1] * (float)param_2[7]);
      param_1[5]  = (uint)((float)param_2[7] * (float)param_1[5]);
      param_1[9]  = (uint)((float)param_2[7] * (float)param_1[9]);
      param_1[2]  = (uint)((float)param_2[8] * (float)param_1[2]);
      param_1[6]  = (uint)((float)param_2[8] * (float)param_1[6]);
      param_1[10] = (uint)((float)param_2[8] * (float)param_1[10]);
      param_1[3]  = (uint)((float)param_1[3] * (float)param_2[9]);
      param_1[7]  = (uint)((float)param_1[7] * (float)param_2[9]);
      param_1[0xb] = (uint)((float)param_1[0xb] * (float)param_2[9]);
      uVar3 = param_2[10];
    }
    *param_1 = uVar3;
  }
*/

void MatrixIdentityOrMultiply(uint32_t* param1, uint32_t* param2)
{
    uint32_t flags = param2[10];

    // Step 1: Load identity matrix
    if ((flags & 1) == 0)
    {
        // Direct copy from static identity (16 uint32)
        for (int i = 0; i < 16; i++)
            param1[i] = g_identityMatrix[i];
        // Extra word at param1[16] (matches DAT_0067d1d8)
        param1[16] = g_identityMatrix[16];
    }
    else
    {
        // Build axis rotation matrix from param_2[3..6]
        // FUN_0063eaa0(param1, param2 + 3);
    }

    // Step 2: Override translation row if bit 4 set
    if ((flags & 0x10) != 0)
    {
        param1[4]  = param2[0];   // X translation → row 1, col 0
        param1[8]  = param2[1];   // Y translation → row 2, col 0
        param1[12] = param2[2];   // Z translation → row 3, col 0
    }

    // Step 3: Apply scale to columns 1, 2, 3
    if ((flags & 0x0A) != 0)
    {
        if ((flags & 0x08) != 0)
        {
            // XOR-deobfuscated scale factors
            // param_2[7] ^ key = Y scale, param_2[8] ^ key = Z scale, param_2[9] ^ key = X scale
            uint32_t scaleY_raw = param2[7] ^ g_depthXorKey;
            uint32_t scaleZ_raw = param2[8] ^ g_depthXorKey;
            uint32_t scaleX_raw = param2[9] ^ g_depthXorKey;
            float scaleY = *reinterpret_cast<float*>(&scaleY_raw);
            float scaleZ = *reinterpret_cast<float*>(&scaleZ_raw);
            float scaleX = *reinterpret_cast<float*>(&scaleX_raw);

            // Column 1 (indices 1, 5, 9)
            *reinterpret_cast<float*>(&param1[1])  *= scaleY;
            *reinterpret_cast<float*>(&param1[5])  *= scaleY;
            *reinterpret_cast<float*>(&param1[9])  *= scaleY;

            // Column 2 (indices 2, 6, 10)
            *reinterpret_cast<float*>(&param1[2])  *= scaleZ;
            *reinterpret_cast<float*>(&param1[6])  *= scaleZ;
            *reinterpret_cast<float*>(&param1[10]) *= scaleZ;

            // Column 3 (indices 3, 7, 11)
            *reinterpret_cast<float*>(&param1[3])  *= scaleX;
            *reinterpret_cast<float*>(&param1[7])  *= scaleX;
            *reinterpret_cast<float*>(&param1[11]) *= scaleX;

            param1[0] = flags;
            return;
        }

        // Plain scale (no XOR obfuscation)
        float scaleY = *reinterpret_cast<float*>(&param2[7]);
        float scaleZ = *reinterpret_cast<float*>(&param2[8]);
        float scaleX = *reinterpret_cast<float*>(&param2[9]);

        // Column 1 (indices 1, 5, 9)
        *reinterpret_cast<float*>(&param1[1])  *= scaleY;
        *reinterpret_cast<float*>(&param1[5])  *= scaleY;
        *reinterpret_cast<float*>(&param1[9])  *= scaleY;

        // Column 2 (indices 2, 6, 10)
        *reinterpret_cast<float*>(&param1[2])  *= scaleZ;
        *reinterpret_cast<float*>(&param1[6])  *= scaleZ;
        *reinterpret_cast<float*>(&param1[10]) *= scaleZ;

        // Column 3 (indices 3, 7, 11)
        *reinterpret_cast<float*>(&param1[3])  *= scaleX;
        *reinterpret_cast<float*>(&param1[7])  *= scaleX;
        *reinterpret_cast<float*>(&param1[11]) *= scaleX;

        flags = param2[10];
    }

    param1[0] = flags;
}

} // namespace Giants
