/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_zone_cluster_srv_write_attr_hook(int param_1,char *param_2)

{
  if (param_2 == (char *)0x0) {
    param_2 = "ias_zone_cluster_srv_write_attr_hook";
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x1fd,
                  "ias_zone_cluster_srv_write_attr_hook",0x10f60);
  }
  else if (param_1 != 2) {
    return;
  }
  ias_zone_zone_status_change_handler(param_2);
  return;
}

