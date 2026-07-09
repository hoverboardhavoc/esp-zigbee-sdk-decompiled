/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int af_data_request(undefined4 *param_1)

{
  int unaff_s1;
  undefined4 unaff_s2;
  
  if (param_1 == (undefined4 *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_core.c",0xd0,"af_data_request",
                  &_LC5);
  }
  else {
    unaff_s2 = *param_1;
    unaff_s1 = aps_apsde_data_request();
    if (unaff_s1 != 0) {
      return unaff_s1;
    }
  }
  af_data_add_cnf_cb(unaff_s2,param_1[7],param_1[8]);
  return unaff_s1;
}

