/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_discovery.o -> touchlink_scan_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rsp */
/* WARNING: Unknown calling convention */

ezb_err_t touchlink_scan_req_handler(touchlink_scan_req_t *req)

{
  ezb_addr_t *peVar1;
  uint8_t uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  ezb_grpaddr_t eVar6;
  uint32_t uVar7;
  undefined1 uVar8;
  uint32_t *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined1 *puVar12;
  ezb_err_t eVar13;
  undefined1 auStack_4c [2];
  undefined1 auStack_4a [2];
  zcl_touchlink_scan_rsp_t rsp;
  
  if (req == (touchlink_scan_req_t *)0x0) {
    return 0;
  }
  uVar7 = req->transaction_id;
  if (uVar7 != 0) {
    puVar9 = (uint32_t *)touchlink_transaction_get();
    if (uVar7 == *puVar9) {
      iVar10 = touchlink_transaction_get();
      if (((req->cmd_ctrl).peer_addr.u.group_addr == *(ezb_grpaddr_t *)(iVar10 + 8)) &&
         (*(int *)((int)&(req->cmd_ctrl).peer_addr.u + 4) == *(int *)(iVar10 + 0xc))) {
        return 3;
      }
    }
    touchlink_set_transaction_id(req->transaction_id);
    iVar10 = touchlink_transaction_get();
    peVar1 = &(req->cmd_ctrl).peer_addr.u;
    puVar11 = (undefined4 *)((int)&(req->cmd_ctrl).peer_addr.u + 4);
    uVar5 = *(undefined2 *)puVar11;
    eVar6 = peVar1->group_addr;
    uVar3 = *puVar11;
    *(char *)(iVar10 + 8) = (char)(peVar1->group_addr).group;
    *(char *)(iVar10 + 9) = eVar6.group._1_1_;
    *(char *)(iVar10 + 0xb) = eVar6.bcast._1_1_;
    *(char *)(iVar10 + 0xd) = (char)((uint)uVar3 >> 8);
    *(char *)(iVar10 + 10) = eVar6.bcast;
    *(char *)(iVar10 + 0xc) = (char)uVar5;
    *(char *)(iVar10 + 0xe) = (char)((uint)uVar3 >> 0x10);
    *(char *)(iVar10 + 0xf) = (char)((uint)uVar3 >> 0x18);
    iVar10 = touchlink_transaction_get();
    *(undefined1 *)(iVar10 + 0x60c) = 1;
    iVar10 = touchlink_transaction_get();
    *(undefined1 *)(iVar10 + 0x610) = 0;
    iVar10 = touchlink_transaction_get();
    *(uint32_t *)(iVar10 + 0x614) = req->transaction_id;
    iVar10 = touchlink_transaction_get();
    *(undefined2 *)(iVar10 + 0x618) = 0x1e46;
    iVar10 = touchlink_transaction_get();
    uVar8 = touchlink_current_channel();
    *(undefined1 *)(iVar10 + 0x61a) = uVar8;
    iVar10 = touchlink_transaction_get();
    iVar10 = touchlink_schedule_transaction_event(iVar10 + 0x60c);
    if (iVar10 != 0) {
      return 0;
    }
    iVar10 = touchlink_device_info_get();
    if ((*(char *)(iVar10 + 3) < (req->cmd_ctrl).rssi) && ((req->zigbee_info & 0x10) == 0)) {
      uVar2 = (req->cmd_ctrl).tsn;
      memset(auStack_4c,0,0x3c);
      rsp.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
      rsp.transaction_id = touchlink_response_id(1);
      rsp.response_id._0_1_ = touchlink_zigbee_info();
      rsp.response_id._1_1_ = touchlink_touchlink_info();
      rsp.response_id._2_2_ = touchlink_get_key_bitmask();
      rsp.zigbee_info = touchlink_get_rssi_correction();
      rsp.ext_panid.field_0.u8[4] = touchlink_nwk_update_id();
      rsp.ext_panid.field_0.u8[5] = touchlink_current_channel();
      rsp._32_2_ = touchlink_pan_id();
      rsp._34_2_ = touchlink_short_address();
      rsp.pan_id._0_1_ = touchlink_n_sub_device_size();
      rsp.pan_id._1_1_ = touchlink_total_groups_size();
      puVar11 = (undefined4 *)touchlink_extended_pan_id();
      uVar3 = *puVar11;
      uVar4 = puVar11[1];
      rsp.touchlink_info = (uint8_t)*(undefined3 *)puVar11;
      rsp.key_bitmask._0_1_ = (undefined1)((uint)uVar3 >> 8);
      rsp.rssi_correction = (uint8_t)((uint)uVar3 >> 0x18);
      rsp.ext_panid.field_0.u8[1] = (uint8_t)((uint)uVar4 >> 8);
      rsp.ext_panid.field_0.u8[3] = (uint8_t)((uint)uVar4 >> 0x18);
      rsp.key_bitmask._1_1_ = (undefined1)((uint)uVar3 >> 0x10);
      rsp.ext_panid.field_0.u8[0] = (uint8_t)*(undefined3 *)(puVar11 + 1);
      rsp.ext_panid.field_0.u8[2] = (uint8_t)((uint)uVar4 >> 0x10);
      if (((char)rsp.pan_id == '\x01') &&
         (puVar12 = (undefined1 *)af_get_next_simple_desc(0), puVar12 != (undefined1 *)0x0)) {
        rsp.nwk_addr._0_1_ = *puVar12;
        rsp._40_2_ = *(undefined2 *)(puVar12 + 2);
        rsp.sub_device._0_2_ = *(undefined2 *)(puVar12 + 4);
        rsp.sub_device.profile_id._1_1_ = 0;
        rsp.sub_device.profile_id._0_1_ = (byte)*(undefined2 *)(puVar12 + 6) & 0xf;
      }
      rsp.sub_device.version = '\0';
      rsp.sub_device.n_group_ids = '\0';
      rsp._50_2_ = 1;
      auStack_4c[0] = 3;
      rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
      iVar10 = touchlink_transaction_get();
      memcpy(auStack_4a,(void *)(iVar10 + 8),8);
      rsp.cmd_ctrl.peer_addr.u._4_1_ = uVar2;
      eVar13 = zcl_touchlink_scan_rsp(auStack_4c);
      return eVar13;
    }
  }
  return 2;
}

