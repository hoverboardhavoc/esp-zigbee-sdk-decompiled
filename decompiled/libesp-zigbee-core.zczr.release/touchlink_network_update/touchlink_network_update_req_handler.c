/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_network_update.o -> touchlink_network_update_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_network_update_req_handler(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  
  if (param_1 == 0) {
    return 2;
  }
  iVar3 = *(int *)(param_1 + 0xc);
  if ((iVar3 == 0) || (iVar4 = touchlink_transaction_id(0), iVar3 != iVar4)) {
    uVar7 = 2;
  }
  else {
    piVar5 = (int *)touchlink_extended_pan_id();
    if (((*(int *)(param_1 + 0x10) == *piVar5) && (*(int *)(param_1 + 0x14) == piVar5[1])) &&
       (uVar2 = *(ushort *)(param_1 + 0x1a), uVar6 = touchlink_pan_id(), uVar2 == uVar6)) {
      iVar3 = touchlink_transaction_get();
      *(undefined1 *)(iVar3 + 0x60c) = 7;
      iVar3 = touchlink_transaction_get();
      *(undefined1 *)(iVar3 + 0x611) = *(undefined1 *)(param_1 + 0x19);
      bVar1 = *(byte *)(param_1 + 0x18);
      iVar3 = touchlink_transaction_get();
      *(ushort *)(iVar3 + 0x612) = (ushort)bVar1;
      iVar3 = touchlink_transaction_get();
      touchlink_schedule_transaction_event(iVar3 + 0x60c);
      uVar7 = 0;
    }
    else {
      uVar7 = 3;
    }
  }
  return uVar7;
}

