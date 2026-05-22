/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_zdo_leave_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_zdo_leave_cb(uint8_t status,void *user_ctx)

{
  char cVar1;
  undefined3 in_register_00002029;
  char *pcVar2;
  
  if (user_ctx == (void *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",
                  0x83,"touchlink_zdo_leave_cb","user_ctx");
  }
  else if (CONCAT31(in_register_00002029,status) != 0) {
    return;
  }
  pcVar2 = (char *)touchlink_commissioning_get();
  cVar1 = *pcVar2;
  if (cVar1 == '\x05') {
    touchlink_zdo_start_router((touchlink_event_start_router_t *)user_ctx);
  }
  else if (cVar1 == '\x06') {
    touchlink_zdo_rejoin_network(user_ctx);
  }
  else if (cVar1 == '\x04') {
    touchlink_zdo_start_network((touchlink_event_start_network_t *)user_ctx);
  }
  return;
}

