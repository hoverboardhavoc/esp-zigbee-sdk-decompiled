/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_initiator_check_commissioning_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_initiator_check_commissioning_device(void)

{
  int iVar1;
  short asStack_12 [7];
  
  iVar1 = touchlink_initiator_get_commissioning_device();
  if (iVar1 == 0) {
    touchlink_commissioning_task_result(1);
  }
  else {
    asStack_12[0] = -1;
    nwk_address_ref_by_extended(iVar1 + 0xf,asStack_12);
    if (asStack_12[0] == -1) {
      touchlink_commissioning_task_result(1);
    }
    else {
      touchlink_commissioning_task_result(0);
    }
  }
  return;
}

