/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> meter_identification_desc.o -> ezb_zcl_meter_identification_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: server_default_cfg */
/* WARNING: Unknown calling convention */

ezb_zcl_cluster_desc_t
ezb_zcl_meter_identification_create_cluster_desc(void *cluster_cfg,uint8_t role_mask)

{
  ezb_zcl_cluster_desc_t cluster_desc;
  undefined *puVar1;
  undefined4 uStack_24;
  ezb_zcl_meter_identification_cluster_server_config_t server_default_cfg;
  
  uStack_24 = 0;
  server_default_cfg.company_name = (char *)0x0;
  server_default_cfg.meter_type_id = 0;
  server_default_cfg.data_quality_id = 0;
  server_default_cfg.pod = (char *)0x0;
  server_default_cfg.available_power = 0;
  cluster_desc = (ezb_zcl_cluster_desc_t)zcl_create_cluster_desc(0xb01,0);
  if (cluster_desc != (ezb_zcl_cluster_desc_t)0x0) {
    if ((role_mask & 1) == 0) {
      puVar1 = &ezb_zcl_meter_identification_cluster_client_init;
    }
    else {
      puVar1 = &ezb_zcl_meter_identification_cluster_server_init;
    }
    *(undefined **)((int)cluster_desc + 8) = puVar1;
    if (cluster_cfg != (void *)0x0) {
      memcpy(&uStack_24,cluster_cfg,0x14);
    }
    zcl_cluster_desc_add_revision_attr(cluster_desc,2);
    if ((role_mask & 1) != 0) {
      ezb_zcl_meter_identification_cluster_desc_add_attr(cluster_desc,0,&uStack_24);
      ezb_zcl_meter_identification_cluster_desc_add_attr(cluster_desc,1,&server_default_cfg);
      ezb_zcl_meter_identification_cluster_desc_add_attr
                (cluster_desc,4,(void *)((int)&server_default_cfg.company_name + 2));
      ezb_zcl_meter_identification_cluster_desc_add_attr
                (cluster_desc,0xc,&server_default_cfg.meter_type_id);
      ezb_zcl_meter_identification_cluster_desc_add_attr(cluster_desc,0xd,&server_default_cfg.pod);
      ezb_zcl_meter_identification_cluster_desc_add_attr
                (cluster_desc,0xe,&server_default_cfg.available_power);
    }
  }
  return cluster_desc;
}

