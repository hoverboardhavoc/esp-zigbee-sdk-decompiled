/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_discovery.o -> touchlink_send_scan_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_send_scan_req(_Bool new_trans,void *arg)

{
  undefined1 uVar1;
  undefined3 in_register_00002029;
  int iVar2;
  undefined4 uStack_2c;
  zcl_touchlink_scan_req_t req;
  
  uStack_2c = 0;
  req.cmd_ctrl.peer_addr._0_4_ = 0;
  req.cmd_ctrl.peer_addr.u._2_4_ = 0;
  req.cmd_ctrl._8_4_ = 0;
  req.transaction_id = 0;
  req.zigbee_info = '\0';
  req.touchlink_info = '\0';
  req._18_2_ = 0;
  req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  req.cmd_ctrl._8_4_ = touchlink_transaction_id(CONCAT31(in_register_00002029,new_trans));
  uVar1 = touchlink_zigbee_info();
  req.transaction_id = CONCAT31(req.transaction_id._1_3_,uVar1);
  uVar1 = touchlink_touchlink_info();
  req.transaction_id._0_2_ = CONCAT11(uVar1,(undefined1)req.transaction_id);
  req._16_4_ = touchlink_scan_req_confirm;
  uStack_2c = CONCAT31(uStack_2c._1_3_,2);
  uStack_2c = CONCAT22(0xffff,(undefined2)uStack_2c);
  req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)arg;
  iVar2 = zcl_touchlink_scan_req(&uStack_2c);
  if (iVar2 != 0) {
    touchlink_set_transaction_id(0);
  }
  return iVar2;
}

