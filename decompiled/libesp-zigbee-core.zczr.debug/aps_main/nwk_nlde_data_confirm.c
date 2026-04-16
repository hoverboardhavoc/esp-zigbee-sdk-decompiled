/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> nwk_nlde_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_nlde_data_confirm(nwk_nlde_data_cnf_t *cnf)

{
  uint error;
  byte abStack_11 [4];
  uint8_t fcf;
  
  error = aps_process_transmit_done_security(cnf->nsdu);
  if (error == 0) {
    if (cnf->status != 0) {
      error = cnf->status | 0x200;
    }
  }
  else {
    log_write(1,"aps_main.c","APS frame tx done (dst:0x%04x err:0x%02x) security failed 0x%x",
              cnf->dst_addr,cnf->status,error);
  }
  zmsg_read_bytes(cnf->nsdu,0,1,abStack_11);
  if ((abStack_11[0] & 3) == 0) {
    if ((abStack_11[0] & 0x40) == 0) {
      aps_send_confirm(cnf->nsdu,error);
    }
    else {
      zmsg_free(cnf->nsdu);
    }
  }
  else if ((abStack_11[0] & 3) == 1) {
    aps_send_cmd_confirm(cnf->nsdu,error);
  }
  else {
    zmsg_free(cnf->nsdu);
  }
  return;
}

