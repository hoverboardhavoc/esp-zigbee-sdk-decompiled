/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> timer.o -> tm_sched_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void tm_sched_remove(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_2 == (int *)0x0) {
    param_1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/timer.c",0x60,
                            "tm_sched_remove","tm != ((void *)0)");
  }
  else {
    param_3 = (int *)*param_2;
    if (param_3 == param_2) {
      return;
    }
    piVar2 = *(int **)(param_1 + 0x10);
    if (piVar2 != param_2) {
      piVar1 = (int *)(param_1 + 0x10);
      while (piVar2 != (int *)0x0) {
        piVar3 = (int *)*piVar1;
        if (piVar3 == param_2) {
          *piVar1 = (int)param_3;
          break;
        }
        piVar1 = piVar3;
        piVar2 = (int *)*piVar3;
      }
      goto _L0;
    }
  }
  *(int **)(param_1 + 0x10) = param_3;
  tm_sched_set_alarm();
_L0:
  *param_2 = (int)param_2;
  return;
}

