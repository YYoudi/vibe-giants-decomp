/* Giants 1.449 — module _unmapped_0055
 * 1 functions (0 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0055.c(pp) (assert-string evidence)
 */

/* ===== FUN_0055001b @ 0x0055001B ===== */
undefined4 FUN_0055001b(char *param_1)



{

  size_t sVar1;

  void *pvVar2;

  undefined4 uVar3;

  

  if (param_1 != (char *)0x0) {

    sVar1 = _strlen(param_1);

    pvVar2 = _malloc(sVar1 + 1);

    if (pvVar2 != (void *)0x0) {

      uVar3 = strcpy(pvVar2,param_1);

      return uVar3;

    }

  }

  return 0;

}

