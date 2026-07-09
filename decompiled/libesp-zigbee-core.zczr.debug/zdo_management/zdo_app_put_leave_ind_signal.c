/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_app_put_leave_ind_signal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_app_put_leave_ind_signal(undefined2 *param_1,undefined1 param_2)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_24 = 4;
  puVar4 = (undefined2 *)zdo_app_signal_get_params(&uStack_24);
  uVar1 = *(undefined4 *)(param_1 + 1);
  uVar2 = param_1[3];
  uVar3 = *(undefined4 *)(param_1 + 3);
  *(char *)(puVar4 + 1) = (char)param_1[1];
  *(char *)((int)puVar4 + 3) = (char)((uint)uVar1 >> 8);
  *(char *)(puVar4 + 2) = (char)((uint)uVar1 >> 0x10);
  *(char *)((int)puVar4 + 5) = (char)((uint)uVar1 >> 0x18);
  *(char *)(puVar4 + 3) = (char)uVar2;
  *(char *)((int)puVar4 + 7) = (char)((uint)uVar3 >> 8);
  *(char *)(puVar4 + 4) = (char)((uint)uVar3 >> 0x10);
  *(char *)((int)puVar4 + 9) = (char)((uint)uVar3 >> 0x18);
  *puVar4 = *param_1;
  *(undefined1 *)(puVar4 + 5) = param_2;
  zdo_app_put_signal(&uStack_24);
  return;
}

