/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_initiator_process_event
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_initiator_process_event(touchlink_transaction_event_t *event)

{
  byte bVar1;
  touchlink_commissioning_t *ptVar2;
  ezb_err_t eVar3;
  
  bVar1 = event->type;
  if (bVar1 == 8) {
    if ((event->comm).transaction.status == '\0') {
      touchlink_commissioning_start_identify((event->comm).rsp_window.duration);
      eVar3 = 0;
    }
    else {
      eVar3 = 0;
    }
  }
  else if (bVar1 < 9) {
    if (bVar1 == 6) {
      if ((event->comm).transaction.status == '\0') {
        touchlink_zdo_leave_network(&event->comm);
        eVar3 = 0;
      }
      else {
        eVar3 = 0;
      }
    }
    else if (bVar1 == 7) {
      eVar3 = 0;
    }
    else if (bVar1 == 2) {
      ptVar2 = touchlink_commissioning_get();
      if (ptVar2->task == '\x02') {
        touchlink_commissioning_continue_add_sub_device_info
                  ((event->comm).add_sub_device.curr_device);
        eVar3 = 0;
      }
      else {
        eVar3 = 3;
      }
    }
    else {
      eVar3 = 3;
    }
  }
  else if (bVar1 == 10) {
    ptVar2 = touchlink_commissioning_get();
    bVar1 = ptVar2->task;
    if (bVar1 == 2) {
      touchlink_disable_timer();
      if ((event->comm).transaction.status == '\0') {
        touchlink_enable_timer
                  (touchlink_commissioning_add_sub_device_timeout,
                   (uint)(event->comm).rsp_window.duration,(event->comm).rsp_window.arg);
        eVar3 = 0;
      }
      else {
        touchlink_commissioning_add_sub_device_timeout((void *)0x0);
        eVar3 = 0;
      }
    }
    else if (bVar1 < 3) {
      if (bVar1 == 1) {
        touchlink_disable_timer();
        if ((event->comm).transaction.status == '\0') {
          touchlink_enable_timer
                    (touchlink_commissioning_scan_req_timeout,
                     (uint)(event->comm).rsp_window.duration,(event->comm).rsp_window.arg);
          eVar3 = 0;
        }
        else {
          touchlink_commissioning_scan_req_timeout((void *)0x0);
          eVar3 = 0;
        }
      }
      else {
        eVar3 = 3;
      }
    }
    else if ((byte)(bVar1 - 4) < 3) {
      touchlink_disable_timer();
      if ((event->comm).transaction.status == '\0') {
        touchlink_enable_timer
                  (touchlink_initiator_transaction_timeout,(uint)(event->comm).rsp_window.duration,
                   (void *)0x0);
        eVar3 = 0;
      }
      else {
        touchlink_initiator_transaction_timeout((void *)0x0);
        eVar3 = 0;
      }
    }
    else {
      eVar3 = 3;
    }
  }
  else if (bVar1 == 0xb) {
    ptVar2 = touchlink_commissioning_get();
    if (ptVar2->task == '\x06') {
      touchlink_disable_timer();
      if ((event->comm).transaction.status == '\0') {
        touchlink_initiator_transaction_timeout(&event->comm);
        touchlink_zdo_permit_join((event->comm).permit_join.duration);
        touchlink_enable_timer(touchlink_initiator_check_commissioning_device,2000,(void *)0x0);
        eVar3 = 0;
      }
      else {
        touchlink_commissioning_task_result('\x01');
        eVar3 = 0;
      }
    }
    else {
      eVar3 = 3;
    }
  }
  else if (bVar1 == 9) {
    ptVar2 = touchlink_commissioning_get();
    if ((ptVar2->task == '\x04') || (ptVar2 = touchlink_commissioning_get(), ptVar2->task == '\x05')
       ) {
      touchlink_disable_timer();
      if ((event->comm).transaction.status == '\0') {
        touchlink_initiator_transaction_timeout(&event->comm);
        touchlink_enable_timer(touchlink_zdo_rejoin_network,2000,&event->comm);
        eVar3 = 0;
      }
      else {
        touchlink_commissioning_task_result('\x01');
        eVar3 = 0;
      }
    }
    else {
      eVar3 = 3;
    }
  }
  else {
    eVar3 = 3;
  }
  return eVar3;
}

