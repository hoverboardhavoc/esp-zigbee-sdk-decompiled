/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_attr_type_is_analog
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool zcl_attr_type_is_analog(uint param_1)

{
  bool bVar1;
  
  if (param_1 < 0x3b) {
    bVar1 = true;
    if (param_1 < 0x38) {
      return param_1 - 0x20 < 0x10;
    }
  }
  else {
    bVar1 = (param_1 + 0x20 & 0xff) < 3;
  }
  return bVar1;
}

