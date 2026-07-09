/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> mempool_free_ent.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mempool_free_ent_part_0(void)

{
  uint uVar1;
  int iVar2;
  uint extraout_a1;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  iVar2 = __assert_func(0,0,0);
  if (uVar3 < extraout_a1) goto _L0;
  do {
    iVar2 = mempool_free_ent_part_0();
_L0:
    uVar1 = 1 << (uVar3 & 7) & 0xff;
    uVar4 = uVar3 >> 3;
    uVar3 = 5;
    uVar4 = __atomic_fetch_and_1(iVar2 + uVar4,~uVar1 & 0xff);
  } while ((uVar1 & uVar4) == 0);
  return;
}

