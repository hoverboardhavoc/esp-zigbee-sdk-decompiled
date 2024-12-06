/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_ha_standard.o -> esp_zb_on_off_switch_clusters_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_on_off_switch_clusters_create(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + 2;
  }
  uVar2 = esp_zb_zcl_cluster_list_create();
  uVar3 = esp_zb_basic_cluster_create(param_1);
  esp_zb_cluster_list_add_basic_cluster(uVar2,uVar3,1);
  uVar3 = esp_zb_identify_cluster_create(iVar1);
  esp_zb_cluster_list_add_identify_cluster(uVar2,uVar3,1);
  uVar3 = esp_zb_groups_cluster_create(0);
  esp_zb_cluster_list_add_groups_cluster(uVar2,uVar3,2);
  uVar3 = esp_zb_scenes_cluster_create(0);
  esp_zb_cluster_list_add_scenes_cluster(uVar2,uVar3,2);
  uVar3 = esp_zb_zcl_attr_list_create(6);
  esp_zb_cluster_list_add_on_off_cluster(uVar2,uVar3,2);
  uVar3 = esp_zb_zcl_attr_list_create(3);
  esp_zb_cluster_list_add_identify_cluster(uVar2,uVar3,2);
  return uVar2;
}

