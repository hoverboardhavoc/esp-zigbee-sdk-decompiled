/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
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
      esp_log(2,"ESP_ZIGBEE_ZCL_SCENES",
              "W (%lu) %s: Endpoint(0x%x) not found in the group table for group ID(0x%x)\n",uVar2,
              "ESP_ZIGBEE_ZCL_SCENES",param_1,param_2);
      uVar2 = 0x85;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log(2,"ESP_ZIGBEE_ZCL_SCENES","W (%lu) %s: Group ID(0x%x) is invalid\n",uVar2,
            "ESP_ZIGBEE_ZCL_SCENES",param_2);
    uVar2 = 0x87;
  }
  return uVar2;
}

