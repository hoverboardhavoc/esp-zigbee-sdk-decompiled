/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_touchlink.o -> zb_zll_identify_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zll_identify_req_handler(int param_1)

{
  if (zll_identify_req_handler != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001000e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*zll_identify_req_handler)(param_1 != 0);
    return;
  }
  return;
}

