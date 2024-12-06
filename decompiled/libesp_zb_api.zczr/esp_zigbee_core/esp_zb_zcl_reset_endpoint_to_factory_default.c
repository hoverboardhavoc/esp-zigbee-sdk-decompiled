/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> esp_zb_zcl_reset_endpoint_to_factory_default
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_reset_endpoint_to_factory_default(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  byte *pbVar3;
  
  iVar1 = zb_zcl_get_ctx();
  pbVar3 = *(byte **)(iVar1 + 4);
  if (pbVar3 != (byte *)0x0) {
    for (iVar1 = 0; iVar1 < (int)(uint)*pbVar3; iVar1 = iVar1 + 1) {
      if (**(byte **)(*(int *)(pbVar3 + 1) + iVar1 * 4) == param_1) {
        uVar2 = reset_endpoint_to_factory_default(param_2,param_3);
        if (param_2 == 0) {
          return uVar2;
        }
        zb_zcl_reset_reporting_ctx();
        return uVar2;
      }
    }
  }
  return 0xffffffff;
}

