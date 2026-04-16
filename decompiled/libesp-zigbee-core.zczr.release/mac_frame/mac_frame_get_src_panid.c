/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_frame_get_src_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_frame_get_src_panid(ezb_radio_frame_t *frame,ezb_panid_t *panid)

{
  uint16_t fcf;
  uint16_t *puVar1;
  _Bool _Var2;
  uint8_t uVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  ezb_err_t eVar4;
  
  puVar1 = (uint16_t *)frame->psdu;
  fcf = *puVar1;
  _Var2 = mac_fcf_has_src_panid(fcf);
  if (CONCAT31(extraout_var,_Var2) == 0) {
    eVar4 = 0x10;
  }
  else {
    uVar3 = mac_fcf_skip_dstaddr_index(fcf);
    eVar4 = 0;
    *panid = *(ezb_panid_t *)((int)puVar1 + CONCAT31(extraout_var_00,uVar3));
  }
  return eVar4;
}

