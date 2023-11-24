/*
 * Last changed at upstream commit 3a2e620f73272cd71b1255d9566d72d6c662dd1c
 * https://github.com/espressif/esp-zigbee-sdk/commit/3a2e620f73272cd71b1255d9566d72d6c662dd1c
 * Upstream date: 2023-11-24 19:53:05 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.5(909d273b)
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
    if (0x2c < uVar1) {
      return "UNKNOWN SIGNAL";
    }
    if ((&s_zb_signal_table)[uVar1 * 2] == param_1) break;
    uVar1 = uVar1 + 1;
  }
  return (&PTR__LC17_00011f74)[uVar1 * 2];
}

