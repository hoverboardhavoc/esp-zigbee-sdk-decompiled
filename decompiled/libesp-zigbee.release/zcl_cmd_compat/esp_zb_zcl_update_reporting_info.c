/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_update_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_zcl_update_reporting_info(esp_zb_zcl_reporting_info_t *report_info)

{
  ezb_zcl_reporting_info_t pvVar1;
  esp_err_t eVar2;
  undefined1 auStack_18 [4];
  ezb_zcl_attr_variable_t delta;
  
  if (report_info != (esp_zb_zcl_reporting_info_t *)0x0) {
    pvVar1 = report_info->info;
    eVar2 = 0x102;
    if (pvVar1 != (ezb_zcl_reporting_info_t)0x0) {
      memcpy(auStack_18,(void *)((int)&report_info->u + 8),8);
      ezb_zcl_reporting_info_update
                (pvVar1,(report_info->u).send_info.min_interval,
                 (report_info->u).send_info.max_interval,auStack_18);
      eVar2 = esp_zigbee_err_to_esp();
    }
    return eVar2;
  }
  return 0x102;
}

