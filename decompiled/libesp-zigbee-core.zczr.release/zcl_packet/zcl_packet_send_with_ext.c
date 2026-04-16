/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_send_with_ext
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t
zcl_packet_send_with_ext
          (zcl_packet_t *packet,zcl_packet_cnf_ctx_t *cnf_ctx,zcl_packet_tx_option_t *option)

{
  zcl_status_t zVar1;
  uint16_t uVar2;
  uint uVar3;
  undefined2 extraout_var;
  int iVar4;
  _Bool is_secured;
  zcl_packet_payload_t *pzStack_44;
  af_data_req_t af_req;
  
  if (packet != (zcl_packet_t *)0x0) {
    zcl_frame_fill_header(packet);
    uVar3 = zmsg_get_length(packet->payload);
    is_secured = false;
    if (option != (zcl_packet_tx_option_t *)0x0) {
      is_secured = (_Bool)((byte)*option & 1);
    }
    uVar2 = zcl_packet_max_available_space
                      ((packet->header).cluster_id,is_secured,
                       (_Bool)((byte)(*(ushort *)&(packet->header).fc >> 2) & 1));
    zVar1 = 0x89;
    if (uVar3 <= CONCAT22(extraout_var,uVar2)) {
      pzStack_44 = packet->payload;
      packet->payload = (zcl_packet_payload_t *)0x0;
      af_req.data.cluster_id = 0;
      af_req.data.profile_id = 0;
      af_req.data.radius = '\0';
      af_req.data.alias_seq_num = '\0';
      af_req.data.alias_src_addr = 0;
      af_req.data._24_4_ = 0;
      af_req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
      memcpy(&af_req,&(packet->header).dst_addr,10);
      af_req.data.dst_addr.u._6_2_ = (packet->header).cluster_id;
      af_req.data._14_2_ = (packet->header).profile_id;
      af_req.data.dst_addr.u._4_1_ = (packet->header).src_ep;
      af_req.data.dst_addr.u._5_1_ = (packet->header).dst_ep;
      if (option == (zcl_packet_tx_option_t *)0x0) {
        af_req.data.radius = af_req.data.radius | 2;
        iVar4 = zcl_cluster_fragment_is_supported();
        af_req.data.radius = af_req.data.radius & 0xf3 | (byte)(iVar4 << 2) & 0xc;
        uVar3 = 0;
      }
      else {
        af_req.data.radius = af_req.data.radius & 0xf0 | (byte)*option & 0xf;
        uVar3 = (byte)*option >> 4 & 1;
      }
      af_req.data.radius = (byte)(uVar3 << 4) | af_req.data.radius & 0xef;
      if (cnf_ctx == (zcl_packet_cnf_ctx_t *)0x0) {
        af_req.data._24_4_ = 0;
        af_req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
      }
      else {
        af_req.data._24_4_ = cnf_ctx->cb;
        af_req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)cnf_ctx->user_ctx;
      }
      af_data_request(&pzStack_44);
      zVar1 = err_to_zcl_status();
    }
    return zVar1;
  }
  return '\x01';
}

