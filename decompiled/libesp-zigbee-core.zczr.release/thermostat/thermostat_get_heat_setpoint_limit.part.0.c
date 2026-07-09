/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_get_heat_setpoint_limit.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void thermostat_get_heat_setpoint_limit_part_0
               (undefined4 param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  
  iVar1 = thermostat_srv_get_attr_desc(0x15);
  iVar2 = thermostat_srv_get_attr_desc(param_1,3);
  if (iVar1 == 0) {
    uVar3 = 0x954d;
    if (iVar2 != 0) {
      puVar4 = *(undefined2 **)(iVar2 + 8);
      goto _L0;
    }
  }
  else {
    puVar4 = *(undefined2 **)(iVar1 + 8);
_L0:
    uVar3 = *puVar4;
  }
  *param_2 = uVar3;
  iVar1 = thermostat_srv_get_attr_desc(param_1,0x16);
  iVar2 = thermostat_srv_get_attr_desc(param_1,4);
  if (iVar1 == 0) {
    if (iVar2 == 0) {
      uVar3 = 0x7fff;
      goto _L0;
    }
    puVar4 = *(undefined2 **)(iVar2 + 8);
  }
  else {
    puVar4 = *(undefined2 **)(iVar1 + 8);
  }
  uVar3 = *puVar4;
_L0:
  *param_3 = uVar3;
  return;
}

