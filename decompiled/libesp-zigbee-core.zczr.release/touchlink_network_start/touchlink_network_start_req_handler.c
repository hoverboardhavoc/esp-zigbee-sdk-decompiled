/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_network_start.o -> touchlink_network_start_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_network_start_req_handler(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined2 uVar5;
  int iVar6;
  undefined1 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined1 auStack_38 [2];
  undefined1 auStack_36 [8];
  undefined1 uStack_2e;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (param_1 == 0) {
    param_1 = __assert_func(0,0,0);
  }
  iVar6 = *(int *)(param_1 + 0xc);
  if ((iVar6 == 0) || (iVar8 = touchlink_transaction_id(0), iVar6 != iVar8)) {
    iVar6 = 3;
  }
  else {
    iVar6 = touchlink_transaction_get();
    *(undefined1 *)(iVar6 + 0x60c) = 0xd;
    iVar6 = touchlink_transaction_get();
    *(undefined4 *)(iVar6 + 0x610) = 1;
    iVar6 = touchlink_transaction_get();
    iVar6 = touchlink_schedule_transaction_event(iVar6 + 0x60c);
    if (iVar6 == 0) {
      iVar6 = touchlink_transaction_get();
      *(undefined1 *)(iVar6 + 0x60c) = 3;
      iVar6 = touchlink_transaction_get();
      *(undefined1 *)(iVar6 + 0x610) = 0;
      uVar7 = touchlink_is_factory_new();
      *(undefined1 *)(iVar6 + 0x630) = uVar7;
      *(undefined1 *)(iVar6 + 0x631) = *(undefined1 *)(param_1 + 10);
      *(undefined2 *)(iVar6 + 0x61a) = *(undefined2 *)(param_1 + 0x2a);
      *(undefined1 *)(iVar6 + 0x61c) = *(undefined1 *)(param_1 + 0x29);
      uVar7 = *(undefined1 *)(param_1 + 0x10);
      uVar1 = *(undefined1 *)(param_1 + 0x12);
      *(undefined2 *)(iVar6 + 0x61e) = *(undefined2 *)(param_1 + 0x2c);
      uVar2 = *(undefined1 *)(param_1 + 0x11);
      uVar5 = *(undefined2 *)(param_1 + 0x14);
      uVar3 = *(undefined1 *)(param_1 + 0x13);
      uVar9 = *(undefined4 *)(param_1 + 0x14);
      *(undefined1 *)(iVar6 + 0x611) = uVar7;
      *(undefined1 *)(iVar6 + 0x612) = uVar2;
      *(undefined1 *)(iVar6 + 0x614) = uVar3;
      *(char *)(iVar6 + 0x616) = (char)((uint)uVar9 >> 8);
      *(undefined1 *)(iVar6 + 0x613) = uVar1;
      *(char *)(iVar6 + 0x615) = (char)uVar5;
      *(char *)(iVar6 + 0x617) = (char)((uint)uVar9 >> 0x10);
      *(char *)(iVar6 + 0x618) = (char)((uint)uVar9 >> 0x18);
      bVar4 = *(byte *)(param_1 + 0x18);
      uVar9 = touchlink_transaction_id(0);
      iVar8 = touchlink_transaction_get();
      touchlink_decrypt_nwk_key
                (param_1 + 0x19,iVar6 + 0x620,1 << (bVar4 & 0x1f) & 0xffff,uVar9,
                 *(undefined4 *)(iVar8 + 4));
      iVar6 = touchlink_transaction_get();
      iVar6 = touchlink_schedule_transaction_event(iVar6 + 0x60c);
      if (iVar6 == 0) {
        return 0;
      }
    }
  }
  uVar7 = *(undefined1 *)(param_1 + 10);
  memset(auStack_38,0,0x28);
  uStack_2c = touchlink_transaction_id(0);
  uStack_28 = 1;
  pcStack_18 = touchlink_network_start_rsp_confirm;
  auStack_38[0] = 3;
  uStack_14 = 0;
  iVar8 = touchlink_transaction_get();
  memcpy(auStack_36,(void *)(iVar8 + 8),8);
  uStack_2e = uVar7;
  zcl_touchlink_network_start_rsp(auStack_38);
  return iVar6;
}

