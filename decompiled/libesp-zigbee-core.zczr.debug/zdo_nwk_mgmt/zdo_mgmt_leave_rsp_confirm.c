/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_mgmt_leave_rsp_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_mgmt_leave_rsp_confirm(void *result,void *arg)

{
  if ((result == (void *)0x0) || (arg == (void *)0x0)) {
    arg = (void *)__assert_func("//build/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x25b,
                                "zdo_mgmt_leave_rsp_confirm","cnf && mgmt_req");
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (*result == '\0') {
      zdo_send_mgmt_req(0);
      return;
    }
  }
  zdo_free_mgmt_req(arg);
  return;
}

