/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> reportable_change_is_present
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int reportable_change_is_present(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = zcl_attr_type_is_analog(param_3);
  if (iVar1 != 0) {
    if ((param_2 == 0) && (param_1 == 0xffff)) {
      iVar1 = 0;
    }
    else if (param_2 == 0xffff) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  return iVar1;
}

