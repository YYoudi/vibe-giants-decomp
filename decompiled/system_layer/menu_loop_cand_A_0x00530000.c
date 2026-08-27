// GiantsRE system layer - menu_loop_cand_A
// VA 0x00530000
// via GhidraMCP headless bulk decompile (project with PS2 renames)


void menu_loop_cand_A(uint param_1)

{
  undefined4 unaff_ESI;
  int unaff_EDI;
  uint uVar1;
  uint uVar2;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  uVar2 = 1;
  local_4 = 0;
  uVar1 = param_1;
  (**(code **)(*DAT_005dd5c0 + 200))(DAT_005dd5c0,DAT_005dd578,param_1,1,&local_8,&local_4);
  if ((8 < uVar1) || (5000 < uVar2)) {
    FUN_00544b47(&DAT_006552c0,s_GF_5d_qn__d_qbytes__6d_dsize__4d_00580a58,DAT_006314d0,uVar1,uVar2,
                 unaff_EDI);
    FUN_0051eca0(&DAT_006552c0);
  }
  if ((uVar1 < 9) && (uVar2 < 0x1389)) {
    DAT_005dcd48 = DAT_005dcd48 + 1;
    DAT_005dcd4c = DAT_005dcd4c + unaff_EDI;
    DAT_005dcd54 = DAT_005dcd54 + unaff_EDI;
    DAT_005dcd50 = DAT_005dcd50 + 1;
    (**(code **)(*DAT_005dd5c0 + 0xc4))
              (DAT_005dd5c0,DAT_005dd578,param_1,0x600,unaff_ESI,unaff_EDI,0,0,0,0);
  }
  return;
}

