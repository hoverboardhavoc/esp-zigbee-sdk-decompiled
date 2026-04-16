/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_identify.o -> touchlink_identify_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_identify_req_handler(touchlink_identify_req_t *req)

{
  uint16_t uVar1;
  uint32_t uVar2;
  ezb_err_t eVar3;
  uint32_t uVar4;
  int iVar5;
  
  if (req == (touchlink_identify_req_t *)0x0) {
    return 3;
  }
  uVar2 = req->transaction_id;
  if ((uVar2 == 0) || (uVar4 = touchlink_transaction_id(0), uVar2 != uVar4)) {
    eVar3 = 3;
  }
  else {
    iVar5 = touchlink_transaction_get();
    *(undefined1 *)(iVar5 + 0x60c) = 8;
    uVar1 = req->duration;
    if (uVar1 == 0xffff) {
      uVar1 = 0xb4;
    }
    iVar5 = touchlink_transaction_get();
    *(uint16_t *)(iVar5 + 0x612) = uVar1;
    iVar5 = touchlink_transaction_get();
    touchlink_schedule_transaction_event(iVar5 + 0x60c);
    eVar3 = 0;
  }
  return eVar3;
}

