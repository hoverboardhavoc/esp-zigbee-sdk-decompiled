/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_set_tx_power
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_plat_radio_set_tx_power(void)

{
  int iVar1;
  
  iVar1 = esp_radio_spinel_set_tx_power(0);
  if (iVar1 == 0) {
    return;
  }
  _esp_error_check_failed
            ("/builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
             ,0x6f,"ezb_plat_radio_set_tx_power",
             "esp_radio_spinel_set_tx_power(power, ESP_RADIO_SPINEL_ZIGBEE)");
  esp_radio_spinel_get_tx_power(0);
  return;
}

