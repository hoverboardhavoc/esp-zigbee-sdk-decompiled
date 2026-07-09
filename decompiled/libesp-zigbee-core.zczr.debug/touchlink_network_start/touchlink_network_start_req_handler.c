/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_network_start.o -> touchlink_network_start_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_network_start_req_handler(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int unaff_s1;
  int iVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink_network_start.c",
                  0x77,"touchlink_network_start_req_handler",&_LC2);
_L0:
    iVar4 = touchlink_transaction_id(0);
    if (unaff_s1 == iVar4) {
      iVar4 = touchlink_transaction_get();
      *(undefined1 *)(iVar4 + 0x60c) = 0xd;
      iVar4 = touchlink_transaction_get();
      *(undefined4 *)(iVar4 + 0x610) = 1;
      iVar4 = touchlink_transaction_get();
      iVar4 = touchlink_schedule_transaction_event(iVar4 + 0x60c);
      if (iVar4 == 0) {
        iVar4 = touchlink_transaction_get();
        *(undefined1 *)(iVar4 + 0x60c) = 3;
        iVar4 = touchlink_transaction_get();
        *(undefined1 *)(iVar4 + 0x610) = 0;
        uVar5 = touchlink_is_factory_new();
        *(undefined1 *)(iVar4 + 0x630) = uVar5;
        *(undefined1 *)(iVar4 + 0x631) = *(undefined1 *)(param_1 + 10);
        *(undefined2 *)(iVar4 + 0x61a) = *(undefined2 *)(param_1 + 0x2a);
        *(undefined1 *)(iVar4 + 0x61c) = *(undefined1 *)(param_1 + 0x29);
        *(undefined2 *)(iVar4 + 0x61e) = *(undefined2 *)(param_1 + 0x2c);
        uVar6 = *(undefined4 *)(param_1 + 0x10);
        uVar2 = *(undefined2 *)(param_1 + 0x14);
        uVar3 = *(undefined4 *)(param_1 + 0x14);
        *(char *)(iVar4 + 0x611) = (char)*(undefined2 *)(param_1 + 0x10);
        *(char *)(iVar4 + 0x612) = (char)((uint)uVar6 >> 8);
        *(char *)(iVar4 + 0x613) = (char)((uint)uVar6 >> 0x10);
        *(char *)(iVar4 + 0x614) = (char)((uint)uVar6 >> 0x18);
        *(char *)(iVar4 + 0x615) = (char)uVar2;
        *(char *)(iVar4 + 0x616) = (char)((uint)uVar3 >> 8);
        *(char *)(iVar4 + 0x617) = (char)((uint)uVar3 >> 0x10);
        *(char *)(iVar4 + 0x618) = (char)((uint)uVar3 >> 0x18);
        bVar1 = *(byte *)(param_1 + 0x18);
        uVar6 = touchlink_transaction_id(0);
        iVar7 = touchlink_transaction_get();
        touchlink_decrypt_nwk_key
                  (param_1 + 0x19,iVar4 + 0x620,1 << (bVar1 & 0x1f) & 0xffff,uVar6,
                   *(undefined4 *)(iVar7 + 4));
        iVar4 = touchlink_transaction_get();
        iVar4 = touchlink_schedule_transaction_event(iVar4 + 0x60c);
        if (iVar4 == 0) {
          return 0;
        }
      }
      goto _L0;
    }
  }
  else {
    unaff_s1 = *(int *)(param_1 + 0xc);
    if (unaff_s1 != 0) goto _L0;
  }
  iVar4 = 3;
_L0:
  touchlink_send_network_start_rsp_with_failure(*(undefined1 *)(param_1 + 10));
  return iVar4;
}

