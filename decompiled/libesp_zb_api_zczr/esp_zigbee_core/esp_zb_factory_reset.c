/*
 * Last changed at upstream commit 6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * https://github.com/espressif/esp-zigbee-sdk/commit/6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * Upstream date: 2023-09-18 10:30:22 +0800
 * Upstream subject: esp-zigbee-sdk: add zigbee trace support and assert support(8c01f3c7)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_factory_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_factory_reset(void)

{
  int iVar1;
  
  zb_zcl_init_reporting_info();
  zb_zcl_reset_reporting_ctx();
  zb_bdb_reset_via_local_action(0);
  zb_nvram_erase();
  DAT_0001a359 = DAT_0001a359 | 8;
  iVar1 = esp_restart();
  if (iVar1 == 0) {
    esp_zb_start_no_autostart();
  }
  else {
    esp_zb_start_autostart();
  }
  return;
}

