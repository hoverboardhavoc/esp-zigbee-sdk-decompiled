/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_discovery.o -> touchlink_send_device_info_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

ezb_err_t touchlink_send_device_info_req(uint8_t start_index,ezb_extaddr_t *dst_addr,void *arg)

{
  ezb_err_t eVar1;
  undefined1 auStack_2c [2];
  undefined1 auStack_2a [2];
  zcl_touchlink_device_info_req_t req;
  
  memset(auStack_2c,0,0x1c);
  req.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
  req._16_4_ = touchlink_device_info_req_confirm;
  auStack_2c[0] = 3;
  req.transaction_id._0_1_ = start_index;
  req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)arg;
  memcpy(auStack_2a,dst_addr,8);
  eVar1 = zcl_touchlink_device_info_req(auStack_2c);
  return eVar1;
}

