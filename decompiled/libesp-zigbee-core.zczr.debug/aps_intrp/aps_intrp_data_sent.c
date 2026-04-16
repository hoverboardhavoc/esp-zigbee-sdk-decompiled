/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_intrp.o -> aps_intrp_data_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_intrp_data_sent(zmsg_t *msg,ezb_err_t error)

{
  zmsg_t *pzStack_44;
  undefined1 auStack_40 [4];
  aps_intrp_data_cnf_t cnf;
  aps_intrp_data_req_t req;
  
  cnf.asdu = (zmsg_t *)0x0;
  pzStack_44 = msg;
  zmsg_get_footer(&cnf.asdu,0x18);
  zmsg_remove_footer(pzStack_44,0x18);
  cnf.status = '\0';
  cnf._17_3_ = 0;
  auStack_40 = (undefined1  [4])0x0;
  cnf.dst_addr._0_4_ = 0;
  cnf.dst_addr.u._2_4_ = 0;
  cnf._8_4_ = 0;
  cnf._12_4_ = error & 0xff;
  cnf._16_4_ = aps_intrp_msg_transfer_ownership(&pzStack_44);
  aps_intrp_data_confirm((aps_intrp_data_cnf_t *)auStack_40);
  if (pzStack_44 != (zmsg_t *)0x0) {
    zmsg_free();
  }
  return;
}

