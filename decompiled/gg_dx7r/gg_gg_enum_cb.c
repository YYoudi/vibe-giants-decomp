// gg_dx7r.dll - gg_enum_cb @ 0x100010A0

undefined4 FUN_100010a0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined1 ***pppuVar4;
  undefined1 **ppuStack_938;
  undefined1 *puStack_924;
  int *piStack_920;
  undefined4 **ppuStack_918;
  int *piStack_914;
  undefined1 *puStack_910;
  undefined4 **ppuStack_908;
  undefined1 auStack_904 [252];
  undefined4 **ppuStack_808;
  uint uStack_7fc;
  undefined4 uStack_7f8;
  int aiStack_67c [98];
  undefined1 auStack_4f4 [1180];
  undefined *puStack_58;
  int *piStack_4c;
  undefined4 *puStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_2c;
  LPCSTR pCStack_10;
  
  if ((DAT_10028454 == 0) || (param_1 != (undefined4 *)0x0)) {
    puStack_910 = (undefined1 *)0x0;
    ppuStack_918 = &ppuStack_908;
    piStack_914 = (int *)&DAT_10017200;
    piStack_920 = (int *)0x100010d1;
    iVar1 = DirectDrawCreateEx();
    if (-1 < iVar1) {
      puStack_910 = auStack_904;
      piStack_914 = (int *)&DAT_100171e0;
      ppuStack_918 = ppuStack_908;
      iVar1 = (*(code *)**ppuStack_908)();
      if (iVar1 < 0) {
        piStack_920 = (int *)0x100010fa;
        (**(code **)(*piStack_914 + 8))();
        return 1;
      }
      puVar2 = (undefined4 *)&stack0xfffff6f4;
      for (iVar1 = 0x240; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
      puStack_924 = auStack_4f4;
      piStack_920 = (int *)0x0;
      (**(code **)(*piStack_914 + 0x6c))();
      ppuStack_938 = (undefined1 **)0x10001140;
      lstrcpynA((LPSTR)&ppuStack_918,pCStack_10,0x27);
      piVar3 = aiStack_67c;
      uStack_7f8 = 0x17c;
      aiStack_67c[0] = 0x17c;
      ppuStack_938 = (undefined1 **)0x1000116d;
      (**(code **)(*piStack_920 + 0x2c))();
      if (param_1 != (undefined4 *)0x0) {
        puStack_48 = (undefined4 *)*param_1;
        uStack_44 = param_1[1];
        uStack_40 = param_1[2];
        uStack_3c = param_1[3];
        ppuStack_808 = &puStack_48;
      }
      if (((uStack_7fc & 0x80000) != 0) && (ppuStack_808 == (undefined4 **)0x0)) {
        uStack_2c = 1;
      }
      ppuStack_938 = &puStack_924;
      (**(code **)(*piVar3 + 0x20))(piVar3,0);
      FUN_1000d2c7(piStack_4c,puStack_48,0x7c,&LAB_10001000);
      pppuVar4 = &ppuStack_938;
      piVar3 = (int *)0x0;
      (**(code **)(iRam00000000 + 0xc))(0,&LAB_10001300);
      if (puStack_58 != (undefined *)0x0) {
        FUN_1000d2bc(puStack_58);
        puStack_58 = (undefined *)0x0;
      }
      (*(code *)(*pppuVar4)[2])(pppuVar4);
      (**(code **)(*piVar3 + 8))(piVar3);
    }
  }
  return 1;
}

