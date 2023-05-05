/*
 * Last changed at upstream commit fbb183ba2e7004edff49ad5740e127aacad3a0f5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fbb183ba2e7004edff49ad5740e127aacad3a0f5
 * Upstream date: 2023-05-05 20:30:36 +0800
 * Upstream subject: esp-zigbee-lib: update lib for support ieee802154 open source(a8dc9c7)
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
  uVar2 = esp_zb_zcl_attr_list_create(4);
  esp_zb_cluster_list_add_groups_cluster(uVar1,uVar2,2);
  return uVar1;
}

