/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_network_update.o -> touchlink_network_update_req_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_network_update_req_confirm(undefined1 *param_1)

{
  if (param_1 == (undefined1 *)0x0) {
    param_1 = (undefined1 *)__assert_func(0,0,0);
  }
  log_write(3,"TL_NETWORK_UPDATE",0x10000,*param_1);
  return;
}

