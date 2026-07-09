/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_alarms_alarm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_alarms_alarm_handler(undefined2 *param_1,code *param_2)

{
  undefined1 uVar1;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined2 uStack_12;
  
  uStack_16 = param_1[1];
  uStack_14 = *(undefined1 *)(param_1 + 6);
  uStack_18 = *param_1;
  uStack_13 = 0;
  uStack_12 = param_1[7];
  if (param_2 != (code *)0x0) {
    (*param_2)(0x34,&uStack_18,param_2);
    uVar1 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 8) = uVar1;
  }
  return;
}

