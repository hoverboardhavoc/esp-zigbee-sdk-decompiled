/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_initiator_start_commissioning
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_initiator_start_commissioning(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = touchlink_commissioning_task_is_idle();
  if (iVar1 == 0) {
    uVar2 = 2;
  }
  else {
    touchlink_set_initiator_device(1);
    touchlink_reset_transaction();
    touchlink_commissioning_set_role(1,param_1);
    iVar1 = touchlink_is_factory_new();
    if (iVar1 != 0) {
      touchlink_assign_nwk_info();
    }
    touchlink_commissioning_task_result(0);
    uVar2 = 0;
  }
  return uVar2;
}

