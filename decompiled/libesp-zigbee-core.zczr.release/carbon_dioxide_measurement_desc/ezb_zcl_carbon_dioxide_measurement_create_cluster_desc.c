/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> carbon_dioxide_measurement_desc.o -> ezb_zcl_carbon_dioxide_measurement_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: server_default_cfg */
/* WARNING: Unknown calling convention */

ezb_zcl_cluster_desc_t
ezb_zcl_carbon_dioxide_measurement_create_cluster_desc(void *cluster_cfg,uint8_t role_mask)

{
  ezb_zcl_cluster_desc_t cluster_desc;
  undefined3 in_register_0000202d;
  undefined *puVar1;
  float fStack_1c;
  ezb_zcl_carbon_dioxide_measurement_cluster_server_config_t server_default_cfg;
  
  fStack_1c = (float)__divsf3(0);
  server_default_cfg.measured_value = fStack_1c;
  server_default_cfg.min_measured_value = fStack_1c;
  cluster_desc = (ezb_zcl_cluster_desc_t)
                 zcl_create_cluster_desc(0x40d,CONCAT31(in_register_0000202d,role_mask),0);
  if (cluster_desc != (ezb_zcl_cluster_desc_t)0x0) {
    if ((role_mask & 1) == 0) {
      puVar1 = &ezb_zcl_carbon_dioxide_measurement_cluster_client_init;
    }
    else {
      puVar1 = &ezb_zcl_carbon_dioxide_measurement_cluster_server_init;
    }
    *(undefined **)((int)cluster_desc + 8) = puVar1;
    if (cluster_cfg != (void *)0x0) {
      memcpy(&fStack_1c,cluster_cfg,0xc);
    }
    zcl_cluster_desc_add_revision_attr(cluster_desc,2);
    if ((role_mask & 1) != 0) {
      ezb_zcl_carbon_dioxide_measurement_cluster_desc_add_attr(cluster_desc,0,&fStack_1c);
      ezb_zcl_carbon_dioxide_measurement_cluster_desc_add_attr(cluster_desc,1,&server_default_cfg);
      ezb_zcl_carbon_dioxide_measurement_cluster_desc_add_attr
                (cluster_desc,2,&server_default_cfg.min_measured_value);
    }
  }
  return cluster_desc;
}

