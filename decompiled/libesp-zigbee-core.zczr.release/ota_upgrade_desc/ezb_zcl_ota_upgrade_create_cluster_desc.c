/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_desc.o -> ezb_zcl_ota_upgrade_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_cluster_desc_t ezb_zcl_ota_upgrade_create_cluster_desc(void *cluster_cfg,uint8_t role_mask)

{
  ezb_zcl_cluster_desc_t cluster_desc;
  undefined3 in_register_0000202d;
  undefined *puVar1;
  undefined1 auStack_3c [4];
  ezb_zcl_ota_upgrade_cluster_server_config_t server_default_cfg;
  ezb_zcl_ota_upgrade_cluster_client_config_t client_default_cfg;
  
  auStack_3c[0] = 1;
  memcpy(&server_default_cfg,&_LANCHOR0,0x18);
  cluster_desc = (ezb_zcl_cluster_desc_t)
                 zcl_create_cluster_desc(0x19,CONCAT31(in_register_0000202d,role_mask),0);
  if (cluster_desc != (ezb_zcl_cluster_desc_t)0x0) {
    if ((role_mask & 1) == 0) {
      puVar1 = &ezb_zcl_ota_upgrade_cluster_client_init;
    }
    else {
      puVar1 = &ezb_zcl_ota_upgrade_cluster_server_init;
    }
    *(undefined **)((int)cluster_desc + 8) = puVar1;
    if (cluster_cfg != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
      auStack_3c[0] = *cluster_cfg;
    }
    zcl_cluster_desc_add_revision_attr(cluster_desc,4);
    if ((role_mask & 1) != 0) {
      ezb_zcl_cluster_desc_add_manuf_attr(cluster_desc,0xeff0,0x20,0x40,0x131b,auStack_3c);
      ezb_zcl_cluster_desc_add_manuf_attr(cluster_desc,0xeff1,0,0x40,0x131b,0);
    }
    if (cluster_cfg != (void *)0x0) {
      memcpy(&server_default_cfg,cluster_cfg,0x18);
    }
    zcl_cluster_desc_add_revision_attr(cluster_desc,4);
    if ((role_mask & 2) != 0) {
      ezb_zcl_ota_upgrade_cluster_desc_add_attr(cluster_desc,0,&server_default_cfg);
      ezb_zcl_ota_upgrade_cluster_desc_add_attr
                (cluster_desc,1,(void *)((int)&client_default_cfg.upgrade_server_id + 4));
      ezb_zcl_ota_upgrade_cluster_desc_add_attr(cluster_desc,6,&client_default_cfg.file_offset);
      ezb_zcl_ota_upgrade_cluster_desc_add_attr
                (cluster_desc,7,(void *)((int)&client_default_cfg.file_offset + 2));
      ezb_zcl_ota_upgrade_cluster_desc_add_attr
                (cluster_desc,8,&client_default_cfg.image_upgrade_status);
      ezb_zcl_cluster_desc_add_manuf_attr(cluster_desc,0xeff0,0,0x40,0x131b,0);
    }
  }
  return cluster_desc;
}

