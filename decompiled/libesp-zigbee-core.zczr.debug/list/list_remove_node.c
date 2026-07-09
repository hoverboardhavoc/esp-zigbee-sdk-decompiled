/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> list.o -> list_remove_node
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 list_remove_node(int *param_1,int *param_2)

{
  int *piVar1;
  
  do {
    piVar1 = param_1;
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    param_1 = (int *)*piVar1;
  } while ((int *)*piVar1 != param_2);
  *piVar1 = *param_2;
  *param_2 = (int)param_2;
  return 1;
}

