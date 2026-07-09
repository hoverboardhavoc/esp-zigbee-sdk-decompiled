/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_join_ed.o -> touchlink_join_ed_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_join_ed_rsp_handler(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (((param_1 == 0) || (iVar1 = *(int *)(param_1 + 0xc), iVar1 == 0)) ||
     (iVar2 = touchlink_transaction_id(0), iVar1 != iVar2)) {
    uVar3 = 3;
  }
  else {
    iVar1 = touchlink_transaction_get();
    *(undefined1 *)(iVar1 + 0x60c) = 0xb;
    iVar1 = touchlink_transaction_get();
    *(undefined1 *)(iVar1 + 0x610) = *(undefined1 *)(param_1 + 0x10);
    *(undefined1 *)(iVar1 + 0x611) = 0xb4;
    iVar1 = touchlink_transaction_get();
    uVar3 = touchlink_schedule_transaction_event(iVar1 + 0x60c);
  }
  return uVar3;
}

