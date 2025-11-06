/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_comm_restart_process_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zcl_comm_restart_process_start(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = esp_log_timestamp();
  esp_log(3,"ESP_ZIGBEE_ZCL_COMMISSIONING",
          "I (%lu) %s: Restart process scheduled: startup_control = %d\n",uVar1,
          "ESP_ZIGBEE_ZCL_COMMISSIONING",DAT_0001172a);
  if (DAT_0001172a == '\0') {
    esp_zcl_comm_restart_process_install(param_1,esp_zcl_comm_restart_process_finish);
  }
  else if ((byte)(DAT_0001172a - 1U) < 3) {
    esp_zcl_comm_restart_process_leave(param_1);
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",
            "E (%lu) %s: Unsupported restart type(%d), abort the restart process\n",uVar1,
            "ESP_ZIGBEE_ZCL_COMMISSIONING",DAT_0001172a);
    zb_buf_free_func(param_1);
  }
  return;
}

