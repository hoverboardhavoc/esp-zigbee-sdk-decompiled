/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> ha_compat.o -> esp_zb_window_covering_clusters_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_cluster_list_t * esp_zb_window_covering_clusters_create(esp_zb_window_covering_cfg_t *window)

{
  esp_zb_window_covering_cluster_cfg_t *peVar1;
  esp_zb_cluster_list_t *peVar2;
  undefined4 uVar3;
  esp_zb_scenes_cluster_cfg_t *peVar4;
  esp_zb_groups_cluster_cfg_t *peVar5;
  esp_zb_identify_cluster_cfg_t *peVar6;
  
  if (window == (esp_zb_window_covering_cfg_t *)0x0) {
    peVar1 = (esp_zb_window_covering_cluster_cfg_t *)0x0;
    peVar4 = (esp_zb_scenes_cluster_cfg_t *)0x0;
    peVar5 = (esp_zb_groups_cluster_cfg_t *)0x0;
    peVar6 = (esp_zb_identify_cluster_cfg_t *)0x0;
  }
  else {
    peVar6 = &window->identify_cfg;
    peVar5 = &window->groups_cfg;
    peVar4 = &window->scenes_cfg;
    peVar1 = &window->window_cfg;
  }
  peVar2 = (esp_zb_cluster_list_t *)esp_zb_zcl_cluster_list_create();
  uVar3 = esp_zb_basic_cluster_create(window);
  esp_zb_cluster_list_add_basic_cluster(peVar2,uVar3,1);
  uVar3 = esp_zb_identify_cluster_create(peVar6);
  esp_zb_cluster_list_add_identify_cluster(peVar2,uVar3,1);
  uVar3 = esp_zb_groups_cluster_create(peVar5);
  esp_zb_cluster_list_add_groups_cluster(peVar2,uVar3,1);
  uVar3 = esp_zb_scenes_cluster_create(peVar4);
  esp_zb_cluster_list_add_scenes_cluster(peVar2,uVar3,1);
  uVar3 = esp_zb_window_covering_cluster_create(peVar1);
  esp_zb_cluster_list_add_window_covering_cluster(peVar2,uVar3,1);
  return peVar2;
}

