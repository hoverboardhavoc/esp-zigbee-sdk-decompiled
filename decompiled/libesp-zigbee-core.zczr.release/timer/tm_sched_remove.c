/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> timer.o -> tm_sched_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void tm_sched_remove(int param_1,int *param_2)

{
  int *extraout_a1;
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_2 == (int *)0x0) {
    param_1 = timer_init_part_0();
    param_2 = extraout_a1;
  }
  piVar1 = (int *)*param_2;
  if (piVar1 != param_2) {
    piVar2 = *(int **)(param_1 + 0x10);
    piVar3 = (int *)(param_1 + 0x10);
    if (piVar2 == param_2) {
      *(int **)(param_1 + 0x10) = piVar1;
      tm_sched_set_alarm();
    }
    else {
      while (piVar2 != (int *)0x0) {
        piVar4 = (int *)*piVar3;
        if (piVar4 == param_2) {
          *piVar3 = (int)piVar1;
          break;
        }
        piVar3 = piVar4;
        piVar2 = (int *)*piVar4;
      }
    }
    *param_2 = (int)param_2;
  }
  return;
}

