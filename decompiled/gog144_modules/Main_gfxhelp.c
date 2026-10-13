/* Giants 1.449 — module Main/gfxhelp
 * 2 functions (2 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\Main/gfxhelp.c(pp) (assert-string evidence)
 */

/* ===== main_gfxhelp_00451e10 @ 0x00451E10 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void main_gfxhelp_00451e10(void)



{

  undefined4 uVar1;

  

  _DAT_00656424 = (**(code **)(DAT_00656420 + 8))(DAT_00656420);

  DAT_00656428 = (**(code **)(DAT_00656420 + 4))(DAT_00656420);

  DAT_00656434 = (**(code **)(DAT_00656420 + 0xc))(DAT_00656420,2,2,0);

  DAT_00656438 = (**(code **)(DAT_00656420 + 0xc))(DAT_00656420,2,0x80,0x80);

  DAT_0065643c = (**(code **)(DAT_00656420 + 0xc))(DAT_00656420,2,4000,0);

  (**(code **)(DAT_00656434 + 0xc))(DAT_00656434,DAT_00656428);

  (**(code **)(DAT_00656438 + 0xc))(DAT_00656438,DAT_00656428);

  (**(code **)(DAT_0065643c + 0xc))(DAT_0065643c,DAT_00656428);

  DAT_0065642c = (**(code **)(DAT_00656420 + 4))(DAT_00656420);

  DAT_00656440 = (**(code **)(DAT_00656420 + 0xc))(DAT_00656420,2,0x100,0);

  DAT_00656448 = (**(code **)(DAT_00656420 + 0xc))(DAT_00656420,2,0x100,0x100);

  DAT_00656444 = (**(code **)(DAT_00656420 + 0xc))(DAT_00656420,2,0x200,0);

  (**(code **)(DAT_00656440 + 0xc))(DAT_00656440,DAT_0065642c);

  (**(code **)(DAT_00656448 + 0xc))(DAT_00656448,DAT_0065642c);

  (**(code **)(DAT_00656444 + 0xc))(DAT_00656444,DAT_0065642c);

  DAT_00656430 = (**(code **)(DAT_00656420 + 4))(DAT_00656420);

  DAT_0065644c = (**(code **)(DAT_00656420 + 0xc))(DAT_00656420,0,11000,0);

  DAT_00656450 = (**(code **)(DAT_00656420 + 0xc))(DAT_00656420,6,11000,0);

  if (DAT_00633244 < 3) {

    uVar1 = 1;

  }

  else {

    uVar1 = 8;

  }

  DAT_00656454 = (**(code **)(DAT_00656420 + 0xc))(DAT_00656420,uVar1,11000,0);

  (**(code **)(DAT_0065644c + 0xc))(DAT_0065644c,DAT_00656430);

  (**(code **)(DAT_00656450 + 0xc))(DAT_00656450,DAT_00656430);

  (**(code **)(DAT_00656454 + 0xc))(DAT_00656454,DAT_00656430);

  DAT_00656458 = MemAllocMsg(9,0x203a0,s_bumpmap_basis_memory_00559db8,

                             s_C__Giants_source_Main_gfxhelp_c_00559dd0,0x6c);

  DAT_0065645c = MemAllocMsg(9,0x203a0,s_bumpmap_basis_memory_00559db8,

                             s_C__Giants_source_Main_gfxhelp_c_00559dd0,0x6d);

  return;

}

/* ===== main_gfxhelp_00452000 @ 0x00452000 ===== */
void main_gfxhelp_00452000(void)



{

  mem_free_tagged(DAT_00656458,s_C__Giants_source_Main_gfxhelp_c_00559dd0,0x73);

  mem_free_tagged(DAT_0065645c,s_C__Giants_source_Main_gfxhelp_c_00559dd0,0x74);

  return;

}

