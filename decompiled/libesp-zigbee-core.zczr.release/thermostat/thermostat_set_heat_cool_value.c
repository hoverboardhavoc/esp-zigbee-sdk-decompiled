/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_set_heat_cool_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void thermostat_set_heat_cool_value
               (undefined4 param_1,int param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  undefined2 uStack_14;
  undefined2 auStack_12 [3];
  
  uStack_14 = param_4;
  auStack_12[0] = param_3;
  iVar1 = thermostat_is_occupied();
  if (iVar1 == 0) {
    if (param_2 == 0) {
      puVar3 = auStack_12;
      uVar2 = 0x14;
    }
    else {
      if (param_2 != 1) {
        thermostat_srv_set_attr_value_isra_0(param_1,0x14,auStack_12);
      }
      puVar3 = &uStack_14;
      uVar2 = 0x13;
    }
  }
  else if (param_2 == 0) {
    puVar3 = auStack_12;
    uVar2 = 0x12;
  }
  else {
    if (param_2 != 1) {
      thermostat_srv_set_attr_value_isra_0(param_1,0x12,auStack_12);
    }
    puVar3 = &uStack_14;
    uVar2 = 0x11;
  }
  thermostat_srv_set_attr_value_isra_0(param_1,uVar2,puVar3);
  return;
}

