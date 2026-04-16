/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_factory_new.o -> touchlink_factory_new_req_handler
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
  undefined2 uVar3;
  ezb_grpaddr_t eVar4;
  undefined4 uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  int iVar8;
  
  if (req == (zcl_touchlink_reset_to_factory_new_req_t *)0x0) {
    return 2;
  }
  uVar6 = req->transaction_id;
  if ((uVar6 != 0) && (uVar7 = touchlink_transaction_id(0), uVar6 == uVar7)) {
    iVar8 = touchlink_is_factory_new();
    if (iVar8 != 0) {
      return 3;
    }
    iVar8 = touchlink_transaction_get();
    *(undefined1 *)(iVar8 + 0x60c) = 6;
    iVar8 = touchlink_transaction_get();
    *(undefined1 *)(iVar8 + 0x610) = 0;
    iVar8 = touchlink_transaction_get();
    peVar1 = &(req->cmd_ctrl).peer_addr.u;
    puVar2 = (undefined4 *)((int)&(req->cmd_ctrl).peer_addr.u + 4);
    uVar3 = *(undefined2 *)puVar2;
    eVar4 = peVar1->group_addr;
    uVar5 = *puVar2;
    *(char *)(iVar8 + 0x611) = (char)(peVar1->group_addr).group;
    *(char *)(iVar8 + 0x612) = eVar4.group._1_1_;
    *(char *)(iVar8 + 0x614) = eVar4.bcast._1_1_;
    *(char *)(iVar8 + 0x616) = (char)((uint)uVar5 >> 8);
    *(char *)(iVar8 + 0x613) = eVar4.bcast;
    *(char *)(iVar8 + 0x615) = (char)uVar3;
    *(char *)(iVar8 + 0x617) = (char)((uint)uVar5 >> 0x10);
    *(char *)(iVar8 + 0x618) = (char)((uint)uVar5 >> 0x18);
    iVar8 = touchlink_transaction_get();
    touchlink_schedule_transaction_event(iVar8 + 0x60c);
  }
  return 0;
}

