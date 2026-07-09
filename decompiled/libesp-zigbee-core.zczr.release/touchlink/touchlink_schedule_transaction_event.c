/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_schedule_transaction_event
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_schedule_transaction_event(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  undefined2 uVar6;
  byte *pbVar7;
  
  iVar3 = core_globals_get();
  if (*(char *)(iVar3 + 0x13ad) == '\x02') {
    bVar1 = *param_1;
    if (bVar1 != 6) {
      if (6 < bVar1) {
        if (bVar1 == 9) {
          uVar5 = touchlink_zigbee_info();
          if ((uVar5 & 3) != 2) {
            return 3;
          }
          if (param_1[4] == 0) {
            touchlink_target_transaction_timeout(0);
            touchlink_commissioning_set_task(6);
            if (param_1[0x24] != 0) {
              touchlink_zdo_rejoin_network(param_1 + 4);
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
            uVar2 = *(undefined4 *)(param_1 + 4);
            iVar3 = core_globals_get();
            iVar3 = touchlink_commissioning_action_permission(uVar2,iVar3 + 0xd80);
            return iVar3 + -1;
          }
        }
_L0:
        touchlink_commissioning_set_task(0);
        return 0;
      }
      if (bVar1 == 3) {
        if (param_1[4] == 0) {
          touchlink_commissioning_set_task(4);
          touchlink_commissioning_set_logic_channel(param_1[0x10]);
          touchlink_zdo_network_discovery();
          return 0;
        }
        goto _L0;
      }
      if (bVar1 < 4) {
        if (bVar1 == 1) {
          touchlink_disable_timer();
          if (param_1[4] == 0) {
            touchlink_commissioning_set_task(1);
            touchlink_set_intrp_channel(param_1[0xe]);
            uVar6 = *(undefined2 *)(param_1 + 0xc);
            pbVar7 = (byte *)0x0;
            pcVar4 = touchlink_target_transaction_timeout;
            goto _L261;
          }
        }
        else if (bVar1 != 2) {
          return 3;
        }
        goto _L0;
      }
      if (bVar1 == 4) {
        if (param_1[4] != 0) goto _L0;
        touchlink_target_transaction_timeout(0);
        touchlink_commissioning_set_task(4);
        if (param_1[0x24] != 0) {
          touchlink_zdo_start_network();
          return 0;
        }
      }
      else {
        if (param_1[4] != 0) goto _L0;
        touchlink_target_transaction_timeout(0);
        touchlink_commissioning_set_task(5);
        if (param_1[0x24] != 0) {
          touchlink_zdo_start_router(param_1 + 4);
          return 0;
        }
      }
      goto _L0;
    }
  }
  else {
    iVar3 = core_globals_get();
    if (*(char *)(iVar3 + 0x13ad) != '\x01') {
      return 3;
    }
    bVar1 = *param_1;
    if (bVar1 == 8) {
_L0:
      if (param_1[4] != 0) {
        return 0;
      }
      touchlink_commissioning_start_identify(*(undefined2 *)(param_1 + 6));
      return 0;
    }
    if (8 < bVar1) {
      if (bVar1 == 10) {
        iVar3 = core_globals_get();
        bVar1 = *(byte *)(iVar3 + 0x13ac);
        if (bVar1 == 2) {
          touchlink_disable_timer();
          if (param_1[4] != 0) {
            touchlink_commissioning_add_sub_device_timeout(0);
            return 0;
          }
          pbVar7 = *(byte **)(param_1 + 8);
          uVar6 = *(undefined2 *)(param_1 + 6);
          pcVar4 = touchlink_commissioning_add_sub_device_timeout;
        }
        else if (bVar1 < 3) {
          if (bVar1 != 1) {
            return 3;
          }
          touchlink_disable_timer();
          if (param_1[4] != 0) {
            touchlink_commissioning_scan_req_timeout(0);
            return 0;
          }
          pbVar7 = *(byte **)(param_1 + 8);
          uVar6 = *(undefined2 *)(param_1 + 6);
          pcVar4 = touchlink_commissioning_scan_req_timeout;
        }
        else {
          if (2 < (byte)(bVar1 - 4)) {
            return 3;
          }
          touchlink_disable_timer();
          if (param_1[4] != 0) {
            touchlink_reset_intrp_channel();
            goto _L0;
          }
          uVar6 = *(undefined2 *)(param_1 + 6);
          pbVar7 = (byte *)0x0;
          pcVar4 = touchlink_initiator_transaction_timeout;
        }
      }
      else if (bVar1 == 0xb) {
        iVar3 = core_globals_get();
        if (*(char *)(iVar3 + 0x13ac) != '\x06') {
          return 3;
        }
        touchlink_disable_timer();
        if (param_1[4] != 0) goto _L0;
        touchlink_initiator_transaction_timeout(param_1 + 4);
        touchlink_zdo_permit_join(param_1[5]);
        pbVar7 = (byte *)0x0;
        uVar6 = 2000;
        pcVar4 = touchlink_initiator_check_commissioning_device;
      }
      else {
        if ((bVar1 != 9) ||
           ((iVar3 = core_globals_get(), *(char *)(iVar3 + 0x13ac) != '\x04' &&
            (iVar3 = core_globals_get(), *(char *)(iVar3 + 0x13ac) != '\x05')))) {
          return 3;
        }
        touchlink_disable_timer();
        if (param_1[4] != 0) {
_L0:
          touchlink_commissioning_task_result(1);
          return 0;
        }
        pbVar7 = param_1 + 4;
        touchlink_initiator_transaction_timeout(pbVar7);
        uVar6 = 2000;
        pcVar4 = touchlink_zdo_rejoin_network;
      }
_L261:
      touchlink_enable_timer(pcVar4,uVar6,pbVar7);
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
      if (*(char *)(iVar3 + 0x13ac) != '\x02') {
        return 3;
      }
      iVar3 = *(int *)(param_1 + 4);
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
  if (param_1[4] != 0) {
    return 0;
  }
_L0:
  touchlink_zdo_leave_network(param_1 + 4);
  return 0;
}

