/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_context_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 thermostat_weekly_schedule_context_get(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = thermostat_srv_get_attr_desc(0xeff0);
  if (iVar1 != 0) {
    return *(undefined4 *)(iVar1 + 8);
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/thermostat.c",0x137,
                "thermostat_weekly_schedule_context_get","sched_ctx_attr_desc");
  iVar1 = thermostat_srv_get_attr_desc(0x23);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if (**(char **)(iVar1 + 8) == '\0') {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

