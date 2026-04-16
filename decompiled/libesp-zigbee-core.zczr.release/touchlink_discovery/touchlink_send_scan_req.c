/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_discovery.o -> touchlink_send_scan_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_send_scan_req(_Bool new_trans,void *arg)

{
  undefined3 in_register_00002029;
  int iVar1;
  undefined1 auStack_2c [2];
  undefined2 uStack_2a;
  zcl_touchlink_scan_req_t req;
  
  memset(auStack_2c,0,0x1c);
  req.cmd_ctrl._8_4_ = touchlink_transaction_id(CONCAT31(in_register_00002029,new_trans));
  req.transaction_id._0_1_ = touchlink_zigbee_info();
  req.transaction_id._1_1_ = touchlink_touchlink_info();
  req._16_4_ = touchlink_scan_req_confirm;
  auStack_2c[0] = 2;
  uStack_2a = 0xffff;
  req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)arg;
  iVar1 = zcl_touchlink_scan_req(auStack_2c);
  if (iVar1 != 0) {
    touchlink_set_transaction_id(0);
  }
  return iVar1;
}

