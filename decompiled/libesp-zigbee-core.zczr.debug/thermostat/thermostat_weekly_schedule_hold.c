/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_hold
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void thermostat_weekly_schedule_hold(uint8_t ep_id,_Bool is_on,uint32_t delay)

{
  weekly_schedule_context_t *pwVar1;
  undefined3 in_register_0000202d;
  code *pcVar2;
  milli_timer_t *pmVar3;
  
  pwVar1 = thermostat_weekly_schedule_context_get(ep_id);
  if (pwVar1 != (weekly_schedule_context_t *)0x0) {
    pmVar3 = &pwVar1->hold_timer;
    milli_timer_stop(pmVar3);
    if (CONCAT31(in_register_0000202d,is_on) == 0) {
      pcVar2 = thermostat_weekly_schedule_hold_off;
    }
    else {
      pcVar2 = thermostat_weekly_schedule_hold_on;
    }
    milli_timer_init(pmVar3,pcVar2,pwVar1);
    milli_timer_start(pmVar3,delay);
  }
  return;
}

