/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_scan_req_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_commissioning_scan_req_timeout(void *arg)

{
  touchlink_commissioning_t *ptVar1;
  int iVar2;
  
  ptVar1 = touchlink_commissioning_get();
  if (ptVar1->task == '\x01') {
    ptVar1 = touchlink_commissioning_get();
    if ((ptVar1->u).initiator.scan_channel_mask != 0) {
      if (arg == (void *)0x0) {
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
        touchlink_commissioning_task_result('\x01');
        return;
      }
      touchlink_commissioning_task_result('\0');
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink.c",0x127,
                  "touchlink_commissioning_scan_req_timeout",
                  "(*touchlink_commissioning_get()).task == TL_COMM_TASK_SCAN");
  }
  touchlink_commissioning_task_result('\0');
  return;
}

