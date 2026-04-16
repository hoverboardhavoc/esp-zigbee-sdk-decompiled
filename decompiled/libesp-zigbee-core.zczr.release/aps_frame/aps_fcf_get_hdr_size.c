/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_fcf_get_hdr_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t aps_fcf_get_hdr_size(uint8_t fcf)

{
  _Bool _Var1;
  uint16_t uVar2;
  undefined3 extraout_var;
  
  _Var1 = aps_fcf_has_address(fcf);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    uVar2 = 2;
  }
  else {
    uVar2 = ((fcf & 0xc) == 0xc) + 8;
  }
  return uVar2;
}

