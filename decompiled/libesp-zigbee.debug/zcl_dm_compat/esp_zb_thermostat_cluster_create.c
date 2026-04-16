/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_thermostat_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_attribute_list_t * esp_zb_thermostat_cluster_create(esp_zb_thermostat_cluster_cfg_t *cfg)

{
  esp_zb_attribute_list_t *peVar1;
  int16_t iStack_14;
  int16_t iStack_12;
  int16_t occupied_heating_setpoint;
  int16_t occupied_cooling_setpoint;
  
  peVar1 = (esp_zb_attribute_list_t *)thermostat_cluster_create();
  if (peVar1 != (esp_zb_attribute_list_t *)0x0) {
    iStack_12 = 0xa28;
    iStack_14 = 2000;
    if (cfg != (esp_zb_thermostat_cluster_cfg_t *)0x0) {
      iStack_12 = cfg->occupied_cooling_setpoint;
      iStack_14 = cfg->occupied_heating_setpoint;
    }
    thermostat_cluster_add_attr(peVar1,0x11,&iStack_12);
    thermostat_cluster_add_attr(peVar1,0x12,&iStack_14);
  }
  return peVar1;
}

