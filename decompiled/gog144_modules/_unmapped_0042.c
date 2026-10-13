/* Giants 1.449 — module _unmapped_0042
 * 129 functions (59 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0042.c(pp) (assert-string evidence)
 */

/* ===== FUN_00420090 @ 0x00420090 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



bool FUN_00420090(uint param_1,undefined4 param_2)



{

  switch(param_1) {

  case 0x65:

    param_1 = 1;

    break;

  case 0x66:

    param_1 = 2;

    break;

  case 0x67:

    param_1 = 4;

    break;

  case 0x68:

    param_1 = 8;

    break;

  case 0x69:

    param_1 = 0x10;

    break;

  case 0x6a:

    param_1 = 0x20;

    break;

  case 0x6b:

    param_1 = 0x40;

    break;

  case 0x6c:

    param_1 = 0x80;

    break;

  case 0x6d:

    return 0 < DAT_005dd224;

  case 0x6e:

    return DAT_005dd224 < 0;

  }

  switch(param_2) {

  case 0:

    if ((_DAT_005dd238 & param_1) == 0) {

      return true;

    }

    break;

  case 1:

    if ((_DAT_005dd238 & param_1) != 0) {

      return true;

    }

    break;

  case 2:

    if ((_DAT_005dd23c & param_1) != 0) {

      return true;

    }

    break;

  case 3:

    if ((_DAT_005dd240 & param_1) != 0) {

      return true;

    }

  }

  return false;

}

/* ===== FUN_00420180 @ 0x00420180 ===== */
undefined4 FUN_00420180(int param_1,undefined4 param_2)



{

  switch(param_2) {

  case 0:

    if (((&DAT_005dd100)[(&DAT_005845d0)[param_1 * 10]] &

        1 << ((byte)(&DAT_005845d4)[param_1 * 10] & 0x1f)) != 0) {

      return 1;

    }

    break;

  case 1:

    if (((&DAT_005dd0e0)[(&DAT_005845d0)[param_1 * 10]] &

        1 << ((byte)(&DAT_005845d4)[param_1 * 10] & 0x1f)) != 0) {

      return 1;

    }

    break;

  case 2:

    if (((&DAT_005dd140)[(&DAT_005845d0)[param_1 * 10]] &

        1 << ((byte)(&DAT_005845d4)[param_1 * 10] & 0x1f)) != 0) {

      return 1;

    }

    break;

  case 3:

    if (((&DAT_005dd120)[(&DAT_005845d0)[param_1 * 10]] &

        1 << ((byte)(&DAT_005845d4)[param_1 * 10] & 0x1f)) != 0) {

      return 1;

    }

  }

  return 0;

}

/* ===== FUN_00420260 @ 0x00420260 ===== */
/* PS2 candidate: player_can_use_ammo__FP6OBJECTi (conf 0.408) */



undefined4 FUN_00420260(void)



{

  int iVar1;

  undefined4 uVar2;

  

  iVar1 = FUN_004a6160(DAT_00632a88);

  uVar2 = DAT_00555a20;

  if (iVar1 == 0) {

    uVar2 = DAT_00555a24;

  }

  return uVar2;

}

/* ===== FUN_00420280 @ 0x00420280 ===== */
void FUN_00420280(int param_1,int param_2,int param_3,int param_4)



{

  int iVar1;

  int *piVar2;

  undefined4 uVar3;

  

  if (DAT_00633104 == 0) {

    return;

  }

  if (DAT_0058c5e0 != 0) {

    DAT_00632adf = 1;

    if (((param_2 == 1) && (param_4 != 1)) || ((param_1 == -1 && (param_3 != -1)))) {

      FUN_0040d370();

      return;

    }

    if ((param_2 != -1) || (param_4 == -1)) {

      if (param_1 != 1) {

        DAT_00632adf = 1;

        return;

      }

      if (param_3 == 1) {

        DAT_00632adf = 1;

        return;

      }

    }

    FUN_0040d280();

    return;

  }

  DAT_00632adf = 0;

  iVar1 = FUN_004a6160(DAT_00632a88);

  if (iVar1 == 0) {

    iVar1 = FUN_004a61a0(DAT_00632a88);

    if (iVar1 != 0) {

      if (param_1 == 1) {

        if (param_2 == 1) {

          DAT_00555a24 = 0;

          return;

        }

        DAT_00555a24 = (param_2 != 0) + 1;

        return;

      }

      if (param_1 != -1) {

        return;

      }

      if (param_2 == 1) {

        DAT_00555a24 = 3;

        return;

      }

      DAT_00555a24 = (param_2 != 0) + 4;

      return;

    }

    iVar1 = FUN_004a6180(DAT_00632a88);

    if (iVar1 == 0) {

      return;

    }

    if (param_1 != 1) {

      if (param_1 != -1) {

        if (param_2 != 1) {

          return;

        }

        *(uint *)(DAT_00632a88 + 0x20c) = *(uint *)(DAT_00632a88 + 0x20c) | 0x1000;

        return;

      }

      if (param_2 != 1) {

        if (param_2 != 0) {

          return;

        }

        *(uint *)(DAT_00632a88 + 0x20c) = *(uint *)(DAT_00632a88 + 0x20c) | 0x4000;

        return;

      }

      *(uint *)(DAT_00632a88 + 0x20c) = *(uint *)(DAT_00632a88 + 0x20c) | 0x2000;

      return;

    }

    if (param_2 == 1) {

      *(uint *)(DAT_00632a88 + 0x20c) = *(uint *)(DAT_00632a88 + 0x20c) | 0x800;

      return;

    }

    if (param_2 != 0) {

      return;

    }

    *(uint *)(DAT_00632a88 + 0x20c) = *(uint *)(DAT_00632a88 + 0x20c) | 0x400;

    return;

  }

  if (param_1 == 1) {

    DAT_00632aeb = 0;

    if (param_2 == 1) {

      iVar1 = FUN_004a6160(DAT_00632a88);

      if (iVar1 == 0) {

        return;

      }

      iVar1 = FUN_00457fb0(DAT_00632a88,1);

      if (iVar1 == -1) {

        return;

      }

      FUN_00457fe0(DAT_00632a88,1);

      return;

    }

    if (param_2 != -1) {

      iVar1 = FUN_004a6160(DAT_00632a88);

      if (iVar1 == 0) {

        return;

      }

      iVar1 = FUN_00457fb0(DAT_00632a88,2);

      if (iVar1 == -1) {

        return;

      }

      FUN_00457fe0(DAT_00632a88,2);

      return;

    }

    iVar1 = FUN_004a6160(DAT_00632a88);

    if (iVar1 == 0) {

      return;

    }

    iVar1 = FUN_00457fb0(DAT_00632a88,3);

    if (iVar1 == -1) {

      return;

    }

    FUN_00457fe0(DAT_00632a88,3);

    return;

  }

  if (param_1 != -1) {

    if (param_2 == 1) {

      iVar1 = FUN_004a6160(DAT_00632a88);

      if (iVar1 == 0) {

        DAT_00632aec = 0;

        return;

      }

      iVar1 = FUN_004586e0(DAT_00632a88);

      if (iVar1 == -1) {

        DAT_00632aec = 0;

        return;

      }

      if (DAT_00632aec != '\0') {

        DAT_00632aec = 0;

        DAT_00632aeb = 1;

        return;

      }

      DAT_00555a20 = FUN_004586e0(DAT_00632a88);

    }

    else if (param_2 == -1) {

      iVar1 = FUN_004a6160(DAT_00632a88);

      if (iVar1 == 0) {

        DAT_00632aec = 0;

        return;

      }

      iVar1 = FUN_0047f730(DAT_00632a88);

      if (iVar1 != 0) {

        DAT_00632aeb = DAT_00632aec != '\0';

        DAT_00632aec = 0;

        return;

      }

      if ((*(uint *)(DAT_00632a88 + 0xdc) & 0x800000) == 0) {

        DAT_00632aec = 0;

        return;

      }

      if (DAT_00632aec == '\0') {

        DAT_00555a20 = 0xfffffffe;

        DAT_00632aeb = 0;

        piVar2 = DAT_00632d98;

        if (DAT_00632d98 == (int *)0x0) {

          DAT_00555a20 = 0xfffffffe;

          DAT_00632aeb = 0;

          DAT_00632aec = 0;

          return;

        }

        while( true ) {

          iVar1 = piVar2[3];

          if ((((*(int *)(iVar1 + 0x274) == DAT_00632a88) && (*(int *)(iVar1 + 4) == 0xb)) &&

              (*(int *)(*(int *)(iVar1 + 0x100) + 0x54) != 0)) &&

             ((*(byte *)(iVar1 + 0xe1) & 2) == 0)) break;

          piVar2 = (int *)*piVar2;

          if (piVar2 == (int *)0x0) {

            DAT_00632aec = 0;

            return;

          }

        }

        DAT_00632aec = 0;

        DAT_00555a20 = *(int *)(*(int *)(iVar1 + 0x100) + 0x54) + 0x30;

        return;

      }

      DAT_00632aeb = 1;

      DAT_00632aec = 0;

      return;

    }

    DAT_00632aeb = 0;

    DAT_00632aec = 0;

    return;

  }

  if (param_2 == 1) {

    iVar1 = FUN_004a6160(DAT_00632a88);

    if (iVar1 == 0) {

      DAT_00632aeb = 0;

      DAT_00632aec = 0;

      return;

    }

    iVar1 = FUN_004582d0(DAT_00632a88,0);

    if (iVar1 == -1) {

      DAT_00632aeb = 0;

      DAT_00632aec = 0;

      return;

    }

    if (DAT_00632aec != '\0') {

      uVar3 = 0;

      goto LAB_00420491;

    }

    uVar3 = 0;

  }

  else if (param_2 == -1) {

    iVar1 = FUN_004a6160(DAT_00632a88);

    if (iVar1 == 0) {

      DAT_00632aeb = 0;

      DAT_00632aec = 0;

      return;

    }

    iVar1 = FUN_004582d0(DAT_00632a88,2);

    if (iVar1 == -1) {

      DAT_00632aeb = 0;

      DAT_00632aec = 0;

      return;

    }

    if (DAT_00632aec != '\0') {

      uVar3 = 2;

LAB_00420491:

      FUN_004582a0(DAT_00632a88,uVar3,0xffffffff);

      DAT_00632aec = 0;

      DAT_00632aeb = 0;

      DAT_00555a20 = 0xffffffff;

      return;

    }

    uVar3 = 2;

  }

  else {

    iVar1 = FUN_004a6160(DAT_00632a88);

    if (iVar1 == 0) {

      DAT_00632aeb = 0;

      DAT_00632aec = 0;

      return;

    }

    iVar1 = FUN_004582d0(DAT_00632a88,1);

    if (iVar1 == -1) {

      DAT_00632aeb = 0;

      DAT_00632aec = 0;

      return;

    }

    if (DAT_00632aec != '\0') {

      uVar3 = 1;

      goto LAB_00420491;

    }

    uVar3 = 1;

  }

  DAT_00555a20 = FUN_004582d0(DAT_00632a88,uVar3);

  DAT_00632aec = 0;

  DAT_00632aeb = 0;

  return;

}

/* ===== FUN_00420780 @ 0x00420780 ===== */
void FUN_00420780(int param_1,undefined4 param_2)



{

  int iVar1;

  

  switch(param_2) {

  case 0x20:

    if (DAT_00633104 == 0) {

      DAT_00632adf = 1;

      return;

    }

    DAT_0058c5e0 = (uint)(DAT_0058c5e0 == 0);

    return;

  case 0x21:

    FUN_0040d370();

    return;

  case 0x22:

    if (DAT_00632e74 == 0) {

      iVar1 = FUN_0040cec0();

      if (iVar1 == 0) {

        FUN_0040d130(1);

        comm_0051a130();

        return;

      }

      FUN_0040d130(2);

      comm_0051a130();

      return;

    }

    break;

  case 0x23:

    DAT_00632ae6 = 1;

    return;

  case 0x24:

    *(undefined1 *)(param_1 + 2) = 0x20;

    return;

  case 0x25:

    *(undefined1 *)(param_1 + 2) = 0xe0;

    return;

  case 0x26:

    *(undefined1 *)(param_1 + 3) = 0x20;

    return;

  case 0x27:

    *(undefined1 *)(param_1 + 3) = 0xe0;

    return;

  case 0x28:

    DAT_00632ae8 = 1;

    return;

  case 0x29:

    DAT_00632ae9 = 1;

    break;

  case 0x2a:

    DAT_00632aeb = 1;

    return;

  case 0x2b:

    DAT_00632aec = 1;

    return;

  }

  return;

}

/* ===== FUN_00420890 @ 0x00420890 ===== */
undefined4 FUN_00420890(void)



{

  byte bVar1;

  int iVar2;

  

  iVar2 = FUN_004a6180(DAT_00632a88);

  if (iVar2 == 0) {

    iVar2 = FUN_004a6160(DAT_00632a88);

    if (iVar2 == 0) {

      iVar2 = FUN_004a61a0(DAT_00632a88);

      iVar2 = 3 - (uint)(iVar2 != 0);

    }

    else {

      iVar2 = 1;

    }

  }

  else {

    iVar2 = 0;

  }

  bVar1 = (&DAT_005843c0)[iVar2 * 0x58];

  iVar2 = (int)(char)(&DAT_005843c1)[iVar2 * 0x58];

  if (bVar1 < 0x65) {

    iVar2 = FUN_00420180(bVar1,iVar2);

  }

  else if (bVar1 < 0x6f) {

    iVar2 = FUN_00420090(bVar1,iVar2);

  }

  else {

    iVar2 = FUN_0041fed0(bVar1,iVar2);

  }

  if (iVar2 == 0) {

    return 0;

  }

  return 1;

}

/* ===== FUN_00420930 @ 0x00420930 ===== */
undefined4 FUN_00420930(void)



{

  byte bVar1;

  int iVar2;

  

  iVar2 = FUN_004a6180(DAT_00632a88);

  if (iVar2 == 0) {

    iVar2 = FUN_004a6160(DAT_00632a88);

    if (iVar2 == 0) {

      iVar2 = FUN_004a61a0(DAT_00632a88);

      iVar2 = 3 - (uint)(iVar2 != 0);

    }

    else {

      iVar2 = 1;

    }

  }

  else {

    iVar2 = 0;

  }

  bVar1 = (&DAT_005843c2)[iVar2 * 0x58];

  iVar2 = (int)(char)(&DAT_005843c3)[iVar2 * 0x58];

  if (bVar1 < 0x65) {

    iVar2 = FUN_00420180(bVar1,iVar2);

  }

  else if (bVar1 < 0x6f) {

    iVar2 = FUN_00420090(bVar1,iVar2);

  }

  else {

    iVar2 = FUN_0041fed0(bVar1,iVar2);

  }

  if (iVar2 == 0) {

    return 0;

  }

  return 1;

}

/* ===== FUN_004209d0 @ 0x004209D0 ===== */
undefined4 FUN_004209d0(void)



{

  byte bVar1;

  int iVar2;

  

  iVar2 = FUN_004a6180(DAT_00632a88);

  if (iVar2 == 0) {

    iVar2 = FUN_004a6160(DAT_00632a88);

    if (iVar2 == 0) {

      iVar2 = FUN_004a61a0(DAT_00632a88);

      iVar2 = 3 - (uint)(iVar2 != 0);

    }

    else {

      iVar2 = 1;

    }

  }

  else {

    iVar2 = 0;

  }

  bVar1 = (&DAT_005843c4)[iVar2 * 0x58];

  iVar2 = (int)(char)(&DAT_005843c5)[iVar2 * 0x58];

  if (bVar1 < 0x65) {

    iVar2 = FUN_00420180(bVar1,iVar2);

  }

  else if (bVar1 < 0x6f) {

    iVar2 = FUN_00420090(bVar1,iVar2);

  }

  else {

    iVar2 = FUN_0041fed0(bVar1,iVar2);

  }

  if (iVar2 == 0) {

    return 0;

  }

  return 1;

}

/* ===== FUN_00420a70 @ 0x00420A70 ===== */
undefined4 FUN_00420a70(void)



{

  byte bVar1;

  int iVar2;

  

  iVar2 = FUN_004a6180(DAT_00632a88);

  if (iVar2 == 0) {

    iVar2 = FUN_004a6160(DAT_00632a88);

    if (iVar2 == 0) {

      iVar2 = FUN_004a61a0(DAT_00632a88);

      iVar2 = 3 - (uint)(iVar2 != 0);

    }

    else {

      iVar2 = 1;

    }

  }

  else {

    iVar2 = 0;

  }

  bVar1 = (&DAT_005843c6)[iVar2 * 0x58];

  iVar2 = (int)(char)(&DAT_005843c7)[iVar2 * 0x58];

  if (bVar1 < 0x65) {

    iVar2 = FUN_00420180(bVar1,iVar2);

  }

  else if (bVar1 < 0x6f) {

    iVar2 = FUN_00420090(bVar1,iVar2);

  }

  else {

    iVar2 = FUN_0041fed0(bVar1,iVar2);

  }

  if (iVar2 == 0) {

    return 0;

  }

  return 1;

}

/* ===== FUN_00420b10 @ 0x00420B10 ===== */
undefined * FUN_00420b10(int param_1,int param_2,uint param_3)



{

  int iVar1;

  

  if (param_1 == 2) {

    if (param_2 != 0) {

      iVar1 = 0;

      for (; (param_3 & 1) == 0; param_3 = (int)param_3 >> 1) {

        iVar1 = iVar1 + 1;

      }

      return &DAT_005845d8 + (uint)(byte)(&DAT_005843d0)[iVar1 * 2] * 0x28;

    }

    return &DAT_005845d8 + (uint)(byte)(&DAT_005843d0)[param_3 * 2] * 0x28;

  }

  if (param_1 == 3) {

    if (param_2 != 0) {

      iVar1 = 0;

      for (; (param_3 & 1) == 0; param_3 = (int)param_3 >> 1) {

        iVar1 = iVar1 + 1;

      }

      return &DAT_005845d8 + (uint)(byte)(&DAT_00584378)[iVar1 * 2] * 0x28;

    }

    return &DAT_005845d8 + (uint)(byte)(&DAT_00584378)[param_3 * 2] * 0x28;

  }

  if (param_1 != 1) {

    return (undefined *)0x0;

  }

  if (param_2 != 0) {

    iVar1 = 0;

    for (; (param_3 & 1) == 0; param_3 = (int)param_3 >> 1) {

      iVar1 = iVar1 + 1;

    }

    return &DAT_005845d8 + (uint)(byte)(&DAT_00584428)[iVar1 * 2] * 0x28;

  }

  return &DAT_005845d8 + (uint)(byte)(&DAT_00584428)[param_3 * 2] * 0x28;

}

/* ===== input_mapping_init @ 0x00420C10 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void input_mapping_init(int param_1)



{

  undefined4 uVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  undefined4 *puVar6;

  bool bVar7;

  char *pcVar8;

  undefined1 local_1e0 [64];

  undefined1 local_1a0;

  undefined1 local_19e;

  undefined1 local_19c;

  undefined1 local_19a;

  undefined1 local_198;

  undefined1 local_196;

  undefined1 local_194;

  undefined1 local_192;

  undefined1 local_190;

  undefined1 local_18e;

  undefined1 local_18c;

  undefined1 local_18a;

  undefined1 local_188 [64];

  undefined1 local_148;

  undefined1 local_146;

  undefined1 local_144;

  undefined1 local_142;

  undefined1 local_140;

  undefined1 local_13e;

  undefined1 local_13c;

  undefined1 local_13a;

  undefined1 local_138;

  undefined1 local_136;

  undefined1 local_134;

  undefined1 local_132;

  undefined1 local_130 [64];

  undefined1 local_f0;

  undefined1 local_ee;

  undefined1 local_ec;

  undefined1 local_ea;

  undefined1 local_e8;

  undefined1 local_e6;

  undefined1 local_e4;

  undefined1 local_e2;

  undefined1 local_e0;

  undefined1 local_de;

  undefined1 local_dc;

  undefined1 local_80 [128];

  

  if (param_1 == -1) {

    puVar6 = (undefined4 *)&DAT_00584378;

    for (iVar2 = 0x58; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar6 = 0xffffffff;

      puVar6 = puVar6 + 1;

    }

  }

  else if (param_1 != 0) {

    DAT_0063322c = 0;

    _DAT_00555a1c = 0x3f000000;

    _DAT_00555a18 = 0x3f800000;

  }

  if (DAT_00633104 == 0) {

    pcVar8 = s_keydefmapping_sav_00555e08;

  }

  else {

    pcVar8 = s_joydefmapping_sav_00555e1c;

  }

  FUN_00542f27(local_80,pcVar8);

  iVar2 = BinFileSeek_2(local_80,&DAT_00555e04);

  bVar7 = iVar2 != 0;

  if (bVar7) {

    FUN_005438c9(local_1e0,0x160,1,iVar2);

    editor_0054384c(iVar2);

  }

  if ((param_1 == 3) || (param_1 == -1)) {

    if (bVar7) {

      uVar3 = 8;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 8;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      DAT_00584378 = local_1e0[0];

      uVar3 = 4;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 4;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      iVar2 = 2;

      iVar4 = 0;

      do {

        iVar2 = iVar2 >> 1;

        iVar4 = iVar4 + 1;

      } while ((char)iVar2 == '\0');

      iVar5 = 2;

      iVar2 = 0;

      do {

        iVar5 = iVar5 >> 1;

        iVar2 = iVar2 + 1;

      } while ((char)iVar5 == '\0');

      (&DAT_00584378)[iVar2 * 2] = local_1e0[iVar4 * 2];

      uVar3 = 0x200;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x200;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x200000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x200000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x400000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x400000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x800000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x800000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x20;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x20;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x400;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x400;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x800;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x800;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x1000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x1000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x2000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x2000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x4000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x4000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x40;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x40;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x80;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x80;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x100;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x100;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x10;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x10;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x8000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x8000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x10000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x10000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x20000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x20000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x40000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x40000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x80000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x80000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      uVar3 = 0x100000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x100000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

      DAT_005843b8 = local_1a0;

      DAT_005843bc = local_19c;

      DAT_005843ba = local_19e;

      DAT_005843be = local_19a;

      DAT_005843c2 = local_196;

      DAT_005843c0 = local_198;

      DAT_005843c4 = local_194;

      DAT_005843cc = local_18c;

      DAT_005843c6 = local_192;

      DAT_005843c8 = local_190;

      DAT_005843ce = local_18a;

      DAT_005843ca = local_18e;

      uVar3 = 0x1000000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x1000000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar4 * 2] = local_1e0[iVar2 * 2];

    }

    else {

      uVar3 = 8;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 10;

      DAT_00584378 = 0x2a;

      uVar3 = 4;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x36;

      iVar4 = 2;

      iVar2 = 0;

      do {

        iVar4 = iVar4 >> 1;

        iVar2 = iVar2 + 1;

      } while ((char)iVar4 == '\0');

      (&DAT_00584378)[iVar2 * 2] = 0x37;

      uVar3 = 0x200;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x2c;

      uVar3 = 0x200000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 7;

      uVar3 = 0x400000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 1;

      uVar3 = 0x800000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x15;

      uVar3 = 0x20;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x2d;

      uVar3 = 0x400;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x1b;

      uVar3 = 0x800;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x1c;

      uVar3 = 0x1000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x1d;

      uVar3 = 0x2000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x1e;

      uVar3 = 0x4000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x1f;

      uVar3 = 0x40;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x10;

      uVar3 = 0x80;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x28;

      uVar3 = 0x100;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x65;

      uVar3 = 0x10;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x66;

      uVar3 = 0x8000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 5;

      uVar3 = 0x10000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x65;

      uVar3 = 0x20000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x66;

      uVar3 = 0x40000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x16;

      uVar3 = 0x80000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0;

      uVar3 = 0x100000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 3;

      DAT_005843b8 = 4;

      DAT_005843ba = 0x19;

      DAT_005843bc = 0x11;

      DAT_005843be = 2;

      DAT_005843c0 = 0x16;

      DAT_005843c2 = 0x12;

      DAT_005843c4 = 0;

      DAT_005843c6 = 3;

      DAT_005843cc = 0x27;

      DAT_005843c8 = 0x13;

      DAT_005843ca = 0x18;

      DAT_005843ce = 9;

      uVar3 = 0x1000000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584378)[iVar2 * 2] = 0x17;

    }

    uVar3 = 8;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpDropSpell_00555df4);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 8;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar1 = FUN_00507b00(s_InpSelectSpell_00555de0);

    FUN_00542f27(&DAT_00586dd0,&DAT_00555df0,uVar1);

    DAT_00584379 = 1;

    uVar3 = 4;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpSelectSpellBkwd_00555dcc);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 4;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    iVar2 = 2;

    iVar4 = 0;

    do {

      iVar2 = iVar2 >> 1;

      iVar4 = iVar4 + 1;

    } while ((char)iVar2 == '\0');

    uVar1 = FUN_00507b00(s_InpSelectSpellFwd_00555db8);

    FUN_00542f27(&DAT_00586dd0 + iVar4 * 0x80,&DAT_00555df0,uVar1);

    iVar4 = 2;

    iVar2 = 0;

    do {

      iVar4 = iVar4 >> 1;

      iVar2 = iVar2 + 1;

    } while ((char)iVar4 == '\0');

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x200;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpJump_00555db0);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x200;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 1;

    uVar3 = 0x200000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpHealth_00555da4);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x200000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x400000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpMine_00555d9c);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x400000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x800000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpFlare_00555d90);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x800000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x20;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpCastSpell_00555d80);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x20;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x400;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpSelectSpell1_00555d70);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x400;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x800;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpSelectSpell2_00555d60);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x800;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x1000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpSelectSpell3_00555d50);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x1000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x2000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpSelectSpell4_00555d40);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x2000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x4000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpSelectSpell5_00555d30);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x4000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x40;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpCycleWeaponFwd_00555d1c);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x40;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x80;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpCycleWeaponBkwd_00555d08);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x80;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x100;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpFire_00555d00);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x100;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x10;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpTurbo_00555cf4);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x10;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x8000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpJetSkiCameraMode_00555ce0);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x8000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 1;

    uVar3 = 0x10000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpJetSkiFire_00555cd0);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x10000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 1;

    uVar3 = 0x20000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpJetSkiTurbo_00555cc0);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x20000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x40000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpJetSkiForward_00555cac);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x40000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 1;

    uVar3 = 0x80000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpJetSkiLeft_00555c9c);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x80000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 1;

    uVar3 = 0x100000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpJetSkiRight_00555c8c);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x100000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 1;

    uVar1 = FUN_00507b00(s_InpSniperZoomSnap_00555c78);

    FUN_00542f27(&DAT_00587dd0,&DAT_00555df0,uVar1);

    DAT_005843b9 = 1;

    uVar1 = FUN_00507b00(s_InpSniperZoomInc_00555c64);

    FUN_00542f27(&DAT_00587e50,&DAT_00555df0,uVar1);

    DAT_005843bb = 3;

    uVar1 = FUN_00507b00(s_InpToggle1stPerson_00555c50);

    FUN_00542f27(&DAT_00587ed0,&DAT_00555df0,uVar1);

    DAT_005843bd = 3;

    uVar1 = FUN_00507b00(s_InpMapMode_00555c44);

    FUN_00542f27(&DAT_00587f50,&DAT_00555df0,uVar1);

    DAT_005843bf = 3;

    uVar1 = FUN_00507b00(s_InpRunFwd_00555c38);

    FUN_00542f27(&DAT_00587fd0,&DAT_00555df0,uVar1);

    DAT_005843c1 = 1;

    uVar1 = FUN_00507b00(s_InpRunBkwd_00555c2c);

    FUN_00542f27(&DAT_00588050,&DAT_00555df0,uVar1);

    DAT_005843c3 = 1;

    uVar1 = FUN_00507b00(s_InpSideLeft_00555c20);

    FUN_00542f27(&DAT_005880d0,&DAT_00555df0,uVar1);

    DAT_005843c5 = 1;

    uVar1 = FUN_00507b00(s_InpSideRight_00555c10);

    FUN_00542f27(&DAT_00588150,&DAT_00555df0,uVar1);

    DAT_005843c7 = 1;

    uVar1 = FUN_00507b00(s_InpEscape2_00555c04);

    FUN_00542f27(&DAT_005882d0,&DAT_00555df0,uVar1);

    DAT_005843cd = 3;

    uVar1 = FUN_00507b00(s_InpChatAll_00555bf8);

    FUN_00542f27(&DAT_005881d0,&DAT_00555df0,uVar1);

    DAT_005843c9 = 3;

    uVar1 = FUN_00507b00(s_InpChatTeam_00555bec);

    FUN_00542f27(&DAT_00588250,&DAT_00555df0,uVar1);

    DAT_005843cb = 3;

    uVar1 = FUN_00507b00(s_InpDropCurWeapon_00555bd8);

    FUN_00542f27(&DAT_00588350,&DAT_00555df0,uVar1);

    DAT_005843cf = 3;

    uVar3 = 0x1000000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpActivatePartyHouse_00555bc0);

    FUN_00542f27(&DAT_00586dd0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x1000000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584379)[iVar2 * 2] = 3;

    uVar3 = 0x100;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    iVar4 = FUN_00423470(0x2000000);

    (&DAT_00584378)[iVar4 * 2] = (&DAT_00584378)[iVar2 * 2];

    iVar2 = FUN_00423470(0x2000000);

    (&DAT_00584379)[iVar2 * 2] = 1;

    if (param_1 != -1) goto LAB_00421d1e;

  }

  else {

LAB_00421d1e:

    if (param_1 != 2) goto LAB_004228ea;

  }

  if (bVar7) {

    uVar3 = 0x1000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar3 = 0x1000;

    iVar4 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar4 * 2] = local_188[iVar2 * 2];

    DAT_005843d0 = local_188[0];

    uVar3 = 0x2000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar3 = 0x2000;

    iVar4 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar4 * 2] = local_188[iVar2 * 2];

    uVar3 = 0x4000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar3 = 0x4000;

    iVar4 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar4 * 2] = local_188[iVar2 * 2];

    uVar3 = 0x8000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar3 = 0x8000;

    iVar4 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar4 * 2] = local_188[iVar2 * 2];

    iVar2 = 2;

    iVar4 = 0;

    do {

      iVar2 = iVar2 >> 1;

      iVar4 = iVar4 + 1;

    } while ((char)iVar2 == '\0');

    iVar5 = 2;

    iVar2 = 0;

    do {

      iVar5 = iVar5 >> 1;

      iVar2 = iVar2 + 1;

    } while ((char)iVar5 == '\0');

    (&DAT_005843d0)[iVar2 * 2] = local_188[iVar4 * 2];

    uVar3 = 4;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar3 = 4;

    iVar4 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar4 * 2] = local_188[iVar2 * 2];

    uVar3 = 8;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar3 = 8;

    iVar4 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar4 * 2] = local_188[iVar2 * 2];

    uVar3 = 0x10;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar3 = 0x10;

    iVar4 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar4 * 2] = local_188[iVar2 * 2];

    uVar3 = 0x20;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar3 = 0x20;

    iVar4 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar4 * 2] = local_188[iVar2 * 2];

    uVar3 = 0x400;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar3 = 0x400;

    iVar4 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar4 * 2] = local_188[iVar2 * 2];

    uVar3 = 0x800;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar3 = 0x800;

    iVar4 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar4 * 2] = local_188[iVar2 * 2];

    uVar3 = 0x40;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar3 = 0x40;

    iVar4 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar4 * 2] = local_188[iVar2 * 2];

    uVar3 = 0x80;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar3 = 0x80;

    iVar4 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar4 * 2] = local_188[iVar2 * 2];

    uVar3 = 0x100;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar3 = 0x100;

    iVar4 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar4 * 2] = local_188[iVar2 * 2];

    uVar3 = 0x200;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar3 = 0x200;

    iVar4 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar4 * 2] = local_188[iVar2 * 2];

    DAT_00584410 = local_148;

    DAT_00584412 = local_146;

    DAT_00584414 = local_144;

    DAT_00584416 = local_142;

    DAT_00584418 = local_140;

    DAT_0058441a = local_13e;

    DAT_0058441c = local_13c;

    DAT_0058441e = local_13a;

    DAT_00584424 = local_134;

    DAT_00584426 = local_132;

    DAT_00584420 = local_138;

    DAT_00584422 = local_136;

  }

  else {

    uVar3 = 0x1000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = 0x2b;

    DAT_005843d0 = 0x65;

    uVar3 = 0x2000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = 0x65;

    uVar3 = 0x4000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = 0x1c;

    uVar3 = 0x8000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = 0x66;

    iVar4 = 2;

    iVar2 = 0;

    do {

      iVar4 = iVar4 >> 1;

      iVar2 = iVar2 + 1;

    } while ((char)iVar4 == '\0');

    (&DAT_005843d0)[iVar2 * 2] = 5;

    uVar3 = 4;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = 0x2a;

    uVar3 = 8;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = 0x17;

    uVar3 = 0x10;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = 0x10;

    uVar3 = 0x20;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = 0x28;

    uVar3 = 0x400;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = 0x66;

    uVar3 = 0x800;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = 0x2d;

    uVar3 = 0x40;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = 7;

    uVar3 = 0x80;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = 6;

    uVar3 = 0x100;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = 1;

    uVar3 = 0x200;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = 0x15;

    DAT_00584410 = 4;

    DAT_00584412 = 0x19;

    DAT_00584414 = 0x11;

    DAT_00584416 = 2;

    DAT_00584418 = 0x16;

    DAT_0058441a = 0x12;

    DAT_0058441c = 0;

    DAT_0058441e = 3;

    DAT_00584424 = 0x27;

    DAT_00584426 = 9;

    DAT_00584420 = 0x13;

    DAT_00584422 = 0x18;

  }

  uVar3 = 0x1000;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  uVar1 = FUN_00507b00(s_InpDiscipleMode_00555bb0);

  FUN_00542f27(&DAT_005883d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

  iVar2 = 0;

  uVar3 = 0x1000;

  if (DAT_00633104 == 0) {

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d1)[iVar2 * 2] = 1;

  }

  else {

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_005843d1)[iVar2 * 2] = 3;

  }

  uVar1 = FUN_00507b00(s_InpFire_00555d00);

  FUN_00542f27(&DAT_005883d0,&DAT_00555df0,uVar1);

  DAT_005843d1 = 1;

  uVar3 = 0x2000;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  uVar1 = FUN_00507b00(s_InpDiscAttack_00555ba0);

  FUN_00542f27(&DAT_005883d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

  uVar3 = 0x2000;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  (&DAT_005843d1)[iVar2 * 2] = 3;

  uVar3 = 0x4000;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  uVar1 = FUN_00507b00(s_InpDiscRecall_00555b90);

  FUN_00542f27(&DAT_005883d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

  uVar3 = 0x4000;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  (&DAT_005843d1)[iVar2 * 2] = 3;

  uVar3 = 0x8000;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  uVar1 = FUN_00507b00(s_InpDiscGoto_00555b84);

  FUN_00542f27(&DAT_005883d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

  uVar3 = 0x8000;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  (&DAT_005843d1)[iVar2 * 2] = 3;

  iVar2 = 2;

  iVar4 = 0;

  do {

    iVar2 = iVar2 >> 1;

    iVar4 = iVar4 + 1;

  } while ((char)iVar2 == '\0');

  uVar1 = FUN_00507b00(s_InpGyroCameraMode_00555b70);

  FUN_00542f27(&DAT_005883d0 + iVar4 * 0x80,&DAT_00555df0,uVar1);

  iVar4 = 2;

  iVar2 = 0;

  do {

    iVar4 = iVar4 >> 1;

    iVar2 = iVar2 + 1;

  } while ((char)iVar4 == '\0');

  (&DAT_005843d1)[iVar2 * 2] = 1;

  uVar3 = 4;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  uVar1 = FUN_00507b00(s_InpActivateBackItem_00555b5c);

  FUN_00542f27(&DAT_005883d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

  uVar3 = 4;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  (&DAT_005843d1)[iVar2 * 2] = 3;

  uVar3 = 8;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  uVar1 = FUN_00507b00(s_InpActivatePartyHouse_00555bc0);

  FUN_00542f27(&DAT_005883d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

  uVar3 = 8;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  (&DAT_005843d1)[iVar2 * 2] = 3;

  uVar3 = 0x10;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  uVar1 = FUN_00507b00(s_InpWeaponCycleWepFwd_00555b44);

  FUN_00542f27(&DAT_005883d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

  uVar3 = 0x10;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  (&DAT_005843d1)[iVar2 * 2] = 3;

  uVar3 = 0x20;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  uVar1 = FUN_00507b00(s_InpWeaponCycleWepBkwd_00555b2c);

  FUN_00542f27(&DAT_005883d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

  uVar3 = 0x20;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  (&DAT_005843d1)[iVar2 * 2] = 3;

  uVar3 = 0x400;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  uVar1 = FUN_00507b00(s_InpThrust_00555b20);

  FUN_00542f27(&DAT_005883d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

  uVar3 = 0x400;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  (&DAT_005843d1)[iVar2 * 2] = 1;

  uVar3 = 0x800;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  uVar1 = FUN_00507b00(s_InpNitro_00555b14);

  FUN_00542f27(&DAT_005883d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

  uVar3 = 0x800;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  (&DAT_005843d1)[iVar2 * 2] = 1;

  uVar3 = 0x40;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  uVar1 = FUN_00507b00(s_InpHealth_00555da4);

  FUN_00542f27(&DAT_005883d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

  uVar3 = 0x40;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  (&DAT_005843d1)[iVar2 * 2] = 3;

  uVar3 = 0x80;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  uVar1 = FUN_00507b00(s_InpGrenade_00555b08);

  FUN_00542f27(&DAT_005883d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

  uVar3 = 0x80;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  (&DAT_005843d1)[iVar2 * 2] = 3;

  uVar3 = 0x100;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  uVar1 = FUN_00507b00(s_InpMine_00555d9c);

  FUN_00542f27(&DAT_005883d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

  uVar3 = 0x100;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  (&DAT_005843d1)[iVar2 * 2] = 3;

  uVar3 = 0x200;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  uVar1 = FUN_00507b00(s_InpFlare_00555d90);

  FUN_00542f27(&DAT_005883d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

  uVar3 = 0x200;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  (&DAT_005843d1)[iVar2 * 2] = 3;

  uVar1 = FUN_00507b00(s_InpSniperZoomSnap_00555c78);

  FUN_00542f27(&DAT_005893d0,&DAT_00555df0,uVar1);

  DAT_00584411 = (DAT_00633104 != 0) * '\x02' + '\x01';

  uVar1 = FUN_00507b00(s_InpSniperZoomInc_00555c64);

  FUN_00542f27(&DAT_00589450,&DAT_00555df0,uVar1);

  DAT_00584413 = 3;

  uVar1 = FUN_00507b00(s_InpToggle1stPerson_00555c50);

  FUN_00542f27(&DAT_005894d0,&DAT_00555df0,uVar1);

  DAT_00584415 = 3;

  uVar1 = FUN_00507b00(s_InpMapMode_00555c44);

  FUN_00542f27(&DAT_00589550,&DAT_00555df0,uVar1);

  DAT_00584417 = 3;

  uVar1 = FUN_00507b00(s_InpRunFwd_00555c38);

  FUN_00542f27(&DAT_005895d0,&DAT_00555df0,uVar1);

  DAT_00584419 = 1;

  uVar1 = FUN_00507b00(s_InpRunBkwd_00555c2c);

  FUN_00542f27(&DAT_00589650,&DAT_00555df0,uVar1);

  DAT_0058441b = 1;

  uVar1 = FUN_00507b00(s_InpSideLeft_00555c20);

  FUN_00542f27(&DAT_005896d0,&DAT_00555df0,uVar1);

  DAT_0058441d = 1;

  uVar1 = FUN_00507b00(s_InpSideRight_00555c10);

  FUN_00542f27(&DAT_00589750,&DAT_00555df0,uVar1);

  DAT_0058441f = 1;

  uVar1 = FUN_00507b00(s_InpEscape2_00555c04);

  FUN_00542f27(&DAT_005898d0,&DAT_00555df0,uVar1);

  DAT_00584425 = 3;

  uVar1 = FUN_00507b00(s_InpDropCurWeapon_00555bd8);

  FUN_00542f27(&DAT_00589950,&DAT_00555df0,uVar1);

  DAT_00584427 = 3;

  uVar1 = FUN_00507b00(s_InpChatAll_00555bf8);

  FUN_00542f27(&DAT_005897d0,&DAT_00555df0,uVar1);

  DAT_00584421 = 3;

  uVar1 = FUN_00507b00(s_InpChatTeam_00555bec);

  FUN_00542f27(&DAT_00589850,&DAT_00555df0,uVar1);

  DAT_00584423 = 3;

  uVar3 = 0x2000;

  iVar2 = 0;

  do {

    uVar3 = (int)uVar3 >> 1;

    iVar2 = iVar2 + 1;

  } while ((uVar3 & 1) == 0);

  iVar4 = FUN_00423470(0x10000);

  (&DAT_005843d0)[iVar4 * 2] = (&DAT_005843d0)[iVar2 * 2];

  iVar2 = FUN_00423470(0x10000);

  (&DAT_005843d1)[iVar2 * 2] = 2;

  iVar2 = FUN_00423470(0x8000);

  iVar4 = FUN_00423470(0x20000);

  (&DAT_005843d0)[iVar4 * 2] = (&DAT_005843d0)[iVar2 * 2];

  iVar2 = FUN_00423470(0x20000);

  (&DAT_005843d1)[iVar2 * 2] = 2;

LAB_004228ea:

  if ((param_1 == -1) || (param_1 == 1)) {

    if (bVar7) {

      DAT_00584428 = local_130[0];

      iVar2 = 2;

      iVar4 = 0;

      do {

        iVar2 = iVar2 >> 1;

        iVar4 = iVar4 + 1;

      } while ((char)iVar2 == '\0');

      iVar5 = 2;

      iVar2 = 0;

      do {

        iVar5 = iVar5 >> 1;

        iVar2 = iVar2 + 1;

      } while ((char)iVar5 == '\0');

      (&DAT_00584428)[iVar2 * 2] = local_130[iVar4 * 2];

      uVar3 = 4;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 4;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar4 * 2] = local_130[iVar2 * 2];

      uVar3 = 8;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 8;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar4 * 2] = local_130[iVar2 * 2];

      uVar3 = 0x10;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x10;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar4 * 2] = local_130[iVar2 * 2];

      uVar3 = 0x20;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x20;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar4 * 2] = local_130[iVar2 * 2];

      uVar3 = 0x40;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x40;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar4 * 2] = local_130[iVar2 * 2];

      uVar3 = 0x80;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x80;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar4 * 2] = local_130[iVar2 * 2];

      uVar3 = 0x100;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x100;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar4 * 2] = local_130[iVar2 * 2];

      uVar3 = 0x200;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x200;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar4 * 2] = local_130[iVar2 * 2];

      uVar3 = 0x400;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x400;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar4 * 2] = local_130[iVar2 * 2];

      uVar3 = 0x4000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x4000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar4 * 2] = local_130[iVar2 * 2];

      uVar3 = 0x8000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x8000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar4 * 2] = local_130[iVar2 * 2];

      uVar3 = 0x800;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x800;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar4 * 2] = local_130[iVar2 * 2];

      uVar3 = 0x1000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x1000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar4 * 2] = local_130[iVar2 * 2];

      uVar3 = 0x2000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      uVar3 = 0x2000;

      iVar4 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar4 = iVar4 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar4 * 2] = local_130[iVar2 * 2];

      DAT_00584470 = local_e8;

      DAT_00584472 = local_e6;

      DAT_00584474 = local_e4;

      DAT_00584476 = local_e2;

      DAT_0058447c = local_dc;

      DAT_00584478 = local_e0;

      DAT_0058447a = local_de;

      DAT_0058446c = local_ec;

      DAT_00584468 = local_f0;

      DAT_0058446a = local_ee;

      DAT_0058446e = local_ea;

    }

    else {

      DAT_00584428 = 5;

      iVar2 = 0;

      iVar4 = 2;

      do {

        iVar4 = iVar4 >> 1;

        iVar2 = iVar2 + 1;

      } while ((char)iVar4 == '\0');

      (&DAT_00584428)[iVar2 * 2] = 0x2b;

      uVar3 = 4;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar2 * 2] = 0x65;

      uVar3 = 8;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar2 * 2] = 0x66;

      uVar3 = 0x10;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar2 * 2] = 0x2a;

      uVar3 = 0x20;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar2 * 2] = 0xb;

      uVar3 = 0x40;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar2 * 2] = 0x1c;

      uVar3 = 0x80;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar2 * 2] = 0x17;

      uVar3 = 0x100;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar2 * 2] = 0x33;

      uVar3 = 0x200;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar2 * 2] = 0x34;

      uVar3 = 0x400;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar2 * 2] = 0x35;

      uVar3 = 0x4000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar2 * 2] = 0x38;

      uVar3 = 0x8000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar2 * 2] = 0x37;

      uVar3 = 0x800;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar2 * 2] = 0x2d;

      uVar3 = 0x1000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar2 * 2] = 0x2c;

      uVar3 = 0x2000;

      iVar2 = 0;

      do {

        uVar3 = (int)uVar3 >> 1;

        iVar2 = iVar2 + 1;

      } while ((uVar3 & 1) == 0);

      (&DAT_00584428)[iVar2 * 2] = 0x10;

      DAT_00584470 = 0x16;

      DAT_00584472 = 0x12;

      DAT_00584474 = 0;

      DAT_00584476 = 3;

      DAT_0058447c = 0x27;

      DAT_00584478 = 0x13;

      DAT_0058447a = 0x18;

      DAT_0058446c = 0x11;

      DAT_00584468 = 4;

      DAT_0058446a = 0x19;

      DAT_0058446e = 2;

    }

    uVar1 = FUN_00507b00(s_InpSpecialCamera_00555af4);

    FUN_00542f27(&DAT_005899d0,&DAT_00555df0,uVar1);

    DAT_00584429 = 1;

    iVar2 = 2;

    iVar4 = 0;

    do {

      iVar2 = iVar2 >> 1;

      iVar4 = iVar4 + 1;

    } while ((char)iVar2 == '\0');

    uVar1 = FUN_00507b00(s_InpOffspringMode_00555ae0);

    FUN_00542f27(&DAT_005899d0 + iVar4 * 0x80,&DAT_00555df0,uVar1);

    iVar4 = 2;

    iVar2 = 0;

    do {

      iVar4 = iVar4 >> 1;

      iVar2 = iVar2 + 1;

    } while ((char)iVar4 == '\0');

    (&DAT_00584429)[iVar2 * 2] = 1;

    uVar3 = 4;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpAttack_00555ad4);

    FUN_00542f27(&DAT_005899d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 4;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584429)[iVar2 * 2] = 1;

    uVar3 = 8;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpGrab_00555acc);

    FUN_00542f27(&DAT_005899d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 8;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584429)[iVar2 * 2] = 1;

    uVar3 = 0x10;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpAdrenaline_00555abc);

    FUN_00542f27(&DAT_005899d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x10;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584429)[iVar2 * 2] = 1;

    uVar3 = 0x20;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpLayEgg_00555ab0);

    FUN_00542f27(&DAT_005899d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x20;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584429)[iVar2 * 2] = 1;

    uVar3 = 0x40;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpSummonOffsping_00555a9c);

    FUN_00542f27(&DAT_005899d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x40;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584429)[iVar2 * 2] = 1;

    uVar3 = 0x80;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpUseSpike_00555a90);

    FUN_00542f27(&DAT_005899d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x80;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584429)[iVar2 * 2] = 1;

    uVar3 = 0x100;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpRoar1_00555a84);

    FUN_00542f27(&DAT_005899d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x100;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584429)[iVar2 * 2] = 1;

    uVar3 = 0x200;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpRoar2_00555a78);

    FUN_00542f27(&DAT_005899d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x200;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584429)[iVar2 * 2] = 1;

    uVar3 = 0x400;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpRoar3_00555a6c);

    FUN_00542f27(&DAT_005899d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x400;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584429)[iVar2 * 2] = 1;

    uVar3 = 0x4000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpCheat_00555a60);

    FUN_00542f27(&DAT_005899d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x4000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584429)[iVar2 * 2] = 3;

    uVar3 = 0x8000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpCheat_Grow_00555a50);

    FUN_00542f27(&DAT_005899d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x8000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584429)[iVar2 * 2] = 3;

    uVar3 = 0x800;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpSprint_00555a44);

    FUN_00542f27(&DAT_005899d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x800;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584429)[iVar2 * 2] = 1;

    uVar3 = 0x1000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpKbJump_00555a38);

    FUN_00542f27(&DAT_005899d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x1000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584429)[iVar2 * 2] = 3;

    uVar3 = 0x2000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    uVar1 = FUN_00507b00(s_InpBurn_00555a30);

    FUN_00542f27(&DAT_005899d0 + iVar2 * 0x80,&DAT_00555df0,uVar1);

    uVar3 = 0x2000;

    iVar2 = 0;

    do {

      uVar3 = (int)uVar3 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar3 & 1) == 0);

    (&DAT_00584429)[iVar2 * 2] = 3;

    uVar1 = FUN_00507b00(s_InpMapMode_00555c44);

    FUN_00542f27(&DAT_0058ab50,&DAT_00555df0,uVar1);

    DAT_0058446f = 3;

    uVar1 = FUN_00507b00(s_InpRunFwd_00555c38);

    FUN_00542f27(&DAT_0058abd0,&DAT_00555df0,uVar1);

    DAT_00584471 = 1;

    uVar1 = FUN_00507b00(s_InpRunBkwd_00555c2c);

    FUN_00542f27(&DAT_0058ac50,&DAT_00555df0,uVar1);

    DAT_00584473 = 1;

    uVar1 = FUN_00507b00(s_InpSideLeft_00555c20);

    FUN_00542f27(&DAT_0058acd0,&DAT_00555df0,uVar1);

    DAT_00584475 = 1;

    uVar1 = FUN_00507b00(s_InpSideRight_00555c10);

    FUN_00542f27(&DAT_0058ad50,&DAT_00555df0,uVar1);

    DAT_00584477 = 1;

    uVar1 = FUN_00507b00(s_InpEscape2_00555c04);

    FUN_00542f27(&DAT_0058aed0,&DAT_00555df0,uVar1);

    DAT_0058447d = 3;

    uVar1 = FUN_00507b00(s_InpChatAll_00555bf8);

    FUN_00542f27(&DAT_0058add0,&DAT_00555df0,uVar1);

    DAT_00584479 = 3;

    uVar1 = FUN_00507b00(s_InpChatTeam_00555bec);

    FUN_00542f27(&DAT_0058ae50,&DAT_00555df0,uVar1);

    DAT_0058447b = 3;

    uVar1 = FUN_00507b00(s_InpToggle1stPerson_00555c50);

    FUN_00542f27(&DAT_0058aad0,&DAT_00555df0,uVar1);

    DAT_0058446d = 3;

    uVar1 = FUN_00507b00(s_InpSniperZoomSnap_00555c78);

    FUN_00542f27(&DAT_0058a9d0,&DAT_00555df0,uVar1);

    DAT_00584469 = 1;

    uVar1 = FUN_00507b00(s_InpSniperZoomInc_00555c64);

    FUN_00542f27(&DAT_0058aa50,&DAT_00555df0,uVar1);

    DAT_0058446b = 3;

    uVar1 = FUN_00507b00(s_InpMapMode_00555c44);

    FUN_00542f27(&DAT_0058ab50,&DAT_00555df0,uVar1);

    DAT_0058446f = 3;

  }

  if ((param_1 == -1) || (param_1 == 0)) {

    DAT_005844c8 = 0x16;

    DAT_005844c9 = 1;

    DAT_005844ca = 0x12;

    DAT_005844cb = 1;

    DAT_005844cc = 0;

    DAT_005844cd = 1;

    DAT_005844ce = 3;

    DAT_005844cf = 1;

    DAT_005844d0 = 0x13;

    DAT_005844d1 = 3;

  }

  return;

}

/* ===== FUN_00423470 @ 0x00423470 ===== */
int FUN_00423470(uint param_1)



{

  int iVar1;

  

  iVar1 = 0;

  for (; (param_1 & 1) == 0; param_1 = (int)param_1 >> 1) {

    iVar1 = iVar1 + 1;

  }

  return iVar1;

}

/* ===== FUN_004235a0 @ 0x004235A0 ===== */
undefined4 FUN_004235a0(int *param_1)



{

  int *piVar1;

  uint uVar2;

  int iVar3;

  

  iVar3 = 0;

  piVar1 = &DAT_005845d0;

  do {

    if (((((&DAT_005dd140)[*piVar1] & 1 << ((byte)piVar1[1] & 0x1f)) != 0) &&

        (piVar1 != (int *)&DAT_00585200)) && (piVar1 != (int *)&DAT_00585228)) goto LAB_00423748;

    piVar1 = piVar1 + 10;

    iVar3 = iVar3 + 1;

  } while ((int)piVar1 < 0x585598);

  if (DAT_00633104 == 0) {

    if ((DAT_005dd23c & 1) != 0) {

      *param_1 = 0x65;

      return 1;

    }

    if ((DAT_005dd23c & 2) != 0) {

      *param_1 = 0x66;

      return 1;

    }

    if ((DAT_005dd23c & 4) != 0) {

      *param_1 = 0x67;

      return 1;

    }

    if ((DAT_005dd23c & 8) != 0) {

      *param_1 = 0x68;

      return 1;

    }

    if ((DAT_005dd23c & 0x10) != 0) {

      *param_1 = 0x69;

      return 1;

    }

    if ((DAT_005dd23c & 0x20) != 0) {

      *param_1 = 0x6a;

      return 1;

    }

    if ((DAT_005dd23c & 0x40) != 0) {

      *param_1 = 0x6b;

      return 1;

    }

    if ((char)DAT_005dd23c < '\0') {

      *param_1 = 0x6c;

      return 1;

    }

    if (0 < DAT_005dd224) {

      *param_1 = 0x6d;

      return 1;

    }

    if (DAT_005dd224 < 0) {

      *param_1 = 0x6e;

      return 1;

    }

  }

  else {

    uVar2 = 0;

    if (DAT_005dd198 != 0) {

      do {

        if ((((&DAT_005dd1c8)[uVar2] & 0x80) == 0) && (((&DAT_005dd1fc)[uVar2] & 0x80) != 0)) {

          *param_1 = uVar2 + 0x6f;

          return 1;

        }

        uVar2 = uVar2 + 1;

      } while (uVar2 < DAT_005dd198);

    }

    if ((DAT_005dd1c4 == -1) && (DAT_005dd1f8 != 0xffffffff)) {

      if (DAT_005dd1f8 < 9000) {

        *param_1 = 0xf0;

        return 1;

      }

      if (DAT_005dd1f8 < 18000) {

        *param_1 = 0xf1;

        return 1;

      }

      iVar3 = 0xf3 - (uint)(DAT_005dd1f8 < 27000);

LAB_00423748:

      *param_1 = iVar3;

      return 1;

    }

  }

  return 0;

}

/* ===== FUN_00423760 @ 0x00423760 ===== */
void FUN_00423760(int param_1,int param_2)



{

  int iVar1;

  

  if (param_1 == 0) {

    iVar1 = 0x19;

  }

  else if (param_1 == 2) {

    iVar1 = 0xe;

  }

  else {

    iVar1 = 0x10;

    if (param_1 != 1) {

      iVar1 = param_1;

    }

  }

  if (iVar1 <= param_2) {

    param_2 = param_2 + (0x20 - iVar1);

  }

  (&DAT_00584378)[(param_1 * 0x2c + param_2) * 2] = 0xff;

  FUN_00518FA0();

  return;

}

/* ===== FUN_004237b0 @ 0x004237B0 ===== */
void FUN_004237b0(int param_1,uint param_2,int param_3)



{

  uint uVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  byte *pbVar5;

  

  if (param_1 == 0) {

    uVar1 = 0x19;

  }

  else if (param_1 == 2) {

    uVar1 = 0xe;

  }

  else {

    uVar1 = 0x10;

    if (param_1 != 1) {

      uVar1 = param_2;

    }

  }

  if ((int)uVar1 <= param_3) {

    param_3 = param_3 + (0x20 - uVar1);

  }

  (&DAT_00584378)[(param_1 * 0x2c + param_3) * 2] = (undefined1)param_2;

  if (param_1 == 0) {

    uVar1 = 0x100;

    iVar4 = 0;

    do {

      uVar1 = (int)uVar1 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar1 & 1) == 0);

    uVar1 = 0x2000000;

    iVar2 = 0;

    do {

      uVar1 = (int)uVar1 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar1 & 1) == 0);

    (&DAT_00584378)[iVar2 * 2] = (&DAT_00584378)[iVar4 * 2];

    uVar1 = 0x2000000;

    iVar4 = 0;

    do {

      uVar1 = (int)uVar1 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar1 & 1) == 0);

    (&DAT_00584379)[iVar4 * 2] = 1;

  }

  else if ((param_1 != 2) && (param_1 == 1)) {

    uVar1 = 0x2000;

    iVar4 = 0;

    do {

      uVar1 = (int)uVar1 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar1 & 1) == 0);

    uVar1 = 0x10000;

    iVar2 = 0;

    do {

      uVar1 = (int)uVar1 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar1 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = (&DAT_005843d0)[iVar4 * 2];

    uVar1 = 0x10000;

    iVar4 = 0;

    do {

      uVar1 = (int)uVar1 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar1 & 1) == 0);

    (&DAT_005843d1)[iVar4 * 2] = 2;

    uVar1 = 0x8000;

    iVar4 = 0;

    do {

      uVar1 = (int)uVar1 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar1 & 1) == 0);

    uVar1 = 0x20000;

    iVar2 = 0;

    do {

      uVar1 = (int)uVar1 >> 1;

      iVar2 = iVar2 + 1;

    } while ((uVar1 & 1) == 0);

    (&DAT_005843d0)[iVar2 * 2] = (&DAT_005843d0)[iVar4 * 2];

    uVar1 = 0x20000;

    iVar4 = 0;

    do {

      uVar1 = (int)uVar1 >> 1;

      iVar4 = iVar4 + 1;

    } while ((uVar1 & 1) == 0);

    (&DAT_005843d1)[iVar4 * 2] = 2;

  }

  iVar4 = 0;

  pbVar5 = &DAT_00584378 + param_1 * 0x58;

  do {

    if ((iVar4 != param_3) && (*pbVar5 == param_2)) {

      iVar2 = 0;

      if (param_1 == 1) {

        piVar3 = &DAT_005844e8;

        do {

          if (param_3 == *piVar3) {

            iVar2 = iVar2 + 1;

          }

          if (iVar4 == *piVar3) {

            iVar2 = iVar2 + 1;

          }

          piVar3 = piVar3 + 1;

        } while ((int)piVar3 < 0x5844f4);

        piVar3 = &DAT_005844e0;

        do {

          if (param_3 == *piVar3) {

            iVar2 = iVar2 + 2;

          }

          if (iVar4 == *piVar3) {

            iVar2 = iVar2 + 2;

          }

          piVar3 = piVar3 + 1;

        } while ((int)piVar3 < 0x5844e8);

      }

      else {

        if (param_1 != 0) goto LAB_004239b5;

        piVar3 = &DAT_0058455c;

        do {

          if (param_3 == *piVar3) {

            iVar2 = iVar2 + 1;

          }

          if (iVar4 == *piVar3) {

            iVar2 = iVar2 + 1;

          }

          piVar3 = piVar3 + 1;

        } while ((int)piVar3 < 0x584574);

        piVar3 = &DAT_005844f8;

        do {

          if (param_3 == *piVar3) {

            iVar2 = iVar2 + 2;

          }

          if (iVar4 == *piVar3) {

            iVar2 = iVar2 + 2;

          }

          piVar3 = piVar3 + 1;

        } while ((int)piVar3 < 0x58455c);

      }

      if (iVar2 != 3) {

LAB_004239b5:

        (&DAT_00584378)[(param_1 * 0x2c + iVar4) * 2] = 0xff;

        FUN_00518FA0();

        return;

      }

    }

    iVar4 = iVar4 + 1;

    pbVar5 = pbVar5 + 2;

    if (0x2b < iVar4) {

      FUN_00518FA0();

      return;

    }

  } while( true );

}

/* ===== keymap_save @ 0x004239D0 ===== */
void keymap_save(void)



{

  int iVar1;

  char *pcVar2;

  undefined1 *puVar3;

  undefined1 *local_84;

  CHAR local_80 [128];

  

  comm_0051a130(s_KeyVersion_00555ef0,0x36);

  FUN_00542f27(local_80,s___savegame_00555ee4);

  CreateDirectoryA(local_80,(LPSECURITY_ATTRIBUTES)0x0);

  local_84 = (undefined1 *)0xffffffff;

  keymap_0051a100(s_SaveIdx_00555edc,&local_84);

  if (local_84 == (undefined1 *)0xffffffff) {

    FUN_00542f27(local_80,s___savegame__s_00555ecc,&DAT_0063304c);

    CreateDirectoryA(local_80,(LPSECURITY_ATTRIBUTES)0x0);

    puVar3 = &DAT_0063304c;

    if (DAT_00633104 == 0) {

      pcVar2 = s_savegame__s_keymapping_sav_00555e94;

    }

    else {

      pcVar2 = s_savegame__s_joymapping_sav_00555eb0;

    }

  }

  else {

    FUN_00542f27(local_80,s___savegame_SaveGame_d_00555e7c,local_84);

    CreateDirectoryA(local_80,(LPSECURITY_ATTRIBUTES)0x0);

    puVar3 = local_84;

    if (DAT_00633104 == 0) {

      pcVar2 = s_savegame_SaveGame_d_keymapping_s_00555e34;

    }

    else {

      pcVar2 = s_savegame_SaveGame_d_joymapping_s_00555e58;

    }

  }

  FUN_00542f27(local_80,pcVar2,puVar3);

  iVar1 = BinFileSeek_2(local_80,&DAT_00555e30);

  if (iVar1 != 0) {

    FUN_00543a24(&DAT_00584378,0x160,1,iVar1);

    editor_0054384c(iVar1);

  }

  return;

}

/* ===== keymap_load @ 0x00423AF0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void keymap_load(void)



{

  uint uVar1;

  int iVar2;

  char *pcVar3;

  undefined1 *puVar4;

  undefined1 *puStack_88;

  int iStack_84;

  undefined1 auStack_80 [128];

  

  input_keyname_lookup();

  uVar1 = 0x2000;

  DAT_005844e8 = 0;

  do {

    uVar1 = (int)uVar1 >> 1;

    DAT_005844e8 = DAT_005844e8 + 1;

  } while ((uVar1 & 1) == 0);

  uVar1 = 0x8000;

  DAT_005844ec = 0;

  do {

    uVar1 = (int)uVar1 >> 1;

    DAT_005844ec = DAT_005844ec + 1;

  } while ((uVar1 & 1) == 0);

  if (DAT_00633104 == 0) {

    _DAT_005844f0 = -1;

  }

  else {

    uVar1 = 0x4000;

    _DAT_005844f0 = 0;

    do {

      uVar1 = (int)uVar1 >> 1;

      _DAT_005844f0 = _DAT_005844f0 + 1;

    } while ((uVar1 & 1) == 0);

  }

  DAT_005844e0 = 0;

  uVar1 = 0x400;

  DAT_005844e4 = 0;

  do {

    uVar1 = (int)uVar1 >> 1;

    DAT_005844e4 = DAT_005844e4 + 1;

  } while ((uVar1 & 1) == 0);

  uVar1 = 0x10000;

  DAT_0058455c = 0;

  do {

    uVar1 = (int)uVar1 >> 1;

    DAT_0058455c = DAT_0058455c + 1;

  } while ((uVar1 & 1) == 0);

  uVar1 = 0x40000;

  DAT_00584560 = 0;

  do {

    uVar1 = (int)uVar1 >> 1;

    DAT_00584560 = DAT_00584560 + 1;

  } while ((uVar1 & 1) == 0);

  uVar1 = 0x100000;

  _DAT_00584564 = 0;

  do {

    uVar1 = (int)uVar1 >> 1;

    _DAT_00584564 = _DAT_00584564 + 1;

  } while ((uVar1 & 1) == 0);

  uVar1 = 0x80000;

  _DAT_00584568 = 0;

  do {

    uVar1 = (int)uVar1 >> 1;

    _DAT_00584568 = _DAT_00584568 + 1;

  } while ((uVar1 & 1) == 0);

  uVar1 = 0x20000;

  _DAT_0058456c = 0;

  do {

    uVar1 = (int)uVar1 >> 1;

    _DAT_0058456c = _DAT_0058456c + 1;

  } while ((uVar1 & 1) == 0);

  uVar1 = 0x2000000;

  _DAT_00584570 = 0;

  do {

    uVar1 = (int)uVar1 >> 1;

    _DAT_00584570 = _DAT_00584570 + 1;

  } while ((uVar1 & 1) == 0);

  uVar1 = 0x100;

  DAT_005844f8 = 0;

  do {

    uVar1 = (int)uVar1 >> 1;

    DAT_005844f8 = DAT_005844f8 + 1;

  } while ((uVar1 & 1) == 0);

  DAT_005844fc = 0;

  iVar2 = 2;

  _DAT_00584500 = 0;

  do {

    iVar2 = iVar2 >> 1;

    _DAT_00584500 = _DAT_00584500 + 1;

  } while ((char)iVar2 == '\0');

  uVar1 = 4;

  _DAT_00584504 = 0;

  do {

    uVar1 = (int)uVar1 >> 1;

    _DAT_00584504 = _DAT_00584504 + 1;

  } while ((uVar1 & 1) == 0);

  _DAT_00584508 = FUN_00423470(0x10);

  _DAT_0058450c = FUN_00423470(0x20);

  _DAT_00584510 = FUN_00423470(0x40);

  _DAT_00584514 = FUN_00423470(0x80);

  _DAT_00584518 = FUN_00423470(0x200);

  _DAT_0058451c = FUN_00423470(0x400);

  _DAT_00584520 = FUN_00423470(0x800);

  _DAT_00584524 = FUN_00423470(0x1000);

  _DAT_00584528 = FUN_00423470(0x2000);

  _DAT_0058452c = FUN_00423470(0x4000);

  _DAT_00584530 = FUN_00423470(0x200000);

  _DAT_00584534 = FUN_00423470(0x400000);

  _DAT_00584538 = FUN_00423470(0x800000);

  _DAT_0058453c = FUN_00423470(0x1000000);

  _DAT_00584540 = 0x24;

  _DAT_00584544 = 0x25;

  _DAT_00584548 = 0x26;

  _DAT_0058454c = 0x27;

  _DAT_00584550 = 0x20;

  _DAT_00584554 = 0x21;

  _DAT_00584558 = 0x2b;

  input_mapping_init(0xffffffff);

  iStack_84 = -1;

  mission_0051a0c0(s_KeyVersion_00555ef0,&iStack_84);

  if (iStack_84 == 0x36) {

    puStack_88 = (undefined1 *)0xffffffff;

    keymap_0051a100(s_SaveIdx_00555edc,&puStack_88);

    if (puStack_88 == (undefined1 *)0xffffffff) {

      puVar4 = &DAT_0063304c;

      if (DAT_00633104 == 0) {

        pcVar3 = s_savegame__s_keymapping_sav_00555e94;

      }

      else {

        pcVar3 = s_savegame__s_joymapping_sav_00555eb0;

      }

    }

    else {

      puVar4 = puStack_88;

      if (DAT_00633104 == 0) {

        pcVar3 = s_savegame_SaveGame_d_keymapping_s_00555e34;

      }

      else {

        pcVar3 = s_savegame_SaveGame_d_joymapping_s_00555e58;

      }

    }

    FUN_00542f27(auStack_80,pcVar3,puVar4);

    iVar2 = BinFileSeek_2(auStack_80,&DAT_00555e04);

    if (iVar2 != 0) {

      FUN_005438c9(&DAT_00584378,0x160,1,iVar2);

      editor_0054384c(iVar2);

    }

    input_mapping_init(0);

  }

  return;

}

/* ===== input_keyname_lookup @ 0x00423E20 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void input_keyname_lookup(void)



{

  undefined1 *puVar1;

  undefined *puVar2;

  undefined4 uVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  uint uVar7;

  char *pcVar8;

  undefined1 local_94 [20];

  undefined1 local_80 [128];

  

  DAT_005845d0 = 0;

  DAT_005845d4 = 0x1e;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_005562b8);

  puVar1 = (undefined1 *)FUN_00507b00(local_94);

  if (puVar1 == local_94) {

    puVar1 = &DAT_005562b8;

  }

  FUN_00542f27(&DAT_005845d8,&DAT_00555df0,puVar1);

  DAT_005845f8 = 1;

  DAT_005845fc = 0x10;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_005562ac);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_005562ac;

  }

  FUN_00542f27(&DAT_00584600,&DAT_00555df0,puVar2);

  _DAT_00584620 = 1;

  _DAT_00584624 = 0xe;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_005562a8);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_005562a8;

  }

  FUN_00542f27(&DAT_00584628,&DAT_00555df0,puVar2);

  _DAT_00584648 = 1;

  _DAT_0058464c = 0;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_005562a4);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_005562a4;

  }

  FUN_00542f27(&DAT_00584650,&DAT_00555df0,puVar2);

  _DAT_00584670 = 0;

  _DAT_00584674 = 0x12;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_005562a0);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_005562a0;

  }

  FUN_00542f27(&DAT_00584678,&DAT_00555df0,puVar2);

  _DAT_00584698 = 1;

  _DAT_0058469c = 1;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_0055629c);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_0055629c;

  }

  FUN_00542f27(&DAT_005846a0,&DAT_00555df0,puVar2);

  _DAT_005846c0 = 1;

  _DAT_005846c4 = 2;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556298);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556298;

  }

  FUN_00542f27(&DAT_005846c8,&DAT_00555df0,puVar2);

  _DAT_005846e8 = 1;

  _DAT_005846ec = 3;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556294);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556294;

  }

  FUN_00542f27(&DAT_005846f0,&DAT_00555df0,puVar2);

  _DAT_00584710 = 0;

  _DAT_00584714 = 0x17;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556290);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556290;

  }

  FUN_00542f27(&DAT_00584718,&DAT_00555df0,puVar2);

  _DAT_00584738 = 1;

  _DAT_0058473c = 4;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_0055628c);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_0055628c;

  }

  FUN_00542f27(&DAT_00584740,&DAT_00555df0,puVar2);

  _DAT_00584760 = 1;

  _DAT_00584764 = 5;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556288);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556288;

  }

  FUN_00542f27(&DAT_00584768,&DAT_00555df0,puVar2);

  _DAT_00584788 = 1;

  _DAT_0058478c = 6;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556284);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556284;

  }

  FUN_00542f27(&DAT_00584790,&DAT_00555df0,puVar2);

  _DAT_005847b0 = 1;

  _DAT_005847b4 = 0x12;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556280);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556280;

  }

  FUN_00542f27(&DAT_005847b8,&DAT_00555df0,puVar2);

  _DAT_005847d8 = 1;

  _DAT_005847dc = 0x11;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_0055627c);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_0055627c;

  }

  FUN_00542f27(&DAT_005847e0,&DAT_00555df0,puVar2);

  _DAT_00584800 = 0;

  _DAT_00584804 = 0x18;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556278);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556278;

  }

  FUN_00542f27(&DAT_00584808,&DAT_00555df0,puVar2);

  _DAT_00584828 = 0;

  _DAT_0058482c = 0x19;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556274);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556274;

  }

  FUN_00542f27(&DAT_00584830,&DAT_00555df0,puVar2);

  _DAT_00584850 = 0;

  _DAT_00584854 = 0x10;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556270);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556270;

  }

  FUN_00542f27(&DAT_00584858,&DAT_00555df0,puVar2);

  _DAT_00584878 = 0;

  _DAT_0058487c = 0x13;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_0055626c);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_0055626c;

  }

  FUN_00542f27(&DAT_00584880,&DAT_00555df0,puVar2);

  _DAT_005848a0 = 0;

  _DAT_005848a4 = 0x1f;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556268);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556268;

  }

  FUN_00542f27(&DAT_005848a8,&DAT_00555df0,puVar2);

  _DAT_005848c8 = 0;

  _DAT_005848cc = 0x14;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556264);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556264;

  }

  FUN_00542f27(&DAT_005848d0,&DAT_00555df0,puVar2);

  _DAT_005848f0 = 0;

  _DAT_005848f4 = 0x16;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556260);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556260;

  }

  FUN_00542f27(&DAT_005848f8,&DAT_00555df0,puVar2);

  _DAT_00584918 = 1;

  _DAT_0058491c = 0xf;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_0055625c);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_0055625c;

  }

  FUN_00542f27(&DAT_00584920,&DAT_00555df0,puVar2);

  _DAT_00584940 = 0;

  _DAT_00584944 = 0x11;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556258);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556258;

  }

  FUN_00542f27(&DAT_00584948,&DAT_00555df0,puVar2);

  _DAT_00584968 = 1;

  _DAT_0058496c = 0xd;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556254);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556254;

  }

  FUN_00542f27(&DAT_00584970,&DAT_00555df0,puVar2);

  _DAT_00584990 = 0;

  _DAT_00584994 = 0x15;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556250);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556250;

  }

  FUN_00542f27(&DAT_00584998,&DAT_00555df0,puVar2);

  _DAT_005849b8 = 1;

  _DAT_005849bc = 0xc;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_0055624c);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_0055624c;

  }

  FUN_00542f27(&DAT_005849c0,&DAT_00555df0,puVar2);

  _DAT_005849e0 = 0;

  _DAT_005849e4 = 0xb;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556248);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556248;

  }

  FUN_00542f27(&DAT_005849e8,&DAT_00555df0,puVar2);

  _DAT_00584a08 = 0;

  _DAT_00584a0c = 2;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556244);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556244;

  }

  FUN_00542f27(&DAT_00584a10,&DAT_00555df0,puVar2);

  _DAT_00584a30 = 0;

  _DAT_00584a34 = 3;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556240);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556240;

  }

  FUN_00542f27(&DAT_00584a38,&DAT_00555df0,puVar2);

  _DAT_00584a58 = 0;

  _DAT_00584a5c = 4;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_0055623c);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_0055623c;

  }

  FUN_00542f27(&DAT_00584a60,&DAT_00555df0,puVar2);

  _DAT_00584a80 = 0;

  _DAT_00584a84 = 5;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556238);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556238;

  }

  FUN_00542f27(&DAT_00584a88,&DAT_00555df0,puVar2);

  _DAT_00584aa8 = 0;

  _DAT_00584aac = 6;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556234);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556234;

  }

  FUN_00542f27(&DAT_00584ab0,&DAT_00555df0,puVar2);

  _DAT_00584ad0 = 0;

  _DAT_00584ad4 = 7;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556230);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556230;

  }

  FUN_00542f27(&DAT_00584ad8,&DAT_00555df0,puVar2);

  _DAT_00584af8 = 0;

  _DAT_00584afc = 8;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_0055622c);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_0055622c;

  }

  FUN_00542f27(&DAT_00584b00,&DAT_00555df0,puVar2);

  _DAT_00584b20 = 0;

  _DAT_00584b24 = 9;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556228);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556228;

  }

  FUN_00542f27(&DAT_00584b28,&DAT_00555df0,puVar2);

  _DAT_00584b48 = 0;

  _DAT_00584b4c = 10;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556224);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556224;

  }

  FUN_00542f27(&DAT_00584b50,&DAT_00555df0,puVar2);

  _DAT_00584b70 = 1;

  _DAT_00584b74 = 9;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556220);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556220;

  }

  FUN_00542f27(&DAT_00584b78,&DAT_00555df0,puVar2);

  _DAT_00584b98 = 0;

  _DAT_00584b9c = 0xc;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_0055621c);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_0055621c;

  }

  FUN_00542f27(&DAT_00584ba0,&DAT_00555df0,puVar2);

  _DAT_00584bc0 = 0;

  _DAT_00584bc4 = 0xd;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556218);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556218;

  }

  FUN_00542f27(&DAT_00584bc8,&DAT_00555df0,puVar2);

  _DAT_00584be8 = 0;

  _DAT_00584bec = 0xe;

  uVar3 = FUN_00507b00(s_InpBSPACE_0055620c);

  FUN_00542f27(&DAT_00584bf0,&DAT_00555df0,uVar3);

  _DAT_00584c10 = 0;

  _DAT_00584c14 = 0xf;

  uVar3 = FUN_00507b00(s_InpTAB_00556204);

  FUN_00542f27(&DAT_00584c18,&DAT_00555df0,uVar3);

  _DAT_00584c38 = 1;

  _DAT_00584c3c = 0x1a;

  uVar3 = FUN_00507b00(s_InpCAPS_005561fc);

  FUN_00542f27(&DAT_00584c40,&DAT_00555df0,uVar3);

  _DAT_00584c60 = 1;

  _DAT_00584c64 = 10;

  uVar3 = FUN_00507b00(s_InpLSHIFT_005561f0);

  FUN_00542f27(&DAT_00584c68,&DAT_00555df0,uVar3);

  _DAT_00584c88 = 0;

  _DAT_00584c8c = 0x1d;

  uVar3 = FUN_00507b00(s_InpLCTRL_005561e4);

  FUN_00542f27(&DAT_00584c90,&DAT_00555df0,uVar3);

  _DAT_00584cb0 = 1;

  _DAT_00584cb4 = 0x18;

  uVar3 = FUN_00507b00(s_InpLALT_005561dc);

  FUN_00542f27(&DAT_00584cb8,&DAT_00555df0,uVar3);

  _DAT_00584cd8 = 1;

  _DAT_00584cdc = 0x19;

  uVar3 = FUN_00507b00(s_InpSPACE_005561d0);

  FUN_00542f27(&DAT_00584ce0,&DAT_00555df0,uVar3);

  _DAT_00584d00 = 1;

  _DAT_00584d04 = 0x16;

  uVar3 = FUN_00507b00(s_InpRSHIFT_005561c4);

  FUN_00542f27(&DAT_00584d08,&DAT_00555df0,uVar3);

  _DAT_00584d28 = 0;

  _DAT_00584d2c = 0x1c;

  uVar3 = FUN_00507b00(s_InpENTER_005561b8);

  FUN_00542f27(&DAT_00584d30,&DAT_00555df0,uVar3);

  _DAT_00584d50 = 0;

  _DAT_00584d54 = 0x1a;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_005561b4);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_005561b4;

  }

  FUN_00542f27(&DAT_00584d58,&DAT_00555df0,puVar2);

  _DAT_00584d78 = 0;

  _DAT_00584d7c = 0x1b;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_005561b0);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_005561b0;

  }

  FUN_00542f27(&DAT_00584d80,&DAT_00555df0,puVar2);

  _DAT_00584da0 = 1;

  _DAT_00584da4 = 0x15;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_005561ac);

  puVar1 = (undefined1 *)FUN_00507b00(local_94);

  if (puVar1 == local_94) {

    puVar1 = &DAT_005561ac;

  }

  FUN_00542f27(&DAT_00584da8,&DAT_00555df0,puVar1);

  _DAT_00584dc8 = 6;

  _DAT_00584dcc = 0x12;

  uVar3 = FUN_00507b00(s_InpINSERT_005561a0);

  FUN_00542f27(&DAT_00584dd0,&DAT_00555df0,uVar3);

  _DAT_00584df0 = 6;

  _DAT_00584df4 = 7;

  uVar3 = FUN_00507b00(s_InpHOME_00556198);

  FUN_00542f27(&DAT_00584df8,&DAT_00555df0,uVar3);

  _DAT_00584e18 = 6;

  _DAT_00584e1c = 9;

  uVar3 = FUN_00507b00(s_InpPAGEUP_0055618c);

  FUN_00542f27(&DAT_00584e20,&DAT_00555df0,uVar3);

  _DAT_00584e40 = 6;

  _DAT_00584e44 = 0x13;

  uVar3 = FUN_00507b00(s_InpDELETE_00556180);

  FUN_00542f27(&DAT_00584e48,&DAT_00555df0,uVar3);

  _DAT_00584e68 = 6;

  _DAT_00584e6c = 0xf;

  uVar3 = FUN_00507b00(s_InpEND_00556178);

  FUN_00542f27(&DAT_00584e70,&DAT_00555df0,uVar3);

  _DAT_00584e90 = 6;

  _DAT_00584e94 = 0x11;

  uVar3 = FUN_00507b00(s_InpPAGEDOWN_0055616c);

  FUN_00542f27(&DAT_00584e98,&DAT_00555df0,uVar3);

  _DAT_00584eb8 = 6;

  _DAT_00584ebc = 8;

  uVar3 = FUN_00507b00(s_InpUP_00556164);

  FUN_00542f27(&DAT_00584ec0,&DAT_00555df0,uVar3);

  _DAT_00584ee0 = 6;

  _DAT_00584ee4 = 0x10;

  uVar3 = FUN_00507b00(s_InpDOWN_0055615c);

  FUN_00542f27(&DAT_00584ee8,&DAT_00555df0,uVar3);

  _DAT_00584f08 = 6;

  _DAT_00584f0c = 0xb;

  uVar3 = FUN_00507b00(s_InpLEFT_00556154);

  FUN_00542f27(&DAT_00584f10,&DAT_00555df0,uVar3);

  _DAT_00584f30 = 6;

  _DAT_00584f34 = 0xd;

  uVar3 = FUN_00507b00(s_InpRIGHT_00556148);

  FUN_00542f27(&DAT_00584f38,&DAT_00555df0,uVar3);

  _DAT_00584f58 = 2;

  _DAT_00584f5c = 5;

  uVar3 = FUN_00507b00(s_InpNUMLOCK_0055613c);

  FUN_00542f27(&DAT_00584f60,&DAT_00555df0,uVar3);

  _DAT_00584f80 = 5;

  _DAT_00584f84 = 0x15;

  uVar3 = FUN_00507b00(s_InpPAD__00556134);

  FUN_00542f27(&DAT_00584f88,&DAT_00555df0,uVar3);

  _DAT_00584fa8 = 1;

  _DAT_00584fac = 0x17;

  uVar3 = FUN_00507b00(s_InpPAD__0055612c);

  FUN_00542f27(&DAT_00584fb0,&DAT_00555df0,uVar3);

  _DAT_00584fd0 = 2;

  _DAT_00584fd4 = 10;

  uVar3 = FUN_00507b00(s_InpPAD__00556124);

  FUN_00542f27(&DAT_00584fd8,&DAT_00555df0,uVar3);

  _DAT_00584ff8 = 2;

  _DAT_00584ffc = 7;

  uVar3 = FUN_00507b00(s_InpPAD7_0055611c);

  FUN_00542f27(&DAT_00585000,&DAT_00555df0,uVar3);

  _DAT_00585020 = 2;

  _DAT_00585024 = 8;

  uVar3 = FUN_00507b00(s_InpPAD8_00556114);

  FUN_00542f27(&DAT_00585028,&DAT_00555df0,uVar3);

  _DAT_00585048 = 2;

  _DAT_0058504c = 9;

  uVar3 = FUN_00507b00(s_InpPAD9_0055610c);

  FUN_00542f27(&DAT_00585050,&DAT_00555df0,uVar3);

  _DAT_00585070 = 2;

  _DAT_00585074 = 0xe;

  uVar3 = FUN_00507b00(s_InpPAD__00556104);

  FUN_00542f27(&DAT_00585078,&DAT_00555df0,uVar3);

  _DAT_00585098 = 2;

  _DAT_0058509c = 0xb;

  uVar3 = FUN_00507b00(s_InpPAD4_005560fc);

  FUN_00542f27(&DAT_005850a0,&DAT_00555df0,uVar3);

  _DAT_005850c0 = 2;

  _DAT_005850c4 = 0xc;

  uVar3 = FUN_00507b00(s_InpPAD5_005560f4);

  FUN_00542f27(&DAT_005850c8,&DAT_00555df0,uVar3);

  _DAT_005850e8 = 2;

  _DAT_005850ec = 0xd;

  uVar3 = FUN_00507b00(s_InpPAD6_005560ec);

  FUN_00542f27(&DAT_005850f0,&DAT_00555df0,uVar3);

  _DAT_00585110 = 2;

  _DAT_00585114 = 0xf;

  uVar3 = FUN_00507b00(s_InpPAD1_005560e4);

  FUN_00542f27(&DAT_00585118,&DAT_00555df0,uVar3);

  _DAT_00585138 = 2;

  _DAT_0058513c = 0x10;

  uVar3 = FUN_00507b00(s_InpPAD2_005560dc);

  FUN_00542f27(&DAT_00585140,&DAT_00555df0,uVar3);

  _DAT_00585160 = 2;

  _DAT_00585164 = 0x11;

  uVar3 = FUN_00507b00(s_InpPAD3_005560d4);

  FUN_00542f27(&DAT_00585168,&DAT_00555df0,uVar3);

  _DAT_00585188 = 2;

  _DAT_0058518c = 0x12;

  uVar3 = FUN_00507b00(s_InpPAD0_005560cc);

  FUN_00542f27(&DAT_00585190,&DAT_00555df0,uVar3);

  _DAT_005851b0 = 2;

  _DAT_005851b4 = 0x13;

  uVar3 = FUN_00507b00(s_InpPAD__005560c4);

  FUN_00542f27(&DAT_005851b8,&DAT_00555df0,uVar3);

  _DAT_005851d8 = 4;

  _DAT_005851dc = 0x1c;

  uVar3 = FUN_00507b00(s_InpPADENTER_005560b8);

  FUN_00542f27(&DAT_005851e0,&DAT_00555df0,uVar3);

  _DAT_00585200 = 1;

  _DAT_00585204 = 0x1b;

  uVar3 = FUN_00507b00(s_InpF1_005560b0);

  FUN_00542f27(&DAT_00585208,&DAT_00555df0,uVar3);

  _DAT_00585228 = 1;

  _DAT_0058522c = 0x1c;

  uVar3 = FUN_00507b00(s_InpF2_005560a8);

  FUN_00542f27(&DAT_00585230,&DAT_00555df0,uVar3);

  _DAT_00585250 = 1;

  _DAT_00585254 = 0x1d;

  uVar3 = FUN_00507b00(s_InpF3_005560a0);

  FUN_00542f27(&DAT_00585258,&DAT_00555df0,uVar3);

  _DAT_00585278 = 1;

  _DAT_0058527c = 0x1e;

  uVar3 = FUN_00507b00(s_InpF4_00556098);

  FUN_00542f27(&DAT_00585280,&DAT_00555df0,uVar3);

  _DAT_005852a0 = 1;

  _DAT_005852a4 = 0x1f;

  uVar3 = FUN_00507b00(s_InpF5_00556090);

  FUN_00542f27(&DAT_005852a8,&DAT_00555df0,uVar3);

  _DAT_005852c8 = 2;

  _DAT_005852cc = 0;

  uVar3 = FUN_00507b00(s_InpF6_00556088);

  FUN_00542f27(&DAT_005852d0,&DAT_00555df0,uVar3);

  _DAT_005852f0 = 2;

  _DAT_005852f4 = 1;

  uVar3 = FUN_00507b00(s_InpF7_00556080);

  FUN_00542f27(&DAT_005852f8,&DAT_00555df0,uVar3);

  _DAT_00585318 = 2;

  _DAT_0058531c = 2;

  uVar3 = FUN_00507b00(s_InpF8_00556078);

  FUN_00542f27(&DAT_00585320,&DAT_00555df0,uVar3);

  _DAT_00585340 = 2;

  _DAT_00585344 = 3;

  uVar3 = FUN_00507b00(s_InpF9_00556070);

  FUN_00542f27(&DAT_00585348,&DAT_00555df0,uVar3);

  _DAT_00585368 = 2;

  _DAT_0058536c = 4;

  uVar3 = FUN_00507b00(s_InpF10_00556068);

  FUN_00542f27(&DAT_00585370,&DAT_00555df0,uVar3);

  _DAT_00585390 = 2;

  _DAT_00585394 = 0x17;

  uVar3 = FUN_00507b00(s_InpF11_00556060);

  FUN_00542f27(&DAT_00585398,&DAT_00555df0,uVar3);

  _DAT_005853b8 = 2;

  _DAT_005853bc = 0x18;

  uVar3 = FUN_00507b00(s_InpF12_00556058);

  FUN_00542f27(&DAT_005853c0,&DAT_00555df0,uVar3);

  _DAT_005853e0 = 0xffffffff;

  _DAT_005853e4 = 0xffffffff;

  uVar3 = FUN_00507b00(s_InpSYSRQ_0055604c);

  FUN_00542f27(&DAT_005853e8,&DAT_00555df0,uVar3);

  _DAT_00585408 = 2;

  _DAT_0058540c = 6;

  uVar3 = FUN_00507b00(s_InpSRCLCK_00556040);

  FUN_00542f27(&DAT_00585410,&DAT_00555df0,uVar3);

  _DAT_00585430 = 0;

  _DAT_00585434 = 1;

  uVar3 = FUN_00507b00(s_InpESC_00556038);

  FUN_00542f27(&DAT_00585438,&DAT_00555df0,uVar3);

  _DAT_00585458 = 0xffffffff;

  _DAT_0058545c = 0xffffffff;

  uVar3 = FUN_00507b00(s_InpBREAK_0055602c);

  FUN_00542f27(&DAT_00585460,&DAT_00555df0,uVar3);

  _DAT_00585480 = 4;

  _DAT_00585484 = 0x1d;

  uVar3 = FUN_00507b00(s_InpRCTRL_00556020);

  FUN_00542f27(&DAT_00585488,&DAT_00555df0,uVar3);

  _DAT_005854a8 = 5;

  _DAT_005854ac = 0x18;

  uVar3 = FUN_00507b00(s_InpRALT_00556018);

  FUN_00542f27(&DAT_005854b0,&DAT_00555df0,uVar3);

  _DAT_005854d0 = 1;

  _DAT_005854d4 = 0x13;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556014);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556014;

  }

  FUN_00542f27(&DAT_005854d8,&DAT_00555df0,puVar2);

  _DAT_005854f8 = 1;

  _DAT_005854fc = 0x14;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556010);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556010;

  }

  FUN_00542f27(&DAT_00585500,&DAT_00555df0,puVar2);

  _DAT_00585520 = 1;

  _DAT_00585524 = 7;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_0055600c);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_0055600c;

  }

  FUN_00542f27(&DAT_00585528,&DAT_00555df0,puVar2);

  _DAT_00585548 = 1;

  _DAT_0058554c = 8;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556008);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556008;

  }

  FUN_00542f27(&DAT_00585550,&DAT_00555df0,puVar2);

  _DAT_00585570 = 1;

  _DAT_00585574 = 0xb;

  FUN_00542f27(local_94,s_Inp_s_005562b0,&DAT_00556004);

  puVar2 = (undefined *)FUN_00507b00(local_94);

  if (puVar2 == local_94) {

    puVar2 = &DAT_00556004;

  }

  FUN_00542f27(&DAT_00585578,&DAT_00555df0,puVar2);

  uVar3 = FUN_00507b00(s_InpLMouseButton_00555ff4);

  FUN_00542f27(&DAT_005855a0,&DAT_00555df0,uVar3);

  uVar3 = FUN_00507b00(s_InpRMouseButton_00555fe4);

  FUN_00542f27(&DAT_005855c8,&DAT_00555df0,uVar3);

  uVar3 = FUN_00507b00(s_InpCMouseButton_00555fd4);

  FUN_00542f27(&DAT_005855f0,&DAT_00555df0,uVar3);

  uVar3 = FUN_00507b00(s_InpAuxMouseButton1_00555fc0);

  FUN_00542f27(&DAT_00585618,&DAT_00555df0,uVar3);

  uVar3 = FUN_00507b00(s_InpAuxMouseButton2_00555fac);

  FUN_00542f27(&DAT_00585640,&DAT_00555df0,uVar3);

  uVar3 = FUN_00507b00(s_InpAuxMouseButton3_00555f98);

  FUN_00542f27(&DAT_00585668,&DAT_00555df0,uVar3);

  uVar3 = FUN_00507b00(s_InpAuxMouseButton4_00555f84);

  FUN_00542f27(&DAT_00585690,&DAT_00555df0,uVar3);

  uVar3 = FUN_00507b00(s_InpAuxMouseButton5_00555f70);

  FUN_00542f27(&DAT_005856b8,&DAT_00555df0,uVar3);

  uVar3 = FUN_00507b00(s_InpScrollFwd_00555f60);

  FUN_00542f27(&DAT_005856e0,&DAT_00555df0,uVar3);

  uVar3 = FUN_00507b00(s_InpScrollBkwd_00555f50);

  FUN_00542f27(&DAT_00585708,&DAT_00555df0,uVar3);

  iVar6 = 0x6f;

  puVar2 = &DAT_00585730;

  do {

    FUN_00542f27(local_80,s_InpJoyButton_00555f40);

    uVar3 = FUN_00507b00(local_80,iVar6 + -0x6e);

    FUN_00542f27(puVar2,s__s__d_00555f38,uVar3);

    puVar2 = puVar2 + 0x28;

    iVar6 = iVar6 + 1;

  } while ((int)puVar2 < 0x586b31);

  puVar2 = &DAT_00586b58;

  uVar7 = 0;

  do {

    uVar4 = uVar7 & 0x80000003;

    if ((int)uVar4 < 0) {

      uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;

    }

    uVar5 = (int)uVar7 >> 0x1f;

    if (uVar4 == 0) {

      pcVar8 = s_InpJoyPOVUp_00555f2c;

LAB_00425765:

      FUN_00542f27(local_80,pcVar8);

      iVar6 = ((int)(uVar7 + (uVar5 & 3)) >> 2) + 1;

    }

    else if (uVar4 == 1) {

      FUN_00542f27(local_80,s_InpJoyPOVRight_00555f1c);

      iVar6 = ((int)(uVar7 + (uVar5 & 3)) >> 2) + 1;

    }

    else {

      if (uVar4 != 2) {

        pcVar8 = s_InpJoyPOVLeft_00555efc;

        goto LAB_00425765;

      }

      FUN_00542f27(local_80,s_InpJoyPOVDown_00555f0c);

      iVar6 = ((int)(uVar7 + (uVar5 & 3)) >> 2) + 1;

    }

    uVar3 = FUN_00507b00(local_80,iVar6);

    FUN_00542f27(puVar2,s__s__d_00555f38,uVar3);

    iVar6 = uVar7 + 0xf1;

    puVar2 = puVar2 + 0x28;

    uVar7 = uVar7 + 1;

    if (0xff < iVar6) {

      return;

    }

  } while( true );

}

/* ===== FUN_004257c0 @ 0x004257C0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004257c0(float param_1)



{

  float fVar1;

  

  if (0.0 <= param_1) {

    if (1.0 < param_1) {

      param_1 = 1.0;

    }

  }

  else {

    param_1 = 0.0;

  }

  _DAT_00555a1c = param_1;

  fVar1 = (1.0 - param_1) * 20.0;

  if (0.1 <= fVar1) {

    if (10.0 < fVar1) {

      _DAT_00555a18 = fVar1 * 0.5;

      return;

    }

  }

  else {

    fVar1 = 0.1;

  }

  _DAT_00555a18 = fVar1 * 0.1;

  return;

}

/* ===== FUN_00425840 @ 0x00425840 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 FUN_00425840(void)



{

  return (float10)_DAT_00555a1c;

}

/* ===== FUN_00425850 @ 0x00425850 ===== */
/* PS2 candidate: verm_ai_cb__FiP6OBJECTPv (conf 0.587) */



void FUN_00425850(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x59)) {

    **(undefined4 **)(param_1 + 0x100) = 0x3f800000;

  }

  return;

}

/* ===== FUN_00425a40 @ 0x00425A40 ===== */
/* PS2 candidate: kabuto_corpse_create__FP6OBJECTi (conf 0.613) */



int FUN_00425a40(int param_1,undefined4 param_2)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  

  iVar1 = object_allocate_type(param_2,0);

  if (iVar1 != 0) {

    object_change_ospec(iVar1,0x59);

    if (param_1 != 0) {

      iVar2 = FUN_004a6160(param_1);

      if (iVar2 == 0) {

        *(undefined4 *)(iVar1 + 0xf4) = 0;

      }

      else {

        *(undefined4 *)(iVar1 + 0xf4) = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x4c);

      }

      *(undefined4 *)(iVar1 + 200) = *(undefined4 *)(param_1 + 200);

      *(undefined4 *)(iVar1 + 0xd0) = *(undefined4 *)(param_1 + 0xd0);

      *(undefined4 *)(iVar1 + 0xcc) = *(undefined4 *)(param_1 + 0xcc);

      *(undefined4 *)(iVar1 + 0xc4) = *(undefined4 *)(param_1 + 0xc4);

      puVar3 = (undefined4 *)(param_1 + 0x294);

      puVar4 = (undefined4 *)(iVar1 + 0x294);

      for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar4 = *puVar3;

        puVar3 = puVar3 + 1;

        puVar4 = puVar4 + 1;

      }

      *(uint *)(iVar1 + 0xd8) = *(uint *)(iVar1 + 0xd8) | 0x10000;

      FUN_00499310(iVar1,*(undefined4 *)(iVar1 + 0x2a4),*(undefined4 *)(iVar1 + 0x2b4),

                   *(undefined4 *)(iVar1 + 0x2c4));

      FUN_004a7440(iVar1);

      FUN_0049a1f0(iVar1);

      FUN_004034a0(iVar1,*(undefined4 *)(param_1 + 0x10),0x20,0,0,0);

    }

    object_init_usage(iVar1);

    **(undefined4 **)(iVar1 + 0x100) = 0x41a00000;

  }

  return iVar1;

}

/* ===== FUN_00425b50 @ 0x00425B50 ===== */
/* PS2 candidate: corpse_create (conf 0.502) */



int FUN_00425b50(int param_1)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  

  iVar1 = FUN_004a6160(param_1);

  if (iVar1 != 0) {

    iVar1 = object_allocate_type(2,0);

    *(undefined4 *)(iVar1 + 0xf4) = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x4c);

    object_change_ospec(iVar1,0x59);

    *(undefined4 *)(iVar1 + 0xa0) = *(undefined4 *)(param_1 + 0xa0);

    *(undefined4 *)(iVar1 + 0xa4) = *(undefined4 *)(param_1 + 0xa4);

    *(undefined4 *)(iVar1 + 0xa8) = *(undefined4 *)(param_1 + 0xa8);

    *(undefined4 *)(iVar1 + 200) = *(undefined4 *)(param_1 + 200);

    **(undefined4 **)(iVar1 + 0x100) = 0x41a00000;

    iVar2 = FUN_0052e480(param_1);

    if (iVar2 == 0) {

      uVar3 = 0x90;

    }

    else {

      uVar3 = *(undefined4 *)(param_1 + 0x10);

    }

    FUN_004034a0(iVar1,uVar3,0x80,0,0,0);

    *(undefined4 *)(iVar1 + 0x14) = 0x3f800000;

    return iVar1;

  }

  return 0;

}

/* ===== AudioGetMasterVolume__Fv_2 @ 0x00425E90 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioGetMasterVolume__Fv_2(void)



{

  return DAT_0058c648;

}

/* ===== AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_2 @ 0x00425EA0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_2(undefined4 p0)



{

  DAT_0058c648 = p0;

  return;

}

/* ===== FUN_00425eb0 @ 0x00425EB0 ===== */
/* PS2 candidate: GetCurrentPtr__C11CByteStream (conf 0.75) */



void FUN_00425eb0(undefined4 param_1)



{

  int iVar1;

  char *pcVar2;

  undefined1 *puVar3;

  undefined1 *local_84;

  undefined1 local_80 [128];

  

  if (DAT_0058c648 != 0) {

    local_84 = (undefined1 *)0xffffffff;

    keymap_0051a100(s_SaveIdx_00555edc,&local_84);

    if (local_84 == (undefined1 *)0xffffffff) {

      pcVar2 = s_savegame__s_debug_err_005563a8;

      puVar3 = &DAT_0063304c;

    }

    else {

      pcVar2 = s_savegame_SaveGame_d_debug_err_00556388;

      puVar3 = local_84;

    }

    FUN_00542f27(local_80,pcVar2,puVar3);

    iVar1 = BinFileSeek_2(local_80,&DAT_00556384);

    if (iVar1 != 0) {

      FUN_00543b5d(iVar1,&DAT_00556380,param_1);

      editor_0054384c(iVar1);

      DAT_0058c644 = DAT_0058c644 + 1;

    }

  }

  return;

}

/* ===== keymap_slot_load @ 0x00425F60 ===== */
void keymap_slot_load(void)



{

  char *pcVar1;

  undefined1 *puVar2;

  undefined1 *local_84;

  CHAR local_80 [128];

  

  FUN_00542f27(local_80,s___savegame_00555ee4);

  CreateDirectoryA(local_80,(LPSECURITY_ATTRIBUTES)0x0);

  local_84 = (undefined1 *)0xffffffff;

  keymap_0051a100(s_SaveIdx_00555edc,&local_84);

  if (local_84 == (undefined1 *)0xffffffff) {

    FUN_00542f27(local_80,s___savegame__s_00555ecc,&DAT_0063304c);

    CreateDirectoryA(local_80,(LPSECURITY_ATTRIBUTES)0x0);

    pcVar1 = s___savegame__s_debug_err_005563e0;

    puVar2 = &DAT_0063304c;

  }

  else {

    FUN_00542f27(local_80,s___savegame_SaveGame_d_00555e7c,local_84);

    CreateDirectoryA(local_80,(LPSECURITY_ATTRIBUTES)0x0);

    pcVar1 = s___savegame_SaveGame_d_debug_err_005563c0;

    puVar2 = local_84;

  }

  FUN_00542f27(local_80,pcVar1,puVar2);

  FUN_00543b99(local_80);

  return;

}

/* ===== comm_00426030 @ 0x00426030 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 comm_00426030(void)



{

  int iVar1;

  int *_Source;

  uint uVar2;

  int iVar3;

  int *piVar4;

  char *_Dest;

  uint _Count;

  undefined1 local_50 [80];

  

  if (DAT_0058c658 != 0) {

    iVar1 = FUN_0051f2d0();

    if (iVar1 < DAT_0058c654) {

      DAT_005def7c = 2;

      return 0;

    }

    DAT_0058c658 = 0;

    return 1;

  }

  if (DAT_0058c64c == (int *)0x0) {

    return 1;

  }

  DAT_0058c654 = 0;

  FUN_00452a30(1,1);

  _Source = DAT_0058c650;

switchD_004260b3_caseD_1:

  piVar4 = _Source;

  _Source = piVar4 + 2;

  DAT_0058c650 = _Source;

  switch(*piVar4) {

  case 1:

  case 3:

    goto switchD_004260b3_caseD_1;

  case 2:

    _Source = DAT_0058c64c;

    goto switchD_004260b3_caseD_1;

  case 4:

    goto switchD_004260b3_caseD_4;

  case 5:

    DAT_00632ee4 = *_Source;

    comm_worldname_menu(DAT_00632ee4,local_50);

    DAT_0058c650 = DAT_0058c650 + 1;

    DAT_00632f1c = FUN_00521350(DAT_00632f18);

    iVar1 = FUN_00521330(DAT_00632f18);

    _Source = DAT_0058c650;

    if ((iVar1 == 0) && (iVar1 = FUN_00521310(DAT_00632f18), _Source = DAT_0058c650, iVar1 == 0)) {

      DAT_00632ff0 = 0;

      _Source = DAT_0058c650;

    }

    goto switchD_004260b3_caseD_1;

  case 6:

    DAT_00632f18 = *_Source;

    _Source = piVar4 + 3;

    goto switchD_004260b3_caseD_1;

  case 7:

    DAT_00632f34 = *_Source;

    _Source = piVar4 + 3;

    goto switchD_004260b3_caseD_1;

  default:

    _Source = _Source + piVar4[1];

    goto switchD_004260b3_caseD_1;

  case 9:

    DAT_00632f20 = *_Source;

    _Source = piVar4 + 3;

    goto switchD_004260b3_caseD_1;

  case 10:

    DAT_00632f24 = *_Source;

    _Source = piVar4 + 3;

    goto switchD_004260b3_caseD_1;

  case 0xb:

    DAT_00632f28 = *_Source;

    _Source = piVar4 + 3;

    goto switchD_004260b3_caseD_1;

  case 0xc:

    DAT_00632f2c = *_Source;

    DAT_00632f30 = (float)DAT_00632f2c * 60.0;

    _Source = piVar4 + 3;

    goto switchD_004260b3_caseD_1;

  case 0xd:

    DAT_00632f3c = *_Source;

    _Source = piVar4 + 3;

    goto switchD_004260b3_caseD_1;

  case 0xe:

    DAT_00632f40 = *_Source;

    _Source = piVar4 + 3;

    goto switchD_004260b3_caseD_1;

  case 0xf:

    DAT_00632fcc = *_Source;

    DAT_00632fc0 = (uint)(0 < DAT_00632fcc);

    DAT_00633010 = (float)DAT_00632fcc * 60.0;

    _Source = piVar4 + 3;

    goto switchD_004260b3_caseD_1;

  case 0x10:

    DAT_00632fdc = *_Source;

    DAT_00632fd0 = (uint)(0 < DAT_00632fdc);

    _Source = piVar4 + 3;

    goto switchD_004260b3_caseD_1;

  case 0x11:

    DAT_00632fec = *_Source;

    _DAT_00632fe0 = (uint)(0 < DAT_00632fec);

    _Source = piVar4 + 3;

    goto switchD_004260b3_caseD_1;

  case 0x13:

    DAT_00632f10 = *_Source;

    _Source = piVar4 + 3;

    goto switchD_004260b3_caseD_1;

  case 0x14:

    uVar2 = 0xffffffff;

    piVar4 = _Source;

    do {

      if (uVar2 == 0) break;

      uVar2 = uVar2 - 1;

      iVar1 = *piVar4;

      piVar4 = (int *)((int)piVar4 + 1);

    } while ((char)iVar1 != '\0');

    uVar2 = ~uVar2 - 1;

    _Count = uVar2;

    if (0x1f < uVar2) {

      _Count = 0x20;

    }

    _Dest = &DAT_00632f48;

    break;

  case 0x15:

    _DAT_0063323c = *_Source;

    _Source = piVar4 + 3;

    goto switchD_004260b3_caseD_1;

  case 0x16:

    DAT_0058c650 = piVar4 + 4;

    FUN_00452b00(*_Source,piVar4[3],1);

    DAT_0059d99c = 1;

    _Source = DAT_0058c650;

    goto switchD_004260b3_caseD_1;

  case 0x17:

    _DAT_00632ffc = *_Source;

    DAT_00632ff0 = (uint)(0 < _DAT_00632ffc);

    _Source = piVar4 + 3;

    goto switchD_004260b3_caseD_1;

  case 0x18:

    goto switchD_004260b3_caseD_18;

  case 0x19:

    uVar2 = 0xffffffff;

    piVar4 = _Source;

    do {

      if (uVar2 == 0) break;

      uVar2 = uVar2 - 1;

      iVar1 = *piVar4;

      piVar4 = (int *)((int)piVar4 + 1);

    } while ((char)iVar1 != '\0');

    uVar2 = ~uVar2 - 1;

    if (uVar2 < 0x100) {

      _Dest = &DAT_00633260;

      _Count = uVar2;

    }

    else {

      _Count = 0x100;

      _Dest = &DAT_00633260;

    }

  }

  _strncpy(_Dest,(char *)_Source,_Count);

  _Source = (int *)(uVar2 + 1 + (int)_Source);

  goto switchD_004260b3_caseD_1;

switchD_004260b3_caseD_18:

  DAT_0058c654 = *_Source;

  _Source = piVar4 + 3;

  goto switchD_004260b3_caseD_1;

switchD_004260b3_caseD_4:

  iVar1 = FUN_00521330(DAT_00632f18);

  if (iVar1 != 0) {

    iVar3 = DAT_0058c654 + 1;

    DAT_0058c654 = iVar3;

    iVar1 = FUN_0051f2d0();

    if (0 < iVar3 - iVar1) {

      if (DAT_00633258 != 0) {

        comm_comm_00529e00();

        comm_0052b780_user_1(0);

        comm_0052b780_user_3(0);

        gamespy_statechange3();

        comm_game_setup_menu();

        DAT_0058c658 = 1;

      }

      DAT_005def7c = 2;

      return 0;

    }

  }

  comm_comm_00529e00();

  comm_0052b780_user_1(0);

  comm_0052b780_user_3(0);

  gamespy_statechange3();

  return 1;

}

/* ===== comm_00426540 @ 0x00426540 ===== */
undefined4 comm_00426540(void)



{

  int iVar1;

  

  if (DAT_00633238 != 0) {

    iVar1 = FUN_0052aa70();

    if (iVar1 != 0) {

      iVar1 = FUN_0052c5c0();

      if (iVar1 != 0) {

        return 1;

      }

    }

  }

  return 0;

}

/* ===== FUN_00426570 @ 0x00426570 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00426570(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int local_64 [3];

  float local_58;

  undefined4 local_54;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  undefined4 local_44;

  undefined4 local_40;

  undefined4 local_3c;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_20;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  int local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  if (DAT_00632d5c != 0) {

    local_58 = DAT_00632e6c - _DAT_005999cc;

    DAT_0058c660 = DAT_0058c660 + 1;

    piVar5 = (int *)0x0;

    iVar4 = 0;

    if (0 < DAT_005999b4) {

      do {

        if ((&DAT_0059a1a0)[iVar4] != 0) {

          iVar1 = (&DAT_005999d0)[iVar4];

          if ((char)((uint)*(undefined4 *)(iVar1 + 0xd8) >> 8) < '\0') {

            (&DAT_0059a1a0)[iVar4] = 0;

            (&DAT_005999d0)[iVar4] = 0;

          }

          else {

            iVar2 = FUN_004a6180(iVar1);

            if ((((iVar2 != 0) || (iVar2 = FUN_004a6160(iVar1), iVar2 != 0)) ||

                (iVar2 = FUN_004a61a0(iVar1), iVar2 != 0)) &&

               ((iVar2 = FUN_004a6160(iVar1), iVar2 == 0 || (*(int *)(iVar1 + 0x174) == 0)))) {

              if (piVar5 != (int *)0x0) {

                FUN_00517900(DAT_005999c4,piVar5,100);

              }

              iVar2 = FUN_004a6180(iVar1);

              if (iVar2 == 0) {

                iVar2 = FUN_004a6160(iVar1);

                if (iVar2 != 0) {

                  iVar2 = *(int *)(iVar1 + 0x100);

                  if (*(int *)(iVar2 + 0xdc) == 0) {

                    local_c = -1;

                  }

                  else {

                    iVar3 = 0;

                    local_c = -1;

                    if (0 < DAT_005999b4) {

                      do {

                        if (((&DAT_0059a1a0)[iVar3] != 0) &&

                           (local_c = iVar3, (&DAT_005999d0)[iVar3] == *(int *)(iVar2 + 0xdc)))

                        goto LAB_004266c5;

                        iVar3 = iVar3 + 1;

                      } while (iVar3 < DAT_005999b4);

                      local_c = -1;

                    }

                  }

LAB_004266c5:

                  local_18 = *(undefined4 *)(iVar2 + 0xe0);

                  local_14 = *(undefined4 *)(iVar2 + 0xe4);

                  local_10 = *(undefined4 *)(iVar2 + 0xe8);

                }

              }

              else {

                local_8 = *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0xdb0);

                local_4 = *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0xcec);

              }

              local_4c = *(undefined4 *)(iVar1 + 0xa0);

              local_48 = *(undefined4 *)(iVar1 + 0xa4);

              local_44 = *(undefined4 *)(iVar1 + 0xa8);

              local_40 = *(undefined4 *)(iVar1 + 200);

              local_3c = *(undefined4 *)(iVar1 + 0xd4);

              local_38 = *(undefined4 *)(iVar1 + 0xcc);

              local_34 = *(undefined4 *)(iVar1 + 0xd0);

              local_30 = *(undefined4 *)(iVar1 + 0x108);

              local_2c = *(undefined4 *)(iVar1 + 0x10c);

              local_28 = *(undefined4 *)(iVar1 + 0x110);

              local_20 = *(undefined4 *)(iVar1 + 0x114);

              local_54 = *(undefined4 *)(iVar1 + 0x208);

              local_50 = *(undefined4 *)(iVar1 + 0x20c);

              local_64[1] = 0;

              piVar5 = local_64;

              local_64[0] = iVar4;

            }

          }

        }

        iVar4 = iVar4 + 1;

      } while (iVar4 < DAT_005999b4);

      if (piVar5 != (int *)0x0) {

        piVar5[1] = 1;

        FUN_00517900(DAT_005999c4,piVar5,100);

      }

    }

  }

  return;

}

/* ===== dialog_level_is_base @ 0x00426ED0 ===== */
/* PS2 candidate: sound_setup_sequence (conf 0.532) */



bool dialog_level_is_base(void)



{

  return DAT_00556498 == -1;

}

/* ===== FUN_00426ee0 @ 0x00426EE0 ===== */
/* PS2 candidate: dialog_level_process (conf 0.323) */



void FUN_00426ee0(void)



{

  if (DAT_00556498 != -1) {

    FUN_00535390();

    FUN_00531470();

    if (DAT_00556498 != -1) {

                    /* WARNING: Could not recover jumptable at 0x00426f00. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*(code *)(&DAT_0059ab80)[DAT_00556498 * 5])();

      return;

    }

  }

  FUN_00471a60(1);

  return;

}

/* ===== FUN_00426f20 @ 0x00426F20 ===== */
void FUN_00426f20(void)



{

  if (DAT_00556498 == -1) {

    FUN_00471dc0();

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x00426f32. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*(code *)(&DAT_0059ab84)[DAT_00556498 * 5])();

  return;

}

/* ===== dlog_push_level @ 0x00426F40 ===== */
void dlog_push_level(undefined4 param_1,undefined4 param_2)



{

  int iVar1;

  

  if (9 < DAT_00556498) {

    FUN_00425eb0(s_FOverflow_of_dialog_level_stack_005564a3 + 1);

    DAT_00556498 = DAT_00556498 + -1;

  }

  iVar1 = DAT_00556498 + 1;

  DAT_00556498 = iVar1;

  (&DAT_0059ab80)[iVar1 * 5] = param_1;

  (&DAT_0059ab84)[iVar1 * 5] = param_2;

  (&DAT_0059ab88)[iVar1 * 5] = 0;

  (&DAT_0059ab8c)[iVar1 * 5] = 0;

  (&DAT_0059ab90)[iVar1 * 5] = 0;

  return;

}

/* ===== FUN_00426FA0 @ 0x00426FA0 ===== */
/* PS2 candidate: dialog_level_set_textentry_mode (conf 0.851) */



void FUN_00426FA0(void)



{

  if (DAT_00556498 != -1) {

    (&DAT_0059ab90)[DAT_00556498 * 5] = 1;

    FUN_0041f0f0(1);

  }

  return;

}

/* ===== dialog_level_pop @ 0x00426FD0 ===== */
/* PS2 candidate: dialog_level_pop (conf 0.521) */



void dialog_level_pop(int param_1)



{

  if (DAT_00556498 < 0) {

    FUN_00425eb0(s_Underflow_of_dialog_level_stack_005564c4);

    DAT_00556498 = 0;

  }

  else if ((&DAT_0059ab80)[DAT_00556498 * 5] != param_1) {

    FUN_00425eb0();

    return;

  }

  DAT_00556498 = DAT_00556498 + -1;

  if (-1 < DAT_00556498) {

    FUN_0041f0f0((&DAT_0059ab90)[DAT_00556498 * 5]);

    return;

  }

  FUN_00518890();

  FUN_0041f0f0(0);

  return;

}

/* ===== dlog_swap_check @ 0x00427040 ===== */
void dlog_swap_check(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  uint uVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  undefined4 local_14 [5];

  

  if (DAT_00556498 < 1) {

    return;

  }

  iVar1 = 0;

  if (-1 < DAT_00556498) {

    piVar2 = &DAT_0059ab80;

    while (*piVar2 != param_1) {

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 5;

      if (DAT_00556498 < iVar1) {

        FUN_00425eb0(s_Swap_mismatch_005564f4);

        return;

      }

    }

    if (iVar1 <= DAT_00556498) {

      puVar5 = &DAT_0059ab80 + iVar1 * 5;

      puVar6 = local_14;

      for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar6 = *puVar5;

        puVar5 = puVar5 + 1;

        puVar6 = puVar6 + 1;

      }

      if (iVar1 < DAT_00556498) {

        iVar3 = DAT_00556498 - iVar1;

        puVar5 = &DAT_0059ab94 + iVar1 * 5;

        puVar6 = &DAT_0059ab80 + iVar1 * 5;

        for (uVar4 = iVar3 * 5 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {

          *puVar6 = *puVar5;

          puVar5 = puVar5 + 1;

          puVar6 = puVar6 + 1;

        }

        iVar1 = iVar1 + iVar3;

      }

      puVar5 = local_14;

      puVar6 = &DAT_0059ab80 + iVar1 * 5;

      for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar6 = *puVar5;

        puVar5 = puVar5 + 1;

        puVar6 = puVar6 + 1;

      }

      return;

    }

  }

  FUN_00425eb0(s_Swap_mismatch_005564f4);

  return;

}

/* ===== Audio3DTestToneUpdate__Fv @ 0x004270F0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void Audio3DTestToneUpdate__Fv(void)



{

  DAT_00556498 = 0xffffffff;

  return;

}

/* ===== FUN_00427100 @ 0x00427100 ===== */
/* PS2 candidate: __main (conf 0.629) */



void FUN_00427100(void)



{

  if (DAT_00633044 != 0) {

    status_draw_sub(&DAT_00632900);

    return;

  }

  cursor_texture_draw();

  return;

}

/* ===== FUN_00427120 @ 0x00427120 ===== */
/* PS2 candidate: ANM_DumpCluster_13 (conf 0.525) */



void FUN_00427120(void)



{

  DAT_00632abc = (float)DAT_00632e84 * 0.5;

  DAT_00632ac0 = (float)DAT_00632e88 * 0.5;

  return;

}

/* ===== main/dlog_004272e0 @ 0x004272E0 ===== */
float10 main_dlog_004272e0(void)



{

  return (float10)0.03125;

}

/* ===== GetCurrentPos__C11CByteStream_2 @ 0x004272F0 ===== */
undefined4 GetCurrentPos__C11CByteStream_2(int param_1)



{

  return *(undefined4 *)(param_1 + 8);

}

/* ===== MAP_MemGroupSetBase_2 @ 0x00427300 ===== */
void MAP_MemGroupSetBase_2(int param_1,undefined4 param_2)



{

  *(undefined4 *)(param_1 + 8) = param_2;

  return;

}

/* ===== main/dlog_00427310 @ 0x00427310 ===== */
undefined4 main_dlog_00427310(undefined4 *param_1)



{

  float fVar1;

  float fVar2;

  

  param_1 = (undefined4 *)*param_1;

  fVar1 = DAT_00632abc / (float)DAT_00632e84;

  fVar2 = 1.0 - DAT_00632ac0 / (float)DAT_00632e88;

  while( true ) {

    if (param_1 == (undefined4 *)0x0) {

      return 0;

    }

    if (((param_1[2] != 0) &&

        (((param_1[1] != 0 || ((*(byte *)(param_1 + 3) & 2) != 0)) && ((float)param_1[7] <= fVar1)))

        ) && (((fVar1 < (float)param_1[8] != (fVar1 == (float)param_1[8]) &&

               ((float)param_1[6] <= fVar2)) &&

              (fVar2 < (float)param_1[9] != (fVar2 == (float)param_1[9]))))) break;

    param_1 = (undefined4 *)*param_1;

  }

  return param_1[2];

}

/* ===== dlog_00427570 @ 0x00427570 ===== */
void dlog_00427570(undefined4 param_1,float param_2)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  float10 fVar6;

  float10 fVar7;

  float local_c;

  float local_8;

  float local_4;

  

  iVar3 = (int)param_2;

  if ((*(byte *)((int)param_2 + 0xc) & 4) == 0) {

    fVar7 = (float10)FUN_0051bc00(*(undefined4 *)((int)param_2 + 0x30));

    fVar6 = (float10)dlog_0051bd30(*(undefined4 *)((int)param_2 + 0x30),

                                   *(undefined4 *)((int)param_2 + 0x28));

    param_2 = (float)fVar6;

  }

  else {

    pcVar4 = *(char **)((int)param_2 + 0x28);

    cVar2 = *pcVar4;

    local_c = 0.0;

    param_2 = 0.0;

    pcVar5 = pcVar4;

    while (cVar2 != '\0') {

      if (cVar2 == '\n') {

        fVar6 = (float10)FUN_0051bc90(*(undefined4 *)(iVar3 + 0x30),pcVar5,(int)pcVar4 - (int)pcVar5

                                     );

        if ((float10)param_2 < fVar6) {

          param_2 = (float)fVar6;

        }

        pcVar5 = pcVar4 + 1;

        local_c = (float)((int)local_c + 1);

      }

      pcVar1 = pcVar4 + 1;

      pcVar4 = pcVar4 + 1;

      cVar2 = *pcVar1;

    }

    fVar6 = (float10)FUN_0051bc90(*(undefined4 *)(iVar3 + 0x30),pcVar5,(int)pcVar4 - (int)pcVar5);

    if ((float10)param_2 < fVar6) {

      param_2 = (float)fVar6;

    }

    if ((pcVar5 < pcVar4) && (pcVar4[-1] == '\n')) {

      local_c = (float)((int)local_c + -1);

    }

    fVar7 = (float10)FUN_0051bc00(*(undefined4 *)(iVar3 + 0x30));

    fVar7 = fVar7 * (float10)(int)local_c;

  }

  local_c = (float)fVar7;

  dlog_004276a0(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 0x10),

                *(undefined4 *)(iVar3 + 0x14),param_2,local_c,&local_4,&local_8);

  *(float *)(iVar3 + 0x24) = local_8 + local_c;

  *(float *)(iVar3 + 0x18) = local_8;

  *(float *)(iVar3 + 0x1c) = local_4;

  *(float *)(iVar3 + 0x20) = local_4 + param_2;

  return;

}

/* ===== dlog_004276a0 @ 0x004276A0 ===== */
void dlog_004276a0(uint param_1,float param_2,float param_3,float param_4,float param_5,

                  float *param_6,float *param_7)



{

  uint uVar1;

  uint uVar2;

  float10 fVar3;

  

  uVar2 = param_1;

  uVar1 = param_1 & 0x1000000;

  param_1 = 0x3ccccccd;

  if (uVar1 == 0) {

    param_1 = 0x3d000000;

  }

  fVar3 = (float10)FUN_0051bc00(param_1);

  if ((int)uVar2 < 0) {

    fVar3 = fVar3 * (float10)param_3;

    if (param_3 < 0.0) {

      fVar3 = fVar3 + (float10)1.0;

    }

    param_3 = (float)fVar3;

  }

  if ((uVar2 & 0x10000000) == 0) {

    if ((uVar2 & 0x20000000) != 0) {

      *param_7 = param_3 - param_5 * 0.5;

      goto LAB_00427749;

    }

    if ((uVar2 & 0x40000000) != 0) {

      fVar3 = (float10)FUN_0051bc70(param_1);

      *param_7 = (float)((float10)param_3 - fVar3);

      goto LAB_00427749;

    }

  }

  else {

    param_3 = param_3 - param_5;

  }

  *param_7 = param_3;

LAB_00427749:

  if ((uVar2 & 0x4000000) != 0) {

    *param_6 = param_2 - param_4;

    return;

  }

  if ((uVar2 & 0x8000000) == 0) {

    *param_6 = param_2;

    return;

  }

  *param_6 = param_2 - param_4 * 0.5;

  return;

}

/* ===== comm_00427860 @ 0x00427860 ===== */
void comm_00427860(int *param_1,int param_2,int param_3)



{

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    while (param_1[2] != param_2) {

      param_1 = (int *)*param_1;

      if (param_1 == (int *)0x0) {

        return;

      }

    }

    if (param_1 != (int *)0x0) {

      param_1[0xb] = param_3;

    }

  }

  return;

}

/* ===== dlog_screen_user_1 @ 0x00427AC0 ===== */
void dlog_screen_user_1(int *param_1,float param_2)



{

  char cVar1;

  uint uVar2;

  int *piVar3;

  char *pcVar4;

  float10 fVar5;

  float10 fVar6;

  float local_4;

  

  piVar3 = (int *)*param_1;

  if (piVar3 != (int *)0x0) {

    while ((float)piVar3[2] != param_2) {

      piVar3 = (int *)*piVar3;

      if (piVar3 == (int *)0x0) {

        return;

      }

    }

    if (piVar3 != (int *)0x0) {

      fVar5 = (float10)FUN_0051bc00(piVar3[0xd]);

      fVar6 = (float10)dlog_0051bd30(piVar3[0xd],piVar3[10]);

      param_1 = (int *)(float)fVar6;

      fVar6 = (float10)dlog_0051bd30(piVar3[0xd],&DAT_005562b8);

      if ((float10)(float)param_1 < fVar6 * (float10)piVar3[0xb]) {

        param_1 = (int *)(float)(fVar6 * (float10)piVar3[0xb]);

      }

      dlog_004276a0(piVar3[3],piVar3[4],piVar3[5],param_1,(float)fVar5,&local_4,&param_2);

      piVar3[9] = (int)(param_2 + (float)fVar5);

      piVar3[7] = (int)local_4;

      piVar3[6] = (int)param_2;

      uVar2 = 0xffffffff;

      piVar3[8] = (int)(local_4 + (float)param_1);

      pcVar4 = (char *)piVar3[10];

      do {

        if (uVar2 == 0) break;

        uVar2 = uVar2 - 1;

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      if ((int)(~uVar2 - 1) < piVar3[0xc]) {

        uVar2 = 0xffffffff;

        pcVar4 = (char *)piVar3[10];

        do {

          if (uVar2 == 0) break;

          uVar2 = uVar2 - 1;

          cVar1 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

        piVar3[0xc] = ~uVar2 - 1;

      }

    }

  }

  return;

}

/* ===== main/dlog_00427e30 @ 0x00427E30 ===== */
void main_dlog_00427e30(undefined4 *param_1,int param_2,undefined4 param_3)



{

  param_1 = (undefined4 *)*param_1;

  while( true ) {

    if (param_1 == (undefined4 *)0x0) {

      uRam00000028 = param_3;

      return;

    }

    if (param_1[2] == param_2) break;

    param_1 = (undefined4 *)*param_1;

  }

  param_1[10] = param_3;

  return;

}

/* ===== main/dlog_00427e60 @ 0x00427E60 ===== */
undefined4 main_dlog_00427e60(undefined4 *param_1,int param_2)



{

  for (param_1 = (undefined4 *)*param_1; (param_1 != (undefined4 *)0x0 && (param_1[2] != param_2));

      param_1 = (undefined4 *)*param_1) {

  }

  return param_1[10];

}

/* ===== dlog_screen_user_2 @ 0x00427F00 ===== */
void dlog_screen_user_2(undefined4 param_1,float param_2)



{

  undefined4 *puVar1;

  uint uVar2;

  int iVar3;

  float fVar4;

  float10 fVar5;

  float local_c;

  int local_8;

  float local_4;

  

  iVar3 = (int)param_2;

  local_c = 0.025;

  if ((*(uint *)((int)param_2 + 0xc) & 0x1000000) == 0) {

    local_c = 0.03125;

  }

  fVar4 = local_c;

  puVar1 = *(undefined4 **)((int)param_2 + 0x28);

  local_8 = 0;

  param_2 = 0.01;

  for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    fVar5 = (float10)dlog_0051bd30(local_c,puVar1 + 4);

    if ((float10)param_2 < fVar5) {

      param_2 = (float)fVar5;

    }

    local_8 = local_8 + 1;

  }

  uVar2 = *(uint *)(iVar3 + 0xc);

  if ((uVar2 & 4) == 0) {

    if ((uVar2 & 8) == 0) {

      local_c = param_2;

      if ((uVar2 & 0x10) != 0) {

        local_c = param_2 * 4.0 + 0.070199996;

      }

    }

    else {

      local_c = param_2 * 3.0 + 0.0468;

    }

  }

  else {

    local_c = param_2 + param_2 + 0.0234;

  }

  if (0 < *(int *)(iVar3 + 0x34)) {

    local_8 = *(int *)(iVar3 + 0x34);

  }

  if ((char)uVar2 < '\0') {

    fVar5 = (float10)FUN_0051bc00(fVar4);

  }

  else {

    fVar5 = (float10)FUN_0051bc00(fVar4);

    fVar5 = fVar5 * (float10)local_8;

  }

  *(float *)(iVar3 + 0x38) = param_2;

  dlog_004276a0(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 0x10),

                *(undefined4 *)(iVar3 + 0x14),local_c,(float)fVar5,&local_4,&param_2);

  *(float *)(iVar3 + 0x24) = param_2 + (float)fVar5;

  *(float *)(iVar3 + 0x1c) = local_4;

  *(float *)(iVar3 + 0x18) = param_2;

  *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) & 0xfffffdff;

  *(float *)(iVar3 + 0x20) = local_4 + local_c;

  return;

}

/* ===== wredit_00428050 @ 0x00428050 ===== */
void wredit_00428050(undefined4 *param_1,int param_2,undefined4 param_3)



{

  for (param_1 = (undefined4 *)*param_1; (param_1 != (undefined4 *)0x0 && (param_1[2] != param_2));

      param_1 = (undefined4 *)*param_1) {

  }

  param_1[0xd] = param_3;

  param_1[3] = param_1[3] | 0x200;

  return;

}

/* ===== wredit_00428460 @ 0x00428460 ===== */
int wredit_00428460(int *param_1,int param_2)



{

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    while (param_1[2] != param_2) {

      param_1 = (int *)*param_1;

      if (param_1 == (int *)0x0) {

        return 0;

      }

    }

    if (param_1 != (int *)0x0) {

      return param_1[0xb];

    }

  }

  return 0;

}

/* ===== main/dlog_00428490 @ 0x00428490 ===== */
int main_dlog_00428490(int *param_1,int param_2)



{

  undefined4 *puVar1;

  int iVar2;

  

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    while (param_1[2] != param_2) {

      param_1 = (int *)*param_1;

      if (param_1 == (int *)0x0) {

        return 0;

      }

    }

    if (param_1 != (int *)0x0) {

      iVar2 = 0;

      for (puVar1 = (undefined4 *)param_1[10]; puVar1 != (undefined4 *)0x0;

          puVar1 = (undefined4 *)*puVar1) {

        iVar2 = iVar2 + 1;

      }

      return iVar2;

    }

  }

  return 0;

}

/* ===== wredit_004284d0 @ 0x004284D0 ===== */
void wredit_004284d0(int *param_1,int param_2,int param_3)



{

  undefined4 *puVar1;

  uint uVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  

  piVar3 = (int *)*param_1;

  piVar4 = piVar3;

  if (piVar3 == (int *)0x0) {

    return;

  }

  while (piVar4[2] != param_2) {

    piVar4 = (int *)*piVar4;

    if (piVar4 == (int *)0x0) {

      return;

    }

  }

  if (piVar4 == (int *)0x0) {

    return;

  }

  if (piVar3 != (int *)0x0) {

LAB_00428500:

    if (piVar3[2] != param_2) goto code_r0x00428505;

    if (piVar3 != (int *)0x0) {

      iVar5 = 0;

      for (puVar1 = (undefined4 *)piVar3[10]; puVar1 != (undefined4 *)0x0;

          puVar1 = (undefined4 *)*puVar1) {

        iVar5 = iVar5 + 1;

      }

      goto LAB_00428527;

    }

  }

  iVar5 = 0;

LAB_00428527:

  if ((param_3 < 0) || (iVar5 <= param_3)) {

    param_3 = 0;

  }

  iVar5 = piVar4[0xd];

  piVar4[0xb] = param_3;

  if (0 < iVar5) {

    uVar2 = piVar4[3];

    if ((uVar2 & 0x10) == 0) {

      if ((uVar2 & 8) == 0) {

        if ((uVar2 & 4) == 0) {

          if (piVar4[0xc] + iVar5 <= param_3) {

            piVar4[0xc] = (param_3 - iVar5) + 1;

          }

          if (piVar4[0xc] <= param_3) goto LAB_00428598;

        }

        else {

          param_3 = (param_3 / (iVar5 * 2)) * iVar5 * 2;

        }

      }

      else {

        param_3 = (param_3 / (iVar5 * 3)) * iVar5 * 3;

      }

    }

    else {

      param_3 = (param_3 / (iVar5 * 4)) * iVar5 * 4;

    }

    piVar4[0xc] = param_3;

  }

LAB_00428598:

  if ((piVar4[3] & 0x200U) != 0) {

    dlog_screen_user_2(param_1,piVar4);

  }

  return;

code_r0x00428505:

  piVar3 = (int *)*piVar3;

  if (piVar3 == (int *)0x0) goto code_r0x0042850b;

  goto LAB_00428500;

code_r0x0042850b:

  iVar5 = 0;

  goto LAB_00428527;

}

/* ===== main/dlog_004285b0 @ 0x004285B0 ===== */
int main_dlog_004285b0(int *param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  param_1 = (int *)*param_1;

  piVar1 = param_1;

  if (param_1 == (int *)0x0) {

LAB_004285d1:

    iVar2 = 0;

  }

  else {

    do {

      if (piVar1[2] == param_2) {

        if (piVar1 == (int *)0x0) goto LAB_004285d1;

        iVar2 = piVar1[0xb];

        goto LAB_004285d8;

      }

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)0x0);

    iVar2 = 0;

  }

LAB_004285d8:

  if (param_1 != (int *)0x0) {

    while (param_1[2] != param_2) {

      param_1 = (int *)*param_1;

      if (param_1 == (int *)0x0) {

        return 0;

      }

    }

    if (param_1 != (int *)0x0) {

      piVar1 = (int *)param_1[10];

      iVar3 = 0;

      if (piVar1 != (int *)0x0) {

        while (iVar3 != iVar2) {

          piVar1 = (int *)*piVar1;

          iVar3 = iVar3 + 1;

          if (piVar1 == (int *)0x0) {

            return 0;

          }

        }

        if (piVar1 != (int *)0x0) {

          return piVar1[1];

        }

      }

      return 0;

    }

  }

  return 0;

}

/* ===== wredit_004284d0_user @ 0x00428620 ===== */
void wredit_004284d0_user(int *param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  

  piVar1 = (int *)*param_1;

  if (piVar1 != (int *)0x0) {

    while (piVar1[2] != param_2) {

      piVar1 = (int *)*piVar1;

      if (piVar1 == (int *)0x0) {

        return;

      }

    }

    if (piVar1 != (int *)0x0) {

      piVar1 = (int *)piVar1[10];

      iVar2 = 0;

      if (piVar1 != (int *)0x0) {

        while (piVar1[1] != param_3) {

          piVar1 = (int *)*piVar1;

          iVar2 = iVar2 + 1;

          if (piVar1 == (int *)0x0) {

            return;

          }

        }

        wredit_004284d0(param_1,param_2,iVar2);

      }

    }

  }

  return;

}

/* ===== wredit_00428670 @ 0x00428670 ===== */
int wredit_00428670(int *param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    while (param_1[2] != param_2) {

      param_1 = (int *)*param_1;

      if (param_1 == (int *)0x0) {

        return 0;

      }

    }

    if (param_1 != (int *)0x0) {

      piVar1 = (int *)param_1[10];

      iVar2 = 0;

      if (piVar1 != (int *)0x0) {

        while (iVar2 != param_3) {

          piVar1 = (int *)*piVar1;

          iVar2 = iVar2 + 1;

          if (piVar1 == (int *)0x0) {

            return 0;

          }

        }

        if (piVar1 != (int *)0x0) {

          return piVar1[1];

        }

      }

      return 0;

    }

  }

  return 0;

}

/* ===== wredit_004287c0 @ 0x004287C0 ===== */
void wredit_004287c0(int *param_1,int param_2,int param_3,int param_4)



{

  int *piVar1;

  int iVar2;

  

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    while (param_1[2] != param_2) {

      param_1 = (int *)*param_1;

      if (param_1 == (int *)0x0) {

        return;

      }

    }

    if ((param_1 != (int *)0x0) && (piVar1 = (int *)param_1[10], piVar1 != (int *)0x0)) {

      iVar2 = 0;

      while (iVar2 != param_3) {

        piVar1 = (int *)*piVar1;

        iVar2 = iVar2 + 1;

        if (piVar1 == (int *)0x0) {

          return;

        }

      }

      if (piVar1 != (int *)0x0) {

        piVar1[2] = param_4;

      }

    }

  }

  return;

}

/* ===== FUN_00428810 @ 0x00428810 ===== */
void FUN_00428810(undefined4 *param_1)



{

  char *pcVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  char cVar6;

  undefined4 *puVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  char *pcVar11;

  char *pcVar12;

  undefined *puVar13;

  int iVar14;

  float10 fVar15;

  int local_14;

  float local_10;

  int local_c;

  undefined4 local_8;

  

  local_c = 0;

  do {

    for (puVar7 = (undefined4 *)*param_1; puVar7 != (undefined4 *)0x0;

        puVar7 = (undefined4 *)*puVar7) {

      iVar8 = -(uint)(param_1[2] != puVar7[2]);

      if (iVar8 + 1 == local_c) {

        switch(puVar7[1]) {

        case 0:

          if ((puVar7[0xd] == 0) || (puVar7[0xb] != 0)) {

            local_14 = puVar7[0xb];

            if (local_14 == 0) {

              local_14 = 0xffffff;

            }

            uVar10 = puVar7[3];

            if (((uVar10 & 8) != 0) && (uVar9 = __ftol(), (uVar9 & 1) != 0)) {

              local_14 = 0;

            }

            if ((uVar10 & 4) == 0) {

              FUN_0051b970(local_14,0,puVar7[0xc],puVar7[7],puVar7[6],puVar7[10]);

            }

            else {

              local_10 = (float)puVar7[6];

              pcVar11 = (char *)puVar7[10];

              cVar6 = *pcVar11;

              pcVar12 = pcVar11;

              while (cVar6 != '\0') {

                if (cVar6 == '\n') {

                  if (0 < (int)pcVar11 - (int)pcVar12) {

                    FUN_0051b9c0(local_14,0,puVar7[0xc],puVar7[7],local_10,pcVar12,

                                 (int)pcVar11 - (int)pcVar12);

                  }

                  pcVar12 = pcVar11 + 1;

                  fVar15 = (float10)FUN_0051bc00(puVar7[0xc]);

                  local_10 = (float)(fVar15 + (float10)local_10);

                }

                pcVar1 = pcVar11 + 1;

                pcVar11 = pcVar11 + 1;

                cVar6 = *pcVar1;

              }

              if (0 < (int)pcVar11 - (int)pcVar12) {

                FUN_0051b9c0(local_14,0,puVar7[0xc],puVar7[7],local_10,pcVar12,

                             (int)pcVar11 - (int)pcVar12);

              }

            }

          }

          break;

        case 1:

          if ((*(byte *)(puVar7 + 3) & 0x10) != 0) {

            FUN_004292b0(0xf0f0f,puVar7[7],puVar7[6],puVar7[8],puVar7[9]);

          }

          FUN_0051b970((-(uint)(iVar8 != -1) & 0x7f7e80) + 0x808080,0,puVar7[0xd],puVar7[7],

                       puVar7[6],puVar7[10]);

          if ((iVar8 != -1) && (uVar10 = __ftol(), (uVar10 & 1) != 0)) {

            fVar2 = (float)puVar7[0xd];

            puVar13 = &DAT_00556004;

            fVar3 = (float)puVar7[6];

            if (DAT_00556504 == 0) {

              puVar13 = &DAT_00556494;

            }

            fVar15 = (float10)FUN_0051bc90(puVar7[0xd],puVar7[10],puVar7[0xc]);

            FUN_0051b970(0xffff00,0,puVar7[0xd],(float)(fVar15 + (float10)(float)puVar7[7]),

                         fVar2 * 0.1 + fVar3,puVar13);

          }

          break;

        case 2:

          local_8 = 0x3ccccccd;

          if ((puVar7[3] & 0x1000000) == 0) {

            local_8 = 0x3d000000;

          }

          fVar2 = (float)puVar7[8];

          fVar3 = (float)puVar7[7];

          fVar4 = (float)puVar7[9];

          fVar5 = (float)puVar7[6];

          fVar15 = (float10)FUN_0051bc70(local_8);

          iVar14 = puVar7[10];

          if (iVar14 == 0) {

            iVar14 = (-(uint)(iVar8 != -1) & 0x7f7e80) + 0x808080;

          }

          FUN_0051ba00(iVar14,0,local_8,(fVar2 + fVar3) * 0.5,

                       (float)((float10)((fVar4 + fVar5) * 0.5) - fVar15 * (float10)0.5),puVar7[0xb]

                      );

          break;

        case 3:

          FUN_00428f70(param_1,puVar7);

          break;

        case 4:

          FUN_00428b20(param_1,puVar7);

        }

      }

    }

    local_c = local_c + 1;

  } while (local_c < 2);

  FUN_00427100();

  return;

}

/* ===== FUN_00428b20 @ 0x00428B20 ===== */
void FUN_00428b20(int param_1,int param_2)



{

  uint *puVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  int iVar6;

  float *pfVar7;

  int iVar8;

  float fVar9;

  float10 fVar10;

  

  iVar6 = param_2;

  fVar2 = *(float *)(param_2 + 0x18);

  fVar3 = *(float *)(param_2 + 0x24);

  fVar5 = (fVar3 - fVar2) * 0.25;

  fVar4 = *(float *)(param_2 + 0x1c);

  fVar9 = (float)((-(uint)(*(int *)(param_1 + 8) != *(int *)(param_2 + 8)) & 0xffdf7f20) + 0x3fffff)

  ;

  (**(code **)(DAT_00656428 + 8))(DAT_00656428,0xa0,0,0);

  pfVar7 = (float *)(**(code **)(DAT_00656434 + 0x10))(DAT_00656434,2);

  iVar8 = __ftol();

  *pfVar7 = (float)iVar8;

  iVar8 = __ftol();

  pfVar7[1] = (float)iVar8;

  iVar8 = __ftol();

  pfVar7[7] = (float)iVar8;

  iVar8 = __ftol();

  pfVar7[0xb] = fVar9;

  pfVar7[8] = (float)iVar8;

  pfVar7[4] = fVar9;

  (**(code **)(DAT_00656428 + 8))(DAT_00656428,0xa0,0,0);

  pfVar7 = (float *)(**(code **)(DAT_00656434 + 0x10))(DAT_00656434,2);

  iVar8 = __ftol();

  *pfVar7 = (float)iVar8;

  iVar8 = __ftol();

  pfVar7[1] = (float)iVar8;

  iVar8 = __ftol();

  pfVar7[7] = (float)iVar8;

  iVar8 = __ftol();

  pfVar7[0xb] = fVar9;

  pfVar7[8] = (float)iVar8;

  pfVar7[4] = fVar9;

  (**(code **)(DAT_00656428 + 8))(DAT_00656428,0xa0,0,0);

  pfVar7 = (float *)(**(code **)(DAT_00656434 + 0x10))(DAT_00656434,2);

  iVar8 = __ftol();

  *pfVar7 = (float)iVar8;

  iVar8 = __ftol();

  pfVar7[1] = (float)iVar8;

  iVar8 = __ftol();

  pfVar7[7] = (float)iVar8;

  iVar8 = __ftol();

  pfVar7[0xb] = fVar9;

  pfVar7[8] = (float)iVar8;

  pfVar7[4] = fVar9;

  (**(code **)(DAT_00656428 + 8))(DAT_00656428,0xa0,0,0);

  pfVar7 = (float *)(**(code **)(DAT_00656434 + 0x10))(DAT_00656434,2);

  iVar8 = __ftol();

  *pfVar7 = (float)iVar8;

  iVar8 = __ftol();

  pfVar7[1] = (float)iVar8;

  iVar8 = __ftol();

  pfVar7[7] = (float)iVar8;

  iVar8 = __ftol();

  pfVar7[0xb] = fVar9;

  pfVar7[4] = fVar9;

  pfVar7[8] = (float)iVar8;

  if (*(int *)(param_2 + 0x28) != 0) {

    (**(code **)(DAT_00656428 + 8))(DAT_00656428,0xa0,0,0);

    pfVar7 = (float *)(**(code **)(DAT_00656434 + 0x10))(DAT_00656434,2);

    iVar8 = __ftol();

    *pfVar7 = (float)iVar8;

    iVar8 = __ftol();

    pfVar7[1] = (float)iVar8;

    iVar8 = __ftol();

    pfVar7[7] = (float)iVar8;

    iVar8 = __ftol();

    pfVar7[0xb] = fVar9;

    pfVar7[8] = (float)iVar8;

    pfVar7[4] = fVar9;

    (**(code **)(DAT_00656428 + 8))(DAT_00656428,0xa0,0,0);

    pfVar7 = (float *)(**(code **)(DAT_00656434 + 0x10))(DAT_00656434,2);

    iVar8 = __ftol();

    *pfVar7 = (float)iVar8;

    iVar8 = __ftol();

    pfVar7[1] = (float)iVar8;

    iVar8 = __ftol();

    pfVar7[7] = (float)iVar8;

    iVar8 = __ftol();

    pfVar7[0xb] = fVar9;

    pfVar7[4] = fVar9;

    pfVar7[8] = (float)iVar8;

  }

  puVar1 = (uint *)(param_2 + 0xc);

  param_2 = 0x3ccccccd;

  if ((*puVar1 & 0x1000000) == 0) {

    param_2 = 0x3d000000;

  }

  fVar10 = (float10)FUN_0051bc70(param_2);

  FUN_0051b970(fVar9,0,param_2,fVar4 + fVar5 + fVar5 + 0.005,

               (float)((float10)((fVar3 + fVar2) * 0.5) - fVar10 * (float10)0.5),

               *(undefined4 *)(iVar6 + 0x2c));

  return;

}

/* ===== FUN_00428f70 @ 0x00428F70 ===== */
void FUN_00428f70(float param_1,float param_2)



{

  float fVar1;

  float fVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  undefined4 uVar9;

  int *piVar10;

  bool bVar11;

  float10 fVar12;

  undefined4 uVar13;

  float fVar14;

  undefined4 local_8;

  float local_4;

  

  iVar5 = (int)param_2;

  local_8 = 0x3ccccccd;

  if ((*(uint *)((int)param_2 + 0xc) & 0x1000000) == 0) {

    local_8 = 0x3d000000;

  }

  if ((*(uint *)((int)param_2 + 0xc) & 0x200) != 0) {

    dlog_screen_user_2(param_1,param_2);

  }

  uVar6 = *(uint *)((int)param_2 + 0xc) & 0x80;

  if ((uVar6 == 0) ||

     ((*(int *)((int)param_1 + 8) == *(int *)((int)param_2 + 8) && ((DAT_005dd238 & 1) != 0)))) {

    bVar11 = true;

  }

  else {

    bVar11 = false;

  }

  if (((*(int *)((int)param_1 + 8) == *(int *)((int)param_2 + 8)) &&

      ((*(uint *)((int)param_2 + 0xc) & 2) == 0)) && (bVar11)) {

    if (uVar6 == 0) {

      fVar14 = *(float *)((int)param_2 + 0x24);

      uVar9 = *(undefined4 *)((int)param_2 + 0x18);

      fVar1 = *(float *)((int)param_2 + 0x20);

      fVar2 = *(float *)((int)param_2 + 0x1c);

      uVar13 = 0x10101;

    }

    else {

      iVar7 = 0;

      for (puVar3 = *(undefined4 **)((int)param_2 + 0x28); puVar3 != (undefined4 *)0x0;

          puVar3 = (undefined4 *)*puVar3) {

        iVar7 = iVar7 + 1;

      }

      fVar12 = (float10)FUN_0051bc00(local_8);

      uVar9 = *(undefined4 *)((int)param_2 + 0x18);

      fVar14 = (float)(fVar12 * (float10)iVar7 + (float10)*(float *)((int)param_2 + 0x18));

      fVar1 = *(float *)((int)param_2 + 0x20);

      fVar2 = *(float *)((int)param_2 + 0x1c);

      uVar13 = 0x20202;

    }

    FUN_004292b0(uVar13,fVar2 - 0.01,uVar9,fVar1 + 0.01,fVar14);

  }

  if ((-1 < (char)*(uint *)((int)param_2 + 0xc)) || (bVar11)) {

    param_1 = *(float *)((int)param_2 + 0x18);

    iVar7 = 0;

    puVar3 = *(undefined4 **)((int)param_2 + 0x28);

    param_2 = *(float *)((int)param_2 + 0x1c);

    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

      iVar8 = *(int *)(iVar5 + 0x34);

      if (iVar8 < 1) {

LAB_004291b7:

        iVar8 = puVar3[2];

        if (iVar8 == 0) {

          iVar8 = ((*(int *)(iVar5 + 0x2c) != iVar7) - 1 & 0x8f8e90) + 0x707070;

        }

        else if (*(int *)(iVar5 + 0x2c) == iVar7) {

          fVar12 = (float10)FUN_0051bc00(local_8);

          FUN_004292b0(0x101010,param_2 - 0.01,param_1,param_2 + *(float *)(iVar5 + 0x38) + 0.01,

                       (float)(fVar12 + (float10)param_1));

        }

        if ((*(byte *)(iVar5 + 0xc) & 0x40) == 0) {

          local_4 = param_2;

        }

        else {

          fVar14 = *(float *)(iVar5 + 0x38);

          fVar12 = (float10)dlog_0051bd30(local_8,puVar3 + 4);

          local_4 = (float)((float10)(fVar14 * 0.5 + param_2) - fVar12 * (float10)0.5);

        }

        FUN_0051b970(iVar8,0,local_8,local_4,param_1,puVar3 + 4);

        fVar12 = (float10)FUN_0051bc00(local_8);

        param_1 = (float)(fVar12 + (float10)param_1);

      }

      else {

        iVar4 = *(int *)(iVar5 + 0x30);

        if (iVar4 <= iVar7) {

          if (iVar7 == iVar4 + iVar8) {

            bVar11 = (*(byte *)(iVar5 + 0xc) & 0x1c) == 0;

          }

          else if (iVar7 == iVar4 + iVar8 * 2) {

            bVar11 = (*(byte *)(iVar5 + 0xc) & 0x18) == 0;

          }

          else {

            if (iVar7 != iVar8 + iVar4 + iVar8 * 2) {

              if (iVar7 == iVar4 + iVar8 * 4) {

                return;

              }

              goto LAB_004291b7;

            }

            bVar11 = (*(byte *)(iVar5 + 0xc) & 0x10) == 0;

          }

          if (bVar11) {

            return;

          }

          param_1 = *(float *)(iVar5 + 0x18);

          param_2 = param_2 + *(float *)(iVar5 + 0x38) + 0.0234;

          goto LAB_004291b7;

        }

      }

      iVar7 = iVar7 + 1;

    }

  }

  else {

    piVar10 = *(int **)((int)param_2 + 0x28);

    iVar7 = 0;

    if (piVar10 != (int *)0x0) {

      while (*(int *)((int)param_2 + 0x2c) != iVar7) {

        piVar10 = (int *)*piVar10;

        iVar7 = iVar7 + 1;

        if (piVar10 == (int *)0x0) {

          return;

        }

      }

      if (piVar10 != (int *)0x0) {

        uVar9 = 0x707070;

        if (*(int *)((int)param_1 + 8) == *(int *)((int)param_2 + 8)) {

          uVar9 = 0xffff00;

        }

        if ((*(uint *)((int)param_2 + 0xc) & 0x40) == 0) {

          param_2 = *(float *)((int)param_2 + 0x1c);

        }

        else {

          fVar14 = *(float *)((int)param_2 + 0x38);

          fVar1 = *(float *)((int)param_2 + 0x1c);

          fVar12 = (float10)dlog_0051bd30(local_8,piVar10 + 4);

          param_2 = (float)((float10)(fVar14 * 0.5 + fVar1) - fVar12 * (float10)0.5);

        }

        FUN_0051b970(uVar9,0,local_8,param_2,*(undefined4 *)(iVar5 + 0x18),piVar10 + 4);

        return;

      }

    }

  }

  return;

}

/* ===== FUN_004292b0 @ 0x004292B0 ===== */
void FUN_004292b0(float param_1)



{

  float *pfVar1;

  int iVar2;

  

  (**(code **)(DAT_00656428 + 8))(DAT_00656428,0xa0,0,0);

  pfVar1 = (float *)(**(code **)(DAT_00656438 + 0x10))(DAT_00656438,4);

  iVar2 = __ftol();

  *pfVar1 = (float)iVar2;

  iVar2 = __ftol();

  pfVar1[1] = (float)iVar2;

  iVar2 = __ftol();

  pfVar1[7] = (float)iVar2;

  iVar2 = __ftol();

  pfVar1[8] = (float)iVar2;

  iVar2 = __ftol();

  pfVar1[0xe] = (float)iVar2;

  iVar2 = __ftol();

  pfVar1[0xf] = (float)iVar2;

  iVar2 = __ftol();

  pfVar1[0x15] = (float)iVar2;

  iVar2 = __ftol();

  pfVar1[0x19] = param_1;

  pfVar1[0x12] = param_1;

  pfVar1[0x16] = (float)iVar2;

  pfVar1[0xb] = param_1;

  pfVar1[4] = param_1;

  return;

}

/* ===== FUN_004293d0 @ 0x004293D0 ===== */
void FUN_004293d0(undefined4 param_1,float param_2,float param_3)



{

  undefined4 uVar1;

  undefined4 uVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  int iVar6;

  float *pfVar7;

  int iVar8;

  

  iVar8 = 0;

  do {

    if ((undefined4 *)(&DAT_0059ac48)[iVar8] == (undefined4 *)0x0) {

      iVar6 = main_texture_00508750(param_1);

      (&DAT_0059ac48)[iVar8] = iVar6;

LAB_00429420:

      if (iVar6 != 0) {

        (**(code **)(DAT_00656428 + 8))(DAT_00656428,0x32c,iVar6,0xff000000);

        fVar3 = (float)DAT_00632e84;

        uVar1 = *(undefined4 *)(iVar6 + 0xc);

        param_2 = param_2 * fVar3;

        uVar2 = *(undefined4 *)(iVar6 + 0x10);

        fVar5 = (float)DAT_00632e88;

        fVar4 = (1.0 - param_3) * fVar5;

        pfVar7 = (float *)(**(code **)(DAT_00656438 + 0x10))(DAT_00656438,4);

        fVar3 = (float)(1 << ((byte)uVar1 & 0x1f)) * fVar3 * 0.00093750004 + param_2;

        *pfVar7 = param_2;

        pfVar7[7] = fVar3;

        pfVar7[6] = 1.0;

        pfVar7[0xe] = fVar3;

        pfVar7[0xc] = 1.0;

        pfVar7[0xd] = 1.0;

        fVar3 = (float)(1 << ((byte)uVar2 & 0x1f)) * fVar5 * 0.0012500001 + fVar4;

        pfVar7[0x13] = 1.0;

        pfVar7[0xf] = fVar3;

        pfVar7[1] = fVar4;

        pfVar7[0x16] = fVar3;

        pfVar7[5] = 0.0;

        pfVar7[8] = fVar4;

        pfVar7[0x14] = 0.0;

        pfVar7[0x15] = param_2;

        pfVar7[0x1a] = 0.0;

        pfVar7[0x1b] = 0.0;

      }

      return;

    }

    iVar6 = FUN_00545650(*(undefined4 *)(&DAT_0059ac48)[iVar8]);

    if (iVar6 == 0) {

      iVar6 = (&DAT_0059ac48)[iVar8];

      goto LAB_00429420;

    }

    iVar8 = iVar8 + 1;

    if (9 < iVar8) {

      return;

    }

  } while( true );

}

/* ===== comm_player_actions_menu @ 0x00429510 ===== */
void comm_player_actions_menu(undefined4 *param_1)



{

  char *pcVar1;

  undefined4 uVar2;

  float fVar3;

  

  param_1 = (undefined4 *)*param_1;

  do {

    if (param_1 == (undefined4 *)0x0) {

      return;

    }

    if ((param_1[1] == 0) && (param_1[0xd] != 0)) {

      switch(param_1[0xd]) {

      case 1:

        fVar3 = (float)param_1[9] - 0.005;

        uVar2 = param_1[7];

        pcVar1 = s_i_unmute_0055655c;

        break;

      case 2:

        uVar2 = param_1[7];

        fVar3 = (float)param_1[9] - 0.005;

        pcVar1 = s_i_mute_00556554;

        break;

      case 3:

        uVar2 = param_1[7];

        fVar3 = (float)param_1[9] - 0.005;

        pcVar1 = s_i_kick_0055654c;

        break;

      case 4:

        fVar3 = (float)param_1[9] - 0.005;

        uVar2 = param_1[7];

        pcVar1 = s_i_ishost_00556540;

        break;

      default:

        goto switchD_00429534_default;

      }

      FUN_004293d0(pcVar1,uVar2,fVar3);

    }

switchD_00429534_default:

    param_1 = (undefined4 *)*param_1;

  } while( true );

}

/* ===== cursor_texture_draw @ 0x004295C0 ===== */
void cursor_texture_draw(void)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float *pfVar4;

  

  fVar3 = DAT_00632ac0;

  fVar2 = DAT_00632abc;

  if (DAT_0059ac70 == 0) {

    DAT_0059ac70 = main_texture_00508750(s_cursor_00556568);

  }

  (**(code **)(DAT_00656428 + 8))(DAT_00656428,0x32c,DAT_0059ac70,0xff000000);

  pfVar4 = (float *)(**(code **)(DAT_00656438 + 0x10))(DAT_00656438,4);

  *pfVar4 = fVar2 - (float)DAT_00632e84 * 0.02;

  fVar1 = (float)DAT_00632e84;

  pfVar4[5] = 0.0;

  pfVar4[6] = 1.0;

  pfVar4[1] = fVar3 - (fVar1 * 0.02 + fVar1 * 0.02);

  pfVar4[7] = (float)DAT_00632e84 * 0.02 + fVar2;

  fVar1 = (float)DAT_00632e84;

  pfVar4[0xc] = 1.0;

  pfVar4[0xd] = 1.0;

  pfVar4[8] = fVar3 - (fVar1 * 0.02 + fVar1 * 0.02);

  fVar1 = (float)DAT_00632e84;

  pfVar4[0x13] = 1.0;

  pfVar4[0x14] = 0.0;

  pfVar4[0xf] = fVar3;

  pfVar4[0xe] = fVar1 * 0.02 + fVar2;

  fVar1 = (float)DAT_00632e84;

  pfVar4[0x1a] = 0.0;

  pfVar4[0x1b] = 0.0;

  pfVar4[0x16] = fVar3;

  pfVar4[0x15] = fVar2 - fVar1 * 0.02;

  return;

}

/* ===== FUN_004296c0 @ 0x004296C0 ===== */
void FUN_004296c0(int *param_1)



{

  undefined4 *puVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  int *piVar5;

  int *piVar6;

  undefined4 *puVar7;

  undefined4 *puVar8;

  int *piVar9;

  

  if (param_1 != (int *)0x0) {

    param_1[1] = param_1[1] & 0xfffffffe;

    if (param_1[2] == -1) {

      puVar1 = (undefined4 *)*param_1;

      for (puVar8 = puVar1; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {

        if (puVar8[2] == -1) {

          if ((puVar8 != (undefined4 *)0x0) &&

             (puVar8 = (undefined4 *)*puVar8, puVar7 = puVar8, puVar8 != (undefined4 *)0x0))

          goto LAB_00429710;

          break;

        }

      }

      puVar8 = puVar1;

      puVar7 = puVar1;

      if (puVar1 != (undefined4 *)0x0) {

LAB_00429710:

        do {

          if (((puVar8[2] != 0) && (puVar8[1] != 0)) &&

             ((puVar8[1] != 3 || ((*(byte *)(puVar8 + 3) & 1) == 0)))) break;

          puVar8 = (undefined4 *)*puVar8;

          if (puVar8 == (undefined4 *)0x0) {

            puVar8 = puVar1;

          }

        } while (puVar8 != puVar7);

        if (puVar8[2] != -1) {

          sound_play(0x65a);

        }

        param_1[2] = puVar8[2];

        param_1[1] = param_1[1] | 1;

      }

    }

    if (DAT_00632aba != '\0') {

      piVar6 = (int *)*param_1;

      if (piVar6 != (int *)0x0) {

        piVar5 = piVar6;

        do {

          if (piVar5[2] == param_1[2]) {

            if ((piVar5 != (int *)0x0) &&

               (piVar5 = (int *)*piVar5, piVar9 = piVar5, piVar5 != (int *)0x0)) goto LAB_00429782;

            break;

          }

          piVar5 = (int *)*piVar5;

        } while (piVar5 != (int *)0x0);

      }

      piVar5 = piVar6;

      piVar9 = piVar6;

      if (piVar6 != (int *)0x0) {

LAB_00429782:

        do {

          if (((piVar5[2] != 0) && (piVar5[1] != 0)) &&

             ((piVar5[1] != 3 || ((*(byte *)(piVar5 + 3) & 1) == 0)))) break;

          piVar5 = (int *)*piVar5;

          if (piVar5 == (int *)0x0) {

            piVar5 = piVar6;

          }

        } while (piVar5 != piVar9);

        if (param_1[2] != piVar5[2]) {

          sound_play(0x65a);

        }

        param_1[2] = piVar5[2];

        param_1[1] = param_1[1] | 1;

      }

    }

    if (DAT_00632aab != '\0') {

      fVar3 = DAT_00632abc / (float)DAT_00632e84;

      fVar4 = 1.0 - DAT_00632ac0 / (float)DAT_00632e88;

      for (puVar1 = (undefined4 *)*param_1; puVar1 != (undefined4 *)0x0;

          puVar1 = (undefined4 *)*puVar1) {

        if (((((puVar1[2] != 0) && (puVar1[1] != 0)) && ((float)puVar1[7] <= fVar3)) &&

            ((fVar3 < (float)puVar1[8] != (fVar3 == (float)puVar1[8]) && ((float)puVar1[6] <= fVar4)

             ))) && (fVar4 < (float)puVar1[9] != (fVar4 == (float)puVar1[9]))) {

          iVar2 = puVar1[2];

          if ((0 < iVar2) && (param_1[2] != iVar2)) {

            param_1[2] = iVar2;

            param_1[1] = param_1[1] | 1;

          }

          break;

        }

      }

    }

    piVar6 = (int *)*param_1;

    if (piVar6 != (int *)0x0) {

      while (piVar6[2] != param_1[2]) {

        piVar6 = (int *)*piVar6;

        if (piVar6 == (int *)0x0) {

          return;

        }

      }

      if (piVar6 != (int *)0x0) {

        switch(piVar6[1]) {

        case 1:

          dlog_screen_user_big(param_1,piVar6);

          return;

        case 2:

          if (((char)DAT_00632aa4 != '\0') || (DAT_00632aa0._2_1_ != '\0')) {

            FUN_0042a3e0(param_1);

            return;

          }

          if ((DAT_00632aa0._3_1_ != '\0') || (DAT_00632aa0._1_1_ != '\0')) {

            FUN_0042a460(param_1);

            return;

          }

          break;

        case 3:

          FUN_00429e10(param_1,piVar6);

          return;

        case 4:

          fVar3 = DAT_00632abc / (float)DAT_00632e84;

          fVar4 = 1.0 - DAT_00632ac0 / (float)DAT_00632e88;

          if ((((DAT_00632aab != '\0') && ((float)piVar6[6] - 0.0125 <= fVar4)) &&

              (fVar4 < (float)piVar6[9] + 0.0125 != (fVar4 == (float)piVar6[9] + 0.0125))) &&

             (((float)piVar6[7] <= fVar3 &&

              (fVar3 < (float)piVar6[8] != (fVar3 == (float)piVar6[8]))))) {

            piVar6[10] = (uint)(piVar6[10] == 0);

            return;

          }

        }

      }

    }

  }

  return;

}

/* ===== dlog_screen_user_big @ 0x00429990 ===== */
void dlog_screen_user_big(undefined4 param_1,float param_2)



{

  int *piVar1;

  char cVar2;

  char cVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  char *pcVar8;

  int iVar9;

  char *pcVar10;

  uint uVar11;

  int iVar12;

  int iVar13;

  float10 fVar14;

  float10 fVar15;

  float local_10;

  float local_c;

  float local_8;

  char *local_4;

  

  iVar7 = (int)param_2;

  if (DAT_00632aa0._3_1_ != '\0') {

    piVar1 = (int *)((int)param_2 + 0x30);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      *(undefined4 *)((int)param_2 + 0x30) = 0;

    }

    goto LAB_00429b07;

  }

  if ((char)DAT_00632aa4 == '\0') {

    if (DAT_00632ab9 != '\0') goto LAB_00429b07;

    if (DAT_00632ab3 != '\0') {

      uVar11 = 0xffffffff;

      pcVar8 = *(char **)((int)param_2 + 0x28);

      do {

        if (uVar11 == 0) break;

        uVar11 = uVar11 - 1;

        cVar3 = *pcVar8;

        pcVar8 = pcVar8 + 1;

      } while (cVar3 != '\0');

      if (*(int *)((int)param_2 + 0x30) < (int)(~uVar11 - 1)) {

        pcVar10 = *(char **)((int)param_2 + 0x28) + *(int *)((int)param_2 + 0x30);

        pcVar8 = pcVar10;

        do {

          pcVar8 = pcVar8 + 1;

          cVar3 = *pcVar8;

          *pcVar10 = cVar3;

          pcVar10 = pcVar10 + 1;

        } while (cVar3 != '\0');

        fVar15 = (float10)FUN_0051bc00(*(undefined4 *)((int)param_2 + 0x34));

        local_c = (float)fVar15;

        fVar15 = (float10)dlog_0051bd30(*(undefined4 *)((int)param_2 + 0x34),

                                        *(undefined4 *)((int)param_2 + 0x28));

        fVar14 = (float10)dlog_0051bd30(*(undefined4 *)((int)param_2 + 0x34),&DAT_005562b8);

        fVar14 = fVar14 * (float10)*(int *)((int)param_2 + 0x2c);

        param_2 = (float)fVar15;

        if ((float10)(float)fVar15 < fVar14) {

          param_2 = (float)fVar14;

        }

        dlog_004276a0(*(undefined4 *)(iVar7 + 0xc),*(undefined4 *)(iVar7 + 0x10),

                      *(undefined4 *)(iVar7 + 0x14),param_2,local_c,&local_8,&local_10);

        *(float *)(iVar7 + 0x24) = local_10 + local_c;

        *(float *)(iVar7 + 0x18) = local_10;

        *(float *)(iVar7 + 0x1c) = local_8;

        *(float *)(iVar7 + 0x20) = local_8 + param_2;

      }

      goto LAB_00429b07;

    }

    if (DAT_00632ab4 != '\0') {

      DAT_00556504 = (uint)(DAT_00556504 == 0);

      goto LAB_00429b07;

    }

    if (DAT_00632ab5 != '\0') {

      *(undefined4 *)((int)param_2 + 0x30) = 0;

      goto LAB_00429b07;

    }

    if (DAT_00632ab6 == '\0') goto LAB_00429b07;

    pcVar8 = *(char **)((int)param_2 + 0x28);

  }

  else {

    pcVar8 = *(char **)((int)param_2 + 0x28);

    iVar9 = *(int *)((int)param_2 + 0x30) + 1;

    uVar11 = 0xffffffff;

    *(int *)((int)param_2 + 0x30) = iVar9;

    pcVar10 = pcVar8;

    do {

      if (uVar11 == 0) break;

      uVar11 = uVar11 - 1;

      cVar3 = *pcVar10;

      pcVar10 = pcVar10 + 1;

    } while (cVar3 != '\0');

    if (iVar9 <= (int)(~uVar11 - 1)) goto LAB_00429b07;

  }

  uVar11 = 0xffffffff;

  do {

    if (uVar11 == 0) break;

    uVar11 = uVar11 - 1;

    cVar3 = *pcVar8;

    pcVar8 = pcVar8 + 1;

  } while (cVar3 != '\0');

  *(uint *)((int)param_2 + 0x30) = ~uVar11 - 1;

LAB_00429b07:

  pcVar8 = (char *)FUN_00519CF0();

  if (pcVar8 != (char *)0x0) {

    cVar3 = *pcVar8;

    while (cVar3 != '\0') {

      if ((*(byte *)(iVar7 + 0xc) & 0x20) != 0) {

        *(undefined4 *)(iVar7 + 0x30) = 0;

        **(undefined1 **)(iVar7 + 0x28) = 0;

        *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) & 0xffffffdf;

      }

      cVar3 = *pcVar8;

      local_4 = pcVar8 + 1;

      if (cVar3 == '\b') {

        if (0 < *(int *)(iVar7 + 0x30)) {

          iVar9 = *(int *)(iVar7 + 0x30) + -1;

          pcVar8 = (char *)(iVar9 + *(int *)(iVar7 + 0x28));

          *(int *)(iVar7 + 0x30) = iVar9;

          pcVar10 = pcVar8;

          do {

            pcVar10 = pcVar10 + 1;

            cVar3 = *pcVar10;

            *pcVar8 = cVar3;

            pcVar8 = pcVar8 + 1;

          } while (cVar3 != '\0');

          fVar15 = (float10)FUN_0051bc00(*(undefined4 *)(iVar7 + 0x34));

          local_c = (float)fVar15;

          fVar15 = (float10)dlog_0051bd30(*(undefined4 *)(iVar7 + 0x34),

                                          *(undefined4 *)(iVar7 + 0x28));

          param_2 = (float)fVar15;

          fVar15 = (float10)dlog_0051bd30(*(undefined4 *)(iVar7 + 0x34),&DAT_005562b8);

          fVar15 = fVar15 * (float10)*(int *)(iVar7 + 0x2c);

          if ((float10)param_2 < fVar15) {

            param_2 = (float)fVar15;

          }

          dlog_004276a0(*(undefined4 *)(iVar7 + 0xc),*(undefined4 *)(iVar7 + 0x10),

                        *(undefined4 *)(iVar7 + 0x14),param_2,local_c,&local_10,&local_8);

          *(float *)(iVar7 + 0x24) = local_8 + local_c;

          *(float *)(iVar7 + 0x18) = local_8;

          *(float *)(iVar7 + 0x1c) = local_10;

          *(float *)(iVar7 + 0x20) = local_10 + param_2;

        }

      }

      else {

        pcVar8 = *(char **)(iVar7 + 0x28);

        iVar9 = *(int *)(iVar7 + 0x30);

        uVar11 = 0xffffffff;

        pcVar10 = pcVar8;

        do {

          if (uVar11 == 0) break;

          uVar11 = uVar11 - 1;

          cVar2 = *pcVar10;

          pcVar10 = pcVar10 + 1;

        } while (cVar2 != '\0');

        if (iVar9 < (int)(~uVar11 - 1)) {

          if (DAT_00556504 == 0) {

            pcVar8[iVar9] = cVar3;

          }

          else {

            uVar11 = 0xffffffff;

            pcVar10 = pcVar8;

            do {

              if (uVar11 == 0) break;

              uVar11 = uVar11 - 1;

              cVar2 = *pcVar10;

              pcVar10 = pcVar10 + 1;

            } while (cVar2 != '\0');

            if (*(int *)(iVar7 + 0x2c) <= (int)(~uVar11 - 1)) goto LAB_00429c6f;

            pcVar8 = pcVar8 + iVar9;

            uVar11 = 0xffffffff;

            pcVar10 = pcVar8;

            do {

              if (uVar11 == 0) break;

              uVar11 = uVar11 - 1;

              cVar2 = *pcVar10;

              pcVar10 = pcVar10 + 1;

            } while (cVar2 != '\0');

            FUN_00543270(pcVar8 + 1,pcVar8,~uVar11 - 1);

            *(char *)(*(int *)(iVar7 + 0x30) + *(int *)(iVar7 + 0x28)) = cVar3;

          }

        }

        else {

          if (*(int *)(iVar7 + 0x2c) <= iVar9) goto LAB_00429c6f;

          pcVar8[iVar9] = cVar3;

          *(undefined1 *)(*(int *)(iVar7 + 0x30) + 1 + *(int *)(iVar7 + 0x28)) = 0;

        }

        *(int *)(iVar7 + 0x30) = *(int *)(iVar7 + 0x30) + 1;

      }

LAB_00429c6f:

      pcVar8 = local_4;

      cVar3 = *local_4;

    }

    wredit_00519c70();

    fVar15 = (float10)FUN_0051bc00(*(undefined4 *)(iVar7 + 0x34));

    local_c = (float)fVar15;

    fVar15 = (float10)dlog_0051bd30(*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x28));

    param_2 = (float)fVar15;

    fVar15 = (float10)dlog_0051bd30(*(undefined4 *)(iVar7 + 0x34),&DAT_005562b8);

    fVar15 = fVar15 * (float10)*(int *)(iVar7 + 0x2c);

    if ((float10)param_2 < fVar15) {

      param_2 = (float)fVar15;

    }

    dlog_004276a0(*(undefined4 *)(iVar7 + 0xc),*(undefined4 *)(iVar7 + 0x10),

                  *(undefined4 *)(iVar7 + 0x14),param_2,local_c,&local_10,&local_8);

    *(float *)(iVar7 + 0x24) = local_8 + local_c;

    *(float *)(iVar7 + 0x18) = local_8;

    *(float *)(iVar7 + 0x1c) = local_10;

    *(float *)(iVar7 + 0x20) = local_10 + param_2;

  }

  fVar4 = DAT_00632abc / (float)DAT_00632e84;

  fVar5 = 1.0 - DAT_00632ac0 / (float)DAT_00632e88;

  if ((((DAT_00632aaa != '\0') || ((DAT_005dd238 & 1) != 0)) &&

      (fVar6 = *(float *)(iVar7 + 0x18) - 0.0125, fVar5 < fVar6 != (fVar5 == fVar6))) &&

     (*(float *)(iVar7 + 0x24) + 0.0125 <= fVar5)) {

    uVar11 = 0xffffffff;

    pcVar8 = *(char **)(iVar7 + 0x28);

    do {

      if (uVar11 == 0) break;

      uVar11 = uVar11 - 1;

      cVar3 = *pcVar8;

      pcVar8 = pcVar8 + 1;

    } while (cVar3 != '\0');

    iVar9 = ~uVar11 - 1;

    if (*(float *)(iVar7 + 0x1c) - 0.0125 < fVar4) {

      iVar12 = 0;

      iVar13 = 0;

      if (0 < iVar9) {

        do {

          iVar13 = iVar12 + 1;

          fVar15 = (float10)FUN_0051bc90(*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x28)

                                         ,iVar13);

          local_8 = (float)fVar15;

          if ((float10)fVar4 < fVar15 + (float10)*(float *)(iVar7 + 0x1c)) {

            iVar13 = iVar12;

            if (iVar12 < iVar9) goto LAB_00429ded;

            break;

          }

          iVar12 = iVar13;

        } while (iVar13 < iVar9);

      }

      iVar12 = iVar13;

      if (fVar4 < local_8 + *(float *)(iVar7 + 0x1c) + 0.0125) {

LAB_00429ded:

        *(int *)(iVar7 + 0x30) = iVar12;

        return;

      }

    }

  }

  return;

}

/* ===== FUN_00429e10 @ 0x00429E10 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00429e10(int param_1,int param_2)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  bool bVar5;

  float fVar6;

  float fVar7;

  int iVar8;

  int *piVar9;

  undefined4 uVar10;

  int iVar11;

  int iVar12;

  int iVar13;

  float10 fVar14;

  

  iVar8 = param_2;

  fVar6 = DAT_00632abc / (float)DAT_00632e84;

  puVar1 = (uint *)(param_2 + 0xc);

  param_2 = 0x3ccccccd;

  fVar7 = 1.0 - DAT_00632ac0 / (float)DAT_00632e88;

  if ((*puVar1 & 0x1000000) == 0) {

    param_2 = 0x3d000000;

  }

  iVar2 = *(int *)(iVar8 + 0x2c);

  piVar9 = *(int **)(iVar8 + 0x28);

  iVar13 = 0;

  if (piVar9 == (int *)0x0) {

    return;

  }

  do {

    iVar12 = iVar13;

    piVar9 = (int *)*piVar9;

    iVar13 = iVar12 + 1;

  } while (piVar9 != (int *)0x0);

  if (iVar13 == 0) {

    return;

  }

  if ((*puVar1 & 0x200) != 0) {

    dlog_screen_user_2(param_1,iVar8);

  }

  if ((*(char *)(iVar8 + 0xc) < '\0') && (DAT_00632aab != '\0')) {

    if ((*(float *)(iVar8 + 0x24) < fVar7) || (fVar7 < *(float *)(iVar8 + 0x18))) {

      *(undefined4 *)(param_1 + 8) = 0xffffffff;

      return;

    }

    FUN_0051bc00(param_2);

    uVar10 = __ftol();

    uVar10 = __ftol(uVar10);

    FUN_0041f100(uVar10);

  }

  if (((char)*(uint *)(iVar8 + 0xc) < '\0') && (DAT_00632aaa != '\0')) {

    FUN_0051bc00(param_2);

    uVar10 = __ftol();

    uVar10 = __ftol(uVar10);

    FUN_0041f100(uVar10);

    return;

  }

  if ((DAT_00632aa0._1_1_ != '\0') || (0.0 < _DAT_00632b18)) {

    piVar9 = (int *)(iVar8 + 0x2c);

    *piVar9 = *piVar9 + -1;

    if (*piVar9 < 0) {

      *(int *)(iVar8 + 0x2c) = iVar12;

    }

  }

  else if ((DAT_00632aa0._2_1_ != '\0') || (_DAT_00632b18 < 0.0)) {

    iVar12 = *(int *)(iVar8 + 0x2c) + 1;

    *(int *)(iVar8 + 0x2c) = iVar12;

    if (iVar13 <= iVar12) {

      *(undefined4 *)(iVar8 + 0x2c) = 0;

    }

  }

  else if (DAT_00632aa0._3_1_ == '\0') {

    if ((char)DAT_00632aa4 == '\0') {

      if (DAT_00632ab5 == '\0') {

        if (DAT_00632ab6 == '\0') {

          if (DAT_00632ab7 == '\0') {

            if (DAT_00632ab8 != '\0') {

              iVar11 = *(int *)(iVar8 + 0x2c) + *(int *)(iVar8 + 0x34);

              goto LAB_0042a10b;

            }

          }

          else {

            iVar12 = *(int *)(iVar8 + 0x2c) - *(int *)(iVar8 + 0x34);

            *(int *)(iVar8 + 0x2c) = iVar12;

            if (iVar12 < 0) {

              *(undefined4 *)(iVar8 + 0x2c) = 0;

            }

          }

        }

        else {

          *(int *)(iVar8 + 0x2c) = iVar12;

        }

      }

      else {

        *(undefined4 *)(iVar8 + 0x2c) = 0;

      }

    }

    else {

      iVar3 = *(int *)(iVar8 + 0x34);

      iVar11 = *(int *)(iVar8 + 0x2c) + iVar3;

      *(int *)(iVar8 + 0x2c) = iVar11;

      if (iVar13 <= iVar11) {

        if (0 < iVar3) {

          iVar11 = iVar11 % iVar3;

LAB_0042a10b:

          *(int *)(iVar8 + 0x2c) = iVar11;

        }

        if (iVar13 <= *(int *)(iVar8 + 0x2c)) {

          *(int *)(iVar8 + 0x2c) = iVar12;

        }

      }

    }

  }

  else {

    iVar12 = *(int *)(iVar8 + 0x34);

    iVar11 = *(int *)(iVar8 + 0x2c) - iVar12;

    *(int *)(iVar8 + 0x2c) = iVar11;

    if (iVar11 < 0) {

      if (0 < iVar12) {

        iVar11 = (iVar13 / iVar12 + 1) * iVar12 + iVar11;

        *(int *)(iVar8 + 0x2c) = iVar11;

        if (iVar13 <= iVar11) {

          do {

            iVar11 = iVar11 - iVar12;

          } while (iVar13 <= iVar11);

          *(int *)(iVar8 + 0x2c) = iVar11;

        }

      }

      if (*(int *)(iVar8 + 0x2c) < 0) {

        *(undefined4 *)(iVar8 + 0x2c) = 0;

      }

    }

  }

  if ((((*(uint *)(iVar8 + 0xc) & 0x20) != 0) &&

      ((((_DAT_00632ac4 != DAT_00632abc || (_DAT_00632ac8 != DAT_00632ac0)) &&

        (*(float *)(iVar8 + 0x1c) <= fVar6)) &&

       ((fVar6 < *(float *)(iVar8 + 0x20) != (fVar6 == *(float *)(iVar8 + 0x20)) &&

        (fVar7 < *(float *)(iVar8 + 0x24) != (fVar7 == *(float *)(iVar8 + 0x24)))))))) &&

     (*(float *)(iVar8 + 0x18) <= fVar7)) {

    uVar10 = FUN_0042a280(param_1,iVar8);

    *(undefined4 *)(iVar8 + 0x2c) = uVar10;

  }

  if ((DAT_00632aaa != '\0') || ((DAT_005dd238 & 1) != 0)) {

    bVar5 = *(float *)(iVar8 + 0x1c) <= fVar6;

    if (*(char *)(iVar8 + 0xc) < '\0') {

      if (((bVar5) && (fVar6 < *(float *)(iVar8 + 0x20) != (fVar6 == *(float *)(iVar8 + 0x20)))) &&

         (fVar14 = (float10)FUN_0051bc00(param_2),

         (float10)fVar7 <= fVar14 * (float10)iVar13 + (float10)*(float *)(iVar8 + 0x18))) {

LAB_0042a1d4:

        if (*(float *)(iVar8 + 0x18) <= fVar7) {

          uVar10 = FUN_0042a280(param_1,iVar8);

          *(undefined4 *)(iVar8 + 0x2c) = uVar10;

        }

      }

    }

    else if (((bVar5) && (fVar6 < *(float *)(iVar8 + 0x20) != (fVar6 == *(float *)(iVar8 + 0x20))))

            && (fVar7 < *(float *)(iVar8 + 0x24) != (fVar7 == *(float *)(iVar8 + 0x24))))

    goto LAB_0042a1d4;

  }

  iVar13 = *(int *)(iVar8 + 0x34);

  if (0 < iVar13) {

    uVar4 = *(uint *)(iVar8 + 0xc);

    if ((uVar4 & 0x10) == 0) {

      if ((uVar4 & 8) == 0) {

        iVar12 = *(int *)(iVar8 + 0x2c);

        if ((uVar4 & 4) == 0) {

          if (*(int *)(iVar8 + 0x30) + iVar13 <= iVar12) {

            *(int *)(iVar8 + 0x30) = (iVar12 - iVar13) + 1;

          }

          if (*(int *)(iVar8 + 0x30) <= iVar12) goto LAB_0042a254;

        }

        else {

          iVar12 = (iVar12 / (iVar13 * 2)) * iVar13 * 2;

        }

      }

      else {

        iVar12 = (*(int *)(iVar8 + 0x2c) / (iVar13 * 3)) * iVar13 * 3;

      }

    }

    else {

      iVar12 = (*(int *)(iVar8 + 0x2c) / (iVar13 * 4)) * iVar13 * 4;

    }

    *(int *)(iVar8 + 0x30) = iVar12;

  }

LAB_0042a254:

  if ((*(int *)(iVar8 + 0x2c) != iVar2) && (*(code **)(iVar8 + 0x3c) != (code *)0x0)) {

    (**(code **)(iVar8 + 0x3c))(param_1,*(undefined4 *)(iVar8 + 8),1);

  }

  return;

}

/* ===== FUN_0042a280 @ 0x0042A280 ===== */
int FUN_0042a280(undefined4 param_1,int param_2)



{

  uint uVar1;

  undefined4 *puVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  

  iVar4 = param_2;

  uVar1 = *(uint *)(param_2 + 0xc);

  fVar3 = DAT_00632abc / (float)DAT_00632e84;

  param_2 = 0x3ccccccd;

  if ((uVar1 & 0x1000000) == 0) {

    param_2 = 0x3d000000;

  }

  iVar5 = 0;

  for (puVar2 = *(undefined4 **)(iVar4 + 0x28); puVar2 != (undefined4 *)0x0;

      puVar2 = (undefined4 *)*puVar2) {

    iVar5 = iVar5 + 1;

  }

  if (((uVar1 & 0x10) == 0) ||

     (fVar3 <= *(float *)(iVar4 + 0x38) * 3.0 + *(float *)(iVar4 + 0x1c) + 0.0585)) {

    if (((uVar1 & 0x18) == 0) ||

       (fVar3 <= *(float *)(iVar4 + 0x38) + *(float *)(iVar4 + 0x38) + *(float *)(iVar4 + 0x1c) +

                 0.035099998)) {

      if (((uVar1 & 0x1c) == 0) ||

         (fVar3 <= *(float *)(iVar4 + 0x38) + *(float *)(iVar4 + 0x1c) + 0.0117)) {

        FUN_0051bc00(param_2);

      }

      else {

        FUN_0051bc00(param_2);

      }

    }

    else {

      FUN_0051bc00(param_2);

    }

  }

  else {

    FUN_0051bc00(param_2);

  }

  iVar4 = __ftol();

  if (iVar5 <= iVar4) {

    iVar4 = iVar5 + -1;

  }

  if (iVar4 < 0) {

    iVar4 = 0;

  }

  return iVar4;

}

/* ===== FUN_0042a3e0 @ 0x0042A3E0 ===== */
void FUN_0042a3e0(int *param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  

  piVar1 = (int *)*param_1;

  if (piVar1 != (int *)0x0) {

    piVar2 = piVar1;

    do {

      if (piVar2[2] == param_1[2]) {

        if ((piVar2 != (int *)0x0) &&

           (piVar2 = (int *)*piVar2, piVar3 = piVar2, piVar2 != (int *)0x0)) goto LAB_0042a410;

        break;

      }

      piVar2 = (int *)*piVar2;

    } while (piVar2 != (int *)0x0);

  }

  piVar2 = piVar1;

  piVar3 = piVar1;

  if (piVar1 != (int *)0x0) {

LAB_0042a410:

    do {

      if (((piVar2[2] != 0) && (piVar2[1] != 0)) &&

         ((piVar2[1] != 3 || ((*(byte *)(piVar2 + 3) & 1) == 0)))) break;

      piVar2 = (int *)*piVar2;

      if (piVar2 == (int *)0x0) {

        piVar2 = piVar1;

      }

    } while (piVar2 != piVar3);

    if (param_1[2] != piVar2[2]) {

      sound_play(0x65a);

    }

    param_1[2] = piVar2[2];

    param_1[1] = param_1[1] | 1;

  }

  return;

}

/* ===== FUN_0042a460 @ 0x0042A460 ===== */
void FUN_0042a460(int *param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  

  piVar1 = (int *)*param_1;

  piVar2 = piVar1;

  piVar4 = piVar1;

  if (piVar1 != (int *)0x0) {

    do {

      if (piVar4[2] == param_1[2]) break;

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)0x0);

  }

  do {

    piVar3 = piVar2;

    if ((piVar3 == (int *)0x0) || (piVar2 = (int *)*piVar3, piVar2 == piVar4)) break;

  } while (piVar2 != (int *)0x0);

  piVar4 = piVar3;

  if (piVar3 != (int *)0x0) {

    do {

      piVar2 = piVar1;

      if (((piVar4[2] != 0) && (piVar4[1] != 0)) &&

         ((piVar5 = piVar4, piVar4[1] != 3 || ((*(byte *)(piVar4 + 3) & 1) == 0)))) break;

      do {

        piVar5 = piVar2;

        if ((piVar5 == (int *)0x0) || (piVar2 = (int *)*piVar5, piVar2 == piVar4)) break;

      } while (piVar2 != (int *)0x0);

      piVar4 = piVar5;

    } while (piVar5 != piVar3);

    param_1[2] = piVar5[2];

    param_1[1] = param_1[1] | 1;

  }

  return;

}

/* ===== FUN_0042a4f0 @ 0x0042A4F0 ===== */
void FUN_0042a4f0(void)



{

  undefined4 *puVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  int iVar7;

  

  (**(code **)(DAT_00656430 + 8))(DAT_00656430,0x24,*(undefined4 *)(DAT_006330e4 + 0x4c),0);

  puVar1 = (undefined4 *)

           (**(code **)(DAT_0065644c + 0x10))(DAT_0065644c,*(undefined4 *)(DAT_00632d2c + 4));

  puVar6 = *(undefined4 **)(DAT_00632d2c + 0x10);

  puVar5 = *(undefined4 **)(DAT_00632d2c + 0xc);

  iVar7 = *(int *)(DAT_00632d2c + 4);

  if (0 < iVar7) {

    do {

      *puVar1 = *puVar5;

      puVar1[1] = puVar5[1];

      puVar1[2] = puVar5[2];

      puVar1[3] = 0xffffffff;

      puVar1[4] = *puVar6;

      puVar1[5] = puVar6[1];

      puVar5 = puVar5 + 3;

      puVar6 = puVar6 + 2;

      puVar1 = puVar1 + 6;

      iVar7 = iVar7 + -1;

    } while (iVar7 != 0);

  }

  (**(code **)(DAT_0065644c + 0x18))(DAT_0065644c,0);

  (**(code **)(DAT_0065644c + 0x20))

            (DAT_0065644c,*(int *)(DAT_00632d2c + 8) * 3,*(undefined4 *)(DAT_00632d2c + 0x18));

  if (0 < *(int *)(DAT_006330e4 + 0x16c)) {

    iVar7 = __ftol();

    uVar2 = __ftol();

    uVar3 = __ftol();

    uVar4 = __ftol();

    (**(code **)(DAT_00656430 + 8))

              (DAT_00656430,0x60720,0,((iVar7 << 8 | uVar2) << 8 | uVar3) << 8 | uVar4);

    (**(code **)(DAT_0065644c + 0x18))(DAT_0065644c,0);

    (**(code **)(DAT_0065644c + 0x20))

              (DAT_0065644c,*(int *)(DAT_00632d2c + 8) * 3,*(undefined4 *)(DAT_00632d2c + 0x18));

  }

  return;

}

/* ===== FUN_0042a640 @ 0x0042A640 ===== */
void FUN_0042a640(float *param_1,float *param_2)



{

  byte bVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  uint uVar5;

  undefined1 uVar6;

  float *pfVar7;

  int iVar8;

  float *pfVar9;

  float *pfVar10;

  float local_e0 [4];

  float local_d0;

  float local_cc;

  undefined1 local_b4;

  undefined1 uStack_b3;

  undefined1 uStack_b2;

  undefined1 uStack_b1;

  float local_b0;

  uint local_ac;

  float local_a8 [4];

  float local_98;

  float local_94;

  undefined1 local_7c;

  undefined1 uStack_7b;

  undefined1 uStack_7a;

  undefined1 uStack_79;

  float local_78;

  uint local_74;

  float local_70 [10];

  undefined1 auStack_48 [16];

  float local_38 [14];

  

  if ((*(byte *)(param_1 + 0xd) & *(byte *)(param_2 + 0xd)) == 0) {

    bVar1 = *(byte *)(param_2 + 0xd) | *(byte *)(param_1 + 0xd);

    DAT_0059ac78 = (uint)bVar1;

    if (DAT_0059ac78 == 0) {

      pfVar7 = (float *)(**(code **)(DAT_00656440 + 0x10))(DAT_00656440,2);

      pfVar9 = param_1 + 6;

      pfVar10 = pfVar7;

      for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {

        *pfVar10 = *pfVar9;

        pfVar9 = pfVar9 + 1;

        pfVar10 = pfVar10 + 1;

      }

      param_2 = param_2 + 6;

    }

    else {

      pfVar9 = local_e0;

      for (iVar8 = 0xe; iVar8 != 0; iVar8 = iVar8 + -1) {

        *pfVar9 = *param_1;

        param_1 = param_1 + 1;

        pfVar9 = pfVar9 + 1;

      }

      pfVar9 = local_a8;

      for (iVar8 = 0xe; iVar8 != 0; iVar8 = iVar8 + -1) {

        *pfVar9 = *param_2;

        param_2 = param_2 + 1;

        pfVar9 = pfVar9 + 1;

      }

      pfVar9 = local_e0;

      pfVar10 = local_70;

      if ((bVar1 & 1) != 0) {

        pfVar9 = local_70;

        DAT_0059ac78 = 0;

        if ((local_ac & 1) == 0) {

          DAT_0059ac78 = local_ac & 0xff;

          pfVar9 = local_e0;

          pfVar10 = local_70;

          for (iVar8 = 0xe; iVar8 != 0; iVar8 = iVar8 + -1) {

            *pfVar10 = *pfVar9;

            pfVar9 = pfVar9 + 1;

            pfVar10 = pfVar10 + 1;

          }

          pfVar9 = (float *)(auStack_48 + 0x10);

        }

        uVar5 = DAT_0059ac78;

        if ((((byte)local_74 ^ (byte)local_ac) & 1) != 0) {

          pfVar9[5] = DAT_0057c0c0;

          fVar2 = (DAT_0057c0c0 - local_cc) / (local_94 - local_cc);

          fVar4 = (local_a8[3] - local_e0[3]) * fVar2 + local_e0[3];

          pfVar9[3] = fVar4;

          fVar3 = (local_98 - local_d0) * fVar2 + local_d0;

          pfVar9[4] = fVar3;

          pfVar9[0xb] = ((float)CONCAT13(uStack_79,CONCAT12(uStack_7a,CONCAT11(uStack_7b,local_7c)))

                        - (float)CONCAT13(uStack_b1,CONCAT12(uStack_b2,CONCAT11(uStack_b3,local_b4))

                                         )) * fVar2 +

                        (float)CONCAT13(uStack_b1,CONCAT12(uStack_b2,CONCAT11(uStack_b3,local_b4)));

          pfVar9[0xc] = (local_78 - local_b0) * fVar2 + local_b0;

          uVar6 = __ftol();

          *(undefined1 *)(pfVar9 + 10) = uVar6;

          uVar6 = __ftol();

          *(undefined1 *)((int)pfVar9 + 0x29) = uVar6;

          uVar6 = __ftol();

          *(undefined1 *)((int)pfVar9 + 0x2a) = uVar6;

          uVar6 = __ftol();

          *(undefined1 *)((int)pfVar9 + 0x2b) = uVar6;

          if (-pfVar9[5] <= fVar4) {

            if (fVar4 <= pfVar9[5]) {

              if (fVar3 <= pfVar9[5]) {

                if (-pfVar9[5] <= fVar3) {

                  *(undefined1 *)(pfVar9 + 0xd) = 0;

                  FUN_00516cf0(pfVar9);

                }

                else {

                  DAT_0059ac78 = uVar5 | 0x10;

                  *(undefined1 *)(pfVar9 + 0xd) = 0x10;

                }

              }

              else {

                DAT_0059ac78 = uVar5 | 0x20;

                *(undefined1 *)(pfVar9 + 0xd) = 0x20;

              }

            }

            else {

              DAT_0059ac78 = uVar5 | 8;

              *(undefined1 *)(pfVar9 + 0xd) = 8;

            }

          }

          else {

            DAT_0059ac78 = uVar5 | 4;

            *(undefined1 *)(pfVar9 + 0xd) = 4;

          }

          pfVar9 = pfVar9 + 0xe;

        }

        if ((local_74 & 1) == 0) {

          DAT_0059ac78 = DAT_0059ac78 | local_74 & 0xff;

          pfVar10 = local_a8;

          for (iVar8 = 0xe; iVar8 != 0; iVar8 = iVar8 + -1) {

            *pfVar9 = *pfVar10;

            pfVar10 = pfVar10 + 1;

            pfVar9 = pfVar9 + 1;

          }

        }

        pfVar9 = local_70;

        pfVar10 = local_e0;

      }

      pfVar7 = pfVar9;

      if ((DAT_0059ac78 & 4) != 0) {

        FUN_0042a9c0(pfVar9,pfVar10);

        pfVar7 = pfVar10;

        pfVar10 = pfVar9;

      }

      pfVar9 = pfVar7;

      if ((DAT_0059ac78 & 8) != 0) {

        FUN_0042ab70(pfVar7,pfVar10);

        pfVar9 = pfVar10;

        pfVar10 = pfVar7;

      }

      param_2 = pfVar9;

      if ((DAT_0059ac78 & 0x20) != 0) {

        FUN_0042aea0(pfVar9,pfVar10);

        param_2 = pfVar10;

        pfVar10 = pfVar9;

      }

      if ((DAT_0059ac78 & 0x10) != 0) {

        FUN_0042ad20(param_2,pfVar10);

        param_2 = pfVar10;

      }

      pfVar7 = (float *)(**(code **)(DAT_00656440 + 0x10))(DAT_00656440,2);

      pfVar9 = param_2 + 6;

      pfVar10 = pfVar7;

      for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {

        *pfVar10 = *pfVar9;

        pfVar9 = pfVar9 + 1;

        pfVar10 = pfVar10 + 1;

      }

      param_2 = param_2 + 0x14;

    }

    pfVar9 = pfVar7 + 7;

    for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {

      *pfVar9 = *param_2;

      param_2 = param_2 + 1;

      pfVar9 = pfVar9 + 1;

    }

  }

  return;

}

/* ===== FUN_0042a9c0 @ 0x0042A9C0 ===== */
void FUN_0042a9c0(undefined4 *param_1,undefined4 *param_2)



{

  float fVar1;

  float fVar2;

  undefined1 uVar3;

  uint uVar4;

  int iVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  

  DAT_0059ac78 = 0;

  if ((*(byte *)(param_1 + 0xd) & 4) == 0) {

    DAT_0059ac78 = (uint)*(byte *)(param_1 + 0xd);

    puVar6 = param_1;

    puVar7 = param_2;

    for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar7 = *puVar6;

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

    }

    param_2 = param_2 + 0xe;

  }

  if (((*(byte *)(param_1 + 0x1b) ^ *(byte *)(param_1 + 0xd)) & 4) == 0) goto LAB_0042ab3d;

  fVar1 = (-(float)param_1[5] - (float)param_1[3]) /

          (((float)param_1[0x13] - (float)param_1[5]) + ((float)param_1[0x11] - (float)param_1[3]));

  param_2[3] = ((float)param_1[0x11] - (float)param_1[3]) * fVar1 + (float)param_1[3];

  param_2[4] = ((float)param_1[0x12] - (float)param_1[4]) * fVar1 + (float)param_1[4];

  fVar2 = -(float)param_2[3];

  param_2[5] = fVar2;

  param_2[0xb] = ((float)param_1[0x19] - (float)param_1[0xb]) * fVar1 + (float)param_1[0xb];

  param_2[0xc] = ((float)param_1[0x1a] - (float)param_1[0xc]) * fVar1 + (float)param_1[0xc];

  uVar3 = __ftol();

  *(undefined1 *)(param_2 + 10) = uVar3;

  uVar3 = __ftol();

  *(undefined1 *)((int)param_2 + 0x29) = uVar3;

  uVar3 = __ftol();

  *(undefined1 *)((int)param_2 + 0x2a) = uVar3;

  uVar3 = __ftol();

  *(undefined1 *)((int)param_2 + 0x2b) = uVar3;

  if ((float)param_2[4] <= fVar2) {

    if ((float)param_2[4] < -fVar2) {

      uVar4 = 0x10;

      goto LAB_0042ab0b;

    }

    *(undefined1 *)(param_2 + 0xd) = 0;

    FUN_00516cf0(param_2);

  }

  else {

    uVar4 = 0x20;

LAB_0042ab0b:

    *(char *)(param_2 + 0xd) = (char)uVar4;

    DAT_0059ac78 = DAT_0059ac78 | uVar4;

  }

  param_2 = param_2 + 0xe;

LAB_0042ab3d:

  if ((*(byte *)(param_1 + 0x1b) & 4) == 0) {

    DAT_0059ac78 = DAT_0059ac78 | *(byte *)(param_1 + 0x1b);

    puVar6 = param_1 + 0xe;

    for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

      *param_2 = *puVar6;

      puVar6 = puVar6 + 1;

      param_2 = param_2 + 1;

    }

  }

  return;

}

/* ===== FUN_0042ab70 @ 0x0042AB70 ===== */
void FUN_0042ab70(undefined4 *param_1,undefined4 *param_2)



{

  float fVar1;

  float fVar2;

  undefined1 uVar3;

  uint uVar4;

  int iVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  

  DAT_0059ac78 = 0;

  if ((*(byte *)(param_1 + 0xd) & 8) == 0) {

    DAT_0059ac78 = (uint)*(byte *)(param_1 + 0xd);

    puVar6 = param_1;

    puVar7 = param_2;

    for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar7 = *puVar6;

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

    }

    param_2 = param_2 + 0xe;

  }

  if (((*(byte *)(param_1 + 0x1b) ^ *(byte *)(param_1 + 0xd)) & 8) == 0) goto LAB_0042ace9;

  fVar2 = ((float)param_1[5] - (float)param_1[3]) /

          (((float)param_1[0x11] - (float)param_1[3]) - ((float)param_1[0x13] - (float)param_1[5]));

  param_2[3] = ((float)param_1[0x11] - (float)param_1[3]) * fVar2 + (float)param_1[3];

  param_2[4] = ((float)param_1[0x12] - (float)param_1[4]) * fVar2 + (float)param_1[4];

  fVar1 = (float)param_2[3];

  param_2[5] = fVar1;

  param_2[0xb] = ((float)param_1[0x19] - (float)param_1[0xb]) * fVar2 + (float)param_1[0xb];

  param_2[0xc] = ((float)param_1[0x1a] - (float)param_1[0xc]) * fVar2 + (float)param_1[0xc];

  uVar3 = __ftol();

  *(undefined1 *)(param_2 + 10) = uVar3;

  uVar3 = __ftol();

  *(undefined1 *)((int)param_2 + 0x29) = uVar3;

  uVar3 = __ftol();

  *(undefined1 *)((int)param_2 + 0x2a) = uVar3;

  uVar3 = __ftol();

  *(undefined1 *)((int)param_2 + 0x2b) = uVar3;

  if ((float)param_2[4] <= fVar1) {

    if ((float)param_2[4] < -fVar1) {

      uVar4 = 0x10;

      goto LAB_0042acb7;

    }

    *(undefined1 *)(param_2 + 0xd) = 0;

    FUN_00516cf0(param_2);

  }

  else {

    uVar4 = 0x20;

LAB_0042acb7:

    *(char *)(param_2 + 0xd) = (char)uVar4;

    DAT_0059ac78 = DAT_0059ac78 | uVar4;

  }

  param_2 = param_2 + 0xe;

LAB_0042ace9:

  if ((*(byte *)(param_1 + 0x1b) & 8) == 0) {

    DAT_0059ac78 = DAT_0059ac78 | *(byte *)(param_1 + 0x1b);

    puVar6 = param_1 + 0xe;

    for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

      *param_2 = *puVar6;

      puVar6 = puVar6 + 1;

      param_2 = param_2 + 1;

    }

  }

  return;

}

/* ===== FUN_0042ad20 @ 0x0042AD20 ===== */
void FUN_0042ad20(undefined4 *param_1,undefined4 *param_2)



{

  float fVar1;

  float fVar2;

  undefined1 uVar3;

  int iVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  

  DAT_0059ac78 = 0;

  if ((*(byte *)(param_1 + 0xd) & 0x10) == 0) {

    DAT_0059ac78 = (uint)*(byte *)(param_1 + 0xd);

    puVar5 = param_1;

    puVar6 = param_2;

    for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar6 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar6 = puVar6 + 1;

    }

    param_2 = param_2 + 0xe;

  }

  if (((*(byte *)(param_1 + 0x1b) ^ *(byte *)(param_1 + 0xd)) & 0x10) != 0) {

    fVar1 = (-(float)param_1[5] - (float)param_1[4]) /

            (((float)param_1[0x12] - (float)param_1[4]) + ((float)param_1[0x13] - (float)param_1[5])

            );

    param_2[3] = ((float)param_1[0x11] - (float)param_1[3]) * fVar1 + (float)param_1[3];

    fVar2 = ((float)param_1[0x12] - (float)param_1[4]) * fVar1 + (float)param_1[4];

    param_2[4] = fVar2;

    param_2[5] = -fVar2;

    param_2[0xb] = ((float)param_1[0x19] - (float)param_1[0xb]) * fVar1 + (float)param_1[0xb];

    param_2[0xc] = ((float)param_1[0x1a] - (float)param_1[0xc]) * fVar1 + (float)param_1[0xc];

    uVar3 = __ftol();

    *(undefined1 *)(param_2 + 10) = uVar3;

    uVar3 = __ftol();

    *(undefined1 *)((int)param_2 + 0x29) = uVar3;

    uVar3 = __ftol();

    *(undefined1 *)((int)param_2 + 0x2a) = uVar3;

    uVar3 = __ftol();

    *(undefined1 *)((int)param_2 + 0x2b) = uVar3;

    *(undefined1 *)(param_2 + 0xd) = 0;

    FUN_00516cf0(param_2);

    param_2 = param_2 + 0xe;

  }

  if ((*(byte *)(param_1 + 0x1b) & 0x10) == 0) {

    DAT_0059ac78 = DAT_0059ac78 | *(byte *)(param_1 + 0x1b);

    puVar5 = param_1 + 0xe;

    for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {

      *param_2 = *puVar5;

      puVar5 = puVar5 + 1;

      param_2 = param_2 + 1;

    }

  }

  return;

}

/* ===== FUN_0042aea0 @ 0x0042AEA0 ===== */
void FUN_0042aea0(undefined4 *param_1,undefined4 *param_2)



{

  float fVar1;

  float fVar2;

  undefined1 uVar3;

  int iVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  

  DAT_0059ac78 = 0;

  if ((*(byte *)(param_1 + 0xd) & 0x20) == 0) {

    DAT_0059ac78 = (uint)*(byte *)(param_1 + 0xd);

    puVar5 = param_1;

    puVar6 = param_2;

    for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar6 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar6 = puVar6 + 1;

    }

    param_2 = param_2 + 0xe;

  }

  if (((*(byte *)(param_1 + 0x1b) ^ *(byte *)(param_1 + 0xd)) & 0x20) != 0) {

    fVar1 = ((float)param_1[5] - (float)param_1[4]) /

            (((float)param_1[0x12] - (float)param_1[4]) - ((float)param_1[0x13] - (float)param_1[5])

            );

    param_2[3] = ((float)param_1[0x11] - (float)param_1[3]) * fVar1 + (float)param_1[3];

    fVar2 = ((float)param_1[0x12] - (float)param_1[4]) * fVar1 + (float)param_1[4];

    param_2[4] = fVar2;

    param_2[5] = fVar2;

    param_2[0xb] = ((float)param_1[0x19] - (float)param_1[0xb]) * fVar1 + (float)param_1[0xb];

    param_2[0xc] = ((float)param_1[0x1a] - (float)param_1[0xc]) * fVar1 + (float)param_1[0xc];

    uVar3 = __ftol();

    *(undefined1 *)(param_2 + 10) = uVar3;

    uVar3 = __ftol();

    *(undefined1 *)((int)param_2 + 0x29) = uVar3;

    uVar3 = __ftol();

    *(undefined1 *)((int)param_2 + 0x2a) = uVar3;

    uVar3 = __ftol();

    *(undefined1 *)((int)param_2 + 0x2b) = uVar3;

    *(undefined1 *)(param_2 + 0xd) = 0;

    FUN_00516cf0(param_2);

    param_2 = param_2 + 0xe;

  }

  if ((*(byte *)(param_1 + 0x1b) & 0x20) == 0) {

    DAT_0059ac78 = DAT_0059ac78 | *(byte *)(param_1 + 0x1b);

    puVar5 = param_1 + 0xe;

    for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {

      *param_2 = *puVar5;

      puVar5 = puVar5 + 1;

      param_2 = param_2 + 1;

    }

  }

  return;

}

/* ===== AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_3 @ 0x0042B010 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_3(undefined4 p0)



{

  DAT_005565d0 = p0;

  return;

}

/* ===== Audio3DTestToneUpdate__Fv_2 @ 0x0042B020 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void Audio3DTestToneUpdate__Fv_2(void)



{

  DAT_005565d0 = 0;

  return;

}

/* ===== Audio3DTestToneUpdate__Fv_3 @ 0x0042B030 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void Audio3DTestToneUpdate__Fv_3(void)



{

  DAT_005565d0 = 0xffffffff;

  return;

}

/* ===== BinFileSeek @ 0x0042B040 ===== */
void BinFileSeek(undefined4 param_1,undefined4 param_2)



{

  FUN_0042b060(param_1,param_2,0);

  return;

}

/* ===== FUN_0042b060 @ 0x0042B060 ===== */
int FUN_0042b060(int param_1,float param_2,int param_3)



{

  float fVar1;

  float fVar2;

  undefined4 uVar3;

  float *pfVar4;

  int iVar5;

  ushort uVar6;

  float10 fVar7;

  float10 fVar8;

  

  iVar5 = DAT_005565d0;

  if (DAT_005565d0 < 0) {

    iVar5 = *(int *)(param_1 + 8);

    if ((*(float *)(iVar5 + 0x42c) < 0.0 != (*(float *)(iVar5 + 0x42c) == 0.0)) &&

       ((*(int *)(iVar5 + 0x42c) != -0x40800000 ||

        (*(float *)(iVar5 + 0x430) < 0.0 != (*(float *)(iVar5 + 0x430) == 0.0))))) {

      return 0;

    }

    uVar3 = FUN_00515db0();

    fVar7 = (float10)FUN_0050a580(param_1 + 0xa0,uVar3);

    fVar8 = (float10)FUN_00515dd0();

    iVar5 = 0;

    fVar7 = (fVar8 / (float10)*(float *)(param_1 + 0xc4)) *

            (float10)(float)(fVar7 + (float10)param_2);

    fVar1 = (float)fVar7;

    pfVar4 = (float *)(*(int *)(param_1 + 8) + 0x42c);

    fVar2 = (float)(fVar7 * (float10)*(float *)(&DAT_005565c0 + DAT_00633150 * 4));

    do {

      if (*pfVar4 != -1.0) {

        if (pfVar4[-10] == 0.0) {

          if (param_3 == 0) break;

          uVar6 = (ushort)(*pfVar4 < fVar1) << 8 | (ushort)(*pfVar4 == fVar1) << 0xe;

        }

        else {

          uVar6 = (ushort)(*pfVar4 < fVar2) << 8 | (ushort)(*pfVar4 == fVar2) << 0xe;

        }

        if ((uVar6 == 0) || (*pfVar4 < 0.0 != (*pfVar4 == 0.0))) break;

      }

      iVar5 = iVar5 + 1;

      pfVar4 = pfVar4 + 1;

    } while (iVar5 < 9);

    if (*(int *)(*(int *)(param_1 + 8) + 0x428 + iVar5 * 4) == -0x40800000) {

      iVar5 = iVar5 + -1;

    }

  }

  return iVar5;

}

/* ===== BinFileCreateWrite_2 @ 0x0042B160 ===== */
void BinFileCreateWrite_2(undefined4 param_1)



{

  FUN_0042b060(param_1,0,0);

  return;

}

/* ===== BinFileCreateWrite_3 @ 0x0042B180 ===== */
void BinFileCreateWrite_3(undefined4 param_1)



{

  FUN_0042b060(param_1,0,1);

  return;

}

/* ===== FUN_0042b1a0 @ 0x0042B1A0 ===== */
/* PS2 candidate: reaper_has_bow_3 (conf 0.807) */



int FUN_0042b1a0(int param_1)



{

  int iVar1;

  float *pfVar2;

  

  iVar1 = 0;

  pfVar2 = (float *)(*(int *)(param_1 + 8) + 0x428);

  do {

    if (*pfVar2 == -1.0) {

      return iVar1;

    }

    iVar1 = iVar1 + 1;

    pfVar2 = pfVar2 + 1;

  } while (iVar1 < 10);

  return 0;

}

/* ===== main_0042b1d0 @ 0x0042B1D0 ===== */
int main_0042b1d0(int param_1)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  iVar2 = 0;

  pfVar1 = (float *)(*(int *)(param_1 + 8) + 0x428);

  iVar3 = 0;

  iVar5 = 0;

  while( true ) {

    if (*pfVar1 == -1.0) {

      return iVar2;

    }

    iVar4 = iVar3;

    iVar6 = iVar5;

    if (((pfVar1[-10] != 0.0) && (iVar4 = iVar2, iVar6 = iVar3, 0 < iVar2)) &&

       (*pfVar1 < 0.0 != (*pfVar1 == 0.0))) break;

    iVar2 = iVar2 + 1;

    pfVar1 = pfVar1 + 1;

    iVar3 = iVar4;

    iVar5 = iVar6;

    if (9 < iVar2) {

      return iVar6;

    }

  }

  return iVar5;

}

/* ===== FUN_0042b220 @ 0x0042B220 ===== */
void FUN_0042b220(ushort *param_1)



{

  ushort uVar1;

  uint uVar2;

  

  while( true ) {

    uVar1 = *param_1;

    uVar2 = (uint)uVar1;

    param_1 = param_1 + 1;

    if (uVar2 == 0) break;

    if ((uVar1 & 0x8000) == 0) {

      if ((uVar1 & 0x4000) == 0) {

        (**(code **)(DAT_0065643c + 0x20))(DAT_0065643c,uVar2 * 3,param_1);

        param_1 = param_1 + uVar2 * 3;

      }

      else {

        (**(code **)(DAT_0065643c + 0x28))(DAT_0065643c,uVar2 & 0xffffbfff);

        param_1 = param_1 + (uVar2 & 0xffffbfff);

      }

    }

    else {

      (**(code **)(DAT_0065643c + 0x24))(DAT_0065643c,uVar2 & 0xffff7fff);

      param_1 = param_1 + (uVar2 & 0xffff7fff);

    }

  }

  return;

}

/* ===== FUN_0042b290 @ 0x0042B290 ===== */
void FUN_0042b290(int param_1,int param_2,float param_3,float param_4)



{

  undefined4 *puVar1;

  ushort uVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  undefined4 *puVar7;

  ushort *puVar8;

  float *pfVar9;

  undefined1 *puVar10;

  

  iVar3 = *(int *)(param_1 + 0x14);

  if (iVar3 != 0) {

    iVar6 = param_2 * 0x50 + param_1;

    iVar4 = *(int *)(iVar6 + 0x88);

    iVar6 = *(int *)(iVar6 + 0x8c);

    puVar7 = (undefined4 *)(**(code **)(DAT_0065644c + 0x10))(DAT_0065644c,iVar6);

    puVar8 = (ushort *)(*(int *)(param_1 + 0x34) + iVar4 * 2);

    pfVar9 = (float *)(*(int *)(param_1 + 0x3c) + iVar4 * 8);

    puVar10 = (undefined1 *)(iVar4 * 3 + *(int *)(param_1 + 0x40));

    if (puVar10 == (undefined1 *)0x0) {

      if (0 < iVar6) {

        do {

          uVar2 = *puVar8;

          puVar8 = puVar8 + 1;

          puVar1 = (undefined4 *)(iVar3 + (uint)uVar2 * 0xc);

          *puVar7 = *puVar1;

          puVar7[1] = puVar1[1];

          uVar5 = puVar1[2];

          puVar7[3] = 0xffffff;

          puVar7[2] = uVar5;

          iVar6 = iVar6 + -1;

          puVar7[4] = param_3 + *pfVar9;

          puVar7[5] = param_4 + pfVar9[1];

          puVar7 = puVar7 + 6;

          pfVar9 = pfVar9 + 2;

        } while (iVar6 != 0);

      }

    }

    else {

      param_1 = iVar6;

      if (0 < iVar6) {

        do {

          uVar2 = *puVar8;

          puVar8 = puVar8 + 1;

          puVar1 = (undefined4 *)(iVar3 + (uint)uVar2 * 0xc);

          *puVar7 = *puVar1;

          puVar7[1] = puVar1[1];

          puVar7[2] = puVar1[2];

          puVar7[3] = (uint)CONCAT21(CONCAT11(*puVar10,puVar10[1]),puVar10[2]);

          param_1 = param_1 + -1;

          puVar7[4] = param_3 + *pfVar9;

          puVar7[5] = param_4 + pfVar9[1];

          puVar7 = puVar7 + 6;

          pfVar9 = pfVar9 + 2;

          puVar10 = puVar10 + 3;

        } while (param_1 != 0);

      }

    }

    (**(code **)(DAT_0065644c + 0x18))(DAT_0065644c,-iVar4);

  }

  return;

}

/* ===== FUN_0042b3d0 @ 0x0042B3D0 ===== */
void FUN_0042b3d0(undefined4 *param_1,int param_2,int param_3)



{

  undefined4 *puVar1;

  ushort uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  undefined4 *puVar6;

  ushort *puVar7;

  undefined1 *puVar8;

  

  iVar3 = *(int *)(param_2 + 0x14);

  if (iVar3 != 0) {

    iVar4 = *(int *)(param_3 * 0x50 + 0x88 + param_2);

    iVar5 = *(int *)(param_3 * 0x50 + 0x8c + param_2);

    puVar7 = (ushort *)(*(int *)(param_2 + 0x34) + iVar4 * 2);

    puVar6 = (undefined4 *)(*(int *)(param_2 + 0x3c) + iVar4 * 8);

    puVar8 = (undefined1 *)(iVar4 * 3 + *(int *)(param_2 + 0x40));

    param_2 = iVar5;

    if (puVar8 == (undefined1 *)0x0) {

      if (0 < iVar5) {

        do {

          uVar2 = *puVar7;

          puVar7 = puVar7 + 1;

          puVar1 = (undefined4 *)(iVar3 + (uint)uVar2 * 0xc);

          *param_1 = *puVar1;

          param_1[1] = puVar1[1];

          param_1[2] = puVar1[2];

          param_1[3] = 0xffffff;

          param_1[4] = *puVar6;

          param_1[5] = puVar6[1];

          param_2 = param_2 + -1;

          puVar6 = puVar6 + 2;

          param_1 = param_1 + 6;

        } while (param_2 != 0);

        return;

      }

    }

    else if (0 < iVar5) {

      do {

        uVar2 = *puVar7;

        puVar7 = puVar7 + 1;

        puVar1 = (undefined4 *)(iVar3 + (uint)uVar2 * 0xc);

        *param_1 = *puVar1;

        param_1[1] = puVar1[1];

        param_1[2] = puVar1[2];

        param_1[3] = (uint)CONCAT21(CONCAT11(*puVar8,puVar8[1]),puVar8[2]);

        param_1[4] = *puVar6;

        param_1[5] = puVar6[1];

        param_2 = param_2 + -1;

        puVar6 = puVar6 + 2;

        param_1 = param_1 + 6;

        puVar8 = puVar8 + 3;

      } while (param_2 != 0);

    }

  }

  return;

}

/* ===== FUN_0042b4e0 @ 0x0042B4E0 ===== */
void FUN_0042b4e0(undefined4 *param_1,int param_2,int param_3)



{

  int iVar1;

  undefined4 *puVar2;

  ushort uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  undefined4 *puVar8;

  ushort *puVar9;

  ushort *puVar10;

  

  iVar4 = *(int *)(param_2 + 0x2c);

  iVar5 = *(int *)(param_2 + 0x14);

  if (iVar5 != 0) {

    iVar1 = param_3 * 0x50 + param_2;

    iVar6 = *(int *)(iVar1 + 0x88);

    iVar1 = *(int *)(iVar1 + 0x8c);

    iVar7 = iVar6 * 2;

    puVar9 = (ushort *)(*(int *)(param_2 + 0x34) + iVar7);

    puVar8 = (undefined4 *)(*(int *)(param_2 + 0x3c) + iVar6 * 8);

    puVar10 = (ushort *)(*(int *)(param_2 + 0x38) + iVar7);

    param_2 = iVar1;

    if (0 < iVar1) {

      do {

        uVar3 = *puVar9;

        puVar9 = puVar9 + 1;

        puVar2 = (undefined4 *)(iVar5 + (uint)uVar3 * 0xc);

        *param_1 = *puVar2;

        param_1[1] = puVar2[1];

        param_1[2] = puVar2[2];

        puVar2 = (undefined4 *)(iVar4 + (uint)*puVar10 * 0xc);

        param_1[3] = *puVar2;

        param_1[4] = puVar2[1];

        param_1[5] = puVar2[2];

        param_1[6] = *puVar8;

        param_1[7] = puVar8[1];

        param_1 = param_1 + 8;

        param_2 = param_2 + -1;

        puVar8 = puVar8 + 2;

        puVar10 = puVar10 + 1;

      } while (param_2 != 0);

    }

  }

  return;

}

/* ===== FUN_0042b5b0 @ 0x0042B5B0 ===== */
void FUN_0042b5b0(undefined4 *param_1,int param_2,undefined4 *param_3)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  int iVar9;

  ushort *puVar10;

  ushort *puVar11;

  int iStack00000018;

  int in_stack_0000001c;

  int local_2c;

  

  iVar3 = *(int *)(param_2 + 0x14);

  iVar4 = *(int *)(param_2 + 0x2c);

  if (iVar3 != 0) {

    iStack00000018 = *(int *)((int)param_3 * 0x50 + 0x8c + param_2);

    iVar9 = *(int *)((int)param_3 * 0x50 + param_2 + 0x88);

    iVar5 = iVar9 * 2;

    param_3 = (undefined4 *)(*(int *)(param_2 + 0x3c) + iVar9 * 8);

    puVar10 = (ushort *)(*(int *)(param_2 + 0x34) + iVar5);

    puVar11 = (ushort *)(*(int *)(param_2 + 0x38) + iVar5);

    if (in_stack_0000001c == 0) {

      if (0 < iStack00000018) {

        do {

          puVar1 = (undefined4 *)(iVar4 + (uint)*puVar11 * 0xc);

          puVar2 = (undefined4 *)(iVar3 + (uint)*puVar10 * 0xc);

          *param_1 = *puVar2;

          param_1[1] = puVar2[1];

          param_1[2] = puVar2[2];

          param_1[3] = *puVar1;

          param_1[4] = puVar1[1];

          param_1[5] = puVar1[2];

          iVar9 = __ftol();

          uVar6 = __ftol();

          uVar7 = __ftol();

          param_1[6] = (iVar9 << 8 | uVar6) << 8 | uVar7;

          param_1[7] = *param_3;

          puVar1 = param_3 + 1;

          puVar10 = puVar10 + 1;

          param_3 = param_3 + 2;

          param_1[8] = *puVar1;

          puVar11 = puVar11 + 1;

          param_1 = param_1 + 9;

          iStack00000018 = iStack00000018 + -1;

        } while (iStack00000018 != 0);

      }

    }

    else {

      local_2c = iStack00000018;

      if (0 < iStack00000018) {

        do {

          puVar1 = (undefined4 *)(iVar3 + (uint)*puVar10 * 0xc);

          *param_1 = *puVar1;

          param_1[1] = puVar1[1];

          param_1[2] = puVar1[2];

          puVar1 = (undefined4 *)(iVar4 + (uint)*puVar11 * 0xc);

          param_1[3] = *puVar1;

          param_1[4] = puVar1[1];

          param_1[5] = puVar1[2];

          uVar6 = __ftol();

          uVar7 = __ftol();

          uVar8 = __ftol();

          param_1[6] = ((uVar6 | 0xffffff00) << 8 | uVar7) << 8 | uVar8;

          param_1[7] = *param_3;

          puVar1 = param_3 + 1;

          param_3 = param_3 + 2;

          param_1[8] = *puVar1;

          puVar10 = puVar10 + 1;

          puVar11 = puVar11 + 1;

          param_1 = param_1 + 9;

          local_2c = local_2c + -1;

        } while (local_2c != 0);

        return;

      }

    }

  }

  return;

}

/* ===== FUN_0042bb10 @ 0x0042BB10 ===== */
void FUN_0042bb10(undefined4 *param_1,int param_2,int param_3,undefined4 *param_4,

                 undefined4 *param_5,undefined4 param_6,int param_7)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  ushort uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  ushort *puVar10;

  ushort *puVar11;

  undefined4 *puVar12;

  int local_2c;

  

  iVar4 = *(int *)(param_2 + 0x14);

  iVar5 = *(int *)(param_2 + 0x2c);

  if (iVar4 != 0) {

    local_2c = *(int *)(param_3 * 0x50 + 0x8c + param_2);

    iVar6 = *(int *)(param_3 * 0x50 + param_2 + 0x88);

    puVar10 = (ushort *)(*(int *)(param_2 + 0x34) + iVar6 * 2);

    puVar11 = (ushort *)(*(int *)(param_2 + 0x38) + iVar6 * 2);

    puVar12 = (undefined4 *)(*(int *)(param_2 + 0x3c) + iVar6 * 8);

    param_4 = (undefined4 *)((int)param_4 + iVar6 * 0xc);

    param_5 = (undefined4 *)((int)param_5 + iVar6 * 0xc);

    if (param_7 == 0) {

      param_7 = local_2c;

      if (0 < local_2c) {

        do {

          uVar3 = *puVar11;

          puVar11 = puVar11 + 1;

          puVar1 = (undefined4 *)(iVar5 + (uint)uVar3 * 0xc);

          puVar2 = (undefined4 *)(iVar4 + (uint)*puVar10 * 0xc);

          *param_1 = *puVar2;

          param_1[1] = puVar2[1];

          param_1[2] = puVar2[2];

          param_1[3] = *puVar1;

          param_1[4] = puVar1[1];

          param_1[5] = puVar1[2];

          param_1[6] = 0;

          param_1[7] = *puVar12;

          param_1[8] = puVar12[1];

          param_1[9] = *param_4;

          param_1[10] = param_4[1];

          param_1[0xb] = param_4[2];

          param_1[0xc] = *param_5;

          param_1[0xd] = param_5[1];

          param_1[0xe] = param_5[2];

          param_4 = param_4 + 3;

          param_5 = param_5 + 3;

          param_1 = param_1 + 0xf;

          param_7 = param_7 + -1;

          puVar10 = puVar10 + 1;

          puVar12 = puVar12 + 2;

        } while (param_7 != 0);

      }

    }

    else if (0 < local_2c) {

      do {

        puVar1 = (undefined4 *)(iVar4 + (uint)*puVar10 * 0xc);

        *param_1 = *puVar1;

        param_1[1] = puVar1[1];

        param_1[2] = puVar1[2];

        puVar1 = (undefined4 *)(iVar5 + (uint)*puVar11 * 0xc);

        param_1[3] = *puVar1;

        param_1[4] = puVar1[1];

        param_1[5] = puVar1[2];

        uVar7 = __ftol();

        uVar8 = __ftol();

        uVar9 = __ftol();

        param_1[6] = ((uVar7 | 0xffffff00) << 8 | uVar8) << 8 | uVar9;

        param_1[7] = *puVar12;

        param_1[8] = puVar12[1];

        param_1[9] = *param_4;

        param_1[10] = param_4[1];

        param_1[0xb] = param_4[2];

        param_1[0xc] = *param_5;

        param_1[0xd] = param_5[1];

        param_4 = param_4 + 3;

        param_1[0xe] = param_5[2];

        puVar10 = puVar10 + 1;

        param_5 = param_5 + 3;

        puVar11 = puVar11 + 1;

        puVar12 = puVar12 + 2;

        param_1 = param_1 + 0xf;

        local_2c = local_2c + -1;

      } while (local_2c != 0);

      return;

    }

  }

  return;

}

/* ===== FUN_0042bfb0 @ 0x0042BFB0 ===== */
void FUN_0042bfb0(undefined4 param_1,ushort *param_2,int param_3,float param_4,float param_5)



{

  ushort *puVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  undefined4 *puVar5;

  int iVar6;

  byte *pbVar7;

  float *pfVar8;

  

  iVar3 = *(int *)((int)param_2 + 0x14);

  if (iVar3 != 0) {

    iVar4 = *(int *)(param_3 * 0x50 + 0x88 + (int)param_2);

    param_1 = *(int *)(param_3 * 0x50 + (int)param_2 + 0x8c);

    puVar5 = (undefined4 *)(**(code **)(DAT_0065644c + 0x10))(DAT_0065644c,param_1);

    puVar1 = (ushort *)(*(int *)((int)param_2 + 0x34) + iVar4 * 2);

    pfVar8 = (float *)(*(int *)((int)param_2 + 0x3c) + iVar4 * 8);

    pbVar7 = (byte *)(iVar4 * 3 + *(int *)((int)param_2 + 0x40));

    param_2 = puVar1;

    if (pbVar7 == (byte *)0x0) {

      if (0 < param_1) {

        do {

          puVar2 = (undefined4 *)(iVar3 + (uint)*param_2 * 0xc);

          *puVar5 = *puVar2;

          puVar5[1] = puVar2[1];

          puVar5[2] = puVar2[2];

          iVar6 = __ftol();

          puVar5[3] = iVar6 << 0x18;

          puVar5[4] = param_4 + *pfVar8;

          param_1 = param_1 + -1;

          puVar5[5] = param_5 + pfVar8[1];

          puVar5 = puVar5 + 6;

          pfVar8 = pfVar8 + 2;

          param_2 = param_2 + 1;

        } while (param_1 != 0);

      }

    }

    else if (0 < param_1) {

      do {

        puVar2 = (undefined4 *)(iVar3 + (uint)*param_2 * 0xc);

        *puVar5 = *puVar2;

        puVar5[1] = puVar2[1];

        puVar5[2] = puVar2[2];

        iVar6 = __ftol();

        puVar5[3] = ((iVar6 << 8 | (uint)*pbVar7) << 8 | (uint)pbVar7[1]) << 8 | (uint)pbVar7[2];

        puVar5[4] = param_4 + *pfVar8;

        param_1 = param_1 + -1;

        puVar5[5] = param_5 + pfVar8[1];

        pbVar7 = pbVar7 + 3;

        puVar5 = puVar5 + 6;

        pfVar8 = pfVar8 + 2;

        param_2 = param_2 + 1;

      } while (param_1 != 0);

    }

    (**(code **)(DAT_0065644c + 0x18))(DAT_0065644c,-iVar4);

  }

  return;

}

/* ===== FUN_0042c1b0 @ 0x0042C1B0 ===== */
void FUN_0042c1b0(int param_1,int param_2,int param_3)



{

  ushort uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  undefined1 uVar5;

  int iVar6;

  undefined4 *puVar7;

  undefined4 *puVar8;

  ushort *puVar9;

  undefined4 *puVar10;

  float *pfVar11;

  undefined1 *puVar12;

  

  iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x400 + param_2 * 4);

  iVar3 = *(int *)(iVar2 + 0x14);

  if (iVar3 != 0) {

    iVar6 = param_3 * 0x50 + iVar2;

    iVar4 = *(int *)(iVar6 + 0x88);

    iVar6 = *(int *)(iVar6 + 0x8c);

    puVar7 = (undefined4 *)(**(code **)(DAT_0065644c + 0x10))(DAT_0065644c,iVar6);

    puVar9 = (ushort *)(*(int *)(iVar2 + 0x34) + iVar4 * 2);

    puVar8 = (undefined4 *)(*(int *)(iVar2 + 0x3c) + iVar4 * 8);

    puVar12 = (undefined1 *)(iVar4 * 3 + *(int *)(iVar2 + 0x40));

    param_3 = iVar6;

    if (puVar12 == (undefined1 *)0x0) {

      if (0 < iVar6) {

        do {

          uVar1 = *puVar9;

          puVar9 = puVar9 + 1;

          puVar10 = (undefined4 *)(iVar3 + (uint)uVar1 * 0xc);

          *puVar7 = *puVar10;

          puVar7[1] = puVar10[1];

          puVar7[2] = puVar10[2];

          puVar7[3] = 0xffffff;

          puVar7[4] = *puVar8;

          puVar7[5] = puVar8[1];

          puVar7 = puVar7 + 6;

          param_3 = param_3 + -1;

          puVar8 = puVar8 + 2;

        } while (param_3 != 0);

      }

    }

    else if (0 < iVar6) {

      do {

        uVar1 = *puVar9;

        puVar9 = puVar9 + 1;

        puVar10 = (undefined4 *)(iVar3 + (uint)uVar1 * 0xc);

        *puVar7 = *puVar10;

        puVar7[1] = puVar10[1];

        puVar7[2] = puVar10[2];

        puVar10 = puVar7 + 6;

        puVar7[3] = (uint)CONCAT21(CONCAT11(*puVar12,puVar12[1]),puVar12[2]);

        puVar7[4] = *puVar8;

        puVar7[5] = puVar8[1];

        param_3 = param_3 + -1;

        puVar8 = puVar8 + 2;

        puVar7 = puVar10;

        puVar12 = puVar12 + 3;

      } while (param_3 != 0);

    }

    if (*(int *)(param_1 + 0x1e0) == 0x42) {

      if (0 < iVar6) {

        do {

          uVar5 = __ftol();

          *(undefined1 *)((int)puVar7 + 0xf) = uVar5;

          iVar6 = iVar6 + -1;

          puVar7[4] = *(float *)(param_1 + 0x278) * 0.6666 + (float)puVar7[4];

          puVar7[5] = *(float *)(param_1 + 0x278) * 0.3333 + (float)puVar7[5];

          puVar7 = puVar7 + 6;

        } while (iVar6 != 0);

      }

    }

    else if (0 < iVar6) {

      pfVar11 = (float *)(puVar7 + 5);

      do {

        uVar5 = __ftol();

        *(undefined1 *)((int)pfVar11 + -5) = uVar5;

        iVar6 = iVar6 + -1;

        *pfVar11 = *(float *)(param_1 + 0x278) + *pfVar11;

        pfVar11 = pfVar11 + 6;

      } while (iVar6 != 0);

    }

    (**(code **)(DAT_0065644c + 0x18))(DAT_0065644c,-iVar4);

  }

  return;

}

/* ===== status_hud_render @ 0x0042C3E0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void status_hud_render(int param_1,byte param_2,int param_3)



{

  ushort uVar1;

  int iVar2;

  float fVar3;

  int *piVar4;

  float fVar5;

  float *pfVar6;

  undefined4 uVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  int iVar11;

  uint uVar12;

  uint uVar13;

  uint uVar14;

  int iVar15;

  uint uVar16;

  uint uVar17;

  uint uVar18;

  uint uVar19;

  ushort *puVar20;

  bool bVar21;

  float10 fVar22;

  float10 extraout_ST0;

  undefined4 uVar23;

  float local_11c;

  int local_118;

  float local_114;

  uint *puStack_110;

  int iStack_10c;

  uint local_108;

  int local_104;

  int local_100;

  int iStack_fc;

  int local_f8;

  uint uStack_f4;

  float fStack_f0;

  float fStack_ec;

  uint uStack_e8;

  uint uStack_e4;

  float local_d8;

  float local_d4;

  float local_d0;

  undefined4 local_cc;

  float local_c8;

  float local_c4;

  float local_c0;

  undefined4 local_bc;

  float local_b8;

  float local_b4;

  float local_b0;

  undefined4 local_ac;

  float local_a8;

  float local_a4;

  float local_a0;

  undefined4 local_9c;

  int local_98;

  uint local_94;

  char *pcStack_90;

  int local_8c;

  undefined4 *puStack_88;

  undefined1 auStack_84 [16];

  float fStack_74;

  float fStack_70;

  float fStack_6c;

  float fStack_68;

  float fStack_64;

  float fStack_60;

  undefined1 auStack_5c [12];

  undefined1 auStack_50 [12];

  float local_44;

  float local_38;

  float local_24;

  undefined1 auStack_c [12];

  

  local_100 = 0;

  local_98 = 0;

  local_118 = 0;

  local_104 = 0;

  main_animate_00404b60(param_1,0xffffffff);

  local_8c = FUN_0042b060(param_1,0,0);

  iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x400 + local_8c * 4);

  uVar19 = *(uint *)(param_1 + 0x1c8);

  local_94 = uVar19 & 0x2000;

  local_108 = uVar19 & 0x4000;

  if (param_3 < 0) {

    local_f8 = *(int *)(iVar2 + 0x68);

    param_3 = 0;

  }

  else {

    local_f8 = param_3 + 1;

  }

  if ((char)uVar19 < '\0') {

    pfVar6 = (float *)AudioDataStreamStatus__Fv_5();

    local_d8 = *pfVar6 * *(float *)(param_1 + 0xc4);

    local_d4 = pfVar6[4] * *(float *)(param_1 + 0xc4);

    local_d0 = pfVar6[8] * *(float *)(param_1 + 0xc4);

    local_c8 = pfVar6[2] * *(float *)(param_1 + 0xc4);

    local_c4 = pfVar6[6] * *(float *)(param_1 + 0xc4);

    local_c0 = pfVar6[10] * *(float *)(param_1 + 0xc4);

    local_b8 = pfVar6[1] * *(float *)(param_1 + 0xc4);

    local_b4 = pfVar6[5] * *(float *)(param_1 + 0xc4);

    local_b0 = pfVar6[9] * *(float *)(param_1 + 0xc4);

    local_a8 = -(pfVar6[0xc] * *pfVar6 + pfVar6[0xd] * pfVar6[1] + pfVar6[0xe] * pfVar6[2]) +

               *(float *)(param_1 + 0xa0);

    local_a4 = -(pfVar6[0xd] * pfVar6[5] + pfVar6[0xe] * pfVar6[6] + pfVar6[0xc] * pfVar6[4]) +

               *(float *)(param_1 + 0xa4);

    local_9c = 0x3f800000;

    local_ac = 0;

    local_bc = 0;

    local_cc = 0;

    local_a0 = -(pfVar6[0xd] * pfVar6[9] + pfVar6[0xe] * pfVar6[10] + pfVar6[0xc] * pfVar6[8]) +

               *(float *)(param_1 + 0xa8);

  }

  else if ((uVar19 & 4) == 0) {

    local_d8 = *(float *)(param_1 + 0x298);

    local_d4 = *(float *)(param_1 + 0x2a8);

    local_d0 = *(float *)(param_1 + 0x2b8);

    local_cc = *(undefined4 *)(param_1 + 0x2c8);

    local_c0 = *(float *)(param_1 + 700);

    local_c8 = *(float *)(param_1 + 0x29c);

    local_c4 = *(float *)(param_1 + 0x2ac);

    local_b4 = *(float *)(param_1 + 0x2b0);

    local_bc = *(undefined4 *)(param_1 + 0x2cc);

    local_b8 = *(float *)(param_1 + 0x2a0);

    local_a8 = *(float *)(param_1 + 0x2a4);

    local_b0 = *(float *)(param_1 + 0x2c0);

    local_ac = *(undefined4 *)(param_1 + 0x2d0);

    local_9c = *(undefined4 *)(param_1 + 0x2d4);

    local_a4 = *(float *)(param_1 + 0x2b4);

    local_a0 = *(float *)(param_1 + 0x2c4);

  }

  else {

    pfVar6 = (float *)AudioDataStreamStatus__Fv_5();

    fVar3 = *(float *)(param_1 + 0xc4);

    FUN_0050ae40(*(undefined4 *)(param_1 + 0xd0),&local_11c,&local_114);

    local_24 = local_114 * fVar3;

    local_a8 = *(float *)(param_1 + 0xa0);

    local_a4 = *(float *)(param_1 + 0xa4);

    local_a0 = *(float *)(param_1 + 0xa8);

    fVar5 = local_11c * fVar3;

    local_44 = -fVar5;

    local_38 = -fVar3;

    local_d8 = fVar5 * pfVar6[1] + local_24 * *pfVar6;

    local_d4 = local_24 * pfVar6[4] + fVar5 * pfVar6[5];

    local_d0 = local_24 * pfVar6[8] + fVar5 * pfVar6[9];

    local_c8 = local_38 * pfVar6[2];

    local_c4 = local_38 * pfVar6[6];

    local_c0 = local_38 * pfVar6[10];

    local_b8 = local_24 * pfVar6[1] + local_44 * *pfVar6;

    local_b4 = local_44 * pfVar6[4] + local_24 * pfVar6[5];

    local_9c = 0x3f800000;

    local_ac = 0;

    local_b0 = local_44 * pfVar6[8] + local_24 * pfVar6[9];

    local_bc = 0;

    local_cc = 0;

  }

  (**(code **)(DAT_00656420 + 0x18))(DAT_00656420,&local_d8);

  if ((DAT_00633194 == 0) && (*(int *)(iVar2 + 0x2c) != 0)) {

    iStack_10c = DAT_006330b4;

    if ((DAT_00633190 == 0) && (DAT_006330b4 != 0)) {

      iVar15 = 1;

    }

    else {

      iVar15 = 0;

    }

    local_104 = iVar15;

    FUN_004043a0(iVar2);

    if ((iVar15 == 0) || ((*(uint *)(iVar2 + 4) & 0x20000000) == 0)) {

      uVar7 = 0;

    }

    else {

      uVar7 = 1;

    }

    FUN_00404530(iVar2,uVar7);

    local_100 = 1;

  }

  if ((*(byte *)(param_1 + 0xd8) & 2) != 0) {

    FUN_00515eb0(&pcStack_90,&puStack_88);

    FNT_StringRender__FPcP14FNT_RenderInfo(pcStack_90,(undefined4 *)0x479c4000);

    fVar22 = (float10)FUN_00515da0(0);

    fVar22 = (float10)FUN_00515d90((float)fVar22);

    FUN_005160b0((float)fVar22);

  }

  (**(code **)(DAT_00656430 + 0x10))(DAT_00656430,~*(uint *)(param_1 + 0xd8) >> 0x15 & 1);

  if (((*(byte *)(param_1 + 0x1c8) & 4) != 0) || (uVar7 = 2, (*(byte *)(param_1 + 0x294) & 8) == 0))

  {

    uVar7 = 1;

  }

  (**(code **)(DAT_00656430 + 0xc))(DAT_00656430,uVar7);

  if (param_3 < local_f8) {

    do {

      if ((*(int *)(param_1 + 0x204) == 0) ||

         (iVar15 = FUN_00513ac0(param_1,iVar2,param_3), iVar15 == 0)) {

        iVar15 = param_3 * 0x50 + iVar2;

        uStack_f4 = (uint)(*(int *)(iVar15 + 0x90) != 0);

        if (uStack_f4 == 0) {

LAB_0042c927:

          local_11c = 0.0;

        }

        else {

          texture_alloc_helper(*(int *)(iVar15 + 0x90));

          iVar8 = FUN_00508fa0(*(undefined4 *)(iVar15 + 0x90));

          if (iVar8 == 0) goto LAB_0042c927;

          local_11c = 1.4013e-45;

        }

        if (*(float *)(iVar15 + 0x98) == 0.0) {

          if (local_11c == 0.0) {

            if (((*(float *)(param_1 + 0x184) != 0.0) ||

                ((*(uint *)(param_1 + 0x1c8) & 0x800000) != 0)) ||

               ((*(uint *)(param_1 + 0xdc) & 0x40000) != 0)) goto LAB_0042c9ed;

            bVar21 = (param_2 & 1) == 0;

          }

          else {

LAB_0042c9e3:

            bVar21 = (param_2 & 4) == 0;

          }

        }

        else {

          if (local_11c != 0.0) goto LAB_0042c9e3;

LAB_0042c9ed:

          bVar21 = (param_2 & 2) == 0;

        }

        if ((!bVar21) &&

           ((*(int *)(param_1 + 0x26c) == 0 ||

            (puStack_110 = (uint *)(1 << ((byte)param_3 & 0x1f) &

                                   *(uint *)(*(int *)(param_1 + 0x26c) + (param_3 >> 5) * 4)),

            puStack_110 != (uint *)0x0)))) {

          if ((DAT_006330e4 == 0) ||

             ((*(int *)(DAT_006330e4 + 0x16c) < 1 && ((*(uint *)(param_1 + 0xd8) & 0x20000) != 0))))

          {

            iStack_fc = 0;

          }

          else {

            iStack_fc = 1;

          }

          iVar8 = __ftol();

          iVar11 = (param_3 * 5 + 10) * 0x10;

          uVar19 = *(uint *)(iVar2 + iVar11);

          puStack_110 = (uint *)(iVar2 + iVar11);

          uVar16 = iVar8 << 0x18;

          if (DAT_0059ac88 == 0) {

            if ((*(float *)(param_1 + 0x184) == 0.0) ||

               (*(float *)(param_1 + 0x184) <= *(float *)(iVar15 + 0x98))) {

              fVar22 = (float10)*(float *)(iVar15 + 0x98);

            }

            else {

              fVar22 = (float10)*(float *)(param_1 + 0x184);

            }

          }

          else {

            fVar22 = (float10)_DAT_0059ac84;

          }

          if (local_94 == 0) {

            if (local_108 != 0) {

              uVar16 = *(uint *)(param_1 + 0xf4);

              uVar19 = 0x10;

            }

          }

          else {

            uVar19 = 0x22;

            FUN_004f8350(param_1);

            uVar16 = __ftol();

            uVar16 = (uVar16 << 8 | uVar16) << 8 | uVar16;

            fVar22 = extraout_ST0;

          }

          uVar14 = 0;

          if ((local_94 != 0) || (local_108 != 0)) {

            uVar14 = 0x20000;

          }

          if (uStack_f4 != 0) {

            uVar14 = uVar14 | 4;

          }

          if (local_11c != 0.0) {

            uVar14 = uVar14 | 8;

          }

          if (iStack_fc != 0) {

            uVar14 = uVar14 | 0x10;

          }

          if ((local_94 == 0) && (local_108 == 0)) {

            if ((uVar16 & 0xff000000) != 0) {

              uVar14 = uVar14 | 0x80;

              goto LAB_0042cb13;

            }

          }

          else {

LAB_0042cb13:

            if ((uVar19 & 0xf0) == 0x10) {

              uVar14 = uVar14 | 0x1000;

            }

            else if ((uVar19 & 0xf0) == 0x20) {

              uVar14 = uVar14 | 0x3000;

            }

            else {

              uVar14 = uVar14 | 0x2000;

            }

          }

          if ((fVar22 != (float10)0.0) || (local_11c != 0.0)) {

            if ((uVar19 & 0xf) == 1) {

              uVar14 = uVar14 | 0x100;

            }

            else if ((uVar19 & 0xf) == 2) {

              uVar14 = uVar14 | 0x200;

            }

            else {

              uVar14 = uVar14 | 0x300;

            }

          }

          uVar19 = *(uint *)(param_1 + 0x1c8);

          if ((uVar19 & 0x800000) != 0) {

            uVar14 = uVar14 | 0x700;

          }

          if (((param_2 & 6) != 0) || ((uVar19 & 0x100) != 0)) {

            uVar14 = uVar14 | 0x20;

          }

          if ((uVar19 & 0x2000000) != 0) {

            uVar14 = uVar14 | 0x40;

          }

          if ((uVar14 & 0xf00) != 0) {

            iVar8 = __ftol();

            uVar16 = uVar16 & 0xffffff | iVar8 << 0x18;

            uVar14 = uVar14 | 0x40000;

          }

          if ((~uVar16 & 0xff000000) != 0) {

            uVar14 = uVar14 | 0x40000;

          }

          if ((uVar19 & 0x800000) == 0) {

            if ((*(uint *)(param_1 + 0xdc) & 0x40000) != 0) {

              piVar4 = *(int **)(param_1 + 0x2f4);

              if (piVar4 == (int *)0x0) {

                uVar7 = *(undefined4 *)(iVar15 + 0x90);

              }

              else {

                uVar7 = *(undefined4 *)(*piVar4 + piVar4[2] * 4);

              }

              (**(code **)(DAT_00656430 + 8))

                        (DAT_00656430,uVar14 & 0xfffff6ff | 0x50600,uVar7,uVar16);

              if ((*(uint *)(param_1 + 0xdc) & 0x80000) == 0) {

                uVar7 = 0;

                uVar23 = 0;

              }

              else {

                uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x8c);

                uVar23 = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x88);

              }

              FUN_0042bfb0(param_1,iVar2,param_3,uVar23,uVar7);

              goto LAB_0042ccba;

            }

            if ((*(uint *)(param_1 + 0xdc) & 0x80000) != 0) {

              piVar4 = *(int **)(param_1 + 0x2f4);

              if (piVar4 == (int *)0x0) {

                uVar7 = *(undefined4 *)(iVar15 + 0x90);

              }

              else {

                uVar7 = *(undefined4 *)(*piVar4 + piVar4[2] * 4);

              }

              (**(code **)(DAT_00656430 + 8))(DAT_00656430,uVar14,uVar7,uVar16);

              FUN_0042b290(iVar2,param_3,*(undefined4 *)(*(int *)(param_1 + 0x100) + 0x88),

                           *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x8c));

              goto LAB_0042ccba;

            }

            if ((*(byte *)(param_1 + 0xd8) & 4) != 0) {

              (**(code **)(DAT_00656430 + 8))

                        (DAT_00656430,uVar14,*(undefined4 *)(iVar15 + 0x90),uVar16);

              FUN_005095e0(param_1,iVar2,param_3);

              goto LAB_0042ccba;

            }

            piVar4 = *(int **)(param_1 + 0x2f4);

            if (piVar4 == (int *)0x0) {

              local_11c = *(float *)(iVar15 + 0x90);

            }

            else {

              local_11c = *(float *)(*piVar4 + piVar4[2] * 4);

            }

            if (local_100 != 0) {

              if (local_11c != 0.0) {

                *(byte *)((int)local_11c + 0x1f) = *(byte *)((int)local_11c + 0x1f) | 1;

              }

              fStack_ec = 0.0;

              uStack_e4 = uVar16;

              if (((DAT_0063319c == 0) && ((*puStack_110 & 0x10000000) != 0)) || (DAT_006331a8 != 0)

                 ) {

                uStack_e8 = uVar14 | 0x7003;

                fStack_ec = (float)(DAT_006330e4 + 0x4ea0);

                if ((uVar14 & 0xf00) == 0) {

                  if ((~uVar16 & 0xff000000) == 0) {

                    uVar16 = uVar16 & 0xffffff | 0xc0000000;

                  }

                  uStack_e8 = uVar14 | 0x47003;

                  uStack_e4 = uVar16;

                }

              }

              else {

                if ((*puStack_110 & 0x10000000) == 0) {

                  uVar19 = uVar14 & 0xffff0fff;

                }

                else {

                  uVar19 = uVar14 & 0xffff0ff7;

                }

                uStack_e8 = uVar19 | DAT_006330bc | 3;

              }

              if (-1 < (char)uStack_e8) {

                uStack_e4 = uStack_e4 | 0xffffff;

                uStack_e8 = uStack_e8 & 0xffff3fff | 0x23000;

              }

              fStack_f0 = local_11c;

              (**(code **)(DAT_00656430 + 0x18))(DAT_00656430,&fStack_f0,iVar15 + 0xa4);

              iVar8 = iStack_10c;

              if ((local_104 == 0) || ((*puStack_110 & 0x20000000) == 0)) {

                if (local_118 != 0) {

                  if (DAT_00633244 < 3) {

                    FUN_0046fe30(iStack_10c,auStack_84);

                    FUN_0046ff90(iVar8,0);

                  }

                  local_118 = 0;

                }

                uVar7 = (**(code **)(DAT_00656450 + 0x10))

                                  (DAT_00656450,*(undefined4 *)(iVar15 + 0x8c),iVar2,param_3);

                (*(code *)PTR_FUN_005565b4)(uVar7);

                (**(code **)(DAT_00656450 + 0x18))(DAT_00656450,-*(int *)(iVar15 + 0x88));

                puVar20 = *(ushort **)(iVar15 + 0x84);

                while( true ) {

                  uVar1 = *puVar20;

                  uVar19 = (uint)uVar1;

                  puVar20 = puVar20 + 1;

                  if (uVar19 == 0) break;

                  if ((uVar1 & 0x8000) == 0) {

                    if ((uVar1 & 0x4000) == 0) {

                      (**(code **)(DAT_00656450 + 0x20))(DAT_00656450,uVar19 * 3,puVar20);

                      puVar20 = puVar20 + uVar19 * 3;

                    }

                    else {

                      (**(code **)(DAT_00656450 + 0x28))(DAT_00656450,uVar19 & 0xffffbfff);

                      puVar20 = puVar20 + (uVar19 & 0xffffbfff);

                    }

                  }

                  else {

                    (**(code **)(DAT_00656450 + 0x24))(DAT_00656450,uVar19 & 0xffff7fff);

                    puVar20 = puVar20 + (uVar19 & 0xffff7fff);

                  }

                }

              }

              else {

                (*(code *)PTR_collgrid_collide_b_00554064)(iVar2,param_3,DAT_00656458,DAT_0065645c);

                iVar8 = iStack_10c;

                if (local_98 == 0) {

                  FUN_0046fa10(iStack_10c,&fStack_68);

                  fStack_74 = -fStack_68;

                  fStack_70 = -fStack_64;

                  fStack_6c = -fStack_60;

                  (*(code *)PTR_FUN_00580c1c)(auStack_50,param_1 + 0x294);

                  uVar7 = FUN_00515db0();

                  (*(code *)PTR_FUN_00580c20)(auStack_c,uVar7,1,auStack_50);

                  (*(code *)PTR_FUN_00580c24)(auStack_5c,&fStack_74,1,auStack_50,0xffffffef);

                  local_98 = 1;

                }

                if (local_118 == 0) {

                  FUN_0046f8d0(iVar8,auStack_84);

                  if (DAT_00633244 < 3) {

                    FUN_0046fe30(iVar8,&DAT_0059ac8c);

                    FUN_0046ff90(iVar8,0);

                  }

                  iVar8 = __ftol();

                  uVar19 = __ftol();

                  uVar16 = __ftol();

                  uVar9 = __ftol();

                  local_114 = (float)(((iVar8 << 8 | uVar19) << 8 | uVar16) << 8 | uVar9);

                  local_118 = 1;

                }

                uStack_f4 = *(uint *)(iVar15 + 0xac);

                uVar16 = uStack_f4 >> 0x10;

                uVar9 = (uint)local_114 >> 0x10;

                uVar10 = uStack_f4 & 0xff;

                uVar17 = uStack_f4 >> 8;

                uVar12 = (uint)local_114 & 0xff;

                uVar19 = (uint)local_114 >> 8;

                uVar13 = (uint)local_114 >> 0x18;

                if (DAT_00633244 < 3) {

                  uVar7 = (**(code **)(DAT_00656454 + 0x10))

                                    (DAT_00656454,*(undefined4 *)(iVar15 + 0x8c),iVar2,param_3,

                                     DAT_00656458,DAT_0065645c,auStack_5c,0);

                  (*(code *)PTR_FUN_005565b8)(uVar7);

                }

                else {

                  uVar7 = (**(code **)(DAT_00656454 + 0x10))();

                  (*(code *)PTR_FUN_005565bc)(uVar7);

                }

                (**(code **)(DAT_00656454 + 0x18))(DAT_00656454,-*(int *)(iVar15 + 0x88));

                if (DAT_00633244 < 3) {

                  puVar20 = *(ushort **)(iVar15 + 0x84);

                  while( true ) {

                    uVar1 = *puVar20;

                    uVar18 = (uint)uVar1;

                    puVar20 = puVar20 + 1;

                    if (uVar18 == 0) break;

                    if ((uVar1 & 0x8000) == 0) {

                      if ((uVar1 & 0x4000) == 0) {

                        (**(code **)(DAT_00656454 + 0x20))(DAT_00656454,uVar18 * 3,puVar20);

                        puVar20 = puVar20 + uVar18 * 3;

                      }

                      else {

                        (**(code **)(DAT_00656454 + 0x28))(DAT_00656454,uVar1 & 0xffffbfff);

                        puVar20 = puVar20 + (uVar1 & 0xffffbfff);

                      }

                    }

                    else {

                      (**(code **)(DAT_00656454 + 0x24))(DAT_00656454,uVar1 & 0xffff7fff);

                      puVar20 = puVar20 + (uVar1 & 0xffff7fff);

                    }

                  }

                  uStack_e8 = uVar14 & 0xffff61ff | 0x66120;

                }

                else {

                  uStack_e8 = uVar14 & 0xffff60ff | 0x6000;

                }

                fStack_f0 = *(float *)(iVar15 + 0x94);

                *(ushort *)((int)fStack_f0 + 0x1e) = *(ushort *)((int)fStack_f0 + 0x1e) | 0x110;

                *(undefined4 *)((int)fStack_f0 + 0x18) = 2;

                fStack_ec = local_11c;

                uStack_e4 = (uVar16 & 0xff) * (uVar9 & 0xff) + 0xff >> 8 & 0xff |

                            (uVar10 * uVar12 + 0xff & 0xff00) << 8 |

                            (uVar19 & 0xff) * (uVar17 & 0xff) + 0xff & 0xff00 |

                            (uVar17 & 0xff0000) * uVar13 + 0xff0000 & 0xff000000;

                (**(code **)(DAT_00656430 + 0x14))(DAT_00656430,&fStack_f0);

                puVar20 = *(ushort **)(iVar15 + 0x84);

                while( true ) {

                  uVar1 = *puVar20;

                  uVar19 = (uint)uVar1;

                  puVar20 = puVar20 + 1;

                  if (uVar19 == 0) break;

                  if ((uVar1 & 0x8000) == 0) {

                    if ((uVar1 & 0x4000) == 0) {

                      (**(code **)(DAT_00656454 + 0x20))(DAT_00656454,uVar19 * 3,puVar20);

                      puVar20 = puVar20 + uVar19 * 3;

                    }

                    else {

                      (**(code **)(DAT_00656454 + 0x28))(DAT_00656454,uVar19 & 0xffffbfff);

                      puVar20 = puVar20 + (uVar19 & 0xffffbfff);

                    }

                  }

                  else {

                    (**(code **)(DAT_00656454 + 0x24))(DAT_00656454,uVar19 & 0xffff7fff);

                    puVar20 = puVar20 + (uVar19 & 0xffff7fff);

                  }

                }

              }

              goto LAB_0042ccba;

            }

            (**(code **)(DAT_00656430 + 8))(DAT_00656430,uVar14,local_11c,uVar16);

            uVar7 = (**(code **)(DAT_0065644c + 0x10))

                              (DAT_0065644c,*(undefined4 *)(iVar15 + 0x8c),iVar2,param_3);

            (*(code *)PTR_FUN_005565b0)(uVar7);

            (**(code **)(DAT_0065644c + 0x18))(DAT_0065644c,-*(int *)(iVar15 + 0x88));

          }

          else {

            piVar4 = *(int **)(param_1 + 0x2f4);

            if (piVar4 == (int *)0x0) {

              uVar7 = *(undefined4 *)(iVar15 + 0x90);

            }

            else {

              uVar7 = *(undefined4 *)(*piVar4 + piVar4[2] * 4);

            }

            (**(code **)(DAT_00656430 + 8))(DAT_00656430,uVar14,uVar7,uVar16);

            FUN_0042c1b0(param_1,local_8c,param_3);

LAB_0042ccba:

            if (local_100 != 0) goto LAB_0042d3f8;

          }

          puVar20 = *(ushort **)(iVar15 + 0x84);

          while( true ) {

            uVar1 = *puVar20;

            uVar19 = (uint)uVar1;

            puVar20 = puVar20 + 1;

            if (uVar19 == 0) break;

            if ((uVar1 & 0x8000) == 0) {

              if ((uVar1 & 0x4000) == 0) {

                (**(code **)(DAT_0065644c + 0x20))(DAT_0065644c,uVar19 * 3,puVar20);

                puVar20 = puVar20 + uVar19 * 3;

              }

              else {

                (**(code **)(DAT_0065644c + 0x28))(DAT_0065644c,uVar19 & 0xffffbfff);

                puVar20 = puVar20 + (uVar19 & 0xffffbfff);

              }

            }

            else {

              (**(code **)(DAT_0065644c + 0x24))(DAT_0065644c,uVar19 & 0xffff7fff);

              puVar20 = puVar20 + (uVar19 & 0xffff7fff);

            }

          }

        }

      }

LAB_0042d3f8:

      param_3 = param_3 + 1;

    } while (param_3 < local_f8);

    if ((local_118 != 0) && (DAT_00633244 < 3)) {

      FUN_0046fe30(DAT_006330b4,auStack_84);

      FUN_0046ff90(DAT_006330b4,0);

    }

  }

  if ((*(byte *)(param_1 + 0xd8) & 2) != 0) {

    FNT_StringRender__FPcP14FNT_RenderInfo(pcStack_90,puStack_88);

    fVar22 = (float10)FUN_00515da0(1);

    fVar22 = (float10)FUN_00515d90((float)fVar22);

    FUN_005160b0((float)fVar22);

  }

  return;

}

/* ===== render_view_xform @ 0x0042D550 ===== */
void render_view_xform(void)



{

  float *pfVar1;

  undefined4 *puVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  float *pfVar8;

  float *pfVar9;

  float fVar10;

  int *piVar11;

  float fVar12;

  int iVar13;

  int local_3c;

  int local_38;

  undefined1 local_24 [8];

  float local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined1 local_c [12];

  

  piVar11 = DAT_0059aca0;

  iVar13 = DAT_0059ac80;

  if (DAT_0059ac80 != 0) {

    if (0 < DAT_0059ac80) {

      pfVar8 = (float *)(DAT_0059aca0 + 2);

      local_38 = DAT_0059ac80;

      do {

        fVar12 = pfVar8[-1];

        if (fVar12 == -NAN) {

          fVar12 = 0.0;

        }

        fVar3 = pfVar8[-2];

        iVar4 = *(int *)((int)fVar3 + 8);

        uVar7 = *(uint *)(iVar4 + 4);

        iVar5 = *(int *)(iVar4 + 0x400);

        if ((uVar7 & 0x10) == 0) {

          if ((uVar7 & 4) == 0) {

            puVar2 = (undefined4 *)((int)fVar12 * 0x50 + 0xb8 + iVar5);

            local_18 = *puVar2;

            local_14 = puVar2[1];

            local_10 = puVar2[2];

            FUN_005170f0(fVar3,&local_18,local_c);

            xform_view(local_c,local_24);

            *pfVar8 = local_1c;

          }

          else {

            if ((uVar7 & 8) == 0) {

              local_3c = 0;

              if (0 < *(int *)(iVar5 + 0x68)) {

                pfVar9 = (float *)(iVar5 + 0xb8);

                do {

                  fVar10 = pfVar9[-0xb];

                  pfVar9[2] = 0.0;

                  pfVar9[1] = 0.0;

                  *pfVar9 = 0.0;

                  if (0 < (int)fVar10) {

                    iVar6 = (int)pfVar9[-0xc] << 1;

                    do {

                      uVar7 = (uint)*(ushort *)(iVar6 + *(int *)(iVar5 + 0x34));

                      pfVar1 = (float *)(*(int *)(iVar5 + 0x14) + uVar7 * 0xc);

                      if (*pfVar9 < *(float *)(*(int *)(iVar5 + 0x14) + uVar7 * 0xc)) {

                        *pfVar9 = *pfVar1;

                      }

                      if (*pfVar9 < pfVar1[1]) {

                        *pfVar9 = pfVar1[1];

                      }

                      if (pfVar9[2] < pfVar1[2]) {

                        pfVar9[2] = pfVar1[2];

                      }

                      iVar6 = iVar6 + 2;

                      fVar10 = (float)((int)fVar10 + -1);

                    } while (fVar10 != 0.0);

                  }

                  local_3c = local_3c + 1;

                  pfVar9 = pfVar9 + 0x14;

                } while (local_3c < *(int *)(iVar5 + 0x68));

              }

              *(uint *)(iVar4 + 4) = *(uint *)(iVar4 + 4) | 8;

            }

            xform_view((int)fVar3 + 0xa0,local_24);

            *pfVar8 = local_1c -

                      *(float *)((int)fVar12 * 0x50 + 0xb8 + iVar5) * *(float *)((int)fVar3 + 0xc4);

          }

        }

        else {

          xform_view((int)fVar3 + 0xa0,local_24);

          *pfVar8 = local_1c - (float)(**(char **)((int)fVar12 * 0x50 + 0x74 + iVar5) + -0x41);

        }

        pfVar8 = pfVar8 + 3;

        local_38 = local_38 + -1;

      } while (local_38 != 0);

    }

    FUN_00543bc3(piVar11,iVar13,0xc,&LAB_0042d860);

    if (0 < iVar13) {

      do {

        iVar4 = *piVar11;

        iVar5 = piVar11[1];

        iVar6 = FUN_0042b060(iVar4,0,0);

        uVar7 = *(uint *)((iVar5 * 5 + 10) * 0x10 +

                         *(int *)(*(int *)(iVar4 + 8) + 0x400 + iVar6 * 4)) & 0xf;

        if ((uVar7 == 1) || (uVar7 == 2)) {

          (**(code **)(DAT_00656420 + 0x10))(DAT_00656420);

          (**(code **)(DAT_00656420 + 0xac))

                    (DAT_00656420,*(undefined4 *)(DAT_006330e4 + 0x128),

                     *(undefined4 *)(DAT_006330e4 + 300),&DAT_0059aca4);

          if (iVar5 == -1) {

            FUN_0042d8a0(iVar4);

          }

          else {

            status_hud_render(iVar4,6,iVar5);

          }

          (**(code **)(DAT_00656420 + 0x10))(DAT_00656420);

          (**(code **)(DAT_00656420 + 0xac))

                    (DAT_00656420,*(undefined4 *)(DAT_006330e4 + 0x128),

                     *(undefined4 *)(DAT_006330e4 + 300),DAT_006330e4 + 0x130);

        }

        else if (iVar5 == -1) {

          FUN_0042d8a0(iVar4);

        }

        else {

          status_hud_render(iVar4,6,iVar5);

        }

        piVar11 = piVar11 + 3;

        iVar13 = iVar13 + -1;

      } while (iVar13 != 0);

    }

  }

  return;

}

/* ===== FUN_0042d8a0 @ 0x0042D8A0 ===== */
void FUN_0042d8a0(int param_1)



{

  uint uVar1;

  undefined4 uVar2;

  undefined1 *puVar3;

  int iVar4;

  float *pfVar5;

  float local_1d8;

  float local_1d4;

  float local_1d0;

  float local_1cc;

  float local_1c8;

  float local_1c0 [10];

  undefined1 local_196 [14];

  float local_188;

  float local_184;

  float local_180;

  float local_150;

  float local_14c;

  float local_148;

  float local_118;

  float local_114;

  float local_110;

  float local_e0;

  float local_dc;

  float local_d8;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_70;

  float local_6c;

  float local_68;

  float local_38;

  float local_34;

  float local_30;

  

  uVar2 = DAT_005565d0;

  pfVar5 = local_1c0;

  for (iVar4 = 0x70; iVar4 != 0; iVar4 = iVar4 + -1) {

    *pfVar5 = 0.0;

    pfVar5 = pfVar5 + 1;

  }

  uVar1 = *(uint *)(param_1 + 0xdc);

  puVar3 = local_196;

  iVar4 = 8;

  do {

    if ((uVar1 & 0x2000) == 0) {

      if ((uVar1 & 0x200) == 0) {

        if ((uVar1 & 0x400) == 0) {

          *(undefined4 *)(puVar3 + -2) = 0x3f3f3f;

        }

        else {

          puVar3[-1] = 0x3f;

        }

      }

      else {

        *puVar3 = 0x3f;

      }

    }

    else {

      *puVar3 = 0x5f;

    }

    puVar3 = puVar3 + 0x38;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x400);

  DAT_005565d0 = 0;

  main_animate_00404b60(param_1,0xffffffff);

  pfVar5 = *(float **)(iVar4 + 0x14);

  iVar4 = *(int *)(iVar4 + 0x10);

  local_1cc = *pfVar5;

  local_1c8 = pfVar5[1];

  local_148 = pfVar5[2];

  local_1d8 = *pfVar5;

  local_1d4 = pfVar5[1];

  local_1d0 = pfVar5[2];

  if (0 < iVar4) {

    do {

      if (*pfVar5 < local_1d8) {

        local_1d8 = *pfVar5;

      }

      if (pfVar5[1] < local_1d4) {

        local_1d4 = pfVar5[1];

      }

      if (pfVar5[2] < local_1d0) {

        local_1d0 = pfVar5[2];

      }

      if (local_1cc < *pfVar5) {

        local_1cc = *pfVar5;

      }

      if (local_1c8 < pfVar5[1]) {

        local_1c8 = pfVar5[1];

      }

      if (local_148 < pfVar5[2]) {

        local_148 = pfVar5[2];

      }

      pfVar5 = pfVar5 + 3;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

  }

  local_1c0[0] = local_1d8;

  local_1c0[2] = local_1d0;

  local_188 = local_1cc;

  local_180 = local_1d0;

  local_150 = local_1cc;

  local_1c0[1] = local_1d4;

  local_184 = local_1d4;

  local_14c = local_1d4;

  local_e0 = local_1d8;

  local_118 = local_1d8;

  local_114 = local_1d4;

  local_a8 = local_1cc;

  local_70 = local_1cc;

  local_dc = local_1c8;

  local_d8 = local_1d0;

  local_a4 = local_1c8;

  local_a0 = local_1d0;

  local_6c = local_1c8;

  local_38 = local_1d8;

  local_34 = local_1c8;

  DAT_005565d0 = uVar2;

  local_110 = local_148;

  local_68 = local_148;

  local_30 = local_148;

  FUN_00517510(*(undefined4 *)(param_1 + 200),*(undefined4 *)(param_1 + 0xcc),

               *(undefined4 *)(param_1 + 0xd0),*(undefined4 *)(param_1 + 0xc4),param_1 + 0xa0,8,

               local_1c0);

  (**(code **)(DAT_0065642c + 8))(DAT_0065642c,0x60100,0,0x80ffffff);

  FUN_0042f8e0(local_1c0,&local_188,&local_150);

  FUN_0042f8e0(local_1c0,&local_150,&local_118);

  FUN_0042f8e0(local_1c0,&local_118,&local_e0);

  FUN_0042f8e0(&local_e0,&local_118,&local_38);

  FUN_0042f8e0(&local_118,&local_150,&local_70);

  FUN_0042f8e0(&local_118,&local_70,&local_38);

  FUN_0042f8e0(&local_188,&local_70,&local_150);

  FUN_0042f8e0(&local_188,&local_a8,&local_70);

  FUN_0042f8e0(&local_a8,&local_38,&local_70);

  FUN_0042f8e0(&local_a8,&local_e0,&local_38);

  FUN_0042f8e0(local_1c0,&local_a8,&local_188);

  FUN_0042f8e0(local_1c0,&local_e0,&local_a8);

  *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0xfffff9ff;

  return;

}

/* ===== alpha_queue_push @ 0x0042DC50 ===== */
void alpha_queue_push(int param_1)



{

  bool bVar1;

  bool bVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  iVar3 = FUN_0042b060(param_1,0,0);

  iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x400 + iVar3 * 4);

  bVar2 = false;

  if (0 < *(int *)(iVar3 + 0x68)) {

    iVar6 = 0;

    do {

      if ((*(int *)(param_1 + 0x204) == 0) ||

         (iVar4 = FUN_00513ac0(param_1,iVar3,iVar6), iVar4 == 0)) {

        iVar5 = *(int *)(iVar6 * 0x50 + 0x90 + iVar3);

        iVar4 = iVar6 * 0x50 + iVar3;

        if (iVar5 == 0) {

LAB_0042dcd8:

          bVar1 = false;

        }

        else {

          texture_alloc_helper(iVar5);

          iVar5 = FUN_00508fa0(*(undefined4 *)(iVar4 + 0x90));

          if (iVar5 == 0) goto LAB_0042dcd8;

          bVar1 = true;

        }

        if ((((*(float *)(iVar4 + 0x98) != 0.0) || (bVar1)) || (*(float *)(param_1 + 0x184) != 0.0))

           || (((*(uint *)(param_1 + 0x1c8) & 0x800000) != 0 ||

               ((*(uint *)(param_1 + 0xdc) & 0x40000) != 0)))) {

          if ((*(uint *)(param_1 + 0xdc) & 0x200000) == 0) {

            if (DAT_0059ac80 < 1000) {

              *(int *)(DAT_0059aca0 + DAT_0059ac80 * 0xc) = param_1;

              *(int *)(DAT_0059aca0 + 4 + DAT_0059ac80 * 0xc) = iVar6;

              DAT_0059ac80 = DAT_0059ac80 + 1;

            }

            else if (iVar6 == -1) {

              FUN_0042d8a0(param_1);

              FUN_00425eb0(s_Overflow_alpha_queue_00556628);

            }

            else {

              status_hud_render(param_1,6,iVar6);

              FUN_00425eb0(s_Overflow_alpha_queue_00556628);

            }

          }

          else if (iVar6 == -1) {

            FUN_0042d8a0(param_1);

          }

          else {

            status_hud_render(param_1,6,iVar6);

          }

        }

        else {

          bVar2 = true;

        }

      }

      iVar6 = iVar6 + 1;

    } while (iVar6 < *(int *)(iVar3 + 0x68));

  }

  if ((*(uint *)(param_1 + 0xdc) & 0x2700) != 0) {

    if ((*(uint *)(param_1 + 0xdc) & 0x200000) == 0) {

      if (DAT_0059ac80 < 1000) {

        *(int *)(DAT_0059aca0 + DAT_0059ac80 * 0xc) = param_1;

        *(undefined4 *)(DAT_0059aca0 + 4 + DAT_0059ac80 * 0xc) = 0xffffffff;

        DAT_0059ac80 = DAT_0059ac80 + 1;

      }

      else {

        FUN_0042d8a0(param_1);

        FUN_00425eb0(s_Overflow_alpha_queue_00556628);

      }

    }

    else {

      FUN_0042d8a0(param_1);

    }

  }

  if (bVar2) {

    status_hud_render(param_1,1,0xffffffff);

  }

  return;

}

/* ===== shrap_create_water @ 0x0042DE50 ===== */
void shrap_create_water(undefined4 param_1)



{

  FUN_0042b060(param_1,0,0);

  status_hud_render(param_1,0xffff,0xffffffff);

  return;

}

/* ===== FUN_0042de80 @ 0x0042DE80 ===== */
void FUN_0042de80(undefined4 param_1,undefined4 *param_2,float param_3,undefined4 *param_4)



{

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  FUN_0053e960(&local_c,param_1);

  FUN_0053e900(&local_18,&local_c,&DAT_005565d4);

  FUN_0053e960(&local_18,&local_18);

  FUN_0053e900(&local_c,&DAT_005565d4,&local_18);

  param_4[1] = local_18 * param_3;

  param_4[5] = local_14 * param_3;

  param_4[9] = local_10 * param_3;

  param_4[2] = local_c * param_3;

  param_4[6] = local_8 * param_3;

  param_4[10] = local_4 * param_3;

  param_4[3] = DAT_005565d4;

  param_4[7] = DAT_005565d8;

  param_4[0xb] = DAT_005565dc;

  param_4[4] = *param_2;

  param_4[8] = param_2[1];

  param_4[0xc] = param_2[2];

  param_4[0xf] = 0;

  param_4[0xe] = 0;

  param_4[0xd] = 0;

  param_4[0x10] = 0x3f800000;

  *param_4 = 0x13;

  return;

}

/* ===== fx_blastmark @ 0x0042DF60 ===== */
void fx_blastmark(void)



{

  DAT_006573f4 = main_texture_00508750(s_Blastmark_2_00556640);

  DAT_006573e8 = main_drawwrld_00435170(200,0x32,2);

  sceMpegSetDecodeMode(DAT_006573e8,0x33c,DAT_006573f4,0xffffffff);

  return;

}

/* ===== drawwrld_helper_a @ 0x0042DFA0 ===== */
void drawwrld_helper_a(void)



{

  main_drawwrld_00434c80(DAT_006573e8);

  DAT_006573e8 = 0;

  return;

}

/* ===== dlog_free_global_1 @ 0x0042DFC0 ===== */
void dlog_free_global_1(void)



{

  cleanup_00434d40(DAT_006573e8);

  return;

}

/* ===== FUN_0042dfd0 @ 0x0042DFD0 ===== */
void FUN_0042dfd0(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  undefined1 local_5c [24];

  undefined1 local_44 [68];

  

  FUN_0042e030(param_1,param_2,param_3,local_44,local_5c);

  main_drawwrld_00434ce0(DAT_006573e8);

  main_drawwrld_00435940(DAT_006573e8,local_44,local_5c);

  dlog_level_free_if(DAT_006573e8);

  return;

}

/* ===== FUN_0042e030 @ 0x0042E030 ===== */
void FUN_0042e030(undefined4 *param_1,undefined4 param_2,float param_3,undefined4 *param_4,

                 undefined4 *param_5)



{

  float fVar1;

  float fVar2;

  float10 fVar3;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  fVar3 = (float10)FUN_004d5780(0x3f4ccccd,0x3fc00000);

  fVar1 = (float)(fVar3 * (float10)param_3);

  fVar3 = (float10)FUN_004d5780(0x3f4ccccd,0x3fc00000);

  fVar2 = (float)(fVar3 * (float10)param_3);

  FUN_0053e960(&local_c,param_2);

  FUN_0053e900(&local_18,&local_c,&DAT_005565e0);

  FUN_0053e960(&local_18,&local_18);

  FUN_0053e900(&local_c,&DAT_005565e0,&local_18);

  param_4[1] = local_18 * fVar1;

  param_4[5] = local_14 * fVar1;

  param_4[9] = local_10 * fVar1;

  param_4[2] = local_c * fVar2;

  param_4[6] = local_8 * fVar2;

  param_4[10] = local_4 * fVar2;

  param_4[3] = DAT_005565e0;

  param_4[7] = DAT_005565e4;

  param_4[0xb] = DAT_005565e8;

  param_4[4] = *param_1;

  param_4[8] = param_1[1];

  param_4[0xc] = param_1[2];

  param_4[0xf] = 0;

  param_4[0xe] = 0;

  param_4[0xd] = 0;

  param_4[0x10] = 0x3f800000;

  *param_4 = 0x13;

  *param_5 = 0xbf000000;

  param_5[1] = 0xbe600000;

  param_5[3] = 0x3f000000;

  param_5[4] = 0x3f480000;

  param_5[5] = 0;

  param_5[2] = 0;

  return;

}

/* ===== fx_kabuto_footprint @ 0x0042E1F0 ===== */
void fx_kabuto_footprint(void)



{

  DAT_006573e4 = main_texture_00508750(s_Kabuto_footprint_0055664c);

  DAT_006573ec = main_drawwrld_00435170(400,100,2);

  sceMpegSetDecodeMode(DAT_006573ec,0x33c,DAT_006573e4,0xffffffff);

  return;

}

/* ===== drawwrld_helper_b @ 0x0042E230 ===== */
void drawwrld_helper_b(void)



{

  main_drawwrld_00434c80(DAT_006573ec);

  DAT_006573ec = 0;

  return;

}

/* ===== dlog_free_global_2 @ 0x0042E250 ===== */
void dlog_free_global_2(void)



{

  cleanup_00434d40(DAT_006573ec);

  return;

}

/* ===== FUN_0042e260 @ 0x0042E260 ===== */
void FUN_0042e260(int param_1,int param_2)



{

  undefined4 uStack_b8;

  undefined4 uStack_b4;

  undefined4 uStack_b0;

  undefined4 uStack_ac;

  undefined4 uStack_a8;

  undefined4 uStack_a4;

  undefined4 uStack_a0;

  undefined4 uStack_9c;

  undefined4 uStack_98;

  undefined4 uStack_94;

  undefined4 uStack_90;

  undefined4 uStack_8c;

  undefined1 local_88 [12];

  undefined4 uStack_7c;

  undefined4 uStack_78;

  undefined4 uStack_6c;

  undefined4 uStack_68;

  undefined4 uStack_5c;

  undefined4 uStack_58;

  undefined1 auStack_44 [68];

  

  (*(code *)PTR_FUN_00580c18)

            (local_88,param_1 + 0x294,(param_2 + 5) * 0x44 + *(int *)(param_1 + 0x2dc));

  uStack_ac = uStack_7c;

  uStack_a8 = uStack_6c;

  uStack_b8 = uStack_78;

  uStack_a4 = uStack_5c;

  uStack_b4 = uStack_68;

  uStack_b0 = uStack_58;

  FUN_0042de80(&uStack_ac,&uStack_b8,*(undefined4 *)(param_1 + 0xc4),auStack_44);

  uStack_a0 = 0xc1000000;

  uStack_9c = 0xbfa66669;

  uStack_94 = 0x41000000;

  uStack_90 = 0x41c59999;

  uStack_8c = 0;

  uStack_98 = 0;

  main_drawwrld_00434ce0(DAT_006573ec);

  main_drawwrld_00435940(DAT_006573ec,auStack_44,&uStack_a0);

  dlog_level_free_if(DAT_006573ec);

  return;

}

/* ===== FUN_0042e350 @ 0x0042E350 ===== */
void FUN_0042e350(void)



{

  DAT_006573f0 = main_drawwrld_00435170(200,0x32,2);

  sceMpegSetDecodeMode(DAT_006573f0,0x33c,DAT_006573f4,0xffffffff);

  return;

}

/* ===== drawwrld_helper_c @ 0x0042E380 ===== */
void drawwrld_helper_c(void)



{

  main_drawwrld_00434c80(DAT_006573f0);

  DAT_006573f0 = 0;

  return;

}

/* ===== dlog_free_global_3 @ 0x0042E3A0 ===== */
void dlog_free_global_3(void)



{

  cleanup_00434d40(DAT_006573f0);

  return;

}

/* ===== mpeg_mode_set @ 0x0042E3B0 ===== */
void mpeg_mode_set(int param_1,undefined4 param_2,undefined4 param_3)



{

  float local_68;

  float local_64;

  float local_60;

  undefined1 local_5c [24];

  undefined1 local_44 [68];

  

  local_68 = -*(float *)(param_1 + 0x29c);

  local_64 = -*(float *)(param_1 + 0x2ac);

  local_60 = -*(float *)(param_1 + 700);

  FUN_0042e030(param_1 + 0xa0,&local_68,param_3,local_44,local_5c);

  main_drawwrld_00434ce0(DAT_006573f0);

  sceMpegSetDecodeMode(DAT_006573f0,0x33c,param_2,0xffffffff);

  main_drawwrld_00435940(DAT_006573f0,local_44,local_5c);

  dlog_level_free_if(DAT_006573f0);

  return;

}

/* ===== _cleanup_4 @ 0x0042E450 ===== */
void _cleanup_4(void)



{

  main_drawwrld_00434c30(DAT_006573f0);

  return;

}

/* ===== animate_core_caller @ 0x0042E460 ===== */
void animate_core_caller(int param_1,undefined4 param_2,int param_3,undefined4 param_4,

                        undefined4 param_5)



{

  float fVar1;

  ushort uVar2;

  undefined4 uVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  ushort *puVar9;

  float10 fVar10;

  float10 fVar11;

  undefined1 local_44 [4];

  undefined1 local_40 [64];

  

  iVar6 = DAT_005565d0;

  if (DAT_005565d0 < 0) {

    fVar1 = *(float *)(*(int *)(param_1 + 8) + 0x42c);

    if (fVar1 < 0.0 == (fVar1 == 0.0)) {

      fVar10 = (float10)FUN_0050a580(param_1 + 0xa0,param_5);

      fVar1 = *(float *)(param_1 + 0x1f0);

      fVar11 = (float10)FUN_00515dd0();

      iVar5 = 0;

      piVar4 = (int *)(*(int *)(param_1 + 8) + 0x404);

      fVar10 = (fVar11 / (float10)*(float *)(param_1 + 0xc4)) *

               (float10)(float)(fVar10 + (float10)fVar1);

      iVar7 = 0;

      do {

        fVar1 = (float)piVar4[10];

        iVar6 = iVar5;

        if (fVar1 < 0.0 == (fVar1 == 0.0)) {

          fVar11 = fVar10;

          if (*piVar4 != 0) {

            iVar7 = iVar5;

            fVar11 = fVar10 * (float10)*(float *)(&DAT_005565c0 + DAT_00633150 * 4);

          }

          if ((float)fVar11 < fVar1) break;

        }

        else if (fVar1 == -3.0) break;

        iVar6 = iVar7;

        iVar5 = iVar5 + 1;

        piVar4 = piVar4 + 1;

        iVar7 = iVar6;

      } while (iVar5 < 9);

    }

    else {

      iVar6 = 0;

    }

  }

  iVar7 = *(int *)(*(int *)(param_1 + 8) + 0x400 + iVar6 * 4);

  if (param_3 != 0) {

    *(undefined4 *)(iVar7 + 0x5c) = 0xbf800000;

  }

  main_animate_00404b60(param_1,iVar6);

  FUN_0053d970(local_44,param_4);

  (**(code **)(DAT_00656420 + 0x18))(DAT_00656420,local_40);

  (**(code **)(DAT_00656430 + 8))(DAT_00656430,0x20060,0,0xffffff);

  iVar6 = 0;

  if (0 < *(int *)(iVar7 + 0x68)) {

    piVar4 = (int *)(iVar7 + 0x88);

    do {

      if ((*(int *)(param_1 + 0x26c) == 0) ||

         ((1 << ((byte)iVar6 & 0x1f) & *(uint *)(*(int *)(param_1 + 0x26c) + (iVar6 >> 5) * 4)) != 0

         )) {

        uVar3 = (**(code **)(DAT_0065644c + 0x10))(DAT_0065644c,piVar4[1],iVar7,iVar6);

        (*(code *)PTR_FUN_005565b0)(uVar3);

        (**(code **)(DAT_0065644c + 0x18))(DAT_0065644c,-*piVar4);

        puVar9 = (ushort *)piVar4[-1];

        while( true ) {

          uVar2 = *puVar9;

          uVar8 = (uint)uVar2;

          puVar9 = puVar9 + 1;

          if (uVar8 == 0) break;

          if ((uVar2 & 0x8000) == 0) {

            if ((uVar2 & 0x4000) == 0) {

              (**(code **)(DAT_0065644c + 0x20))(DAT_0065644c,uVar8 * 3,puVar9);

              puVar9 = puVar9 + uVar8 * 3;

            }

            else {

              (**(code **)(DAT_0065644c + 0x28))(DAT_0065644c,uVar8 & 0xffffbfff);

              puVar9 = puVar9 + (uVar8 & 0xffffbfff);

            }

          }

          else {

            (**(code **)(DAT_0065644c + 0x24))(DAT_0065644c,uVar8 & 0xffff7fff);

            puVar9 = puVar9 + (uVar8 & 0xffff7fff);

          }

        }

      }

      iVar6 = iVar6 + 1;

      piVar4 = piVar4 + 0x14;

    } while (iVar6 < *(int *)(iVar7 + 0x68));

  }

  return;

}

/* ===== rp_spark_hud_setup @ 0x0042E690 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void rp_spark_hud_setup(int param_1)



{

  ushort uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  undefined4 uVar7;

  float10 fVar8;

  undefined4 local_fc;

  undefined4 local_f8;

  undefined4 local_f4;

  undefined4 local_f0;

  undefined4 local_ec;

  undefined4 local_e8;

  undefined4 local_e4;

  undefined4 local_e0;

  undefined4 local_dc;

  undefined4 local_d8;

  undefined4 local_d4;

  undefined4 local_d0;

  undefined1 local_cc [68];

  undefined1 auStack_88 [68];

  undefined1 local_44 [68];

  

  if (*(int *)(param_1 + 0x210) != 0) {

    return;

  }

  if (*(int *)(param_1 + 4) == 3) {

    if (*(int *)(param_1 + 8) == 0) {

      return;

    }

    local_e4 = 0xc1000000;

    local_e0 = 0xc1000000;

    local_dc = 0;

    local_d8 = 0x41000000;

    local_d4 = 0x41000000;

    local_d0 = 0;

    if (DAT_0059acb0 == 0) {

      DAT_0059acb0 = main_texture_00508750(s_rp_spark_00556660);

    }

    local_f0 = *(undefined4 *)(param_1 + 0x29c);

    local_ec = *(undefined4 *)(param_1 + 0x2ac);

    local_e8 = *(undefined4 *)(param_1 + 700);

    local_fc = *(undefined4 *)(param_1 + 0x2a4);

    local_f8 = *(undefined4 *)(param_1 + 0x2b4);

    local_f4 = *(undefined4 *)(param_1 + 0x2c4);

    FUN_0042de80(&local_f0,&local_fc,*(undefined4 *)(param_1 + 0xc4),local_44);

    FUN_00518b70(param_1,0);

    fVar8 = (float10)AddHud__4cHudP8cHudIcon_6();

    _DAT_0059acb4 = (float)fVar8;

    iVar2 = __ftol();

    FUN_00436090(0x134,DAT_0059acb0,iVar2 << 0x18);

    FUN_0053dd90(local_cc,_DAT_0059acb4 * 6.2831855);

    (*(code *)PTR_FUN_00580c18)(auStack_88,local_44,local_cc);

    FUN_004360d0(auStack_88,&local_e4);

    FUN_0053dd90(local_cc,_DAT_0059acb4 * -6.2831855);

    (*(code *)PTR_FUN_00580c18)(auStack_88,local_44,local_cc);

    FUN_004360d0(auStack_88,&local_e4);

    return;

  }

  local_fc = *(undefined4 *)(param_1 + 0x29c);

  local_f8 = *(undefined4 *)(param_1 + 0x2ac);

  local_f4 = *(undefined4 *)(param_1 + 700);

  iVar2 = *(int *)(param_1 + 0x2e0);

  local_f0 = *(undefined4 *)(param_1 + 0x2a4);

  local_ec = *(undefined4 *)(param_1 + 0x2b4);

  local_e8 = *(undefined4 *)(param_1 + 0x2c4);

  FUN_0042de80(&local_fc,&local_f0,*(undefined4 *)(param_1 + 0xc4),local_cc);

  if (iVar2 != 0) {

    uVar1 = *(ushort *)(iVar2 + 0x1e) & 0x80;

    if ((uVar1 == 0) || (DAT_006331c0 == 0)) {

      if (uVar1 != 0) {

        uVar4 = __ftol();

        uVar4 = uVar4 | (uVar4 << 8 | uVar4) << 8;

        iVar5 = *(int *)(param_1 + 8);

        iVar6 = *(int *)(iVar5 + 8 + *(int *)(param_1 + 0x10) * 4);

        uVar7 = 0x23234;

        goto LAB_0042e978;

      }

    }

    else {

      iVar2 = 0;

    }

  }

  iVar3 = __ftol();

  iVar5 = *(int *)(param_1 + 8);

  iVar6 = *(int *)(iVar5 + 0xc);

  uVar4 = iVar3 << 0x18;

  uVar7 = 0x60338;

LAB_0042e978:

  if (((iVar6 != 0) && (iVar6 = iVar6 + 0xc, iVar6 != 0)) ||

     ((*(int *)(iVar5 + 0x400) != 0 && (iVar6 = *(int *)(iVar5 + 0x400) + 0x44, iVar6 != 0)))) {

    if (*(int *)(param_1 + 0x1c8) < 0) {

      if (iVar2 == 0) {

        FUN_00436170();

        FUN_00436190(local_cc,iVar6);

      }

      else {

        FUN_00436130(uVar7,iVar2);

        FUN_00436150(local_cc,iVar6);

      }

      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x40000000;

      return;

    }

    if (iVar2 != 0) {

      FUN_00436090(uVar7,iVar2);

      FUN_004360d0(local_cc,iVar6);

      return;

    }

    FUN_004360f0(uVar4);

    FUN_00436110(local_cc,iVar6);

  }

  return;

}

/* ===== FUN_0042ea60 @ 0x0042EA60 ===== */
/* PS2 candidate: texture_object_debug_dump (conf 0.333) */



void FUN_0042ea60(void)



{

  int iVar1;

  float fVar2;

  int iVar3;

  undefined4 *puVar4;

  int *piVar5;

  int iVar6;

  float10 fVar7;

  float local_4;

  

  iVar6 = 0;

  local_4 = -1.0;

  piVar5 = DAT_00632d8c;

  if (DAT_00632d8c != (int *)0x0) {

    do {

      iVar1 = piVar5[3];

      if ((local_4 < *(float *)(iVar1 + 0xf4)) || (local_4 < 0.0)) {

        local_4 = *(float *)(iVar1 + 0xf4);

        iVar6 = iVar1;

      }

      piVar5 = (int *)*piVar5;

    } while (piVar5 != (int *)0x0);

    if (iVar6 != 0) {

      if (DAT_00632e4c == 0) {

        DAT_00632e4c = main_texture_00508750(s_n_wind_005566f0);

      }

      iVar1 = DAT_00632e4c;

      if (*(float *)(DAT_00632ed8 + 0x35c) * *(float *)(iVar6 + 0xf4) != 0.0) {

        iVar3 = __ftol();

        (**(code **)(DAT_00656428 + 8))(DAT_00656428,0x40324,iVar1,iVar3 << 0x18);

        fVar7 = (float10)FUN_00518b70(iVar6,0);

        fVar7 = fVar7 * (float10)*(float *)(DAT_00632ed8 + 0x360) + (float10)DAT_0059b7b0;

        DAT_0059b7b0 = (float)fVar7;

        if ((float10)1.0 < fVar7) {

          DAT_0059b7b0 = DAT_0059b7b0 - 1.0;

        }

        puVar4 = (undefined4 *)(**(code **)(DAT_00656438 + 0x10))(DAT_00656438,4);

        *puVar4 = 0;

        puVar4[1] = 0;

        puVar4[5] = DAT_0059b7b0;

        puVar4[6] = 0x3f800000;

        fVar2 = (float)DAT_00632e84;

        puVar4[8] = 0;

        puVar4[7] = fVar2;

        fVar2 = DAT_0059b7b0;

        puVar4[0xd] = 0x3f800000;

        puVar4[0xc] = fVar2 + 1.0;

        puVar4[0xe] = (float)DAT_00632e84;

        puVar4[0xf] = (float)DAT_00632e88;

        fVar2 = DAT_0059b7b0;

        puVar4[0x14] = 0;

        puVar4[0x15] = 0;

        puVar4[0x13] = fVar2 + 1.0;

        puVar4[0x16] = (float)DAT_00632e88;

        fVar2 = DAT_0059b7b0;

        puVar4[0x1b] = 0;

        puVar4[0x1a] = fVar2;

        return;

      }

    }

  }

  return;

}

/* ===== FUN_0042ebf0 @ 0x0042EBF0 ===== */
void FUN_0042ebf0(float param_1,float param_2,float param_3,float param_4,float param_5)



{

  float fVar1;

  float *pfVar2;

  

  (**(code **)(DAT_00656428 + 8))(DAT_00656428,0xa0,0,0);

  pfVar2 = (float *)(**(code **)(DAT_00656438 + 0x10))(DAT_00656438,4);

  *pfVar2 = (float)DAT_00632e84 * param_2;

  pfVar2[1] = (float)DAT_00632e88 * param_4;

  pfVar2[7] = (float)DAT_00632e84 * param_3;

  pfVar2[8] = (float)DAT_00632e88 * param_4;

  pfVar2[0xe] = (float)DAT_00632e84 * param_3;

  pfVar2[0xf] = (float)DAT_00632e88 * param_5;

  pfVar2[0x15] = (float)DAT_00632e84 * param_2;

  fVar1 = (float)DAT_00632e88;

  pfVar2[0x19] = param_1;

  pfVar2[0x12] = param_1;

  pfVar2[0xb] = param_1;

  pfVar2[4] = param_1;

  pfVar2[0x16] = fVar1 * param_5;

  return;

}

/* ===== FUN_0042ec90 @ 0x0042EC90 ===== */
void FUN_0042ec90(float *param_1,float param_2,float param_3)



{

  int iVar1;

  int iVar2;

  float *pfVar3;

  byte *pbVar4;

  float afStack_1c0 [112];

  

  iVar1 = __ftol();

  (**(code **)(DAT_0065642c + 8))(DAT_0065642c,0x41180,0,iVar1 << 0x18);

  pfVar3 = afStack_1c0;

  for (iVar1 = 0x70; iVar1 != 0; iVar1 = iVar1 + -1) {

    *pfVar3 = 0.0;

    pfVar3 = pfVar3 + 1;

  }

  iVar1 = 0;

  pfVar3 = afStack_1c0 + 1;

  do {

    pfVar3[9] = param_3;

    iVar2 = iVar1 + 4;

    pfVar3[-1] = param_2 * *(float *)((int)&DAT_0055666c + iVar1) + *param_1;

    *pfVar3 = param_2 * *(float *)((int)&DAT_0055668c + iVar1) + param_1[1];

    pfVar3[1] = param_2 * *(float *)((int)&DAT_005566ac + iVar1) + param_1[2];

    iVar1 = iVar2;

    pfVar3 = pfVar3 + 0xe;

  } while (iVar2 < 0x20);

  FUN_00516d80(8,afStack_1c0);

  pbVar4 = &DAT_005566cd;

  iVar1 = 0xc;

  do {

    FUN_0042f8e0(afStack_1c0 + (uint)pbVar4[-1] * 0xe,afStack_1c0 + (uint)*pbVar4 * 0xe,

                 afStack_1c0 + (uint)pbVar4[1] * 0xe);

    pbVar4 = pbVar4 + 3;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  return;

}

/* ===== FUN_0042ed90 @ 0x0042ED90 ===== */
void FUN_0042ed90(float *param_1,float param_2,undefined4 param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  undefined4 *puVar4;

  int iVar5;

  float fVar6;

  float fVar7;

  float *pfVar8;

  float local_98;

  int local_94;

  float local_88;

  float local_78;

  float local_74;

  float afStack_70 [9];

  undefined4 uStack_4c;

  undefined4 auStack_48 [4];

  float fStack_38;

  float fStack_34;

  float fStack_30;

  undefined4 uStack_14;

  

  local_98 = 0.0;

  local_94 = 0x14;

  fVar6 = param_2 * 0.0 + *param_1;

  fVar7 = param_1[1] - param_2;

  local_88 = param_1[2];

  do {

    local_98 = local_98 + 18.0;

    FUN_0050ae40(local_98,&local_78,&local_74);

    fVar1 = param_1[2];

    fVar2 = local_78 * param_2 + *param_1;

    fVar3 = param_1[1] - local_74 * param_2;

    (**(code **)(DAT_0065642c + 8))(DAT_0065642c,0x80,0,0);

    pfVar8 = afStack_70;

    for (iVar5 = 0x1c; iVar5 != 0; iVar5 = iVar5 + -1) {

      *pfVar8 = 0.0;

      pfVar8 = pfVar8 + 1;

    }

    afStack_70[2] = local_88;

    puVar4 = auStack_48;

    iVar5 = 2;

    fStack_38 = fVar2;

    fStack_34 = fVar3;

    fStack_30 = fVar1;

    do {

      *puVar4 = param_3;

      puVar4 = puVar4 + 0xe;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

    afStack_70[0] = fVar6;

    afStack_70[1] = fVar7;

    FUN_00516d80(2,afStack_70);

    uStack_14 = 0x3d4ccccd;

    uStack_4c = 0x3d4ccccd;

    FUN_0042a640(afStack_70,&fStack_38);

    local_94 = local_94 + -1;

    fVar6 = fVar2;

    fVar7 = fVar3;

    local_88 = fVar1;

  } while (local_94 != 0);

  return;

}

/* ===== FUN_0042eee0 @ 0x0042EEE0 ===== */
void FUN_0042eee0(undefined4 *param_1,undefined4 *param_2)



{

  if (DAT_0059b7b4 < 0x40) {

    (&DAT_0059acb8)[DAT_0059b7b4 * 3] = *param_1;

    (&DAT_0059acbc)[DAT_0059b7b4 * 3] = param_1[1];

    (&DAT_0059acc0)[DAT_0059b7b4 * 3] = param_1[2];

    (&DAT_0059afb8)[DAT_0059b7b4 * 3] = *param_2;

    (&DAT_0059afbc)[DAT_0059b7b4 * 3] = param_2[1];

    (&DAT_0059afc0)[DAT_0059b7b4 * 3] = param_2[2];

    DAT_0059b7b4 = DAT_0059b7b4 + 1;

  }

  return;

}

/* ===== FUN_0042ef40 @ 0x0042EF40 ===== */
void FUN_0042ef40(undefined4 *param_1,undefined4 param_2)



{

  int iVar1;

  undefined4 uVar2;

  

  if (DAT_0059b7c4 < 8) {

    iVar1 = DAT_0059b7c4 * 0xc;

    *(undefined4 *)(&DAT_0059b2b8 + iVar1) = *param_1;

    *(undefined4 *)(&DAT_0059b2bc + iVar1) = param_1[1];

    uVar2 = param_1[2];

    (&DAT_0059b318)[DAT_0059b7c4] = param_2;

    DAT_0059b7c4 = DAT_0059b7c4 + 1;

    *(undefined4 *)(&DAT_0059b2c0 + iVar1) = uVar2;

  }

  return;

}

/* ===== FUN_0042ef80 @ 0x0042EF80 ===== */
void FUN_0042ef80(void)



{

  undefined4 uVar1;

  int *piVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  undefined *puVar8;

  undefined4 *puVar9;

  int iVar10;

  byte *pbVar11;

  int iStack_26c;

  undefined4 auStack_268 [9];

  undefined4 uStack_244;

  int aiStack_240 [4];

  undefined4 uStack_230;

  undefined4 uStack_22c;

  undefined4 uStack_228;

  undefined4 uStack_20c;

  undefined4 uStack_1f8;

  undefined4 uStack_1f4;

  undefined4 uStack_1f0;

  undefined4 auStack_1c0 [112];

  

  if (DAT_0059b7b4 + DAT_0059b7bc + DAT_0059b7b8 != DAT_0059b7c4 + DAT_0059b7c0) {

    iVar7 = 0;

    if (0 < DAT_0059b7b4) {

      iVar10 = 0;

      do {

        (**(code **)(DAT_0065642c + 8))(DAT_0065642c,0x80,0,0);

        puVar9 = auStack_268;

        for (iVar4 = 0x1c; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar9 = 0;

          puVar9 = puVar9 + 1;

        }

        auStack_268[0] = *(undefined4 *)((int)&DAT_0059acb8 + iVar10);

        auStack_268[1] = *(undefined4 *)((int)&DAT_0059acbc + iVar10);

        auStack_268[2] = *(undefined4 *)((int)&DAT_0059acc0 + iVar10);

        uStack_230 = *(undefined4 *)((int)&DAT_0059afb8 + iVar10);

        uStack_22c = *(undefined4 *)((int)&DAT_0059afbc + iVar10);

        uStack_228 = *(undefined4 *)((int)&DAT_0059afc0 + iVar10);

        piVar2 = aiStack_240;

        iVar4 = 2;

        do {

          *piVar2 = 0x7f7fff;

          piVar2 = piVar2 + 0xe;

          iVar4 = iVar4 + -1;

        } while (iVar4 != 0);

        FUN_00516d80(2,auStack_268);

        uStack_20c = 0x3d4ccccd;

        uStack_244 = 0x3d4ccccd;

        FUN_0042a640(auStack_268,&uStack_230);

        iVar7 = iVar7 + 1;

        iVar10 = iVar10 + 0xc;

      } while (iVar7 < DAT_0059b7b4);

    }

    iVar7 = 0;

    if (0 < DAT_0059b7b8) {

      iVar10 = 0xff4040;

      iVar4 = 0;

      do {

        (**(code **)(DAT_0065642c + 8))(DAT_0065642c,0x41180,0,0xbf000000);

        puVar9 = auStack_268;

        for (iVar5 = 0x2a; iVar5 != 0; iVar5 = iVar5 + -1) {

          *puVar9 = 0;

          puVar9 = puVar9 + 1;

        }

        auStack_268[0] = *(undefined4 *)((int)&DAT_0059b374 + iVar4);

        auStack_268[1] = *(undefined4 *)((int)&DAT_0059b378 + iVar4);

        auStack_268[2] = *(undefined4 *)((int)&DAT_0059b37c + iVar4);

        uStack_230 = *(undefined4 *)((int)&DAT_0059b3b0 + iVar4);

        uStack_22c = *(undefined4 *)((int)&DAT_0059b3b4 + iVar4);

        uStack_228 = *(undefined4 *)((int)&DAT_0059b3b8 + iVar4);

        uStack_1f8 = *(undefined4 *)((int)&DAT_0059b338 + iVar4);

        uStack_1f4 = *(undefined4 *)((int)&DAT_0059b33c + iVar4);

        uStack_1f0 = *(undefined4 *)((int)&DAT_0059b340 + iVar4);

        piVar2 = aiStack_240;

        iVar5 = 3;

        do {

          *piVar2 = iVar10;

          piVar2 = piVar2 + 0xe;

          iVar5 = iVar5 + -1;

        } while (iVar5 != 0);

        FUN_00516d80(3,auStack_268);

        FUN_0042f8e0(auStack_268,&uStack_230,&uStack_1f8);

        FUN_0042f8e0(auStack_268,&uStack_1f8,&uStack_230);

        iVar7 = iVar7 + 1;

        iVar4 = iVar4 + 0xc;

        iVar10 = iVar10 + 0x1010;

      } while (iVar7 < DAT_0059b7b8);

    }

    iVar7 = 0;

    if (0 < DAT_0059b7bc) {

      puVar8 = &DAT_0059b4b0;

      iVar10 = 0x70ff70;

      do {

        FUN_0042ec90(puVar8,0x3e800000,iVar10,0x3dcccccd);

        iVar7 = iVar7 + 1;

        iVar10 = iVar10 + 0x10;

        puVar8 = puVar8 + 0xc;

      } while (iVar7 < DAT_0059b7bc);

    }

    iStack_26c = 0;

    if (0 < DAT_0059b7c0) {

      iVar7 = 0x70ff70;

      puVar9 = &DAT_0059b3f0;

      do {

        (**(code **)(DAT_0065642c + 8))(DAT_0065642c,0x41180,0,0xe5000000);

        puVar3 = auStack_1c0;

        for (iVar10 = 0x70; iVar10 != 0; iVar10 = iVar10 + -1) {

          *puVar3 = 0;

          puVar3 = puVar3 + 1;

        }

        uVar6 = 0;

        puVar3 = auStack_1c0 + 1;

        do {

          if ((uVar6 & 1) == 0) {

            uVar1 = puVar9[3];

          }

          else {

            uVar1 = *puVar9;

          }

          puVar3[-1] = uVar1;

          if ((uVar6 & 2) == 0) {

            uVar1 = puVar9[4];

          }

          else {

            uVar1 = puVar9[1];

          }

          *puVar3 = uVar1;

          if ((uVar6 & 4) == 0) {

            uVar1 = puVar9[5];

          }

          else {

            uVar1 = puVar9[2];

          }

          puVar3[1] = uVar1;

          puVar3[9] = iVar7;

          uVar6 = uVar6 + 1;

          puVar3 = puVar3 + 0xe;

        } while ((int)uVar6 < 8);

        FUN_00516d80(8,auStack_1c0);

        pbVar11 = &DAT_005566cd;

        iVar10 = 0xc;

        do {

          FUN_0042f8e0(auStack_1c0 + (uint)pbVar11[-1] * 0xe,auStack_1c0 + (uint)*pbVar11 * 0xe,

                       auStack_1c0 + (uint)pbVar11[1] * 0xe);

          pbVar11 = pbVar11 + 3;

          iVar10 = iVar10 + -1;

        } while (iVar10 != 0);

        iStack_26c = iStack_26c + 1;

        iVar7 = iVar7 + 0x10;

        puVar9 = puVar9 + 6;

      } while (iStack_26c < DAT_0059b7c0);

    }

    iVar7 = 0;

    if (0 < DAT_0059b7c4) {

      puVar8 = &DAT_0059b2b8;

      do {

        FUN_0042ed90(puVar8,(&DAT_0059b318)[iVar7],0x7f7fff);

        iVar7 = iVar7 + 1;

        puVar8 = puVar8 + 0xc;

      } while (iVar7 < DAT_0059b7c4);

    }

    DAT_0059b7b4 = 0;

    DAT_0059b7b8 = 0;

    DAT_0059b7bc = 0;

    DAT_0059b7c0 = 0;

    DAT_0059b7c4 = 0;

  }

  return;

}

/* ===== FUN_0042f310 @ 0x0042F310 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0042f310(void)



{

  float fVar1;

  int iVar2;

  undefined4 *puVar3;

  uint uVar4;

  uint uVar5;

  

  if (DAT_00632e44 == 0) {

    if (DAT_00632bb4 != 0) {

      return;

    }

    if ((DAT_00632c04 == 0) || (_DAT_00632b60 == 0.0)) {

      if (_DAT_00632b60 <= 0.0) {

        if (_DAT_00632b5c <= 0.0) {

          return;

        }

        uVar4 = 0xffffff;

        uVar5 = 0x180;

        _DAT_00632b5c = _DAT_00632b5c - DAT_006328e0 * 0.5;

        if (_DAT_00632b5c < 0.0) {

          _DAT_00632b5c = 0.0;

        }

      }

      else if (DAT_00632f08 == 0) {

        if (_DAT_00632b60 <= 3.0) {

          return;

        }

        uVar4 = 0;

        uVar5 = 0x380;

      }

      else {

        uVar4 = 0;

        uVar5 = 0x380;

      }

    }

    else {

      uVar4 = 0;

      uVar5 = 0x380;

    }

  }

  else {

    uVar4 = 0;

    uVar5 = 0x3a0;

  }

  iVar2 = __ftol();

  uVar4 = uVar4 | iVar2 << 0x18;

  (**(code **)(DAT_00656428 + 8))(DAT_00656428,uVar5 | 0x40000,0,uVar4);

  puVar3 = (undefined4 *)(**(code **)(DAT_00656438 + 0x10))(DAT_00656438,4);

  *puVar3 = 0;

  puVar3[1] = 0;

  fVar1 = (float)DAT_00632e84;

  puVar3[8] = 0;

  puVar3[7] = fVar1;

  puVar3[0xe] = (float)DAT_00632e84;

  fVar1 = (float)DAT_00632e88;

  puVar3[0x15] = 0;

  puVar3[0xf] = fVar1;

  fVar1 = (float)DAT_00632e88;

  puVar3[0x19] = uVar4;

  puVar3[0x12] = uVar4;

  puVar3[0xb] = uVar4;

  puVar3[0x16] = fVar1;

  puVar3[4] = uVar4;

  return;

}

/* ===== FUN_0042f4c0 @ 0x0042F4C0 ===== */
void FUN_0042f4c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  FUN_0042f4f0(0x3f800000,0x3f800000,param_1,param_2,param_3,param_4);

  return;

}

/* ===== FUN_0042f4f0 @ 0x0042F4F0 ===== */
void FUN_0042f4f0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,

                 int param_6)



{

  float fVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  float *pfVar10;

  undefined4 *puVar11;

  int iVar12;

  int iStack_40;

  int iStack_18;

  

  iVar3 = __ftol();

  iStack_40 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,3);

  param_5 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,4);

  if (0x80 < iStack_40) {

    iStack_40 = 0x80;

  }

  if (0x80 < param_5) {

    param_5 = 0x80;

  }

  if (param_6 != 0) {

    iVar4 = (iStack_40 + -1 + param_3) / iStack_40;

    iVar5 = (param_4 + -1 + param_5) / param_5;

    (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,2,0);

    iStack_18 = 0;

    if (0 < iVar5) {

      do {

        iVar12 = 0;

        if (0 < iVar4) {

          puVar11 = (undefined4 *)(iStack_18 * iVar4 * 0x20 + 0xc + param_6);

          do {

            if (DAT_00632ea0 == 0) {

              param_1 = 0.5 / (float)(1 << ((char)*puVar11 - *(char *)((int)puVar11 + 0x11) & 0x1fU)

                                     );

              param_2 = 0.5 / (float)(1 << ((char)puVar11[1] - *(char *)((int)puVar11 + 0x11) &

                                           0x1fU));

            }

            else {

              param_2 = 0.0;

              param_1 = 0.0;

            }

            if (iVar12 == iVar4 + -1) {

              fVar1 = (float)(param_3 - (iVar4 + -1) * iStack_40) /

                      (float)(1 << ((byte)*puVar11 & 0x1f));

            }

            else {

              fVar1 = 1.0 - param_1;

            }

            if (iStack_18 == iVar5 + -1) {

              fVar2 = (float)(param_4 - (iVar5 + -1) * param_5) /

                      (float)(1 << ((byte)puVar11[1] & 0x1f));

            }

            else {

              fVar2 = 1.0 - param_2;

            }

            iVar6 = __ftol();

            iVar7 = __ftol();

            iVar8 = __ftol();

            iVar9 = __ftol();

            (**(code **)(DAT_00656428 + 8))(DAT_00656428,0x62024,puVar11 + -3,iVar3 << 0x18);

            pfVar10 = (float *)(**(code **)(DAT_00656438 + 0x10))(DAT_00656438,4);

            *pfVar10 = (float)iVar6;

            pfVar10[6] = fVar2 + param_2;

            pfVar10[1] = (float)iVar7;

            pfVar10[5] = param_1;

            pfVar10[7] = (float)iVar8;

            pfVar10[0xc] = fVar1 + param_1;

            pfVar10[8] = (float)iVar7;

            pfVar10[0xd] = fVar2 + param_2;

            pfVar10[0xe] = (float)iVar8;

            pfVar10[0x13] = fVar1 + param_1;

            pfVar10[0xf] = (float)iVar9;

            pfVar10[0x14] = param_2;

            iVar12 = iVar12 + 1;

            pfVar10[0x15] = (float)iVar6;

            pfVar10[0x16] = (float)iVar9;

            puVar11 = puVar11 + 8;

            pfVar10[0x1a] = param_1;

            pfVar10[0x1b] = param_2;

          } while (iVar12 < iVar4);

        }

        iStack_18 = iStack_18 + 1;

      } while (iStack_18 < iVar5);

    }

    (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,0,0);

  }

  return;

}

/* ===== FUN_0042f8e0 @ 0x0042F8E0 ===== */
void FUN_0042f8e0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)



{

  float fVar1;

  undefined1 uVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  byte bVar5;

  int iVar6;

  undefined4 *puVar7;

  undefined4 *puVar8;

  undefined4 *puVar9;

  bool bVar10;

  int local_480;

  undefined4 *local_474;

  undefined4 *local_470;

  int local_46c;

  float local_468;

  float local_464;

  undefined4 local_460 [14];

  undefined4 local_428 [14];

  undefined4 local_3f0 [112];

  undefined4 local_230 [140];

  

  if ((*(byte *)(param_1 + 0xd) & *(byte *)(param_3 + 0xd) & *(byte *)(param_2 + 0xd)) == 0) {

    bVar5 = *(byte *)(param_3 + 0xd) | *(byte *)(param_2 + 0xd) | *(byte *)(param_1 + 0xd);

    DAT_0059b7c8 = (uint)bVar5;

    if (DAT_0059b7c8 == 0) {

      puVar3 = (undefined4 *)(**(code **)(DAT_00656444 + 0x10))(DAT_00656444,3);

      puVar4 = param_1 + 6;

      puVar7 = puVar3;

      for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar7 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar7 = puVar7 + 1;

      }

      puVar4 = param_2 + 6;

      puVar7 = puVar3 + 7;

      for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar7 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar7 = puVar7 + 1;

      }

      puVar4 = param_3 + 6;

      puVar7 = puVar3 + 0xe;

      for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar7 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar7 = puVar7 + 1;

      }

      return;

    }

    puVar4 = local_460;

    for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {

      *puVar4 = *param_1;

      param_1 = param_1 + 1;

      puVar4 = puVar4 + 1;

    }

    local_470 = local_230;

    puVar4 = local_428;

    for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {

      *puVar4 = *param_2;

      param_2 = param_2 + 1;

      puVar4 = puVar4 + 1;

    }

    puVar4 = local_460;

    local_480 = 3;

    puVar7 = local_3f0;

    for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {

      *puVar7 = *param_3;

      param_3 = param_3 + 1;

      puVar7 = puVar7 + 1;

    }

    if ((bVar5 & 1) != 0) {

      FUN_0042fec0(3,local_460,&local_46c,local_230);

      if (local_46c < 3) {

        return;

      }

      local_480 = local_46c;

      puVar4 = local_230;

      local_470 = local_460;

    }

    iVar6 = local_480;

    local_474 = puVar4;

    if ((DAT_0059b7c8 & 4) != 0) {

      bVar10 = local_480 != 1;

      local_480 = 0;

      DAT_0059b7c8 = 0;

      puVar7 = local_470;

      puVar3 = puVar4;

      if (bVar10) {

        local_468 = (float)(iVar6 + -1);

        do {

          bVar5 = *(byte *)(puVar3 + 0xd);

          if ((bVar5 & 4) == 0) {

            puVar8 = puVar3;

            puVar9 = puVar7;

            for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {

              *puVar9 = *puVar8;

              puVar8 = puVar8 + 1;

              puVar9 = puVar9 + 1;

            }

            puVar7 = puVar7 + 0xe;

            local_480 = local_480 + 1;

            bVar5 = *(byte *)(puVar3 + 0xd);

            DAT_0059b7c8 = DAT_0059b7c8 | bVar5;

          }

          if (((*(byte *)(puVar3 + 0x1b) ^ bVar5) & 4) != 0) {

            fVar1 = (-(float)puVar3[5] - (float)puVar3[3]) /

                    (((float)puVar3[0x13] - (float)puVar3[5]) +

                    ((float)puVar3[0x11] - (float)puVar3[3]));

            puVar7[3] = ((float)puVar3[0x11] - (float)puVar3[3]) * fVar1 + (float)puVar3[3];

            puVar7[4] = ((float)puVar3[0x12] - (float)puVar3[4]) * fVar1 + (float)puVar3[4];

            local_464 = -(float)puVar7[3];

            puVar7[5] = local_464;

            puVar7[0xb] = ((float)puVar3[0x19] - (float)puVar3[0xb]) * fVar1 + (float)puVar3[0xb];

            puVar7[0xc] = ((float)puVar3[0x1a] - (float)puVar3[0xc]) * fVar1 + (float)puVar3[0xc];

            uVar2 = __ftol();

            *(undefined1 *)(puVar7 + 10) = uVar2;

            uVar2 = __ftol();

            *(undefined1 *)((int)puVar7 + 0x29) = uVar2;

            uVar2 = __ftol();

            *(undefined1 *)((int)puVar7 + 0x2a) = uVar2;

            uVar2 = __ftol();

            *(undefined1 *)((int)puVar7 + 0x2b) = uVar2;

            if ((float)puVar7[4] <= local_464) {

              if (-local_464 <= (float)puVar7[4]) {

                *(undefined1 *)(puVar7 + 0xd) = 0;

                FUN_00516cf0(puVar7);

              }

              else {

                DAT_0059b7c8 = DAT_0059b7c8 | 0x10;

                *(undefined1 *)(puVar7 + 0xd) = 0x10;

              }

            }

            else {

              DAT_0059b7c8 = DAT_0059b7c8 | 0x20;

              *(undefined1 *)(puVar7 + 0xd) = 0x20;

            }

            puVar7 = puVar7 + 0xe;

            local_480 = local_480 + 1;

          }

          puVar3 = puVar3 + 0xe;

          local_468 = (float)((int)local_468 + -1);

        } while (local_468 != 0.0);

      }

      bVar5 = *(byte *)(puVar3 + 0xd);

      if ((bVar5 & 4) == 0) {

        puVar8 = puVar3;

        puVar9 = puVar7;

        for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {

          *puVar9 = *puVar8;

          puVar8 = puVar8 + 1;

          puVar9 = puVar9 + 1;

        }

        puVar7 = puVar7 + 0xe;

        local_480 = local_480 + 1;

        bVar5 = *(byte *)(puVar3 + 0xd);

        DAT_0059b7c8 = DAT_0059b7c8 | bVar5;

      }

      if (((*(byte *)(puVar4 + 0xd) ^ bVar5) & 4) != 0) {

        fVar1 = (-(float)puVar3[5] - (float)puVar3[3]) /

                (((float)puVar4[5] - (float)puVar3[5]) + ((float)puVar4[3] - (float)puVar3[3]));

        puVar7[3] = ((float)puVar4[3] - (float)puVar3[3]) * fVar1 + (float)puVar3[3];

        puVar7[4] = ((float)puVar4[4] - (float)puVar3[4]) * fVar1 + (float)puVar3[4];

        local_468 = -(float)puVar7[3];

        puVar7[5] = local_468;

        puVar7[0xb] = ((float)puVar4[0xb] - (float)puVar3[0xb]) * fVar1 + (float)puVar3[0xb];

        puVar7[0xc] = ((float)puVar4[0xc] - (float)puVar3[0xc]) * fVar1 + (float)puVar3[0xc];

        uVar2 = __ftol();

        *(undefined1 *)(puVar7 + 10) = uVar2;

        uVar2 = __ftol();

        *(undefined1 *)((int)puVar7 + 0x29) = uVar2;

        uVar2 = __ftol();

        *(undefined1 *)((int)puVar7 + 0x2a) = uVar2;

        uVar2 = __ftol();

        *(undefined1 *)((int)puVar7 + 0x2b) = uVar2;

        if ((float)puVar7[4] <= local_468) {

          if (-local_468 <= (float)puVar7[4]) {

            *(undefined1 *)(puVar7 + 0xd) = 0;

            FUN_00516cf0(puVar7);

          }

          else {

            DAT_0059b7c8 = DAT_0059b7c8 | 0x10;

            *(undefined1 *)(puVar7 + 0xd) = 0x10;

          }

        }

        else {

          DAT_0059b7c8 = DAT_0059b7c8 | 0x20;

          *(undefined1 *)(puVar7 + 0xd) = 0x20;

        }

        local_480 = local_480 + 1;

      }

      local_46c = local_480;

      if (local_480 < 3) {

        return;

      }

      local_474 = local_470;

      local_470 = puVar4;

    }

    puVar4 = local_474;

    if ((DAT_0059b7c8 & 8) != 0) {

      FUN_00430480(local_480,local_474,&local_46c,local_470);

      if (local_46c < 3) {

        return;

      }

      local_480 = local_46c;

      local_474 = local_470;

      local_470 = puVar4;

    }

    puVar4 = local_474;

    if ((DAT_0059b7c8 & 0x20) != 0) {

      FUN_00430b20(local_480,local_474,&local_46c,local_470);

      if (local_46c < 3) {

        return;

      }

      local_480 = local_46c;

      local_474 = local_470;

      local_470 = puVar4;

    }

    if ((DAT_0059b7c8 & 0x10) != 0) {

      FUN_00430820(local_480,local_474,&local_46c,local_470);

      if (local_46c < 3) {

        return;

      }

      local_474 = local_470;

      local_480 = local_46c;

    }

    if ((DAT_0059b7c8 == 0) &&

       (puVar4 = (undefined4 *)(**(code **)(DAT_00656448 + 0x10))(DAT_00656448,local_480),

       local_480 != 0)) {

      puVar7 = local_474 + 6;

      do {

        local_480 = local_480 + -1;

        puVar3 = puVar7;

        puVar8 = puVar4;

        for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {

          *puVar8 = *puVar3;

          puVar3 = puVar3 + 1;

          puVar8 = puVar8 + 1;

        }

        puVar4 = puVar4 + 7;

        puVar7 = puVar7 + 0xe;

      } while (local_480 != 0);

    }

  }

  return;

}

/* ===== FUN_0042fec0 @ 0x0042FEC0 ===== */
void FUN_0042fec0(undefined4 param_1,undefined4 *param_2,int *param_3,undefined4 *param_4)



{

  float fVar1;

  undefined1 uVar2;

  int iVar3;

  int iVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  

  iVar4 = 0;

  DAT_0059b7c8 = 0;

  if ((*(byte *)(param_2 + 0xd) & 1) == 0) {

    DAT_0059b7c8 = (uint)*(byte *)(param_2 + 0xd);

    puVar5 = param_2;

    puVar6 = param_4;

    for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar6 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar6 = puVar6 + 1;

    }

    iVar4 = 1;

    param_4 = param_4 + 0xe;

  }

  if (((*(byte *)(param_2 + 0x1b) ^ *(byte *)(param_2 + 0xd)) & 1) != 0) {

    fVar1 = (DAT_0057c0c0 - (float)param_2[5]) / ((float)param_2[0x13] - (float)param_2[5]);

    param_4[3] = ((float)param_2[0x11] - (float)param_2[3]) * fVar1 + (float)param_2[3];

    param_4[4] = ((float)param_2[0x12] - (float)param_2[4]) * fVar1 + (float)param_2[4];

    param_4[5] = DAT_0057c0c0;

    param_4[0xb] = ((float)param_2[0x19] - (float)param_2[0xb]) * fVar1 + (float)param_2[0xb];

    param_4[0xc] = ((float)param_2[0x1a] - (float)param_2[0xc]) * fVar1 + (float)param_2[0xc];

    uVar2 = __ftol();

    *(undefined1 *)(param_4 + 10) = uVar2;

    uVar2 = __ftol();

    *(undefined1 *)((int)param_4 + 0x29) = uVar2;

    uVar2 = __ftol();

    *(undefined1 *)((int)param_4 + 0x2a) = uVar2;

    uVar2 = __ftol();

    *(undefined1 *)((int)param_4 + 0x2b) = uVar2;

    if (-(float)param_4[5] <= (float)param_4[3]) {

      if ((float)param_4[3] <= (float)param_4[5]) {

        if ((float)param_4[4] <= (float)param_4[5]) {

          if (-(float)param_4[5] <= (float)param_4[4]) {

            *(undefined1 *)(param_4 + 0xd) = 0;

            FUN_00516cf0(param_4);

          }

          else {

            *(undefined1 *)(param_4 + 0xd) = 0x10;

            DAT_0059b7c8 = DAT_0059b7c8 | 0x10;

          }

        }

        else {

          *(undefined1 *)(param_4 + 0xd) = 0x20;

          DAT_0059b7c8 = DAT_0059b7c8 | 0x20;

        }

      }

      else {

        *(undefined1 *)(param_4 + 0xd) = 8;

        DAT_0059b7c8 = DAT_0059b7c8 | 8;

      }

    }

    else {

      *(undefined1 *)(param_4 + 0xd) = 4;

      DAT_0059b7c8 = DAT_0059b7c8 | 4;

    }

    iVar4 = iVar4 + 1;

    param_4 = param_4 + 0xe;

  }

  if ((*(byte *)(param_2 + 0x1b) & 1) == 0) {

    DAT_0059b7c8 = DAT_0059b7c8 | *(byte *)(param_2 + 0x1b);

    iVar4 = iVar4 + 1;

    puVar5 = param_2 + 0xe;

    puVar6 = param_4;

    for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar6 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar6 = puVar6 + 1;

    }

    param_4 = param_4 + 0xe;

  }

  if (((*(byte *)(param_2 + 0x1b) ^ *(byte *)(param_2 + 0x29)) & 1) != 0) {

    fVar1 = (DAT_0057c0c0 - (float)param_2[0x13]) / ((float)param_2[0x21] - (float)param_2[0x13]);

    param_4[3] = ((float)param_2[0x1f] - (float)param_2[0x11]) * fVar1 + (float)param_2[0x11];

    param_4[4] = ((float)param_2[0x20] - (float)param_2[0x12]) * fVar1 + (float)param_2[0x12];

    param_4[5] = DAT_0057c0c0;

    param_4[0xb] = ((float)param_2[0x27] - (float)param_2[0x19]) * fVar1 + (float)param_2[0x19];

    param_4[0xc] = ((float)param_2[0x28] - (float)param_2[0x1a]) * fVar1 + (float)param_2[0x1a];

    uVar2 = __ftol();

    *(undefined1 *)(param_4 + 10) = uVar2;

    uVar2 = __ftol();

    *(undefined1 *)((int)param_4 + 0x29) = uVar2;

    uVar2 = __ftol();

    *(undefined1 *)((int)param_4 + 0x2a) = uVar2;

    uVar2 = __ftol();

    *(undefined1 *)((int)param_4 + 0x2b) = uVar2;

    if (-(float)param_4[5] <= (float)param_4[3]) {

      if ((float)param_4[3] <= (float)param_4[5]) {

        if ((float)param_4[4] <= (float)param_4[5]) {

          if (-(float)param_4[5] <= (float)param_4[4]) {

            *(undefined1 *)(param_4 + 0xd) = 0;

            FUN_00516cf0(param_4);

          }

          else {

            *(undefined1 *)(param_4 + 0xd) = 0x10;

            DAT_0059b7c8 = DAT_0059b7c8 | 0x10;

          }

        }

        else {

          *(undefined1 *)(param_4 + 0xd) = 0x20;

          DAT_0059b7c8 = DAT_0059b7c8 | 0x20;

        }

      }

      else {

        *(undefined1 *)(param_4 + 0xd) = 8;

        DAT_0059b7c8 = DAT_0059b7c8 | 8;

      }

    }

    else {

      *(undefined1 *)(param_4 + 0xd) = 4;

      DAT_0059b7c8 = DAT_0059b7c8 | 4;

    }

    iVar4 = iVar4 + 1;

    param_4 = param_4 + 0xe;

  }

  if ((*(byte *)(param_2 + 0x29) & 1) == 0) {

    DAT_0059b7c8 = DAT_0059b7c8 | *(byte *)(param_2 + 0x29);

    iVar4 = iVar4 + 1;

    puVar5 = param_2 + 0x1c;

    puVar6 = param_4;

    for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar6 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar6 = puVar6 + 1;

    }

    param_4 = param_4 + 0xe;

  }

  if (((*(byte *)(param_2 + 0x29) ^ *(byte *)(param_2 + 0xd)) & 1) == 0) {

    *param_3 = iVar4;

    return;

  }

  fVar1 = (DAT_0057c0c0 - (float)param_2[0x21]) / ((float)param_2[5] - (float)param_2[0x21]);

  param_4[3] = ((float)param_2[3] - (float)param_2[0x1f]) * fVar1 + (float)param_2[0x1f];

  param_4[4] = ((float)param_2[4] - (float)param_2[0x20]) * fVar1 + (float)param_2[0x20];

  param_4[5] = DAT_0057c0c0;

  param_4[0xb] = ((float)param_2[0xb] - (float)param_2[0x27]) * fVar1 + (float)param_2[0x27];

  param_4[0xc] = ((float)param_2[0xc] - (float)param_2[0x28]) * fVar1 + (float)param_2[0x28];

  uVar2 = __ftol();

  *(undefined1 *)(param_4 + 10) = uVar2;

  uVar2 = __ftol();

  *(undefined1 *)((int)param_4 + 0x29) = uVar2;

  uVar2 = __ftol();

  *(undefined1 *)((int)param_4 + 0x2a) = uVar2;

  uVar2 = __ftol();

  *(undefined1 *)((int)param_4 + 0x2b) = uVar2;

  if ((float)param_4[3] < -(float)param_4[5]) {

    *(undefined1 *)(param_4 + 0xd) = 4;

    DAT_0059b7c8 = DAT_0059b7c8 | 4;

    *param_3 = iVar4 + 1;

    return;

  }

  if ((float)param_4[5] < (float)param_4[3]) {

    *(undefined1 *)(param_4 + 0xd) = 8;

    DAT_0059b7c8 = DAT_0059b7c8 | 8;

    *param_3 = iVar4 + 1;

    return;

  }

  if ((float)param_4[5] < (float)param_4[4]) {

    *(undefined1 *)(param_4 + 0xd) = 0x20;

    DAT_0059b7c8 = DAT_0059b7c8 | 0x20;

    *param_3 = iVar4 + 1;

    return;

  }

  if ((float)param_4[4] < -(float)param_4[5]) {

    *(undefined1 *)(param_4 + 0xd) = 0x10;

    DAT_0059b7c8 = DAT_0059b7c8 | 0x10;

    *param_3 = iVar4 + 1;

    return;

  }

  *(undefined1 *)(param_4 + 0xd) = 0;

  FUN_00516cf0(param_4);

  *param_3 = iVar4 + 1;

  return;

}

