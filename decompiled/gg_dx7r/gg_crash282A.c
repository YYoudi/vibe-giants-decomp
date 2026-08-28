// gg_dx7r.dll - crash282A @ 0x1000282A

void __cdecl FUN_100027f0(int param_1,int param_2,undefined2 *param_3)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  short *psVar4;
  int iVar5;
  
  puVar3 = param_3;
  iVar1 = *(int *)(param_1 + 0x38);
  iVar5 = *(int *)(param_1 + 0x80) + *(int *)(param_1 + 100);
  iVar2 = *(int *)(param_1 + 0x68);
  if (iVar5 < 0) {
    if (param_2 != 0) {
      param_3 = (undefined2 *)param_2;
      psVar4 = &DAT_10028870;
      do {
        *psVar4 = *(short *)((int)(puVar3 + -0x8014438) + (int)psVar4) + (short)iVar5;
        param_3 = (undefined2 *)((int)param_3 + -1);
        psVar4 = psVar4 + 1;
      } while (param_3 != (undefined2 *)0x0);
    }
    param_3 = &DAT_10028870;
    iVar5 = 0;
  }
  if (*(int *)(*(int *)(param_1 + 0x44) + 0x28) != *(int *)(*(int *)(param_1 + 0x38) + 0xf8)) {
    FUN_100028c0(param_1);
  }
  *(int *)(iVar1 + 0x4fc) = *(int *)(iVar1 + 0x4fc) + param_2 / 3;
  (**(code **)(**(int **)(iVar1 + 0x294) + 0x80))
            (*(int **)(iVar1 + 0x294),4,
             *(undefined4 *)(param_1 + 0xc4 + *(int *)(param_1 + 0x90) * 4),iVar5,iVar2 - iVar5,
             param_3,param_2,*(undefined4 *)(param_1 + 0x98));
  return;
}

