/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_free_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void af_free_endpoint_desc(af_ep_desc_t *ep_desc)

{
  zcl_cluster_desc_s *pzVar1;
  zcl_reporting_info_s *pzVar2;
  af_simple_desc_t *paVar3;
  
  if (ep_desc != (af_ep_desc_t *)0x0) {
    pzVar1 = ep_desc->cluster_list;
    while (pzVar1 != (zcl_cluster_desc_t *)0x0) {
      pzVar1 = pzVar1->next;
      zcl_free_cluster_desc();
    }
    pzVar2 = ep_desc->reporting_list;
    while (pzVar2 != (zcl_reporting_info_t *)0x0) {
      pzVar2 = pzVar2->next;
      mm_free();
    }
    paVar3 = ep_desc->simple_desc;
    if (paVar3 != (af_simple_desc_t *)0x0) {
      if (paVar3->app_cluster_list != (uint16_t *)0x0) {
        mm_free();
        paVar3 = ep_desc->simple_desc;
        paVar3->app_cluster_list = (uint16_t *)0x0;
      }
      mm_free(paVar3);
      ep_desc->simple_desc = (af_simple_desc_t *)0x0;
    }
    if (ep_desc->ep_config != (af_ep_config_t *)0x0) {
      mm_free();
      ep_desc->ep_config = (af_ep_config_t *)0x0;
    }
    ep_desc->next = (af_ep_desc_s *)0x0;
    mm_free(ep_desc);
    return;
  }
  return;
}

