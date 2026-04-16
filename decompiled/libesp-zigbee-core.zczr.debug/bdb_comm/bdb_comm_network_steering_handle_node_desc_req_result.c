/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_network_steering_handle_node_desc_req_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bdb_comm_network_steering_handle_node_desc_req_result
               (ezb_zdo_node_desc_req_result_t *result,void *unused)

{
  int iVar1;
  
  if ((result->error == 0) && (result->rsp->status == '\0')) {
    if ((result->rsp->node_desc).server_mask >> 9 < 0x15) {
      iVar1 = core_globals_get();
      *(undefined1 *)(iVar1 + 0xda0) = 0;
    }
    else {
      iVar1 = core_globals_get();
      *(undefined1 *)(iVar1 + 0xda0) = 1;
      zdo_initiate_commissioning(0x200);
    }
  }
  else {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xda0) = 10;
  }
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xda0) != '\x01') {
    bdb_comm_finish_network_steering_with_leave();
  }
  return;
}

