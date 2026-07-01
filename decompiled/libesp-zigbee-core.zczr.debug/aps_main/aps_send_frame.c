/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_send_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: nlde_req */
/* WARNING: Unknown calling convention */

ezb_err_t aps_send_frame(ezb_shortaddr_t dst_addr,aps_apsde_data_req_t *req)

{
  int iVar1;
  ezb_err_t eVar2;
  undefined4 uStack_24;
  ezb_extaddr_t dst_extaddr;
  nwk_nlde_data_req_t nlde_req;
  
  if ((req->asdu->flags & 4) == 0) {
    uStack_24 = 0;
    dst_extaddr.field_0.u64._0_4_ = 0;
    nwk_address_extended_by_short(&uStack_24);
    iVar1 = aps_process_transmit_security(&uStack_24,req->asdu);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  dst_extaddr.field_0.u64._4_4_ = req->asdu;
  eVar2 = nwk_nlde_data_request((undefined1 *)((int)&dst_extaddr.field_0 + 4));
  return eVar2;
}

