/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ha_standard.o -> esp_zb_on_off_switch_clusters_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_on_off_switch_clusters_create(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_1 + 2;
  if (param_1 == 0) {
    iVar3 = 0;
  }
  uVar1 = esp_zb_zcl_cluster_list_create();
  uVar2 = esp_zb_basic_cluster_create(param_1);
  esp_zb_cluster_list_add_basic_cluster(uVar1,uVar2,1);
  uVar2 = esp_zb_identify_cluster_create(iVar3);
  esp_zb_cluster_list_add_identify_cluster(uVar1,uVar2,1);
  uVar2 = esp_zb_groups_cluster_create(0);
  esp_zb_cluster_list_add_groups_cluster(uVar1,uVar2,2);
  uVar2 = esp_zb_scenes_cluster_create(0);
  esp_zb_cluster_list_add_scenes_cluster(uVar1,uVar2,2);
  uVar2 = esp_zb_zcl_attr_list_create(6);
  esp_zb_cluster_list_add_on_off_cluster(uVar1,uVar2,2);
  uVar2 = esp_zb_zcl_attr_list_create(3);
  esp_zb_cluster_list_add_identify_cluster(uVar1,uVar2,2);
  return uVar1;
}

