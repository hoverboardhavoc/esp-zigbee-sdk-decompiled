/*
 * Last changed at upstream commit d7e241034cb0adc2116988a320badb285c391de3
 * https://github.com/espressif/esp-zigbee-sdk/commit/d7e241034cb0adc2116988a320badb285c391de3
 * Upstream date: 2024-02-06 17:30:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.1(0cd72dc5)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_table_clear_by_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_zcl_scenes_table_clear_by_index(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 < 0x10) {
    if ((&DAT_00018df6)[param_1 * 6] != -1) {
      zb_zcl_scenes_set_scene_count((&esp_zb_zcl_scenes_table)[param_1 * 0xc],0xffffffff);
      device_scenes_table_record_free(param_1 & 0xff);
    }
    iVar1 = zb_nvram_write_dataset(9);
    if (iVar1 != 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC46,uVar2,"ESP_ZIGBEE_CORE",
                    "esp_zb_zcl_scenes_table_clear_by_index",0x400);
      iVar1 = -1;
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC82,uVar2,"ESP_ZIGBEE_CORE",
                  "esp_zb_zcl_scenes_table_clear_by_index",0x3fb,param_1);
    iVar1 = 0x102;
  }
  return iVar1;
}

