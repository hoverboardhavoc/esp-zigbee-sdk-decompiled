/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_ep_reporting_info_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_ep_reporting_info_init(af_ep_desc_t *ep_desc)

{
  zcl_attr_desc_t *pzVar1;
  zcl_cluster_desc_t *pzVar2;
  int iVar3;
  int iVar4;
  
  if (ep_desc == (af_ep_desc_t *)0x0) {
    iVar4 = 2;
  }
  else {
    zcl_reporting_restore_reporting_info(ep_desc->ep_id);
    iVar4 = 0;
    for (pzVar2 = ep_desc->cluster_list; pzVar2 != (zcl_cluster_desc_t *)0x0; pzVar2 = pzVar2->next)
    {
      for (pzVar1 = pzVar2->attr_list; pzVar1 != (zcl_attr_desc_t *)0x0; pzVar1 = pzVar1->next) {
        if (((pzVar1->access & 4) != 0) &&
           (iVar3 = zcl_reporting_info_find
                              (ep_desc->ep_id,pzVar2->cluster_id,pzVar2->role_mask,pzVar1->id,
                               pzVar1->manuf_code), iVar3 == 0)) {
          zcl_reporting_info_create
                    (ep_desc->ep_id,ep_desc->profile_id,0,pzVar2->cluster_id,pzVar2->role_mask,
                     pzVar1->id,pzVar1->manuf_code);
          iVar4 = zcl_reporting_info_add();
          if (iVar4 != 0) {
            return iVar4;
          }
        }
      }
    }
  }
  return iVar4;
}

