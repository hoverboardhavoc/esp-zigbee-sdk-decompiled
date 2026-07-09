/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_status_to_err
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_status_to_err(uint param_1)

{
  if (param_1 == 0x89) {
    return 1;
  }
  if (param_1 < 0x8a) {
    if (param_1 == 0x85) {
      return 4;
    }
    if (0x85 < param_1) {
      if (param_1 == 0x87) {
        return 2;
      }
      return 0xffffffff;
    }
    if (param_1 == 0) {
      return 0;
    }
    if (param_1 == 0x7e) {
      return 3;
    }
    return 0xffffffff;
  }
  if (param_1 == 0x95) {
    return 8;
  }
  if (0x95 < param_1) {
    if (param_1 == 0x97) {
      return 0xc;
    }
    return 0xffffffff;
  }
  if (param_1 == 0x8b) {
    return 5;
  }
  if (param_1 == 0x94) {
    return 7;
  }
  return 0xffffffff;
}

