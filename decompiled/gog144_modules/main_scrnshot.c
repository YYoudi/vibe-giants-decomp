/* Giants 1.449 — module main/scrnshot
 * 1 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/scrnshot.c(pp) (assert-string evidence)
 */

/* ===== main_scrnshot_004ebae0 @ 0x004EBAE0 ===== */
void main_scrnshot_004ebae0(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  undefined4 *puVar6;

  undefined1 *puVar7;

  undefined1 uStack_168;

  undefined1 uStack_167;

  undefined1 uStack_166;

  undefined1 uStack_165;

  undefined1 uStack_164;

  undefined2 uStack_163;

  undefined1 uStack_161;

  undefined4 uStack_160;

  undefined4 uStack_15c;

  undefined2 uStack_158;

  undefined4 auStack_154 [2];

  char acStack_14c [4];

  char acStack_148 [4];

  char acStack_144 [4];

  char acStack_140 [4];

  char acStack_13c [4];

  undefined1 auStack_138 [32];

  undefined1 auStack_118 [25];

  undefined1 auStack_ff [255];

  

  iVar1 = FUN_0053a700(0x13,DAT_00632e88 * DAT_00632e84 * 3,s_scrnshot_00561b74,

                       s_C__Giants_source_main_scrnshot_c_00561b80,99);

  (**(code **)(DAT_00656420 + 0xe0))(DAT_00656420,iVar1);

  iVar4 = 0;

  iVar5 = 0;

  iVar2 = crt_strcpy_ext(s_GIANT__TGA_00561b68,auStack_118);

  if (iVar2 != -1) {

    do {

      iVar3 = ANM_BinderDestroy_3(auStack_ff);

      if (iVar5 < iVar3) {

        iVar5 = iVar3;

      }

      iVar3 = FUN_005448eb(iVar2,auStack_118);

    } while (iVar3 == 0);

    FUN_005449b3(iVar2);

  }

  FUN_00542f27(auStack_138,s_GIANT_3_3d_TGA_00561b58,iVar5 + 1);

  uStack_15c = CONCAT22((undefined2)DAT_00632e88,(short)DAT_00632e84);

  puVar6 = auStack_154;

  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  *(undefined2 *)puVar6 = 0;

  acStack_144[0] = s_TRUEVISION_XFILE__00561b44[8];

  acStack_144[1] = s_TRUEVISION_XFILE__00561b44[9];

  acStack_144[2] = s_TRUEVISION_XFILE__00561b44[10];

  acStack_144[3] = s_TRUEVISION_XFILE__00561b44[0xb];

  acStack_14c[0] = s_TRUEVISION_XFILE__00561b44[0];

  acStack_14c[1] = s_TRUEVISION_XFILE__00561b44[1];

  acStack_14c[2] = s_TRUEVISION_XFILE__00561b44[2];

  acStack_14c[3] = s_TRUEVISION_XFILE__00561b44[3];

  acStack_148[0] = s_TRUEVISION_XFILE__00561b44[4];

  acStack_148[1] = s_TRUEVISION_XFILE__00561b44[5];

  acStack_148[2] = s_TRUEVISION_XFILE__00561b44[6];

  acStack_148[3] = s_TRUEVISION_XFILE__00561b44[7];

  uStack_168 = 0;

  uStack_167 = 0;

  uStack_166 = 2;

  uStack_165 = 0;

  uStack_164 = 0;

  uStack_163 = 0;

  uStack_161 = 0;

  uStack_160 = 0;

  uStack_158 = 0x2018;

  auStack_154[0] = 0;

  auStack_154[1] = 0;

  acStack_140[0] = s_TRUEVISION_XFILE__00561b44[0xc];

  acStack_140[1] = s_TRUEVISION_XFILE__00561b44[0xd];

  acStack_140[2] = s_TRUEVISION_XFILE__00561b44[0xe];

  acStack_140[3] = s_TRUEVISION_XFILE__00561b44[0xf];

  acStack_13c[0] = s_TRUEVISION_XFILE__00561b44[0x10];

  acStack_13c[1] = s_TRUEVISION_XFILE__00561b44[0x11];

  iVar5 = BinFileSeek_2(auStack_138,&DAT_00555e30);

  if (iVar5 != 0) {

    FUN_00543a24(&uStack_168,0x12,1,iVar5);

    if (0 < DAT_00632e88 * DAT_00632e84) {

      puVar7 = (undefined1 *)(iVar1 + 1);

      do {

        crt_flsbuf_ext(puVar7[1],iVar5);

        crt_flsbuf_ext(*puVar7,iVar5);

        crt_flsbuf_ext(puVar7[-1],iVar5);

        puVar7 = puVar7 + 3;

        iVar4 = iVar4 + 1;

      } while (iVar4 < DAT_00632e88 * DAT_00632e84);

    }

    FUN_00543a24(auStack_154,0x1a,1,iVar5);

    editor_0054384c(iVar5);

    mem_free_tagged(iVar1,s_C__Giants_source_main_scrnshot_c_00561b80,0xa7);

  }

  return;

}

