/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_osif.o -> zb_osif_iteration_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_osif_iteration_process(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  __fd_mask extraout_a1;
  uint local_40 [8];
  timeval tStack_20;
  int iStack_18;
  
  local_40[6] = 0xffffffff;
  local_40[1] = 0;
  local_40[0] = 0;
  local_40[3] = 0;
  local_40[2] = 0;
  local_40[5] = 0;
  local_40[4] = 0;
  tStack_20.tv_sec = __udivdi3(1000,0);
  tStack_20.tv_usec = extraout_a1;
  iStack_18 = __umoddi3(param_1,param_2,1000,0);
  iStack_18 = iStack_18 * 1000;
  if (s_zb_sched_fd < 0x40) {
    local_40[(int)s_zb_sched_fd >> 5] =
         1 << (s_zb_sched_fd & 0x1f) | local_40[(int)s_zb_sched_fd >> 5];
  }
  else if ((int)s_zb_sched_fd < 0) goto _L0;
  local_40[6] = s_zb_sched_fd;
_L0:
  zb_esp_workflow_update(local_40);
  zb_esp_osif_lock_release();
  iVar1 = select(local_40[6] + 1,(fd_set *)local_40,(fd_set *)(local_40 + 2),
                 (fd_set *)(local_40 + 4),&tStack_20);
  zb_esp_osif_lock_acquire(0xffffffff);
  if (iVar1 < 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ZB OSIF",&_L0,uVar2,"ZB OSIF");
  }
  else {
    zb_esp_workflow_process(local_40);
  }
  if (s_zb_sched_fd < 0x40) {
    if ((1 << (s_zb_sched_fd & 0x1f) & local_40[(int)s_zb_sched_fd >> 5]) != 0) {
      zb_esp_clr_event();
    }
  }
  return;
}

