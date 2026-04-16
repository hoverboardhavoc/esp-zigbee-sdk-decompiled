/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> custom.o -> ezb_zcl_custom_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_cluster_desc_t
ezb_zcl_custom_create_cluster_desc(ezb_zcl_custom_cluster_config_t *cluster_cfg,uint8_t role_mask)

{
  ezb_zcl_custom_cluster_config_t *peVar1;
  
  peVar1 = cluster_cfg;
  if (cluster_cfg != (ezb_zcl_custom_cluster_config_t *)0x0) {
    if ((short)cluster_cfg->cluster_id < 0) {
      peVar1 = (ezb_zcl_custom_cluster_config_t *)zcl_create_cluster_desc(0);
      peVar1->deinit_func = cluster_cfg->init_func;
    }
    else {
      peVar1 = (ezb_zcl_custom_cluster_config_t *)0x0;
    }
  }
  return peVar1;
}

