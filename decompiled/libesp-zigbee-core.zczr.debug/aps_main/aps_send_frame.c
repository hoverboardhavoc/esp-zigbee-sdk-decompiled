/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_send_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_send_frame(ezb_shortaddr_t dst_addr,aps_apsde_data_req_t *req)

{
  ezb_err_t eVar1;
  zmsg_t *pzStack_1c;
  nwk_nlde_data_req_t nlde_req;
  
  pzStack_1c = req->asdu;
  nlde_req.nsdu = (zmsg_t *)CONCAT13(req->alias_seq_num,CONCAT12(req->radius,dst_addr));
  nlde_req._4_4_ =
       CONCAT12((char)((*(uint *)&req->field_0x18 >> 4 & 1) << 2),req->alias_src_addr) | 0x30000;
  eVar1 = nwk_nlde_data_request(&pzStack_1c);
  return eVar1;
}

