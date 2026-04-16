/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> ha_compat.o -> esp_zb_color_dimmable_switch_clusters_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_cluster_list_t *
esp_zb_color_dimmable_switch_clusters_create(esp_zb_color_dimmable_switch_cfg_t *switch_cfg)

{
  esp_zb_cluster_list_t *peVar1;
  undefined4 uVar2;
  esp_zb_identify_cluster_cfg_t *peVar3;
  
  peVar3 = &switch_cfg->identify_cfg;
  if (switch_cfg == (esp_zb_color_dimmable_switch_cfg_t *)0x0) {
    peVar3 = (esp_zb_identify_cluster_cfg_t *)0x0;
  }
  peVar1 = (esp_zb_cluster_list_t *)esp_zb_zcl_cluster_list_create();
  uVar2 = esp_zb_basic_cluster_create(switch_cfg);
  esp_zb_cluster_list_add_basic_cluster(peVar1,uVar2,1);
  uVar2 = esp_zb_identify_cluster_create(peVar3);
  esp_zb_cluster_list_add_identify_cluster(peVar1,uVar2,1);
  uVar2 = esp_zb_zcl_attr_list_create(6);
  esp_zb_cluster_list_add_on_off_cluster(peVar1,uVar2,2);
  uVar2 = esp_zb_zcl_attr_list_create(3);
  esp_zb_cluster_list_add_identify_cluster(peVar1,uVar2,2);
  uVar2 = esp_zb_zcl_attr_list_create(8);
  esp_zb_cluster_list_add_level_cluster(peVar1,uVar2,2);
  uVar2 = esp_zb_zcl_attr_list_create(0x300);
  esp_zb_cluster_list_add_color_control_cluster(peVar1,uVar2,2);
  return peVar1;
}

