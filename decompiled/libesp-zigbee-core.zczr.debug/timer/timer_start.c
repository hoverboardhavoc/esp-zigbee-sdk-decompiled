/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> timer.o -> timer_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void timer_start(tm_sched_t *sched,timer_base *tm,uint32_t delay)

{
  time32_t tVar1;
  
  if (delay < 0x7fffffff) {
    tVar1 = timer_get_now(sched);
    timer_fire_at(sched,tm,(time32_t)(delay + tVar1.val));
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/timer.c",0xd3,"timer_start",
                "delay < ((0xffffffffUL) >> 1)");
  tm_sched_do_init(&s_tm_sched_micro,(_func_uint32_t *)&ezb_plat_micro_alarm_get_now,
                   (_func_void_uint32_t_uint32_t *)&ezb_plat_micro_alarm_start_at,
                   (_func_void *)&ezb_plat_micro_alarm_stop);
  tm_sched_do_init(&s_tm_sched_milli,(_func_uint32_t *)&ezb_plat_milli_alarm_get_now,
                   (_func_void_uint32_t_uint32_t *)&ezb_plat_milli_alarm_start_at,
                   (_func_void *)&ezb_plat_milli_alarm_stop);
  return;
}

