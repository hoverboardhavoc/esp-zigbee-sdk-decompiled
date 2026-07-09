/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_fcf_has_src_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint mac_fcf_has_src_panid(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (0x3fff < param_1) {
    uVar1 = param_1 >> 6 & 1 ^ 1;
  }
  if ((param_1 >> 0xc & 3) != 0) {
    uVar1 = uVar1 & (param_1 & 0xffffcc00) != 0xcc00;
  }
  return uVar1;
}

