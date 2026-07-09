/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void poll_control_cluster_srv_write_attr_hook
               (undefined4 param_1,int param_2,int *param_3,int param_4)

{
  if (param_3 == (int *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/poll_control.c",0x149,
                  "poll_control_cluster_srv_write_attr_hook","new_value");
  }
  else {
    param_4 = *param_3;
    if (param_2 != 1) {
      if (param_2 == 2) {
        nwk_pim_set_fast_poll_interval(param_4 * 0xfa);
        return;
      }
      if (param_2 != 0) {
        return;
      }
      poll_control_check_in_stop();
      poll_control_check_in_start(param_1);
      return;
    }
  }
  nwk_ed_set_keepalive_interval(param_4 * 0xfa);
  return;
}

