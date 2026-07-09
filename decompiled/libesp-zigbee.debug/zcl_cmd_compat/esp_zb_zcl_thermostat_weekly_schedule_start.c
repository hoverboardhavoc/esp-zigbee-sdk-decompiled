/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_thermostat_weekly_schedule_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_thermostat_weekly_schedule_start(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = get_endpoint_by_cluster(0x201,1);
  if (iVar1 == 0) {
    uVar2 = 0x105;
  }
  else {
    ezb_zcl_thermostat_weekly_schedule_loop_start();
    uVar2 = 0;
  }
  return uVar2;
}

