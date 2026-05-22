/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  undefined4 uStack_24;
  ezb_extaddr_t dst_extaddr;
  nwk_nlde_data_req_t nlde_req;
  
  uStack_24 = 0;
  dst_extaddr.field_0.u64._0_4_ = 0;
  nwk_address_extended_by_short(&uStack_24);
  eVar1 = aps_process_transmit_security(&uStack_24,req->asdu);
  if (eVar1 == 0) {
    dst_extaddr.field_0.u64._4_4_ = req->asdu;
    eVar1 = nwk_nlde_data_request((undefined1 *)((int)&dst_extaddr.field_0 + 4));
  }
  return eVar1;
}

