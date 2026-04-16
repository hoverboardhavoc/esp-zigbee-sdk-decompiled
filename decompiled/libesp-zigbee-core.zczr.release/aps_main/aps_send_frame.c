/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_send_frame
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
  nlde_req._6_2_ = (byte)(*(uint *)&req->field_0x18 >> 2) & 0xff04 | 3;
  nlde_req.dst_addr = req->alias_src_addr;
  nlde_req.nsdu._2_1_ = req->radius;
  nlde_req.nsdu._3_1_ = req->alias_seq_num;
  nlde_req.nsdu._0_2_ = dst_addr;
  eVar1 = nwk_nlde_data_request(&pzStack_1c);
  return eVar1;
}

