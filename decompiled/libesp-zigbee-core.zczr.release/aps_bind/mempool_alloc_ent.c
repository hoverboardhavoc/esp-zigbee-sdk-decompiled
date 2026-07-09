/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> mempool_alloc_ent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mempool_alloc_ent(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  do {
    uVar2 = bitmap_find_first_zero_bit(param_2,param_4);
    if (param_4 <= uVar2) {
      return 0;
    }
    uVar1 = 1 << (uVar2 & 7) & 0xff;
    uVar3 = __atomic_fetch_or_1((uVar2 >> 3) + param_2,uVar1,5);
  } while ((uVar1 & uVar3) != 0);
  return param_1 + param_3 * uVar2;
}

