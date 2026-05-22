/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_intrp.o -> aps_intrp_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_intrp_data_request(aps_intrp_data_req_t *req)

{
  ezb_err_t eVar1;
  undefined1 *puVar2;
  undefined1 auStack_2c [2];
  undefined1 uStack_2a;
  undefined1 uStack_29;
  nwk_intrp_data_req_t nwk_req;
  
  eVar1 = aps_intrp_prepend_header(req->asdu,req);
  if (eVar1 == 0) {
    auStack_2c[0] = 3;
    puVar2 = (undefined1 *)nwk_get_extended_address();
    uStack_2a = *puVar2;
    uStack_29 = puVar2[1];
    nwk_req.src_addr.addr_mode = puVar2[2];
    nwk_req.src_addr._1_1_ = puVar2[3];
    nwk_req.src_addr.u.short_addr._0_1_ = puVar2[4];
    nwk_req.src_addr.u.short_addr._1_1_ = puVar2[5];
    nwk_req.src_addr.u.group_addr.bcast._0_1_ = puVar2[6];
    nwk_req.src_addr.u.group_addr.bcast._1_1_ = puVar2[7];
    nwk_req.src_addr.u._4_2_ = req->dst_pan_id;
    nwk_req._8_4_ = *(undefined4 *)&req->dst_addr;
    nwk_req.dst_addr._0_4_ = *(undefined4 *)((int)&(req->dst_addr).u + 2);
    nwk_req.dst_addr.u.group_addr.bcast = *(ezb_shortaddr_t *)((int)&(req->dst_addr).u + 6);
    nwk_req._20_4_ = req->asdu;
    eVar1 = zmsg_add_footer(req,0x18);
    if (eVar1 == 0) {
      eVar1 = nwk_intrp_data_request(auStack_2c);
    }
  }
  return eVar1;
}

