// gg_dx7r.dll - gg_enum_wrapper @ 0x10001050

int __cdecl FUN_10001050(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DAT_10028448 = param_3;
  DAT_10028454 = param_2;
  DirectDrawEnumerateExA(FUN_100010a0,0,param_1);
  if (DAT_1002844c == 0) {
    return -0x7efffffe;
  }
  return (-(uint)(DAT_10028450 != 0) & 0x7efffffd) + 0x81000003;
}

