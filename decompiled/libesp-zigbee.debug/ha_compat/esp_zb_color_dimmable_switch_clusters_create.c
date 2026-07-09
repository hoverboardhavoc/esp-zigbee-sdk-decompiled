/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> ha_compat.o -> esp_zb_color_dimmable_switch_clusters_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_color_dimmable_switch_clusters_create(int param_1)

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
  uVar3 = esp_zb_zcl_attr_list_create(6);
  esp_zb_cluster_list_add_on_off_cluster(uVar2,uVar3,2);
  uVar3 = esp_zb_zcl_attr_list_create(3);
  esp_zb_cluster_list_add_identify_cluster(uVar2,uVar3,2);
  uVar3 = esp_zb_zcl_attr_list_create(8);
  esp_zb_cluster_list_add_level_cluster(uVar2,uVar3,2);
  uVar3 = esp_zb_zcl_attr_list_create(0x300);
  esp_zb_cluster_list_add_color_control_cluster(uVar2,uVar3,2);
  return uVar2;
}

