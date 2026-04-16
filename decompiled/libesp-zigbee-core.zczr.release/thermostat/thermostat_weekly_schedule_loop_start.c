/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_weekly_schedule_loop_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void thermostat_weekly_schedule_loop_start(uint8_t ep_id)

{
  weekly_schedule_context_t *pwVar1;
  
  pwVar1 = thermostat_weekly_schedule_context_get(ep_id);
  pwVar1->exec_daily = 0xff;
  pwVar1->exec_point = 0xff;
  milli_timer_stop();
  milli_timer_init(&pwVar1->loop_timer,thermostat_weekly_schedule_loop,pwVar1);
  milli_timer_start(&pwVar1->loop_timer,0);
  return;
}

