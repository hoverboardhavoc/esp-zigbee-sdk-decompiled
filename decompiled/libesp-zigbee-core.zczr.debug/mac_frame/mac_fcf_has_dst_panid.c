/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_fcf_has_dst_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool mac_fcf_has_dst_panid(uint param_1)

{
  if ((param_1 & 0x3000) != 0x2000) {
    return (param_1 & 0xc00) != 0;
  }
  param_1 = param_1 & 0xffffcc40;
  if (param_1 == 0x8040) {
    return false;
  }
  if (0x8040 < param_1) {
    if (param_1 == 0xc040) {
      return false;
    }
    if (param_1 != 0xcc40) {
      if (param_1 != 0xc000) {
        return true;
      }
      return false;
    }
    return false;
  }
  if (param_1 == 0xc40) {
    return false;
  }
  if (0xc40 < param_1) {
    if (param_1 != 0x8000) {
      return true;
    }
    return false;
  }
  if (param_1 == 0) {
    return false;
  }
  if (param_1 != 0x840) {
    return true;
  }
  return false;
}

