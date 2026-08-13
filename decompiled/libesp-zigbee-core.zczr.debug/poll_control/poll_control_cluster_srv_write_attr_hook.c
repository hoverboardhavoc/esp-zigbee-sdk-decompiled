/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
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
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/poll_control.c",0x14b,
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

