/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> esp_zb_zcl_scenes_group_check
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
    uVar2 = 0x85;
    if (iVar1 != 0) {
      uVar2 = 0;
    }
    return uVar2;
  }
  return 0x87;
}

