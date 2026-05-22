/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_intrp.o -> nwk_intrp_data_request
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
  
  eVar1 = nwk_intrp_prepend_header(req->nsdu);
  if (eVar1 == 0) {
    pzStack_2c = req->nsdu;
    mac_req.msdu = *(zmsg_t **)&req->src_addr;
    mac_req.addresses.source._0_4_ = *(undefined4 *)((int)&(req->src_addr).u + 2);
    mac_req.addresses._8_4_ = (req->dst_addr).u.group_addr;
    mac_req.addresses.destination.u.group_addr = *(ezb_grpaddr_t *)((int)&(req->dst_addr).u + 4);
    mac_req.addresses.source.u._4_2_ = *(undefined2 *)&req->dst_addr;
    mac_req.addresses.source.u.group_addr.bcast = *(undefined2 *)((int)&(req->src_addr).u + 6);
    mac_req.addresses.destination.u._6_2_ = 0;
    mac_req.addresses.destination.u._4_2_ = req->dst_panid;
    eVar1 = nwk_mm_data_request(&pzStack_2c);
  }
  return eVar1;
}

