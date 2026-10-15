/* ANNOTATED RE-EXPORT — obj->field substitutions from docs/formats/OBJECT_LAYOUT.md (observed/derived fields only).
 * Source of truth: decompiled/gog144_full. Regenerate: scripts/annotate_corpus.py. */



/* PS2 candidate: object_animate_process (conf 0.407) */



void object_animate_process(int *param_1,float param_2)



{

  float fVar1;

  float fVar2;

  uint uVar3;

  float *pfVar4;

  bool bVar5;

  uint uVar6;

  int iVar7;

  int *piVar8;

  undefined4 uVar9;

  uint *puVar10;

  undefined4 uVar11;

  int local_8;

  

  uVar9 = 0;

  if (param_1[2] == 0) {

    return;

  }

  bVar5 = false;

  piVar8 = param_1 + 4;

  local_8 = 4;

  do {

    if ((param_2 != 0.0) || ((piVar8[8] & 0x100U) != 0)) {

      uVar3 = piVar8[8];

      piVar8[8] = uVar3 & 0xfffffeff;

      bVar5 = true;

      if ((*piVar8 != 0xfe) &&

         (pfVar4 = *(float **)(param_1[2] + 8 + *piVar8 * 4), pfVar4 != (float *)0x0)) {

        fVar1 = 1.0;

        if ((float)piVar8[5] != 0.0) {

          fVar1 = (float)param_1[piVar8[4] + 0x42] / (float)piVar8[5];

        }

        if ((uVar3 & 0x10) != 0) {

          fVar1 = -fVar1;

        }

        if ((uVar3 & 0xc) != 0) {

          piVar8[8] = uVar3 & 0xfffffef7;

          param_2 = 0.0;

          piVar8[3] = 0;

        }

        if ((char)piVar8[8] < '\0') {

          if (0.0 <= fVar1) {

            piVar8[1] = (int)(*pfVar4 * (float)piVar8[1]);

          }

          else {

            piVar8[1] = (int)*pfVar4;

          }

          piVar8[8] = piVar8[8] & 0xffffff7f;

          param_2 = 0.0;

          piVar8[3] = 0;

        }

        if ((piVar8[8] & 0x20U) != 0) {

          if (0.0 <= fVar1) {

            piVar8[1] = piVar8[3];

          }

          else {

            piVar8[1] = (int)(*pfVar4 - (float)piVar8[3]);

          }

          piVar8[8] = piVar8[8] & 0xffffffdf;

        }

        if ((piVar8[8] & 0x40U) != 0) {

          if (fVar1 <= 0.0) {

            piVar8[1] = piVar8[3];

          }

          else {

            piVar8[1] = (int)(*pfVar4 - (float)piVar8[3]);

          }

          piVar8[8] = piVar8[8] & 0xffffffbf;

        }

        uVar3 = piVar8[8];

        uVar6 = uVar3 & 0xfffffffd;

        piVar8[2] = piVar8[1];

        fVar2 = fVar1 * param_2 + (float)piVar8[1];

        piVar8[8] = uVar6;

        piVar8[1] = (int)fVar2;

        piVar8[3] = 0;

        if (0.0 <= fVar1) {

          if (*pfVar4 <= fVar2) {

            piVar8[8] = uVar6 | 2;

            if (*pfVar4 <= fVar2) {

              do {

                fVar1 = (float)piVar8[1];

                fVar2 = *pfVar4;

                piVar8[1] = (int)(fVar1 - fVar2);

              } while (*pfVar4 <= fVar1 - fVar2);

            }

            piVar8[3] = piVar8[1];

            if ((uVar3 & 1) == 0) {

              piVar8[1] = (int)*pfVar4;

            }

          }

        }

        else if (fVar2 < 0.0) {

          piVar8[8] = uVar6 | 2;

          do {

            fVar1 = *pfVar4 + (float)piVar8[1];

            piVar8[1] = (int)fVar1;

          } while (fVar1 < 0.0);

          piVar8[3] = (int)(*pfVar4 - fVar1);

          if ((uVar3 & 1) == 0) {

            piVar8[1] = 0;

          }

        }

        if (((0.0 < (float)piVar8[7]) && ((float)piVar8[6] != 0.0)) &&

           (fVar1 = (float)piVar8[7] - param_2 / (float)piVar8[6], piVar8[7] = (int)fVar1,

           fVar1 < 0.0)) {

          piVar8[7] = 0;

        }

      }

    }

    piVar8 = piVar8 + 9;

    local_8 = local_8 + -1;

  } while (local_8 != 0);

  if (!bVar5) {

    return;

  }

  iVar7 = handle_next_get();

  param_1[3] = iVar7;

  BasicUsrAnmApply__FP9ObjectSetP14BasicUsrAnmDefPFP6OBJECTPvii_i(param_1);

  if (param_1[4] == 0xfe) {

    return;

  }

  pfVar4 = *(float **)(param_1[2] + 8 + param_1[4] * 4);

  if (pfVar4 == (float *)0x0) {

    return;

  }

  puVar10 = (uint *)0x0;

  if ((obj->state /* param_1[0x78] */ == 2) && (*param_1 != 0)) {

    puVar10 = *(uint **)(obj->animate_state /* param_1[0x40] */ + 0x7c);

  }

  piVar8 = (int *)pfVar4[9];

  if ((piVar8 == (int *)0x0) && (puVar10 == (uint *)0x0)) {

    return;

  }

  fVar1 = (float)param_1[5] - (float)param_1[6];

  if (fVar1 < 0.0) {

    if (*pfVar4 * 0.5 < -fVar1) {

      uVar11 = 0;

      uVar9 = 1;

      goto LAB_00404137;

    }

  }

  else {

    if (fVar1 <= *pfVar4 * 0.5) {

      uVar11 = 0;

      goto LAB_00404137;

    }

    uVar9 = 1;

  }

  uVar11 = 1;

LAB_00404137:

  if ((piVar8 != (int *)0x0) && (local_8 = 0, 0 < *piVar8)) {

    param_2 = 0.0;

    do {

      obj_impact_effects(param_1,pfVar4,uVar11,uVar9,(int)param_2 + 4 + (int)piVar8);

      param_2 = (float)((int)param_2 + 0x20);

      piVar8 = (int *)pfVar4[9];

      local_8 = local_8 + 1;

    } while (local_8 < *piVar8);

  }

  if (puVar10 != (uint *)0x0) {

    do {

      obj_impact_effects(param_1,pfVar4,uVar11,uVar9,puVar10);

      uVar3 = *puVar10;

      puVar10 = puVar10 + 8;

    } while ((uVar3 & 0x4000) == 0);

  }

  return;

}





