/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> timer.o -> milli_timer_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void milli_timer_init(int param_1,timer_base *param_2,undefined4 param_3)

{
  int extraout_a0;
  timer_base *extraout_a1;
  
  if (param_1 == 0) {
    tm_sched_remove((tm_sched_t *)0x0,param_2);
    param_1 = extraout_a0;
    param_2 = extraout_a1;
  }
  *(int *)param_1 = param_1;
  *(timer_base **)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  return;
}

