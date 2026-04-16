/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> metering_desc.o -> ezb_zcl_metering_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: server_default_cfg */
/* WARNING: Unknown calling convention */

ezb_zcl_cluster_desc_t ezb_zcl_metering_create_cluster_desc(void *cluster_cfg,uint8_t role_mask)

{
  ezb_zcl_cluster_desc_t cluster_desc;
  undefined *puVar1;
  undefined4 local_20;
  ezb_zcl_metering_cluster_server_config_t server_default_cfg;
  
  local_20 = 0;
  server_default_cfg.current_summation_delivered._0_4_ = 0;
  server_default_cfg.current_summation_delivered._4_1_ = 0;
  server_default_cfg.current_summation_delivered._5_1_ = 0;
  server_default_cfg.current_summation_delivered._6_1_ = 0;
  server_default_cfg.current_summation_delivered._7_1_ = 0;
  cluster_desc = (ezb_zcl_cluster_desc_t)zcl_create_cluster_desc(0x702,0);
  if (cluster_desc != (ezb_zcl_cluster_desc_t)0x0) {
    if ((role_mask & 1) == 0) {
      puVar1 = &ezb_zcl_metering_cluster_client_init;
    }
    else {
      puVar1 = &ezb_zcl_metering_cluster_server_init;
    }
    *(undefined **)((int)cluster_desc + 8) = puVar1;
    if (cluster_cfg != (void *)0x0) {
      memcpy(&local_20,cluster_cfg,0x10);
    }
    zcl_cluster_desc_add_revision_attr(cluster_desc,3);
    if ((role_mask & 1) != 0) {
      ezb_zcl_metering_cluster_desc_add_attr(cluster_desc,0,&local_20);
      ezb_zcl_metering_cluster_desc_add_attr
                (cluster_desc,0x200,
                 (void *)((int)&server_default_cfg.current_summation_delivered + 4));
      ezb_zcl_metering_cluster_desc_add_attr
                (cluster_desc,0x300,
                 (void *)((int)&server_default_cfg.current_summation_delivered + 5));
      ezb_zcl_metering_cluster_desc_add_attr
                (cluster_desc,0x303,
                 (void *)((int)&server_default_cfg.current_summation_delivered + 6));
      ezb_zcl_metering_cluster_desc_add_attr
                (cluster_desc,0x306,
                 (void *)((int)&server_default_cfg.current_summation_delivered + 7));
    }
  }
  return cluster_desc;
}

