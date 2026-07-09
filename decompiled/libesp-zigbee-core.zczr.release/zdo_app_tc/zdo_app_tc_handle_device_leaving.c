/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_tc.o -> zdo_app_tc_handle_device_leaving
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
  undefined2 uStack_18;
  undefined1 uStack_16;
  
  iVar1 = zdo_dev_joined();
  if (iVar1 != 0) {
    if (*(int *)(param_1 + 1) != 0 || *(int *)(param_1 + 3) != 0) goto _L0;
    do {
      __assert_func(0,0,0,0);
_L0:
      piVar2 = (int *)nwk_get_extended_address();
    } while ((*(int *)(param_1 + 1) == *piVar2) && (*(int *)(param_1 + 3) == piVar2[1]));
    iVar1 = aps_secur_is_centralized();
    if ((iVar1 != 0) && ((param_1[5] & 1) == 0)) {
      memset(&uStack_28,0,0x18);
      uStack_16 = 2;
      puVar3 = (undefined4 *)aps_secur_get_tc_address();
      uStack_28 = *puVar3;
      uStack_24 = puVar3[1];
      uStack_20 = *(undefined4 *)(param_1 + 1);
      uStack_1c = *(undefined4 *)(param_1 + 3);
      uStack_18 = *param_1;
      apsme_update_device_request(&uStack_28);
    }
  }
  return;
}

