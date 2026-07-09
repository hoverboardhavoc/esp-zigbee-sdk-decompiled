/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_get_heat_setpoint_limit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void thermostat_get_heat_setpoint_limit(undefined4 param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  if ((param_2 != (undefined2 *)0x0) && (param_3 != (undefined2 *)0x0)) {
    iVar1 = thermostat_srv_get_attr_desc(0x15);
    iVar2 = thermostat_srv_get_attr_desc(param_1,3);
    if (iVar1 == 0) {
      if (iVar2 == 0) {
        uVar3 = 0x954d;
      }
      else {
        uVar3 = **(undefined2 **)(iVar2 + 8);
      }
    }
    else {
      uVar3 = **(undefined2 **)(iVar1 + 8);
    }
    *param_2 = uVar3;
    iVar1 = thermostat_srv_get_attr_desc(param_1,0x16);
    iVar2 = thermostat_srv_get_attr_desc(param_1,4);
    if (iVar1 == 0) {
      if (iVar2 == 0) {
        uVar3 = 0x7fff;
      }
      else {
        uVar3 = **(undefined2 **)(iVar2 + 8);
      }
    }
    else {
      uVar3 = **(undefined2 **)(iVar1 + 8);
    }
    *param_3 = uVar3;
  }
  return;
}

