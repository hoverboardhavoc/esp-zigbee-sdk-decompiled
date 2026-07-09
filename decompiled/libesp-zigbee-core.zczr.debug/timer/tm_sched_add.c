/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> timer.o -> tm_sched_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void tm_sched_add(int param_1,int *param_2)

{
  undefined4 *unaff_s0;
  undefined4 *unaff_s1;
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/timer.c",0x78,"tm_sched_add",
                  "tm != ((void *)0)");
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x14))(*(code **)(param_1 + 0x14));
    tm_sched_remove(param_1,param_2);
    unaff_s0 = (undefined4 *)(param_1 + 0x10);
    do {
      unaff_s1 = unaff_s0;
      unaff_s0 = (undefined4 *)*unaff_s1;
      if (unaff_s0 == (undefined4 *)0x0) break;
      iVar2 = timer_fire_before(param_2,unaff_s0,uVar1);
    } while (iVar2 == 0);
  }
  *param_2 = (int)unaff_s0;
  *unaff_s1 = param_2;
  if (*(int **)(param_1 + 0x10) == param_2) {
    tm_sched_set_alarm(param_1);
  }
  return;
}

