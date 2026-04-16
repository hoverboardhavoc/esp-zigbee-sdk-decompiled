/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_intrp.o -> nwk_intrp_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_intrp_data_request(nwk_intrp_data_req_t *req)

{
  zmsg_t *pzStack_2c;
  mac_data_req_t mac_req;
  
  pzStack_2c = (zmsg_t *)CONCAT22(pzStack_2c._2_2_,0xb);
  zmsg_prepend_bytes(req->nsdu,2,&pzStack_2c);
  pzStack_2c = req->nsdu;
  mac_req.addresses.destination.u._6_2_ = 0;
  if (pzStack_2c != (zmsg_t *)0x0) {
    req->nsdu = (zmsg_t *)0x0;
  }
  memcpy(&mac_req,req,10);
  memcpy((void *)((int)&mac_req.addresses.source.u + 4),&req->dst_addr,10);
  mac_req.addresses.destination.u._4_2_ = req->dst_panid;
  nwk_mm_data_request(0,&pzStack_2c);
  if (req->nsdu != (zmsg_t *)0x0) {
    zmsg_free();
  }
  return 0;
}

