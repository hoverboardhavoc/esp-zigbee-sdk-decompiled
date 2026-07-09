/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_pim_handle_poll_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_pim_handle_poll_timer(void)

{
  int iVar1;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined2 uStack_1a;
  undefined2 uStack_12;
  
  iVar1 = core_globals_get();
  if (*(int *)(iVar1 + 0xb14) << 10 < 0) {
    memset(&uStack_1b,0,0xb);
    uStack_1c = 2;
    uStack_1a = nwk_get_parent_shortaddr();
    uStack_12 = nwk_get_panid();
    nwk_get_parent_mac_iface_idx();
    iVar1 = nwk_mm_poll_request(&uStack_1c);
    if (iVar1 != 0) {
      if (iVar1 == 3) goto _L0;
      log_write(2,"nwk_ed_mngr.c","Unexpected error when requesting data poll: %d",iVar1);
      iVar1 = 1;
    }
    nwk_pim_schedule_next_poll(iVar1);
  }
  else {
_L0:
    log_write(2,"nwk_ed_mngr.c","Request Data poll when polling is disabled!");
    nwk_pim_stop_poll();
  }
  return;
}

