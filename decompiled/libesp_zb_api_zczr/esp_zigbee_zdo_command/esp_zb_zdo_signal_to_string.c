/*
 * Last changed at upstream commit 992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * https://github.com/espressif/esp-zigbee-sdk/commit/992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * Upstream date: 2023-07-28 17:48:58 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.7.2(e1472baa)
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
  return (&PTR__LC25_000122b0)[uVar1 * 2];
}

