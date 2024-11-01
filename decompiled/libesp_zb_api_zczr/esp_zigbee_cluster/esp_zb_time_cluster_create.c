/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_time_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_time_cluster_create(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 uStack_15;
  undefined4 auStack_14 [2];
  
  uVar1 = esp_zb_zcl_attr_list_create(10);
  if (param_1 == (undefined4 *)0x0) {
    auStack_14[0] = 0xffffffff;
    uStack_15 = 0;
  }
  else {
    auStack_14[0] = *param_1;
    uStack_15 = *(undefined1 *)(param_1 + 1);
  }
  esp_zb_time_cluster_add_attr(uVar1,0,auStack_14);
  esp_zb_time_cluster_add_attr(uVar1,1,&uStack_15);
  return uVar1;
}

