/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_mgmt_leave_sync_rsp_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_mgmt_leave_sync_rsp_cb(undefined1 param_1,int param_2)

{
  undefined1 auStack_11 [9];
  
  if (param_2 != 0) {
    auStack_11[0] = param_1;
    zmsg_write_bytes(*(undefined4 *)(param_2 + 0x14),0,1,auStack_11);
    zdo_packet_send(param_2);
    mm_free(param_2);
  }
  return;
}

