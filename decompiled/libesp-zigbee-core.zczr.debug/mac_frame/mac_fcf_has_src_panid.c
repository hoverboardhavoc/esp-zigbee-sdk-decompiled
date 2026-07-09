/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_fcf_has_src_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_fcf_has_src_panid(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x4000) {
    uVar1 = 0;
  }
  else if ((param_1 & 0x40) == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  if (((param_1 & 0x3000) != 0) && ((param_1 & 0xffffcc00) == 0xcc00)) {
    return 0;
  }
  return uVar1;
}

