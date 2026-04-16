/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_discovery.o -> touchlink_device_info_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_device_info_req_handler(touchlink_device_info_req_t *req)

{
  uint32_t uVar1;
  uint32_t *puVar2;
  ezb_err_t eVar3;
  
  if (req == (touchlink_device_info_req_t *)0x0) {
    eVar3 = 2;
  }
  else {
    uVar1 = req->transaction_id;
    if ((uVar1 == 0) || (puVar2 = (uint32_t *)touchlink_transaction_get(), uVar1 != *puVar2)) {
      eVar3 = 3;
    }
    else {
      eVar3 = touchlink_send_device_info_rsp(req->start_index,(req->cmd_ctrl).tsn);
    }
  }
  return eVar3;
}

