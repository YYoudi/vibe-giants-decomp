/* Giants 1.449 — module main/textget
 * 2 functions (2 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/textget.c(pp) (assert-string evidence)
 */

/* ===== main_textget_005078e0 @ 0x005078E0 ===== */
void main_textget_005078e0(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  if (DAT_0057bc78 == 0) {

    if (DAT_0057bc94 != 0) {

      utils_hash_00539470(DAT_0057bc94);

    }

    if (DAT_0057bc88 != 0) {

      mem_free_tagged(DAT_0057bc88,s_C__Giants_source_main_textget_c_0057bc98,0x26);

    }

    if (DAT_0057bc8c != 0) {

      mem_free_tagged(DAT_0057bc8c,s_C__Giants_source_main_textget_c_0057bc98,0x29);

    }

    if (DAT_0057bc90 != 0) {

      mem_free_tagged(DAT_0057bc90,s_C__Giants_source_main_textget_c_0057bc98,0x2c);

    }

    puVar2 = &DAT_0057bc78;

    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    DAT_0057bc78 = 1;

  }

  return;

}

/* ===== TextPtrInit__Fv @ 0x00507970 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void TextPtrInit__Fv(void)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  undefined1 local_100 [256];

  

  if (DAT_0057bc78 != 0) {

    puVar4 = &DAT_0057bc78;

    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    uVar1 = __default_unexpected__Fv();

    FUN_00542f27(local_100,s_GText_s_bin_0057bcd4,uVar1);

    iVar3 = stream_player_start(local_100);

    if (iVar3 != 0) {

      BinFileRead(iVar3,&DAT_0057bc7c,4);

      BinFileRead(iVar3,&DAT_0057bc80,4);

      BinFileRead(iVar3,&DAT_0057bc84,4);

      DAT_0057bc88 = FUN_0053a700(0x1c,DAT_0057bc7c * 8,s_keyoffs_0057bccc,

                                  s_C__Giants_source_main_textget_c_0057bc98,0x5a);

      DAT_0057bc8c = FUN_0053a700(0x1c,DAT_0057bc80,s_keydata_0057bcc4,

                                  s_C__Giants_source_main_textget_c_0057bc98,0x5b);

      DAT_0057bc90 = FUN_0053a700(0x1c,DAT_0057bc84,s_textdata_0057bcb8,

                                  s_C__Giants_source_main_textget_c_0057bc98,0x5c);

      BinFileRead(iVar3,DAT_0057bc88,DAT_0057bc7c * 8);

      BinFileRead(iVar3,DAT_0057bc8c,DAT_0057bc80);

      BinFileRead(iVar3,DAT_0057bc90,DAT_0057bc84);

      ANM_BinderDestroy_2(iVar3);

      DAT_0057bc94 = utils_hash_005391c0(0x76d,4,1);

      iVar3 = 0;

      if (0 < DAT_0057bc7c) {

        do {

          iVar2 = utils_hash_00539230(DAT_0057bc94,*(int *)(DAT_0057bc88 + iVar3 * 8) + DAT_0057bc8c

                                     );

          *(int *)(iVar2 + 4) = *(int *)(DAT_0057bc88 + 4 + iVar3 * 8) + DAT_0057bc90;

          iVar3 = iVar3 + 1;

        } while (iVar3 < DAT_0057bc7c);

      }

    }

  }

  return;

}

