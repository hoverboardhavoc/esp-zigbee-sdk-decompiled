/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote.debug -> zb_esp_osif.o -> zb_osif_iteration_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_osif_iteration_process(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  __fd_mask extraout_a1;
  int iVar2;
  uint auStack_40 [6];
  uint uStack_28;
  timeval tStack_20;
  int iStack_18;
  
  iVar2 = 2;
  while (iVar2 != 0) {
    iVar2 = iVar2 + -1;
    auStack_40[iVar2] = 0;
  }
  for (iVar2 = 2; iVar2 != 0; iVar2 = iVar2 + -1) {
    auStack_40[iVar2 + 1] = 0;
  }
  for (iVar2 = 2; iVar2 != 0; iVar2 = iVar2 + -1) {
    auStack_40[iVar2 + 3] = 0;
  }
  uStack_28 = 0xffffffff;
  tStack_20.tv_sec = __udivdi3(param_1,param_2,1000,0);
  tStack_20.tv_usec = extraout_a1;
  iVar2 = __umoddi3(param_1,param_2,1000,0);
  iStack_18 = iVar2 * 1000;
  if (s_zb_sched_fd < 0x40) {
    auStack_40[(int)(((int)s_zb_sched_fd >> 0x1f & 0x1fU) + s_zb_sched_fd) >> 5] =
         auStack_40[(int)(((int)s_zb_sched_fd >> 0x1f & 0x1fU) + s_zb_sched_fd) >> 5] |
         1 << (s_zb_sched_fd & 0x1f);
  }
  if (-1 < (int)s_zb_sched_fd) {
    uStack_28 = s_zb_sched_fd;
  }
  zb_esp_workflow_update(auStack_40);
  zb_esp_osif_lock_release();
  iVar2 = select(uStack_28 + 1,(fd_set *)auStack_40,(fd_set *)(auStack_40 + 2),
                 (fd_set *)(auStack_40 + 4),&tStack_20);
  zb_esp_osif_lock_acquire(0xffffffff);
  if (iVar2 < 0) {
    uVar1 = esp_log_timestamp();
    esp_log(1,"ZB OSIF","E (%lu) %s: ZB system polling failed\n",uVar1,"ZB OSIF");
  }
  else {
    zb_esp_workflow_process(auStack_40);
  }
  if (s_zb_sched_fd < 0x40) {
    if ((auStack_40[(int)(((int)s_zb_sched_fd >> 0x1f & 0x1fU) + s_zb_sched_fd) >> 5] &
        1 << (s_zb_sched_fd & 0x1f)) != 0) {
      zb_esp_clr_event();
    }
  }
  return;
}

