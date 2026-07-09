/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> timer.o -> micro_timer_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void micro_timer_stop(undefined4 *param_1)

{
  undefined1 *puVar1;
  undefined4 *extraout_a1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar1 = s_tm_sched_micro;
  if (param_1 == (undefined4 *)0x0) {
    puVar1 = (undefined1 *)timer_init_part_0();
    param_1 = extraout_a1;
  }
  puVar2 = (undefined4 *)*param_1;
  if (puVar2 != param_1) {
    puVar3 = *(undefined4 **)(puVar1 + 0x10);
    puVar4 = (undefined4 *)(puVar1 + 0x10);
    if (puVar3 == param_1) {
      *(undefined4 **)(puVar1 + 0x10) = puVar2;
      tm_sched_set_alarm();
    }
    else {
      while (puVar3 != (undefined4 *)0x0) {
        puVar5 = (undefined4 *)*puVar4;
        if (puVar5 == param_1) {
          *puVar4 = puVar2;
          break;
        }
        puVar4 = puVar5;
        puVar3 = (undefined4 *)*puVar5;
      }
    }
    *param_1 = param_1;
  }
  return;
}

