/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_network_start.o -> touchlink_network_start_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_network_start_rsp_handler(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (((param_1 == 0) || (iVar2 = *(int *)(param_1 + 0xc), iVar2 == 0)) ||
     (iVar5 = touchlink_transaction_id(0), iVar2 != iVar5)) {
    uVar6 = 3;
  }
  else {
    iVar2 = touchlink_transaction_get();
    *(undefined1 *)(iVar2 + 0x60c) = 9;
    iVar2 = touchlink_transaction_get();
    *(undefined1 *)(iVar2 + 0x610) = *(undefined1 *)(param_1 + 0x10);
    uVar3 = touchlink_is_factory_new();
    *(undefined1 *)(iVar2 + 0x630) = uVar3;
    *(undefined2 *)(iVar2 + 0x61a) = *(undefined2 *)(param_1 + 0x1c);
    *(undefined1 *)(iVar2 + 0x61c) = *(undefined1 *)(param_1 + 0x1a);
    uVar4 = touchlink_short_address();
    *(undefined2 *)(iVar2 + 0x61e) = uVar4;
    uVar6 = *(undefined4 *)(param_1 + 0x11);
    uVar4 = *(undefined2 *)(param_1 + 0x15);
    uVar1 = *(undefined4 *)(param_1 + 0x15);
    *(char *)(iVar2 + 0x611) = (char)*(undefined2 *)(param_1 + 0x11);
    *(char *)(iVar2 + 0x612) = (char)((uint)uVar6 >> 8);
    *(char *)(iVar2 + 0x613) = (char)((uint)uVar6 >> 0x10);
    *(char *)(iVar2 + 0x614) = (char)((uint)uVar6 >> 0x18);
    *(char *)(iVar2 + 0x615) = (char)uVar4;
    *(char *)(iVar2 + 0x616) = (char)((uint)uVar1 >> 8);
    *(char *)(iVar2 + 0x617) = (char)((uint)uVar1 >> 0x10);
    *(char *)(iVar2 + 0x618) = (char)((uint)uVar1 >> 0x18);
    iVar2 = touchlink_transaction_get();
    uVar6 = touchlink_schedule_transaction_event(iVar2 + 0x60c);
  }
  return uVar6;
}

