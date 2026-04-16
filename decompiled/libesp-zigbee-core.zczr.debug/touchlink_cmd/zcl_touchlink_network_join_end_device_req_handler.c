/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_network_join_end_device_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_touchlink_network_join_end_device_req_handler(zcl_packet_t *packet)

{
  undefined1 uVar1;
  zcl_status_t zVar2;
  uint uVar3;
  uint16_t uStack_56;
  undefined4 uStack_54;
  uint16_t offset;
  zcl_touchlink_join_end_device_req_t req;
  
  if (packet == (zcl_packet_t *)0x0) {
    zVar2 = 0xfe;
  }
  else if (packet->payload == (zcl_packet_payload_t *)0x0) {
    zVar2 = 0xfe;
  }
  else {
    memset(&stack0xffffffac,0,0x44);
    uStack_54 = *(undefined4 *)&(packet->header).src_addr;
    req.cmd_ctrl.peer_addr._0_4_ = *(undefined4 *)((int)&(packet->header).src_addr.u + 2);
    req.cmd_ctrl.peer_addr.u.group_addr.bcast =
         *(ezb_shortaddr_t *)((int)&(packet->header).src_addr.u + 6);
    req.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
    req.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
    uStack_56 = 0;
    af_read_le32(packet->payload,&uStack_56,(uint32_t *)((int)&req.cmd_ctrl.peer_addr.u + 6));
    af_read_bytes(packet->payload,&uStack_56,8,(uint8_t *)&req.transaction_id);
    af_read_le8(packet->payload,&uStack_56,req.ext_panid.field_0.u8 + 4);
    af_read_bytes(packet->payload,&uStack_56,0x10,req.ext_panid.field_0.u8 + 5);
    af_read_le8(packet->payload,&uStack_56,req.encrypted_nwk_key + 0xc);
    af_read_le8(packet->payload,&uStack_56,req.encrypted_nwk_key + 0xd);
    af_read_le16(packet->payload,&uStack_56,(uint16_t *)(req.encrypted_nwk_key + 0xf));
    af_read_le16(packet->payload,&uStack_56,(uint16_t *)&req.channel);
    af_read_le16(packet->payload,&uStack_56,&req.pan_id);
    af_read_le16(packet->payload,&uStack_56,&req.new_nwk_addr);
    af_read_le16(packet->payload,&uStack_56,&req.group_id_begin);
    af_read_le16(packet->payload,&uStack_56,&req.group_id_end);
    af_read_le16(packet->payload,&uStack_56,&req.free_nwk_addr_begin);
    af_read_le16(packet->payload,&uStack_56,&req.free_nwk_addr_end);
    uVar3 = zmsg_get_length(packet->payload);
    if (uVar3 < uStack_56) {
      zVar2 = 0x80;
    }
    else {
      uVar1 = touchlink_join_ed_req_handler(&stack0xffffffac);
      zVar2 = zcl_status_to_err(uVar1);
    }
  }
  return zVar2;
}

