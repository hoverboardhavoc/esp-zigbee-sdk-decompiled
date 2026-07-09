/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_energy_detect
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 ezb_plat_radio_energy_detect(int param_1)

{
  int iVar1;
  
  iVar1 = esp_radio_spinel_energy_scan((uint)(param_1 * 1000) >> 4 & 0xffff,0);
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

