/* Giants 1.449 — address bucket region_0055 (NO original-source claim:
 * this file is an address band of the Ghidra export, not a recovered
 * source file). 1 functions, decompiled by Ghidra; names are of
 * mixed provenance (PS2-anchored + LLM-inferred) — see docs/TRUST.md
 * and verify the body before trusting any name. */

/* ===== crt_strdup @ 0x0055001B ===== */
undefined4 crt_strdup(char *param_1)



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

