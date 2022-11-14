/*
 * Last changed at upstream commit 7abab98979b3ea95f88c7b3687103b07986e5dd5
 * https://github.com/espressif/esp-zigbee-sdk/commit/7abab98979b3ea95f88c7b3687103b07986e5dd5
 * Upstream date: 2022-11-14 17:26:16 +0800
 * Upstream subject: examples: support rename esp32h2 to esp32h4
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
  DAT_0001523d = DAT_0001523d | 8;
  iVar1 = esp_restart();
  if (iVar1 == 0) {
    esp_zb_start_no_autostart();
  }
  else {
    esp_zb_start_autostart();
  }
  return;
}

