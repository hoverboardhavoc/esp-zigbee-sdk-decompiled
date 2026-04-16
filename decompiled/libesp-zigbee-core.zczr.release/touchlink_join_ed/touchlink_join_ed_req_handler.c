/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_join_ed.o -> touchlink_join_ed_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_join_ed_req_handler(touchlink_join_end_device_req_t *req)

{
  undefined4 *puVar1;
  uint8_t uVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  uint32_t uVar6;
  undefined1 uVar7;
  int iVar8;
  ezb_err_t eVar9;
  uint32_t uVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  ezb_af_user_cnf_callback_t p_Var14;
  undefined1 auStack_3c [2];
  undefined1 auStack_3a [2];
  zcl_touchlink_join_end_device_rsp_t rsp;
  
  if (req == (touchlink_join_end_device_req_t *)0x0) {
    req = (touchlink_join_end_device_req_t *)__assert_func(0,0,0);
  }
  uVar6 = req->transaction_id;
  if ((uVar6 == 0) || (uVar10 = touchlink_transaction_id(0), uVar6 != uVar10)) {
    p_Var14 = (ezb_af_user_cnf_callback_t)0x0;
    uVar13 = 3;
  }
  else {
    iVar8 = touchlink_transaction_get();
    *(undefined1 *)(iVar8 + 0x60c) = 0xd;
    iVar8 = touchlink_transaction_get();
    *(undefined4 *)(iVar8 + 0x610) = 3;
    iVar8 = touchlink_transaction_get();
    uVar13 = touchlink_schedule_transaction_event(iVar8 + 0x60c);
    p_Var14 = (ezb_af_user_cnf_callback_t)0x0;
    if (uVar13 == 0) {
      iVar8 = touchlink_transaction_get();
      *(undefined1 *)(iVar8 + 0x60c) = 9;
      iVar8 = touchlink_transaction_get();
      *(undefined1 *)(iVar8 + 0x610) = 0;
      p_Var14 = (ezb_af_user_cnf_callback_t)(iVar8 + 0x610);
      *(ezb_panid_t *)(iVar8 + 0x61a) = req->pan_id;
      *(uint8_t *)(iVar8 + 0x61c) = req->channel;
      *(uint16_t *)(iVar8 + 0x61e) = req->new_nwk_addr;
      uVar7 = touchlink_is_factory_new();
      *(undefined1 *)(iVar8 + 0x630) = uVar7;
      puVar1 = (undefined4 *)((int)&(req->ext_panid).field_0 + 4);
      uVar4 = *(undefined2 *)puVar1;
      uVar11 = *(undefined4 *)&(req->ext_panid).field_0;
      uVar5 = *puVar1;
      *(char *)(iVar8 + 0x611) = (char)*(undefined2 *)&(req->ext_panid).field_0;
      *(char *)(iVar8 + 0x612) = (char)((uint)uVar11 >> 8);
      *(char *)(iVar8 + 0x614) = (char)((uint)uVar11 >> 0x18);
      *(char *)(iVar8 + 0x616) = (char)((uint)uVar5 >> 8);
      *(char *)(iVar8 + 0x615) = (char)uVar4;
      *(char *)(iVar8 + 0x617) = (char)((uint)uVar5 >> 0x10);
      *(char *)(iVar8 + 0x613) = (char)((uint)uVar11 >> 0x10);
      *(char *)(iVar8 + 0x618) = (char)((uint)uVar5 >> 0x18);
      bVar3 = req->key_index;
      uVar11 = touchlink_transaction_id(0);
      iVar12 = touchlink_transaction_get();
      touchlink_decrypt_nwk_key
                (req->encrypted_nwk_key,iVar8 + 0x620,1 << (bVar3 & 0x1f) & 0xffff,uVar11,
                 *(undefined4 *)(iVar12 + 4));
    }
  }
  uVar7 = touchlink_convert_status(uVar13 & 0xff);
  uVar2 = (req->cmd_ctrl).tsn;
  memset(auStack_3c,0,0x1c);
  rsp.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
  rsp._16_4_ = touchlink_join_ed_rsp_confirm;
  auStack_3c[0] = 3;
  rsp.transaction_id._0_1_ = uVar7;
  rsp.cnf_ctx.cb = p_Var14;
  iVar8 = touchlink_transaction_get();
  memcpy(auStack_3a,(void *)(iVar8 + 8),8);
  rsp.cmd_ctrl.peer_addr.u._4_1_ = uVar2;
  eVar9 = zcl_touchlink_network_join_end_device_rsp(auStack_3c);
  return eVar9;
}

