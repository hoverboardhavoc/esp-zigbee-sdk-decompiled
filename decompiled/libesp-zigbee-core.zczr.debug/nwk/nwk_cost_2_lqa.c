/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_cost_2_lqa
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_cost_2_lqa(int param_1)

{
  if (param_1 != 0) {
    if (param_1 == 1) {
      return 0xe0;
    }
    if (param_1 == 2) {
      return 0xa0;
    }
    if (param_1 == 3) {
      return 0x70;
    }
    if (param_1 == 4) {
      return 0x50;
    }
    if (param_1 == 5) {
      return 0x30;
    }
    if (param_1 == 6) {
      return 0x18;
    }
    param_1 = 8;
  }
  return param_1;
}

