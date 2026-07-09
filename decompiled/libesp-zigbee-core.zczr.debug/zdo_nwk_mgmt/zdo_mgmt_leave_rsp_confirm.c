/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_mgmt_leave_rsp_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_mgmt_leave_rsp_confirm(char *param_1,int param_2)

{
  if ((param_1 == (char *)0x0) || (param_2 == 0)) {
    param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x362,
                            "zdo_mgmt_leave_rsp_confirm","cnf && mgmt_req");
  }
  else if (*param_1 == '\0') {
    zdo_send_mgmt_req(0);
    return;
  }
  zdo_free_mgmt_req(param_2);
  return;
}

