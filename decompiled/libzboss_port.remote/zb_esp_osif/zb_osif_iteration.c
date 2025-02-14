/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_osif.o -> zb_osif_iteration
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void zb_osif_iteration(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  __fd_mask extraout_a1;
  uint auStack_40 [8];
  timeval tStack_20;
  int iStack_18;
  
  if (((param_1 != 0) && (*(int *)(_g_zb + 8) == 0)) && (DAT_000110a0 != -1)) {
    esp_timer_get_time();
  }
  auStack_40[6] = 0xffffffff;
  auStack_40[1] = 0;
  auStack_40[0] = 0;
  auStack_40[3] = 0;
  auStack_40[2] = 0;
  auStack_40[5] = 0;
  auStack_40[4] = 0;
  tStack_20.tv_sec = __udivdi3(1000,0);
  tStack_20.tv_usec = extraout_a1;
  iStack_18 = __umoddi3(0,0,1000,0);
  iStack_18 = iStack_18 * 1000;
  if (s_zb_sched_fd < 0x40) {
    auStack_40[(int)s_zb_sched_fd >> 5] =
         1 << (s_zb_sched_fd & 0x1f) | auStack_40[(int)s_zb_sched_fd >> 5];
  }
  else if ((int)s_zb_sched_fd < 0) goto _L0;
  auStack_40[6] = s_zb_sched_fd;
_L0:
  zb_esp_workflow_update(auStack_40);
  zb_esp_osif_lock_release();
  iVar1 = select(auStack_40[6] + 1,(fd_set *)auStack_40,(fd_set *)(auStack_40 + 2),
                 (fd_set *)(auStack_40 + 4),&tStack_20);
  zb_esp_osif_lock_acquire(0xffffffff);
  if (iVar1 < 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ZB OSIF",&_L0,uVar2,"ZB OSIF");
  }
  else {
    zb_esp_workflow_process(auStack_40);
  }
  if ((s_zb_sched_fd < 0x40) &&
     ((1 << (s_zb_sched_fd & 0x1f) & auStack_40[(int)s_zb_sched_fd >> 5]) != 0)) {
    zb_esp_clr_event();
  }
  return;
}

