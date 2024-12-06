/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> esp_zb_zcl_reset_endpoint_to_factory_default
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_reset_endpoint_to_factory_default(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  byte *pbVar4;
  
  iVar1 = zb_zcl_get_ctx();
  pbVar4 = *(byte **)(iVar1 + 4);
  if (pbVar4 == (byte *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar3,"ESP_ZIGBEE_CORE",
                  "esp_zb_zcl_reset_endpoint_to_factory_default",0x403);
    uVar3 = 0xffffffff;
  }
  else {
    for (iVar1 = 0; iVar1 < (int)(uint)*pbVar4; iVar1 = iVar1 + 1) {
      pbVar2 = *(byte **)(*(int *)(pbVar4 + 1) + iVar1 * 4);
      if (*pbVar2 == param_1) goto _L0;
    }
    pbVar2 = (byte *)0x0;
_L0:
    if (pbVar2 == (byte *)0x0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar3,"ESP_ZIGBEE_CORE",
                    "esp_zb_zcl_reset_endpoint_to_factory_default",0x40a,param_1);
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = reset_endpoint_to_factory_default(param_2,param_3);
      if (param_2 != 0) {
        zb_zcl_reset_reporting_ctx();
      }
    }
  }
  return uVar3;
}

