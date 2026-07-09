/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_err_to_zcl_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_err_to_zcl_status(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x89;
    if ((((param_1 != 0x101) && (uVar1 = 0x87, param_1 != 0x102)) &&
        (uVar1 = 0x8b, param_1 != 0x105)) && (uVar1 = 0x94, param_1 != 0x107)) {
      return 1;
    }
  }
  return uVar1;
}

