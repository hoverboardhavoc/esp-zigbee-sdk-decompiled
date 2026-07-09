/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_get_extaddr.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_get_extaddr_part_0(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 extraout_a1;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar2 = __assert_func(0,0,0);
  uVar1 = nwk_calculate_lqa_raw(extraout_a1,uVar3);
  memmove((void *)(iVar2 + 3),(void *)(iVar2 + 2),2);
  *(undefined1 *)(iVar2 + 2) = uVar1;
  *(char *)(iVar2 + 5) = (char)uVar3;
  return;
}

