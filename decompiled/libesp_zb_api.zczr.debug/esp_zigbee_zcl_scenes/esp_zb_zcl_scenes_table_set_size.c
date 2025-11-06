/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> esp_zb_zcl_scenes_table_set_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_scenes_table_set_size(uint param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  uint uVar3;
  
  if (esp_zb_zcl_scenes_table == (void *)0x0) {
    pvVar2 = calloc(param_1,0xc);
    esp_zb_zcl_scenes_table = pvVar2;
    if ((pvVar2 == (void *)0x0) && (param_1 != 0)) {
      uVar1 = esp_log_timestamp();
      esp_log(1,"ESP_ZIGBEE_ZCL_SCENES",
              "E (%lu) %s: %s(%d): No memory for ZCL scene table with capacity %d\n",uVar1,
              "ESP_ZIGBEE_ZCL_SCENES","esp_zb_zcl_scenes_table_set_size",0xd5,param_1);
      uVar1 = 0x101;
    }
    else {
      esp_zb_zcl_scenes_table_capacity = (undefined1)param_1;
      s_nvram_app1_data = pvVar2;
      for (uVar3 = 0; uVar3 < param_1; uVar3 = uVar3 + 1 & 0xff) {
        *(undefined2 *)((int)pvVar2 + uVar3 * 0xc + 2) = 0xffff;
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x103;
  }
  return uVar1;
}

