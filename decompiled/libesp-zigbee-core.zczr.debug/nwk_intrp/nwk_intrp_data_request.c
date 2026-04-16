/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_intrp.o -> nwk_intrp_data_request
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
  
  nwk_intrp_prepend_header(req->nsdu);
  pzStack_2c = (zmsg_t *)0x0;
  mac_req.msdu = (zmsg_t *)0x0;
  mac_req.addresses.source._0_4_ = 0;
  mac_req.addresses.source.u._2_4_ = 0;
  mac_req.addresses._8_4_ = 0;
  mac_req.addresses.destination.u._0_2_ = 0;
  mac_req.addresses.destination.u._2_2_ = 0;
  mac_req.addresses.destination.u._4_4_ = 0;
  pzStack_2c = nwk_intrp_msg_transfer_ownership(&req->nsdu);
  mac_req.msdu = *(zmsg_t **)&req->src_addr;
  mac_req.addresses.source._0_4_ = *(undefined4 *)((int)&(req->src_addr).u + 2);
  mac_req.addresses._8_4_ = (req->dst_addr).u.group_addr;
  mac_req.addresses.destination.u.group_addr = *(ezb_grpaddr_t *)((int)&(req->dst_addr).u + 4);
  mac_req.addresses.source.u._4_2_ = *(undefined2 *)&req->dst_addr;
  mac_req.addresses.source.u.group_addr.bcast = *(undefined2 *)((int)&(req->src_addr).u + 6);
  mac_req.addresses.destination.u._4_2_ = req->dst_panid;
  nwk_mm_data_request(0,&pzStack_2c);
  if (req->nsdu != (zmsg_t *)0x0) {
    zmsg_free();
  }
  return 0;
}

