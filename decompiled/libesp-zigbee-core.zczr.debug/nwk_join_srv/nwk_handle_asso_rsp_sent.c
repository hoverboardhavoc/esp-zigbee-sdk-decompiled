/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_handle_asso_rsp_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_asso_rsp_sent(uint8_t iface_id,mac_comm_status_ind_t *ind)

{
  uint error;
  ezb_addr_t *joiner_extaddr;
  
  if ((ind->addresses).destination.addr_mode == '\x03') {
    joiner_extaddr = &(ind->addresses).destination.u;
    if (ind->status != 0) {
      error = ind->status | 0x100;
      goto _L0;
    }
  }
  else {
    joiner_extaddr =
         (ezb_addr_t *)
         __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",0x1a5,
                       "nwk_handle_asso_rsp_sent",
                       "ind->addresses.destination.addr_mode == EZB_ADDR_MODE_EXT");
  }
  error = 0;
_L0:
  nwk_accept_child_done(error,&joiner_extaddr->extended_addr,'\0');
  return;
}

