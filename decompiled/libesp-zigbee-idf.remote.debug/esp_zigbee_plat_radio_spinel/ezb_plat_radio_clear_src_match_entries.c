/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_clear_src_match_entries
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_plat_radio_clear_src_match_entries(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = esp_radio_spinel_clear_short_entries(0);
    if (iVar1 == 0) {
      return 0;
    }
    _esp_error_check_failed
              ("/builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
               ,0xf2,"ezb_plat_radio_clear_src_match_entries",
               "esp_radio_spinel_clear_short_entries(ESP_RADIO_SPINEL_ZIGBEE)");
  }
  iVar1 = esp_radio_spinel_clear_extended_entries(0);
  if (iVar1 == 0) {
    return 0;
  }
  _esp_error_check_failed
            ("/builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
             ,0xf4,"ezb_plat_radio_clear_src_match_entries",
             "esp_radio_spinel_clear_extended_entries(ESP_RADIO_SPINEL_ZIGBEE)");
  return 7;
}

