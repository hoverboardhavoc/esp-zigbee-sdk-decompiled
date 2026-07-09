/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
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
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  puVar1 = s_mem_pools;
  uVar5 = param_1 + 7 >> 3;
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
      iVar3 = mm_realloc(*(undefined4 *)(puVar1 + 8),uVar5,1);
      *(int *)(puVar1 + 8) = iVar3;
      if (*(ushort *)(puVar1 + 4) < param_1) {
        uVar4 = *(ushort *)(puVar1 + 4) + 7 >> 3;
        memset((void *)(iVar3 + uVar4),0,uVar5 - uVar4);
      }
    }
    *(short *)(puVar1 + 4) = (short)param_1;
    puVar1 = puVar1 + 0x10;
  } while (puVar1 != (undefined1 *)0x10264);
  return;
}

