/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cluster_srv_fast_poll_stop_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
poll_control_cluster_srv_fast_poll_stop_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  _Bool _Var1;
  ezb_zcl_status_t eVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 uVar4;
  
  if (packet == (zcl_packet_t *)0x0) {
    uVar4 = 0xfe;
  }
  else if (rsp == (zcl_packet_t *)0x0) {
    uVar4 = 0xfe;
  }
  else {
    _Var1 = poll_control_source_is_exist_in_bind_table
                      ((packet->header).src_ep,(packet->header).src_addr.u.short_addr);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      uVar4 = 1;
    }
    else {
      iVar3 = nwk_pim_is_fast_poll_running();
      if (iVar3 == 0) {
        uVar4 = 1;
      }
      else {
        nwk_pim_stop_fast_poll();
        iVar3 = nwk_pim_is_fast_poll_running();
        if (iVar3 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
      }
    }
  }
  eVar2 = zcl_packet_setup_default_response(rsp,packet,uVar4);
  return eVar2;
}

