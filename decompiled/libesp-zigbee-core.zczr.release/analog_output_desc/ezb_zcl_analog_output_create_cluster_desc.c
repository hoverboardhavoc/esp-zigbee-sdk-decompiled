/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> analog_output_desc.o -> ezb_zcl_analog_output_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: server_default_cfg */
/* WARNING: Unknown calling convention */

ezb_zcl_cluster_desc_t
ezb_zcl_analog_output_create_cluster_desc(void *cluster_cfg,uint8_t role_mask)

{
  ezb_zcl_cluster_desc_t cluster_desc;
  undefined *puVar1;
  undefined1 auStack_1c [4];
  ezb_zcl_analog_output_cluster_server_config_t server_default_cfg;
  
  auStack_1c[0] = 0;
  server_default_cfg.out_of_service = false;
  server_default_cfg._1_3_ = 0;
  server_default_cfg.present_value._0_1_ = 0;
  cluster_desc = (ezb_zcl_cluster_desc_t)zcl_create_cluster_desc(0xd,0);
  if (cluster_desc != (ezb_zcl_cluster_desc_t)0x0) {
    if ((role_mask & 1) == 0) {
      puVar1 = &ezb_zcl_analog_output_cluster_client_init;
    }
    else {
      puVar1 = &ezb_zcl_analog_output_cluster_server_init;
    }
    *(undefined **)((int)cluster_desc + 8) = puVar1;
    if (cluster_cfg != (void *)0x0) {
      memcpy(auStack_1c,cluster_cfg,0xc);
    }
    zcl_cluster_desc_add_revision_attr(cluster_desc,1);
    if ((role_mask & 1) != 0) {
      ezb_zcl_analog_output_cluster_desc_add_attr(cluster_desc,0x51,auStack_1c);
      ezb_zcl_analog_output_cluster_desc_add_attr(cluster_desc,0x55,&server_default_cfg);
      ezb_zcl_analog_output_cluster_desc_add_attr
                (cluster_desc,0x6f,&server_default_cfg.present_value);
    }
  }
  return cluster_desc;
}

