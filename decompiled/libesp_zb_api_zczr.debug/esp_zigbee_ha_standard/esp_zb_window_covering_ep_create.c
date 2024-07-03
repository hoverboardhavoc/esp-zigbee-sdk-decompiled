/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_ha_standard.o -> esp_zb_window_covering_ep_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_window_covering_ep_create(undefined1 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  uVar1 = esp_zb_ep_list_create();
  uStack_18 = CONCAT13(2,CONCAT12(1,CONCAT11(4,param_1)));
  uStack_14 = CONCAT11((byte)((uint)_uStack_14 >> 8) & 0xf0,2);
  uVar2 = esp_zb_window_covering_clusters_create(param_2);
  esp_zb_ep_list_add_ep(uVar1,uVar2,uStack_18,uStack_14);
  return uVar1;
}

