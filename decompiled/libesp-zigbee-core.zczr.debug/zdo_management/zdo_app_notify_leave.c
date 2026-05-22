/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_app_notify_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_app_notify_leave(nwk_leave_ind_t *ind,_Bool is_requested)

{
  byte leave_type;
  int *piVar1;
  undefined3 in_register_0000202d;
  
  leave_type = ind->field_0xa & 1;
  if (*(int *)&(ind->device_address).field_0 != 0 ||
      *(int *)((int)&(ind->device_address).field_0 + 4) != 0) {
    piVar1 = (int *)nwk_get_extended_address();
    if ((*(int *)&(ind->device_address).field_0 != *piVar1) ||
       (*(int *)((int)&(ind->device_address).field_0 + 4) != piVar1[1])) {
      aps_forget_device(ind->short_address,&ind->device_address);
      zdo_app_tc_handle_device_leaving(ind);
      zdo_app_put_leave_ind_signal(ind,leave_type);
      return;
    }
  }
  if (CONCAT31(in_register_0000202d,is_requested) == 0) {
    zdo_secur_handle_device_left();
  }
  aps_reset(*(ushort *)&ind->field_0xa & 1);
  zdo_dev_set_joined(0);
  zdo_comm_handle_device_left(*(ushort *)&ind->field_0xa & 1);
  zdo_app_put_leave_signal(leave_type);
  return;
}

