/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_join_router.o -> touchlink_join_router_rsp_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_join_router_rsp_confirm(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  if (param_1 == (undefined1 *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink_join_router.c",
                  0x42,"touchlink_join_router_rsp_confirm",0x10000);
  }
  else {
    iVar2 = touchlink_transaction_get();
    *(undefined1 *)(iVar2 + 0x60c) = 5;
    iVar2 = touchlink_transaction_get();
    if ((undefined1 *)(iVar2 + 0x610) != param_2) {
      iVar2 = touchlink_transaction_get();
      *(undefined1 *)(iVar2 + 0x610) = 1;
      goto _L0;
    }
  }
  uVar1 = touchlink_convert_status(*param_1);
  *param_2 = uVar1;
_L0:
  iVar2 = touchlink_transaction_get();
  touchlink_schedule_transaction_event(iVar2 + 0x60c);
  return;
}

