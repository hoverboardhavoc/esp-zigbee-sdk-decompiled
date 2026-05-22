/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_assign_random_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t touchlink_assign_random_channel(void)

{
  uint8_t uVar1;
  int iVar2;
  _Bool _Var3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint8_t local_30 [4];
  uint8_t primary_channels [4];
  uint8_t secondary_channels [12];
  
  builtin_memcpy(local_30,"\v\x0f\x14\x19",4);
  iVar2 = 0;
  do {
    uVar1 = primary_channels[iVar2 + -4];
    _Var3 = touchlink_channel_is_valid(uVar1);
    if (CONCAT31(extraout_var,_Var3) != 0) {
      return uVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 4);
  memcpy(primary_channels,&_LC1,0xc);
  iVar2 = 0;
  do {
    uVar1 = primary_channels[iVar2];
    _Var3 = touchlink_channel_is_valid(uVar1);
    if (CONCAT31(extraout_var_00,_Var3) != 0) {
      return uVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0xc);
  return '\v';
}

