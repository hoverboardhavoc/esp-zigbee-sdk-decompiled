/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_discovery.o -> touchlink_scan_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_scan_req_handler(touchlink_scan_req_t *req)

{
  ezb_addr_t *peVar1;
  undefined4 *puVar2;
  ezb_grpaddr_t eVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  uint32_t uVar6;
  undefined1 uVar7;
  uint32_t *puVar8;
  int iVar9;
  ezb_err_t eVar10;
  
  if (req == (touchlink_scan_req_t *)0x0) {
    eVar10 = 0;
  }
  else {
    uVar6 = req->transaction_id;
    if (uVar6 == 0) {
      eVar10 = 2;
    }
    else {
      puVar8 = (uint32_t *)touchlink_transaction_get();
      if (uVar6 == *puVar8) {
        iVar9 = touchlink_transaction_get();
        if (((req->cmd_ctrl).peer_addr.u.group_addr == *(ezb_grpaddr_t *)(iVar9 + 8)) &&
           (*(int *)((int)&(req->cmd_ctrl).peer_addr.u + 4) == *(int *)(iVar9 + 0xc))) {
          return 3;
        }
      }
      touchlink_set_transaction_id(req->transaction_id);
      iVar9 = touchlink_transaction_get();
      peVar1 = &(req->cmd_ctrl).peer_addr.u;
      eVar3 = peVar1->group_addr;
      puVar2 = (undefined4 *)((int)&(req->cmd_ctrl).peer_addr.u + 4);
      uVar4 = *(undefined2 *)puVar2;
      uVar5 = *puVar2;
      *(char *)(iVar9 + 8) = (char)(peVar1->group_addr).group;
      *(char *)(iVar9 + 9) = eVar3.group._1_1_;
      *(char *)(iVar9 + 10) = eVar3.bcast;
      *(char *)(iVar9 + 0xb) = eVar3.bcast._1_1_;
      *(char *)(iVar9 + 0xc) = (char)uVar4;
      *(char *)(iVar9 + 0xd) = (char)((uint)uVar5 >> 8);
      *(char *)(iVar9 + 0xe) = (char)((uint)uVar5 >> 0x10);
      *(char *)(iVar9 + 0xf) = (char)((uint)uVar5 >> 0x18);
      iVar9 = touchlink_transaction_get();
      *(undefined1 *)(iVar9 + 0x60c) = 1;
      iVar9 = touchlink_transaction_get();
      *(undefined1 *)(iVar9 + 0x610) = 0;
      iVar9 = touchlink_transaction_get();
      *(uint32_t *)(iVar9 + 0x614) = req->transaction_id;
      iVar9 = touchlink_transaction_get();
      *(undefined2 *)(iVar9 + 0x618) = 0x1e46;
      iVar9 = touchlink_transaction_get();
      uVar7 = touchlink_current_channel();
      *(undefined1 *)(iVar9 + 0x61a) = uVar7;
      iVar9 = touchlink_transaction_get();
      iVar9 = touchlink_schedule_transaction_event(iVar9 + 0x60c);
      if (iVar9 == 0) {
        iVar9 = touchlink_device_info_get();
        if (*(char *)(iVar9 + 3) < (req->cmd_ctrl).rssi) {
          if ((req->zigbee_info & 0x10) == 0) {
            eVar10 = touchlink_send_scan_rsp((req->cmd_ctrl).tsn);
          }
          else {
            eVar10 = 2;
          }
        }
        else {
          eVar10 = 2;
        }
      }
      else {
        eVar10 = 0;
      }
    }
  }
  return eVar10;
}

