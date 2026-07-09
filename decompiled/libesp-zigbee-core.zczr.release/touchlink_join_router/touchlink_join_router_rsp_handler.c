/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_join_router.o -> touchlink_join_router_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_join_router_rsp_handler(int param_1)

{
  undefined3 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  
  if (param_1 == 0) {
    return 3;
  }
  iVar3 = *(int *)(param_1 + 0xc);
  if ((iVar3 != 0) && (iVar6 = touchlink_transaction_id(0), iVar3 == iVar6)) {
    iVar3 = touchlink_transaction_get();
    *(undefined1 *)(iVar3 + 0x60c) = 9;
    iVar3 = touchlink_transaction_get();
    *(undefined1 *)(iVar3 + 0x610) = *(undefined1 *)(param_1 + 0x10);
    uVar4 = touchlink_is_factory_new();
    *(undefined1 *)(iVar3 + 0x630) = uVar4;
    uVar5 = touchlink_pan_id();
    *(undefined2 *)(iVar3 + 0x61a) = uVar5;
    uVar4 = touchlink_current_channel();
    *(undefined1 *)(iVar3 + 0x61c) = uVar4;
    puVar7 = (undefined4 *)touchlink_extended_pan_id();
    uVar8 = *puVar7;
    uVar1 = *(undefined3 *)(puVar7 + 1);
    uVar2 = puVar7[1];
    *(char *)(iVar3 + 0x611) = (char)*(undefined3 *)puVar7;
    *(char *)(iVar3 + 0x612) = (char)((uint)uVar8 >> 8);
    *(char *)(iVar3 + 0x614) = (char)((uint)uVar8 >> 0x18);
    *(char *)(iVar3 + 0x616) = (char)((uint)uVar2 >> 8);
    *(char *)(iVar3 + 0x613) = (char)((uint)uVar8 >> 0x10);
    *(char *)(iVar3 + 0x615) = (char)uVar1;
    *(char *)(iVar3 + 0x617) = (char)((uint)uVar2 >> 0x10);
    *(char *)(iVar3 + 0x618) = (char)((uint)uVar2 >> 0x18);
    iVar3 = touchlink_transaction_get();
    uVar8 = touchlink_schedule_transaction_event(iVar3 + 0x60c);
    return uVar8;
  }
  return 3;
}

