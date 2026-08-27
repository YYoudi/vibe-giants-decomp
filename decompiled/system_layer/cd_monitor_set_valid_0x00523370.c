// GiantsRE system layer - cd_monitor_set_valid
// VA 0x00523370 (ghidra name was cd_monitor_set_valid)
// provenance: runtime anchors in scripts/re_db.json + PS2 symbols


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cd_monitor_set_valid(LPCSTR param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  
  DAT_005dca38 = 6;
  FUN_004a3900();
  _DAT_005dcb5c = 0;
  DAT_005dcb60 = 0;
  iVar7 = 0;
  pcVar6 = param_1;
  do {
    iVar3 = FUN_00546fb1((int)*pcVar6);
    pcVar8 = pcVar6;
    while (iVar3 != 0) {
      pcVar6 = pcVar8 + 1;
      pcVar8 = pcVar8 + 1;
      iVar3 = FUN_00546fb1((int)*pcVar6);
    }
    if (*pcVar8 == '\0') {
      return;
    }
    pcVar6 = pcVar8;
    if (*pcVar8 == '\"') {
      pcVar6 = pcVar8 + 1;
      pcVar8 = pcVar8 + 1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar8;
      while ((cVar2 != '\0' && (cVar2 != '\"'))) {
        pcVar1 = pcVar6 + 1;
        pcVar6 = pcVar6 + 1;
        cVar2 = *pcVar1;
      }
    }
    else {
      do {
        iVar3 = FUN_00546fb1((int)*pcVar6);
        if (iVar3 != 0) break;
        pcVar1 = pcVar6 + 1;
        pcVar6 = pcVar6 + 1;
      } while (*pcVar1 != '\0');
    }
    if (iVar7 == 1) {
      FUN_0053ca00(&DAT_005dca60,pcVar8,(int)pcVar6 - (int)pcVar8,8);
      iVar7 = 0;
    }
    else if (iVar7 == 2) {
      FUN_0053ca00(&DAT_005dca68,pcVar8,(int)pcVar6 - (int)pcVar8,0x50);
      iVar7 = 0;
    }
    else if (iVar7 == 3) {
      FUN_0053ca00(&DAT_005dcab8,pcVar8,(int)pcVar6 - (int)pcVar8,8);
      iVar7 = 0;
    }
    else if (iVar7 == 4) {
      FUN_0053ca00(&DAT_005dcac0,pcVar8,(int)pcVar6 - (int)pcVar8,0x50);
      iVar7 = 0;
    }
    else if (iVar7 == 7) {
      FUN_0053ca00(&DAT_00631674,pcVar8,(int)pcVar6 - (int)pcVar8,0x20);
      iVar7 = 0;
    }
    else if (iVar7 == 8) {
      FUN_0053ca00(&DAT_006315a8,pcVar8,(int)pcVar6 - (int)pcVar8,0x20);
      iVar7 = 0;
    }
    else if (iVar7 == 9) {
      FUN_0053ca00(&DAT_006315c8,pcVar8,(int)pcVar6 - (int)pcVar8,0x10);
      iVar7 = 0;
    }
    else if (iVar7 == 10) {
      FUN_0053ca00(&DAT_00631698,pcVar8,(int)pcVar6 - (int)pcVar8,0x20);
      FUN_0053ca00(&DAT_00631548,pcVar8,(int)pcVar6 - (int)pcVar8,0x20);
      iVar7 = 0;
    }
    else if (iVar7 == 0xb) {
      DAT_0063156c = FUN_00545e3d(pcVar8);
      iVar7 = 0;
    }
    else if (iVar7 == 0xc) {
      DAT_00631570 = FUN_00545e3d(pcVar8);
      iVar7 = 0;
    }
    else if (iVar7 == 5) {
      DAT_00631578 = FUN_00545e3d(pcVar8);
      if ((5 < DAT_00631578) || (DAT_00631578 < 0)) {
        DAT_00631578 = 0;
      }
      iVar7 = 0;
    }
    else if (iVar7 == 6) {
      DAT_00631594 = FUN_00545e3d(pcVar8);
      if ((0x14 < DAT_00631594) || (DAT_00631594 < 2)) {
        DAT_00631594 = 10;
      }
      iVar7 = 0;
    }
    else if (iVar7 == 0xd) {
      FUN_0053ca00(&DAT_0063165c,pcVar8,(int)pcVar6 - (int)pcVar8,8);
      iVar7 = 0;
    }
    else if (iVar7 == 0xe) {
      FUN_00520400(pcVar8,(int)pcVar6 - (int)pcVar8);
      iVar7 = 0;
    }
    else {
      iVar3 = (int)pcVar6 - (int)pcVar8;
      if ((iVar3 == 4) && (iVar4 = FUN_0053c940(pcVar8,&DAT_0057fd94), iVar4 != 0)) {
        iVar7 = 1;
      }
      else if ((iVar3 == 8) && (iVar4 = FUN_0053c940(pcVar8,s__GFXPath_0057fd88), iVar4 != 0)) {
        iVar7 = 2;
      }
      else if ((iVar3 == 4) && (iVar4 = FUN_0053c940(pcVar8,&DAT_0057fd80), iVar4 != 0)) {
        iVar7 = 3;
      }
      else if ((iVar3 == 8) && (iVar4 = FUN_0053c940(pcVar8,s__SNDPath_0057fd74), iVar4 != 0)) {
        iVar7 = 4;
      }
      else if (iVar3 == 7) {
        iVar4 = FUN_0053c940(pcVar8,s__debwin_0057fd6c);
        if (iVar4 == 0) {
          iVar4 = FUN_0053c940(pcVar8,s__deberr_0057fd64);
          if (iVar4 == 0) goto LAB_00522f35;
          DAT_005dcb60 = 1;
        }
        else {
          _DAT_005dcb5c = 1;
        }
      }
      else {
LAB_00522f35:
        if ((iVar3 == 9) && (iVar4 = FUN_0053c940(pcVar8,s__noswitch_0057fd58), iVar4 != 0)) {
          DAT_005dcb64 = 1;
        }
        else if ((iVar3 == 6) && (iVar4 = FUN_0053c940(pcVar8,s__lobby_0057fd50), iVar4 != 0)) {
          DAT_006317c4 = 1;
        }
        else if ((iVar3 == 5) && (iVar4 = FUN_0053c940(pcVar8,s__name_0057fd48), iVar4 != 0)) {
          iVar7 = 7;
          DAT_006317a0 = 1;
        }
        else if ((iVar3 == 9) && (iVar4 = FUN_0053c940(pcVar8,s__gametype_0057fd3c), iVar4 != 0)) {
          iVar7 = 5;
          DAT_006317bc = 1;
        }
        else if ((iVar3 == 0xb) && (iVar4 = FUN_0053c940(pcVar8,s__maxplayers_0057fd30), iVar4 != 0)
                ) {
          iVar7 = 6;
          DAT_006317b8 = 1;
        }
        else if (iVar3 == 5) {
          iVar4 = FUN_0053c940(pcVar8,s__host_0057fd28);
          if (iVar4 == 0) {
            iVar4 = FUN_0053c940(pcVar8,s__join_0057fd0c);
            if (iVar4 == 0) goto LAB_00523096;
            if (DAT_00631720 != 0) {
              MessageBoxA((HWND)0x0,param_1,s_Giants_Command_line_0057fd14,0);
            }
            iVar7 = 9;
            DAT_006317ac = 1;
          }
          else {
            if (DAT_00631720 != 0) {
              MessageBoxA((HWND)0x0,param_1,s_Giants_Command_line_0057fd14,0);
            }
            iVar7 = 8;
            DAT_006317a8 = 1;
          }
        }
        else {
LAB_00523096:
          if ((iVar3 == 6) && (iVar4 = FUN_0053c940(pcVar8,s__world_0057fd04), iVar4 != 0)) {
            iVar7 = 10;
            DAT_006317a4 = 1;
          }
          else if ((iVar3 == 10) && (iVar4 = FUN_0053c940(pcVar8,s__baselevel_0057fcf8), iVar4 != 0)
                  ) {
            iVar7 = 0xb;
            DAT_006317b0 = 1;
          }
          else if (iVar3 == 9) {
            iVar4 = FUN_0053c940(pcVar8,s__gameteam_0057fcec);
            if (iVar4 == 0) {
              iVar4 = FUN_0053c940(pcVar8,s__location_0057fce0);
              if (iVar4 == 0) goto LAB_00523142;
              iVar7 = 0xd;
              DAT_006317c8 = 1;
            }
            else {
              iVar7 = 0xc;
              DAT_006317b4 = 1;
            }
          }
          else {
LAB_00523142:
            if ((iVar3 == 0xe) &&
               (iVar4 = FUN_0053c940(pcVar8,s__highbandwidth_0057fcd0), iVar4 != 0)) {
              DAT_00631870 = 1;
            }
            else if ((iVar3 == 10) &&
                    (iVar4 = FUN_0053c940(pcVar8,s__nogamespy_0057fcc4), iVar4 != 0)) {
              DAT_006317cc = 1;
            }
            else if ((iVar3 == 8) && (iVar4 = FUN_0053c940(pcVar8,s__nosnd3d_0057fcb8), iVar4 != 0))
            {
              DAT_005dca38 = DAT_005dca38 & 0xfffffffe;
            }
            else if (iVar3 == 6) {
              iVar4 = FUN_0053c940(pcVar8,s__snd3d_0057fcb0);
              if (iVar4 == 0) {
                iVar4 = FUN_0053c940(pcVar8,s__noeax_0057fca8);
                if (iVar4 == 0) goto LAB_00523206;
                DAT_005dca38 = DAT_005dca38 & 0xfffffffd;
              }
              else {
                DAT_005dca38 = DAT_005dca38 | 1;
              }
            }
            else {
LAB_00523206:
              if ((iVar3 == 9) && (iVar4 = FUN_0053c940(pcVar8,s__noeaxman_0057fc9c), iVar4 != 0)) {
                DAT_005dca38 = DAT_005dca38 & 0xfffffffb;
              }
              else if ((iVar3 == 8) &&
                      (iVar4 = FUN_0053c940(pcVar8,s__noaudio_0057fc90), iVar4 != 0)) {
                DAT_0063185c = 1;
              }
              else if ((iVar3 == 9) &&
                      (iVar4 = FUN_0053c940(pcVar8,s__nostream_0057fc84), iVar4 != 0)) {
                DAT_00631864 = 1;
              }
              else if (iVar3 == 7) {
                iVar4 = FUN_0053c940(pcVar8,s__noplay_0057fc7c);
                if (iVar4 == 0) {
                  iVar4 = FUN_0053c940(pcVar8,s__noload_0057fc74);
                  if (iVar4 == 0) goto LAB_005232c6;
                  DAT_00631868 = 1;
                }
                else {
                  DAT_00631860 = 1;
                }
              }
              else {
LAB_005232c6:
                if (iVar3 == 9) {
                  iVar4 = FUN_0053c940(pcVar8,s__amd3dnow_0057fc68);
                  if (iVar4 == 0) {
                    iVar4 = FUN_0053c940(pcVar8,s__intelsse_0057fc5c);
                    if (iVar4 == 0) {
                      iVar4 = FUN_0053c940(pcVar8,s__nocpuext_0057fc50);
                      if (iVar4 == 0) goto LAB_00523338;
                      DAT_00631874 = 1;
                    }
                    else {
                      DAT_0063187c = 1;
                    }
                  }
                  else {
                    DAT_00631878 = 1;
                  }
                }
                else {
LAB_00523338:
                  if ((iVar3 == 5) && (iVar4 = FUN_0053c940(pcVar8,s__font_0057fc48), iVar4 != 0)) {
                    iVar7 = 0xe;
                  }
                  else if ((iVar3 == 9) &&
                          (iVar4 = FUN_0053c940(pcVar8,s__safemode_0057fc3c), iVar4 != 0)) {
                    DAT_005dca38 = DAT_005dca38 & 0xfffffff8;
                    DAT_00631880 = 1;
                    DAT_0063185c = 1;
                    DAT_00631864 = 1;
                    DAT_00631860 = 1;
                    DAT_00631868 = 1;
                  }
                  else if (iVar3 == 10) {
                    iVar4 = FUN_0053c940(pcVar8,s__5footclip_0057fc30);
                    if (iVar4 == 0) {
                      iVar4 = FUN_0053c940(pcVar8,s__nocdcheck_0057fc24);
                      if (iVar4 == 0) goto LAB_005233eb;
                      DAT_00631890 = 1;
                    }
                    else {
                      DAT_00631884 = 1;
                    }
                  }
                  else {
LAB_005233eb:
                    if ((iVar3 == 8) &&
                       (iVar3 = FUN_0053c940(pcVar8,s__cdcheck_0057fc18), iVar3 != 0)) {
                      DAT_00631890 = 0;
                    }
                    else {
                      iVar3 = FUN_0053c940(pcVar8,s__lang_0057fc10);
                      if (iVar3 == 0) {
                        cVar2 = *pcVar6;
                        *pcVar6 = '\0';
                        FUN_004a39c0(pcVar8);
                        *pcVar6 = cVar2;
                      }
                      else {
                        uVar5 = FUN_00546d95(pcVar8 + 5,0,0x10);
                        FUN_0053ae40(uVar5);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if (*pcVar6 == '\"') {
      pcVar6 = pcVar6 + 1;
    }
  } while( true );
}


