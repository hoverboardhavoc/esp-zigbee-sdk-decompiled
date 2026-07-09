/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_schedule_transaction_event
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_schedule_transaction_event(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = touchlink_commissioning_get();
  if (*(char *)(iVar1 + 1) == '\x02') {
    uVar2 = touchlink_target_process_event(param_1);
  }
  else {
    iVar1 = touchlink_commissioning_get();
    if (*(char *)(iVar1 + 1) == '\x01') {
      uVar2 = touchlink_initiator_process_event(param_1);
    }
    else {
      uVar2 = 3;
    }
  }
  return uVar2;
}

