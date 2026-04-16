/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_endpoint_add_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_endpoint_add_cluster_desc(af_ep_desc_t *ep_desc,zcl_cluster_desc_t *cluster_desc)

{
  ezb_err_t eVar1;
  zcl_cluster_desc_t *pzVar2;
  
  eVar1 = 2;
  if (ep_desc == (af_ep_desc_t *)0x0) {
    return eVar1;
  }
  if (cluster_desc != (zcl_cluster_desc_t *)0x0) {
    for (pzVar2 = ep_desc->cluster_list; pzVar2 != (zcl_cluster_desc_t *)0x0; pzVar2 = pzVar2->next)
    {
      if ((pzVar2->cluster_id == cluster_desc->cluster_id) &&
         ((cluster_desc->role_mask & pzVar2->role_mask) != 0)) {
        return 2;
      }
    }
    cluster_desc->next = ep_desc->cluster_list;
    ep_desc->cluster_list = cluster_desc;
    eVar1 = 0;
  }
  return eVar1;
}

