/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control_desc.o -> ezb_zcl_poll_control_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: server_default_cfg */
/* WARNING: Unknown calling convention */

ezb_zcl_cluster_desc_t ezb_zcl_poll_control_create_cluster_desc(void *cluster_cfg,uint8_t role_mask)

{
  ezb_zcl_cluster_desc_t cluster_desc;
  undefined *puVar1;
  undefined4 uStack_1c;
  ezb_zcl_poll_control_cluster_server_config_t server_default_cfg;
  
  uStack_1c = 0x3840;
  server_default_cfg.check_in_interval = 0x14;
  server_default_cfg.long_poll_interval._0_2_ = 2;
  server_default_cfg.long_poll_interval._2_2_ = 0x28;
  cluster_desc = (ezb_zcl_cluster_desc_t)zcl_create_cluster_desc(0x20,0);
  if (cluster_desc != (ezb_zcl_cluster_desc_t)0x0) {
    if ((role_mask & 1) == 0) {
      puVar1 = &ezb_zcl_poll_control_cluster_client_init;
    }
    else {
      puVar1 = &ezb_zcl_poll_control_cluster_server_init;
    }
    *(undefined **)((int)cluster_desc + 8) = puVar1;
    if (cluster_cfg != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
      uStack_1c = *cluster_cfg;
      server_default_cfg.check_in_interval = *(uint32_t *)((int)cluster_cfg + 4);
      server_default_cfg.long_poll_interval._0_2_ = *(undefined2 *)((int)cluster_cfg + 8);
      server_default_cfg.long_poll_interval._2_2_ = *(undefined2 *)((int)cluster_cfg + 10);
    }
    zcl_cluster_desc_add_revision_attr(cluster_desc,3);
    if ((role_mask & 1) != 0) {
      ezb_zcl_poll_control_cluster_desc_add_attr(cluster_desc,0,&uStack_1c);
      ezb_zcl_poll_control_cluster_desc_add_attr(cluster_desc,1,&server_default_cfg);
      ezb_zcl_poll_control_cluster_desc_add_attr
                (cluster_desc,2,&server_default_cfg.long_poll_interval);
      ezb_zcl_poll_control_cluster_desc_add_attr
                (cluster_desc,3,(void *)((int)&server_default_cfg.long_poll_interval + 2));
      ezb_zcl_cluster_desc_add_manuf_attr(cluster_desc,0xeff0,0,0x40,0x131b,0);
    }
  }
  return cluster_desc;
}

