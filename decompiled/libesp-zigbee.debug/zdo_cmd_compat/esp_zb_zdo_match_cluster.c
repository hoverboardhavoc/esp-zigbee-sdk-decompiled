/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_match_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

esp_err_t esp_zb_zdo_match_cluster
                    (esp_zb_zdo_match_desc_req_param_t *cmd_req,
                    esp_zb_zdo_match_desc_callback_t user_cb,void *user_ctx)

{
  ushort uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  esp_err_t eVar5;
  undefined4 uStack_28;
  ezb_zdo_match_desc_req_t req;
  
  uStack_28 = 0;
  req.dst_nwk_addr = 0;
  req._2_2_ = 0;
  req.field.nwk_addr_of_interest = 0;
  req.field.profile_id = 0;
  req.field.num_in_clusters = '\0';
  req.field.num_out_clusters = '\0';
  req.field._6_2_ = 0;
  req.field.cluster_list = (uint16_t *)0x0;
  req.cb = (ezb_zdo_match_desc_req_callback_t)0x0;
  if (cmd_req == (esp_zb_zdo_match_desc_req_param_t *)0x0) {
    eVar5 = 0x102;
  }
  else {
    req.cb = (ezb_zdo_match_desc_req_callback_t)calloc(1,0xc);
    uVar4 = req.field._0_4_;
    if (req.cb == (ezb_zdo_match_desc_req_callback_t)0x0) {
      eVar5 = 0x101;
    }
    else {
      *(esp_zb_zdo_match_desc_callback_t *)req.cb = user_cb;
      *(void **)(req.cb + 4) = user_ctx;
      uVar1 = cmd_req->dst_nwk_addr;
      req.cb[8] = (_func_void_ezb_zdo_match_desc_req_result_t_ptr_void_ptr)(0xfff7 < uVar1);
      req.cb[9] = (code)0x0;
      req.dst_nwk_addr = cmd_req->addr_of_interest;
      req._2_2_ = cmd_req->profile_id;
      uVar2 = cmd_req->num_in_clusters;
      uVar3 = cmd_req->num_out_clusters;
      req.field.nwk_addr_of_interest._1_1_ = uVar3;
      req.field.nwk_addr_of_interest._0_1_ = uVar2;
      req.field.profile_id = SUB42(uVar4,2);
      req.field._4_4_ = cmd_req->cluster_list;
      uStack_28 = CONCAT22(uStack_28._2_2_,uVar1);
      req.field.cluster_list = (uint16_t *)esp_zb_zdo_match_desc_rsp_wrapper;
      ezb_zdo_match_desc_req(&uStack_28);
      eVar5 = 0;
    }
  }
  return eVar5;
}

