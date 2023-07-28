/*
 * Last changed at upstream commit 992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * https://github.com/espressif/esp-zigbee-sdk/commit/992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * Upstream date: 2023-07-28 17:48:58 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.7.2(e1472baa)
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
  DAT_000181c9 = DAT_000181c9 | 8;
  iVar1 = esp_restart();
  if (iVar1 == 0) {
    esp_zb_start_no_autostart();
  }
  else {
    esp_zb_start_autostart();
  }
  return;
}

