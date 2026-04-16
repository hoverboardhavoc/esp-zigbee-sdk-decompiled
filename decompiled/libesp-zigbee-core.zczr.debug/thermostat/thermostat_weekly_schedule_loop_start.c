/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_loop_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void thermostat_weekly_schedule_loop_start(uint8_t ep_id)

{
  milli_timer_t *pmVar1;
  weekly_schedule_context_t *pwVar2;
  
  pwVar2 = thermostat_weekly_schedule_context_get(ep_id);
  pwVar2->exec_daily = 0xff;
  pwVar2->exec_point = 0xff;
  pmVar1 = &pwVar2->loop_timer;
  milli_timer_stop(pmVar1);
  milli_timer_init(pmVar1,thermostat_weekly_schedule_loop,pwVar2);
  milli_timer_start(pmVar1,0);
  return;
}

