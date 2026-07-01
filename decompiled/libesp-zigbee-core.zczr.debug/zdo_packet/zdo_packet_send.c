/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: af_req */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_packet_send(zdo_packet_t *packet)

{
  uint8_t uVar1;
  zdp_status_t zVar2;
  uint16_t uVar3;
  undefined2 extraout_var_00;
  uint uVar4;
  zdo_packet_ctx_entry_t *entry;
  undefined3 extraout_var;
  int iVar5;
  zmsg_t *pzStack_34;
  af_data_req_t af_req;
  
  if (packet == (zdo_packet_t *)0x0) {
_L0:
    iVar5 = 0x80;
    entry = (zdo_packet_ctx_entry_t *)packet;
  }
  else {
    uVar3 = zdo_packet_max_available_space(packet->cluster_id);
    uVar4 = zmsg_get_length(packet->payload);
    if (CONCAT22(extraout_var_00,uVar3) < uVar4) {
      entry = (zdo_packet_ctx_entry_t *)0x0;
      iVar5 = 0x8a;
    }
    else {
      if ((short)packet->cluster_id < 0) {
        if ((packet->ctx).mode != '\0') {
          __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_packet.c",0x1ca,
                        "zdo_packet_send","packet->ctx.mode == ZDO_NONE_RSP");
          goto _L0;
        }
      }
      else {
        iVar5 = core_globals_get();
        uVar1 = *(uint8_t *)(iVar5 + 0xca8);
        *(uint8_t *)(iVar5 + 0xca8) = uVar1 + '\x01';
        packet->tsn = uVar1;
      }
      zmsg_prepend_bytes(packet->payload,1,packet);
      entry = zdo_packet_ctx_create_entry(packet->tsn,(zdo_packet_ctx_t *)packet);
      if (entry == (zdo_packet_ctx_entry_t *)0x0) {
        iVar5 = 0x8a;
      }
      else {
        if ((entry->ctx).mode != '\0') {
          zVar2 = zdo_packet_ctx_list_add_entry(entry);
          iVar5 = CONCAT31(extraout_var,zVar2);
          if (iVar5 != 0) goto _L0;
        }
        pzStack_34 = (zmsg_t *)0x0;
        af_req.data.asdu = (zmsg_t *)0x0;
        af_req.data.dst_addr._0_4_ = 0;
        af_req.data.dst_addr.u._2_4_ = 0;
        af_req.data._12_4_ = 0;
        af_req.data.cluster_id = 0;
        af_req.data.profile_id = 0;
        af_req.data.radius = '\0';
        af_req.data.alias_seq_num = '\0';
        af_req.data.alias_src_addr = 0;
        af_req.data.field_9 = (anon_union_1_2_0b76fd53_for_aps_apsde_data_req_s_9)0x0;
        af_req.data._25_3_ = 0;
        af_req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
        pzStack_34 = zdo_packet_transfer_ownership(packet);
        af_req.data.asdu = (zmsg_t *)CONCAT31(af_req.data.asdu._1_3_,2);
        af_req.data.asdu = (zmsg_t *)CONCAT22(packet->dst_addr,af_req.data.asdu._0_2_);
        af_req.data.dst_addr.u._6_2_ = packet->cluster_id;
        af_req.data._20_4_ = af_req.data._20_4_ | 2;
        af_req.data._24_4_ = zdo_packet_cnf_handler;
        af_req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)entry;
        af_data_request(&pzStack_34);
        iVar5 = ezb_err_to_zdp_status();
        if (iVar5 == 0) goto _L0;
      }
    }
  }
_L0:
  zdo_packet_ctx_free_entry_direct(entry);
_L0:
  return (zdp_status_t)iVar5;
}

