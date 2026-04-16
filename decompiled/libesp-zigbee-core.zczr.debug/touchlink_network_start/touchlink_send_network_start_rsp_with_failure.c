/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_network_start.o -> touchlink_send_network_start_rsp_with_failure
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_send_network_start_rsp_with_failure(uint8_t tsn)

{
  int iVar1;
  ezb_err_t eVar2;
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
  rsp.transaction_id = CONCAT31(rsp.transaction_id._1_3_,1);
  rsp._28_4_ = touchlink_network_start_rsp_confirm;
  rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  uStack_38 = CONCAT31(uStack_38._1_3_,3);
  iVar1 = touchlink_transaction_get();
  rsp.cmd_ctrl.peer_addr._0_4_ = *(undefined4 *)(iVar1 + 10);
  uStack_38 = CONCAT22(*(undefined2 *)(iVar1 + 8),(undefined2)uStack_38);
  rsp.cmd_ctrl.peer_addr.u._4_1_ = tsn;
  rsp.cmd_ctrl.peer_addr.u.group_addr.bcast = *(undefined2 *)(iVar1 + 0xe);
  eVar2 = zcl_touchlink_network_start_rsp(&uStack_38);
  return eVar2;
}

