/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> esp_zb_zcl_scenes_group_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_scenes_group_check(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 < 0xfff8) {
    iVar1 = zb_aps_is_endpoint_in_group(param_2,param_1);
    if (iVar1 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_ZCL_SCENES",&_LC3,uVar2,"ESP_ZIGBEE_ZCL_SCENES",param_1,param_2);
      uVar2 = 0x85;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_ZCL_SCENES",&_LC2,uVar2,"ESP_ZIGBEE_ZCL_SCENES",param_2);
    uVar2 = 0x87;
  }
  return uVar2;
}

