/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> secur_ic.o -> ic_crc_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ic_crc_offset(uint param_1)

{
  if (param_1 == 2) {
    return 0xc;
  }
  if (2 < param_1) {
    if (param_1 == 3) {
      return 0x10;
    }
    return 0;
  }
  if (param_1 == 0) {
    return 6;
  }
  if (param_1 == 1) {
    return 8;
  }
  return 0;
}

