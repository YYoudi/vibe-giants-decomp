// GiantsRE system layer - func_00432FDE
// VA 0x00432FDE
// via GhidraMCP headless bulk decompile (project with PS2 renames)


void video_init_upcall_store(float param_1,float param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  float *pfVar2;
  
  (**(code **)(DAT_00654948 + 8))(DAT_00654948,0xa0,0,0);
  pfVar2 = (float *)(**(code **)(DAT_00654958 + 0x10))(DAT_00654958,4);
  *pfVar2 = (float)DAT_006314e4 * param_2;
  pfVar2[1] = (float)DAT_006314e8 * param_4;
  pfVar2[7] = (float)DAT_006314e4 * param_3;
  pfVar2[8] = (float)DAT_006314e8 * param_4;
  pfVar2[0xe] = (float)DAT_006314e4 * param_3;
  pfVar2[0xf] = (float)DAT_006314e8 * param_5;
  pfVar2[0x15] = (float)DAT_006314e4 * param_2;
  fVar1 = (float)DAT_006314e8;
  pfVar2[0x19] = param_1;
  pfVar2[0x12] = param_1;
  pfVar2[0xb] = param_1;
  pfVar2[4] = param_1;
  pfVar2[0x16] = fVar1 * param_5;
  return;
}

