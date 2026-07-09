/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> compat.o -> esp_zb_scheduler_user_alarm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_scheduler_user_alarm(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  byte bStack_14;
  
  bStack_14 = bStack_14 | 1;
  local_20 = 0;
  uStack_1c = param_1;
  uStack_18 = param_2;
  esp_zb_run_alarm_isra_0(&uStack_1c,param_3,&local_20);
  return local_20;
}

