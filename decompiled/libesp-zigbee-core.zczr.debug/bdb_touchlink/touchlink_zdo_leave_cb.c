/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_zdo_leave_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_zdo_leave_cb(int param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  
  if (param_2 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",
                  0x83,"touchlink_zdo_leave_cb","user_ctx");
  }
  else if (param_1 != 0) {
    return;
  }
  pcVar2 = (char *)touchlink_commissioning_get();
  cVar1 = *pcVar2;
  if (cVar1 == '\x05') {
    touchlink_zdo_start_router(param_2);
  }
  else if (cVar1 == '\x06') {
    touchlink_zdo_rejoin_network(param_2);
  }
  else if (cVar1 == '\x04') {
    touchlink_zdo_start_network(param_2);
  }
  return;
}

