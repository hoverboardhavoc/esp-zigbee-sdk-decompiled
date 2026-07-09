/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> timer.o -> timer_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void timer_init(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *unaff_s0;
  undefined4 *unaff_s1;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *extraout_a1;
  
  if (param_1 != 0) {
    *(int *)param_1 = param_1;
    *(undefined4 *)(param_1 + 4) = param_2;
    *(undefined4 *)(param_1 + 8) = param_3;
    return;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/timer.c",0xbc,
                        "timer_init","tm != ((void *)0)");
  if (extraout_a1 == (int *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/timer.c",0x78,"tm_sched_add",
                  "tm != ((void *)0)");
  }
  else {
    uVar2 = (**(code **)(iVar1 + 0x14))(*(code **)(iVar1 + 0x14));
    tm_sched_remove(iVar1,extraout_a1);
    unaff_s0 = (undefined4 *)(iVar1 + 0x10);
    do {
      unaff_s1 = unaff_s0;
      unaff_s0 = (undefined4 *)*unaff_s1;
      if (unaff_s0 == (undefined4 *)0x0) break;
      iVar3 = timer_fire_before(extraout_a1,unaff_s0,uVar2);
    } while (iVar3 == 0);
  }
  *extraout_a1 = (int)unaff_s0;
  *unaff_s1 = extraout_a1;
  if (*(int **)(iVar1 + 0x10) == extraout_a1) {
    tm_sched_set_alarm(iVar1);
  }
  return;
}

