/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> ezb_zcl_time_server_synchronize_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_time_server_synchronize_time
                    (uint8_t ep_id,uint8_t timeout_seconds,
                    ezb_zcl_time_server_sync_callback_t callback,
                    ezb_zcl_time_server_rank_t expected_rank)

{
  zcl_time_server_time_ctx_t *pzVar1;
  int iVar2;
  ezb_err_t eVar3;
  undefined3 in_register_0000202d;
  
  if (expected_rank - EZB_ZCL_TIME_SERVER_RANK_SYNCHRONIZED < 5) {
    pzVar1 = time_server_get_time_ctx(ep_id);
    if (pzVar1 == (zcl_time_server_time_ctx_t *)0x0) {
      eVar3 = 5;
    }
    else if ((pzVar1->interface).set_utc_time == (_func_void_uint32_t *)0x0) {
      eVar3 = 6;
    }
    else {
      iVar2 = milli_timer_is_running(&pzVar1->sync_timer);
      if (iVar2 == 0) {
        pzVar1->callback = callback;
        eVar3 = zcl_time_server_sync_start(ep_id);
        if (eVar3 == 0) {
          milli_timer_start(&pzVar1->sync_timer,
                            CONCAT31(in_register_0000202d,timeout_seconds) * 1000);
          pzVar1->min_rank = (uint8_t)expected_rank;
          pzVar1->server_addr = 0xffff;
          pzVar1->nwk_time = 0xffffffff;
        }
      }
      else {
        eVar3 = 6;
      }
    }
  }
  else {
    eVar3 = 2;
  }
  return eVar3;
}

