/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_schedule_transaction_event
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_schedule_transaction_event(touchlink_transaction_event_t *event)

{
  byte bVar1;
  touchlink_disc_dev_info_t *action;
  _Bool _Var2;
  int iVar3;
  undefined3 extraout_var;
  code *timer_func;
  uint uVar4;
  uint32_t delay_ms;
  anon_union_36_11_e71becce_for_comm *arg;
  
  iVar3 = core_globals_get();
  if (*(char *)(iVar3 + 0x1401) == '\x02') {
    bVar1 = event->type;
    if (bVar1 != 6) {
      if (6 < bVar1) {
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
            goto _L0;
          }
        }
        else {
          if (bVar1 < 10) {
            if (bVar1 == 7) {
              return 0;
            }
            goto _L0;
          }
          if (0xb < bVar1) {
            if (bVar1 != 0xd) {
              return 3;
            }
            action = (event->comm).add_sub_device.curr_device;
            iVar3 = core_globals_get();
            _Var2 = touchlink_commissioning_action_permission
                              ((touchlink_action_t)action,(ezb_extaddr_t *)(iVar3 + 0xdd4));
            return CONCAT31(extraout_var,_Var2) + -1;
          }
        }
_L0:
        touchlink_commissioning_set_task('\0');
        return 0;
      }
      if (bVar1 == 3) {
        if ((event->comm).transaction.status == '\0') {
          touchlink_commissioning_set_task('\x04');
          touchlink_commissioning_set_logic_channel((event->comm).start_network.channel);
          touchlink_zdo_network_discovery();
          return 0;
        }
        goto _L0;
      }
      if (bVar1 < 4) {
        if (bVar1 == 1) {
          touchlink_disable_timer();
          if ((event->comm).transaction.status == '\0') {
            touchlink_commissioning_set_task('\x01');
            touchlink_set_intrp_channel((event->comm).transaction.channel);
            delay_ms = (uint32_t)(event->comm).transaction.transaction_time;
            arg = (anon_union_36_11_e71becce_for_comm *)0x0;
            timer_func = touchlink_target_transaction_timeout;
            goto _L261;
          }
        }
        else if (bVar1 != 2) {
          return 3;
        }
        goto _L0;
      }
      if (bVar1 == 4) {
        if ((event->comm).transaction.status != '\0') goto _L0;
        touchlink_target_transaction_timeout((void *)0x0);
        touchlink_commissioning_set_task('\x04');
        if ((event->comm).start_network.factory_new != '\0') {
          touchlink_zdo_start_network();
          return 0;
        }
      }
      else {
        if ((event->comm).transaction.status != '\0') goto _L0;
        touchlink_target_transaction_timeout((void *)0x0);
        touchlink_commissioning_set_task('\x05');
        if ((event->comm).start_network.factory_new != '\0') {
          touchlink_zdo_start_router(&event->comm);
          return 0;
        }
      }
      goto _L0;
    }
  }
  else {
    iVar3 = core_globals_get();
    if (*(char *)(iVar3 + 0x1401) != '\x01') {
      return 3;
    }
    bVar1 = event->type;
    if (bVar1 == 8) {
_L0:
      if ((event->comm).transaction.status != '\0') {
        return 0;
      }
      touchlink_commissioning_start_identify((event->comm).rsp_window.duration);
      return 0;
    }
    if (8 < bVar1) {
      if (bVar1 == 10) {
        iVar3 = core_globals_get();
        bVar1 = *(byte *)(iVar3 + 0x1400);
        if (bVar1 == 2) {
          touchlink_disable_timer();
          if ((event->comm).transaction.status != '\0') {
            touchlink_commissioning_add_sub_device_timeout((void *)0x0);
            return 0;
          }
          arg = (anon_union_36_11_e71becce_for_comm *)(event->comm).rsp_window.arg;
          delay_ms = (uint32_t)(event->comm).rsp_window.duration;
          timer_func = touchlink_commissioning_add_sub_device_timeout;
        }
        else if (bVar1 < 3) {
          if (bVar1 != 1) {
            return 3;
          }
          touchlink_disable_timer();
          if ((event->comm).transaction.status != '\0') {
            touchlink_commissioning_scan_req_timeout((void *)0x0);
            return 0;
          }
          arg = (anon_union_36_11_e71becce_for_comm *)(event->comm).rsp_window.arg;
          delay_ms = (uint32_t)(event->comm).rsp_window.duration;
          timer_func = touchlink_commissioning_scan_req_timeout;
        }
        else {
          if (2 < (byte)(bVar1 - 4)) {
            return 3;
          }
          touchlink_disable_timer();
          if ((event->comm).transaction.status != '\0') {
            touchlink_reset_intrp_channel();
            goto _L0;
          }
          delay_ms = (uint32_t)(event->comm).rsp_window.duration;
          arg = (anon_union_36_11_e71becce_for_comm *)0x0;
          timer_func = touchlink_initiator_transaction_timeout;
        }
      }
      else if (bVar1 == 0xb) {
        iVar3 = core_globals_get();
        if (*(char *)(iVar3 + 0x1400) != '\x06') {
          return 3;
        }
        touchlink_disable_timer();
        if ((event->comm).transaction.status != '\0') goto _L0;
        touchlink_initiator_transaction_timeout(&event->comm);
        touchlink_zdo_permit_join((event->comm).permit_join.duration);
        arg = (anon_union_36_11_e71becce_for_comm *)0x0;
        delay_ms = 2000;
        timer_func = touchlink_initiator_check_commissioning_device;
      }
      else {
        if ((bVar1 != 9) ||
           ((iVar3 = core_globals_get(), *(char *)(iVar3 + 0x1400) != '\x04' &&
            (iVar3 = core_globals_get(), *(char *)(iVar3 + 0x1400) != '\x05')))) {
          return 3;
        }
        touchlink_disable_timer();
        if ((event->comm).transaction.status != '\0') {
_L0:
          touchlink_commissioning_task_result('\x01');
          return 0;
        }
        arg = &event->comm;
        touchlink_initiator_transaction_timeout(arg);
        delay_ms = 2000;
        timer_func = touchlink_zdo_rejoin_network;
      }
_L261:
      touchlink_enable_timer(timer_func,delay_ms,arg);
      return 0;
    }
    if (bVar1 != 6) {
      if (bVar1 == 7) {
        return 0;
      }
      if (bVar1 != 2) {
        return 3;
      }
      iVar3 = core_globals_get();
      if (*(char *)(iVar3 + 0x1400) != '\x02') {
        return 3;
      }
      iVar3 = *(int *)&event->comm;
      if (iVar3 == 0) {
        return 0;
      }
      if (*(byte *)(iVar3 + 0x26) <= *(byte *)(iVar3 + 0x28)) {
        return 0;
      }
      touchlink_send_device_info_req(iVar3 + 0xf,0);
      return 0;
    }
  }
  if ((event->comm).transaction.status != '\0') {
    return 0;
  }
_L0:
  touchlink_zdo_leave_network(&event->comm);
  return 0;
}

