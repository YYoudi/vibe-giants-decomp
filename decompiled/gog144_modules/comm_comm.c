/* Giants 1.449 — module comm/comm
 * 4 functions (4 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\comm/comm.c(pp) (assert-string evidence)
 */

/* ===== comm_comm_00520490 @ 0x00520490 ===== */
/* WARNING: Type propagation algorithm not settling */



void comm_comm_00520490(void)



{

  int *piVar1;

  float fVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  WCHAR **ppWVar6;

  int iVar7;

  float fVar8;

  undefined4 *local_26c;

  WCHAR *local_268 [5];

  undefined4 uStack_254;

  undefined4 uStack_250;

  undefined4 uStack_24c;

  undefined4 uStack_248;

  undefined4 uStack_244;

  undefined4 uStack_240;

  WCHAR local_208 [260];

  

  uVar3 = wredit_00428460(DAT_005def88,1);

  if ((DAT_00633180 != 0) ||

     (local_26c = (undefined4 *)wredit_00428670(DAT_005def88,1,uVar3),

     local_26c != (undefined4 *)0x0)) {

    MultiByteToWideChar(0,0,&DAT_0063304c,-1,local_208,0x208);

    ppWVar6 = local_268;

    for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {

      *ppWVar6 = (WCHAR *)0x0;

      ppWVar6 = ppWVar6 + 1;

    }

    local_268[2] = local_208;

    local_268[0] = (WCHAR *)0x18;

    local_268[1] = (WCHAR *)0x1;

    iVar5 = (**(code **)(*DAT_005def64 + 0x2c))(DAT_005def64,local_268,0,0,0x80000000);

    if (-1 < iVar5) {

      ppWVar6 = local_268;

      for (iVar5 = 0x12; ppWVar6 = (WCHAR **)((int)ppWVar6 + 4), iVar5 != 0; iVar5 = iVar5 + -1) {

        *ppWVar6 = (WCHAR *)0x0;

      }

      local_268[1] = (WCHAR *)0x48;

      uStack_24c = *(undefined4 *)PTR_DAT_0057dc4c;

      uStack_248 = *(undefined4 *)(PTR_DAT_0057dc4c + 4);

      uStack_244 = *(undefined4 *)(PTR_DAT_0057dc4c + 8);

      uStack_240 = *(undefined4 *)(PTR_DAT_0057dc4c + 0xc);

      if (DAT_00633180 == 0) {

        local_268[3] = (WCHAR *)*local_26c;

        local_268[4] = (WCHAR *)local_26c[1];

        uStack_254 = local_26c[2];

        uStack_250 = local_26c[3];

      }

      DAT_005def80 = 4;

      if (DAT_00633180 == 0) {

        (**(code **)(*DAT_005def6c + 8))(DAT_005def6c);

        (**(code **)(*DAT_005def70 + 8))(DAT_005def70);

        (**(code **)(*(int *)local_26c[6] + 0x14))((int *)local_26c[6],&DAT_005def70);

        (**(code **)(*(int *)local_26c[5] + 0x14))((int *)local_26c[5],&DAT_005def6c);

      }

      iVar5 = (**(code **)(*DAT_005def64 + 0x1c))

                        (DAT_005def64,local_268 + 1,DAT_005def70,

                         (DAT_00633180 != 0) - 1 & (uint)DAT_005def6c,0,0,0,0,0,&DAT_005def78,0);

      if ((iVar5 != -0x7ffffff6) && (iVar5 < 0)) {

        if (DAT_005def74 != 0) {

          (**(code **)(*DAT_005def64 + 0x18))(DAT_005def64,DAT_005def74,0);

          DAT_005def74 = 0;

        }

        main_dlog_004273b0(DAT_005def88,0x3ea,0x3f000000,0x41200000,0x8a000000,

                           s_ErrDPOpenSess_0057def4);

        (**(code **)(DAT_00656420 + 0x98))(DAT_00656420,0);

        FUN_00451cf0();

        FUN_00428810(DAT_005def88);

        FUN_00451da0();

        (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

        (**(code **)(DAT_00656420 + 0x98))(DAT_00656420,0);

        FUN_00451cf0();

        FUN_00428810(DAT_005def88);

        FUN_00451da0();

        (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

        FUN_00518950();

        fVar2 = DAT_006328e8 - DAT_006328e8;

        fVar8 = DAT_006328e8;

        while (fVar2 < 5.0) {

          FUN_00518950();

          fVar2 = DAT_006328e8 - fVar8;

        }

        FUN_0051fba0();

        iVar5 = main_dlog_00428490(DAT_005def88,1);

        if (0 < iVar5) {

          iVar7 = 0;

          do {

            iVar4 = wredit_00428670(DAT_005def88,1,iVar7);

            if (iVar4 != 0) {

              piVar1 = *(int **)(iVar4 + 0x14);

              if (piVar1 != (int *)0x0) {

                (**(code **)(*piVar1 + 8))(piVar1);

                *(undefined4 *)(iVar4 + 0x14) = 0;

              }

              piVar1 = *(int **)(iVar4 + 0x18);

              if (piVar1 != (int *)0x0) {

                (**(code **)(*piVar1 + 8))(piVar1);

                *(undefined4 *)(iVar4 + 0x18) = 0;

              }

              mem_free_tagged(iVar4,s_C__Giants_source_comm_comm_cpp_0057ded4,0x363);

            }

            iVar7 = iVar7 + 1;

          } while (iVar7 < iVar5);

        }

        if (DAT_005def88 != 0) {

          main_dlog_00427180(DAT_005def88);

        }

        DAT_005def88 = 0;

        menu_keymap_screen();

        return;

      }

      if (DAT_005def74 != 0) {

        (**(code **)(*DAT_005def64 + 0x18))(DAT_005def64,DAT_005def74,0);

        DAT_005def74 = 0;

      }

    }

  }

  return;

}

/* ===== comm_comm_00529e00 @ 0x00529E00 ===== */
void comm_comm_00529e00(void)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  undefined4 uStack_130;

  int *piStack_128;

  undefined4 uStack_124;

  undefined4 *puStack_120;

  undefined4 uStack_11c;

  undefined4 local_114 [69];

  

  if (DAT_005def80 != 5) {

    return;

  }

  if (DAT_00632f44 == 0) {

    return;

  }

  uStack_11c = 0;

  puStack_120 = local_114;

  uStack_124 = 0;

  local_114[0] = 0;

  piStack_128 = DAT_005def60;

  iVar1 = (**(code **)(*DAT_005def60 + 0x1c))();

  if (iVar1 != -0x7fea7f00) {

    uStack_130 = 0x529e4f;

    FUN_0051ea20();

    return;

  }

  uStack_130 = 0x10df;

  puVar2 = (undefined4 *)

           FUN_0053a700(0,uStack_124,s_dpappdesc_0057e950,s_C__Giants_source_comm_comm_cpp_0057ded4)

  ;

  uStack_130 = 0;

  puVar3 = puVar2;

  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *puVar2 = 0x48;

  iVar1 = (**(code **)(*DAT_005def60 + 0x1c))(DAT_005def60,puVar2,&uStack_124);

  if (iVar1 != 0) {

    FUN_0051ea20(s_could_not_get_session_desc_in_se_0057e920);

    mem_free_tagged(puVar2,s_C__Giants_source_comm_comm_cpp_0057ded4,0x10e6);

    return;

  }

  uStack_130 = 0;

  piStack_128 = (int *)0x0;

  uStack_124 = 0;

  FUN_00529C00(&uStack_130,&stack0xfffffed4,&piStack_128,&uStack_124);

  puVar2[0x10] = &uStack_130;

  puVar2[0x11] = 0x10;

  puVar2[10] = DAT_00632f34;

  MultiByteToWideChar(0,0,&DAT_00632f48,-1,(LPWSTR)&puStack_120,0x100);

  puVar2[0xc] = &puStack_120;

  iVar1 = (**(code **)(*DAT_005def60 + 0x30))(DAT_005def60,puVar2,0);

  if (iVar1 == -0x7ff8ffa9) {

    FUN_0051ea20(s_Invalid_Params_in_SetSessionDesc_0057e8e8);

  }

  else if (iVar1 == 0) goto LAB_00529f64;

  FUN_0051ea20(s_trouble_in_SetSessionDesc_in_set_0057e8b8);

LAB_00529f64:

  mem_free_tagged(puVar2,s_C__Giants_source_comm_comm_cpp_0057ded4,0x10fc);

  return;

}

/* ===== comm_comm_00529f80 @ 0x00529F80 ===== */
void comm_comm_00529f80(void)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  undefined4 uStack_14;

  undefined4 *puStack_10;

  undefined4 uStack_c;

  undefined4 local_4;

  

  if (DAT_00632f44 == 0) {

    uStack_c = 0;

    puStack_10 = &local_4;

    uStack_14 = 0;

    local_4 = 0;

    iVar1 = (**(code **)(*DAT_005def64 + 0x28))(DAT_005def64);

    if (iVar1 != -0x7fea7f00) {

      FUN_0051ea20(s_tried_to_get_req_d_size_for_get__0057e9e8);

      return;

    }

    puVar2 = (undefined4 *)

             FUN_0053a700(0,uStack_14,s_dpappdesc_0057e950,s_C__Giants_source_comm_comm_cpp_0057ded4

                          ,0x1112);

    puVar3 = puVar2;

    for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    *puVar2 = 0x48;

    iVar1 = (**(code **)(*DAT_005def64 + 0x28))(DAT_005def64,puVar2,&uStack_14,0);

    if (iVar1 != 0) {

      FUN_0051ea20(s_could_not_get_session_desc_in_ge_0057e9b8);

      mem_free_tagged(puVar2,s_C__Giants_source_comm_comm_cpp_0057ded4,0x1119);

      return;

    }

    FUN_0052a050(puVar2);

    mem_free_tagged(puVar2,s_C__Giants_source_comm_comm_cpp_0057ded4,0x111f);

  }

  return;

}

/* ===== comm_comm_0052acc0 @ 0x0052ACC0 ===== */
undefined4 comm_comm_0052acc0(LPSTR param_1)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  undefined4 *puStack_18;

  undefined4 uStack_14;

  undefined4 local_4;

  

  uStack_14 = 0;

  puStack_18 = &local_4;

  local_4 = 0;

  iVar1 = (**(code **)(*DAT_005def60 + 0x24))(DAT_005def60);

  if (iVar1 == -0x7fea7be0) {

    return 0;

  }

  if (iVar1 != -0x7fea7f00) {

    FUN_0051ea20(s_tried_to_get_req_d_size_for_clie_0057ea80);

    return 0;

  }

  puVar2 = (undefined4 *)

           FUN_0053a700(0,puStack_18,s_clientenum_0057ea70,s_C__Giants_source_comm_comm_cpp_0057ded4

                        ,0x122c);

  puVar3 = puVar2;

  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *puVar2 = 0x18;

  iVar1 = (**(code **)(*DAT_005def60 + 0x24))(DAT_005def60,param_1,puVar2,&puStack_18,0);

  if (iVar1 != 0) {

    FUN_0051ea20(s_could_not_get_client_info_0057ea54);

    mem_free_tagged(puVar2,s_C__Giants_source_comm_comm_cpp_0057ded4,0x1233);

    return 0;

  }

  WideCharToMultiByte(0,0,(LPCWSTR)puVar2[2],-1,param_1,0,(LPCSTR)0x0,(LPBOOL)0x0);

  param_1[-1] = '\0';

  mem_free_tagged(puVar2,s_C__Giants_source_comm_comm_cpp_0057ded4,0x1238);

  return 1;

}

