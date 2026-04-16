/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_discovery.o -> touchlink_send_device_info_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rsp */
/* WARNING: Unknown calling convention */

ezb_err_t touchlink_send_device_info_rsp(uint8_t start_index,uint8_t tsn)

{
  ezb_err_t eVar1;
  uint uVar2;
  undefined3 in_register_00002029;
  uint uVar3;
  int iVar4;
  char cVar5;
  undefined4 local_30;
  zcl_touchlink_device_info_rsp_t rsp;
  
  uVar2 = CONCAT31(in_register_00002029,start_index);
  local_30 = 0;
  rsp.cmd_ctrl.peer_addr._0_4_ = 0;
  rsp.cmd_ctrl.peer_addr.u._2_4_ = 0;
  rsp.cmd_ctrl._8_4_ = 0;
  rsp.transaction_id = 0;
  rsp.n_sub_devices = '\0';
  rsp.start_index = '\0';
  rsp.n_records = '\0';
  rsp._19_1_ = 0;
  rsp.records = (zcl_touchlink_sub_device_info_record_t *)0x0;
  rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  rsp.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
  uVar3 = touchlink_n_sub_device_size();
  rsp.transaction_id._0_2_ = CONCAT11(start_index,(char)uVar3);
  if (uVar2 < uVar3) {
    uVar3 = uVar3 - uVar2 & 0xff;
    if (uVar3 == 0) {
      rsp._16_4_ = 0;
    }
    else {
      rsp._16_4_ = mm_alloc(uVar3,0x12);
    }
  }
  else {
    uVar3 = 0;
    rsp._16_4_ = 0;
  }
  if ((rsp._16_4_ == 0) && (uVar3 != 0)) {
    eVar1 = 1;
  }
  else {
    while (iVar4 = touchlink_get_sub_device_info
                             (uVar2,rsp._16_4_ + (rsp.transaction_id >> 0x10 & 0xff) * 0x12),
          iVar4 == 0) {
      uVar2 = uVar2 + 1 & 0xff;
      cVar5 = rsp.transaction_id._2_1_ + '\x01';
      rsp.transaction_id._0_3_ = CONCAT12(cVar5,(undefined2)rsp.transaction_id);
    }
    rsp.records = (zcl_touchlink_sub_device_info_record_t *)touchlink_device_info_rsp_confirm;
    rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
    local_30 = CONCAT31(local_30._1_3_,3);
    iVar4 = touchlink_transaction_get();
    rsp.cmd_ctrl.peer_addr._0_4_ = *(undefined4 *)(iVar4 + 10);
    local_30 = CONCAT22(*(undefined2 *)(iVar4 + 8),(undefined2)local_30);
    rsp.cmd_ctrl.peer_addr.u._4_1_ = tsn;
    rsp.cmd_ctrl.peer_addr.u.group_addr.bcast = *(undefined2 *)(iVar4 + 0xe);
    eVar1 = zcl_touchlink_device_info_rsp(&local_30);
  }
  if (rsp._16_4_ != 0) {
    mm_free();
  }
  return eVar1;
}

