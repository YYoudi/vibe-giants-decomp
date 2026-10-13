/* Giants 1.449 — module _unmapped_0049
 * 142 functions (119 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0049.c(pp) (assert-string evidence)
 */

/* ===== FUN_004907e0 @ 0x004907E0 ===== */
/* PS2 candidate: army_create_ripper__FP6OBJECTP9ArmyOrderi (conf 0.198) */



void FUN_004907e0(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar1 = dialog_level_is_base();

  if (iVar1 != 0) {

    comm_disconnect_sleep();

    gamespy_host_game();

    return;

  }

  iVar2 = InitFxDict__Fv();

  iVar4 = 0;

  iVar1 = DAT_00632d20;

  if (-1 < iVar2) {

    do {

      iVar1 = world_get_pointer(iVar4);

      if ((iVar1 != 0) &&

         (iVar3 = match(s_intro_island_0055be84,*(undefined4 *)(iVar1 + 4)), iVar1 = iVar4,

         iVar3 != 0)) break;

      iVar4 = iVar4 + 1;

      iVar1 = DAT_00632d20;

    } while (iVar4 <= iVar2);

  }

  DAT_00632d20 = iVar1;

  AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_4(DAT_00632d20);

  mission_texture_audio();

  DAT_005a85fc = 1;

  return;

}

/* ===== Main/mission_00490940 @ 0x00490940 ===== */
void Main_mission_00490940(void)



{

  int iVar1;

  

  iVar1 = 0;

  do {

    *(undefined4 *)(iVar1 + 0x4550 + DAT_006330e4) = 0;

    iVar1 = iVar1 + 0x30;

  } while (iVar1 < 0x510);

  *(undefined4 *)(DAT_006330e4 + 0x4a60) = 0;

  return;

}

/* ===== scenerio_start_index__Fi @ 0x004909D0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void scenerio_start_index__Fi(int p0)



{

  mission_unload_mission_objects__Fv();

  *(int *)(DAT_006330e4 + 0x4a60) = p0;

  scenerio_start_mission__Fv();

  return;

}

/* ===== scenerio_start_mission__Fv @ 0x004909F0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: scenerio_start_mission__Fv (conf 0.418) */



void scenerio_start_mission__Fv(void)



{

  char *pcVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  _DAT_00632be8 = 0;

  _DAT_00632be4 = 0xbf800000;

  DAT_00632bec = 0;

  DAT_00632c04 = 0;

  _DAT_00632b60 = 0;

  iVar4 = *(int *)(DAT_006330e4 + 0x4a60) * 0x30;

  if (*(char *)(iVar4 + 0x4558 + DAT_006330e4) == '\0') {

    *(int *)(DAT_006330e4 + 0x4a60) = *(int *)(DAT_006330e4 + 0x4a60) + 1;

    return;

  }

  iVar4 = mission_init((char *)(iVar4 + 0x4558 + DAT_006330e4));

  if (iVar4 != 0) {

    _DAT_0059ef08 =

         *(float *)(*(int *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4578 + DAT_006330e4) * 0x118

                    + 0x2308 + DAT_006330e4);

    _DAT_00632be0 =

         _DAT_0059ef08 -

         *(float *)(*(int *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4578 + DAT_006330e4) * 0x118

                    + 0x230c + DAT_006330e4);

    if (_DAT_00632be0 < 0.0) {

      _DAT_00632be0 = 0.0;

    }

    *(undefined4 *)(DAT_006330e4 + 0x4a68) = 0;

    *(undefined4 *)(DAT_006330e4 + 0x4a64) = 0;

    *(undefined4 *)(DAT_006330e4 + 0x4a6c) =

         *(undefined4 *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4554 + DAT_006330e4);

    *(undefined4 *)(DAT_006330e4 + 0x4a74) = 0;

    *(undefined4 *)(DAT_006330e4 + 0x4a70) = 0;

    iVar5 = 0x20;

    iVar4 = DAT_006330e4;

    do {

      pcVar1 = (char *)(*(int *)(*(int *)(iVar4 + 0x4a60) * 0x30 + 0x4578 + iVar4) * 0x118 + 0x22c0

                       + iVar4);

      if (*pcVar1 != '\0') {

        flick_file_load_state(pcVar1);

        *(undefined4 *)

         (*(int *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4578 + DAT_006330e4) * 0x118 + 0x22e4

         + DAT_006330e4) = 1;

        iVar4 = DAT_006330e4;

      }

      puVar2 = DAT_00632d68;

      iVar3 = DAT_00632d20;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

    iVar5 = DAT_00632d20 * 0x20;

    *(undefined4 *)

     (&DAT_00634404 + (*(int *)(*(int *)(iVar4 + 0x4a60) * 0x30 + 0x4578 + iVar4) + iVar5) * 4) = 0;

    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

      if ((*(uint *)(puVar2[3] + 0xd8) & 0x400) != 0) {

        *(int *)(&DAT_00634404 +

                (*(int *)(*(int *)(iVar4 + 0x4a60) * 0x30 + 0x4578 + iVar4) + iVar5) * 4) =

             *(int *)(&DAT_00634404 +

                     (*(int *)(*(int *)(iVar4 + 0x4a60) * 0x30 + 0x4578 + iVar4) + iVar5) * 4) +

             *(int *)(puVar2[3] + 0x1c4);

      }

    }

    DAT_00633380 = DAT_00633380 | 1 << ((byte)iVar3 & 0x1f);

    (&DAT_00633384)[iVar3] =

         (&DAT_00633384)[iVar3] |

         1 << ((byte)*(undefined4 *)(*(int *)(iVar4 + 0x4a60) * 0x30 + 0x4578 + iVar4) & 0x1f);

    savegame_verify();

    *(int *)(DAT_006330e4 + 0x4a60) = *(int *)(DAT_006330e4 + 0x4a60) + 1;

    return;

  }

  *(int *)(DAT_006330e4 + 0x4a60) = *(int *)(DAT_006330e4 + 0x4a60) + 1;

  return;

}

/* ===== scenario_list_load @ 0x00490C50 ===== */
void scenario_list_load(int param_1,undefined4 param_2,char *param_3)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  undefined1 local_200 [512];

  

  iVar1 = 0;

  piVar3 = (int *)(DAT_006330e4 + 0x4550);

  do {

    if (*piVar3 == 0) {

      if (iVar1 < 0x1b) {

        iVar1 = iVar1 * 0x30;

        *(int *)(iVar1 + 0x4550 + DAT_006330e4) = param_1;

        *(undefined4 *)(iVar1 + 0x4554 + DAT_006330e4) = param_2;

        _strncpy((char *)(iVar1 + 0x4558 + DAT_006330e4),param_3,0x20);

        if (param_1 != 2) {

          return;

        }

        iVar4 = 0;

        iVar5 = 0;

        do {

          iVar2 = FUN_00545650(iVar5 + 0x2210 + DAT_006330e4,param_3);

          if (iVar2 == 0) {

            *(int *)(iVar1 + 0x4578 + DAT_006330e4) = iVar4;

            return;

          }

          iVar5 = iVar5 + 0x118;

          iVar4 = iVar4 + 1;

        } while (iVar5 < 0x2300);

        return;

      }

      break;

    }

    iVar1 = iVar1 + 1;

    piVar3 = piVar3 + 0xc;

  } while (iVar1 < 0x1b);

  crt_sprintf(local_200,s_Too_many_scenerios__skipping___d_0055c6e4,0x1b);

  FUN_0051ea20(local_200);

  return;

}

/* ===== FUN_00490d40 @ 0x00490D40 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: __get_eh_context_2 (conf 0.861) */



void FUN_00490d40(void)



{

  DAT_0055c4a8 = 100;

  _DAT_0059f324 = 0;

  _DAT_0059f328 = 0;

                    /* WARNING: Could not recover jumptable at 0x00490d5e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*DAT_005dd31c)();

  return;

}

/* ===== showchat_mission_objective__Fi @ 0x00490D70 ===== */
/* PS2 candidate: showchat_mission_objective__Fi (conf 0.421) */



void showchat_mission_objective__Fi(void)



{

  char cVar1;

  char cVar2;

  char *pcVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  char *pcVar7;

  int iVar8;

  char *pcVar9;

  char in_stack_00000028;

  undefined1 uStack00000029;

  undefined1 uStack0000002a;

  int in_stack_0000102c;

  

  crt_chkstk_probe();

  if ((DAT_00632f08 == 0) && (in_stack_0000102c < 0x1a)) {

    controlShutdown_2();

    iVar8 = in_stack_0000102c * 0x30;

    in_stack_00000028 = '\f';

    uStack00000029 = 5;

    uStack0000002a = 0;

    pcVar3 = (char *)FUN_00507b00();

    uVar4 = 0xffffffff;

    do {

      pcVar7 = pcVar3;

      if (uVar4 == 0) break;

      uVar4 = uVar4 - 1;

      pcVar7 = pcVar3 + 1;

      cVar1 = *pcVar3;

      pcVar3 = pcVar7;

    } while (cVar1 != '\0');

    uVar4 = ~uVar4;

    iVar5 = -1;

    pcVar3 = &stack0x00000028;

    do {

      pcVar9 = pcVar3;

      if (iVar5 == 0) break;

      iVar5 = iVar5 + -1;

      pcVar9 = pcVar3 + 1;

      cVar1 = *pcVar3;

      pcVar3 = pcVar9;

    } while (cVar1 != '\0');

    pcVar3 = pcVar7 + -uVar4;

    pcVar7 = pcVar9 + -1;

    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;

      pcVar3 = pcVar3 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar7 = *pcVar3;

      pcVar3 = pcVar3 + 1;

      pcVar7 = pcVar7 + 1;

    }

    chat_insert();

    chat_insert();

    in_stack_00000028 = '\v';

    uStack00000029 = 6;

    uStack0000002a = 0;

    pcVar3 = (char *)FUN_00507b00();

    uVar4 = 0xffffffff;

    do {

      pcVar7 = pcVar3;

      if (uVar4 == 0) break;

      uVar4 = uVar4 - 1;

      pcVar7 = pcVar3 + 1;

      cVar1 = *pcVar3;

      pcVar3 = pcVar7;

    } while (cVar1 != '\0');

    uVar4 = ~uVar4;

    iVar5 = -1;

    pcVar3 = &stack0x00000028;

    do {

      pcVar9 = pcVar3;

      if (iVar5 == 0) break;

      iVar5 = iVar5 + -1;

      pcVar9 = pcVar3 + 1;

      cVar1 = *pcVar3;

      pcVar3 = pcVar9;

    } while (cVar1 != '\0');

    pcVar3 = pcVar7 + -uVar4;

    pcVar7 = pcVar9 + -1;

    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;

      pcVar3 = pcVar3 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar7 = *pcVar3;

      pcVar3 = pcVar3 + 1;

      pcVar7 = pcVar7 + 1;

    }

    chat_insert();

    _strncat(&stack0x00000000,(char *)(DAT_006330e4 + 0x4558 + iVar8),0x1c);

    pcVar3 = (char *)FUN_00507b00();

    iVar5 = crt_file_lock_ops();

    if (iVar5 != 0) {

      pcVar7 = &stack0x00000028;

      cVar1 = *pcVar3;

      while (cVar1 != '\0') {

        cVar1 = *pcVar3;

        if (cVar1 == '^') {

          *pcVar7 = '\n';

        }

        else if (((cVar1 == '~') && (cVar2 = pcVar3[1], '0' < cVar2)) && (cVar2 < ':')) {

          *pcVar7 = cVar2 + -0x30;

          pcVar3 = pcVar3 + 1;

        }

        else {

          *pcVar7 = cVar1;

        }

        pcVar9 = pcVar3 + 1;

        pcVar7 = pcVar7 + 1;

        pcVar3 = pcVar3 + 1;

        cVar1 = *pcVar9;

      }

      *pcVar7 = '\0';

      chat_insert_lf();

    }

    if (*(int *)(*(int *)(DAT_006330e4 + 0x4578 + iVar8) * 0x118 + 0x22e0 + DAT_006330e4) != 0) {

      iVar8 = *(int *)(*(int *)(DAT_006330e4 + 0x4578 + iVar8) * 0x118 + 0x22e0 + DAT_006330e4);

      if (iVar8 == 1) {

        FUN_00507b00();

        mission_objective_entry_lookup();

        crt_sprintf();

      }

      else if (iVar8 == 2) {

        FUN_00507b00();

        mission_objective_entry_lookup();

        mission_objective_entry_lookup();

        mission_objective_entry_lookup();

        mission_objective_entry_lookup();

        crt_sprintf();

      }

      chat_insert_lf();

    }

  }

  return;

}

/* ===== scenerio_process__Fv @ 0x00490FE0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: scenerio_process__Fv (conf 0.403) */



undefined4 scenerio_process__Fv(void)



{

  int *piVar1;

  undefined4 p0;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  

  if (DAT_006330dc == 0) {

    if (DAT_00632f08 == 0) {

      evilreaper_logic__FP6OBJECT();

    }

    if ((((DAT_00632c0c == 0) && (DAT_00632bb4 == 0)) && (DAT_006330e4 != 0)) &&

       ((DAT_00632bd8 == 0 && (DAT_00632bd0 == 0)))) {

      if ((DAT_0059f31c == 0) && (DAT_0059f31c = 1, DAT_00632f08 == 0)) {

        DAT_00633020 = 1;

        DAT_00633028 = 1;

        DAT_0063302c = 0;

        showchat_mission_objective__Fi(*(int *)(DAT_006330e4 + 0x4a60) + -1);

      }

      if (*(int *)(DAT_006330e4 + 0x4a6c) <= *(int *)(DAT_006330e4 + 0x4a68)) {

        if ((0 < *(int *)(DAT_006330e4 + 0x4a60)) &&

           (*(int *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4520 + DAT_006330e4) == 2)) {

          hud_feed_buffer_clear();

          DAT_00632c04 = 1;

          fVar4 = (float10)FUN_00518b70(0,0);

          fVar5 = (float10)_DAT_0059ef08;

          _DAT_0059ef08 = (float)(fVar5 - fVar4);

          if ((float10)0.0 < fVar5 - fVar4) {

            if (_DAT_00632b60 <= 0.0) {

              if (_DAT_0059ef08 < _DAT_00632be0) {

                _DAT_00632b60 = _DAT_00632be0 - _DAT_0059ef08;

              }

              DAT_0059f320 = 1;

              return 0;

            }

            fVar5 = (float10)FUN_00518b70(0,0);

            DAT_0059f320 = 1;

            _DAT_00632b60 = (float)(fVar5 + (float10)_DAT_00632b60);

            return 0;

          }

          DAT_0059f320 = 0;

          if ((DAT_0059f318 == 0) &&

             (*(char *)(*(int *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4548 + DAT_006330e4) *

                        0x118 + 0x22e8 + DAT_006330e4) != '\0')) {

            DAT_0059f318 = 1;

            flick_file_load_state

                      (*(int *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4548 + DAT_006330e4) *

                       0x118 + 0x22e8 + DAT_006330e4);

            return 0;

          }

          DAT_0055c4a8 = 100;

          (*DAT_005dd31c)();

          iVar3 = DAT_006330e4;

          iVar2 = DAT_00632d20 * 0x20 + *(int *)(DAT_006330e4 + 0x4a60);

          if (*(int *)(&DAT_00633400 + iVar2 * 4) < *(int *)(DAT_006330e4 + 0x4a64)) {

            *(int *)(&DAT_00633400 + iVar2 * 4) = *(int *)(DAT_006330e4 + 0x4a64);

          }

          iVar2 = *(int *)(iVar3 + 0x4a60);

          if (iVar2 < 0x20) {

            piVar1 = (int *)(iVar2 * 0x30 + 0x4550 + iVar3);

            do {

              if (*piVar1 == 2) break;

              iVar2 = iVar2 + 1;

              piVar1 = piVar1 + 0xc;

            } while (iVar2 < 0x20);

          }

          save_mission_continuity__Fv();

          if (iVar2 < 0x20) {

            level_config_write(DAT_00632d20,iVar2,*(undefined4 *)(DAT_00632a88 + 4));

          }

          savegame_verify();

        }

        DAT_0059f318 = 0;

        DAT_0059f31c = 0;

        if (*(int *)(DAT_006330e4 + 0x4a60) < 0x1b) {

          mission_unload_mission_objects__Fv();

          iVar3 = *(int *)(DAT_006330e4 + 0x4a60) * 0x30;

          switch(*(undefined4 *)(iVar3 + 0x4550 + DAT_006330e4)) {

          case 1:

            flick_file_load_state(iVar3 + DAT_006330e4 + 0x4558);

            *(int *)(DAT_006330e4 + 0x4a60) = *(int *)(DAT_006330e4 + 0x4a60) + 1;

            return 1;

          case 2:

            scenerio_start_mission__Fv();

            return 1;

          case 3:

            DAT_0055c4a8 = 100;

            _DAT_0059f324 = 0;

            _DAT_0059f328 = 0;

            (*DAT_005dd31c)();

            DAT_0059f300 = *(undefined4 *)(DAT_00632a88 + 4);

            p0 = session_table_lookup

                           (*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4558 + DAT_006330e4);

            *(undefined4 *)(DAT_006330e4 + 0x4a60) = 0x1b;

            AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_4(p0);

            mission_texture_audio();

            return 1;

          case 4:

            *(int *)(DAT_006330e4 + 0x4a60) = *(int *)(DAT_006330e4 + 0x4a60) + 1;

            FUN_004907e0();

            return 0;

          default:

            *(undefined4 *)(DAT_006330e4 + 0x4a6c) = 9999999;

            *(undefined4 *)(DAT_006330e4 + 0x4a68) = 1;

          }

        }

      }

    }

  }

  return 0;

}

/* ===== evilreaper_logic__FP6OBJECT @ 0x00491380 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: evilreaper_logic__FP6OBJECT (conf 0.502) */



void evilreaper_logic__FP6OBJECT(void)



{

  float fVar1;

  undefined4 *puVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  undefined4 uVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  float10 fVar10;

  float10 fVar11;

  

  iVar9 = DAT_0055c4a8;

  if (DAT_00632a88 == 0) {

    return;

  }

  if (DAT_00633204 != 0) {

    return;

  }

  fVar10 = (float10)FUN_00518b70(0,0);

  _DAT_0059f324 = (float)((float10)_DAT_0059f324 - fVar10);

  iVar5 = (*DAT_005dd328)();

  if (iVar5 != 0) {

    if (DAT_0055c4a8 != 100) {

      return;

    }

    fVar10 = (float10)FUN_00518b70(0,0);

    _DAT_0059f328 = (float)((float10)_DAT_0059f328 - fVar10);

    return;

  }

  if (_DAT_0059f324 < 0.0 == (_DAT_0059f324 == 0.0)) {

    if (DAT_0055c4a8 == 100) {

      fVar10 = (float10)FUN_00518b70(0,0);

      fVar10 = (float10)_DAT_0059f328 - fVar10;

      goto LAB_00491aab;

    }

    goto LAB_00491ab1;

  }

  iVar5 = 0;

  iVar8 = 0;

  _DAT_0059f324 = 0.1;

  iVar9 = DAT_0055c4a8;

  iVar7 = DAT_00632a88;

  for (puVar2 = DAT_00632d6c; DAT_0055c4a8 = iVar9, DAT_00632a88 = iVar7,

      puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar9 = puVar2[3];

    if ((*(uint *)(iVar9 + 0x1c8) & 0x10000000) == 0) goto LAB_0049156a;

    iVar7 = *(int *)(iVar9 + 4);

    if (iVar7 == 0xd7) {

      uVar6 = **(undefined4 **)(iVar9 + 0x100);

LAB_00491511:

      iVar7 = ObjIsPlayer(uVar6);

      if (iVar7 == 0) {

        if ((iVar5 == 0) && (iVar8 < *(int *)(DAT_00632ed8 + 0x15bc))) {

LAB_0049153f:

          fVar1 = *(float *)(DAT_00632ed8 + 0x15c4);

          goto LAB_00491545;

        }

      }

      else {

        iVar5 = iVar5 + 1;

      }

    }

    else {

      if ((iVar7 == 0x49) || (iVar7 == 0xe6)) {

        uVar6 = *(undefined4 *)(*(int *)(iVar9 + 0x100) + 0xc);

        goto LAB_00491511;

      }

      if ((iVar7 != 0x438) || (*(int *)(iVar9 + 0x1e0) != 99)) {

        if (iVar7 != 0x23f) goto LAB_0049156a;

        iVar7 = ObjIsPlayer(*(undefined4 *)(*(int *)(iVar9 + 0x100) + 0x28));

        if (iVar7 != 0) {

          iVar5 = iVar5 + 1;

          goto LAB_0049156a;

        }

        if ((iVar5 != 0) || (*(int *)(DAT_00632ed8 + 0x15bc) <= iVar8)) goto LAB_0049156a;

        goto LAB_0049153f;

      }

      iVar7 = ObjIsPlayer(*(undefined4 *)(*(int *)(iVar9 + 0x100) + 0x3c));

      if (iVar7 != 0) {

        iVar5 = iVar5 + 1;

        goto LAB_0049156a;

      }

      if ((iVar5 != 0) || (*(int *)(DAT_00632ed8 + 0x15bc) <= iVar8)) goto LAB_0049156a;

      fVar1 = *(float *)(DAT_00632ed8 + 0x15c4);

LAB_00491545:

      fVar10 = (float10)FUN_0050a610(iVar9 + 0xa0,DAT_00632a88 + 0xa0);

      if (fVar10 <= (float10)fVar1 * (float10)fVar1) {

        iVar8 = iVar8 + 1;

      }

    }

LAB_0049156a:

    iVar9 = DAT_0055c4a8;

    iVar7 = DAT_00632a88;

  }

  iVar4 = iVar9;

  switch(iVar9) {

  case 0:

    if (*(int *)(DAT_00632ed8 + 0x15b8) < iVar5) {

      iVar9 = 3;

      DAT_0059f32c = iVar5;

      goto LAB_00491abd;

    }

    if (iVar5 < *(int *)(DAT_00632ed8 + 0x15c0)) {

      return;

    }

    iVar9 = ObjIsKabuto(iVar7);

    if (iVar9 == 0) {

      iVar9 = crt_rand_scaled(100);

      iVar9 = ((0x31 < iVar9) - 1 & 0xd) + 1;

    }

    else {

      iVar9 = crt_rand_scaled(100);

      if (iVar9 < 0x21) {

        iVar9 = 0xe;

      }

      else {

        iVar9 = ((0x41 < iVar9) - 1 & 0xfffffff1) + 0x10;

      }

    }

    break;

  case 1:

  case 0xe:

  case 0x10:

    iVar8 = (*DAT_005dd324)();

    if (iVar8 == 0) {

      iVar9 = 100;

    }

    if (*(int *)(DAT_00632ed8 + 0x15b8) < iVar5) {

      iVar9 = 3;

      DAT_0059f32c = iVar5;

      break;

    }

    if (iVar5 != 0) break;

    if (DAT_0055c4a8 == 0xe) {

      iVar9 = 0xf;

    }

    else {

      if (DAT_0055c4a8 != 1) {

        iVar9 = 0x11;

        break;

      }

      iVar9 = 2;

    }

    goto LAB_00491abd;

  case 2:

  case 4:

  case 7:

  case 8:

  case 0xf:

  case 0x11:

    iVar5 = (*DAT_005dd324)();

    if (iVar5 == 0) {

      iVar9 = 100;

    }

    break;

  case 3:

    iVar8 = (*DAT_005dd324)();

    if (iVar8 == 0) {

      iVar9 = 100;

    }

    if (*(float *)(DAT_00632a88 + 0x278) < *(float *)(DAT_00632a88 + 0x1c0)) {

      if (*(float *)(DAT_00632ed8 + 0x15cc) * (float)*(int *)(DAT_00632ed8 + 0x15b8) <= (float)iVar5

         ) {

        if (*(int *)(DAT_00632ed8 + 0x15c8) < iVar5) {

          iVar9 = 9;

        }

      }

      else {

        iVar9 = 5;

      }

    }

    else {

      iVar9 = 4;

    }

    break;

  case 5:

    (*DAT_005dd324)();

    if (*(float *)(DAT_00632a88 + 0x278) < *(float *)(DAT_00632a88 + 0x1c0)) {

      if ((float)iVar5 / *(float *)(DAT_00632ed8 + 0x15cc) <= (float)*(int *)(DAT_00632ed8 + 0x15b8)

         ) {

        iVar9 = ((iVar5 < 1) - 1 & 0xfffffffd) + 8;

      }

      else {

        iVar9 = 3;

        DAT_0059f32c = iVar5;

      }

    }

    else {

      iVar9 = 7;

    }

    break;

  default:

    goto switchD_00491591_caseD_6;

  case 9:

    iVar8 = (*DAT_005dd324)();

    if (iVar8 == 0) {

      iVar9 = 100;

    }

    if (*(float *)(DAT_00632a88 + 0x278) < *(float *)(DAT_00632a88 + 0x1c0)) {

      if (iVar5 < DAT_0059f32c) {

        iVar9 = 3;

        DAT_0059f32c = iVar5;

      }

    }

    else {

      iVar9 = 7;

    }

    break;

  case 0xb:

  case 0xc:

    iVar8 = (*DAT_005dd324)();

    if (iVar8 == 0) {

      iVar9 = 100;

    }

    else if (*(float *)(DAT_00632a88 + 0x278) < *(float *)(DAT_00632a88 + 0x1c0)) {

      if (*(int *)(DAT_00632ed8 + 0x15b8) < iVar5) {

        iVar9 = 3;

        DAT_0059f32c = iVar5;

      }

      else if (*(int *)(DAT_00632ed8 + 0x15c0) <= iVar5) {

        iVar9 = ObjIsKabuto(DAT_00632a88);

        goto LAB_00491945;

      }

    }

    break;

  case 0xd:

    iVar7 = (*DAT_005dd324)();

    iVar8 = DAT_00632a88;

    if (iVar7 == 0) {

      iVar9 = 100;

    }

    else {

      iVar7 = ObjIsMecc(DAT_00632a88);

      if (iVar7 == 0) {

        iVar7 = ObjIsReaper(iVar8);

        if (iVar7 != 0) {

          uVar3 = *(uint *)(*(int *)(iVar8 + 0x100) + 0xe2c);

          goto LAB_00491875;

        }

      }

      else {

        uVar3 = *(uint *)(iVar8 + 0xe0) & 0x2000000;

LAB_00491875:

        if (uVar3 != 0) break;

      }

      if ((*(float *)(DAT_00632a88 + 0x278) < *(float *)(DAT_00632a88 + 0x1c0)) &&

         (*(int *)(DAT_00632ed8 + 0x15b8) < iVar5)) {

        iVar9 = 3;

        DAT_0059f32c = iVar5;

      }

    }

    break;

  case 100:

    if (*(float *)(iVar7 + 0x1c0) <= *(float *)(iVar7 + 0x278)) {

      return;

    }

    if (*(int *)(DAT_00632ed8 + 0x15b8) < iVar5) {

      fVar10 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x1674),

                                      *(undefined4 *)(DAT_00632ed8 + 0x1678));

      iVar9 = 3;

      DAT_0059f32c = iVar5;

LAB_00491aab:

      _DAT_0059f328 = (float)fVar10;

    }

    else {

      if (*(int *)(DAT_00632ed8 + 0x15c0) <= iVar5) {

        fVar10 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x1674),

                                        *(undefined4 *)(DAT_00632ed8 + 0x1678));

        _DAT_0059f328 = (float)fVar10;

        iVar9 = ObjIsKabuto(DAT_00632a88);

LAB_00491945:

        if (iVar9 == 0) {

          iVar9 = crt_rand_scaled(100);

          iVar9 = ((0x31 < iVar9) - 1 & 0xd) + 1;

        }

        else {

          iVar9 = crt_rand_scaled(100);

          if (iVar9 < 0x21) {

            iVar9 = 0xe;

          }

          else {

            iVar9 = ((0x41 < iVar9) - 1 & 0xfffffff1) + 0x10;

          }

        }

        break;

      }

      if (*(int *)(DAT_00632ed8 + 0x15bc) <= iVar8) {

        fVar10 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x1674),

                                        *(undefined4 *)(DAT_00632ed8 + 0x1678));

        iVar9 = 0;

        goto LAB_00491aab;

      }

      iVar5 = ObjIsMecc(iVar7);

      if (iVar5 == 0) {

        iVar5 = ObjIsReaper(iVar7);

        if (iVar5 != 0) {

          uVar3 = *(uint *)(*(int *)(iVar7 + 0x100) + 0xe2c);

          goto joined_r0x00491a63;

        }

      }

      else {

        uVar3 = *(uint *)(iVar7 + 0xe0) & 0x2000000;

joined_r0x00491a63:

        if (uVar3 != 0) {

          fVar10 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x1674),

                                          *(undefined4 *)(DAT_00632ed8 + 0x1678));

          iVar9 = 0xd;

          goto LAB_00491aab;

        }

      }

      fVar11 = (float10)FUN_00518b70(0,0);

      fVar10 = (float10)_DAT_0059f328;

      _DAT_0059f328 = (float)(fVar10 - fVar11);

      if (fVar10 - fVar11 < (float10)0.0) {

        fVar10 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x1674),

                                        *(undefined4 *)(DAT_00632ed8 + 0x1678));

        _DAT_0059f328 = (float)fVar10;

        iVar9 = crt_rand_scaled(100);

        iVar9 = (0x31 < iVar9) + 0xb;

      }

    }

  }

LAB_00491ab1:

  iVar4 = DAT_0055c4a8;

  if (iVar9 != DAT_0055c4a8) {

LAB_00491abd:

    _DAT_0059f324 = 5.0;

    iVar4 = iVar9;

    if (iVar9 == 100) {

      (*DAT_005dd31c)();

    }

    else {

      iVar5 = ObjIsKabuto(DAT_00632a88);

      if (iVar5 != 0) {

        (*DAT_005dd318)((&PTR_PTR_0055c4f8)[iVar9]);

        DAT_0055c4a8 = iVar9;

        return;

      }

      iVar5 = ObjIsMecc(DAT_00632a88);

      if (iVar5 != 0) {

        (*DAT_005dd318)((&PTR_PTR_0055c4b0)[iVar9]);

        DAT_0055c4a8 = iVar9;

        return;

      }

      iVar5 = ObjIsReaper(DAT_00632a88);

      if (iVar5 != 0) {

        (*DAT_005dd318)((&PTR_PTR_0055c540)[iVar9]);

        DAT_0055c4a8 = iVar9;

        return;

      }

    }

  }

switchD_00491591_caseD_6:

  DAT_0055c4a8 = iVar4;

  return;

}

/* ===== mission_level_load @ 0x00491C00 ===== */
void mission_level_load(undefined4 param_1)



{

  char *pcVar1;

  int iVar2;

  

  *(undefined4 *)(DAT_00632bd4 * 0x30 + 0x4550 + DAT_006330e4) = 3;

  pcVar1 = (char *)FUN_004b0a60(param_1);

  _strncpy((char *)(DAT_00632bd4 * 0x30 + 0x4558 + DAT_006330e4),pcVar1,0x20);

  iVar2 = DAT_00632bd4 * 0x30 + DAT_006330e4;

  switch(*(undefined4 *)(iVar2 + 0x4550)) {

  case 0:

    pcVar1 = &DAT_0055c72c;

    goto LAB_00491cd0;

  case 1:

    crt_sprintf(&DAT_0059f170,s_Cutscene_____s_0055c768,iVar2 + 0x4558);

    break;

  case 2:

    crt_sprintf(&DAT_0059f170,s_Mission_____s_____d_0055c744,iVar2 + 0x4558,

                *(undefined4 *)(iVar2 + 0x4554));

    break;

  case 3:

    crt_sprintf(&DAT_0059f170,s_New_Level_____s_0055c758,iVar2 + 0x4558);

    break;

  case 4:

    pcVar1 = s_Goto_Start_Menu_0055c734;

LAB_00491cd0:

    crt_sprintf(&DAT_0059f170,pcVar1);

  }

  main_dlog_00428080(DAT_0059f304,1,DAT_00632bd4,&DAT_0059f170);

  main_dlog_004277f0(DAT_0059f308,1,&DAT_0059f170);

  return;

}

/* ===== camera_attach_path_object @ 0x00491D30 ===== */
void camera_attach_path_object(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  

  puVar4 = DAT_00632d68;

  if ((param_1 == 0x85) || (param_1 == 2)) {

    iVar3 = 1;

  }

  else {

    iVar3 = (param_1 != 3) + 2;

  }

  while( true ) {

    if (puVar4 == (undefined4 *)0x0) {

      return;

    }

    iVar1 = puVar4[3];

    if (((((*(uint *)(iVar1 + 0x1c8) & 0x8000000) != 0) && ((*(byte *)(iVar1 + 0xd9) & 0x80) == 0))

        && (*(int *)(iVar1 + 0x174) == 0)) &&

       ((*(int *)(iVar1 + 0xe8) == iVar3 && (*(int *)(iVar1 + 4) == 0x2a7)))) break;

    puVar4 = (undefined4 *)*puVar4;

  }

  puVar4 = (undefined4 *)(iVar1 + 0x294);

  puVar5 = (undefined4 *)(DAT_00632a88 + 0x294);

  for (iVar3 = 0x11; iVar2 = DAT_00632a88, iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

  }

  *(undefined4 *)(DAT_00632a88 + 0xa0) = *(undefined4 *)(iVar1 + 0xa0);

  *(undefined4 *)(iVar2 + 0xa4) = *(undefined4 *)(iVar1 + 0xa4);

  *(undefined4 *)(iVar2 + 0xa8) = *(undefined4 *)(iVar1 + 0xa8);

  *(undefined4 *)(DAT_00632a88 + 200) = *(undefined4 *)(iVar1 + 200);

  *(undefined4 *)(DAT_00632a88 + 0xcc) = *(undefined4 *)(iVar1 + 0xcc);

  *(undefined4 *)(DAT_00632a88 + 0xd0) = *(undefined4 *)(iVar1 + 0xd0);

  if ((param_1 != 0x85) && (param_1 != 2)) {

    return;

  }

  obj_path_follow();

  return;

}

/* ===== savegame_load @ 0x00491E30 ===== */
void savegame_load(void)



{

  int iVar1;

  undefined4 *puVar2;

  char *pcVar3;

  undefined1 *puVar4;

  undefined1 *local_88;

  int local_84;

  undefined1 local_80 [128];

  

  puVar2 = &DAT_00633380;

  for (iVar1 = 0x8c21; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_00637404;

  for (iVar1 = 0x4800; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0xffffffff;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_00637404;

  for (iVar1 = 0x6c00; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0xffffffff;

    puVar2 = puVar2 + 1;

  }

  mission_0051a0c0(s_SaveGameVersion_0055c7b0,&local_84);

  if (local_84 == 0x11) {

    local_88 = (undefined1 *)0xffffffff;

    keymap_0051a100(s_SaveIdx_00555edc,&local_88);

    if (local_88 == (undefined1 *)0xffffffff) {

      pcVar3 = s_savegame__s_mission_sav_0055c798;

      puVar4 = &DAT_0063304c;

    }

    else {

      pcVar3 = s_savegame_SaveGame_d_mission_sav_0055c778;

      puVar4 = local_88;

    }

    crt_sprintf(local_80,pcVar3,puVar4);

    iVar1 = BinFileSeek_2(local_80,&DAT_00555e04);

    if (iVar1 != 0) {

      file_read_locked(&DAT_00633380,0x23084,1,iVar1);

      editor_0054384c(iVar1);

    }

  }

  return;

}

/* ===== savegame_verify @ 0x00491F10 ===== */
void savegame_verify(void)



{

  int iVar1;

  char *pcVar2;

  undefined1 *puVar3;

  undefined1 *local_84;

  CHAR local_80 [128];

  

  comm_0051a130(s_SaveGameVersion_0055c7b0,0x11);

  crt_sprintf(local_80,s___savegame_00555ee4);

  CreateDirectoryA(local_80,(LPSECURITY_ATTRIBUTES)0x0);

  local_84 = (undefined1 *)0xffffffff;

  keymap_0051a100(s_SaveIdx_00555edc,&local_84);

  if (local_84 == (undefined1 *)0xffffffff) {

    crt_sprintf(local_80,s___savegame__s_00555ecc,&DAT_0063304c);

    CreateDirectoryA(local_80,(LPSECURITY_ATTRIBUTES)0x0);

    pcVar2 = s_savegame__s_mission_sav_0055c798;

    puVar3 = &DAT_0063304c;

  }

  else {

    crt_sprintf(local_80,s___savegame_SaveGame_d_00555e7c,local_84);

    CreateDirectoryA(local_80,(LPSECURITY_ATTRIBUTES)0x0);

    pcVar2 = s_savegame_SaveGame_d_mission_sav_0055c778;

    puVar3 = local_84;

  }

  crt_sprintf(local_80,pcVar2,puVar3);

  iVar1 = BinFileSeek_2(local_80,&DAT_00555e30);

  if (iVar1 != 0) {

    file_write_locked(&DAT_00633380,0x23084,1,iVar1);

    editor_0054384c(iVar1);

  }

  return;

}

/* ===== level_config_write @ 0x00492010 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void level_config_write(int param_1,int param_2,int param_3)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  int iVar6;

  int iVar7;

  undefined4 *puVar8;

  undefined4 *puVar9;

  

  if (param_2 < 0x20) {

    param_2 = param_2 + param_1 * 0x20;

    *(undefined4 *)(&DAT_00635404 + param_2 * 4) = DAT_0059f278;

    *(int *)(&DAT_00636404 + param_2 * 4) = param_3;

    uVar5 = _DAT_0059f2ec;

    uVar4 = _DAT_0059f2cc;

    uVar3 = DAT_0059f2c8;

    uVar2 = DAT_0059f288;

    uVar1 = DAT_0059f284;

    if (param_3 == 2) {

      puVar8 = (undefined4 *)&DAT_0059f280;

      puVar9 = &DAT_00637404 + param_2 * 0x12;

      for (iVar6 = 0x12; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar9 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

      }

      *(undefined4 *)(&DAT_0064b404 + param_2 * 4) = uVar4;

      uVar1 = DAT_0059f2d0;

      *(undefined4 *)(&DAT_00649404 + param_2 * 4) = uVar3;

      *(undefined4 *)(&DAT_0064c404 + param_2 * 4) = uVar1;

      return;

    }

    if (param_3 == 3) {

      iVar7 = param_2 * 0x6c;

      puVar8 = &DAT_0059f2bc;

      puVar9 = (undefined4 *)(&DAT_00637440 + iVar7);

      for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar9 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

      }

      puVar8 = (undefined4 *)&DAT_0059f280;

      puVar9 = &DAT_00637404 + param_2 * 0x1b;

      for (iVar6 = 0xf; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar9 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

      }

      *(undefined4 *)(&DAT_00637460 + iVar7) = DAT_0059f2dc;

      *(undefined4 *)(&DAT_00637464 + iVar7) = DAT_0059f2e0;

      *(undefined4 *)(&DAT_00637468 + iVar7) = DAT_0059f2e4;

      *(undefined4 *)(&DAT_0063746c + iVar7) = DAT_0059f2e8;

      uVar1 = DAT_0059f2f0;

      *(undefined4 *)(&DAT_00652404 + param_2 * 4) = DAT_0059f2f4;

      *(undefined4 *)(&DAT_00655404 + param_2 * 4) = uVar1;

      *(undefined4 *)(&DAT_00654404 + param_2 * 4) = uVar5;

      return;

    }

    if (param_3 == 1) {

      (&DAT_00637404)[param_2] = _DAT_0059f280;

      *(undefined4 *)(&DAT_00638404 + param_2 * 4) = uVar1;

      *(undefined4 *)(&DAT_00639404 + param_2 * 4) = uVar2;

      *(undefined4 *)(&DAT_0063a404 + param_2 * 4) = DAT_0059f28c;

    }

  }

  return;

}

/* ===== level_config_lookup @ 0x00492150 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void level_config_lookup(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  

  if ((param_1 != 0) || (param_2 != 0)) {

    param_2 = param_1 * 0x20 + param_2;

    DAT_0059f278 = *(int *)(&DAT_00635404 + param_2 * 4);

    DAT_0059f27c = *(undefined4 *)(&DAT_00636404 + param_2 * 4);

    if (DAT_0059f278 == 2) {

      _DAT_0059f2cc = *(undefined4 *)(&DAT_0064b404 + param_2 * 4);

      DAT_0059f2c8 = *(undefined4 *)(&DAT_00649404 + param_2 * 4);

      DAT_0059f2d0 = *(undefined4 *)(&DAT_0064c404 + param_2 * 4);

      DAT_0059f278 = 2;

      puVar3 = &DAT_00637404 + param_2 * 0x12;

      puVar4 = (undefined4 *)&DAT_0059f280;

      for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar4 = *puVar3;

        puVar3 = puVar3 + 1;

        puVar4 = puVar4 + 1;

      }

      return;

    }

    if (DAT_0059f278 == 3) {

      _DAT_0059f2ec = *(undefined4 *)(&DAT_00654404 + param_2 * 4);

      iVar2 = param_2 * 0x6c;

      DAT_0059f278 = 3;

      puVar3 = (undefined4 *)(&DAT_00637440 + iVar2);

      puVar4 = &DAT_0059f2bc;

      for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar4 = *puVar3;

        puVar3 = puVar3 + 1;

        puVar4 = puVar4 + 1;

      }

      puVar3 = &DAT_00637404 + param_2 * 0x1b;

      puVar4 = (undefined4 *)&DAT_0059f280;

      for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar4 = *puVar3;

        puVar3 = puVar3 + 1;

        puVar4 = puVar4 + 1;

      }

      DAT_0059f2dc = *(undefined4 *)(&DAT_00637460 + iVar2);

      DAT_0059f2e0 = *(undefined4 *)(&DAT_00637464 + iVar2);

      DAT_0059f2e4 = *(undefined4 *)(&DAT_00637468 + iVar2);

      DAT_0059f2e8 = *(undefined4 *)(&DAT_0063746c + iVar2);

      DAT_0059f2f4 = *(undefined4 *)(&DAT_00652404 + param_2 * 4);

      DAT_0059f2f0 = *(undefined4 *)(&DAT_00655404 + param_2 * 4);

      return;

    }

    if (DAT_0059f278 == 1) {

      DAT_0059f288 = *(undefined4 *)(&DAT_00639404 + param_2 * 4);

      _DAT_0059f280 = (&DAT_00637404)[param_2];

      DAT_0059f284 = *(undefined4 *)(&DAT_00638404 + param_2 * 4);

      DAT_0059f28c = *(undefined4 *)(&DAT_0063a404 + param_2 * 4);

    }

  }

  return;

}

/* ===== save_mission_continuity__Fv @ 0x00492290 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: save_mission_continuity__Fv (conf 0.432) */



void save_mission_continuity__Fv(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  uint uVar5;

  undefined4 *puVar6;

  float10 fVar7;

  

  iVar1 = ObjIsMecc(DAT_00632a88);

  iVar2 = DAT_00632a88;

  if (iVar1 == 0) {

    iVar2 = ObjIsReaper(DAT_00632a88);

    if (iVar2 == 0) {

      iVar2 = ObjIsKabuto(DAT_00632a88);

      uVar5 = DAT_0059f284;

      if (iVar2 != 0) {

        _DAT_0059f280 = AddHud__4cHudP8cHudIcon(DAT_00632a88);

        _DAT_0059f280 = _DAT_0059f280 & 0xff;

        iVar2 = teammecc_get_slavecount(DAT_00632a88,0);

        if (iVar2 != 0) {

          fVar7 = (float10)FUN_0046b450(iVar2);

          DAT_0059f288 = (float)fVar7;

        }

        uVar5 = (uint)(iVar2 != 0);

        iVar2 = teammecc_get_slavecount(DAT_00632a88,1);

        if (iVar2 != 0) {

          uVar5 = uVar5 + 1;

          fVar7 = (float10)FUN_0046b450(iVar2);

          if (uVar5 == 1) {

            DAT_0059f288 = (float)fVar7;

          }

          else {

            DAT_0059f28c = (float)fVar7;

          }

        }

      }

    }

    else {

      iVar2 = *(int *)(DAT_00632a88 + 0x100);

      puVar4 = (undefined4 *)(iVar2 + 0xd78);

      puVar6 = &DAT_0059f2bc;

      for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar6 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar6 = puVar6 + 1;

      }

      puVar4 = (undefined4 *)(iVar2 + 0xd3c);

      puVar6 = (undefined4 *)&DAT_0059f280;

      for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar6 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar6 = puVar6 + 1;

      }

      DAT_0059f2dc = *(undefined4 *)(iVar2 + 0xd98);

      DAT_0059f2e0 = *(undefined4 *)(iVar2 + 0xd9c);

      DAT_0059f2e4 = *(undefined4 *)(iVar2 + 0xda0);

      DAT_0059f2e8 = *(undefined4 *)(iVar2 + 0xda4);

      _DAT_0059f2ec = *(undefined4 *)(iVar2 + 0xcec);

      DAT_0059f2f0 = *(undefined4 *)(iVar2 + 0xdb4);

      DAT_0059f2f4 = *(undefined4 *)(iVar2 + 0xdb0);

      uVar5 = DAT_0059f284;

    }

  }

  else {

    iVar1 = *(int *)(DAT_00632a88 + 0x100);

    puVar4 = (undefined4 *)(iVar1 + 0x148);

    puVar6 = (undefined4 *)&DAT_0059f280;

    for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar6 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar6 = puVar6 + 1;

    }

    _DAT_0059f2cc = *(undefined4 *)(iVar1 + 0x4c);

    DAT_0059f2d0 = *(undefined4 *)(iVar1 + 0x60);

    iVar2 = team_count(iVar2);

    DAT_0059f2c8 = iVar2 + -1;

    uVar5 = DAT_0059f284;

  }

  DAT_0059f284 = uVar5;

  DAT_0059f278 = *(undefined4 *)(DAT_00632a88 + 4);

  DAT_0059f27c = *(undefined4 *)(DAT_00632a88 + 4);

  return;

}

/* ===== load_mission_continuity__Fii @ 0x00492430 ===== */
/* PS2 candidate: load_mission_continuity__Fii (conf 0.605) */



void load_mission_continuity__Fii(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  undefined4 *puVar6;

  int *piVar7;

  int *piVar8;

  int iVar9;

  undefined4 *puVar10;

  bool bVar11;

  

  if (param_1 == 0xc) {

    bVar11 = DAT_0059f278 == 3;

  }

  else {

    if (param_1 != 5) goto LAB_00492458;

    bVar11 = DAT_0059f278 == 2;

  }

  if (bVar11) {

    return;

  }

LAB_00492458:

  FUN_0049a030(DAT_00632a88);

  iVar1 = DAT_0059f278;

  if ((*(int *)(DAT_006330e4 + 0x4e84) != 0) && (DAT_0059f278 == 2)) {

    iVar1 = 0x85;

  }

  player_force_type(iVar1);

  if ((((param_1 != 0) && (param_1 != 0xc)) && (param_1 != 5)) || (param_2 != (int *)0x0)) {

    iVar1 = ObjIsMecc(DAT_00632a88);

    if (iVar1 == 0) {

      iVar1 = ObjIsKabuto(DAT_00632a88);

      if (iVar1 != 0) {

        kabuto_init(DAT_00632a88);

        reaper_ability_playersound4(DAT_00632a88,DAT_0059f280,1);

        if (DAT_0059f284 != 0) {

          uVar5 = kabuto_create_kbos(DAT_00632a88,0);

          reaper_lock_user_4(uVar5,DAT_0059f288,1);

          if (DAT_0059f284 == 2) {

            uVar5 = kabuto_create_kbos(DAT_00632a88,1);

            reaper_lock_user_4(uVar5,DAT_0059f28c,1);

          }

        }

        cam_mode_switch(1);

      }

    }

    else {

      iVar1 = team_count(DAT_00632a88);

      iVar1 = iVar1 + -1;

      if ((DAT_0059f2c8 < iVar1) && (iVar1 != 0)) {

        do {

          team_toggle(DAT_00632a88);

          iVar1 = team_count(DAT_00632a88);

        } while (iVar1 != 1);

        iVar1 = 0;

      }

      iVar9 = 0;

      if (DAT_0059f2c8 != iVar1 && -1 < DAT_0059f2c8 - iVar1) {

        do {

          team_toggle(DAT_00632a88);

          iVar9 = iVar9 + 1;

        } while (iVar9 < DAT_0059f2c8 - iVar1);

      }

    }

    if ((DAT_0059f27c != 0) && (DAT_0059f27c == *(int *)(DAT_00632a88 + 4))) {

      iVar1 = ObjIsMecc(DAT_00632a88);

      if (iVar1 != 0) {

        iVar1 = *(int *)(DAT_00632a88 + 0x100);

        TeamMemberClearWeapons__FP6OBJECT(DAT_00632a88);

        uVar5 = DAT_0059f2c4;

        DAT_0059f2c4 = 0xffffffff;

        puVar6 = (undefined4 *)&DAT_0059f280;

        puVar10 = (undefined4 *)(iVar1 + 0x148);

        for (iVar9 = 0x12; iVar9 != 0; iVar9 = iVar9 + -1) {

          *puVar10 = *puVar6;

          puVar6 = puVar6 + 1;

          puVar10 = puVar10 + 1;

        }

        iVar9 = 0;

        inv_award_item(DAT_00632a88,0xffffffff,uVar5,0,1);

        DAT_0059f2c4 = uVar5;

        WeaponIdSet__FP6OBJECTii(DAT_00632a88,0,1);

        *(undefined4 *)(iVar1 + 0x4c) = 0;

        reaper_lock_short_3(DAT_00632a88,DAT_0059f2d0);

        do {

          iVar1 = FUN_00457fb0(DAT_00632a88,iVar9);

          if ((iVar1 != -1) && (iVar2 = IconDefAmmoIcon(iVar1), iVar2 != -1)) {

            param_2 = (int *)0x0;

            item_get_ammo(DAT_00632a88,iVar2,&param_2);

            if (param_2 != (int *)0x0) {

              if (iVar1 == 5) {

                iVar3 = __ftol();

              }

              else {

                iVar3 = *param_2;

              }

              iVar4 = IconDefGiveAmmo(iVar1);

              if (iVar3 < iVar4) {

                *param_2 = 0;

                uVar5 = IconDefGiveAmmo(iVar1,1);

                inv_award_item(DAT_00632a88,0xffffffff,iVar2,uVar5);

              }

            }

          }

          iVar9 = iVar9 + 1;

        } while (iVar9 < 4);

        return;

      }

      iVar1 = ObjIsReaper(DAT_00632a88);

      if (iVar1 != 0) {

        iVar1 = *(int *)(DAT_00632a88 + 0x100);

        puVar6 = &DAT_0059f2bc;

        puVar10 = (undefined4 *)(iVar1 + 0xd78);

        for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {

          *puVar10 = *puVar6;

          puVar6 = puVar6 + 1;

          puVar10 = puVar10 + 1;

        }

        puVar6 = (undefined4 *)&DAT_0059f280;

        puVar10 = (undefined4 *)(iVar1 + 0xd3c);

        for (iVar9 = 0xf; iVar9 != 0; iVar9 = iVar9 + -1) {

          *puVar10 = *puVar6;

          puVar6 = puVar6 + 1;

          puVar10 = puVar10 + 1;

        }

        piVar8 = (int *)(iVar1 + 0xd98);

        *piVar8 = DAT_0059f2dc;

        *(undefined4 *)(iVar1 + 0xd9c) = DAT_0059f2e0;

        *(undefined4 *)(iVar1 + 0xda0) = DAT_0059f2e4;

        *(undefined4 *)(iVar1 + 0xda4) = DAT_0059f2e8;

        uVar5 = IconDefGiveAmmo(0x2c,0);

        reaper_set_bow(DAT_00632a88,0x2c,0,uVar5);

        *(undefined4 *)(iVar1 + 0xcec) = 0;

        *(undefined4 *)(iVar1 + 0xdb0) = DAT_0059f2f4;

        *(int *)(iVar1 + 0xdb4) = DAT_0059f2f0;

        obj_link_slot_clear(DAT_00632a88,0x21,0xffffffff,0);

        if (DAT_0059f2f0 < 1) {

          object_create_child(DAT_00632a88,1,0x29d);

        }

        else {

          uVar5 = IconDefWieldType(*(undefined4 *)(iVar1 + 0xd70 + *(int *)(iVar1 + 0xdb4) * 8),1);

          object_create_child(DAT_00632a88,1,uVar5);

        }

        piVar7 = (int *)(iVar1 + 0xd84);

        iVar1 = 3;

        do {

          if ((piVar7[-1] != -1) && (iVar9 = IconDefGiveAmmo(piVar7[-1]), *piVar7 < iVar9)) {

            *piVar7 = iVar9;

          }

          piVar7 = piVar7 + 2;

          iVar1 = iVar1 + -1;

        } while (iVar1 != 0);

        iVar1 = 2;

        do {

          if ((-1 < *piVar8) && (iVar9 = IconDefGiveAmmo(*piVar8), piVar8[1] < iVar9)) {

            iVar9 = IconDefGiveAmmo(*piVar8);

            piVar8[1] = iVar9;

          }

          piVar8 = piVar8 + 2;

          iVar1 = iVar1 + -1;

        } while (iVar1 != 0);

        return;

      }

      ObjIsKabuto(DAT_00632a88);

    }

  }

  return;

}

/* ===== savegame_verify_user @ 0x004928A0 ===== */
void savegame_verify_user(void)



{

  int iVar1;

  int *piVar2;

  

  if (DAT_0059f300 != 0) {

    iVar1 = 0;

    piVar2 = (int *)(DAT_006330e4 + 0x4550);

    do {

      if (*piVar2 == 2) break;

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 0xc;

    } while (iVar1 < 0x1b);

    *(undefined4 *)(DAT_00632a88 + 0x278) = 0;

    if (iVar1 < 0x1b) {

      level_config_write(DAT_00632d20,iVar1,DAT_0059f300);

    }

    savegame_verify();

    DAT_0059f300 = 0;

  }

  return;

}

/* ===== mission_init @ 0x00492910 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* PS2 candidate: mission_init__FPc (conf 0.712) */



undefined4 mission_init(char *p0)



{

  undefined4 uVar1;

  byte bVar2;

  int *piVar3;

  uint uVar4;

  byte *pbVar5;

  int iVar6;

  undefined4 uVar7;

  byte bVar8;

  int *piVar9;

  undefined4 *puVar10;

  int iVar11;

  byte *pbVar12;

  byte *pbVar13;

  int iVar14;

  int *piVar15;

  undefined4 *puVar16;

  bool bVar17;

  int local_13c;

  byte local_135;

  int local_134;

  int local_130;

  int local_12c;

  int local_124 [9];

  undefined1 local_100 [256];

  

  if ((p0 == (char *)0x0) || (DAT_006331f8 != 0)) {

    *(undefined4 *)(DAT_006330e4 + 0x50bc) = 0xffffffff;

    *(undefined4 *)(DAT_006330e4 + 0x4a68) = 0xffffffff;

    *(undefined4 *)(DAT_006330e4 + 0x4a6c) = 0xffffffff;

  }

  else {

    mission_0051a0c0(s_CamMode_00555a28,local_124);

    cam_mode_switch(local_124[0]);

    iVar14 = 0;

    pbVar5 = (byte *)(DAT_006330e4 + 0x4558);

    pbVar12 = (byte *)p0;

    pbVar13 = pbVar5;

LAB_00492964:

    do {

      bVar2 = *pbVar5;

      bVar17 = bVar2 < *pbVar12;

      if (bVar2 == *pbVar12) {

        if (bVar2 != 0) {

          bVar2 = pbVar5[1];

          bVar17 = bVar2 < pbVar12[1];

          if (bVar2 != pbVar12[1]) goto LAB_00492988;

          pbVar5 = pbVar5 + 2;

          pbVar12 = pbVar12 + 2;

          if (bVar2 != 0) goto LAB_00492964;

        }

        iVar6 = 0;

      }

      else {

LAB_00492988:

        iVar6 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

      }

      if (iVar6 == 0) break;

      iVar14 = iVar14 + 1;

      pbVar5 = pbVar13 + 0x30;

      pbVar12 = (byte *)p0;

      pbVar13 = pbVar5;

    } while (iVar14 < 0x1b);

    if (iVar14 == 0x1b) {

      return 0;

    }

    piVar9 = *(int **)(iVar14 * 0x30 + 0x457c + DAT_006330e4);

    if (piVar9 == (int *)0x0) {

      return 0;

    }

    if (*piVar9 != 4) {

      crt_sprintf(&DAT_00657400,s_Bad_Mission_Version__Mission_Mus_0055c848);

      FUN_0051ea20(&DAT_00657400);

      return 0;

    }

    local_13c = 0;

    pbVar13 = (byte *)(DAT_006330e4 + 0x2210);

    pbVar5 = (byte *)p0;

    pbVar12 = pbVar13;

LAB_00492a16:

    do {

      bVar2 = *pbVar13;

      bVar17 = bVar2 < *pbVar5;

      if (bVar2 == *pbVar5) {

        if (bVar2 != 0) {

          bVar2 = pbVar13[1];

          bVar17 = bVar2 < pbVar5[1];

          if (bVar2 != pbVar5[1]) goto LAB_00492a3a;

          pbVar13 = pbVar13 + 2;

          pbVar5 = pbVar5 + 2;

          if (bVar2 != 0) goto LAB_00492a16;

        }

        iVar14 = 0;

      }

      else {

LAB_00492a3a:

        iVar14 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);

      }

      if (iVar14 == 0) break;

      local_13c = local_13c + 1;

      pbVar13 = pbVar12 + 0x118;

      pbVar5 = (byte *)p0;

      pbVar12 = pbVar13;

    } while (local_13c < 0x20);

    if (local_13c == 0x20) {

      return 0;

    }

    *(int *)(DAT_006330e4 + 0x50bc) = local_13c;

    bVar17 = false;

    local_12c = 0;

    pbVar5 = (byte *)(piVar9 + 1);

    do {

      bVar2 = *pbVar5;

      pbVar12 = pbVar5 + 1;

      switch(bVar2) {

      case 1:

        break;

      case 2:

        bVar17 = true;

        break;

      case 3:

      case 4:

        uVar7 = *(undefined4 *)pbVar12;

        pbVar12 = pbVar5 + 5;

        iVar14 = object_find(uVar7);

        if ((iVar14 != 0) && (local_134 = object_allocate_type(uVar7,0x80000000), local_134 != 0)) {

          object_copy_personality(local_134,iVar14);

          object_copy_activedata(local_134,iVar14);

          *(undefined4 *)(local_134 + 0xa0) = *(undefined4 *)pbVar12;

          *(undefined4 *)(local_134 + 0xa4) = *(undefined4 *)(pbVar5 + 9);

          *(undefined4 *)(local_134 + 0xa8) = *(undefined4 *)(pbVar5 + 0xd);

          pbVar12 = pbVar5 + 0x15;

          *(undefined4 *)(local_134 + 200) = *(undefined4 *)(pbVar5 + 0x11);

          if (bVar2 == 4) {

            *(undefined4 *)(local_134 + 0xcc) = *(undefined4 *)pbVar12;

            *(undefined4 *)(local_134 + 0xd0) = *(undefined4 *)(pbVar5 + 0x19);

            pbVar12 = pbVar5 + 0x1d;

          }

          object_set_location(local_134,*(undefined4 *)(local_134 + 0xa0),

                              *(undefined4 *)(local_134 + 0xa4),*(undefined4 *)(local_134 + 0xa8));

          uVar4 = *(uint *)(local_134 + 0xd8);

          puVar10 = (undefined4 *)(iVar14 + 400);

          puVar16 = (undefined4 *)(local_134 + 400);

          for (iVar6 = 0x1e; iVar6 != 0; iVar6 = iVar6 + -1) {

            *puVar16 = *puVar10;

            puVar10 = puVar10 + 1;

            puVar16 = puVar16 + 1;

          }

          *(uint *)(local_134 + 0xdc) = *(uint *)(local_134 + 0xdc) | 0x20000000;

          *(uint *)(local_134 + 0xd8) = uVar4 | 0x400;

          ObjectCalculateTransform(local_134);

        }

        break;

      case 5:

        bVar8 = *pbVar12;

        pbVar12 = pbVar5 + 2;

        *(uint *)(local_134 + 0xe8) = (uint)bVar8;

        break;

      case 6:

        *(undefined4 *)(local_134 + 0xf4) = *(undefined4 *)pbVar12;

        *(undefined4 *)(local_134 + 0xf8) = *(undefined4 *)(pbVar5 + 5);

        *(undefined4 *)(local_134 + 0xfc) = *(undefined4 *)(pbVar5 + 9);

        pbVar12 = pbVar5 + 0xd;

        break;

      case 7:

        *(undefined4 *)(local_134 + 0x174) = *(undefined4 *)pbVar12;

        pbVar12 = pbVar5 + 5;

        break;

      case 8:

        bVar8 = *pbVar12;

        pbVar12 = pbVar5 + 2;

        *(uint *)(local_134 + 0xdc) = *(uint *)(local_134 + 0xdc) | bVar8 & 0xf;

        break;

      case 9:

        *(undefined4 *)(local_134 + 0xc4) = *(undefined4 *)pbVar12;

        pbVar12 = pbVar5 + 5;

        break;

      case 10:

        iVar14 = *(int *)(local_134 + 0x100);

        bVar8 = *pbVar12;

        pbVar12 = pbVar5 + 2;

        iVar6 = 0;

        if (bVar8 != 0) {

          do {

            uVar7 = *(undefined4 *)pbVar12;

            pbVar12 = pbVar12 + 4;

            *(undefined4 *)(iVar14 + iVar6 * 4) = uVar7;

            iVar6 = iVar6 + 1;

          } while (iVar6 < (int)(uint)bVar8);

        }

        break;

      case 0xb:

        DAT_0059f278 = *(int *)pbVar12;

        uVar7 = *(undefined4 *)(pbVar5 + 5);

        iVar14 = *(int *)(pbVar5 + 9);

        uVar1 = *(undefined4 *)(pbVar5 + 0xd);

        iVar6 = local_13c * 0x118;

        *(int *)(iVar6 + 0x2234 + DAT_006330e4) = DAT_0059f278;

        *(undefined4 *)(iVar6 + 0x228c + DAT_006330e4) = uVar7;

        *(int *)(iVar6 + 0x2294 + DAT_006330e4) = iVar14;

        pbVar12 = pbVar5 + 0x11;

        *(undefined4 *)(iVar6 + 0x2290 + DAT_006330e4) = uVar1;

        if ((DAT_0059f278 != 2) && (uVar7 = DAT_0059f2c8, DAT_0059f278 == 1)) {

          _DAT_0059f280 = uVar1;

        }

        DAT_0059f2c8 = uVar7;

        if (iVar14 != 0) {

          camera_attach_path_object(DAT_0059f278);

        }

        load_mission_continuity__Fii(DAT_00632d20,local_13c);

        break;

      case 0xc:

        uVar7 = *(undefined4 *)pbVar12;

        *(undefined4 *)(local_13c * 0x118 + 0x2298 + DAT_006330e4) = uVar7;

        pbVar12 = pbVar5 + 5;

        if (((*(uint *)(DAT_00632a88 + 0xdc) & 0x800000) != 0) && (DAT_00632d98 != 0)) {

          iVar14 = *(int *)(DAT_00632d98 + 0xc);

          if ((*(int *)(iVar14 + 0x1e0) == 0x12) && (*(int *)(iVar14 + 0x274) == DAT_00632a88)) {

            smartie_unlock_from_player(iVar14,*(int *)(iVar14 + 0x274),3);

          }

          object_destroy(iVar14);

        }

        iVar14 = object_allocate_type(uVar7,0x80000000);

        *(undefined4 *)(iVar14 + 0xe8) = 3;

        *(uint *)(iVar14 + 0xe0) = *(uint *)(iVar14 + 0xe0) | 0x20;

        *(undefined4 *)(iVar14 + 0xe4) = 3;

        *(uint *)(iVar14 + 0xd8) = *(uint *)(iVar14 + 0xd8) | 0x400;

        smartie_board_player__FP6OBJECTT0i(iVar14,DAT_00632a88,0);

        break;

      case 0xd:

        *(undefined4 *)(local_13c * 0x118 + 0x22e0 + DAT_006330e4) = *(undefined4 *)pbVar12;

        pbVar12 = pbVar5 + 5;

        break;

      case 0xe:

        if (*(int *)(DAT_00632a88 + 4) == 2) {

          iVar14 = local_13c * 0x118;

          *(undefined4 *)(iVar14 + 0x2238 + DAT_006330e4) = *(undefined4 *)pbVar12;

          pbVar12 = pbVar5 + 5;

          local_130 = 0;

          if (0 < *(int *)(iVar14 + 0x2238 + DAT_006330e4)) {

            iVar6 = iVar14 + 0x223c;

            do {

              *(undefined4 *)(iVar6 + DAT_006330e4) = *(undefined4 *)pbVar12;

              pbVar12 = pbVar12 + 4;

              iVar11 = player_has_weapon(DAT_00632a88,*(undefined4 *)(iVar6 + DAT_006330e4));

              if ((iVar11 == 0) && (iVar11 = FUN_00457d10(DAT_00632a88), iVar11 != 0)) {

                if (*(int *)(iVar6 + DAT_006330e4) != 1) {

                  inv_award_item(DAT_00632a88,0xffffffff,*(int *)(iVar6 + DAT_006330e4),0xffffffff,1

                                );

                }

              }

              else {

                iVar11 = FUN_00457d10(DAT_00632a88);

                if ((iVar11 == 0) &&

                   ((iVar11 = *(int *)(iVar6 + DAT_006330e4), iVar11 == 7 || (iVar11 == 0xe)))) {

                  iVar11 = item_drop_item(DAT_00632a88,iVar11,0xffffffff,

                                          *(float *)(DAT_00632a88 + 0x29c) * -30.0,

                                          *(float *)(DAT_00632a88 + 0x2ac) * -30.0,0x41700000,

                                          0xbf800000);

                  *(uint *)(iVar11 + 0xd8) = *(uint *)(iVar11 + 0xd8) | 0x400;

                }

              }

              local_130 = local_130 + 1;

              iVar6 = iVar6 + 4;

            } while (local_130 < *(int *)(iVar14 + 0x2238 + DAT_006330e4));

          }

        }

        else if (*(int *)(DAT_00632a88 + 4) == 3) {

          iVar14 = local_13c * 0x118;

          *(undefined4 *)(iVar14 + 0x2238 + DAT_006330e4) = *(undefined4 *)pbVar12;

          pbVar12 = pbVar5 + 5;

          local_130 = 0;

          if (0 < *(int *)(iVar14 + 0x2238 + DAT_006330e4)) {

            iVar6 = iVar14 + 0x223c;

            do {

              *(undefined4 *)(iVar6 + DAT_006330e4) = *(undefined4 *)pbVar12;

              pbVar12 = pbVar12 + 4;

              if (*(int *)(iVar6 + DAT_006330e4) != 0x2c) {

                iVar11 = IconDef_wield_eq3(*(int *)(iVar6 + DAT_006330e4));

                if (iVar11 == 0) {

                  iVar11 = IconDef_wield_eq1(*(undefined4 *)(iVar6 + DAT_006330e4));

                  if (iVar11 == 0) {

                    IconDef_wield_eq5(*(undefined4 *)(iVar6 + DAT_006330e4));

                  }

                  else {

                    iVar11 = reaper_has_bow_2(DAT_00632a88);

                    if (iVar11 == 0) {

                      iVar11 = reaper_has_bow_2(DAT_00632a88);

                      if (0 < iVar11) {

                        uVar7 = IconDefGiveAmmo(*(undefined4 *)(iVar6 + DAT_006330e4),1);

                        reaper_set_bow(DAT_00632a88,*(undefined4 *)(iVar6 + DAT_006330e4),iVar11,

                                       uVar7);

                      }

                    }

                    else {

                      uVar7 = IconDefAmmoIcon(*(undefined4 *)(iVar6 + DAT_006330e4));

                      uVar7 = IconDefGiveAmmo(uVar7);

                      uVar7 = IconDefAmmoIcon(*(undefined4 *)(iVar6 + DAT_006330e4),uVar7);

                      reaper_give_ammo(DAT_00632a88,uVar7);

                    }

                  }

                }

                else {

                  iVar11 = reaper_has_bow(DAT_00632a88);

                  if (iVar11 == 0) {

                    reaper_item_find_slot();

                  }

                  else {

                    reaper_item_count(DAT_00632a88,*(undefined4 *)(iVar6 + DAT_006330e4),0xffffffff)

                    ;

                  }

                }

              }

              local_130 = local_130 + 1;

              iVar6 = iVar6 + 4;

            } while (local_130 < *(int *)(iVar14 + 0x2238 + DAT_006330e4));

          }

        }

        else {

          iVar14 = local_13c * 0x118;

          *(undefined4 *)(iVar14 + 0x2238 + DAT_006330e4) = *(undefined4 *)pbVar12;

          pbVar12 = pbVar5 + 5;

          iVar6 = 0;

          if (0 < *(int *)(iVar14 + 0x2238 + DAT_006330e4)) {

            iVar11 = iVar14 + 0x223c;

            do {

              *(undefined4 *)(iVar11 + DAT_006330e4) = *(undefined4 *)pbVar12;

              pbVar12 = pbVar12 + 4;

              iVar6 = iVar6 + 1;

              iVar11 = iVar11 + 4;

            } while (iVar6 < *(int *)(iVar14 + 0x2238 + DAT_006330e4));

          }

        }

        break;

      case 0xf:

        _DAT_00632be4 = (float)*(int *)pbVar12;

        pbVar12 = pbVar5 + 5;

        uVar7 = __ftol();

        *(undefined4 *)(local_13c * 0x118 + 0x2310 + DAT_006330e4) = uVar7;

        break;

      case 0x10:

        uVar7 = *(undefined4 *)pbVar12;

        pbVar12 = pbVar5 + 5;

        *(undefined4 *)(DAT_006330e4 + 0x4e80) = uVar7;

        *(undefined4 *)(local_13c * 0x118 + 0x2318 + DAT_006330e4) =

             *(undefined4 *)(DAT_006330e4 + 0x4e80);

        break;

      case 0x11:

        uVar7 = *(undefined4 *)pbVar12;

        pbVar12 = pbVar5 + 5;

        *(undefined4 *)(DAT_006330e4 + 0x4e84) = uVar7;

        *(undefined4 *)(local_13c * 0x118 + 0x231c + DAT_006330e4) =

             *(undefined4 *)(DAT_006330e4 + 0x4e84);

        break;

      case 0x12:

        _DAT_00632bdc = (float)*(int *)pbVar12;

        pbVar12 = pbVar5 + 5;

        uVar7 = __ftol();

        *(undefined4 *)(local_13c * 0x118 + 0x229c + DAT_006330e4) = uVar7;

        break;

      case 0x13:

        puVar10 = (undefined4 *)(local_13c * 0x118 + 0x22a0 + DAT_006330e4);

        for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {

          *puVar10 = *(undefined4 *)pbVar12;

          pbVar12 = pbVar12 + 4;

          puVar10 = puVar10 + 1;

        }

        pbVar12 = pbVar5 + 0x21;

        break;

      case 0x14:

        iVar14 = 0;

        iVar6 = 0;

        do {

          iVar11 = match(iVar6 + 0x210 + DAT_006330e4,pbVar12);

          if (iVar11 != 0) break;

          iVar6 = iVar6 + 0x20;

          iVar14 = iVar14 + 1;

        } while (iVar6 < 0x1000);

        if (iVar14 == 0x80) {

          crt_sprintf(&DAT_00657400,s_Error__Flick__s_not_in_world_fli_0055c7e4,pbVar12);

          pbVar12 = pbVar5 + 0x21;

        }

        else {

          bVar8 = (byte)iVar14;

          if (iVar14 < 0x20) {

            *(uint *)(local_134 + 0x2e8) = *(uint *)(local_134 + 0x2e8) | 1 << (bVar8 & 0x1f);

            pbVar12 = pbVar5 + 0x21;

          }

          else if (iVar14 < 0x40) {

            *(uint *)(local_134 + 0x2ec) = *(uint *)(local_134 + 0x2ec) | 1 << (bVar8 - 0x20 & 0x1f)

            ;

            pbVar12 = pbVar5 + 0x21;

          }

          else if (iVar14 < 0x60) {

            *(uint *)(local_134 + 0x2f0) = *(uint *)(local_134 + 0x2f0) | 1 << (bVar8 - 0x40 & 0x1f)

            ;

            pbVar12 = pbVar5 + 0x21;

          }

          else {

            if (iVar14 < 0x80) {

              *(uint *)(local_134 + 0x2f0) =

                   *(uint *)(local_134 + 0x2f0) | 1 << (bVar8 + 0xa0 & 0x1f);

            }

            pbVar12 = pbVar5 + 0x21;

          }

        }

        break;

      case 0x15:

        puVar10 = (undefined4 *)(local_13c * 0x118 + 0x22c0 + DAT_006330e4);

        for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {

          *puVar10 = *(undefined4 *)pbVar12;

          pbVar12 = pbVar12 + 4;

          puVar10 = puVar10 + 1;

        }

        pbVar12 = pbVar5 + 0x21;

        break;

      case 0x16:

        if (7 < local_12c) {

          FUN_0051ea20(s_Mission_Lock_level_nest_too_deep_0055c824);

          local_12c = local_12c + -1;

        }

        uVar7 = *(undefined4 *)pbVar12;

        local_124[local_12c + 1] = local_134;

        local_134 = object_allocate_type(uVar7,0x80000000);

        *(uint *)(local_134 + 0xdc) = *(uint *)(local_134 + 0xdc) | 0x20000000;

        iVar14 = local_124[local_12c + 1];

        *(uint *)(local_134 + 0xd8) = *(uint *)(local_134 + 0xd8) | 0x400;

        *(int *)(local_134 + 0x210) = iVar14;

        pbVar12 = pbVar5 + 7;

        local_12c = local_12c + 1;

        *(uint *)(local_134 + 0x214) = (uint)pbVar5[5];

        *(uint *)(local_134 + 0x218) = (uint)pbVar5[6];

        break;

      case 0x17:

        if (local_12c == 0) {

          FUN_0051ea20(s_Lock_level_underflow_0055c80c);

        }

        else {

          local_134 = local_124[local_12c];

          local_12c = local_12c + -1;

        }

        break;

      case 0x18:

        *(undefined4 *)(local_134 + 200) = *(undefined4 *)pbVar12;

        *(undefined4 *)(local_134 + 0xcc) = *(undefined4 *)(pbVar5 + 5);

        pbVar12 = pbVar5 + 0xd;

        *(undefined4 *)(local_134 + 0xd0) = *(undefined4 *)(pbVar5 + 9);

        if (*(int *)(local_134 + 0x210) != 0) {

          *(uint *)(local_134 + 0xdc) = *(uint *)(local_134 + 0xdc) | 0x8000;

        }

        break;

      case 0x19:

        puVar10 = (undefined4 *)(local_13c * 0x118 + 0x22e8 + DAT_006330e4);

        for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {

          *puVar10 = *(undefined4 *)pbVar12;

          pbVar12 = pbVar12 + 4;

          puVar10 = puVar10 + 1;

        }

        pbVar12 = pbVar5 + 0x21;

        break;

      case 0x1a:

        uVar7 = *(undefined4 *)pbVar12;

        iVar14 = *(int *)(local_134 + 0x100);

        uVar1 = *(undefined4 *)(pbVar5 + 5);

        pbVar12 = pbVar5 + 9;

        *(undefined4 *)(iVar14 + 0x10) = uVar7;

        *(undefined4 *)(iVar14 + 0x38) = 1;

        *(undefined4 *)(iVar14 + 0x14) = uVar1;

        break;

      case 0x1b:

        uVar7 = *(undefined4 *)pbVar12;

        iVar14 = *(int *)(local_134 + 0x100);

        uVar1 = *(undefined4 *)(pbVar5 + 5);

        pbVar12 = pbVar5 + 9;

        *(undefined4 *)(iVar14 + 0x18) = uVar7;

        *(undefined4 *)(iVar14 + 0x1c) = uVar1;

        break;

      case 0x1c:

        *(undefined4 *)(*(int *)(local_134 + 0x100) + 0x48) = 1;

        break;

      case 0x1d:

        *(undefined4 *)(*(int *)(local_134 + 0x100) + 0x4c) = 1;

        break;

      case 0x1e:

        piVar3 = *(int **)(local_134 + 0x100);

        piVar9 = piVar3 + 1;

        piVar15 = piVar9;

        for (iVar14 = 0x14; iVar14 != 0; iVar14 = iVar14 + -1) {

          *piVar15 = -1;

          piVar15 = piVar15 + 1;

        }

        iVar14 = *(int *)pbVar12;

        pbVar12 = pbVar5 + 5;

        iVar6 = 0;

        *piVar3 = iVar14;

        if (0 < iVar14) {

          do {

            *piVar9 = *(int *)pbVar12;

            pbVar12 = pbVar12 + 4;

            iVar6 = iVar6 + 1;

            piVar9 = piVar9 + 1;

          } while (iVar6 < *piVar3);

        }

        break;

      case 0x1f:

        iVar14 = *(int *)(local_134 + 0x100);

        puVar10 = (undefined4 *)(iVar14 + 0xa8);

        puVar16 = puVar10;

        for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {

          *puVar16 = 0xffffffff;

          puVar16 = puVar16 + 1;

        }

        *(undefined4 *)(iVar14 + 0xa4) = *(undefined4 *)pbVar12;

        pbVar12 = pbVar5 + 5;

        iVar6 = 0;

        if (0 < *(int *)(iVar14 + 0xa4)) {

          do {

            *puVar10 = *(undefined4 *)pbVar12;

            pbVar12 = pbVar12 + 4;

            iVar6 = iVar6 + 1;

            puVar10 = puVar10 + 1;

          } while (iVar6 < *(int *)(iVar14 + 0xa4));

        }

        break;

      case 0x20:

        if (*(int *)(local_134 + 0x1e0) == 0x33) {

          bVar8 = *pbVar12;

          pbVar12 = pbVar5 + 2;

          *(uint *)(*(int *)(local_134 + 0x100) + 0x60) = (uint)bVar8;

        }

        else {

          if (*(int *)(local_134 + 0x1e0) == 0x61) {

            *(uint *)(*(int *)(local_134 + 0x100) + 0xc) = (uint)*pbVar12;

          }

          pbVar12 = pbVar5 + 2;

        }

        break;

      case 0x21:

        *(undefined4 *)(*(int *)(local_134 + 0x100) + 0x50) = *(undefined4 *)pbVar12;

        pbVar12 = pbVar5 + 5;

        break;

      case 0x22:

        iVar14 = ObjIsReaper(DAT_00632a88);

        puVar10 = DAT_00632d68;

        if (iVar14 != 0) {

          for (; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

            if (*(int *)(puVar10[3] + 4) == 0x434) {

              object_destroy(puVar10[3]);

            }

          }

          iVar6 = object_allocate_type(0x434,0x80000000);

          iVar14 = DAT_00632a88;

          *(undefined4 *)(iVar6 + 0xa0) = *(undefined4 *)(DAT_00632a88 + 0xa0);

          *(undefined4 *)(iVar6 + 0xa4) = *(undefined4 *)(iVar14 + 0xa4);

          *(undefined4 *)(iVar6 + 0xa8) = *(undefined4 *)(iVar14 + 0xa8);

          puVar10 = (undefined4 *)(DAT_00632a88 + 0x294);

          puVar16 = (undefined4 *)(iVar6 + 0x294);

          for (iVar14 = 0x11; iVar14 != 0; iVar14 = iVar14 + -1) {

            *puVar16 = *puVar10;

            puVar10 = puVar10 + 1;

            puVar16 = puVar16 + 1;

          }

          *(undefined4 *)(iVar6 + 200) = *(undefined4 *)(DAT_00632a88 + 200);

          *(undefined4 *)(iVar6 + 0xfc) = 1;

          *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) | 0x400;

          reaper_init__FP6OBJECT(DAT_00632a88);

          object_attach_target(DAT_00632a88,iVar6);

        }

        *(undefined4 *)(local_13c * 0x118 + 0x2320 + DAT_006330e4) = 1;

        break;

      case 0x23:

        *(undefined4 *)(DAT_006330e4 + 0x4f38) = *(undefined4 *)pbVar12;

        pbVar12 = pbVar5 + 5;

        break;

      case 0x24:

        *(undefined4 *)(local_13c * 0x118 + 0x2324 + DAT_006330e4) = 1;

        iVar14 = ObjIsMecc(DAT_00632a88);

        if (iVar14 == 0) {

          iVar14 = ObjIsReaper(DAT_00632a88);

          if (iVar14 != 0) {

            *(undefined4 *)(*(int *)(DAT_00632a88 + 0x100) + 0xcec) = 0;

          }

        }

        else {

          *(undefined4 *)(*(int *)(DAT_00632a88 + 0x100) + 0x4c) = 0;

        }

        break;

      case 0x25:

        *(undefined4 *)(local_13c * 0x118 + 0x2314 + DAT_006330e4) = 1;

        DAT_00632bec = 1;

        break;

      case 0x26:

        *(undefined4 *)(local_13c * 0x118 + 0x2308 + DAT_006330e4) = *(undefined4 *)pbVar12;

        *(undefined4 *)(local_13c * 0x118 + 0x230c + DAT_006330e4) = *(undefined4 *)(pbVar5 + 5);

        pbVar12 = pbVar5 + 9;

        break;

      default:

        crt_sprintf(local_100,s_Mission_Load_Error__last_op____d_0055c7c0,(int)(char)local_135);

        FUN_0051ea20(local_100);

      }

      pbVar5 = pbVar12;

      local_135 = bVar2;

    } while (!bVar17);

    rpboat_lock_to_boat__FP6OBJECTT0();

    *(undefined4 *)(DAT_00632a88 + 0x278) = 0;

    DAT_0059f318 = 0;

    DAT_0059f320 = 0;

    DAT_0059f31c = 0;

    if ((((DAT_00632d20 == 10) && (*(int *)(DAT_006330e4 + 0x4a60) == 0)) &&

        (iVar14 = object_find(0x2e6), iVar14 != 0)) &&

       (iVar6 = object_allocate_type(0x2e6,0x80000000), iVar6 != 0)) {

      object_copy_personality(iVar6,iVar14);

      object_copy_activedata(iVar6,iVar14);

      *(undefined4 *)(iVar6 + 0xa0) = 0x453a4000;

      *(undefined4 *)(iVar6 + 0xa4) = 0x42800000;

      *(undefined4 *)(iVar6 + 0xa8) = 0xc0000000;

      *(undefined4 *)(iVar6 + 0xc4) = 0x3fc00000;

      *(undefined4 *)(iVar6 + 200) = 0x43250000;

      *(undefined4 *)(iVar6 + 0xe8) = 10;

      object_set_location(iVar6,0x453a4000,0x42800000,0xc0000000);

      uVar4 = *(uint *)(iVar6 + 0xd8);

      puVar10 = (undefined4 *)(iVar14 + 400);

      puVar16 = (undefined4 *)(iVar6 + 400);

      for (iVar11 = 0x1e; iVar11 != 0; iVar11 = iVar11 + -1) {

        *puVar16 = *puVar10;

        puVar10 = puVar10 + 1;

        puVar16 = puVar16 + 1;

      }

      *(uint *)(iVar6 + 0xdc) = *(uint *)(iVar6 + 0xdc) | 0x20000000;

      *(uint *)(iVar6 + 0xd8) = uVar4 | 0x400;

      ObjectCalculateTransform(iVar6);

      return 1;

    }

  }

  return 1;

}

/* ===== mission_flick_load @ 0x00493960 ===== */
void mission_flick_load(byte *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)



{

  byte bVar1;

  int *piVar2;

  byte *pbVar3;

  int iVar4;

  byte *pbVar5;

  byte *pbVar6;

  int iVar7;

  bool bVar8;

  byte local_101;

  undefined1 local_100 [256];

  

  *param_2 = 0;

  *param_3 = 0;

  *param_4 = 0;

  iVar7 = 0;

  pbVar3 = (byte *)(DAT_006330e4 + 0x4558);

  pbVar6 = param_1;

  pbVar5 = pbVar3;

LAB_004939a4:

  do {

    bVar1 = *pbVar3;

    bVar8 = bVar1 < *pbVar6;

    if (bVar1 == *pbVar6) {

      if (bVar1 != 0) {

        bVar1 = pbVar3[1];

        bVar8 = bVar1 < pbVar6[1];

        if (bVar1 != pbVar6[1]) goto LAB_004939c8;

        pbVar3 = pbVar3 + 2;

        pbVar6 = pbVar6 + 2;

        if (bVar1 != 0) goto LAB_004939a4;

      }

      iVar4 = 0;

    }

    else {

LAB_004939c8:

      iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);

    }

    if (iVar4 == 0) break;

    iVar7 = iVar7 + 1;

    pbVar3 = pbVar5 + 0x30;

    pbVar6 = param_1;

    pbVar5 = pbVar3;

  } while (iVar7 < 0x1b);

  if (((iVar7 != 0x1b) &&

      (piVar2 = *(int **)(iVar7 * 0x30 + 0x457c + DAT_006330e4), piVar2 != (int *)0x0)) &&

     (*piVar2 == 4)) {

    iVar7 = 0;

    pbVar5 = (byte *)(DAT_006330e4 + 0x2210);

    pbVar3 = param_1;

    pbVar6 = pbVar5;

LAB_00493a24:

    do {

      bVar1 = *pbVar5;

      bVar8 = bVar1 < *pbVar3;

      if (bVar1 == *pbVar3) {

        if (bVar1 != 0) {

          bVar1 = pbVar5[1];

          bVar8 = bVar1 < pbVar3[1];

          if (bVar1 != pbVar3[1]) goto LAB_00493a48;

          pbVar5 = pbVar5 + 2;

          pbVar3 = pbVar3 + 2;

          if (bVar1 != 0) goto LAB_00493a24;

        }

        iVar4 = 0;

      }

      else {

LAB_00493a48:

        iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);

      }

      if (iVar4 == 0) break;

      iVar7 = iVar7 + 1;

      pbVar5 = pbVar6 + 0x118;

      pbVar3 = param_1;

      pbVar6 = pbVar5;

    } while (iVar7 < 0x20);

    if (iVar7 != 0x20) {

      bVar8 = false;

      pbVar3 = (byte *)(piVar2 + 1);

      do {

        bVar1 = *pbVar3;

        pbVar6 = pbVar3 + 1;

        switch(bVar1) {

        case 1:

        case 0x17:

        case 0x1c:

        case 0x1d:

        case 0x22:

        case 0x24:

        case 0x25:

          break;

        case 2:

          bVar8 = true;

          break;

        case 3:

        case 4:

          pbVar6 = pbVar3 + 0x15;

          if (bVar1 == 4) goto switchD_00493a7f_caseD_1a;

          break;

        case 5:

        case 8:

        case 0x20:

          pbVar6 = pbVar3 + 2;

          break;

        case 6:

        case 0x18:

          pbVar6 = pbVar3 + 0xd;

          break;

        case 7:

        case 9:

        case 0xc:

        case 0xd:

        case 0xf:

        case 0x10:

        case 0x11:

        case 0x12:

        case 0x21:

        case 0x23:

          pbVar6 = pbVar3 + 5;

          break;

        case 10:

          pbVar6 = pbVar3 + (uint)*pbVar6 * 4 + 2;

          break;

        case 0xb:

          pbVar6 = pbVar3 + 0x11;

          break;

        case 0xe:

          pbVar6 = pbVar3 + *(int *)pbVar6 * 4 + 5;

          break;

        case 0x13:

          *param_4 = pbVar6;

        case 0x14:

          pbVar6 = pbVar3 + 0x21;

          break;

        case 0x15:

          *param_2 = pbVar6;

          pbVar6 = pbVar3 + 0x21;

          break;

        case 0x16:

          pbVar6 = pbVar3 + 7;

          break;

        case 0x19:

          *param_3 = pbVar6;

          pbVar6 = pbVar3 + 0x21;

          break;

        case 0x1a:

        case 0x1b:

        case 0x26:

switchD_00493a7f_caseD_1a:

          pbVar6 = pbVar6 + 8;

          break;

        case 0x1e:

          pbVar6 = pbVar3 + *(int *)pbVar6 * 4 + 5;

          break;

        case 0x1f:

          pbVar6 = pbVar3 + *(int *)pbVar6 * 4 + 5;

          break;

        default:

          crt_sprintf(local_100,s_Flick_Mission_Load_Error__last_o_0055c884,(int)(char)local_101);

          FUN_0051ea20(local_100);

        }

        pbVar3 = pbVar6;

        local_101 = bVar1;

      } while (!bVar8);

    }

  }

  return;

}

/* ===== voice_event_trigger @ 0x00493BD0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void voice_event_trigger(int param_1)



{

  undefined4 uVar1;

  int iVar2;

  

  if ((((DAT_00632c00 == 0) && (DAT_00632e74 == 0)) && (DAT_00632bd8 == 0)) &&

     (_DAT_00632b60 <= 0.0)) {

    *(int *)(DAT_006330e4 + 0x4a68) = *(int *)(DAT_006330e4 + 0x4a68) + 1;

    if (param_1 != 0) {

      *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0xfffffff0;

    }

    crt_sprintf(&DAT_0059f060,&DAT_0055c8ac,

                *(int *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4548 + DAT_006330e4) * 0x118 +

                0x2210 + DAT_006330e4,*(undefined4 *)(DAT_006330e4 + 0x4a68));

    uVar1 = FUN_00507b00(&DAT_0059f060);

    iVar2 = FUN_00545650(&DAT_0059f060,uVar1);

    if (iVar2 != 0) {

      chat_insert(uVar1,6);

    }

  }

  return;

}

/* ===== smartie_voice_trigger @ 0x00493C90 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void smartie_voice_trigger(void)



{

  undefined4 uVar1;

  int iVar2;

  

  if ((((DAT_00632bec != 0) && (DAT_00632bec = 0, DAT_00632c00 == 0)) && (DAT_00632e74 == 0)) &&

     ((DAT_00632bd8 == 0 && (_DAT_00632b60 <= 0.0)))) {

    *(int *)(DAT_006330e4 + 0x4a68) = *(int *)(DAT_006330e4 + 0x4a68) + 1;

    crt_sprintf(&DAT_0059f060,&DAT_0055c8ac,

                *(int *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4548 + DAT_006330e4) * 0x118 +

                0x2210 + DAT_006330e4,*(undefined4 *)(DAT_006330e4 + 0x4a68));

    uVar1 = FUN_00507b00(&DAT_0059f060);

    iVar2 = FUN_00545650(&DAT_0059f060,uVar1);

    if (iVar2 != 0) {

      chat_insert(uVar1,6);

    }

  }

  return;

}

/* ===== player_voice_timer_update @ 0x00493D60 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void player_voice_timer_update(undefined4 param_1,float param_2)



{

  undefined4 uVar1;

  int iVar2;

  

  if ((((_DAT_00632be4 != -1.0) &&

       (_DAT_00632be8 = _DAT_00632be8 + param_2,

       _DAT_00632be4 < _DAT_00632be8 != (_DAT_00632be4 == _DAT_00632be8))) &&

      (_DAT_00632be4 = -1.0, DAT_00632c00 == 0)) &&

     (((DAT_00632e74 == 0 && (DAT_00632bd8 == 0)) && (_DAT_00632b60 <= 0.0)))) {

    *(int *)(DAT_006330e4 + 0x4a68) = *(int *)(DAT_006330e4 + 0x4a68) + 1;

    crt_sprintf(&DAT_0059f060,&DAT_0055c8ac,

                *(int *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4548 + DAT_006330e4) * 0x118 +

                0x2210 + DAT_006330e4,*(undefined4 *)(DAT_006330e4 + 0x4a68));

    uVar1 = FUN_00507b00(&DAT_0059f060);

    iVar2 = FUN_00545650(&DAT_0059f060,uVar1);

    if (iVar2 != 0) {

      chat_insert(uVar1,6);

    }

  }

  return;

}

/* ===== mission_replenish_food__Fv_2 @ 0x00493EA0 ===== */
/* PS2 candidate: mission_replenish_food__Fv (conf 0.55) */



void mission_replenish_food__Fv_2(void)



{

  int iVar1;

  

  if (((DAT_00632bf4 == 0) && (DAT_00632d20 == 4)) &&

     (iVar1 = *(int *)(DAT_006330e4 + 0x4a60) + -1, iVar1 == 1)) {

    DAT_00632bf4 = iVar1;

    flick_file_load_state(s_story5_get_food_1_0055c44c);

  }

  return;

}

/* ===== mission_replenish_food__Fv @ 0x00493EE0 ===== */
/* PS2 candidate: mission_replenish_food__Fv_2 (conf 0.55) */



void mission_replenish_food__Fv(void)



{

  int iVar1;

  

  if (((DAT_00632bf0 == 0) && (DAT_00632d20 == 4)) &&

     (iVar1 = *(int *)(DAT_006330e4 + 0x4a60) + -1, iVar1 == 1)) {

    DAT_00632bf0 = iVar1;

    flick_file_load_state(s_story5_Pad_0055c460);

  }

  return;

}

/* ===== voice_quota_check @ 0x00493F20 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void voice_quota_check(void)



{

  if ((*(int *)(DAT_006330e4 + 0x4a68) < *(int *)(DAT_006330e4 + 0x4a6c)) && (DAT_00632c04 == 0)) {

    hud_feed_buffer_clear();

    _DAT_00632b60 = _DAT_00632b60 + DAT_006328e0;

    DAT_00632c00 = 1;

    if (5.0 < _DAT_00632b60) {

      dlog_mission_fail_menu();

      return;

    }

  }

  return;

}

/* ===== story_flick_open @ 0x00493F70 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void story_flick_open(void)



{

  int iVar1;

  float10 fVar2;

  

  if ((DAT_00632c00 == 0) && (DAT_00632e74 == 0)) {

    fVar2 = (float10)FUN_00518b70(0,0);

    fVar2 = (float10)_DAT_00632bdc - fVar2;

    _DAT_00632bdc = (float)fVar2;

    if (fVar2 < (float10)0.0 != (fVar2 == (float10)0.0)) {

      iVar1 = *(int *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4578 + DAT_006330e4) * 0x118;

      if (*(char *)(iVar1 + 0x22a0 + DAT_006330e4) == '\0') {

        if (DAT_00632c08 == 0) {

          voice_quota_check();

          _DAT_00632bdc = 0.001;

          return;

        }

      }

      else if (DAT_00632c08 == 0) {

        flick_file_load_state(iVar1 + 0x22a0 + DAT_006330e4);

        DAT_00632c08 = 1;

        _DAT_00632bdc = 0.001;

        return;

      }

      dlog_mission_fail_menu();

      return;

    }

  }

  return;

}

/* ===== damage_voice_trigger @ 0x00494030 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void damage_voice_trigger(int param_1)



{

  undefined4 uVar1;

  int iVar2;

  

  if (((DAT_00632c00 == 0) &&

      (((*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278) ||

        ((char)((uint)*(undefined4 *)(param_1 + 0xd8) >> 8) < '\0')) &&

       (((byte)*(undefined4 *)(param_1 + 0xdc) & 0xf) == 2)))) &&

     (((DAT_00632e74 == 0 && (DAT_00632bd8 == 0)) && (_DAT_00632b60 <= 0.0)))) {

    *(int *)(DAT_006330e4 + 0x4a68) = *(int *)(DAT_006330e4 + 0x4a68) + 1;

    *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0xfffffff0;

    crt_sprintf(&DAT_0059f060,&DAT_0055c8ac,

                *(int *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4548 + DAT_006330e4) * 0x118 +

                0x2210 + DAT_006330e4,*(undefined4 *)(DAT_006330e4 + 0x4a68));

    uVar1 = FUN_00507b00(&DAT_0059f060);

    iVar2 = FUN_00545650(&DAT_0059f060,uVar1);

    if (iVar2 != 0) {

      chat_insert(uVar1,6);

    }

  }

  return;

}

/* ===== mission_check_obj_proximity__FP6OBJECT @ 0x00494120 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: mission_check_obj_proximity__FP6OBJECT (conf 0.443) */



void mission_check_obj_proximity__FP6OBJECT(int param_1)



{

  float fVar1;

  float fVar2;

  uint uVar3;

  int iVar4;

  undefined4 uVar5;

  ushort uVar6;

  float10 fVar7;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if (((DAT_00632c00 == 0) && (DAT_00632a88 != 0)) &&

     ((uVar3 = *(uint *)(param_1 + 0xdc) & 0xf, uVar3 == 1 || (uVar3 == 4)))) {

    if (uVar3 == 4) {

      iVar4 = ObjIsMecc(DAT_00632a88);

      if (iVar4 == 0) {

        iVar4 = ObjIsReaper(DAT_00632a88);

        if (iVar4 == 0) {

          return;

        }

        fVar2 = (float)*(int *)(*(int *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4548 +

                                        DAT_006330e4) * 0x118 + 0x2310 + DAT_006330e4);

        fVar1 = *(float *)(*(int *)(DAT_00632a88 + 0x100) + 0xcec);

        uVar6 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(fVar2 == fVar1) << 0xe;

      }

      else {

        fVar2 = (float)*(int *)(*(int *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4548 +

                                        DAT_006330e4) * 0x118 + 0x2310 + DAT_006330e4);

        fVar1 = *(float *)(*(int *)(DAT_00632a88 + 0x100) + 0x4c);

        uVar6 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(fVar2 == fVar1) << 0xe;

      }

      if (uVar6 == 0) {

        return;

      }

    }

    fVar7 = (float10)FUN_0050a610(DAT_00632a88 + 0xa0,(float *)(param_1 + 0xa0));

    if (fVar7 < (float10)100.0 == (fVar7 == (float10)100.0)) {

      local_18 = *(float *)(param_1 + 0xa0) - *(float *)(DAT_00632a88 + 0xa0);

      local_14 = *(float *)(param_1 + 0xa4) - *(float *)(DAT_00632a88 + 0xa4);

      local_10 = *(float *)(param_1 + 0xa8) - *(float *)(DAT_00632a88 + 0xa8);

      normalize__FPfN20(&local_18,&local_14,&local_10);

      local_c = local_18 * 10.0 + *(float *)(DAT_00632a88 + 0xa0);

      local_8 = local_14 * 10.0 + *(float *)(DAT_00632a88 + 0xa4);

      local_4 = local_10 * 10.0 + *(float *)(DAT_00632a88 + 0xa8);

      iVar4 = collide_pt_bbox(&local_c,param_1 + 0x27c);

      if (iVar4 == 0) {

        return;

      }

      if (DAT_00632c00 != 0) {

        return;

      }

      if (DAT_00632e74 != 0) {

        return;

      }

      if (DAT_00632bd8 != 0) {

        return;

      }

      if (0.0 < _DAT_00632b60) {

        return;

      }

      *(int *)(DAT_006330e4 + 0x4a68) = *(int *)(DAT_006330e4 + 0x4a68) + 1;

      *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0xfffffff0;

      uVar5 = *(undefined4 *)(DAT_006330e4 + 0x4a68);

      iVar4 = *(int *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4548 + DAT_006330e4) * 0x118 +

              0x2210 + DAT_006330e4;

    }

    else {

      if (DAT_00632c00 != 0) {

        return;

      }

      if (DAT_00632e74 != 0) {

        return;

      }

      if (DAT_00632bd8 != 0) {

        return;

      }

      if (0.0 < _DAT_00632b60) {

        return;

      }

      *(int *)(DAT_006330e4 + 0x4a68) = *(int *)(DAT_006330e4 + 0x4a68) + 1;

      *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0xfffffff0;

      uVar5 = *(undefined4 *)(DAT_006330e4 + 0x4a68);

      iVar4 = *(int *)(*(int *)(DAT_006330e4 + 0x4a60) * 0x30 + 0x4548 + DAT_006330e4) * 0x118 +

              0x2210 + DAT_006330e4;

    }

    crt_sprintf(&DAT_0059f060,&DAT_0055c8ac,iVar4,uVar5);

    uVar5 = FUN_00507b00(&DAT_0059f060);

    iVar4 = FUN_00545650(&DAT_0059f060,uVar5);

    if (iVar4 != 0) {

      chat_insert(uVar5,6);

    }

  }

  return;

}

/* ===== mission_unload_mission_objects__Fv @ 0x00494400 ===== */
/* PS2 candidate: mission_unload_mission_objects__Fv (conf 0.47) */



void mission_unload_mission_objects__Fv(void)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  

  puVar1 = DAT_00632d68;

  do {

    if (puVar1 == (undefined4 *)0x0) {

      wound_list_cleanup();

      FUN_0040b300();

      object_list_update();

      object_list_update();

      _cleanup_4();

      return;

    }

    iVar3 = puVar1[3];

    iVar2 = *(int *)(iVar3 + 0x1e0);

    if ((*(uint *)(iVar3 + 0xd8) & 0x400) == 0) {

      if (iVar2 == 0x4d) goto LAB_00494493;

      if (iVar2 == 8) {

        object_destroy();

        iVar3 = *(int *)(iVar3 + 0x274);

        if (iVar3 != 0) goto LAB_00494493;

      }

      else {

        iVar2 = ObjIsJetski(iVar3);

        if (iVar2 != 0) {

          iVar2 = ObjIsReaper(*(undefined4 *)(iVar3 + 0x274));

          if (iVar2 != 0) {

            rpboat_unlock_from_boat__FP6OBJECTT0(*(undefined4 *)(iVar3 + 0x274),iVar3);

          }

          goto LAB_00494493;

        }

      }

    }

    else {

      if ((iVar2 == 0x12) && (*(int *)(iVar3 + 0x274) == DAT_00632a88)) {

        smartie_unlock_from_player(iVar3,*(int *)(iVar3 + 0x274),3);

      }

LAB_00494493:

      object_destroy(iVar3);

    }

    puVar1 = (undefined4 *)*puVar1;

  } while( true );

}

/* ===== mission_trigger_name @ 0x004944D0 ===== */
char * mission_trigger_name(int param_1)



{

  switch(*(uint *)(param_1 + 0xdc) & 0xf) {

  case 1:

    return s_On_Proximity_Mission_Trigger_0055c908;

  case 2:

    return s_On_Death_Mission_Trigger_0055c928;

  case 3:

    return s_On_Destination_Arrival__Trigger_0055c8e8;

  case 4:

    return s_On_Vimp_Meat_Proximity__Trigger_0055c8c8;

  default:

    return s_No_Mission_Trigger_0055c8b4;

  }

}

/* ===== ambient_streams_handler @ 0x004946A0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void ambient_streams_handler(void)



{

  undefined4 *puVar1;

  int iVar2;

  

  DAT_0055c4a8 = 100;

  _DAT_0059f324 = 0;

  _DAT_0059f328 = 0;

  (*DAT_005dd31c)();

  (*DAT_005dd360)();

  for (puVar1 = DAT_00632d68; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    if (*(int *)(puVar1[3] + 0x1e0) == 0x3a) {

      ambient_streams_stopped__FP6OBJECT(puVar1[3]);

    }

  }

  *(undefined4 *)(DAT_00632a88 + 0x278) = 0;

  *(undefined4 *)(DAT_00632a88 + 0x1d4) = 0;

  *(undefined4 *)(DAT_00632a88 + 0xcc) = 0;

  *(undefined4 *)(DAT_00632a88 + 0x210) = 0;

  *(undefined4 *)(DAT_00632a88 + 0x108) = 0;

  *(undefined4 *)(DAT_00632a88 + 0x184) = 0;

  *(uint *)(DAT_00632a88 + 0xd8) = *(uint *)(DAT_00632a88 + 0xd8) & 0xbfffffff;

  iVar2 = ObjIsMecc(DAT_00632a88);

  if (iVar2 == 0) {

    ObjIsReaper(DAT_00632a88);

    puVar1 = DAT_00632d68;

  }

  else {

    iVar2 = *(int *)(DAT_00632a88 + 0x100);

    if (*(int *)(iVar2 + 0x1a0) != 0) {

      fx_delete(*(int *)(iVar2 + 0x1a0));

      *(undefined4 *)(iVar2 + 0x1a0) = 0;

    }

    puVar1 = DAT_00632d68;

    if (*(int *)(iVar2 + 0xf4) != 0) {

      fx_delete(*(int *)(iVar2 + 0xf4));

      *(undefined4 *)(iVar2 + 0xf4) = 0;

      puVar1 = DAT_00632d68;

    }

  }

  do {

    if (puVar1 == (undefined4 *)0x0) {

LAB_004947ed:

      load_mission_continuity__Fii(DAT_00632d20,*(int *)(DAT_006330e4 + 0x4a60) + -1);

      iVar2 = *(int *)(DAT_006330e4 + 0x4a60);

      mission_unload_mission_objects__Fv();

      *(int *)(DAT_006330e4 + 0x4a60) = iVar2 + -1;

      scenerio_start_mission__Fv();

      camera_attach_path_object(*(undefined4 *)(DAT_00632a88 + 4));

      if (DAT_00632f08 == 0) {

        DAT_00633020 = 1;

        DAT_00633028 = 1;

        DAT_0063302c = 0;

        showchat_mission_objective__Fi(*(int *)(DAT_006330e4 + 0x4a60) + -1);

      }

      DAT_00632c00 = 0;

      DAT_00632c04 = 0;

      _DAT_00632b60 = 0;

      return;

    }

    iVar2 = puVar1[3];

    if ((*(int *)(iVar2 + 0x1e0) == 0x59) && (*(int *)(iVar2 + 0x210) == DAT_00632a88)) {

      *(undefined4 *)(iVar2 + 0x210) = 0;

      *(undefined4 *)(iVar2 + 0x218) = 0;

      *(undefined4 *)(iVar2 + 0x214) = 0;

      goto LAB_004947ed;

    }

    puVar1 = (undefined4 *)*puVar1;

  } while( true );

}

/* ===== dlog_mission_fail_menu @ 0x00494890 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: buoy_process__FP6OBJECT (conf 0.473) */



void dlog_mission_fail_menu(void)



{

  DAT_0059f354 = main_dlog_00427150();

  main_dlog_004273b0(DAT_0059f354,0,0x3f000000,0x40c00000,0x8a000000,s_FailTitle_0055c954);

  main_dlog_00427e80(DAT_0059f354,1,0x3f000000,0x41000000,0x88000062);

  main_dlog_00428340(DAT_0059f354,1,s_FailYes_0055c94c);

  main_dlog_00428340(DAT_0059f354,1,s_FailNo_0055c944);

  dlog_push_level(&LAB_00494940,&LAB_00494bb0);

  dialog_level_set_textentry_mode();

  DAT_00632aa4._3_1_ = 0;

  _DAT_00632b60 = 0;

  DAT_00632c00 = 0;

  DAT_00632c08 = 0;

  return;

}

/* ===== mission_type_dispatch @ 0x00494BC0 ===== */
void mission_type_dispatch(void)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  

  *(undefined4 *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) = 0;

  iVar6 = *(int *)(DAT_00632bfc * 0x118 + 0x2234 + DAT_006330e4);

  if (iVar6 == 3) {

    iVar6 = *(int *)(DAT_00632a88 + 0x100);

    piVar4 = (int *)(iVar6 + 0xd3c);

    iVar5 = 5;

    iVar2 = DAT_006330e4;

    iVar3 = DAT_00632bfc;

    do {

      if (0 < *piVar4) {

        *(int *)(iVar2 + 0x223c + (iVar3 * 0x46 + *(int *)(iVar2 + 0x2238 + iVar3 * 0x118)) * 4) =

             *piVar4;

        piVar1 = (int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4);

        *piVar1 = *piVar1 + 1;

        iVar2 = DAT_006330e4;

        iVar3 = DAT_00632bfc;

      }

      piVar4 = piVar4 + 3;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

    piVar4 = (int *)(iVar6 + 0xd78);

    iVar6 = 4;

    do {

      if (0 < *piVar4) {

        *(int *)(iVar2 + 0x223c + (iVar3 * 0x46 + *(int *)(iVar3 * 0x118 + 0x2238 + iVar2)) * 4) =

             *piVar4;

        *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) =

             *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) + 1;

        iVar2 = DAT_006330e4;

        iVar3 = DAT_00632bfc;

      }

      piVar4 = piVar4 + 2;

      iVar6 = iVar6 + -1;

    } while (iVar6 != 0);

  }

  else if (iVar6 == 2) {

    iVar6 = FUN_00457fb0(DAT_00632a88,0);

    if (-1 < iVar6) {

      *(int *)(DAT_006330e4 + 0x223c +

              (DAT_00632bfc * 0x46 + *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4)) * 4) =

           iVar6;

      *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) =

           *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) + 1;

    }

    iVar6 = FUN_00457fb0(DAT_00632a88,1);

    if (-1 < iVar6) {

      *(int *)(DAT_006330e4 + 0x223c +

              (DAT_00632bfc * 0x46 + *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4)) * 4) =

           iVar6;

      *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) =

           *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) + 1;

    }

    iVar6 = FUN_00457fb0(DAT_00632a88,2);

    if (-1 < iVar6) {

      *(int *)(DAT_006330e4 + 0x223c +

              (DAT_00632bfc * 0x46 + *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4)) * 4) =

           iVar6;

      *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) =

           *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) + 1;

    }

    iVar6 = SpecialWeaponIdGet__FP6OBJECT(DAT_00632a88);

    if (-1 < iVar6) {

      *(int *)(DAT_006330e4 + 0x223c +

              (DAT_00632bfc * 0x46 + *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4)) * 4) =

           iVar6;

      *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) =

           *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) + 1;

    }

    iVar6 = FUN_004582d0(DAT_00632a88,0);

    if (-1 < iVar6) {

      *(int *)(DAT_006330e4 + 0x223c +

              (DAT_00632bfc * 0x46 + *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4)) * 4) =

           iVar6;

      *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) =

           *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) + 1;

    }

    iVar6 = FUN_004582d0(DAT_00632a88,1);

    if (-1 < iVar6) {

      *(int *)(DAT_006330e4 + 0x223c +

              (DAT_00632bfc * 0x46 + *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4)) * 4) =

           iVar6;

      *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) =

           *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) + 1;

    }

    iVar6 = FUN_004582d0(DAT_00632a88,2);

    if (-1 < iVar6) {

      *(int *)(DAT_006330e4 + 0x223c +

              (DAT_00632bfc * 0x46 + *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4)) * 4) =

           iVar6;

      *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) =

           *(int *)(DAT_00632bfc * 0x118 + 0x2238 + DAT_006330e4) + 1;

    }

  }

  object_destroy(DAT_00632a88);

  DAT_00632a88 = DAT_0059ef0c;

  DAT_0059ef0c = 0;

  return;

}

/* ===== FUN_00494f90 @ 0x00494F90 ===== */
undefined4 FUN_00494f90(void)



{

  int iVar1;

  

  if (DAT_0059f320 != 0) {

    iVar1 = dialog_level_is_base();

    if (iVar1 == 0) {

      return 1;

    }

  }

  return 0;

}

/* ===== FUN_00494fb0 @ 0x00494FB0 ===== */
void FUN_00494fb0(void)



{

  int iVar1;

  

  (*DAT_005dd308)(0);

  iVar1 = (*DAT_005dd2e0)(1);

  if (iVar1 != 0) {

    (*DAT_005dd308)(*(undefined4 *)(DAT_006330e4 + 4));

  }

  return;

}

/* ===== FUN_00494fe0 @ 0x00494FE0 ===== */
void FUN_00494fe0(void)



{

  undefined4 *puVar1;

  int iVar2;

  

  (*DAT_005dd2fc)(0xffffffff);

  iVar2 = (*DAT_005dd2e0)(2);

  puVar1 = DAT_00632d68;

  if (iVar2 != 0) {

    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      iVar2 = puVar1[3];

      if ((((*(int *)(iVar2 + 8) != 0) && ((*(uint *)(iVar2 + 0xdc) & 0x1000000) != 0)) &&

          ((*(uint *)(iVar2 + 0xd8) & 0x4000c000) == 0)) && (*(int *)(iVar2 + 0x184) != 0x3f800000))

      {

        (*DAT_005dd2f4)(1,iVar2,iVar2 + 0x27c,iVar2 + 0x288);

      }

    }

  }

  return;

}

/* ===== FUN_00495060 @ 0x00495060 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00495060(int param_1)



{

  if (((param_1 != 0) && (*(int *)(param_1 + 8) == 0)) && (DAT_00633208 == 0)) {

                    /* WARNING: Could not recover jumptable at 0x0049507d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (*_DAT_005dd298)();

    return;

  }

  return;

}

/* ===== FUN_00495090 @ 0x00495090 ===== */
void FUN_00495090(void)



{

                    /* WARNING: Could not recover jumptable at 0x00495090. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*DAT_005dd31c)();

  return;

}

/* ===== sound_play_obj @ 0x004954E0 ===== */
/* PS2 candidate: sound_play_obj (conf 0.423) */



int sound_play_obj(int param_1,undefined4 param_2)



{

  int iVar1;

  int *piVar2;

  

  if ((((DAT_00633200 == 0) && (DAT_00632dbc != 0)) &&

      (piVar2 = (int *)(param_1 * 0x2c + DAT_00632dbc), piVar2 != (int *)0x0)) &&

     ((*piVar2 != 0 && (piVar2[2] != 0)))) {

    iVar1 = (*DAT_005dd2ac)(piVar2,param_2);

    if (iVar1 == 0) {

      crt_sprintf(&DAT_00657400,s_SoundFail__s_0055c9b8,*piVar2);

      FUN_00425eb0(&DAT_00657400);

    }

    return iVar1;

  }

  return 0;

}

/* ===== sound_play_player @ 0x00495550 ===== */
/* PS2 candidate: sound_play_player (conf 0.763) */



int sound_play_player(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  

  if ((DAT_00633200 == 0) && (param_2 != 0)) {

    iVar2 = *(int *)(param_2 + 0x210);

    while (iVar1 = iVar2, iVar1 != 0) {

      param_2 = iVar1;

      iVar2 = *(int *)(iVar1 + 0x210);

    }

    if (param_2 == DAT_00632a88) {

      if (((DAT_00632dbc != 0) &&

          (piVar3 = (int *)(param_1 * 0x2c + DAT_00632dbc), piVar3 != (int *)0x0)) &&

         ((*piVar3 != 0 && (piVar3[2] != 0)))) {

        iVar2 = (*DAT_005dd2b4)(piVar3,0,param_2);

        if (iVar2 != 0) {

          return iVar2;

        }

        crt_sprintf(&DAT_00657400,s_SoundFail__s_0055c9b8,*piVar3);

        FUN_00425eb0(&DAT_00657400);

        return 0;

      }

    }

    else if ((((DAT_00632dbc != 0) &&

              (piVar3 = (int *)(param_1 * 0x2c + DAT_00632dbc), piVar3 != (int *)0x0)) &&

             (*piVar3 != 0)) && (piVar3[2] != 0)) {

      iVar2 = (*DAT_005dd2ac)(piVar3,param_2);

      if (iVar2 != 0) {

        return iVar2;

      }

      crt_sprintf(&DAT_00657400,s_SoundFail__s_0055c9b8,*piVar3);

      FUN_00425eb0(&DAT_00657400);

      return 0;

    }

  }

  return 0;

}

/* ===== sound_play_2 @ 0x00495650 ===== */
int sound_play_2(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  

  if (DAT_00633200 != 0) {

    return 0;

  }

  if (param_2 == DAT_00632a88) {

    if (DAT_00632dbc == 0) {

      return 0;

    }

    piVar2 = (int *)(param_1 * 0x2c + DAT_00632dbc);

    if (piVar2 == (int *)0x0) {

      return 0;

    }

    if (*piVar2 == 0) {

      return 0;

    }

    if (piVar2[2] == 0) {

      return 0;

    }

    iVar1 = (*DAT_005dd2b4)(piVar2,0,param_2);

    if (iVar1 != 0) {

      return iVar1;

    }

    iVar1 = *piVar2;

  }

  else {

    if (DAT_00632dbc == 0) {

      return 0;

    }

    piVar2 = (int *)(param_1 * 0x2c + DAT_00632dbc);

    if (piVar2 == (int *)0x0) {

      return 0;

    }

    if (*piVar2 == 0) {

      return 0;

    }

    if (piVar2[2] == 0) {

      return 0;

    }

    iVar1 = (*DAT_005dd2ac)(piVar2,param_2);

    if (iVar1 != 0) {

      return iVar1;

    }

    iVar1 = *piVar2;

  }

  crt_sprintf(&DAT_00657400,s_SoundFail__s_0055c9b8,iVar1);

  FUN_00425eb0(&DAT_00657400);

  return 0;

}

/* ===== sound_stop_player @ 0x00495700 ===== */
/* PS2 candidate: sound_stop_player (conf 0.43) */



void sound_stop_player(int param_1,int param_2)



{

  int iVar1;

  

  if (param_2 != 0) {

    for (iVar1 = *(int *)(param_2 + 0x210); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x210)) {

    }

    if (((DAT_00632dbc != 0) && (iVar1 = param_1 * 0x2c + DAT_00632dbc, iVar1 != 0)) &&

       (*(int *)(iVar1 + 8) != 0)) {

                    /* WARNING: Could not recover jumptable at 0x00495742. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*DAT_005dd2a0)();

      return;

    }

  }

  return;

}

/* ===== sound_stop_obj @ 0x00495750 ===== */
/* PS2 candidate: sound_stop_obj (conf 0.421) */



void sound_stop_obj(int param_1)



{

  int iVar1;

  

  if (((DAT_00632dbc != 0) && (iVar1 = param_1 * 0x2c + DAT_00632dbc, iVar1 != 0)) &&

     (*(int *)(iVar1 + 8) != 0)) {

                    /* WARNING: Could not recover jumptable at 0x00495770. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (*DAT_005dd2a0)();

    return;

  }

  return;

}

/* ===== sound_entry_volume_set @ 0x00495780 ===== */
void sound_entry_volume_set(int param_1,float param_2)



{

  int iVar1;

  

  if (((DAT_00632dbc != 0) && (iVar1 = param_1 * 0x2c + DAT_00632dbc, iVar1 != 0)) &&

     (*(int *)(iVar1 + 8) != 0)) {

    iVar1 = (*DAT_005dd2c4)(iVar1);

    if (iVar1 != 0) {

      (*DAT_005dd2bc)(iVar1,param_2 * 0.01);

    }

  }

  return;

}

/* ===== sound_play_3 @ 0x004957D0 ===== */
int sound_play_3(int param_1,undefined4 param_2,undefined4 param_3)



{

  int iVar1;

  int *piVar2;

  

  if ((((DAT_00633200 == 0) && (DAT_00632dbc != 0)) &&

      (piVar2 = (int *)(param_1 * 0x2c + DAT_00632dbc), piVar2 != (int *)0x0)) &&

     ((*piVar2 != 0 && (piVar2[2] != 0)))) {

    iVar1 = (*DAT_005dd2b0)(piVar2,param_2,param_3);

    if (iVar1 == 0) {

      crt_sprintf(&DAT_00657400,s_SoundFail__s_0055c9b8,*piVar2);

      FUN_00425eb0(&DAT_00657400);

    }

    return iVar1;

  }

  return 0;

}

/* ===== sound_play_3dpos @ 0x00495840 ===== */
/* PS2 candidate: sound_play_3dpos (conf 0.412) */



int sound_play_3dpos(int param_1,undefined4 param_2)



{

  int iVar1;

  int *piVar2;

  

  if (DAT_00633200 != 0) {

    return 0;

  }

  if ((((DAT_00632dbc != 0) &&

       (piVar2 = (int *)(param_1 * 0x2c + DAT_00632dbc), piVar2 != (int *)0x0)) && (*piVar2 != 0))

     && (piVar2[2] != 0)) {

    iVar1 = (*DAT_005dd2b0)(piVar2,param_2,0);

    if (iVar1 == 0) {

      crt_sprintf(&DAT_00657400,s_SoundFail__s_0055c9b8,*piVar2);

      FUN_00425eb0(&DAT_00657400);

    }

    return iVar1;

  }

  return 0;

}

/* ===== sound_play_4 @ 0x004958B0 ===== */
int sound_play_4(int param_1,undefined4 param_2)



{

  int iVar1;

  int *piVar2;

  

  if ((((DAT_00633200 == 0) && (DAT_00632dbc != 0)) &&

      (piVar2 = (int *)(param_1 * 0x2c + DAT_00632dbc), piVar2 != (int *)0x0)) &&

     ((*piVar2 != 0 && (piVar2[2] != 0)))) {

    iVar1 = (*DAT_005dd2b4)(piVar2,0,param_2);

    if (iVar1 == 0) {

      crt_sprintf(&DAT_00657400,s_SoundFail__s_0055c9b8,*piVar2);

      FUN_00425eb0(&DAT_00657400);

    }

    return iVar1;

  }

  return 0;

}

/* ===== sound_play @ 0x00495920 ===== */
/* PS2 candidate: sound_play (conf 0.5840000000000001) */



int sound_play(int param_1)



{

  int iVar1;

  int *piVar2;

  

  if (DAT_00633200 != 0) {

    return 0;

  }

  if ((((DAT_00632dbc != 0) &&

       (piVar2 = (int *)(param_1 * 0x2c + DAT_00632dbc), piVar2 != (int *)0x0)) && (*piVar2 != 0))

     && (piVar2[2] != 0)) {

    iVar1 = (*DAT_005dd2b4)(piVar2,0,0);

    if (iVar1 == 0) {

      crt_sprintf(&DAT_00657400,s_SoundFail__s_0055c9b8,*piVar2);

      FUN_00425eb0(&DAT_00657400);

    }

    return iVar1;

  }

  return 0;

}

/* ===== sound_stop @ 0x00495990 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: sound_stop (conf 0.34) */



void sound_stop(int param_1)



{

  int *piVar1;

  

  if ((((DAT_00632dbc != 0) &&

       (piVar1 = (int *)(param_1 * 0x2c + DAT_00632dbc), piVar1 != (int *)0x0)) && (*piVar1 != 0))

     && (piVar1[2] != 0)) {

                    /* WARNING: Could not recover jumptable at 0x004959b5. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (*_DAT_005dd2a4)();

    return;

  }

  return;

}

/* ===== wredit_004959c0 @ 0x004959C0 ===== */
void wredit_004959c0(void)



{

                    /* WARNING: Could not recover jumptable at 0x004959c0. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*DAT_005dd288)();

  return;

}

/* ===== FUN_004959d0 @ 0x004959D0 ===== */
void FUN_004959d0(void)



{

                    /* WARNING: Could not recover jumptable at 0x004959d0. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*DAT_005dd28c)();

  return;

}

/* ===== sound_checked_big @ 0x004959E0 ===== */
void sound_checked_big(int param_1)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  float10 fVar4;

  

  piVar3 = DAT_0059f368;

  do {

    while( true ) {

      piVar1 = piVar3;

      if (piVar1 == (int *)0x0) {

        return;

      }

      if ((piVar1[10] == 0) || (-1 < (char)((uint)*(undefined4 *)(piVar1[10] + 0xd8) >> 8))) break;

LAB_00495a11:

      iVar2 = piVar1[7];

      if (iVar2 != 0) {

        if (iVar2 != 0) {

          (*DAT_005dd2a8)(iVar2);

        }

        piVar1[7] = 0;

      }

      piVar3 = (int *)piVar1[1];

      piVar1[0x11] = 0;

      if (piVar3 == (int *)0x0) {

        DAT_0059f368 = (int *)*piVar1;

        if (DAT_0059f368 == (int *)0x0) {

          DAT_0059f36c = (int *)0x0;

        }

        else {

          DAT_0059f368[1] = 0;

        }

        *piVar1 = (int)DAT_0059f360;

        piVar3 = DAT_0059f368;

        DAT_0059f360 = piVar1;

      }

      else if (*piVar1 == 0) {

        DAT_0059f36c = piVar3;

        *piVar3 = 0;

        *piVar1 = (int)DAT_0059f360;

        piVar3 = (int *)0x0;

        DAT_0059f360 = piVar1;

      }

      else {

        *piVar3 = *piVar1;

        *(int *)(*piVar1 + 4) = piVar1[1];

        piVar3 = (int *)*piVar1;

        *piVar1 = (int)DAT_0059f360;

        DAT_0059f360 = piVar1;

      }

    }

    if (param_1 != 0) {

      return;

    }

    if (piVar1[5] == 0) {

      if ((*(byte *)(piVar1 + 0x10) & 1) == 0) {

        fVar4 = (float10)FUN_00518b70(0,0);

        piVar1[8] = (int)(float)((float10)(float)piVar1[8] - fVar4);

      }

      if ((float)piVar1[8] <= 0.0) {

        sound_play_checked(piVar1);

      }

      else if (piVar1[6] == 0) {

        if (piVar1[10] == 0) {

          if (piVar1[0xf] == 0) {

            if (piVar1[0xb] != 0) {

              sound_stop_obj(piVar1[4],piVar1[0xb]);

            }

            sound_play_4(piVar1[2],piVar1[0xb]);

            iVar2 = sound_play_4(piVar1[3],piVar1[0xb]);

            piVar1[7] = iVar2;

            piVar1[6] = 1;

          }

          else {

            if ((((piVar1[0xb] != 0) && (DAT_00632dbc != 0)) &&

                (iVar2 = piVar1[4] * 0x2c + DAT_00632dbc, iVar2 != 0)) && (*(int *)(iVar2 + 8) != 0)

               ) {

              (*DAT_005dd2a0)(iVar2,piVar1[0xb]);

            }

            sound_play_3(piVar1[2],piVar1 + 0xc,piVar1[0xb]);

            iVar2 = sound_play_3(piVar1[3],piVar1 + 0xc,piVar1[0xb]);

            piVar1[7] = iVar2;

            piVar1[6] = 1;

          }

        }

        else {

          if (((DAT_00632dbc != 0) && (iVar2 = piVar1[4] * 0x2c + DAT_00632dbc, iVar2 != 0)) &&

             (*(int *)(iVar2 + 8) != 0)) {

            (*DAT_005dd2a0)(iVar2,piVar1[10]);

          }

          if (((DAT_00633200 == 0) && (DAT_00632dbc != 0)) &&

             ((piVar3 = (int *)(piVar1[2] * 0x2c + DAT_00632dbc), piVar3 != (int *)0x0 &&

              (((*piVar3 != 0 && (piVar3[2] != 0)) &&

               (iVar2 = (*DAT_005dd2ac)(piVar3,piVar1[10]), iVar2 == 0)))))) {

            crt_sprintf(&DAT_00657400,s_SoundFail__s_0055c9b8,*piVar3);

            FUN_00425eb0(&DAT_00657400);

          }

          iVar2 = sound_play_obj(piVar1[3],piVar1[10]);

          piVar1[7] = iVar2;

          piVar1[6] = 1;

        }

      }

    }

    else {

      fVar4 = (float10)FUN_00518b70(0,0);

      fVar4 = (float10)(float)piVar1[8] - fVar4;

      piVar1[8] = (int)(float)fVar4;

      if (fVar4 <= (float10)0.0) goto LAB_00495a11;

      (*DAT_005dd2bc)(piVar1[7],(float)(fVar4 / (float10)(float)piVar1[9]));

    }

    piVar3 = (int *)*piVar1;

  } while( true );

}

/* ===== sound_play_checked @ 0x00495C70 ===== */
void sound_play_checked(int param_1)



{

  int iVar1;

  int *piVar2;

  float10 fVar3;

  

  if (*(int *)(param_1 + 0x28) == 0) {

    *(undefined4 *)(param_1 + 0x14) = 1;

    if (*(int *)(param_1 + 0x3c) == 0) {

      if ((((DAT_00633200 == 0) && (DAT_00632dbc != 0)) &&

          (piVar2 = (int *)(*(int *)(param_1 + 0x10) * 0x2c + DAT_00632dbc), piVar2 != (int *)0x0))

         && ((*piVar2 != 0 && (piVar2[2] != 0)))) {

        iVar1 = (*DAT_005dd2b4)(piVar2,0,*(undefined4 *)(param_1 + 0x2c));

        if (iVar1 != 0) {

          fVar3 = (float10)(*DAT_005dd2e8)(iVar1);

          *(float *)(param_1 + 0x20) = (float)fVar3;

          *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x20);

          *(undefined4 *)(param_1 + 0x44) = 0xffffffff;

          return;

        }

        crt_sprintf(&DAT_00657400,s_SoundFail__s_0055c9b8,*piVar2);

        FUN_00425eb0(&DAT_00657400);

      }

      *(undefined4 *)(param_1 + 0x20) = 0;

      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x20);

      *(undefined4 *)(param_1 + 0x44) = 0xffffffff;

      return;

    }

    if (((DAT_00633200 != 0) || (DAT_00632dbc == 0)) ||

       ((piVar2 = (int *)(*(int *)(param_1 + 0x10) * 0x2c + DAT_00632dbc), piVar2 == (int *)0x0 ||

        ((*piVar2 == 0 || (piVar2[2] == 0)))))) goto LAB_00495d07;

    iVar1 = (*DAT_005dd2b0)(piVar2,param_1 + 0x30,*(undefined4 *)(param_1 + 0x2c));

  }

  else {

    if (((DAT_00632dbc != 0) && (iVar1 = *(int *)(param_1 + 8) * 0x2c + DAT_00632dbc, iVar1 != 0))

       && (*(int *)(iVar1 + 8) != 0)) {

      (*DAT_005dd2a0)(iVar1,*(int *)(param_1 + 0x28));

    }

    *(undefined4 *)(param_1 + 0x14) = 1;

    if (((DAT_00633200 != 0) || (DAT_00632dbc == 0)) ||

       ((piVar2 = (int *)(*(int *)(param_1 + 0x10) * 0x2c + DAT_00632dbc), piVar2 == (int *)0x0 ||

        ((*piVar2 == 0 || (piVar2[2] == 0)))))) goto LAB_00495d07;

    iVar1 = (*DAT_005dd2ac)(piVar2,*(undefined4 *)(param_1 + 0x28));

  }

  if (iVar1 != 0) {

    fVar3 = (float10)(*DAT_005dd2e8)(iVar1);

    *(float *)(param_1 + 0x20) = (float)fVar3;

    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x20);

    *(undefined4 *)(param_1 + 0x44) = 0xffffffff;

    return;

  }

  crt_sprintf(&DAT_00657400,s_SoundFail__s_0055c9b8,*piVar2);

  FUN_00425eb0(&DAT_00657400);

LAB_00495d07:

  *(undefined4 *)(param_1 + 0x20) = 0;

  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x20);

  *(undefined4 *)(param_1 + 0x44) = 0xffffffff;

  return;

}

/* ===== sound_stop_sequence @ 0x00495E10 ===== */
/* PS2 candidate: sound_stop_sequence (conf 0.545) */



void sound_stop_sequence(int *param_1)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  

  if (DAT_0059f368 == (int *)0x0) {

    *param_1 = 0;

    return;

  }

  piVar3 = DAT_0059f368;

  while (piVar3[0x11] != *param_1) {

    piVar3 = (int *)*piVar3;

    if (piVar3 == (int *)0x0) {

      *param_1 = 0;

      return;

    }

  }

  iVar1 = piVar3[7];

  if (iVar1 != 0) {

    if (iVar1 != 0) {

      (*DAT_005dd2a8)(iVar1);

    }

    piVar3[7] = 0;

  }

  piVar2 = (int *)piVar3[1];

  piVar3[0x11] = 0;

  if (piVar2 == (int *)0x0) {

    DAT_0059f368 = (int *)*piVar3;

    if (DAT_0059f368 != (int *)0x0) {

      *(undefined4 *)((int)DAT_0059f368 + 4) = 0;

      *piVar3 = (int)DAT_0059f360;

      DAT_0059f360 = piVar3;

      *param_1 = 0;

      return;

    }

    DAT_0059f36c = (int *)0x0;

    *piVar3 = (int)DAT_0059f360;

    DAT_0059f360 = piVar3;

    *param_1 = 0;

    return;

  }

  if (*piVar3 == 0) {

    DAT_0059f36c = piVar2;

    *piVar2 = 0;

  }

  else {

    *piVar2 = *piVar3;

    *(int *)(*piVar3 + 4) = piVar3[1];

  }

  *piVar3 = (int)DAT_0059f360;

  DAT_0059f360 = piVar3;

  *param_1 = 0;

  return;

}

/* ===== sound_interrupt_sequence @ 0x00495EE0 ===== */
/* PS2 candidate: sound_interrupt_sequence (conf 0.482) */



void sound_interrupt_sequence(int *param_1)



{

  int *piVar1;

  

  if (DAT_0059f368 == (int *)0x0) {

    *param_1 = 0;

    return;

  }

  piVar1 = DAT_0059f368;

  do {

    if (piVar1[0x11] == *param_1) {

      sound_play_checked(piVar1);

      *param_1 = 0;

      return;

    }

    piVar1 = (int *)*piVar1;

  } while (piVar1 != (int *)0x0);

  *param_1 = 0;

  return;

}

/* ===== teammecc_clear_mode @ 0x004961C0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: sound_play_stream (conf 0.621) */



undefined4 teammecc_clear_mode(void)



{

  undefined4 uVar1;

  

  if (DAT_00633204 != 0) {

    return 0;

  }

                    /* WARNING: Could not recover jumptable at 0x004961cc. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar1 = (*_DAT_005dd348)();

  return uVar1;

}

/* ===== FUN_004961e0 @ 0x004961E0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 FUN_004961e0(void)



{

  undefined4 uVar1;

  

  if (DAT_00633204 != 0) {

    return 0;

  }

                    /* WARNING: Could not recover jumptable at 0x004961ec. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar1 = (*_DAT_005dd34c)();

  return uVar1;

}

/* ===== FUN_00496200 @ 0x00496200 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 FUN_00496200(void)



{

  float10 fVar1;

  

  if (DAT_00633204 != 0) {

    return (float10)0.0;

  }

                    /* WARNING: Could not recover jumptable at 0x00496210. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  fVar1 = (float10)(*_DAT_005dd350)();

  return fVar1;

}

/* ===== ambient_streams_stopped__FP6OBJECT @ 0x00496220 ===== */
void ambient_streams_stopped__FP6OBJECT(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x100);

  *(undefined4 *)(iVar1 + 0x2c) = 0;

  *(undefined4 *)(iVar1 + 0x30) = 0;

  return;

}

/* ===== objspec_dispatch_gate @ 0x004967B0 ===== */
void objspec_dispatch_gate(int param_1)



{

  if ((((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) &&

      ((*(uint *)(param_1 + 0xd8) & 0xc000) == 0)) && ((*(byte *)(param_1 + 0x1c8) & 0x10) == 0)) {

    FUN_0049a0c0();

    return;

  }

  return;

}

/* ===== objanim_select_anim @ 0x004967E0 ===== */
/* PS2 candidate: objanim_select_anim (conf 0.399) */



void objanim_select_anim(int param_1,int param_2)



{

  if ((*(int *)(param_1 + 0x10) != param_2) &&

     (*(int *)(*(int *)(param_1 + 8) + 8 + param_2 * 4) != 0)) {

    anim_select_check2();

    return;

  }

  return;

}

/* ===== objanim_select_anim_2 @ 0x00496810 ===== */
void objanim_select_anim_2(int param_1,int param_2)



{

  if ((*(int *)(param_1 + 0x10) != param_2) &&

     (*(int *)(*(int *)(param_1 + 8) + 8 + param_2 * 4) != 0)) {

    ObjectSetAnim(param_1,param_2,0x30,0,0,0x3e2aaaab);

  }

  return;

}

/* ===== anim_select_user @ 0x00496840 ===== */
void anim_select_user(int param_1,int param_2)



{

  if ((*(int *)(param_1 + 0x10) != param_2) &&

     (*(int *)(*(int *)(param_1 + 8) + 8 + param_2 * 4) != 0)) {

    anim_select_check();

    return;

  }

  return;

}

/* ===== object_get_num_objects @ 0x00496B10 ===== */
/* PS2 candidate: object_get_num_objects (conf 0.75) */



undefined4 object_get_num_objects(undefined4 *param_1)



{

  if (param_1 != (undefined4 *)0x0) {

    *param_1 = 3000;

  }

  return DAT_0059f374;

}

/* ===== object_uniqueid_alloc @ 0x00496BC0 ===== */
/* PS2 candidate: object_allocator__Fi (conf 0.375) */



uint object_uniqueid_alloc(void)



{

  uint uVar1;

  

  DAT_0059f37c = DAT_0059f37c + 1;

  if (DAT_0059f37c == 0) {

    FUN_0051ea20(s_Warning_we_ve_used_all_the_uniqu_0055ca0c);

    DAT_0059f37c = DAT_0059f37c + 1;

  }

  uVar1 = comm_0052b430();

  return uVar1 | DAT_0059f37c << 8;

}

/* ===== object_allocate_type @ 0x00496C00 ===== */
/* PS2 candidate: object_allocate_type (conf 0.75) */



undefined4 * object_allocate_type(int param_1,uint param_2)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 uVar3;

  int iVar4;

  int *piVar5;

  

  puVar1 = DAT_00632da4;

  DAT_0059f374 = DAT_0059f374 + 1;

  if (DAT_0059f378 < DAT_0059f374) {

    DAT_0059f378 = DAT_0059f374;

  }

  if (DAT_00632da4 == (undefined4 *)0x0) {

    error_screen_show(s_Out_of_objects__exceeded_limit_0055ca54);

  }

  else {

    puVar2 = DAT_00632da4;

    DAT_00632da4 = (undefined4 *)*DAT_00632da4;

    for (iVar4 = 0xc1; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    main_linkage_00470360(&DAT_00632d68,puVar1);

    puVar1[0x37] = puVar1[0x37] | 0x80000000;

    puVar1[0x31] = 0x3f800000;

    puVar2 = puVar1 + 4;

    iVar4 = 4;

    do {

      *puVar2 = 0xfe;

      puVar2 = puVar2 + 9;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

    uVar3 = object_uniqueid_alloc();

    puVar1[0x62] = uVar3;

    for (puVar2 = DAT_00632d54; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

      iVar4 = 0;

      if (0 < (int)puVar2[1]) {

        piVar5 = puVar2 + 3;

        do {

          if (*piVar5 == param_1) {

            puVar2 = puVar2 + iVar4 * 0xc1 + 2;

            if (puVar2 == (undefined4 *)0x0) goto LAB_00496ce5;

            object_copy_personality(puVar1,puVar2);

            object_copy_activedata(puVar1,puVar2);

            goto LAB_00496d41;

          }

          iVar4 = iVar4 + 1;

          piVar5 = piVar5 + 0xc1;

        } while (iVar4 < (int)puVar2[1]);

      }

    }

LAB_00496ce5:

    crt_sprintf(&DAT_00657400,s_Error__ObjObj_type__d_not_found_0055ca34,param_1);

    if (DAT_0055c9e0 < 1) {

      str_copy_to_static(&DAT_00657400);

      DAT_0055c9e0 = DAT_0055c9e0 + -1;

    }

    else {

      error_screen_show();

      DAT_0055c9e0 = DAT_0055c9e0 + -1;

    }

  }

LAB_00496d41:

  if (param_2 == 0x80000000) {

    param_2 = object_render_flags_calc(puVar1);

  }

  if (param_2 == 0x80000000) {

    param_2 = object_render_flags_calc(puVar1);

  }

  if ((param_2 & 1) != 0) {

    main_linkage_00470360(&DAT_00632d6c,puVar1);

  }

  if ((param_2 & 2) != 0) {

    main_linkage_00470360(&DAT_00632d70,puVar1);

  }

  if ((param_2 & 4) != 0) {

    main_linkage_00470360(&DAT_00632d74,puVar1);

  }

  if ((param_2 & 8) != 0) {

    main_linkage_00470360(&DAT_00632d78,puVar1);

  }

  if ((param_2 & 0x10) != 0) {

    main_linkage_00470360(&DAT_00632d7c,puVar1);

  }

  if ((param_2 & 0x20) != 0) {

    main_linkage_00470360(&DAT_00632d80,puVar1);

  }

  if ((param_2 & 0x40) != 0) {

    main_linkage_00470360(&DAT_00632d84,puVar1);

  }

  if ((char)param_2 < '\0') {

    main_linkage_00470360(&DAT_00632d88,puVar1);

  }

  if ((param_2 & 0x100) != 0) {

    main_linkage_00470360(&DAT_00632d8c,puVar1);

  }

  if ((param_2 & 0x200) != 0) {

    main_linkage_00470360(&DAT_00632d90,puVar1);

  }

  if ((param_2 & 0x400) != 0) {

    main_linkage_00470360(&DAT_00632d94,puVar1);

  }

  if ((param_2 & 0x800) != 0) {

    main_linkage_00470360(&DAT_00632d98,puVar1);

  }

  if ((param_2 & 0x1000) != 0) {

    main_linkage_00470360(&DAT_00632d9c,puVar1);

  }

  if ((param_2 & 0x2000) != 0) {

    main_linkage_00470360(&DAT_00632da0,puVar1);

  }

  return puVar1;

}

/* ===== object_render_flags_calc @ 0x00496E80 ===== */
uint object_render_flags_calc(int param_1)



{

  int iVar1;

  uint uVar2;

  

  if ((*(uint *)(param_1 + 0x1c8) & 0x20000) == 0) {

    uVar2 = (-(uint)((*(uint *)(param_1 + 0xd8) & 0x4000c000) != 0 ||

                    (*(uint *)(param_1 + 0x1c8) & 0x800) != 0) & 0xfffffff0) + 0x10;

  }

  else {

    uVar2 = 0x11;

  }

  switch(*(undefined4 *)(param_1 + 0x1e0)) {

  case 6:

    uVar2 = uVar2 | 0x20;

    break;

  case 8:

    uVar2 = uVar2 | 0x100;

    break;

  case 0x12:

    uVar2 = uVar2 | 0x811;

    break;

  case 0x15:

    uVar2 = uVar2 | 0x200;

    break;

  case 0x20:

  case 0x4a:

  case 0x52:

  case 0x53:

  case 0x5b:

    uVar2 = uVar2 | 0x1000;

    break;

  case 0x54:

    uVar2 = uVar2 | 0x400;

  }

  iVar1 = *(int *)(param_1 + 4);

  if (iVar1 < 0x2a) {

    if (iVar1 != 0x29) {

      switch(iVar1) {

      case 1:

        break;

      case 2:

      case 4:

        goto switchD_00496f0b_caseD_2;

      case 3:

      case 6:

      case 7:

        return uVar2 | 4;

      default:

        return uVar2;

      }

    }

switchD_00496f0b_caseD_1:

    return uVar2 | 8;

  }

  if (iVar1 < 0x2ea) {

    if (iVar1 == 0x2e9) goto switchD_00496f0b_caseD_1;

    if (iVar1 < 0x54) {

      return uVar2;

    }

    if ((0x55 < iVar1) && (iVar1 != 0x85)) {

      return uVar2;

    }

  }

  else if (iVar1 != 0x3df) {

    return uVar2;

  }

switchD_00496f0b_caseD_2:

  return uVar2 | 2;

}

/* ===== object_allocate_type_end @ 0x00497150 ===== */
/* PS2 candidate: object_allocate_type_end (conf 0.437) */



undefined4 * object_allocate_type_end(int param_1,uint param_2)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 uVar3;

  int iVar4;

  int *piVar5;

  

  puVar1 = DAT_00632da4;

  DAT_0059f374 = DAT_0059f374 + 1;

  if (DAT_0059f378 < DAT_0059f374) {

    DAT_0059f378 = DAT_0059f374;

  }

  if (DAT_00632da4 == (undefined4 *)0x0) {

    error_screen_show(s_Out_of_objects__exceeded_limit_0055ca54);

  }

  else {

    puVar2 = DAT_00632da4;

    DAT_00632da4 = (undefined4 *)*DAT_00632da4;

    for (iVar4 = 0xc1; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    main_linkage_00470360(&DAT_00632d68,puVar1);

    puVar1[0x37] = puVar1[0x37] | 0x80000000;

    puVar1[0x31] = 0x3f800000;

    puVar2 = puVar1 + 4;

    iVar4 = 4;

    do {

      *puVar2 = 0xfe;

      puVar2 = puVar2 + 9;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

    uVar3 = object_uniqueid_alloc();

    puVar1[0x62] = uVar3;

    for (puVar2 = DAT_00632d54; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

      iVar4 = 0;

      if (0 < (int)puVar2[1]) {

        piVar5 = puVar2 + 3;

        do {

          if (*piVar5 == param_1) {

            puVar2 = puVar2 + iVar4 * 0xc1 + 2;

            if (puVar2 == (undefined4 *)0x0) goto LAB_00497226;

            object_copy_personality(puVar1,puVar2);

            object_copy_activedata(puVar1,puVar2);

            goto LAB_00497282;

          }

          iVar4 = iVar4 + 1;

          piVar5 = piVar5 + 0xc1;

        } while (iVar4 < (int)puVar2[1]);

      }

    }

LAB_00497226:

    crt_sprintf(&DAT_00657400,s_Error__ObjObj_type__d_not_found_0055ca34,param_1);

    if (DAT_0055c9e0 < 1) {

      str_copy_to_static(&DAT_00657400);

      DAT_0055c9e0 = DAT_0055c9e0 + -1;

    }

    else {

      error_screen_show();

      DAT_0055c9e0 = DAT_0055c9e0 + -1;

    }

  }

LAB_00497282:

  if (param_2 == 0x80000000) {

    param_2 = object_render_flags_calc(puVar1);

  }

  if (param_2 == 0x80000000) {

    param_2 = object_render_flags_calc(puVar1);

  }

  if ((param_2 & 1) != 0) {

    main_linkage_00470360(&DAT_00632d6c,puVar1);

  }

  if ((param_2 & 2) != 0) {

    main_linkage_00470360(&DAT_00632d70,puVar1);

  }

  if ((param_2 & 4) != 0) {

    main_linkage_00470360(&DAT_00632d74,puVar1);

  }

  if ((param_2 & 8) != 0) {

    main_linkage_00470360(&DAT_00632d78,puVar1);

  }

  if ((param_2 & 0x10) != 0) {

    main_linkage_00470360(&DAT_00632d7c,puVar1);

  }

  if ((param_2 & 0x20) != 0) {

    main_linkage_00470360(&DAT_00632d80,puVar1);

  }

  if ((param_2 & 0x40) != 0) {

    main_linkage_00470360(&DAT_00632d84,puVar1);

  }

  if ((char)param_2 < '\0') {

    main_linkage_00470360(&DAT_00632d88,puVar1);

  }

  if ((param_2 & 0x100) != 0) {

    main_linkage_00470360(&DAT_00632d8c,puVar1);

  }

  if ((param_2 & 0x200) != 0) {

    main_linkage_00470360(&DAT_00632d90,puVar1);

  }

  if ((param_2 & 0x400) != 0) {

    main_linkage_00470360(&DAT_00632d94,puVar1);

  }

  if ((param_2 & 0x800) != 0) {

    main_linkage_00470360(&DAT_00632d98,puVar1);

  }

  if ((param_2 & 0x1000) != 0) {

    main_linkage_00470360(&DAT_00632d9c,puVar1);

  }

  if ((param_2 & 0x2000) != 0) {

    main_linkage_00470360(&DAT_00632da0,puVar1);

  }

  return puVar1;

}

/* ===== object_stop_movement_2 @ 0x004973C0 ===== */
/* PS2 candidate: object_stop_movement_3 (conf 0.565) */



void object_stop_movement_2(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = (undefined4 *)(param_1 + 400);

  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  *(undefined4 *)(param_1 + 0x1a0) = 0x42000000;

  *(undefined4 *)(param_1 + 0x1ac) = 0x42000000;

  *(undefined4 *)(param_1 + 0x1b8) = 0x42000000;

  *(undefined4 *)(param_1 + 0x1bc) = 0x42c80000;

  *(undefined4 *)(param_1 + 0x19c) = 0x3f800000;

  *(undefined4 *)(param_1 + 0x1b0) = 0x3f800000;

  *(undefined4 *)(param_1 + 0x198) = 0x3f800000;

  *(undefined4 *)(param_1 + 0x1b4) = 0x3f800000;

  *(undefined4 *)(param_1 + 0x1e8) = 0x3f800000;

  *(undefined4 *)(param_1 + 0x1e4) = 0x3f800000;

  *(undefined4 *)(param_1 + 0x1ec) = 0x3f800000;

  *(undefined4 *)(param_1 + 0x1f0) = 0x41f00000;

  *(undefined4 *)(param_1 + 0x200) = 0x42c80000;

  *(undefined4 *)(param_1 + 0x1c0) = 0x42c80000;

  *(undefined4 *)(param_1 + 0x1c4) = 100;

  return;

}

/* ===== object_destroy @ 0x00497510 ===== */
/* PS2 candidate: object_destroy (conf 0.467) */



void object_destroy(int param_1)



{

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x8000;

  return;

}

/* ===== obj_children_flag_set @ 0x00497520 ===== */
void obj_children_flag_set(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x4000;

  for (puVar2 = DAT_00632d68; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    if (((*(uint *)(iVar1 + 0xd8) & 0x4000) == 0) && (*(int *)(iVar1 + 0x210) == param_1)) {

      obj_children_flag_set(iVar1);

    }

  }

  return;

}

/* ===== obj_children_flag_clear @ 0x00497570 ===== */
void obj_children_flag_clear(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xffffbfff;

  for (puVar2 = DAT_00632d68; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    if (((*(uint *)(iVar1 + 0xd8) & 0x4000) != 0) && (*(int *)(iVar1 + 0x210) == param_1)) {

      obj_children_flag_clear(iVar1);

    }

  }

  return;

}

/* ===== object_copy_posdirinfo_2 @ 0x004979B0 ===== */
/* PS2 candidate: object_copy_posdirinfo (conf 0.324) */



void object_copy_posdirinfo_2(int param_1,int param_2)



{

  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_2 + 0xa0);

  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_2 + 0xa4);

  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_2 + 0xa8);

  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_2 + 0xb8);

  *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_2 + 0xbc);

  *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_2 + 0xc0);

  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_2 + 0xac);

  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_2 + 0xb0);

  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_2 + 0xb4);

  *(undefined4 *)(param_1 + 200) = *(undefined4 *)(param_2 + 200);

  *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_2 + 0xd4);

  *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_2 + 0xcc);

  *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_2 + 0xd0);

  return;

}

/* ===== object_copy_activedata @ 0x00497A50 ===== */
/* PS2 candidate: object_copy_activedata (conf 0.337) */



void object_copy_activedata(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  

  iVar1 = param_2;

  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_2 + 0xa0);

  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_2 + 0xa4);

  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_2 + 0xa8);

  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_2 + 0xb8);

  *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_2 + 0xbc);

  *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_2 + 0xc0);

  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_2 + 0xac);

  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_2 + 0xb0);

  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_2 + 0xb4);

  *(undefined4 *)(param_1 + 200) = *(undefined4 *)(param_2 + 200);

  *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_2 + 0xd4);

  *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_2 + 0xcc);

  *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_2 + 0xd0);

  *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(param_2 + 0xd8);

  *(uint *)(param_1 + 0xdc) = *(uint *)(param_2 + 0xdc) | 0x80000000;

  *(undefined4 *)(param_1 + 0x18c) = *(undefined4 *)(param_2 + 0x18c);

  *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_2 + 0xe0);

  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_2 + 0xe8);

  *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_2 + 0xe4);

  object_copy_ospec(param_1,param_2);

  *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_2 + 0xec);

  if (0 < *(int *)(param_2 + 0x1d8)) {

    iVar2 = FUN_00455fa0(param_2);

    if ((0 < iVar2) && (iVar2 <= *(int *)(param_1 + 0x1d8))) {

      object_create_gun(param_1,iVar2);

    }

    iVar2 = FUN_00455f20(param_2);

    if ((0 < iVar2) && (iVar2 <= *(int *)(param_1 + 0x1d8))) {

      object_create_gun_2(param_1,iVar2);

    }

  }

  puVar3 = (undefined4 *)(param_1 + 0x10);

  iVar2 = param_2 - param_1;

  param_2 = 4;

  do {

    puVar5 = (undefined4 *)(iVar2 + (int)puVar3);

    puVar6 = puVar3;

    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar6 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar6 = puVar6 + 1;

    }

    puVar3 = puVar3 + 9;

    param_2 = param_2 + -1;

  } while (param_2 != 0);

  teammate_copy_weapons(param_1,iVar1);

  return;

}

/* ===== objobj_type_lookup @ 0x00497BD0 ===== */
void objobj_type_lookup(int param_1,int param_2)



{

  undefined4 *puVar1;

  int iVar2;

  int *piVar3;

  

  puVar1 = DAT_00632d54;

  if (param_2 == 0) {

    return;

  }

  do {

    if (puVar1 == (undefined4 *)0x0) {

LAB_00497c25:

      crt_sprintf(&DAT_00657400,s_Error__ObjObj_type__d_not_found_0055ca34,param_1);

      if (0 < DAT_0055c9e0) {

        error_screen_show();

        DAT_0055c9e0 = DAT_0055c9e0 + -1;

        return;

      }

      str_copy_to_static(&DAT_00657400);

      DAT_0055c9e0 = DAT_0055c9e0 + -1;

      return;

    }

    iVar2 = 0;

    if (0 < (int)puVar1[1]) {

      piVar3 = puVar1 + 3;

      do {

        if (*piVar3 == param_1) {

          puVar1 = puVar1 + iVar2 * 0xc1 + 2;

          if (puVar1 != (undefined4 *)0x0) {

            object_copy_personality(param_2,puVar1);

            object_copy_activedata(param_2,puVar1);

            return;

          }

          goto LAB_00497c25;

        }

        iVar2 = iVar2 + 1;

        piVar3 = piVar3 + 0xc1;

      } while (iVar2 < (int)puVar1[1]);

    }

    puVar1 = (undefined4 *)*puVar1;

  } while( true );

}

/* ===== FUN_00497c90 @ 0x00497C90 ===== */
void FUN_00497c90(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  if ((param_1 != 0) && (iVar1 = 0, 0 < *(int *)(param_1 + 0x68))) {

    puVar2 = (undefined4 *)(param_1 + 0x90);

    do {

      main_00508840(*puVar2);

      iVar1 = iVar1 + 1;

      puVar2 = puVar2 + 0x14;

    } while (iVar1 < *(int *)(param_1 + 0x68));

  }

  return;

}

/* ===== objectset_find_2 @ 0x00497CD0 ===== */
undefined4 objectset_find_2(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar1 = DAT_00632d4c;

  do {

    if (puVar1 == (undefined4 *)0x0) {

      return 0;

    }

    iVar2 = 0;

    if (0 < (int)puVar1[1]) {

      puVar3 = puVar1 + 2;

      do {

        if (*(int *)*puVar3 == param_1) {

          return puVar1[iVar2 + 2];

        }

        iVar2 = iVar2 + 1;

        puVar3 = puVar3 + 1;

      } while (iVar2 < (int)puVar1[1]);

    }

    puVar1 = (undefined4 *)*puVar1;

  } while( true );

}

/* ===== objectset_find @ 0x00497D20 ===== */
/* PS2 candidate: objectset_find (conf 0.519) */



undefined4 * objectset_find(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  int *piVar3;

  

  puVar1 = DAT_00632d50;

  do {

    if (puVar1 == (undefined4 *)0x0) {

      return (undefined4 *)0x0;

    }

    iVar2 = 0;

    if (0 < (int)puVar1[1]) {

      piVar3 = puVar1 + 2;

      do {

        if (*piVar3 == param_1) {

          return puVar1 + iVar2 * 0x119 + 2;

        }

        iVar2 = iVar2 + 1;

        piVar3 = piVar3 + 0x119;

      } while (iVar2 < (int)puVar1[1]);

    }

    puVar1 = (undefined4 *)*puVar1;

  } while( true );

}

/* ===== object_find @ 0x00497D70 ===== */
/* PS2 candidate: object_find (conf 0.38) */



undefined4 * object_find(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  int *piVar3;

  

  puVar1 = DAT_00632d54;

  do {

    if (puVar1 == (undefined4 *)0x0) {

      return (undefined4 *)0x0;

    }

    iVar2 = 0;

    if (0 < (int)puVar1[1]) {

      piVar3 = puVar1 + 3;

      do {

        if (*piVar3 == param_1) {

          return puVar1 + iVar2 * 0xc1 + 2;

        }

        iVar2 = iVar2 + 1;

        piVar3 = piVar3 + 0xc1;

      } while (iVar2 < (int)puVar1[1]);

    }

    puVar1 = (undefined4 *)*puVar1;

  } while( true );

}

/* ===== obj_ptr_clear_if_dead @ 0x00497DC0 ===== */
void obj_ptr_clear_if_dead(int *param_1)



{

  if ((*param_1 != 0) && ((char)((uint)*(undefined4 *)(*param_1 + 0xd8) >> 8) < '\0')) {

    *param_1 = 0;

  }

  return;

}

/* ===== weapon_id_inventory_update @ 0x00497DE0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void weapon_id_inventory_update(void)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  int *piVar5;

  int iVar6;

  undefined4 *puVar7;

  undefined4 *puVar8;

  int *piVar9;

  bool bVar10;

  int local_90 [36];

  

  DAT_0059f98c = 0;

  puVar1 = (undefined4 *)AudioGetMasterVolume__Fv();

  if (puVar1[2] == 0) {

    return;

  }

  iVar2 = camera_is_sniper();

  if (iVar2 == 0) {

    return;

  }

  iVar2 = ObjIsMecc(puVar1);

  if (iVar2 == 0) {

    iVar2 = ObjIsReaper(puVar1);

    if (iVar2 == 0) {

      iVar2 = ObjIsKabuto(puVar1);

      if (iVar2 == 0) {

        return;

      }

      iVar2 = *(int *)(puVar1[0x40] + 0xa0);

      iVar3 = *(int *)(puVar1[0x40] + 0xa4);

    }

    else {

      iVar2 = *(int *)(puVar1[0x40] + 0xfb4);

      iVar3 = 0;

    }

  }

  else {

    iVar2 = *(int *)(puVar1[0x40] + 0x6c);

    iVar3 = 0;

  }

  if (iVar2 == 0) {

    return;

  }

  DAT_0059f990 = (uint)(iVar3 != 0);

  piVar5 = &DAT_0059f698;

  piVar9 = local_90;

  for (iVar6 = 0x24; iVar6 != 0; iVar6 = iVar6 + -1) {

    *piVar9 = *piVar5;

    piVar5 = piVar5 + 1;

    piVar9 = piVar9 + 1;

  }

  bVar10 = DAT_0059f990 == 0;

  DAT_0059f98c = 1;

  puVar7 = puVar1;

  puVar8 = &DAT_0059f688;

  for (iVar6 = 0xc1; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar8 = *puVar7;

    puVar7 = puVar7 + 1;

    puVar8 = puVar8 + 1;

  }

  DAT_0059f688 = 0;

  piVar5 = local_90;

  piVar9 = &DAT_0059f698;

  for (iVar6 = 0x24; iVar6 != 0; iVar6 = iVar6 + -1) {

    *piVar9 = *piVar5;

    piVar5 = piVar5 + 1;

    piVar9 = piVar9 + 1;

  }

  if (bVar10) {

    _DAT_0059f690 = iVar2;

    return;

  }

  piVar5 = &DAT_0059f390;

  piVar9 = local_90;

  for (iVar6 = 0x24; iVar6 != 0; iVar6 = iVar6 + -1) {

    *piVar9 = *piVar5;

    piVar5 = piVar5 + 1;

    piVar9 = piVar9 + 1;

  }

  puVar7 = &DAT_0059f380;

  _DAT_0059f690 = iVar2;

  for (iVar6 = 0xc1; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar7 = *puVar1;

    puVar1 = puVar1 + 1;

    puVar7 = puVar7 + 1;

  }

  piVar5 = local_90;

  piVar9 = &DAT_0059f390;

  for (iVar2 = 0x24; iVar2 != 0; iVar2 = iVar2 + -1) {

    *piVar9 = *piVar5;

    piVar5 = piVar5 + 1;

    piVar9 = piVar9 + 1;

  }

  if (*(int *)(iVar3 + 8 + local_90[0] * 4) != 0) {

    _DAT_0059f388 = iVar3;

    return;

  }

  _DAT_0059f388 = iVar3;

  iVar3 = ObjIsMecc(&DAT_0059f380);

  iVar2 = DAT_0059f390;

  if (iVar3 == 0) {

    iVar2 = ObjIsReaper(&DAT_0059f380);

    if (iVar2 != 0) {

      obj_weapon_animselect(&DAT_0059f380);

      return;

    }

    if (DAT_0059f390 == 1) {

      return;

    }

    iVar2 = 1;

  }

  else {

    if ((*(uint *)(DAT_00632a88 + 0xe0) & 0x40000) != 0) {

      uVar4 = 0x24;

      goto LAB_00497f49;

    }

    if (DAT_0059f390 == 0x24) {

LAB_00497f67:

      if ((DAT_0059f3b0 & 2) == 0) goto LAB_00498199;

    }

    else {

      if ((*(uint *)(DAT_00632a88 + 0xe0) & 0x4000) != 0) {

        uVar4 = WeaponIdGetPresent__FP6OBJECT(&DAT_0059f380);

        iVar2 = IconDef_valid_check(uVar4);

        uVar4 = *(undefined4 *)(&DAT_0055cad0 + iVar2 * 4);

        goto LAB_00497f49;

      }

      if (((_DAT_0059f48c != 0.0) || (_DAT_0059f490 != 0.0)) || (_DAT_0059f494 != 0.0)) {

        uVar4 = WeaponIdGetPresent__FP6OBJECT(&DAT_0059f380);

        iVar2 = IconDef_valid_check(uVar4);

        iVar2 = (&DAT_0055cac0)[iVar2];

        goto LAB_00498199;

      }

      iVar3 = ObjIsMecc(&DAT_0059f380);

      if (iVar3 != 0) {

        piVar5 = &DAT_0055cab0;

        do {

          if (DAT_0059f390 == *piVar5) goto LAB_00498087;

          piVar5 = piVar5 + 1;

        } while ((int)piVar5 < 0x55cac0);

      }

      if ((DAT_0059f58c & 0x30) != 0) {

        iVar3 = 1;

        do {

          iVar6 = FUN_00457fb0(DAT_00632a88,iVar3);

          if (iVar6 != -1) goto LAB_00498087;

          iVar3 = iVar3 + 1;

        } while (iVar3 < 5);

      }

      iVar3 = ObjIsMecc(&DAT_0059f380);

      if (iVar3 != 0) {

        piVar5 = &DAT_0055cac0;

        do {

          if (DAT_0059f390 == *piVar5) goto LAB_00497f67;

          piVar5 = piVar5 + 1;

        } while ((int)piVar5 < 0x55cad0);

      }

    }

LAB_00497f79:

    uVar4 = WeaponIdGetPresent__FP6OBJECT(&DAT_0059f380);

    iVar2 = IconDef_valid_check(uVar4);

    iVar2 = *(int *)(&DAT_0055caa0 + iVar2 * 4);

  }

LAB_00498199:

  anim_select_user(&DAT_0059f380,iVar2);

  return;

LAB_00498087:

  iVar3 = ObjIsMecc(&DAT_0059f380);

  if (iVar3 != 0) {

    piVar5 = &DAT_0055cab0;

    do {

      if (DAT_0059f390 == *piVar5) {

        if ((DAT_0059f3b0 & 2) == 0) goto LAB_00498199;

        if ((DAT_0059f3b0 & 0x10) == 0) {

          iVar2 = WeaponIdGetPresent__FP6OBJECT(&DAT_0059f380);

          if (iVar2 == DAT_0055cb00) {

            return;

          }

          uVar4 = WeaponIdGetPresent__FP6OBJECT(&DAT_0059f380);

          iVar2 = IconDef_valid_check(uVar4);

          DAT_0059f390 = 0xffffffff;

          objanim_select_anim_2(&DAT_0059f380,(&DAT_0055cab0)[iVar2]);

          return;

        }

        goto LAB_00497f79;

      }

      piVar5 = piVar5 + 1;

    } while ((int)piVar5 < 0x55cac0);

  }

  DAT_0055cb00 = WeaponIdGetPresent__FP6OBJECT(&DAT_0059f380);

  uVar4 = WeaponIdGetPresent__FP6OBJECT(&DAT_0059f380);

  iVar2 = IconDef_valid_check(uVar4);

  uVar4 = (&DAT_0055cab0)[iVar2];

LAB_00497f49:

  objanim_select_anim(&DAT_0059f380,uVar4);

  return;

}

/* ===== obj_weapon_animselect @ 0x004981C0 ===== */
void obj_weapon_animselect(int param_1)



{

  char *pcVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  

  pcVar1 = *(char **)(param_1 + 0x100);

  iVar2 = gun_find_right(DAT_00632a88);

  if (iVar2 == 0) {

    return;

  }

  iVar3 = *(int *)(param_1 + 0x10);

  uVar4 = (uint)(*(int *)(iVar2 + 4) == 0x29d);

  if ((*(uint *)(param_1 + 0x20c) & 0x100) != 0) {

    objanim_select_anim(param_1,*(undefined4 *)(&DAT_0055caf8 + uVar4 * 4));

    return;

  }

  if (iVar3 == *(int *)(&DAT_0055caf8 + uVar4 * 4)) {

    if ((*(byte *)(param_1 + 0x30) & 2) == 0) goto LAB_00498224;

  }

  else {

    if (((*(uint *)(param_1 + 0xe0) & 0x10) != 0) || (*pcVar1 < '\0')) {

      objanim_select_anim(param_1,*(undefined4 *)(&DAT_0055cae8 + uVar4 * 4));

      return;

    }

    if ((*(uint *)(param_1 + 0xe0) & 0x8000000) != 0) {

      objanim_select_anim(param_1,0x18);

      return;

    }

    if (((*(float *)(param_1 + 0x10c) != 0.0) || (*(float *)(param_1 + 0x110) != 0.0)) ||

       (*(float *)(param_1 + 0x114) != 0.0)) {

      anim_select_user(param_1,*(undefined4 *)(&DAT_0055caf0 + uVar4 * 4));

      return;

    }

  }

  iVar3 = *(int *)(&DAT_0055cae0 + uVar4 * 4);

LAB_00498224:

  anim_select_user(param_1,iVar3);

  return;

}

/* ===== mecc_logic @ 0x004982C0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: mecc_logic (conf 0.605) */



void mecc_logic(void)



{

  char *pcVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  float10 fVar5;

  

  iVar3 = DAT_00632a88;

  iVar2 = AudioGetMasterVolume__Fv();

  if (iVar3 != iVar2) {

    return;

  }

  if (DAT_0059f98c == 0) {

    return;

  }

  iVar3 = ObjIsMecc(&DAT_0059f688);

  if (iVar3 != 0) {

    weapon_id_check_big();

    goto LAB_0049841a;

  }

  iVar3 = ObjIsReaper(&DAT_0059f688);

  pcVar1 = DAT_0059f788;

  if (iVar3 == 0) {

    if (DAT_0059f698 == 1) goto LAB_0049841a;

    iVar3 = 1;

  }

  else {

    iVar3 = gun_find_right(DAT_00632a88);

    if (iVar3 == 0) goto LAB_0049841a;

    uVar4 = (uint)(*(int *)(iVar3 + 4) == 0x29d);

    if ((DAT_0059f894 & 0x100) != 0) {

      objanim_select_anim(&DAT_0059f688,*(undefined4 *)(&DAT_0055caf8 + uVar4 * 4));

      goto LAB_0049841a;

    }

    if (DAT_0059f698 == *(int *)(&DAT_0055caf8 + uVar4 * 4)) {

      iVar3 = DAT_0059f698;

      if ((DAT_0059f6b8 & 2) != 0) {

LAB_00498377:

        iVar3 = *(int *)(&DAT_0055cae0 + uVar4 * 4);

      }

    }

    else {

      if (((DAT_0059f768 & 0x10) != 0) || (*pcVar1 < '\0')) {

        objanim_select_anim(&DAT_0059f688,*(undefined4 *)(&DAT_0055cae8 + uVar4 * 4));

        goto LAB_0049841a;

      }

      if ((DAT_0059f768 & 0x8000000) != 0) {

        objanim_select_anim(&DAT_0059f688,0x18);

        goto LAB_0049841a;

      }

      if (((_DAT_0059f794 == 0.0) && (_DAT_0059f798 == 0.0)) && (_DAT_0059f79c == 0.0))

      goto LAB_00498377;

      iVar3 = *(int *)(&DAT_0055caf0 + uVar4 * 4);

    }

  }

  anim_select_user(&DAT_0059f688,iVar3);

LAB_0049841a:

  kabuto_logic();

  fVar5 = (float10)FUN_00518b70(DAT_00632a88,0);

  object_animate_process(&DAT_0059f688,(float)fVar5);

  iVar3 = ObjIsMecc(DAT_00632a88);

  if ((iVar3 != 0) && ((*(uint *)(DAT_00632a88 + 0xe0) & 0x2000000) == 0)) {

    mecc_fire_logic__FP6OBJECT(DAT_00632a88);

  }

  object_animate_process(&DAT_0059f688,0);

  if (DAT_0059f990 != 0) {

    fVar5 = (float10)FUN_00518b70(DAT_00632a88,0);

    object_animate_process(&DAT_0059f380,(float)fVar5);

  }

  return;

}

/* ===== kabuto_logic @ 0x004984B0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: kabuto_logic (conf 0.424) */



void kabuto_logic(void)



{

  int iVar1;

  int iVar2;

  float *pfVar3;

  float *pfVar4;

  float10 fVar5;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  XFGetViewportExt(&local_5c,&local_68,&local_60,&local_c);

  ref_anode_user();

  iVar1 = AudioGetMasterVolume__Fv();

  iVar2 = ObjIsMecc(iVar1);

  if (iVar2 == 0) {

    iVar2 = ObjIsReaper(iVar1);

    if (iVar2 == 0) {

      iVar2 = ObjIsKabuto(iVar1);

      if (iVar2 == 0) {

        return;

      }

      pfVar3 = (float *)(*(int *)(iVar1 + 0x100) + 0xa8);

      pfVar4 = (float *)(*(int *)(iVar1 + 0x100) + 0xb4);

    }

    else {

      pfVar3 = (float *)(*(int *)(iVar1 + 0x100) + 0xfb8);

      pfVar4 = (float *)0x0;

    }

  }

  else {

    pfVar3 = (float *)(*(int *)(iVar1 + 0x100) + 0x70);

    pfVar4 = (float *)0x0;

  }

  XFGetViewportExt(&local_6c,&local_64,&local_58,&local_18);

  fVar5 = (float10)playerobj_turn(local_5c,local_6c);

  local_5c = (float)(fVar5 + (float10)local_6c);

  fVar5 = (float10)playerobj_turn(local_68,local_64);

  local_68 = (float)(fVar5 + (float10)local_64);

  fVar5 = (float10)playerobj_turn(local_60,local_58);

  local_60 = (float)(fVar5 + (float10)local_58);

  local_70 = (local_6c * 5.0 + local_5c) * 0.16666667;

  local_74 = (local_64 * 5.0 + local_68) * 0.16666667;

  local_20 = (local_58 * 5.0 + local_60) * 0.16666667;

  fVar5 = (float10)FUN_0050a610(&local_c,&local_18);

  if (fVar5 <= (float10)0.10890001) {

    local_3c = local_c;

    local_38 = local_8;

    local_34 = local_4;

  }

  else {

    local_84 = local_c - local_18;

    local_80 = local_8 - local_14;

    local_7c = local_4 - local_10;

    normalize__FPfN20(&local_84,&local_80,&local_7c);

    local_3c = local_84 * 0.33 + local_18;

    local_38 = local_80 * 0.33 + local_14;

    local_34 = local_7c * 0.33 + local_10;

  }

  sine_cos_lookup(local_70,&local_1c,&local_30);

  sine_cos_lookup(local_74,&local_78,&local_88);

  local_84 = local_88 * local_1c;

  local_7c = local_78;

  local_4c = local_88;

  local_80 = -(local_88 * local_30);

  local_54 = -(local_78 * local_1c);

  local_50 = local_78 * local_30;

  local_2c = local_88 * local_80 - local_50 * local_78;

  local_28 = local_54 * local_78 - local_88 * local_84;

  local_24 = local_50 * local_84 - local_54 * local_80;

  _DAT_0059f728 = local_54 * pfVar3[2] + local_2c * pfVar3[1] + local_84 * *pfVar3 + local_3c;

  _DAT_0059f72c = local_50 * pfVar3[2] + local_28 * pfVar3[1] + local_80 * *pfVar3 + local_38;

  _DAT_0059f730 = local_88 * pfVar3[2] + local_24 * pfVar3[1] + local_78 * *pfVar3 + local_34;

  _DAT_0059f750 = local_70;

  _DAT_0059f758 = local_20;

  _DAT_0059f754 = local_74;

  local_48 = _DAT_0059f728;

  local_44 = _DAT_0059f72c;

  local_40 = _DAT_0059f730;

  ObjectCalculateTransform(&DAT_0059f688);

  if (DAT_0059f990 != 0) {

    _DAT_0059f420 = local_54 * pfVar4[2] + local_2c * pfVar4[1] + local_84 * *pfVar4 + local_3c;

    _DAT_0059f424 = local_50 * pfVar4[2] + local_28 * pfVar4[1] + local_80 * *pfVar4 + local_38;

    _DAT_0059f448 = local_70;

    _DAT_0059f450 = local_20;

    _DAT_0059f44c = local_74;

    _DAT_0059f428 = local_4c * pfVar4[2] + local_24 * pfVar4[1] + local_7c * *pfVar4 + local_34;

    local_48 = _DAT_0059f420;

    local_44 = _DAT_0059f424;

    local_40 = _DAT_0059f428;

    ObjectCalculateTransform(&DAT_0059f380);

  }

  return;

}

/* ===== weapon_id_check_big @ 0x004988E0 ===== */
void weapon_id_check_big(int param_1)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  

  iVar2 = *(int *)(param_1 + 0x10);

  if ((*(uint *)(DAT_00632a88 + 0xe0) & 0x40000) != 0) {

    objanim_select_anim(param_1,0x24);

    return;

  }

  if (iVar2 == 0x24) {

LAB_00498914:

    if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

LAB_00498ae1:

      anim_select_user(param_1,iVar2);

      return;

    }

  }

  else {

    if ((*(uint *)(DAT_00632a88 + 0xe0) & 0x4000) != 0) {

      uVar1 = WeaponIdGetPresent__FP6OBJECT(param_1);

      iVar2 = IconDef_valid_check(uVar1);

      objanim_select_anim(param_1,*(undefined4 *)(&DAT_0055cad0 + iVar2 * 4));

      return;

    }

    if (((*(float *)(param_1 + 0x10c) != 0.0) || (*(float *)(param_1 + 0x110) != 0.0)) ||

       (*(float *)(param_1 + 0x114) != 0.0)) {

      uVar1 = WeaponIdGetPresent__FP6OBJECT(param_1);

      iVar2 = IconDef_valid_check(uVar1);

      iVar2 = (&DAT_0055cac0)[iVar2];

      goto LAB_00498ae1;

    }

    iVar3 = ObjIsMecc(param_1);

    if (iVar3 != 0) {

      piVar4 = &DAT_0055cab0;

      do {

        if (*(int *)(param_1 + 0x10) == *piVar4) goto LAB_00498a2c;

        piVar4 = piVar4 + 1;

      } while ((int)piVar4 < 0x55cac0);

    }

    if ((*(byte *)(param_1 + 0x20c) & 0x30) != 0) {

      iVar3 = 1;

      do {

        iVar5 = FUN_00457fb0(DAT_00632a88,iVar3);

        if (iVar5 != -1) goto LAB_00498a2c;

        iVar3 = iVar3 + 1;

      } while (iVar3 < 5);

    }

    iVar3 = ObjIsMecc(param_1);

    if (iVar3 != 0) {

      piVar4 = &DAT_0055cac0;

      do {

        if (*(int *)(param_1 + 0x10) == *piVar4) goto LAB_00498914;

        piVar4 = piVar4 + 1;

      } while ((int)piVar4 < 0x55cad0);

    }

  }

LAB_0049891f:

  uVar1 = WeaponIdGetPresent__FP6OBJECT(param_1);

  iVar2 = IconDef_valid_check(uVar1);

  anim_select_user(param_1,*(undefined4 *)(&DAT_0055caa0 + iVar2 * 4));

  return;

LAB_00498a2c:

  iVar3 = ObjIsMecc(param_1);

  if (iVar3 != 0) {

    piVar4 = &DAT_0055cab0;

    do {

      if (*(int *)(param_1 + 0x10) == *piVar4) {

        if ((*(uint *)(param_1 + 0x30) & 2) == 0) goto LAB_00498ae1;

        if ((*(uint *)(param_1 + 0x30) & 0x10) == 0) {

          iVar2 = WeaponIdGetPresent__FP6OBJECT(param_1);

          if (iVar2 != DAT_0055cb00) {

            uVar1 = WeaponIdGetPresent__FP6OBJECT(param_1);

            iVar2 = IconDef_valid_check(uVar1);

            uVar1 = (&DAT_0055cab0)[iVar2];

            *(undefined4 *)(param_1 + 0x10) = 0xffffffff;

            objanim_select_anim_2(param_1,uVar1);

          }

          return;

        }

        goto LAB_0049891f;

      }

      piVar4 = piVar4 + 1;

    } while ((int)piVar4 < 0x55cac0);

  }

  DAT_0055cb00 = WeaponIdGetPresent__FP6OBJECT(param_1);

  uVar1 = WeaponIdGetPresent__FP6OBJECT(param_1);

  iVar2 = IconDef_valid_check(uVar1);

  objanim_select_anim(param_1,(&DAT_0055cab0)[iVar2]);

  return;

}

/* ===== vimp_death_fx @ 0x00498AF0 ===== */
void vimp_death_fx(int param_1)



{

  int iVar1;

  

  if (DAT_0059f98c == 0) {

    if (((((*(byte *)(param_1 + 0x1c8) & 0x40) == 0) && ((*(byte *)(param_1 + 0xd8) & 0x10) == 0))

        && (-61.1 < *(float *)(param_1 + 0x140))) && (DAT_0063311c == 0)) {

      rp_spark_hud_setup(param_1);

    }

    alpha_queue_push(param_1);

    return;

  }

  if (param_1 != DAT_00632a88) {

    iVar1 = ObjIsMecc(*(undefined4 *)(param_1 + 0x210));

    if (iVar1 == 0) {

      iVar1 = ObjIsJetski(param_1);

    }

    else {

      iVar1 = mecc_in_gyro(*(undefined4 *)(param_1 + 0x210));

    }

    if (iVar1 != 0) {

      return;

    }

    sine_cosine_table_gen(param_1);

    alpha_queue_push(param_1);

    return;

  }

  iVar1 = ObjIsMecc(DAT_00632a88);

  if (iVar1 != 0) {

    if ((*(uint *)(DAT_00632a88 + 0xe0) & 0x2000000) != 0) {

      return;

    }

    iVar1 = mecc_in_gyro(param_1);

    if (iVar1 != 0) {

      return;

    }

  }

  iVar1 = ObjIsReaper(DAT_00632a88);

  if (iVar1 != 0) {

    if (*(int *)(*(int *)(DAT_00632a88 + 0x100) + 0xf20) != 0) {

      return;

    }

    iVar1 = ObjIsJetski(*(undefined4 *)(param_1 + 0x210));

    if (iVar1 != 0) {

      return;

    }

  }

  iVar1 = ObjIsKabuto(DAT_00632a88);

  if ((iVar1 == 0) || (DAT_00632adf == '\0')) {

    sine_cosine_table_gen(&DAT_0059f688);

    alpha_queue_push(&DAT_0059f688);

    if (DAT_0059f990 != 0) {

      sine_cosine_table_gen(&DAT_0059f380);

      alpha_queue_push();

      return;

    }

  }

  return;

}

/* ===== object_lock_with_volume @ 0x00498C60 ===== */
void object_lock_with_volume(int param_1)



{

  int iVar1;

  int iVar2;

  

  if (*(int *)(param_1 + 0x210) != 0) {

    iVar2 = AudioGetMasterVolume__Fv();

    if (((DAT_0059f98c == 0) || (DAT_00632bb4 != 0)) ||

       (iVar1 = *(int *)(param_1 + 0x210), iVar1 != iVar2)) {

      object_lock_logic(param_1);

    }

    else if (iVar1 != 0) {

      *(undefined4 **)(param_1 + 0x210) = &DAT_0059f688;

      object_lock_logic(param_1);

      if (*(int *)(param_1 + 0x210) != 0) {

        *(int *)(param_1 + 0x210) = iVar1;

        return;

      }

    }

  }

  return;

}

/* ===== object_volume_sfx @ 0x00498CD0 ===== */
undefined4 object_volume_sfx(int param_1)



{

  int iVar1;

  

  iVar1 = AudioGetMasterVolume__Fv();

  if ((param_1 == iVar1) && (DAT_0059f98c != 0)) {

    return 1;

  }

  return 0;

}

/* ===== create_static_object @ 0x00498CF0 ===== */
/* PS2 candidate: create_static_object (conf 0.417) */



void create_static_object(int param_1,int param_2)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  

  iVar5 = param_1 * 0x304 + *(int *)(DAT_006330e4 + 0x174);

  iVar3 = object_allocate_type

                    (*(undefined4 *)(param_1 * 0x304 + 4 + *(int *)(DAT_006330e4 + 0x174)),

                     0x80000000);

  if (iVar3 != 0) {

    *(int *)(iVar5 + 0x274) = iVar3;

    object_copy_personality(iVar3,iVar5);

    object_copy_activedata(iVar3,iVar5);

    *(undefined4 *)(iVar3 + 0x170) = *(undefined4 *)(iVar5 + 0x170);

    *(undefined4 *)(iVar3 + 0x174) = *(undefined4 *)(iVar5 + 0x174);

    *(undefined4 *)(iVar3 + 0xf4) = *(undefined4 *)(iVar5 + 0xf4);

    *(undefined4 *)(iVar3 + 0xf8) = *(undefined4 *)(iVar5 + 0xf8);

    *(undefined4 *)(iVar3 + 0xfc) = *(undefined4 *)(iVar5 + 0xfc);

    if (*(int *)(iVar5 + 0x210) < 0) {

      *(undefined4 *)(iVar3 + 0x218) = *(undefined4 *)(iVar5 + 0x218);

      *(undefined4 *)(iVar3 + 0x214) = *(undefined4 *)(iVar5 + 0x214);

      iVar4 = *(int *)((*(uint *)(iVar5 + 0x210) & 0x7fffffff) * 0x304 + 0x274 +

                      *(int *)(DAT_006330e4 + 0x174));

      *(int *)(iVar3 + 0x210) = iVar4;

      iVar1 = *(int *)(iVar3 + 0x210);

      *(undefined4 *)(iVar3 + 0x18c) = *(undefined4 *)(iVar4 + 0x18c);

      *(undefined4 *)(iVar3 + 0xa0) = *(undefined4 *)(iVar1 + 0xa0);

      *(undefined4 *)(iVar3 + 0xa4) = *(undefined4 *)(iVar1 + 0xa4);

      *(undefined4 *)(iVar3 + 0xa8) = *(undefined4 *)(iVar1 + 0xa8);

      if (-1 < (char)((uint)*(undefined4 *)(iVar3 + 0xdc) >> 8)) {

        *(undefined4 *)(iVar3 + 200) = *(undefined4 *)(*(int *)(iVar3 + 0x210) + 200);

      }

    }

    if ((((*(uint *)(iVar3 + 0x1c8) & 0x10000) != 0) && (*(int *)(iVar3 + 0x10) != 0xfe)) &&

       (puVar2 = *(undefined4 **)(*(int *)(iVar3 + 8) + 8 + *(int *)(iVar3 + 0x10) * 4),

       puVar2 != (undefined4 *)0x0)) {

      fVar6 = (float10)rndfloat(*puVar2);

      *(float *)(iVar3 + 0x14) = (float)fVar6;

    }

    if (*(int *)(iVar5 + 0x228) != 0) {

      sound_play_obj(*(int *)(iVar5 + 0x228),iVar3);

    }

    if (param_2 != 0) {

      *(int *)(iVar3 + 0x188) = param_2;

    }

    iVar4 = FUN_0052c5c0();

    if (iVar4 != 0) {

      if (*(int *)(iVar3 + 0x1e0) == 0x16) {

        object_spawn_4c(iVar3);

        return;

      }

      if ((*(int **)(iVar3 + 0x170) != (int *)0x0) && (**(int **)(iVar3 + 0x170) == 5)) {

        object_spawn_menu_wredit(iVar5,iVar3);

      }

      if (*(int *)(iVar3 + 4) == 0x3f) {

        iVar5 = object_allocate_type(0xb,0x80000000);

        *(undefined4 *)(iVar5 + 0x18c) = *(undefined4 *)(iVar3 + 0x18c);

        *(undefined4 *)(iVar5 + 0xa0) = *(undefined4 *)(iVar3 + 0xa0);

        *(undefined4 *)(iVar5 + 0xa4) = *(undefined4 *)(iVar3 + 0xa4);

        *(undefined4 *)(iVar5 + 0xa8) = *(undefined4 *)(iVar3 + 0xa8);

        *(undefined4 *)(iVar5 + 200) = *(undefined4 *)(iVar3 + 200);

        *(int *)(iVar5 + 0x210) = iVar3;

        *(undefined4 *)(iVar5 + 0x214) = 0xff;

        *(undefined4 *)(iVar5 + 0x218) = 0;

        *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x400000;

        *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xffbfffff;

      }

      if (*(int *)(iVar3 + 4) == 0x37) {

        iVar5 = object_allocate_type(0x38,0x80000000);

        *(undefined4 *)(iVar5 + 0x18c) = *(undefined4 *)(iVar3 + 0x18c);

        *(undefined4 *)(iVar5 + 0xa0) = *(undefined4 *)(iVar3 + 0xa0);

        *(undefined4 *)(iVar5 + 0xa4) = *(undefined4 *)(iVar3 + 0xa4);

        *(undefined4 *)(iVar5 + 0xa8) = *(undefined4 *)(iVar3 + 0xa8);

        *(undefined4 *)(iVar5 + 200) = *(undefined4 *)(iVar3 + 200);

        *(int *)(iVar5 + 0x210) = iVar3;

        *(undefined4 *)(iVar5 + 0x214) = 0;

        *(undefined4 *)(iVar5 + 0x218) = 0;

        *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x400000;

        *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xffbfffff;

      }

      if (*(int *)(iVar3 + 4) == 0x77) {

        iVar5 = object_allocate_type(0x78,0x80000000);

        *(undefined4 *)(iVar5 + 0x18c) = *(undefined4 *)(iVar3 + 0x18c);

        *(undefined4 *)(iVar5 + 0xa0) = *(undefined4 *)(iVar3 + 0xa0);

        *(undefined4 *)(iVar5 + 0xa4) = *(undefined4 *)(iVar3 + 0xa4);

        *(undefined4 *)(iVar5 + 0xa8) = *(undefined4 *)(iVar3 + 0xa8);

        *(undefined4 *)(iVar5 + 200) = *(undefined4 *)(iVar3 + 200);

        *(int *)(iVar5 + 0x210) = iVar3;

        *(undefined4 *)(iVar5 + 0x214) = 0;

        *(undefined4 *)(iVar5 + 0x218) = 0;

        *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x400000;

      }

      if (*(int *)(iVar3 + 4) == 2) {

        object_create_gun_2(iVar3,1);

      }

    }

  }

  return;

}

/* ===== object_spawn_small @ 0x00499030 ===== */
void object_spawn_small(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                       int param_5)



{

  undefined4 uVar1;

  int iVar2;

  

  iVar2 = object_allocate_type(param_2,0x80000000);

  *(undefined4 *)(iVar2 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

  *(undefined4 *)(iVar2 + 0xa0) = *(undefined4 *)(param_1 + 0xa0);

  *(undefined4 *)(iVar2 + 0xa4) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(iVar2 + 0xa8) = *(undefined4 *)(param_1 + 0xa8);

  uVar1 = *(undefined4 *)(param_1 + 200);

  *(int *)(iVar2 + 0x210) = param_1;

  *(undefined4 *)(iVar2 + 0x214) = param_3;

  *(undefined4 *)(iVar2 + 200) = uVar1;

  *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x400000;

  *(undefined4 *)(iVar2 + 0x218) = param_4;

  if (param_5 != 0) {

    *(int *)(iVar2 + 0x188) = param_5;

  }

  return;

}

/* ===== object_spawn_from_linkage @ 0x004990C0 ===== */
void object_spawn_from_linkage(int param_1,uint param_2)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar3 = DAT_00632d68;

  do {

    if (puVar3 == (undefined4 *)0x0) {

      if ((param_1 != 0) && (iVar1 = object_allocate_type(param_1,0x80000000), iVar1 != 0)) {

        *(undefined4 *)(iVar1 + 0xe4) = 0;

        *(undefined4 *)(iVar1 + 0xe0) = 0;

        *(uint *)(iVar1 + 0x188) = param_2;

        object_setup_specialtype(iVar1);

        obj_children_flag_set(iVar1);

LAB_004991da:

        iVar2 = comm_0052ab50(param_2 & 0xff);

        *(int *)(iVar1 + 0x18c) = iVar2 + 1;

        *(uint *)(iVar1 + 0x1c8) = *(uint *)(iVar1 + 0x1c8) | 1;

      }

      return;

    }

    iVar1 = puVar3[3];

    if (((*(uint *)(iVar1 + 0xd8) & 0x8000) == 0) && (*(uint *)(iVar1 + 0x188) == param_2)) {

      if (*(int *)(iVar1 + 4) == param_1) goto LAB_004991da;

      object_destroy_specialtype(iVar1);

      object_free_all_allocated_data(iVar1);

      iVar2 = object_find(param_1);

      if (iVar2 == 0) goto LAB_004991da;

      object_copy_personality(iVar1,iVar2);

      *(undefined4 *)(iVar1 + 0xe4) = 0;

      *(undefined4 *)(iVar1 + 0xe0) = 0;

      object_setup_specialtype(iVar1);

      *(uint *)(iVar1 + 0xdc) = *(uint *)(iVar1 + 0xdc) | 0x80000000;

      main_linkage_004704e0(&DAT_00632d78,iVar1);

      main_linkage_004704e0(&DAT_00632d70,iVar1);

      main_linkage_004704e0(&DAT_00632d74,iVar1);

      if (param_1 == 1) {

        puVar3 = &DAT_00632d78;

      }

      else if (param_1 == 2) {

        puVar3 = &DAT_00632d70;

      }

      else {

        if (param_1 != 3) goto LAB_004991da;

        puVar3 = &DAT_00632d74;

      }

      main_linkage_00470250(puVar3,iVar1);

      goto LAB_004991da;

    }

    puVar3 = (undefined4 *)*puVar3;

  } while( true );

}

/* ===== FUN_00499200 @ 0x00499200 ===== */
/* PS2 candidate: destroy_player_object (conf 0.322) */



void FUN_00499200(undefined4 param_1)



{

  object_destroy_specialtype(param_1);

  object_destroy(param_1);

  return;

}

/* ===== object_stop_movement @ 0x00499220 ===== */
void object_stop_movement(int param_1)



{

  *(undefined4 *)(param_1 + 0x118) = 0;

  *(undefined4 *)(param_1 + 0x108) = 0;

  *(undefined4 *)(param_1 + 0x11c) = 0;

  *(undefined4 *)(param_1 + 0x10c) = 0;

  *(undefined4 *)(param_1 + 0x120) = 0;

  *(undefined4 *)(param_1 + 0x110) = 0;

  *(undefined4 *)(param_1 + 0x130) = 0;

  *(undefined4 *)(param_1 + 300) = 0;

  *(undefined4 *)(param_1 + 0x128) = 0;

  *(undefined4 *)(param_1 + 0x13c) = 0;

  *(undefined4 *)(param_1 + 0x138) = 0;

  *(undefined4 *)(param_1 + 0x134) = 0;

  *(undefined4 *)(param_1 + 0x124) = 0;

  *(undefined4 *)(param_1 + 0x114) = 0;

  return;

}

/* ===== object_copy_posdirinfo @ 0x00499280 ===== */
/* PS2 candidate: object_set_location_fix (conf 0.535) */



void object_copy_posdirinfo(int param_1)



{

  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0xac);

  *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_1 + 0xb0);

  *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_1 + 0xb4);

  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0xa0);

  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xa8);

  ANM_DumpCluster();

  return;

}

/* ===== object_add_location @ 0x004992D0 ===== */
/* PS2 candidate: object_add_location (conf 0.842) */



void object_add_location(int param_1,float param_2,float param_3,float param_4)



{

  *(float *)(param_1 + 0xa0) = param_2 + *(float *)(param_1 + 0xa0);

  *(float *)(param_1 + 0xa4) = param_3 + *(float *)(param_1 + 0xa4);

  *(float *)(param_1 + 0xa8) = param_4 + *(float *)(param_1 + 0xa8);

  ANM_DumpCluster(param_1);

  return;

}

/* ===== object_set_location @ 0x00499310 ===== */
/* PS2 candidate: object_set_location (conf 0.459) */



void object_set_location(int param_1,float param_2,float param_3,float param_4)



{

  if (((*(float *)(param_1 + 0xa0) != param_2) || (*(float *)(param_1 + 0xa4) != param_3)) ||

     (*(float *)(param_1 + 0xa8) != param_4)) {

    collgrid_clear_grid(param_1);

  }

  *(float *)(param_1 + 0xa8) = param_4;

  *(float *)(param_1 + 0xa0) = param_2;

  *(float *)(param_1 + 0xa4) = param_3;

  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0xac);

  *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_1 + 0xb0);

  *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_1 + 0xb4);

  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0xa0);

  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xa8);

  ANM_DumpCluster(param_1);

  return;

}

/* ===== object_set_location_p3d @ 0x004993C0 ===== */
/* PS2 candidate: object_set_location_p3d (conf 0.468) */



void object_set_location_p3d(int param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar1 = param_2[2];

  fVar2 = param_2[1];

  fVar3 = *param_2;

  if (((*(float *)(param_1 + 0xa0) != fVar3) || (*(float *)(param_1 + 0xa4) != fVar2)) ||

     (*(float *)(param_1 + 0xa8) != fVar1)) {

    collgrid_clear_grid(param_1);

  }

  *(float *)(param_1 + 0xa4) = fVar2;

  *(float *)(param_1 + 0xa8) = fVar1;

  *(float *)(param_1 + 0xa0) = fVar3;

  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0xac);

  *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_1 + 0xb0);

  *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_1 + 0xb4);

  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0xa0);

  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xa8);

  ANM_DumpCluster(param_1);

  return;

}

/* ===== object_add_location_2 @ 0x00499490 ===== */
/* PS2 candidate: object_add_location_2 (conf 0.573) */



void object_add_location_2(int param_1,float param_2,float param_3,float param_4)



{

  collgrid_clear_grid(param_1);

  *(float *)(param_1 + 0xa0) = param_2 + *(float *)(param_1 + 0xa0);

  *(float *)(param_1 + 0xa4) = param_3 + *(float *)(param_1 + 0xa4);

  *(float *)(param_1 + 0xa8) = param_4 + *(float *)(param_1 + 0xa8);

  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0xa0);

  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xa8);

  ANM_DumpCluster(param_1);

  return;

}

/* ===== object_apply_location @ 0x00499500 ===== */
/* PS2 candidate: object_apply_location (conf 0.439) */



void object_apply_location(float param_1)



{

  float *pfVar1;

  float *pfVar2;

  float fVar3;

  float fVar4;

  ushort uVar5;

  ushort uVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  uint uVar10;

  ushort uVar11;

  float10 fVar12;

  float local_24;

  float local_20;

  float local_1c;

  

  fVar9 = param_1;

  local_24 = *(float *)((int)param_1 + 0xa0) - *(float *)((int)param_1 + 0xac);

  pfVar1 = (float *)((int)param_1 + 0xac);

  local_20 = *(float *)((int)param_1 + 0xa4) - *(float *)((int)param_1 + 0xb0);

  local_1c = *(float *)((int)param_1 + 0xa8) - *(float *)((int)param_1 + 0xb4);

  fVar3 = param_1;

  if (*(int *)((int)param_1 + 0x104) == 0) {

    fVar12 = (float10)FUN_00518b70(param_1,0);

    fVar3 = (float)fVar12;

    pfVar2 = (float *)((int)param_1 + 0x128);

    local_24 = (*(float *)((int)param_1 + 0x128) + *(float *)((int)param_1 + 0x134)) * fVar3 * 0.5 +

               local_24;

    local_20 = (*(float *)((int)param_1 + 0x138) + *(float *)((int)param_1 + 300)) * fVar3 * 0.5 +

               local_20;

    fVar4 = *(float *)((int)param_1 + 0x13c);

    *(float *)((int)param_1 + 0x134) = *pfVar2;

    *(undefined4 *)((int)param_1 + 0x138) = *(undefined4 *)((int)param_1 + 300);

    *(undefined4 *)((int)param_1 + 0x13c) = *(undefined4 *)((int)param_1 + 0x130);

    local_1c = (fVar4 + *(float *)((int)param_1 + 0x130)) * fVar3 * 0.5 + local_1c;

    if ((0.0 < *pfVar2) &&

       (fVar4 = *pfVar2 - fVar3 * *(float *)((int)param_1 + 0x200), *pfVar2 = fVar4, fVar4 < 0.0)) {

      *pfVar2 = 0.0;

    }

    if ((*pfVar2 < 0.0) &&

       (fVar4 = fVar3 * *(float *)((int)param_1 + 0x200) + *pfVar2, *pfVar2 = fVar4, 0.0 < fVar4)) {

      *pfVar2 = 0.0;

    }

    if ((0.0 < *(float *)((int)param_1 + 300)) &&

       (fVar4 = *(float *)((int)param_1 + 300) - fVar3 * *(float *)((int)param_1 + 0x200),

       *(float *)((int)param_1 + 300) = fVar4, fVar4 < 0.0)) {

      *(undefined4 *)((int)param_1 + 300) = 0;

    }

    if ((*(float *)((int)param_1 + 300) < 0.0) &&

       (fVar4 = fVar3 * *(float *)((int)param_1 + 0x200) + *(float *)((int)param_1 + 300),

       *(float *)((int)param_1 + 300) = fVar4, 0.0 < fVar4)) {

      *(undefined4 *)((int)param_1 + 300) = 0;

    }

    if ((0.0 < *(float *)((int)param_1 + 0x130)) &&

       (fVar4 = *(float *)((int)param_1 + 0x130) - fVar3 * *(float *)((int)param_1 + 0x200),

       *(float *)((int)param_1 + 0x130) = fVar4, fVar4 < 0.0)) {

      *(undefined4 *)((int)param_1 + 0x130) = 0;

    }

    if ((*(float *)((int)param_1 + 0x130) < 0.0) &&

       (fVar4 = fVar3 * *(float *)((int)param_1 + 0x200) + *(float *)((int)param_1 + 0x130),

       *(float *)((int)param_1 + 0x130) = fVar4, 0.0 < fVar4)) {

      *(undefined4 *)((int)param_1 + 0x130) = 0;

    }

  }

  param_1 = fVar3;

  if ((local_24 != 0.0) || (local_20 != 0.0)) {

    collgrid_clear_grid(fVar9);

  }

  fVar3 = *pfVar1;

  fVar4 = *(float *)((int)fVar9 + 0xb0);

  *(float *)((int)fVar9 + 0xa0) = local_24 + *pfVar1;

  *(float *)((int)fVar9 + 0xa4) = local_20 + *(float *)((int)fVar9 + 0xb0);

  local_1c = local_1c + *(float *)((int)fVar9 + 0xb4);

  *(float *)((int)fVar9 + 0xa8) = local_1c;

  if (*(int *)((int)fVar9 + 0x210) != 0) goto LAB_004998d3;

  if ((*(int *)((int)fVar9 + 4) == 6) || (*(int *)((int)fVar9 + 4) == 7)) {

LAB_004997cf:

    *(float *)((int)fVar9 + 0x140) = local_1c;

  }

  else {

    if ((*(byte *)((int)fVar9 + 0xd8) & 0x10) != 0) {

      local_1c = local_1c - *(float *)((int)fVar9 + 0x1d4);

      *(undefined4 *)((int)fVar9 + 0x108) = 0;

      goto LAB_004997cf;

    }

    collide_objects(fVar9);

  }

  uVar10 = *(uint *)((int)fVar9 + 0xd8);

  if (*(float *)((int)fVar9 + 0xa8) < 0.0 == (*(float *)((int)fVar9 + 0xa8) == 0.0)) {

    *(uint *)((int)fVar9 + 0xd8) = uVar10 & 0xf7efffff;

  }

  else {

    *(uint *)((int)fVar9 + 0xd8) = uVar10 | 0x100000;

    if (-(*(float *)((int)fVar9 + 0x1e8) * *(float *)((int)fVar9 + 0xc4)) <

        *(float *)((int)fVar9 + 0xa8)) {

      *(uint *)((int)fVar9 + 0xd8) = uVar10 & 0xf7ffffff | 0x100000;

    }

    else {

      *(uint *)((int)fVar9 + 0xd8) = uVar10 | 0x8100000;

    }

  }

  fVar3 = *(float *)((int)fVar9 + 0xa0) - fVar3;

  fVar4 = *(float *)((int)fVar9 + 0xa4) - fVar4;

  fVar7 = ABS(local_24);

  fVar8 = ABS(local_20);

  if (fVar7 <= fVar8) {

    if (param_1 <= fVar8) {

      if (fVar7 / fVar8 < 0.35) {

LAB_0049990d:

        fVar4 = fVar4 / local_20;

        uVar11 = (ushort)(fVar4 < 0.5) << 8 | (ushort)(fVar4 == 0.5) << 0xe;

        goto LAB_0049991d;

      }

      if ((fVar3 / local_24 <= 0.5) || (fVar4 / local_20 <= 0.5)) goto LAB_004998b9;

    }

LAB_00499952:

    uVar10 = *(uint *)((int)fVar9 + 0xd8) & 0xfffbffff;

  }

  else {

    if (fVar7 < param_1) goto LAB_00499952;

    fVar3 = fVar3 / local_24;

    uVar5 = (ushort)(fVar3 < 0.5);

    uVar6 = (ushort)(fVar3 == 0.5);

    uVar11 = uVar5 << 8 | uVar6 << 0xe;

    if (fVar8 / fVar7 < 0.35) {

LAB_0049991d:

      if (uVar11 == 0) goto LAB_00499952;

    }

    else if (uVar5 == 0 && uVar6 == 0) goto LAB_0049990d;

LAB_004998b9:

    uVar10 = *(uint *)((int)fVar9 + 0xd8) | 0x40000;

  }

  *(uint *)((int)fVar9 + 0xd8) = uVar10;

  ObjectCalculateTransform(fVar9);

LAB_004998d3:

  *(uint *)((int)fVar9 + 0xd8) = *(uint *)((int)fVar9 + 0xd8) | 0x20;

  return;

}

/* ===== object_init_usage @ 0x00499970 ===== */
/* PS2 candidate: object_init_usage (conf 0.313) */



void object_init_usage(int param_1)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  

  if (-1 < *(int *)(param_1 + 0xdc)) {

    return;

  }

  if (*(int *)(param_1 + 8) == 0) {

    return;

  }

  iVar1 = *(int *)(param_1 + 0x1e0);

  if (iVar1 == 0x4e) goto LAB_00499c49;

  iVar2 = *(int *)(param_1 + 4);

  if ((iVar2 == 2) || (iVar2 == 3)) {

    uVar4 = *(uint *)(param_1 + 0x1cc) | 0x3fc0;

LAB_00499c13:

    uVar3 = *(uint *)(param_1 + 0x1d0) | 0xff;

LAB_00499c1e:

    *(uint *)(param_1 + 0x1cc) = uVar4;

LAB_00499c24:

    *(uint *)(param_1 + 0x1d0) = uVar3;

  }

  else {

    if ((((((iVar2 == 0xb) || (iVar2 == 0x2e6)) || (iVar2 == 0x248)) ||

         ((iVar2 == 0xd7 || (iVar2 == 8)))) || (iVar2 == 0xe5)) ||

       (((iVar2 == 0x49 || (iVar2 == 0xe6)) || (iVar2 == 0x438)))) {

      uVar4 = *(uint *)(param_1 + 0x1cc) | 0x3c03fc0;

      goto LAB_00499c13;

    }

    if (iVar2 == 0x2a5) {

      uVar4 = *(uint *)(param_1 + 0x1cc) | 1;

      uVar3 = *(uint *)(param_1 + 0x1d0) | 0xf0;

      goto LAB_00499c1e;

    }

    if (((((iVar1 == 0x3d) || (iVar1 == 0x62)) || (iVar2 == 0x249)) ||

        (((((iVar2 == 0x425 || (iVar2 == 0x426)) ||

           (((iVar2 == 0x4a1 || ((iVar2 == 0x4a2 || (iVar2 == 0x4a4)))) || (iVar2 == 0x4a3)))) ||

          ((((iVar2 == 0x3c || (iVar2 == 0x232)) || (iVar2 == 0x23b)) ||

           ((iVar2 == 0x2da || (iVar2 == 0x2df)))))) ||

         ((iVar2 == 0x2e0 || ((iVar2 == 0x47c || (iVar2 == 0x47d)))))))) ||

       ((iVar2 == 0x47e ||

        (((((iVar2 == 0x47f || (iVar2 == 0x480)) || (iVar2 == 0x482)) ||

          ((iVar2 == 0x484 || (iVar2 == 0x486)))) ||

         ((iVar2 == 0x3dd || ((iVar2 == 0x49d || (iVar2 == 0x4a5)))))))))) {

      uVar3 = *(uint *)(param_1 + 0x1d0) | 0xf0f;

      goto LAB_00499c24;

    }

    if (iVar2 == 0x2e9) {

      uVar3 = *(uint *)(param_1 + 0x1d0) | 0xf00;

      goto LAB_00499c24;

    }

    if ((iVar2 == 0x66) || (iVar2 == 0x65)) {

      *(uint *)(param_1 + 0x1cc) = *(uint *)(param_1 + 0x1cc) | 0x3ffc;

    }

    else if (((((((iVar2 == 0x4e) || (iVar2 == 0x5b)) || (iVar2 == 0x222)) ||

               (((iVar2 == 0x225 || (iVar2 == 0x208)) ||

                ((iVar2 == 0x1fb || ((iVar2 == 0x1fd || (iVar2 == 0x201)))))))) || (iVar2 == 0x202))

             || (((iVar2 == 0x203 || (iVar2 == 0x204)) || (iVar2 == 0x2a8)))) ||

            (((iVar2 == 0x2a9 || (iVar2 == 0x2af)) || ((iVar2 == 0x213 || (iVar2 == 0x220)))))) {

      *(uint *)(param_1 + 0x1cc) = *(uint *)(param_1 + 0x1cc) | 0x3c03c00;

    }

  }

  if (((iVar1 == 0x3c) || (iVar1 == 0x3d)) && ((*(uint *)(param_1 + 0x1c8) & 0x40) == 0)) {

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x80000000;

  }

LAB_00499c49:

  collgrid_clear_grid(param_1);

  setMenuSelection__7PS2Gameiiii_2(param_1);

  *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0x7fffffff;

  return;

}

/* ===== object_copy_ospec @ 0x00499F30 ===== */
void object_copy_ospec(int param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  

  if (((*(int *)(param_2 + 0x100) != 0) && (*(int *)(param_1 + 0x100) != 0)) &&

     (iVar1 = *(int *)(param_2 + 0x1e0), iVar1 == *(int *)(param_1 + 0x1e0))) {

    if ((iVar1 < 0x6b) && (*(code **)(&DAT_0055cb14 + iVar1 * 0x44) != (code *)0x0)) {

      uVar2 = (**(code **)(&DAT_0055cb14 + iVar1 * 0x44))(param_2);

    }

    else {

      uVar2 = 0;

    }

    puVar4 = *(undefined4 **)(param_2 + 0x100);

    puVar5 = *(undefined4 **)(param_1 + 0x100);

    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;

      puVar4 = (undefined4 *)((int)puVar4 + 1);

      puVar5 = (undefined4 *)((int)puVar5 + 1);

    }

  }

  return;

}

/* ===== object_mty_check_obj @ 0x00499FA0 ===== */
/* PS2 candidate: object_mty_check_obj (conf 0.42) */



void object_mty_check_obj(int param_1)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0x1e0) == 0x12) {

    iVar1 = ObjIsMecc(*(undefined4 *)(param_1 + 0x274));

    if (iVar1 != 0) goto LAB_00499fe3;

    iVar1 = ObjIsReaper(*(undefined4 *)(param_1 + 0x274));

    if (iVar1 != 0) goto LAB_00499fe3;

  }

  obj_ptr_clear_if_dead(param_1 + 0x274);

LAB_00499fe3:

  obj_ptr_clear_if_dead(param_1 + 0x210);

  obj_ptr_clear_if_dead(param_1 + 0x220);

  obj_ptr_clear_if_dead(param_1 + 0x224);

  if ((*(int *)(param_1 + 0x1e0) < 0x6b) &&

     (*(code **)(&DAT_0055cb2c + *(int *)(param_1 + 0x1e0) * 0x44) != (code *)0x0)) {

    (**(code **)(&DAT_0055cb2c + *(int *)(param_1 + 0x1e0) * 0x44))(param_1);

  }

  return;

}

/* ===== FUN_0049a030 @ 0x0049A030 ===== */
/* PS2 candidate: reaper_set_spell (conf 0.423) */



void FUN_0049a030(int param_1)



{

  if ((*(int *)(param_1 + 0x1e0) < 0x6b) &&

     (*(code **)(&DAT_0055cb44 + *(int *)(param_1 + 0x1e0) * 0x44) != (code *)0x0)) {

                    /* WARNING: Jumptable at 0x0049a050 did not pass sanity check. */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(&DAT_0055cb44 + *(int *)(param_1 + 0x1e0) * 0x44))();

    return;

  }

  return;

}

/* ===== objspec_has_shot_function_2 @ 0x0049A060 ===== */
/* PS2 candidate: objspec_has_shot_function_2 (conf 0.79) */



undefined4 objspec_has_shot_function_2(int param_1)



{

  undefined4 uVar1;

  

  if ((*(int *)(param_1 + 0x1e0) < 0x6b) &&

     (*(code **)(&DAT_0055cb40 + *(int *)(param_1 + 0x1e0) * 0x44) != (code *)0x0)) {

                    /* WARNING: Jumptable at 0x0049a080 did not pass sanity check. */

                    /* WARNING: Treating indirect jump as call */

    uVar1 = (**(code **)(&DAT_0055cb40 + *(int *)(param_1 + 0x1e0) * 0x44))();

    return uVar1;

  }

  return 0;

}

/* ===== FUN_0049a090 @ 0x0049A090 ===== */
void FUN_0049a090(int param_1)



{

  if ((*(int *)(param_1 + 0x1e0) < 0x6b) &&

     (*(code **)(&DAT_0055cb08 + *(int *)(param_1 + 0x1e0) * 0x44) != (code *)0x0)) {

                    /* WARNING: Jumptable at 0x0049a0b0 did not pass sanity check. */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(&DAT_0055cb08 + *(int *)(param_1 + 0x1e0) * 0x44))();

    return;

  }

  return;

}

/* ===== FUN_0049a0c0 @ 0x0049A0C0 ===== */
void FUN_0049a0c0(int param_1)



{

  if ((*(int *)(param_1 + 0x1e0) < 0x6b) &&

     (*(code **)(&DAT_0055cb0c + *(int *)(param_1 + 0x1e0) * 0x44) != (code *)0x0)) {

                    /* WARNING: Jumptable at 0x0049a0e0 did not pass sanity check. */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(&DAT_0055cb0c + *(int *)(param_1 + 0x1e0) * 0x44))();

    return;

  }

  return;

}

/* ===== objspec_has_shot_function @ 0x0049A0F0 ===== */
/* PS2 candidate: objspec_has_shot_function (conf 0.814) */



undefined4

objspec_has_shot_function

          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,

          undefined4 param_6)



{

  if ((*(int *)(param_3 + 0x1e0) < 0x6b) &&

     (*(code **)(&DAT_0055cb10 + *(int *)(param_3 + 0x1e0) * 0x44) != (code *)0x0)) {

    (**(code **)(&DAT_0055cb10 + *(int *)(param_3 + 0x1e0) * 0x44))

              (param_1,param_2,param_3,param_4,param_5,param_6);

    return 1;

  }

  return 0;

}

/* ===== object_load_ospec @ 0x0049A140 ===== */
/* PS2 candidate: object_load_ospec (conf 0.55) */



void object_load_ospec(int param_1,undefined4 param_2,undefined4 param_3,int param_4,

                      undefined4 param_5)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x1e0);

  if (((iVar1 == param_4) && (iVar1 < 0x6b)) &&

     (*(code **)(&DAT_0055cb24 + iVar1 * 0x44) != (code *)0x0)) {

    (**(code **)(&DAT_0055cb24 + iVar1 * 0x44))(param_1,param_3,param_2,param_5);

  }

  return;

}

/* ===== FUN_0049a180 @ 0x0049A180 ===== */
/* PS2 candidate: objspec_get_movetype_string (conf 0.637) */



void FUN_0049a180(void)



{

  FUN_00507b00();

  return;

}

/* ===== FUN_0049a1d0 @ 0x0049A1D0 ===== */
/* PS2 candidate: objspec_get_targetflags (conf 0.716) */



undefined4 FUN_0049a1d0(int param_1)



{

  if (param_1 == 0) {

    return 0;

  }

  return *(undefined4 *)(&DAT_0055cb48 + *(int *)(param_1 + 0x1e0) * 0x44);

}

/* ===== PROJ_ObjectFinalize @ 0x0049A1F0 ===== */
/* PS2 candidate: PROJ_ObjectFinalize (conf 0.401) */



void PROJ_ObjectFinalize(int param_1)



{

  int iVar1;

  uint uVar2;

  int *piVar3;

  float *pfVar4;

  float *pfVar5;

  float local_30;

  float local_2c;

  float local_28;

  int local_24;

  int local_20;

  int local_1c;

  float local_18 [4];

  float local_8;

  float local_4;

  

  local_24 = *(int *)(param_1 + 8);

  if (local_24 == 0) {

    local_20 = local_24;

    local_1c = local_24;

    xformobj_p3d_world(param_1,&local_24,&local_30);

    local_18[3] = local_30 + 1.0;

    local_18[0] = local_30;

    local_18[1] = local_2c;

    local_18[2] = local_28;

    local_8 = local_2c + 1.0;

    local_4 = local_28 + 1.0;

  }

  else {

    if ((*(int *)(param_1 + 0x10) == 0xfe) ||

       (iVar1 = *(int *)(local_24 + 8 + *(int *)(param_1 + 0x10) * 4), iVar1 == 0)) {

      piVar3 = (int *)(*(int *)(local_24 + 0x400) + 0x44);

    }

    else {

      piVar3 = (int *)(iVar1 + 0xc);

    }

    uVar2 = 0;

    do {

      if ((uVar2 & 1) == 0) {

        local_24 = piVar3[3];

      }

      else {

        local_24 = *piVar3;

      }

      if ((uVar2 & 2) == 0) {

        local_20 = piVar3[4];

      }

      else {

        local_20 = piVar3[1];

      }

      if ((uVar2 & 4) == 0) {

        local_1c = piVar3[5];

      }

      else {

        local_1c = piVar3[2];

      }

      xformobj_p3d_world(param_1,&local_24,&local_30);

      if (uVar2 == 0) {

        local_18[3] = local_30;

        local_8 = local_2c;

        local_4 = local_28;

        local_18[0] = local_30;

        local_18[1] = local_2c;

        local_18[2] = local_28;

      }

      else {

        if (local_30 < local_18[0]) {

          local_18[0] = local_30;

        }

        if (local_2c < local_18[1]) {

          local_18[1] = local_2c;

        }

        if (local_28 < local_18[2]) {

          local_18[2] = local_28;

        }

        if (local_18[3] < local_30) {

          local_18[3] = local_30;

        }

        if (local_8 < local_2c) {

          local_8 = local_2c;

        }

        if (local_4 < local_28) {

          local_4 = local_28;

        }

      }

      uVar2 = uVar2 + 1;

    } while ((int)uVar2 < 8);

  }

  pfVar4 = local_18;

  pfVar5 = (float *)(param_1 + 0x27c);

  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {

    *pfVar5 = *pfVar4;

    pfVar4 = pfVar4 + 1;

    pfVar5 = pfVar5 + 1;

  }

  return;

}

/* ===== collide_bbox_bbox @ 0x0049A3C0 ===== */
/* PS2 candidate: collide_bbox_bbox (conf 0.782) */



undefined4 collide_bbox_bbox(float *param_1,float *param_2)



{

  if (*param_1 == param_1[3]) {

    return 0;

  }

  if (*param_2 == param_2[3]) {

    return 0;

  }

  if (param_2[3] < *param_1) {

    return 0;

  }

  if (param_2[4] < param_1[1]) {

    return 0;

  }

  if (param_2[5] < param_1[2]) {

    return 0;

  }

  if (param_1[3] < *param_2) {

    return 0;

  }

  if (param_1[4] < param_2[1]) {

    return 0;

  }

  if (param_1[5] < param_2[2]) {

    return 0;

  }

  return 1;

}

/* ===== collide_ptsize_bbox @ 0x0049A450 ===== */
/* PS2 candidate: collide_ptsize_bbox (conf 0.714) */



undefined4 collide_ptsize_bbox(float *param_1,float param_2,float *param_3)



{

  if (param_3[3] < *param_1 - param_2) {

    return 0;

  }

  if (param_3[4] < param_1[1] - param_2) {

    return 0;

  }

  if (param_3[5] < param_1[2] - param_2) {

    return 0;

  }

  if (param_2 + *param_1 < *param_3) {

    return 0;

  }

  if (param_2 + param_1[1] < param_3[1]) {

    return 0;

  }

  if (param_2 + param_1[2] < param_3[2]) {

    return 0;

  }

  return 1;

}

/* ===== collide_pt_bbox @ 0x0049A4E0 ===== */
/* PS2 candidate: collide_pt_bbox (conf 0.631) */



undefined4 collide_pt_bbox(float *param_1,float *param_2)



{

  if (param_2[3] < *param_1) {

    return 0;

  }

  if (param_2[4] < param_1[1]) {

    return 0;

  }

  if (param_2[5] < param_1[2]) {

    return 0;

  }

  if (*param_1 < *param_2) {

    return 0;

  }

  if (param_1[1] < param_2[1]) {

    return 0;

  }

  if (param_1[2] < param_2[2]) {

    return 0;

  }

  return 1;

}

/* ===== collide_line_bbox @ 0x0049A550 ===== */
/* PS2 candidate: collide_line_bbox (conf 0.646) */



undefined4 collide_line_bbox(float *param_1,float *param_2,float *param_3,float *param_4)



{

  float fVar1;

  byte bVar2;

  byte bVar3;

  float local_c [3];

  

  if (param_1 == (float *)0x0) {

    param_1 = local_c;

  }

  bVar3 = *param_2 < *param_4;

  if (param_4[3] < *param_2) {

    bVar3 = bVar3 | 2;

  }

  if (param_2[1] < param_4[1]) {

    bVar3 = bVar3 | 4;

  }

  if (param_4[4] < param_2[1]) {

    bVar3 = bVar3 | 8;

  }

  if (param_2[2] < param_4[2]) {

    bVar3 = bVar3 | 0x10;

  }

  if (param_4[5] < param_2[2]) {

    bVar3 = bVar3 | 0x20;

  }

  if (bVar3 != 0) {

    bVar2 = *param_3 < *param_4;

    if (param_4[3] < *param_3) {

      bVar2 = bVar2 | 2;

    }

    if (param_3[1] < param_4[1]) {

      bVar2 = bVar2 | 4;

    }

    if (param_4[4] < param_3[1]) {

      bVar2 = bVar2 | 8;

    }

    if (param_3[2] < param_4[2]) {

      bVar2 = bVar2 | 0x10;

    }

    if (param_4[5] < param_3[2]) {

      bVar2 = bVar2 | 0x20;

    }

    if (bVar2 == 0) {

      *param_1 = *param_3;

      param_1[1] = param_3[1];

      param_1[2] = param_3[2];

      return 1;

    }

    if ((bVar3 & bVar2) == 0) {

      bVar2 = bVar2 ^ bVar3;

      if ((bVar2 & 1) != 0) {

        fVar1 = (*param_4 - *param_2) / (*param_3 - *param_2);

        param_1[1] = (param_3[1] - param_2[1]) * fVar1 + param_2[1];

        param_1[2] = (param_3[2] - param_2[2]) * fVar1 + param_2[2];

        *param_1 = *param_4;

        if ((((param_4[1] <= param_1[1]) && (param_1[1] < param_4[4] != (param_1[1] == param_4[4])))

            && (param_4[2] <= param_1[2])) &&

           (param_1[2] < param_4[5] != (param_1[2] == param_4[5]))) {

          return 1;

        }

      }

      if ((bVar2 & 2) != 0) {

        fVar1 = (param_4[3] - *param_2) / (*param_3 - *param_2);

        param_1[1] = (param_3[1] - param_2[1]) * fVar1 + param_2[1];

        param_1[2] = (param_3[2] - param_2[2]) * fVar1 + param_2[2];

        *param_1 = param_4[3];

        if (((param_4[1] <= param_1[1]) && (param_1[1] < param_4[4] != (param_1[1] == param_4[4])))

           && ((param_4[2] <= param_1[2] && (param_1[2] < param_4[5] != (param_1[2] == param_4[5])))

              )) {

          return 1;

        }

      }

      if ((bVar2 & 4) != 0) {

        fVar1 = (param_4[1] - param_2[1]) / (param_3[1] - param_2[1]);

        *param_1 = (*param_3 - *param_2) * fVar1 + *param_2;

        param_1[2] = (param_3[2] - param_2[2]) * fVar1 + param_2[2];

        param_1[1] = param_4[1];

        if (((*param_4 <= *param_1) && (*param_1 < param_4[3] != (*param_1 == param_4[3]))) &&

           ((param_4[2] <= param_1[2] && (param_1[2] < param_4[5] != (param_1[2] == param_4[5])))))

        {

          return 1;

        }

      }

      if ((bVar2 & 8) != 0) {

        fVar1 = (param_4[4] - param_2[1]) / (param_3[1] - param_2[1]);

        *param_1 = (*param_3 - *param_2) * fVar1 + *param_2;

        param_1[2] = (param_3[2] - param_2[2]) * fVar1 + param_2[2];

        param_1[1] = param_4[4];

        if ((((*param_4 <= *param_1) && (*param_1 < param_4[3] != (*param_1 == param_4[3]))) &&

            (param_4[2] <= param_1[2])) && (param_1[2] < param_4[5] != (param_1[2] == param_4[5])))

        {

          return 1;

        }

      }

      if ((bVar2 & 0x10) != 0) {

        fVar1 = (param_4[2] - param_2[2]) / (param_3[2] - param_2[2]);

        *param_1 = (*param_3 - *param_2) * fVar1 + *param_2;

        param_1[1] = (param_3[1] - param_2[1]) * fVar1 + param_2[1];

        param_1[2] = param_4[2];

        if (((*param_4 <= *param_1) && (*param_1 < param_4[3] != (*param_1 == param_4[3]))) &&

           ((param_4[1] <= param_1[1] && (param_1[1] < param_4[4] != (param_1[1] == param_4[4])))))

        {

          return 1;

        }

      }

      if ((bVar2 & 0x20) != 0) {

        fVar1 = (param_4[5] - param_2[2]) / (param_3[2] - param_2[2]);

        *param_1 = (*param_3 - *param_2) * fVar1 + *param_2;

        param_1[1] = (param_3[1] - param_2[1]) * fVar1 + param_2[1];

        param_1[2] = param_4[5];

        if (((*param_4 <= *param_1) && (*param_1 < param_4[3] != (*param_1 == param_4[3]))) &&

           ((param_4[1] <= param_1[1] && (param_1[1] < param_4[4] != (param_1[1] == param_4[4])))))

        {

          return 1;

        }

      }

    }

    return 0;

  }

  *param_1 = *param_2;

  param_1[1] = param_2[1];

  param_1[2] = param_2[2];

  return 1;

}

/* ===== geom_point_line_dist @ 0x0049A950 ===== */
undefined4 geom_point_line_dist(float *param_1,float *param_2,float *param_3,float param_4)



{

  float fVar1;

  float10 fVar2;

  float *pfVar3;

  float local_c;

  float local_8;

  float local_4;

  

  fVar2 = (float10)distancesq2d__FP3P3DT0(param_1,param_2);

  fVar1 = (float)((((float10)*param_3 - (float10)*param_1) * (float10)(*param_2 - *param_1) +

                  ((float10)param_3[1] - (float10)param_1[1]) * (float10)(param_2[1] - param_1[1]))

                 / fVar2);

  pfVar3 = param_1;

  if ((0.0 <= fVar1) && (pfVar3 = param_2, fVar1 <= 1.0)) {

    local_4 = param_1[2];

    local_c = (*param_2 - *param_1) * fVar1 + *param_1;

    local_8 = (param_2[1] - param_1[1]) * fVar1 + param_1[1];

    pfVar3 = &local_c;

  }

  fVar2 = (float10)distancesq2d__FP3P3DT0(pfVar3,param_3);

  if ((float10)param_4 * (float10)param_4 <= fVar2) {

    return 0;

  }

  return 1;

}

/* ===== sine_cosine_table_gen @ 0x0049AA20 ===== */
void sine_cosine_table_gen(int param_1)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  float fVar26;

  float fVar27;

  byte bVar28;

  byte bVar29;

  byte bVar30;

  byte bVar31;

  byte bVar32;

  byte bVar33;

  float *pfVar34;

  uint uVar35;

  byte bVar36;

  byte bVar37;

  byte bVar38;

  undefined1 *puVar39;

  float local_dc;

  float local_d8;

  float local_d4;

  undefined1 local_88 [4];

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_38;

  float local_2c;

  float local_18;

  

  if (*(int *)(param_1 + 8) == 0) {

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xffdfff7f;

    return;

  }

  uVar35 = *(uint *)(param_1 + 0x1c8);

  puVar39 = (undefined1 *)(param_1 + 0x294);

  if ((uVar35 & 0x84) != 0) {

    if ((uVar35 & 4) == 0) {

      if ((char)uVar35 < '\0') {

        puVar39 = local_88;

        pfVar34 = (float *)AudioDataStreamStatus__Fv_5();

        local_84 = *pfVar34 * *(float *)(param_1 + 0xc4);

        local_74 = pfVar34[4] * *(float *)(param_1 + 0xc4);

        local_64 = pfVar34[8] * *(float *)(param_1 + 0xc4);

        local_80 = pfVar34[2] * *(float *)(param_1 + 0xc4);

        local_70 = pfVar34[6] * *(float *)(param_1 + 0xc4);

        local_60 = pfVar34[10] * *(float *)(param_1 + 0xc4);

        local_7c = pfVar34[1] * *(float *)(param_1 + 0xc4);

        local_6c = pfVar34[5] * *(float *)(param_1 + 0xc4);

        local_5c = pfVar34[9] * *(float *)(param_1 + 0xc4);

        local_78 = -(pfVar34[1] * pfVar34[0xd] + pfVar34[2] * pfVar34[0xe] + *pfVar34 * pfVar34[0xc]

                    ) + *(float *)(param_1 + 0xa0);

        local_68 = -(pfVar34[0xc] * pfVar34[4] +

                    pfVar34[5] * pfVar34[0xd] + pfVar34[6] * pfVar34[0xe]) +

                   *(float *)(param_1 + 0xa4);

        local_58 = -(pfVar34[0xe] * pfVar34[10] +

                    pfVar34[0xc] * pfVar34[8] + pfVar34[9] * pfVar34[0xd]) +

                   *(float *)(param_1 + 0xa8);

      }

    }

    else {

      puVar39 = local_88;

      pfVar34 = (float *)AudioDataStreamStatus__Fv_5();

      local_d4 = *(float *)(param_1 + 0xc4);

      sine_cos_lookup(*(undefined4 *)(param_1 + 0xd0),&local_d8,&local_dc);

      local_18 = local_dc * local_d4;

      local_78 = *(float *)(param_1 + 0xa0);

      local_68 = *(float *)(param_1 + 0xa4);

      local_58 = *(float *)(param_1 + 0xa8);

      local_d8 = local_d8 * local_d4;

      local_38 = -local_d8;

      local_2c = -local_d4;

      local_84 = local_18 * *pfVar34 + local_d8 * pfVar34[1];

      local_74 = local_18 * pfVar34[4] + local_d8 * pfVar34[5];

      local_64 = local_18 * pfVar34[8] + local_d8 * pfVar34[9];

      local_80 = local_2c * pfVar34[2];

      local_70 = local_2c * pfVar34[6];

      local_60 = local_2c * pfVar34[10];

      local_7c = local_38 * *pfVar34 + local_18 * pfVar34[1];

      local_6c = local_38 * pfVar34[4] + local_18 * pfVar34[5];

      local_5c = local_38 * pfVar34[8] + local_18 * pfVar34[9];

    }

  }

  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x400);

  pfVar34 = (float *)AudioDataStreamStatus__Fv_4();

  fVar2 = *(float *)(iVar1 + 0x44) * *(float *)(puVar39 + 4);

  fVar3 = *(float *)(puVar39 + 4) * *(float *)(iVar1 + 0x50);

  fVar5 = *(float *)(puVar39 + 8) * *(float *)(iVar1 + 0x48);

  fVar9 = *(float *)(iVar1 + 0x54) * *(float *)(puVar39 + 8);

  fVar10 = *(float *)(iVar1 + 0x44) * *(float *)(puVar39 + 0x14);

  fVar11 = *(float *)(iVar1 + 0x50) * *(float *)(puVar39 + 0x14);

  fVar12 = *(float *)(iVar1 + 0x48) * *(float *)(puVar39 + 0x18);

  fVar13 = *(float *)(iVar1 + 0x54) * *(float *)(puVar39 + 0x18);

  fVar16 = *(float *)(iVar1 + 0x44) * *(float *)(puVar39 + 0x24);

  fVar17 = *(float *)(iVar1 + 0x50) * *(float *)(puVar39 + 0x24);

  fVar18 = *(float *)(puVar39 + 0x28) * *(float *)(iVar1 + 0x48);

  fVar19 = *(float *)(iVar1 + 0x54) * *(float *)(puVar39 + 0x28);

  fVar6 = *(float *)(iVar1 + 0x4c) * *(float *)(puVar39 + 0xc) + *(float *)(puVar39 + 0x10);

  fVar4 = fVar6 + fVar5;

  fVar7 = fVar4 + fVar2;

  fVar14 = *(float *)(iVar1 + 0x4c) * *(float *)(puVar39 + 0x1c) + *(float *)(puVar39 + 0x20);

  fVar15 = fVar14 + fVar12;

  fVar8 = fVar15 + fVar10;

  fVar20 = *(float *)(iVar1 + 0x4c) * *(float *)(puVar39 + 0x2c) + *(float *)(puVar39 + 0x30);

  fVar21 = fVar20 + fVar18;

  fVar22 = fVar21 + fVar16;

  fVar23 = fVar8 * pfVar34[4] + fVar22 * pfVar34[8] + fVar7 * *pfVar34 + pfVar34[0xc];

  fVar24 = fVar8 * pfVar34[5] + fVar22 * pfVar34[9] + fVar7 * pfVar34[1] + pfVar34[0xd];

  fVar22 = fVar8 * pfVar34[7] + fVar22 * pfVar34[0xb] + fVar7 * pfVar34[3] + pfVar34[0xf];

  fVar7 = *(float *)(puVar39 + 0xc) * *(float *)(iVar1 + 0x58) + *(float *)(puVar39 + 0x10);

  fVar5 = fVar5 + fVar7;

  fVar8 = fVar5 + fVar2;

  bVar36 = (((((fVar22 < fVar24) * '\x02' | fVar24 < -fVar22) << 1 | fVar22 < fVar23) << 1 |

            fVar23 < -fVar22) << 1 | DAT_0057c0c4 < fVar22) << 1 | fVar22 < DAT_0057c0c0;

  fVar22 = *(float *)(iVar1 + 0x58) * *(float *)(puVar39 + 0x1c) + *(float *)(puVar39 + 0x20);

  fVar12 = fVar22 + fVar12;

  fVar23 = fVar12 + fVar10;

  fVar24 = *(float *)(iVar1 + 0x58) * *(float *)(puVar39 + 0x2c) + *(float *)(puVar39 + 0x30);

  fVar18 = fVar24 + fVar18;

  fVar25 = fVar18 + fVar16;

  fVar26 = fVar23 * pfVar34[4] + fVar25 * pfVar34[8] + fVar8 * *pfVar34 + pfVar34[0xc];

  fVar27 = fVar23 * pfVar34[5] + fVar25 * pfVar34[9] + fVar8 * pfVar34[1] + pfVar34[0xd];

  fVar23 = fVar23 * pfVar34[7] + fVar25 * pfVar34[0xb] + fVar8 * pfVar34[3] + pfVar34[0xf];

  fVar6 = fVar6 + fVar9;

  fVar8 = fVar6 + fVar2;

  fVar14 = fVar14 + fVar13;

  bVar28 = (((((fVar23 < fVar27) * '\x02' | fVar27 < -fVar23) << 1 | fVar23 < fVar26) << 1 |

            fVar26 < -fVar23) << 1 | DAT_0057c0c4 < fVar23) << 1 | fVar23 < DAT_0057c0c0;

  fVar23 = fVar14 + fVar10;

  fVar20 = fVar20 + fVar19;

  fVar25 = fVar20 + fVar16;

  fVar26 = fVar23 * pfVar34[4] + fVar25 * pfVar34[8] + fVar8 * *pfVar34 + pfVar34[0xc];

  fVar27 = fVar23 * pfVar34[5] + fVar25 * pfVar34[9] + fVar8 * pfVar34[1] + pfVar34[0xd];

  fVar8 = fVar23 * pfVar34[7] + fVar25 * pfVar34[0xb] + fVar8 * pfVar34[3] + pfVar34[0xf];

  fVar7 = fVar7 + fVar9;

  fVar2 = fVar2 + fVar7;

  fVar22 = fVar22 + fVar13;

  fVar10 = fVar10 + fVar22;

  bVar29 = (((((fVar8 < fVar27) * '\x02' | fVar27 < -fVar8) << 1 | fVar8 < fVar26) << 1 |

            fVar26 < -fVar8) << 1 | DAT_0057c0c4 < fVar8) << 1 | fVar8 < DAT_0057c0c0;

  fVar24 = fVar24 + fVar19;

  fVar16 = fVar24 + fVar16;

  fVar8 = fVar10 * pfVar34[4] + fVar16 * pfVar34[8] + fVar2 * *pfVar34 + pfVar34[0xc];

  fVar9 = fVar10 * pfVar34[5] + fVar16 * pfVar34[9] + fVar2 * pfVar34[1] + pfVar34[0xd];

  fVar2 = fVar10 * pfVar34[7] + fVar16 * pfVar34[0xb] + fVar2 * pfVar34[3] + pfVar34[0xf];

  fVar4 = fVar4 + fVar3;

  fVar15 = fVar15 + fVar11;

  fVar21 = fVar21 + fVar17;

  bVar30 = (((((fVar2 < fVar9) * '\x02' | fVar9 < -fVar2) << 1 | fVar2 < fVar8) << 1 |

            fVar8 < -fVar2) << 1 | DAT_0057c0c4 < fVar2) << 1 | fVar2 < DAT_0057c0c0;

  fVar2 = fVar15 * pfVar34[4] + fVar21 * pfVar34[8] + fVar4 * *pfVar34 + pfVar34[0xc];

  fVar8 = fVar15 * pfVar34[5] + fVar21 * pfVar34[9] + fVar4 * pfVar34[1] + pfVar34[0xd];

  fVar4 = fVar15 * pfVar34[7] + fVar21 * pfVar34[0xb] + fVar4 * pfVar34[3] + pfVar34[0xf];

  fVar5 = fVar5 + fVar3;

  fVar12 = fVar12 + fVar11;

  fVar18 = fVar18 + fVar17;

  bVar31 = (((((fVar4 < fVar8) * '\x02' | fVar8 < -fVar4) << 1 | fVar4 < fVar2) << 1 |

            fVar2 < -fVar4) << 1 | DAT_0057c0c4 < fVar4) << 1 | fVar4 < DAT_0057c0c0;

  fVar2 = fVar12 * pfVar34[4] + fVar18 * pfVar34[8] + fVar5 * *pfVar34 + pfVar34[0xc];

  fVar4 = fVar12 * pfVar34[5] + fVar18 * pfVar34[9] + fVar5 * pfVar34[1] + pfVar34[0xd];

  fVar5 = fVar12 * pfVar34[7] + fVar18 * pfVar34[0xb] + fVar5 * pfVar34[3] + pfVar34[0xf];

  fVar6 = fVar6 + fVar3;

  fVar14 = fVar14 + fVar11;

  fVar20 = fVar20 + fVar17;

  bVar32 = (((((fVar5 < fVar4) * '\x02' | fVar4 < -fVar5) << 1 | fVar5 < fVar2) << 1 |

            fVar2 < -fVar5) << 1 | DAT_0057c0c4 < fVar5) << 1 | fVar5 < DAT_0057c0c0;

  fVar2 = fVar14 * pfVar34[4] + fVar20 * pfVar34[8] + fVar6 * *pfVar34 + pfVar34[0xc];

  fVar4 = fVar14 * pfVar34[5] + fVar20 * pfVar34[9] + fVar6 * pfVar34[1] + pfVar34[0xd];

  fVar5 = fVar14 * pfVar34[7] + fVar20 * pfVar34[0xb] + fVar6 * pfVar34[3] + pfVar34[0xf];

  fVar7 = fVar7 + fVar3;

  fVar22 = fVar22 + fVar11;

  bVar33 = (((((fVar5 < fVar4) * '\x02' | fVar4 < -fVar5) << 1 | fVar5 < fVar2) << 1 |

            fVar2 < -fVar5) << 1 | DAT_0057c0c4 < fVar5) << 1 | fVar5 < DAT_0057c0c0;

  fVar24 = fVar24 + fVar17;

  fVar2 = fVar22 * pfVar34[4] + fVar24 * pfVar34[8] + fVar7 * *pfVar34 + pfVar34[0xc];

  fVar3 = fVar22 * pfVar34[5] + fVar24 * pfVar34[9] + fVar7 * pfVar34[1] + pfVar34[0xd];

  fVar4 = fVar22 * pfVar34[7] + fVar24 * pfVar34[0xb] + fVar7 * pfVar34[3] + pfVar34[0xf];

  bVar38 = (((((fVar4 < fVar3) * '\x02' | fVar3 < -fVar4) << 1 | fVar4 < fVar2) << 1 |

            fVar2 < -fVar4) << 1 | DAT_0057c0c4 < fVar4) << 1 | fVar4 < DAT_0057c0c0;

  bVar37 = bVar36 & bVar28 & bVar29 & bVar30 & bVar31 & bVar32 & bVar33 & bVar38;

  bVar38 = bVar36 | bVar28 | bVar29 | bVar30 | bVar31 | bVar32 | bVar33 | bVar38;

  uVar35 = *(uint *)(param_1 + 0xd8);

  if ((uVar35 & 2) != 0) {

    bVar37 = bVar37 & 0xfd;

    bVar38 = bVar38 & 0xfd;

  }

  if (bVar37 == 0) {

    uVar35 = uVar35 & 0xffffff7f;

  }

  else {

    uVar35 = uVar35 | 0x80;

  }

  *(uint *)(param_1 + 0xd8) = uVar35;

  if (bVar38 != 0) {

    *(uint *)(param_1 + 0xd8) = uVar35 & 0xffdfffff;

    return;

  }

  *(uint *)(param_1 + 0xd8) = uVar35 | 0x200000;

  return;

}

/* ===== FUN_0049b810 @ 0x0049B810 ===== */
void FUN_0049b810(void)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  undefined4 *puVar5;

  

  piVar2 = DAT_00632d68;

joined_r0x0049b817:

  do {

    do {

      piVar4 = piVar2;

      if (piVar4 == (int *)0x0) {

        return;

      }

      iVar1 = piVar4[3];

      puVar5 = *(undefined4 **)(iVar1 + 0x210);

      piVar2 = (int *)*piVar4;

    } while ((puVar5 == (undefined4 *)0x0) &&

            ((*(int *)(iVar1 + 0x1e0) != 0x3e ||

             (puVar5 = *(undefined4 **)(iVar1 + 0x274), puVar5 == (undefined4 *)0x0))));

    for (puVar5 = (undefined4 *)*puVar5; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5

        ) {

      piVar3 = (int *)puVar5[3];

      if ((int **)piVar3[2] == &DAT_00632d68) {

        puVar5 = (undefined4 *)*piVar3;

        goto joined_r0x0049b864;

      }

    }

  } while( true );

joined_r0x0049b864:

  if (puVar5 == (undefined4 *)0x0) goto LAB_0049b871;

  if (puVar5[3] == iVar1) goto joined_r0x0049b817;

  puVar5 = (undefined4 *)*puVar5;

  goto joined_r0x0049b864;

LAB_0049b871:

  *(int **)piVar4[1] = piVar2;

  if (*piVar4 != 0) {

    *(int *)(*piVar4 + 4) = piVar4[1];

  }

  *piVar4 = *piVar3;

  piVar4[1] = (int)piVar3;

  *piVar3 = (int)piVar4;

  if (*piVar4 != 0) {

    *(int **)(*piVar4 + 4) = piVar4;

  }

  goto joined_r0x0049b817;

}

/* ===== object_setup_specialtype @ 0x0049B8A0 ===== */
/* PS2 candidate: object_setup_specialtype (conf 0.388) */



void object_setup_specialtype(int param_1)



{

  int iVar1;

  int iVar2;

  

  if (*(int *)(param_1 + 4) == 2) {

    iVar1 = *(int *)(param_1 + 0x100);

    iVar2 = object_allocate_type(0x54,2);

    *(int *)(iVar2 + 0x210) = param_1;

    *(undefined4 *)(iVar2 + 0x214) = 0xffffffff;

    *(undefined4 *)(iVar2 + 0x218) = 2;

    object_set_location_p3d(iVar2,param_1 + 0xa0);

    *(undefined4 *)(iVar2 + 200) = *(undefined4 *)(param_1 + 200);

    *(undefined4 *)(iVar2 + 0xcc) = *(undefined4 *)(param_1 + 0xcc);

    *(undefined4 *)(iVar2 + 0xd0) = *(undefined4 *)(param_1 + 0xd0);

    *(undefined4 *)(iVar2 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

    *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) | 1;

    *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x40400000;

    iVar2 = object_allocate_type(0x55,2);

    *(int *)(iVar2 + 0x210) = param_1;

    *(undefined4 *)(iVar2 + 0x214) = 0;

    *(undefined4 *)(iVar2 + 0x218) = 2;

    object_set_location_p3d(iVar2,param_1 + 0xa0);

    *(undefined4 *)(iVar2 + 200) = *(undefined4 *)(param_1 + 200);

    *(undefined4 *)(iVar2 + 0xcc) = *(undefined4 *)(param_1 + 0xcc);

    *(undefined4 *)(iVar2 + 0xd0) = *(undefined4 *)(param_1 + 0xd0);

    *(undefined4 *)(iVar2 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

    *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) | 1;

    *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x40400000;

    iVar2 = object_allocate_type(0x30d,2);

    *(int *)(iVar2 + 0x210) = param_1;

    *(undefined4 *)(iVar2 + 0x214) = 0xffffffff;

    *(undefined4 *)(iVar2 + 0x218) = 2;

    *(undefined4 *)(iVar2 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

    *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x40400000;

    *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) | 1;

    *(undefined4 *)(iVar1 + 0x5c) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x18c) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x188) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x184) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x180) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x178) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x174) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x170) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0xf0) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x60) = 0;

    TeamMemberInitWeapons__FP6OBJECT(param_1);

    ANM_DumpCluster(param_1);

    return;

  }

  if (*(int *)(param_1 + 4) == 3) {

    iVar1 = *(int *)(param_1 + 0x100);

    reaper_init_trails(param_1,iVar1 + 0x68);

    reaper_init_items(param_1);

    reaper_set_bow(param_1,0x2c,0,0xffffffff,0);

    object_create_child(param_1,1,0x29d);

    *(undefined4 *)(iVar1 + 0xdb4) = 0;

  }

  ANM_DumpCluster(param_1);

  return;

}

/* ===== object_destroy_specialtype @ 0x0049BAA0 ===== */
/* PS2 candidate: object_destroy_specialtype (conf 0.391) */



void object_destroy_specialtype(int param_1)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  

  ANM_DumpCluster(param_1);

  iVar4 = *(int *)(param_1 + 4);

  if (iVar4 == 2) {

    iVar4 = *(int *)(param_1 + 0x100);

    obj_children_destroy(param_1);

    obj_children_destroy_2(param_1);

    puVar3 = DAT_00632d68;

    if (*(int *)(param_1 + 0x174) == 0) {

      FUN_00500f80(param_1);

      puVar3 = DAT_00632d68;

    }

    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

      iVar1 = puVar3[3];

      if ((*(int *)(iVar1 + 0x210) == param_1) &&

         (((iVar2 = *(int *)(iVar1 + 4), iVar2 == 0x54 || (iVar2 == 0x55)) || (iVar2 == 0x30d)))) {

        object_destroy(iVar1);

      }

    }

    TeamMemberClearWeapons__FP6OBJECT(param_1);

    item_drop_backheld(param_1);

    if (*(int *)(iVar4 + 0x1a0) != 0) {

      fx_delete(*(int *)(iVar4 + 0x1a0));

      *(undefined4 *)(iVar4 + 0x1a0) = 0;

    }

    if (*(int *)(iVar4 + 0xf4) != 0) {

      fx_delete(*(int *)(iVar4 + 0xf4));

      *(undefined4 *)(iVar4 + 0xf4) = 0;

    }

  }

  else {

    if (iVar4 == 3) {

      reaper_release_shrink(param_1,*(int *)(param_1 + 0x100) + 0xdbc);

      *(undefined4 *)(param_1 + 0x184) = 0;

      obj_children_destroy(param_1);

      obj_children_destroy_2(param_1);

      puVar3 = DAT_00632d68;

      if (*(int *)(param_1 + 0x174) == 0) {

        FUN_00500f80(param_1);

        puVar3 = DAT_00632d68;

      }

      for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

        iVar4 = puVar3[3];

        if ((*(int *)(iVar4 + 0x210) == param_1) &&

           ((*(int *)(iVar4 + 4) == 0x1f || (*(int *)(iVar4 + 4) == 0x25)))) {

          object_destroy(iVar4);

        }

        if ((*(int *)(iVar4 + 0x1e0) == 0x3e) && (*(int *)(iVar4 + 0x274) == param_1)) {

          object_destroy(iVar4);

        }

      }

      item_drop_backheld(param_1);

      return;

    }

    if (iVar4 == 1) {

      iVar4 = teammecc_get_slavecount(param_1,0);

      if (iVar4 != 0) {

        object_destroy(iVar4);

      }

      iVar4 = teammecc_get_slavecount(param_1,1);

      if (iVar4 != 0) {

        object_destroy();

        return;

      }

    }

  }

  return;

}

/* ===== FUN_0049bc50 @ 0x0049BC50 ===== */
void FUN_0049bc50(int param_1)



{

  if ((*(int *)(param_1 + 0x10) == 0xfe) ||

     (*(int *)(*(int *)(param_1 + 8) + 8 + *(int *)(param_1 + 0x10) * 4) == 0)) {

    if (*(int *)(*(int *)(param_1 + 8) + 0xc) == 0) {

      return;

    }

    *(undefined4 *)(param_1 + 0x10) = 1;

  }

  object_animate_process(param_1,0);

  return;

}

/* ===== tracer_calc_falloff__FP6Traceri @ 0x0049BC90 ===== */
/* PS2 candidate: object_get_ref_world (conf 0.313) */



void tracer_calc_falloff__FP6Traceri(int param_1,int param_2,undefined4 param_3)



{

  int iVar1;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar1 = param_2 * 0x44 + *(int *)(param_1 + 0x2dc);

  local_c = *(undefined4 *)(iVar1 + 0x10);

  local_8 = *(undefined4 *)(iVar1 + 0x20);

  local_4 = *(undefined4 *)(iVar1 + 0x30);

  xformobj_p3d_world(param_1,&local_c,param_3);

  return;

}

/* ===== FUN_0049bd10 @ 0x0049BD10 ===== */
int FUN_0049bd10(undefined4 param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = 0;

  if (0 < *(int *)(DAT_006330e4 + 0x208)) {

    iVar3 = 0;

    do {

      iVar1 = match(param_1,*(undefined4 *)(*(int *)(DAT_006330e4 + 0x20c) + iVar3));

      if (iVar1 != 0) {

        return *(int *)(DAT_006330e4 + 0x20c) + iVar2 * 0xc;

      }

      iVar2 = iVar2 + 1;

      iVar3 = iVar3 + 0xc;

    } while (iVar2 < *(int *)(DAT_006330e4 + 0x208));

  }

  crt_sprintf(&DAT_00657400,s_Failed_to_find_WorldAnim___s__0055e79c,param_1);

  FUN_0051ea20(&DAT_00657400);

  return 0;

}

/* ===== collgrid_anim_audio_user @ 0x0049BD90 ===== */
int collgrid_anim_audio_user

              (undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,

              undefined4 *param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int local_30;

  int local_2c;

  int local_28;

  undefined4 local_24;

  undefined4 local_20;

  int local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar1 = main_0042b1d0(param_3);

  AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_3(iVar1);

  main_animate_00404b60(param_3,0xffffffff);

  Audio3DTestToneUpdate__Fv_3();

  local_18 = *param_2;

  local_14 = param_2[1];

  local_10 = param_2[2];

  iVar1 = *(int *)(*(int *)((int)param_3 + 8) + 0x400 + iVar1 * 4);

  iVar3 = 0;

  local_1c = 0;

  param_2 = (undefined4 *)0x0;

  if (0 < *(int *)(iVar1 + 0x68)) {

    param_3 = (undefined4 *)(iVar1 + 0x84);

    do {

      local_20 = *param_3;

      local_24 = 0xffff;

      iVar2 = collgrid_00430e10(&local_20,&local_24,&local_28,&local_2c,&local_30);

      iVar3 = local_1c;

      while (local_1c = iVar3, iVar2 != 0) {

        iVar3 = *(int *)(iVar1 + 0x34);

        iVar2 = *(int *)(iVar1 + 0x14);

        iVar3 = collide_line_tri_hit

                          (param_1,&local_18,iVar2 + (uint)*(ushort *)(iVar3 + local_28 * 2) * 0xc,

                           iVar2 + (uint)*(ushort *)(iVar3 + local_2c * 2) * 0xc,

                           iVar2 + (uint)*(ushort *)(iVar3 + local_30 * 2) * 0xc,&local_c);

        if (iVar3 != 0) {

          if (param_4 == (undefined4 *)0x0) {

            return 1;

          }

          local_18 = local_c;

          local_14 = local_8;

          local_10 = local_4;

          local_1c = 1;

        }

        iVar2 = collgrid_00430e10(&local_20,&local_24,&local_28,&local_2c,&local_30);

        iVar3 = local_1c;

      }

      param_2 = (undefined4 *)((int)param_2 + 1);

      param_3 = param_3 + 0x14;

    } while ((int)param_2 < *(int *)(iVar1 + 0x68));

    if (iVar3 != 0) {

      if (param_4 != (undefined4 *)0x0) {

        *param_4 = local_c;

        param_4[1] = local_8;

        param_4[2] = local_4;

      }

      if (param_5 != (undefined4 *)0x0) {

        *param_5 = 0;

      }

    }

  }

  return iVar3;

}

/* ===== los_line_check @ 0x0049BF60 ===== */
int los_line_check(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,

                  undefined4 param_5)



{

  int iVar1;

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined1 local_18 [12];

  undefined1 local_c [12];

  

  xformobj_world_local(param_3,param_1,local_c);

  xformobj_world_local(param_3,param_2,local_18);

  iVar1 = collgrid_anim_audio_user(local_c,local_18,param_3,param_4,param_5);

  if ((iVar1 != 0) && (param_4 != (undefined4 *)0x0)) {

    local_24 = *param_4;

    local_20 = param_4[1];

    local_1c = param_4[2];

    xformobj_p3d_world(param_3,&local_24,param_4);

  }

  return iVar1;

}

/* ===== collide_line_tri_hit @ 0x0049BFE0 ===== */
/* PS2 candidate: collide_line_tri_hit (conf 0.573) */



int collide_line_tri_hit

              (float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,

              float *param_6)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  local_10 = (param_5[2] - param_3[2]) * (param_4[1] - param_3[1]) -

             (param_5[1] - param_3[1]) * (param_4[2] - param_3[2]);

  local_c = (*param_5 - *param_3) * (param_4[2] - param_3[2]) -

            (*param_4 - *param_3) * (param_5[2] - param_3[2]);

  local_8 = (*param_4 - *param_3) * (param_5[1] - param_3[1]) -

            (*param_5 - *param_3) * (param_4[1] - param_3[1]);

  normalize__FPfN20(&local_10,&local_c,&local_8);

  local_4 = -(local_c * param_3[1] + local_8 * param_3[2] + local_10 * *param_3);

  fVar1 = local_c * param_1[1] + local_8 * param_1[2] + local_10 * *param_1 + local_4;

  if ((local_c * param_2[1] + local_8 * param_2[2] + local_10 * *param_2 + local_4) * fVar1 < 0.0) {

    fVar2 = (param_2[2] - param_1[2]) * local_8 +

            (param_2[1] - param_1[1]) * local_c + (*param_2 - *param_1) * local_10;

    if (((fVar2 != 0.0) && (fVar1 = -(fVar1 / fVar2), 0.0 <= fVar1)) && (fVar1 <= 1.0)) {

      local_1c = (*param_2 - *param_1) * fVar1 + *param_1;

      local_18 = (param_2[1] - param_1[1]) * fVar1 + param_1[1];

      local_14 = (param_2[2] - param_1[2]) * fVar1 + param_1[2];

      iVar3 = point_in_tri(&local_1c,&local_10,param_3,param_4,param_5);

      if (param_6 == (float *)0x0) {

        return iVar3;

      }

      if (iVar3 == 0) {

        return 0;

      }

      *param_6 = local_1c;

      param_6[1] = local_18;

      param_6[2] = local_14;

      return iVar3;

    }

  }

  return 0;

}

/* ===== collide_line_grid @ 0x0049C1D0 ===== */
/* PS2 candidate: collide_line_grid (conf 0.602) */



undefined4 collide_line_grid(undefined4 param_1,undefined4 param_2,int param_3,int param_4)



{

  byte bVar1;

  int iVar2;

  undefined1 *puVar3;

  undefined1 *puVar4;

  undefined1 *puVar5;

  undefined1 local_30 [12];

  undefined1 local_24 [12];

  undefined1 local_18 [12];

  undefined1 local_c [12];

  

  if ((((-1 < param_3) && (-1 < param_4)) && (param_3 < *(int *)(DAT_006330e4 + 0x1d8) + -1)) &&

     (param_4 < *(int *)(DAT_006330e4 + 0x1dc) + -1)) {

    bVar1 = *(byte *)(*(int *)(*(int *)(DAT_006330e4 + 0x10) + param_4 * 4) + 0xc + param_3 * 0x10);

    grid_get_point(param_3,param_4,local_30);

    grid_get_point(param_3 + 1,param_4,local_18);

    grid_get_point(param_3,param_4 + 1,local_c);

    grid_get_point(param_3 + 1,param_4 + 1,local_24);

    switch(bVar1 & 7) {

    case 1:

      puVar5 = local_30;

      puVar4 = local_c;

      puVar3 = local_18;

      break;

    case 2:

      puVar5 = local_24;

      puVar4 = local_18;

      puVar3 = local_c;

      break;

    case 3:

      puVar5 = local_18;

      puVar4 = local_30;

      puVar3 = local_24;

      break;

    case 4:

      puVar5 = local_c;

      puVar4 = local_24;

      puVar3 = local_30;

      break;

    case 5:

      iVar2 = collide_line_tri_hit(param_1,param_2,local_24,local_30,local_18,param_2);

      if (iVar2 != 0) {

        return 1;

      }

      puVar5 = local_c;

      puVar4 = local_24;

      puVar3 = local_30;

      break;

    case 6:

      iVar2 = collide_line_tri_hit(param_1,param_2,local_18,local_c,local_30,param_2);

      if (iVar2 != 0) {

        return 1;

      }

      puVar5 = local_24;

      puVar4 = local_18;

      puVar3 = local_c;

      break;

    default:

      goto switchD_0049c26d_default;

    }

    iVar2 = collide_line_tri_hit(param_1,param_2,puVar3,puVar4,puVar5,param_2);

    if (iVar2 != 0) {

      return 1;

    }

  }

switchD_0049c26d_default:

  return 0;

}

/* ===== collide_wall_block @ 0x0049C550 ===== */
/* PS2 candidate: collide_wall_block (conf 0.537) */



undefined4 collide_wall_block(float *param_1,float *param_2,float param_3)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  float local_10;

  float local_c;

  float local_8;

  

  local_10 = 100.0;

  if (*param_1 != *param_2) {

    local_10 = ABS(param_3 / (*param_2 - *param_1));

  }

  fVar1 = 100.0;

  if (param_1[1] != param_2[1]) {

    fVar1 = ABS(param_3 / (param_2[1] - param_1[1]));

  }

  if (local_10 < fVar1) {

    fVar1 = local_10;

  }

  local_c = (*param_2 - *param_1) * (fVar1 + 1.1) + *param_1;

  local_8 = (param_2[1] - param_1[1]) * (fVar1 + 1.1) + param_1[1];

  grid_coords_from_floats(param_1,&param_1,&local_10);

  grid_coords_from_floats(&local_c,&param_3,&param_2);

  iVar4 = (int)param_3 - (int)param_1;

  iVar5 = (int)param_2 - (int)local_10;

  if (iVar5 < 0) {

    iVar5 = -iVar5;

  }

  if (iVar4 < 0) {

    iVar4 = -iVar4;

  }

  if (iVar5 < iVar4) {

    iVar5 = iVar5 * 2;

    iVar2 = iVar4 * -2;

    iVar6 = iVar5 - iVar4;

    if (iVar4 != 0) {

      do {

        iVar3 = iVar5;

        if (-1 < iVar6) {

          iVar3 = iVar5 + iVar2;

        }

        iVar6 = iVar6 + iVar3;

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      return 0;

    }

  }

  else {

    iVar4 = iVar4 * 2;

    iVar2 = iVar5 * -2;

    iVar6 = iVar4 - iVar5;

    for (; iVar5 != 0; iVar5 = iVar5 + -1) {

      iVar3 = iVar4;

      if (-1 < iVar6) {

        iVar3 = iVar4 + iVar2;

      }

      iVar6 = iVar6 + iVar3;

    }

  }

  return 0;

}

/* ===== FUN_0049dbd0 @ 0x0049DBD0 ===== */
/* PS2 candidate: offspring_can_attack__FP6OBJECT (conf 0.444) */



undefined4 FUN_0049dbd0(int param_1)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float10 fVar4;

  undefined4 uVar5;

  

  iVar3 = *(int *)(param_1 + 0x100);

  fVar4 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,*(int *)(iVar3 + 0x3c) + 0xa0);

  fVar4 = (float10)playerobj_turn((float)fVar4,*(undefined4 *)(param_1 + 200));

  if ((fVar4 <= (float10)10.0) && ((float10)-10.0 <= fVar4)) {

    fVar4 = (float10)distancesq2d__FP3P3DT0(*(int *)(iVar3 + 0x3c) + 0xa0,param_1 + 0xa0);

    fVar1 = (float)fVar4;

    if (fVar1 < *(float *)(DAT_00632ed8 + 0xd04) * *(float *)(DAT_00632ed8 + 0xd04)) {

      iVar3 = crt_rand_scaled(100);

      if (iVar3 < 0x32) {

        uVar5 = 0x682;

      }

      else {

        uVar5 = 0x683;

      }

      sound_play_obj(uVar5,param_1);

      *(undefined4 *)(param_1 + 0xe4) = 0xe;

      return 1;

    }

    if ((fVar1 < *(float *)(DAT_00632ed8 + 0x1288) * *(float *)(DAT_00632ed8 + 0x1288)) &&

       (fVar2 = *(float *)(DAT_00632ed8 + 0xd00),

       fVar4 = (float10)distancesq2d__FP3P3DT0(*(int *)(iVar3 + 0x3c) + 0xa0,iVar3 + 0x40),

       fVar4 <= (float10)fVar2 * (float10)fVar2)) {

      sound_play_obj(0x688,param_1);

      *(undefined4 *)(param_1 + 0xe4) = 0x13;

      return 2;

    }

    if (((fVar1 < *(float *)(DAT_00632ed8 + 0x12a0) * *(float *)(DAT_00632ed8 + 0x12a0)) &&

        (*(float *)(param_1 + 0xfc) < 0.0)) &&

       (fVar1 = *(float *)(DAT_00632ed8 + 0xd00),

       fVar4 = (float10)distancesq2d__FP3P3DT0(*(int *)(iVar3 + 0x3c) + 0xa0,iVar3 + 0x40),

       (float10)fVar1 * (float10)fVar1 < fVar4)) {

      *(undefined4 *)(param_1 + 0xe4) = 0x17;

      return 3;

    }

  }

  return 0;

}

/* ===== get_floor_z_point_plat_2 @ 0x0049DD90 ===== */
void get_floor_z_point_plat_2(int param_1)



{

  float fVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  float10 fVar6;

  float local_4;

  

  iVar2 = *(int *)(param_1 + 0x100);

  *(undefined4 *)(iVar2 + 0x3c) = 0;

  local_4 = *(float *)(DAT_00632ed8 + 0x12a0) + *(float *)(DAT_00632ed8 + 0xd00);

  local_4 = local_4 * local_4;

  for (puVar4 = DAT_00632d6c; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

    iVar3 = puVar4[3];

    iVar5 = ObjIsPlayer(iVar3);

    if ((((iVar5 != 0) || (*(int *)(iVar3 + 0x1e0) == 0x55)) &&

        ((*(uint *)(iVar3 + 0xd8) & 0x4000c000) == 0)) &&

       ((*(float *)(iVar3 + 0x278) < *(float *)(iVar3 + 0x1c0) &&

        ((iVar5 = ObjIsMecc(iVar3), iVar5 == 0 || ((*(uint *)(iVar3 + 0xe0) & 0x2000000) == 0))))))

    {

      fVar6 = (float10)FUN_0050a610(iVar2 + 0x40,iVar3 + 0xa0);

      fVar1 = (float)fVar6;

      iVar5 = ObjIsKabuto(iVar3);

      if (iVar5 != 0) {

        fVar1 = fVar1 * 0.25;

      }

      if (fVar1 <= local_4) {

        *(int *)(iVar2 + 0x3c) = iVar3;

        local_4 = fVar1;

      }

    }

  }

  return;

}

/* ===== FUN_0049de80 @ 0x0049DE80 ===== */
/* PS2 candidate: offspring_set_chase_location__FP6OBJECTi (conf 0.441) */



void FUN_0049de80(int param_1,int param_2)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  float10 fVar4;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  fVar2 = *(float *)(DAT_00632ed8 + 0xd00);

  iVar3 = *(int *)(param_1 + 0x100);

  pfVar1 = (float *)(iVar3 + 0x40);

  fVar4 = (float10)distancesq2d__FP3P3DT0(*(int *)(iVar3 + 0x3c) + 0xa0,pfVar1);

  if ((float10)fVar2 * (float10)fVar2 < fVar4) {

    local_18 = *(float *)(*(int *)(iVar3 + 0x3c) + 0xa0) - *pfVar1;

    local_14 = *(float *)(*(int *)(iVar3 + 0x3c) + 0xa4) - *(float *)(iVar3 + 0x44);

    local_10 = 0.0;

    normalize__FPfN20(&local_18,&local_14,&local_10);

    local_c = *(float *)(DAT_00632ed8 + 0xd00) * local_18 + *pfVar1;

    local_8 = *(float *)(DAT_00632ed8 + 0xd00) * local_14 + *(float *)(iVar3 + 0x44);

    local_4 = *(float *)(DAT_00632ed8 + 0xd00) * local_10 + *(float *)(iVar3 + 0x48);

    ai_move_force_goal(param_1,&local_c);

    return;

  }

  if (param_2 != 0) {

    ai_move_force_goal(param_1,*(int *)(iVar3 + 0x3c) + 0xa0);

    return;

  }

  ai_move_force_goal(param_1,*(int *)(iVar3 + 0x3c) + 0xa0);

  return;

}

/* ===== offspring_dive_release_target__FP6OBJECT @ 0x0049DF90 ===== */
/* PS2 candidate: offspring_dive_release_target__FP6OBJECT (conf 0.394) */



void offspring_dive_release_target__FP6OBJECT(int param_1)



{

  int iVar1;

  float10 fVar2;

  float local_c;

  float local_8;

  float local_4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(int *)(param_1 + 0x274) != 0) {

    kbos_attach_object(param_1,*(int *)(param_1 + 0x274),0,1);

    *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(param_1 + 0x274);

    *(undefined4 *)(param_1 + 0x274) = 0;

    obj_damage_apply(0x15,*(undefined4 *)(DAT_00632ed8 + 0x1294),*(undefined4 *)(iVar1 + 0x3c),

                     param_1,0,0);

    local_c = -*(float *)(param_1 + 0x29c);

    local_8 = -*(float *)(param_1 + 0x2ac);

    local_4 = 0.0;

    normalize__FPfN20(&local_c,&local_8,&local_4);

    local_c = *(float *)(DAT_00632ed8 + 0x1588) * local_c + *(float *)(param_1 + 0x2a4);

    local_8 = *(float *)(DAT_00632ed8 + 0x1588) * local_8 + *(float *)(param_1 + 0x2b4);

    fVar2 = (float10)get_floor_z_point(&local_c);

    local_4 = (float)fVar2;

    reaper_spawn_ospec_1

              (param_1,*(undefined4 *)(iVar1 + 0x3c),&local_c,0,

               *(undefined4 *)(DAT_00632ed8 + 0x1550),0x3f800000);

    sound_play_obj(0x689,param_1);

  }

  return;

}

/* ===== options_defaults @ 0x0049E290 ===== */
void options_defaults(void)



{

  int iVar1;

  undefined4 *puVar2;

  char local_40 [64];

  

  puVar2 = &DAT_00633100;

  for (iVar1 = 0x99; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  DAT_00633118 = 1;

  DAT_00633150 = 2;

  filecopy_dirs();

  reg_query_value_5(s_DefPlayer_0055a07c,local_40,0x40);

  if (local_40[0] != '\0') {

    menu_audio_setup(2);

    reg_open_key(local_40);

    mission_0051a0c0(s_VideoWidth_0055be0c,&DAT_006331c8);

    mission_0051a0c0(s_VideoHeight_0055be00,&DAT_006331cc);

    mission_0051a0c0(s_VideoDepth_0055bdf4,&DAT_006331d0);

    reg_query_value_4(s_VideoDevGuid_0055bde4,&DAT_006331e8,0x10);

    reg_query_value_4(s_VideoDrvGuid_0055bdd4,&DAT_006331d8,0x10);

  }

  reg_close_key();

  return;

}

/* ===== cmdline_parse @ 0x0049E350 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void cmdline_parse(char *param_1)



{

  int iVar1;

  uint uVar2;

  char *pcVar3;

  int local_8;

  int local_4;

  

  pcVar3 = param_1;

  iVar1 = match(param_1,s__guns_0055e7e0);

  if (iVar1 != 0) {

    _DAT_00633138 = 1;

    return;

  }

  iVar1 = match(pcVar3,s__japan_0055e7d8);

  if (iVar1 != 0) {

    DAT_00633148 = 1;

    return;

  }

  iVar1 = matchn(pcVar3,s__tlod_0055e7d0,5);

  if (iVar1 != 0) {

    _DAT_0063314c = ANM_BinderDestroy_3(pcVar3 + 5);

    return;

  }

  iVar1 = match(pcVar3,s__window_0055e7c8);

  if (iVar1 != 0) {

    DAT_006331d4 = 1;

    return;

  }

  if (*pcVar3 == '-') {

    pcVar3 = pcVar3 + 1;

    if (DAT_005810b8 < 2) {

      uVar2 = (byte)PTR_DAT_00580eac[*pcVar3 * 2] & 4;

    }

    else {

      uVar2 = FUN_00544123((int)*pcVar3,4);

    }

    if (uVar2 != 0) {

      local_4 = 0;

      local_8 = 0;

      param_1 = (char *)0x0;

      iVar1 = crt_scanf_entry(pcVar3,s__dx_dx_d_0055c288,&param_1,&local_8,&local_4);

      if (iVar1 == 0) {

        crt_scanf_entry(pcVar3,s__dX_dX_d_0055e7bc,&param_1,&local_8,&local_4);

      }

      if (0 < (int)param_1) {

        DAT_006331c8 = (int)param_1;

      }

      if (0 < local_8) {

        DAT_006331cc = local_8;

      }

      if (0 < local_4) {

        DAT_006331d0 = local_4;

      }

    }

  }

  return;

}

/* ===== lift_logic__FP6OBJECT @ 0x0049E4A0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: lift_logic__FP6OBJECT (conf 0.463) */



void lift_logic__FP6OBJECT(int param_1)



{

  int iVar1;

  float10 fVar2;

  

  if (((DAT_00632a88 != 0) && (DAT_00632bb8 == 0)) &&

     ((param_1 == 0 || ((DAT_00632bbc != 0 && (3 < *(int *)(param_1 + 0xe4))))))) {

    dlog_push_level(&LAB_0049f2d0,&LAB_0049f050);

    dialog_level_set_textentry_mode();

    DAT_00632bb8 = 1;

    DAT_00633020 = 0;

    DAT_0059f9a4 = 0;

    DAT_0059f998 = param_1;

    DAT_0059f99c = object_allocate_type(0x400,0);

    *(undefined4 *)(DAT_0059f99c + 200) = *(undefined4 *)(param_1 + 200);

    object_set_location_p3d(DAT_0059f99c,param_1 + 0xa0);

    fVar2 = (float10)FUN_00518b70(0,0);

    object_animate_process(DAT_0059f99c,(float)fVar2);

    *(uint *)(DAT_0059f99c + 0xd8) = *(uint *)(DAT_0059f99c + 0xd8) | 0x10;

    ObjectCalculateTransform(DAT_0059f99c);

    iVar1 = main_status_00500520(&DAT_00632900);

    if (iVar1 != 0) {

      BinFileCreateWrite(0x42700000);

      iVar1 = ObjIsMecc(DAT_00632a88);

      DAT_0063291c = 0xc - (uint)(iVar1 != 0);

      DAT_00632920 = 0xffffffff;

      DAT_00632924 = DAT_00632e84;

      DAT_00632928 = DAT_00632e88;

      iVar1 = ObjIsMecc(DAT_00632a88);

      if (iVar1 == 0) {

        iVar1 = ObjIsReaper(DAT_00632a88);

        if (iVar1 != 0) {

          obj_snap_variant_a(DAT_00632a88);

        }

      }

      else {

        mecc_stop_looping_effects(DAT_00632a88);

      }

      if (DAT_0059f998 != 0) {

        camera_override_refpt(DAT_0059f998,10);

        FUN_00418770(DAT_0059f998,10,&DAT_0059f994);

      }

      _DAT_0059f9a8 = 0;

      DAT_0059f9b0 = 0;

      sound_play(0x669);

      sound_play();

      return;

    }

    dialog_level_pop(&LAB_0049f2d0);

    DAT_00632bb8 = 0;

  }

  return;

}

/* ===== FUN_0049e670 @ 0x0049E670 ===== */
bool FUN_0049e670(int param_1,int param_2,int *param_3,int param_4)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  iVar3 = ObjIsMecc(param_1);

  iVar5 = param_2 + -0x30;

  if (iVar3 == 0) {

    iVar5 = param_2 + -0x40;

  }

  iVar3 = IconDefMaxAmmo(param_2);

  if (iVar3 == -1) {

    *param_3 = -1;

    return false;

  }

  iVar4 = IconDefWieldType(param_2,1);

  iVar6 = 0;

  for (puVar1 = DAT_00632d6c; puVar2 = DAT_00632d98, puVar1 != (undefined4 *)0x0;

      puVar1 = (undefined4 *)*puVar1) {

    if ((*(int *)(puVar1[3] + 4) == iVar4) &&

       (*(int *)(puVar1[3] + 0x18c) == *(int *)(param_1 + 0x18c))) {

      iVar6 = iVar6 + 1;

    }

  }

  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar4 = puVar2[3];

    if ((((*(int *)(iVar4 + 0x1e0) == 0x12) && (*(int *)(*(int *)(iVar4 + 0x100) + 0x54) == iVar5))

        && (*(int *)(iVar4 + 0x274) != 0)) &&

       (*(int *)(*(int *)(iVar4 + 0x274) + 0x18c) == *(int *)(param_1 + 0x18c))) {

      iVar6 = iVar6 + 1;

    }

  }

  if ((param_4 != 0) && (DAT_00632920 == param_2)) {

    iVar6 = iVar6 + 1;

  }

  if (iVar3 < iVar6) {

    iVar6 = iVar3;

  }

  *param_3 = iVar3 - iVar6;

  return iVar6 < iVar3;

}

/* ===== partyhouse_exit_dlog @ 0x0049F1C0 ===== */
void partyhouse_exit_dlog(void)



{

  int iVar1;

  

  DAT_00632aa4._3_1_ = 0;

  DAT_00632aeb = 0;

  camera_fov_update();

  dialog_level_pop(&LAB_0049f2d0);

  DAT_00632bb8 = 0;

  if (((DAT_0059f998 != 0) && (DAT_00632a88 != 0)) && (DAT_00632bbc != 0)) {

    iVar1 = fx_create(DAT_0059f998);

    if (iVar1 == 0) {

      iVar1 = dialog_level_is_base();

      if (iVar1 != 0) {

        commonbase_init_user(DAT_00632bbc,DAT_00632a88,DAT_0059f998);

      }

    }

    else {

      base_partyhouse_exit(DAT_00632a88,DAT_0059f998);

    }

    bldg_get_refpt_worldlocdir(DAT_0059f998,0xc,DAT_00632a88 + 0xa0,DAT_00632a88 + 200);

    object_copy_posdirinfo(DAT_00632a88);

    camera_override_done();

  }

  if (DAT_0059f99c != 0) {

    *(undefined4 *)(DAT_0059f99c + 0x184) = 0x3f800000;

    object_destroy(DAT_0059f99c);

    DAT_0059f99c = 0;

  }

  sound_stop(0x669);

  sound_play(0x66c);

  DAT_0059f998 = 0;

  return;

}

/* ===== chat_log_close @ 0x0049F510 ===== */
void chat_log_close(void)



{

  int iVar1;

  

  if (DAT_00633240 == 0) {

    iVar1 = BinFileSeek_2(s_chatlog_txt_0055e874,&DAT_00556384);

    if (iVar1 != 0) {

      crt_file_free_init(iVar1,s_____________Log_chat_toggled_OFF_0055e81c,(double)DAT_006328e8);

      editor_0054384c(iVar1);

    }

  }

  else {

    iVar1 = BinFileSeek_2(s_chatlog_txt_0055e874,&DAT_00556384);

    if (iVar1 != 0) {

      crt_file_free_init(iVar1,s_____________Log_chat_toggled_ON_a_0055e848,(double)DAT_006328e8);

      editor_0054384c(iVar1);

      return;

    }

  }

  return;

}

/* ===== chat_log_init @ 0x0049F5A0 ===== */
undefined4 chat_log_init(int param_1)



{

  char cVar1;

  int iVar2;

  undefined1 *puVar3;

  undefined4 uVar4;

  uint uVar5;

  char *pcVar6;

  undefined8 uVar7;

  int local_104;

  undefined1 local_100 [256];

  

  iVar2 = match(param_1);

  if (iVar2 != 0) {

    DAT_0063320c = (uint)(DAT_0063320c == 0);

    return 1;

  }

  iVar2 = match(param_1);

  if ((iVar2 != 0) && (iVar2 = dialog_level_is_base(), iVar2 == 0)) {

    mission_0051a0c0(s_MissionCheat_0055be64,&local_104);

    if (local_104 == 0) {

      comm_0051a130(s_MissionCheat_0055be64,1);

      return 1;

    }

    comm_0051a130(s_MissionCheat_0055be64,0);

    return 1;

  }

  iVar2 = match(param_1);

  if (iVar2 != 0) {

    DAT_00633100 = (0x31 < (int)DAT_00633100) - 1 & 99;

    return 1;

  }

  iVar2 = match(param_1);

  if (iVar2 != 0) {

    DAT_00633100 = (0x31 < (int)DAT_00633100) - 1 & 100;

    return 1;

  }

  iVar2 = match(param_1);

  if (iVar2 != 0) {

    if (DAT_00632f44 == 0) {

      DAT_00633100 = 1;

      return 1;

    }

    if ((int)DAT_00633100 < 0x32) {

      DAT_00633100 = (int)(DAT_00633100 + 1) % 0x15;

      return 1;

    }

    DAT_00633100 = 1;

    return 1;

  }

  iVar2 = match(param_1);

  if (iVar2 == 0) {

    iVar2 = match(param_1);

    if (iVar2 == 0) {

      iVar2 = match(param_1);

      if (iVar2 == 0) {

        iVar2 = match(param_1);

        if (iVar2 == 0) {

          iVar2 = match(param_1);

          if (iVar2 != 0) {

            DAT_0063325c = (uint)(DAT_0063325c == 0);

            if (DAT_0063325c == 0) {

              uVar4 = FUN_00507b00();

              crt_sprintf(local_100,uVar4);

              uVar4 = 1;

              puVar3 = local_100;

            }

            else {

              uVar4 = FUN_00507b00();

              crt_sprintf(local_100,uVar4);

              uVar4 = 1;

              puVar3 = local_100;

            }

LAB_0049f8f1:

            comm_005363f0(puVar3,uVar4);

            return 1;

          }

          iVar2 = crt_file_lock_ops(param_1,s_newhost_0055e8a0);

          if (iVar2 == 0) {

            comm_fakehost_player();

            return 1;

          }

          iVar2 = match(param_1);

          if (iVar2 != 0) {

            comm_fakehost_toggle();

            return 1;

          }

          iVar2 = crt_file_lock_ops(param_1,s_message_0055e88c);

          if (iVar2 == 0) {

            uVar5 = 0xffffffff;

            pcVar6 = (char *)(param_1 + 8);

            do {

              if (uVar5 == 0) break;

              uVar5 = uVar5 - 1;

              cVar1 = *pcVar6;

              pcVar6 = pcVar6 + 1;

            } while (cVar1 != '\0');

            _strncpy(&DAT_00633260,(char *)(param_1 + 8),~uVar5 - 1);

            return 1;

          }

          iVar2 = match(param_1,s_pmarkers_0055e880);

          if (iVar2 == 0) {

            return 0;

          }

          iVar2 = dialog_level_is_base();

          if (iVar2 != 0) {

            iVar2 = FUN_0052c5c0();

            if (iVar2 != 0) {

              comm_player_marker_menu();

              return 1;

            }

            iVar2 = AudioGetMasterVolume__Fv_9();

            if (DAT_005def94 == iVar2) {

              comm_audio_vol_d();

            }

          }

        }

        else {

          iVar2 = dialog_level_is_base();

          if (iVar2 != 0) {

            iVar2 = FUN_0052c5c0();

            if (iVar2 != 0) {

              DAT_00633250 = (uint)(DAT_00633250 == 0);

              comm_0052b780_user_4();

              if (DAT_00633250 == 0) {

                uVar7 = 0x10055e8e4;

              }

              else {

                uVar7 = 0x10055e8f0;

              }

              puVar3 = (undefined1 *)FUN_00507b00(uVar7);

              uVar4 = (undefined4)((ulonglong)uVar7 >> 0x20);

              goto LAB_0049f8f1;

            }

            iVar2 = AudioGetMasterVolume__Fv_9();

            if (DAT_005def94 == iVar2) {

              comm_audio_vol_c();

              return 1;

            }

          }

        }

      }

      else {

        DAT_00633240 = (uint)(DAT_00633240 == 0);

        if (DAT_00633240 == 0) {

          iVar2 = BinFileSeek_2(s_chatlog_txt_0055e874,&DAT_00556384);

          if (iVar2 != 0) {

            crt_file_free_init(iVar2,s_____________Log_chat_toggled_OFF_0055e81c,

                               (double)DAT_006328e8);

            editor_0054384c(iVar2);

            return 1;

          }

        }

        else {

          iVar2 = BinFileSeek_2(s_chatlog_txt_0055e874,&DAT_00556384);

          if (iVar2 != 0) {

            crt_file_free_init(iVar2,s_____________Log_chat_toggled_ON_a_0055e848,

                               (double)DAT_006328e8);

            editor_0054384c(iVar2);

            return 1;

          }

        }

      }

    }

    else if (DAT_00632f44 != 0) {

      DAT_00633238 = (uint)(DAT_00633238 == 0);

      game_options_verify();

      return 1;

    }

  }

  else {

    if (DAT_00632f44 == 0) {

      DAT_00633100 = 1;

      return 1;

    }

    if (0x31 < (int)DAT_00633100) {

      DAT_00633100 = 0x14;

      return 1;

    }

    DAT_00633100 = DAT_00633100 + -1;

    if ((int)DAT_00633100 < 1) {

      DAT_00633100 = 0x14;

      return 1;

    }

  }

  return 1;

}

/* ===== main/path_0049fb00 @ 0x0049FB00 ===== */
void main_path_0049fb00(undefined4 param_1,int *param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar2 = DAT_006330e4;

  iVar3 = __ftol();

  iVar4 = __ftol();

  iVar1 = *(int *)(iVar2 + 0x1d8);

  if (iVar1 + -1 <= iVar3) {

    iVar3 = iVar1 + -2;

  }

  iVar1 = *(int *)(iVar2 + 0x1dc);

  if (iVar1 + -1 <= iVar4) {

    iVar4 = iVar1 + -2;

  }

  if (iVar3 < 0) {

    iVar3 = 0;

  }

  *param_2 = iVar3;

  if (iVar4 < 0) {

    iVar4 = 0;

  }

  *param_3 = iVar4;

  return;

}

/* ===== terrain_grid_lookup @ 0x0049FB80 ===== */
void terrain_grid_lookup(float *param_1,int *param_2,int *param_3,undefined1 *param_4)



{

  float fVar1;

  undefined1 uVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  float10 extraout_ST0;

  

  param_1 = (float *)((*param_1 - *(float *)(DAT_006330e4 + 0x1c8)) *

                     *(float *)(DAT_006330e4 + 0x1c4));

  fVar1 = (float)(*(int *)(DAT_006330e4 + 0x1d8) + -1);

  if (fVar1 < (float)param_1 != (fVar1 == (float)param_1)) {

    param_1 = (float *)((float)*(int *)(DAT_006330e4 + 0x1d8) - 2.0);

  }

  if ((float)param_1 < 0.0) {

    param_1 = (float *)0x0;

  }

  iVar3 = __ftol();

  iVar4 = __ftol();

  uVar5 = grid_get_conntype(iVar3,iVar4);

  switch(uVar5) {

  case 2:

switchD_0049fc78_caseD_2:

    uVar2 = 4;

    break;

  case 4:

switchD_0049fc78_caseD_4:

    uVar2 = 3;

    break;

  case 5:

    if ((float)param_1 - (float)iVar3 <= (float)(extraout_ST0 - (float10)iVar4))

    goto switchD_0049fc78_caseD_4;

  case 3:

    uVar2 = 2;

    break;

  case 6:

    if (1.0 - (float)(extraout_ST0 - (float10)iVar4) < (float)param_1 - (float)iVar3)

    goto switchD_0049fc78_caseD_2;

  case 1:

    uVar2 = 1;

    break;

  default:

    uVar2 = 0;

  }

  *param_2 = iVar3;

  *param_3 = iVar4;

  *param_4 = uVar2;

  return;

}

