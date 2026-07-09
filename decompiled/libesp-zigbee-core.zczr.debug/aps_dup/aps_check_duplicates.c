/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_dup.o -> aps_check_duplicates
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_check_duplicates(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = aps_dup_need_check();
  if (iVar1 != 0) {
    iVar2 = core_globals_get();
    iVar3 = aps_dup_table_find(iVar2 + 0x984,param_1);
    if (iVar3 == 0) {
      aps_dup_table_add(iVar2 + 0x984,param_1);
      iVar1 = 0;
    }
  }
  return iVar1;
}

