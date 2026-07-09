/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> radio_spinel_transmit_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void radio_spinel_transmit_done(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    ezb_plat_radio_transmit_done(s_radio_ctx,0,0);
  }
  else {
    convert_to_radio_frame(param_2,s_radio_ctx);
    ezb_plat_radio_transmit_done(s_radio_ctx,s_radio_ctx,0);
  }
  return;
}

