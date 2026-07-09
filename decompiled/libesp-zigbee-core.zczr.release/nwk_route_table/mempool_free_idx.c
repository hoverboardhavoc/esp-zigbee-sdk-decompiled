/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> mempool_free_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mempool_free_idx(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 < param_2) goto _L0;
  do {
    param_1 = mempool_free_ent_part_0();
_L0:
    uVar1 = 1 << (param_3 & 7) & 0xff;
    uVar2 = param_3 >> 3;
    param_3 = 5;
    uVar2 = __atomic_fetch_and_1(param_1 + uVar2,~uVar1 & 0xff);
  } while ((uVar1 & uVar2) == 0);
  return;
}

