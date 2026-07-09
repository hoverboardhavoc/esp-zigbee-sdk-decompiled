/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> ha_compat.o -> esp_zb_color_dimmable_light_clusters_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_color_dimmable_light_clusters_create(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (param_1 == 0) {
    iVar1 = 0;
    iVar4 = 0;
    iVar5 = 0;
    iVar6 = 0;
    iVar7 = 0;
    iVar8 = 0;
  }
  else {
    iVar8 = param_1 + 2;
    iVar7 = param_1 + 4;
    iVar6 = param_1 + 6;
    iVar5 = param_1 + 0xe;
    iVar4 = param_1 + 0xf;
    iVar1 = param_1 + 0x10;
  }
  uVar2 = esp_zb_zcl_cluster_list_create();
  uVar3 = esp_zb_basic_cluster_create(param_1);
  esp_zb_cluster_list_add_basic_cluster(uVar2,uVar3,1);
  uVar3 = esp_zb_identify_cluster_create(iVar8);
  esp_zb_cluster_list_add_identify_cluster(uVar2,uVar3,1);
  uVar3 = esp_zb_groups_cluster_create(iVar7);
  esp_zb_cluster_list_add_groups_cluster(uVar2,uVar3,1);
  uVar3 = esp_zb_scenes_cluster_create(iVar6);
  esp_zb_cluster_list_add_scenes_cluster(uVar2,uVar3,1);
  uVar3 = esp_zb_on_off_cluster_create(iVar5);
  esp_zb_cluster_list_add_on_off_cluster(uVar2,uVar3,1);
  uVar3 = esp_zb_level_cluster_create(iVar4);
  esp_zb_cluster_list_add_level_cluster(uVar2,uVar3,1);
  uVar3 = esp_zb_color_control_cluster_create(iVar1);
  esp_zb_cluster_list_add_color_control_cluster(uVar2,uVar3,1);
  return uVar2;
}

