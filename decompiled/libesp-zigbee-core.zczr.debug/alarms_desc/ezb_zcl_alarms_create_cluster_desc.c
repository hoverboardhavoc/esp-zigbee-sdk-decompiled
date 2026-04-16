/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> alarms_desc.o -> ezb_zcl_alarms_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: server_default_cfg */
/* WARNING: Unknown calling convention */

ezb_zcl_cluster_desc_t ezb_zcl_alarms_create_cluster_desc(void *cluster_cfg,uint8_t role_mask)

{
  ezb_zcl_cluster_desc_t pvVar1;
  undefined *puVar2;
  undefined2 auStack_14 [2];
  ezb_zcl_alarms_cluster_server_config_t server_default_cfg;
  
  auStack_14[0] = 0xf;
  pvVar1 = (ezb_zcl_cluster_desc_t)zcl_create_cluster_desc(9,0);
  if (pvVar1 != (ezb_zcl_cluster_desc_t)0x0) {
    if ((role_mask & 1) == 0) {
      puVar2 = &ezb_zcl_alarms_cluster_client_init;
    }
    else {
      puVar2 = &ezb_zcl_alarms_cluster_server_init;
    }
    *(undefined **)((int)pvVar1 + 8) = puVar2;
    if (cluster_cfg != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
      auStack_14[0] = *cluster_cfg;
    }
    zcl_cluster_desc_add_revision_attr(pvVar1,1);
    if ((role_mask & 1) != 0) {
      ezb_zcl_cluster_desc_add_manuf_attr(pvVar1,0xeffe,0x21,0x40,0x131b,auStack_14);
      ezb_zcl_cluster_desc_add_manuf_attr(pvVar1,0xefff,0,0x40,0x131b,0);
    }
  }
  return pvVar1;
}

