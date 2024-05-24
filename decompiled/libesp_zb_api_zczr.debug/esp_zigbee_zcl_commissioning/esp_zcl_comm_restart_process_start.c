/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_comm_restart_process_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zcl_comm_restart_process_start(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = esp_log_timestamp();
  esp_log_write(3,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_L0,uVar1,"ESP_ZIGBEE_ZCL_COMMISSIONING",
                DAT_000117aa);
  if (DAT_000117aa == '\0') {
    esp_zcl_comm_restart_process_install(param_1,esp_zcl_comm_restart_process_finish);
  }
  else if ((byte)(DAT_000117aa - 1U) < 3) {
    esp_zcl_comm_restart_process_leave(param_1);
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_LC10,uVar1,"ESP_ZIGBEE_ZCL_COMMISSIONING",
                  DAT_000117aa);
    zb_buf_free_func(param_1);
  }
  return;
}

