/* Giants 1.449 — module main/verm
 * 1 functions (0 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/verm.c(pp) (assert-string evidence)
 */

/* ===== FUN_0050f830 @ 0x0050F830 ===== */
void FUN_0050f830(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  

  puVar1 = (undefined4 *)

           FUN_0053a700(0x13,0x28,&DAT_0057bfd8,s_C__Giants_source_main_verm_c_0057bfdc,0x466);

  puVar3 = *(undefined4 **)(param_2 + 0x100);

  puVar4 = puVar1;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar4 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar4 = puVar4 + 1;

  }

  FUN_00470670(param_1,puVar1 + 1);

  *param_3 = 0x28;

  *param_4 = puVar1;

  return;

}

