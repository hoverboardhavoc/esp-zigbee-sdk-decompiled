/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_join_ed.o -> touchlink_join_ed_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_join_ed_rsp_handler(touchlink_join_end_device_rsp_t *rsp)

{
  uint32_t uVar1;
  uint32_t uVar2;
  ezb_err_t eVar3;
  int iVar4;
  
  if (((rsp == (touchlink_join_end_device_rsp_t *)0x0) || (uVar1 = rsp->transaction_id, uVar1 == 0))
     || (uVar2 = touchlink_transaction_id(0), uVar1 != uVar2)) {
    eVar3 = 3;
  }
  else {
    iVar4 = touchlink_transaction_get();
    *(undefined1 *)(iVar4 + 0x60c) = 0xb;
    iVar4 = touchlink_transaction_get();
    *(uint8_t *)(iVar4 + 0x610) = rsp->status;
    *(undefined1 *)(iVar4 + 0x611) = 0xb4;
    iVar4 = touchlink_transaction_get();
    eVar3 = touchlink_schedule_transaction_event(iVar4 + 0x60c);
  }
  return eVar3;
}

