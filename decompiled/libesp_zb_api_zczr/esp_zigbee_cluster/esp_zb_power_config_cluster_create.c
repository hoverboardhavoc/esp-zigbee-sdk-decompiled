/*
 * Last changed at upstream commit 6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * https://github.com/espressif/esp-zigbee-sdk/commit/6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * Upstream date: 2023-04-06 16:02:34 +0800
 * Upstream subject: example: support single C6 gateway example and other API support(a1884f9)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_power_config_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_power_config_cluster_create(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = esp_zb_zcl_attr_list_create(1);
  if (param_1 == 0) {
    esp_zb_power_config_cluster_add_attr(0,&lu16_main_voltage_default_51);
    esp_zb_power_config_cluster_add_attr(uVar1,1,&lu8_main_freq_default_50);
    esp_zb_power_config_cluster_add_attr(uVar1,0x10,&lu8_main_alarm_mask_49);
    esp_zb_power_config_cluster_add_attr(uVar1,0x11,&lu16_main_voltage_min_48);
    esp_zb_power_config_cluster_add_attr(uVar1,0x12,&lu16_main_voltage_max_47);
    esp_zb_power_config_cluster_add_attr(uVar1,0x13,&lu16_main_voltage_dwell_46);
  }
  else {
    esp_zb_power_config_cluster_add_attr(0,param_1);
    esp_zb_power_config_cluster_add_attr(uVar1,1,param_1 + 2);
    esp_zb_power_config_cluster_add_attr(uVar1,0x10,param_1 + 3);
    esp_zb_power_config_cluster_add_attr(uVar1,0x11,param_1 + 4);
    esp_zb_power_config_cluster_add_attr(uVar1,0x12,param_1 + 6);
    esp_zb_power_config_cluster_add_attr(uVar1,0x13,param_1 + 8);
  }
  return uVar1;
}

