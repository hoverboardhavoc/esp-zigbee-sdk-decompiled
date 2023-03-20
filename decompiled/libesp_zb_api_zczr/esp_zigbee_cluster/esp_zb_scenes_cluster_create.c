/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_scenes_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_scenes_cluster_create(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = esp_zb_zcl_attr_list_create(5);
  if (param_1 == 0) {
    esp_zb_scenes_cluster_add_attr(0,&lu8_scenes_scene_count_default_40);
    esp_zb_scenes_cluster_add_attr(uVar1,1,&lu8_scenes_current_scene_default_39);
    esp_zb_scenes_cluster_add_attr(uVar1,2,&lu16_scenes_current_group_default_38);
    esp_zb_scenes_cluster_add_attr(uVar1,3,&lu8_scenes_scene_valid_default_37);
    esp_zb_scenes_cluster_add_attr(uVar1,4,&lu8_scenes_name_support_default_36);
  }
  else {
    esp_zb_scenes_cluster_add_attr(0,param_1);
    esp_zb_scenes_cluster_add_attr(uVar1,1,param_1 + 1);
    esp_zb_scenes_cluster_add_attr(uVar1,2,param_1 + 2);
    esp_zb_scenes_cluster_add_attr(uVar1,3,param_1 + 4);
    esp_zb_scenes_cluster_add_attr(uVar1,4,param_1 + 5);
  }
  return uVar1;
}

