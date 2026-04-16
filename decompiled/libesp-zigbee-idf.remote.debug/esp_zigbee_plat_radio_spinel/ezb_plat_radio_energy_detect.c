/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_energy_detect
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_radio_energy_detect(uint8_t channel,uint32_t duration)

{
  undefined3 in_register_00002029;
  int iVar1;
  
  iVar1 = esp_radio_spinel_energy_scan
                    (CONCAT31(in_register_00002029,channel),duration * 1000 >> 4 & 0xffff,0);
  if (iVar1 == 0) {
    return 0;
  }
  _esp_error_check_failed
            ("/build/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
             ,0xae,"ezb_plat_radio_energy_detect",
             "esp_radio_spinel_energy_scan(channel, duration * 1000 / US_PER_SYMBLE, ESP_RADIO_SPINEL_ZIGBEE)"
            );
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

