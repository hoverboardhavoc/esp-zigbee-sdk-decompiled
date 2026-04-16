/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_cluster_desc_add_revision_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_cluster_desc_add_revision_attr(zcl_cluster_desc_t *cluster_desc,uint16_t revision)

{
  zcl_attr_desc_t *pzVar1;
  ezb_err_t eVar2;
  uint16_t auStack_12 [5];
  
  if (cluster_desc == (zcl_cluster_desc_t *)0x0) {
    eVar2 = 2;
  }
  else {
    auStack_12[0] = revision;
    pzVar1 = zcl_create_attr_desc(0xfffd,'!','\x01',0,auStack_12);
    pzVar1->next = cluster_desc->attr_list;
    cluster_desc->attr_list = pzVar1;
    eVar2 = 0;
  }
  return eVar2;
}

