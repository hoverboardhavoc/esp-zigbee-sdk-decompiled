/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_get_utc_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint32_t thermostat_weekly_schedule_get_utc_time(uint8_t ep_id)

{
  undefined3 in_register_00002029;
  uint32_t uVar1;
  uint uVar2;
  
  uVar1 = zcl_time_get_utc_time(CONCAT31(in_register_00002029,ep_id));
  if (uVar1 == 0xffffffff) {
    uVar2 = milli_timer_get_now();
    uVar1 = uVar2 / 1000;
  }
  return uVar1;
}

