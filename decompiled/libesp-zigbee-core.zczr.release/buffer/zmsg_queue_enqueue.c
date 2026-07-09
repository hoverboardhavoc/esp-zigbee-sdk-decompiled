/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_queue_enqueue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_queue_enqueue(int param_1,int *param_2)

{
  int *extraout_a1;
  undefined4 *puVar1;
  
  if ((*param_2 != 0) && (param_2[1] != 0)) {
    param_1 = __assert_func(0,0,0,0);
    param_2 = extraout_a1;
  }
  puVar1 = *(undefined4 **)(param_1 + 4);
  *(int **)(param_1 + 4) = param_2;
  *param_2 = param_1;
  param_2[1] = (int)puVar1;
  *puVar1 = param_2;
  *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + 1;
  return;
}

