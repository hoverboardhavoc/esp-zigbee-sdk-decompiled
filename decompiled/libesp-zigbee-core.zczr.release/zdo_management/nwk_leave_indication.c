/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_management.o -> nwk_leave_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_leave_indication(undefined2 *param_1)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  byte *pbVar6;
  int *piVar7;
  undefined2 *puVar8;
  undefined2 uStack_24;
  undefined1 auStack_22 [18];
  
  bVar1 = *(byte *)(param_1 + 5);
  if (*(int *)(param_1 + 1) != 0 || *(int *)(param_1 + 3) != 0) {
    piVar7 = (int *)nwk_get_extended_address();
    if ((*(int *)(param_1 + 1) != *piVar7) || (*(int *)(param_1 + 3) != piVar7[1])) {
      aps_forget_device(*param_1,param_1 + 1);
      zdo_app_tc_handle_device_leaving(param_1);
      memset(auStack_22,0,0x10);
      uStack_24 = 4;
      puVar8 = (undefined2 *)zdo_app_signal_get_params(&uStack_24);
      uVar3 = param_1[3];
      uVar4 = *(undefined4 *)(param_1 + 1);
      uVar5 = *(undefined4 *)(param_1 + 3);
      *(char *)(puVar8 + 1) = (char)param_1[1];
      *(char *)((int)puVar8 + 3) = (char)((uint)uVar4 >> 8);
      *(char *)((int)puVar8 + 5) = (char)((uint)uVar4 >> 0x18);
      *(char *)((int)puVar8 + 7) = (char)((uint)uVar5 >> 8);
      *(char *)((int)puVar8 + 9) = (char)((uint)uVar5 >> 0x18);
      uVar2 = *param_1;
      *(char *)(puVar8 + 2) = (char)((uint)uVar4 >> 0x10);
      *(char *)(puVar8 + 3) = (char)uVar3;
      *(char *)(puVar8 + 4) = (char)((uint)uVar5 >> 0x10);
      *puVar8 = uVar2;
      *(byte *)(puVar8 + 5) = bVar1 & 1;
      goto _L0;
    }
  }
  zdo_secur_handle_device_left();
  aps_reset(param_1[5] & 1);
  zdo_dev_set_joined(0);
  zdo_comm_handle_device_left(param_1[5] & 1);
  memset(auStack_22,0,0x10);
  uStack_24 = 3;
  pbVar6 = (byte *)zdo_app_signal_get_params(&uStack_24);
  *pbVar6 = bVar1 & 1;
_L0:
  zdo_app_put_signal(&uStack_24);
  return;
}

