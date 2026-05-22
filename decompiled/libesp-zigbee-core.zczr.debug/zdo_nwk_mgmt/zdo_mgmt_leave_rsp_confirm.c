/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
    arg = (void *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",
                                0x28d,"zdo_mgmt_leave_rsp_confirm","cnf && mgmt_req");
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

