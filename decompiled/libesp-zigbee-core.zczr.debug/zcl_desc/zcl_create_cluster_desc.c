/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_cluster_desc_t *
zcl_create_cluster_desc(uint16_t cluster_id,uint8_t role_mask,uint16_t manuf_code)

{
  zcl_cluster_desc_t *pzVar1;
  
  pzVar1 = (zcl_cluster_desc_t *)calloc(1,0x14);
  if (pzVar1 != (zcl_cluster_desc_t *)0x0) {
    pzVar1->cluster_id = cluster_id;
    pzVar1->role_mask = role_mask;
    pzVar1->manuf_code = manuf_code;
    pzVar1->cluster_init = (zcl_cluster_init_t)0x0;
    pzVar1->attr_list = (zcl_attr_desc_t *)0x0;
    pzVar1->next = (zcl_cluster_desc_s *)0x0;
  }
  return pzVar1;
}

