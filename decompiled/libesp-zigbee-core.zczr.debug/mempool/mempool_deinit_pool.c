/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mempool.o -> mempool_deinit_pool
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mempool_deinit_pool(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint extraout_a1;
  uint uVar4;
  uint uVar5;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      mm_free();
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    if (*(int *)(param_1 + 8) != 0) {
      mm_free();
      *(undefined4 *)(param_1 + 8) = 0;
    }
    return;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.c",0x5f,
                        "mempool_deinit_pool",0x10000);
  if (iVar1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.c",0x6e,
                  "mempool_resize_pool",0x10000);
  }
  else if (extraout_a1 != 0) {
    uVar2 = mm_realloc(*(undefined4 *)(iVar1 + 0xc),*(undefined2 *)(iVar1 + 2));
    *(undefined4 *)(iVar1 + 0xc) = uVar2;
    uVar5 = extraout_a1 + 7 >> 3;
    iVar3 = mm_realloc(*(undefined4 *)(iVar1 + 8),uVar5,1);
    *(int *)(iVar1 + 8) = iVar3;
    if (*(ushort *)(iVar1 + 4) < extraout_a1) {
      uVar4 = *(ushort *)(iVar1 + 4) + 7 >> 3;
      memset((void *)(iVar3 + uVar4),0,uVar5 - uVar4);
    }
    goto _L0;
  }
  mempool_deinit_pool();
_L0:
  *(short *)(iVar1 + 4) = (short)extraout_a1;
  return;
}

