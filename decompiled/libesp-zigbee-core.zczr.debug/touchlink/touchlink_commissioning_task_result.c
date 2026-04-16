/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_task_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_commissioning_task_result(uint8_t status)

{
  uint8_t uVar1;
  touchlink_commissioning_t *ptVar2;
  
  ptVar2 = touchlink_commissioning_get();
  if ((ptVar2->role == '\x02') &&
     (((ptVar2 = touchlink_commissioning_get(), ptVar2->task == '\x04' ||
       (ptVar2 = touchlink_commissioning_get(), ptVar2->task == '\x05')) ||
      (ptVar2 = touchlink_commissioning_get(), ptVar2->task == '\x06')))) {
    ptVar2 = touchlink_commissioning_get();
    milli_timer_stop((undefined1 *)((int)&ptVar2->u + 4));
  }
  ptVar2 = touchlink_commissioning_get();
  if (ptVar2->cb != (touchlink_commissioning_callback_t)0x0) {
    ptVar2 = touchlink_commissioning_get();
    uVar1 = ptVar2->task;
    touchlink_commissioning_set_task('\0');
    ptVar2 = touchlink_commissioning_get();
    (*ptVar2->cb)(uVar1,status);
  }
  return;
}

