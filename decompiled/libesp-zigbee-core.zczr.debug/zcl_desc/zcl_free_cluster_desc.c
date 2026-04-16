/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_free_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_free_cluster_desc(zcl_cluster_desc_t *cluster_desc)

{
  zcl_attr_desc_s *pzVar1;
  zcl_attr_desc_t *attr_desc;
  
  if (cluster_desc != (zcl_cluster_desc_t *)0x0) {
    attr_desc = cluster_desc->attr_list;
    while (attr_desc != (zcl_attr_desc_t *)0x0) {
      pzVar1 = attr_desc->next;
      zcl_free_attr_desc(attr_desc);
      attr_desc = pzVar1;
    }
    cluster_desc->next = (zcl_cluster_desc_s *)0x0;
    mm_free(cluster_desc);
  }
  return;
}

