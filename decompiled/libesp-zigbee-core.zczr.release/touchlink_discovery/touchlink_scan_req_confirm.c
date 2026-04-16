/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_discovery.o -> touchlink_scan_req_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_scan_req_confirm(touchlink_cmd_cnf_t *cnf,void *arg)

{
  uint8_t uVar1;
  undefined1 uVar2;
  int iVar3;
  
  iVar3 = touchlink_transaction_get();
  *(undefined1 *)(iVar3 + 0x60c) = 10;
  uVar1 = cnf->status;
  iVar3 = touchlink_transaction_get();
  uVar2 = touchlink_convert_status(uVar1);
  *(undefined1 *)(iVar3 + 0x610) = uVar2;
  iVar3 = touchlink_transaction_get();
  *(undefined2 *)(iVar3 + 0x612) = 0xfa;
  iVar3 = touchlink_transaction_get();
  *(void **)(iVar3 + 0x614) = arg;
  iVar3 = touchlink_transaction_get();
  touchlink_schedule_transaction_event(iVar3 + 0x60c);
  return;
}

