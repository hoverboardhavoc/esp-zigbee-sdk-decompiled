/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes_desc.o -> ezb_zcl_scenes_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: server_default_cfg */
/* WARNING: Unknown calling convention */

ezb_zcl_cluster_desc_t ezb_zcl_scenes_create_cluster_desc(void *cluster_cfg,uint8_t role_mask)

{
  ezb_zcl_cluster_desc_t cluster_desc;
  undefined *puVar1;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined2 uStack_16;
  ezb_zcl_scenes_cluster_server_config_t server_default_cfg;
  
  uStack_18 = 0;
  uStack_17 = 0;
  uStack_16 = 0;
  server_default_cfg.scene_count = '\0';
  server_default_cfg.current_scene = '\0';
  server_default_cfg.current_group._0_1_ = 0xf;
  cluster_desc = (ezb_zcl_cluster_desc_t)zcl_create_cluster_desc(5,0);
  if (cluster_desc != (ezb_zcl_cluster_desc_t)0x0) {
    if ((role_mask & 1) == 0) {
      puVar1 = &ezb_zcl_scenes_cluster_client_init;
    }
    else {
      puVar1 = &ezb_zcl_scenes_cluster_server_init;
    }
    *(undefined **)((int)cluster_desc + 8) = puVar1;
    if (cluster_cfg != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
      uStack_18 = *cluster_cfg;
      uStack_17 = *(undefined1 *)((int)cluster_cfg + 1);
      uStack_16 = *(undefined2 *)((int)cluster_cfg + 2);
      server_default_cfg.scene_count = *(uint8_t *)((int)cluster_cfg + 4);
      server_default_cfg.current_scene = *(uint8_t *)((int)cluster_cfg + 5);
      server_default_cfg.current_group._0_1_ = *(undefined1 *)((int)cluster_cfg + 6);
      server_default_cfg.current_group._1_1_ = *(undefined1 *)((int)cluster_cfg + 7);
    }
    zcl_cluster_desc_add_revision_attr(cluster_desc,3);
    if ((role_mask & 1) != 0) {
      ezb_zcl_scenes_cluster_desc_add_attr(cluster_desc,0,&uStack_18);
      ezb_zcl_scenes_cluster_desc_add_attr(cluster_desc,1,&uStack_17);
      ezb_zcl_scenes_cluster_desc_add_attr(cluster_desc,2,&uStack_16);
      ezb_zcl_scenes_cluster_desc_add_attr(cluster_desc,3,&server_default_cfg);
      ezb_zcl_scenes_cluster_desc_add_attr(cluster_desc,4,&server_default_cfg.current_scene);
      ezb_zcl_cluster_desc_add_manuf_attr
                (cluster_desc,0xeff0,0x20,0x40,0x131b,&server_default_cfg.current_group);
      ezb_zcl_cluster_desc_add_manuf_attr(cluster_desc,0xeff1,0,0x40,0x131b,0);
    }
  }
  return cluster_desc;
}

