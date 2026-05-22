/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_send_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: dst_extaddr */
/* WARNING: Unknown calling convention */

ezb_err_t aps_send_frame(ezb_shortaddr_t dst_addr,aps_apsde_data_req_t *req)

{
  ezb_err_t eVar1;
  zmsg_t *pzStack_24;
  nwk_nlde_data_req_t nlde_req;
  ezb_extaddr_t dst_extaddr;
  
  nlde_req.alias_src_addr = 0;
  nlde_req._10_2_ = 0;
  nwk_address_extended_by_short(&nlde_req.alias_src_addr);
  eVar1 = aps_process_transmit_security(&nlde_req.alias_src_addr,req->asdu);
  if (eVar1 == 0) {
    pzStack_24 = req->asdu;
    nlde_req.nsdu = (zmsg_t *)CONCAT13(req->alias_seq_num,CONCAT12(req->radius,dst_addr));
    nlde_req._4_4_ =
         CONCAT12((char)((*(uint *)&req->field_0x18 >> 4 & 1) << 2),req->alias_src_addr) | 0x30000;
    eVar1 = nwk_nlde_data_request(&pzStack_24);
  }
  return eVar1;
}

