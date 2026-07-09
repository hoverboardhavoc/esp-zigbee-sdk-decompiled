/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> timer.o -> tm_sched_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void tm_sched_init(void)

{
  tm_sched_do_init(s_tm_sched_micro,&ezb_plat_micro_alarm_get_now,&ezb_plat_micro_alarm_start_at,
                   &ezb_plat_micro_alarm_stop);
  tm_sched_do_init(s_tm_sched_milli,&ezb_plat_milli_alarm_get_now,&ezb_plat_milli_alarm_start_at,
                   &ezb_plat_milli_alarm_stop);
  return;
}

