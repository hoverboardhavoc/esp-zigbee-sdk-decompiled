/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
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
      esp_log_write(1,"ESP_ZIGBEE_ZCL_SCENES",&_LC35,uVar1,"ESP_ZIGBEE_ZCL_SCENES",
                    "esp_zb_zcl_scenes_table_set_size",0xd5,param_1);
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

