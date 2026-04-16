/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_reset_to_factory_new_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_touchlink_reset_to_factory_new_req_handler(zcl_packet_t *packet)

{
  undefined1 uVar1;
  zcl_status_t zVar2;
  uint uVar3;
  uint16_t uStack_2a;
  undefined4 uStack_28;
  uint16_t offset;
  zcl_touchlink_reset_to_factory_new_req_t req;
  
  if (packet == (zcl_packet_t *)0x0) {
    zVar2 = 0xfe;
  }
  else if (packet->payload == (zmsg_t *)0x0) {
    zVar2 = 0xfe;
  }
  else {
    req.cmd_ctrl._8_4_ = 0;
    req.transaction_id = 0;
    req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
    uStack_28 = *(undefined4 *)&(packet->header).src_addr;
    req.cmd_ctrl.peer_addr._0_4_ = *(undefined4 *)((int)&(packet->header).src_addr.u + 2);
    req.cmd_ctrl.peer_addr.u._4_1_ = (packet->header).tsn;
    req.cmd_ctrl.peer_addr.u.group_addr.bcast =
         *(undefined2 *)((int)&(packet->header).src_addr.u + 6);
    req.cmd_ctrl.peer_addr.u._5_1_ = (packet->header).rssi;
    uStack_2a = 0;
    af_read_le32(packet->payload,&uStack_2a,(uint32_t *)((int)&req.cmd_ctrl.peer_addr.u + 6));
    uVar3 = zmsg_get_length(packet->payload);
    if (uVar3 < uStack_2a) {
      zVar2 = 0x80;
    }
    else {
      uVar1 = touchlink_factory_new_req_handler(&stack0xffffffd8);
      zVar2 = zcl_status_to_err(uVar1);
    }
  }
  return zVar2;
}

