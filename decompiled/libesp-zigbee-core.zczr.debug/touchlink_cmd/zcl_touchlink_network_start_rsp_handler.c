/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_network_start_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_touchlink_network_start_rsp_handler(zcl_packet_t *packet)

{
  undefined1 uVar1;
  zcl_status_t zVar2;
  uint uVar3;
  uint16_t uStack_3a;
  undefined4 uStack_38;
  uint16_t offset;
  zcl_touchlink_network_start_rsp_t rsp;
  
  if (packet == (zcl_packet_t *)0x0) {
    zVar2 = 0xfe;
  }
  else if (packet->payload == (zcl_packet_payload_t *)0x0) {
    zVar2 = 0xfe;
  }
  else {
    rsp.cmd_ctrl._8_4_ = 0;
    rsp.transaction_id = 0;
    rsp._16_4_ = 0;
    rsp.ext_panid.field_0.u64._3_4_ = 0;
    rsp._24_4_ = 0;
    rsp.pan_id = 0;
    rsp._30_2_ = 0;
    rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
    uStack_38 = *(undefined4 *)&(packet->header).src_addr;
    rsp.cmd_ctrl.peer_addr._0_4_ = *(undefined4 *)((int)&(packet->header).src_addr.u + 2);
    rsp.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
    rsp.cmd_ctrl.peer_addr.u.group_addr.bcast =
         *(undefined2 *)((int)&(packet->header).src_addr.u + 6);
    rsp.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
    uStack_3a = 0;
    af_read_le32(packet->payload,&uStack_3a,(uint32_t *)((int)&rsp.cmd_ctrl.peer_addr.u + 6));
    af_read_le8(packet->payload,&uStack_3a,(uint8_t *)&rsp.transaction_id);
    af_read_bytes(packet->payload,&uStack_3a,8,(uint8_t *)((int)&rsp.transaction_id + 1));
    af_read_le8(packet->payload,&uStack_3a,rsp.ext_panid.field_0.u8 + 4);
    af_read_le8(packet->payload,&uStack_3a,rsp.ext_panid.field_0.u8 + 5);
    af_read_le16(packet->payload,&uStack_3a,(uint16_t *)(rsp.ext_panid.field_0.u8 + 7));
    uVar3 = zmsg_get_length(packet->payload);
    if (uVar3 < uStack_3a) {
      zVar2 = 0x80;
    }
    else {
      uVar1 = touchlink_network_start_rsp_handler(&stack0xffffffc8);
      zVar2 = zcl_status_to_err(uVar1);
    }
  }
  return zVar2;
}

