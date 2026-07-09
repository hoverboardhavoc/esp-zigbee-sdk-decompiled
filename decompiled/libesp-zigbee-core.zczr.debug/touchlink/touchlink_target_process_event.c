/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_target_process_event
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_target_process_event(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  bVar1 = *param_1;
  if (bVar1 == 6) {
    if (param_1[4] != 0) {
      return 0;
    }
    touchlink_zdo_leave_network(param_1 + 4);
    return 0;
  }
  if (bVar1 < 7) {
    if (bVar1 == 3) {
      if (param_1[4] == 0) {
        touchlink_commissioning_set_task(4);
        touchlink_commissioning_set_logic_channel(param_1[0x10]);
        touchlink_zdo_network_discovery();
        return 0;
      }
      touchlink_commissioning_set_task(0);
      return 0;
    }
    if (3 < bVar1) {
      if (bVar1 == 4) {
        if (param_1[4] != 0) {
          touchlink_commissioning_set_task(0);
          return 0;
        }
        touchlink_target_transaction_timeout(0);
        touchlink_commissioning_set_task(4);
        if (param_1[0x24] != 0) {
          touchlink_zdo_start_network(param_1 + 4);
          return 0;
        }
        touchlink_zdo_leave_network(param_1 + 4);
        return 0;
      }
      if (bVar1 != 5) {
        return 3;
      }
      if (param_1[4] == 0) {
        touchlink_target_transaction_timeout(0);
        touchlink_commissioning_set_task(5);
        if (param_1[0x24] != 0) {
          touchlink_zdo_start_router(param_1 + 4);
          return 0;
        }
        touchlink_zdo_leave_network(param_1 + 4);
        return 0;
      }
      touchlink_commissioning_set_task(0);
      return 0;
    }
    if (bVar1 == 1) {
      touchlink_disable_timer();
      if (param_1[4] == 0) {
        touchlink_commissioning_set_task(1);
        touchlink_set_intrp_channel(param_1[0xe]);
        touchlink_enable_timer
                  (touchlink_target_transaction_timeout,*(undefined2 *)(param_1 + 0xc),0);
        return 0;
      }
      touchlink_commissioning_set_task(0);
      return 0;
    }
    if (bVar1 != 2) {
      return 3;
    }
  }
  else {
    if (bVar1 == 9) {
      uVar4 = touchlink_zigbee_info();
      if ((uVar4 & 3) != 2) {
        return 3;
      }
      if (param_1[4] == 0) {
        touchlink_target_transaction_timeout(0);
        touchlink_commissioning_set_task(6);
        if (param_1[0x24] != 0) {
          touchlink_zdo_rejoin_network(param_1 + 4);
          return 0;
        }
        touchlink_zdo_leave_network(param_1 + 4);
        return 0;
      }
      touchlink_commissioning_set_task(0);
      return 0;
    }
    if (bVar1 < 10) {
      if (bVar1 == 7) {
        return 0;
      }
      if (bVar1 == 8) {
        if (param_1[4] != 0) {
          return 0;
        }
        touchlink_commissioning_start_identify(*(undefined2 *)(param_1 + 6));
        return 0;
      }
      return 3;
    }
    if (0xb < bVar1) {
      if (bVar1 != 0xd) {
        return 3;
      }
      uVar2 = *(undefined4 *)(param_1 + 4);
      iVar3 = touchlink_transaction_get();
      iVar3 = touchlink_commissioning_action_permission(uVar2,iVar3 + 8);
      if (iVar3 != 0) {
        return 0;
      }
      return 0xffffffff;
    }
    if (bVar1 < 10) {
      return 3;
    }
  }
  touchlink_commissioning_set_task(0);
  return 0;
}

