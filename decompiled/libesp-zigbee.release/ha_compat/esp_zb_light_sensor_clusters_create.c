/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> ha_compat.o -> esp_zb_light_sensor_clusters_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_cluster_list_t * esp_zb_light_sensor_clusters_create(esp_zb_light_sensor_cfg_t *light_sensor)

{
  esp_zb_cluster_list_t *peVar1;
  undefined4 uVar2;
  esp_zb_illuminance_meas_cluster_cfg_t *peVar3;
  esp_zb_identify_cluster_cfg_t *peVar4;
  
  if (light_sensor == (esp_zb_light_sensor_cfg_t *)0x0) {
    peVar4 = (esp_zb_identify_cluster_cfg_t *)0x0;
    peVar3 = (esp_zb_illuminance_meas_cluster_cfg_t *)0x0;
  }
  else {
    peVar4 = &light_sensor->identify_cfg;
    peVar3 = &light_sensor->illuminance_cfg;
  }
  peVar1 = (esp_zb_cluster_list_t *)esp_zb_zcl_cluster_list_create();
  uVar2 = esp_zb_basic_cluster_create(light_sensor);
  esp_zb_cluster_list_add_basic_cluster(peVar1,uVar2,1);
  uVar2 = esp_zb_identify_cluster_create(peVar4);
  esp_zb_cluster_list_add_identify_cluster(peVar1,uVar2,1);
  uVar2 = esp_zb_illuminance_meas_cluster_create(peVar3);
  esp_zb_cluster_list_add_illuminance_meas_cluster(peVar1,uVar2,1);
  return peVar1;
}

