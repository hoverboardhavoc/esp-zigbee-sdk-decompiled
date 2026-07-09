/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_scan_req_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_commissioning_scan_req_timeout(int param_1)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)touchlink_commissioning_get();
  if (*pcVar1 == '\x01') {
    iVar2 = touchlink_commissioning_get();
    if (*(int *)(iVar2 + 0x10) != 0) {
      if (param_1 == 0) {
        iVar2 = 2;
      }
      else {
        iVar2 = touchlink_commissioning_scan_next_channel();
        if (iVar2 == 0) {
          return;
        }
      }
      if (iVar2 != 5) {
        touchlink_reset_disc_table();
        touchlink_commissioning_task_result(1);
        return;
      }
      touchlink_commissioning_task_result(0);
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink.c",0x127,
                  "touchlink_commissioning_scan_req_timeout",
                  "(*touchlink_commissioning_get()).task == TL_COMM_TASK_SCAN");
  }
  touchlink_commissioning_task_result(0);
  return;
}

