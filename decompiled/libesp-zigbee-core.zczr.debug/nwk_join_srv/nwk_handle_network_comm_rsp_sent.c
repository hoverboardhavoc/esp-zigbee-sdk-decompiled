/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_handle_network_comm_rsp_sent
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
  undefined2 uStack_1c;
  nwk_join_method_t nStack_19;
  nwk_rejoin_rsp_t rsp;
  nwk_join_method_t join_method;
  ezb_extaddr_t extaddr;
  
  zmsg_get_footer(&nStack_19,1);
  iVar2 = nwk_frame_get_dst_extaddr(msg,&rsp);
  if (iVar2 == 0) {
    sVar1 = zmsg_get_offset(msg);
    zmsg_read_bytes(msg,sVar1 + 1,3,&uStack_1c);
    if (nStack_19 != '\a') {
      nwk_accept_child_done(error,(ezb_extaddr_t *)&rsp,nStack_19);
      goto _L0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",399,
                  "nwk_handle_network_comm_rsp_sent",
                  "(nwk_frame_get_dst_extaddr(msg, &extaddr)) == 0");
  }
  nwk_neighbor_table_get_by_extended(&rsp);
  nwk_child_address_change_confirm(uStack_1c,error);
_L0:
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

