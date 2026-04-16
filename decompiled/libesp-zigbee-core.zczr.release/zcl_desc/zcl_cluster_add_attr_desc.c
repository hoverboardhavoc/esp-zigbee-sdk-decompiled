/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_desc.o -> zcl_cluster_add_attr_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_cluster_add_attr_desc(zcl_cluster_desc_t *cluster_desc,zcl_attr_desc_t *attr_desc)

{
  ezb_err_t eVar1;
  zcl_attr_desc_t *pzVar2;
  
  eVar1 = 2;
  if (cluster_desc == (zcl_cluster_desc_t *)0x0) {
    return eVar1;
  }
  if (attr_desc != (zcl_attr_desc_t *)0x0) {
    for (pzVar2 = cluster_desc->attr_list; pzVar2 != (zcl_attr_desc_t *)0x0; pzVar2 = pzVar2->next)
    {
      if ((pzVar2->id == attr_desc->id) && (pzVar2->manuf_code == attr_desc->manuf_code)) {
        return 2;
      }
    }
    attr_desc->next = cluster_desc->attr_list;
    cluster_desc->attr_list = attr_desc;
    eVar1 = 0;
  }
  return eVar1;
}

