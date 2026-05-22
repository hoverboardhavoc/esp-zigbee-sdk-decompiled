/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_set_promiscuous
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_plat_radio_set_promiscuous(_Bool enable)

{
  int iVar1;
  
  iVar1 = esp_radio_spinel_set_promiscuous_mode(0);
  if (iVar1 == 0) {
    s_radio_ctx._176_1_ = s_radio_ctx._176_1_ & 0xfd | (byte)((enable & 1) << 1);
    return;
  }
  _esp_error_check_failed
            ("/builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
             ,0x60,"ezb_plat_radio_set_promiscuous",
             "esp_radio_spinel_set_promiscuous_mode(enable, ESP_RADIO_SPINEL_ZIGBEE)");
  return;
}

