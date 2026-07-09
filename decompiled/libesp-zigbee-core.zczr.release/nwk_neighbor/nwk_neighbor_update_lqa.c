/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_update_lqa
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_update_lqa(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  
  uVar1 = nwk_calculate_lqa_raw(param_2,param_3);
  memmove((void *)(param_1 + 3),(void *)(param_1 + 2),2);
  *(undefined1 *)(param_1 + 2) = uVar1;
  *(char *)(param_1 + 5) = (char)param_3;
  return;
}

