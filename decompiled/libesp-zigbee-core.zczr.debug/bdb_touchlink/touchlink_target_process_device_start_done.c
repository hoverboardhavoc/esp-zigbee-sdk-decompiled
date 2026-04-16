/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_target_process_device_start_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_target_process_device_start_done(ezb_err_t error)

{
  int iVar1;
  
  iVar1 = touchlink_commissioning_get();
  if (*(char *)(iVar1 + 1) == '\x02') {
    if (error == 0) {
      zdo_initiate_commissioning(0x100);
      return;
    }
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",0x102,
                  "touchlink_target_process_device_start_done",
                  "(*touchlink_commissioning_get()).role == TL_COMM_ROLE_TARGET");
  }
  touchlink_commissioning_task_result(1);
  return;
}

