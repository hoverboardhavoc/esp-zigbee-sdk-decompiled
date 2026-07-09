/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mempool.o -> mempool_init_pool
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mempool_init_pool(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.c",0x52,
                  "mempool_init_pool",0x10000);
  }
  else if ((*(short *)(param_1 + 4) == 0) || (*(short *)(param_1 + 2) == 0)) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    return;
  }
  uVar1 = mm_calloc();
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  uVar1 = mm_calloc(*(ushort *)(param_1 + 4) + 7 >> 3,1);
  *(undefined4 *)(param_1 + 8) = uVar1;
  return;
}

