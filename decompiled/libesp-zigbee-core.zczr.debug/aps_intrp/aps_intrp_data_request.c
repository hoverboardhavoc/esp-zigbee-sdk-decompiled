/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_intrp.o -> aps_intrp_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_intrp_data_request(aps_intrp_data_req_t *req)

{
  undefined1 *puVar1;
  ezb_err_t eVar2;
  undefined1 auStack_2c [2];
  undefined1 uStack_2a;
  undefined1 uStack_29;
  nwk_intrp_data_req_t nwk_req;
  
  aps_intrp_prepend_header(req->asdu,req);
  auStack_2c[0] = 3;
  puVar1 = (undefined1 *)nwk_get_extended_address();
  uStack_2a = *puVar1;
  uStack_29 = puVar1[1];
  nwk_req.src_addr.addr_mode = puVar1[2];
  nwk_req.src_addr._1_1_ = puVar1[3];
  nwk_req.src_addr.u.short_addr._0_1_ = puVar1[4];
  nwk_req.src_addr.u.short_addr._1_1_ = puVar1[5];
  nwk_req.src_addr.u.group_addr.bcast._0_1_ = puVar1[6];
  nwk_req.src_addr.u.group_addr.bcast._1_1_ = puVar1[7];
  nwk_req.src_addr.u._4_2_ = req->dst_pan_id;
  nwk_req._8_4_ = *(undefined4 *)&req->dst_addr;
  nwk_req.dst_addr._0_4_ = *(undefined4 *)((int)&(req->dst_addr).u + 2);
  nwk_req.dst_addr.u.group_addr.bcast = *(ezb_shortaddr_t *)((int)&(req->dst_addr).u + 6);
  nwk_req._20_4_ = aps_intrp_msg_transfer_ownership(&req->asdu);
  zmsg_add_footer(req,0x18);
  eVar2 = nwk_intrp_data_request(auStack_2c);
  if (req->asdu != (zmsg_t *)0x0) {
    zmsg_free();
  }
  return eVar2;
}

