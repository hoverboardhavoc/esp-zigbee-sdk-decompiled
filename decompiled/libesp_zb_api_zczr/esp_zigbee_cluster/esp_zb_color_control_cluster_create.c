/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_color_control_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_color_control_cluster_create(undefined2 *param_1)

{
  undefined4 uVar1;
  undefined1 uStack_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined2 uStack_16;
  undefined2 uStack_14;
  undefined2 auStack_12 [3];
  
  uVar1 = esp_zb_zcl_attr_list_create(0x300);
  if (param_1 == (undefined2 *)0x0) {
    uStack_16 = 0x616b;
    uStack_14 = 0x607d;
    uStack_19 = 1;
    uStack_17 = 1;
    uStack_18 = 0;
    auStack_12[0] = 8;
  }
  else {
    uStack_16 = *param_1;
    uStack_14 = param_1[1];
    uStack_19 = *(undefined1 *)(param_1 + 2);
    uStack_18 = *(undefined1 *)((int)param_1 + 5);
    uStack_17 = *(undefined1 *)(param_1 + 3);
    auStack_12[0] = param_1[4];
  }
  esp_zb_color_control_cluster_add_attr(uVar1,3,&uStack_16);
  esp_zb_color_control_cluster_add_attr(uVar1,4,&uStack_14);
  esp_zb_color_control_cluster_add_attr(uVar1,8,&uStack_19);
  esp_zb_color_control_cluster_add_attr(uVar1,0xf,&uStack_18);
  esp_zb_color_control_cluster_add_attr(uVar1,0x4001,&uStack_17);
  esp_zb_color_control_cluster_add_attr(uVar1,0x400a,auStack_12);
  return uVar1;
}

