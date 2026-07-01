/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_match_desc_add_matched_ep_ids
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t zdo_match_desc_add_matched_ep_ids
                  (zdp_match_desc_req_field_t *req,zdp_match_desc_rsp_field_t *rsp)

{
  byte bVar1;
  uint8_t list_len;
  byte num_of_clusters;
  uint8_t *unaff_s0;
  _Bool _Var2;
  uint16_t *cluster_list;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint16_t *clusters;
  
  if ((rsp != (zdp_match_desc_rsp_field_t *)0x0) && (req != (zdp_match_desc_req_field_t *)0x0)) {
    unaff_s0 = (uint8_t *)0x0;
    while (unaff_s0 = (uint8_t *)af_get_next_simple_desc(unaff_s0), unaff_s0 != (uint8_t *)0x0) {
      cluster_list = *(uint16_t **)(unaff_s0 + 0xc);
      bVar1 = unaff_s0[7];
      list_len = unaff_s0[8];
      if ((*(uint16_t *)(unaff_s0 + 2) == req->profile_id) || (req->profile_id == 0xffff)) {
        clusters = req->cluster_list;
        num_of_clusters = req->num_in_clusters;
        _Var2 = clusters_is_on_list(cluster_list,bVar1,clusters,num_of_clusters);
        if ((CONCAT31(extraout_var,_Var2) != 0) ||
           (_Var2 = clusters_is_on_list(cluster_list + bVar1,list_len,clusters + num_of_clusters,
                                        req->num_out_clusters), CONCAT31(extraout_var_00,_Var2) != 0
           )) {
_L0:
          bVar1 = rsp->match_length;
          rsp->match_length = bVar1 + 1;
          rsp->match_list[bVar1] = *unaff_s0;
        }
      }
    }
    return rsp->match_length;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",999,
                "zdo_match_desc_add_matched_ep_ids","rsp && req");
  goto _L0;
}

