/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_clear_src_match_entries
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_plat_radio_clear_src_match_entries(_Bool is_short)

{
  undefined3 in_register_00002029;
  int iVar1;
  
  if (CONCAT31(in_register_00002029,is_short) != 0) {
    iVar1 = esp_radio_spinel_clear_short_entries(0);
    if (iVar1 == 0) {
      return;
    }
    _esp_error_check_failed
              ("/builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
               ,0xd5,"ezb_plat_radio_clear_src_match_entries",
               "esp_radio_spinel_clear_short_entries(ESP_RADIO_SPINEL_ZIGBEE)");
  }
  iVar1 = esp_radio_spinel_clear_extended_entries(0);
  if (iVar1 == 0) {
    return;
  }
  _esp_error_check_failed
            ("/builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
             ,0xd7,"ezb_plat_radio_clear_src_match_entries",
             "esp_radio_spinel_clear_extended_entries(ESP_RADIO_SPINEL_ZIGBEE)");
  return;
}

