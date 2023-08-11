/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scene_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scene_resp_handler(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 1) {
    if (zcl_scenes_view_scene_resp_cb != 0) {
      esp_zcl_scenes_view_scene_response_handler();
    }
  }
  else {
    if (param_1 < 2) {
      if (param_1 == 0) {
        return;
      }
    }
    else if (param_1 < 5) {
      if (1 < param_1) {
        return;
      }
    }
    else if (param_1 == 6) {
      return;
    }
    uVar1 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC13,uVar1,"ESP_ZIGBEE_CORE",param_1);
  }
  return;
}

