/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_target_process_formation_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_target_process_formation_done(int param_1)

{
  int iVar1;
  
  iVar1 = touchlink_commissioning_get();
  if (*(char *)(iVar1 + 1) == '\x02') {
    if (param_1 == 0) {
      iVar1 = touchlink_transaction_get();
      nwk_secur_set_key(iVar1 + 0x620,0);
      nwk_secur_switch_key(0);
      zdo_initiate_commissioning(0x80);
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",
                  0xf2,"touchlink_target_process_formation_done",
                  "(*touchlink_commissioning_get()).role == TL_COMM_ROLE_TARGET");
  }
  touchlink_commissioning_task_result(1);
  return;
}

