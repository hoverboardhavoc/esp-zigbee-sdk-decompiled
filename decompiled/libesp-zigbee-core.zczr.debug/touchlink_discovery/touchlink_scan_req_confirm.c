/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_discovery.o -> touchlink_scan_req_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_scan_req_confirm(undefined1 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = touchlink_transaction_get();
  *(undefined1 *)(iVar2 + 0x60c) = 10;
  uVar1 = *param_1;
  iVar2 = touchlink_transaction_get();
  uVar1 = touchlink_convert_status(uVar1);
  *(undefined1 *)(iVar2 + 0x610) = uVar1;
  iVar2 = touchlink_transaction_get();
  *(undefined2 *)(iVar2 + 0x612) = 0xfa;
  iVar2 = touchlink_transaction_get();
  *(undefined4 *)(iVar2 + 0x614) = param_2;
  iVar2 = touchlink_transaction_get();
  touchlink_schedule_transaction_event(iVar2 + 0x60c);
  return;
}

