/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_commissioning.o -> touchlink_commissioning_get_group_ids_rsp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
touchlink_commissioning_get_group_ids_rsp_cmd_handler(zcl_packet_t *packet,zcl_packet_t *resp)

{
  uint16_t *offset_00;
  uint uVar1;
  ezb_zcl_status_t eVar2;
  uint uVar3;
  undefined1 auStack_2c [4];
  ezb_zcl_touchlink_get_group_ids_rsp_t rsp;
  uint16_t offset;
  
  rsp.group_ids._2_2_ = 0;
  auStack_2c = (undefined1  [4])0x0;
  rsp.total = '\0';
  rsp.start_index = '\0';
  rsp.count = '\0';
  rsp._3_1_ = 0;
  if (packet == (zcl_packet_t *)0x0) {
    eVar2 = 0xfe;
  }
  else if (resp == (zcl_packet_t *)0x0) {
    eVar2 = 0xfe;
  }
  else {
    uVar3 = zmsg_get_length(packet->payload);
    offset_00 = (uint16_t *)((int)&rsp.group_ids + 2);
    af_read_le8(packet->payload,offset_00,auStack_2c);
    af_read_le8(packet->payload,offset_00,auStack_2c + 1);
    af_read_le8(packet->payload,offset_00,auStack_2c + 2);
    if (uVar3 < rsp.group_ids._2_2_) {
      eVar2 = 0x80;
    }
    else {
      rsp._0_4_ = calloc((uint)auStack_2c >> 0x10 & 0xff,2);
      if ((void *)rsp._0_4_ == (void *)0x0) {
        eVar2 = 0x89;
      }
      else {
        for (uVar1 = 0; uVar1 < ((uint)auStack_2c >> 0x10 & 0xff); uVar1 = uVar1 + 1 & 0xff) {
          af_read_le16(packet->payload,(uint16_t *)((int)&rsp.group_ids + 2),
                       (uint16_t *)(rsp._0_4_ + uVar1 * 2));
        }
        if (uVar3 < rsp.group_ids._2_2_) {
          eVar2 = 0x80;
        }
        else {
          eVar2 = zcl_message_group_ids_rsp
                            (packet,(ezb_zcl_touchlink_get_group_ids_rsp_t *)auStack_2c);
        }
      }
    }
  }
  if (rsp._0_4_ != 0) {
    mm_free();
  }
  eVar2 = zcl_packet_setup_default_response(resp,packet,eVar2);
  return eVar2;
}

