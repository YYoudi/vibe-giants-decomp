/* Giants 1.449 — module win95/text
 * 2 functions (0 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\win95/text.c(pp) (assert-string evidence)
 */

/* ===== FUN_0051adb0 @ 0x0051ADB0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0051adb0(int param_1)



{

  char cVar1;

  char *pcVar2;

  undefined4 uVar3;

  int iVar4;

  undefined1 *puVar5;

  undefined4 *puVar6;

  BITMAPINFO *pBVar7;

  LOGFONTA *pLVar8;

  BITMAPINFO local_6c;

  undefined1 local_40;

  undefined1 local_3f;

  undefined1 local_3e;

  LOGFONTA local_3c;

  

  if (DAT_005dd910 == 0) {

    puVar6 = &DAT_005dd378;

    for (iVar4 = 0x152; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar6 = 0;

      puVar6 = puVar6 + 1;

    }

    DAT_005dd39c = (undefined4 *)

                   FUN_0053a700(0x1c,0x10000,s_textext_0057d77c,

                                s_C__Giants_source_win95_text_c_0057d784,0x86);

    puVar6 = DAT_005dd39c;

    for (iVar4 = 0x4000; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar6 = 0;

      puVar6 = puVar6 + 1;

    }

    DAT_005dd8c8 = CreateCompatibleDC((HDC)0x0);

    pBVar7 = &local_6c;

    for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {

      (pBVar7->bmiHeader).biSize = 0;

      pBVar7 = (BITMAPINFO *)&(pBVar7->bmiHeader).biWidth;

    }

    local_40 = 0xff;

    local_3f = 0xff;

    local_3e = 0xff;

    local_6c.bmiHeader.biSize = 0x28;

    local_6c.bmiHeader.biWidth = 0x80;

    local_6c.bmiHeader.biHeight = -0x40;

    local_6c.bmiHeader.biPlanes = 1;

    local_6c.bmiHeader.biBitCount = 1;

    local_6c.bmiHeader.biCompression = 0;

    DAT_005dd8cc = CreateDIBSection(DAT_005dd8c8,&local_6c,0,(void **)&DAT_005dd8c0,(HANDLE)0x0,0);

    SelectObject(DAT_005dd8c8,DAT_005dd8cc);

    SetBkMode(DAT_005dd8c8,1);

    SetTextColor(DAT_005dd8c8,0xffffff);

    SetTextAlign(DAT_005dd8c8,0x18);

    _DAT_005dd8c4 = (float)param_1;

    pLVar8 = &local_3c;

    for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {

      pLVar8->lfHeight = 0;

      pLVar8 = (LOGFONTA *)&pLVar8->lfWidth;

    }

    local_3c.lfHeight = param_1;

    local_3c.lfWidth = 0;

    local_3c.lfEscapement = 0;

    local_3c.lfOrientation = 0;

    local_3c.lfWeight = 400;

    local_3c.lfItalic = '\0';

    local_3c.lfUnderline = '\0';

    local_3c.lfStrikeOut = '\0';

    local_3c.lfCharSet = (DAT_00633148 == 0) - 1U & 0x80;

    local_3c.lfOutPrecision = '\0';

    local_3c.lfClipPrecision = '\0';

    local_3c.lfQuality = '\x02';

    local_3c.lfPitchAndFamily = '\"';

    iVar4 = 0;

    do {

      cVar1 = (&DAT_005dd8d0)[iVar4];

      local_3c.lfFaceName[iVar4] = cVar1;

      iVar4 = iVar4 + 1;

    } while (cVar1 != '\0');

    DAT_005dd370 = CreateFontIndirectA(&local_3c);

    SelectObject(DAT_005dd8c8,DAT_005dd370);

    _DAT_005dd3a4 = DAT_005dd39c;

    DAT_005dd910 = 1;

    _DAT_005dd3a0 = s_AFont_0057d774;

    _DAT_005dd3ac = 8;

    _DAT_005dd3b0 = 7;

    _DAT_005dd3b4 = 3;

    _DAT_005dd3b8 = 3;

    DAT_005dd3bc = 0x40;

    DAT_005dd3bd = 0;

    _DAT_005dd3be = 0;

    FUN_0051adb0(0x18);

    puVar5 = &DAT_005562b8;

    cVar1 = DAT_005562b8;

    while (cVar1 != '\0') {

      FUN_0051b1c0(cVar1);

      pcVar2 = puVar5 + 1;

      puVar5 = puVar5 + 1;

      cVar1 = *pcVar2;

    }

    pcVar2 = (char *)FUN_00507c10(s_TextColor1_0057d768);

    if (*pcVar2 != '?') {

      uVar3 = FUN_00507c10(s_TextColor1_0057d768);

      _DAT_0057d6e4 = FUN_00536050(uVar3);

    }

    pcVar2 = (char *)FUN_00507c10(s_TextColor2_0057d75c);

    if (*pcVar2 != '?') {

      uVar3 = FUN_00507c10(s_TextColor2_0057d75c);

      _DAT_0057d6e8 = FUN_00536050(uVar3);

    }

    pcVar2 = (char *)FUN_00507c10(s_TextColor3_0057d750);

    if (*pcVar2 != '?') {

      uVar3 = FUN_00507c10(s_TextColor3_0057d750);

      _DAT_0057d6ec = FUN_00536050(uVar3);

    }

    pcVar2 = (char *)FUN_00507c10(s_TextColor4_0057d744);

    if (*pcVar2 != '?') {

      uVar3 = FUN_00507c10(s_TextColor4_0057d744);

      _DAT_0057d6f0 = FUN_00536050(uVar3);

    }

    pcVar2 = (char *)FUN_00507c10(s_TextColor5_0057d738);

    if (*pcVar2 != '?') {

      uVar3 = FUN_00507c10(s_TextColor5_0057d738);

      _DAT_0057d6f4 = FUN_00536050(uVar3);

    }

    pcVar2 = (char *)FUN_00507c10(s_TextColor6_0057d72c);

    if (*pcVar2 != '?') {

      uVar3 = FUN_00507c10(s_TextColor6_0057d72c);

      _DAT_0057d6f8 = FUN_00536050(uVar3);

    }

    pcVar2 = (char *)FUN_00507c10(s_TextColor7_0057d720);

    if (*pcVar2 != '?') {

      uVar3 = FUN_00507c10(s_TextColor7_0057d720);

      _DAT_0057d6fc = FUN_00536050(uVar3);

    }

    pcVar2 = (char *)FUN_00507c10(s_TextColor8_0057d714);

    if (*pcVar2 != '?') {

      uVar3 = FUN_00507c10(s_TextColor8_0057d714);

      _DAT_0057d700 = FUN_00536050(uVar3);

    }

    pcVar2 = (char *)FUN_00507c10(s_TextColor9_0057d708);

    if (*pcVar2 != '?') {

      uVar3 = FUN_00507c10(s_TextColor9_0057d708);

      _DAT_0057d704 = FUN_00536050(uVar3);

    }

  }

  return;

}

/* ===== FUN_0051b160 @ 0x0051B160 ===== */
void FUN_0051b160(void)



{

  if (DAT_005dd910 != 0) {

    GdiFlush();

    DeleteObject(DAT_005dd370);

    DeleteObject(DAT_005dd8cc);

    DeleteDC(DAT_005dd8c8);

    mem_free_tagged(DAT_005dd39c,s_C__Giants_source_win95_text_c_0057d784,0x104);

    DAT_005dd910 = 0;

  }

  return;

}

