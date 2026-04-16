/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_core.o -> zdo_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_indication_handler(af_data_ind_t *ind)

{
  int iVar1;
  undefined4 uStack_28;
  zdo_packet_t packet;
  
  uStack_28 = 0;
  packet.tsn = '\0';
  packet._1_1_ = 0;
  packet.dst_addr = 0;
  packet.src_addr = 0;
  packet.cluster_id = 0;
  packet.ctx.mode = '\0';
  packet.ctx._1_3_ = 0;
  packet.ctx.req_ctx.cb = (zdo_packet_req_callback_t)0x0;
  packet.ctx.req_ctx.arg = (zdo_packet_user_ctx_t)0x0;
  if (ind == (af_data_ind_t *)0x0) {
    iVar1 = 0x80;
  }
  else {
    iVar1 = zdo_packet_init_with_msg(&uStack_28,ind);
    if (iVar1 == 0) {
      iVar1 = zdo_packet_indication_handler(&uStack_28);
    }
  }
  return (zdp_status_t)iVar1;
}

