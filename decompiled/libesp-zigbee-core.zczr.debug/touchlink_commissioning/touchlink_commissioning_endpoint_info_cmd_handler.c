/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_commissioning.o -> touchlink_commissioning_endpoint_info_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
touchlink_commissioning_endpoint_info_cmd_handler(zcl_packet_t *packet,zcl_packet_t *resp)

{
  ezb_zcl_status_t eVar1;
  uint uVar2;
  uint16_t *offset_00;
  undefined1 auStack_34 [4];
  ezb_zcl_touchlink_ep_info_t ep_info;
  uint16_t offset;
  
  ep_info.device_id = 0;
  auStack_34 = (undefined1  [4])0x0;
  ep_info.ieee_addr.field_0.u64._0_4_ = 0;
  ep_info.ieee_addr.field_0.u64._4_4_ = 0;
  ep_info.nwk_addr = 0;
  ep_info.ep_id = '\0';
  ep_info._11_1_ = 0;
  ep_info.profile_id = 0;
  if (packet == (zcl_packet_t *)0x0) {
    eVar1 = 0xfe;
  }
  else if (resp == (zcl_packet_t *)0x0) {
    eVar1 = 0xfe;
  }
  else {
    uVar2 = zmsg_get_length(packet->payload);
    offset_00 = &ep_info.device_id;
    af_read_bytes(packet->payload,offset_00,8,auStack_34);
    af_read_le16(packet->payload,offset_00,(uint16_t *)(ep_info.ieee_addr.field_0.u8 + 4));
    af_read_le8(packet->payload,offset_00,ep_info.ieee_addr.field_0.u8 + 6);
    af_read_le16(packet->payload,offset_00,&ep_info.nwk_addr);
    af_read_le16(packet->payload,offset_00,(uint16_t *)&ep_info.ep_id);
    af_read_le8(packet->payload,offset_00,(uint8_t *)&ep_info.profile_id);
    if (uVar2 < ep_info.device_id) {
      eVar1 = 0x80;
    }
    else {
      eVar1 = zcl_message_to_touchlink_ep_info(packet,(ezb_zcl_touchlink_ep_info_t *)auStack_34);
    }
  }
  eVar1 = zcl_packet_setup_default_response(resp,packet,eVar1);
  return eVar1;
}

