/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_comm_network_steering_handle_node_desc_req_result
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
      *(undefined1 *)(iVar1 + 0xd4c) = 0;
    }
    else {
      iVar1 = core_globals_get();
      *(undefined1 *)(iVar1 + 0xd4c) = 1;
      zdo_initiate_commissioning(0x200);
    }
  }
  else {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xd4c) = 10;
  }
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xd4c) != '\x01') {
    bdb_comm_finish_network_steering_with_leave();
    return;
  }
  return;
}

