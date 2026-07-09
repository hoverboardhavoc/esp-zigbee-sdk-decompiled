/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> nwk_disc_table_get_by_extended
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_disc_table_get_by_extended(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = core_globals_get();
  uStack_18 = *param_2;
  uStack_14 = param_2[1];
  disc_table_find(iVar1 + 0xb2c,param_1,0,&uStack_18);
  return;
}

