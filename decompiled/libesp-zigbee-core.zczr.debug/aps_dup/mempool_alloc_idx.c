/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_dup.o -> mempool_alloc_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint mempool_alloc_idx(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  do {
    uVar1 = bitmap_find_first_zero_bit(param_1,param_2);
    if (param_2 <= uVar1) {
      return uVar1;
    }
    iVar2 = test_and_set_bitmap(uVar1,param_1);
  } while (iVar2 != 0);
  return uVar1;
}

