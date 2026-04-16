/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_ep_reporting_info_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_ep_reporting_info_init(af_ep_desc_t *ep_desc)

{
  zcl_cluster_desc_t *pzVar1;
  int iVar2;
  zcl_attr_desc_t *pzVar3;
  
  if (ep_desc == (af_ep_desc_t *)0x0) {
    return 2;
  }
  zcl_reporting_restore_reporting_info(ep_desc->ep_id);
  pzVar1 = ep_desc->cluster_list;
  do {
    if (pzVar1 == (zcl_cluster_desc_t *)0x0) {
      return 0;
    }
    for (pzVar3 = pzVar1->attr_list; pzVar3 != (zcl_attr_desc_t *)0x0; pzVar3 = pzVar3->next) {
      if (((pzVar3->access & 4) != 0) &&
         (iVar2 = zcl_reporting_info_find
                            (ep_desc->ep_id,pzVar1->cluster_id,pzVar1->role_mask,pzVar3->id,
                             pzVar3->manuf_code), iVar2 == 0)) {
        zcl_reporting_info_create
                  (ep_desc->ep_id,ep_desc->profile_id,0,pzVar1->cluster_id,pzVar1->role_mask,
                   pzVar3->id,pzVar3->manuf_code);
        iVar2 = zcl_reporting_info_add();
        if (iVar2 != 0) {
          return iVar2;
        }
      }
    }
    pzVar1 = pzVar1->next;
  } while( true );
}

