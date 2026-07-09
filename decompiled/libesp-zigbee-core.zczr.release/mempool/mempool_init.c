/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mempool.o -> mempool_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mempool_init(void)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  puVar1 = s_mem_pools;
  do {
    if ((*(short *)(puVar1 + 4) == 0) || (*(short *)(puVar1 + 2) == 0)) {
      *(undefined4 *)(puVar1 + 0xc) = 0;
      uVar2 = 0;
    }
    else {
      uVar2 = mm_calloc();
      *(undefined4 *)(puVar1 + 0xc) = uVar2;
      uVar2 = mm_calloc(*(ushort *)(puVar1 + 4) + 7 >> 3,1);
    }
    *(undefined4 *)(puVar1 + 8) = uVar2;
    puVar1 = puVar1 + 0x10;
  } while (puVar1 != (undefined1 *)0x10264);
  return;
}

