/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> datasets.o -> ds_internal_save_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ds_internal_save_entry(undefined4 param_1,void *param_2,void *param_3,size_t param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ushort auStack_22 [7];
  
  auStack_22[0] = (ushort)param_4;
  iVar1 = ezb_plat_datasets_get(0,auStack_22);
  if (((iVar1 == 0) && (auStack_22[0] == param_4)) &&
     (iVar1 = memcmp(param_2,param_3,param_4), iVar1 == 0)) {
    uVar3 = 2;
    uVar2 = 0;
  }
  else {
    uVar2 = ezb_plat_datasets_set(param_1,param_2,param_4);
    uVar3 = 1;
  }
  ds_log(uVar3,uVar2,param_1,param_2);
  return uVar2;
}

