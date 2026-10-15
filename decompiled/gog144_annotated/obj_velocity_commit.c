/* ANNOTATED RE-EXPORT — obj->field substitutions from docs/formats/OBJECT_LAYOUT.md (observed/derived fields only).
 * Source of truth: decompiled/gog144_full. Regenerate: scripts/annotate_corpus.py. */



void obj_velocity_commit(int param_1)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  bool bVar4;

  int local_8 [2];

  

  if ((param_1 != 0) && (((obj->flags /* *(uint *)(param_1 + 0xd8) */) & 0xc000) == 0)) {

    if ((*(uint *)(param_1 + 0x1c8) & 0x10) != 0) {

      local_8[0] = 0;

      local_8[1] = 0;

      bVar4 = true;

      iVar1 = 2;

      piVar2 = local_8;

      piVar3 = (int *)(param_1 + 0x208);

      do {

        if (iVar1 == 0) break;

        iVar1 = iVar1 + -1;

        bVar4 = *piVar2 == *piVar3;

        piVar2 = piVar2 + 1;

        piVar3 = piVar3 + 1;

      } while (bVar4);

      if (bVar4) {

        return;

      }

      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xffffffef;

    }

    *(undefined4 *)(param_1 + 0x11c) = (obj->vel[1] /* *(undefined4 *)(param_1 + 0x10c) */);

    *(undefined4 *)(param_1 + 0x120) = (obj->vel[2] /* *(undefined4 *)(param_1 + 0x110) */);

    *(undefined4 *)(param_1 + 0x124) = (obj->vel[3] /* *(undefined4 *)(param_1 + 0x114) */);

    *(undefined4 *)(param_1 + 0x118) = (obj->vel[0] /* *(undefined4 *)(param_1 + 0x108) */);

    cspec_update_dispatch(param_1);

  }

  return;

}





