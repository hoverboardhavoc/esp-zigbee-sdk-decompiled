/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_data_request(af_data_req_t *req)

{
  int unaff_s1;
  int extraout_a0;
  zmsg_t *unaff_s2;
  af_user_cnf_ctx_t cnf_ctx;
  
  if (req == (af_data_req_t *)0x0) {
    cnf_ctx = (af_user_cnf_ctx_t)
              __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_core.c",0xd0,
                            "af_data_request",&_LC5);
  }
  else {
    unaff_s2 = (req->data).asdu;
    cnf_ctx = (af_user_cnf_ctx_t)aps_apsde_data_request();
    unaff_s1 = extraout_a0;
    if (extraout_a0 != 0) {
      return extraout_a0;
    }
  }
  af_data_add_cnf_cb(unaff_s2,cnf_ctx);
  return unaff_s1;
}

