/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mempool.o -> mempool_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mempool_deinit(void)

{
  undefined1 *puVar1;
  
  puVar1 = s_mem_pools;
  do {
    if (*(int *)(puVar1 + 0xc) != 0) {
      mm_free();
      *(undefined4 *)(puVar1 + 0xc) = 0;
    }
    if (*(int *)(puVar1 + 8) != 0) {
      mm_free();
      *(undefined4 *)(puVar1 + 8) = 0;
    }
    puVar1 = puVar1 + 0x10;
  } while (puVar1 != (undefined1 *)0x10264);
  return;
}

