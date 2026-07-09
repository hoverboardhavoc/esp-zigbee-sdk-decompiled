/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_discovery.o -> touchlink_scan_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_scan_req_handler(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uVar4;
  int *piVar5;
  undefined4 uVar6;
  
  if (param_1 == 0) {
    uVar6 = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 0xc);
    if (iVar3 == 0) {
      uVar6 = 2;
    }
    else {
      piVar5 = (int *)touchlink_transaction_get();
      if (iVar3 == *piVar5) {
        iVar3 = touchlink_transaction_get();
        if ((*(int *)(param_1 + 2) == *(int *)(iVar3 + 8)) &&
           (*(int *)(param_1 + 6) == *(int *)(iVar3 + 0xc))) {
          return 3;
        }
      }
      touchlink_set_transaction_id(*(undefined4 *)(param_1 + 0xc));
      iVar3 = touchlink_transaction_get();
      uVar6 = *(undefined4 *)(param_1 + 2);
      uVar1 = *(undefined2 *)(param_1 + 6);
      uVar2 = *(undefined4 *)(param_1 + 6);
      *(char *)(iVar3 + 8) = (char)*(undefined2 *)(param_1 + 2);
      *(char *)(iVar3 + 9) = (char)((uint)uVar6 >> 8);
      *(char *)(iVar3 + 10) = (char)((uint)uVar6 >> 0x10);
      *(char *)(iVar3 + 0xb) = (char)((uint)uVar6 >> 0x18);
      *(char *)(iVar3 + 0xc) = (char)uVar1;
      *(char *)(iVar3 + 0xd) = (char)((uint)uVar2 >> 8);
      *(char *)(iVar3 + 0xe) = (char)((uint)uVar2 >> 0x10);
      *(char *)(iVar3 + 0xf) = (char)((uint)uVar2 >> 0x18);
      iVar3 = touchlink_transaction_get();
      *(undefined1 *)(iVar3 + 0x60c) = 1;
      iVar3 = touchlink_transaction_get();
      *(undefined1 *)(iVar3 + 0x610) = 0;
      iVar3 = touchlink_transaction_get();
      *(undefined4 *)(iVar3 + 0x614) = *(undefined4 *)(param_1 + 0xc);
      iVar3 = touchlink_transaction_get();
      *(undefined2 *)(iVar3 + 0x618) = 0x1e46;
      iVar3 = touchlink_transaction_get();
      uVar4 = touchlink_current_channel();
      *(undefined1 *)(iVar3 + 0x61a) = uVar4;
      iVar3 = touchlink_transaction_get();
      iVar3 = touchlink_schedule_transaction_event(iVar3 + 0x60c);
      if (iVar3 == 0) {
        iVar3 = touchlink_device_info_get();
        if (*(char *)(iVar3 + 3) < *(char *)(param_1 + 0xb)) {
          if ((*(byte *)(param_1 + 0x10) & 0x10) == 0) {
            uVar6 = touchlink_send_scan_rsp(*(undefined1 *)(param_1 + 10));
          }
          else {
            uVar6 = 2;
          }
        }
        else {
          uVar6 = 2;
        }
      }
      else {
        uVar6 = 0;
      }
    }
  }
  return uVar6;
}

