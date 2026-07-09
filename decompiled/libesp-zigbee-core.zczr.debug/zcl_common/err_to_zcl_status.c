/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> err_to_zcl_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 err_to_zcl_status(int param_1)

{
  if (param_1 == 4) {
    return 0x85;
  }
  if (param_1 < 5) {
    if (param_1 == 2) {
      return 0x87;
    }
    if (2 < param_1) {
      if (param_1 == 3) {
        return 0x7e;
      }
      return 1;
    }
    if (param_1 == 0) {
      return 0;
    }
    if (param_1 == 1) {
      return 0x89;
    }
    return 1;
  }
  if (param_1 == 8) {
    return 0x95;
  }
  if (8 < param_1) {
    if (param_1 == 0xc) {
      return 0x97;
    }
    return 1;
  }
  if (param_1 == 5) {
    return 0x8b;
  }
  if (param_1 == 7) {
    return 0x94;
  }
  return 1;
}

