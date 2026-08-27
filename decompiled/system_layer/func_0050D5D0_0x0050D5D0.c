// GiantsRE system layer - func_0050D5D0
// VA 0x0050D5D0
// via GhidraMCP headless bulk decompile (project with PS2 renames)


void binobj_load(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (DAT_0057de18 == 0) {
    if (DAT_0057de34 != 0) {
      FUN_0053b310(DAT_0057de34);
    }
    if (DAT_0057de28 != 0) {
      mem_free_tagged(DAT_0057de28,s_C__Giants_Source_main_textget_c_0057de38,0x26);
    }
    if (DAT_0057de2c != 0) {
      mem_free_tagged(DAT_0057de2c,s_C__Giants_Source_main_textget_c_0057de38,0x29);
    }
    if (DAT_0057de30 != 0) {
      mem_free_tagged(DAT_0057de30,s_C__Giants_Source_main_textget_c_0057de38,0x2c);
    }
    puVar2 = &DAT_0057de18;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    DAT_0057de18 = 1;
  }
  return;
}

