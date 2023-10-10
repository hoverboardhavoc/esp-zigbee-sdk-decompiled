/*
 * Last changed at upstream commit 37b2129eea9960f95d70bf2e6607337834e2750d
 * https://github.com/espressif/esp-zigbee-sdk/commit/37b2129eea9960f95d70bf2e6607337834e2750d
 * Upstream date: 2023-10-10 17:40:24 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.0(8d71c0ae)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_analog_output.o -> check_value_analog_output_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 check_value_analog_output_server(int param_1,byte *param_2)

{
  if (param_1 == 0x51) {
    if (*param_2 < 2) {
      return 0;
    }
    return 0xffffffff;
  }
  if (param_1 != 0x6f) {
    return 0;
  }
  if (*param_2 < 0x10) {
    return 0;
  }
  return 0xffffffff;
}

