/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_free_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void af_free_endpoint_desc(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 4);
    while (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 0x10);
      zcl_free_cluster_desc();
    }
    iVar1 = *(int *)(param_1 + 8);
    while (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 0x34);
      mm_free();
    }
    if (*(int *)(param_1 + 0x18) != 0) {
      mm_free();
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
    mm_free(param_1);
    return;
  }
  return;
}

