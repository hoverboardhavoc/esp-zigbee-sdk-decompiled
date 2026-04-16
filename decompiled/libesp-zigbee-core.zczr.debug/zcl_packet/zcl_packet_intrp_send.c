/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_intrp_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_intrp_send(zcl_packet_t *packet,zcl_packet_cnf_ctx_t *cnf_ctx)

{
  zcl_status_t zVar1;
  ezb_addr_mode_t local_30 [2];
  undefined2 uStack_2e;
  af_intrp_data_req_t req;
  
  if (packet == (zcl_packet_t *)0x0) {
    zVar1 = 0x87;
  }
  else {
    zcl_frame_fill_header(packet);
    local_30[0] = (packet->header).src_addr.addr_mode;
    uStack_2e = 0xffff;
    req.data.src_addr_mode = (packet->header).dst_addr.addr_mode;
    req.data._1_1_ = (packet->header).dst_addr.field_0x1;
    req.data.dst_pan_id = (packet->header).dst_addr.u.short_addr;
    req.data.dst_addr._0_2_ = (packet->header).dst_addr.u.group_addr.bcast;
    req.data.dst_addr.u.short_addr = *(ezb_shortaddr_t *)((int)&(packet->header).dst_addr.u + 4);
    req.data.dst_addr.u.group_addr.bcast =
         *(ezb_shortaddr_t *)((int)&(packet->header).dst_addr.u + 6);
    req.data.dst_addr.u._4_2_ = (packet->header).profile_id;
    req.data.dst_addr.u._6_2_ = (packet->header).cluster_id;
    req.data.profile_id._0_1_ = 0;
    req.data._16_4_ = zcl_packet_transfer_ownership(packet);
    if (cnf_ctx == (zcl_packet_cnf_ctx_t *)0x0) {
      req.data.asdu = (zmsg_t *)0x0;
      req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
    }
    else {
      req.data.asdu = (zmsg_t *)cnf_ctx->cb;
      req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)cnf_ctx->user_ctx;
    }
    af_intrp_data_request(local_30);
    zVar1 = err_to_zcl_status();
  }
  return zVar1;
}

