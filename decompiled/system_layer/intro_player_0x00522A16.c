// containing fn for intros.bin xref 0x522A16 (FUN_005222c0)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005222c0(HINSTANCE param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char *pcVar1;
  ATOM AVar2;
  LANGID LVar3;
  int iVar4;
  HANDLE hHandle;
  DWORD DVar5;
  BOOL BVar6;
  int iVar7;
  undefined1 *puVar8;
  int *piVar9;
  undefined4 *puVar10;
  _STARTUPINFOA *p_Var11;
  int *piVar12;
  bool bVar13;
  undefined4 uVar14;
  undefined4 uStack_39c;
  undefined4 uStack_398;
  HACCEL pHStack_394;
  undefined4 uStack_390;
  HANDLE local_38c;
  tagMSG tStack_388;
  _PROCESS_INFORMATION local_36c;
  WNDCLASSA local_35c;
  _STARTUPINFOA local_31c;
  undefined1 local_2d8 [100];
  undefined1 auStack_274 [100];
  CHAR local_210 [264];
  CHAR local_108 [264];
  
  iVar4 = 0;
  puVar10 = &DAT_005dca50;
  for (iVar7 = 0x41; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  do {
    pcVar1 = &DAT_0057fc08 + iVar4;
    (&DAT_005dca60)[iVar4] = *pcVar1;
    iVar4 = iVar4 + 1;
  } while (*pcVar1 != '\0');
  iVar4 = 0;
  DAT_005dca68 = 0;
  do {
    pcVar1 = &DAT_0057fc04 + iVar4;
    (&DAT_005dcab8)[iVar4] = *pcVar1;
    iVar4 = iVar4 + 1;
  } while (*pcVar1 != '\0');
  DAT_005dcac0 = 0;
  puVar10 = &DAT_00631380;
  for (iVar4 = 0xdb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  cd_monitor_set_valid(param_3);
  hHandle = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,0,s_Giants_CK_0057fbf8);
  local_38c = hHandle;
  if (hHandle == (HANDLE)0x0) {
    MessageBoxA((HWND)0x0,s_Error_Creating_Giants_CK_Mutex___0057fbac,s_Giants_Fatal_Error_0057fbe4,
                0);
    return 0;
  }
  DVar5 = WaitForSingleObject(hHandle,0);
  if (DVar5 == 0x102) {
    MessageBoxA((HWND)0x0,s_Giants_already_running_or_instal_0057fb7c,s_Giants_Fatal_Error_0057fbe4,
                0);
    CloseHandle(hHandle);
    return 0;
  }
  GetCurrentDirectoryA(0x105,local_108);
  lstrcpyA(local_210,local_108);
  lstrcatA(local_210,s__ereg_0057faf0);
  SetCurrentDirectoryA(local_210);
  p_Var11 = &local_31c;
  for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
    p_Var11->cb = 0;
    p_Var11 = (_STARTUPINFOA *)&p_Var11->lpReserved;
  }
  local_31c.cb = 0x44;
  BVar6 = CreateProcessA((LPCSTR)0x0,s_reg32_exe_FALSE_0057fae0,(LPSECURITY_ATTRIBUTES)0x0,
                         (LPSECURITY_ATTRIBUTES)0x0,0,0x20,(LPVOID)0x0,(LPCSTR)0x0,&local_31c,
                         &local_36c);
  if (BVar6 != 0) {
    WaitForSingleObject(local_36c.hProcess,0xffffffff);
    CloseHandle(local_36c.hThread);
    CloseHandle(local_36c.hProcess);
  }
  SetCurrentDirectoryA(local_108);
  if (DAT_005dcb60 == 0) {
    uVar14 = 0;
  }
  else {
    uVar14 = 0xffffffff;
  }
  FUN_0053bc80(uVar14);
  FUN_00541d10(&LAB_00522280);
  FUN_00541d40(&LAB_005222a0);
  FUN_005408f0();
  if ((DAT_00631874 == 0) && (DAT_00631880 == 0)) {
    if (DAT_00631878 == 0) {
      if (DAT_0063187c == 0) {
        uVar14 = 0xffffffff;
      }
      else {
        uVar14 = 2;
      }
    }
    else {
      uVar14 = 1;
    }
  }
  else {
    uVar14 = 0;
  }
  FUN_00542900(uVar14);
  DAT_005dca54 = param_1;
  local_35c.style = 3;
  local_35c.lpfnWndProc = (WNDPROC)&LAB_00523470;
  local_35c.cbClsExtra = 0;
  local_35c.cbWndExtra = 0;
  local_35c.hInstance = param_1;
  local_35c.hIcon = LoadIconA(param_1,s_AppIcon_0057fb74);
  local_35c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_35c.hbrBackground = GetStockObject(4);
  local_35c.lpszMenuName = s_AppMenu_0057fb6c;
  local_35c.lpszClassName = s_Example_0057fb64;
  AVar2 = RegisterClassA(&local_35c);
  if (AVar2 == 0) {
    return 0;
  }
  DAT_005dca50 = CreateWindowExA(0x40000,s_Example_0057fb64,s_Giants_0057fb5c,0x6cf0000,-0x80000000,
                                 -0x80000000,-0x80000000,-0x80000000,(HWND)0x0,(HMENU)0x0,param_1,
                                 (LPVOID)0x0);
  ShowWindow(DAT_005dca50,param_4);
  if (DAT_005dca50 == (HWND)0x0) {
    FUN_00523700(s_CreateWindowEx_failed_0057fb44);
    return 0;
  }
  UpdateWindow(DAT_005dca50);
  if (DAT_005dcb14 != 0) {
    return 0;
  }
  DAT_005dcb2c = FUN_00505d20(DAT_005dca50);
  LVar3 = GetSystemDefaultLangID();
  if ((LVar3 & 0x3ff) == 0x11) {
    return 0x1234;
  }
  FUN_005423f0(FUN_00523700);
  iVar4 = FUN_004f41c0();
  if (iVar4 == 0) {
    DAT_005dcb14 = 1;
    return 0;
  }
  if (DAT_005dcb14 != 0) {
    return 0;
  }
  SetEnvironmentVariableA(s_FX_GLIDE_NO_SPLASH_0057fb30,&DAT_00557204);
  iVar4 = renderer_load_return_site(&DAT_005dca68,&DAT_005dca60);
  if (iVar4 == 0) {
    uVar14 = FUN_0050d7f0(s_ErrFailedGFX_0057fb20);
    FUN_00544b47(local_2d8,uVar14,&DAT_005dca60);
    if (DAT_005dca58 != 0) {
      return 0;
    }
    puVar8 = local_2d8;
LAB_005227a8:
    FUN_00523700(puVar8);
    DAT_005dca58 = 1;
    return 0;
  }
  if (DAT_005dcb14 != 0) {
    return 0;
  }
  if (DAT_00631880 != 0) {
    DAT_00631828 = 0;
    DAT_00631838 = 0;
    DAT_0063182c = 0;
    DAT_0063183c = 0;
    _DAT_00631830 = 0;
    _DAT_00631840 = 0;
    DAT_00631818 = 0x1e0;
    DAT_00631820 = 0x10;
    _DAT_00631834 = 0;
    _DAT_00631844 = 0;
  }
  DAT_00654940 = (undefined4 *)
                 (*DAT_005dc01c)(param_3,DAT_005dca50,DAT_00631818,DAT_0063181c,DAT_00631820,
                                 DAT_00631824,1,&DAT_00631828,&DAT_00631838);
  if (DAT_00654940 == (undefined4 *)0x0) {
    DAT_00631818 = 0x280;
    DAT_0063181c = 0x1e0;
    DAT_00654940 = (undefined4 *)
                   (*DAT_005dc01c)(param_3,DAT_005dca50,0x280,0x1e0,DAT_00631820,DAT_00631824,1,
                                   &DAT_00631828,&DAT_00631838);
    if (DAT_00654940 == (undefined4 *)0x0) goto LAB_00522abf;
  }
  iVar4 = FUN_0051f900(&DAT_005dcac0,&DAT_005dcab8);
  if (iVar4 == 0) {
    uVar14 = FUN_0050d7f0(s_ErrFailedSND_0057fb10);
    FUN_00544b47(auStack_274,uVar14,&DAT_005dcab8);
    if (DAT_005dca58 != 0) {
      return 0;
    }
    puVar8 = auStack_274;
    goto LAB_005227a8;
  }
  if (DAT_005dcb14 != 0) {
    return 0;
  }
  (*DAT_005dc24c)(0x2c,DAT_005dca38);
  (*DAT_005dc2d8)();
  (*(code *)DAT_00654940[0x1b])(DAT_00654940,&DAT_005dcb34,&DAT_005dcb44);
  iVar4 = 4;
  bVar13 = true;
  piVar9 = &DAT_005dcb34;
  piVar12 = &DAT_00631828;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar13 = *piVar9 == *piVar12;
    piVar9 = piVar9 + 1;
    piVar12 = piVar12 + 1;
  } while (bVar13);
  if (bVar13) {
    iVar4 = 4;
    bVar13 = true;
    piVar9 = &DAT_005dcb44;
    piVar12 = &DAT_00631838;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar13 = *piVar9 == *piVar12;
      piVar9 = piVar9 + 1;
      piVar12 = piVar12 + 1;
    } while (bVar13);
    if (!bVar13) goto LAB_005228dc;
    FUN_0051f500();
    FUN_0051f8a0(s_DefPlayer_0055c198,&local_35c,0x40);
    if ((char)local_35c.style == '\0') {
      _DAT_006314f4 = (*(code *)DAT_00654940[0x31])(DAT_00654940,7);
      FUN_00521e90(1);
      FUN_00521c80(1);
      FUN_00521d00(1);
      FUN_00521e20(1);
      FUN_00521ed0(1);
      FUN_00521f00(2);
      FUN_00455620(1);
      FUN_00521d80(2);
      DAT_00631798 = 2;
      FUN_0051bcc0(0);
      FUN_0051f5b0();
    }
    else {
      _DAT_006314f4 = (*(code *)DAT_00654940[0x31])();
      FUN_0051f6c0(&local_35c);
      FUN_00483740();
      FUN_0051f5b0();
    }
  }
  else {
LAB_005228dc:
    FUN_00521f90();
    FUN_00483510();
  }
  FUN_005220b0();
  (*(code *)DAT_00654940[0x1c])(DAT_00654940,&pHStack_394);
  (*(code *)DAT_00654940[0x1e])(DAT_00654940,&uStack_390,&DAT_005dcb34,&DAT_005dcb44);
  (*(code *)DAT_00654940[0x1f])(DAT_00654940,uStack_390);
  (*(code *)DAT_00654940[0x1d])(DAT_00654940,pHStack_394);
  if (DAT_005dcb14 != 0) {
    return 0;
  }
  FUN_00520430(0x18);
  FUN_00455300();
  FUN_004fe450();
  FUN_004290f0(DAT_005dcb60);
  iVar4 = FUN_0051ede0(param_3);
  if (iVar4 != 0) {
    iVar4 = 0;
    do {
      iVar7 = ShowCursor(0);
      if (iVar7 < 0) break;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 10);
    FUN_0051f500();
    FUN_0051f8a0(s_DefPlayer_0055c198,&local_31c,0x40);
    if ((char)local_31c.cb != '\0') {
      FUN_0051f6c0(&local_31c);
      uStack_398 = 0x3f400000;
      uStack_39c = 0x3f400000;
      FUN_0051f7e0(s_MusicVolume_0055def8,&uStack_39c);
      (*DAT_005dc2f8)(uStack_39c);
      uStack_398 = 0x3f400000;
      uStack_39c = 0x3f400000;
      FUN_0051f7e0(s_SoundVolume_0055deec,&uStack_39c);
      (*DAT_005dc298)(uStack_39c);
    }
    FUN_0051f5b0();
    FUN_0042bfe0();
    FUN_00523b60(s_intros_bin_0057fb04);
    FUN_004913c0();
    pHStack_394 = LoadAcceleratorsA(param_1,s_AppAccel_0057faf8);
    timeBeginPeriod(1);
    DAT_005dcb24 = 1;
    PeekMessageA(&tStack_388,(HWND)0x0,0,0,0);
    while (tStack_388.message != 0x12) {
      DAT_0057fa60 = (*(code *)DAT_00654940[0x20])(DAT_00654940,DAT_0057fa60);
      if (DAT_0057fa60 == 3) {
        FUN_00483740();
        FUN_005220b0();
      }
      if (DAT_005dcb28 == 0) {
        iVar4 = GetMessageA(&tStack_388,(HWND)0x0,0,0);
      }
      else {
        iVar4 = PeekMessageA(&tStack_388,(HWND)0x0,0,0,1);
      }
      if (iVar4 == 0) {
        if (((DAT_0057fa60 == 1) && (DAT_005dcb28 != 0)) && (DAT_005dcb24 != 0)) {
          FUN_0051f0e0();
          FUN_0051e7c0();
          FUN_0051f1f0();
          FUN_004742f0();
          if (DAT_005dca58 != 0) {
            SendMessageA(DAT_005dca50,0x10,0,0);
          }
        }
      }
      else {
        iVar4 = TranslateAcceleratorA(DAT_005dca50,pHStack_394,&tStack_388);
        if (iVar4 == 0) {
          TranslateMessage(&tStack_388);
          DispatchMessageA(&tStack_388);
        }
      }
    }
    FUN_0051f360();
    FUN_004f4250();
    if (DAT_005dcb58 != 0) {
      DAT_005dcb58 = 0;
      FUN_004554e0();
      (*(code *)*DAT_00654940)(DAT_00654940);
    }
    FUN_0053bd00();
    FUN_004fe450();
    timeEndPeriod(1);
    CloseHandle(local_38c);
    if (DAT_005dcb30 != 0) {
      return 0x2345;
    }
    return tStack_388.wParam;
  }
LAB_00522abf:
  FUN_0051d900();
  return 0;
}

