/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_commissioning_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_commissioning_scan(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = touchlink_commissioning_task_is_idle();
  iVar1 = 2;
  if (iVar2 != 0) {
    touchlink_commissioning_set_task(1);
    iVar1 = core_globals_get();
    uVar3 = touchlink_commissioning_get_channel_mask();
    *(undefined4 *)(iVar1 + 0x13bc) = uVar3;
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0x13b8) = 5;
    iVar1 = touchlink_commissioning_scan_next_channel();
    if (iVar1 == 0) {
      return 0;
    }
  }
  touchlink_commissioning_set_task(0);
  return iVar1;
}

