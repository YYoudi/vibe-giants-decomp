/* Giants 1.449 — module main/drawwrld
 * 5 functions (5 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/drawwrld.c(pp) (assert-string evidence)
 */

/* ===== main_drawwrld_004329b0 @ 0x004329B0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void main_drawwrld_004329b0(void)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  undefined4 *puVar5;

  int iVar6;

  

  iVar4 = DAT_006331ac;

  iVar2 = DAT_006330e4;

  DAT_00656d00 = *(undefined4 *)(DAT_006330e4 + 0x1e4);

  _DAT_00657044 = *(undefined4 *)(DAT_006330e4 + 0x1ec);

  _DAT_00657048 = -*(float *)(DAT_006330e4 + 0x1ec);

  _DAT_00657054 = *(undefined4 *)(DAT_006330e4 + 500);

  _DAT_00657058 = -*(float *)(DAT_006330e4 + 500);

  _DAT_00656d04 = *(undefined4 *)(DAT_006330e4 + 0x1ec);

  _DAT_00656d14 = *(undefined4 *)(DAT_006330e4 + 500);

  DAT_00656c00 = *(undefined4 *)(DAT_006330e4 + 0x4f24);

  _DAT_00656c04 = *(undefined4 *)(DAT_006330e4 + 0x4f2c);

  _DAT_00656c08 = -*(float *)(DAT_006330e4 + 0x4f2c);

  _DAT_00656c14 = *(undefined4 *)(DAT_006330e4 + 0x4f34);

  _DAT_00656c18 = -*(float *)(DAT_006330e4 + 0x4f34);

  _DAT_00656c84 = *(undefined4 *)(DAT_006330e4 + 0x4f2c);

  _DAT_00656c94 = *(undefined4 *)(DAT_006330e4 + 0x4f34);

  DAT_006564a0 = *(undefined4 *)(DAT_006330e4 + 0x4ef4);

  _DAT_006564a4 = *(undefined4 *)(DAT_006330e4 + 0x4efc);

  _DAT_006564a8 = -*(float *)(DAT_006330e4 + 0x4efc);

  _DAT_006564b4 = *(undefined4 *)(DAT_006330e4 + 0x4f04);

  _DAT_006564b8 = -*(float *)(DAT_006330e4 + 0x4f04);

  _DAT_006564e4 = *(undefined4 *)(DAT_006330e4 + 0x4efc);

  _DAT_006564f4 = *(undefined4 *)(DAT_006330e4 + 0x4f04);

  DAT_00656640 = *(undefined4 *)(DAT_006330e4 + 0x4f0c);

  _DAT_00656d84 = *(undefined4 *)(DAT_006330e4 + 0x4f14);

  _DAT_00656d88 = -*(float *)(DAT_006330e4 + 0x4f14);

  _DAT_00656d94 = *(undefined4 *)(DAT_006330e4 + 0x4f1c);

  _DAT_00656d98 = -*(float *)(DAT_006330e4 + 0x4f1c);

  _DAT_00656644 = *(undefined4 *)(DAT_006330e4 + 0x4f14);

  _DAT_00656654 = *(undefined4 *)(DAT_006330e4 + 0x4f1c);

  _DAT_006564ac = _DAT_006564a4;

  _DAT_006564b0 = _DAT_006564a8;

  _DAT_006564bc = _DAT_006564b4;

  _DAT_006564c0 = _DAT_006564b8;

  DAT_006564e0 = DAT_006564a0;

  _DAT_006564e8 = _DAT_006564e4;

  _DAT_006564ec = _DAT_006564e4;

  _DAT_006564f0 = _DAT_006564e4;

  _DAT_006564f8 = _DAT_006564f4;

  _DAT_006564fc = _DAT_006564f4;

  _DAT_00656500 = _DAT_006564f4;

  _DAT_00656648 = _DAT_00656644;

  _DAT_0065664c = _DAT_00656644;

  _DAT_00656650 = _DAT_00656644;

  _DAT_00656658 = _DAT_00656654;

  _DAT_0065665c = _DAT_00656654;

  _DAT_00656660 = _DAT_00656654;

  _DAT_00656c0c = _DAT_00656c04;

  _DAT_00656c10 = _DAT_00656c08;

  _DAT_00656c1c = _DAT_00656c14;

  _DAT_00656c20 = _DAT_00656c18;

  DAT_00656c80 = DAT_00656c00;

  _DAT_00656c88 = _DAT_00656c84;

  _DAT_00656c8c = _DAT_00656c84;

  _DAT_00656c90 = _DAT_00656c84;

  _DAT_00656c98 = _DAT_00656c94;

  _DAT_00656c9c = _DAT_00656c94;

  _DAT_00656ca0 = _DAT_00656c94;

  _DAT_00656d08 = _DAT_00656d04;

  _DAT_00656d0c = _DAT_00656d04;

  _DAT_00656d10 = _DAT_00656d04;

  _DAT_00656d18 = _DAT_00656d14;

  _DAT_00656d1c = _DAT_00656d14;

  _DAT_00656d20 = _DAT_00656d14;

  DAT_00656d80 = DAT_00656640;

  _DAT_00656d8c = _DAT_00656d84;

  _DAT_00656d90 = _DAT_00656d88;

  _DAT_00656d9c = _DAT_00656d94;

  _DAT_00656da0 = _DAT_00656d98;

  DAT_00657040 = DAT_00656d00;

  _DAT_0065704c = _DAT_00657044;

  _DAT_00657050 = _DAT_00657048;

  _DAT_0065705c = _DAT_00657054;

  _DAT_00657060 = _DAT_00657058;

  if (((byte)DAT_00632e94 & 8) == 0) {

    puVar5 = &DAT_00657380;

    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = &LAB_004320b0;

      puVar5 = puVar5 + 1;

    }

    puVar5 = &DAT_00656cc0;

    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = &LAB_00431f30;

      puVar5 = puVar5 + 1;

    }

    puVar5 = &DAT_00656d40;

    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = FUN_00432270;

      puVar5 = puVar5 + 1;

    }

    puVar5 = &DAT_006566c0;

    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    puVar5 = &DAT_00657300;

    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = 0x18;

      puVar5 = puVar5 + 1;

    }

    puVar5 = &DAT_006565c0;

    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

  }

  else {

    iVar1 = 0;

    do {

      *(undefined4 *)((int)&DAT_006565c0 + iVar1) = 1;

      if ((iVar4 == 0) && (*(int *)(iVar2 + 0x4ecc + *(int *)((int)&DAT_00556dfc + iVar1) * 4) != 0)

         ) {

        *(undefined4 *)((int)&DAT_00657300 + iVar1) = 0x14;

        *(undefined4 *)((int)&DAT_006566c0 + iVar1) = 4;

        *(undefined1 **)((int)&DAT_00656cc0 + iVar1) = &LAB_00432030;

        *(undefined1 **)((int)&DAT_00657380 + iVar1) = &LAB_004321e0;

      }

      else {

        *(undefined4 *)((int)&DAT_00657300 + iVar1) = 0x10;

        *(undefined4 *)((int)&DAT_006566c0 + iVar1) = 3;

        *(undefined1 **)((int)&DAT_00656cc0 + iVar1) = &LAB_00431fc0;

        *(undefined1 **)((int)&DAT_00657380 + iVar1) = &LAB_00432160;

      }

      *(undefined1 **)((int)&DAT_00656d40 + iVar1) = &LAB_004322d0;

      iVar1 = iVar1 + 4;

    } while (iVar1 < 0x24);

  }

  iVar4 = *(int *)(iVar2 + 0x24) - *(int *)(iVar2 + 0x20);

  iVar2 = *(int *)(iVar2 + 0x2c) - *(int *)(iVar2 + 0x28);

  if (iVar4 < iVar2) {

    iVar4 = iVar2;

  }

  puVar5 = &DAT_006573b0;

  do {

    uVar3 = (**(code **)(DAT_00656420 + 4))(DAT_00656420);

    *puVar5 = uVar3;

    puVar5 = puVar5 + 1;

  } while ((int)puVar5 < 0x6573bc);

  iVar2 = 0;

  do {

    iVar1 = DAT_00656420;

    iVar6 = (*(int *)((int)&DAT_00556dd8 + iVar2) + 1) * (iVar4 + 1);

    *(int *)((int)&DAT_00656c40 + iVar2) = iVar6;

    *(int *)((int)&DAT_006573c0 + iVar2) = (iVar6 - (iVar4 + 1)) * 2 + 2;

    iVar1 = (**(code **)(iVar1 + 0xc))

                      (iVar1,*(undefined4 *)((int)&DAT_006566c0 + iVar2),iVar6 * 2 + 2,0);

    uVar3 = (&DAT_006573b0)[*(int *)((int)&DAT_00556dfc + iVar2)];

    *(int *)((int)&DAT_00656680 + iVar2) = iVar1;

    (**(code **)(iVar1 + 0xc))(iVar1,uVar3);

    uVar3 = MemAllocMsg(9,iVar6 * 0xc,s_HBlandscape_renderer_index_buffe_00556f7e + 2,

                        s_C__Giants_source_main_drawwrld_c_00556fa0,0x436);

    *(undefined4 *)((int)&DAT_00656520 + iVar2) = uVar3;

    iVar2 = iVar2 + 4;

  } while (iVar2 < 0x24);

  (**(code **)(DAT_00656420 + 0x58))

            (DAT_00656420,*(undefined4 *)(DAT_006330e4 + 0x4e8c),

             *(undefined4 *)(DAT_006330e4 + 0x4e90),*(undefined4 *)(DAT_006330e4 + 0x4e94));

  return;

}

/* ===== main_drawwrld_00432e10 @ 0x00432E10 ===== */
void main_drawwrld_00432e10(void)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  

  puVar2 = &DAT_006573b0;

  do {

    (**(code **)*puVar2)((undefined4 *)*puVar2);

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  } while ((int)puVar2 < 0x6573bc);

  iVar3 = 0;

  do {

    (*(code *)**(undefined4 **)((int)&DAT_00656680 + iVar3))

              (*(undefined4 **)((int)&DAT_00656680 + iVar3));

    mem_free_tagged(*(undefined4 *)((int)&DAT_00656520 + iVar3),

                    s_C__Giants_source_main_drawwrld_c_00556fa0,0x448);

    *(undefined4 *)((int)&DAT_00656520 + iVar3) = 0;

    iVar3 = iVar3 + 4;

  } while (iVar3 < 0x24);

  if (DAT_006330e4 != 0) {

    iVar3 = 0x4ed8;

    do {

      iVar1 = *(int *)(iVar3 + 0xc + DAT_006330e4);

      if (iVar1 != 0) {

        main_00508840(iVar1);

        texture_destroy(*(undefined4 *)(iVar3 + 0xc + DAT_006330e4));

      }

      if (*(int *)(iVar3 + DAT_006330e4) != 0) {

        main_00508840(*(int *)(iVar3 + DAT_006330e4));

        texture_destroy(*(undefined4 *)(iVar3 + DAT_006330e4));

      }

      iVar1 = *(int *)(iVar3 + -0xc + DAT_006330e4);

      if (iVar1 != 0) {

        main_00508840(iVar1);

        texture_destroy(*(undefined4 *)(iVar3 + -0xc + DAT_006330e4));

      }

      iVar1 = *(int *)(iVar3 + -0x18 + DAT_006330e4);

      if (iVar1 != 0) {

        main_00508840(iVar1);

        texture_destroy(*(undefined4 *)(iVar3 + -0x18 + DAT_006330e4));

      }

      iVar3 = iVar3 + 4;

    } while (iVar3 < 0x4ee4);

  }

  return;

}

/* ===== main_drawwrld_00434c80 @ 0x00434C80 ===== */
void main_drawwrld_00434c80(int param_1)



{

  undefined4 *puVar1;

  

  if (param_1 != 0) {

    puVar1 = *(undefined4 **)(param_1 + 0x34);

    if (puVar1 != (undefined4 *)0x0) {

      (*(code *)*puVar1)(puVar1);

    }

    puVar1 = *(undefined4 **)(param_1 + 0x30);

    if (puVar1 != (undefined4 *)0x0) {

      (*(code *)*puVar1)(puVar1);

    }

    mem_free_tagged(param_1,s_C__Giants_source_main_drawwrld_c_00556fa0,0xa2d);

  }

  return;

}

/* ===== main_drawwrld_00435170 @ 0x00435170 ===== */
uint * main_drawwrld_00435170(int param_1,uint param_2,uint param_3)



{

  undefined4 *puVar1;

  int iVar2;

  uint *puVar3;

  uint uVar4;

  uint *puVar5;

  

  uVar4 = param_1 * 2 + 2;

  iVar2 = 0;

  if ((~param_3 & 1) != 0) {

    iVar2 = uVar4 * 0x18;

  }

  puVar3 = (uint *)MemAllocMsg(9,iVar2 + 0x80 + (param_1 * 6 + param_2 * 0xc) * 2,

                               s_Shadow_Pool_00556fc8,s_C__Giants_source_main_drawwrld_c_00556fa0,

                               0xb57);

  puVar5 = puVar3;

  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  puVar5 = puVar3 + 0x20;

  *puVar3 = param_3;

  puVar3[6] = (uint)puVar5;

  puVar3[5] = param_2;

  puVar3[2] = (uint)(puVar5 + param_2 * 6);

  puVar3[1] = param_1 * 6;

  puVar3[4] = 0;

  if ((~param_3 & 1) != 0) {

    puVar3[4] = (uint)(puVar5 + param_2 * 6 + param_1 * 3);

  }

  puVar3[3] = uVar4;

  uVar4 = (**(code **)(DAT_00656420 + 0xc))(DAT_00656420,0,uVar4,0);

  puVar3[0xc] = uVar4;

  uVar4 = (**(code **)(DAT_00656420 + 4))(DAT_00656420);

  puVar3[0xd] = uVar4;

  (**(code **)(puVar3[0xc] + 0xc))(puVar3[0xc],uVar4);

  puVar1 = (undefined4 *)puVar3[6];

  puVar3[7] = (uint)puVar1;

  puVar3[8] = (uint)puVar1;

  puVar3[9] = (uint)(puVar1 + puVar3[5] * 6 + -6);

  *(undefined2 *)(puVar1 + 5) = 0;

  *(undefined2 *)(puVar1 + 4) = 0;

  *(undefined2 *)((int)puVar1 + 0x12) = 0;

  *(undefined2 *)((int)puVar1 + 0x16) = 0;

  *puVar1 = 0;

  FUN_0053d9e0(puVar3 + 0xe);

  puVar3[0x1f] = 0;

  drawwrld_cell_cull(puVar3,0,0);

  *(undefined4 *)(puVar3[7] + 4) = 0x33c;

  *(undefined4 *)(puVar3[7] + 8) = 0;

  *(undefined4 *)(puVar3[7] + 0xc) = 0xffffffff;

  return puVar3;

}

/* ===== main_drawwrld_00435e20 @ 0x00435E20 ===== */
void main_drawwrld_00435e20(void)



{

  undefined4 *puVar1;

  int iVar2;

  

  iVar2 = DAT_00656544;

  DAT_006565e4 = 0;

  if (DAT_00656544 != 0) {

    puVar1 = *(undefined4 **)(DAT_00656544 + 0x34);

    if (puVar1 != (undefined4 *)0x0) {

      (*(code *)*puVar1)(puVar1);

    }

    puVar1 = *(undefined4 **)(iVar2 + 0x30);

    if (puVar1 != (undefined4 *)0x0) {

      (*(code *)*puVar1)(puVar1);

    }

    mem_free_tagged(iVar2,s_C__Giants_source_main_drawwrld_c_00556fa0,0xa2d);

  }

  iVar2 = DAT_0065646c;

  DAT_00656544 = 0;

  if (DAT_0065646c != 0) {

    puVar1 = *(undefined4 **)(DAT_0065646c + 0x34);

    if (puVar1 != (undefined4 *)0x0) {

      (*(code *)*puVar1)(puVar1);

    }

    puVar1 = *(undefined4 **)(iVar2 + 0x30);

    if (puVar1 != (undefined4 *)0x0) {

      (*(code *)*puVar1)(puVar1);

    }

    mem_free_tagged(iVar2,s_C__Giants_source_main_drawwrld_c_00556fa0,0xa2d);

  }

  iVar2 = DAT_00656494;

  DAT_0065646c = 0;

  if (DAT_00656494 != 0) {

    puVar1 = *(undefined4 **)(DAT_00656494 + 0x34);

    if (puVar1 != (undefined4 *)0x0) {

      (*(code *)*puVar1)(puVar1);

    }

    puVar1 = *(undefined4 **)(iVar2 + 0x30);

    if (puVar1 != (undefined4 *)0x0) {

      (*(code *)*puVar1)(puVar1);

    }

    mem_free_tagged(iVar2,s_C__Giants_source_main_drawwrld_c_00556fa0,0xa2d);

  }

  iVar2 = DAT_00656498;

  DAT_00656494 = 0;

  if (DAT_00656498 != 0) {

    puVar1 = *(undefined4 **)(DAT_00656498 + 0x34);

    if (puVar1 != (undefined4 *)0x0) {

      (*(code *)*puVar1)(puVar1);

    }

    puVar1 = *(undefined4 **)(iVar2 + 0x30);

    if (puVar1 != (undefined4 *)0x0) {

      (*(code *)*puVar1)(puVar1);

    }

    mem_free_tagged(iVar2,s_C__Giants_source_main_drawwrld_c_00556fa0,0xa2d);

  }

  DAT_00656498 = 0;

  drawwrld_helper_b();

  drawwrld_helper_a();

  drawwrld_helper_c();

  return;

}

