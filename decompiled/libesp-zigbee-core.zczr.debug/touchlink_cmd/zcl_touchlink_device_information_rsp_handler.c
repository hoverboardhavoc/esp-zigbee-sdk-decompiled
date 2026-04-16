/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_device_information_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_touchlink_device_information_rsp_handler(zcl_packet_t *packet)

{
  int iVar1;
  undefined1 uVar2;
  zcl_status_t zVar3;
  uint uVar4;
  uint16_t uStack_42;
  undefined4 uStack_40;
  uint16_t offset;
  zcl_touchlink_device_info_rsp_t rsp;
  
  if (packet == (zcl_packet_t *)0x0) {
    zVar3 = 0xfe;
  }
  else if (packet->payload == (zmsg_t *)0x0) {
    zVar3 = 0xfe;
  }
  else {
    rsp.cmd_ctrl._8_4_ = 0;
    rsp.transaction_id = 0;
    rsp.n_sub_devices = '\0';
    rsp.start_index = '\0';
    rsp.n_records = '\0';
    rsp._19_1_ = 0;
    rsp.records = (zcl_touchlink_sub_device_info_record_t *)0x0;
    rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
    uStack_40 = *(undefined4 *)&(packet->header).src_addr;
    rsp.cmd_ctrl.peer_addr._0_4_ = *(undefined4 *)((int)&(packet->header).src_addr.u + 2);
    rsp.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
    rsp.cmd_ctrl.peer_addr.u.group_addr.bcast =
         *(undefined2 *)((int)&(packet->header).src_addr.u + 6);
    rsp.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
    uStack_42 = 0;
    af_read_le32(packet->payload,&uStack_42,(uint32_t *)((int)&rsp.cmd_ctrl.peer_addr.u + 6));
    af_read_le8(packet->payload,&uStack_42,(uint8_t *)((int)&rsp.transaction_id + 1));
    af_read_le8(packet->payload,&uStack_42,(uint8_t *)&rsp.transaction_id);
    af_read_le8(packet->payload,&uStack_42,(uint8_t *)((int)&rsp.transaction_id + 2));
    uVar4 = zmsg_get_length(packet->payload);
    if (uVar4 < uStack_42) {
      zVar3 = 0x80;
    }
    else {
      uVar4 = rsp.transaction_id >> 0x10 & 0xff;
      if (uVar4 != 0) {
        rsp._16_4_ = calloc(uVar4,0x12);
        for (uVar4 = 0; uVar4 < (rsp.transaction_id >> 0x10 & 0xff); uVar4 = uVar4 + 1 & 0xff) {
          iVar1 = uVar4 * 0x12;
          af_read_bytes(packet->payload,&uStack_42,8,(uint8_t *)(rsp._16_4_ + iVar1));
          af_read_le8(packet->payload,&uStack_42,(uint8_t *)(rsp._16_4_ + iVar1 + 8));
          af_read_le16(packet->payload,&uStack_42,(uint16_t *)(rsp._16_4_ + iVar1 + 10));
          af_read_le16(packet->payload,&uStack_42,(uint16_t *)(rsp._16_4_ + iVar1 + 0xc));
          af_read_le8(packet->payload,&uStack_42,(uint8_t *)(rsp._16_4_ + iVar1 + 0xe));
          af_read_le8(packet->payload,&uStack_42,(uint8_t *)(rsp._16_4_ + iVar1 + 0xf));
          af_read_le8(packet->payload,&uStack_42,(uint8_t *)(rsp._16_4_ + iVar1 + 0x10));
        }
      }
      uVar2 = touchlink_device_info_rsp_handler(&stack0xffffffc0);
      zVar3 = zcl_status_to_err(uVar2);
    }
  }
  if (rsp._16_4_ != 0) {
    mm_free();
  }
  return zVar3;
}

