/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> power_config.o -> power_config_check_battery_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void power_config_check_battery_value(undefined1 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 != (undefined1 *)0x0) {
    if (param_2 == 0x20) {
      uVar1 = 1;
    }
    else if (param_2 == 0x40) {
      uVar1 = 2;
    }
    else {
      if (param_2 != 0x60) {
        return;
      }
      uVar1 = 3;
    }
    power_config_check_battery_voltage_or_percentage(*param_1,0,uVar1);
  }
  return;
}

