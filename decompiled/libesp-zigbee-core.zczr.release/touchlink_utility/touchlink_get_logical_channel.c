/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_get_logical_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t touchlink_get_logical_channel(void)

{
  uint8_t uVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  undefined3 extraout_var_01;
  uint8_t auStack_30 [28];
  
  iVar3 = touchlink_device_info_get();
  _Var2 = touchlink_channel_is_valid(*(uint8_t *)(iVar3 + 1));
  if (CONCAT31(extraout_var_01,_Var2) != 0) {
    iVar3 = touchlink_device_info_get();
    return *(uint8_t *)(iVar3 + 1);
  }
  builtin_memcpy(auStack_30,"\v\x0f\x14\x19",4);
  iVar3 = 0;
  do {
    uVar1 = auStack_30[iVar3];
    _Var2 = touchlink_channel_is_valid(uVar1);
    if (CONCAT31(extraout_var,_Var2) != 0) {
      return uVar1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 4);
  memcpy(auStack_30 + 4,&_LC1,0xc);
  iVar3 = 0;
  do {
    uVar1 = (auStack_30 + 4)[iVar3];
    _Var2 = touchlink_channel_is_valid(uVar1);
    if (CONCAT31(extraout_var_00,_Var2) != 0) {
      return uVar1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0xc);
  return '\v';
}

