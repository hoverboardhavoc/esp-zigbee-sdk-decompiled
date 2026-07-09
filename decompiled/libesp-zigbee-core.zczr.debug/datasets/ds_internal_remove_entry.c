/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> datasets.o -> ds_internal_remove_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ds_internal_remove_entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = ezb_plat_datasets_delete();
  if (param_2 == -1) {
    uVar2 = 6;
  }
  else {
    uVar2 = 5;
  }
  ds_log(uVar2,uVar1,param_1,param_3);
  return uVar1;
}

