/* Giants 1.449 — module main/readdata
 * 1 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/readdata.c(pp) (assert-string evidence)
 */

/* ===== main_readdata_004adfa0 @ 0x004ADFA0 ===== */
void main_readdata_004adfa0(void)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  char *pcVar6;

  char *pcVar7;

  undefined4 local_8;

  int local_4;

  

  iVar3 = stream_player_start(s_GameObj_bin_0055feac);

  if (iVar3 == 0) {

    error_screen_show(s_Failed_to_open_GameObj_bin_0055fe90);

    return;

  }

  FUN_005178d0(iVar3,&local_4,4);

  if (local_4 == 0x1a0002dd) {

    FUN_005178d0(iVar3,&local_8,4);

    pcVar4 = (char *)FUN_0053a700(0x13,local_8,&DAT_0055fe48,

                                  s_C__Giants_source_main_readdata_c_0055fe50,0x25);

    FUN_005178d0(iVar3,pcVar4,local_8);

    pcVar5 = pcVar4;

    while( true ) {

      cVar2 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      if (cVar2 == -1) break;

      if (cVar2 == '\x01') {

        cVar2 = *pcVar5;

        pcVar6 = pcVar5;

        while (cVar2 != '\0') {

          pcVar7 = pcVar6 + 1;

          pcVar6 = pcVar6 + 1;

          cVar2 = *pcVar7;

        }

        cVar2 = pcVar6[1];

        pcVar7 = pcVar6 + 1;

        while (cVar2 != '\0') {

          pcVar1 = pcVar7 + 1;

          pcVar7 = pcVar7 + 1;

          cVar2 = *pcVar1;

        }

        DAT_00632d2c = BinFileSeek_5(pcVar5,pcVar6 + 1);

        pcVar5 = pcVar7 + 1;

      }

      else if (cVar2 == '\x02') {

        cVar2 = *pcVar5;

        pcVar6 = pcVar5;

        while (cVar2 != '\0') {

          pcVar7 = pcVar6 + 1;

          pcVar6 = pcVar6 + 1;

          cVar2 = *pcVar7;

        }

        cVar2 = pcVar6[1];

        pcVar7 = pcVar6 + 1;

        while (cVar2 != '\0') {

          pcVar1 = pcVar7 + 1;

          pcVar7 = pcVar7 + 1;

          cVar2 = *pcVar1;

        }

        DAT_00632d30 = BinFileSeek_5(pcVar5,pcVar6 + 1);

        pcVar5 = pcVar7 + 1;

      }

      else if (cVar2 == '\x03') {

        cVar2 = *pcVar5;

        pcVar6 = pcVar5;

        while (cVar2 != '\0') {

          pcVar7 = pcVar6 + 1;

          pcVar6 = pcVar6 + 1;

          cVar2 = *pcVar7;

        }

        cVar2 = pcVar6[1];

        pcVar7 = pcVar6 + 1;

        while (cVar2 != '\0') {

          pcVar1 = pcVar7 + 1;

          pcVar7 = pcVar7 + 1;

          cVar2 = *pcVar1;

        }

        DAT_00632d3c = BinFileSeek_5(pcVar5,pcVar6 + 1);

        pcVar5 = pcVar7 + 1;

      }

      else if (cVar2 == '\x04') {

        cVar2 = *pcVar5;

        pcVar6 = pcVar5;

        while (cVar2 != '\0') {

          pcVar7 = pcVar6 + 1;

          pcVar6 = pcVar6 + 1;

          cVar2 = *pcVar7;

        }

        cVar2 = pcVar6[1];

        pcVar7 = pcVar6 + 1;

        while (cVar2 != '\0') {

          pcVar1 = pcVar7 + 1;

          pcVar7 = pcVar7 + 1;

          cVar2 = *pcVar1;

        }

        DAT_00632d40 = BinFileSeek_5(pcVar5,pcVar6 + 1);

        pcVar5 = pcVar7 + 1;

      }

      else if (cVar2 == '\x05') {

        cVar2 = *pcVar5;

        pcVar6 = pcVar5;

        while (cVar2 != '\0') {

          pcVar7 = pcVar6 + 1;

          pcVar6 = pcVar6 + 1;

          cVar2 = *pcVar7;

        }

        cVar2 = pcVar6[1];

        pcVar7 = pcVar6 + 1;

        while (cVar2 != '\0') {

          pcVar1 = pcVar7 + 1;

          pcVar7 = pcVar7 + 1;

          cVar2 = *pcVar1;

        }

        DAT_00632d44 = BinFileSeek_5(pcVar5,pcVar6 + 1);

        pcVar5 = pcVar7 + 1;

      }

      else if (cVar2 == '\x06') {

        cVar2 = *pcVar5;

        pcVar6 = pcVar5;

        while (cVar2 != '\0') {

          pcVar7 = pcVar6 + 1;

          pcVar6 = pcVar6 + 1;

          cVar2 = *pcVar7;

        }

        cVar2 = pcVar6[1];

        pcVar7 = pcVar6 + 1;

        while (cVar2 != '\0') {

          pcVar1 = pcVar7 + 1;

          pcVar7 = pcVar7 + 1;

          cVar2 = *pcVar1;

        }

        DAT_00632d48 = BinFileSeek_5(pcVar5,pcVar6 + 1);

        pcVar5 = pcVar7 + 1;

      }

      else if (cVar2 == '\a') {

        cVar2 = *pcVar5;

        pcVar6 = pcVar5;

        while (cVar2 != '\0') {

          pcVar7 = pcVar6 + 1;

          pcVar6 = pcVar6 + 1;

          cVar2 = *pcVar7;

        }

        cVar2 = pcVar6[1];

        pcVar7 = pcVar6 + 1;

        while (cVar2 != '\0') {

          pcVar1 = pcVar7 + 1;

          pcVar7 = pcVar7 + 1;

          cVar2 = *pcVar1;

        }

        DAT_00632d38 = BinFileSeek_5(pcVar5,pcVar6 + 1);

        pcVar5 = pcVar7 + 1;

      }

      else if (cVar2 == '\b') {

        cVar2 = *pcVar5;

        pcVar6 = pcVar5;

        while (cVar2 != '\0') {

          pcVar7 = pcVar6 + 1;

          pcVar6 = pcVar6 + 1;

          cVar2 = *pcVar7;

        }

        cVar2 = pcVar6[1];

        pcVar7 = pcVar6 + 1;

        while (cVar2 != '\0') {

          pcVar1 = pcVar7 + 1;

          pcVar7 = pcVar7 + 1;

          cVar2 = *pcVar1;

        }

        DAT_00632d34 = BinFileSeek_5(pcVar5,pcVar6 + 1);

        pcVar5 = pcVar7 + 1;

      }

      else if (cVar2 == '\t') {

        cVar2 = *pcVar5;

        while (cVar2 != '\0') {

          pcVar6 = pcVar5 + 1;

          pcVar5 = pcVar5 + 1;

          cVar2 = *pcVar6;

        }

        cVar2 = pcVar5[1];

        while (cVar2 != '\0') {

          cVar2 = pcVar5[2];

          pcVar5 = pcVar5 + 1;

        }

        pcVar5 = pcVar5 + 2;

      }

    }

    mem_free_tagged(pcVar4,s_C__Giants_source_main_readdata_c_0055fe50,0x95);

    ANM_BinderDestroy_2(iVar3);

    return;

  }

  error_screen_show(s_Bad_version_for_GameObj_bin_0055fe74);

  ANM_BinderDestroy_2(iVar3);

  return;

}

