/* Giants 1.449 — module _unmapped_0044
 * 76 functions (58 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0044.c(pp) (assert-string evidence)
 */

/* ===== wredit_menu_cleanup_1 @ 0x004400B0 ===== */
void wredit_menu_cleanup_1(void)



{

  char cVar1;

  int iVar2;

  uint uVar3;

  char *pcVar4;

  int iVar5;

  

  dlog_list_navigate_sound(DAT_0059cd7c);

  if ((DAT_00632aa4._3_1_ == '\0') && (DAT_00632aad == '\0')) {

    if (DAT_00632aa8 == '\0') {

      if ((DAT_00632aaa == '\0') || (iVar5 = main_dlog_00427310(DAT_0059cd7c), iVar5 != 1))

      goto LAB_00440165;

      iVar5 = *(int *)(DAT_0059cbd8 + 0x38);

      uVar3 = wredit_00428460(DAT_0059cd7c,1);

      uVar3 = *(uint *)(iVar5 + 0xdc) ^ (*(uint *)(iVar5 + 0xdc) ^ uVar3) & 0xf;

    }

    else {

      iVar5 = *(int *)(DAT_0059cbd8 + 0x38);

      uVar3 = wredit_00428460(DAT_0059cd7c,1);

      uVar3 = *(uint *)(iVar5 + 0xdc) ^ (*(uint *)(iVar5 + 0xdc) ^ uVar3) & 0xf;

    }

    *(uint *)(iVar5 + 0xdc) = uVar3;

  }

  wredit_00439490();

LAB_00440165:

  if ((DAT_0059cd48 == (char *)0x0) || (*DAT_0059cd48 == '\0')) {

    pcVar4 = (char *)FUN_00519CF0();

    if (pcVar4 == (char *)0x0) {

      return;

    }

    if (*pcVar4 == '\0') {

      return;

    }

    if (*pcVar4 == '\b') {

      return;

    }

    iVar5 = (int)&DAT_0059cbb4 - (int)pcVar4;

    do {

      cVar1 = *pcVar4;

      pcVar4[iVar5] = cVar1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    DAT_0059cd48 = &DAT_0059cbb4;

    wredit_00519c70();

  }

  iVar5 = (int)*DAT_0059cd48;

  if (iVar5 != 0) {

    DAT_0059cd48 = DAT_0059cd48 + 1;

    if ((iVar5 < 0x31) || (0x39 < iVar5)) {

      if ((iVar5 < 0x41) || (0x5a < iVar5)) {

        if (iVar5 < 0x61) {

          return;

        }

        if (0x7a < iVar5) {

          return;

        }

        iVar5 = iVar5 + -0x57;

      }

      else {

        iVar5 = iVar5 + -0x37;

      }

    }

    else {

      iVar5 = iVar5 + -0x30;

    }

    if (0 < iVar5) {

      iVar2 = *(int *)(DAT_0059cbd8 + 0x38);

      *(uint *)(iVar2 + 0xdc) =

           *(uint *)(iVar2 + 0xdc) ^ (*(uint *)(iVar2 + 0xdc) ^ iVar5 - 1U) & 0xf;

      wredit_00439490();

      return;

    }

  }

  return;

}

/* ===== wredit_marker_menu_full @ 0x00440230 ===== */
void wredit_marker_menu_full(void)



{

  int iVar1;

  int iVar2;

  char *pcVar3;

  int iVar4;

  undefined4 uVar5;

  int *piVar6;

  int iVar7;

  undefined1 local_100 [256];

  

  if (DAT_0059cbd8 == 0) {

    wredit_00439490();

    return;

  }

  iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

  DAT_0059cd6c = main_dlog_00427150();

  iVar4 = *(int *)(iVar1 + 4);

  main_editor_00438350();

  iVar2 = 0;

  piVar6 = DAT_0059cd30;

  if (0 < DAT_0059cd34) {

    do {

      if (*piVar6 == iVar4) {

        pcVar3 = (char *)(DAT_0059cd30 + iVar2 * 9 + 1);

        goto LAB_00440295;

      }

      iVar2 = iVar2 + 1;

      piVar6 = piVar6 + 9;

    } while (iVar2 < DAT_0059cd34);

  }

  pcVar3 = s__unknown__0055724c;

LAB_00440295:

  crt_sprintf(local_100,s_Object_Type__d___s__005570bc,*(undefined4 *)(iVar1 + 4),pcVar3);

  main_dlog_00427890(DAT_0059cd6c,0,0x3f000000,0,0x88000000,local_100);

  crt_sprintf(local_100,s_Marker_Type____d_00557e84,*(undefined4 *)(iVar1 + 0xe8));

  main_dlog_00427890(DAT_0059cd6c,0,0x3f000000,0x3f800000,0x88000000,local_100);

  iVar4 = AudioDataStreamStatus__Fv_2();

  main_dlog_00427e80(DAT_0059cd6c,1,0x3f000000,0x40400000,0x88000022);

  iVar2 = 0;

  if (-1 < iVar4) {

    do {

      iVar7 = iVar2 + 0x30;

      if (9 < iVar2) {

        iVar7 = iVar2 + 0x37;

      }

      uVar5 = marker_get_name(iVar1,iVar2);

      crt_sprintf(local_100,s__c___s_00557e7c,iVar7,uVar5);

      main_dlog_004281f0(DAT_0059cd6c,1,local_100);

      uVar5 = showchat_mission_objective__Fi(iVar2);

      wredit_004287c0(DAT_0059cd6c,1,iVar2,uVar5);

      iVar2 = iVar2 + 1;

    } while (iVar2 <= iVar4);

  }

  return;

}

/* ===== wredit_menu_cleanup_2 @ 0x004403A0 ===== */
void wredit_menu_cleanup_2(void)



{

  char cVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  char *pcVar5;

  

  dlog_list_navigate_sound(DAT_0059cd6c);

  if ((DAT_00632aa4._3_1_ == '\0') && (DAT_00632aad == '\0')) {

    if ((DAT_00632aa8 == '\0') &&

       ((DAT_00632aaa == '\0' || (iVar3 = main_dlog_00427310(DAT_0059cd6c), iVar3 != 1))))

    goto LAB_00440422;

    uVar4 = wredit_00428460(DAT_0059cd6c,1);

    AudioDataStreamStatus__Fv_2();

    iVar3 = *(int *)(DAT_0059cbd8 + 0x38);

    *(undefined4 *)(iVar3 + 0x174) = 0;

    *(undefined4 *)(iVar3 + 0xe8) = uVar4;

    FUN_00476eb0(iVar3);

  }

  wredit_00439490();

LAB_00440422:

  if ((DAT_0059cd48 == (char *)0x0) || (*DAT_0059cd48 == '\0')) {

    pcVar5 = (char *)FUN_00519CF0();

    if (pcVar5 == (char *)0x0) {

      return;

    }

    if (*pcVar5 == '\0') {

      return;

    }

    if (*pcVar5 == '\b') {

      return;

    }

    iVar3 = (int)&DAT_0059cbb4 - (int)pcVar5;

    do {

      cVar1 = *pcVar5;

      pcVar5[iVar3] = cVar1;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    DAT_0059cd48 = &DAT_0059cbb4;

    wredit_00519c70();

  }

  iVar3 = (int)*DAT_0059cd48;

  if (iVar3 != 0) {

    DAT_0059cd48 = DAT_0059cd48 + 1;

    if ((iVar3 < 0x31) || (0x39 < iVar3)) {

      if ((iVar3 < 0x41) || (0x5a < iVar3)) {

        if (iVar3 < 0x61) {

          return;

        }

        if (0x7a < iVar3) {

          return;

        }

        iVar3 = iVar3 + -0x57;

      }

      else {

        iVar3 = iVar3 + -0x37;

      }

    }

    else {

      iVar3 = iVar3 + -0x30;

    }

    if (0 < iVar3) {

      if (iVar3 == -1) {

        iVar3 = wredit_00428460(DAT_0059cd6c,1);

      }

      AudioDataStreamStatus__Fv_2();

      iVar2 = *(int *)(DAT_0059cbd8 + 0x38);

      *(int *)(iVar2 + 0xe8) = iVar3;

      *(undefined4 *)(iVar2 + 0x174) = 0;

      FUN_00476eb0(iVar2);

      wredit_00439490();

      return;

    }

  }

  return;

}

/* ===== wredit_marker_info3 @ 0x00440500 ===== */
void wredit_marker_info3(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  char *pcVar4;

  int *piVar5;

  undefined1 local_100 [256];

  

  if (DAT_0059cbd8 == 0) {

    wredit_00439490();

    return;

  }

  iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

  DAT_0059cd70 = main_dlog_00427150();

  iVar2 = *(int *)(iVar1 + 4);

  main_editor_00438350();

  iVar3 = 0;

  piVar5 = DAT_0059cd30;

  if (0 < DAT_0059cd34) {

    do {

      if (*piVar5 == iVar2) {

        pcVar4 = (char *)(DAT_0059cd30 + iVar3 * 9 + 1);

        goto LAB_0044055b;

      }

      iVar3 = iVar3 + 1;

      piVar5 = piVar5 + 9;

    } while (iVar3 < DAT_0059cd34);

  }

  pcVar4 = s__unknown__0055724c;

LAB_0044055b:

  crt_sprintf(local_100,s_Object_Type__d___s__005570bc,*(undefined4 *)(iVar1 + 4),pcVar4);

  main_dlog_00427890(DAT_0059cd70,0,0x3f000000,0x40400000,0x88000000,local_100);

  crt_sprintf(local_100,s_Marker_Type_ID_Misc_Misc2____d___0055708c,*(undefined4 *)(iVar1 + 0xe8),

              *(undefined4 *)(iVar1 + 0x174),(double)*(float *)(iVar1 + 0xf8),

              (double)*(float *)(iVar1 + 0xfc));

  main_dlog_00427890(DAT_0059cd70,0,0x3f000000,0x40800000,0x88000000,local_100);

  crt_sprintf(&DAT_0059cd18,&DAT_00557088,*(undefined4 *)(iVar1 + 0x174));

  main_dlog_00427970(DAT_0059cd70,2,0x3f000000,0x40a00000,0x88000008,&DAT_0059cd18,0x10);

  return;

}

/* ===== wredit_menu_cleanup_3 @ 0x00440640 ===== */
void wredit_menu_cleanup_3(void)



{

  char cVar1;

  undefined4 uVar2;

  char *pcVar3;

  int iVar4;

  

  dlog_list_navigate_sound(DAT_0059cd70);

  if ((DAT_00632aa4._3_1_ == '\0') && (DAT_00632aad == '\0')) {

    if (DAT_00632aa8 == '\0') {

      if ((DAT_00632aaa == '\0') || (iVar4 = main_dlog_00427310(DAT_0059cd70), iVar4 != 1))

      goto LAB_004406b2;

      iVar4 = *(int *)(DAT_0059cbd8 + 0x38);

    }

    else {

      iVar4 = *(int *)(DAT_0059cbd8 + 0x38);

    }

    uVar2 = ANM_BinderDestroy_3(&DAT_0059cd18);

    *(undefined4 *)(iVar4 + 0x174) = uVar2;

  }

  wredit_00439490();

LAB_004406b2:

  if ((DAT_0059cd48 == (char *)0x0) || (*DAT_0059cd48 == '\0')) {

    pcVar3 = (char *)FUN_00519CF0();

    if (pcVar3 == (char *)0x0) {

      return;

    }

    if (*pcVar3 == '\0') {

      return;

    }

    if (*pcVar3 == '\b') {

      return;

    }

    iVar4 = (int)&DAT_0059cbb4 - (int)pcVar3;

    do {

      cVar1 = *pcVar3;

      pcVar3[iVar4] = cVar1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    DAT_0059cd48 = &DAT_0059cbb4;

    wredit_00519c70();

  }

  iVar4 = (int)*DAT_0059cd48;

  if (iVar4 != 0) {

    DAT_0059cd48 = DAT_0059cd48 + 1;

    if ((iVar4 < 0x31) || (0x39 < iVar4)) {

      if ((iVar4 < 0x41) || (0x5a < iVar4)) {

        if (iVar4 < 0x61) {

          return;

        }

        if (0x7a < iVar4) {

          return;

        }

        iVar4 = iVar4 + -0x57;

      }

      else {

        iVar4 = iVar4 + -0x37;

      }

    }

    else {

      iVar4 = iVar4 + -0x30;

    }

    if (0 < iVar4) {

      iVar4 = *(int *)(DAT_0059cbd8 + 0x38);

      uVar2 = ANM_BinderDestroy_3(&DAT_0059cd18);

      *(undefined4 *)(iVar4 + 0x174) = uVar2;

      wredit_00439490();

      return;

    }

  }

  return;

}

/* ===== wredit_minishop_icons @ 0x00440770 ===== */
void wredit_minishop_icons(undefined4 param_1,int param_2,int param_3)



{

  int *piVar1;

  uint uVar2;

  uint uVar3;

  byte bVar4;

  int iVar5;

  byte bVar6;

  undefined4 *puVar7;

  int local_88;

  int local_84;

  undefined1 local_80 [16];

  undefined4 local_70 [27];

  

  puVar7 = local_70;

  for (iVar5 = 0x19; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar7 = 0x20202020;

    puVar7 = puVar7 + 1;

  }

  iVar5 = 0;

  *(undefined1 *)((int)local_70 + param_3 * 2) = 0;

  if (0 < DAT_0059cd34) {

    piVar1 = DAT_0059cd30;

    do {

      if (*piVar1 == *(int *)(param_2 + 4)) break;

      iVar5 = iVar5 + 1;

      piVar1 = piVar1 + 9;

    } while (iVar5 < DAT_0059cd34);

  }

  if (iVar5 == DAT_0059cd34) {

    iVar5 = 0;

  }

  if (param_3 < 1) {

    if ((*(float *)(param_2 + 0xcc) == 0.0) && (*(float *)(param_2 + 0xd0) == 0.0)) {

      crt_file_free_init();

    }

    else {

      crt_file_free_init(param_1,s_Object___12s__8_2f__8_2f__7_2f___00558328,

                         DAT_0059cd30 + iVar5 * 9 + 1,(double)*(float *)(param_2 + 0xa0),

                         (double)*(float *)(param_2 + 0xa4),(double)*(float *)(param_2 + 0xa8),

                         (double)*(float *)(param_2 + 200),(double)*(float *)(param_2 + 0xcc),

                         (double)*(float *)(param_2 + 0xd0));

    }

  }

  else {

    crt_file_free_init(param_1,s__sLockStart___12s__d__d_005583b0,local_70,

                       DAT_0059cd30 + iVar5 * 9 + 1,*(undefined4 *)(param_2 + 0x214),

                       *(undefined4 *)(param_2 + 0x218));

    if ((char)((uint)*(undefined4 *)(param_2 + 0xdc) >> 8) < '\0') {

      crt_file_free_init();

    }

  }

  if (*(int *)(param_2 + 0xc4) != 0x3f800000) {

    crt_file_free_init();

  }

  if (*(int *)(param_2 + 0xe8) != 0) {

    crt_file_free_init(param_1,s__s_AIMode__d_00558304,local_70,*(int *)(param_2 + 0xe8));

  }

  if (*(int *)(param_2 + 0x174) != 0) {

    crt_file_free_init(param_1,s__s_TeamId__d_005582f4,local_70,*(int *)(param_2 + 0x174));

  }

  if ((*(float *)(param_2 + 0xf8) != 0.0) || (*(float *)(param_2 + 0xfc) != 0.0)) {

    crt_file_free_init();

  }

  uVar2 = *(uint *)(param_2 + 0xdc) & 0xf;

  if (uVar2 != 0) {

    crt_file_free_init(param_1,s__s_TriggerType__d_005582c0,local_70,uVar2);

  }

  if (*(int *)(param_2 + 0x1e0) == 0x60) {

    iVar5 = *(int *)(param_2 + 0x100);

    crt_file_free_init(param_1,s__s_SplineKeyTime__d_005582a8,local_70,*(undefined4 *)(iVar5 + 0x50)

                      );

    if ((*(float *)(iVar5 + 0x18) != 0.0) || (*(float *)(iVar5 + 0x1c) != 0.0)) {

      crt_file_free_init();

    }

    if ((*(int *)(iVar5 + 0x10) != 0x3f800000) || (*(int *)(iVar5 + 0x14) != 0x3f800000)) {

      crt_file_free_init();

    }

    if (*(int *)(iVar5 + 0x48) != 0) {

      crt_file_free_init();

    }

    if (*(int *)(iVar5 + 0x4c) != 0) {

      crt_file_free_init();

    }

  }

  if ((*(int *)(param_2 + 0x1e0) == 0x33) &&

     (iVar5 = *(int *)(*(int *)(param_2 + 0x100) + 0x60), iVar5 != 0)) {

    crt_file_free_init(param_1,s__s_SplineStartID__d_00558234,local_70,iVar5);

  }

  if ((*(int *)(param_2 + 0x1e0) == 0x61) &&

     (iVar5 = *(int *)(*(int *)(param_2 + 0x100) + 0xc), iVar5 != 0)) {

    crt_file_free_init(param_1,s__s_SplineStartID__d_00558234,local_70,iVar5);

  }

  if (*(int *)(param_2 + 0x1e0) == 0x66) {

    piVar1 = *(int **)(param_2 + 0x100);

    crt_file_free_init(param_1,s__s_MinishopRIcons__d_0055821c,local_70,*piVar1);

    local_88 = 0;

    if (0 < *piVar1) {

      do {

        crt_file_free_init();

        local_88 = local_88 + 1;

      } while (local_88 < *piVar1);

    }

    crt_file_free_init(param_1,&DAT_00558214);

    crt_file_free_init(param_1,s__s_MinishopMIcons__d_005581fc,local_70,piVar1[0x29]);

    local_88 = 0;

    if (0 < piVar1[0x29]) {

      do {

        crt_file_free_init();

        local_88 = local_88 + 1;

      } while (local_88 < piVar1[0x29]);

    }

    crt_file_free_init(param_1,&DAT_00558214);

  }

  if (*(int *)(param_2 + 0x1e0) == 0x5c) {

    obj_5c_slot_scan(param_2,local_80);

    crt_file_free_init();

  }

  if (*(int *)(param_2 + 0x1e0) == 0x34) {

    crt_file_free_init();

  }

  bVar6 = 0;

  local_84 = 0;

  do {

    if (local_84 < 0x400) {

      uVar3 = 1 << (bVar6 & 0x1f);

      uVar2 = *(uint *)(param_2 + 0x2e8);

LAB_00440cda:

      if ((uVar2 & uVar3) != 0) {

        crt_file_free_init(param_1,s__s_FlickUsed__s_005581a8,local_70,

                           local_84 + 0x210 + DAT_006330e4);

      }

    }

    else {

      if (local_84 < 0x800) {

        uVar2 = 1 << (bVar6 - 0x20 & 0x1f);

        uVar3 = *(uint *)(param_2 + 0x2ec);

        goto LAB_00440cda;

      }

      if (local_84 < 0xc00) {

        bVar4 = bVar6 - 0x40;

LAB_00440ccd:

        uVar2 = 1 << (bVar4 & 0x1f);

        uVar3 = *(uint *)(param_2 + 0x2f0);

        goto LAB_00440cda;

      }

      if (local_84 < 0x1000) {

        bVar4 = bVar6 + 0xa0;

        goto LAB_00440ccd;

      }

    }

    local_84 = local_84 + 0x20;

    bVar6 = bVar6 + 1;

    puVar7 = DAT_00632d68;

    if (0xfff < local_84) {

      for (; puVar7 != (undefined4 *)0x0; puVar7 = (undefined4 *)*puVar7) {

        iVar5 = puVar7[3];

        if ((((*(int *)(iVar5 + 0x210) == param_2) && ((*(uint *)(iVar5 + 0xd8) & 0x40000000) == 0))

            && ((*(uint *)(iVar5 + 0xdc) & 0x20000000) != 0)) && (*(int *)(iVar5 + 4) != 0xf0)) {

          wredit_minishop_icons();

        }

      }

      if (0 < param_3) {

        crt_file_free_init();

      }

      return;

    }

  } while( true );

}

/* ===== wredit_str_input @ 0x00441480 ===== */
int wredit_str_input(void)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  

  if ((DAT_0059cd48 == (char *)0x0) || (*DAT_0059cd48 == '\0')) {

    pcVar2 = (char *)FUN_00519CF0();

    if (pcVar2 == (char *)0x0) {

      return 0;

    }

    if (*pcVar2 == '\0') {

      return 0;

    }

    if (*pcVar2 == '\b') {

      return 0;

    }

    iVar3 = (int)&DAT_0059cbb4 - (int)pcVar2;

    do {

      cVar1 = *pcVar2;

      pcVar2[iVar3] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    DAT_0059cd48 = &DAT_0059cbb4;

    wredit_00519c70();

  }

  iVar3 = (int)*DAT_0059cd48;

  if (iVar3 != 0) {

    DAT_0059cd48 = DAT_0059cd48 + 1;

    if ((0x30 < iVar3) && (iVar3 < 0x3a)) {

      return iVar3 + -0x30;

    }

    if ((0x40 < iVar3) && (iVar3 < 0x5b)) {

      return iVar3 + -0x37;

    }

    if ((0x60 < iVar3) && (iVar3 < 0x7b)) {

      return iVar3 + -0x57;

    }

  }

  return 0;

}

/* ===== wredit_str_input_short @ 0x00441510 ===== */
int wredit_str_input_short(void)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  

  if ((DAT_0059cd48 == (char *)0x0) || (*DAT_0059cd48 == '\0')) {

    pcVar2 = (char *)FUN_00519CF0();

    if (pcVar2 == (char *)0x0) {

      return 0;

    }

    if (*pcVar2 == '\0') {

      return 0;

    }

    if (*pcVar2 == '\b') {

      return 0;

    }

    iVar3 = (int)&DAT_0059cbb4 - (int)pcVar2;

    do {

      cVar1 = *pcVar2;

      pcVar2[iVar3] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    DAT_0059cd48 = &DAT_0059cbb4;

    wredit_00519c70();

  }

  cVar1 = *DAT_0059cd48;

  if (cVar1 == 0) {

    return 0;

  }

  DAT_0059cd48 = DAT_0059cd48 + 1;

  return (int)cVar1;

}

/* ===== wredit_00441580 @ 0x00441580 ===== */
void wredit_00441580(undefined4 param_1,undefined4 param_2,int param_3)



{

  undefined *puVar1;

  undefined1 local_100 [256];

  

  puVar1 = &DAT_0055722c;

  if (param_3 == 0) {

    puVar1 = &DAT_00557228;

  }

  crt_sprintf(local_100,param_2,puVar1);

  main_dlog_004281f0(param_1,1,local_100);

  return;

}

/* ===== wredit_spawn_object @ 0x004417A0 ===== */
void wredit_spawn_object(void)



{

  uint uVar1;

  bool bVar2;

  

  DAT_0059cd9c = DAT_0059cd9c + 1;

  uVar1 = DAT_0059cd9c & 0x80000001;

  bVar2 = uVar1 == 0;

  if ((int)uVar1 < 0) {

    bVar2 = (uVar1 - 1 | 0xfffffffe) == 0xffffffff;

  }

  if (bVar2) {

    DAT_00632e7c = 0;

    object_destroy(DAT_00632a88);

    DAT_00632a88 = DAT_0059cbb0;

    DAT_0059cbb0 = 0;

    wredit_00439490();

    return;

  }

  object_destroy(DAT_00632a88);

  DAT_00632a88 = DAT_0059cbb0;

  DAT_00632a88 = object_allocate_type(2,0x80000000);

  object_setup_specialtype(DAT_00632a88);

  giftshopview_enable(0,0);

  return;

}

/* ===== make_explosion_large @ 0x004419D0 ===== */
/* PS2 candidate: make_explosion_large (conf 0.517) */



void make_explosion_large(undefined4 param_1)



{

  uint *puVar1;

  undefined4 *puVar2;

  int iVar3;

  

  iVar3 = object_allocate_type(*(undefined4 *)(DAT_00632ed8 + 0x420),0x80000000);

  puVar2 = *(undefined4 **)(iVar3 + 0x100);

  puVar2[2] = *(undefined4 *)(DAT_00632ed8 + 0x424);

  puVar2[3] = *(undefined4 *)(DAT_00632ed8 + 0x428);

  puVar2[4] = *(undefined4 *)(DAT_00632ed8 + 0x42c);

  puVar2[1] = *(undefined4 *)(DAT_00632ed8 + 0x430);

  *puVar2 = *(undefined4 *)(DAT_00632ed8 + 0x434);

  object_set_location_p3d(iVar3,param_1);

  if (0.0 < (float)puVar2[2]) {

    *(undefined4 *)(iVar3 + 0xc4) = puVar2[2];

  }

  *(undefined4 *)(iVar3 + 0xec) = puVar2[4];

  *(uint *)(iVar3 + 0x1c8) = *(uint *)(iVar3 + 0x1c8) | 0x800000;

  puVar1 = (uint *)(*(int *)(iVar3 + 8) + 4);

  *puVar1 = *puVar1 | 4;

  iVar3 = object_allocate_type(*(undefined4 *)(DAT_00632ed8 + 0x44c),0x80000000);

  puVar2 = *(undefined4 **)(iVar3 + 0x100);

  puVar2[2] = *(undefined4 *)(DAT_00632ed8 + 0x444);

  puVar2[3] = *(undefined4 *)(DAT_00632ed8 + 0x440);

  puVar2[4] = *(undefined4 *)(DAT_00632ed8 + 0x43c);

  puVar2[1] = *(undefined4 *)(DAT_00632ed8 + 0x438);

  *puVar2 = *(undefined4 *)(DAT_00632ed8 + 0x448);

  object_set_location_p3d(iVar3,param_1);

  if (0.0 < (float)puVar2[2]) {

    *(undefined4 *)(iVar3 + 0xc4) = puVar2[2];

  }

  *(undefined4 *)(iVar3 + 0xec) = puVar2[4];

  *(uint *)(iVar3 + 0x1c8) = *(uint *)(iVar3 + 0x1c8) | 0x800000;

  *(uint *)(*(int *)(iVar3 + 8) + 4) = *(uint *)(*(int *)(iVar3 + 8) + 4) | 4;

  iVar3 = object_allocate_type(0x274,0);

  object_change_ospec(iVar3,0x10);

  anim_select_check2(iVar3,1);

  object_set_location_p3d(iVar3,param_1);

  *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) & 0xfffffffe;

  main_smoke_004f8e10(iVar3,*(undefined4 *)(DAT_00632ed8 + 0x4a8),

                      *(undefined4 *)(DAT_00632ed8 + 0x4f8));

  main_smoke_004f90e0(param_1,*(undefined4 *)(DAT_00632ed8 + 0x494));

  ANM_BinderDestroy(param_1,*(undefined4 *)(DAT_00632ed8 + 0x498),

                    *(undefined4 *)(DAT_00632ed8 + 0x49c),0,*(undefined4 *)(DAT_00632ed8 + 0x490),

                    *(float *)(DAT_00632ed8 + 0x490) * 2.5,*(float *)(DAT_00632ed8 + 0x490) * 25.0,

                    0x41c80000,*(float *)(DAT_00632ed8 + 0x490) * 60.0,0x442f0000,0x44098000);

  return;

}

/* ===== make_dust_ball @ 0x00441D20 ===== */
/* PS2 candidate: make_dust_ball (conf 0.426) */



void make_dust_ball(undefined4 *param_1,float param_2)



{

  float fVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = object_allocate_type(0x2a0,0x80000000);

  fVar1 = *(float *)(DAT_00632ed8 + 0x50c) * param_2;

  *(float *)(iVar2 + 0xf4) = fVar1;

  *(float *)(iVar2 + 0xc4) = fVar1;

  *(undefined4 *)(iVar2 + 0xa0) = *param_1;

  *(undefined4 *)(iVar2 + 0xa4) = param_1[1];

  *(undefined4 *)(iVar2 + 0xa8) = param_1[2];

  object_copy_posdirinfo(iVar2);

  *(undefined4 *)(iVar2 + 0xec) = 0;

  fx_fade_compute(*(float *)(DAT_00632ed8 + 0x50c) * param_2,

                  *(float *)(DAT_00632ed8 + 0x510) * param_2,

                  *(float *)(DAT_00632ed8 + 0x514) * param_2,*(undefined4 *)(DAT_00632ed8 + 0x518),

                  *(undefined4 *)(DAT_00632ed8 + 0x51c),iVar2 + 0x1a4,iVar2 + 0x1a8);

  FUN_0049bc50(iVar2);

  param_2 = 0.0;

  do {

    iVar3 = object_allocate_type(0x29f,0x80000000);

    tracer_calc_falloff__FP6Traceri(iVar2,param_2,iVar3 + 0xa0);

    object_copy_posdirinfo(iVar3);

    *(undefined4 *)(iVar3 + 0xc4) = *(undefined4 *)(iVar2 + 0xc4);

    *(float *)(iVar3 + 200) = (float)(int)param_2 * 30.0;

    *(float *)(iVar3 + 0xcc) = (float)(int)param_2 * 50.0;

    param_2 = (float)((int)param_2 + 1);

    *(uint *)(*(int *)(iVar3 + 8) + 4) = *(uint *)(*(int *)(iVar3 + 8) + 4) | 4;

    *(int *)(iVar3 + 0x274) = iVar2;

  } while ((int)param_2 < 6);

  return;

}

/* ===== fx_fade_compute @ 0x00442120 ===== */
void fx_fade_compute(float param_1,float param_2,float param_3,float param_4,float param_5,

                    float *param_6,float *param_7)



{

  int iVar1;

  float10 fVar2;

  float10 fVar3;

  float10 fVar4;

  float10 fVar5;

  float10 fVar6;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  

  local_8 = 0.01;

  fVar2 = (float10)param_2 - (float10)param_1;

  local_c = 10.0;

  fVar4 = (float10)1.4426950408889634 * (float10)param_4 * (float10)-0.01;

  fVar3 = ROUND(fVar4);

  fVar4 = (float10)f2xm1(fVar4 - fVar3);

  fVar3 = (float10)fscale((float10)1 + fVar4,fVar3);

  fVar5 = (float10)1.4426950408889634 * (float10)param_5 * (float10)-0.01;

  fVar4 = ROUND(fVar5);

  fVar5 = (float10)f2xm1(fVar5 - fVar4);

  fVar4 = (float10)fscale((float10)1 + fVar5,fVar4);

  param_2 = (float)((float10)param_3 -

                   (((float10)1.0 - fVar4) * (((float10)0.01 * fVar2) / ((float10)1.0 - fVar3)) *

                    (float10)100.0 + (float10)param_1));

  fVar4 = (float10)1.4426950408889634 * (float10)param_4 * (float10)-10.0;

  fVar3 = ROUND(fVar4);

  fVar4 = (float10)f2xm1(fVar4 - fVar3);

  fVar3 = (float10)fscale((float10)1 + fVar4,fVar3);

  fVar5 = (float10)1.4426950408889634 * (float10)param_5 * (float10)-10.0;

  fVar4 = ROUND(fVar5);

  iVar1 = 0;

  fVar5 = (float10)f2xm1(fVar5 - fVar4);

  fVar4 = (float10)fscale((float10)1 + fVar5,fVar4);

  local_10 = (float)((float10)param_3 -

                    (((float10)1.0 - fVar4) * (((float10)10.0 * fVar2) / ((float10)1.0 - fVar3)) *

                     (float10)0.1 + (float10)param_1));

  fVar3 = (float10)param_1;

  do {

    if (0.0 <= local_10 * param_2) break;

    fVar3 = ((float10)local_c + (float10)local_8) * (float10)0.5;

    fVar5 = (float10)1.4426950408889634 * -(fVar3 * (float10)param_4);

    fVar4 = ROUND(fVar5);

    fVar5 = (float10)f2xm1(fVar5 - fVar4);

    fVar4 = (float10)fscale((float10)1 + fVar5,fVar4);

    fVar6 = (float10)1.4426950408889634 * -(fVar3 * (float10)param_5);

    fVar5 = ROUND(fVar6);

    fVar6 = (float10)f2xm1(fVar6 - fVar5);

    fVar5 = (float10)fscale((float10)1 + fVar6,fVar5);

    fVar4 = (float10)param_3 -

            ((((float10)1.0 - fVar5) / fVar3) * ((fVar2 * fVar3) / ((float10)1.0 - fVar4)) +

            (float10)param_1);

    if ((float10)0.0 <= (float10)param_2 * fVar4) {

      param_2 = (float)fVar4;

      local_8 = (float)fVar3;

    }

    else {

      local_10 = (float)fVar4;

      local_c = (float)fVar3;

    }

    iVar1 = iVar1 + 1;

  } while (iVar1 < 10);

  *param_6 = (float)fVar3;

  fVar5 = (float10)1.4426950408889634 * -(fVar3 * (float10)param_4);

  fVar4 = ROUND(fVar5);

  fVar5 = (float10)f2xm1(fVar5 - fVar4);

  fVar4 = (float10)fscale((float10)1 + fVar5,fVar4);

  *param_7 = (float)((fVar2 * fVar3) / ((float10)1.0 - fVar4));

  return;

}

/* ===== object_spawn_menu_wredit @ 0x00442330 ===== */
void object_spawn_menu_wredit(undefined4 param_1,int param_2)



{

  float fVar1;

  undefined4 uVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  float10 fVar7;

  float10 fVar8;

  

  iVar4 = param_2;

  iVar5 = fx_create(param_2);

  if (((iVar5 != 0) && (iVar5 = fx_create(param_2), iVar5 != 0)) &&

     (param_2 = *(int *)(*(int *)(param_2 + 0x170) + 4) + -1, 0 < param_2)) {

    do {

      fVar7 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0x23c),

                                     *(undefined4 *)(DAT_00632ed8 + 0x23c));

      fVar8 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0x23c),

                                     *(undefined4 *)(DAT_00632ed8 + 0x23c));

      fVar3 = (float)fVar7 + *(float *)(iVar4 + 0xa0);

      uVar2 = *(undefined4 *)(iVar4 + 0xa8);

      iVar5 = *(int *)(iVar4 + 0x170);

      fVar1 = (float)(fVar8 + (float10)*(float *)(iVar4 + 0xa4));

      iVar6 = iVar4;

      if (*(int *)(iVar4 + 0x188) != 0) {

        iVar6 = object_allocate_type(*(undefined4 *)(iVar4 + 4),0x11);

        *(undefined4 *)(iVar6 + 0x170) = *(undefined4 *)(iVar4 + 0x170);

      }

      **(undefined4 **)(iVar6 + 0x100) = 0;

      *(float *)(iVar6 + 0xa0) = fVar3;

      *(float *)(iVar6 + 0xa4) = fVar1;

      *(undefined4 *)(iVar6 + 0xa8) = uVar2;

      *(float *)(iVar6 + 0xac) = fVar3;

      *(float *)(iVar6 + 0xb0) = fVar1;

      *(undefined4 *)(iVar6 + 0xb4) = uVar2;

      *(float *)(iVar6 + 0xb8) = fVar3;

      *(float *)(iVar6 + 0xbc) = fVar1;

      *(undefined4 *)(iVar6 + 0xc0) = uVar2;

      fVar7 = (float10)rndfloatrange(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 0x10));

      param_2 = param_2 + -1;

      *(float *)(iVar6 + 0xc4) = (float)(fVar7 * (float10)*(float *)(iVar6 + 0xc4));

    } while (param_2 != 0);

  }

  return;

}

/* ===== scenerio_handle_music__FPv @ 0x004429C0 ===== */
/* PS2 candidate: scenerio_handle_music__FPv (conf 0.437) */



undefined4 scenerio_handle_music__FPv(float param_1)



{

  int iVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  float10 fVar7;

  

  iVar3 = (int)param_1;

  iVar5 = *(int *)((int)param_1 + 0x100);

  fVar7 = (float10)FUN_00518b70(param_1,0);

  fVar7 = (float10)*(float *)(iVar5 + 4) - fVar7;

  *(float *)(iVar5 + 4) = (float)fVar7;

  if (fVar7 <= (float10)0.0) {

    *(undefined4 *)(iVar5 + 4) = 0x3f000000;

    param_1 = *(float *)(DAT_00632ed8 + 0x254) * *(float *)(DAT_00632ed8 + 0x254);

    iVar5 = 0;

    piVar6 = DAT_00632d6c;

    if (DAT_00632d6c != (int *)0x0) {

      do {

        iVar1 = piVar6[3];

        if (((((*(uint *)(iVar1 + 0xd8) & 0x4000c000) == 0) &&

             (iVar4 = ObjIsPlayer(iVar1), iVar4 != 0)) && (*(int *)(iVar1 + 0x210) == 0)) &&

           (fVar7 = (float10)FUN_0050a610(iVar1 + 0xa0,iVar3 + 0xa0), fVar7 <= (float10)param_1)) {

          param_1 = (float)fVar7;

          iVar5 = iVar1;

        }

        piVar6 = (int *)*piVar6;

      } while (piVar6 != (int *)0x0);

      if (iVar5 != 0) {

        iVar5 = ObjIsKabuto(iVar5);

        if (iVar5 != 0) {

          return 1;

        }

        fVar2 = *(float *)(DAT_00632ed8 + 0x250) * *(float *)(DAT_00632ed8 + 0x250);

        if (param_1 < fVar2 != (param_1 == fVar2)) {

          return 1;

        }

      }

    }

  }

  return 0;

}

/* ===== obj_scale_pulse @ 0x00442AD0 ===== */
void obj_scale_pulse(float param_1,undefined4 param_2)



{

  uint uVar1;

  float fVar2;

  undefined1 uVar3;

  float10 fVar4;

  float10 extraout_ST0;

  

  fVar2 = param_1;

  if ((*(byte *)((int)param_1 + 0xe0) & 2) != 0) {

    if ((*(uint *)((int)param_1 + 0xd8) & 0x40000) != 0) {

      return;

    }

    param_1 = (float)(int)*(char *)((int)param_1 + 0x208) * 0.03125;

  }

  *(undefined1 *)((int)fVar2 + 0x208) = 0;

  fVar4 = (float10)dirfcalcp3d__FP3P3DT0((int)fVar2 + 0xa0,param_2);

  fVar4 = (float10)FUN_0050a7c0((float)fVar4,*(undefined4 *)((int)fVar2 + 200));

  if ((float10)5.0 <= ABS(fVar4)) {

    uVar1 = *(uint *)((int)fVar2 + 0xe0);

    if ((uVar1 & 2) == 0) {

      uVar3 = __ftol();

      *(undefined1 *)((int)fVar2 + 0x208) = uVar3;

      return;

    }

    uVar3 = __ftol();

    *(undefined1 *)((int)fVar2 + 0x208) = uVar3;

    if (ABS(extraout_ST0 - (float10)param_1) < (float10)0.1) {

      *(uint *)((int)fVar2 + 0xe0) = uVar1 & 0xfffffffd;

      return;

    }

  }

  return;

}

/* ===== sound_3dpos_play @ 0x00442EC0 ===== */
/* PS2 candidate: verm_collect__FP6OBJECT (conf 0.354) */



void sound_3dpos_play(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  float fVar3;

  int iVar4;

  float10 fVar5;

  

  for (puVar2 = DAT_00632d6c; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    if (((*(uint *)(iVar1 + 0xd8) & 0x4000c000) == 0) && (iVar4 = ObjIsPlayer(iVar1), iVar4 != 0)) {

      fVar5 = (float10)FUN_0050a610(iVar1 + 0xa0,param_1 + 0xa0);

      if (fVar5 < (float10)25.0) {

        object_destroy(param_1);

        fVar3 = *(float *)(iVar1 + 0x278) - 1.0;

        *(float *)(iVar1 + 0x278) = fVar3;

        if (fVar3 < 0.0) {

          *(undefined4 *)(iVar1 + 0x278) = 0;

        }

        sound_play_3dpos(0x63b,param_1 + 0xa0);

      }

    }

  }

  return;

}

/* ===== FUN_00443110 @ 0x00443110 ===== */
void FUN_00443110(void)



{

  undefined4 *puVar1;

  float fVar2;

  undefined4 *puVar3;

  float *pfVar4;

  undefined4 *puVar5;

  int iVar6;

  float10 fVar7;

  

  for (puVar1 = DAT_0059cda4; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    fVar7 = (float10)FUN_00518b70(0,puVar1 + 2);

    iVar6 = 0;

    puVar1[1] = (float)puVar1[1] - (float)fVar7;

    if (0 < (int)puVar1[6]) {

      pfVar4 = (float *)(puVar1 + 10);

      do {

        fVar2 = (float)fVar7 * pfVar4[1] + *pfVar4;

        *pfVar4 = fVar2;

        if (1.0 < fVar2) {

          *pfVar4 = fVar2 - 1.0;

        }

        iVar6 = iVar6 + 1;

        pfVar4 = pfVar4 + 5;

      } while (iVar6 < (int)puVar1[6]);

    }

  }

  puVar3 = &DAT_0059cda4;

  puVar1 = DAT_0059cda4;

  while (puVar1 != (undefined4 *)0x0) {

    puVar5 = (undefined4 *)*puVar3;

    if ((float)puVar5[1] < 0.0 != ((float)puVar5[1] == 0.0)) {

      *puVar3 = *puVar5;

      puVar5 = puVar3;

    }

    puVar3 = puVar5;

    puVar1 = (undefined4 *)*puVar5;

  }

  return;

}

/* ===== status_update_3obj @ 0x004431C0 ===== */
void status_update_3obj(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  float *pfVar5;

  float afStack_e0 [10];

  undefined4 uStack_b8;

  undefined4 uStack_b4;

  float fStack_b0;

  float afStack_a8 [2];

  float fStack_a0;

  undefined4 uStack_80;

  undefined4 uStack_7c;

  float fStack_78;

  float afStack_70 [2];

  undefined4 uStack_68;

  int iStack_48;

  undefined4 uStack_44;

  float fStack_40;

  float afStack_38 [2];

  undefined4 uStack_30;

  int iStack_10;

  undefined4 uStack_c;

  float fStack_8;

  

  for (puVar2 = DAT_0059cda4; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    (**(code **)(DAT_0065642c + 8))(DAT_0065642c,0x40634,DAT_0059cda8,0x88000000);

    pfVar5 = afStack_e0;

    for (iVar4 = 0x38; iVar4 != 0; iVar4 = iVar4 + -1) {

      *pfVar5 = 0.0;

      pfVar5 = pfVar5 + 1;

    }

    iVar4 = 0;

    if (0 < (int)puVar2[6]) {

      iVar3 = __ftol();

      puVar1 = puVar2 + 2;

      pfVar5 = (float *)(puVar2 + 8);

      do {

        afStack_e0[2] = pfVar5[1];

        afStack_e0[0] = *pfVar5 + pfVar5[-1];

        afStack_a8[0] = pfVar5[-1] - *pfVar5;

        fStack_b0 = pfVar5[2];

        uStack_80 = 0xffffff;

        uStack_b8 = 0xffffff;

        fStack_40 = pfVar5[2] + 1.0;

        uStack_68 = 0;

        uStack_30 = 0;

        uStack_b4 = 0x3f800000;

        uStack_7c = 0;

        uStack_44 = 0;

        uStack_c = 0x3f800000;

        fStack_a0 = afStack_e0[2];

        fStack_78 = fStack_b0;

        afStack_70[0] = afStack_a8[0];

        iStack_48 = iVar3 << 0x18;

        afStack_38[0] = afStack_e0[0];

        iStack_10 = iVar3 << 0x18;

        fStack_8 = fStack_40;

        hud_screen_project(puVar1,afStack_e0);

        hud_screen_project(puVar1,afStack_a8);

        hud_screen_project(puVar1,afStack_70);

        hud_screen_project(puVar1,afStack_38);

        status_bar_update3(afStack_e0,afStack_a8,afStack_70);

        status_bar_update3(afStack_e0,afStack_70,afStack_38);

        iVar4 = iVar4 + 1;

        pfVar5 = pfVar5 + 5;

      } while (iVar4 < (int)puVar2[6]);

    }

  }

  return;

}

/* ===== FLK_ReplayFileNameClear @ 0x004433A0 ===== */
void FLK_ReplayFileNameClear(void)



{

  DAT_0059cdb8 = 0;

  return;

}

/* ===== FUN_004433b0 @ 0x004433B0 ===== */
void FUN_004433b0(float *param_1)



{

  int iVar1;

  undefined1 auStack_e0 [20];

  float local_cc;

  uint local_b8;

  float local_94;

  uint local_80;

  float local_5c;

  uint local_48;

  float local_24;

  uint local_10;

  

  if (*param_1 != 1.0) {

    local_24 = DAT_0057c0c0;

    local_5c = DAT_0057c0c0;

    local_94 = DAT_0057c0c0;

    local_cc = DAT_0057c0c0;

    local_b8 = (uint)CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 3),

                                       *(undefined1 *)((int)param_1 + 0xd)),

                              *(undefined1 *)((int)param_1 + 0xe));

    local_80 = local_b8;

    local_48 = local_b8;

    local_10 = local_b8;

    iVar1 = __ftol();

    (**(code **)(DAT_0065642c + 8))(DAT_0065642c,0x42380,0,iVar1 << 0x18);

    FUN_00446b00(auStack_e0,DAT_0057c0c0 * -1.0,DAT_0057c0c0,DAT_0057c0c0 + DAT_0057c0c0,

                 DAT_0057c0c0 + DAT_0057c0c0);

  }

  return;

}

/* ===== flick_file_load @ 0x00443480 ===== */
undefined4 *

flick_file_load(int param_1,undefined4 param_2,char *param_3,undefined4 param_4,undefined4 param_5,

               undefined4 param_6,undefined4 param_7)



{

  undefined4 uVar1;

  undefined4 *puVar2;

  undefined4 uVar3;

  size_t *psVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  size_t *psVar8;

  size_t *psVar9;

  size_t local_98 [6];

  undefined1 local_80 [128];

  

  iVar7 = 0;

  uVar1 = FUN_0053feb0(0,0);

  puVar2 = (undefined4 *)FUN_0053ffa0(uVar1,0x140,1);

  *puVar2 = uVar1;

  if (param_3 != (char *)0x0) {

    _strncpy((char *)(puVar2 + 1),param_3,0x80);

    *(undefined1 *)(puVar2 + 0x21) = 0;

  }

  puVar2[0x21] = param_1;

  if (param_1 == 0) {

    puVar2[0x25] = param_5;

    puVar2[0x24] = param_4;

  }

  else {

    puVar2[0x22] = param_1 + 0x18;

    puVar2[0x25] = *(undefined4 *)(param_1 + 0xc);

    puVar2[0x24] = *(undefined4 *)(param_1 + 8);

    param_6 = *(undefined4 *)(param_1 + 0x10);

  }

  puVar2[0x26] = param_6;

  puVar2[0x23] = param_2;

  uVar3 = FUN_0053ffa0(uVar1,puVar2[0x24] * 0xc,1);

  puVar2[0x27] = uVar3;

  uVar3 = FUN_0053ffa0(uVar1,puVar2[0x25] * 0x874,1);

  puVar2[0x28] = uVar3;

  uVar1 = FUN_0053ffa0(uVar1,puVar2[0x26] * 0x310,1);

  puVar2[0x29] = uVar1;

  puVar2[0x2a] = 1;

  puVar2[0x2f] = 1;

  puVar2[0x30] = 1;

  puVar2[0x34] = 0x3f800000;

  puVar2[0x33] = 0x3f800000;

  puVar2[0x35] = 0;

  puVar2[0x37] = 0x3f800000;

  puVar2[0x36] = 0x3f800000;

  puVar2[0x38] = 0;

  puVar2[0x3b] = 0x3f800000;

  puVar2[0x3a] = 0x3f800000;

  puVar2[0x3c] = 0;

  puVar2[0x3e] = param_7;

  if (*(int *)(param_1 + 0x14) != 0) {

    param_1 = param_1 + *(int *)(param_1 + 0x14);

    local_80[0] = 0;

    iVar6 = param_1;

    if (DAT_006330e4 == 0) {

LAB_00443656:

      crt_sprintf(local_80,s_flk__s_bin_005585d8,iVar6);

    }

    else {

      iVar6 = 0;

      do {

        iVar5 = match(param_1,iVar6 + 0x210 + DAT_006330e4);

        if (iVar5 != 0) {

          iVar6 = iVar7 * 0x20 + 0x210 + DAT_006330e4;

          goto LAB_00443656;

        }

        iVar6 = iVar6 + 0x20;

        iVar7 = iVar7 + 1;

      } while (iVar6 < 0x1000);

    }

    iVar7 = stream_player_start(local_80);

    if (iVar7 != 0) {

      BinFileRead(iVar7,local_98,0x18);

      psVar4 = _malloc(local_98[1]);

      psVar8 = local_98;

      psVar9 = psVar4;

      for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {

        *psVar9 = *psVar8;

        psVar8 = psVar8 + 1;

        psVar9 = psVar9 + 1;

      }

      BinFileRead(iVar7,psVar4 + 6,local_98[1] - 0x18);

      ANM_BinderDestroy_2(iVar7);

      if (DAT_006330e4 != 0) {

        iVar7 = 0;

        iVar6 = 0;

        do {

          iVar5 = match(param_1,iVar6 + 0x210 + DAT_006330e4);

          if (iVar5 != 0) goto LAB_004436f3;

          iVar6 = iVar6 + 0x20;

          iVar7 = iVar7 + 1;

        } while (iVar6 < 0x1000);

      }

      iVar7 = -1;

LAB_004436f3:

      uVar1 = flick_file_load(psVar4,iVar7,param_1,0,0,0,param_7);

      puVar2[0x32] = uVar1;

    }

  }

  puVar2[0x4e] = 0x447a0000;

  return puVar2;

}

/* ===== wredit_matrix_recurse @ 0x00443910 ===== */
void wredit_matrix_recurse(undefined4 *param_1,int *param_2)



{

  int *piVar1;

  undefined4 uVar2;

  int iVar3;

  undefined4 *puVar4;

  float fStack_8c;

  undefined4 local_88 [17];

  undefined1 auStack_44 [68];

  

  if (param_2[0x1dd] == 0) {

    FUN_0053d9e0(local_88);

  }

  else {

    wredit_matrix_recurse(local_88,param_2[0x1dd]);

    if (param_2[0x1de] != 0) {

      uVar2 = AddHud__4cHudP8cHudIcon_4

                        (*(undefined4 *)(param_2[0x1de] + 0xc),

                         *(undefined4 *)(param_2[0x1dd] + 0x20));

      piVar1 = (int *)param_2[0x1dd];

      if (*piVar1 != 0) {

        piVar1[6] = *(int *)(*piVar1 + 4);

      }

      uVar2 = ANM_NodeGetMat(param_2[0x1de],uVar2,piVar1[6]);

      (*(code *)PTR_crt_matrix_mul_00580c18)(local_88,local_88,uVar2);

    }

  }

  if (param_2[0x1f6] != 0) {

    (*(code *)PTR_crt_matrix_mul_00580c18)(local_88,local_88,param_2 + 0x1f7);

  }

  if (*param_2 == 0) {

    fStack_8c = (float)param_2[0x34];

    if (param_2[0x1dd] != 0) {

      fStack_8c = fStack_8c / *(float *)(param_2[0x1dd] + 0xd0);

    }

    FUN_0053dc50(auStack_44,fStack_8c);

    (*(code *)PTR_crt_matrix_mul_00580c18)(local_88,local_88,auStack_44);

  }

  if (param_2[0x1df] != 0) {

    uVar2 = AddHud__4cHudP8cHudIcon_4(*(undefined4 *)(param_2[0x1df] + 0xc),param_2[8]);

    if (*param_2 != 0) {

      param_2[6] = *(int *)(*param_2 + 4);

    }

    uVar2 = ANM_NodeGetMat(param_2[0x1df],uVar2,param_2[6]);

    (*(code *)PTR_crt_matrix_copy_init_00580c1c)(auStack_44,uVar2);

    (*(code *)PTR_crt_matrix_mul_00580c18)(local_88,local_88,auStack_44);

  }

  puVar4 = local_88;

  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {

    *param_1 = *puVar4;

    puVar4 = puVar4 + 1;

    param_1 = param_1 + 1;

  }

  return;

}

/* ===== FLK_ActorAdd__FP9FLK_FlickiPcii @ 0x00443A90 ===== */
/* PS2 candidate: FLK_ActorAdd__FP9FLK_FlickiPcii (conf 0.419) */



undefined4

FLK_ActorAdd__FP9FLK_FlickiPcii(int *param_1,int param_2,int param_3,int param_4,int param_5)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int *piVar7;

  int *piVar8;

  undefined4 *puVar9;

  

  if (param_2 < 0) {

    piVar7 = (int *)0x0;

  }

  else {

    piVar7 = (int *)(param_1[0x27] + param_2 * 0xc);

    if (piVar7 != (int *)0x0) {

      param_2 = *piVar7;

      goto LAB_00443ac3;

    }

  }

  param_2 = 0;

LAB_00443ac3:

  if ((-1 < param_4) && (piVar5 = (int *)(param_4 * 0x874 + param_1[0x28]), piVar5 != (int *)0x0)) {

    if (piVar5[0x21c] == 0) {

      *piVar5 = 0;

      piVar5[1] = param_3;

      piVar5[2] = 1;

      if (param_5 < 0) {

        objobj_type_lookup(0,piVar5 + 3);

        piVar5[0x34] = 0x3f800000;

      }

      else {

        objobj_type_lookup(param_5,piVar5 + 3);

      }

      if (param_2 != 0) {

        *piVar5 = (int)piVar7;

        if ((int *)piVar5[5] != (int *)0x0) {

          piVar7 = (int *)piVar5[5];

          piVar8 = piVar5 + 0xc4;

          for (iVar4 = 0x119; iVar4 != 0; iVar4 = iVar4 + -1) {

            *piVar8 = *piVar7;

            piVar7 = piVar7 + 1;

            piVar8 = piVar8 + 1;

          }

        }

        piVar5[5] = (int)(piVar5 + 0xc4);

        uVar3 = *param_1;

        iVar4 = main_animate_004050d0(param_2);

        puVar9 = (undefined4 *)(iVar4 + 0x2c);

        param_1 = piVar5 + 0x1c4;

        iVar6 = 0;

        do {

          if (*param_1 == 0) break;

          iVar1 = *(int *)(*param_1 + 0x6c);

          if (iVar1 != 0) {

            uVar2 = editor_anim_skin(param_2,param_3,iVar1,0);

            *puVar9 = uVar2;

          }

          iVar6 = iVar6 + 1;

          param_1 = param_1 + 1;

          puVar9 = puVar9 + 1;

        } while (iVar6 < 10);

        piVar5[0xc6] = iVar4;

        uVar3 = FUN_0053ffa0(uVar3,piVar5[0x1d8] << 2,1);

        *(undefined4 *)(piVar5[0xc6] + 0x54) = uVar3;

        ObjectSetAnim(piVar5 + 3,0,0x20,1,0,0);

      }

      FUN_0053d9e0(piVar5 + 0xa8);

      piVar5[0x20f] = 0;

      piVar5[0x210] = 0;

      piVar5[0x211] = 0;

      piVar5[0x219] = 0;

      piVar5[0x218] = 0;

      piVar5[0x21a] = 0;

      piVar5[0x21c] = 1;

      return 1;

    }

    FUN_00540310(s_Error__Duplicate_actor__already_i_00558620,param_1 + 1);

  }

  return 0;

}

/* ===== flick_slot_lookup_handle @ 0x00443C50 ===== */
undefined4 flick_slot_lookup_handle(int param_1,int param_2,int param_3,int param_4,int param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int local_8;

  int local_4;

  

  iVar3 = 0;

  iVar2 = 0;

  local_8 = 0;

  local_4 = 0;

  if (-1 < param_4) {

    iVar2 = param_4 * 0x874 + *(int *)(param_1 + 0xa0);

    if ((((param_5 != 0) && (*(int *)(iVar2 + 0x14) != 0)) && (*(int *)(iVar2 + 0x1c) != 0xfe)) &&

       (iVar1 = *(int *)(*(int *)(*(int *)(iVar2 + 0x14) + 8 + *(int *)(iVar2 + 0x1c) * 4) + 0x28),

       iVar1 != 0)) {

      local_4 = FUN_0053be00(iVar1,*(undefined4 *)(iVar2 + 4),param_5);

      if (local_4 == 0) {

        FUN_00540310(s_Flick_error___Can_t_find_handle_r_0055868c,param_5);

      }

    }

  }

  if (-1 < param_2) {

    iVar3 = param_2 * 0x874 + *(int *)(param_1 + 0xa0);

    if (((param_3 != 0) && (*(int *)(iVar3 + 0x14) != 0)) &&

       ((*(int *)(iVar3 + 0x1c) != 0xfe &&

        (iVar1 = *(int *)(*(int *)(*(int *)(iVar3 + 0x14) + 8 + *(int *)(iVar3 + 0x1c) * 4) + 0x28),

        iVar1 != 0)))) {

      local_8 = FUN_0053be00(iVar1,*(undefined4 *)(iVar3 + 4),param_3);

      if (local_8 == 0) {

        FUN_00540310(s_Flick_error___Can_t_find_attach_r_00558658,param_3);

      }

    }

  }

  if (iVar2 != 0) {

    *(int *)(iVar2 + 0x774) = iVar3;

    *(int *)(iVar2 + 0x778) = local_8;

    *(int *)(iVar2 + 0x77c) = local_4;

  }

  return 1;

}

/* ===== hud_icon_for_object @ 0x00443D60 ===== */
undefined4

hud_icon_for_object(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)



{

  int iVar1;

  int *piVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  iVar6 = 0;

  iVar4 = 0;

  if (-1 < param_2) {

    iVar5 = param_2 * 0x310 + *(int *)(param_1 + 0xa4);

    if (iVar5 != 0) {

      if (-1 < param_5) {

        iVar6 = param_5 * 0x874 + *(int *)(param_1 + 0xa0);

        if ((((param_6 != 0) && (*(int *)(iVar6 + 0x14) != 0)) && (*(int *)(iVar6 + 0x1c) != 0xfe))

           && (iVar1 = *(int *)(*(int *)(*(int *)(iVar6 + 0x14) + 8 + *(int *)(iVar6 + 0x1c) * 4) +

                               0x28), iVar1 != 0)) {

          iVar4 = FUN_0053be00(iVar1,*(undefined4 *)(iVar6 + 4),param_6);

          if (iVar4 == 0) {

            FUN_00540310(s_Flick_error___Can_t_find_fx_acto_005586c0,param_6);

          }

        }

      }

      *(int *)(iVar5 + 0x308) = iVar4;

      *(int *)(iVar5 + 0x304) = iVar6;

      *(int *)(iVar5 + 0x30c) = param_4;

      objobj_type_lookup(0,iVar5);

      *(undefined4 *)(iVar5 + 0xc4) = 0x3f800000;

      if (*(int *)(iVar5 + 0x304) == 0) {

        FUN_0053d9e0(iVar5 + 0x294);

      }

      else {

        iVar6 = iVar5 + 0x294;

        wredit_matrix_recurse(iVar6,*(int *)(iVar5 + 0x304));

        if (*(int *)(iVar5 + 0x308) != 0) {

          uVar3 = AddHud__4cHudP8cHudIcon_4

                            (*(undefined4 *)(*(int *)(iVar5 + 0x308) + 0xc),

                             *(undefined4 *)(*(int *)(iVar5 + 0x304) + 0x20));

          piVar2 = *(int **)(iVar5 + 0x304);

          if (*piVar2 != 0) {

            piVar2[6] = *(int *)(*piVar2 + 4);

          }

          uVar3 = ANM_NodeGetMat(*(undefined4 *)(iVar5 + 0x308),uVar3,piVar2[6]);

          (*(code *)PTR_crt_matrix_mul_00580c18)(iVar6,iVar6,uVar3);

        }

      }

      object_set_location(iVar5,*(undefined4 *)(iVar5 + 0x2a4),*(undefined4 *)(iVar5 + 0x2b4),

                          *(undefined4 *)(iVar5 + 0x2c4));

      if (param_4 != 0) {

        fx_get_free_effect__Fv();

        return 1;

      }

      fx_get_free_effect__Fv();

    }

  }

  return 1;

}

/* ===== FUN_00443f30 @ 0x00443F30 ===== */
undefined4 FUN_00443f30(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = 0;

  if (-1 < param_2) {

    iVar2 = param_2 * 0x874 + *(int *)(param_1 + 0xa0);

    if ((((param_3 != 0) && (*(int *)(iVar2 + 0x14) != 0)) && (*(int *)(iVar2 + 0x1c) != 0xfe)) &&

       (iVar1 = *(int *)(*(int *)(*(int *)(iVar2 + 0x14) + 8 + *(int *)(iVar2 + 0x1c) * 4) + 0x28),

       iVar1 != 0)) {

      iVar3 = FUN_0053be00(iVar1,*(undefined4 *)(iVar2 + 4),param_3);

      if (iVar3 == 0) {

        FUN_00540310(s_Flick_error___Can_t_find_origin_r_005586f8,param_3);

      }

    }

    *(int *)(iVar2 + 0x780) = iVar3;

  }

  return 1;

}

/* ===== FUN_00443fb0 @ 0x00443FB0 ===== */
/* PS2 candidate: FLK_ActorOffsetEval__FP9FLK_Actor (conf 0.354) */



void FUN_00443fb0(float param_1)



{

  float fVar1;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  fVar1 = param_1;

  *(undefined4 *)((int)param_1 + 0x7d8) = 1;

  sine_cos_lookup(-*(float *)((int)param_1 + 0x830),&param_1,&local_14);

  sine_cos_lookup(*(undefined4 *)((int)fVar1 + 0x82c),&local_4,&local_8);

  sine_cos_lookup(*(undefined4 *)((int)fVar1 + 0x834),&local_10,&local_c);

  *(float *)((int)fVar1 + 0x7e0) = local_c * local_8;

  *(float *)((int)fVar1 + 0x7e4) = -(param_1 * local_c * local_4) - local_10 * local_14;

  *(float *)((int)fVar1 + 0x7e8) = local_10 * param_1 - local_c * local_4 * local_14;

  *(undefined4 *)((int)fVar1 + 0x7ec) = *(undefined4 *)((int)fVar1 + 0x820);

  *(float *)((int)fVar1 + 0x7f0) = local_10 * local_8;

  *(float *)((int)fVar1 + 0x7f4) = local_c * local_14 - local_10 * local_4 * param_1;

  *(float *)((int)fVar1 + 0x7f8) = -(local_10 * local_4 * local_14) - local_c * param_1;

  *(undefined4 *)((int)fVar1 + 0x7fc) = *(undefined4 *)((int)fVar1 + 0x824);

  *(float *)((int)fVar1 + 0x800) = local_4;

  *(float *)((int)fVar1 + 0x804) = local_8 * param_1;

  *(float *)((int)fVar1 + 0x808) = local_8 * local_14;

  *(undefined4 *)((int)fVar1 + 0x80c) = *(undefined4 *)((int)fVar1 + 0x828);

  *(undefined4 *)((int)fVar1 + 0x7dc) = 0x11;

  return;

}

/* ===== FLK_FlickTextProcess__FP9FLK_Flick @ 0x004440F0 ===== */
/* PS2 candidate: FLK_FlickTextProcess__FP9FLK_Flick (conf 0.399) */



void FLK_FlickTextProcess__FP9FLK_Flick(int param_1)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  undefined4 *puVar6;

  

  if (param_1 != 0) {

    puVar6 = *(undefined4 **)(param_1 + 0xfc);

    iVar1 = *(int *)(param_1 + 0x84);

    if (puVar6 != (undefined4 *)0x0) {

LAB_00444114:

      switch(*puVar6) {

      case 0xe:

        *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x120);

        puVar6 = puVar6 + puVar6[1];

        goto LAB_00444114;

      case 0xf:

        FNT_RenderInfoProcess__FP14FNT_RenderInfof

                  ((undefined4 *)(param_1 + 0x104),*(float *)(param_1 + 0xac));

        return;

      case 0x10:

        if (puVar6[2] == 0) {

          iVar3 = 0;

        }

        else {

          iVar3 = puVar6[2] + iVar1;

        }

        uVar2 = FUN_00507b00(iVar3);

        FUN_00446ce0(*(undefined4 *)(param_1 + 0xf8),uVar2,param_1 + 0x104);

        puVar6 = puVar6 + puVar6[1];

        goto LAB_00444114;

      case 0x11:

        *(undefined4 *)(param_1 + 0x114) = puVar6[2];

        puVar6 = puVar6 + puVar6[1];

        goto LAB_00444114;

      case 0x12:

        *(undefined4 *)(param_1 + 0x118) = puVar6[2];

        puVar6 = puVar6 + puVar6[1];

        goto LAB_00444114;

      case 0x13:

        *(undefined4 *)(param_1 + 0x10c) = puVar6[2];

        puVar6 = puVar6 + puVar6[1];

        goto LAB_00444114;

      case 0x14:

        *(undefined4 *)(param_1 + 0x110) = puVar6[2];

        puVar6 = puVar6 + puVar6[1];

        goto LAB_00444114;

      case 0x15:

        *(undefined4 *)(param_1 + 0x104) = puVar6[2];

        *(undefined4 *)(param_1 + 0x108) = puVar6[3];

        puVar6 = puVar6 + puVar6[1];

        goto LAB_00444114;

      case 0x16:

        if (0.0 <= *(float *)(param_1 + 0x124)) {

          if ((float)puVar6[2] == 0.0) {

            *(undefined4 *)(param_1 + 0x11c) = 0x447a0000;

            puVar6 = puVar6 + puVar6[1];

          }

          else {

            *(float *)(param_1 + 0x11c) = 1.0 / (float)puVar6[2];

            puVar6 = puVar6 + puVar6[1];

          }

          goto LAB_00444114;

        }

        break;

      case 0x17:

        *(undefined4 *)(param_1 + 0x128) = puVar6[2];

        puVar6 = puVar6 + puVar6[1];

        goto LAB_00444114;

      case 0x18:

        goto switchD_0044412a_caseD_18;

      case 0x29:

        iVar3 = __ftol();

        uVar4 = __ftol();

        uVar5 = __ftol();

        *(uint *)(param_1 + 0x134) = (iVar3 << 8 | uVar4) << 8 | uVar5;

      }

      puVar6 = puVar6 + puVar6[1];

      goto LAB_00444114;

    }

  }

  return;

switchD_0044412a_caseD_18:

  *(float *)(param_1 + 0x124) = (float)puVar6[2] + *(float *)(param_1 + 0x124);

  puVar6 = puVar6 + puVar6[1];

  goto LAB_00444114;

}

/* ===== wredit_text_fade @ 0x00444320 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void wredit_text_fade(void)



{

  float fVar1;

  char cVar2;

  undefined4 uVar3;

  char *pcVar4;

  char *pcVar5;

  char *pcVar6;

  byte bVar7;

  float10 fVar8;

  float local_214;

  char local_200 [512];

  

  uVar3 = DAT_0059ce4c;

  if (DAT_0059ce38 != (char *)0x0) {

    fVar8 = (float10)crt_fabs(DAT_0059ce4c);

    fVar1 = (float)fVar8;

    local_214 = 1.0 - _DAT_0059ce48;

    if (local_214 < 1.0) {

      pcVar4 = DAT_0059ce38;

      do {

        cVar2 = *pcVar4;

        pcVar6 = pcVar4;

        while ((cVar2 != '\0' && (cVar2 != '\n'))) {

          pcVar5 = pcVar6 + 1;

          pcVar6 = pcVar6 + 1;

          cVar2 = *pcVar5;

        }

        if ((-fVar1 <= local_214) && (pcVar6 != pcVar4 && -1 < (int)pcVar6 - (int)pcVar4)) {

          pcVar5 = local_200;

          while (pcVar4 != pcVar6) {

            if (*pcVar4 == '~') {

              *pcVar5 = pcVar4[1] + -0x30;

              pcVar4 = pcVar4 + 2;

            }

            else {

              *pcVar5 = *pcVar4;

              pcVar4 = pcVar4 + 1;

            }

            pcVar5 = pcVar5 + 1;

          }

          fVar8 = (float10)textrender_draw_cached(uVar3,local_200,(int)pcVar5 - (int)local_200);

          FUN_0051b9c0(0xffffffff,0,uVar3,(float)((float10)0.5 - fVar8 * (float10)0.5),local_214,

                       local_200,(int)pcVar5 - (int)local_200);

        }

        local_214 = fVar1 * 1.01 + local_214;

      } while ((*pcVar6 != '\0') && (pcVar4 = pcVar6 + 1, local_214 < 1.0));

    }

    if (DAT_0059ce40 == 0) {

      fVar1 = DAT_006328e0 * _DAT_0059ce50 * fVar1;

      if (DAT_0059ce3c == 0) {

        _DAT_0059ce48 = fVar1 + _DAT_0059ce48;

        bVar7 = local_214 < 0.0 | (byte)((ushort)((ushort)NAN(local_214) << 10) >> 8);

      }

      else {

        _DAT_0059ce48 = _DAT_0059ce48 - fVar1;

        bVar7 = _DAT_0059ce48 < 0.0 | (byte)((ushort)((ushort)NAN(_DAT_0059ce48) << 10) >> 8);

      }

      if ((POPCOUNT(bVar7) & 1U) != 0) {

        DAT_0059ce38 = (char *)0x0;

      }

    }

  }

  return;

}

/* ===== FLK_FlickRender @ 0x004444C0 ===== */
/* WARNING: Removing unreachable block (ram,0x004446e1) */

/* PS2 candidate: FLK_FlickRender__FP9FLK_Flick (conf 0.365) */



undefined4 FLK_FlickRender(int param_1)



{

  float *pfVar1;

  float fVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 *puVar6;

  int iVar7;

  int *piVar8;

  int *piVar9;

  uint *puVar10;

  int *piVar11;

  int iVar12;

  int *piVar13;

  float10 fVar14;

  undefined8 uVar15;

  int local_210;

  float fStack_208;

  int iStack_200;

  float local_1f8;

  float fStack_1f4;

  undefined4 *local_1e8;

  float fStack_1e4;

  int iStack_1e0;

  float local_1dc;

  int iStack_1d8;

  int aiStack_1d4 [2];

  undefined4 uStack_1cc;

  undefined4 uStack_1c8;

  undefined4 uStack_1c4;

  undefined4 uStack_1c0;

  char *local_190;

  float local_18c;

  undefined4 uStack_188;

  undefined4 uStack_184;

  int iStack_180;

  int iStack_17c;

  int iStack_178;

  undefined4 uStack_170;

  undefined4 uStack_16c;

  undefined4 uStack_168;

  int iStack_164;

  int iStack_160;

  int iStack_15c;

  undefined4 uStack_158;

  undefined4 uStack_154;

  undefined4 uStack_150;

  undefined4 uStack_14c;

  undefined1 auStack_148 [4];

  undefined1 auStack_144 [124];

  undefined1 auStack_c8 [4];

  undefined1 auStack_c4 [64];

  undefined1 local_84 [64];

  undefined1 auStack_44 [68];

  

  local_210 = 1;

  if (*(int *)(param_1 + 0xb4) == 0) {

    return 1;

  }

  fVar14 = (float10)FUN_00515d90();

  local_18c = (float)fVar14;

  fVar14 = (float10)FUN_00515da0();

  local_1dc = (float)fVar14;

  XFGetViewport_2();

  FUN_005163e0(local_84);

  render_get_clip_nearfar(&local_190,&local_1e8);

  FNT_StringRender__FPcP14FNT_RenderInfo((char *)0x3f800000,local_1e8);

  uVar4 = AddHud__4cHudP8cHudIcon_4

                    (*(undefined4 *)(*(int *)(param_1 + 0xb4) + 0xc),*(undefined4 *)(param_1 + 0xb0)

                    );

  uVar5 = FUN_0053bef0(*(undefined4 *)(param_1 + 0xb4),uVar4,

                       *(undefined4 *)(*(int *)(param_1 + 0xb8) + 4));

  FUN_0053d970(auStack_c8,uVar5);

  FUN_005162b0(auStack_c4);

  puVar6 = (undefined4 *)XFGetCameraOrigin();

  fVar2 = DAT_006328e0;

  uStack_170 = *puVar6;

  uStack_16c = puVar6[1];

  uStack_168 = puVar6[2];

  fStack_208 = DAT_006328e0;

  iVar12 = *(int *)(param_1 + 0x94);

  DAT_006328e0 = (float)*(undefined4 *)(param_1 + 0xac);

  puVar6 = DAT_00632d84;

  if (iVar12 != 0) {

    puVar10 = (uint *)(*(int *)(param_1 + 0xa0) + 0x3c);

    do {

      if (*(int *)(param_1 + 0xa8) != 0) {

        *puVar10 = *puVar10 | 0x20;

      }

      if ((puVar10[-0xd] != 0) || (*(int *)(param_1 + 0xa8) != 0)) {

        object_animate_process(puVar10 + -0xc,DAT_006328e0);

      }

      puVar10 = puVar10 + 0x21d;

      iVar12 = iVar12 + -1;

      puVar6 = DAT_00632d84;

    } while (iVar12 != 0);

  }

  for (; puVar3 = DAT_00632d68, puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {

    iVar12 = puVar6[3];

    *(uint *)(iVar12 + 0xd8) = *(uint *)(iVar12 + 0xd8) & 0xffffffbf;

    FUN_004a6420();

    if ((*(byte *)(iVar12 + 0xd8) & 0x40) != 0) {

      object_apply_location();

      FUN_004967b0(iVar12);

    }

    if (*(int *)(iVar12 + 0x1e0) == 0x3d) {

      ObjectSetAnim(iVar12,*(undefined4 *)(iVar12 + 0x10),0x34,1,0);

      object_animate_process(iVar12,DAT_006328e0);

    }

    else if ((*(int *)(iVar12 + 4) == 0x65) || (*(int *)(iVar12 + 4) == 0x66)) {

      object_animate_process(iVar12,DAT_006328e0);

    }

  }

  for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

    iVar12 = puVar3[3];

    iVar7 = FUN_00445570(param_1,iVar12);

    if (iVar7 != 0) {

      *(uint *)(iVar12 + 0xd8) = *(uint *)(iVar12 + 0xd8) & 0xffffffbf;

      if (*(int *)(iVar12 + 0x1e0) == 0x3d) {

        ObjectSetAnim(iVar12,*(undefined4 *)(iVar12 + 0x10),0x34,1);

        object_animate_process(iVar12,DAT_006328e0);

      }

      else if ((*(int *)(iVar12 + 4) == 0x65) || (*(int *)(iVar12 + 4) == 0x66)) {

        object_animate_process();

      }

    }

  }

  iVar12 = *(int *)(param_1 + 0x98);

  if (iVar12 != 0) {

    piVar8 = (int *)(*(int *)(param_1 + 0xa4) + 0x304);

    do {

      if (*piVar8 != 0) {

        piVar9 = piVar8 + -0x1c;

        wredit_matrix_recurse(piVar9,*piVar8);

        if (piVar8[1] != 0) {

          AddHud__4cHudP8cHudIcon_4(*(undefined4 *)(piVar8[1] + 0xc));

          iVar7 = *(int *)*piVar8;

          if (iVar7 != 0) {

            ((int *)*piVar8)[6] = *(int *)(iVar7 + 4);

          }

          uVar5 = ANM_NodeGetMat(piVar8[1]);

          (*(code *)PTR_crt_matrix_mul_00580c18)(piVar9,piVar9,uVar5);

        }

      }

      piVar8 = piVar8 + 0xc4;

      iVar12 = iVar12 + -1;

    } while (iVar12 != 0);

  }

  object_list_update();

  FUN_0044efd0();

  object_lock_apply(1,4);

  sound_checked_big(0);

  piVar8 = *(int **)(param_1 + 0xa0);

  DAT_006328e0 = fVar2;

  if (*(int *)(param_1 + 0x94) != 0) {

    piVar9 = piVar8 + 5;

    iStack_1d8 = *(int *)(param_1 + 0x94);

    do {

      if ((piVar9[-3] != 0) && (piVar9[-1] != 0)) {

        piVar11 = piVar9 + 0xa3;

        wredit_matrix_recurse(piVar11,piVar8);

        if (piVar9[0x1db] != 0) {

          if (*piVar8 != 0) {

            piVar9[1] = *(int *)(*piVar8 + 4);

          }

          uVar5 = AddHud__4cHudP8cHudIcon_4(*(undefined4 *)(piVar9[0x1db] + 0xc),piVar9[3]);

          uVar5 = ANM_NodeGetMat(piVar9[0x1db],uVar5);

          (*(code *)PTR_crt_matrix_mul_00580c18)(aiStack_1d4,piVar11,uVar5);

          piVar11 = aiStack_1d4;

        }

        uStack_158 = 0;

        uStack_154 = 0x3f800000;

        uStack_150 = 0;

        uStack_14c = 0;

        (*(code *)PTR_S_GEO_Vec4Transform_00580c28)(&iStack_180,&uStack_158);

        iStack_178 = 0;

        GEO_Vec3Normalize(&iStack_180,&iStack_180);

        GEO_Vec2Cross(&iStack_164,&iStack_180,&DAT_005585a8);

        piVar9[0x1e0] = iStack_164;

        piVar9[0x1e4] = iStack_160;

        piVar9[0x1e8] = iStack_15c;

        piVar9[0x1e1] = iStack_180;

        piVar9[0x1e5] = iStack_17c;

        piVar9[0x1e9] = iStack_178;

        piVar9[0x1e2] = DAT_005585a8;

        piVar9[0x1e6] = DAT_005585ac;

        piVar9[0x1ea] = DAT_005585b0;

        piVar9[0x1e3] = piVar11[4];

        piVar9[0x1e7] = piVar11[8];

        piVar9[0x1eb] = piVar11[0xc];

        piVar9[0x1ee] = 0;

        piVar9[0x1ed] = 0;

        piVar9[0x1ec] = 0;

        piVar9[0x1ef] = 0x3f800000;

        piVar9[0x1df] = 0x11;

        piVar9[0x2c] = piVar9[0x29];

        piVar9[0x2d] = piVar9[0x2a];

        piVar9[0x2e] = piVar9[0x2b];

        piVar9[0x29] = piVar9[0x26];

        piVar9[0x2a] = piVar9[0x27];

        piVar9[0x2b] = piVar9[0x28];

        piVar9[0x26] = piVar11[4];

        piVar9[0x27] = piVar11[8];

        piVar9[0x28] = piVar11[0xc];

        setMenuSelection__7PS2Gameiiii(piVar9 + -2);

        if (DAT_0063311c == 0) {

          iStack_200 = piVar9[0xb6];

          if (((iStack_200 != 0) && (*(char *)(iStack_200 + 0x1e) < '\0')) && (DAT_006331c0 != 0)) {

            iStack_200 = 0;

          }

          piVar11 = (int *)0x0;

          if (piVar9[0x1f0] == 0) {

            if ((iStack_200 == 0) || (-1 < *(char *)(iStack_200 + 0x1e))) {

              iVar12 = *piVar9;

              iVar7 = *(int *)(iVar12 + 0xc);

            }

            else {

              iVar12 = *piVar9;

              iVar7 = *(int *)(iVar12 + 8 + piVar9[2] * 4);

            }

            if (((iVar7 == 0) || (piVar11 = (int *)(iVar7 + 0xc), piVar11 == (int *)0x0)) &&

               (*(int *)(iVar12 + 0x400) != 0)) {

              piVar11 = (int *)(*(int *)(iVar12 + 0x400) + 0x44);

            }

            piVar13 = piVar9 + 0x20d;

            for (iVar12 = 6; iVar12 != 0; iVar12 = iVar12 + -1) {

              *piVar13 = *piVar11;

              piVar11 = piVar11 + 1;

              piVar13 = piVar13 + 1;

            }

          }

          if ((iStack_200 != 0) && (*(char *)(iStack_200 + 0x1e) < '\0')) {

            if (local_210 != 0) {

              local_210 = (**(code **)(DAT_00656420 + 0x8c))(DAT_00656420,iStack_200);

            }

            (**(code **)(DAT_00656420 + 0xc0))(DAT_00656420,iStack_200,&uStack_184);

            fStack_208 = (float)(1 << ((byte)uStack_184 & 0x1f));

            iStack_1e0 = 1 << ((byte)uStack_188 & 0x1f);

            fVar2 = (float)iStack_1e0;

            fStack_1e4 = (float)(int)fStack_208;

            XFSetViewportRegion(0,0,fStack_1e4,fVar2);

            (**(code **)(DAT_00656420 + 0xa0))(DAT_00656420,0,0,fStack_1e4,fVar2,0);

            FUN_00515de0(piVar9 + 0x20d,piVar9 + 0x210);

            FUN_00515de0();

            (*(code *)PTR_crt_matrix_copy_init_00580c1c)(auStack_44,piVar9 + 0x1df);

            FUN_0053d970(auStack_148,auStack_44);

            FUN_005162b0(auStack_144);

            FUN_00451cf0();

            (**(code **)(DAT_00656420 + 0x14))(DAT_00656420);

            animate_core_caller(piVar9 + -2,0,0,piVar9 + 0xa3,&uStack_170);

            FUN_00451da0();

            if (local_210 == 0) {

              (**(code **)(DAT_00656420 + 0xb8))(DAT_00656420,iStack_200,0,0);

            }

          }

        }

        if ((float)piVar9[0x20a] != 0.0) {

          fVar14 = (float10)distance3d__FP3P3DT0(piVar9 + 0x29);

          drip_make(piVar9 + -2,piVar9 + 0x20b,(float)(fVar14 / (float10)DAT_006328e0),0,

                    piVar9[0x20a]);

        }

      }

      piVar8 = piVar8 + 0x21d;

      piVar9 = piVar9 + 0x21d;

      iStack_1d8 = iStack_1d8 + -1;

    } while (iStack_1d8 != 0);

    if (local_210 == 0) {

      (**(code **)(DAT_00656420 + 0x9c))

                (DAT_00656420,0,0,(float)(int)fStack_208,(float)iStack_1e0,0);

    }

  }

  if ((DAT_0063311c == 0) && (DAT_006331c0 == 0)) {

    (**(code **)(DAT_00656420 + 0x8c))(DAT_00656420,0,0);

  }

  object_spawn_class3();

  if (*(float *)(param_1 + 0xd4) != 0.0) {

    fVar2 = *(float *)(param_1 + 0xd4) * *(float *)(param_1 + 0xac) + *(float *)(param_1 + 0xcc);

    *(float *)(param_1 + 0xcc) = fVar2;

    if (0.0 <= *(float *)(param_1 + 0xd4)) {

      if (*(float *)(param_1 + 0xd0) < fVar2) {

        *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_1 + 0xd0);

        goto LAB_00444d25;

      }

    }

    else if (fVar2 < *(float *)(param_1 + 0xd0)) {

      *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_1 + 0xd0);

LAB_00444d25:

      *(undefined4 *)(param_1 + 0xd4) = 0;

    }

  }

  iVar12 = __ftol();

  fVar2 = (float)iVar12;

  FUN_00516220();

  (**(code **)(DAT_00656420 + 0x9c))

            (DAT_00656420,0,fStack_1f4 - fVar2,local_1f8 + local_1f8,fVar2 + fVar2,

             *(undefined4 *)(DAT_006330e4 + 0x13c));

  (**(code **)(DAT_00656420 + 0x9c))(DAT_00656420,0,0,local_1f8 + local_1f8,fStack_1f4 - fVar2,0);

  (**(code **)(DAT_00656420 + 0x9c))

            (DAT_00656420,0,fStack_1f4 + fVar2,local_1f8 + local_1f8,fStack_1f4 - fVar2,0);

  XFSetViewportRegion(0,fStack_1f4 - fVar2,local_1f8 + local_1f8,fVar2 + fVar2);

  FUN_005162b0(auStack_c4);

  fVar14 = (float10)FUN_0053be80(*(undefined4 *)(param_1 + 0xb4),uVar4);

  fVar14 = (float10)fptan(fVar14 * (float10)0.5);

  fVar14 = (float10)fpatan(fVar14 / (float10)local_1dc,(float10)1);

  render_projection_set((float)(fVar14 * (float10)114.59156),0,1);

  xfmat_mult_b();

  FUN_00451cf0();

  main_drawobj_0042d490();

  uVar4 = XFGetCameraOrigin();

  ai_island_init(uVar4);

  iVar12 = *(int *)(param_1 + 0x94);

  piVar8 = *(int **)(param_1 + 0xa0);

  FUN_00435f30();

  if (iVar12 != 0) {

    piVar9 = piVar8 + 5;

    do {

      if ((piVar9[-3] != 0) && (piVar9[-1] != 0)) {

        Audio3DTestToneUpdate__Fv_2();

        iVar7 = BinFileCreateWrite_2();

        iVar7 = *(int *)(*piVar9 + 0x400 + iVar7 * 4);

        *(undefined4 *)(iVar7 + 100) = 0;

        *(undefined4 *)(iVar7 + 0x5c) = 0xbf800000;

        if (((*piVar9 != 0) &&

            ((((piVar9[0x34] & 0x4000c000U) == 0 && (piVar9[0x5f] != 0x3f800000)) &&

             (piVar9 + -2 != DAT_00632a88)))) && ((int *)piVar9[0x82] != DAT_00632a88)) {

          if (*piVar8 == 0) {

            sine_cosine_table_gen();

          }

          if (-1 < (char)piVar9[0x34]) {

            alpha_queue_push();

          }

        }

        Audio3DTestToneUpdate__Fv_3();

        if ((*(int *)(param_1 + 0xc0) == 0) && (piVar9[0x1db] != 0)) {

          iVar7 = piVar9[0xb6];

          if ((iVar7 == 0) || ((*(char *)(iVar7 + 0x1e) < '\0' && (DAT_006331c0 != 0)))) {

            FUN_004360f0();

            FUN_00436110(piVar9 + 0x1df,piVar9 + 0x20d);

          }

          else {

            FUN_00436090(0x23234,iVar7,0xa0a0a0);

            FUN_004360d0(piVar9 + 0x1df,piVar9 + 0x20d);

          }

        }

      }

      piVar8 = piVar8 + 0x21d;

      piVar9 = piVar9 + 0x21d;

      iVar12 = iVar12 + -1;

    } while (iVar12 != 0);

  }

  FUN_00435fd0();

  cleanup_00436060();

  for (puVar6 = DAT_00632d84; puVar3 = DAT_00632d68, puVar6 != (undefined4 *)0x0;

      puVar6 = (undefined4 *)*puVar6) {

    piVar8 = (int *)puVar6[3];

    if (((((piVar8[2] != 0) && ((piVar8[0x36] & 0x4000c000U) == 0)) && (piVar8[0x61] != 0x3f800000))

        && ((piVar8 != DAT_00632a88 && ((int *)piVar8[0x84] != DAT_00632a88)))) &&

       (sine_cosine_table_gen(), -1 < (char)piVar8[0x36])) {

      alpha_queue_push();

    }

  }

  for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

    piVar8 = (int *)puVar3[3];

    iVar12 = FUN_00445570(param_1,piVar8);

    if ((((iVar12 != 0) && (piVar8[2] != 0)) &&

        (((piVar8[0x36] & 0x4000c000U) == 0 &&

         (((piVar8[0x61] != 0x3f800000 && (piVar8 != DAT_00632a88)) &&

          ((int *)piVar8[0x84] != DAT_00632a88)))))) &&

       (sine_cosine_table_gen(), -1 < (char)piVar8[0x36])) {

      alpha_queue_push();

    }

  }

  Audio3DTestToneUpdate__Fv_2();

  alpha_queue_push_3(0,4);

  Audio3DTestToneUpdate__Fv_3();

  dome_render_text(0,*(undefined4 *)(param_1 + 0xbc));

  if (*(int *)(param_1 + 0xc4) == 0) {

    lens_effects_process__Fv();

  }

  main_drawwatr_00431700();

  Audio3DTestToneUpdate__Fv_2();

  render_view_xform();

  Audio3DTestToneUpdate__Fv_3();

  if (*(int *)(param_1 + 0xc4) == 0) {

    FUN_004cd990();

  }

  if (DAT_00632c0c != 0) {

    FUN_005162b0();

    xfmat_mult_a();

    main_drawobj_0042d490();

    FUN_00426f20();

    render_view_xform();

  }

  pfVar1 = (float *)(param_1 + 0xe8);

  if (*(float *)(param_1 + 0xf0) != 0.0) {

    fVar2 = *(float *)(param_1 + 0xac) * *(float *)(param_1 + 0xf0) + *pfVar1;

    *pfVar1 = fVar2;

    if (0.0 <= *(float *)(param_1 + 0xf0)) {

      if (*(float *)(param_1 + 0xec) < fVar2) {

        *pfVar1 = *(float *)(param_1 + 0xec);

        goto LAB_00445182;

      }

    }

    else if (fVar2 < *(float *)(param_1 + 0xec)) {

      *pfVar1 = *(float *)(param_1 + 0xec);

LAB_00445182:

      *(undefined4 *)(param_1 + 0xf0) = 0;

    }

  }

  FUN_004433b0();

  pfVar1 = (float *)(param_1 + 0xd8);

  if (*(float *)(param_1 + 0xe0) != 0.0) {

    fVar2 = *(float *)(param_1 + 0xac) * *(float *)(param_1 + 0xe0) + *pfVar1;

    *pfVar1 = fVar2;

    if (0.0 <= *(float *)(param_1 + 0xe0)) {

      if (fVar2 <= *(float *)(param_1 + 0xdc)) goto LAB_004451e2;

      *pfVar1 = *(float *)(param_1 + 0xdc);

    }

    else {

      if (*(float *)(param_1 + 0xdc) <= fVar2) goto LAB_004451e2;

      *pfVar1 = *(float *)(param_1 + 0xdc);

    }

    *(undefined4 *)(param_1 + 0xe0) = 0;

  }

LAB_004451e2:

  FUN_004433b0();

  ANM_DumpCluster();

  FUN_00516220(&local_1f8);

  render_projection_set(local_18c,local_1dc,1);

  if (DAT_00633248 != 0) {

    fVar14 = (float10)FUN_00450c90();

    crt_sprintf(auStack_148,s_Framerate_Average___3_2f_005587b8,(double)fVar14);

    object_stop_movement(aiStack_1d4);

    aiStack_1d4[0] = 0;

    uStack_1c4 = 0;

    uStack_1c0 = 0x3d4ccccd;

    uStack_1c8 = 0x3cf5c28f;

    uStack_1cc = 0x3cf5c28f;

    FNT_RenderInfoProcess__FP14FNT_RenderInfof(aiStack_1d4,DAT_006328e0);

    uVar15 = CONCAT44(aiStack_1d4,auStack_148);

    uVar4 = AudioGetMasterVolume__Fv_3();

    FUN_00446ce0(uVar4,uVar15);

    uVar4 = AudioGetMasterVolume__Fv_7();

    crt_sprintf(auStack_148,s_Triangle_second___d_005587a4,uVar4);

    object_stop_movement(aiStack_1d4);

    aiStack_1d4[0] = 0;

    uStack_1c4 = 0;

    uStack_1c0 = 0x3d99999a;

    uStack_1c8 = 0x3cf5c28f;

    uStack_1cc = 0x3cf5c28f;

    FNT_RenderInfoProcess__FP14FNT_RenderInfof(aiStack_1d4,DAT_006328e0);

    uVar15 = CONCAT44(aiStack_1d4,auStack_148);

    uVar4 = AudioGetMasterVolume__Fv_3();

    FUN_00446ce0(uVar4,uVar15);

    uVar4 = FUN_00450cc0();

    crt_sprintf(auStack_148,s_Triangle_scene___d_00558790,uVar4);

    object_stop_movement(aiStack_1d4);

    aiStack_1d4[0] = 0;

    uStack_1c4 = 0;

    uStack_1c0 = 0x3dcccccd;

    uStack_1c8 = 0x3cf5c28f;

    uStack_1cc = 0x3cf5c28f;

    FNT_RenderInfoProcess__FP14FNT_RenderInfof(aiStack_1d4,DAT_006328e0);

    uVar15 = CONCAT44(aiStack_1d4,auStack_148);

    uVar4 = AudioGetMasterVolume__Fv_3();

    FUN_00446ce0(uVar4,uVar15);

    uVar4 = AudioGetMasterVolume__Fv_4();

    crt_sprintf(auStack_148,s_Number_of_Frames___d_00558778,uVar4);

    object_stop_movement(aiStack_1d4);

    aiStack_1d4[0] = 0;

    uStack_1c4 = 0;

    uStack_1c0 = 0x3e000000;

    uStack_1c8 = 0x3cf5c28f;

    uStack_1cc = 0x3cf5c28f;

    FNT_RenderInfoProcess__FP14FNT_RenderInfof(aiStack_1d4,DAT_006328e0);

    uVar15 = CONCAT44(aiStack_1d4,auStack_148);

    uVar4 = AudioGetMasterVolume__Fv_3();

    FUN_00446ce0(uVar4,uVar15);

    uVar4 = AudioGetMasterVolume__Fv_6();

    crt_sprintf(auStack_148,s_Framerate_Min___d_00558764,uVar4);

    object_stop_movement(aiStack_1d4);

    aiStack_1d4[0] = 0;

    uStack_1c4 = 0;

    uStack_1c0 = 0x3e19999a;

    uStack_1c8 = 0x3cf5c28f;

    uStack_1cc = 0x3cf5c28f;

    FNT_RenderInfoProcess__FP14FNT_RenderInfof(aiStack_1d4,DAT_006328e0);

    uVar15 = CONCAT44(aiStack_1d4,auStack_148);

    uVar4 = AudioGetMasterVolume__Fv_3();

    FUN_00446ce0(uVar4,uVar15);

    uVar4 = AudioGetMasterVolume__Fv_5();

    crt_sprintf(auStack_148,s_Framerate_Max___d_00558750,uVar4);

    object_stop_movement(aiStack_1d4);

    aiStack_1d4[0] = 0;

    uStack_1c4 = 0;

    uStack_1c0 = 0x3e333333;

    uStack_1c8 = 0x3cf5c28f;

    uStack_1cc = 0x3cf5c28f;

    FNT_RenderInfoProcess__FP14FNT_RenderInfof(aiStack_1d4,DAT_006328e0);

    uVar15 = CONCAT44(aiStack_1d4,auStack_148);

    uVar4 = AudioGetMasterVolume__Fv_3();

    FUN_00446ce0(uVar4,uVar15);

  }

  FLK_FlickTextProcess__FP9FLK_Flick();

  wredit_text_fade(param_1);

  AddHud__4cHudP8cHudIcon_2();

  fps_display();

  FUN_00451da0();

  (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

  if (DAT_00633248 != 0) {

    FUN_00450bb0();

  }

  FNT_StringRender__FPcP14FNT_RenderInfo(local_190,local_1e8);

  return 1;

}

/* ===== FUN_00445570 @ 0x00445570 ===== */
/* PS2 candidate: FLK_ObjectInFlick__FP9FLK_FlickP6OBJECT (conf 0.367) */



undefined4 FUN_00445570(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  undefined4 uVar4;

  byte bVar5;

  uint uVar6;

  float10 fVar7;

  

  iVar1 = *(int *)(param_2 + 4);

  if (iVar1 < 0x248) {

    if (iVar1 == 0x247) {

      return 0;

    }

    if (iVar1 < 0xd3) {

      if (iVar1 == 0xd2) {

        return 0;

      }

      switch(iVar1) {

      case 2:

      case 0xb:

      case 0x15:

      case 0x16:

      case 0x49:

      case 0x7b:

      case 0x7c:

        goto switchD_0044559d_caseD_2;

      }

    }

    else if (iVar1 < 0xf1) {

      if (iVar1 == 0xf0) {

        return 0;

      }

      if (iVar1 == 0xd7) {

        return 0;

      }

      if ((0xe4 < iVar1) && (iVar1 < 0xe7)) {

        return 0;

      }

    }

    else {

      if (iVar1 == 0x20a) {

        return 0;

      }

      iVar2 = iVar1 + -0x232;

LAB_004455d1:

      if (iVar2 == 0) {

        return 0;

      }

    }

  }

  else if (iVar1 < 0x42b) {

    if (0x428 < iVar1) {

      return 0;

    }

    if (iVar1 < 0x2e7) {

      if (iVar1 == 0x2e6) {

        return 0;

      }

      if (iVar1 == 0x29a) {

        return 0;

      }

      iVar2 = iVar1 + -0x2b5;

      goto LAB_004455d1;

    }

    if (iVar1 == 0x33b) {

      return 0;

    }

    if ((0x416 < iVar1) && (iVar1 < 0x41a)) {

      return 0;

    }

  }

  else {

    switch(iVar1) {

    case 0x434:

    case 0x438:

    case 0x446:

    case 0x476:

    case 0x487:

      goto switchD_0044559d_caseD_2;

    }

  }

  if (*(int *)(param_2 + 0x1e0) == 0x61) {

    return 0;

  }

  iVar2 = *(int *)(param_1 + 0x8c);

  if (-1 < iVar2) {

    bVar5 = (byte)iVar2;

    if (iVar2 < 0x20) {

      uVar3 = 1 << (bVar5 & 0x1f);

      uVar6 = *(uint *)(param_2 + 0x2e8);

    }

    else if (iVar2 < 0x40) {

      uVar3 = 1 << (bVar5 - 0x20 & 0x1f);

      uVar6 = *(uint *)(param_2 + 0x2ec);

    }

    else {

      if (iVar2 < 0x60) {

        bVar5 = bVar5 - 0x40;

      }

      else {

        if (0x7f < iVar2) goto LAB_0044569a;

        bVar5 = bVar5 + 0xa0;

      }

      uVar3 = 1 << (bVar5 & 0x1f);

      uVar6 = *(uint *)(param_2 + 0x2f0);

    }

    if ((uVar3 & uVar6) != 0) {

      return 0;

    }

  }

LAB_0044569a:

  if ((iVar1 != 0x473) && (iVar1 != 0x3bb)) {

    uVar4 = XFGetCameraOrigin();

    fVar7 = (float10)FUN_0050a610(uVar4,param_2 + 0xa0);

    if ((float10)*(float *)(param_1 + 0x138) * (float10)*(float *)(param_1 + 0x138) <= fVar7) {

switchD_0044559d_caseD_2:

      return 0;

    }

  }

  return 1;

}

/* ===== hud_icon_timed @ 0x004457D0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 hud_icon_timed(int param_1,float param_2)



{

  int iVar1;

  undefined4 uVar2;

  float fVar3;

  uint uVar4;

  int iVar5;

  undefined4 *puVar6;

  float *pfVar7;

  float10 fVar8;

  

  if (*(int *)(param_1 + 0xb4) == 0) {

    return 1;

  }

  if (*(int *)(param_1 + 0xa8) != 0) {

    *(undefined4 *)(param_1 + 0xb0) = 0;

    param_2 = 0.0;

  }

  if (((DAT_0059cdb0 != 0) && (DAT_00633130 == 0)) && (DAT_0063312c == 0)) {

    fVar8 = (float10)FUN_00496200();

    fVar3 = (float)(((float10)_DAT_0059cdb4 + (float10)*(float *)(param_1 + 0xb0) + (float10)param_2

                    ) - fVar8);

    if ((float10)0.0 < fVar8) {

      if (fVar3 <= param_2) {

        if ((fVar3 < -param_2) && (param_2 = ((-fVar3 - param_2) + 1.0) * param_2, 1.0 < param_2)) {

          param_2 = 1.0;

        }

      }

      else {

        param_2 = param_2 / ((fVar3 - param_2) + 1.0);

      }

    }

  }

  fVar3 = param_2 + *(float *)(param_1 + 0xb0);

  iVar5 = *(int *)(param_1 + 0xb4);

  *(float *)(param_1 + 0xb0) = fVar3;

  *(float *)(param_1 + 0xac) = param_2;

  iVar1 = AddHud__4cHudP8cHudIcon_4(*(undefined4 *)(iVar5 + 0xc),fVar3);

  uVar4 = (uint)(*(int *)(*(int *)(iVar5 + 0xc) + 0x14) <= iVar1);

  *(uint *)(param_1 + 0xa8) = uVar4;

  if (((DAT_0059ce38 != 0) && (DAT_0059ce44 != 0)) &&

     ((uVar4 != 0 && (*(int *)(param_1 + 200) == 0)))) {

    *(undefined4 *)(param_1 + 0xa8) = 0;

    fVar8 = (float10)ANM_SecsFromTicks(*(int *)(iVar5 + 0xc),

                                       *(undefined4 *)(*(int *)(iVar5 + 0xc) + 0x14));

    param_2 = 0.0;

    *(float *)(param_1 + 0xb0) = (float)(fVar8 - (float10)1.0);

    *(undefined4 *)(param_1 + 0xac) = 0;

  }

  iVar5 = *(int *)(param_1 + 0x90);

  if (iVar5 != 0) {

    puVar6 = (undefined4 *)(*(int *)(param_1 + 0x9c) + 4);

    do {

      uVar2 = FUN_0053ca70();

      *puVar6 = uVar2;

      puVar6 = puVar6 + 3;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

  }

  iVar5 = *(int *)(param_1 + 0x94);

  if (iVar5 != 0) {

    pfVar7 = (float *)(*(int *)(param_1 + 0xa0) + 0x868);

    do {

      if (*pfVar7 != 0.0) {

        fVar3 = param_2 * *pfVar7 + pfVar7[-2];

        pfVar7[-2] = fVar3;

        if (0.0 <= *pfVar7) {

          if (pfVar7[-1] < fVar3) {

            pfVar7[-2] = pfVar7[-1];

            goto LAB_004459e7;

          }

        }

        else if (fVar3 < pfVar7[-1]) {

          pfVar7[-2] = pfVar7[-1];

LAB_004459e7:

          *pfVar7 = 0.0;

        }

      }

      pfVar7[-0x1b6] = pfVar7[-2];

      fVar3 = (float)FUN_0053ca70();

      pfVar7[-0x214] = fVar3;

      pfVar7 = pfVar7 + 0x21d;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

  }

  return *(undefined4 *)(param_1 + 0xa8);

}

/* ===== FLK_FlickProcess @ 0x00445A20 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: FLK_FlickProcess__FP9FLK_Flick (conf 0.38) */



undefined4 FLK_FlickProcess(undefined4 *param_1)



{

  int *piVar1;

  float *pfVar2;

  float fVar3;

  int iVar4;

  undefined4 *puVar5;

  float fVar6;

  undefined4 uVar7;

  undefined1 uVar8;

  undefined4 uVar9;

  int iVar10;

  int iVar11;

  undefined4 *puVar12;

  float10 fVar13;

  float10 fVar14;

  float10 fVar15;

  float10 extraout_ST0;

  float10 extraout_ST0_00;

  float10 extraout_ST0_01;

  float10 extraout_ST1;

  float10 extraout_ST1_00;

  

  uVar7 = DAT_006328e0;

  if (param_1 == (undefined4 *)0x0) {

    return 1;

  }

  iVar4 = param_1[0x21];

  puVar12 = (undefined4 *)param_1[0x22];

LAB_00445a50:

  switch(*puVar12) {

  case 1:

    if (puVar12[3] == 0) {

      iVar11 = 0;

    }

    else {

      iVar11 = puVar12[3] + iVar4;

    }

    piVar1 = (int *)(param_1[0x27] + puVar12[2] * 0xc);

    if (piVar1 != (int *)0x0) {

      if (piVar1[2] == 0) {

        iVar11 = bistream_tell_user(0,0,iVar11);

        if (iVar11 != 0) {

          *piVar1 = iVar11;

        }

        piVar1[2] = 1;

        puVar12 = puVar12 + puVar12[1];

      }

      else {

        FUN_00540310(s_Error__Duplicate_director__alrea_005585e4,param_1 + 1);

        puVar12 = puVar12 + puVar12[1];

      }

      goto LAB_00445a50;

    }

    break;

  case 2:

    if (puVar12[3] == 0) {

      iVar11 = 0;

    }

    else {

      iVar11 = puVar12[3] + iVar4;

    }

    FLK_ActorAdd__FP9FLK_FlickiPcii(param_1,puVar12[2],iVar11,puVar12[4],puVar12[5]);

    puVar12 = puVar12 + puVar12[1];

    goto LAB_00445a50;

  case 3:

    if (puVar12[5] == 0) {

      iVar11 = 0;

    }

    else {

      iVar11 = iVar4 + puVar12[5];

    }

    if (puVar12[3] == 0) {

      iVar10 = 0;

    }

    else {

      iVar10 = puVar12[3] + iVar4;

    }

    flick_slot_lookup_handle(param_1,puVar12[2],iVar10,puVar12[4],iVar11);

    puVar12 = puVar12 + puVar12[1];

    goto LAB_00445a50;

  case 4:

    if (puVar12[4] == 0) {

      iVar11 = 0;

    }

    else {

      iVar11 = puVar12[4] + iVar4;

    }

    if (puVar12[3] == 0) {

      iVar10 = 0;

    }

    else {

      iVar10 = puVar12[3] + iVar4;

    }

    if (((-1 < (int)puVar12[2]) &&

        (piVar1 = (int *)(param_1[0x27] + puVar12[2] * 0xc), piVar1 != (int *)0x0)) &&

       (*piVar1 != 0)) {

      iVar10 = FUN_0053be00(*piVar1,iVar10,iVar11);

      if (iVar10 == 0) {

        FUN_00540310(s_Flick_error___Can_t_find_camera___0055872c,iVar11);

        puVar12 = puVar12 + puVar12[1];

      }

      else {

        uVar9 = FUN_0053be60(iVar10);

        param_1[0x2d] = uVar9;

        param_1[0x2e] = piVar1;

        puVar12 = puVar12 + puVar12[1];

      }

      goto LAB_00445a50;

    }

    break;

  case 6:

    param_1[0x30] = 0;

    param_1[0x2f] = 0;

    puVar12 = puVar12 + puVar12[1];

    goto LAB_00445a50;

  case 7:

    fVar6 = (float)puVar12[3];

    fVar3 = (float)puVar12[2];

    param_1[0x34] = fVar3;

    if (fVar6 == 0.0) {

      param_1[0x33] = fVar3;

      param_1[0x35] = 0;

      puVar12 = puVar12 + puVar12[1];

    }

    else {

      param_1[0x35] = (fVar3 - (float)param_1[0x33]) / fVar6;

      puVar12 = puVar12 + puVar12[1];

    }

    goto LAB_00445a50;

  case 8:

    if ((float)param_1[0x2c] < (float)puVar12[2]) goto switchD_00445a5c_caseD_5;

    break;

  case 9:

    if (param_1[0x2d] != 0) {

      iVar11 = AddHud__4cHudP8cHudIcon_4(*(undefined4 *)(param_1[0x2d] + 0xc),param_1[0x2c]);

      if (iVar11 / *(int *)(*(int *)(param_1[0x2d] + 0xc) + 0x18) < (int)puVar12[2])

      goto switchD_00445a5c_caseD_5;

      puVar12 = puVar12 + puVar12[1];

      goto LAB_00445a50;

    }

    break;

  case 10:

    if (param_1[0x2d] != 0) {

      iVar11 = AddHud__4cHudP8cHudIcon_4(*(undefined4 *)(param_1[0x2d] + 0xc),param_1[0x2c]);

      if (iVar11 < (int)puVar12[2]) goto switchD_00445a5c_caseD_5;

      puVar12 = puVar12 + puVar12[1];

      goto LAB_00445a50;

    }

    break;

  case 0xb:

    if (-1 < (int)puVar12[2]) {

      *(undefined4 *)(puVar12[2] * 0x874 + 8 + param_1[0x28]) = 1;

      puVar12 = puVar12 + puVar12[1];

      goto LAB_00445a50;

    }

    break;

  case 0xc:

    if (-1 < (int)puVar12[2]) {

      *(undefined4 *)(puVar12[2] * 0x874 + 8 + param_1[0x28]) = 0;

      puVar12 = puVar12 + puVar12[1];

      goto LAB_00445a50;

    }

    break;

  case 0xd:

    if (-1 < (int)puVar12[2]) {

      sound_play_obj(puVar12[3],puVar12[2] * 0x874 + 0xc + param_1[0x28]);

      puVar12 = puVar12 + puVar12[1];

      goto LAB_00445a50;

    }

    break;

  case 0xe:

    param_1[0x3f] = puVar12;

    param_1[0x48] = 0;

    param_1[0x4b] = 0;

    param_1[0x4c] = 0x3f800000;

    param_1[0x4d] = 0xffff;

    puVar12 = puVar12 + puVar12[1];

    goto LAB_00445a50;

  case 0x19:

    if (puVar12[3] == 0) {

      FUN_00443f30(param_1,puVar12[2],0);

      puVar12 = puVar12 + puVar12[1];

    }

    else {

      FUN_00443f30(param_1,puVar12[2],puVar12[3] + iVar4);

      puVar12 = puVar12 + puVar12[1];

    }

    goto LAB_00445a50;

  case 0x1a:

    if (-1 < (int)puVar12[2]) {

      sound_play(puVar12[2]);

      puVar12 = puVar12 + puVar12[1];

      goto LAB_00445a50;

    }

    break;

  case 0x1b:

    if (-1 < (int)puVar12[2]) {

      FUN_00495990(puVar12[2]);

      puVar12 = puVar12 + puVar12[1];

      goto LAB_00445a50;

    }

    break;

  case 0x1c:

    if (puVar12[2] == 0) {

      (*DAT_005dd318)(0);

      puVar12 = puVar12 + puVar12[1];

    }

    else {

      (*DAT_005dd318)(puVar12[2] + iVar4);

      puVar12 = puVar12 + puVar12[1];

    }

    goto LAB_00445a50;

  case 0x1e:

    (*DAT_005dd31c)();

    puVar12 = puVar12 + puVar12[1];

    goto LAB_00445a50;

  case 0x1f:

    fVar6 = (float)puVar12[3];

    fVar3 = (float)puVar12[2];

    param_1[0x37] = fVar3;

    if (fVar6 == 0.0) {

      param_1[0x36] = fVar3;

      param_1[0x38] = 0;

      puVar12 = puVar12 + puVar12[1];

    }

    else {

      param_1[0x38] = (fVar3 - (float)param_1[0x36]) / fVar6;

      puVar12 = puVar12 + puVar12[1];

    }

    goto LAB_00445a50;

  case 0x20:

    iVar11 = puVar12[1];

    if (-1 < (int)puVar12[iVar11 + -1]) {

      iVar10 = puVar12[iVar11 + -1] * 0x874 + param_1[0x28];

      if (iVar11 == 5) {

        *(undefined4 *)(iVar10 + 0x820) = puVar12[2];

        *(undefined4 *)(iVar10 + 0x824) = puVar12[3];

        FUN_00443fb0(iVar10);

        puVar12 = puVar12 + puVar12[1];

      }

      else if (iVar11 == 6) {

        *(undefined4 *)(iVar10 + 0x820) = puVar12[2];

        *(undefined4 *)(iVar10 + 0x824) = puVar12[3];

        *(undefined4 *)(iVar10 + 0x828) = puVar12[4];

        FUN_00443fb0(iVar10);

        puVar12 = puVar12 + puVar12[1];

      }

      else if (iVar11 == 7) {

        *(undefined4 *)(iVar10 + 0x820) = puVar12[2];

        *(undefined4 *)(iVar10 + 0x824) = puVar12[3];

        *(undefined4 *)(iVar10 + 0x828) = puVar12[4];

        *(undefined4 *)(iVar10 + 0x834) = puVar12[5];

        FUN_00443fb0(iVar10);

        puVar12 = puVar12 + puVar12[1];

      }

      else {

        if (iVar11 == 9) {

          *(undefined4 *)(iVar10 + 0x820) = puVar12[2];

          *(undefined4 *)(iVar10 + 0x824) = puVar12[3];

          *(undefined4 *)(iVar10 + 0x828) = puVar12[4];

          *(undefined4 *)(iVar10 + 0x834) = puVar12[5];

          *(undefined4 *)(iVar10 + 0x830) = puVar12[6];

          *(undefined4 *)(iVar10 + 0x82c) = puVar12[7];

        }

        FUN_00443fb0(iVar10);

        puVar12 = puVar12 + puVar12[1];

      }

      goto LAB_00445a50;

    }

    break;

  case 0x21:

    if (-1 < (int)puVar12[2]) {

      *(undefined4 *)(puVar12[2] * 0x874 + 0xd0 + param_1[0x28]) = puVar12[3];

      puVar12 = puVar12 + puVar12[1];

      goto LAB_00445a50;

    }

    break;

  case 0x22:

    if ((-1 < (int)puVar12[2]) && (DAT_006331c0 == 0)) {

      iVar11 = puVar12[2] * 0x874;

      iVar10 = iVar11 + param_1[0x28];

      if (*(int *)(iVar11 + 0x7d4 + param_1[0x28]) == 0) {

        main_objspec_00499c80(iVar10 + 0xc);

      }

      else if (*(int *)(iVar10 + 0x2ec) != 0) {

        (**(code **)(DAT_00656420 + 0xb4))(DAT_00656420,*(int *)(iVar10 + 0x2ec));

        map_memfree(*param_1,*(undefined4 *)(iVar10 + 0x2ec));

        *(undefined4 *)(iVar10 + 0x2ec) = 0;

      }

      uVar9 = FUN_0053ffa0(*param_1,0x20,1);

      *(undefined4 *)(iVar10 + 0x2ec) = uVar9;

      *(undefined4 *)(iVar10 + 0x7d4) = 1;

      puVar5 = *(undefined4 **)(iVar10 + 0x2ec);

      if (puVar5 != (undefined4 *)0x0) {

        *puVar5 = s_Flick_shadow_005587d4;

        puVar5[1] = 0;

        puVar5[2] = 0;

        puVar5[3] = puVar12[3];

        puVar5[4] = puVar12[4];

        *(undefined1 *)((int)puVar5 + 0x1d) = 0;

        *(undefined1 *)(puVar5 + 7) = 0x20;

        *(undefined2 *)((int)puVar5 + 0x1e) = 0x80;

        puVar5[6] = 5;

        puVar5[5] = 5;

        *(undefined4 **)(iVar10 + 0x2ec) = puVar5;

        *(undefined4 *)(iVar10 + 0x848) = puVar12[5];

        *(undefined4 *)(iVar10 + 0x84c) = puVar12[6];

        *(undefined4 *)(iVar10 + 0x854) = puVar12[7];

        *(undefined4 *)(iVar10 + 0x858) = puVar12[8];

        *(undefined4 *)(iVar10 + 0x85c) = 0;

        *(undefined4 *)(iVar10 + 0x850) = 0;

        puVar12 = puVar12 + puVar12[1];

        goto LAB_00445a50;

      }

    }

    break;

  case 0x23:

    if (-1 < (int)puVar12[2]) {

      iVar11 = puVar12[2] * 0x874 + param_1[0x28];

      *(undefined4 *)(iVar11 + 0x840) = 0;

      *(undefined4 *)(iVar11 + 0x83c) = puVar12[3];

      *(undefined4 *)(iVar11 + 0x844) = puVar12[3];

      puVar12 = puVar12 + puVar12[1];

      goto LAB_00445a50;

    }

    break;

  case 0x24:

    if (-1 < (int)puVar12[2]) {

      sound_stop_obj(puVar12[3],puVar12[2] * 0x874 + 0xc + param_1[0x28]);

      puVar12 = puVar12 + puVar12[1];

      goto LAB_00445a50;

    }

    break;

  case 0x25:

    fVar13 = (float10)(float)puVar12[6];

    fVar14 = (float10)(float)puVar12[4];

    fVar15 = (float10)(float)puVar12[3];

    fVar3 = (float)puVar12[2];

    param_1[0x3b] = 1.0 - (float)puVar12[5];

    if (0.0 < fVar3) {

      fVar13 = fVar14;

      uVar8 = __ftol();

      *(undefined1 *)(param_1 + 0x3d) = uVar8;

      fVar15 = extraout_ST0;

      fVar14 = extraout_ST1;

    }

    if ((float10)0.0 < fVar15) {

      uVar8 = __ftol();

      *(undefined1 *)((int)param_1 + 0xf5) = uVar8;

      fVar14 = extraout_ST0_00;

      fVar13 = extraout_ST1_00;

    }

    if ((float10)0.0 < fVar14) {

      uVar8 = __ftol();

      *(undefined1 *)((int)param_1 + 0xf6) = uVar8;

      fVar13 = extraout_ST0_01;

    }

    if (fVar13 == (float10)0.0) {

      param_1[0x3a] = param_1[0x3b];

      param_1[0x3c] = 0;

      puVar12 = puVar12 + puVar12[1];

    }

    else {

      param_1[0x3c] =

           (float)(((float10)(float)param_1[0x3b] - (float10)(float)param_1[0x3a]) / fVar13);

      puVar12 = puVar12 + puVar12[1];

    }

    goto LAB_00445a50;

  case 0x26:

    param_1[0x4e] = puVar12[2];

    puVar12 = puVar12 + puVar12[1];

    goto LAB_00445a50;

  case 0x27:

    if (puVar12[6] == 0) {

      iVar11 = 0;

    }

    else {

      iVar11 = iVar4 + puVar12[6];

    }

    if (puVar12[3] == 0) {

      iVar10 = 0;

    }

    else {

      iVar10 = puVar12[3] + iVar4;

    }

    hud_icon_for_object(param_1,puVar12[2],iVar10,puVar12[4],puVar12[5],iVar11);

    puVar12 = puVar12 + puVar12[1];

    goto LAB_00445a50;

  case 0x28:

    if (puVar12[2] == 0) {

      param_1[0x4f] = 0;

      puVar12 = puVar12 + puVar12[1];

    }

    else {

      param_1[0x4f] = puVar12[2] + iVar4;

      puVar12 = puVar12 + puVar12[1];

    }

    goto LAB_00445a50;

  case 0x2a:

    if (-1 < (int)puVar12[2]) {

      fVar6 = (float)puVar12[4];

      fVar3 = (float)puVar12[3];

      pfVar2 = (float *)(puVar12[2] * 0x874 + 0x860 + param_1[0x28]);

      pfVar2[1] = fVar3;

      if (fVar6 == 0.0) {

        *pfVar2 = fVar3;

        pfVar2[2] = 0.0;

        puVar12 = puVar12 + puVar12[1];

      }

      else {

        pfVar2[2] = (fVar3 - *pfVar2) / fVar6;

        puVar12 = puVar12 + puVar12[1];

      }

      goto LAB_00445a50;

    }

    break;

  case 0x2b:

    if (-1 < (int)puVar12[2]) {

      FUN_00495780(puVar12[2],puVar12[3]);

      puVar12 = puVar12 + puVar12[1];

      goto LAB_00445a50;

    }

    break;

  case 0x2c:

    if (puVar12[2] == 0) {

      iVar11 = 0;

    }

    else {

      iVar11 = puVar12[2] + iVar4;

    }

    teammecc_clear_mode(iVar11,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

    puVar12 = puVar12 + puVar12[1];

    goto LAB_00445a50;

  case 0x2d:

    param_1[0x30] = 1;

    puVar12 = puVar12 + puVar12[1];

    goto LAB_00445a50;

  case 0x2e:

    param_1[0x31] = 1;

    puVar12 = puVar12 + puVar12[1];

    goto LAB_00445a50;

  case 0x2f:

    if (puVar12[2] == 0) {

      iVar11 = 0;

    }

    else {

      iVar11 = puVar12[2] + iVar4;

    }

    DAT_0059ce38 = FUN_00507b00(iVar11);

    DAT_0059ce40 = 0;

    DAT_0059ce3c = 0;

    _DAT_0059ce48 = 0;

    DAT_0059ce44 = 0;

    param_1[0x3f] = 0;

    puVar12 = puVar12 + puVar12[1];

    goto LAB_00445a50;

  case 0x30:

    DAT_0059ce40 = (uint)(DAT_0059ce40 == 0);

    puVar12 = puVar12 + puVar12[1];

    goto LAB_00445a50;

  case 0x31:

    DAT_0059ce3c = (uint)(DAT_0059ce3c == 0);

    DAT_0059ce40 = 0;

    puVar12 = puVar12 + puVar12[1];

    goto LAB_00445a50;

  case 0x32:

    DAT_0059ce4c = puVar12[2];

    puVar12 = puVar12 + puVar12[1];

    goto LAB_00445a50;

  case 0x33:

    _DAT_0059ce50 = puVar12[2];

    puVar12 = puVar12 + puVar12[1];

    goto LAB_00445a50;

  case 0x34:

    if ((param_1[0x2d] == 0) ||

       (iVar11 = AddHud__4cHudP8cHudIcon_4(*(undefined4 *)(param_1[0x2d] + 0xc),param_1[0x2c]),

       *(int *)(*(int *)(param_1[0x2d] + 0xc) + 0x10) < iVar11)) goto LAB_00446389;

  case 5:

switchD_00445a5c_caseD_5:

    param_1[0x22] = puVar12;

    hud_icon_timed(param_1,uVar7);

    if (DAT_00632c0c != 0) {

      FUN_00426ee0();

      if (DAT_0059ce54 == 0) {

        return 1;

      }

      if (DAT_005585b4 != 0) {

        return 1;

      }

    }

    return param_1[0x2a];

  case 0x35:

    DAT_0059ce44 = (uint)(DAT_0059ce44 == 0);

  }

  puVar12 = puVar12 + puVar12[1];

  goto LAB_00445a50;

LAB_00446389:

  if (puVar12[2] == 0) {

    iVar11 = 0;

  }

  else {

    iVar11 = puVar12[2] + iVar4;

  }

  FUN_004961e0(iVar11,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

  DAT_0059cdb0 = 1;

  _DAT_0059cdb4 = -(float)param_1[0x2c];

  puVar12 = puVar12 + puVar12[1];

  goto LAB_00445a50;

}

/* ===== FLK_FlickStop @ 0x00446620 ===== */
/* PS2 candidate: FLK_FlickStop (conf 0.885) */



void FLK_FlickStop(void)



{

  if (DAT_0059ce54 != 0) {

    while (DAT_005585b4 == 0) {

      DAT_005585b4 = 1;

      DAT_005585b4 = flick_objects_reload();

    }

  }

  return;

}

/* ===== flick_file_load_state @ 0x00446650 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int flick_file_load_state(char *param_1)



{

  char cVar1;

  undefined4 uVar2;

  size_t *psVar3;

  char *pcVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  size_t *psVar8;

  undefined4 *puVar9;

  size_t *psVar10;

  size_t asStack_98 [6];

  undefined1 auStack_80 [128];

  

  if (DAT_0059ce54 != 0) {

    while (DAT_005585b4 == 0) {

      DAT_005585b4 = 1;

      DAT_005585b4 = flick_objects_reload();

    }

    if (DAT_0059ce54 != 0) {

      return DAT_005585b4;

    }

  }

  puVar9 = DAT_00632d68;

  if (DAT_005585b4 != 0) {

    for (; puVar9 != (undefined4 *)0x0; puVar9 = (undefined4 *)*puVar9) {

      FUN_0049a030(puVar9[3]);

    }

    (*DAT_005dd290)();

    (*DAT_005dd31c)();

    (*DAT_005dd344)();

    puVar9 = &DAT_0059ce38;

    for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {

      *puVar9 = 0;

      puVar9 = puVar9 + 1;

    }

    DAT_0059cdb0 = 0;

    DAT_0059ce4c = 0x3d23d70a;

    _DAT_0059ce50 = 0x40a00000;

    _DAT_0059cdb4 = 0;

    uVar2 = AudioDataStreamStatus__Fv_3();

    main_status_00500520(uVar2);

    FUN_005155c0();

    FUN_00446ee0();

    auStack_80[0] = 0;

    pcVar4 = param_1;

    if (DAT_006330e4 == 0) {

LAB_00446783:

      crt_sprintf(auStack_80,s_flk__s_bin_005585d8,pcVar4);

    }

    else {

      iVar7 = 0;

      iVar6 = 0;

      do {

        iVar5 = match(param_1,iVar6 + 0x210 + DAT_006330e4);

        if (iVar5 != 0) {

          pcVar4 = (char *)(iVar7 * 0x20 + 0x210 + DAT_006330e4);

          goto LAB_00446783;

        }

        iVar6 = iVar6 + 0x20;

        iVar7 = iVar7 + 1;

      } while (iVar6 < 0x1000);

    }

    iVar6 = stream_player_start(auStack_80);

    if (iVar6 != 0) {

      BinFileRead(iVar6,asStack_98,0x18);

      psVar3 = _malloc(asStack_98[1]);

      psVar8 = asStack_98;

      psVar10 = psVar3;

      for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {

        *psVar10 = *psVar8;

        psVar8 = psVar8 + 1;

        psVar10 = psVar10 + 1;

      }

      BinFileRead(iVar6,psVar3 + 6,asStack_98[1] - 0x18);

      ANM_BinderDestroy_2(iVar6);

      pcVar4 = param_1;

      do {

        cVar1 = *pcVar4;

        pcVar4[(int)&DAT_0059cdb8 - (int)param_1] = cVar1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      if (DAT_006330e4 != 0) {

        iVar6 = 0;

        iVar7 = 0;

        do {

          iVar5 = match(param_1,iVar7 + 0x210 + DAT_006330e4);

          if (iVar5 != 0) goto LAB_00446830;

          iVar7 = iVar7 + 0x20;

          iVar6 = iVar6 + 1;

        } while (iVar7 < 0x1000);

      }

      iVar6 = -1;

LAB_00446830:

      DAT_0059ce54 = flick_file_load(psVar3,iVar6,param_1,0,0,0,DAT_00656468);

      if (DAT_0059ce54 != 0) {

        DAT_005585b4 = 0;

      }

    }

    if (DAT_00633248 != 0) {

      FUN_00450aa0();

    }

  }

  return DAT_005585b4;

}

/* ===== flick_objects_reload @ 0x00446890 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int flick_objects_reload(void)



{

  undefined4 *puVar1;

  

  if (DAT_0059ce54 != 0) {

    if (DAT_005585b4 == 0) {

      if ((DAT_00632aa4._3_1_ == '\0') || (DAT_00632c0c != 0)) {

        DAT_005585b4 = FLK_FlickProcess(DAT_0059ce54);

        if (DAT_005585b4 == 0) {

          FLK_FlickRender(DAT_0059ce54);

        }

        else {

          if (DAT_0059ce54 == 0) {

            return DAT_005585b4;

          }

          if (*(int *)(DAT_0059ce54 + 0x13c) != 0) {

            DAT_005585b4 = 0;

          }

        }

      }

      else {

        DAT_00632aa4._3_1_ = '\0';

        (*DAT_005dd360)();

        if (DAT_0059ce54 == 0) {

          return DAT_005585b4;

        }

        while (DAT_005585b4 == 0) {

          DAT_005585b4 = 1;

          DAT_005585b4 = flick_objects_reload();

        }

      }

    }

    if ((DAT_0059ce54 != 0) && (DAT_005585b4 != 0)) {

      if (DAT_0059cdb0 != 0) {

        _DAT_0059cdb4 = _DAT_0059cdb4 + *(float *)(DAT_0059ce54 + 0xb0);

      }

      mission_00447fd0(0,4);

      for (puVar1 = DAT_00632d84; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

        object_destroy(puVar1[3]);

      }

      FUN_005155c0();

      object_list_update();

      DAT_0059ce54 = main_flick_00443740(DAT_0059ce54);

      if (DAT_0059ce54 != 0) {

        DAT_005585b4 = 0;

        return 0;

      }

      (*DAT_005dd290)();

    }

  }

  return DAT_005585b4;

}

/* ===== FUN_004469e0 @ 0x004469E0 ===== */
/* PS2 candidate: FLK_FlickPlaying (conf 0.33) */



undefined4 FUN_004469e0(void)



{

  if ((DAT_0059ce54 != 0) && (DAT_005585b4 == 0)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_00446a00 @ 0x00446A00 ===== */
undefined4 * FUN_00446a00(undefined4 param_1,char *param_2)



{

  int iVar1;

  char cVar2;

  undefined4 uVar3;

  undefined4 *puVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  

  uVar3 = FUN_0053feb0(0,0);

  puVar4 = (undefined4 *)FUN_0053ffa0(uVar3,0x110,1);

  if (puVar4 != (undefined4 *)0x0) {

    *puVar4 = uVar3;

    puVar4[1] = 0;

    puVar4[0x43] = 0;

    puVar4[2] = 0x42000000;

    iVar8 = 0x100;

    do {

      iVar7 = iVar8 + -1;

      iVar5 = crt_lock_simple(iVar7);

      iVar6 = 0;

      cVar2 = *param_2;

      while ((cVar2 != '\0' && (cVar2 != iVar5))) {

        iVar1 = iVar6 + 1;

        iVar6 = iVar6 + 1;

        cVar2 = param_2[iVar1];

      }

      if (param_2[iVar6] == '\0') {

        *(undefined1 *)(iVar8 + 0xb + (int)puVar4) = 2;

      }

      else {

        *(char *)(iVar8 + 0xb + (int)puVar4) = (char)iVar6;

      }

      iVar8 = iVar7;

    } while (iVar7 != 0);

    return puVar4;

  }

  return (undefined4 *)0x0;

}

/* ===== object_stop_movement @ 0x00446A90 ===== */
/* PS2 candidate: object_stop_movement_2 (conf 0.881) */



void object_stop_movement(undefined4 *param_1)



{

  param_1[3] = 0x3e800000;

  param_1[2] = 0x3e800000;

  param_1[5] = 0x3f000000;

  param_1[4] = 0x3f000000;

  param_1[1] = 0x3f000000;

  *param_1 = 0x3f000000;

  param_1[9] = 0;

  param_1[6] = 0;

  param_1[7] = 0x3f800000;

  param_1[8] = 0x3f800000;

  param_1[10] = 0;

  param_1[0xb] = 0x3f800000;

  param_1[0xc] = 0xffff;

  return;

}

/* ===== FNT_RenderInfoProcess__FP14FNT_RenderInfof @ 0x00446AD0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void FNT_RenderInfoProcess__FP14FNT_RenderInfof(undefined4 *p0,float p1)



{

  float fVar1;

  

  fVar1 = p1 * (float)p0[6] + (float)p0[7];

  p0[7] = fVar1;

  p0[0xb] = (float)p0[0xb] - p1 * (float)p0[10];

  p0[8] = fVar1;

  return;

}

/* ===== FUN_00446b00 @ 0x00446B00 ===== */
void FUN_00446b00(int param_1,float param_2,float param_3,float param_4,float param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  *(float *)(param_1 + 0xc) = param_2;

  *(float *)(param_1 + 0x10) = param_3;

  *(float *)(param_1 + 0x48) = param_3;

  *(float *)(param_1 + 0x44) = param_2 + param_4;

  *(float *)(param_1 + 0xb4) = param_2;

  *(float *)(param_1 + 0x7c) = param_2 + param_4;

  *(float *)(param_1 + 0x80) = param_3 - param_5;

  *(float *)(param_1 + 0xb8) = param_3 - param_5;

  FUN_00516c70(param_1);

  if (*(char *)(param_1 + 0x34) == '\0') {

    FUN_00516cf0(param_1);

  }

  iVar1 = param_1 + 0x38;

  FUN_00516c70(iVar1);

  if (*(char *)(param_1 + 0x6c) == '\0') {

    FUN_00516cf0(iVar1);

  }

  iVar2 = param_1 + 0x70;

  FUN_00516c70(iVar2);

  if (*(char *)(param_1 + 0xa4) == '\0') {

    FUN_00516cf0(iVar2);

  }

  iVar3 = param_1 + 0xa8;

  FUN_00516c70(iVar3);

  if (*(char *)(param_1 + 0xdc) == '\0') {

    FUN_00516cf0(iVar3);

  }

  status_bar_update3(param_1,iVar3,iVar2);

  status_bar_update3(param_1,iVar2,iVar1);

  return;

}

/* ===== FUN_00446be0 @ 0x00446BE0 ===== */
void FUN_00446be0(undefined4 param_1,undefined4 param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float10 fVar3;

  float10 fVar4;

  undefined1 local_10 [16];

  

  XFGetViewport_2(local_10);

  fVar3 = (float10)textrender_draw_min(param_3[3],param_2);

  fVar4 = (float10)crt_fabs(param_3[3],param_2);

  fVar1 = *param_3;

  *param_3 = 0.0;

  param_3[4] = param_3[4] - (float)fVar3 * fVar1;

  fVar1 = param_3[1];

  param_3[1] = 0.0;

  param_3[5] = (float)((float10)param_3[5] - fVar4 * (float10)fVar1);

  fVar1 = param_3[0xb];

  if (0.0 <= fVar1) {

    if (1.0 < fVar1) {

      fVar1 = 1.0;

    }

  }

  else {

    fVar1 = 0.0;

  }

  fVar2 = param_3[8];

  if (0.0 <= fVar2) {

    if (1.0 < fVar2) {

      fVar2 = 1.0;

    }

  }

  else {

    fVar2 = 0.0;

  }

  textrender_draw_small(param_3[0xc],1.0 - fVar2 * fVar1,param_3[3],param_3[4],param_3[5],param_2);

  param_3[8] = param_3[9] + param_3[8];

  param_3[4] = (float)fVar3 + param_3[4];

  return;

}

/* ===== FUN_00446ce0 @ 0x00446CE0 ===== */
void FUN_00446ce0(undefined4 param_1,char *param_2,float *param_3)



{

  int iVar1;

  float fVar2;

  char cVar3;

  byte bVar4;

  int iVar5;

  float *pfVar6;

  float *pfVar7;

  float10 fVar8;

  float10 fVar9;

  float local_34 [4];

  float local_24;

  

  pfVar6 = param_3;

  pfVar7 = local_34;

  for (iVar5 = 0xd; iVar5 != 0; iVar5 = iVar5 + -1) {

    *pfVar7 = *pfVar6;

    pfVar6 = pfVar6 + 1;

    pfVar7 = pfVar7 + 1;

  }

  iVar5 = 0;

  if (param_2 != (char *)0x0) {

    fVar8 = (float10)textrender_draw_large(param_3[3],param_2);

    fVar9 = (float10)FUN_0051bea0(param_3[3],param_2);

    fVar2 = *param_3;

    *param_3 = 0.0;

    param_3[4] = param_3[4] - (float)fVar8 * fVar2;

    fVar2 = param_3[1];

    param_3[1] = 0.0;

    param_3[5] = param_3[5] - (float)fVar9 * fVar2;

    cVar3 = *param_2;

    while (cVar3 != '\0') {

      bVar4 = param_2[iVar5];

      if (bVar4 == 10) {

        param_3[4] = local_24;

        param_3[5] = param_3[3] + param_3[5];

        *param_3 = local_34[0];

        fVar8 = (float10)textrender_draw_large(param_3[3],param_2 + iVar5 + 1);

        if (fVar8 != (float10)0.0) {

          fVar2 = *param_3;

          *param_3 = 0.0;

          param_3[4] = (float)((float10)param_3[4] - fVar8 * (float10)fVar2);

          fVar2 = param_3[1];

          param_3[1] = 0.0;

          param_3[5] = param_3[5] - (float)fVar9 * fVar2;

        }

      }

      else if (0x1f < bVar4) {

        FUN_00446be0(param_1,bVar4,param_3);

      }

      iVar1 = iVar5 + 1;

      iVar5 = iVar5 + 1;

      cVar3 = param_2[iVar1];

    }

  }

  return;

}

/* ===== map_chunk_destroy @ 0x00446DF0 ===== */
void map_chunk_destroy(int param_1,float param_2)



{

  int *piVar1;

  undefined4 *puVar2;

  int iVar3;

  float fVar4;

  int iVar5;

  int *piVar6;

  int *piVar7;

  int *piVar8;

  int *piVar9;

  int local_34 [4];

  int local_24;

  int local_20;

  

  puVar2 = *(undefined4 **)(param_1 + 0xc);

  piVar6 = (int *)((puVar2 == (undefined4 *)(param_1 + 0xcU)) - 1 & (uint)puVar2);

  piVar7 = (int *)*puVar2;

  if (piVar6 != (int *)0x0) {

    while( true ) {

      piVar1 = piVar6 + 2;

      fVar4 = param_2 * (float)piVar6[8] + (float)piVar6[9];

      piVar6[9] = (int)fVar4;

      piVar6[0xd] = (int)((float)piVar6[0xd] - param_2 * (float)piVar6[0xc]);

      piVar6[10] = (int)fVar4;

      if ((float)piVar6[0xd] <= 0.0) {

        if (piVar6[0x10] != 0) {

          *(int *)piVar6[1] = *piVar6;

          *(int *)(*piVar6 + 4) = piVar6[1];

          *piVar6 = (int)piVar6;

          piVar6[1] = (int)piVar6;

          MAP_ChunkDestroy(piVar6,*(undefined4 *)(param_1 + 4));

        }

      }

      else {

        iVar3 = piVar6[0xf];

        piVar8 = piVar1;

        piVar9 = local_34;

        for (iVar5 = 0xd; iVar5 != 0; iVar5 = iVar5 + -1) {

          *piVar9 = *piVar8;

          piVar8 = piVar8 + 1;

          piVar9 = piVar9 + 1;

        }

        FUN_00446ce0(*(undefined4 *)(param_1 + 8),iVar3,piVar1);

        piVar6[6] = local_24;

        piVar6[7] = local_20;

        *piVar1 = local_34[0];

        piVar6[3] = local_34[1];

      }

      if (piVar7 == (int *)(param_1 + 0xc)) break;

      piVar6 = piVar7;

      piVar7 = (int *)*piVar7;

    }

  }

  return;

}

/* ===== FUN_00446ee0 @ 0x00446EE0 ===== */
/* PS2 candidate: texture_object_debug_dump (conf 0.333) */



void FUN_00446ee0(void)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 uVar3;

  undefined4 *puVar4;

  

  if (DAT_00656468 == 0) {

    DAT_00656468 = FUN_00446a00(s_GiantFont_Eng_00558828,s________________0123456789__<_>___005587e8

                               );

  }

  iVar2 = DAT_00656468;

  if (DAT_00656464 == (undefined4 *)0x0) {

    uVar3 = FUN_0053feb0(0,0);

    puVar4 = (undefined4 *)FUN_0053ffa0(uVar3,0x14,1);

    *puVar4 = uVar3;

    uVar3 = MAP_ChunkPoolCreate(uVar3,0x10,0x44);

    puVar4[1] = uVar3;

    puVar1 = puVar4 + 3;

    puVar4[2] = iVar2;

    puVar4[4] = puVar1;

    *puVar1 = puVar1;

    DAT_00656464 = puVar4;

  }

  return;

}

/* ===== SetupCameraHail__Fv @ 0x00446F50 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void SetupCameraHail__Fv(void)



{

  map_chunk_destroy(DAT_00656464,DAT_006328e0);

  return;

}

/* ===== FUN_00446f70 @ 0x00446F70 ===== */
void FUN_00446f70(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,

                 float param_6,int param_7)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  int local_34 [5];

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  float local_8;

  undefined4 local_4;

  

  iVar1 = DAT_00656464;

  local_34[4] = param_2;

  local_34[1] = param_5;

  local_20 = param_3;

  local_34[2] = 0x3d19999a;

  local_34[3] = 0x3d19999a;

  local_34[0] = param_4;

  local_1c = 0x40400000;

  local_18 = 0;

  local_14 = 0;

  local_10 = 0xbe4ccccd;

  if (param_6 == 0.0) {

    local_c = 0;

    local_8 = 1.0;

  }

  else {

    local_c = 0x40400000;

    local_8 = param_6 * 3.0 + 1.0;

  }

  local_4 = 0xffff;

  piVar2 = (int *)FUN_005401e0(*(undefined4 *)(DAT_00656464 + 4));

  piVar4 = local_34;

  piVar5 = piVar2 + 2;

  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {

    *piVar5 = *piVar4;

    piVar4 = piVar4 + 1;

    piVar5 = piVar5 + 1;

  }

  piVar2[1] = (int)piVar2;

  piVar2[0xf] = param_1;

  piVar2[0x10] = param_7;

  *piVar2 = (int)piVar2;

  piVar2[1] = *(int *)(iVar1 + 0x10);

  *piVar2 = iVar1 + 0xc;

  *(int **)(iVar1 + 0x10) = piVar2;

  *(int **)piVar2[1] = piVar2;

  return;

}

/* ===== FUN_00447060 @ 0x00447060 ===== */
void FUN_00447060(void)



{

  if (DAT_00656464 != (undefined4 *)0x0) {

    map_alloc_cleanup(*DAT_00656464);

    DAT_00656464 = (undefined4 *)0x0;

  }

  if (DAT_00656468 != (undefined4 *)0x0) {

    map_alloc_cleanup(*DAT_00656468);

    DAT_00656468 = (undefined4 *)0x0;

  }

  return;

}

/* ===== AudioGetMasterVolume__Fv_3 @ 0x004470A0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioGetMasterVolume__Fv_3(void)



{

  return DAT_00656468;

}

/* ===== dialog_level_is_base_8 @ 0x00447190 ===== */
bool dialog_level_is_base_8(void)



{

  return DAT_0059ce6c == 0;

}

/* ===== Main/fx_00447210 @ 0x00447210 ===== */
undefined4 Main_fx_00447210(undefined4 param_1)



{

  undefined4 uVar1;

  char *pcVar2;

  char *pcVar3;

  int iVar4;

  int iVar5;

  char *pcVar6;

  

  iVar5 = 0;

  pcVar2 = DAT_0059ce6c;

  pcVar6 = DAT_0059ce6c;

  if (0 < DAT_0059ce60) {

    do {

      do {

        pcVar3 = pcVar2;

        pcVar2 = pcVar3 + 1;

      } while (*pcVar3 != '\0');

      uVar1 = *(undefined4 *)(pcVar3 + 1);

      iVar4 = FUN_00545650(pcVar6,param_1);

      if (iVar4 == 0) {

        return uVar1;

      }

      iVar5 = iVar5 + 1;

      pcVar2 = pcVar3 + 5;

      pcVar6 = pcVar3 + 5;

    } while (iVar5 < DAT_0059ce60);

  }

  return 0xffffffff;

}

/* ===== fx_weather_fog_setup @ 0x00447370 ===== */
void fx_weather_fog_setup

               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,

               undefined4 param_5)



{

  int iVar1;

  char *pcVar2;

  undefined1 local_200 [512];

  

  if (param_1 == 0) {

    pcVar2 = s_Failed_to_setup_weather_fog_for_f_005589f0;

  }

  else {

    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x100);

    if ((*(byte *)(*(int *)(param_1 + 4) + 0xe4) & 1) != 0) {

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x3c) = *(undefined4 *)(DAT_006330e4 + 0x128);

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x44) = *(undefined4 *)(DAT_006330e4 + 300);

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x2c) = *(undefined4 *)(DAT_006330e4 + 0x130);

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x30) = *(undefined4 *)(DAT_006330e4 + 0x134);

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x34) = *(undefined4 *)(DAT_006330e4 + 0x138);

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x38) = param_2;

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x40) = param_3;

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x20) = *param_4;

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x24) = param_4[1];

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x28) = param_4[2];

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x48) = param_5;

      *(uint *)(*(int *)(param_1 + 4) + 0xe4) = *(uint *)(*(int *)(param_1 + 4) + 0xe4) | 8;

      return;

    }

    pcVar2 = s_Failed_to_setup_weather_fog_for_f_00558a30;

  }

  crt_sprintf(local_200,pcVar2,DAT_0059ce5c + 0x20);

  FUN_0051ea20(local_200);

  return;

}

/* ===== fx_weather_fogsky_setup @ 0x004474C0 ===== */
void fx_weather_fogsky_setup

               (int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,

               undefined4 *param_5,undefined4 param_6)



{

  int iVar1;

  char *pcVar2;

  undefined1 local_200 [512];

  

  if (param_1 == 0) {

    pcVar2 = s_Failed_to_setup_weather_fog_sky_f_00558b20;

  }

  else {

    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x100);

    if ((*(byte *)(*(int *)(param_1 + 4) + 0xe4) & 1) != 0) {

      *(undefined4 *)(DAT_006330e4 + 0x15c) = *param_3;

      *(undefined4 *)(DAT_006330e4 + 0x160) = param_3[1];

      *(undefined4 *)(DAT_006330e4 + 0x164) = param_3[2];

      *(undefined4 *)(DAT_006330e4 + 0x158) = param_2;

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x68) = param_2;

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x58) = *param_3;

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x5c) = param_3[1];

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x60) = param_3[2];

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 100) = param_4;

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x4c) = *param_5;

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x50) = param_5[1];

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x54) = param_5[2];

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x6c) = param_6;

      *(int *)(DAT_006330e4 + 0x16c) = *(int *)(DAT_006330e4 + 0x16c) + 1;

      *(uint *)(*(int *)(param_1 + 4) + 0xe4) = *(uint *)(*(int *)(param_1 + 4) + 0xe4) | 0x20;

      return;

    }

    pcVar2 = s_Failed_to_setup_weather_fog_sky_f_00558b60;

  }

  crt_sprintf(local_200,pcVar2,DAT_0059ce5c + 0x20);

  FUN_0051ea20(local_200);

  return;

}

/* ===== fx_weather_fog_setup2 @ 0x00447620 ===== */
void fx_weather_fog_setup2

               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,

               undefined4 param_5)



{

  int iVar1;

  char *pcVar2;

  undefined1 local_200 [512];

  

  if (param_1 == 0) {

    pcVar2 = s_Failed_to_setup_weather_fog_for_f_005589f0;

  }

  else {

    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x100);

    if ((*(byte *)(*(int *)(param_1 + 4) + 0xe4) & 1) != 0) {

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x8c) = *(undefined4 *)(DAT_006330e4 + 0x140);

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x94) = *(undefined4 *)(DAT_006330e4 + 0x144);

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x7c) = *(undefined4 *)(DAT_006330e4 + 0x148);

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x80) = *(undefined4 *)(DAT_006330e4 + 0x14c);

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x84) = *(undefined4 *)(DAT_006330e4 + 0x150);

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x88) = param_2;

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x90) = param_3;

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x70) = *param_4;

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x74) = param_4[1];

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x78) = param_4[2];

      *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x98) = param_5;

      *(uint *)(*(int *)(param_1 + 4) + 0xe4) = *(uint *)(*(int *)(param_1 + 4) + 0xe4) | 0x80;

      return;

    }

    pcVar2 = s_Failed_to_setup_weather_fog_for_f_00558a30;

  }

  crt_sprintf(local_200,pcVar2,DAT_0059ce5c + 0x20);

  FUN_0051ea20(local_200);

  return;

}

/* ===== object_lock_apply @ 0x00447F20 ===== */
void object_lock_apply(int param_1,byte param_2)



{

  int iVar1;

  undefined4 *puVar2;

  uint uVar3;

  

  uVar3 = 0;

  if ((param_2 & 2) != 0) {

    uVar3 = 0x400;

  }

  puVar2 = DAT_00632d68;

  if ((param_2 & 4) != 0) {

    uVar3 = uVar3 | 0x1000;

  }

  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    if (((*(int *)(iVar1 + 0x1e0) == 0x4e) && ((*(uint *)(iVar1 + 0xd8) & 0xc000) == 0)) &&

       ((param_1 != 0 || ((*(uint *)(iVar1 + 0xe4) & uVar3) != 0)))) {

      *(uint *)(iVar1 + 0xd8) = *(uint *)(iVar1 + 0xd8) & 0xffffffbf;

      FUN_004a6420(iVar1);

      object_apply_location(iVar1);

      object_lock_logic(iVar1);

    }

  }

  return;

}

/* ===== Main/fx_00447fa0 @ 0x00447FA0 ===== */
bool Main_fx_00447fa0(int param_1,byte param_2)



{

  uint uVar1;

  

  uVar1 = 0;

  if ((param_2 & 2) != 0) {

    uVar1 = 0x400;

  }

  if ((param_2 & 4) != 0) {

    uVar1 = uVar1 | 0x1000;

  }

  return (*(uint *)(param_1 + 0xe4) & uVar1) != 0;

}

/* ===== mission_00447fd0 @ 0x00447FD0 ===== */
void mission_00447fd0(int param_1,uint param_2)



{

  int iVar1;

  undefined4 *puVar2;

  int *piVar3;

  int *piVar4;

  uint uVar5;

  

  uVar5 = 0;

  if ((param_2 & 2) != 0) {

    uVar5 = 0x400;

  }

  puVar2 = DAT_00632d68;

  piVar3 = DAT_0059ce64;

  if ((param_2 & 4) != 0) {

    uVar5 = uVar5 | 0x1000;

  }

  for (; DAT_0059ce64 = piVar3, puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    if ((*(int *)(iVar1 + 0x1e0) == 0x4e) &&

       ((param_1 != 0 || ((*(uint *)(iVar1 + 0xe4) & uVar5) != 0)))) {

      object_destroy(iVar1);

    }

    piVar3 = DAT_0059ce64;

  }

  uVar5 = 0;

  if ((param_2 & 2) != 0) {

    uVar5 = 0x4000;

  }

  if ((param_2 & 4) != 0) {

    uVar5 = uVar5 | 0x8000;

  }

  if ((param_2 & 1) != 0) {

    uVar5 = uVar5 | 0x10000;

  }

  if ((param_2 & 0x10) != 0) {

    uVar5 = uVar5 | 0x200000;

  }

  if (piVar3 != (int *)0x0) {

    do {

      if ((param_1 == 0) && ((piVar3[6] & uVar5) == 0)) {

        piVar4 = (int *)*piVar3;

      }

      else {

        piVar4 = (int *)*piVar3;

        if ((undefined4 *)piVar3[1] == (undefined4 *)0x0) {

          DAT_0059ce64 = piVar4;

          if (piVar4 == (int *)0x0) {

            DAT_0059ce58 = (undefined4 *)0x0;

          }

          else {

            piVar4[1] = 0;

          }

          *piVar3 = (int)DAT_0059ce70;

          piVar4 = DAT_0059ce64;

          DAT_0059ce70 = piVar3;

        }

        else {

          if (piVar4 == (int *)0x0) {

            DAT_0059ce58 = (undefined4 *)piVar3[1];

            *DAT_0059ce58 = 0;

            *piVar3 = (int)DAT_0059ce70;

            DAT_0059ce70 = piVar3;

            return;

          }

          *(undefined4 *)piVar3[1] = piVar4;

          *(int *)(*piVar3 + 4) = piVar3[1];

          piVar4 = (int *)*piVar3;

          *piVar3 = (int)DAT_0059ce70;

          DAT_0059ce70 = piVar3;

        }

      }

      piVar3 = piVar4;

    } while (piVar4 != (int *)0x0);

    return;

  }

  return;

}

/* ===== alpha_queue_push_2 @ 0x00448100 ===== */
void alpha_queue_push_2(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  for (puVar2 = DAT_00632d68; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    if ((((*(int *)(iVar1 + 0x1e0) == 0x4e) && (-1 < (char)(*(uint *)(iVar1 + 0xd8) >> 8))) &&

        ((*(uint *)(iVar1 + 0xe4) & 2) != 0)) && ((*(uint *)(iVar1 + 0xe4) & 0x400) == 0)) {

      *(uint *)(iVar1 + 0xd8) = *(uint *)(iVar1 + 0xd8) & 0xbfffffff;

      alpha_queue_push(iVar1);

      *(uint *)(iVar1 + 0xd8) = *(uint *)(iVar1 + 0xd8) | 0x40000000;

    }

  }

  return;

}

/* ===== alpha_queue_push_3 @ 0x00448170 ===== */
void alpha_queue_push_3(int param_1,byte param_2)



{

  int iVar1;

  undefined4 *puVar2;

  uint uVar3;

  

  uVar3 = 0;

  if ((param_2 & 2) != 0) {

    uVar3 = 0x400;

  }

  puVar2 = DAT_00632d68;

  if ((param_2 & 4) != 0) {

    uVar3 = uVar3 | 0x1000;

  }

  do {

    if (puVar2 == (undefined4 *)0x0) {

      return;

    }

    iVar1 = puVar2[3];

    if ((*(int *)(iVar1 + 0x1e0) == 0x4e) && (-1 < (char)((uint)*(undefined4 *)(iVar1 + 0xd8) >> 8))

       ) {

      if (param_1 == 0) {

        if ((uVar3 & *(uint *)(iVar1 + 0xe4)) != 0) goto LAB_004481cb;

      }

      else if ((*(uint *)(iVar1 + 0xe4) & 0x400) == 0) {

LAB_004481cb:

        alpha_queue_push(iVar1);

      }

    }

    puVar2 = (undefined4 *)*puVar2;

  } while( true );

}

/* ===== FUN_00448750 @ 0x00448750 ===== */
/* PS2 candidate: fxobj_delete__FP6OBJECTP7FxOspeci (conf 0.376) */



void FUN_00448750(int param_1,int param_2,int param_3)



{

  uint *puVar1;

  float fVar2;

  uint uVar3;

  float10 fVar4;

  float local_40;

  float local_3c;

  float local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  uint local_24;

  

  if ((param_3 != 0) && ((*(byte *)(param_1 + 0xe0) & 1) != 0)) {

    uVar3 = *(uint *)(param_1 + 0xe4);

    local_24 = 0;

    if ((uVar3 & 0x400) != 0) {

      local_24 = 2;

    }

    if ((uVar3 & 0x1000) != 0) {

      local_24 = local_24 | 4;

    }

    if ((*(uint *)(param_1 + 0xd8) & 0x400) != 0) {

      local_24 = local_24 | 1;

    }

    if ((uVar3 & 0x100000) != 0) {

      local_24 = local_24 | 0x10;

    }

    local_30 = *(undefined4 *)(param_1 + 0xa0);

    local_2c = *(undefined4 *)(param_1 + 0xa4);

    local_28 = *(undefined4 *)(param_1 + 0xa8);

    local_34 = *(undefined4 *)(param_1 + 0x174);

    fx_get_free_effect__Fv();

  }

  if ((*(uint *)(param_1 + 0xe4) & 2) == 0) {

    if (*(int *)(param_1 + 0xe8) != 0) {

      sound_interrupt_sequence(param_1 + 0xe8);

    }

    if (*(int *)(param_2 + 0x108) != 0) {

      sound_stop_player(*(int *)(param_2 + 0x108),param_1);

    }

  }

  else if (((*(uint *)(param_1 + 0xe4) & 4) == 0) ||

          (fVar2 = *(float *)(*(int *)(param_2 + 0x100) + 8), fVar2 < 0.0 == (fVar2 == 0.0))) {

    XFGetViewport(&local_40);

    fVar4 = (float10)rndfloatrange(-**(float **)(param_2 + 0x100),**(float **)(param_2 + 0x100));

    local_40 = (float)(fVar4 + (float10)local_40);

    fVar4 = (float10)rndfloatrange(-**(float **)(param_2 + 0x100),**(float **)(param_2 + 0x100));

    puVar1 = (uint *)(param_1 + 0x294);

    local_3c = (float)(fVar4 + (float10)local_3c);

    local_38 = local_38 + *(float *)(*(int *)(param_2 + 0x100) + 4);

    FUN_0053d9e0(puVar1);

    *(float *)(param_1 + 0x2a4) = local_40;

    *puVar1 = *puVar1 | 0x10;

    *(float *)(param_1 + 0x2b4) = local_3c;

    *(float *)(param_1 + 0x2c4) = local_38;

    object_set_location_p3d(param_1,&local_40);

    *(undefined4 *)(param_2 + 8) = 0;

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000000;

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x2e0;

    return;

  }

  object_destroy(param_1);

  return;

}

/* ===== fx_delete @ 0x00448920 ===== */
/* PS2 candidate: fx_delete (conf 0.536) */



void fx_delete(int *param_1)



{

  int *piVar1;

  undefined4 *puVar2;

  

  if (param_1 != (int *)0x0) {

    for (puVar2 = DAT_00632da0; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

      piVar1 = *(int **)(puVar2[3] + 0x100);

      if ((int *)*piVar1 == param_1 + 2) {

        FUN_00448750(puVar2[3],piVar1,1);

      }

    }

    piVar1 = (int *)param_1[1];

    if (piVar1 == (int *)0x0) {

      DAT_0059ce64 = *param_1;

      if (DAT_0059ce64 != 0) {

        *(undefined4 *)(DAT_0059ce64 + 4) = 0;

        *param_1 = (int)DAT_0059ce70;

        DAT_0059ce70 = param_1;

        return;

      }

      DAT_0059ce58 = (int *)0x0;

      *param_1 = (int)DAT_0059ce70;

      DAT_0059ce70 = param_1;

      return;

    }

    if (*param_1 == 0) {

      DAT_0059ce58 = piVar1;

      *piVar1 = 0;

      *param_1 = (int)DAT_0059ce70;

      DAT_0059ce70 = param_1;

      return;

    }

    *piVar1 = *param_1;

    *(int *)(*param_1 + 4) = param_1[1];

    *param_1 = (int)DAT_0059ce70;

    DAT_0059ce70 = param_1;

  }

  return;

}

/* ===== FUN_004489e0 @ 0x004489E0 ===== */
void FUN_004489e0(int param_1,undefined4 *param_2)



{

  undefined4 *puVar1;

  

  if (param_1 != 0) {

    *(undefined4 *)(param_1 + 0x1c) = *param_2;

    *(undefined4 *)(param_1 + 0x20) = param_2[1];

    *(undefined4 *)(param_1 + 0x24) = param_2[2];

    for (puVar1 = DAT_00632da0; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      if (**(int **)(puVar1[3] + 0x100) == param_1 + 8) {

        object_set_location_p3d(puVar1[3],param_2);

      }

    }

  }

  return;

}

/* ===== fx_lifespan_setup @ 0x00448AF0 ===== */
void fx_lifespan_setup(int param_1,float param_2,float param_3,float param_4)



{

  uint *puVar1;

  int iVar2;

  undefined1 local_200 [512];

  

  if (param_1 == 0) {

    crt_sprintf(local_200,s_Failed_to_set_lifespan_for_fx__s_00558cf4,DAT_0059ce5c + 0x20);

    FUN_0051ea20(local_200);

  }

  else {

    iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x100);

    puVar1 = (uint *)(*(int *)(param_1 + 4) + 0xe0);

    *puVar1 = *puVar1 | 2;

    *(float *)(iVar2 + 4) = param_2;

    *(undefined4 *)(iVar2 + 8) = 0;

    if (0.0 < param_3) {

      *(float *)(*(int *)(param_1 + 4) + 0xec) = param_3;

      puVar1 = (uint *)(*(int *)(param_1 + 4) + 0xe0);

      *puVar1 = *puVar1 | 0x800000;

      *(float *)(*(int *)(param_1 + 4) + 0xf8) = 1.0 / param_3;

      *(undefined4 *)(*(int *)(param_1 + 4) + 0x184) = 0x3f800000;

    }

    if ((0.0 < param_4) && (*(float *)(*(int *)(param_1 + 4) + 0xf0) = param_4, param_4 < param_2))

    {

      *(uint *)(*(int *)(param_1 + 4) + 0xe0) = *(uint *)(*(int *)(param_1 + 4) + 0xe0) | 4;

      *(float *)(*(int *)(param_1 + 4) + 0xf4) = 1.0 / (param_2 - param_4);

      return;

    }

  }

  return;

}

/* ===== FUN_00448c20 @ 0x00448C20 ===== */
void FUN_00448c20(int param_1)



{

  int iVar1;

  uint uVar2;

  undefined4 *puVar3;

  uint uVar4;

  

  if (param_1 != 0) {

    if (*(int *)(param_1 + 0x14) != 4) {

      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x80000;

      return;

    }

    for (puVar3 = DAT_00632da0; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

      iVar1 = puVar3[3];

      if (**(int **)(iVar1 + 0x100) == param_1 + 8) {

        uVar2 = *(uint *)(iVar1 + 0xe0);

        uVar4 = uVar2 | 0x400000;

        *(uint *)(iVar1 + 0xe0) = uVar4;

        if (uVar4 != 0) {

          *(uint *)(iVar1 + 0xe0) = uVar2 & 0xffbfffff;

          fx_processOpCodes(param_1 + 8,0,iVar1);

        }

      }

    }

    *(undefined4 *)(param_1 + 0x14) = 0;

  }

  return;

}

/* ===== fx_createGameLockedObj__FP6FxDataiii @ 0x00448CA0 ===== */
/* PS2 candidate: fx_createGameLockedObj__FP6FxDataiii (conf 0.489) */



int fx_createGameLockedObj__FP6FxDataiii

              (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  int *piVar1;

  undefined4 uVar2;

  uint uVar3;

  int iVar4;

  undefined1 local_200 [512];

  

  if ((*(byte *)(param_1 + 0x10) & 4) != 0) {

    iVar4 = object_allocate_type(param_3,0);

    piVar1 = *(int **)(iVar4 + 0x100);

    *(uint *)(iVar4 + 0x1c8) = *(uint *)(iVar4 + 0x1c8) & 0xfffdffff | 0x800;

    *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x10020;

    *piVar1 = param_1;

    uVar2 = *(undefined4 *)(param_1 + 0x3c);

    *(undefined4 *)(iVar4 + 0x214) = param_4;

    *(undefined4 *)(iVar4 + 0x210) = uVar2;

    *(undefined4 *)(iVar4 + 0x218) = *(undefined4 *)(param_1 + 0x40);

    *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x400020;

    *(int **)(iVar4 + 0x104) = piVar1 + 0x28;

    PhysicsExZeroForce(iVar4);

    uVar3 = *(uint *)(iVar4 + 0xd8);

    *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) | 0x20;

    *(undefined4 *)(iVar4 + 0x1e8) = 0x42480000;

    *(uint *)(iVar4 + 0x294) = *(uint *)(iVar4 + 0x294) | 0x10;

    *(uint *)(iVar4 + 0xd8) = uVar3 | 0x40000010;

    if ((*(uint *)(param_1 + 0x10) & 0x4000) != 0) {

      *(uint *)(iVar4 + 0xe4) = *(uint *)(iVar4 + 0xe4) | 0x400;

    }

    if ((char)((uint)*(undefined4 *)(param_1 + 0x10) >> 8) < '\0') {

      *(uint *)(iVar4 + 0xe4) = *(uint *)(iVar4 + 0xe4) | 0x1000;

    }

    if ((*(uint *)(param_1 + 0x10) & 0x10000) != 0) {

      *(uint *)(iVar4 + 0xd8) = uVar3 | 0x40000410;

    }

    object_lock_logic(iVar4);

    *(undefined4 *)(iVar4 + 0xfc) = *(undefined4 *)(param_1 + 8);

    return iVar4;

  }

  crt_sprintf(local_200,s_Failed_to_create_game_locked_obj_005590d8,DAT_0059ce5c + 0x20);

  FUN_0051ea20(local_200);

  return 0;

}

/* ===== fx_createObj__FP6FxDatai @ 0x00448E10 ===== */
/* PS2 candidate: fx_createObj__FP6FxDatai (conf 0.521) */



int fx_createObj__FP6FxDatai(int param_1,undefined4 param_2,int param_3,float param_4,float param_5)



{

  int *piVar1;

  uint uVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int *piVar7;

  float10 fVar8;

  float10 fVar9;

  float fVar10;

  float local_c;

  float local_8;

  undefined4 local_4;

  

  iVar4 = object_allocate_type(param_2,0x80000000);

  if (*(int *)(iVar4 + 0x1e0) != 0x4e) {

    object_change_ospec(iVar4,0x4e);

  }

  piVar1 = *(int **)(iVar4 + 0x100);

  *(uint *)(iVar4 + 0x1c8) = *(uint *)(iVar4 + 0x1c8) | 0x800;

  *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x10020;

  *piVar1 = param_1;

  uVar2 = *(uint *)(param_1 + 0x10);

  if ((uVar2 & 1) == 0) {

    if ((uVar2 & 2) == 0) {

      if ((uVar2 & 4) == 0) {

        if (((uVar2 & 0x200000) == 0) && (param_3 == 0)) {

          FUN_0053d9e0(iVar4 + 0x294);

          *(undefined4 *)(iVar4 + 0x2a4) = *(undefined4 *)(param_1 + 0x14);

          *(undefined4 *)(iVar4 + 0x2b4) = *(undefined4 *)(param_1 + 0x18);

          *(undefined4 *)(iVar4 + 0x2c4) = *(undefined4 *)(param_1 + 0x1c);

          object_set_location(iVar4,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),

                              *(undefined4 *)(param_1 + 0x1c));

        }

        else {

          FUN_0053d9e0(iVar4 + 0x294);

          XFGetViewport(&local_c);

          if (param_3 == 0) {

            fVar8 = (float10)rndfloatrange(-*(float *)(param_1 + 0x14),

                                           *(undefined4 *)(param_1 + 0x14));

            fVar8 = fVar8 + (float10)local_c;

            param_5 = *(float *)(param_1 + 0x18);

            fVar10 = *(float *)(param_1 + 0x18);

          }

          else {

            fVar8 = (float10)rndfloatrange(-param_4,param_4);

            fVar8 = fVar8 + (float10)local_c;

            fVar10 = param_5;

          }

          local_c = (float)fVar8;

          fVar9 = (float10)rndfloatrange(-param_5,fVar10);

          fVar8 = (float10)local_8;

          local_8 = (float)(fVar9 + fVar8);

          *(float *)(iVar4 + 0x2b4) = (float)(fVar9 + fVar8);

          *(float *)(iVar4 + 0x2a4) = local_c;

          *(undefined4 *)(iVar4 + 0x2c4) = local_4;

          object_set_location(iVar4,local_c,local_8,local_4);

        }

        goto LAB_00449042;

      }

      object_set_location_p3d(iVar4,*(int *)(param_1 + 0x3c) + 0xa0);

      iVar5 = *(int *)(param_1 + 0x3c);

      goto LAB_00448eab;

    }

    *(undefined4 *)(iVar4 + 0x210) = *(undefined4 *)(param_1 + 0x38);

    *(undefined4 *)(iVar4 + 0x214) = *(undefined4 *)(param_1 + 0x30);

    uVar3 = *(undefined4 *)(param_1 + 0x34);

    *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) | 0x40;

    *(undefined4 *)(iVar4 + 0x218) = uVar3;

    *(uint *)(iVar4 + 0xdc) = *(uint *)(iVar4 + 0xdc) | 0x1000;

    uVar2 = *(uint *)(*(int *)(iVar4 + 0x210) + 0xd8);

  }

  else {

    if (*(int *)(param_1 + 0x38) == 0) {

      *(uint *)(param_1 + 0x10) = uVar2 & 0xfffffffe;

      goto LAB_00449042;

    }

    *(int *)(iVar4 + 0x210) = *(int *)(param_1 + 0x38);

    iVar5 = *(int *)(iVar4 + 0x210);

    *(undefined4 *)(iVar4 + 0x214) = *(undefined4 *)(param_1 + 0x30);

    *(undefined4 *)(iVar4 + 0x218) = *(undefined4 *)(param_1 + 0x34);

    *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x400000;

LAB_00448eab:

    uVar2 = *(uint *)(iVar5 + 0xd8);

  }

  if ((uVar2 & 0x400) != 0) {

    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x10000;

  }

LAB_00449042:

  *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) | 0x20;

  *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x40000000;

  *(int **)(iVar4 + 0x104) = piVar1 + 0x28;

  PhysicsExZeroForce(iVar4);

  *(undefined4 *)(iVar4 + 0x1e8) = 0x42480000;

  *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x10;

  if ((*(uint *)(param_1 + 0x10) & 0x1000) != 0) {

    *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) | 0x800;

    piVar6 = (int *)(param_1 + 0x74);

    piVar7 = piVar1 + 0xf;

    for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {

      *piVar7 = *piVar6;

      piVar6 = piVar6 + 1;

      piVar7 = piVar7 + 1;

    }

  }

  if (*(int *)(param_1 + 0xb8) == 0) {

    *(uint *)(iVar4 + 0x1c8) = *(uint *)(iVar4 + 0x1c8) & 0xfffdffff;

  }

  else {

    piVar1[0x37] = *(int *)(param_1 + 0xb8);

    piVar1[0x38] = *(int *)(param_1 + 0xbc);

  }

  *(uint *)(iVar4 + 0x294) = *(uint *)(iVar4 + 0x294) | 0x10;

  if ((*(uint *)(param_1 + 0x10) & 0x4000) != 0) {

    *(uint *)(iVar4 + 0xe4) = *(uint *)(iVar4 + 0xe4) | 0x400;

  }

  if ((char)((uint)*(undefined4 *)(param_1 + 0x10) >> 8) < '\0') {

    *(uint *)(iVar4 + 0xe4) = *(uint *)(iVar4 + 0xe4) | 0x1000;

  }

  if ((*(uint *)(param_1 + 0x10) & 0x10000) != 0) {

    *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x400;

  }

  if ((*(uint *)(param_1 + 0x10) & 0x200000) != 0) {

    *(uint *)(iVar4 + 0xe4) = *(uint *)(iVar4 + 0xe4) | 0x100000;

  }

  *(undefined4 *)(iVar4 + 0xfc) = *(undefined4 *)(param_1 + 8);

  return iVar4;

}

/* ===== fx_alloc_effect @ 0x00449150 ===== */
/* PS2 candidate: fx_refLock__FP6OBJECTiiiiP7GEO_Mati (conf 0.407) */



int fx_alloc_effect(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                   int param_5,undefined4 *param_6)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  

  iVar2 = fx_get_free_effect__Fv();

  if (param_5 == 0) {

    uVar1 = *(uint *)(iVar2 + 0x18);

    *(uint *)(iVar2 + 0x18) = uVar1 | 2;

    if (param_6 != (undefined4 *)0x0) {

      *(uint *)(iVar2 + 0x18) = uVar1 | 0x1002;

      puVar4 = (undefined4 *)(iVar2 + 0x7c);

      for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar4 = *param_6;

        param_6 = param_6 + 1;

        puVar4 = puVar4 + 1;

      }

    }

  }

  else {

    *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) | 1;

  }

  *(undefined4 *)(iVar2 + 0x3c) = param_4;

  *(undefined4 *)(iVar2 + 0x38) = param_3;

  *(undefined4 *)(iVar2 + 0x40) = param_1;

  if ((*(byte *)(iVar2 + 0x18) & 2) != 0) {

    fx_process_one(iVar2,0);

  }

  return iVar2;

}

/* ===== fx_orient_ground @ 0x00449200 ===== */
void fx_orient_ground(int param_1,float param_2)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float local_364;

  undefined4 local_354;

  undefined4 local_350;

  undefined4 local_34c;

  float local_348;

  float local_344;

  float local_340;

  float local_33c;

  float local_338;

  float local_32c;

  float local_328;

  float local_324;

  undefined1 local_320 [16];

  undefined1 local_310 [12];

  undefined4 local_304;

  undefined4 local_2f4;

  undefined4 local_2e4;

  undefined1 local_2cc [68];

  undefined1 local_288 [68];

  undefined1 local_244 [68];

  undefined1 local_200 [512];

  

  if (param_1 != 0) {

    FUN_00414690(*(int *)(param_1 + 4) + 0xa0,&local_348);

    iVar1 = *(int *)(param_1 + 4);

    fVar2 = *(float *)(iVar1 + 0xa4);

    fVar3 = *(float *)(iVar1 + 0xa0);

    local_364 = 1.0 - (local_348 * fVar3 + local_344 * fVar2 + local_340 * local_338 + local_33c);

    if (0.0 <= local_364) {

      if (1.0 < local_364) {

        local_364 = 1.0;

      }

    }

    else {

      local_364 = 0.0;

    }

    local_328 = local_344;

    local_32c = local_348;

    local_324 = local_340;

    FUN_0053dbb0(local_288,local_310,iVar1 + 0x294);

    local_354 = local_304;

    local_350 = local_2f4;

    local_34c = local_2e4;

    GEO_Vec3Normalize(&local_354,&local_354);

    FUN_0053fb40(local_320,&local_354,&local_32c,local_364);

    quat_to_matrix__FP4QUATPf(local_2cc,local_320);

    (*(code *)PTR_crt_matrix_mul_00580c18)(local_244,local_2cc,local_310);

    (*(code *)PTR_crt_matrix_mul_00580c18)(*(int *)(param_1 + 4) + 0x294,local_288,local_244);

    object_set_location(*(undefined4 *)(param_1 + 4),fVar3,fVar2,local_338 + param_2);

    *(float *)(*(int *)(param_1 + 4) + 0x2a4) = fVar3;

    *(float *)(*(int *)(param_1 + 4) + 0x2b4) = fVar2;

    *(float *)(*(int *)(param_1 + 4) + 0x2c4) = local_338 + param_2;

    return;

  }

  crt_sprintf(local_200,s_Failed_to_orient_ground_for_fx___005591c4,DAT_0059ce5c + 0x20);

  FUN_0051ea20(local_200);

  return;

}

/* ===== fx_setupTracerRGB__FP10FXSTACKTAGPfT1 @ 0x00449800 ===== */
/* PS2 candidate: _vfprintf_r (conf 0.333) */



void fx_setupTracerRGB__FP10FXSTACKTAGPfT1(int param_1,undefined4 *param_2,undefined4 *param_3)



{

  int iVar1;

  undefined1 local_200 [512];

  

  if (param_1 == 0) {

    crt_sprintf(local_200,s_Failed_to_setup_tracer_rgb_fadin_005598c0,DAT_0059ce5c + 0x20);

    FUN_0051ea20(local_200);

  }

  else {

    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x100);

    if ((*(int **)(iVar1 + 0xf8) == (int *)0x0) || (**(int **)(iVar1 + 0xf8) == 0)) {

      fx_setupTracer__FP10FXSTACKTAG(param_1);

    }

    if (**(int **)(iVar1 + 0xf8) != 0) {

      *(undefined4 *)(**(int **)(iVar1 + 0xf8) + 0x20) = *param_2;

      *(undefined4 *)(**(int **)(iVar1 + 0xf8) + 0x24) = param_2[1];

      *(undefined4 *)(**(int **)(iVar1 + 0xf8) + 0x28) = param_2[2];

      *(undefined4 *)(**(int **)(iVar1 + 0xf8) + 0x2c) = *param_3;

      *(undefined4 *)(**(int **)(iVar1 + 0xf8) + 0x30) = param_3[1];

      *(undefined4 *)(**(int **)(iVar1 + 0xf8) + 0x34) = param_3[2];

      return;

    }

  }

  return;

}

/* ===== fx_processOpCodes @ 0x00449CE0 ===== */
/* WARNING: Removing unreachable block (ram,0x0044aa26) */

/* WARNING: Removing unreachable block (ram,0x0044a94f) */

/* PS2 candidate: fx_processOpCodes__FP6FxDataiP6OBJECT (conf 0.69) */



undefined4 fx_processOpCodes(void)



{

  char cVar1;

  int *piVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  bool bVar5;

  bool bVar6;

  char *pcVar7;

  undefined4 *puVar8;

  int *piVar9;

  int iVar10;

  char *pcVar11;

  int iVar12;

  int iVar13;

  undefined4 uVar14;

  float fVar15;

  uint uVar16;

  float fVar17;

  float *pfVar18;

  float *pfVar19;

  float10 fVar20;

  float10 fVar21;

  float10 fVar22;

  int iStack00000008;

  int *piStack0000000c;

  undefined4 *puStack00000014;

  int in_stack_0000001c;

  undefined4 *puStack0000003c;

  undefined4 uStack0000008c;

  undefined4 in_stack_0000032c;

  int *in_stack_0000d770;

  int in_stack_0000d774;

  int in_stack_0000d778;

  

  FUN_00543e00();

  pfVar18 = (float *)*in_stack_0000d770;

  bVar5 = false;

  bVar6 = false;

  uStack0000008c = 0;

  puStack0000003c = (undefined4 *)0x0;

  DAT_0059ce5c = in_stack_0000d770;

  puStack00000014 = puStack0000003c;

  if (in_stack_0000d778 != 0) {

    pfVar18 = *(float **)(*(int *)(in_stack_0000d778 + 0x100) + 0x9c);

    puStack0000003c = (undefined4 *)MemAllocMsg();

    *puStack0000003c = 0;

    puStack0000003c[1] = in_stack_0000d778;

    puStack00000014 = puStack0000003c;

  }

  do {

    pfVar19 = (float *)((int)pfVar18 + 1);

    switch(*(undefined1 *)pfVar18) {

    case 2:

      bVar6 = true;

      uStack0000008c = 1;

      break;

    case 3:

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        in_stack_0000001c = fx_createObj__FP6FxDatai();

      }

      break;

    case 4:

      pfVar19 = (float *)((int)pfVar18 + 0xd);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_lifespan_setup();

      }

      break;

    case 5:

      if (*(float *)((int)pfVar18 + 5) < *pfVar19) {

        crt_sprintf();

        FUN_0051ea20();

      }

      rndfloatrange();

      rndfloatrange();

      pfVar19 = (float *)((int)pfVar18 + 0x19);

      rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_lifespan_setup();

      }

      break;

    case 6:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        puVar8 = puStack0000003c;

        if (in_stack_0000001c != 0) {

          puVar8 = (undefined4 *)MemAllocMsg();

          *puVar8 = 0;

          puVar8[1] = in_stack_0000001c;

          puStack00000014 = puVar8;

          if (puStack0000003c == (undefined4 *)0x0) {

            in_stack_0000001c = 0;

            puStack0000003c = puVar8;

            break;

          }

          *puStack0000003c = puVar8;

        }

        in_stack_0000001c = 0;

        puStack0000003c = puVar8;

      }

      break;

    case 7:

      if (in_stack_0000d774 == 0) {

        if (!bVar5) {

          uVar16 = *(uint *)(puStack0000003c[1] + 0xe0);

          if (((((uVar16 & 2) == 0) && ((in_stack_0000d770[4] & 0x60000U) == 0)) &&

              (*(int *)(puStack0000003c[1] + 0x210) == 0)) && ((uVar16 & 0x600) == 0)) {

            fx_lifespan_setup();

          }

        }

        fx_stackPop__FPP10FXSTACKTAGT0();

        if (in_stack_0000d778 != 0) {

          bVar6 = true;

        }

        bVar5 = false;

        puStack0000003c = puStack00000014;

      }

      break;

    case 8:

      fVar17 = *pfVar19;

      fVar15 = *(float *)((int)pfVar18 + 5);

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          *(float *)(puStack0000003c[1] + 0xc4) = fVar17;

          *(float *)(iVar12 + 0x10) = fVar17;

          *(float *)(iVar12 + 0x14) = fVar15;

          crt_euler_to_quat();

          if (fVar17 != fVar15) {

            *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 8;

          }

        }

      }

      break;

    case 9:

      fVar20 = (float10)rndfloatrange();

      fVar17 = (float)fVar20;

      pfVar19 = (float *)((int)pfVar18 + 0x11);

      fVar20 = (float10)rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          *(float *)(puStack0000003c[1] + 0xc4) = fVar17;

          *(float *)(iVar12 + 0x10) = fVar17;

          *(float *)(iVar12 + 0x14) = (float)fVar20;

          crt_euler_to_quat();

          if (fVar17 != (float)fVar20) {

            *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 8;

          }

        }

      }

      break;

    case 10:

      pcVar7 = (char *)((int)pfVar18 + 5);

      do {

        pcVar11 = pcVar7;

        pcVar7 = pcVar11 + 1;

      } while (*pcVar11 != '\0');

      pfVar19 = (float *)(pcVar11 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          piStack0000000c = DAT_0059ce6c;

          iVar12 = 0;

          if (0 < DAT_0059ce60) {

            do {

              FUN_0044ead0();

              iVar13 = *piStack0000000c;

              iVar10 = FUN_00545650();

              if (iVar10 == 0) {

                if (-1 < iVar13) {

                  fx_alloc_effect();

                }

                break;

              }

              iVar12 = iVar12 + 1;

              piStack0000000c = piStack0000000c + 1;

            } while (iVar12 < DAT_0059ce60);

          }

        }

      }

      break;

    case 0xb:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          in_stack_0000d770[1] = (int)fVar17;

          in_stack_0000d770[3] = 1;

          bVar6 = true;

        }

        else {

          crt_sprintf();

          FUN_0051ea20();

          bVar6 = true;

        }

      }

      break;

    case 0xc:

      pfVar19 = (float *)((int)pfVar18 + 9);

      fVar20 = (float10)rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          in_stack_0000d770[1] = (int)(float)fVar20;

          in_stack_0000d770[3] = 1;

          bVar6 = true;

        }

        else {

          crt_sprintf();

          FUN_0051ea20();

          bVar6 = true;

        }

      }

      break;

    case 0xd:

      do {

        cVar1 = *(char *)pfVar19;

        pfVar19 = (float *)((int)pfVar19 + 1);

      } while (cVar1 != '\0');

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          piStack0000000c = (int *)0x0;

          piVar2 = DAT_0059ce6c;

          if (0 < DAT_0059ce60) {

            do {

              do {

                piVar9 = piVar2;

                piVar2 = (int *)((int)piVar9 + 1);

              } while ((char)*piVar9 != '\0');

              iVar12 = *(int *)((int)piVar9 + 1);

              iVar13 = FUN_00545650();

              if (iVar13 == 0) {

                if (-1 < iVar12) {

                  *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 1;

                  *(int *)(puStack0000003c[1] + 0x174) = iVar12;

                  goto LAB_0044e828;

                }

                break;

              }

              piStack0000000c = (int *)((int)piStack0000000c + 1);

              piVar2 = (int *)((int)piVar9 + 5);

            } while ((int)piStack0000000c < DAT_0059ce60);

          }

          crt_sprintf();

          FUN_0051ea20();

        }

      }

      break;

    case 0xe:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = puStack0000003c[1];

          iVar13 = *(int *)(iVar12 + 0x100);

          *(uint *)(iVar12 + 0xe0) = *(uint *)(iVar12 + 0xe0) | 0x80;

LAB_0044abc9:

          *(float *)(iVar13 + 0xa4) = fVar17;

          *(uint *)(puStack0000003c[1] + 0xd8) = *(uint *)(puStack0000003c[1] + 0xd8) & 0xffffffef;

        }

      }

      break;

    case 0xf:

      pfVar19 = (float *)((int)pfVar18 + 9);

      fVar20 = (float10)rndfloatrange();

      fVar17 = (float)fVar20;

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c != (undefined4 *)0x0) {

          iVar12 = puStack0000003c[1];

          iVar13 = *(int *)(iVar12 + 0x100);

          *(uint *)(iVar12 + 0xe0) = *(uint *)(iVar12 + 0xe0) | 0x80;

          goto LAB_0044abc9;

        }

        crt_sprintf();

        FUN_0051ea20();

      }

      break;

    case 0x10:

      pcVar7 = (char *)((int)pfVar18 + 5);

      do {

        pcVar11 = pcVar7;

        pcVar7 = pcVar11 + 1;

      } while (*pcVar11 != '\0');

      pfVar19 = (float *)(pcVar11 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          piStack0000000c = DAT_0059ce6c;

          iVar12 = 0;

          if (0 < DAT_0059ce60) {

            do {

              FUN_0044ead0();

              iVar13 = *piStack0000000c;

              iVar10 = FUN_00545650();

              if (iVar10 == 0) {

                if (-1 < iVar13) {

                  fx_alloc_effect();

                }

                break;

              }

              iVar12 = iVar12 + 1;

              piStack0000000c = piStack0000000c + 1;

            } while (iVar12 < DAT_0059ce60);

          }

        }

      }

      break;

    case 0x11:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = puStack0000003c[1];

          *(uint *)(iVar12 + 0xe0) = *(uint *)(iVar12 + 0xe0) | 0x80;

          *(float *)(*(int *)(iVar12 + 0x100) + 0x1c) = fVar17;

        }

      }

      break;

    case 0x12:

      pfVar19 = (float *)((int)pfVar18 + 9);

      fVar20 = (float10)rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = puStack0000003c[1];

          *(uint *)(iVar12 + 0xe0) = *(uint *)(iVar12 + 0xe0) | 0x80;

          *(float *)(*(int *)(iVar12 + 0x100) + 0x1c) = (float)fVar20;

        }

      }

      break;

    case 0x13:

      fVar17 = *pfVar19;

      uVar14 = *(undefined4 *)((int)pfVar18 + 5);

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = puStack0000003c[1];

          iVar13 = *(int *)(iVar12 + 0x100);

          *(uint *)(iVar12 + 0xe0) = *(uint *)(iVar12 + 0xe0) | 0x80;

          *(float *)(iVar13 + 0xd4) = fVar17;

          *(undefined4 *)(iVar13 + 0xd8) = uVar14;

        }

      }

      break;

    case 0x14:

      fVar20 = (float10)rndfloatrange();

      pfVar19 = (float *)((int)pfVar18 + 0x11);

      fVar21 = (float10)rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = puStack0000003c[1];

          iVar13 = *(int *)(iVar12 + 0x100);

          *(uint *)(iVar12 + 0xe0) = *(uint *)(iVar12 + 0xe0) | 0x80;

          *(float *)(iVar13 + 0xd4) = (float)fVar20;

          *(float *)(iVar13 + 0xd8) = (float)fVar21;

        }

      }

      break;

    case 0x15:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x400;

        }

      }

      break;

    case 0x16:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x200;

        }

      }

      break;

    case 0x17:

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          object_add_location();

          *(undefined4 *)(puStack0000003c[1] + 0x2a4) = *(undefined4 *)(puStack0000003c[1] + 0xa0);

          *(undefined4 *)(puStack0000003c[1] + 0x2b4) = *(undefined4 *)(puStack0000003c[1] + 0xa4);

          *(undefined4 *)(puStack0000003c[1] + 0x2c4) = *(undefined4 *)(puStack0000003c[1] + 0xa8);

        }

      }

      break;

    case 0x18:

      pfVar19 = (float *)((int)pfVar18 + 9);

      rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          object_add_location();

          *(undefined4 *)(puStack0000003c[1] + 0x2a4) = *(undefined4 *)(puStack0000003c[1] + 0xa0);

          *(undefined4 *)(puStack0000003c[1] + 0x2b4) = *(undefined4 *)(puStack0000003c[1] + 0xa4);

          *(undefined4 *)(puStack0000003c[1] + 0x2c4) = *(undefined4 *)(puStack0000003c[1] + 0xa8);

        }

      }

      break;

    case 0x19:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(float *)(*(int *)(puStack0000003c[1] + 0x100) + 0xac) = fVar17;

          *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x100;

        }

      }

      break;

    case 0x1a:

      pfVar19 = (float *)((int)pfVar18 + 9);

      break;

    case 0x1b:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          *(float *)(puStack0000003c[1] + 0xc4) = fVar17;

          *(float *)(iVar12 + 0x10) = fVar17;

          *(float *)(iVar12 + 0x14) = fVar17;

          crt_euler_to_quat();

        }

      }

      break;

    case 0x1c:

      pfVar19 = (float *)((int)pfVar18 + 9);

      fVar20 = (float10)rndfloatrange();

      fVar17 = (float)fVar20;

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          *(float *)(puStack0000003c[1] + 0xc4) = fVar17;

          *(float *)(iVar12 + 0x10) = fVar17;

          *(float *)(iVar12 + 0x14) = fVar17;

          crt_euler_to_quat();

        }

      }

      break;

    case 0x1d:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_setupEmitter__FP6FxDataP10FXSTACKTAGifiiiiii();

      }

      break;

    case 0x1e:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      pfVar19 = (float *)((int)pfVar18 + 9);

      rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_setupEmitter__FP6FxDataP10FXSTACKTAGifiiiiii();

      }

      break;

    default:

      crt_sprintf();

      FUN_0051ea20();

      break;

    case 0x20:

      pfVar19 = (float *)((int)pfVar18 + 0x19);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_setupTracerRGB__FP10FXSTACKTAGPfT1();

      }

      break;

    case 0x21:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(uint *)(puStack0000003c[1] + 0xe4) = *(uint *)(puStack0000003c[1] + 0xe4) | 0x10000;

          *(uint *)(puStack0000003c[1] + 0xd8) = *(uint *)(puStack0000003c[1] + 0xd8) | 0x40000000;

        }

      }

      break;

    case 0x22:

      fVar17 = *pfVar19;

      fVar15 = *(float *)((int)pfVar18 + 5);

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          if ((*(int **)(iVar12 + 0xf8) == (int *)0x0) || (**(int **)(iVar12 + 0xf8) == 0)) {

            fx_setupTracer__FP10FXSTACKTAG();

          }

          if (**(int **)(iVar12 + 0xf8) != 0) {

            *(float *)(**(int **)(iVar12 + 0xf8) + 0x10) = fVar17;

            *(float *)(**(int **)(iVar12 + 0xf8) + 0x14) = fVar15;

            if (fVar15 < fVar17) {

              *(float *)(**(int **)(iVar12 + 0xf8) + 0x18) = 1.0 / (fVar17 - fVar15);

            }

          }

        }

      }

      break;

    case 0x23:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_setupTracer__FP10FXSTACKTAG();

      }

      break;

    case 0x24:

      pfVar19 = (float *)((int)pfVar18 + 0xd);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        in_stack_0000001c = fx_createGameLockedObj__FP6FxDataiii();

      }

      break;

    case 0x25:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          piVar2 = *(int **)(iVar12 + 0xf8);

          if ((piVar2 == (int *)0x0) || (*piVar2 == 0)) {

            fx_setupTracer__FP10FXSTACKTAG();

          }

          iVar12 = **(int **)(iVar12 + 0xf8);

          if (iVar12 != 0) {

            *(float *)(iVar12 + 0x3c) = fVar17;

          }

        }

      }

      break;

    case 0x26:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          piVar2 = *(int **)(iVar12 + 0xf8);

          if ((piVar2 == (int *)0x0) || (*piVar2 == 0)) {

            fx_setupTracer__FP10FXSTACKTAG();

          }

          iVar12 = **(int **)(iVar12 + 0xf8);

          if (iVar12 != 0) {

            *(float *)(iVar12 + 0x38) = fVar17;

          }

        }

      }

      break;

    case 0x27:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      pfVar19 = (float *)((int)pfVar18 + 9);

      goto joined_r0x0044cec5;

    case 0x28:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      rndfloatrange();

      pfVar19 = (float *)((int)pfVar18 + 0x11);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_setupEmitter__FP6FxDataP10FXSTACKTAGifiiiiii();

      }

      break;

    case 0x29:

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_setupTextureAnimtion__FP10FXSTACKTAGif();

      }

      break;

    case 0x2a:

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        sound_play_3dpos();

      }

      break;

    case 0x2b:

      pfVar19 = (float *)((int)pfVar18 + 9);

      rndintrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        sound_play_3dpos();

      }

      break;

    case 0x2c:

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          sound_play_obj();

        }

      }

      break;

    case 0x2d:

      pfVar19 = (float *)((int)pfVar18 + 9);

      rndintrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          sound_play_obj();

        }

      }

      break;

    case 0x2e:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          piVar2 = *(int **)(iVar12 + 0xf8);

          if ((piVar2 == (int *)0x0) || (*piVar2 == 0)) {

            fx_setupTracer__FP10FXSTACKTAG();

          }

          *(float *)(*(int *)(iVar12 + 0xf8) + 8) = fVar17;

        }

      }

      break;

    case 0x2f:

      pfVar19 = (float *)((int)pfVar18 + 9);

      fVar20 = (float10)rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          piVar2 = *(int **)(iVar12 + 0xf8);

          if ((piVar2 == (int *)0x0) || (*piVar2 == 0)) {

            fx_setupTracer__FP10FXSTACKTAG();

          }

          *(float *)(*(int *)(iVar12 + 0xf8) + 8) = (float)fVar20;

        }

      }

      break;

    case 0x30:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          if ((*(int **)(iVar12 + 0xf8) == (int *)0x0) || (**(int **)(iVar12 + 0xf8) == 0)) {

            fx_setupTracer__FP10FXSTACKTAG();

          }

          if (**(int **)(iVar12 + 0xf8) != 0) {

            MAP_MemGroupSetBase_3();

            *(float *)(*(int *)(iVar12 + 0xf8) + 0xc) = fVar17;

            *(float *)(*(int *)(iVar12 + 0xf8) + 0x10) = fVar17;

            *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x20000;

          }

        }

      }

      break;

    case 0x31:

      pfVar19 = (float *)((int)pfVar18 + 9);

      fVar20 = (float10)rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          if ((*(int **)(iVar12 + 0xf8) == (int *)0x0) || (**(int **)(iVar12 + 0xf8) == 0)) {

            fx_setupTracer__FP10FXSTACKTAG();

          }

          if (**(int **)(iVar12 + 0xf8) != 0) {

            MAP_MemGroupSetBase_3();

            *(float *)(*(int *)(iVar12 + 0xf8) + 0xc) = (float)fVar20;

            *(float *)(*(int *)(iVar12 + 0xf8) + 0x10) = (float)fVar20;

            *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x20000;

          }

        }

      }

      break;

    case 0x32:

      fVar17 = *pfVar19;

      fVar15 = *(float *)((int)pfVar18 + 9);

      pfVar19 = (float *)((int)pfVar18 + 0xd);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          *(undefined4 *)(iVar12 + 0x30) = *(undefined4 *)((int)pfVar18 + 5);

LAB_0044d7d9:

          *(float *)(iVar12 + 0x34) = fVar17;

          *(float *)(iVar12 + 0x38) = fVar15;

          if ((*(uint *)(puStack0000003c[1] + 0xe0) & 0x40000000) == 0) {

            FUN_0053e6c0();

          }

          *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x40000;

        }

      }

      break;

    case 0x33:

      fVar20 = (float10)rndfloatrange();

      fVar17 = (float)fVar20;

      fVar20 = (float10)rndfloatrange();

      pfVar19 = (float *)((int)pfVar18 + 0x19);

      fVar21 = (float10)rndfloatrange();

      fVar15 = (float)fVar21;

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c != (undefined4 *)0x0) {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          *(float *)(iVar12 + 0x30) = (float)fVar20;

          goto LAB_0044d7d9;

        }

        crt_sprintf();

        FUN_0051ea20();

      }

      break;

    case 0x34:

      fVar17 = *pfVar19;

      fVar15 = *(float *)((int)pfVar18 + 5);

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          *(float *)(puStack0000003c[1] + 0xc4) = fVar17;

          *(float *)(iVar12 + 0x10) = fVar17;

          *(float *)(iVar12 + 0x14) = fVar15;

          crt_euler_to_quat();

          if (fVar17 != fVar15) {

            *(float *)(iVar12 + 0x18) = SQRT(fVar15 - fVar17);

            *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x80000;

          }

        }

      }

      break;

    case 0x35:

      fVar20 = (float10)rndfloatrange();

      fVar17 = (float)fVar20;

      pfVar19 = (float *)((int)pfVar18 + 0x11);

      fVar20 = (float10)rndfloatrange();

      fVar15 = (float)fVar20;

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          *(float *)(puStack0000003c[1] + 0xc4) = fVar17;

          *(float *)(iVar12 + 0x14) = fVar15;

          *(float *)(iVar12 + 0x10) = fVar17;

          crt_euler_to_quat();

          if (fVar17 != fVar15) {

            *(float *)(iVar12 + 0x18) = SQRT(fVar15 - fVar17);

            *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x80000;

          }

        }

      }

      break;

    case 0x36:

      fVar17 = *pfVar19;

      fVar15 = *(float *)((int)pfVar18 + 5);

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          *(float *)(puStack0000003c[1] + 0xc4) = fVar17;

          *(float *)(iVar12 + 0x10) = fVar17;

          *(float *)(iVar12 + 0x14) = fVar15;

          crt_euler_to_quat();

          if (fVar17 != fVar15) {

            *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x100000;

          }

        }

      }

      break;

    case 0x37:

      fVar20 = (float10)rndfloatrange();

      fVar17 = (float)fVar20;

      pfVar19 = (float *)((int)pfVar18 + 0x11);

      fVar20 = (float10)rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          *(float *)(puStack0000003c[1] + 0xc4) = fVar17;

          *(float *)(iVar12 + 0x10) = fVar17;

          *(float *)(iVar12 + 0x14) = (float)fVar20;

          crt_euler_to_quat();

          if (fVar17 != (float)fVar20) {

            *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x100000;

          }

        }

      }

      break;

    case 0x38:

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        in_stack_0000001c = fx_setupWeather__Fi();

      }

      break;

    case 0x39:

      fVar17 = *pfVar19;

      uVar14 = *(undefined4 *)((int)pfVar18 + 5);

      uVar3 = *(undefined4 *)((int)pfVar18 + 9);

      pfVar19 = (float *)((int)pfVar18 + 0xd);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          if ((*(byte *)(puStack0000003c[1] + 0xe4) & 1) == 0) {

            crt_sprintf();

            FUN_0051ea20();

          }

          else {

            *(float *)(*(int *)(iVar12 + 0x100) + 0x10) = fVar17;

            *(undefined4 *)(*(int *)(iVar12 + 0x100) + 0x14) = uVar14;

            *(undefined4 *)(*(int *)(iVar12 + 0x100) + 0xc) = uVar3;

          }

        }

      }

      break;

    case 0x3a:

      fVar17 = *pfVar19;

      uVar14 = *(undefined4 *)((int)pfVar18 + 5);

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          if ((*(byte *)(puStack0000003c[1] + 0xe4) & 1) == 0) {

            crt_sprintf();

            FUN_0051ea20();

          }

          else {

            **(float **)(iVar12 + 0x100) = fVar17;

            *(undefined4 *)(*(int *)(iVar12 + 0x100) + 4) = uVar14;

          }

        }

      }

      break;

    case 0x3b:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = puStack0000003c[1];

          uVar16 = *(uint *)(iVar12 + 0xe0) | 0x4000000;

LAB_0044b93c:

          *(uint *)(iVar12 + 0xe0) = uVar16;

          *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x80;

        }

      }

      break;

    case 0x3c:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = puStack0000003c[1];

          if ((*(uint *)(iVar12 + 0xe4) & 1) == 0) {

            crt_sprintf();

            FUN_0051ea20();

          }

          else {

            *(uint *)(iVar12 + 0xe4) = *(uint *)(iVar12 + 0xe4) | 4;

            *(float *)(*(int *)(*(int *)(iVar12 + 0x100) + 0x100) + 8) = fVar17;

          }

        }

      }

      break;

    case 0x3d:

      pfVar19 = (float *)((int)pfVar18 + 0x19);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_weather_fog_setup();

      }

      break;

    case 0x3e:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c != (undefined4 *)0x0) {

          iVar12 = puStack0000003c[1];

          uVar16 = *(uint *)(iVar12 + 0xe0) | 0x8000000;

          goto LAB_0044b93c;

        }

        crt_sprintf();

        FUN_0051ea20();

      }

      break;

    case 0x3f:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c != (undefined4 *)0x0) {

          iVar12 = puStack0000003c[1];

          uVar16 = *(uint *)(iVar12 + 0xe0) | 0x10000000;

          goto LAB_0044b93c;

        }

        crt_sprintf();

        FUN_0051ea20();

      }

      break;

    case 0x40:

      fVar17 = *pfVar19;

      uVar14 = *(undefined4 *)((int)pfVar18 + 5);

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = puStack0000003c[1];

          iVar13 = *(int *)(iVar12 + 0x100);

          *(uint *)(iVar12 + 0xe0) = *(uint *)(iVar12 + 0xe0) | 0x20000000;

          *(uint *)(puStack0000003c[1] + 0xdc) = *(uint *)(puStack0000003c[1] + 0xdc) | 0x80000;

          *(float *)(iVar13 + 0x80) = fVar17;

          *(undefined4 *)(iVar13 + 0x84) = uVar14;

        }

      }

      break;

    case 0x41:

      pfVar19 = (float *)((int)pfVar18 + 0x25);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_weather_fogsky_setup();

      }

      break;

    case 0x42:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else if ((*(byte *)(puStack0000003c[1] + 0xe4) & 1) == 0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(float *)(*(int *)(*(int *)(puStack0000003c[1] + 0x100) + 0x100) + 0x9c) = fVar17;

        }

      }

      break;

    case 0x43:

      fVar17 = *pfVar19;

      fVar15 = *(float *)((int)pfVar18 + 5);

      pfVar19 = (float *)((int)pfVar18 + 9);

      if (((in_stack_0000d774 == 0) && (!bVar5)) && (sound_play(), 0.0 < fVar15)) {

        in_stack_0000d770[4] = in_stack_0000d770[4] | 0x2000;

        in_stack_0000d770[0x30] = (int)fVar17;

        in_stack_0000d770[0x31] = (int)fVar15;

      }

      break;

    case 0x44:

      iVar12 = rndintrange();

      pfVar19 = (float *)((int)pfVar18 + 0x11);

      fVar20 = (float10)rndfloatrange();

      if (((in_stack_0000d774 == 0) && (!bVar5)) && (sound_play(), 0.0 < (float)fVar20)) {

        in_stack_0000d770[4] = in_stack_0000d770[4] | 0x2000;

        in_stack_0000d770[0x30] = iVar12;

        in_stack_0000d770[0x31] = (int)(float)fVar20;

      }

      break;

    case 0x45:

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        FUN_00442f70();

      }

      break;

    case 0x46:

      pfVar19 = (float *)((int)pfVar18 + 0x15);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_setupVerticleFade__FP10FXSTACKTAGfffff();

      }

      break;

    case 0x47:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x80;

          *(uint *)(puStack0000003c[1] + 0xe4) = *(uint *)(puStack0000003c[1] + 0xe4) | 0x800;

          if (fVar17 != 0.0) {

            *(uint *)(puStack0000003c[1] + 0xe4) = *(uint *)(puStack0000003c[1] + 0xe4) | 0x20000;

          }

        }

      }

      break;

    case 0x48:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        in_stack_0000d770[4] = in_stack_0000d770[4] | 0x10;

      }

      break;

    case 0x49:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          in_stack_0000d770[4] = in_stack_0000d770[4] | 0x40000;

          main_linkage_00470250();

        }

      }

      break;

    case 0x4a:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          in_stack_0000d770[3] = 4;

          bVar6 = true;

        }

        else {

          crt_sprintf();

          FUN_0051ea20();

          bVar6 = true;

        }

      }

      break;

    case 0x4b:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 != 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          if ((int)fVar17 < 6) {

            in_stack_0000d770[(int)fVar17 + 0x11] = (int)pfVar19;

          }

          else {

            crt_sprintf();

            FUN_0051ea20();

          }

        }

        else {

          crt_sprintf();

          FUN_0051ea20();

        }

      }

      break;

    case 0x4c:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          if ((int)fVar17 < 6) {

            in_stack_0000d770[3] = 0;

            pfVar19 = (float *)in_stack_0000d770[(int)fVar17 + 0x11];

          }

          else {

            crt_sprintf();

            FUN_0051ea20();

          }

        }

        else {

          crt_sprintf();

          FUN_0051ea20();

        }

      }

      break;

    case 0x4d:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          in_stack_0000d770[4] = in_stack_0000d770[4] | 0x60;

          in_stack_0000d770[0x17] = (int)fVar17;

        }

        else {

          crt_sprintf();

          FUN_0051ea20();

        }

      }

      break;

    case 0x4e:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          in_stack_0000d770[4] = in_stack_0000d770[4] | 0xa0;

          in_stack_0000d770[0x18] = (int)fVar17;

        }

        else {

          crt_sprintf();

          FUN_0051ea20();

        }

      }

      break;

    case 0x4f:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          in_stack_0000d770[4] = in_stack_0000d770[4] | 0x120;

          in_stack_0000d770[0x19] = (int)fVar17;

        }

        else {

          crt_sprintf();

          FUN_0051ea20();

        }

      }

      break;

    case 0x50:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          in_stack_0000d770[4] = in_stack_0000d770[4] | 0x220;

          in_stack_0000d770[0x1a] = (int)fVar17;

        }

        else {

          crt_sprintf();

          FUN_0051ea20();

        }

      }

      break;

    case 0x51:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          in_stack_0000d770[4] = in_stack_0000d770[4] | 0x420;

          in_stack_0000d770[0x1b] = (int)fVar17;

        }

        else {

          crt_sprintf();

          FUN_0051ea20();

        }

      }

      break;

    case 0x52:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          in_stack_0000d770[4] = in_stack_0000d770[4] | 0x120;

          in_stack_0000d770[0x1c] = (int)fVar17;

        }

        else {

          crt_sprintf();

          FUN_0051ea20();

        }

      }

      break;

    case 0x53:

      pfVar19 = (float *)((int)pfVar18 + 0x19);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_weather_fog_setup2();

      }

      break;

    case 0x54:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        puVar8 = DAT_00632da0;

        if (puStack0000003c == (undefined4 *)0x0) {

          for (; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {

            if ((int *)**(undefined4 **)(puVar8[3] + 0x100) == in_stack_0000d770) {

              FUN_00448750();

            }

          }

        }

        else {

          crt_sprintf();

          FUN_0051ea20();

        }

      }

      break;

    case 0x55:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

          bVar5 = true;

        }

        else {

          iVar12 = puStack0000003c[1];

          *(uint *)(iVar12 + 0xe0) = *(uint *)(iVar12 + 0xe0) | 0x400000;

          *(float **)(*(int *)(iVar12 + 0x100) + 0x9c) = pfVar19;

          bVar5 = true;

        }

      }

      break;

    case 0x56:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      pfVar19 = (float *)((int)pfVar18 + 0xd);

joined_r0x0044cec5:

      if (in_stack_0000d774 == 0) {

joined_r0x0044cc6b:

        if (!bVar5) {

          fx_setupEmitter__FP6FxDataP10FXSTACKTAGifiiiiii();

        }

      }

      break;

    case 0x57:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      rndfloatrange();

      pfVar19 = (float *)((int)pfVar18 + 0x19);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_setupEmitter__FP6FxDataP10FXSTACKTAGifiiiiii();

      }

      break;

    case 0x58:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          FUN_00414690();

          *(undefined4 *)(puStack0000003c[1] + 0x2c4) = in_stack_0000032c;

          *(undefined4 *)(puStack0000003c[1] + 0xa8) = in_stack_0000032c;

        }

      }

      break;

    case 0x59:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x1000000;

        }

      }

      break;

    case 0x5a:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      fVar17 = *(float *)((int)pfVar18 + 1);

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          piStack0000000c = DAT_0059ce6c;

          iStack00000008 = 0;

          if (0 < DAT_0059ce60) {

            do {

              FUN_0044ead0();

              iVar12 = *piStack0000000c;

              iVar13 = FUN_00545650();

              if (iVar13 == 0) {

                if (-1 < iVar12) {

                  iVar13 = *(int *)(puStack0000003c[1] + 0x100);

                  *(float *)(iVar13 + 0x20) = fVar17;

                  *(int *)(iVar13 + 0x24) = iVar12;

                  *(uint *)(puStack0000003c[1] + 0xe0) =

                       *(uint *)(puStack0000003c[1] + 0xe0) | 0x2000000;

                  goto LAB_0044e828;

                }

                break;

              }

              iStack00000008 = iStack00000008 + 1;

              piStack0000000c = piStack0000000c + 1;

            } while (iStack00000008 < DAT_0059ce60);

          }

          crt_sprintf();

          FUN_0051ea20();

        }

      }

      break;

    case 0x5b:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      goto joined_r0x0044cc5f;

    case 0x5c:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      rndfloatrange();

      pfVar19 = (float *)((int)pfVar18 + 0x19);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_setupEmitter__FP6FxDataP10FXSTACKTAGifiiiiii();

      }

      break;

    case 0x5d:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = puStack0000003c[1];

          iVar13 = *(int *)(iVar12 + 0x100);

          *(uint *)(iVar12 + 0xd8) = *(uint *)(iVar12 + 0xd8) & 0xffffffef;

          *(float *)(iVar13 + 0xa4) = fVar17;

          *(float *)(iVar13 + 0xa8) = fVar17;

        }

      }

      break;

    case 0x5e:

      pfVar19 = (float *)((int)pfVar18 + 9);

      fVar20 = (float10)rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = puStack0000003c[1];

          iVar13 = *(int *)(iVar12 + 0x100);

          *(uint *)(iVar12 + 0xd8) = *(uint *)(iVar12 + 0xd8) & 0xffffffef;

          *(float *)(iVar13 + 0xa4) = (float)fVar20;

          *(float *)(iVar13 + 0xa8) = (float)fVar20;

        }

      }

      break;

    case 0x5f:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        iVar12 = puStack0000003c[1];

        uVar14 = *(undefined4 *)(*(int *)(iVar12 + 0x104) + 8);

        iVar13 = *(int *)(iVar12 + 0x100);

        *(uint *)(iVar12 + 0xd8) = *(uint *)(iVar12 + 0xd8) & 0xffffffef;

        *(float *)(iVar13 + 0xa4) = fVar17;

        *(undefined4 *)(iVar13 + 0xa8) = uVar14;

      }

      break;

    case 0x60:

      pfVar19 = (float *)((int)pfVar18 + 9);

      fVar20 = (float10)rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        iVar12 = puStack0000003c[1];

        uVar14 = *(undefined4 *)(*(int *)(iVar12 + 0x104) + 8);

        iVar13 = *(int *)(iVar12 + 0x100);

        *(uint *)(iVar12 + 0xd8) = *(uint *)(iVar12 + 0xd8) & 0xffffffef;

        *(float *)(iVar13 + 0xa4) = (float)fVar20;

        *(undefined4 *)(iVar13 + 0xa8) = uVar14;

      }

      break;

    case 0x61:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        iVar12 = puStack0000003c[1];

        uVar14 = *(undefined4 *)(*(int *)(iVar12 + 0x104) + 4);

        iVar13 = *(int *)(iVar12 + 0x100);

        *(uint *)(iVar12 + 0xd8) = *(uint *)(iVar12 + 0xd8) & 0xffffffef;

        *(undefined4 *)(iVar13 + 0xa4) = uVar14;

        *(float *)(iVar13 + 0xa8) = fVar17;

      }

      break;

    case 0x62:

      pfVar19 = (float *)((int)pfVar18 + 9);

      fVar20 = (float10)rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        iVar12 = puStack0000003c[1];

        uVar14 = *(undefined4 *)(*(int *)(iVar12 + 0x104) + 4);

        iVar13 = *(int *)(iVar12 + 0x100);

        *(uint *)(iVar12 + 0xd8) = *(uint *)(iVar12 + 0xd8) & 0xffffffef;

        *(undefined4 *)(iVar13 + 0xa4) = uVar14;

        *(float *)(iVar13 + 0xa8) = (float)fVar20;

      }

      break;

    case 99:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(float *)(*(int *)(puStack0000003c[1] + 0x100) + 0xd0) = fVar17;

        }

      }

      break;

    case 100:

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fVar20 = (float10)rndfloatrange();

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(float *)(*(int *)(puStack0000003c[1] + 0x100) + 0xd0) = (float)fVar20;

        }

      }

      break;

    case 0x65:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(float *)(*(int *)(puStack0000003c[1] + 0x100) + 0xac) = fVar17;

          *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x100;

        }

      }

      break;

    case 0x66:

      pfVar19 = (float *)((int)pfVar18 + 9);

      fVar20 = (float10)rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(float *)(*(int *)(puStack0000003c[1] + 0x100) + 0xac) = (float)fVar20;

          *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x100;

        }

      }

      break;

    case 0x67:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(float *)(*(int *)(puStack0000003c[1] + 0x100) + 0xb0) = fVar17;

        }

      }

      break;

    case 0x68:

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fVar20 = (float10)rndfloatrange();

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(float *)(*(int *)(puStack0000003c[1] + 0x100) + 0xb0) = (float)fVar20;

        }

      }

      break;

    case 0x69:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(float *)(*(int *)(puStack0000003c[1] + 0x100) + 0x28) = fVar17;

        }

      }

      break;

    case 0x6a:

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fVar20 = (float10)rndfloatrange();

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(float *)(*(int *)(puStack0000003c[1] + 0x100) + 0x28) = (float)fVar20;

        }

      }

      break;

    case 0x6b:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(float *)(*(int *)(puStack0000003c[1] + 0x100) + 0x2c) = fVar17;

        }

      }

      break;

    case 0x6c:

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fVar20 = (float10)rndfloatrange();

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(float *)(*(int *)(puStack0000003c[1] + 0x100) + 0x2c) = (float)fVar20;

        }

      }

      break;

    case 0x6d:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x10;

        }

      }

      break;

    case 0x6e:

      fVar17 = *pfVar19;

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(*(int *)(puStack0000003c[1] + 0x100) + 0x104);

          iVar13 = *(int *)(iVar12 + 400);

          if (iVar13 < 1) {

            crt_sprintf();

            FUN_0051ea20();

          }

          else {

            *(float *)(iVar12 + 0x164 + iVar13 * 4) = fVar17;

          }

        }

      }

      break;

    case 0x6f:

      pfVar19 = (float *)((int)pfVar18 + 9);

      fVar20 = (float10)rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(*(int *)(puStack0000003c[1] + 0x100) + 0x104);

          iVar13 = *(int *)(iVar12 + 400);

          if (iVar13 < 1) {

            crt_sprintf();

            FUN_0051ea20();

          }

          else {

            *(float *)(iVar12 + 0x164 + iVar13 * 4) = (float)fVar20;

          }

        }

      }

      break;

    case 0x70:

      pcVar7 = (char *)((int)pfVar18 + 5);

      do {

        pcVar11 = pcVar7;

        pcVar7 = pcVar11 + 1;

      } while (*pcVar11 != '\0');

      pfVar19 = (float *)(pcVar11 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          piStack0000000c = DAT_0059ce6c;

          iVar12 = 0;

          if (0 < DAT_0059ce60) {

            do {

              FUN_0044ead0();

              iVar13 = *piStack0000000c;

              iVar10 = FUN_00545650();

              if (iVar10 == 0) {

                if (-1 < iVar13) {

                  fx_alloc_effect();

                }

                break;

              }

              iVar12 = iVar12 + 1;

              piStack0000000c = piStack0000000c + 1;

            } while (iVar12 < DAT_0059ce60);

          }

        }

      }

      break;

    case 0x71:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

joined_r0x0044cc5f:

      pfVar19 = (float *)((int)pfVar18 + 0xd);

      if (in_stack_0000d774 != 0) break;

      goto joined_r0x0044cc6b;

    case 0x72:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      rndfloatrange();

      pfVar19 = (float *)((int)pfVar18 + 0x19);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_setupEmitter__FP6FxDataP10FXSTACKTAGifiiiiii();

      }

      break;

    case 0x73:

      fVar17 = *pfVar19;

      uVar14 = *(undefined4 *)((int)pfVar18 + 5);

      uVar3 = *(undefined4 *)((int)pfVar18 + 9);

      pfVar19 = (float *)((int)pfVar18 + 0xd);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x40000000;

          *(undefined4 *)(puStack0000003c[1] + 200) = uVar14;

          *(float *)(puStack0000003c[1] + 0xcc) = fVar17;

          *(undefined4 *)(puStack0000003c[1] + 0xd0) = uVar3;

LAB_0044d657:

          crt_euler_to_quat();

        }

      }

      break;

    case 0x74:

      fVar20 = (float10)rndfloatrange();

      fVar21 = (float10)rndfloatrange();

      pfVar19 = (float *)((int)pfVar18 + 0x19);

      fVar22 = (float10)rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c != (undefined4 *)0x0) {

          *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x40000000;

          *(float *)(puStack0000003c[1] + 200) = (float)fVar21;

          *(float *)(puStack0000003c[1] + 0xcc) = (float)fVar20;

          *(float *)(puStack0000003c[1] + 0xd0) = (float)fVar22;

          goto LAB_0044d657;

        }

        crt_sprintf();

        FUN_0051ea20();

      }

      break;

    case 0x75:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      fVar17 = *(float *)((int)pfVar18 + 1);

      uVar14 = *(undefined4 *)((int)pfVar18 + 5);

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          iVar13 = main_texture_00508750();

          *(int *)(iVar12 + 0x90) = iVar13;

          *(float *)(iVar12 + 0x94) = fVar17;

          *(undefined4 *)(iVar12 + 0x98) = uVar14;

          if (iVar13 == 0) {

            crt_sprintf();

            FUN_0051ea20();

          }

          else {

            *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x80000000

            ;

          }

        }

      }

      break;

    case 0x76:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = main_texture_00508750();

          if (iVar12 != 0) {

            rndfloatrange();

            mpeg_mode_set();

          }

        }

      }

      break;

    case 0x77:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      fVar17 = *(float *)((int)pfVar18 + 1);

      uVar14 = *(undefined4 *)((int)pfVar18 + 5);

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          iVar13 = main_texture_00508750();

          *(int *)(iVar12 + 0x90) = iVar13;

          *(float *)(iVar12 + 0x94) = fVar17;

          *(undefined4 *)(iVar12 + 0x98) = uVar14;

          if (iVar13 == 0) {

            crt_sprintf();

            FUN_0051ea20();

          }

          else {

            *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x80000000

            ;

            *(uint *)(puStack0000003c[1] + 0xe4) = *(uint *)(puStack0000003c[1] + 0xe4) | 0x200;

          }

        }

      }

      break;

    case 0x78:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = main_texture_00508750();

          if (iVar12 != 0) {

            rndfloatrange();

            mpeg_mode_set();

          }

        }

      }

      break;

    case 0x79:

      pfVar19 = (float *)((int)pfVar18 + 9);

      rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_orient_ground();

      }

      break;

    case 0x7a:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      pfVar19 = (float *)((int)pfVar18 + 0x19);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        rndfloatrange();

        rndfloatrange();

        rndfloatrange();

        fx_get_free_effect__Fv();

      }

      break;

    case 0x7b:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(uint *)(puStack0000003c[1] + 0x1c8) = *(uint *)(puStack0000003c[1] + 0x1c8) & 0xfffff7ff

          ;

        }

      }

      break;

    case 0x7c:

      pfVar19 = (float *)((int)pfVar18 + 0x15);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

LAB_0044de79:

          pfVar19 = (float *)((int)pfVar18 + 0x15);

          uVar14 = sound_get_free_sequence__Fv();

          *(undefined4 *)(puStack0000003c[1] + 0xe8) = uVar14;

        }

      }

      break;

    case 0x7d:

      pfVar19 = (float *)((int)pfVar18 + 0x15);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c != (undefined4 *)0x0) goto LAB_0044de79;

        sound_get_free_sequence__Fv();

      }

      break;

    case 0x7e:

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          sound_interrupt_sequence();

        }

      }

      break;

    case 0x7f:

      fVar17 = *pfVar19;

      uVar14 = *(undefined4 *)((int)pfVar18 + 5);

      uVar3 = *(undefined4 *)((int)pfVar18 + 9);

      uVar4 = *(undefined4 *)((int)pfVar18 + 0xd);

      pfVar19 = (float *)((int)pfVar18 + 0x11);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          iVar12 = *(int *)(puStack0000003c[1] + 0x100);

          *(float *)(iVar12 + 0xe4) = fVar17;

          *(undefined4 *)(iVar12 + 0xe8) = uVar14;

          *(undefined4 *)(iVar12 + 0xf0) = uVar4;

          *(undefined4 *)(iVar12 + 0xec) = uVar3;

          *(uint *)(puStack0000003c[1] + 0xe4) = *(uint *)(puStack0000003c[1] + 0xe4) | 0x4000;

        }

      }

      break;

    case 0x80:

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fVar20 = (float10)rndfloatrange();

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(float *)(*(int *)(puStack0000003c[1] + 0x100) + 0xf4) = (float)fVar20;

          *(uint *)(puStack0000003c[1] + 0xe4) = *(uint *)(puStack0000003c[1] + 0xe4) | 0x8000;

          *(uint *)(puStack0000003c[1] + 0xe0) = *(uint *)(puStack0000003c[1] + 0xe0) | 0x40;

        }

      }

      break;

    case 0x81:

      pfVar19 = (float *)((int)pfVar18 + 0x15);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c != (undefined4 *)0x0) goto LAB_0044de79;

        crt_sprintf();

        FUN_0051ea20();

      }

      break;

    case 0x82:

      pfVar19 = (float *)((int)pfVar18 + 0x15);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        sound_get_free_sequence__Fv();

      }

      break;

    case 0x83:

      pfVar19 = (float *)((int)pfVar18 + 9);

      uVar14 = rndintrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(undefined4 *)(*(int *)(puStack0000003c[1] + 0x100) + 0x108) = uVar14;

          sound_play_player();

        }

      }

      break;

    case 0x84:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(uint *)(puStack0000003c[1] + 0xe4) = *(uint *)(puStack0000003c[1] + 0xe4) | 0x40000;

          ObjectSetAnim();

        }

      }

      break;

    case 0x85:

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(uint *)(puStack0000003c[1] + 0xe4) = *(uint *)(puStack0000003c[1] + 0xe4) | 0x40000;

          ObjectSetAnim();

        }

      }

      break;

    case 0x87:

      pfVar19 = (float *)((int)pfVar18 + 9);

      rndintrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          sound_play_player();

        }

      }

      break;

    case 0x88:

      fVar20 = (float10)rndfloatrange();

      pfVar19 = (float *)((int)pfVar18 + 0x11);

      fVar21 = (float10)rndfloatrange();

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        if (puStack0000003c == (undefined4 *)0x0) {

          crt_sprintf();

          FUN_0051ea20();

        }

        else {

          *(float *)(puStack0000003c[1] + 0xec) = (float)fVar20;

          *(uint *)(puStack0000003c[1] + 0xe4) = *(uint *)(puStack0000003c[1] + 0xe4) | 0x80000;

          *(float *)(puStack0000003c[1] + 0xf8) = 1.0 / ((float)fVar21 - (float)fVar20);

          *(undefined4 *)(puStack0000003c[1] + 0x184) = 0x3f800000;

        }

      }

      break;

    case 0x89:

      do {

        pfVar18 = pfVar19;

        pfVar19 = (float *)((int)pfVar18 + 1);

      } while (*(char *)pfVar18 != '\0');

      pfVar19 = (float *)((int)pfVar18 + 9);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        fx_get_free_effect__Fv();

      }

      break;

    case 0x8a:

      pfVar19 = (float *)((int)pfVar18 + 0xd);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        in_stack_0000001c = fx_createObj__FP6FxDatai();

      }

      break;

    case 0x8b:

      pfVar19 = (float *)((int)pfVar18 + 5);

      if ((in_stack_0000d774 == 0) && (!bVar5)) {

        ANM_DumpCluster();

      }

    }

LAB_0044e828:

    pfVar18 = pfVar19;

    if (bVar6) {

      if (in_stack_0000d774 != 0) {

        return 0;

      }

      if (in_stack_0000d778 == 0) {

        *in_stack_0000d770 = (int)pfVar19;

      }

      while (puStack0000003c != (undefined4 *)0x0) {

        fx_stackPop__FPP10FXSTACKTAGT0();

        puStack0000003c = puStack00000014;

      }

      return uStack0000008c;

    }

  } while( true );

}

/* ===== FUN_0044ead0 @ 0x0044EAD0 ===== */
void FUN_0044ead0(undefined4 *param_1,undefined4 *param_2)



{

  char cVar1;

  char *pcVar2;

  

  pcVar2 = (char *)*param_1;

  *param_2 = pcVar2;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  *param_1 = pcVar2;

  return;

}

/* ===== fx_goto_processing @ 0x0044EAF0 ===== */
void fx_goto_processing(undefined4 *param_1)



{

  int iVar1;

  undefined1 local_200 [512];

  

  if (DAT_00632a88 != 0) {

    if ((((*(byte *)(param_1 + 4) & 0x40) != 0) && ((DAT_005dd138 >> 0x12 & 1) != 0)) &&

       (iVar1 = param_1[0x17], -1 < iVar1)) {

      if (iVar1 < 6) {

        param_1[3] = 0;

        *param_1 = param_1[iVar1 + 0x11];

      }

      else {

        crt_sprintf(local_200,s_Invalid_goto_for_fx___s___0_<__L_00558f5c,DAT_0059ce5c + 0x20,6);

        FUN_0051ea20(local_200);

      }

    }

    if (((*(char *)(param_1 + 4) < '\0') && ((DAT_005dd138 >> 7 & 1) != 0)) &&

       (iVar1 = param_1[0x18], -1 < iVar1)) {

      if (iVar1 < 6) {

        param_1[3] = 0;

        *param_1 = param_1[iVar1 + 0x11];

      }

      else {

        crt_sprintf(local_200,s_Invalid_goto_for_fx___s___0_<__L_00558f5c,DAT_0059ce5c + 0x20,6);

        FUN_0051ea20(local_200);

      }

    }

    if ((((param_1[4] & 0x100) != 0) && ((DAT_005dd138 >> 9 & 1) != 0)) &&

       (iVar1 = param_1[0x19], -1 < iVar1)) {

      if (iVar1 < 6) {

        param_1[3] = 0;

        *param_1 = param_1[iVar1 + 0x11];

      }

      else {

        crt_sprintf(local_200,s_Invalid_goto_for_fx___s___0_<__L_00558f5c,DAT_0059ce5c + 0x20,6);

        FUN_0051ea20(local_200);

      }

    }

    if ((((param_1[4] & 0x200) != 0) && ((DAT_005dd138 >> 0x13 & 1) != 0)) &&

       (iVar1 = param_1[0x1a], -1 < iVar1)) {

      if (iVar1 < 6) {

        param_1[3] = 0;

        *param_1 = param_1[iVar1 + 0x11];

      }

      else {

        crt_sprintf(local_200,s_Invalid_goto_for_fx___s___0_<__L_00558f5c,DAT_0059ce5c + 0x20,6);

        FUN_0051ea20(local_200);

      }

    }

    if ((((param_1[4] & 0x400) != 0) && ((DAT_005dd138 >> 0xf & 1) != 0)) &&

       (iVar1 = param_1[0x1b], -1 < iVar1)) {

      if (iVar1 < 6) {

        param_1[3] = 0;

        *param_1 = param_1[iVar1 + 0x11];

      }

      else {

        crt_sprintf(local_200,s_Invalid_goto_for_fx___s___0_<__L_00558f5c,DAT_0059ce5c + 0x20,6);

        FUN_0051ea20(local_200);

      }

    }

    if ((((param_1[4] & 0x800) != 0) && ((DAT_005dd138 >> 0x11 & 1) != 0)) &&

       (iVar1 = param_1[0x1c], -1 < iVar1)) {

      if (iVar1 < 6) {

        param_1[3] = 0;

        *param_1 = param_1[iVar1 + 0x11];

        return;

      }

      crt_sprintf(local_200,s_Invalid_goto_for_fx___s___0_<__L_00558f5c,DAT_0059ce5c + 0x20,6);

      FUN_0051ea20(local_200);

    }

  }

  return;

}

/* ===== fx_process_one @ 0x0044ED20 ===== */
/* PS2 candidate: fx_process_one (conf 0.526) */



int fx_process_one(int *param_1,int param_2)



{

  float fVar1;

  undefined4 *puVar2;

  int *piVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  float10 fVar7;

  undefined1 local_100 [256];

  

  if (param_1 == (int *)0x0) {

    return 0;

  }

  if ((param_2 != 0) && ((param_1[6] & 0x4000U) == 0)) {

    return *param_1;

  }

  uVar4 = param_1[6];

  if ((uVar4 & 0x80000) != 0) {

    if ((uVar4 & 0x100000) == 0) {

      if (param_1[5] == 4) {

        uVar4 = uVar4 & 0xffe7ffff;

      }

      else {

        uVar4 = uVar4 | 0x100000;

      }

      param_1[6] = uVar4;

    }

    else {

      param_1[6] = uVar4 & 0xffe7ffff;

      if (param_1[5] == 4) {

        for (puVar2 = DAT_00632da0; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

          iVar5 = puVar2[3];

          if ((int *)**(undefined4 **)(iVar5 + 0x100) == param_1 + 2) {

            uVar4 = *(uint *)(iVar5 + 0xe0);

            uVar6 = uVar4 | 0x400000;

            *(uint *)(iVar5 + 0xe0) = uVar6;

            if (uVar6 != 0) {

              *(uint *)(iVar5 + 0xe0) = uVar4 & 0xffbfffff;

              fx_processOpCodes(param_1 + 2,0,iVar5);

            }

          }

        }

        param_1[5] = 0;

      }

      else {

        crt_sprintf(local_100,s_Invalid_resume_for_fx___s__00559d34,param_1 + 10);

        FUN_0051ea20(local_100);

      }

    }

  }

  if ((*(byte *)(param_1 + 6) & 0x20) != 0) {

    fx_goto_processing(param_1 + 2);

  }

  if ((param_1[6] & 0x2000U) != 0) {

    fVar7 = (float10)FUN_00518b70(0,0);

    fVar7 = (float10)(float)param_1[0x33] - fVar7;

    param_1[0x33] = (int)(float)fVar7;

    if (fVar7 < (float10)0.0 != (fVar7 == (float10)0.0)) {

      FUN_00495990(param_1[0x32]);

      param_1[0x32] = -1;

      param_1[6] = param_1[6] & 0xffffdfff;

    }

  }

  if (param_1[5] != 0) {

    if (param_1[5] != 1) goto LAB_0044efbb;

    fVar7 = (float10)FUN_00518b70(0,0);

    fVar7 = (float10)(float)param_1[3] - fVar7;

    param_1[3] = (int)(float)fVar7;

    if (fVar7 < (float10)0.0 == (fVar7 == (float10)0.0)) goto LAB_0044efbb;

    param_1[5] = 0;

  }

  iVar5 = fx_processOpCodes(param_1 + 2,0,0);

  if (iVar5 != 0) {

    uVar4 = param_1[6];

    if (((uVar4 & 0x10) != 0) || ((uVar4 & 0x20000) != 0)) {

      param_1[5] = 3;

      return *param_1;

    }

    if ((uVar4 & 0x2000) != 0) {

      param_1[5] = 5;

      return *param_1;

    }

    puVar2 = DAT_00632da0;

    if ((uVar4 & 0x40000) != 0) {

      for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

        if ((int *)**(undefined4 **)(puVar2[3] + 0x100) == param_1 + 2) {

          **(undefined4 **)(puVar2[3] + 0x100) = 0;

        }

      }

    }

    piVar3 = (int *)param_1[1];

    if (piVar3 != (int *)0x0) {

      if (*param_1 != 0) {

        *piVar3 = *param_1;

        *(int *)(*param_1 + 4) = param_1[1];

        iVar5 = *param_1;

        *param_1 = (int)DAT_0059ce70;

        DAT_0059ce70 = param_1;

        return iVar5;

      }

      DAT_0059ce58 = piVar3;

      *piVar3 = 0;

      *param_1 = (int)DAT_0059ce70;

      DAT_0059ce70 = param_1;

      return 0;

    }

    DAT_0059ce64 = *param_1;

    if (DAT_0059ce64 == 0) {

      DAT_0059ce58 = (int *)0x0;

    }

    else {

      *(undefined4 *)(DAT_0059ce64 + 4) = 0;

    }

    *param_1 = (int)DAT_0059ce70;

    DAT_0059ce70 = param_1;

    return DAT_0059ce64;

  }

  fVar1 = (float)param_1[4];

  param_1[4] = 0;

  param_1[3] = (int)((float)param_1[3] - fVar1);

LAB_0044efbb:

  return *param_1;

}

/* ===== FUN_0044efd0 @ 0x0044EFD0 ===== */
/* PS2 candidate: fx_process (conf 0.377) */



void FUN_0044efd0(undefined4 param_1)



{

  int iVar1;

  

  for (iVar1 = DAT_0059ce64; iVar1 != 0; iVar1 = fx_process_one(iVar1,param_1)) {

  }

  return;

}

/* ===== wredit_obj_cleanup @ 0x0044EFF0 ===== */
void wredit_obj_cleanup(void)



{

  undefined4 *puVar1;

  int *piVar2;

  int *piVar3;

  

  piVar3 = DAT_0059ce64;

  if (DAT_0059ce64 == (int *)0x0) {

    return;

  }

  do {

    if ((piVar3[0x10] == 0) || (FUN_00497dc0(piVar3 + 0x10), piVar3[0x10] != 0)) {

      if ((piVar3[0x11] == 0) || (FUN_00497dc0(piVar3 + 0x11), piVar3[0x11] != 0))

      goto LAB_0044f153;

      if ((piVar3[6] & 0x20000U) != 0) goto LAB_0044f150;

      if ((piVar3[6] & 0x40000U) != 0) {

        for (puVar1 = DAT_00632da0; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

          if ((int *)**(undefined4 **)(puVar1[3] + 0x100) == piVar3 + 2) {

            **(undefined4 **)(puVar1[3] + 0x100) = 0;

          }

        }

      }

      piVar2 = (int *)*piVar3;

      if ((undefined4 *)piVar3[1] == (undefined4 *)0x0) goto LAB_0044f070;

      if (piVar2 == (int *)0x0) {

        DAT_0059ce58 = (undefined4 *)piVar3[1];

        *DAT_0059ce58 = 0;

        *piVar3 = (int)DAT_0059ce70;

        DAT_0059ce70 = piVar3;

        return;

      }

      *(undefined4 *)piVar3[1] = piVar2;

      *(int *)(*piVar3 + 4) = piVar3[1];

      piVar2 = (int *)*piVar3;

      *piVar3 = (int)DAT_0059ce70;

      DAT_0059ce70 = piVar3;

    }

    else if ((piVar3[6] & 0x20000U) == 0) {

      if ((piVar3[6] & 0x40000U) != 0) {

        for (puVar1 = DAT_00632da0; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

          if ((int *)**(int **)(puVar1[3] + 0x100) == piVar3 + 2) {

            **(int **)(puVar1[3] + 0x100) = 0;

          }

        }

      }

      piVar2 = (int *)*piVar3;

      if ((int *)piVar3[1] == (int *)0x0) {

LAB_0044f070:

        DAT_0059ce64 = piVar2;

        if (piVar2 == (int *)0x0) {

          DAT_0059ce58 = (undefined4 *)0x0;

        }

        else {

          piVar2[1] = 0;

        }

        *piVar3 = (int)DAT_0059ce70;

        piVar2 = DAT_0059ce64;

        DAT_0059ce70 = piVar3;

      }

      else {

        if (piVar2 == (int *)0x0) {

          DAT_0059ce58 = (undefined4 *)piVar3[1];

          *DAT_0059ce58 = 0;

          *piVar3 = (int)DAT_0059ce70;

          DAT_0059ce70 = piVar3;

          return;

        }

        *(int *)piVar3[1] = (int)piVar2;

        *(int *)(*piVar3 + 4) = piVar3[1];

        piVar2 = (int *)*piVar3;

        *piVar3 = (int)DAT_0059ce70;

        DAT_0059ce70 = piVar3;

      }

    }

    else {

LAB_0044f150:

      piVar3[5] = 3;

LAB_0044f153:

      piVar2 = (int *)*piVar3;

    }

    piVar3 = piVar2;

    if (piVar2 == (int *)0x0) {

      return;

    }

  } while( true );

}

