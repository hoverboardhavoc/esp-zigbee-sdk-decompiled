/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_ha_standard.o -> esp_zb_mains_power_outlet_clusters_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_mains_power_outlet_clusters_create(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 == 0) {
    iVar1 = 0;
    iVar4 = 0;
    iVar5 = 0;
    iVar6 = 0;
  }
  else {
    iVar6 = param_1 + 2;
    iVar5 = param_1 + 4;
    iVar4 = param_1 + 6;
    iVar1 = param_1 + 0xc;
  }
  uVar2 = esp_zb_zcl_cluster_list_create();
  uVar3 = esp_zb_basic_cluster_create(param_1);
  esp_zb_cluster_list_add_basic_cluster(uVar2,uVar3,1);
  uVar3 = esp_zb_identify_cluster_create(iVar6);
  esp_zb_cluster_list_add_identify_cluster(uVar2,uVar3,1);
  uVar3 = esp_zb_groups_cluster_create(iVar5);
  esp_zb_cluster_list_add_groups_cluster(uVar2,uVar3,1);
  uVar3 = esp_zb_scenes_cluster_create(iVar4);
  esp_zb_cluster_list_add_scenes_cluster(uVar2,uVar3,1);
  uVar3 = esp_zb_on_off_cluster_create(iVar1);
  esp_zb_cluster_list_add_on_off_cluster(uVar2,uVar3,1);
  return uVar2;
}

