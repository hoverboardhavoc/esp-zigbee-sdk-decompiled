/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_tc.o -> zdo_app_tc_handle_device_leaving
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_app_tc_handle_device_leaving(nwk_leave_ind_t *ind)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uStack_28;
  apsme_update_device_req_t ud_req;
  
  iVar1 = zdo_dev_joined();
  if (iVar1 != 0) {
    if (*(int *)&(ind->device_address).field_0 != 0 ||
        *(int *)((int)&(ind->device_address).field_0 + 4) != 0) goto _L0;
    do {
      __assert_func(0,0,0,0);
_L0:
      piVar2 = (int *)nwk_get_extended_address();
    } while ((*(int *)&(ind->device_address).field_0 == *piVar2) &&
            (*(int *)((int)&(ind->device_address).field_0 + 4) == piVar2[1]));
    iVar1 = aps_secur_is_centralized();
    if ((iVar1 != 0) && ((*(ushort *)&ind->field_0xa & 1) == 0)) {
      memset(&uStack_28,0,0x18);
      ud_req.device_address.field_0.u8[6] = '\x02';
      puVar3 = (undefined4 *)aps_secur_get_tc_address();
      uStack_28 = *puVar3;
      ud_req.field_0._0_4_ = puVar3[1];
      ud_req.field_0._4_4_ = *(undefined4 *)&(ind->device_address).field_0;
      ud_req.device_address.field_0.u64._0_4_ =
           *(undefined4 *)((int)&(ind->device_address).field_0 + 4);
      ud_req.device_address.field_0.u64._4_2_ = ind->short_address;
      apsme_update_device_request(&uStack_28);
    }
  }
  return;
}

