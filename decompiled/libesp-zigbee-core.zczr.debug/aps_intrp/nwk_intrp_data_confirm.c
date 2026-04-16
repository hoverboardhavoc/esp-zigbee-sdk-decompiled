/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_intrp.o -> nwk_intrp_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_intrp_data_confirm(nwk_intrp_data_cnf_t *cnf)

{
  uint error;
  byte abStack_11 [4];
  uint8_t fcf;
  
  abStack_11[0] = 0;
  zmsg_read_bytes(cnf->nsdu,0,1,abStack_11);
  if ((abStack_11[0] & 3) == 3) {
    if ((abStack_11[0] & 0xc) == 0xc) {
      zmsg_remove_header(cnf->nsdu,7);
    }
    else {
      zmsg_remove_header(cnf->nsdu,5);
    }
    if (cnf->status == 0) {
      error = 0;
    }
    else {
      error = cnf->status | 0x200;
    }
    aps_intrp_data_sent(cnf->nsdu,error);
  }
  else if (cnf->nsdu != (zmsg_t *)0x0) {
    zmsg_free();
  }
  return;
}

