/*
 * Last changed at upstream commit 9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * https://github.com/espressif/esp-zigbee-sdk/commit/9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * Upstream date: 2024-01-12 14:14:49 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.8(0e41638c)
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
  DAT_0001e6dd = DAT_0001e6dd | 8;
  iVar1 = esp_restart();
  if (iVar1 == 0) {
    esp_zb_start_no_autostart();
  }
  else {
    esp_zb_start_autostart();
  }
  return;
}

