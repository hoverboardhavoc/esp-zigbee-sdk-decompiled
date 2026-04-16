/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_ep_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_ep_desc_init(af_ep_desc_t *ep_desc)

{
  zcl_cluster_desc_t *pzVar1;
  
  if (ep_desc != (af_ep_desc_t *)0x0) {
    for (pzVar1 = ep_desc->cluster_list; pzVar1 != (zcl_cluster_desc_t *)0x0; pzVar1 = pzVar1->next)
    {
      if (pzVar1->cluster_init != (zcl_cluster_init_t)0x0) {
        (*pzVar1->cluster_init)(ep_desc->ep_id);
      }
    }
  }
  return 0;
}

