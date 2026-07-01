/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_send_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_send_frame(ezb_shortaddr_t dst_addr,aps_apsde_data_req_t *req)

{
  undefined2 uVar1;
  int iVar2;
  ezb_err_t eVar3;
  zmsg_t *pzStack_1c;
  nwk_nlde_data_req_t nlde_req;
  
  if ((req->asdu->flags & 4) == 0) {
    pzStack_1c = (zmsg_t *)0x0;
    nlde_req.nsdu = (zmsg_t *)0x0;
    nwk_address_extended_by_short(&pzStack_1c);
    iVar2 = aps_process_transmit_security(&pzStack_1c,req->asdu);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  pzStack_1c = req->asdu;
  nlde_req._6_2_ = (byte)(*(uint *)&req->field_9 >> 2) & 0xff04 | 3;
  nlde_req.dst_addr = req->alias_src_addr;
  uVar1._0_1_ = req->radius;
  uVar1._1_1_ = req->alias_seq_num;
  nlde_req.nsdu = (zmsg_t *)CONCAT22(uVar1,dst_addr);
  eVar3 = nwk_nlde_data_request(&pzStack_1c);
  return eVar3;
}

