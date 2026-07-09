/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> timer.o -> tm_sched_set_alarm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void tm_sched_set_alarm(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0) {
    (**(code **)(param_1 + 0x1c))(*(code **)(param_1 + 0x1c));
  }
  else {
    iVar2 = (**(code **)(param_1 + 0x14))(*(code **)(param_1 + 0x14));
    iVar2 = *(int *)(iVar1 + 0xc) - iVar2;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    (**(code **)(param_1 + 0x18))(iVar2,*(code **)(param_1 + 0x18));
  }
  return;
}

