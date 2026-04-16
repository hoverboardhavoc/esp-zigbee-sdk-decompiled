/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> timer.o -> micro_timer_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void micro_timer_init(micro_timer_t *tm,timer_func_t timer_func,void *user_ctx)

{
  micro_timer_t *extraout_a0;
  timer_func_t extraout_a1;
  
  if (tm == (micro_timer_t *)0x0) {
    tm_sched_remove((tm_sched_t *)0x0,(timer_base *)timer_func);
    tm = extraout_a0;
    timer_func = extraout_a1;
  }
  tm->next = tm;
  tm->timer_func = timer_func;
  tm->user_ctx = user_ctx;
  return;
}

