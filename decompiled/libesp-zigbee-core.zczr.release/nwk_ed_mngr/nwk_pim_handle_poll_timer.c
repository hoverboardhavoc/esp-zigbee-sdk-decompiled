/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_pim_handle_poll_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_pim_handle_poll_timer(void *ctx)

{
  int iVar1;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined2 uStack_1a;
  mac_poll_req_t req;
  
  iVar1 = core_globals_get();
  if (*(int *)(iVar1 + 0xb14) << 10 < 0) {
    memset(&uStack_1b,0,0xb);
    uStack_1c = 2;
    uStack_1a = nwk_get_parent_shortaddr();
    req.coord_address.u._4_2_ = nwk_get_panid();
    nwk_get_parent_mac_iface_idx();
    iVar1 = nwk_mm_poll_request(&uStack_1c);
    if (iVar1 != 0) {
      if (iVar1 == 3) goto _L0;
      log_write(2,"nwk_ed_mngr.c","Unexpected error when requesting data poll: %d",iVar1);
      iVar1 = 1;
    }
    nwk_pim_schedule_next_poll(SUB41(iVar1,0));
  }
  else {
_L0:
    log_write(2,"nwk_ed_mngr.c","Request Data poll when polling is disabled!");
    nwk_pim_stop_poll();
  }
  return;
}

