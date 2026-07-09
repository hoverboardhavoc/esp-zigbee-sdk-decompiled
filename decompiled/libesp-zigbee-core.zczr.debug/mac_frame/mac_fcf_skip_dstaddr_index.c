/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_fcf_skip_dstaddr_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint mac_fcf_skip_dstaddr_index(uint param_1)

{
  uint uVar1;
  
  uVar1 = mac_fcf_skip_dst_panid_index();
  param_1 = param_1 & 0xc00;
  if (param_1 != 0) {
    if (param_1 == 0x800) {
      uVar1 = uVar1 + 2 & 0xff;
    }
    else if (param_1 == 0xc00) {
      uVar1 = uVar1 + 8 & 0xff;
    }
  }
  return uVar1;
}

