/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_status_to_err
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_status_to_err(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0x89) {
    uVar1 = 1;
  }
  else if (param_1 < 0x8a) {
    uVar1 = 4;
    if (param_1 != 0x85) {
      if (param_1 < 0x86) {
        uVar1 = 0;
        if ((param_1 != 0) && (uVar1 = 0xffffffff, param_1 == 0x7e)) {
          return 3;
        }
      }
      else {
        uVar1 = 0xffffffff;
        if (param_1 == 0x87) {
          return 2;
        }
      }
    }
  }
  else {
    uVar1 = 8;
    if (param_1 != 0x95) {
      if (param_1 < 0x96) {
        uVar1 = 5;
        if ((param_1 != 0x8b) && (uVar1 = 0xffffffff, param_1 == 0x94)) {
          return 7;
        }
      }
      else {
        uVar1 = 0xffffffff;
        if (param_1 == 0x97) {
          return 0xc;
        }
      }
    }
  }
  return uVar1;
}

