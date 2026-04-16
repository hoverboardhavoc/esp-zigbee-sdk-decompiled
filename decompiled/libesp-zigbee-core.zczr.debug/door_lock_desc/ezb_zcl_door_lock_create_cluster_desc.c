/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> door_lock_desc.o -> ezb_zcl_door_lock_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: server_default_cfg */
/* WARNING: Unknown calling convention */

ezb_zcl_cluster_desc_t ezb_zcl_door_lock_create_cluster_desc(void *cluster_cfg,uint8_t role_mask)

{
  ezb_zcl_cluster_desc_t cluster_desc;
  undefined *puVar1;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 auStack_12 [2];
  ezb_zcl_door_lock_cluster_server_config_t server_default_cfg;
  
  uStack_14 = 0;
  uStack_13 = 0;
  auStack_12[0] = 0;
  cluster_desc = (ezb_zcl_cluster_desc_t)zcl_create_cluster_desc(0x101,0);
  if (cluster_desc != (ezb_zcl_cluster_desc_t)0x0) {
    if ((role_mask & 1) == 0) {
      puVar1 = &ezb_zcl_door_lock_cluster_client_init;
    }
    else {
      puVar1 = &ezb_zcl_door_lock_cluster_server_init;
    }
    *(undefined **)((int)cluster_desc + 8) = puVar1;
    if (cluster_cfg != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
      uStack_14 = *cluster_cfg;
      uStack_13 = *(undefined1 *)((int)cluster_cfg + 1);
      auStack_12[0] = *(undefined1 *)((int)cluster_cfg + 2);
    }
    zcl_cluster_desc_add_revision_attr(cluster_desc,1);
    if ((role_mask & 1) != 0) {
      ezb_zcl_door_lock_cluster_desc_add_attr(cluster_desc,0,&uStack_14);
      ezb_zcl_door_lock_cluster_desc_add_attr(cluster_desc,1,&uStack_13);
      ezb_zcl_door_lock_cluster_desc_add_attr(cluster_desc,2,auStack_12);
    }
  }
  return cluster_desc;
}

