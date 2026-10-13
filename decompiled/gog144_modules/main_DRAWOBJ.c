/* Giants 1.449 — module main/DRAWOBJ
 * 2 functions (2 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/DRAWOBJ.c(pp) (assert-string evidence)
 */

/* ===== main_drawobj_0042d490 @ 0x0042D490 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void main_drawobj_0042d490(void)



{

  if (DAT_0059ac9c == 0) {

    DAT_0059ac9c = MemAllocMsg(9,12000,&DAT_00556604,s_C__Giants_source_main_DRAWOBJ_C_00556608,

                               0x5e8);

  }

  if (DAT_0059aca0 == 0) {

    DAT_0059aca0 = MemAllocMsg(9,12000,&DAT_00556604,s_C__Giants_source_main_DRAWOBJ_C_00556608,

                               0x5ea);

  }

  _DAT_0059ac7c = 0;

  DAT_0059ac80 = 0;

  return;

}

/* ===== main_drawobj_0042d500 @ 0x0042D500 ===== */
void main_drawobj_0042d500(void)



{

  if (DAT_0059ac9c != 0) {

    mem_free_tagged(DAT_0059ac9c,s_C__Giants_source_main_DRAWOBJ_C_00556608,0x5f2);

  }

  DAT_0059ac9c = 0;

  if (DAT_0059aca0 != 0) {

    mem_free_tagged(DAT_0059aca0,s_C__Giants_source_main_DRAWOBJ_C_00556608,0x5f6);

  }

  DAT_0059aca0 = 0;

  return;

}

