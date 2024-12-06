/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_analog_output.o -> check_value_analog_output_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int check_value_analog_output_server(int param_1,byte *param_2)

{
  bool bVar1;
  
  if (param_1 == 0x51) {
    bVar1 = *param_2 < 2;
  }
  else {
    if (param_1 != 0x6f) {
      return 0;
    }
    bVar1 = *param_2 < 0x10;
  }
  return bVar1 - 1;
}

