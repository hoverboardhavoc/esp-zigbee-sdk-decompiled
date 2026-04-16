/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_factory_new.o -> touchlink_send_factory_new_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_send_factory_new_req(ezb_extaddr_t *ieee_addr,void *arg)

{
  ezb_err_t eVar1;
  int *piVar2;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [2];
  zcl_touchlink_reset_to_factory_new_req_t req;
  
  memset(auStack_28,0,0x18);
  eVar1 = 2;
  if (ieee_addr != (ezb_extaddr_t *)0x0) {
    piVar2 = (int *)touchlink_transaction_get();
    eVar1 = 3;
    if (*piVar2 != 0) {
      req.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
      req.transaction_id = 0x10000;
      auStack_28[0] = 3;
      req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)arg;
      memcpy(auStack_26,ieee_addr,8);
      eVar1 = zcl_touchlink_reset_to_factory_new_req(auStack_28);
    }
  }
  return eVar1;
}

