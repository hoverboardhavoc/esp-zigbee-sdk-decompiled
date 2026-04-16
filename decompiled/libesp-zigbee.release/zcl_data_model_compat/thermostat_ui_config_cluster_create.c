/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_data_model_compat.o -> thermostat_ui_config_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_attribute_list_t *
thermostat_ui_config_cluster_create(ezb_zcl_thermostat_ui_config_cluster_config_t *cfg)

{
  esp_zb_attribute_list_t *peVar1;
  
  peVar1 = (esp_zb_attribute_list_t *)ezb_zcl_thermostat_ui_config_create_cluster_desc(1);
  if (peVar1 != (esp_zb_attribute_list_t *)0x0) {
    peVar1 = peVar1 + 3;
  }
  return peVar1;
}

