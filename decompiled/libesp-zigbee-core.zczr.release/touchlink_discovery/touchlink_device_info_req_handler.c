/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_discovery.o -> touchlink_device_info_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rsp */
/* WARNING: Unknown calling convention */

ezb_err_t touchlink_device_info_req_handler(touchlink_device_info_req_t *req)

{
  byte bVar1;
  uint8_t uVar2;
  uint32_t uVar3;
  uint uVar4;
  uint32_t *puVar5;
  uint uVar6;
  int iVar7;
  ezb_err_t eVar8;
  undefined1 local_30 [2];
  undefined1 auStack_2e [2];
  zcl_touchlink_device_info_rsp_t rsp;
  
  if (req == (touchlink_device_info_req_t *)0x0) {
    return 2;
  }
  uVar3 = req->transaction_id;
  if ((uVar3 == 0) || (puVar5 = (uint32_t *)touchlink_transaction_get(), uVar3 != *puVar5)) {
    return 3;
  }
  bVar1 = req->start_index;
  uVar4 = (uint)bVar1;
  uVar2 = (req->cmd_ctrl).tsn;
  memset(local_30,0,0x20);
  rsp.cmd_ctrl._8_4_ = touchlink_transaction_id(0);
  uVar6 = touchlink_n_sub_device_size();
  rsp.transaction_id._0_1_ = (undefined1)uVar6;
  rsp.transaction_id._1_1_ = bVar1;
  if (uVar4 < uVar6) {
    rsp._16_4_ = mm_alloc(uVar6 - uVar4 & 0xff,0x12);
    eVar8 = 1;
    if (rsp._16_4_ == 0) goto _L0;
  }
  else {
    rsp.n_sub_devices = '\0';
    rsp.start_index = '\0';
    rsp.n_records = '\0';
    rsp._19_1_ = 0;
  }
  while (iVar7 = touchlink_get_sub_device_info
                           (uVar4,rsp._16_4_ + (uint)rsp.transaction_id._2_1_ * 0x12), iVar7 == 0) {
    uVar4 = uVar4 + 1 & 0xff;
    rsp.transaction_id._2_1_ = rsp.transaction_id._2_1_ + 1;
  }
  rsp.records = (zcl_touchlink_sub_device_info_record_t *)touchlink_device_info_rsp_confirm;
  local_30[0] = 3;
  rsp.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  iVar7 = touchlink_transaction_get();
  memcpy(auStack_2e,(void *)(iVar7 + 8),8);
  rsp.cmd_ctrl.peer_addr.u._4_1_ = uVar2;
  eVar8 = zcl_touchlink_device_info_rsp(local_30);
_L0:
  if (rsp._16_4_ != 0) {
    mm_free();
  }
  return eVar8;
}

