/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> esp_zb_zdo_signal_to_string
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
    if (0x21 < uVar1) {
      return "UNKNOWN SIGNAL";
    }
    if ((&s_zb_signal_table)[uVar1 * 2] == param_1) break;
    uVar1 = uVar1 + 1;
  }
  return (&PTR__LC29_000130ac)[uVar1 * 2];
}

