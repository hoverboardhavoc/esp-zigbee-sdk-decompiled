/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_HA_standard.o -> esp_zb_scenes_cluster_create
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
    esp_zb_cluster_add_attr(0,&lu8_scenes_scene_count_default_12);
    esp_zb_cluster_add_attr(uVar1,1,&lu8_scenes_current_scene_default_11);
    esp_zb_cluster_add_attr(uVar1,2,&lu16_scenes_current_group_default_10);
    esp_zb_cluster_add_attr(uVar1,3,&lu8_scenes_scene_valid_default_9);
    esp_zb_cluster_add_attr(uVar1,4,&lu8_scenes_name_support_default_8);
  }
  else {
    esp_zb_cluster_add_attr(0,param_1);
    esp_zb_cluster_add_attr(uVar1,1,param_1 + 1);
    esp_zb_cluster_add_attr(uVar1,2,param_1 + 2);
    esp_zb_cluster_add_attr(uVar1,3,param_1 + 4);
    esp_zb_cluster_add_attr(uVar1,4,param_1 + 5);
  }
  return uVar1;
}

