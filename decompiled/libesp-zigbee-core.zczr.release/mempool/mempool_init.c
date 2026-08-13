/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
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
  } while (puVar1 != (undefined1 *)0x10288);
  return;
}

