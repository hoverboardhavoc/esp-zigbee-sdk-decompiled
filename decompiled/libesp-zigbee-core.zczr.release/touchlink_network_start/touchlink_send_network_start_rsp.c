/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_network_start.o -> touchlink_send_network_start_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_send_network_start_rsp(touchlink_event_start_network_t *start_network)

{
  undefined2 uVar1;
  int iVar2;
  ezb_err_t eVar3;
  undefined1 auStack_38 [2];
  undefined1 auStack_36 [2];
  zcl_touchlink_network_start_rsp_t rsp;
  
  memset(auStack_38,0,0x28);
  rsp.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
  if (start_network == (touchlink_event_start_network_t *)0x0) {
    rsp.transaction_id._0_1_ = '\x01';
    rsp.cmd_ctrl.peer_addr.u._4_1_ = '\0';
  }
  else {
    rsp.transaction_id._0_1_ = start_network->status;
    rsp.transaction_id._1_1_ = (start_network->ext_panid).field_0.u8[0];
    rsp.transaction_id._3_1_ = (start_network->ext_panid).field_0.u8[2];
    rsp.transaction_id._2_1_ = (start_network->ext_panid).field_0.u8[1];
    uVar1 = *(undefined2 *)((int)&(start_network->ext_panid).field_0 + 4);
    rsp.status = (start_network->ext_panid).field_0.u8[3];
    rsp.ext_panid.field_0.u8[2] = (start_network->ext_panid).field_0.u8[6];
    rsp.ext_panid.field_0.u8[3] = (start_network->ext_panid).field_0.u8[7];
    rsp.ext_panid.field_0.u8[1] = (uint8_t)((ushort)uVar1 >> 8);
    rsp.ext_panid.field_0.u8[0] = (uint8_t)uVar1;
    rsp.ext_panid.field_0.u8[4] = touchlink_nwk_update_id();
    rsp._24_2_ = start_network->pan_id;
    rsp.cmd_ctrl.peer_addr.u._4_1_ = start_network->tsn;
    rsp.ext_panid.field_0.u8[5] = start_network->channel;
  }
  rsp._28_4_ = touchlink_network_start_rsp_confirm;
  auStack_38[0] = 3;
  rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)start_network;
  iVar2 = touchlink_transaction_get();
  memcpy(auStack_36,(void *)(iVar2 + 8),8);
  eVar3 = zcl_touchlink_network_start_rsp(auStack_38);
  return eVar3;
}

