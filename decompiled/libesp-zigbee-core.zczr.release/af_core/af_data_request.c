/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_core.o -> af_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_data_request(af_data_req_t *req)

{
  int extraout_a0;
  zmsg_t *msg;
  af_user_cnf_ctx_t cnf_ctx;
  
  if (req == (af_data_req_t *)0x0) {
    req = (af_data_req_t *)__assert_func(0,0,0);
  }
  msg = (req->data).asdu;
  cnf_ctx = (af_user_cnf_ctx_t)aps_apsde_data_request();
  if (extraout_a0 == 0) {
    af_data_add_cnf_cb(msg,cnf_ctx);
  }
  return extraout_a0;
}

