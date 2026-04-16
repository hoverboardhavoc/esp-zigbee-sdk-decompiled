/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_cmd.o -> zcl_touchlink_srv_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_touchlink_srv_handler(zcl_packet_t *packet)

{
  byte bVar1;
  zmsg_t *pzVar2;
  zcl_status_t zVar3;
  undefined1 uVar4;
  uint uVar5;
  uint16_t uStack_5e;
  undefined1 auStack_5c [2];
  uint16_t offset;
  zcl_touchlink_reset_to_factory_new_req_t req;
  uint16_t auStack_40 [6];
  uint8_t uStack_33;
  uint16_t uStack_32;
  uint16_t uStack_30;
  uint16_t uStack_2e;
  uint16_t uStack_2c;
  uint16_t uStack_2a;
  uint16_t uStack_28;
  uint16_t uStack_26;
  uint16_t uStack_24;
  uint16_t auStack_22 [9];
  
  if (packet == (zcl_packet_t *)0x0) {
    packet = (zcl_packet_t *)__assert_func(0,0,0);
  }
  bVar1 = (packet->header).cmd_id;
  if (bVar1 == 0x10) {
    pzVar2 = packet->payload;
    if (pzVar2 == (zmsg_t *)0x0) {
      return 0xfe;
    }
    memset((void *)((int)&req.cmd_ctrl.peer_addr.u + 6),0,0x40);
    memcpy(auStack_5c,packet,10);
    req.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
    req.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
    uStack_5e = 0;
    af_read_le32(pzVar2,&uStack_5e,(uint32_t *)((int)&req.cmd_ctrl.peer_addr.u + 6));
    af_read_bytes(packet->payload,&uStack_5e,8,(uint8_t *)&req.transaction_id);
    af_read_le8(packet->payload,&uStack_5e,(uint8_t *)&req.cnf_ctx.user_ctx);
    af_read_bytes(packet->payload,&uStack_5e,0x10,(uint8_t *)((int)&req.cnf_ctx.user_ctx + 1));
    af_read_le8(packet->payload,&uStack_5e,&uStack_33);
    af_read_le16(packet->payload,&uStack_5e,&uStack_32);
    af_read_le16(packet->payload,&uStack_5e,&uStack_30);
    af_read_le16(packet->payload,&uStack_5e,&uStack_2e);
    af_read_le16(packet->payload,&uStack_5e,&uStack_2c);
    af_read_le16(packet->payload,&uStack_5e,&uStack_2a);
    af_read_le16(packet->payload,&uStack_5e,&uStack_28);
    af_read_le16(packet->payload,&uStack_5e,&uStack_26);
    af_read_le16(packet->payload,&uStack_5e,&uStack_24);
    uVar5 = zmsg_get_length(packet->payload);
    if (uVar5 < uStack_5e) {
      return 0x80;
    }
    uVar4 = touchlink_network_start_req_handler(auStack_5c);
  }
  else if (bVar1 < 0x11) {
    if (bVar1 == 6) {
      pzVar2 = packet->payload;
      if (pzVar2 == (zmsg_t *)0x0) {
        return 0xfe;
      }
      req.cmd_ctrl._8_4_ = 0;
      req.transaction_id = 0;
      req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
      req.cnf_ctx.user_ctx = (void *)0x0;
      memcpy(auStack_5c,packet,10);
      req.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
      req.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
      uStack_5e = 0;
      af_read_le32(pzVar2,&uStack_5e,(uint32_t *)((int)&req.cmd_ctrl.peer_addr.u + 6));
      af_read_le16(packet->payload,&uStack_5e,(uint16_t *)&req.transaction_id);
      uVar5 = zmsg_get_length(packet->payload);
      if (uVar5 < uStack_5e) {
        return 0x80;
      }
      uVar4 = touchlink_identify_req_handler(auStack_5c);
    }
    else if (bVar1 < 7) {
      if (bVar1 == 0) {
        pzVar2 = packet->payload;
        if (pzVar2 == (zmsg_t *)0x0) {
          return 0xfe;
        }
        req.cmd_ctrl._8_4_ = 0;
        req.transaction_id = 0;
        req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
        req.cnf_ctx.user_ctx = (void *)0x0;
        memcpy(auStack_5c,packet,10);
        req.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
        req.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
        uStack_5e = 0;
        af_read_le32(pzVar2,&uStack_5e,(uint32_t *)((int)&req.cmd_ctrl.peer_addr.u + 6));
        af_read_le8(packet->payload,&uStack_5e,(uint8_t *)&req.transaction_id);
        af_read_le8(packet->payload,&uStack_5e,(uint8_t *)((int)&req.transaction_id + 1));
        uVar5 = zmsg_get_length(packet->payload);
        if (uVar5 < uStack_5e) {
          return 0x80;
        }
        uVar4 = touchlink_scan_req_handler(auStack_5c);
      }
      else {
        if (bVar1 != 2) goto _L0;
        pzVar2 = packet->payload;
        if (pzVar2 == (zmsg_t *)0x0) {
          return 0xfe;
        }
        req.cmd_ctrl._8_4_ = 0;
        req.transaction_id = 0;
        req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
        req.cnf_ctx.user_ctx = (void *)0x0;
        memcpy(auStack_5c,packet,10);
        req.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
        req.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
        uStack_5e = 0;
        af_read_le32(pzVar2,&uStack_5e,(uint32_t *)((int)&req.cmd_ctrl.peer_addr.u + 6));
        af_read_le8(packet->payload,&uStack_5e,(uint8_t *)&req.transaction_id);
        uVar5 = zmsg_get_length(packet->payload);
        if (uVar5 < uStack_5e) {
          return 0x80;
        }
        uVar4 = touchlink_device_info_req_handler(auStack_5c);
      }
    }
    else {
      if (bVar1 != 7) {
_L0:
        zVar3 = zcl_packet_send_default_response(packet,0x81);
        return zVar3;
      }
      pzVar2 = packet->payload;
      if (pzVar2 == (zmsg_t *)0x0) {
        return 0xfe;
      }
      req.cmd_ctrl._8_4_ = 0;
      req.transaction_id = 0;
      req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
      memcpy(auStack_5c,packet,10);
      req.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
      req.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
      uStack_5e = 0;
      af_read_le32(pzVar2,&uStack_5e,(uint32_t *)((int)&req.cmd_ctrl.peer_addr.u + 6));
      uVar5 = zmsg_get_length(packet->payload);
      if (uVar5 < uStack_5e) {
        return 0x80;
      }
      uVar4 = touchlink_factory_new_req_handler(auStack_5c);
    }
  }
  else if (bVar1 == 0x14) {
    pzVar2 = packet->payload;
    if (pzVar2 == (zmsg_t *)0x0) {
      return 0xfe;
    }
    memset((void *)((int)&req.cmd_ctrl.peer_addr.u + 6),0,0x38);
    memcpy(auStack_5c,packet,10);
    req.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
    req.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
    uStack_5e = 0;
    af_read_le32(pzVar2,&uStack_5e,(uint32_t *)((int)&req.cmd_ctrl.peer_addr.u + 6));
    af_read_bytes(packet->payload,&uStack_5e,8,(uint8_t *)&req.transaction_id);
    af_read_le8(packet->payload,&uStack_5e,(uint8_t *)&req.cnf_ctx.user_ctx);
    af_read_bytes(packet->payload,&uStack_5e,0x10,(uint8_t *)((int)&req.cnf_ctx.user_ctx + 1));
    af_read_le8(packet->payload,&uStack_5e,&uStack_33);
    af_read_le8(packet->payload,&uStack_5e,(uint8_t *)&uStack_32);
    af_read_le16(packet->payload,&uStack_5e,&uStack_30);
    af_read_le16(packet->payload,&uStack_5e,&uStack_2e);
    af_read_le16(packet->payload,&uStack_5e,&uStack_2c);
    af_read_le16(packet->payload,&uStack_5e,&uStack_2a);
    af_read_le16(packet->payload,&uStack_5e,&uStack_28);
    af_read_le16(packet->payload,&uStack_5e,&uStack_26);
    af_read_le16(packet->payload,&uStack_5e,&uStack_24);
    af_read_le16(packet->payload,&uStack_5e,auStack_22);
    uVar5 = zmsg_get_length(packet->payload);
    if (uVar5 < uStack_5e) {
      return 0x80;
    }
    uVar4 = touchlink_join_ed_req_handler(auStack_5c);
  }
  else if (bVar1 == 0x16) {
    pzVar2 = packet->payload;
    if (pzVar2 == (zmsg_t *)0x0) {
      return 0xfe;
    }
    memset((void *)((int)&req.cmd_ctrl.peer_addr.u + 6),0,0x1c);
    memcpy(auStack_5c,packet,10);
    req.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
    req.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
    uStack_5e = 0;
    af_read_le32(pzVar2,&uStack_5e,(uint32_t *)((int)&req.cmd_ctrl.peer_addr.u + 6));
    af_read_bytes(packet->payload,&uStack_5e,8,(uint8_t *)&req.transaction_id);
    af_read_le8(packet->payload,&uStack_5e,(uint8_t *)&req.cnf_ctx.user_ctx);
    af_read_le8(packet->payload,&uStack_5e,(uint8_t *)((int)&req.cnf_ctx.user_ctx + 1));
    af_read_le16(packet->payload,&uStack_5e,(uint16_t *)((int)&req.cnf_ctx.user_ctx + 2));
    af_read_le16(packet->payload,&uStack_5e,auStack_40);
    uVar5 = zmsg_get_length(packet->payload);
    if (uVar5 < uStack_5e) {
      return 0x80;
    }
    uVar4 = touchlink_network_update_req_handler(auStack_5c);
  }
  else {
    if (bVar1 != 0x12) goto _L0;
    pzVar2 = packet->payload;
    if (pzVar2 == (zmsg_t *)0x0) {
      return 0xfe;
    }
    memset((void *)((int)&req.cmd_ctrl.peer_addr.u + 6),0,0x38);
    memcpy(auStack_5c,packet,10);
    req.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
    req.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
    uStack_5e = 0;
    af_read_le32(pzVar2,&uStack_5e,(uint32_t *)((int)&req.cmd_ctrl.peer_addr.u + 6));
    af_read_bytes(packet->payload,&uStack_5e,8,(uint8_t *)&req.transaction_id);
    af_read_le8(packet->payload,&uStack_5e,(uint8_t *)&req.cnf_ctx.user_ctx);
    af_read_bytes(packet->payload,&uStack_5e,0x10,(uint8_t *)((int)&req.cnf_ctx.user_ctx + 1));
    af_read_le8(packet->payload,&uStack_5e,&uStack_33);
    af_read_le8(packet->payload,&uStack_5e,(uint8_t *)&uStack_32);
    af_read_le16(packet->payload,&uStack_5e,&uStack_30);
    af_read_le16(packet->payload,&uStack_5e,&uStack_2e);
    af_read_le16(packet->payload,&uStack_5e,&uStack_2c);
    af_read_le16(packet->payload,&uStack_5e,&uStack_2a);
    af_read_le16(packet->payload,&uStack_5e,&uStack_28);
    af_read_le16(packet->payload,&uStack_5e,&uStack_26);
    af_read_le16(packet->payload,&uStack_5e,&uStack_24);
    af_read_le16(packet->payload,&uStack_5e,auStack_22);
    uVar5 = zmsg_get_length(packet->payload);
    if (uVar5 < uStack_5e) {
      return 0x80;
    }
    uVar4 = touchlink_join_router_req_handler(auStack_5c);
  }
  zVar3 = zcl_status_to_err(uVar4);
  return zVar3;
}

