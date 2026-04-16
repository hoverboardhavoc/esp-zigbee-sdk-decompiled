/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> touchlink_compat.o -> touchlink_identify_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_identify_handler(uint16_t duration)

{
  undefined2 in_register_0000202a;
  
  if (s_zll_identify_req_cb != (esp_zb_zll_identify_req_callback_t)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001000e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*s_zll_identify_req_cb)(CONCAT22(in_register_0000202a,duration) != 0);
    return;
  }
  return;
}

