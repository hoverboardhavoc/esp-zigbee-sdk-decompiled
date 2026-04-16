/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> timer.o -> tm_sched_do_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void tm_sched_do_init(tm_sched_t *sched,_func_uint32_t *get_now,
                     _func_void_uint32_t_uint32_t *alarm_start_at,_func_void *alarm_stop)

{
  sched->timer_list = (timer_base *)0x0;
  tasklet_init(tm_sched_process_timers_task,sched);
  sched->get_now = get_now;
  sched->alarm_start_at = alarm_start_at;
  sched->alarm_stop = alarm_stop;
  return;
}

