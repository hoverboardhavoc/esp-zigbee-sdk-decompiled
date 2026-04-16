/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> ha_compat.o -> esp_zb_temperature_sensor_clusters_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_cluster_list_t *
esp_zb_temperature_sensor_clusters_create(esp_zb_temperature_sensor_cfg_t *temperature_sensor)

{
  esp_zb_temperature_meas_cluster_cfg_t *peVar1;
  esp_zb_cluster_list_t *peVar2;
  undefined4 uVar3;
  esp_zb_identify_cluster_cfg_t *peVar4;
  
  if (temperature_sensor == (esp_zb_temperature_sensor_cfg_t *)0x0) {
    peVar1 = (esp_zb_temperature_meas_cluster_cfg_t *)0x0;
    peVar4 = (esp_zb_identify_cluster_cfg_t *)0x0;
  }
  else {
    peVar4 = &temperature_sensor->identify_cfg;
    peVar1 = &temperature_sensor->temp_meas_cfg;
  }
  peVar2 = (esp_zb_cluster_list_t *)esp_zb_zcl_cluster_list_create();
  uVar3 = esp_zb_basic_cluster_create(temperature_sensor);
  esp_zb_cluster_list_add_basic_cluster(peVar2,uVar3,1);
  uVar3 = esp_zb_identify_cluster_create(peVar4);
  esp_zb_cluster_list_add_identify_cluster(peVar2,uVar3,1);
  uVar3 = esp_zb_temperature_meas_cluster_create(peVar1);
  esp_zb_cluster_list_add_temperature_meas_cluster(peVar2,uVar3,1);
  uVar3 = esp_zb_zcl_attr_list_create(3);
  esp_zb_cluster_list_add_identify_cluster(peVar2,uVar3,2);
  return peVar2;
}

