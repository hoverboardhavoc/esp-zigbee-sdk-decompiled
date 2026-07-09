/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_initiator_process_event
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_initiator_process_event(byte *param_1)

{
  byte bVar1;
  char *pcVar2;
  undefined4 uVar3;
  byte *pbVar4;
  
  bVar1 = *param_1;
  if (bVar1 == 8) {
    if (param_1[4] == 0) {
      touchlink_commissioning_start_identify(*(undefined2 *)(param_1 + 6));
      uVar3 = 0;
    }
    else {
      uVar3 = 0;
    }
  }
  else if (bVar1 < 9) {
    if (bVar1 == 6) {
      if (param_1[4] == 0) {
        touchlink_zdo_leave_network(param_1 + 4);
        uVar3 = 0;
      }
      else {
        uVar3 = 0;
      }
    }
    else if (bVar1 == 7) {
      uVar3 = 0;
    }
    else if (bVar1 == 2) {
      pcVar2 = (char *)touchlink_commissioning_get();
      if (*pcVar2 == '\x02') {
        touchlink_commissioning_continue_add_sub_device_info(*(undefined4 *)(param_1 + 4));
        uVar3 = 0;
      }
      else {
        uVar3 = 3;
      }
    }
    else {
      uVar3 = 3;
    }
  }
  else if (bVar1 == 10) {
    pbVar4 = (byte *)touchlink_commissioning_get();
    bVar1 = *pbVar4;
    if (bVar1 == 2) {
      touchlink_disable_timer();
      if (param_1[4] == 0) {
        touchlink_enable_timer
                  (touchlink_commissioning_add_sub_device_timeout,*(undefined2 *)(param_1 + 6),
                   *(undefined4 *)(param_1 + 8));
        uVar3 = 0;
      }
      else {
        touchlink_commissioning_add_sub_device_timeout(0);
        uVar3 = 0;
      }
    }
    else if (bVar1 < 3) {
      if (bVar1 == 1) {
        touchlink_disable_timer();
        if (param_1[4] == 0) {
          touchlink_enable_timer
                    (touchlink_commissioning_scan_req_timeout,*(undefined2 *)(param_1 + 6),
                     *(undefined4 *)(param_1 + 8));
          uVar3 = 0;
        }
        else {
          touchlink_commissioning_scan_req_timeout(0);
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 3;
      }
    }
    else if ((byte)(bVar1 - 4) < 3) {
      touchlink_disable_timer();
      if (param_1[4] == 0) {
        touchlink_enable_timer
                  (touchlink_initiator_transaction_timeout,*(undefined2 *)(param_1 + 6),0);
        uVar3 = 0;
      }
      else {
        touchlink_initiator_transaction_timeout(0);
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 3;
    }
  }
  else if (bVar1 == 0xb) {
    pcVar2 = (char *)touchlink_commissioning_get();
    if (*pcVar2 == '\x06') {
      touchlink_disable_timer();
      if (param_1[4] == 0) {
        touchlink_initiator_transaction_timeout(param_1 + 4);
        touchlink_zdo_permit_join(param_1[5]);
        touchlink_enable_timer(touchlink_initiator_check_commissioning_device,2000,0);
        uVar3 = 0;
      }
      else {
        touchlink_commissioning_task_result(1);
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 3;
    }
  }
  else if (bVar1 == 9) {
    pcVar2 = (char *)touchlink_commissioning_get();
    if ((*pcVar2 != '\x04') && (pcVar2 = (char *)touchlink_commissioning_get(), *pcVar2 != '\x05'))
    {
      return 3;
    }
    touchlink_disable_timer();
    if (param_1[4] == 0) {
      touchlink_initiator_transaction_timeout(param_1 + 4);
      touchlink_enable_timer(touchlink_zdo_rejoin_network,2000,param_1 + 4);
      uVar3 = 0;
    }
    else {
      touchlink_commissioning_task_result(1);
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 3;
  }
  return uVar3;
}

