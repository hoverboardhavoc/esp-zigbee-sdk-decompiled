/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> apsde_handle_nwk_addr_req_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void apsde_handle_nwk_addr_req_result(ezb_zdo_nwk_addr_req_result_t *result,void *user_ctx)

{
  ezb_err_t error;
  ezb_zdp_address_rsp_field_t *in_a5;
  undefined1 auStack_2c [4];
  aps_apsde_data_req_t req;
  
  if ((result == (ezb_zdo_nwk_addr_req_result_t *)0x0) || (user_ctx == (void *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/aps/aps_main.c",0x27c,
                  "apsde_handle_nwk_addr_req_result",
                  "result != ((void *)0) && user_ctx != ((void *)0)");
_L0:
    __assert_func("//build/esp-zigbee/src/core/aps/aps_main.c",0x285,
                  "apsde_handle_nwk_addr_req_result","req.dst_addr.addr_mode == EZB_ADDR_MODE_EXT");
  }
  else {
    auStack_2c = (undefined1  [4])0x0;
    req.asdu = (zmsg_t *)0x0;
    req.dst_addr._0_4_ = 0;
    req.dst_addr.u._2_4_ = 0;
    req._12_4_ = 0;
    req.cluster_id = 0;
    req.profile_id = 0;
    req.radius = '\0';
    req.alias_seq_num = '\0';
    req.alias_src_addr = 0;
    zmsg_get_footer(user_ctx,auStack_2c,0x1c);
    zmsg_remove_footer(user_ctx,0x1c);
    in_a5 = (ezb_zdp_address_rsp_field_t *)(((uint)req.asdu & 0xff) - 3);
    if (in_a5 != (ezb_zdp_address_rsp_field_t *)0x0) goto _L0;
    in_a5 = result->rsp;
    if (in_a5 == (ezb_zdp_address_rsp_field_t *)0x0) {
      error = 0x3a9;
      goto _L0;
    }
    if (in_a5->status != '\0') {
      error = 0x3a9;
      goto _L0;
    }
  }
  error = apsde_data_request_continue((aps_apsde_data_req_t *)auStack_2c,in_a5->nwk_addr_remote_dev)
  ;
  if (error == 0) {
    return;
  }
_L0:
  zmsg_add_footer(user_ctx,auStack_2c,0x1c);
  zmsg_set_offset(user_ctx,0);
  aps_send_confirm((zmsg_t *)user_ctx,error);
  return;
}

