/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_start_new_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_commissioning_start_new_network(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    iVar1 = 2;
  }
  else {
    iVar1 = touchlink_commissioning_task_is_idle();
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    else {
      iVar1 = touchlink_commissioning_action_permission(1,param_1 + 0xf);
      if (iVar1 == 0) {
        iVar1 = -1;
      }
      else {
        uVar2 = touchlink_touchlink_info();
        if ((uVar2 & 2) != 0) {
          touchlink_commissioning_set_task(3);
          touchlink_get_logical_channel();
          touchlink_commissioning_set_logic_channel();
          touchlink_zdo_network_discovery();
          return 0;
        }
        touchlink_commissioning_set_task(4);
        iVar1 = touchlink_send_network_start_req(param_1);
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
  }
  touchlink_commissioning_set_task(0);
  return iVar1;
}

