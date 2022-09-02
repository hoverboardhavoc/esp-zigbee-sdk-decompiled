/*
 * Last changed at upstream commit 161b24f200d3999849a30e5fddeac9123c04dbfe
 * https://github.com/espressif/esp-zigbee-sdk/commit/161b24f200d3999849a30e5fddeac9123c04dbfe
 * Upstream date: 2022-09-02 14:39:54 +0800
 * Upstream subject: Components: Separation of the zigbee_core_api header
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_HA_standard.o -> esp_zb_color_dimmable_light_clusters_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_color_dimmable_light_clusters_create(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = esp_zb_zcl_cluster_list_create();
  uVar2 = esp_zb_basic_cluster_create(param_1);
  esp_zb_cluster_list_add_basic_cluster(uVar1,uVar2,1);
  uVar2 = esp_zb_identify_cluster_create(param_1 + 2);
  esp_zb_cluster_list_add_identify_cluster(uVar1,uVar2,1);
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

