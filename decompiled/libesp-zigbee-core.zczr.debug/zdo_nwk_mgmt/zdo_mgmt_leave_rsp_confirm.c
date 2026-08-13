/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_mgmt_leave_rsp_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_mgmt_leave_rsp_confirm(int *param_1,int param_2)

{
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x361,
                            "zdo_mgmt_leave_rsp_confirm","result && mgmt_req");
  }
  else if (*param_1 == 0) {
    zdo_send_mgmt_req(0);
    return;
  }
  zdo_free_mgmt_req(param_2);
  return;
}

