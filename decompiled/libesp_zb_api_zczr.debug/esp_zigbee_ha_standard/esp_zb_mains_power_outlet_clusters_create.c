/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_ha_standard.o -> esp_zb_mains_power_outlet_clusters_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_mains_power_outlet_clusters_create(int param_1)

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
  return uVar1;
}

