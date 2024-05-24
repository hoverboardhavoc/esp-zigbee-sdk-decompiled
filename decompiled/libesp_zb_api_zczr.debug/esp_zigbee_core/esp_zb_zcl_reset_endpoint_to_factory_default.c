/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> esp_zb_zcl_reset_endpoint_to_factory_default
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
                  "esp_zb_zcl_reset_endpoint_to_factory_default",0x42c);
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
                    "esp_zb_zcl_reset_endpoint_to_factory_default",0x433,param_1);
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

