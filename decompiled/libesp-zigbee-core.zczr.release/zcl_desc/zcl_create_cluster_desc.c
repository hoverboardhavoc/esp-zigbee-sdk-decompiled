/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_desc.o -> zcl_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_create_cluster_desc(undefined2 param_1,undefined1 param_2,undefined2 param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)calloc(1,0x14);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = param_1;
    *(undefined1 *)(puVar1 + 1) = param_2;
    puVar1[2] = param_3;
    *(undefined4 *)(puVar1 + 4) = 0;
    *(undefined4 *)(puVar1 + 6) = 0;
    *(undefined4 *)(puVar1 + 8) = 0;
  }
  return;
}

