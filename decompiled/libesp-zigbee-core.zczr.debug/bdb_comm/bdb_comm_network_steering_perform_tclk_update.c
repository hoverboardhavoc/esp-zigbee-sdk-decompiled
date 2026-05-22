/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_network_steering_perform_tclk_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_comm_network_steering_perform_tclk_update(void)

{
  int iVar1;
  undefined1 local_20 [4];
  zdo_node_desc_req_t req;
  ezb_shortaddr_t tc_short;
  
  aps_secur_get_tc_address();
  iVar1 = nwk_address_short_by_extended((undefined1 *)((int)&req.user_ctx + 2));
  if (iVar1 == 0) {
    req.cb = (ezb_zdo_node_desc_req_callback_t)0x0;
    req._0_4_ = bdb_comm_network_steering_handle_node_desc_req_result;
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

