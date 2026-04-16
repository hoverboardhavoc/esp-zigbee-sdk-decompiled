/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_network_update.o -> touchlink_send_network_update_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

ezb_err_t touchlink_send_network_update_req(touchlink_disc_dev_info_t *dev_info,void *arg)

{
  ezb_err_t eVar1;
  int iVar2;
  uint32_t *puVar3;
  undefined1 auStack_38 [2];
  undefined1 auStack_36 [2];
  zcl_touchlink_network_update_req_t req;
  
  memset(auStack_38,0,0x28);
  eVar1 = 2;
  if (dev_info != (touchlink_disc_dev_info_t *)0x0) {
    iVar2 = touchlink_transaction_id(0);
    eVar1 = 3;
    if (iVar2 != 0) {
      req.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
      req.ext_panid.field_0.u8[4] = touchlink_nwk_update_id();
      req.ext_panid.field_0.u8[5] = touchlink_current_channel();
      req.ext_panid.field_0.u64._6_2_ = touchlink_pan_id();
      req._24_2_ = (dev_info->basic).nwk_addr;
      puVar3 = (uint32_t *)touchlink_extended_pan_id();
      req.transaction_id = *puVar3;
      req.ext_panid.field_0.u64._0_4_ = puVar3[1];
      req._28_4_ = touchlink_network_update_req_confirm;
      auStack_38[0] = 3;
      req.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)arg;
      memcpy(auStack_36,&(dev_info->basic).ieee_addr,8);
      eVar1 = zcl_touchlink_network_update_req(auStack_38);
    }
  }
  return eVar1;
}

