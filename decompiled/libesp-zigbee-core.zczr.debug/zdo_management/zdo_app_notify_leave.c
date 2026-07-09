/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_app_notify_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_app_notify_leave(undefined2 *param_1,int param_2)

{
  byte bVar1;
  int *piVar2;
  
  bVar1 = *(byte *)(param_1 + 5);
  if (*(int *)(param_1 + 1) != 0 || *(int *)(param_1 + 3) != 0) {
    piVar2 = (int *)nwk_get_extended_address();
    if ((*(int *)(param_1 + 1) != *piVar2) || (*(int *)(param_1 + 3) != piVar2[1])) {
      aps_forget_device(*param_1,param_1 + 1);
      zdo_app_tc_handle_device_leaving(param_1);
      zdo_app_put_leave_ind_signal(param_1,bVar1 & 1);
      return;
    }
  }
  if (param_2 == 0) {
    zdo_secur_handle_device_left();
  }
  aps_reset(param_1[5] & 1);
  zdo_dev_set_joined(0);
  zdo_comm_handle_device_left(param_1[5] & 1);
  zdo_app_put_leave_signal(bVar1 & 1);
  return;
}

