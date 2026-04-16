/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> zcl_time_server_sync_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_time_server_sync_start(uint8_t ep_id)

{
  undefined3 in_register_00002029;
  ezb_err_t eVar1;
  undefined4 uStack_2c;
  ezb_zdo_match_desc_req_t req;
  
  req.cb = (ezb_zdo_match_desc_req_callback_t)CONCAT31(in_register_00002029,ep_id);
  uStack_2c = 0xfffd;
  req.dst_nwk_addr = 0xfffd;
  req._2_2_ = 0x104;
  req.field.nwk_addr_of_interest = 1;
  req.field.profile_id = 0;
  req.user_ctx._0_2_ = 10;
  req.field._4_4_ = &req.user_ctx;
  req.field.cluster_list = (uint16_t *)zcl_time_server_sync_callback;
  eVar1 = ezb_zdo_match_desc_req(&uStack_2c);
  return eVar1;
}

