/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> esp_zb_zcl_scenes_table_clear_by_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_zcl_scenes_table_clear_by_index(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 < esp_zb_zcl_scenes_table_capacity) {
    if (*(short *)(param_1 * 0xc + esp_zb_zcl_scenes_table + 2) != -1) {
      device_scenes_table_record_free(param_1 & 0xff);
    }
    iVar1 = zb_nvram_write_dataset(9);
    if (iVar1 != 0) {
      uVar2 = esp_log_timestamp();
      esp_log(1,"ESP_ZIGBEE_ZCL_SCENES","E (%lu) %s: %s(%d): Failed to write scene table\n",uVar2,
              "ESP_ZIGBEE_ZCL_SCENES","esp_zb_zcl_scenes_table_clear_by_index",0x2c9);
      iVar1 = -1;
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_SCENES","E (%lu) %s: %s(%d): Index(%d) out of range\n",uVar2,
            "ESP_ZIGBEE_ZCL_SCENES","esp_zb_zcl_scenes_table_clear_by_index",0x2c4,param_1);
    iVar1 = 0x102;
  }
  return iVar1;
}

