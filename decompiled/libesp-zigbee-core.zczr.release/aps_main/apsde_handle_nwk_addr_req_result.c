/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> apsde_handle_nwk_addr_req_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void apsde_handle_nwk_addr_req_result(ezb_zdo_nwk_addr_req_result_t *result,void *user_ctx)

{
  zmsg_t *unaff_s0;
  ezb_err_t error;
  ezb_zdp_address_rsp_field_t *peVar1;
  undefined1 auStack_2c [4];
  aps_apsde_data_req_t req;
  
  if ((result != (ezb_zdo_nwk_addr_req_result_t *)0x0) &&
     (unaff_s0 = (zmsg_t *)user_ctx, user_ctx != (void *)0x0)) goto _L0;
  do {
    result = (ezb_zdo_nwk_addr_req_result_t *)__assert_func(0,0,0,0);
_L0:
    memset(auStack_2c,0,0x1c);
    zmsg_get_footer(unaff_s0,auStack_2c,0x1c);
    zmsg_remove_footer(unaff_s0,0x1c);
  } while ((char)req.asdu != '\x03');
  peVar1 = result->rsp;
  if (peVar1 == (ezb_zdp_address_rsp_field_t *)0x0) {
    error = 0x3a9;
  }
  else {
    error = 0x3a9;
    if ((peVar1->status == '\0') &&
       (error = apsde_data_request_continue
                          ((aps_apsde_data_req_t *)auStack_2c,peVar1->nwk_addr_remote_dev),
       error == 0)) {
      return;
    }
  }
  zmsg_add_footer(unaff_s0,auStack_2c,0x1c);
  zmsg_set_offset(unaff_s0,0);
  aps_send_data_confirm(unaff_s0,error);
  return;
}

