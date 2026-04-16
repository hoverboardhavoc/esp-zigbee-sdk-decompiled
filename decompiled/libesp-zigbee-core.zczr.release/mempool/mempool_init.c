/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mempool.o -> mempool_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void mempool_init(void)

{
  mem_pool_t *pmVar1;
  uint8_t *puVar2;
  bitmap_t *pbVar3;
  
  pmVar1 = s_mem_pools;
  do {
    if ((pmVar1->blk_nr == 0) || (pmVar1->blk_size == 0)) {
      pmVar1->base_mem = (uint8_t *)0x0;
      pbVar3 = (bitmap_t *)0x0;
    }
    else {
      puVar2 = (uint8_t *)mm_calloc();
      pmVar1->base_mem = puVar2;
      pbVar3 = (bitmap_t *)mm_calloc(pmVar1->blk_nr + 7 >> 3,1);
    }
    pmVar1->blk_busy_map = pbVar3;
    pmVar1 = pmVar1 + 1;
  } while (pmVar1 != (mem_pool_t *)0x10264);
  return;
}

