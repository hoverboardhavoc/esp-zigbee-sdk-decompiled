/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_target_process_event
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_target_process_event(touchlink_transaction_event_t *event)

{
  byte bVar1;
  touchlink_disc_dev_info_t *action;
  _Bool _Var2;
  touchlink_transaction_t *ptVar3;
  undefined3 extraout_var;
  uint uVar4;
  
  bVar1 = event->type;
  if (bVar1 == 6) {
    if ((event->comm).transaction.status != '\0') {
      return 0;
    }
    touchlink_zdo_leave_network(&event->comm);
    return 0;
  }
  if (bVar1 < 7) {
    if (bVar1 == 3) {
      if ((event->comm).transaction.status == '\0') {
        touchlink_commissioning_set_task('\x04');
        touchlink_commissioning_set_logic_channel((event->comm).start_network.channel);
        touchlink_zdo_network_discovery();
        return 0;
      }
      touchlink_commissioning_set_task('\0');
      return 0;
    }
    if (3 < bVar1) {
      if (bVar1 == 4) {
        if ((event->comm).transaction.status != '\0') {
          touchlink_commissioning_set_task('\0');
          return 0;
        }
        touchlink_target_transaction_timeout((void *)0x0);
        touchlink_commissioning_set_task('\x04');
        if ((event->comm).start_network.factory_new != '\0') {
          touchlink_zdo_start_network(&event->comm);
          return 0;
        }
        touchlink_zdo_leave_network(&event->comm);
        return 0;
      }
      if (bVar1 != 5) {
        return 3;
      }
      if ((event->comm).transaction.status == '\0') {
        touchlink_target_transaction_timeout((void *)0x0);
        touchlink_commissioning_set_task('\x05');
        if ((event->comm).start_network.factory_new != '\0') {
          touchlink_zdo_start_router(&event->comm);
          return 0;
        }
        touchlink_zdo_leave_network(&event->comm);
        return 0;
      }
      touchlink_commissioning_set_task('\0');
      return 0;
    }
    if (bVar1 == 1) {
      touchlink_disable_timer();
      if ((event->comm).transaction.status == '\0') {
        touchlink_commissioning_set_task('\x01');
        touchlink_set_intrp_channel((event->comm).transaction.channel);
        touchlink_enable_timer
                  (touchlink_target_transaction_timeout,
                   (uint)(event->comm).transaction.transaction_time,(void *)0x0);
        return 0;
      }
      touchlink_commissioning_set_task('\0');
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
      if ((event->comm).transaction.status == '\0') {
        touchlink_target_transaction_timeout((void *)0x0);
        touchlink_commissioning_set_task('\x06');
        if ((event->comm).start_network.factory_new != '\0') {
          touchlink_zdo_rejoin_network(&event->comm);
          return 0;
        }
        touchlink_zdo_leave_network(&event->comm);
        return 0;
      }
      touchlink_commissioning_set_task('\0');
      return 0;
    }
    if (bVar1 < 10) {
      if (bVar1 == 7) {
        return 0;
      }
      if (bVar1 == 8) {
        if ((event->comm).transaction.status != '\0') {
          return 0;
        }
        touchlink_commissioning_start_identify((event->comm).rsp_window.duration);
        return 0;
      }
      return 3;
    }
    if (0xb < bVar1) {
      if (bVar1 != 0xd) {
        return 3;
      }
      action = (event->comm).add_sub_device.curr_device;
      ptVar3 = touchlink_transaction_get();
      _Var2 = touchlink_commissioning_action_permission
                        ((touchlink_action_t)action,(ezb_extaddr_t *)&(ptVar3->field_2).cli);
      if (CONCAT31(extraout_var,_Var2) != 0) {
        return 0;
      }
      return -1;
    }
    if (bVar1 < 10) {
      return 3;
    }
  }
  touchlink_commissioning_set_task('\0');
  return 0;
}

