/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_intrp_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_intrp_data_request(af_intrp_data_req_t *req)

{
  int iVar1;
  int extraout_a0;
  zmsg_t *msg;
  af_user_cnf_ctx_t cnf_ctx;
  
  if (req == (af_intrp_data_req_t *)0x0) {
    iVar1 = 0;
  }
  else {
    msg = (req->data).asdu;
    cnf_ctx = (af_user_cnf_ctx_t)aps_intrp_data_request();
    iVar1 = extraout_a0;
    if (extraout_a0 == 0) {
      af_data_add_cnf_cb(msg,cnf_ctx);
    }
    else if (msg != (zmsg_t *)0x0) {
      zmsg_free(msg);
    }
  }
  return iVar1;
}

