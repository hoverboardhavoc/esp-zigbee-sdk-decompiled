/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> compat.o -> esp_zb_scheduler_alarm_cancel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_scheduler_alarm_cancel(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = &s_alarms;
  iVar1 = 0;
  while (((iVar2 = *piVar3, iVar2 == 0 || (*(int *)(iVar2 + 4) != param_1)) ||
         (*(byte *)(iVar2 + 8) != param_2))) {
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
    if (iVar1 == 8) {
      return;
    }
  }
  esp_zb_cancel_alarm();
  (&s_alarms)[iVar1] = 0;
  return;
}

