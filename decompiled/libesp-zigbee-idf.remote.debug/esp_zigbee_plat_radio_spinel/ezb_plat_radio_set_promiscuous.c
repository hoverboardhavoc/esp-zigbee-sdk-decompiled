/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_set_promiscuous
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint ezb_plat_radio_set_promiscuous(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = esp_radio_spinel_set_promiscuous_mode(0);
  if (iVar1 == 0) {
    uVar2 = (param_1 & 1) << 1;
    s_radio_ctx[0xb0] = s_radio_ctx[0xb0] & 0xfd | (byte)uVar2;
    return uVar2;
  }
  _esp_error_check_failed
            ("/builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
             ,100,"ezb_plat_radio_set_promiscuous",
             "esp_radio_spinel_set_promiscuous_mode(enable, ESP_RADIO_SPINEL_ZIGBEE)");
  return (uint)s_radio_ctx._176_4_ >> 1 & 1;
}

