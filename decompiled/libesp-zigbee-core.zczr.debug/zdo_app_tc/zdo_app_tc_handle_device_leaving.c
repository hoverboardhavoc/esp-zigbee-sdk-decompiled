/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_tc.o -> zdo_app_tc_handle_device_leaving
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_app_tc_handle_device_leaving(undefined2 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = zdo_dev_joined();
  if (iVar1 == 0) {
    return;
  }
  if ((*(int *)(param_1 + 1) == 0 && *(int *)(param_1 + 3) == 0) ||
     (piVar2 = (int *)nwk_get_extended_address(),
     *(int *)(param_1 + 3) == piVar2[1] && *(int *)(param_1 + 1) == *piVar2)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_app_tc.c",0xa9,
                  "zdo_app_tc_handle_device_leaving",
                  "!ezb_eui64_is_all_zero(&ind->device_address) && !ezb_eui64_compare(&ind->device_address, nwk_get_extended_address())"
                 );
  }
  else {
    iVar1 = aps_secur_is_centralized();
    if (iVar1 == 0) {
      return;
    }
    if ((param_1[5] & 1) != 0) {
      return;
    }
  }
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_14 = 0;
  uStack_18 = 0x20000;
  puVar3 = (undefined4 *)aps_secur_get_tc_address();
  uStack_28 = *puVar3;
  uStack_24 = puVar3[1];
  uStack_20 = *(undefined4 *)(param_1 + 1);
  uStack_1c = *(undefined4 *)(param_1 + 3);
  uStack_18 = CONCAT22(uStack_18._2_2_,*param_1);
  apsme_update_device_request(&uStack_28);
  return;
}

