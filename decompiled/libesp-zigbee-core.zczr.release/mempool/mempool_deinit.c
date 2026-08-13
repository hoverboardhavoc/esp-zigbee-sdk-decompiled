/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
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
  } while (puVar1 != (undefined1 *)0x10288);
  return;
}

