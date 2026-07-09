/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_get_heat_cool_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void thermostat_get_heat_cool_desc(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = thermostat_is_occupied();
  if (iVar1 == 0) {
    uVar2 = thermostat_srv_get_attr_desc(param_1,0x14);
    *param_2 = uVar2;
    uVar2 = thermostat_srv_get_attr_desc(param_1,0x13);
    *param_3 = uVar2;
  }
  else {
    uVar2 = thermostat_srv_get_attr_desc(param_1,0x12);
    *param_2 = uVar2;
    uVar2 = thermostat_srv_get_attr_desc(param_1,0x11);
    *param_3 = uVar2;
  }
  return;
}

