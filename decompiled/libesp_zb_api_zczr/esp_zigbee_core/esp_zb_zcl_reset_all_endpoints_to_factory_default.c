/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_reset_all_endpoints_to_factory_default
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_reset_all_endpoints_to_factory_default(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = zb_zcl_get_ctx();
  pbVar1 = *(byte **)(iVar2 + 4);
  if (pbVar1 == (byte *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar3,"ESP_ZIGBEE_CORE",
                  "esp_zb_zcl_reset_all_endpoints_to_factory_default",0xa8c);
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0;
    for (iVar2 = 0; iVar2 < (int)(uint)*pbVar1; iVar2 = iVar2 + 1) {
      uVar3 = reset_endpoint_to_factory_default
                        (*(undefined4 *)(*(int *)(pbVar1 + 1) + iVar2 * 4),param_1,param_2);
    }
    if (param_1 != 0) {
      zb_zcl_reset_reporting_ctx();
    }
  }
  return uVar3;
}

