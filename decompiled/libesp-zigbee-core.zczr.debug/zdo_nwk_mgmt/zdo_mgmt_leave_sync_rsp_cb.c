/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_mgmt_leave_sync_rsp_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_mgmt_leave_sync_rsp_cb(uint8_t status,void *user_ctx)

{
  uint8_t auStack_11 [9];
  
  if (user_ctx != (void *)0x0) {
    auStack_11[0] = status;
    zmsg_write_bytes(*(undefined4 *)((int)user_ctx + 0x14),0,1,auStack_11);
    zdo_packet_send(user_ctx);
    mm_free(user_ctx);
  }
  return;
}

