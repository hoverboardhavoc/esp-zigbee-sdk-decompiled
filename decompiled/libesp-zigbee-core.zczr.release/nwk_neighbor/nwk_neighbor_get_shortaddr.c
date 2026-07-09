/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_get_shortaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 nwk_neighbor_get_shortaddr(undefined2 *param_1)

{
  int iVar1;
  undefined2 auStack_12 [7];
  
  iVar1 = nwk_address_short_by_ref(*param_1,auStack_12);
  if (iVar1 != 0) {
    nwk_neighbor_get_extaddr_part_0();
  }
  return auStack_12[0];
}

