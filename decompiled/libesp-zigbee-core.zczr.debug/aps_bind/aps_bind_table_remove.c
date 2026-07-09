/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_bind_table_remove(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = bind_table_find_src();
  iVar2 = bind_table_find_dst(param_1,param_2);
  if (iVar1 == 0) {
    uVar3 = 5;
  }
  else if (iVar2 == 0) {
    uVar3 = 5;
  }
  else {
    iVar1 = bind_table_unbind(iVar1,iVar2);
    if (iVar1 == 0) {
      uVar3 = 5;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}

