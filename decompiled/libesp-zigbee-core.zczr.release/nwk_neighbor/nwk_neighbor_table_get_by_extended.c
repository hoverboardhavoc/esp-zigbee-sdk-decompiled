/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_get_by_extended
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_neighbor_table_get_by_extended(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 auStack_12 [7];
  
  iVar1 = nwk_address_ref_by_extended(auStack_12);
  if (iVar1 == 0) {
    uVar2 = nwk_neighbor_table_get_by_addr_ref(auStack_12[0]);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

