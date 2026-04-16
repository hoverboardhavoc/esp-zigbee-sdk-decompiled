/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_network_start.o -> touchlink_network_start_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rsp */
/* WARNING: Unknown calling convention */

ezb_err_t touchlink_network_start_req_handler(touchlink_network_start_req_t *req)

{
  undefined4 *puVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint8_t uVar5;
  byte bVar6;
  undefined2 uVar7;
  uint32_t uVar8;
  int iVar9;
  undefined1 uVar10;
  int iVar11;
  uint32_t uVar12;
  undefined4 uVar13;
  undefined1 auStack_38 [2];
  undefined1 auStack_36 [2];
  zcl_touchlink_network_start_rsp_t rsp;
  
  if (req == (touchlink_network_start_req_t *)0x0) {
    req = (touchlink_network_start_req_t *)__assert_func(0,0,0);
  }
  uVar8 = req->transaction_id;
  if ((uVar8 == 0) || (uVar12 = touchlink_transaction_id(0), uVar8 != uVar12)) {
    iVar9 = 3;
  }
  else {
    iVar9 = touchlink_transaction_get();
    *(undefined1 *)(iVar9 + 0x60c) = 0xd;
    iVar9 = touchlink_transaction_get();
    *(undefined4 *)(iVar9 + 0x610) = 1;
    iVar9 = touchlink_transaction_get();
    iVar9 = touchlink_schedule_transaction_event(iVar9 + 0x60c);
    if (iVar9 == 0) {
      iVar9 = touchlink_transaction_get();
      *(undefined1 *)(iVar9 + 0x60c) = 3;
      iVar9 = touchlink_transaction_get();
      *(undefined1 *)(iVar9 + 0x610) = 0;
      uVar10 = touchlink_is_factory_new();
      *(undefined1 *)(iVar9 + 0x630) = uVar10;
      *(uint8_t *)(iVar9 + 0x631) = (req->cmd_ctrl).tsn;
      *(ezb_panid_t *)(iVar9 + 0x61a) = req->pan_id;
      *(uint8_t *)(iVar9 + 0x61c) = req->channel;
      uVar2 = (req->ext_panid).field_0.u8[0];
      uVar3 = (req->ext_panid).field_0.u8[2];
      *(uint16_t *)(iVar9 + 0x61e) = req->nwk_addr;
      uVar4 = (req->ext_panid).field_0.u8[1];
      puVar1 = (undefined4 *)((int)&(req->ext_panid).field_0 + 4);
      uVar7 = *(undefined2 *)puVar1;
      uVar5 = (req->ext_panid).field_0.u8[3];
      uVar13 = *puVar1;
      *(uint8_t *)(iVar9 + 0x611) = uVar2;
      *(uint8_t *)(iVar9 + 0x612) = uVar4;
      *(uint8_t *)(iVar9 + 0x614) = uVar5;
      *(char *)(iVar9 + 0x616) = (char)((uint)uVar13 >> 8);
      *(uint8_t *)(iVar9 + 0x613) = uVar3;
      *(char *)(iVar9 + 0x615) = (char)uVar7;
      *(char *)(iVar9 + 0x617) = (char)((uint)uVar13 >> 0x10);
      *(char *)(iVar9 + 0x618) = (char)((uint)uVar13 >> 0x18);
      bVar6 = req->key_index;
      uVar13 = touchlink_transaction_id(0);
      iVar11 = touchlink_transaction_get();
      touchlink_decrypt_nwk_key
                (req->encrypted_nwk_key,iVar9 + 0x620,1 << (bVar6 & 0x1f) & 0xffff,uVar13,
                 *(undefined4 *)(iVar11 + 4));
      iVar9 = touchlink_transaction_get();
      iVar9 = touchlink_schedule_transaction_event(iVar9 + 0x60c);
      if (iVar9 == 0) {
        return 0;
      }
    }
  }
  uVar2 = (req->cmd_ctrl).tsn;
  memset(auStack_38,0,0x28);
  rsp.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
  rsp.transaction_id._0_1_ = 1;
  rsp._28_4_ = touchlink_network_start_rsp_confirm;
  auStack_38[0] = 3;
  rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  iVar11 = touchlink_transaction_get();
  memcpy(auStack_36,(void *)(iVar11 + 8),8);
  rsp.cmd_ctrl.peer_addr.u._4_1_ = uVar2;
  zcl_touchlink_network_start_rsp(auStack_38);
  return iVar9;
}

