/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_power_config_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_attribute_list_t * esp_zb_power_config_cluster_create(esp_zb_power_config_cluster_cfg_t *cfg)

{
  esp_zb_attribute_list_t *peVar1;
  uint8_t uStack_14;
  uint8_t uStack_13;
  uint16_t uStack_12;
  uint8_t main_freq;
  uint8_t main_alarm_mask;
  uint16_t main_voltage_dwell;
  
  peVar1 = (esp_zb_attribute_list_t *)power_config_cluster_create();
  if (peVar1 != (esp_zb_attribute_list_t *)0x0) {
    uStack_14 = '\0';
    uStack_13 = '\0';
    uStack_12 = 0;
    if (cfg != (esp_zb_power_config_cluster_cfg_t *)0x0) {
      uStack_14 = cfg->main_freq;
      uStack_13 = cfg->main_alarm_mask;
      uStack_12 = cfg->main_voltage_dwell;
    }
    power_config_cluster_add_attr(peVar1,1,&uStack_14);
    power_config_cluster_add_attr(peVar1,0x10,&uStack_13);
    power_config_cluster_add_attr(peVar1,0x13,&uStack_12);
  }
  return peVar1;
}

