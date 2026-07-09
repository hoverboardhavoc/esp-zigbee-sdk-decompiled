/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> power_config.o -> power_config_check_battery_percentage_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void power_config_check_battery_percentage_value(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 != (undefined1 *)0x0) {
    if (param_1 == 0x21) {
      uVar2 = 1;
      uVar1 = 0x20;
    }
    else if (param_1 == 0x41) {
      uVar2 = 2;
      uVar1 = 0x40;
    }
    else {
      if (param_1 != 0x61) {
        return;
      }
      uVar2 = 3;
      uVar1 = 0x60;
    }
    power_config_check_battery_voltage_or_percentage(*param_2,uVar1,1,uVar2);
  }
  return;
}

