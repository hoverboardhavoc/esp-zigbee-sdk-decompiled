/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_lqa_2_cost
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_lqa_2_cost(uint param_1)

{
  if (param_1 != 0) {
    if (param_1 < 0x11) {
      return 7;
    }
    if (param_1 < 0x21) {
      return 6;
    }
    if (param_1 < 0x41) {
      return 5;
    }
    if (param_1 < 0x61) {
      return 4;
    }
    if (param_1 < 0x81) {
      return 3;
    }
    if (param_1 < 0xc1) {
      return 2;
    }
    param_1 = 1;
  }
  return param_1;
}

