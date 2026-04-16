/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_handle_asso_rsp_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_asso_rsp_sent(uint8_t iface_id,mac_comm_status_ind_t *ind)

{
  uint error;
  
  if ((ind->addresses).destination.addr_mode != '\x03') {
    ind = (mac_comm_status_ind_t *)__assert_func(0,0,0,0);
  }
  error = 0;
  if (ind->status != 0) {
    error = ind->status | 0x100;
  }
  nwk_accept_child_done(error,&(ind->addresses).destination.u.extended_addr,'\0');
  return;
}

