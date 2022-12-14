/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ota.o -> esp_zb_ota_server_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_ota_server_start(void)

{
  undefined4 uVar1;
  
  uVar1 = esp_log_timestamp();
  esp_log_write(3,"ESP_ZIGBEE_OTA",&_LC1,uVar1,"ESP_ZIGBEE_OTA");
  esp_zb_scheduler_alarm(ota_insert_file,0,20000);
  return;
}

