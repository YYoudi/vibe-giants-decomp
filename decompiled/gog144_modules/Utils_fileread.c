/* Giants 1.449 — module Utils/fileread
 * 2 functions (2 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\Utils/fileread.c(pp) (assert-string evidence)
 */

/* ===== utils_fileread_00538560 @ 0x00538560 ===== */
void utils_fileread_00538560(undefined4 param_1)



{

  mem_free_tagged(param_1,s_C__Giants_source_Utils_fileread__005803a8,0xdd);

  return;

}

/* ===== vfs_fileread_load @ 0x00538580 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void vfs_fileread_load(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)



{

  char cVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  char *pcVar5;

  int iVar6;

  undefined1 *puVar7;

  char local_200 [512];

  

  stream_00538800();

  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_005e2948);

  _DAT_005e2c64 = 0x41200000;

  *param_3 = 0;

  *param_2 = 0;

  if (DAT_005e2c68 != 0) goto LAB_0053878a;

  DAT_005e2c68 = 1;

  iVar3 = FUN_005393e0(DAT_005e2c74,param_1);

  if (iVar3 == 0) {

    crt_sprintf(&DAT_00657400,s_ZipRead_fail___s_005803d4,param_1);

    FUN_00425eb0(&DAT_00657400);

    error_screen_show(&DAT_00657400);

  }

  else {

    iVar6 = *(int *)(iVar3 + 4);

    if (*(int *)(iVar6 + 4) == 0) {

      crt_sprintf(local_200,s__s__s_0058031c,s_Bin_Override_00580324,iVar3 + 0x10);

      iVar3 = binfile_create_open(local_200);

      if (iVar3 != 0) {

        uVar4 = binfile_seek(iVar3);

        *param_3 = uVar4;

        uVar4 = MemAllocMsg(0x1e,uVar4,s_gzpmem_005803cc,s_C__Giants_source_Utils_fileread__005803a8

                            ,0x117);

        *param_2 = uVar4;

        BinFileRead(iVar3,uVar4,*param_3);

        ANM_BinderDestroy_2(iVar3);

      }

    }

    else {

      iVar2 = *(int *)(iVar6 + 4);

      if (iVar2 == 0) {

        pcVar5 = s_Bin_Override_00580324;

LAB_005386d1:

        if (*pcVar5 == '\0') {

          pcVar5 = (char *)(iVar6 + 8);

          iVar6 = -(int)pcVar5;

          do {

            cVar1 = *pcVar5;

            pcVar5[(int)(local_200 + iVar6)] = cVar1;

            pcVar5 = pcVar5 + 1;

          } while (cVar1 != '\0');

        }

        else {

          crt_sprintf(local_200,s__s__s_0058031c,pcVar5,iVar6 + 8);

        }

      }

      else {

        if (iVar2 == 1) {

          pcVar5 = &DAT_00580334;

          goto LAB_005386d1;

        }

        if (iVar2 == 2) {

          if (DAT_005e2a60 != '\0') {

            puVar7 = &DAT_005e2a60;

            goto LAB_005386ba;

          }

        }

        else if (DAT_005e2b60 != '\0') {

          puVar7 = &DAT_005e2b60;

LAB_005386ba:

          crt_sprintf(&DAT_005e2740,s__s_Bin_00580338,puVar7);

          pcVar5 = &DAT_005e2740;

          goto LAB_005386d1;

        }

        local_200[0] = '\0';

      }

      if (*(int *)(iVar3 + 4) != DAT_005e2c88) {

        if (DAT_005e2c88 != 0) {

          utils_lzss_00539cb0();

        }

        DAT_005e2c88 = 0;

        iVar6 = Utils_lzss_00539ac0(local_200);

        if (iVar6 == 0) goto LAB_00538784;

        DAT_005e2c88 = *(int *)(iVar3 + 4);

      }

      uVar4 = MemAllocMsg(0x1e,*(undefined4 *)(iVar3 + 8),s_gzpmem_005803cc,

                          s_C__Giants_source_Utils_fileread__005803a8,0x136);

      *param_2 = uVar4;

      utils_lzss_005395f0(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8),uVar4);

      *param_3 = *(undefined4 *)(iVar3 + 8);

    }

  }

LAB_00538784:

  DAT_005e2c68 = 0;

LAB_0053878a:

  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005e2948);

  return;

}

