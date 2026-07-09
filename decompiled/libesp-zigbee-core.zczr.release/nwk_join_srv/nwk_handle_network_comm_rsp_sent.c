/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_handle_network_comm_rsp_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_network_comm_rsp_sent(int param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  char cStack_1d;
  undefined2 auStack_1c [2];
  undefined1 auStack_18 [12];
  
  zmsg_get_footer(&cStack_1d,1);
  iVar2 = nwk_frame_get_dst_extaddr(param_1,auStack_18);
  if (iVar2 != 0) {
    __assert_func(0,0,0,0);
  }
  sVar1 = zmsg_get_offset(param_1);
  zmsg_read_bytes(param_1,sVar1 + 1,3,auStack_1c);
  if (cStack_1d == '\a') {
    nwk_neighbor_table_get_by_extended(auStack_18);
    nwk_child_address_change_confirm(auStack_1c[0],param_2);
  }
  else {
    nwk_accept_child_done(param_2,auStack_18);
  }
  if (param_1 != 0) {
    zmsg_free(param_1);
  }
  return;
}

