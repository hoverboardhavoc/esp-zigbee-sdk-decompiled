/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_intrp.o -> nwk_intrp_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_intrp_data_request(nwk_intrp_data_req_t *req)

{
  ezb_err_t eVar1;
  zmsg_t *pzStack_2c;
  mac_data_req_t mac_req;
  
  pzStack_2c = (zmsg_t *)CONCAT22(pzStack_2c._2_2_,0xb);
  eVar1 = zmsg_prepend_bytes(req->nsdu,2,&pzStack_2c);
  if (eVar1 == 0) {
    pzStack_2c = req->nsdu;
    mac_req.addresses.destination.u._6_2_ = 0;
    memcpy(&mac_req,req,10);
    memcpy((void *)((int)&mac_req.addresses.source.u + 4),&req->dst_addr,10);
    mac_req.addresses.destination.u._4_2_ = req->dst_panid;
    eVar1 = nwk_mm_data_request(0,&pzStack_2c);
  }
  return eVar1;
}

