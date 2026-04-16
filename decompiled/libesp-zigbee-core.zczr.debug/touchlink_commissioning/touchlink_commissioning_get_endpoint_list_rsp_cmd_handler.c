/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_commissioning.o -> touchlink_commissioning_get_endpoint_list_rsp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
touchlink_commissioning_get_endpoint_list_rsp_cmd_handler(zcl_packet_t *packet,zcl_packet_t *resp)

{
  uint16_t *puVar1;
  int iVar2;
  ezb_zcl_status_t eVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_2c [4];
  ezb_zcl_touchlink_get_ep_list_rsp_t rsp;
  uint16_t offset;
  
  rsp.records._2_2_ = 0;
  auStack_2c = (undefined1  [4])0x0;
  rsp.total = '\0';
  rsp.start_index = '\0';
  rsp.count = '\0';
  rsp._3_1_ = 0;
  if (packet == (zcl_packet_t *)0x0) {
    eVar3 = 0xfe;
  }
  else if (resp == (zcl_packet_t *)0x0) {
    eVar3 = 0xfe;
  }
  else {
    uVar4 = zmsg_get_length(packet->payload);
    puVar1 = (uint16_t *)((int)&rsp.records + 2);
    af_read_le8(packet->payload,puVar1,auStack_2c);
    af_read_le8(packet->payload,puVar1,auStack_2c + 1);
    af_read_le8(packet->payload,puVar1,auStack_2c + 2);
    if (uVar4 < rsp.records._2_2_) {
      eVar3 = 0x80;
    }
    else {
      rsp._0_4_ = calloc((uint)auStack_2c >> 0x10 & 0xff,10);
      if ((void *)rsp._0_4_ == (void *)0x0) {
        eVar3 = 0x89;
      }
      else {
        for (uVar5 = 0; uVar5 < ((uint)auStack_2c >> 0x10 & 0xff); uVar5 = uVar5 + 1 & 0xff) {
          iVar2 = uVar5 * 10;
          puVar1 = (uint16_t *)((int)&rsp.records + 2);
          af_read_le16(packet->payload,puVar1,(uint16_t *)(rsp._0_4_ + iVar2));
          af_read_le8(packet->payload,puVar1,(uint8_t *)(rsp._0_4_ + iVar2 + 2));
          af_read_le16(packet->payload,puVar1,(uint16_t *)(rsp._0_4_ + iVar2 + 4));
          af_read_le16(packet->payload,puVar1,(uint16_t *)(rsp._0_4_ + iVar2 + 6));
          af_read_le8(packet->payload,puVar1,(uint8_t *)(rsp._0_4_ + iVar2 + 8));
        }
        if (uVar4 < rsp.records._2_2_) {
          eVar3 = 0x80;
        }
        else {
          eVar3 = zcl_message_endpoint_list_rsp
                            (packet,(ezb_zcl_touchlink_get_ep_list_rsp_t *)auStack_2c);
        }
      }
    }
  }
  if (rsp._0_4_ != 0) {
    mm_free();
  }
  eVar3 = zcl_packet_setup_default_response(resp,packet,eVar3);
  return eVar3;
}

