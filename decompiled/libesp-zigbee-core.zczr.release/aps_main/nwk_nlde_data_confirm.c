/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> nwk_nlde_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_nlde_data_confirm(nwk_nlde_data_cnf_t *cnf)

{
  uint error;
  undefined4 uVar1;
  byte abStack_11 [4];
  uint8_t fcf;
  
  zmsg_read_bytes(cnf->nsdu,0,1,abStack_11);
  if (((abStack_11[0] & 3) == 2) ||
     (error = aps_process_transmit_done_security(cnf->nsdu), error == 0)) {
    error = 0;
    if (cnf->status != 0) {
      error = cnf->status | 0x200;
    }
  }
  else {
    uVar1 = aps_frame_type_str(abStack_11[0] & 3);
    log_write(1,"aps_main.c","APS %s frame (dst:0x%04x err:0x%02x) tx done security failed 0x%x",
              uVar1,cnf->dst_addr,cnf->status,error);
  }
  if ((abStack_11[0] & 0x40) == 0) {
    aps_send_frame_confirm(cnf->nsdu,error);
  }
  else {
    zmsg_free(cnf->nsdu);
  }
  return;
}

