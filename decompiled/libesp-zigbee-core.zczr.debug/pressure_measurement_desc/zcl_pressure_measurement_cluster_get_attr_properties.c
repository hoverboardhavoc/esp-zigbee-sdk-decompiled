/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> pressure_measurement_desc.o -> zcl_pressure_measurement_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_pressure_measurement_cluster_get_attr_properties
          (int param_1,uint param_2,char *param_3,char *param_4)

{
  if (param_3 == (char *)0x0) {
    return 2;
  }
  if (param_4 == (char *)0x0) {
    return 2;
  }
  if ((param_1 - 1U & 0xffff) < 2) {
    if (param_1 != 1) {
      return 6;
    }
  }
  else {
    param_4 = "cluster_role == 0x01U || cluster_role == 0x02U";
    param_3 = "zcl_pressure_measurement_cluster_get_attr_properties";
    param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/pressure_measurement_desc.c"
                            ,0x19);
  }
  if (param_2 == 0x10) {
_L0:
    *param_4 = '\x05';
    *param_3 = ')';
  }
  else {
    if (param_2 < 0x11) {
      if (2 < param_2) {
        if (param_2 == 3) {
          *param_4 = '\x01';
          *param_3 = '!';
          return 0;
        }
        return 6;
      }
      if ((short)param_2 == 0) {
        if (param_2 != 0) {
          return 6;
        }
        goto _L0;
      }
    }
    else {
      if (param_2 == 0x13) {
        *param_4 = '\x05';
        *param_3 = '!';
        return 0;
      }
      if (0x13 < param_2) {
        if (param_2 == 0x14) {
          *param_4 = '\x01';
          *param_3 = '(';
          return 0;
        }
        return 6;
      }
      if (1 < (param_2 - 0x11 & 0xffff)) {
        return 6;
      }
    }
    *param_4 = '\x01';
    *param_3 = ')';
  }
  return 0;
}

