/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> timer.o -> FUN_000102cc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void FUN_000102cc(tm_sched_t *param_1,timer_base *param_2,uint param_3)

{
  time32_t tVar1;
  
  if (param_3 < 0x7fffffff) {
    tVar1 = timer_get_now(param_1);
    timer_fire_at(param_1,param_2,(time32_t)(param_3 + tVar1.val));
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/common/timer.c",0xd3,"timer_start",0x102ac);
  tm_sched_do_init(&s_tm_sched_micro,(_func_uint32_t *)&ezb_plat_micro_alarm_get_now,
                   (_func_void_uint32_t_uint32_t *)&ezb_plat_micro_alarm_start_at,
                   (_func_void *)&ezb_plat_micro_alarm_stop);
  tm_sched_do_init(&s_tm_sched_milli,(_func_uint32_t *)&ezb_plat_milli_alarm_get_now,
                   (_func_void_uint32_t_uint32_t *)&ezb_plat_milli_alarm_start_at,
                   (_func_void *)&ezb_plat_milli_alarm_stop);
  return;
}

