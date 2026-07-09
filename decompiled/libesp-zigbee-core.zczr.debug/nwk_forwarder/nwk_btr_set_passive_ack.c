/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btr_set_passive_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_btr_set_passive_ack(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = nwk_neighbor_table_get_by_short(param_2);
  if (iVar1 != 0) {
    nwk_neighbor_table_get_nbr_idx();
    test_and_clr_bitmap(*(undefined4 *)(param_1 + 4));
  }
  return;
}

