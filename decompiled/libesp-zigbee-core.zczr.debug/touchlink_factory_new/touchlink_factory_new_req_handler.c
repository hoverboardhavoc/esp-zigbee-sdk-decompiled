/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_factory_new.o -> touchlink_factory_new_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_factory_new_req_handler(zcl_touchlink_reset_to_factory_new_req_t *req)

{
  ezb_addr_t *peVar1;
  undefined4 *puVar2;
  ezb_grpaddr_t eVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  uint32_t uVar6;
  ezb_err_t eVar7;
  uint32_t uVar8;
  int iVar9;
  
  if (req == (zcl_touchlink_reset_to_factory_new_req_t *)0x0) {
    eVar7 = 2;
  }
  else {
    uVar6 = req->transaction_id;
    if ((uVar6 == 0) || (uVar8 = touchlink_transaction_id(0), uVar6 != uVar8)) {
      eVar7 = 0;
    }
    else {
      iVar9 = touchlink_is_factory_new();
      if (iVar9 == 0) {
        iVar9 = touchlink_transaction_get();
        *(undefined1 *)(iVar9 + 0x60c) = 6;
        iVar9 = touchlink_transaction_get();
        *(undefined1 *)(iVar9 + 0x610) = 0;
        iVar9 = touchlink_transaction_get();
        peVar1 = &(req->cmd_ctrl).peer_addr.u;
        eVar3 = peVar1->group_addr;
        puVar2 = (undefined4 *)((int)&(req->cmd_ctrl).peer_addr.u + 4);
        uVar4 = *(undefined2 *)puVar2;
        uVar5 = *puVar2;
        *(char *)(iVar9 + 0x611) = (char)(peVar1->group_addr).group;
        *(char *)(iVar9 + 0x612) = eVar3.group._1_1_;
        *(char *)(iVar9 + 0x613) = eVar3.bcast;
        *(char *)(iVar9 + 0x614) = eVar3.bcast._1_1_;
        *(char *)(iVar9 + 0x615) = (char)uVar4;
        *(char *)(iVar9 + 0x616) = (char)((uint)uVar5 >> 8);
        *(char *)(iVar9 + 0x617) = (char)((uint)uVar5 >> 0x10);
        *(char *)(iVar9 + 0x618) = (char)((uint)uVar5 >> 0x18);
        iVar9 = touchlink_transaction_get();
        touchlink_schedule_transaction_event(iVar9 + 0x60c);
        eVar7 = 0;
      }
      else {
        eVar7 = 3;
      }
    }
  }
  return eVar7;
}

