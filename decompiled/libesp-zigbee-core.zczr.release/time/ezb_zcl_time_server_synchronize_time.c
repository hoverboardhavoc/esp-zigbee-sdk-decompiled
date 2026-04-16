/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> ezb_zcl_time_server_synchronize_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_time_server_synchronize_time
                    (uint8_t ep_id,uint8_t timeout_seconds,
                    ezb_zcl_time_server_sync_callback_t callback,
                    ezb_zcl_time_server_rank_t expected_rank)

{
  ezb_err_t eVar1;
  undefined3 in_register_00002029;
  zcl_time_server_time_ctx_t *pzVar2;
  int iVar3;
  undefined3 in_register_0000202d;
  undefined2 auStack_3c [2];
  undefined4 uStack_38;
  ezb_zdo_match_desc_req_t req;
  
  eVar1 = 2;
  if (expected_rank - EZB_ZCL_TIME_SERVER_RANK_SYNCHRONIZED < 5) {
    pzVar2 = time_server_get_time_ctx(ep_id);
    eVar1 = 5;
    if (pzVar2 != (zcl_time_server_time_ctx_t *)0x0) {
      if ((pzVar2->interface).set_utc_time != (_func_void_uint32_t *)0x0) {
        iVar3 = milli_timer_is_running(&pzVar2->sync_timer);
        if (iVar3 == 0) {
          uStack_38 = 0xfffd;
          pzVar2->callback = callback;
          req.dst_nwk_addr = 0xfffd;
          req._2_2_ = 0x104;
          req.field.nwk_addr_of_interest = 1;
          req.field.profile_id = 0;
          auStack_3c[0] = 10;
          req.field._4_4_ = auStack_3c;
          req.field.cluster_list = (uint16_t *)zcl_time_server_sync_callback;
          req.cb = (ezb_zdo_match_desc_req_callback_t)CONCAT31(in_register_00002029,ep_id);
          iVar3 = ezb_zdo_match_desc_req(&uStack_38);
          if (iVar3 != 0) {
            return iVar3;
          }
          milli_timer_start(&pzVar2->sync_timer,
                            CONCAT31(in_register_0000202d,timeout_seconds) * 1000);
          pzVar2->min_rank = (uint8_t)expected_rank;
          pzVar2->server_addr = 0xffff;
          pzVar2->nwk_time = 0xffffffff;
          return 0;
        }
      }
      eVar1 = 6;
    }
  }
  return eVar1;
}

