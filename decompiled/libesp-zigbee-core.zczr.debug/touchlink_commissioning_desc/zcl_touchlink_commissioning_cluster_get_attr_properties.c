/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_commissioning_desc.o -> zcl_touchlink_commissioning_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_touchlink_commissioning_cluster_get_attr_properties(short param_1,int param_2,int param_3)

{
  if (param_2 != 0) {
    if (param_3 == 0) {
      return 2;
    }
    if ((ushort)(param_1 - 1U) < 2) {
      return 6;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/touchlink_commissioning_desc.c"
                  ,0x19,"zcl_touchlink_commissioning_cluster_get_attr_properties",0x10000);
  }
  return 2;
}

