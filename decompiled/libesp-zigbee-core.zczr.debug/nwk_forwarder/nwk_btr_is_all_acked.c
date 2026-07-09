/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btr_is_all_acked
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool nwk_btr_is_all_acked(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = nwk_neighbor_table_get_capacity();
  uVar3 = bitmap_find_first_bit(uVar1,uVar2);
  uVar4 = nwk_neighbor_table_get_capacity();
  return uVar4 <= uVar3;
}

