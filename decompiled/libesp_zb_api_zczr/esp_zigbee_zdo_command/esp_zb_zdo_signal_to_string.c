/*
 * Last changed at upstream commit 0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * https://github.com/espressif/esp-zigbee-sdk/commit/0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * Upstream date: 2023-07-14 11:30:10 +0800
 * Upstream subject: esp-zigbee-sdk: release v0.7.1(5785a2c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_signal_to_string
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * esp_zb_zdo_signal_to_string(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (0x25 < uVar1) {
      return "UNKNOWN SIGNAL";
    }
    if ((&s_zb_signal_table)[uVar1 * 2] == param_1) break;
    uVar1 = uVar1 + 1;
  }
  return (&PTR__LC23_00011f3c)[uVar1 * 2];
}

