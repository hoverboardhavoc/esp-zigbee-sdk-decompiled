/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> fan_control_desc.o -> zcl_fan_control_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_fan_control_cluster_get_attr_properties(int param_1,uint param_2,char *param_3,char *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_3 == (char *)0x0) {
    uVar1 = 2;
  }
  else if (param_4 == (char *)0x0) {
    uVar1 = 2;
  }
  else {
    uVar2 = (uint)((param_1 - 1U & 0xffff) < 2);
    if (uVar2 == 0) {
      param_4 = "cluster_role == 0x01U || cluster_role == 0x02U";
      param_3 = "zcl_fan_control_cluster_get_attr_properties";
      param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/fan_control_desc.c"
                              ,0x19);
    }
    else {
      uVar2 = 1;
      if (param_1 != 1) {
        return 6;
      }
    }
    if (uVar2 < param_2) {
      uVar1 = 6;
    }
    else {
      *param_4 = '\x03';
      *param_3 = '0';
      uVar1 = 0;
    }
  }
  return uVar1;
}

