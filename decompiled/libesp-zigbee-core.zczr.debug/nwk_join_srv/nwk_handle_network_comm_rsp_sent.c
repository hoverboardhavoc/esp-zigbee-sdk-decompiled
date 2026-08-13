/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_handle_network_comm_rsp_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_network_comm_rsp_sent(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  undefined2 uStack_1c;
  char cStack_19;
  undefined1 auStack_18 [8];
  
  zmsg_get_footer(&cStack_19,1);
  iVar2 = nwk_frame_get_dst_extaddr(param_1,auStack_18);
  if (iVar2 == 0) {
    sVar1 = zmsg_get_offset(param_1);
    zmsg_read_bytes(param_1,sVar1 + 1,3,&uStack_1c);
    if (cStack_19 != '\a') {
      nwk_accept_child_done(param_2,auStack_18);
      goto _L0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",0x196,
                  "nwk_handle_network_comm_rsp_sent",
                  "(nwk_frame_get_dst_extaddr(msg, &extaddr)) == 0");
  }
  iVar2 = nwk_neighbor_table_get_by_extended(auStack_18);
  nwk_child_address_change_confirm(uStack_1c,param_2);
  if ((param_2 == 0) && (iVar2 != 0)) {
    nwk_join_indication_with_method(iVar2,2);
  }
_L0:
  if (param_1 != 0) {
    zmsg_free(param_1);
  }
  return;
}

