/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_identify.o -> touchlink_send_identify_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

ezb_err_t touchlink_send_identify_req(uint16_t duration,ezb_extaddr_t *ieee_addr,void *arg)

{
  int iVar1;
  ezb_err_t eVar2;
  undefined4 uStack_2c;
  zcl_touchlink_identify_req_t req;
  
  uStack_2c = 0;
  req.cmd_ctrl.peer_addr._0_4_ = 0;
  req.cmd_ctrl.peer_addr.u._2_4_ = 0;
  req.cmd_ctrl._8_4_ = 0;
  req.transaction_id = 0;
  req.duration = 0;
  req._18_2_ = 0;
  req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  if (ieee_addr == (ezb_extaddr_t *)0x0) {
    eVar2 = 2;
  }
  else {
    iVar1 = touchlink_transaction_id(0);
    if (iVar1 == 0) {
      eVar2 = 3;
    }
    else {
      req.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
      req.transaction_id = CONCAT22(req.transaction_id._2_2_,duration);
      req._16_4_ = touchlink_identify_req_confirm;
      uStack_2c = CONCAT31(uStack_2c._1_3_,3);
      req.cmd_ctrl.peer_addr._0_4_ = *(undefined4 *)((int)&ieee_addr->field_0 + 2);
      uStack_2c = CONCAT13((ieee_addr->field_0).u8[1],
                           CONCAT12((ieee_addr->field_0).u8[0],(undefined2)uStack_2c));
      req.cmd_ctrl.peer_addr.u.group_addr.bcast = *(undefined2 *)((int)&ieee_addr->field_0 + 6);
      req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)arg;
      eVar2 = zcl_touchlink_identify_req(&uStack_2c);
    }
  }
  return eVar2;
}

