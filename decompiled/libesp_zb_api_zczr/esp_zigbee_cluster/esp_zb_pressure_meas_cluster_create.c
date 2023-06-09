/*
 * Last changed at upstream commit 6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * https://github.com/espressif/esp-zigbee-sdk/commit/6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * Upstream date: 2023-06-09 17:12:37 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.6.2(2626797)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_pressure_meas_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_pressure_meas_cluster_create(undefined2 *param_1)

{
  undefined4 uVar1;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  
  uStack_18 = 0x8000;
  uStack_16 = 0x954d;
  uStack_14 = 0x7fff;
  uVar1 = esp_zb_zcl_attr_list_create(0x403);
  if (param_1 != (undefined2 *)0x0) {
    uStack_18 = *param_1;
    uStack_16 = param_1[1];
    uStack_14 = param_1[2];
  }
  esp_zb_pressure_meas_cluster_add_attr(uVar1,0,&uStack_18);
  esp_zb_pressure_meas_cluster_add_attr(uVar1,1,&uStack_16);
  esp_zb_pressure_meas_cluster_add_attr(uVar1,2,&uStack_16);
  return uVar1;
}

