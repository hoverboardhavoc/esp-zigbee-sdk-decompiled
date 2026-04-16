/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_endpoint_add_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_endpoint_add_cluster_desc(af_ep_desc_t *ep_desc,zcl_cluster_desc_t *cluster_desc)

{
  _Bool _Var1;
  undefined3 extraout_var;
  ezb_err_t eVar2;
  zcl_cluster_desc_t *head;
  
  if (ep_desc == (af_ep_desc_t *)0x0) {
    eVar2 = 2;
  }
  else if (cluster_desc == (zcl_cluster_desc_t *)0x0) {
    eVar2 = 2;
  }
  else {
    head = ep_desc->cluster_list;
    _Var1 = check_cluster_is_unique(head,cluster_desc->cluster_id,cluster_desc->role_mask);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      eVar2 = 2;
    }
    else {
      cluster_desc->next = head;
      ep_desc->cluster_list = cluster_desc;
      eVar2 = 0;
    }
  }
  return eVar2;
}

