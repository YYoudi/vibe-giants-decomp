/* Giants 1.449 — module main/blood
 * 4 functions (3 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/blood.c(pp) (assert-string evidence)
 */

/* ===== FUN_0040b220 @ 0x0040B220 ===== */
/* PS2 candidate: texture_object_debug_dump (conf 0.333) */



void FUN_0040b220(void)



{

  int iVar1;

  

  DAT_005841c4 = MemAllocMsg(4,26000,s_bigblood_00555008,s_C__Giants_source_main_blood_c_00555014,

                             0x23);

  iVar1 = 0;

  do {

    *(int *)(iVar1 + DAT_005841c4) = iVar1 + 0x34 + DAT_005841c4;

    iVar1 = iVar1 + 0x34;

  } while (iVar1 < 0x655c);

  *(undefined4 *)(DAT_005841c4 + 0x655c) = 0;

  DAT_00632da8 = 0;

  DAT_00632dac = DAT_005841c4;

  DAT_005841c8 = main_texture_00508750(s_bloodblob_00554ffc);

  return;

}

/* ===== main_blood_0040b290 @ 0x0040B290 ===== */
void main_blood_0040b290(void)



{

  mem_free_tagged(DAT_005841c4,s_C__Giants_source_main_blood_c_00555014,0x31);

  DAT_005841c4 = 0;

  DAT_00632da8 = 0;

  DAT_00632dac = 0;

  return;

}

/* ===== main_blood_0040bab0 @ 0x0040BAB0 ===== */
void main_blood_0040bab0(void)



{

  int iVar1;

  

  DAT_005841c0 = MemAllocMsg(4,0xe10,s_bigwound_00555034,s_C__Giants_source_main_blood_c_00555014,

                             0x14c);

  iVar1 = 0;

  do {

    *(int *)(iVar1 + DAT_005841c0) = iVar1 + 0x48 + DAT_005841c0;

    iVar1 = iVar1 + 0x48;

  } while (iVar1 < 0xdc8);

  *(undefined4 *)(DAT_005841c0 + 0xdc8) = 0;

  DAT_00632db0 = 0;

  DAT_00632db4 = DAT_005841c0;

  return;

}

/* ===== main_blood_0040bb10 @ 0x0040BB10 ===== */
void main_blood_0040bb10(void)



{

  mem_free_tagged(DAT_005841c0,s_C__Giants_source_main_blood_c_00555014,0x158);

  DAT_005841c0 = 0;

  DAT_00632db0 = 0;

  DAT_00632db4 = 0;

  return;

}

