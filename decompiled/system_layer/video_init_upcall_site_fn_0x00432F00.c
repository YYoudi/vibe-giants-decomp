// GiantsRE system layer - video_init_upcall_site_fn
// VA 0x00432F00 (ghidra name was FUN_00432db0)
// provenance: runtime anchors in scripts/re_db.json + PS2 symbols


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00432db0(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  float10 fVar7;
  float local_4;
  
  iVar6 = 0;
  local_4 = -1.0;
  piVar5 = DAT_006313ec;
  if (DAT_006313ec != (int *)0x0) {
    do {
      iVar1 = piVar5[3];
      if ((local_4 < *(float *)(iVar1 + 0xf4)) || (local_4 < _DAT_005522b0)) {
        local_4 = *(float *)(iVar1 + 0xf4);
        iVar6 = iVar1;
      }
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)0x0);
    if (iVar6 != 0) {
      if (DAT_006314ac == 0) {
        DAT_006314ac = FUN_0050e3c0(s_n_wind_005588cc);
      }
      iVar1 = DAT_006314ac;
      if (*(float *)(DAT_00631538 + 0x35c) * *(float *)(iVar6 + 0xf4) != _DAT_005522b0) {
        iVar3 = __ftol();
        (**(code **)(DAT_00654948 + 8))(DAT_00654948,0x40324,iVar1,iVar3 << 0x18);
        fVar7 = (float10)FUN_0051e9b0(iVar6,0);
        fVar7 = fVar7 * (float10)*(float *)(DAT_00631538 + 0x360) + (float10)DAT_0059b2b0;
        DAT_0059b2b0 = (float)fVar7;
        if ((float10)_DAT_005522c0 < fVar7) {
          DAT_0059b2b0 = DAT_0059b2b0 - _DAT_005522c0;
        }
        puVar4 = (undefined4 *)(**(code **)(DAT_00654958 + 0x10))(DAT_00654958,4);
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[5] = DAT_0059b2b0;
        puVar4[6] = 0x3f800000;
        fVar2 = (float)DAT_006314e4;
        puVar4[8] = 0;
        puVar4[7] = fVar2;
        fVar2 = DAT_0059b2b0 + _DAT_005522c0;
        puVar4[0xd] = 0x3f800000;
        puVar4[0xc] = fVar2;
        puVar4[0xe] = (float)DAT_006314e4;
        puVar4[0xf] = (float)DAT_006314e8;
        fVar2 = DAT_0059b2b0 + _DAT_005522c0;
        puVar4[0x14] = 0;
        puVar4[0x15] = 0;
        puVar4[0x13] = fVar2;
        puVar4[0x16] = (float)DAT_006314e8;
        fVar2 = DAT_0059b2b0;
        puVar4[0x1b] = 0;
        puVar4[0x1a] = fVar2;
        return;
      }
    }
  }
  return;
}


