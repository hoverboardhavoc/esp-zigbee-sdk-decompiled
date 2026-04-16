/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_discovery.o -> touchlink_send_scan_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_send_scan_rsp(uint8_t tsn)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  uint8_t uVar4;
  undefined2 uVar5;
  undefined4 *puVar6;
  int iVar7;
  ezb_err_t eVar8;
  undefined1 *puVar9;
  undefined4 uStack_4c;
  zcl_touchlink_scan_rsp_t rsp;
  
  uStack_4c = 0;
  rsp.cmd_ctrl.peer_addr._0_4_ = 0;
  rsp.cmd_ctrl.peer_addr.u._2_4_ = 0;
  rsp.cmd_ctrl._8_4_ = 0;
  rsp.transaction_id = 0;
  rsp.response_id = 0;
  rsp.zigbee_info = '\0';
  rsp.touchlink_info = '\0';
  rsp.key_bitmask = 0;
  rsp._24_4_ = 0;
  rsp.ext_panid.field_0.u64._3_4_ = 0;
  rsp._32_4_ = 0;
  rsp.pan_id = 0;
  rsp.nwk_addr = 0;
  rsp.n_subdevs = '\0';
  rsp.total_group_ids = '\0';
  rsp.sub_device.ep_id = '\0';
  rsp.sub_device._1_1_ = 0;
  rsp.sub_device.profile_id = 0;
  rsp.sub_device.device_id = 0;
  rsp.sub_device.version = '\0';
  rsp.sub_device.n_group_ids = '\0';
  rsp._50_2_ = 0;
  rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  rsp.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
  rsp.transaction_id = touchlink_response_id(1);
  uVar3 = touchlink_zigbee_info();
  rsp.response_id = CONCAT31(rsp.response_id._1_3_,uVar3);
  uVar3 = touchlink_touchlink_info();
  rsp.response_id._0_2_ = CONCAT11(uVar3,(undefined1)rsp.response_id);
  uVar5 = touchlink_get_key_bitmask();
  rsp.response_id = CONCAT22(uVar5,(undefined2)rsp.response_id);
  uVar4 = touchlink_get_rssi_correction();
  rsp.zigbee_info = uVar4;
  uVar3 = touchlink_nwk_update_id();
  rsp.ext_panid.field_0.u8[4] = uVar3;
  uVar3 = touchlink_current_channel();
  rsp.ext_panid.field_0.u8[5] = uVar3;
  uVar5 = touchlink_pan_id();
  rsp._32_2_ = uVar5;
  uVar5 = touchlink_short_address();
  rsp._34_2_ = uVar5;
  uVar3 = touchlink_n_sub_device_size();
  rsp.pan_id._0_1_ = uVar3;
  uVar3 = touchlink_total_groups_size();
  rsp.pan_id._1_1_ = uVar3;
  puVar6 = (undefined4 *)touchlink_extended_pan_id();
  uVar1 = *puVar6;
  uVar2 = puVar6[1];
  rsp.touchlink_info = (uint8_t)*(undefined3 *)puVar6;
  rsp.key_bitmask._0_1_ = (char)((uint)uVar1 >> 8);
  rsp.key_bitmask._1_1_ = (char)((uint)uVar1 >> 0x10);
  rsp.ext_panid.field_0.u8[0] = (char)*(undefined3 *)(puVar6 + 1);
  rsp.rssi_correction = (uint8_t)((uint)uVar1 >> 0x18);
  rsp.ext_panid.field_0.u8[1] = (char)((uint)uVar2 >> 8);
  rsp.ext_panid.field_0.u8[2] = (char)((uint)uVar2 >> 0x10);
  rsp.ext_panid.field_0.u8[3] = (char)((uint)uVar2 >> 0x18);
  if (((rsp._36_4_ & 0xff) == 1) &&
     (puVar9 = (undefined1 *)af_get_next_simple_desc(0), puVar9 != (undefined1 *)0x0)) {
    rsp.nwk_addr._0_1_ = *puVar9;
    rsp._40_4_ = *(undefined4 *)(puVar9 + 2);
    rsp.sub_device._2_4_ =
         CONCAT31(rsp.sub_device._3_3_,(char)*(undefined2 *)(puVar9 + 6)) & 0xffffff0f;
    rsp.sub_device.profile_id = (uint16_t)(byte)rsp.sub_device.profile_id;
  }
  rsp.sub_device.version = '\0';
  rsp.sub_device.n_group_ids = '\0';
  rsp._50_2_ = 1;
  rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  uStack_4c = CONCAT31(uStack_4c._1_3_,3);
  iVar7 = touchlink_transaction_get();
  rsp.cmd_ctrl.peer_addr._0_4_ = *(undefined4 *)(iVar7 + 10);
  uStack_4c = CONCAT22(*(undefined2 *)(iVar7 + 8),(undefined2)uStack_4c);
  rsp.cmd_ctrl.peer_addr.u._4_1_ = tsn;
  rsp.cmd_ctrl.peer_addr.u.group_addr.bcast = *(undefined2 *)(iVar7 + 0xe);
  eVar8 = zcl_touchlink_scan_rsp(&uStack_4c);
  return eVar8;
}

