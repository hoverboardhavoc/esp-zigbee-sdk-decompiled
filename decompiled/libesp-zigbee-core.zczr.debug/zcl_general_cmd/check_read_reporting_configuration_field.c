/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> check_read_reporting_configuration_field
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 check_read_reporting_configuration_field(byte *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0x86;
  }
  else if (*(int *)(param_2 + 8) == 0) {
    uVar1 = 0x86;
  }
  else if ((*(byte *)(param_2 + 3) & 4) == 0) {
    uVar1 = 0x8c;
  }
  else {
    uVar1 = 0;
  }
  if (param_1 != (byte *)0x0) {
    if (*param_1 < 2) {
      return uVar1;
    }
    return 0x87;
  }
  return 0x87;
}

