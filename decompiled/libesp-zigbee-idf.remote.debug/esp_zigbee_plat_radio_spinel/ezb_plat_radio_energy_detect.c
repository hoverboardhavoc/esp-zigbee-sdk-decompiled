/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
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
            ("/builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
             ,0xb2,"ezb_plat_radio_energy_detect",
             "esp_radio_spinel_energy_scan(channel, duration * 1000 / EZB_RADIO_SYMBOL_TIME, ESP_RADIO_SPINEL_ZIGBEE)"
            );
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

