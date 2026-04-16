/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> ezb_zcl_thermostat_get_weekly_schedule_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_thermostat_weekly_schedule_entry_t *
ezb_zcl_thermostat_get_weekly_schedule_entry(uint8_t ep_id,uint8_t day_of_week)

{
  weekly_schedule_context_t *pwVar1;
  undefined3 in_register_0000202d;
  
  pwVar1 = thermostat_weekly_schedule_context_get(ep_id);
  if (pwVar1 != (weekly_schedule_context_t *)0x0) {
    if (CONCAT31(in_register_0000202d,day_of_week) < 7) {
      pwVar1 = (weekly_schedule_context_t *)
               pwVar1->graph[CONCAT31(in_register_0000202d,day_of_week)];
    }
    else {
      pwVar1 = (weekly_schedule_context_t *)0x0;
    }
  }
  return (ezb_zcl_thermostat_weekly_schedule_entry_t *)pwVar1;
}

