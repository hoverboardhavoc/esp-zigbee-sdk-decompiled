/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_intrp.o -> nwk_handle_intrp_data_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_intrp_data_sent(zmsg_t *msg,ezb_err_t error)

{
  zmsg_t *apzStack_24 [3];
  undefined1 auStack_18 [4];
  nwk_intrp_data_cnf_t cnf;
  
  apzStack_24[0] = msg;
  zmsg_remove_header(2);
  auStack_18 = (undefined1  [4])nwk_intrp_msg_transfer_ownership(apzStack_24);
  cnf.nsdu._0_1_ = (undefined1)error;
  nwk_intrp_data_confirm((nwk_intrp_data_cnf_t *)auStack_18);
  if (apzStack_24[0] != (zmsg_t *)0x0) {
    zmsg_free();
  }
  return;
}

