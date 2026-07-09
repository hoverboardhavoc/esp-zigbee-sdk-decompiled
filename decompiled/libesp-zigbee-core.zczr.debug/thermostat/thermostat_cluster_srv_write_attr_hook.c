/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void thermostat_cluster_srv_write_attr_hook(undefined4 param_1,uint param_2,char *param_3)

{
  int iVar1;
  
  if (param_2 == 0x1c) {
    iVar1 = thermostat_srv_get_attr_desc(0x1c);
    if ((iVar1 != 0) && (param_3 != (char *)0x0)) {
      if (**(char **)(iVar1 + 8) != *param_3) {
        thermostat_weekly_schedule_hold(param_1,1,0);
      }
    }
  }
  else if ((0x1b < param_2) && ((param_2 - 0x23 & 0xffff) < 2)) {
    thermostat_weekly_schedule_hold(1,0);
  }
  return;
}

