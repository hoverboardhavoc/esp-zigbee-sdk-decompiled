/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_task_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_commissioning_task_result(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
  
  iVar2 = touchlink_commissioning_get();
  if ((*(char *)(iVar2 + 1) == '\x02') &&
     (((pcVar4 = (char *)touchlink_commissioning_get(), *pcVar4 == '\x04' ||
       (pcVar4 = (char *)touchlink_commissioning_get(), *pcVar4 == '\x05')) ||
      (pcVar4 = (char *)touchlink_commissioning_get(), *pcVar4 == '\x06')))) {
    iVar2 = touchlink_commissioning_get();
    milli_timer_stop(iVar2 + 0x10);
  }
  iVar2 = touchlink_commissioning_get();
  if (*(int *)(iVar2 + 0x38) != 0) {
    puVar3 = (undefined1 *)touchlink_commissioning_get();
    uVar1 = *puVar3;
    touchlink_commissioning_set_task(0);
    iVar2 = touchlink_commissioning_get();
    (**(code **)(iVar2 + 0x38))(uVar1,param_1,*(code **)(iVar2 + 0x38));
  }
  return;
}

