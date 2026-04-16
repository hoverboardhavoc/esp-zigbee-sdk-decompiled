/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_intrp.o -> nwk_intrp_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_intrp_data_confirm(nwk_intrp_data_cnf_t *cnf)

{
  zmsg_t *pzVar1;
  undefined4 uVar2;
  byte bStack_41;
  undefined1 auStack_40 [3];
  uint8_t fcf;
  aps_intrp_data_req_t req;
  aps_intrp_data_cnf_t cnf_1;
  
  bStack_41 = 0;
  zmsg_read_bytes(cnf->nsdu,0,1,&bStack_41);
  if ((bStack_41 & 3) == 3) {
    uVar2 = 7;
    if ((bStack_41 & 0xc) != 0xc) {
      uVar2 = 5;
    }
    zmsg_remove_header(uVar2);
    pzVar1 = cnf->nsdu;
    memset(auStack_40,0,0x18);
    zmsg_get_footer(pzVar1,auStack_40,0x18);
    zmsg_remove_footer(pzVar1,0x18);
    memcpy(&req.asdu,&req,10);
    aps_intrp_data_confirm((aps_intrp_data_cnf_t *)&req.asdu);
  }
  else if (cnf->nsdu != (zmsg_t *)0x0) {
    zmsg_free();
  }
  return;
}

