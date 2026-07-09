/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_target_process_discovery_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_target_process_discovery_done(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = touchlink_commissioning_get();
  if (*(char *)(iVar1 + 1) == '\x02') {
    if (param_1 == 0) {
      pcVar2 = (char *)touchlink_commissioning_get();
      if (*pcVar2 == '\x04') goto _L0;
      if (*pcVar2 == '\x06') {
        iVar1 = touchlink_transaction_get();
        touchlink_zdo_set_rejoin_network_info(iVar1 + 0x610);
        return;
      }
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",
                    0xda,"touchlink_target_process_discovery_done",&_LC3);
    }
    touchlink_commissioning_task_result(1);
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",
                  0xcf,"touchlink_target_process_discovery_done",
                  "(*touchlink_commissioning_get()).role == TL_COMM_ROLE_TARGET");
_L0:
    iVar1 = touchlink_transaction_get();
    touchlink_zdo_target_start_network_response(iVar1 + 0x610);
  }
  return;
}

