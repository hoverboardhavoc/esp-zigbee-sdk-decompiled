/*
 * Last changed at upstream commit 503c5e49627f84174ce142bf784c3f01532fb5c9
 * https://github.com/espressif/esp-zigbee-sdk/commit/503c5e49627f84174ce142bf784c3f01532fb5c9
 * Upstream date: 2023-06-05 10:37:46 +0800
 * Upstream subject: esp-zigbee-sdk: optimize the zigbee cluster implementation(0f0acd4)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_power_config_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_power_config_cluster_create(undefined2 *param_1)

{
  undefined4 uVar1;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined2 auStack_12 [3];
  
  uVar1 = esp_zb_zcl_attr_list_create(1);
  if (param_1 == (undefined2 *)0x0) {
    auStack_12[0] = 0;
    uStack_13 = 0;
    uStack_14 = 0;
    uStack_16 = 0;
    uStack_18 = 0xffff;
    uStack_1a = 0;
  }
  else {
    auStack_12[0] = *param_1;
    uStack_13 = *(undefined1 *)(param_1 + 1);
    uStack_14 = *(undefined1 *)((int)param_1 + 3);
    uStack_16 = param_1[2];
    uStack_18 = param_1[3];
    uStack_1a = param_1[4];
  }
  esp_zb_power_config_cluster_add_attr(uVar1,0,auStack_12);
  esp_zb_power_config_cluster_add_attr(uVar1,1,&uStack_13);
  esp_zb_power_config_cluster_add_attr(uVar1,0x10,&uStack_14);
  esp_zb_power_config_cluster_add_attr(uVar1,0x11,&uStack_16);
  esp_zb_power_config_cluster_add_attr(uVar1,0x12,&uStack_18);
  esp_zb_power_config_cluster_add_attr(uVar1,0x13,&uStack_1a);
  return uVar1;
}

