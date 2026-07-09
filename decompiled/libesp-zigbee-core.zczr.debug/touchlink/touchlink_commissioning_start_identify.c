/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_start_identify
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_commissioning_start_identify(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = touchlink_commissioning_get();
  if (*(int *)(iVar1 + 0x34) != 0) {
    iVar1 = touchlink_commissioning_get();
    *(short *)(iVar1 + 0x20) = (short)param_1;
    iVar1 = touchlink_commissioning_get();
    (**(code **)(iVar1 + 0x34))(param_1,*(code **)(iVar1 + 0x34));
    iVar1 = touchlink_commissioning_get();
    milli_timer_stop(iVar1 + 0x24);
    iVar1 = touchlink_commissioning_get();
    milli_timer_init(iVar1 + 0x24,touchlink_commissioning_identify_timeout,0);
    iVar1 = touchlink_commissioning_get();
    milli_timer_start(iVar1 + 0x24,1000);
  }
  return;
}

