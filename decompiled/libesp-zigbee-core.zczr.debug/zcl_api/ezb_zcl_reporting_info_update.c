/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_api.o -> ezb_zcl_reporting_info_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_reporting_info_update
               (int param_1,undefined2 param_2,undefined2 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  *(undefined2 *)(param_1 + 0x10) = param_2;
  *(undefined2 *)(param_1 + 0x12) = param_3;
  uVar1 = param_4[1];
  *(undefined4 *)(param_1 + 0x18) = *param_4;
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  zcl_reporting_info_update();
  return;
}

