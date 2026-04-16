/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_network_update.o -> touchlink_network_update_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_network_update_req_handler(zcl_touchlink_network_update_req_t *req)

{
  byte bVar1;
  ushort uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  ezb_err_t eVar8;
  
  if (req == (zcl_touchlink_network_update_req_t *)0x0) {
    return 2;
  }
  uVar3 = req->transaction_id;
  if ((uVar3 == 0) || (uVar4 = touchlink_transaction_id(0), uVar3 != uVar4)) {
    eVar8 = 2;
  }
  else {
    piVar5 = (int *)touchlink_extended_pan_id();
    if (((*(int *)&(req->ext_panid).field_0 == *piVar5) &&
        (*(int *)((int)&(req->ext_panid).field_0 + 4) == piVar5[1])) &&
       (uVar2 = req->pan_id, uVar6 = touchlink_pan_id(), uVar2 == uVar6)) {
      iVar7 = touchlink_transaction_get();
      *(undefined1 *)(iVar7 + 0x60c) = 7;
      iVar7 = touchlink_transaction_get();
      *(uint8_t *)(iVar7 + 0x611) = req->channel;
      bVar1 = req->network_update_id;
      iVar7 = touchlink_transaction_get();
      *(ushort *)(iVar7 + 0x612) = (ushort)bVar1;
      iVar7 = touchlink_transaction_get();
      touchlink_schedule_transaction_event(iVar7 + 0x60c);
      eVar8 = 0;
    }
    else {
      eVar8 = 3;
    }
  }
  return eVar8;
}

