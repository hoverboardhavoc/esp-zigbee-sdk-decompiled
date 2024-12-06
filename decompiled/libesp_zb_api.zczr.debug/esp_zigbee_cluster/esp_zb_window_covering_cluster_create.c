/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_cluster.o -> esp_zb_window_covering_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_window_covering_cluster_create(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 auStack_12 [6];
  
  uStack_14 = 0;
  uStack_13 = 3;
  auStack_12[0] = 4;
  uVar1 = esp_zb_zcl_attr_list_create(0x102);
  if (param_1 != (undefined1 *)0x0) {
    uStack_14 = *param_1;
    uStack_13 = param_1[1];
    auStack_12[0] = param_1[2];
  }
  esp_zb_window_covering_cluster_add_attr(uVar1,0,&uStack_14);
  esp_zb_window_covering_cluster_add_attr(uVar1,7,&uStack_13);
  esp_zb_window_covering_cluster_add_attr(uVar1,0x17,auStack_12);
  return uVar1;
}

