/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_factory_new.o -> touchlink_factory_new_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_factory_new_req_handler(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 == 0) {
    return 2;
  }
  iVar4 = *(int *)(param_1 + 0xc);
  if ((iVar4 != 0) && (iVar5 = touchlink_transaction_id(0), iVar4 == iVar5)) {
    iVar4 = touchlink_is_factory_new();
    if (iVar4 != 0) {
      return 3;
    }
    iVar4 = touchlink_transaction_get();
    *(undefined1 *)(iVar4 + 0x60c) = 6;
    iVar4 = touchlink_transaction_get();
    *(undefined1 *)(iVar4 + 0x610) = 0;
    iVar4 = touchlink_transaction_get();
    uVar1 = *(undefined2 *)(param_1 + 6);
    uVar2 = *(undefined4 *)(param_1 + 2);
    uVar3 = *(undefined4 *)(param_1 + 6);
    *(char *)(iVar4 + 0x611) = (char)*(undefined2 *)(param_1 + 2);
    *(char *)(iVar4 + 0x612) = (char)((uint)uVar2 >> 8);
    *(char *)(iVar4 + 0x614) = (char)((uint)uVar2 >> 0x18);
    *(char *)(iVar4 + 0x616) = (char)((uint)uVar3 >> 8);
    *(char *)(iVar4 + 0x613) = (char)((uint)uVar2 >> 0x10);
    *(char *)(iVar4 + 0x615) = (char)uVar1;
    *(char *)(iVar4 + 0x617) = (char)((uint)uVar3 >> 0x10);
    *(char *)(iVar4 + 0x618) = (char)((uint)uVar3 >> 0x18);
    iVar4 = touchlink_transaction_get();
    touchlink_schedule_transaction_event(iVar4 + 0x60c);
  }
  return 0;
}

