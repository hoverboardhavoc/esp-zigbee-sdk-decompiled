/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_pim_poll_parent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_pim_poll_parent(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar2 = core_globals_get();
  if ((*(uint *)(iVar2 + 0xb14) >> 0x15 & 1) == 0) {
    iVar2 = 3;
  }
  else {
    uStack_18 = 0;
    uStack_14 = 0;
    uStack_1c = 2;
    uVar1 = nwk_get_parent_shortaddr();
    uStack_1c = CONCAT22(uVar1,(undefined2)uStack_1c);
    uVar1 = nwk_get_panid();
    uStack_14 = CONCAT22(uVar1,(undefined2)uStack_14);
    nwk_get_parent_mac_iface_idx();
    iVar2 = nwk_mm_poll_request(&uStack_1c);
    if (iVar2 == 0) {
      nwk_pim_schedule_next_poll(0);
      return 0;
    }
    if (iVar2 != 3) {
      log_write(2,"nwk_ed_mngr.c","Unexpected error when requesting data poll: %d",iVar2);
      nwk_pim_schedule_next_poll(1);
      return iVar2;
    }
  }
  log_write(2,"nwk_ed_mngr.c","Request Data poll when polling is disabled!");
  nwk_pim_stop_poll();
  return iVar2;
}

