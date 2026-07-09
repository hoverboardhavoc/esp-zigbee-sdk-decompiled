/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_network_steering_perform_tclk_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_network_steering_perform_tclk_update(void)

{
  int iVar1;
  undefined1 local_20 [4];
  code *pcStack_1c;
  undefined4 uStack_18;
  undefined1 auStack_12 [14];
  
  aps_secur_get_tc_address();
  iVar1 = nwk_address_short_by_extended(auStack_12);
  if (iVar1 == 0) {
    uStack_18 = 0;
    pcStack_1c = bdb_comm_network_steering_handle_node_desc_req_result;
    iVar1 = zdo_node_desc_req(local_20);
    if (iVar1 == 0) {
      return;
    }
  }
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd4c) = 10;
  bdb_comm_finish_network_steering_with_leave();
  return;
}

