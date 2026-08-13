/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> mempool.o -> mempool_resize
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mempool_resize(uint param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = s_mem_pools;
  uVar4 = param_1 + 7 >> 3;
  do {
    if (param_1 == 0) {
      if (*(int *)(puVar1 + 0xc) != 0) {
        mm_free();
        *(undefined4 *)(puVar1 + 0xc) = 0;
      }
      if (*(int *)(puVar1 + 8) != 0) {
        mm_free();
        *(undefined4 *)(puVar1 + 8) = 0;
      }
    }
    else {
      uVar2 = mm_realloc(param_1,*(undefined2 *)(puVar1 + 2));
      *(undefined4 *)(puVar1 + 0xc) = uVar2;
      uVar2 = mm_realloc(*(undefined4 *)(puVar1 + 8),uVar4,1);
      *(undefined4 *)(puVar1 + 8) = uVar2;
      uVar3 = (uint)*(ushort *)(puVar1 + 4);
      if (uVar3 < param_1) {
        memset((void *)(uVar3 * *(ushort *)(puVar1 + 2) + *(int *)(puVar1 + 0xc)),0,
               (param_1 - uVar3) * (uint)*(ushort *)(puVar1 + 2));
        uVar3 = *(ushort *)(puVar1 + 4) + 7 >> 3;
        memset((void *)(*(int *)(puVar1 + 8) + uVar3),0,uVar4 - uVar3);
      }
    }
    *(short *)(puVar1 + 4) = (short)param_1;
    puVar1 = puVar1 + 0x10;
  } while (puVar1 != (undefined1 *)0x10288);
  return;
}

