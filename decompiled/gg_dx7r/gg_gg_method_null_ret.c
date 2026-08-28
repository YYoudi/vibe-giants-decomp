// gg_dx7r.dll - gg_method_null_ret @ 0x100025C0

int __cdecl FUN_100025c0(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x60) < *(int *)(param_1 + 0x68) + param_2) {
    (**(code **)(param_1 + 0x2c))(param_1);
    if (*(int *)(param_1 + 0x60) < *(int *)(param_1 + 0x68) + param_2) {
      return 0;
    }
  }
  **(undefined2 **)(param_1 + 0x74) = (short)param_2;
  iVar1 = *(int *)(param_1 + 0x68);
  *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + 2;
  *(int *)(param_1 + 0x68) = iVar1 + param_2;
  return *(int *)(param_1 + 0x84) * iVar1 + *(int *)(param_1 + 0x6c);
}

