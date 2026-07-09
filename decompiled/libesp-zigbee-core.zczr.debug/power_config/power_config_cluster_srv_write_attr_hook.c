/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> power_config.o -> power_config_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void power_config_cluster_srv_write_attr_hook(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    power_config_check_mains_voltage();
  }
  else if (((param_1 == 0x20) || (param_1 == 0x40)) || (param_1 == 0x60)) {
    power_config_check_battery_value(param_1);
  }
  else if (((param_1 == 0x21) || (param_1 == 0x41)) || (param_1 == 0x61)) {
    power_config_check_battery_percentage_value(param_1,param_2);
  }
  return;
}

