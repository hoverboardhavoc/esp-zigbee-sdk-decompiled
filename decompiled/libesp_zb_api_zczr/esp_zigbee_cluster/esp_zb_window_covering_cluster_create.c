/*
 * Last changed at upstream commit 6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * https://github.com/espressif/esp-zigbee-sdk/commit/6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * Upstream date: 2023-06-09 17:12:37 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.6.2(2626797)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_window_covering_cluster_create
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

