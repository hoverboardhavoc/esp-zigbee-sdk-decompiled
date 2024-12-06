/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_ha_standard.o -> esp_zb_shade_controller_ep_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_shade_controller_ep_create(undefined1 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  uVar1 = esp_zb_ep_list_create();
  uStack_18 = CONCAT13(1,CONCAT12(1,CONCAT11(4,param_1)));
  uStack_14 = CONCAT11((byte)((uint)_uStack_14 >> 8) & 0xf0,2);
  uVar2 = esp_zb_shade_controller_clusters_create(param_2);
  esp_zb_ep_list_add_ep(uVar1,uVar2,uStack_18,uStack_14);
  return uVar1;
}

