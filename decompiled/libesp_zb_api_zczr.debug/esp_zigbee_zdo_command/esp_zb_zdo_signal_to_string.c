/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zdo_command.o -> esp_zb_zdo_signal_to_string
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
    if (0x29 < uVar1) {
      return "UNKNOWN SIGNAL";
    }
    if ((&s_zb_signal_table)[uVar1 * 2] == param_1) break;
    uVar1 = uVar1 + 1;
  }
  return (&PTR__LC18_0001202c)[uVar1 * 2];
}

