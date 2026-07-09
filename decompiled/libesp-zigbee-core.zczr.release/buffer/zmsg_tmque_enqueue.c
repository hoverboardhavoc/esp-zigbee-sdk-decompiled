/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_tmque_enqueue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_tmque_enqueue(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  short sVar1;
  int iVar2;
  undefined4 *extraout_a1;
  int *piVar3;
  undefined4 *puVar4;
  
  if (param_3 == 0) {
    param_1 = (undefined4 *)__assert_func(0,0,0);
    param_2 = extraout_a1;
  }
  iVar2 = micro_timer_get_now();
  puVar4 = (undefined4 *)*param_1;
  iVar2 = param_3 * 1000 + iVar2;
  param_2[6] = iVar2;
  for (; (puVar4 != param_1 && (puVar4[6] - iVar2 < 0)); puVar4 = (undefined4 *)*puVar4) {
  }
  piVar3 = (int *)puVar4[1];
  puVar4[1] = param_2;
  *param_2 = puVar4;
  sVar1 = *(short *)(param_1 + 2);
  param_2[1] = piVar3;
  *piVar3 = (int)param_2;
  *(short *)(param_1 + 2) = sVar1 + 1;
  if (param_2 == (undefined4 *)*param_1) {
    micro_timer_fire_at(param_1 + 3);
    return;
  }
  return;
}

