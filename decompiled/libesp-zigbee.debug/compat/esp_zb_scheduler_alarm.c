/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> compat.o -> esp_zb_scheduler_alarm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_scheduler_alarm(undefined4 param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  
  uVar1 = 0;
  while( true ) {
    if (7 < uVar1) {
      return;
    }
    if ((&s_alarms)[uVar1] == 0) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  uStack_14 = 0;
  uStack_18 = param_2 & 0xff;
  uStack_1c = param_1;
  esp_zb_run_alarm(&uStack_1c,param_3);
  return;
}

