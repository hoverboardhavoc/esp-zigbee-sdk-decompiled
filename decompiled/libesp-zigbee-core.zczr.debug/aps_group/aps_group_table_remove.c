/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_group_table_remove(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = group_table_find();
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else {
    iVar1 = group_remove_endpoint(param_1);
    if (iVar1 == 0) {
      uVar2 = 5;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

