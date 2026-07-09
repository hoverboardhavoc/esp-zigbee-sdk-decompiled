/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> list.o -> list_push_head_ll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool list_push_head_ll(int *param_1,int *param_2)

{
  int iVar1;
  int aiStack_14 [2];
  
  aiStack_14[0] = *param_1;
  do {
    *param_2 = aiStack_14[0];
    iVar1 = __atomic_compare_exchange_4(param_1,aiStack_14,param_2,5);
  } while (iVar1 == 0);
  return aiStack_14[0] == 0;
}

