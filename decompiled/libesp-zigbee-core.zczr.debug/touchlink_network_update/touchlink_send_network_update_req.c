/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_network_update.o -> touchlink_send_network_update_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_send_network_update_req(touchlink_disc_dev_info_t *dev_info,void *arg)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint32_t *puVar4;
  ezb_err_t eVar5;
  undefined4 uStack_38;
  zcl_touchlink_network_update_req_t req;
  
  uStack_38 = 0;
  req.cmd_ctrl.peer_addr._0_4_ = 0;
  req.cmd_ctrl.peer_addr.u._2_4_ = 0;
  req.cmd_ctrl._8_4_ = 0;
  req.transaction_id = 0;
  req.ext_panid.field_0.u64._0_4_ = 0;
  req.ext_panid.field_0.u64._4_4_ = 0;
  req.network_update_id = '\0';
  req.channel = '\0';
  req.pan_id = 0;
  req.nwk_addr = 0;
  req._30_2_ = 0;
  req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  if (dev_info == (touchlink_disc_dev_info_t *)0x0) {
    eVar5 = 2;
  }
  else {
    iVar3 = touchlink_transaction_id(0);
    if (iVar3 == 0) {
      eVar5 = 3;
    }
    else {
      req.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
      uVar1 = touchlink_nwk_update_id();
      req.ext_panid.field_0.u8[4] = uVar1;
      uVar1 = touchlink_current_channel();
      req.ext_panid.field_0.u8[5] = uVar1;
      uVar2 = touchlink_pan_id();
      req.ext_panid.field_0.u64._6_2_ = uVar2;
      req._24_2_ = (dev_info->basic).nwk_addr;
      puVar4 = (uint32_t *)touchlink_extended_pan_id();
      req.transaction_id = *puVar4;
      req.ext_panid.field_0.u64._0_4_ = puVar4[1];
      req._28_4_ = touchlink_network_update_req_confirm;
      uStack_38 = CONCAT31(uStack_38._1_3_,3);
      req.cmd_ctrl.peer_addr._0_4_ = *(undefined4 *)((int)&(dev_info->basic).ieee_addr.field_0 + 2);
      uStack_38 = CONCAT13((dev_info->basic).ieee_addr.field_0.u8[1],
                           CONCAT12((dev_info->basic).ieee_addr.field_0.u8[0],(undefined2)uStack_38)
                          );
      req.cmd_ctrl.peer_addr.u.group_addr.bcast =
           *(undefined2 *)((int)&(dev_info->basic).ieee_addr.field_0 + 6);
      req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)arg;
      eVar5 = zcl_touchlink_network_update_req(&uStack_38);
    }
  }
  return eVar5;
}

