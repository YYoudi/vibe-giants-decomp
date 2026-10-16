
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* PS2 candidate: sound_play_obj (conf 0.423) */

int sound_play_obj(OBJECT *obj)

{
  int iVar1;
  int *piVar2;
  
  if ((((DAT_00633200 == 0) && (DAT_00632dbc != 0)) &&
      (piVar2 = (int *)((int)obj * 0x2c + DAT_00632dbc), piVar2 != (int *)0x0)) &&
     ((*piVar2 != 0 && (piVar2[2] != 0)))) {
    iVar1 = (*DAT_005dd2ac)(piVar2);
    if (iVar1 == 0) {
      crt_sprintf(&DAT_00657400,s_SoundFail__s_0055c9b8,*piVar2);
      savegame_slot_load(&DAT_00657400);
    }
    return iVar1;
  }
  return 0;
}

