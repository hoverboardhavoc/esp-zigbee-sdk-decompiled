/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> ha_compat.o -> esp_zb_window_covering_ep_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: endpoint_config */
/* WARNING: Unknown calling convention */

esp_zb_ep_list_t *
esp_zb_window_covering_ep_create(uint8_t endpoint_id,esp_zb_window_covering_cfg_t *window_covering)

{
  esp_zb_ep_list_t *peVar1;
  esp_zb_cluster_list_t *peVar2;
  undefined4 uStack_18;
  esp_zb_endpoint_config_t endpoint_config;
  
  peVar1 = (esp_zb_ep_list_t *)esp_zb_ep_list_create();
  uStack_18 = CONCAT22(0x104,(ushort)endpoint_id);
  peVar2 = esp_zb_window_covering_clusters_create(window_covering);
  esp_zb_ep_list_add_ep(peVar1,peVar2,uStack_18,0x202);
  return peVar1;
}

