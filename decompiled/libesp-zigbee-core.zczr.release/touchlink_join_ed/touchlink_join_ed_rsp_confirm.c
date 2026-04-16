/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_join_ed.o -> touchlink_join_ed_rsp_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_join_ed_rsp_confirm(touchlink_cmd_cnf_t *cnf,void *arg)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *extraout_a1;
  
  if (cnf == (touchlink_cmd_cnf_t *)0x0) {
    cnf = (touchlink_cmd_cnf_t *)__assert_func(0,0,0);
    arg = extraout_a1;
  }
  iVar2 = touchlink_transaction_get();
  *(undefined1 *)(iVar2 + 0x60c) = 9;
  iVar2 = touchlink_transaction_get();
  if ((undefined1 *)arg == (undefined1 *)(iVar2 + 0x610)) {
    uVar1 = touchlink_convert_status(cnf->status);
    *(undefined1 *)arg = uVar1;
  }
  else {
    iVar2 = touchlink_transaction_get();
    *(undefined1 *)(iVar2 + 0x610) = 1;
  }
  iVar2 = touchlink_transaction_get();
  touchlink_schedule_transaction_event(iVar2 + 0x60c);
  return;
}

