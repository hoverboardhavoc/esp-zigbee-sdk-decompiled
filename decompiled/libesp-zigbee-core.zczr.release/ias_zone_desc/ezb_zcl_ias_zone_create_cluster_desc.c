/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone_desc.o -> ezb_zcl_ias_zone_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: server_default_cfg */
/* WARNING: Unknown calling convention */

ezb_zcl_cluster_desc_t ezb_zcl_ias_zone_create_cluster_desc(void *cluster_cfg,uint8_t role_mask)

{
  ezb_zcl_cluster_desc_t cluster_desc;
  undefined *puVar1;
  undefined1 auStack_28 [2];
  undefined2 uStack_26;
  ezb_zcl_ias_zone_cluster_server_config_t server_default_cfg;
  
  server_default_cfg.zone_status = 0;
  server_default_cfg._6_2_ = 0;
  auStack_28[0] = 0;
  uStack_26 = 0;
  server_default_cfg.zone_state = '\0';
  server_default_cfg._1_1_ = 0;
  server_default_cfg.ias_cie_address._0_4_ = 0;
  server_default_cfg.ias_cie_address._4_1_ = 0xff;
  cluster_desc = (ezb_zcl_cluster_desc_t)zcl_create_cluster_desc(0x500,0);
  if (cluster_desc != (ezb_zcl_cluster_desc_t)0x0) {
    if ((role_mask & 1) == 0) {
      puVar1 = &ezb_zcl_ias_zone_cluster_client_init;
    }
    else {
      puVar1 = &ezb_zcl_ias_zone_cluster_server_init;
    }
    *(undefined **)((int)cluster_desc + 8) = puVar1;
    if (cluster_cfg != (void *)0x0) {
      memcpy(auStack_28,cluster_cfg,0x18);
    }
    zcl_cluster_desc_add_revision_attr(cluster_desc,1);
    if ((role_mask & 1) != 0) {
      ezb_zcl_ias_zone_cluster_desc_add_attr(cluster_desc,0,auStack_28);
      ezb_zcl_ias_zone_cluster_desc_add_attr(cluster_desc,1,&uStack_26);
      ezb_zcl_ias_zone_cluster_desc_add_attr(cluster_desc,2,&server_default_cfg);
      ezb_zcl_ias_zone_cluster_desc_add_attr(cluster_desc,0x10,&server_default_cfg.zone_status);
      ezb_zcl_ias_zone_cluster_desc_add_attr
                (cluster_desc,0x11,(void *)((int)&server_default_cfg.ias_cie_address + 4));
      ezb_zcl_cluster_desc_add_manuf_attr(cluster_desc,0xeff0,0,0x40,0x131b,0);
    }
  }
  return cluster_desc;
}

