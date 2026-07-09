/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_core.o -> zdp_status_to_err
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdp_status_to_err(uint param_1)

{
  if (param_1 == 0x84) {
    return 6;
  }
  if (param_1 < 0x85) {
    if (param_1 == 0) {
      return 0;
    }
    if (param_1 == 0x80) {
      return 2;
    }
    return 0xffffffff;
  }
  if (param_1 == 0x85) {
    return 7;
  }
  if (param_1 == 0x8a) {
    return 1;
  }
  return 0xffffffff;
}

