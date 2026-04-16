/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_identify.o -> touchlink_send_identify_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

ezb_err_t touchlink_send_identify_req(uint16_t duration,ezb_extaddr_t *ieee_addr,void *arg)

{
  ezb_err_t eVar1;
  int iVar2;
  undefined1 auStack_2c [2];
  undefined1 auStack_2a [2];
  zcl_touchlink_identify_req_t req;
  
  memset(auStack_2c,0,0x1c);
  eVar1 = 2;
  if (ieee_addr != (ezb_extaddr_t *)0x0) {
    iVar2 = touchlink_transaction_id(0);
    eVar1 = 3;
    if (iVar2 != 0) {
      req.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
      req.duration = 0;
      req._18_2_ = 1;
      auStack_2c[0] = 3;
      req.transaction_id._0_2_ = duration;
      req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)arg;
      memcpy(auStack_2a,ieee_addr,8);
      eVar1 = zcl_touchlink_identify_req(auStack_2c);
    }
  }
  return eVar1;
}

