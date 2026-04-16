/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_join_router.o -> touchlink_send_join_router_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

ezb_err_t touchlink_send_join_router_req(touchlink_disc_dev_info_t *dev_info)

{
  uint16_t uVar1;
  int iVar2;
  ezb_err_t eVar3;
  uint32_t *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_54 [2];
  uint8_t uStack_52;
  uint8_t uStack_51;
  zcl_touchlink_join_router_req_t req;
  
  memset(auStack_54,0,0x44);
  if (dev_info == (touchlink_disc_dev_info_t *)0x0) {
    eVar3 = 2;
  }
  else {
    iVar2 = touchlink_transaction_id(0);
    if (iVar2 == 0) {
      eVar3 = 3;
    }
    else {
      iVar2 = touchlink_disc_table_entry_exists(dev_info);
      if (iVar2 == 0) {
        eVar3 = 5;
      }
      else if (((dev_info->basic).zigbee_info & 3) == 1) {
        req.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
        puVar4 = (uint32_t *)touchlink_extended_pan_id();
        req.transaction_id = *puVar4;
        req.ext_panid.field_0.u64._0_4_ = puVar4[1];
        uVar5 = touchlink_nwk_key();
        uVar1 = (dev_info->basic).key_bitmask;
        uVar6 = touchlink_transaction_id(0);
        req.ext_panid.field_0.u8[4] =
             touchlink_encrypt_nwk_key
                       (uVar5,(undefined1 *)((int)&req.ext_panid.field_0 + 5),uVar1,uVar6,
                        (dev_info->basic).response_id);
        req.encrypted_nwk_key[0xc] = touchlink_nwk_update_id();
        req.encrypted_nwk_key[0xd] = touchlink_current_channel();
        req._40_2_ = touchlink_pan_id();
        req._42_2_ = nwk_assign_shortaddr();
        req.pan_id = 1;
        req.new_nwk_addr = 0xfeff;
        req.group_id_begin = 1;
        req.group_id_end = 0xfff7;
        req.free_nwk_addr_begin = 1;
        req.free_nwk_addr_end = 0xfeff;
        req._56_4_ = touchlink_join_router_req_confirm;
        iVar2 = touchlink_transaction_get();
        req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)(iVar2 + 0x610);
        auStack_54[0] = 3;
        uStack_52 = (dev_info->basic).ieee_addr.field_0.u8[0];
        uStack_51 = (dev_info->basic).ieee_addr.field_0.u8[1];
        req.cmd_ctrl.peer_addr.addr_mode = (dev_info->basic).ieee_addr.field_0.u8[2];
        req.cmd_ctrl.peer_addr._1_1_ = (dev_info->basic).ieee_addr.field_0.u8[3];
        req.cmd_ctrl.peer_addr.u.short_addr._0_1_ = (dev_info->basic).ieee_addr.field_0.u8[4];
        req.cmd_ctrl.peer_addr.u.short_addr._1_1_ = (dev_info->basic).ieee_addr.field_0.u8[5];
        req.cmd_ctrl.peer_addr.u.group_addr.bcast._0_1_ = (dev_info->basic).ieee_addr.field_0.u8[6];
        req.cmd_ctrl.peer_addr.u.group_addr.bcast._1_1_ = (dev_info->basic).ieee_addr.field_0.u8[7];
        eVar3 = zcl_touchlink_network_join_router_req(auStack_54);
      }
      else {
        eVar3 = 5;
      }
    }
  }
  return eVar3;
}

