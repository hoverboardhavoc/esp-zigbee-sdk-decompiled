/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> esp_zigbee.o -> esp_zigbee_err_to_esp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint esp_zigbee_err_to_esp(uint param_1)

{
  if ((param_1 != 0) && (param_1 != 0xffffffff)) {
    if ((param_1 >> 8 & 0xff) == 0) {
      return (param_1 & 0xff) + 0x100;
    }
    param_1 = 0xffffffff;
  }
  return param_1;
}

