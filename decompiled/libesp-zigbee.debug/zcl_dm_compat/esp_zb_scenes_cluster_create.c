/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_scenes_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_attribute_list_t * esp_zb_scenes_cluster_create(esp_zb_scenes_cluster_cfg_t *cfg)

{
  uint8_t uVar1;
  esp_zb_attribute_list_t *peVar2;
  
  if (cfg != (esp_zb_scenes_cluster_cfg_t *)0x0) {
    uVar1 = esp_zb_zcl_scenes_table_get_size();
    cfg->scenes_count = uVar1;
  }
  peVar2 = (esp_zb_attribute_list_t *)scenes_cluster_create(cfg);
  return peVar2;
}

