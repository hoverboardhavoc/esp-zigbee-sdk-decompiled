/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_power_config_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_power_config_cluster_create(undefined2 *param_1)

{
  undefined4 uVar1;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  undefined2 auStack_12 [3];
  
  uVar1 = esp_zb_zcl_attr_list_create(1);
  if (param_1 == (undefined2 *)0x0) {
    uStack_14 = 0xffff;
    uStack_18 = 0;
    uStack_1a = 0;
    uStack_19 = 0;
    uStack_16 = 0;
    auStack_12[0] = 0;
  }
  else {
    uStack_18 = *param_1;
    uStack_1a = *(undefined1 *)(param_1 + 1);
    uStack_19 = *(undefined1 *)((int)param_1 + 3);
    uStack_16 = param_1[2];
    uStack_14 = param_1[3];
    auStack_12[0] = param_1[4];
  }
  esp_zb_power_config_cluster_add_attr(uVar1,0,&uStack_18);
  esp_zb_power_config_cluster_add_attr(uVar1,1,&uStack_1a);
  esp_zb_power_config_cluster_add_attr(uVar1,0x10,&uStack_19);
  esp_zb_power_config_cluster_add_attr(uVar1,0x11,&uStack_16);
  esp_zb_power_config_cluster_add_attr(uVar1,0x12,&uStack_14);
  esp_zb_power_config_cluster_add_attr(uVar1,0x13,auStack_12);
  return uVar1;
}

