/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_hold_on
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void thermostat_weekly_schedule_hold_on(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 != (undefined1 *)0x0) {
    iVar1 = thermostat_srv_get_attr_desc(*param_1,0x23);
    iVar2 = thermostat_srv_get_attr_desc(*param_1,0x24);
    if ((iVar1 != 0) && (iVar2 != 0)) {
      uVar3 = (uint)**(ushort **)(iVar2 + 8);
      if ((**(char **)(iVar1 + 8) == '\x01') && ((uVar3 != 0 && (uVar3 < 0x5a1)))) {
        thermostat_weekly_schedule_loop_stop(*param_1);
        thermostat_weekly_schedule_hold(*param_1,0,uVar3 * 60000);
      }
    }
  }
  return;
}

