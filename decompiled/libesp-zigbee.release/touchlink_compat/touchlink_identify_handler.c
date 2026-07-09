/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> touchlink_compat.o -> touchlink_identify_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_identify_handler(int param_1)

{
  if (s_zll_identify_req_cb != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001000e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*s_zll_identify_req_cb)(param_1 != 0);
    return;
  }
  return;
}

