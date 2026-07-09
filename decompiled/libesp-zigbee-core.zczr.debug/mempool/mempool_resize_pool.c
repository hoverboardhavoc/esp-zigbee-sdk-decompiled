/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mempool.o -> mempool_resize_pool
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mempool_resize_pool(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.c",0x6e,
                  "mempool_resize_pool",0x10000);
  }
  else if (param_2 != 0) {
    uVar1 = mm_realloc(*(undefined4 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 2));
    *(undefined4 *)(param_1 + 0xc) = uVar1;
    uVar4 = param_2 + 7 >> 3;
    iVar2 = mm_realloc(*(undefined4 *)(param_1 + 8),uVar4,1);
    *(int *)(param_1 + 8) = iVar2;
    if (*(ushort *)(param_1 + 4) < param_2) {
      uVar3 = *(ushort *)(param_1 + 4) + 7 >> 3;
      memset((void *)(iVar2 + uVar3),0,uVar4 - uVar3);
    }
    goto _L0;
  }
  mempool_deinit_pool();
_L0:
  *(short *)(param_1 + 4) = (short)param_2;
  return;
}

