/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_fcf_has_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_fcf_has_address(uint8_t fcf)

{
  _Bool _Var1;
  
  _Var1 = true;
  if ((fcf & 3) == 1) {
    _Var1 = false;
  }
  else if ((fcf & 3) == 2) {
    return (_Bool)(fcf >> 4 & 1 ^ 1);
  }
  return _Var1;
}

