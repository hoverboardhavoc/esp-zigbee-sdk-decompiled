/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> af_core.o -> af_intrp_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_intrp_data_request(af_intrp_data_req_t *req)

{
  int extraout_a0;
  zmsg_t *msg;
  af_user_cnf_ctx_t cnf_ctx;
  
  if (req != (af_intrp_data_req_t *)0x0) {
    msg = (req->data).asdu;
    cnf_ctx = (af_user_cnf_ctx_t)aps_intrp_data_request();
    if (extraout_a0 != 0) {
      if (msg == (zmsg_t *)0x0) {
        return extraout_a0;
      }
      zmsg_free(msg);
      return extraout_a0;
    }
    af_data_add_cnf_cb(msg,cnf_ctx);
  }
  return 0;
}

