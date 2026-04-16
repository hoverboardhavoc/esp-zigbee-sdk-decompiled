/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_send_with_ext
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
  zcl_packet_tx_option_t zVar1;
  zcl_status_t zVar2;
  _Bool _Var3;
  uint16_t uVar4;
  uint uVar5;
  undefined2 extraout_var;
  zmsg_t *pzStack_44;
  af_data_req_t af_req;
  
  if (packet == (zcl_packet_t *)0x0) {
    zVar2 = '\x01';
  }
  else {
    zcl_frame_fill_header(packet);
    uVar5 = zmsg_get_length(packet->payload);
    if (option == (zcl_packet_tx_option_t *)0x0) {
      _Var3 = false;
    }
    else {
      _Var3 = (_Bool)((byte)*option & 1);
    }
    uVar4 = zcl_packet_max_available_space
                      ((packet->header).cluster_id,_Var3,(_Bool)((packet->header).fc >> 2 & 1));
    if (CONCAT22(extraout_var,uVar4) < uVar5) {
      zVar2 = 0x89;
    }
    else {
      pzStack_44 = (zmsg_t *)0x0;
      af_req.data.asdu = (zmsg_t *)0x0;
      af_req.data.dst_addr._0_4_ = 0;
      af_req.data.dst_addr.u._2_4_ = 0;
      af_req.data._12_4_ = 0;
      af_req.data.cluster_id = 0;
      af_req.data.profile_id = 0;
      af_req.data.radius = '\0';
      af_req.data.alias_seq_num = '\0';
      af_req.data.alias_src_addr = 0;
      af_req.data._24_4_ = 0;
      af_req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
      pzStack_44 = zcl_packet_transfer_ownership(packet);
      af_req.data.asdu = *(zmsg_t **)&(packet->header).dst_addr;
      af_req.data.dst_addr._0_4_ = *(undefined4 *)((int)&(packet->header).dst_addr.u + 2);
      af_req.data.dst_addr.u._2_4_ = *(undefined4 *)((int)&(packet->header).dst_addr.u + 6);
      af_req.data._12_4_ = *(undefined4 *)&(packet->header).cluster_id;
      if (option == (zcl_packet_tx_option_t *)0x0) {
        af_req.data._20_4_ = af_req.data._20_4_ & 0xfffffffe | 2;
        _Var3 = zcl_packet_fragment_is_supported(packet);
        af_req.data.radius = (byte)af_req.data._20_4_ & 0xf3 | _Var3 << 2;
        uVar5 = 0;
      }
      else {
        zVar1 = *option;
        af_req.data.radius =
             (byte)af_req.data._20_4_ & 0xf0 | (byte)zVar1 & 1 | (byte)(((byte)zVar1 >> 1 & 1) << 1)
             | (byte)(((byte)zVar1 >> 2 & 1) << 2) | (byte)(((byte)zVar1 >> 3 & 1) << 3);
        uVar5 = (byte)zVar1 >> 4 & 1;
      }
      af_req.data.radius = (byte)(uVar5 << 4) | af_req.data.radius & 0xef;
      if (cnf_ctx == (zcl_packet_cnf_ctx_t *)0x0) {
        af_req.data._24_4_ = 0;
        af_req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
      }
      else {
        af_req.data._24_4_ = cnf_ctx->cb;
        af_req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)cnf_ctx->user_ctx;
      }
      af_data_request(&pzStack_44);
      zVar2 = err_to_zcl_status();
    }
  }
  return zVar2;
}

