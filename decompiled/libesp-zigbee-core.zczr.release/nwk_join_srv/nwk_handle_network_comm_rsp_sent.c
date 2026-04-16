/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_handle_network_comm_rsp_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_network_comm_rsp_sent(zmsg_t *msg,ezb_err_t error)

{
  short sVar1;
  int iVar2;
  nwk_join_method_t nStack_1d;
  undefined2 uStack_1c;
  nwk_join_method_t join_method;
  nwk_rejoin_rsp_t rsp;
  ezb_extaddr_t extaddr;
  
  zmsg_get_footer(&nStack_1d,1);
  iVar2 = nwk_frame_get_dst_extaddr(msg,&rsp);
  if (iVar2 != 0) {
    __assert_func(0,0,0,0);
  }
  sVar1 = zmsg_get_offset(msg);
  zmsg_read_bytes(msg,sVar1 + 1,3,&uStack_1c);
  if (nStack_1d == '\a') {
    nwk_neighbor_table_get_by_extended(&rsp);
    nwk_child_address_change_confirm(uStack_1c,error);
  }
  else {
    nwk_accept_child_done(error,(ezb_extaddr_t *)&rsp,nStack_1d);
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

