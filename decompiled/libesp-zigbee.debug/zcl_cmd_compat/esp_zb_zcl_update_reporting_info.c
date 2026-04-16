/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_update_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_zcl_update_reporting_info(esp_zb_zcl_reporting_info_t *report_info)

{
  esp_err_t eVar1;
  ezb_zcl_attr_variable_t delta;
  
  if (report_info == (esp_zb_zcl_reporting_info_t *)0x0) {
    eVar1 = 0x102;
  }
  else if (report_info->info == (ezb_zcl_reporting_info_t)0x0) {
    eVar1 = 0x102;
  }
  else {
    ezb_zcl_reporting_info_update
              ((report_info->u).send_info.min_interval,(report_info->u).send_info.max_interval);
    eVar1 = esp_zigbee_err_to_esp();
  }
  return eVar1;
}

