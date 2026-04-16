/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_cmd.o -> zcl_touchlink_cli_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_touchlink_cli_handler(zcl_packet_t *packet)

{
  byte bVar1;
  int iVar2;
  zcl_status_t zVar3;
  undefined1 uVar4;
  uint uVar5;
  zmsg_t *pzVar6;
  uint16_t uStack_5e;
  undefined1 auStack_5c [2];
  uint16_t offset;
  zcl_touchlink_join_end_device_rsp_t rsp;
  uint8_t uStack_3b;
  uint8_t auStack_3a [2];
  uint16_t uStack_38;
  uint16_t uStack_36;
  uint8_t uStack_34;
  uint8_t uStack_33;
  uint8_t auStack_32 [2];
  uint16_t uStack_30;
  uint16_t uStack_2e;
  uint8_t uStack_2c;
  uint8_t auStack_2b [19];
  
  if (packet == (zcl_packet_t *)0x0) {
    packet = (zcl_packet_t *)__assert_func(0,0,0);
  }
  bVar1 = (packet->header).cmd_id;
  if (bVar1 == 0x11) {
    pzVar6 = packet->payload;
    if (pzVar6 == (zmsg_t *)0x0) {
      return 0xfe;
    }
    memset((void *)((int)&rsp.cmd_ctrl.peer_addr.u + 6),0,0x1c);
    memcpy(auStack_5c,packet,10);
    rsp.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
    rsp.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
    uStack_5e = 0;
    af_read_le32(pzVar6,&uStack_5e,(uint32_t *)((int)&rsp.cmd_ctrl.peer_addr.u + 6));
    af_read_le8(packet->payload,&uStack_5e,(uint8_t *)&rsp.transaction_id);
    af_read_bytes(packet->payload,&uStack_5e,8,(uint8_t *)((int)&rsp.transaction_id + 1));
    af_read_le8(packet->payload,&uStack_5e,(uint8_t *)((int)&rsp.cnf_ctx.cb + 1));
    af_read_le8(packet->payload,&uStack_5e,(uint8_t *)((int)&rsp.cnf_ctx.cb + 2));
    af_read_le16(packet->payload,&uStack_5e,(uint16_t *)&rsp.cnf_ctx.user_ctx);
    uVar5 = zmsg_get_length(packet->payload);
    if (uVar5 < uStack_5e) {
      return 0x80;
    }
    uVar4 = touchlink_network_start_rsp_handler(auStack_5c);
  }
  else if (bVar1 < 0x12) {
    if (bVar1 != 1) {
      if (bVar1 == 3) {
        pzVar6 = packet->payload;
        zVar3 = 0xfe;
        if (pzVar6 != (zmsg_t *)0x0) {
          rsp.cmd_ctrl._8_4_ = 0;
          rsp.transaction_id = 0;
          rsp.status = '\0';
          rsp._17_3_ = 0;
          rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
          rsp.cnf_ctx.user_ctx = (void *)0x0;
          memcpy(auStack_5c,packet,10);
          rsp.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
          rsp.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
          uStack_5e = 0;
          af_read_le32(pzVar6,&uStack_5e,(uint32_t *)((int)&rsp.cmd_ctrl.peer_addr.u + 6));
          af_read_le8(packet->payload,&uStack_5e,(uint8_t *)((int)&rsp.transaction_id + 1));
          af_read_le8(packet->payload,&uStack_5e,(uint8_t *)&rsp.transaction_id);
          af_read_le8(packet->payload,&uStack_5e,(uint8_t *)((int)&rsp.transaction_id + 2));
          zVar3 = 0x80;
          uVar5 = zmsg_get_length(packet->payload);
          if (uStack_5e <= uVar5) {
            uVar5 = rsp.transaction_id >> 0x10 & 0xff;
            if (uVar5 != 0) {
              rsp._16_4_ = calloc(uVar5,0x12);
              for (uVar5 = 0; uVar5 < (rsp.transaction_id >> 0x10 & 0xff); uVar5 = uVar5 + 1 & 0xff)
              {
                iVar2 = uVar5 * 0x12;
                af_read_bytes(packet->payload,&uStack_5e,8,(uint8_t *)(rsp._16_4_ + iVar2));
                af_read_le8(packet->payload,&uStack_5e,(uint8_t *)(rsp._16_4_ + iVar2 + 8));
                af_read_le16(packet->payload,&uStack_5e,(uint16_t *)(rsp._16_4_ + iVar2 + 10));
                af_read_le16(packet->payload,&uStack_5e,(uint16_t *)(rsp._16_4_ + iVar2 + 0xc));
                af_read_le8(packet->payload,&uStack_5e,(uint8_t *)(rsp._16_4_ + iVar2 + 0xe));
                af_read_le8(packet->payload,&uStack_5e,(uint8_t *)(rsp._16_4_ + iVar2 + 0xf));
                af_read_le8(packet->payload,&uStack_5e,(uint8_t *)(rsp._16_4_ + iVar2 + 0x10));
              }
            }
            uVar4 = touchlink_device_info_rsp_handler(auStack_5c);
            zVar3 = zcl_status_to_err(uVar4);
          }
        }
        if (rsp._16_4_ == 0) {
          return zVar3;
        }
        mm_free();
        return zVar3;
      }
_L0:
      zVar3 = zcl_packet_send_default_response(packet,0x81);
      return zVar3;
    }
    pzVar6 = packet->payload;
    if (pzVar6 == (zmsg_t *)0x0) {
      return 0xfe;
    }
    memset((void *)((int)&rsp.cmd_ctrl.peer_addr.u + 6),0,0x30);
    memcpy(auStack_5c,packet,10);
    rsp.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
    rsp.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
    uStack_5e = 0;
    af_read_le32(pzVar6,&uStack_5e,(uint32_t *)((int)&rsp.cmd_ctrl.peer_addr.u + 6));
    af_read_le8(packet->payload,&uStack_5e,(uint8_t *)&rsp.cnf_ctx);
    af_read_le8(packet->payload,&uStack_5e,&rsp.status);
    af_read_le8(packet->payload,&uStack_5e,&rsp.field_0x11);
    af_read_le16(packet->payload,&uStack_5e,(uint16_t *)&rsp.field_0x12);
    af_read_le32(packet->payload,&uStack_5e,&rsp.transaction_id);
    af_read_bytes(packet->payload,&uStack_5e,8,(uint8_t *)((int)&rsp.cnf_ctx.cb + 1));
    af_read_le8(packet->payload,&uStack_5e,&uStack_3b);
    af_read_le8(packet->payload,&uStack_5e,auStack_3a);
    af_read_le16(packet->payload,&uStack_5e,&uStack_38);
    af_read_le16(packet->payload,&uStack_5e,&uStack_36);
    af_read_le8(packet->payload,&uStack_5e,&uStack_34);
    af_read_le8(packet->payload,&uStack_5e,&uStack_33);
    if (uStack_34 == '\x01') {
      af_read_le8(packet->payload,&uStack_5e,auStack_32);
      af_read_le16(packet->payload,&uStack_5e,&uStack_30);
      af_read_le16(packet->payload,&uStack_5e,&uStack_2e);
      af_read_le8(packet->payload,&uStack_5e,&uStack_2c);
      af_read_le8(packet->payload,&uStack_5e,auStack_2b);
    }
    uVar5 = zmsg_get_length(packet->payload);
    if (uVar5 < uStack_5e) {
      return 0x80;
    }
    uVar4 = touchlink_scan_rsp_handler(auStack_5c);
  }
  else if (bVar1 == 0x13) {
    pzVar6 = packet->payload;
    if (pzVar6 == (zmsg_t *)0x0) {
      return 0xfe;
    }
    rsp.cmd_ctrl._8_4_ = 0;
    rsp.transaction_id = 0;
    rsp.status = '\0';
    rsp._17_3_ = 0;
    rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
    memcpy(auStack_5c,packet,10);
    rsp.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
    rsp.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
    uStack_5e = 0;
    af_read_le32(pzVar6,&uStack_5e,(uint32_t *)((int)&rsp.cmd_ctrl.peer_addr.u + 6));
    af_read_le8(packet->payload,&uStack_5e,(uint8_t *)&rsp.transaction_id);
    uVar5 = zmsg_get_length(packet->payload);
    if (uVar5 < uStack_5e) {
      return 0x80;
    }
    uVar4 = touchlink_join_router_rsp_handler(auStack_5c);
  }
  else {
    if (bVar1 != 0x15) goto _L0;
    pzVar6 = packet->payload;
    if (pzVar6 == (zmsg_t *)0x0) {
      return 0xfe;
    }
    rsp.cmd_ctrl._8_4_ = 0;
    rsp.transaction_id = 0;
    rsp.status = '\0';
    rsp._17_3_ = 0;
    rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
    memcpy(auStack_5c,packet,10);
    rsp.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
    rsp.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
    uStack_5e = 0;
    af_read_le32(pzVar6,&uStack_5e,(uint32_t *)((int)&rsp.cmd_ctrl.peer_addr.u + 6));
    af_read_le8(packet->payload,&uStack_5e,(uint8_t *)&rsp.transaction_id);
    uVar5 = zmsg_get_length(packet->payload);
    if (uVar5 < uStack_5e) {
      return 0x80;
    }
    uVar4 = touchlink_join_ed_rsp_handler(auStack_5c);
  }
  zVar3 = zcl_status_to_err(uVar4);
  return zVar3;
}

