/*
 * Last changed at upstream commit 0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * https://github.com/espressif/esp-zigbee-sdk/commit/0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * Upstream date: 2024-01-19 19:10:32 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.9(b7135493)
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
    if ((&DAT_00017822)[param_1 * 6] != -1) {
      zb_zcl_scenes_set_scene_count((&esp_zb_zcl_scenes_table)[param_1 * 0xc],0xffffffff);
      device_scenes_table_record_free(param_1 & 0xff);
    }
    iVar1 = zb_nvram_write_dataset(9);
    if (iVar1 != 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC37,uVar2,"ESP_ZIGBEE_CORE",
                    "esp_zb_zcl_scenes_table_clear_by_index",0x40e);
      iVar1 = -1;
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC71,uVar2,"ESP_ZIGBEE_CORE",
                  "esp_zb_zcl_scenes_table_clear_by_index",0x409,param_1);
    iVar1 = 0x102;
  }
  return iVar1;
}

