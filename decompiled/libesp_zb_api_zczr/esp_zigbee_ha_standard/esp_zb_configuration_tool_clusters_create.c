/*
 * Last changed at upstream commit baa2c0427a754013932b7b4a3bc21cee014ddd24
 * https://github.com/espressif/esp-zigbee-sdk/commit/baa2c0427a754013932b7b4a3bc21cee014ddd24
 * Upstream date: 2023-02-10 16:01:53 +0800
 * Upstream subject: examples: provide new API for channel set(5818e5d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ha_standard.o -> esp_zb_configuration_tool_clusters_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_configuration_tool_clusters_create(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = esp_zb_zcl_cluster_list_create();
  uVar2 = esp_zb_basic_cluster_create(param_1);
  esp_zb_cluster_list_add_basic_cluster(uVar1,uVar2,1);
  uVar2 = esp_zb_identify_cluster_create(param_1 + 2);
  esp_zb_cluster_list_add_identify_cluster(uVar1,uVar2,1);
  uVar2 = esp_zb_zcl_attr_list_create(3);
  esp_zb_cluster_list_add_identify_cluster(uVar1,uVar2,2);
  uVar2 = esp_zb_groups_cluster_create(param_1 + 4);
  esp_zb_cluster_list_add_groups_cluster(uVar1,uVar2,1);
  uVar2 = esp_zb_scenes_cluster_create(param_1 + 6);
  esp_zb_cluster_list_add_scenes_cluster(uVar1,uVar2,1);
  uVar2 = esp_zb_on_off_cluster_create(param_1 + 0xc);
  esp_zb_cluster_list_add_on_off_cluster(uVar1,uVar2,1);
  uVar2 = esp_zb_level_cluster_create(param_1 + 0xd);
  esp_zb_cluster_list_add_level_cluster(uVar1,uVar2,1);
  uVar2 = esp_zb_color_control_cluster_create(param_1 + 0xe);
  esp_zb_cluster_list_add_color_control_cluster(uVar1,uVar2,1);
  return uVar1;
}

