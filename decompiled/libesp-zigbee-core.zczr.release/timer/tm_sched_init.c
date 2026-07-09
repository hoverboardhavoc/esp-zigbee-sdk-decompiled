/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> timer.o -> tm_sched_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void tm_sched_init(void)

{
  s_tm_sched_micro._16_4_ = 0;
  tasklet_init(s_tm_sched_micro,tm_sched_process_timers_task,s_tm_sched_micro);
  s_tm_sched_micro._20_4_ = &ezb_plat_micro_alarm_get_now;
  s_tm_sched_micro._24_4_ = &ezb_plat_micro_alarm_start_at;
  s_tm_sched_micro._28_4_ = &ezb_plat_micro_alarm_stop;
  s_tm_sched_milli._16_4_ = 0;
  tasklet_init(s_tm_sched_milli,tm_sched_process_timers_task,s_tm_sched_milli);
  s_tm_sched_milli._20_4_ = &ezb_plat_milli_alarm_get_now;
  s_tm_sched_milli._24_4_ = &ezb_plat_milli_alarm_start_at;
  s_tm_sched_milli._28_4_ = &ezb_plat_milli_alarm_stop;
  return;
}

