/*
 * Last changed at upstream commit 3a2e620f73272cd71b1255d9566d72d6c662dd1c
 * https://github.com/espressif/esp-zigbee-sdk/commit/3a2e620f73272cd71b1255d9566d72d6c662dd1c
 * Upstream date: 2023-11-24 19:53:05 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.5(909d273b)
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
  DAT_0001bd79 = DAT_0001bd79 | 8;
  iVar1 = esp_restart();
  if (iVar1 == 0) {
    esp_zb_start_no_autostart();
  }
  else {
    esp_zb_start_autostart();
  }
  return;
}

