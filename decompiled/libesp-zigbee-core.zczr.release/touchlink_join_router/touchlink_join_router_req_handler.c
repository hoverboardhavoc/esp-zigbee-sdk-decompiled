/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_join_router.o -> touchlink_join_router_req_handler
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
  int iVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  undefined1 auStack_3c [2];
  undefined1 auStack_3a [8];
  undefined1 uStack_32;
  undefined4 uStack_30;
  undefined1 uStack_2c;
  code *pcStack_28;
  int iStack_24;
  
  if (param_1 == 0) {
    param_1 = __assert_func(0,0,0);
  }
  iVar4 = *(int *)(param_1 + 0xc);
  if ((iVar4 == 0) || (iVar7 = touchlink_transaction_id(0), iVar4 != iVar7)) {
    iVar4 = 0;
    uVar10 = 3;
  }
  else {
    iVar4 = touchlink_transaction_get();
    *(undefined1 *)(iVar4 + 0x60c) = 0xd;
    iVar4 = touchlink_transaction_get();
    *(undefined4 *)(iVar4 + 0x610) = 2;
    iVar4 = touchlink_transaction_get();
    uVar10 = touchlink_schedule_transaction_event(iVar4 + 0x60c);
    iVar4 = 0;
    if (uVar10 == 0) {
      iVar4 = touchlink_transaction_get();
      *(undefined1 *)(iVar4 + 0x60c) = 5;
      iVar7 = touchlink_transaction_get();
      *(undefined1 *)(iVar7 + 0x610) = 0;
      iVar4 = iVar7 + 0x610;
      *(undefined2 *)(iVar7 + 0x61a) = *(undefined2 *)(param_1 + 0x2c);
      *(undefined1 *)(iVar7 + 0x61c) = *(undefined1 *)(param_1 + 0x2a);
      *(undefined2 *)(iVar7 + 0x61e) = *(undefined2 *)(param_1 + 0x2e);
      uVar6 = touchlink_is_factory_new();
      *(undefined1 *)(iVar7 + 0x630) = uVar6;
      uVar2 = *(undefined2 *)(param_1 + 0x14);
      uVar8 = *(undefined4 *)(param_1 + 0x10);
      uVar3 = *(undefined4 *)(param_1 + 0x14);
      *(char *)(iVar7 + 0x611) = (char)*(undefined2 *)(param_1 + 0x10);
      *(char *)(iVar7 + 0x612) = (char)((uint)uVar8 >> 8);
      *(char *)(iVar7 + 0x614) = (char)((uint)uVar8 >> 0x18);
      *(char *)(iVar7 + 0x616) = (char)((uint)uVar3 >> 8);
      *(char *)(iVar7 + 0x615) = (char)uVar2;
      *(char *)(iVar7 + 0x617) = (char)((uint)uVar3 >> 0x10);
      *(char *)(iVar7 + 0x613) = (char)((uint)uVar8 >> 0x10);
      *(char *)(iVar7 + 0x618) = (char)((uint)uVar3 >> 0x18);
      bVar1 = *(byte *)(param_1 + 0x18);
      uVar8 = touchlink_transaction_id(0);
      iVar9 = touchlink_transaction_get();
      touchlink_decrypt_nwk_key
                (param_1 + 0x19,iVar7 + 0x620,1 << (bVar1 & 0x1f) & 0xffff,uVar8,
                 *(undefined4 *)(iVar9 + 4));
    }
  }
  uVar5 = touchlink_convert_status(uVar10 & 0xff);
  uVar6 = *(undefined1 *)(param_1 + 10);
  memset(auStack_3c,0,0x1c);
  uStack_30 = touchlink_transaction_id(0);
  pcStack_28 = touchlink_join_router_rsp_confirm;
  auStack_3c[0] = 3;
  uStack_2c = uVar5;
  iStack_24 = iVar4;
  iVar4 = touchlink_transaction_get();
  memcpy(auStack_3a,(void *)(iVar4 + 8),8);
  uStack_32 = uVar6;
  zcl_touchlink_network_join_router_rsp(auStack_3c);
  return;
}

