/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_weekly_schedule_hold_on
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010798) */

void thermostat_weekly_schedule_hold_on(undefined1 *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (undefined1 *)0x0) {
    return;
  }
  iVar2 = thermostat_srv_get_attr_desc(*param_1,0x23);
  iVar3 = thermostat_srv_get_attr_desc(*param_1,0x24);
  if ((((iVar2 != 0) && (iVar3 != 0)) && (**(char **)(iVar2 + 8) == '\x01')) &&
     (uVar1 = **(ushort **)(iVar3 + 8), (uVar1 - 1 & 0xffff) < 0x5a0)) {
    thermostat_weekly_schedule_loop_stop(*param_1);
    iVar2 = thermostat_weekly_schedule_context_get(*param_1);
    if (iVar2 != 0) {
      milli_timer_stop();
      milli_timer_init(thermostat_weekly_schedule_hold_off,iVar2);
      milli_timer_start(iVar2 + 0x24,(uint)uVar1 * 60000);
      return;
    }
    return;
  }
  return;
}

