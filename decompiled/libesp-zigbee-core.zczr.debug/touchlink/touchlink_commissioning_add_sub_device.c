/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_add_sub_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_commissioning_add_sub_device(void)

{
  int iVar1;
  
  iVar1 = touchlink_commissioning_task_is_idle();
  if (iVar1 == 0) {
    iVar1 = 2;
  }
  else {
    touchlink_commissioning_set_task(2);
    iVar1 = touchlink_commissioning_get_next_device_info(0);
    if (iVar1 == 0) {
      return 0;
    }
  }
  touchlink_commissioning_set_task(0);
  return iVar1;
}

