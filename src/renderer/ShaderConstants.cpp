// Giants Engine - Shader Constants & Math Helpers
// Reverse engineered from FUN_00483140, FUN_00483160, FUN_0061f8f0

#include "ShaderConstants.h"
#include <cmath>

namespace Giants {

// External SSE2 math symbols linked from the CRT math library
extern "C" float libm_sse2_cos_precise();
extern "C" float libm_sse2_sin_precise();

// ─── ComputeCos / EndShaderBlock (FUN_00483140) ────────────────
// Ghidra: FUN_00483140 (18 callers, 1 callee)
// Purpose: SSE2 cosine wrapper. Trampoline to libm_sse2_cos_precise.
//          The x87/XMM0 calling convention is preserved by the compiler
//          so this is a pure tail-call (jmp, not call).
// Original:
// void FUN_00483140(void)
// {
//   libm_sse2_cos_precise();
//   return;
// }
float ComputeCos(float angle)
{
    return cosf(angle);
}

// ─── ComputeSin / BeginShaderBlock (FUN_00483160) ──────────────
// Ghidra: FUN_00483160 (15 callers, 1 callee)
// Purpose: SSE2 sine wrapper. Trampoline to libm_sse2_sin_precise.
//          Identical structure to ComputeCos — pure tail-call jmp.
// Original:
// void FUN_00483160(void)
// {
//   libm_sse2_sin_precise();
//   return;
// }
float ComputeSin(float angle)
{
    return sinf(angle);
}

// ─── SubmitShaderConstants (FUN_0061f8f0) ──────────────────────
// Ghidra: FUN_0061f8f0 (11 callers, 1 callee)
// Purpose: Submits a 4-float constant vector (position/quaternion/color)
//          to the renderer device via vtable dispatch. Implements dirty-
//          check caching: if the 4 floats + index haven't changed since
//          last call, the expensive vtable data upload is skipped.
//          After submission, sets render state on the device object.
// External globals used:
//   DAT_00702b69  — enabled flag (skip entire function if 0)
//   DAT_00702700  — renderer device vtable pointer
//   DAT_00702720  — secondary device object
//   DAT_0066bcf4  — epsilon threshold for float comparison
//   DAT_0066c560  — bitmask for float-to-uint conversion
// Original:
// void __fastcall FUN_0061f8f0(float *param_1,int param_2,undefined4 param_3)
// {
//   int *piVar1;
//   int iVar2;
//   undefined4 uVar3;
//   int *piStack_78;
//   int local_70;
//   float local_50;
//   float fStack_4c;
//   float fStack_48;
//   float fStack_44;
//   int local_40;
//   uint uStack_3c;
//   char local_30;
//   int *piStack_2c;
//   undefined4 local_20;
//   if (DAT_00702b69 != '\0') {
//     FUN_00621ba0();
//     piVar1 = DAT_00702720;
//     if ((((DAT_0066bcf4 <= (float)((uint)(*param_1 - local_50) & DAT_0066c560)) ||
//          (DAT_0066bcf4 <= (float)((uint)(param_1[1] - fStack_4c) & DAT_0066c560))) ||
//        (DAT_0066bcf4 <= (float)((uint)(param_1[2] - fStack_48) & DAT_0066c560))) ||
//        (((DAT_0066bcf4 <= (float)((uint)(param_1[3] - fStack_44) & DAT_0066c560) ||
//          (param_2 != local_40)) || (uStack_3c != 0)))) {
//       uStack_3c = 0;
//       local_30 = '\x01';
//       local_50 = *param_1;
//       fStack_4c = param_1[1];
//       fStack_48 = param_1[2];
//       fStack_44 = param_1[3];
//       local_40 = param_2;
//     }
//     local_20 = param_3;
//     iVar2 = (**(code **)(*DAT_00702700 + 0x58))();
//     local_30 = '\x01';
//     uStack_3c = (uint)(iVar2 == 2);
//     uVar3 = (**(code **)(local_70 + 8))(1);
//     (**(code **)(*piVar1 + 0xc))(local_70,uVar3);
//     (**(code **)(*piStack_78 + 0x10))(0,piStack_2c);
//     if (local_30 != '\0') {
//       (**(code **)(*piStack_2c + 0x10))(&local_50,0x20);
//     }
//   }
//   (*(code *)DAT_00702720[4])(DAT_00702720,0);
//   (*(code *)DAT_00702720[6])(DAT_00702720,6,&DAT_00685854);
//   return;
// }
void SubmitShaderConstants(float* constants, int index, uint32_t flags)
{
    // Guard: skip if shader system not enabled
    // DAT_00702b69 is the global enable flag
    // if (!s_shaderEnabled) return;

    // Dirty-check: compare 4 floats + index against cached values
    // If any component changed beyond epsilon threshold, mark dirty
    // static float s_cached[4] = {};
    // static int   s_cachedIndex = 0;
    // static bool  s_dirty = true;

    // if (any component differs by more than epsilon) {
    //     s_cached[0..3] = constants[0..3];
    //     s_cachedIndex = index;
    //     s_dirty = true;
    // }

    // vtable dispatch to renderer device:
    // 1. Query shader type via vtable+0x58
    // 2. Create/update constant buffer via vtable+0x08, +0x0C
    // 3. If dirty, upload 0x20 bytes of constant data via vtable+0x10
    //
    // (**DAT_00702700->vtable[0x58])()        — query pass type
    // (*device->vtable[0x08])(1)              — begin pass
    // (*secondary->vtable[0x0C])(pass, result) — submit
    // (*context->vtable[0x10])(0, &out)        — get upload context
    // if (dirty) (*uploadCtx->vtable[0x10])(&cached, 0x20)

    // Post-submission render state:
    // (*DAT_00702720->vtable[4])(DAT_00702720, 0);
    // (*DAT_00702720->vtable[6])(DAT_00702720, 6, &DAT_00685854);
}

} // namespace Giants
