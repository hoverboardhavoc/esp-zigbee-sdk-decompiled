/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_network_start.o -> touchlink_send_network_start_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_send_network_start_req(touchlink_disc_dev_info_t *dev_info)

{
  uint16_t uVar1;
  int iVar2;
  ezb_err_t eVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined1 auStack_5c [2];
  undefined1 auStack_5a [2];
  zcl_touchlink_network_start_req_t req;
  
  memset(auStack_5c,0,0x4c);
  iVar2 = touchlink_disc_table_entry_exists(dev_info);
  if (iVar2 == 0) {
    eVar3 = 5;
  }
  else {
    eVar3 = 5;
    if (((dev_info->basic).zigbee_info & 3) == 1) {
      req.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
      req.transaction_id = 0;
      req.ext_panid.field_0.u64._0_4_ = 0;
      iVar2 = touchlink_get_logical_channel();
      if (iVar2 == 0) {
        req.encrypted_nwk_key[0xc] = (dev_info->basic).logical_channel;
      }
      else {
        req.encrypted_nwk_key[0xc] = touchlink_get_logical_channel();
      }
      req.encrypted_nwk_key[0xd] = '\0';
      req.encrypted_nwk_key[0xe] = '\0';
      if ((dev_info->basic).pan_id != 0xffff) {
        req.encrypted_nwk_key._13_2_ = touchlink_assign_pan_id();
      }
      req._40_2_ = nwk_assign_shortaddr();
      uVar4 = touchlink_nwk_key();
      uVar1 = (dev_info->basic).key_bitmask;
      uVar5 = touchlink_transaction_id(0);
      req.ext_panid.field_0.u8[4] =
           touchlink_encrypt_nwk_key
                     (uVar4,(undefined1 *)((int)&req.ext_panid.field_0 + 5),uVar1,uVar5,
                      (dev_info->basic).response_id);
      req.pan_id = 1;
      req.nwk_addr = 0xfeff;
      req.group_id_begin = 1;
      req.group_id_end = 0xfff7;
      req.free_nwk_addr_begin = 1;
      req.free_nwk_addr_end = 0xfeff;
      puVar6 = (undefined4 *)touchlink_extended_address();
      req.free_group_id_begin = (uint16_t)*(undefined3 *)puVar6;
      req.free_group_id_end = (uint16_t)((uint)*puVar6 >> 0x10);
      req.initiator_ieee_addr.field_0.u64._0_2_ = (undefined2)*(undefined3 *)(puVar6 + 1);
      req.initiator_ieee_addr.field_0.u64._2_2_ = (undefined2)((uint)puVar6[1] >> 0x10);
      req.initiator_ieee_addr.field_0.u64._4_2_ = touchlink_short_address();
      req._64_4_ = 0x10000;
      iVar2 = touchlink_transaction_get();
      req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)(iVar2 + 0x610);
      auStack_5c[0] = 3;
      memcpy(auStack_5a,&(dev_info->basic).ieee_addr,8);
      eVar3 = zcl_touchlink_network_start_req(auStack_5c);
    }
  }
  return eVar3;
}

