/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btr_setup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_btr_setup(undefined2 *param_1,undefined2 param_2,undefined1 param_3)

{
  void *__s;
  int iVar1;
  int iVar2;
  
  *param_1 = param_2;
  *(undefined1 *)(param_1 + 1) = param_3;
  *(undefined1 *)((int)param_1 + 3) = 9;
  time_ticker_register_receiver(0);
  __s = *(void **)(param_1 + 2);
  iVar1 = nwk_neighbor_table_get_capacity();
  memset(__s,0,iVar1 + 7U >> 3);
  iVar1 = 0;
  while (iVar1 = nwk_router_table_next(iVar1), iVar1 != 0) {
    iVar2 = nwk_neighbor_get_incoming_cost(iVar1);
    if ((iVar2 != 0) && (iVar2 = nwk_neighbor_get_outgoing_cost(iVar1), iVar2 != 0)) {
      nwk_neighbor_table_get_nbr_idx(iVar1);
      test_and_set_bitmap(*(undefined4 *)(param_1 + 2));
    }
  }
  return;
}

