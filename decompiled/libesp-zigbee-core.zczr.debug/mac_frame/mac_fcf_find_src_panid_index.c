/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_fcf_find_src_panid_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t mac_fcf_find_src_panid_index(uint16_t fcf)

{
  _Bool _Var1;
  uint8_t uVar2;
  undefined3 extraout_var;
  
  _Var1 = mac_fcf_has_src_panid(fcf);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    uVar2 = 0xff;
  }
  else {
    uVar2 = mac_fcf_skip_dstaddr_index(fcf);
  }
  return uVar2;
}

