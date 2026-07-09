/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_join_router
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_commissioning_join_router(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = touchlink_commissioning_task_is_idle();
  if (iVar1 == 0) {
    uVar2 = 2;
  }
  else {
    iVar1 = touchlink_commissioning_action_permission(2,param_1 + 0xf);
    if (iVar1 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      touchlink_commissioning_set_task(5);
      if (param_1 == 0) {
        uVar2 = 2;
      }
      else {
        uVar2 = touchlink_send_join_router_req(param_1);
      }
    }
  }
  return uVar2;
}

