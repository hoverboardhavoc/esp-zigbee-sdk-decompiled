/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_join_router.o -> touchlink_join_router_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_join_router_req_handler(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int unaff_s1;
  uint uVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink_join_router.c",99,
                  "touchlink_join_router_req_handler",&_L0);
_L0:
    iVar9 = touchlink_transaction_id(0);
    if (unaff_s1 == iVar9) {
      iVar9 = touchlink_transaction_get();
      *(undefined1 *)(iVar9 + 0x60c) = 0xd;
      iVar9 = touchlink_transaction_get();
      *(undefined4 *)(iVar9 + 0x610) = 2;
      iVar9 = touchlink_transaction_get();
      uVar4 = touchlink_schedule_transaction_event(iVar9 + 0x60c);
      if (uVar4 == 0) {
        iVar9 = touchlink_transaction_get();
        *(undefined1 *)(iVar9 + 0x60c) = 5;
        iVar6 = touchlink_transaction_get();
        iVar9 = iVar6 + 0x610;
        *(undefined1 *)(iVar6 + 0x610) = 0;
        *(undefined2 *)(iVar6 + 0x61a) = *(undefined2 *)(param_1 + 0x2c);
        *(undefined1 *)(iVar6 + 0x61c) = *(undefined1 *)(param_1 + 0x2a);
        *(undefined2 *)(iVar6 + 0x61e) = *(undefined2 *)(param_1 + 0x2e);
        uVar5 = touchlink_is_factory_new();
        *(undefined1 *)(iVar6 + 0x630) = uVar5;
        uVar7 = *(undefined4 *)(param_1 + 0x10);
        uVar2 = *(undefined2 *)(param_1 + 0x14);
        uVar3 = *(undefined4 *)(param_1 + 0x14);
        *(char *)(iVar6 + 0x611) = (char)*(undefined2 *)(param_1 + 0x10);
        *(char *)(iVar6 + 0x612) = (char)((uint)uVar7 >> 8);
        *(char *)(iVar6 + 0x613) = (char)((uint)uVar7 >> 0x10);
        *(char *)(iVar6 + 0x614) = (char)((uint)uVar7 >> 0x18);
        *(char *)(iVar6 + 0x615) = (char)uVar2;
        *(char *)(iVar6 + 0x616) = (char)((uint)uVar3 >> 8);
        *(char *)(iVar6 + 0x617) = (char)((uint)uVar3 >> 0x10);
        *(char *)(iVar6 + 0x618) = (char)((uint)uVar3 >> 0x18);
        bVar1 = *(byte *)(param_1 + 0x18);
        uVar7 = touchlink_transaction_id(0);
        iVar8 = touchlink_transaction_get();
        touchlink_decrypt_nwk_key
                  (param_1 + 0x19,iVar6 + 0x620,1 << (bVar1 & 0x1f) & 0xffff,uVar7,
                   *(undefined4 *)(iVar8 + 4));
      }
      else {
        iVar9 = 0;
      }
      goto _L0;
    }
  }
  else {
    unaff_s1 = *(int *)(param_1 + 0xc);
    if (unaff_s1 != 0) goto _L0;
  }
  iVar9 = 0;
  uVar4 = 3;
_L0:
  touchlink_convert_status(uVar4 & 0xff);
  touchlink_send_join_router_rsp(*(undefined1 *)(param_1 + 10),iVar9);
  return;
}

