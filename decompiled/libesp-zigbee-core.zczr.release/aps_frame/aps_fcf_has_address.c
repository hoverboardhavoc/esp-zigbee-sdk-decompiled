/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_fcf_has_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint aps_fcf_has_address(uint param_1)

{
  uint uVar1;
  
  uVar1 = 1;
  if ((param_1 & 3) == 1) {
    uVar1 = 0;
  }
  else if ((param_1 & 3) == 2) {
    return param_1 >> 4 & 1 ^ 1;
  }
  return uVar1;
}

