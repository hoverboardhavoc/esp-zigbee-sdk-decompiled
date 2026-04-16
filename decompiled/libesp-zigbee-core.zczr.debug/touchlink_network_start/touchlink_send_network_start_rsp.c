/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_network_start.o -> touchlink_send_network_start_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_send_network_start_rsp(touchlink_event_start_network_t *start_network)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint8_t uVar5;
  undefined1 uVar6;
  int iVar7;
  ezb_err_t eVar8;
  undefined4 uStack_38;
  zcl_touchlink_network_start_rsp_t rsp;
  
  uStack_38 = 0;
  rsp.cmd_ctrl.peer_addr._0_4_ = 0;
  rsp.cmd_ctrl.peer_addr.u._2_4_ = 0;
  rsp.cmd_ctrl._8_4_ = 0;
  rsp.transaction_id = 0;
  rsp._16_4_ = 0;
  rsp.ext_panid.field_0.u64._3_4_ = 0;
  rsp._24_4_ = 0;
  rsp.pan_id = 0;
  rsp._30_2_ = 0;
  rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  rsp.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
  if (start_network == (touchlink_event_start_network_t *)0x0) {
    rsp.transaction_id = CONCAT31(rsp.transaction_id._1_3_,1);
    uVar5 = '\0';
  }
  else {
    uVar2 = *(undefined4 *)&(start_network->ext_panid).field_0;
    puVar1 = (undefined4 *)((int)&(start_network->ext_panid).field_0 + 4);
    uVar3 = *puVar1;
    rsp.transaction_id =
         CONCAT13((char)((uint)uVar2 >> 0x10),
                  CONCAT12((char)((uint)uVar2 >> 8),*(undefined2 *)start_network));
    rsp.ext_panid.field_0.u8[0] = (char)*(undefined2 *)puVar1;
    rsp.status = (uint8_t)((uint)uVar2 >> 0x18);
    rsp.ext_panid.field_0.u8[1] = (char)((uint)uVar3 >> 8);
    rsp.ext_panid.field_0.u8[2] = (char)((uint)uVar3 >> 0x10);
    rsp.ext_panid.field_0.u8[3] = (char)((uint)uVar3 >> 0x18);
    uVar6 = touchlink_nwk_update_id();
    uVar4 = rsp.ext_panid.field_0.u64._3_4_;
    rsp.ext_panid.field_0.u8[4] = uVar6;
    rsp._24_2_ = start_network->pan_id;
    rsp.ext_panid.field_0.u8[6] = SUB41(uVar4,3);
    rsp.ext_panid.field_0.u8[5] = start_network->channel;
    uVar5 = start_network->tsn;
  }
  rsp._28_4_ = touchlink_network_start_rsp_confirm;
  uStack_38 = CONCAT31(uStack_38._1_3_,3);
  rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)start_network;
  iVar7 = touchlink_transaction_get();
  rsp.cmd_ctrl.peer_addr._0_4_ = *(undefined4 *)(iVar7 + 10);
  uStack_38 = CONCAT22(*(undefined2 *)(iVar7 + 8),(undefined2)uStack_38);
  rsp.cmd_ctrl.peer_addr.u._4_1_ = uVar5;
  rsp.cmd_ctrl.peer_addr.u.group_addr.bcast = *(undefined2 *)(iVar7 + 0xe);
  eVar8 = zcl_touchlink_network_start_rsp(&uStack_38);
  return eVar8;
}

